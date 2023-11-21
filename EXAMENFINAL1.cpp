#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 30


void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void multiplyMatrices(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
 
    srand(time(NULL));

    
    int matrix1[SIZE][SIZE];
    int matrix2[SIZE][SIZE];
    int resultMatrix[SIZE][SIZE];

    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }
    }


    printf("Matriz 1:\n");
    printMatrix(matrix1);
    printf("\nMatriz 2:\n");
    printMatrix(matrix2);

  
    clock_t start_time = clock();
    multiplyMatrices(matrix1, matrix2, resultMatrix);
    clock_t end_time = clock();
    
    
    printf("\nResultado de la multiplicación:\n");
    printMatrix(resultMatrix);

   
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000.0;
    printf("\nTiempo de ejecución: %.2f milisegundos\n", elapsed_time);

    return 0;
}

