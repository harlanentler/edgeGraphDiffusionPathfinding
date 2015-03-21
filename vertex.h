#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>

#include "vector"
#include "edge.h"

template<typename T>
class vertex
{
public:
    vertex(T dataIn);
    ~vertex();

    void pushEdge(edge<vertex> in);

    edge<vertex<T> > getEdge(int direction) const;

    int getCount() const;

    T& access();

    void printStuff();

private:
    int neighbors;

    T data;

    std::vector<edge<vertex<T> > > neighbor;
};

template<typename T>
vertex<T>::vertex(T dataIn)
{
    data = dataIn;
    neighbors=0;
}

template<typename T>
vertex<T>::~vertex()
{

}

template<typename T>
void vertex<T>::pushEdge(edge<vertex<T> > in)
{
    neighbor.push_back(in);
    ++neighbors;
}

template<typename T>
edge<vertex<T> > vertex<T>::getEdge(int direction) const
{
    return neighbor[direction];
}

template<typename T>
int vertex<T>::getCount() const
{
    return neighbors;
}

template<typename T>
T& vertex<T>::access()
{
    return data;
}

template<typename T>
void vertex<T>::printStuff()
{
    for(int i=0; i<neighbor.size(); ++i)
        std::cout << "direction: " << i << std::endl << "distance: " << neighbor[i].getD() << std::endl << std::endl;
}


#endif // VERTEX_H
