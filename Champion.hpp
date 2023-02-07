#ifndef Champion_hpp
#define Champion_hpp
#include <iostream>
#include "Cell.h"
using namespace std;
class Champion :public Cell{
   private: 
    int health;
    int champ_score;
    int ability;
    bool ability_active;
    int champ_gems;
    string name;
    public : 
   Champion(int x, int y, char t,string name) : Cell (x,y,'c'){ //fee 7aga b2a we don't need el setLocation
        // wl x y coordinates dol already defines f cell fa u don't need it u can just change the location through it
        health=100;
        champ_score=0;
        champ_gems=0;
        x=0;
        y=0;
        ability=2;
        ability_active=false;
        this->name=name;
        cout<<"Constructor champion() is called"<<endl;
    }
    virtual void print_champ_info(){
        cout<<"Champion position is : X = "<<
        this->getX()<<" Y = "<<this->getY()<<" , Champion health : "<<health<<endl;
        cout<<"Champion score : "<<champ_score<<" , Champion Gems : "<<champ_gems<<endl;
        cout<<"Type : "<<name<<" , Remaning ability moves = "<<ability<<endl;
    }
    void setHealth(int health){
        this->health=health;
    if(health<0)
    this->health=0;
    if(health>100)
    this->health=100;
    }
    int getHealth(){
        return health;}
    void setChamp_score(int champ_score){
        this->champ_score=champ_score;
        if(champ_score<0)
        this->champ_score=0;
    }
    int getAbilityLeft(){
        return this->ability;
    }
    void setAbilityLeft(int ability){
        this->ability=ability;
    }
    int getchamp_score(){return champ_score;}
    virtual void useAbility(Cell*** board,char c){
        cout<<"ability x is called";
    }
    void setGems(int champ_gems){
        this->champ_gems=champ_gems;
        if(champ_gems<0)
        this->champ_gems=0;
    }
    int getGems(){
        return this->champ_gems;
    }
    virtual void abilityInfo(){}
    void luigiRemove(Cell*** board,char c);
    void move(Cell*** board,char x,int change);
};
class Mario :public Champion{

public:
    Mario(): Champion(0,0,'c',"Mario")
    {

    }
    void abilityInfo(){
        cout<<"Mario ability is jumping 2 steps in when move when u press x!!!"<<endl;
    }
    void useAbility(Cell*** board,char c){
        cout<<"Mario Ability is called"<<endl;
        this->move(board,c,2);
        setAbilityLeft(getAbilityLeft()-1);
    }

};
class Luigi :public Champion{
public:
    Luigi() : Champion (0,0,'c',"Luigi")
    {

    }
    void abilityInfo(){
        cout<<"luigi ability is clearing obstacles in single direction when u press x!!!"<<endl;
    }
    void useAbility(Cell*** board,char c){
        cout<<"Luigi Ability is called"<<endl;
        this->luigiRemove(board,c);
        setAbilityLeft(getAbilityLeft()-1);
    }
};
#endif