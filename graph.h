#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "edge.h"

#include "coord.h"

template<typename T>
class graph
{
public:
    graph();
    graph(int sizeIn);
    ~graph();

    void resize(int sizeIn);

    T& access(int x, int y);

    vertex<T> *getV(int x, int y);

    void getInfo(int x, int y);

private:
    vector< vector<vertex<T> > > v;

    double here, neum, diag;
    int size;

    void makeGraph();

    void clear();
};


template<typename T>
graph<T>::graph()
{
    here = 0;
    neum = 1.0;
    diag = 1.414;
}

template<typename T>
graph<T>::graph(int sizeIn)
{
    size = sizeIn;
    here = 0;
    neum = 1.0;
    diag = 1.414;
    makeGraph();
}

template<typename T>
graph<T>::~graph()
{

}

template<typename T>
void graph<T>::resize(int sizeIn)
{
    size = sizeIn;
    clear();
    makeGraph();
}

template<typename T>
T& graph<T>::access(int x, int y)
{
    return v[coord(y,size).val()][coord(x,size).val()].access();
}

template<typename T>
vertex<T> *graph<T>::getV(int x, int y)
{
    return &v[y][x];
}

template<typename T>
void graph<T>::getInfo(int x, int y)
{
    v[coord(y,size).val()][coord(x,size).val()].printStuff();
}

template<typename T>
void graph<T>::makeGraph()
{
    coord x(0,size),y(0,size);
    v.resize(size);
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            v[i].push_back(vertex<T>(T()));
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
        {
            y.set(i);
            x.set(j);
            v[i][j].pushEdge(edge<vertex<T> >(&v[y.val()][x.val()], here));
            v[i][j].pushEdge(edge<vertex<T> >(&v[y+1][x+1], diag));
            v[i][j].pushEdge(edge<vertex<T> >(&v[y+1][x.val()], neum));
            v[i][j].pushEdge(edge<vertex<T> >(&v[y+1][x-1], diag));
            v[i][j].pushEdge(edge<vertex<T> >(&v[y.val()][x-1], neum));
            v[i][j].pushEdge(edge<vertex<T> >(&v[y-1][x-1], diag));
            v[i][j].pushEdge(edge<vertex<T> >(&v[y-1][x.val()], neum));
            v[i][j].pushEdge(edge<vertex<T> >(&v[y-1][x+1], diag));
            v[i][j].pushEdge(edge<vertex<T> >(&v[y.val()][x+1], neum));
        }
}

template<typename T>
void graph<T>::clear()
{
    v.clear();
}



#endif // GRAPH_H
