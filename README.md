🎮 Sudoku Game | C++

<p align="center">
  A Console-Based Sudoku Puzzle Game Developed Using C++
</p><p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue" />
  <img src="https://img.shields.io/badge/Standard-C%2B%2B11-orange" />
  <img src="https://img.shields.io/badge/Project-Console%20Based-green" />
  <img src="https://img.shields.io/badge/Status-In%20Development-yellow" />
</p>---

📖 1. Project Overview

Sudoku Game is a console-based puzzle application developed using C++. It provides an interactive environment where players solve randomly generated Sudoku puzzles while tracking their scores, mistakes, and completion time.

The project demonstrates the practical application of Object-Oriented Programming (OOP), recursion, backtracking, random number generation, arrays, and file handling.

The main objective is to develop a structured, modular, and interactive C++ application that combines logical problem-solving with essential software development concepts.

🎯 2. Project Objectives

1. Develop an interactive Sudoku game using C++.
2. Apply Object-Oriented Programming principles.
3. Implement random Sudoku puzzle generation.
4. Use recursion and backtracking for generating valid Sudoku solutions.
5. Develop a scoring and performance-tracking system.
6. Implement save and load functionality using file handling.
7. Improve code organization, modularity, and maintainability.

✨ 3. Key Features

3.1 Random Puzzle Generation

- Generates a complete valid 9×9 Sudoku solution.
- Uses randomized number placement.
- Removes selected cells to create playable puzzles.

3.2 Multiple Difficulty Levels

Difficulty| Empty Cells
Easy| 30
Medium| 40
Hard| 55

3.3 Interactive Gameplay

- Accepts row, column, and number as player input.
- Validates answers against the generated solution.
- Prevents modification of initially provided cells.
- Displays the Sudoku board in a structured 9×9 format.

3.4 Scoring System

Action| Score
Initial Score| 1000
Correct Move| +10
Incorrect Move| -15
Hint Usage| -20
AutoFix Usage| -50

3.5 Hint System

- Provides the correct number for the first available empty cell.
- Deducts points when a hint is used.

3.6 AutoFix System

- Identifies incorrect entries on the board.
- Automatically replaces incorrect values with their correct solutions.
- Deducts points when AutoFix is used.

3.7 Timer and Performance Tracking

- Tracks the time spent playing.
- Maintains the total number of mistakes.
- Displays final score and completion time.

3.8 Save and Resume

- Saves the current Sudoku board.
- Stores the original solution and fixed-cell information.
- Preserves score, mistakes, and elapsed time.
- Allows players to resume a previously saved game.

3.9 Input Validation

- Validates menu selections.
- Checks row and column boundaries.
- Restricts Sudoku entries to numbers between 1 and 9.
- Handles invalid numeric input.

🏗️ 4. System Architecture

The application follows a class-based architecture consisting of three primary classes.

4.1 Player Class

Responsible for maintaining player-related information.

Responsibilities:

- Maintain player score.
- Track mistakes.
- Calculate elapsed time.
- Reset and restore player information.

4.2 SudokuBoard Class

Responsible for Sudoku puzzle generation and board operations.

Responsibilities:

- Generate a valid Sudoku solution.
- Create puzzles by removing selected cells.
- Display the board.
- Validate and update player entries.
- Provide hints and automatic corrections.
- Save and load game progress.

4.3 SudokuGame Class

Responsible for controlling the overall game execution.

Responsibilities:

- Start a new game or load a previous game.
- Handle difficulty selection.
- Manage player interactions.
- Control gameplay operations.
- Display game status and completion results.

🧠 5. Core Concepts and Algorithms

Concept| Application
Object-Oriented Programming| Organizing game functionality into classes
Encapsulation| Protecting data through private members
Constructors| Initializing player information
Composition| SudokuGame contains Player and SudokuBoard objects
Recursion| Generating the Sudoku solution
Backtracking| Trying alternative numbers when a placement fails
Randomization| Shuffling numbers to create varied solutions
Two-dimensional Arrays| Representing the 9×9 Sudoku board
File Handling| Saving and restoring game progress

Sudoku Generation Algorithm

