#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <mpi.h>

void print_matrix(double* matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", matrix[i*n + j]);
        }
        printf("\n");
    }
}

void print_vector(double* vector, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", vector[i]);
    }
    printf("\n");
}

double rand_double(double min, double max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

void make_zero_matrix(double* matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i*n + j] = 0;
        }
    }
}

void matrix_copy(double* matrix1, double* matrix2, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix1[i*n + j] = matrix2[i*n + j];
        }
    }
}

void vector_copy(double* vector1, double* vector2, int n) {
    for (int i = 0; i < n; i++) {
        vector1[i] = vector2[i];
    }
}

void make_one_two_matrix(double* matrix, int n) {
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

void make_one_matrix(double* matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i*n + j] = 1;
            }
            else {
                matrix[i*n + j] = 0;
            }
        }
    }
}

void make_random_matrix(double* matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            matrix[i*n + j] = rand_double(0, 1);
            if (i == j) {
                matrix[i*n + j] += 1000;
            }
            else {
                matrix[j*n + i] = matrix[i*n + j];
            }
        }
    }
}

double vec_len(double* vector, int n) {
    double len = 0;
    for (int i = 0; i < n; i++) {
        len += vector[i] * vector[i];
    }

    return sqrt(len);
}

double scalar_mul_part(double* vector1, double* vector2, int n, size_t proc_num, size_t rank) {
    double result = 0;
    double result_tmp = 0;
    size_t lines = n / proc_num;
    size_t offset = lines * rank;

    for (int i = 0; i < lines; i++) {
        result_tmp += vector1[i + offset] * vector2[i + offset];
    }

    MPI_Allreduce(&result_tmp, &result, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

    return result;
}

double scalar_mul(double* vector1, double* vector2, int n, size_t proc_num, size_t rank) {
    double result = 0;

    for (int i = 0; i < n; i++) {
        result += vector1[i] * vector2[i];
    }

    return result;
}


void matrix_mul_vector(double* matrix, double* vector, double* result, int n, size_t proc_num, size_t rank) {
    size_t lines = n / proc_num;
    size_t offset = lines * rank;

    double result_tmp[n];

    for (int i = 0; i < lines; i++) {
        result_tmp[i] = 0;
        for (int j = 0; j < n; j++) {
            result_tmp[i] += matrix[i * n + j] * vector[j];
        }
    }

    MPI_Allgather(result_tmp, lines, MPI_DOUBLE, result, lines, MPI_DOUBLE, MPI_COMM_WORLD);
}

void vector_mul_double(double* vector, double dub, int n) {
    for (int i = 0; i < n; i++) {
        vector[i] *= dub;
    }
}

void vector_minus_vector_part_2(double* vector1, double* vector2_part, int n, size_t proc_num, size_t rank) {
    double result_tmp[n];
    size_t lines = n / proc_num;
    size_t offset = lines * rank;

    for (int i = 0; i < lines; i++) {
        result_tmp[i] = vector1[offset + i] - vector2_part[i];
    }

    MPI_Allgather(result_tmp, lines, MPI_DOUBLE, vector1, lines, MPI_DOUBLE, MPI_COMM_WORLD);
}

void vector_minus_vector(double* vector1, double* vector2, int n) {
    for (int i = 0; i < n; i++) {
        vector1[i] -= vector2[i];
    }
}

int is_finished(double* matrix, double* vector, double* b, double epsilon, int n, size_t proc_num, size_t rank) {

    double* A = (double*)malloc(n * n * sizeof(double));
    make_zero_matrix(A, n);

    matrix_copy(A, matrix, n);
    double* Ax = (double*)malloc(n * sizeof(double));

    matrix_mul_vector(A, vector, Ax, n, proc_num, rank);
    vector_minus_vector(Ax, b, n);

    if ((vec_len(Ax, n) / vec_len(b, n)) < epsilon) {
        free(A);
        free(Ax);
        return 1;
    }

    free(A);
    free(Ax);
    return 0;
}

void count_y_part(double* y, double* A, double* x_n, double* b_part, int n, size_t proc_num, size_t rank){
    matrix_mul_vector(A, x_n, y, n, proc_num, rank);

    vector_minus_vector_part_2(y, b_part, n, proc_num, rank);
}

void count_y(double* y, double* A, double* x_n, double* b, int n, size_t proc_num, size_t rank){
    matrix_mul_vector(A, x_n, y, n, proc_num, rank);

    vector_minus_vector(y, b, n);
}

double count_tau(double* A, double* y, int n, size_t proc_num, size_t rank) {
    double* Ay = (double*)malloc(n * sizeof(double));
    matrix_mul_vector(A, y, Ay, n, proc_num, rank);

    double tau = (sqrt(scalar_mul(y, Ay, n, proc_num, rank)) / sqrt(scalar_mul(Ay, Ay, n, proc_num, rank)));

    free(Ay);
    return tau;
}

double* solve_eq(double* matrix, double* values, int n, size_t proc_num, size_t rank) {
    double epsilon = 0.001;

    double* y = (double*)malloc(n * sizeof(double));
    double* x_i = (double*)malloc(n * sizeof(double));
    vector_copy(x_i, values, n);

    int vec_part = (n / proc_num);
    double* x_i_part = (double*)malloc(vec_part * sizeof(double));
    double* values_part = (double*)malloc(vec_part * sizeof(double));
    MPI_Scatter(values, vec_part, MPI_DOUBLE, values_part, vec_part, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    while (!is_finished(matrix, x_i, values, epsilon, n, proc_num, rank)) {
        /*for (int i = 0; i < n; i++) {
            printf("%lf ", x_i[i]);
        }
        printf("\n");*/
        count_y_part(y, matrix, x_i, values, n, proc_num, rank);

        double tau = count_tau(matrix, y, n, proc_num, rank);

        vector_mul_double(y, tau, n);

        vector_minus_vector(x_i, y, n);

    }

    free(y);

    return x_i;
}

int main(int argc, char** argv) {
    // SETTING UP
    MPI_Init(&argc, &argv);
    int proc_num;
    MPI_Comm_size(MPI_COMM_WORLD, &proc_num);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    srand(time(NULL));
    int n = 16;

    double* matrix = (double*)malloc(n * n * sizeof(double));
    make_zero_matrix(matrix, n);

    //make_one_two_matrix(matrix, n);
    //make_random_matrix(matrix, n);
    make_one_matrix(matrix, n);

    double* values = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        values[i] = n + 1;
    }

    // MPI staff
    size_t lines = n / proc_num;
    double* matrix_part = (double*)malloc(lines * n * sizeof(double));
    MPI_Scatter(matrix, lines * n, MPI_DOUBLE, matrix_part, lines * n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // ACTION
    double* x_n = solve_eq(matrix_part, values, n, proc_num, rank);

    for (int i = 0; i < n; i++) {
        printf("%f ", x_n[i]);
    }
    printf("\n");

    // FREEING
    MPI_Finalize();
    free(values);
    free(x_n);
    free(matrix);
    return 0;
}
