/**
CMSC313 0830 MW
Name: Tyler Peacock
email: pg84571@umbc.edu
HW8 C version
**/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // max allowed matrix dimensions

// Function prototypes
void inputMatrixElements(int matrix[MAX][MAX], int rows, int cols);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols, int *resRows, int *resCols);
void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols, int *resRows, int *resCols);
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rA, int cA, int cB, int *resRows, int *resCols);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols, int *resRows, int *resCols);
void scaleMatrix(int matrix[MAX][MAX], int rows, int cols, int scale);

int main() {
    int matrixA[MAX][MAX] = {{6,4},{8,3}};
    int matrixB[MAX][MAX] = {{1,2,3},{4,5,6}};
    int matrixC[MAX][MAX] = {{2,4,6},{1,3,5}};
    int matrixD[MAX][MAX];
    int result1[MAX][MAX], result2[MAX][MAX];
    int rA = 2, cA = 2, rB = 2, cB = 3, rC = 2, cC = 3;
    int rD, cD;
    int res1Row, res1Col, res2Row, res2Col;

    /**
    printf("Enter elements for Matrix A (%dx%d):\n", rA, cA);
    inputMatrixElements(matrixA, rA, cA);
    printf("Enter elements for Matrix B (%dx%d):\n", rB, cB);
    inputMatrixElements(matrixB, rB, cB);
    printf("Enter elements for Matrix C (%dx%d):\n", rC, cC);
    inputMatrixElements(matrixC, rC, cC);
    **/

    printf("Matrix A:\n");
    printMatrix(matrixA, rA, cA);
    printf("Matrix B:\n");
    printMatrix(matrixB, rB, cB);
    printf("Matrix C:\n");
    printMatrix(matrixC, rC, cC);

    printf("Calculating A + (3 * B) x C^T\n");

    // transpose matrixC, store in result1
    transposeMatrix(matrixC, result1, rC, cC, &res1Row, &res1Col);

    // scale matrixB by 3
    scaleMatrix(matrixB, rB, cB, 3);

    // multiply (3*B) x C^T store in result 2
    multiplyMatrices(matrixB, result1, result2, rB, cB, res1Col, &res2Row, &res2Col);

    // add matrixA + result2
    addMatrices(matrixA, result2, matrixD, rA, cA, &rD, &cD);

    printf("Result:\n");
    printMatrix(matrixD, rD, cD);

    return 0;
}

// Function definitions
/**
void inputMatrixElements(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}
**/
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols, int *resRows, int *resCols) {
    *resRows = rows;
    *resCols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols, int *resRows, int *resCols) {
    *resRows = rows;
    *resCols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rA, int cA, int cB, int *resRows, int *resCols) {
    *resRows = rA;
    *resCols = cB;
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols, int *resRows, int *resCols) {
    *resRows = cols;
    *resCols = rows;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void scaleMatrix(int matrix[MAX][MAX], int rows, int cols, int scale) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] *= scale;
        }
    }
}