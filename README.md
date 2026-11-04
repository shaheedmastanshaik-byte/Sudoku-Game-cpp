🎮 Sudoku Game – C++

A console-based Sudoku puzzle game developed using C++. The project provides an interactive puzzle-solving experience with randomly generated Sudoku boards, difficulty levels, score tracking, hints, automatic mistake correction, and game progress saving.

📌 Project Overview

Sudoku Game is a C++ mini-project designed to strengthen logical thinking and problem-solving skills while demonstrating practical implementation of Object-Oriented Programming concepts.

Players can generate Sudoku puzzles, enter answers, track their performance, use hints, correct mistakes, and save their progress to continue later.

✨ Features

1. Random Sudoku Generation

- Generates a complete valid 9×9 Sudoku solution.
- Randomizes number placement.
- Creates puzzles by removing selected cells.

2. Difficulty Levels

Three difficulty levels are available:

Level| Empty Cells
Easy| 30
Medium| 40
Hard| 55

3. Interactive Gameplay

- Enter row, column, and number.
- Validate player answers against the generated solution.
- Prevent modification of initially provided numbers.
- Display the Sudoku board in a structured format.

4. Scoring System

- Initial score: 1000 points.
- Correct answer: +10 points.
- Incorrect answer: -15 points.
- Hint usage: -20 points.
- AutoFix usage: -50 points.

5. Hint System

Provides the correct value for the first available empty cell.

6. AutoFix System

Automatically identifies incorrect entries and replaces them with their correct values.

7. Timer

Tracks the total time taken by the player to complete the puzzle.

8. Save and Load

- Save the current game progress.
- Store the board, solution, fixed cells, score, mistakes, and elapsed time.
- Resume a previously saved game.

9. Input Validation

Handles invalid menu choices, incorrect number formats, and out-of-range row and column inputs.

🛠️ Technologies Used

- Programming Language: C++
- Concepts: Object-Oriented Programming
- Libraries: iostream, fstream, ctime, cstdlib, algorithm, random, limits, string
- Tools: Visual Studio Code, Git, GitHub
- File Handling: C++ file streams

🧠 OOP Concepts Implemented

Concept| Implementation
Encapsulation| Private data members in classes
Constructors| Player class constructor
Classes and Objects| Player, SudokuBoard, SudokuGame
Composition| SudokuGame contains Player and SudokuBoard objects
Abstraction| Game operations are organized into methods

⚙️ Sudoku Generation Algorithm

The project uses Recursion and Backtracking to generate a complete valid Sudoku solution.

1. Start filling the Sudoku grid cell by cell.
2. Randomly shuffle numbers from 1 to 9.
3. Check whether a number can be placed without violating Sudoku rules.
4. If valid, place the number and move to the next cell.
5. If no valid number is available, backtrack and try another possibility.
6. Once the grid is complete, remove selected cells to create the puzzle.

📂 Project Structure

Sudoku-Game-cpp/
│
├── include/
│   └── Header files
│
├── src/
│   └── Source files
│
├── main.cpp
│
└── README.md

🚀 How to Run the Project

Prerequisites

- C++ compiler (GCC / MinGW)
- Visual Studio Code or any C++ IDE
- C++11 or later

Step 1: Clone the Repository

git clone https://github.com/shaheedmastanshaik-byte/Sudoku-Game-cpp.git

Step 2: Open the Project

cd Sudoku-Game-cpp

Step 3: Compile

If the complete implementation is in "main.cpp":

g++ -std=c++11 main.cpp -o sudoku

If the implementation is distributed across "src/" and "include/", compile all required ".cpp" files together using the appropriate include path.

Step 4: Run

On Windows:

sudoku.exe

On Linux:

./sudoku

🎯 Project Objectives

- Develop an interactive Sudoku game using C++.
- Apply Object-Oriented Programming principles.
- Understand recursion and backtracking algorithms.
- Implement random puzzle generation.
- Practice file handling through save and load functionality.
- Improve logical thinking and problem-solving skills.

🔮 Future Enhancements

- Implement puzzle generation with guaranteed unique solutions.
- Introduce a more intelligent difficulty classification system.
- Add undo and redo functionality.
- Introduce a leaderboard and player profiles.
- Improve the user interface with a graphical interface.
- Add Sudoku solving assistance and advanced hints.

👥 Team Members

- Shaheed Mastan Shaik
- M. Jeevan Kumar
- V. Manoj Kumar
- M. Sahith

📌 Project Status

The project currently supports console-based Sudoku gameplay with random puzzle generation, difficulty selection, score tracking, hints, AutoFix, timer, and save/load functionality.

---

Developed with C++ | Sudoku Game Project