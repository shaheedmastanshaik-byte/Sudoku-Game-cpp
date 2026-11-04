
#include "SudokuBoard.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

// Check whether a number can be placed safely
bool SudokuBoard::isSafe(int row, int col, int value) const {

    // Check row and column
    for (int i = 0; i < 9; i++) {
        if (solution[row][i] == value)
            return false;

        if (solution[i][col] == value)
            return false;
    }

    // Check 3x3 box
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (solution[i][j] == value)
                return false;
        }
    }

    return true;
}


// Generate a complete Sudoku solution using backtracking
bool SudokuBoard::fillSolution(int cell) {

    if (cell == 81)
        return true;

    int row = cell / 9;
    int col = cell % 9;

    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    shuffle(numbers.begin(), numbers.end(), rng);

    for (int value : numbers) {

        if (isSafe(row, col, value)) {

            solution[row][col] = value;

            if (fillSolution(cell + 1))
                return true;

            solution[row][col] = 0;
        }
    }

    return false;
}


// Generate a Sudoku puzzle
bool SudokuBoard::generate(int emptyCells) {

    if (emptyCells < 0 || emptyCells > 81)
        return false;

    // Reset arrays
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = 0;
            solution[i][j] = 0;
            fixed[i][j] = false;
        }
    }

    // Generate complete solution
    if (!fillSolution())
        return false;

    // Copy solution into playable board
    board = solution;

    // Create a list of all cell positions
    vector<int> positions;

    for (int i = 0; i < 81; i++)
        positions.push_back(i);

    shuffle(positions.begin(), positions.end(), rng);

    // Remove random cells
    for (int i = 0; i < emptyCells; i++) {

        int position = positions[i];

        int row = position / 9;
        int col = position % 9;

        board[row][col] = 0;
    }

    // Mark remaining cells as fixed
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fixed[i][j] = (board[i][j] != 0);
        }
    }

    return true;
}


// Display the Sudoku board
void SudokuBoard::display() const {

    cout << "\n";

    cout << "       S U D O K U\n\n";

    cout << "    1 2 3   4 5 6   7 8 9\n";

    cout << "  +-------+-------+-------+\n";

    for (int i = 0; i < 9; i++) {

        cout << i + 1 << " | ";

        for (int j = 0; j < 9; j++) {

            if (board[i][j] == 0)
                cout << ". ";
            else
                cout << board[i][j] << " ";

            if ((j + 1) % 3 == 0)
                cout << "| ";
        }

        cout << "\n";

        if ((i + 1) % 3 == 0)
            cout << "  +-------+-------+-------+\n";
    }

    cout << "\n";
}


// Check whether a cell is fixed
bool SudokuBoard::isFixed(int row, int col) const {

    if (row < 0 || row >= 9 || col < 0 || col >= 9)
        return false;

    return fixed[row][col];
}


// Get the value of a particular cell
int SudokuBoard::getValue(int row, int col) const {

    if (row < 0 || row >= 9 || col < 0 || col >= 9)
        return -1;

    return board[row][col];
}


// Place a number in the board
bool SudokuBoard::place(int row, int col, int value) {

    if (row < 0 || row >= 9 || col < 0 || col >= 9)
        return false;

    if (value < 1 || value > 9)
        return false;

    if (fixed[row][col])
        return false;

    board[row][col] = value;

    return true;
}


// Check whether the puzzle is completed correctly
bool SudokuBoard::isComplete() const {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == 0)
                return false;

            if (board[i][j] != solution[i][j])
                return false;
        }
    }

    return true;
}


// Give a hint by filling the first empty cell
bool SudokuBoard::giveHint() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == 0) {

                board[i][j] = solution[i][j];

                return true;
            }
        }
    }

    return false;
}


// Automatically correct incorrect entries
bool SudokuBoard::autoFix() {

    bool corrected = false;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (!fixed[i][j] &&
                board[i][j] != 0 &&
                board[i][j] != solution[i][j]) {

                board[i][j] = solution[i][j];

                corrected = true;
            }
        }
    }

    return corrected;
}


// Save the Sudoku board to a file
bool SudokuBoard::save(const string& filename) const {

    ofstream file(filename);

    if (!file.is_open())
        return false;

    file << "SUDOKU_BOARD_V1\n";

    // Save current board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            file << board[i][j] << " ";
        }
        file << "\n";
    }

    // Save solution
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            file << solution[i][j] << " ";
        }
        file << "\n";
    }

    // Save fixed cell information
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            file << fixed[i][j] << " ";
        }
        file << "\n";
    }

    file.close();

    return true;
}


// Load the Sudoku board from a file
bool SudokuBoard::load(const string& filename) {

    ifstream file(filename);

    if (!file.is_open())
        return false;

    string version;

    file >> version;

    if (version != "SUDOKU_BOARD_V1")
        return false;

    array<array<int, 9>, 9> tempBoard{};
    array<array<int, 9>, 9> tempSolution{};
    array<array<bool, 9>, 9> tempFixed{};

    // Read current board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (!(file >> tempBoard[i][j]))
                return false;

            if (tempBoard[i][j] < 0 || tempBoard[i][j] > 9)
                return false;
        }
    }

    // Read solution
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (!(file >> tempSolution[i][j]))
                return false;

            if (tempSolution[i][j] < 1 || tempSolution[i][j] > 9)
                return false;
        }
    }

    // Read fixed cells
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            int value;

            if (!(file >> value))
                return false;

            if (value != 0 && value != 1)
                return false;

            tempFixed[i][j] = (value == 1);

            if (tempFixed[i][j] &&
                tempBoard[i][j] != tempSolution[i][j])
                return false;
        }
    }

    // Validate that the saved solution is a valid Sudoku
    for (int i = 0; i < 9; i++) {

        bool rowSeen[10] = {};
        bool colSeen[10] = {};

        for (int j = 0; j < 9; j++) {

            int rowValue = tempSolution[i][j];
            int colValue = tempSolution[j][i];

            if (rowSeen[rowValue] || colSeen[colValue])
                return false;

            rowSeen[rowValue] = true;
            colSeen[colValue] = true;
        }
    }

    for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {

            bool seen[10] = {};

            for (int i = boxRow; i < boxRow + 3; i++) {
                for (int j = boxCol; j < boxCol + 3; j++) {

                    int value = tempSolution[i][j];

                    if (seen[value])
                        return false;

                    seen[value] = true;
                }
            }
        }
    }

    // Update actual board only after successful validation
    board = tempBoard;
    solution = tempSolution;
    fixed = tempFixed;

    return true;
}
