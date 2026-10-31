#ifndef PLAYER_H
#define PLAYER_H

#include <chrono>

class Player {
private:
    int score = 1000;
    int mistakes = 0;

    std::chrono::steady_clock::time_point startTime =
        std::chrono::steady_clock::now();

public:
    void addCorrectMove();
    void addMistake();
    void useHint();
    void useAutoFix();

    int getScore() const;
    int getMistakes() const;
    int getElapsedSeconds() const;
};

#endif