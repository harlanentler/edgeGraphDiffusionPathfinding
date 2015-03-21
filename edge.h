#ifndef EDGE_H
#define EDGE_H

template<typename vertex>
class edge
{
public:
    edge(vertex *vIn, double dIn);
    ~edge();

    vertex *getV();
    double getD();
private:
    double d;
    vertex *v;
};

template<typename vertex>
edge<vertex>::edge(vertex *vIn, double dIn)
{
    v = vIn;
    d = dIn;
}

template<typename vertex>
edge<vertex>::~edge()
{

}

template<typename vertex>
vertex *edge<vertex>::getV()
{
    return v;
}

template<typename vertex>
double edge<vertex>::getD()
{
    return d;
}


#endif // EDGE_H
