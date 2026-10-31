#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

#include <array>
#include <string>

class SudokuBoard {
private:
    std::array<std::array<int, 9>, 9> board{};
    std::array<std::array<int, 9>, 9> solution{};
    std::array<std::array<bool, 9>, 9> fixed{};

    bool isSafe(int row, int col, int num) const;
    bool fillSolution();

public:
    void generate(int emptyCells);
    void display() const;
    bool isFixed(int row, int col) const;
    int getSolution(int row, int col) const;
    bool set(int row, int col, int num);
    bool isComplete() const;
    bool hint(int& row, int& col, int& value);
    void autoFix();
    bool save(const std::string& filename) const;
    bool load(const std::string& filename);
};

#endif