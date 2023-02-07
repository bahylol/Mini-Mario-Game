#ifndef Gem_hpp
#define Gem_hpp
#include <iostream>
#include<time.h>
#include "Champion.hpp"
#include "Cell.h"
using namespace std;

//mwdoo3 el gems

class Gem :public Cell{

private : 
int amount;
public :
Gem(int x, int y,char t,int amount) : Cell(x,y,'g'){
    this->amount=amount;
}

int getAmount(){
    return amount;
}

virtual void execute(Champion *c){
    cout<<"Gem executed"<<endl;
}

};
class Potion : public Gem{
public :
Potion(int x, int y,char t,int amount) : Gem(x,y,'g',amount){
}
void execute(Champion *c){
    c->setHealth(c->getHealth()+this->getAmount());
    c->setGems(c->getGems()+1);
    cout<<"Potion executed with points = "<<this->getAmount()<<endl;
}

};
class Coin : public Gem{
public :
Coin(int x, int y,char t,int amount) : Gem(x,y,'g',amount){
}
    void execute(Champion *c){
    c->setChamp_score(c->getchamp_score()+this->getAmount());
    c->setGems(c->getGems()+1);
    cout<<"Coin executed with points = "<<this->getAmount()<<endl;
}
};
#endif