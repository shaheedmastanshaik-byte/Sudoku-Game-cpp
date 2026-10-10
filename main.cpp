#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

// ---------------- PLAYER CLASS ----------------
class Player
{
private:
    int score;
    int mistakes;
    time_t startTime;

public:
    Player()
    {
        score = 1000;
        mistakes = 0;
        startTime = time(0);
    }

    void addScore(int s)
    {
        score += s;
    }
