#ifndef COORD_H
#define COORD_H

#include <iostream>
using namespace std;

enum COORDERROR{INSENSIBLE_RANGE};

class coord
{
public:
    coord();
    coord(int coordIn, int maxIn);
    coord(coord &other);
    ~coord();

    int val();
    int set(int coordIn, int maxIn);
    int set(int coordIn);

    int operator +(int other);
    int operator -(int other);

    int operator +=(int other);
    int operator -=(int other);
    int operator =(int other);

    int operator ++();
    int operator --();

private:
    int coordinate, rangeMax;

    int add(int other);
    int subtract(int other);
    int bound(int value);
};

#endif // COORD_H
