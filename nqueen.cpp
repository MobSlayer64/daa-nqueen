#include <iostream>
#include <vector>
using namespace std;
//Write a program N-Queen problem using Backtracking approach.
class nqueen 
{
private:
    int rows, cols;
    vector<vector<int>> board;
    int count;
    vector<vector<vector<int>>> solutions;
    
    bool isSafe(int row, int col) {
        // Check left side of row
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 1) {
                return false;
            }
        }
        
        // Check upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }
        
        // Check lower left diagonal
        for (int i = row, j = col; i < rows && j >= 0; i++, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }
        
        return true;
    }
    
    void solve(int col) {
        // Base case: all queens placed
        if (col >= cols) {
            count++;
            solutions.push_back(board);
            return;
        }
        
        // Try placing queen in each row of current column
        for (int row = 0; row < rows; row++) {
            if (isSafe(row, col)) {
                board[row][col] = 1;
                solve(col + 1);
                board[row][col] = 0;
            }
        }
    }
    
public:
    nqueen(int r, int c) : rows(r), cols(c), count(0) {
        board.assign(rows, vector<int>(cols, 0));
    }
    
    int getQueenCount() {
        solve(0);
        return count;
    }
    
    void displayAllSolutions() {
        cout << "\n========== ALL SOLUTIONS ==========" << endl;
        for (int s = 0; s < solutions.size(); s++) {
            cout << "\nSolution " << (s + 1) << ":\n";
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (solutions[s][i][j] == 1) {
                        cout << "Q ";
                    } else {
                        cout << ". ";
                    }
                }
                cout << "\n";
            }
        }
        cout << "\n==================================\n" << endl;
    }
    
    void displayBoard() {
        cout << "\nBoard:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() 
{
    int rows, cols, queens;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout<<"enter the number of queens to be placed: ";
    cin >> queens;
    nqueen obj(rows, cols);
    int result = obj.getQueenCount();
    
    cout << "\nNumber of ways to place " << min(rows, cols) << " queens on a " 
         << rows << "x" << cols << " board: " << result << endl;
    
    obj.displayAllSolutions();
    
    return 0;
}