The project uses a recursive backtracking approach.

1. Initialize an empty 9×9 Sudoku solution grid.
2. Select an empty cell.
3. Shuffle numbers from 1 to 9 randomly.
4. Check whether the selected number satisfies row, column, and 3×3 subgrid constraints.
5. Place the number if it is valid.
6. Recursively move to the next cell.
7. Backtrack if no valid number can be placed.
8. Continue until a complete valid Sudoku solution is generated.
9. Remove selected cells according to the chosen difficulty level.

🛠️ 6. Technology Stack

Category| Technology
Programming Language| C++
Language Standard| C++11 or later
Compiler| GCC / MinGW
IDE| Visual Studio Code
Version Control| Git
Repository Hosting| GitHub
Data Storage| File Handling using "fstream"

Standard Libraries Used

- "iostream" – Input and output operations.
- "fstream" – File reading and writing.
- "ctime" – Time tracking.
- "cstdlib" – General utility functions.
- "algorithm" – Random shuffling.
- "random" – Random number generation.
- "limits" – Input stream validation.
- "string" – String operations.

📂 7. Project Structure

Sudoku-Game-cpp/
│
├── include/
│   ├── Player.h
│   ├── SudokuBoard.h
│   └── SudokuGame.h
│
├── src/
│   ├── Player.cpp
│   ├── SudokuBoard.cpp
│   └── SudokuGame.cpp
│
├── main.cpp
│
├── README.md
│
└── savegame.txt       # Generated during game saving

Note: The above represents the planned modular structure. File names should be adjusted to match the final repository implementation.

⚙️ 8. Installation and Execution

Prerequisites

1. GCC or MinGW C++ compiler.
2. Visual Studio Code or another C++ IDE.
3. C++11 or later support.

Step 1: Clone the Repository

git clone https://github.com/shaheedmastanshaik-byte/Sudoku-Game-cpp.git

Step 2: Navigate to the Project Directory

cd Sudoku-Game-cpp

Step 3: Compile the Project

For the current single-file implementation:

g++ -std=c++11 main.cpp -o sudoku

For the modular implementation, compile all source files together:

g++ -std=c++11 -Iinclude main.cpp src/*.cpp -o sudoku

Step 4: Run the Application

Windows:

sudoku.exe

Linux / macOS:

./sudoku

🧪 9. Testing and Validation

The following scenarios should be verified during testing:

1. Verify that generated Sudoku solutions satisfy row, column, and subgrid constraints.
2. Verify that all three difficulty levels generate the requested number of empty cells.
3. Check that fixed cells cannot be modified.
4. Verify correct and incorrect answer handling.
5. Check score deductions and additions.
6. Verify Hint and AutoFix functionality.
7. Test timer accuracy.
8. Verify that saved games can be restored correctly.
9. Test invalid menu choices and numeric inputs.
10. Verify the completion condition and final score display.

🔮 10. Future Enhancements

1. Unique Puzzle Generation: Ensure every generated puzzle has exactly one solution.
2. Advanced Difficulty Classification: Introduce difficulty levels based on solving techniques rather than only the number of empty cells.
3. Undo and Redo: Allow players to reverse or restore previous moves.
4. Leaderboard: Maintain player rankings and high scores.
5. Player Profiles: Introduce individual player accounts and performance history.
6. Advanced Hints: Provide logical explanations instead of directly revealing answers.
7. Graphical User Interface: Develop a more interactive visual Sudoku experience.
8. Automated Testing: Introduce unit tests for puzzle generation, validation, scoring, and saving.

👥 11. Team Members

S. No.| Name
1| Shaheed Mastan Shaik
2| M. Jeevan Kumar
3| V. Manoj Kumar
4| M. Sabith

📌 12. Project Status

The project currently includes console-based Sudoku gameplay, randomized solution generation, three difficulty levels, score tracking, a timer, hints, automatic mistake correction, and save/load functionality.

Further improvements are planned to enhance puzzle quality, modularity, testing, and user experience.

---

<p align="center">
  <b>Developed with ❤️ using C++</b>
  <br/>
  <i>Sudoku Game – A Logical Approach to Problem Solving</i>
</p>