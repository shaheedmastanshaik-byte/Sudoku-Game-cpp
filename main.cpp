#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <limits>
#include <string>

using namespace std;

// ---------------- PLAYER CLASS ----------------
class Player
{
private:
    int score;
    int mistakes;
    int elapsedTime;
    time_t startTime;

public:
    Player()
    {
        reset();
    }

    void reset()
    {
        score = 1000;
        mistakes = 0;
        elapsedTime = 0;
        startTime = time(0);
    }

    void addScore(int s)
    {
        score += s;
    }

    void addMistake()
    {
        mistakes++;
        score -= 15;
    }

    int getScore()
    {
        return score;
    }

    int getMistakes()
    {
        return mistakes;
    }

    int getTime()
    {
        return elapsedTime + (int)(time(0) - startTime);
    }

    // Restore player information after loading
    void restore(int s, int m, int t)
    {
        score = s;
        mistakes = m;
        elapsedTime = t;
        startTime = time(0);
    }
};


// ---------------- SUDOKU BOARD CLASS ----------------
class SudokuBoard
{
private:
    int board[9][9]{};
    int solution[9][9]{};
    bool fixed[9][9]{};

    // Random number generator
    static mt19937& getRNG()
    {
        static mt19937 rng(random_device{}());
        return rng;
    }

    // Check whether a number can be placed safely
    bool isSafe(int r, int c, int n)
    {
        for (int i = 0; i < 9; i++)
        {
            if (solution[r][i] == n)
                return false;
        }

        for (int i = 0; i < 9; i++)
        {
            if (solution[i][c] == n)
                return false;
        }

        int startRow = r - (r % 3);
        int startCol = c - (c % 3);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (solution[startRow + i][startCol + j] == n)
                    return false;
            }
        }

        return true;
    }

    // Generate complete Sudoku solution
    bool fillSolution(int r, int c)
    {
        if (r == 9)
            return true;

        if (c == 9)
            return fillSolution(r + 1, 0);

        int nums[9];

        for (int i = 0; i < 9; i++)
            nums[i] = i + 1;

        shuffle(nums, nums + 9, getRNG());

        for (int i = 0; i < 9; i++)
        {
            int n = nums[i];

            if (isSafe(r, c, n))
            {
                solution[r][c] = n;

                if (fillSolution(r, c + 1))
                    return true;

                solution[r][c] = 0;
            }
        }

        return false;
    }


