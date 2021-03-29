#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <xmmintrin.h>
#include <omp.h>


#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))


void make_one_two_matrix(float* matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i*n + j] = 2;
            }
            else {
                matrix[i*n + j] = 1;
            }
        }
    }
}

void mul_matrix_line_pillar(float* first_matrix, float* second_matrix, int raw, int column, int n, float* result_matrix) {
    __m128 result, line_element, column_element, tmp;

    result = _mm_setzero_ps();
    for (int i = 0; i < n; i++) {
        line_element = _mm_set1_ps(first_matrix[raw * n + i]);
        column_element = _mm_load_ps(second_matrix + i * n + column);

        tmp = _mm_mul_ps(line_element, column_element);
        result = _mm_add_ps(result, tmp);
    }

    _mm_store_ps(result_matrix + raw * n + column, result);
}

void matrix_multiply(float* one_matrix, float* two_matrix, int n) {
    float* result_matrix = (float*)malloc(n * n * sizeof(float));

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j += 4) {
            mul_matrix_line_pillar(one_matrix, two_matrix, i, j, n, result_matrix);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            one_matrix[i * n + j] = result_matrix[i * n + j];
        }
    }
    free(result_matrix);
}

void matrix_sum(float* one_matrix, float* two_matrix, int n) {
    float* result_matrix = (float*)malloc(n * n * sizeof(float));

    __m128 summary;
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        __m128 *first, *second;
        first = (__m128*)(one_matrix + i * n);
        second = (__m128*)(two_matrix + i * n);
        for (int j = 0; j < n / 4; j++) {
            summary = _mm_add_ps(first[j], second[j]);
            _mm_store_ps((result_matrix + i * n + j * 4), summary);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            one_matrix[i * n + j] = result_matrix[i * n + j];
        }
    }
    free(result_matrix);
}

void transpose(float* matrix, int n) {

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            float tmp = matrix[i * n + j];
            matrix[i * n + j] = matrix[j * n + i];
            matrix[j * n + i] = tmp;
        }
    }
}

float max_column_sum(float* matrix, int n) {

    float max_sum = 0;
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        float cur_sum = 0;
        for (int j = 0; j < n; j++) {
            cur_sum += fabs(matrix[j * n + i]);
        }
        #pragma omp critical
        {
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
            }
        }
    }

    return max_sum;
}

float max_raw_sum(float* matrix, int n) {

    float max_sum = 0;
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        float cur_sum = 0;
        for (int j = 0; j < n; j++) {
            cur_sum += fabs(matrix[i * n + j]);
        }
        #pragma omp critical
        {
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
            }
        }
    }

    return max_sum;
}

void div_by_number(float* matrix, double number, int n) {

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i * n + j] = matrix[i * n + j] / number;
        }
    }
}

float* make_identity(int n) {
    float* matrix = (float*)malloc(n*n * sizeof(float));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i * n + j] = 1;
            }
            else {
                matrix[i * n + j] = 0;
            }
        }
    }

    return matrix;
}

float* make_zero(int n) {
    float* matrix = (float*)malloc(n*n * sizeof(float));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i * n + j] = 0;
        }
    }

    return matrix;
}

void copy_matrix(float* to_matrix, float* from_matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            to_matrix[i * n + j] = from_matrix[i * n + j];
        }
    }
}

void print_matrix(float* matrix, int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", matrix[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    float* matrix = (float*)malloc(n*n * sizeof(float));

    //srand(time(NULL));
    //char str[2] = "A\n";
    //write(0, str, 2);
    make_one_two_matrix(matrix, n);

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &matrix[i * n + j]);
        }
    }*/

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    float* b_matrix = make_zero(n);
    double div = max_column_sum(matrix, n) * max_raw_sum(matrix, n);
    copy_matrix(b_matrix, matrix, n);
    transpose(b_matrix, n);
    div_by_number(b_matrix, div, n);


    float* identity_matrix = make_identity(n);

    float* ba_matrix = make_identity(n);
    matrix_multiply(ba_matrix, b_matrix, n);
    matrix_multiply(ba_matrix, matrix, n);
    div_by_number(ba_matrix, -1, n);

    float* r_matrix = make_zero(n);
    matrix_sum(r_matrix, ba_matrix, n);
    matrix_sum(r_matrix, identity_matrix, n);

    float* r_in_degree = make_zero(n);
    copy_matrix(r_in_degree, r_matrix, n);
    float* summar_matrix = make_identity(n);

    for (int i = 0; i < m; i++) {
        matrix_sum(summar_matrix, r_in_degree, n);
        matrix_multiply(r_in_degree, r_matrix, n);
    }

    float* result_matrix = make_identity(n);
    matrix_multiply(result_matrix, summar_matrix, n);
    matrix_multiply(result_matrix, b_matrix, n);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("Time taken: %lf sec.\n", end.tv_sec-start.tv_sec + 0.000000001*(end.tv_nsec-start.tv_nsec));

    //print_matrix(result_matrix, n);

    return 0;
}
