
#include "SudokuGame.h"

#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Constructor
SudokuGame::SudokuGame() = default;


// Read and validate numerical input
int SudokuGame::readNumber(const char* message) {

    int number;

    while (true) {

        cout << message;

        if (cin >> number) {
            return number;
        }

        if (cin.eof()) {
            return -1;
        }

        cout << "Invalid input! Please enter a number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


// Display final game results
void SudokuGame::displayCompletion() {

    cout << "\n================================\n";
    cout << "       CONGRATULATIONS!\n";
    cout << "       SUDOKU COMPLETED!\n";
    cout << "================================\n";

    cout << "Final Score: " << player.getScore() << "\n";
    cout << "Mistakes: " << player.getMistakes() << "\n";
    cout << "Time Taken: " << player.getElapsedSeconds()
         << " seconds\n";

    cout << "================================\n";
}


// Main menu
void SudokuGame::start() {

    while (true) {

        cout << "\n================================\n";
        cout << "         SUDOKU GAME\n";
        cout << "================================\n";

        cout << "1. New Game\n";
        cout << "2. Load Saved Game\n";
        cout << "3. Exit\n";

        int choice = readNumber("Enter your choice: ");

        if (choice == -1 || choice == 3) {
            cout << "\nThank you for playing Sudoku!\n";
            return;
        }

        // Start a new game
        if (choice == 1) {

            cout << "\nSelect Difficulty:\n";
            cout << "1. Easy\n";
            cout << "2. Medium\n";
            cout << "3. Hard\n";

            int difficulty = readNumber("Enter difficulty: ");

            int emptyCells;

            switch (difficulty) {

                case 1:
                    emptyCells = 30;
                    break;

                case 2:
                    emptyCells = 40;
                    break;

                case 3:
                    emptyCells = 55;
                    break;

                default:
                    cout << "Invalid difficulty!\n";
                    continue;
            }

            if (!board.generate(emptyCells)) {
                cout << "Unable to generate Sudoku puzzle.\n";
                continue;
            }

            cout << "\nNew Sudoku game started!\n";

            play();
        }

        // Load saved game
        else if (choice == 2) {

            if (board.load("savegame.txt")) {

                cout << "\nSaved Sudoku board loaded successfully!\n";

                play();
            }
            else {
                cout << "\nNo valid saved game found!\n";
            }
        }

        else {
            cout << "\nInvalid choice! Try again.\n";
        }
    }
}


// Main gameplay function
void SudokuGame::play() {

    while (true) {

        // Display current board
        board.display();

        // Check completion
        if (board.isComplete()) {

            displayCompletion();
            return;
        }

        cout << "\n========== GAME MENU ==========\n";

        cout << "1. Enter a Number\n";
        cout << "2. Get a Hint\n";
        cout << "3. Auto Fix\n";
        cout << "4. Save Game\n";
        cout << "5. Exit to Main Menu\n";

        cout << "================================\n";

        int choice = readNumber("Enter your choice: ");

        if (choice == -1) {
            return;
        }

        // Enter a number
        if (choice == 1) {

            int row = readNumber("Enter row (1-9): ");
            int col = readNumber("Enter column (1-9): ");
            int value = readNumber("Enter number (1-9): ");

            if (row == -1 || col == -1 || value == -1) {
                return;
            }

            // Validate input range
            if (row < 1 || row > 9 ||
                col < 1 || col > 9 ||
                value < 1 || value > 9) {

                cout << "\nInvalid position or number!\n";

                player.addMistake();
                continue;
            }

            // Convert to zero-based indexing
            row--;
            col--;

            // Check whether cell is fixed
            if (board.isFixed(row, col)) {

                cout << "\nThis cell cannot be changed!\n";

                player.addMistake();
                continue;
            }

            // Place number
            if (board.place(row, col, value)) {

                cout << "\nNumber placed successfully!\n";
            }
            else {

                cout << "\nUnable to place number!\n";

                player.addMistake();
            }
        }

        // Get a hint
        else if (choice == 2) {

            if (board.giveHint()) {

                player.useHint();

                cout << "\nHint used successfully!\n";
            }
            else {

                cout << "\nNo empty cells available!\n";
            }
        }

        // Auto Fix
        else if (choice == 3) {

            if (board.autoFix()) {

                player.useAutoFix();

                cout << "\nIncorrect entries have been corrected!\n";
            }
            else {

                cout << "\nNo incorrect entries found!\n";
            }
        }

        // Save game
        else if (choice == 4) {

            if (board.save("savegame.txt")) {

                cout << "\nGame saved successfully!\n";
            }
            else {

                cout << "\nUnable to save the game!\n";
            }
        }

        // Exit to main menu
        else if (choice == 5) {

            cout << "\nReturning to main menu...\n";

            return;
        }

        else {

            cout << "\nInvalid choice! Try again.\n";
        }
    }
}
