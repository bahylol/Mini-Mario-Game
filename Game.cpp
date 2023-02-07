#include <iostream>
#include <conio.h>
#include<time.h>
#include "Map.h"
using namespace std;

ostream& operator << (ostream& os, Cell* c)
{
    return os << c->type;
}
void Map::print_Map()
{
    cout << "print_map() called" << endl;
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            cout <<" "<< board[i][j] << " ";
        }
        cout << endl;
    }
}
void Map::randomize_map() // 20 obstacles 40 gems
{
    for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                board[i][j] =new Cell(i,j,'.');
            }
        }
    board[0][0] = c;
    c->setY(0);
    c->setX(0);
    srand(time(0));
    int currentGems = 0;
    
    while (currentGems < 40)
    {
        int i = rand() % 10;
        int j = rand() % 10;
        int amount=5 +rand() % 6;
        if (i < 10 && j < 10)
        {
            if( *(board[i][j]) == '.' && (i+j)>0){
                int rando = rand() % 2;
                if(rando==1)
                board[i][j] = new Potion(i,j,'g',amount);
                else 
                board[i][j] = new Coin(i,j,'g',amount);
                currentGems++;
            }
        }
    }
    int currentObs = 0;
    while (currentObs < 10)
    {
        int i = rand() % 10;
        int j = rand() % 10;
        int damage=(rand() % 5) + 1;
        if (i < 10 && j < 10)
        {
            if(*(board[i][j]) == '.')
            {
                board[i][j] = new Bomb(i,j,'o',damage);
                currentObs++;
            }
        }
    }
    while (currentObs < 20)
    {
        int i = rand() % 10;
        int j = rand() % 10;
        int damage=(rand() % 5) + 1;
        if (i < 10 && j < 10)
        {
            if(*(board[i][j]) == '.')
            {
                board[i][j] = new Thief(i,j,'o',damage);
                currentObs++;
            }
        }
    }
    cout<<"randomize_map() called"<<endl;
}

void Champion::move(Cell*** board,char x,int change)
{
    if(this->ability_active==true){
        this->ability_active=false;
        this->useAbility(board,x);
        return;
    }
    switch (x){
    case 'x':
    case 'X':
            if(this->getAbilityLeft()>0){
                this->ability_active=true;
                cout<<"Choose Direction !!!! "<<endl;
                return;
            }
            else cout<<"Ability already used twice"<<endl;
            break;
    //Move UP
    case 'w':
    case '8':
        if (this->getY() + change < 10)
        {
            if ((*board[this->getY() + change][this->getX()]) == 'g')
            {
                ((Gem*)board[this->getY() + change][this->getX()])->execute(this);
            }
            if ((*board[this->getY() + change][this->getX()]) == 'o')
            {
                ((Obstacle*)board[this->getY() + change][this->getX()])->execute(this);
            }
            board[this->getY()][this->getX()] = new Cell(this->getY(),this->getX(),'.');
            this->setY(this->getY()+change);
            board[this->getY()][this->getX()]=this;
            
        }
        else
        {
            cout << "INVALID MOVE" << endl;
        }
       break;
    //Move Down
    case 's':
    case '5':
        if (this->getY() - change >= 0)
        {
            if ((*board[this->getY() - change][this->getX()]) == 'g')
            {
                ((Gem*)board[this->getY() - change][this->getX()])->execute(this);
            }
            if ((*board[this->getY() - change][this->getX()]) == 'o')
            {
                ((Obstacle*)board[this->getY() - change][this->getX()])->execute(this);
            }
            board[this->getY()][this->getX()] = new Cell(this->getY(),this->getX(),'.');
            this->setY(this->getY()-change);
            board[this->getY()][this->getX()]=this;
            
        }
        else
        {
            cout << "INVALID MOVE" << endl;
        }
        break;
    //Move Right
    case 'd':
    case '6':
        if (this->getX() + change < 10)
        {
            if ((*board[this->getY()][this->getX()+change]) == 'g')
            {
                ((Gem*)board[this->getY()][this->getX()+change])->execute(this);
            }
            if ((*board[this->getY() ][this->getX()+change]) == 'o')
            {
                ((Obstacle*)board[this->getY()][this->getX()+change])->execute(this);
            }
            board[this->getY()][this->getX()] = new Cell(this->getY(),this->getX(),'.');
            this->setX(this->getX()+change);
            board[this->getY()][this->getX()]=this;
            
        }
        else
        {
            cout << "INVALID MOVE" << endl;
        }
        break;
    //Move Left
    case 'a':
    case '4':
        if (this->getX() - change >= 0)
        {
            if ((*board[this->getY()][this->getX()-change]) == 'g')
            {
                ((Gem*)board[this->getY()][this->getX()-change])->execute(this);
            }
            if ((*board[this->getY() ][this->getX()-change]) == 'o')
            {
                ((Obstacle*)board[this->getY()][this->getX()-change])->execute(this);
            }
            board[this->getY()][this->getX()] = new Cell(this->getY(),this->getX(),'.');
            this->setX(this->getX()-change);
            board[this->getY()][this->getX()]=this;
        }
        else
        {
            cout << "INVALID MOVE" << endl;
        }
        break;
    default:
        cout << "INVALID KEY" << endl;
    }
}

