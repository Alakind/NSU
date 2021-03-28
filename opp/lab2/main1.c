#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

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

float mul_matrix_line_pillar(float* first_matrix, float* second_matrix, int raw, int column, int n) {
    float result = 0;

    for (int i = 0; i < n; i++) {
        result += first_matrix[raw * n + i] * second_matrix[i * n + column];
    }

    return result;
}

void matrix_multiply(float* one_matrix, float* two_matrix, int n) {
    float* result_matrix = (float*)malloc(n * n * sizeof(float));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result_matrix[i * n + j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result_matrix[i * n + j] = mul_matrix_line_pillar(one_matrix, two_matrix, i, j, n);
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            one_matrix[i * n + j] = one_matrix[i * n + j] + two_matrix[i * n + j];
        }
    }
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
    for (int i = 0; i < n; i++) {
        float cur_sum = 0;
        for (int j = 0; j < n; j++) {
            cur_sum += fabs(matrix[j * n + i]);
        }
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
        }
    }

    return max_sum;
}

float max_raw_sum(float* matrix, int n) {

    float max_sum = 0;
    for (int i = 0; i < n; i++) {
        float cur_sum = 0;
        for (int j = 0; j < n; j++) {
            cur_sum += fabs(matrix[i * n + j]);
        }
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
        }
    }

    return max_sum;
}

void div_by_number(float* matrix, double number, int n) {

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

    print_matrix(result_matrix, n);

    return 0;
}
