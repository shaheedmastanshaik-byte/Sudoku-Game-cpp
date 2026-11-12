#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

#include <array>
#include <random>
#include <string>

class SudokuBoard {
private:
    std::array<std::array<int, 9>, 9> board{};
    std::array<std::array<int, 9>, 9> solution{};
    std::array<std::array<bool, 9>, 9> fixed{};
    std::mt19937 rng{std::random_device{}()};

    bool isSafe(int row, int col, int value) const;
    bool fillSolution(int cell = 0);

public:
    bool generate(int emptyCells);
    void display() const;
    bool isFixed(int row, int col) const;
    int getValue(int row, int col) const;
    bool place(int row, int col, int value);
    bool isComplete() const;
    bool giveHint();
    bool autoFix();
    bool save(const std::string& filename) const;
    bool load(const std::string& filename);
};

#endif