public:

    // ---------------- GENERATE PUZZLE ----------------
    void generate(int removeCount)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                board[i][j] = 0;
                solution[i][j] = 0;
                fixed[i][j] = false;
            }
        }

        fillSolution(0, 0);

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                board[i][j] = solution[i][j];
                fixed[i][j] = true;
            }
        }

        if (removeCount < 0)
            removeCount = 0;

        if (removeCount > 81)
            removeCount = 81;

        int removed = 0;

        while (removed < removeCount)
        {
            uniform_int_distribution<int> dist(0, 8);

            int r = dist(getRNG());
            int c = dist(getRNG());

            if (board[r][c] != 0)
            {
                board[r][c] = 0;
                fixed[r][c] = false;
                removed++;
            }
        }
    }


    // ---------------- DISPLAY SUDOKU BOARD ----------------
    void display()
    {
        cout << "\n";
        cout << "========== SUDOKU ==========\n\n";

        for (int i = 0; i < 9; i++)
        {
            if (i % 3 == 0)
                cout << "+-------+-------+-------+\n";

            for (int j = 0; j < 9; j++)
            {
                if (j % 3 == 0)
                    cout << "| ";

                if (board[i][j] == 0)
                    cout << ". ";
                else
                    cout << board[i][j] << " ";
            }

            cout << "|\n";
        }

        cout << "+-------+-------+-------+\n";
    }


    // ---------------- CHECK FIXED CELL ----------------
    bool isFixed(int r, int c)
    {
        return fixed[r][c];
    }


    // ---------------- GET SOLUTION ----------------
    int getSol(int r, int c)
    {
        return solution[r][c];
    }


    // ---------------- SET VALUE ----------------
    void set(int r, int c, int n)
    {
        board[r][c] = n;
    }


    // ---------------- CHECK COMPLETION ----------------
    bool isComplete()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == 0)
                    return false;

                if (board[i][j] != solution[i][j])
                    return false;
            }
        }

        return true;
    }


    // ---------------- HINT SYSTEM ----------------
    bool hint()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == 0)
                {
                    board[i][j] = solution[i][j];

                    cout << "Hint used successfully!\n";

                    return true;
                }
            }
        }

        cout << "No empty cells available for a hint!\n";

        return false;
    }


    // ---------------- AUTO FIX SYSTEM ----------------
    bool autofix()
    {
        bool foundMistake = false;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != 0 &&
                    board[i][j] != solution[i][j])
                {
                    board[i][j] = solution[i][j];

                    foundMistake = true;
                }
            }
        }

        if (foundMistake)
        {
            cout << "Mistakes corrected successfully!\n";
            return true;
        }
        else
        {
            cout << "No mistakes found!\n";
            return false;
        }
    }


    // ---------------- SAVE GAME ----------------
    bool save(int score, int mistakes, int elapsedTime)
    {
        ofstream f("savegame.txt");

        if (!f)
        {
            cout << "Error saving game!\n";
            return false;
        }

        // Save file version and player details
        f << "SUDOKU_SAVE_V1\n";

        f << score << " "
          << mistakes << " "
          << elapsedTime << "\n";

        // Save board, solution and fixed cells
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                f << board[i][j] << " "
                  << solution[i][j] << " "
                  << fixed[i][j] << " ";
            }
        }

        f.close();

        if (!f)
        {
            cout << "Error writing save file!\n";
            return false;
        }

        cout << "Game Saved Successfully!\n";

        return true;
    }


    // ---------------- LOAD GAME ----------------
    bool load(int &score, int &mistakes, int &elapsedTime)
    {
        ifstream f("savegame.txt");

        if (!f)
            return false;

        string version;

        f >> version;

        if (!f || version != "SUDOKU_SAVE_V1")
        {
            cout << "Invalid or unsupported save file!\n";
            return false;
        }

        int tempScore, tempMistakes, tempTime;

        f >> tempScore >> tempMistakes >> tempTime;

        if (!f || tempMistakes < 0 || tempTime < 0)
        {
            cout << "Corrupted save file!\n";
            return false;
        }

        int tempBoard[9][9];
        int tempSolution[9][9];
        bool tempFixed[9][9];

        // Read saved information into temporary arrays
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                int fixedValue;

                f >> tempBoard[i][j]
                  >> tempSolution[i][j]
                  >> fixedValue;

                if (!f ||
                    tempBoard[i][j] < 0 || tempBoard[i][j] > 9 ||
                    tempSolution[i][j] < 1 || tempSolution[i][j] > 9 ||
                    fixedValue < 0 || fixedValue > 1)
                {
                    cout << "Corrupted save file!\n";
                    return false;
                }

                tempFixed[i][j] = (fixedValue == 1);
            }
        }

        // Restore board only after successful reading
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                board[i][j] = tempBoard[i][j];
                solution[i][j] = tempSolution[i][j];
                fixed[i][j] = tempFixed[i][j];
            }
        }

        score = tempScore;
        mistakes = tempMistakes;
        elapsedTime = tempTime;

        f.close();

        return true;
    }
};


// ---------------- SUDOKU GAME CLASS ----------------
class SudokuGame
{
private:
    SudokuBoard board;
    Player player;

    // Safe integer input
    bool readNumber(string message, int &value)
    {
        while (true)
        {
            cout << message;

            if (cin >> value)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return true;
            }

            if (cin.eof())
                return false;

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );

            cout << "Invalid input! Please enter a number.\n";
        }
    }

    // Display completion message
    bool checkCompletion()
    {
        if (board.isComplete())
        {
            cout << "\n================================\n";
            cout << "       SUDOKU COMPLETED!\n";
            cout << "================================\n";

            cout << "Completed in "
                 << player.getTime()
                 << " seconds!\n";

            cout << "Final Score: "
                 << player.getScore()
                 << "\n";

            cout << "Total Mistakes: "
                 << player.getMistakes()
                 << "\n";

            return true;
        }

        return false;
    }


