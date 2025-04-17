/**
CMSC313 0830 MW
Name: Tyler Peacock
email: pg84571@umbc.edu
HW8 C++ version
**/
#include <iostream>
using namespace std;

const int MAX = 10;

class Matrix {
public:
    Matrix() {
        m_row = 0;
        m_col = 0;
    }

    Matrix(int row, int col, int data[MAX][MAX]) {
        initializeMatrix(row, col, data);
    }

    Matrix(const Matrix& rhs) {
        m_row = rhs.m_row;
        m_col = rhs.m_col;
        for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < m_col; j++) {
                m_data[i][j] = rhs.m_data[i][j];
            }
        }

    }

    Matrix& operator=(const Matrix& rhs) {
        if (this != &rhs) {
            m_row = rhs.m_row;
            m_col = rhs.m_col;
            for (int i = 0; i < m_row; i++) {
                for (int j = 0; j < m_col; j++) {
                    m_data[i][j] = rhs.m_data[i][j];
                }
            }
        }
        return *this;
    }

    void setRows(int row) { m_row = row; }
    void setCols(int col) { m_col = col; }

    void printMatrix() const {
        for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < m_col; j++) {
                cout << m_data[i][j] << " ";
            }
            cout << endl;
        }
    }

    void initializeMatrix(int row, int col, int data[MAX][MAX]) {
        m_row = row;
        m_col = col;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                m_data[i][j] = data[i][j];
            }
        }
    }

    int getRow() const { return m_row; }
    int getCol() const { return m_col; }
    int getElement(int row, int col) const { return m_data[row][col]; }
    void setElement(int row, int col, int value) { m_data[row][col] = value; }

private:
    int m_data[MAX][MAX];
    int m_row, m_col;
};

class MatrixCalculator {
public:
    void addMatrices(const Matrix& matrix1, const Matrix& matrix2, Matrix& resultMatrix) {
        resultMatrix.setRows(matrix1.getRow());
        resultMatrix.setCols(matrix1.getCol());
        for (int i = 0; i < matrix1.getRow(); i++) {
            for (int j = 0; j < matrix1.getCol(); j++) {
                resultMatrix.setElement(i, j, matrix1.getElement(i, j) + matrix2.getElement(i, j));
            }
        }
    }

    void subtractMatrices(const Matrix& matrix1, const Matrix& matrix2, Matrix& resultMatrix) {
        resultMatrix.setRows(matrix1.getRow());
        resultMatrix.setCols(matrix1.getCol());
        for (int i = 0; i < matrix1.getRow(); i++) {
            for (int j = 0; j < matrix1.getCol(); j++) {
                resultMatrix.setElement(i, j, matrix1.getElement(i, j) - matrix2.getElement(i, j));
            }
        }
    }

    void multiplyMatrices(const Matrix& matrix1, const Matrix& matrix2, Matrix& resultMatrix) {
        int rows = matrix1.getRow();
        int cols = matrix2.getCol();
        int sharedDimension = matrix1.getCol();

        resultMatrix.setRows(rows);
        resultMatrix.setCols(cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int sum = 0;
                for (int k = 0; k < sharedDimension; k++) {
                    sum += matrix1.getElement(i, k) * matrix2.getElement(k, j);
                }
                resultMatrix.setElement(i, j, sum);
            }
        }
    }

    void scaleMatrix(Matrix& matrix, int scale) {
        for (int i = 0; i < matrix.getRow(); i++) {
            for (int j = 0; j < matrix.getCol(); j++) {
                matrix.setElement(i, j, matrix.getElement(i, j) * scale);
            }
        }
    }

    void transposeMatrix(const Matrix& matrix, Matrix& resultMatrix) {
        resultMatrix.setRows(matrix.getCol());
        resultMatrix.setCols(matrix.getRow());
        for (int i = 0; i < matrix.getRow(); i++) {
            for (int j = 0; j < matrix.getCol(); j++) {
                resultMatrix.setElement(j, i, matrix.getElement(i, j));
            }
        }
    }
};

int main() {
    MatrixCalculator matrixCalculator;
    int dataA[MAX][MAX] = {{6, 4}, {8, 3}};
    int dataB[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}};
    int dataC[MAX][MAX] = {{2, 4, 6}, {1, 3, 5}};

    Matrix matrixA(2, 2, dataA);
    Matrix matrixB(2, 3, dataB);
    Matrix matrixC(2, 3, dataC);
    Matrix matrixD; // Final result
    Matrix resultMatrix1, resultMatrix2;

    cout << "Matrix A:" << endl;
    matrixA.printMatrix();
    cout << "Matrix B:" << endl;
    matrixB.printMatrix();
    cout << "Matrix C:" << endl;
    matrixC.printMatrix();

    cout << "Calculating A + (3 * B) x C^T" << endl;

    matrixCalculator.transposeMatrix(matrixC, resultMatrix1);
    matrixCalculator.scaleMatrix(matrixB, 3);
    matrixCalculator.multiplyMatrices(matrixB, resultMatrix1, resultMatrix2);
    matrixCalculator.addMatrices(matrixA, resultMatrix2, matrixD);

    cout << "Result:" << endl;
    matrixD.printMatrix();

    return 0;
}