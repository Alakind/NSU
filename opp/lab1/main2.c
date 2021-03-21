#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

double scalar_mul(double* vector1, double* vector2, int n, size_t proc_num, size_t rank) {
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

void matrix_mul_vector(double* matrix, double* vector, double* result, int n, size_t proc_num, size_t rank) {
    double vec[n];
    size_t lines = n / proc_num;
    size_t offset = lines * rank;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < n; j++) {
            vec[j] = matrix[i * n + j];
        }
        result[i + offset] = scalar_mul(vec, vector, n);
    }

    double* tmp = (double*)macalloc(n * sizeof(double));
    MPI_Allgather(result + offset, lines, MPI_DOUBLE, tmp, lines, MPI_DOUBLE, MPI_COMM_WORLD);
    memcpy(result, tmp, n * sizeof(double));
    free(tmp);
}

/*void matrix_mul_double(double* matrix, double dub, int n, size_t proc_num, size_t rank) {
    size_t lines = n / proc_num;
    size_t offset = lines * rank;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i + offset + j] *= dub;
        }
    }
}*/

void vector_mul_double(double* vector, double dub, int n) {
    for (int i = 0; i < n; i++) {
        vector[i] *= dub;
    }
}

void vector_minus_vector(double* vector1, double* vector2, int n) {
    for (int i = 0; i < n; i++) {
        vector1[i] -= vector2[i];
    }
}

int is_finished(double* matrix, double* vector, double* b, double epsilon, int n) {

    double* A = (double*)malloc(n * n * sizeof(double));
    make_zero_matrix(A, n);

    matrix_copy(A, matrix, n);
    double* Ax = (double*)malloc(n * sizeof(double));

    matrix_mul_vector(A, vector, Ax, n);
    vector_minus_vector(Ax, b, n);

    if ((sqrt(scalar_mul(Ax, Ax, n)) / sqrt(scalar_mul(b, b, n))) < epsilon) {
        free(A);
        free(Ax);
        return 1;
    }

    free(A);
    free(Ax);
    return 0;
}

void count_y(double* y, double* A, double* x_n, double* b, int n, size_t proc_num, size_t rank){
    matrix_mul_vector(A, x_n, y, n, proc_num, rank);

    vector_minus_vector(y, b, n);
}

double count_tau(double* A, double* y, int n) {
    double* Ay = (double*)malloc(n * sizeof(double));
    matrix_mul_vector(A, y, Ay, n);

    double tau = (scalar_mul(y, Ay, n) / scalar_mul(Ay, Ay, n));

    free(Ay);
    return tau;
}

double* solve_eq(double* matrix, double* values, int n, size_t proc_num, size_t rank) {
    double epsilon = 0.001;

    double* y = (double*)malloc(n * sizeof(double));
    double* x_i = (double*)malloc(n * sizeof(double));
    vector_copy(x_i, values, n);

    while (!is_finished(matrix, x_i, values, epsilon, n)) {
        count_y(y, matrix, x_i, values, n, proc_num, rank);

        double tau = count_tau(matrix, y, n);

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
    int n;
    printf("Enter size of matrix: ");
    scanf("%d", &n);

    double* matrix = (double*)malloc(n * n * sizeof(double));
    make_zero_matrix(matrix, n);

    //make_one_two_matrix(matrix, n);
    make_random_matrix(matrix, n);

    double* values = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        values[i] = n + 1;
    }

    // MPI staff
    size_t lines = n / proc_num;
    size_t offset = lines * rank;
    double* matrix_part = (double*)malloc(lines * sizeof(double));
    MPI_Scatter(matrix, lines * n, MPI_DOUBLE, matrix_part, lines * n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(values, n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // ACTION
    double* x_n = solve_eq(matrix, values, n, proc_num, rank);

    for (int i = 0; i < n; i++) {
        printf("%f ", x_n[i]);
    }
    printf("\n");

    // FREEING
    free(values);
    free(x_n);
    free(matrix);
    return 0;
}
