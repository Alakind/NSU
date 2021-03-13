#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void free_matrix(double** matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void malloc_zero_matrix(double** matrix, int n) {
    matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(n * sizeof(double));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

void matrix_copy(double** matrix1, double** matrix2, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix1[i][j] = matrix2[i][j];
        }
    }
}

void vector_copy(double* vector1, double* vector2, int n) {
    for (int i = 0; i < n; i++) {
        vector1[i] = vector2[i];
    }
}

void make_one_two_matrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 2;
            }
            else {
                matrix[i][j] = 1;
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

double scalar_mul(double* vector1, double* vector2, int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += vector1[i] * vector2[i];
    }

    return result;
}

void matrix_mul_vector(double** matrix, double* vector, double* result, int n) {
    for (int i = 0; i < n; i++) {
        result[i] = scalar_mul(matrix[i], vector, n);
    }
}

void matrix_mul_double(double** matrix, double dub, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] *= dub;
        }
    }
}

void vector_mul_double(double* vector, double dub, int n) {
    for (int i = 0; i < n; i++) {
        matrix[i] *= dub;
    }
}

void vector_minus_vector(double* vector1, double* vector2, int n) {
    for (int i = 0; i < n; i++) {
        vector1[i] -= vector2[i];
    }
}

int is_finished(double** matrix, double* vector, double* b, double epsilon, int n) {

    double** A;
    malloc_zero_matrix(A, n);
    matrix_copy(A, matrix, n);
    double* Ax = (double*)malloc(n * sizeof(double));

    matrix_mul_vector(A, vector, Ax, n);
    vector_minus_vector(Ax, b, n);

    if (sqrt(scalar_mul(Ax, Ax, n)) / sqrt(scalar_mul(b, b, n))) < epsilon) {
        return 1;
    }

    return 0;
}

void count_y(double* y, double** A, double* x_n, double* b){
    matrix_mul_vector(A, x, y, n);

    vector_minus_vector(y, b, n);
}

void count_tau(double** A, double* y, int n) {
    double* Ay = (double*)malloc(n * sizeof(double));
    matrix_mul_vector(A, y, Ay, n);

    double tau = (scalar_mul(y, Ay) / scalar_mul(Ay, Ay));

    free(Ay);
    return tau;
}

double* solve_eq(double** matrix, double* values, int n) {
    double epsilon = 0.001;

    double* y = (double*)malloc(n * sizeof(double));
    double* x_i = (double*)malloc(n * sizeof(double));
    vector_copy(x_i, values, n);

    while (!is_finished(matrix, )) {
        count_y(y, matrix, x_i, values);

        double tau = count_tau(matrix, y, n);

        vector_mul_double(y, tau);

        vector_minus_vector(x_i, y);
    }

}

int main() {
    // SETTING UP
    int n;
    printf("Enter size of matrix: ");
    scanf("%d", &n);

    double** matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(n * sizeof(double));
    }

    make_one_two_matrix(matrix, n);

    // ACTION


    // FREEING
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
