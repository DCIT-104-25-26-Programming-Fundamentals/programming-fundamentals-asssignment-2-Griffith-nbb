// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ---------- helper to display a matrix neatly ----------
void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// ---------- PART A: Transpose ----------
void transposeMatrix(int matrix[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// ---------- PART B: Add two matrices ----------
void addMatrices(int a[10][10], int b[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// ---------- PART C: Multiply two matrices ----------
void multiplyMatrices(int a[10][10], int b[10][10], int m, int n, int p, int result[10][10]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matrix[10][10];
    int rows, cols;

    // ----- PART A: Transpose -----
    cout << "=== PART A: Transpose a Matrix ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    int transposed[10][10];
    transposeMatrix(matrix, rows, cols, transposed);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix, rows, cols);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, cols, rows);

    // ----- PART B: Add two matrices -----
    cout << "\n=== PART B: Add Two Matrices ===" << endl;
    int a[10][10], b[10][10];
    int addRows, addCols;
    cout << "Enter number of rows: ";
    cin >> addRows;
    cout << "Enter number of columns: ";
    cin >> addCols;

    cout << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < addRows; i++) {
        for (int j = 0; j < addCols; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    cout << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < addRows; i++) {
        for (int j = 0; j < addCols; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> b[i][j];
        }
    }

    int sum[10][10];
    addMatrices(a, b, addRows, addCols, sum);

    cout << "\nSum Matrix (A + B):" << endl;
    printMatrix(sum, addRows, addCols);

    // ----- PART C: Multiply two matrices -----
    cout << "\n=== PART C: Multiply Two Matrices ===" << endl;
    int m, n, p;
    int matA[10][10], matB[10][10];

    cout << "Enter rows of Matrix A (M): ";
    cin >> m;
    cout << "Enter columns of Matrix A / rows of Matrix B (N): ";
    cin >> n;
    cout << "Enter columns of Matrix B (P): ";
    cin >> p;

    cout << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> matA[i][j];
        }
    }

    cout << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> matB[i][j];
        }
    }

    int product[10][10];
    multiplyMatrices(matA, matB, m, n, p, product);

    cout << "\nProduct Matrix (A x B):" << endl;
    printMatrix(product, m, p);

    return 0;
}

