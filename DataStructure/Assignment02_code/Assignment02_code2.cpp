#include <stdio.h>
#include <stdlib.h>

void* malloc_3d_double(size_t x, size_t y, size_t z) {
    void* ret = malloc((x * y * z) * sizeof(size_t));
    return ret;
}

void addition_3D(double*** A, double*** B, int X, int Y, int Z)       //addition of matrix A and B
{
    double*** sum = (double***)malloc(X * sizeof(double**));
    if (sum == NULL) {
        fprintf(stderr, "Out of memory");
        exit(0);
    }

    for (int i = 0; i < X; i++) {
        sum[i] = (double**)malloc(Y * sizeof(double*));
        if (sum[i] == NULL) {
            fprintf(stderr, "Out of memory");
            exit(0);
        }
        for (int j = 0; j < Y; j++) {
            sum[i][j] = (double*)malloc(Z * sizeof(double));
            if (sum[i][j] == NULL) {
                fprintf(stderr, "Out of memory");
                exit(0);
            }
        }
    }

    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {
                sum[i][j][k] = A[i][j][k] + B[i][j][k];
            }
        }
    }
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {
                printf("%lf ", sum[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return;
}

int main() {

    // size of 3D mem-alloc
    int X = 3;
    int Y = 4;
    int Z = 5;

    // for test loop.
    int i, j, k;


    // Memory Allocation
    // define A
    double*** A = (double***)malloc_3d_double(X, Y, Z);
    if (A == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    for (int i = 0; i < X; i++) {
        A[i] = (double**)malloc(Y * sizeof(double*));
        if (A[i] == NULL) {
            fprintf(stderr, "Out of memory");
            exit(0);
        }
        for (int j = 0; j < Y; j++) {
            A[i][j] = (double*)malloc(Z * sizeof(double));
            if (A[i][j] == NULL) {
                fprintf(stderr, "Out of memory");
                exit(0);
            }
        }
    }

    // Get the elements of the array
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {

                A[i][j][k] = rand() % 100;
            }
        }
    }


    // Print the elements of the array
    printf("The elements of array A: \n");
    for (i = 0; i < X; i++) {
        for (j = 0; j < Y; j++) {
            for (k = 0; k < Z; k++) {
                //printf("%d %d %d:", i, j, k);

                printf("%lf ", (A)[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    //define B
    double*** B = (double***)malloc_3d_double(X, Y, Z);
    if (B == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    for (int i = 0; i < X; i++) {
        B[i] = (double**)malloc(Y * sizeof(double*));
        if (B[i] == NULL) {
            fprintf(stderr, "Out of memory");
            exit(0);
        }
        for (int j = 0; j < Y; j++) {
            B[i][j] = (double*)malloc(Z * sizeof(double));
            if (B[i][j] == NULL) {
                fprintf(stderr, "Out of memory");
                exit(0);
            }
        }
    }

    // Get the elements of the array
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {

                B[i][j][k] = rand() % 100;
            }
        }
    }


    // Print the elements of the array
    printf("The elements of array B: \n");
    for (i = 0; i < X; i++) {
        for (j = 0; j < Y; j++) {
            for (k = 0; k < Z; k++) {
                // printf("%d %d %d:", i, j, k);

                printf("%lf ", (B)[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    //addition of A and B
    printf("sum of array A and B : \n");
    addition_3D(A, B, X, Y, Z);

    // Deallocate A and B
    if (A != NULL) {
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                free(A[i][j]);
            }
            free(A[i]);
        }
        free(A);
    }
    if (B != NULL) {
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                free(B[i][j]);
            }
            free(B[i]);
        }
        free(B);
    }
}
