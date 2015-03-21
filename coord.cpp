#include "coord.h"

coord::coord()
{
    rangeMax = coordinate -1;
}

coord::coord(int coordIn, int maxIn)
{
    set(coordIn, maxIn);
}

coord::~coord()
{
}

int coord::val()
{
    return coordinate;
}

int coord::set(int coordIn, int maxIn)
{
    rangeMax = maxIn;
    return (coordinate=bound(coordIn));
}

int coord::set(int coordIn)
{
    return (coordinate=bound(coordIn));
}

int coord::operator +(int other)
{
    return add(other);
}

int coord::operator -(int other)
{
    return subtract(other);
}

int coord::operator +=(int other)
{
    return (coordinate = add(other));
}

int coord::operator -=(int other)
{
    return (coordinate = subtract(other));
}

int coord::operator =(int other)
{
    return (coordinate=bound(other));
}

int coord::operator ++()
{
    return add(coordinate+1);
}

int coord::operator --()
{
    return subtract(coordinate-1);
}

int coord::add(int other)
{
    return ((coordinate+other)%rangeMax);;
}

int coord::subtract(int other)
{
    other *= -1;
    other += coordinate;
    while(other<0)
        other+=rangeMax;
    return other;
//    if((other-coordinate)%rangeMax)      //case coordinate==0,other==rangeMax
//        return (rangeMax - (other-coordinate)%rangeMax);
//    return coordinate;
}

int coord::bound(int value)
{
    if(value < 0)
        return (value=0);
    if(value >= rangeMax)
        return (value=(rangeMax-1));
    return value;
}
