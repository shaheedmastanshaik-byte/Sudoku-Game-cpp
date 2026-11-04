
#ifndef SUDOKUGAME_H
#define SUDOKUGAME_H

#include "SudokuBoard.h"
#include "Player.h"

class SudokuGame {
private:
    SudokuBoard board;
    Player player;

    int readNumber(const char* message);
    void displayCompletion();

public:
    SudokuGame();

    void start();
    void play();
};

#endif
