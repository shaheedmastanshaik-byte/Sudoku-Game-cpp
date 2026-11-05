






  # 🧩 C++ Console Sudoku Game

A fully featured, object-oriented, cross-platform console Sudoku application written in **C++17**. The game features dynamic backtracking puzzle generation, a multi-tier difficulty system, real-time input sanitization, non-volatile state persistence (saving and loading games), an inline timer, mistake counters, auto-correction, and an interactive scoring system.

---


## 📋 Table of Contents
1. [Key Features](#-key-features)
2. [Project Architecture & OOP Design](#-project-architecture--oop-design)
3. [File Organization](#-file-organization)
4. [Algorithm & Core Systems Explanation](#-algorithm--core-systems-explanation)
   * [Backtracking Puzzle Generator](#1-backtracking-puzzle-generator)
   * [Input Sanitization & Failure Recovery](#2-input-sanitization--failure-recovery)
   * [Save System Data Specification](#3-save-system-data-specification)
5. [Compilation & Execution Guide](#-compilation--execution-guide)
6. [Detailed Rules & Gameplay Mechanics](#-detailed-rules--gameplay-mechanics)
7. [Future Roadmap](#-future-roadmap)
8. [Contributors & Acknowledgments](#-contributors--acknowledgments)

---


## 🚀 Key Features

* **Procedural Board Generation:** Every game generates a brand-new, solvable Sudoku puzzle using a randomized recursive backtracking algorithm combined with `std::shuffle` and `std::mt19937`.
* **Selectable Difficulties:**

  * **Easy:** Removes 30 numbers (~51 initial clues).
  * **Medium:** Removes 40 numbers (~41 initial clues).
  * **Hard:** Removes 55 numbers (~26 initial clues).
* **Fault-Tolerant Input Stream:** Uses `cin.clear()` and `numeric_limits<streamsize>::max()` to gracefully recover from non-numeric user entries without crashing or looping infinitely.
* **Persistent State Management:** Save and resume games seamlessly via `savegame.txt`. Includes magic-header validation (`SUDOKU_SAVE_V1`) and numerical range checking to prevent corrupted file crashes.
* **Assistive Gameplay Features:**
  * **Hint System:** Automatically places the correct answer in the first available empty grid space (-20 score deduction).
  * **AutoFix System:** Scans the board for player errors, clears incorrect entries, and overwrites them with the generated solution (-50 score deduction).
* **Real-time Performance Metrics:** Tracks move duration in seconds (`<ctime>`), counts total invalid guesses, and updates cumulative scores.

---

## 🛠️ Project Architecture & OOP Design

The system adheres strictly to Object-Oriented Programming (OOP) principles, delegating logic across three core classes:


### 1. `Player` Class
* **Responsibility:** Manages player session metrics.
* **Key Attributes:** `score` (starts at 1000), `mistakes`, `elapsedTime`, `startTime`.
* **Key Methods:** `addScore()`, `addMistake()`, `getTime()`, `restore()`.

### 2. `SudokuBoard` Class
* **Responsibility:** Controls grid state, generation, validation rules, display formatting, and disk serialization.
* **Key Attributes:** 
  * `board[9][9]`: The active grid modified by the user.
  * `solution[9][9]`: The generated full grid solution key.
  * `fixed[9][9]`: Boolean matrix denoting initial clue cells that cannot be edited.
* **Key Methods:** `fillSolution()`, `isSafe()`, `generate()`, `display()`, `hint()`, `autofix()`, `save()`, `load()`.

### 3. `SudokuGame` Class
* **Responsibility:** Orchestrates application execution flow, level selection, player interactions, and win-condition evaluations.
* **Key Methods:** `start()`, `play()`, `readNumber()`, `checkCompletion()`.

## 📂 File Organization

```text
Sudoku-Game-cpp/
├── main.cpp          # Entry point;                  
                instantiates  and executes SudokuGame

├── Player.h          # Declaration of the Player class
├── Player.cpp        # Definition of Player methods and scoring logic
├── SudokuBoard.h     # Declaration of the SudokuBoard class
├── SudokuBoard.cpp   # Board generation, backtracking solver, save/load implementation
├── SudokuGame.h      # Declaration of the main SudokuGame controller class
├── SudokuGame.cpp    # CLI interface, move validation, game loop logic
├── savegame.txt      # (Auto-generated) Serialized state file for saved games
└── README.md         # Comprehensive project documentation
---

📋 Algorithm & Core Systems Explanation
1. Backtracking Puzzle Generator
The grid is populated using a recursive backtracking technique:
Base Case: If row == 9, the entire grid is successfully filled.
Move Execution: Fill numbers 1 through 9 into array nums[9] and randomly shuffle them using std::mt19937.
Safety Check (isSafe): Verify that number N does not exist in:
The target row R.
The target column C.
The 3 \times 3 subgrid containing cell (R, C).
Recursion & Backtracking: Place N in solution[R][C]. Recurse to column C+1. If downstream placement fails, reset solution[R][C] = 0 and attempt the next candidate.

2. Input Sanitization & Failure Recovery
Standard console C++ apps often fail when string input is passed to integer cin variables. This project handles bad inputs safely:

if (!(cin >> value)) {
    cin.clear(); // Clear stream error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid characters
    cout << "Invalid input! Please enter a number.\n";
}



👥 11. Team Members

S. No.| Name
1| Shaheed Mastan Shaik
2| M. Jeevan Kumar
3| V. Manoj Kumar
4| M. Sahith

📌 12. Project Status

The project currently includes console-based Sudoku gameplay, randomized solution generation, three difficulty levels, score tracking, a timer, hints, automatic mistake correction, and save/load functionality.

Further improvements are planned to enhance puzzle quality, modularity, testing, and user experience.

---

<p align="center">
  <b>Developed with ❤️ using C++</b>
  <br/>
  <i>Sudoku Game – A Logical Approach to Problem Solving</i>
</p>