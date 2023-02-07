#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "Cell.h"
#include "Champion.hpp"
#include "Gem.hpp"
#include "Obstacle.hpp"
using namespace std;
class Map
{
private:
    int row, column;
    Cell*** board;
    Champion* c;

public:
    Map(int r, int c, Champion* champ): row(10), column(10), c(champ)
    {
        board = new Cell**[column];
        for(int i = 0; i < row; i++)
        {
            board[i] = new Cell*[row];
            for(int j = 0; j < column; j++)
            {
                board[i][j] = new Cell(i,j,'.');
            }
        }
    }
    ~Map()
    {
        for(int i = 0; i < row; i++)
        {
            for (int j= 0 ; j < column; j++)
            {
                delete board[i][j];
            }
        }
        delete board;
    }

    Champion *getC() const;
    Cell*** getBoard(){
        return board;
    }
    void print_Map();
    void randomize_map();
    bool endGame();
};

#endif //MILESTONE2_MAP_H
