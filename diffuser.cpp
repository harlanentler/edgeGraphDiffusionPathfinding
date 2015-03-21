#include "diffuser.h"

diffuser::diffuser()
{
    diffConstant = 12;
}

diffuser::diffuser(int sizeIn)
{
    size = sizeIn;
    mirror.resize(size);
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            mirror[i].push_back(0);
    diffConstant = 12;
}

diffuser::~diffuser()
{

}

void diffuser::resize(int sizeIn)
{
    size = sizeIn;
    mirror.resize(size);
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            mirror[i].push_back(0);
}

void diffuser::step(graph<vData> &g)
{
    zero();
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            mirror[i][j] = diffuse(*(g.getV(j,i)));
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            g.access(j,i).dMaskL = mirror[i][j];
}

double diffuser::access(int x, int y)
{
    return mirror[y][x];
}

double diffuser::diffuse(const vertex<vData> &v)
{
    double out=v.getEdge(0).getV()->access().dMaskL;
    for(int i=1; i<v.getCount(); ++i)
        out+= v.getEdge(i).getV()->access().dMaskL/v.getEdge(i).getD(); //concentration div distance
    return out/diffConstant;
}

void diffuser::zero()
{
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            mirror[i][j] = 0;
}

