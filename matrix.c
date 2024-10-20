#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform matrix multiplication and calculate memory usage
void matrix_multiplication(int n) {
    // Calculate memory for each matrix (A, B, C)
    long memory_used = 3 * n * n * sizeof(double);  // Memory for 3 matrices A, B, and C

    // Create matrices A, B, and C
    double **A = (double **)malloc(n * sizeof(double *));
    double **B = (double **)malloc(n * sizeof(double *));
    double **C = (double **)malloc(n * sizeof(double *));
    
    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
        B[i] = (double *)malloc(n * sizeof(double));
        C[i] = (double *)malloc(n * sizeof(double));
    }

    // Initialize matrices A and B with random values
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = (double)rand() / RAND_MAX;
            B[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Measure start time
    clock_t start = clock();

    // Perform matrix multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Measure end time
    clock_t end = clock();

    // Calculate execution time in seconds
    double execution_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Convert memory used to MB
    double memory_used_mb = memory_used / (1024.0 * 1024.0);

    // Print results for this matrix size
    printf("\nMatrix size: %dx%d\n", n, n);
    printf("Execution time: %.6f seconds\n", execution_time);
    printf("Memory used: %.2f MB\n", memory_used_mb);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}

int main() {
    // Matrix sizes to test
    int matrix_sizes[] = {10, 50, 150, 300, 450, 500, 650, 800, 1000};
    int num_sizes = sizeof(matrix_sizes) / sizeof(matrix_sizes[0]);

    // Run matrix multiplication for each matrix size
    for (int i = 0; i < num_sizes; i++) {
        matrix_multiplication(matrix_sizes[i]);
    }

    return 0;
}
