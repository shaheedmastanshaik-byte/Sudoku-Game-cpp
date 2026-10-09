# Sudoku-Game-cpp
sudoku game development in c++
 #include <iostream> 
#include <fstream>
 #include <ctime>
 #include <cstdlib>
 #include <algorithm>

using namespace std;

// ---- Player Class  ----


class Player

{

private:

int score;
 int mistakes; 
time_t startTime;

public:

Player()

{
score=1000;
mistakes=0;
startTime=time(0);
}
void addScore(int s)
{
score+=s;
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

return time(0) - startTime;
}
};






