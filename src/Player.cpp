#include "../include/Player.h"
#include <algorithm>

void Player::addCorrectMove() {
    score += 10;
}

void Player::addMistake() {
    ++mistakes;
    score = std::max(0, score - 15);
}

void Player::useHint() {
    score = std::max(0, score - 20);
}

void Player::useAutoFix() {
    score = std::max(0, score - 50);
}

int Player::getScore() const {
    return score;
}

int Player::getMistakes() const {
    return mistakes;
}

int Player::getElapsedSeconds() const {
    return static_cast<int>(
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::steady_clock::now() - startTime
        ).count()
    );
}