public:

    // ---------------- START GAME ----------------
    void start()
    {
        int choice;

        cout << "\n=============================\n";
        cout << "        SUDOKU GAME\n";
        cout << "=============================\n\n";

        cout << "1. New Game\n";
        cout << "2. Load Previous Game\n";

        if (!readNumber("Choice: ", choice))
            return;

        while (choice != 1 && choice != 2)
        {
            cout << "Invalid choice! Enter 1 or 2.\n";

            if (!readNumber("Choice: ", choice))
                return;
        }

        bool loaded = false;

        if (choice == 2)
        {
            int savedScore, savedMistakes, savedTime;

            if (board.load(savedScore, savedMistakes, savedTime))
            {
                player.restore(
                    savedScore,
                    savedMistakes,
                    savedTime
                );

                cout << "\nPrevious game loaded successfully!\n";

                loaded = true;
            }
            else
            {
                cout << "\nNo valid saved game found.\n";
            }
        }

        if (!loaded)
        {
            int level;
            int removeCount;

            cout << "\nSelect Level:\n";
            cout << "1. Easy\n";
            cout << "2. Medium\n";
            cout << "3. Hard\n";

            if (!readNumber("Choice: ", level))
                return;

            while (level < 1 || level > 3)
            {
                cout << "Invalid level! Select 1, 2 or 3.\n";

                if (!readNumber("Choice: ", level))
                    return;
            }

            if (level == 1)
                removeCount = 30;

            else if (level == 2)
                removeCount = 40;

            else
                removeCount = 55;

            board.generate(removeCount);

            player.reset();

            cout << "\nNew Sudoku generated successfully!\n";
        }

        play();
    }


    // ---------------- PLAY GAME ----------------
    void play()
    {
        int ch, r, c, n;

        while (true)
        {
            board.display();

            cout << "\nScore: " << player.getScore();

            cout << " | Mistakes: "
                 << player.getMistakes();

            cout << " | Time: "
                 << player.getTime() << "s\n";

            cout << "\n1. Move";
            cout << "\n2. Hint (-20 points)";
            cout << "\n3. AutoFix (-50 points)";
            cout << "\n4. Save";
            cout << "\n5. Exit";

            cout << "\nChoice: ";

            if (!readNumber("", ch))
                break;

            // Validate menu choice
            if (ch < 1 || ch > 5)
            {
                cout << "Invalid choice! Try again.\n";
                continue;
            }

            // Exit
            if (ch == 5)
            {
                cout << "\nGame exited.\n";
                break;
            }

            // ---------------- HINT ----------------
            if (ch == 2)
            {
                if (board.hint())
                {
                    player.addScore(-20);
                    cout << "20 points deducted!\n";
                }

                if (checkCompletion())
                    break;

                continue;
            }

            // ---------------- AUTO FIX ----------------
            if (ch == 3)
            {
                if (board.autofix())
                {
                    player.addScore(-50);
                    cout << "50 points deducted!\n";
                }

                if (checkCompletion())
                    break;

                continue;
            }

            // ---------------- SAVE GAME ----------------
            if (ch == 4)
            {
                board.save(
                    player.getScore(),
                    player.getMistakes(),
                    player.getTime()
                );

                continue;
            }

            // ---------------- PLAYER MOVE ----------------
            if (!readNumber("\nEnter Row (1-9): ", r))
                break;

            if (!readNumber("Enter Column (1-9): ", c))
                break;

            if (!readNumber("Enter Number (1-9): ", n))
                break;

            // Validate row and column
            if (r < 1 || r > 9 || c < 1 || c > 9)
            {
                cout << "Invalid row or column!\n";
                continue;
            }

            // Validate number
            if (n < 1 || n > 9)
            {
                cout << "Invalid number! Enter 1 to 9.\n";
                continue;
            }

            // Convert to array index
            r--;
            c--;

            // Check fixed cell
            if (board.isFixed(r, c))
            {
                cout << "Fixed cell! You cannot change this number.\n";
                continue;
            }

            // Check answer
            if (n == board.getSol(r, c))
            {
                board.set(r, c, n);

                player.addScore(10);

                cout << "Correct move! Number placed successfully.\n";
            }
            else
            {
                // Store wrong answer so AutoFix can correct it
                board.set(r, c, n);

                player.addMistake();

                cout << "Wrong move! 15 points deducted.\n";
            }

            // Check completion
            if (checkCompletion())
                break;
        }
    }
};


// ---------------- MAIN ----------------
int main()
{
    SudokuGame game;

    game.start();

    return 0;
}