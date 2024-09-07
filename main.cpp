#include <iostream>
#include <vector>

using namespace std;
int moves = 0;

// Display
vector<vector<char>> display(vector<vector<char>> board3, int size) {
    int num = 0;

    cout << " ";
    for (int i = 1; i <= size; i++) {
        cout << " " << i;
    }
    cout << endl;
    for (auto row : board3) {
        num++;
        cout << num;
        for (char column : row) {
            cout << "|" << column;
        }
        cout << "|" << endl;
    
    }
    return board3;
}

// Turn
vector<vector<char>> turn (vector<vector<char>> board2, int size) {
    int row, column;
    
    char X_O = (moves % 2 == 0)? 'X' : 'O';
    cout << X_O << "'s turn (enter coordinate: row, column)\n" << "Row: ";
    cin >> row;
    cout << "Column: ";
    cin >> column;
        
    while (row > size || column > size || row < 0 || column < 0 || board2[row-1][column-1] != ' ') {
        cout << "Invalid input.\n";
        cout << X_O << "'s turn (enter coordinate: row, column)\n" << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> column;
    }
    board2[row-1][column-1] = X_O;
    moves++;
        
    display(board2, size);
    return board2;
}

// Checking for game result
int check(int move, vector<vector<char>> board4, int wincondition, int size) {

    int x_inarow = 0, o_inarow = 0;

    // Rows
    for (auto rows : board4) {
        for (char i : rows) {
            if (i == 'X') {
                x_inarow++;
                o_inarow = 0;
            } else if (i == 'O') {
                o_inarow++;
                x_inarow = 0;
            } else {
                o_inarow = 0;
                x_inarow = 0;
            }
        }
        if (x_inarow == wincondition) {
            return 1;
            break;
        } else if (o_inarow == wincondition) {
            return 2;
            break;
        }   
    }

    // Columns
    for (int j = 0; j < size; j++) {
        int x_inarow = 0, o_inarow = 0;
        for (int i = 0; i < size; i++) {
            if (board4[i][j] == 'X') {
                x_inarow++;
                o_inarow = 0;
            } else if (board4[i][j] == 'O') {
                o_inarow++;
                x_inarow = 0;
            } else {
                x_inarow = 0;
                o_inarow = 0;
            }
           
            if (x_inarow == wincondition) {
                return 1;
            } else if (o_inarow == wincondition) {
                return 2;
            }
            
        }
    }
    
    // Diagonals
    for (int i = 0; i <= size - wincondition; i++) {
    for (int j = 0; j <= size - wincondition; j++) {
        int x_inarow = 0, y_inarow = 0;
        for (int k = 0; k < wincondition; k++) {
            if (board4[i + k][j + k] == 'X') {
                x_inarow++;
                y_inarow = 0;
            } else if (board4[i + k][j + k] == 'O') {
                y_inarow++;
                x_inarow = 0;
            } else {
                x_inarow = 0;
                y_inarow = 0;
            }
            if (x_inarow == wincondition) {
                return 1;
            } else if (o_inarow == wincondition) {
                return 2;
            }
        }
    }
    }

    return 0;
}



int main () {

    int size, wincondition;

    cout << "Board size (3x3 to 10x10): ";
    cin >> size;
    cout << "How many in a row is needed to win? ";
    cin >> wincondition;
    while (wincondition > size) {
        cout << "The input is either invalid or higher than board size\n";
        cout << "How many in a row is needed to win? ";
        cin >> wincondition;
    }

    while (size < 3 || size > 10) {
        cout << "Board size must be between 3x3 and 10x10.\n";
        cin >> size;
    }

    vector<vector<char>> board(size, vector<char>(size, ' '));
    display(board, size);

    while (moves < size*size) {
    board = turn (board, size);
    cout << check(moves, board, wincondition, size) << endl;
    }

    return 0;
}
