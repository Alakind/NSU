#define MAIN_DIAG 2000
#define SIZE 9600
#define EPS 0.001
#define MAX_EL_SIZE 1


double rand_double(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}


void generate_task(double* matrix, double* right_side, size_t size)
{
    double* tmp_vector = (double*)malloc(size * sizeof(double));
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i; j < size; j++) {
            double tmp = rand_double(0, MAX_EL_SIZE);
            matrix[i * size + j] = tmp;
            matrix[j * size + i] = tmp;
        }
    }
    for (int i = 0; i < size; i++) {
        matrix[i * size + i] += MAIN_DIAG;
        right_side[i] = rand_double(0, MAX_EL_SIZE);
    }

    if (DEBUG) {
        printf("generated right side:\n");
        print_matrix(right_side, 1, SIZE);
        printf("generated matrix:\n");
        print_matrix(matrix, SIZE, SIZE);
    }

    free(tmp_vector);
}
