
#ifndef CELL_H
#define CELL_H

class Cell
{
private:
    char type;
    int x;
    int y;

public:
    Cell (int y = 0, int x = 0, char t = '.') : y(y), x(x), type (t)
    {}

    char getType() {
        return type;
    }

    void setType(char type) {
        Cell::type = type;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        Cell::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Cell::y = y;
    }

    bool operator == (char const &c)
    {
        return this->type == c;
    }

    bool operator != (char const &c)
    {
        return this->type != c;
    }
    friend std::ostream& operator << (std::ostream& os, Cell* c);
};


#endif //MILESTONE2_CELL_H
