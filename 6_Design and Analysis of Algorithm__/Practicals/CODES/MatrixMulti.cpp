#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
// Function to perform matrix multiplication
vector<vector<int>> multiplyMatrix(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int row1 = mat1.size();
    int col1 = mat1[0].size();
    int row2 = mat2.size();
    int col2 = mat2[0].size();
    // Check if matrix multiplication is possible
    if (col1 != row2) {
        cout << "Error: Matrix dimensions are not compatible for multiplication.\n";
        return {};
    }
    // Initialize the result matrix with zeros
    vector<vector<int>> result(row1, vector<int>(col2, 0));
    // Perform matrix multiplication
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            for (int k = 0; k < col1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}
// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}
int main() {
    clock_t t1,t2;
    float t;
    t1=clock();
    // Example matrices
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> matrix2 = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    // Perform matrix multiplication
    vector<vector<int>> result = multiplyMatrix(matrix1, matrix2);
    // Print the matrices and the result
    cout << "Matrix 1:\n";
    printMatrix(matrix1);
    cout << "\nMatrix 2:\n";
    printMatrix(matrix2);
    cout << "\nResult of Matrix Multiplication:\n";
    printMatrix(result);
    t2=clock();
    t=float(t2-t1)/CLOCKS_PER_SEC;
    cout << "\nProcessing Time is " << t << " seconds.\n\n";
    return 0;
}
