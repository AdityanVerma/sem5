#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // Check for queens in the same column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check for queens in the left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check for queens in the right diagonal
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to print the order of queens in a solution
void printQueenOrder(const vector<vector<int>>& board, int N) {
    vector<int> queenOrder(N, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 1) {
                queenOrder[i] = j + 1;
                break;
            }
        }
    }

    cout << "(";
    for (int i = 0; i < N; ++i) {
        cout << queenOrder[i];
        if (i < N - 1) {
            cout << ",";
        }
    }
    cout << ")";
}

// Function to print the chessboard
void printChessboard(const vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (board[i][j] == 1 ? "Q" : ".") << " ";
        }
        cout << "\n";
    }
}

// Function to solve the N-Queens problem using backtracking
void solveNQueens(vector<vector<int>>& board, int row, int N, int& solutionsCount) {
    if (row == N) {
        // All queens are placed successfully
        cout << "Solution " << solutionsCount++ << ": ";
        printQueenOrder(board, N);
        cout << "\n";
        printChessboard(board, N);
        cout << "\n\n";
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the rest of the queens
            solveNQueens(board, row + 1, N, solutionsCount);

            // Backtrack
            board[row][col] = 0;
        }
    }
}

int main() {
    clock_t t1,t2;
    float t;
    int N;
    cout << "Enter the size of the chessboard (N): ";
    cin >> N;
    t1=clock();

    vector<vector<int>> board(N, vector<int>(N, 0));
    int solutionsCount = 1;

    solveNQueens(board, 0, N, solutionsCount);

    if (solutionsCount == 1) {
        cout << "No solutions found.\n";
    }
    t2=clock();
    t=float(t2-t1)/CLOCKS_PER_SEC;
    cout << "\nProcessing Time is " << t << " seconds.\n\n";
    return 0;
}
