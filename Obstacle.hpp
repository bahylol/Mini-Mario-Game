
#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include<iostream>
#include <cstdlib>
#include<time.h>
#include "Cell.h"
#include "Champion.hpp"
using namespace std;

class Obstacle : public Cell {
private:
    int damage;
public:
    Obstacle(int x, int y , char t ,int damage) : Cell(x,y,'o')
    {
        this->damage = damage;
    }
    int getDamage(){
        return damage;
    }
    virtual void execute(Champion *c){
        cout<<"obstacle called"<<endl;
    }
};

class Bomb: public Obstacle{
public:
    Bomb(int x, int y , char t ,int damage)  : Obstacle(x,y,'o',damage)
    {
    }
    void execute(Champion *c){
        c->setHealth(c->getHealth()-this->getDamage());
        cout<<"Bomb excecuted with damage = "<<this->getDamage()<<endl;
    }
};

class Thief: public Obstacle{
public :
    Thief(int x, int y , char t ,int damage)  : Obstacle(x,y,'o',damage)
    {
    }
    void execute(Champion *c){
        srand(time(0));
        int num=0;
        if(c->getGems()-this->getDamage()<0){
         num=this->getDamage()-c->getGems();
         }
        else 
        num=this->getDamage();
        c->setGems(c->getGems()-this->getDamage());
        c->setChamp_score(c->getchamp_score()-(num*((rand() % 5) + 1)));
        cout<<"Thief excecuted with damage = "<<this->getDamage()<<endl;
    }
};


#endif //MILESTONE2_OBSTACLE_HPP