Champion * Map::getC() const {
    return c;
}
bool Map::endGame(){
    if(this->getC()->getHealth() == 0){
        return false;
    }

    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++){
        if((*this->board[i][j]) == 'g')
        return true;
        }
    }

    return false;
}
void Champion::luigiRemove(Cell*** board,char x){
    switch(x){
    //up
    case 'w':
    case '8':
    for(int i=this->getY();i<10;i++)
        if ((*board[i][this->getX()]) == 'o')
        board[i][this->getX()] = new Cell(i,this->getX(),'.');
    break;
    //down
    case 's':
    case '5':
        for(int i=this->getY();i>=0;i--)
        if ((*board[i][this->getX()]) == 'o')
        board[i][this->getX()] = new Cell(i,this->getX(),'.');
    break;
    //Right
    case 'd':
    case '6':
        for(int i=this->getX();i<10;i++)
        if ((*board[this->getY()][i]) == 'o')
        board[this->getY()][i] = new Cell(this->getY(),i,'.');
    break;
    //Left
    case 'a':
    case '4':
        for(int i=this->getX();i>=0;i--)
        if ((*board[this->getY()][i]) == 'o')
        board[this->getY()][i] = new Cell(this->getY(),i,'.');
    break;
    }
}

int main() {
    char champChoice;
    Champion * player;
    do{
    system("CLS");
    cout<<"Welcome!"<<endl;
    cout<<"Would you like to play with Mario or Luigi? M for Mario and L for Luigi: ";
    cin>>champChoice; 
    }
    while(!(champChoice == 'M' ||champChoice == 'm'||champChoice == 'L' ||champChoice == 'l'));
    system("CLS");
    if(champChoice == 'M' ||champChoice == 'm'){
        player = new Mario();
        cout<<"U choose Mario!!!!"<<endl;}
    else{
        player = new Luigi();
        cout<<"U choose Luigi!!!!"<<endl;}
    Map* map = new Map(10,10,player);
    char choice;
    do {
        map->randomize_map();
        map->print_Map();
        cout << "Would you like to proceed with this map? Press 1 to start and 2 to re-randomize : ";
        cin >> choice;
        system("CLS");
    }while(choice != '1');
    system("CLS");
    map->print_Map();
    map->getC()->print_champ_info();
    map->getC()->abilityInfo();
    char x;
    while(map->endGame())
    {
        
        cout<<"Press 8/w to move up, 5/s to move down, 4/a to move left, 6/d to move right: ";
        x= (char) getch();
        system("CLS");
        map->getC()->move(map->getBoard(),x,1);
        map->print_Map();
        map->getC()->print_champ_info();
        map->getC()->abilityInfo();
        
    }
    system("CLS");
    if(map->getC()->getHealth() == 0){
        cout<<"U LOST !!!!!"<<endl;
    }
    else
    cout<<"U WON !!!!!"<<endl;
    cout<<"FINAL SCORE : "<<map->getC()->getchamp_score();
    return 0;
}
//arrows issue