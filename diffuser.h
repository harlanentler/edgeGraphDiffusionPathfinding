#ifndef DIFFUSER_H
#define DIFFUSER_H

#include "vdata.h"
#include "graph.h"

class diffuser
{
public:
    diffuser();
    diffuser(int sizeIn);
    ~diffuser();

    void resize(int sizeIn=15);

    void step(graph<vData> &g);

    double access(int x, int y);

private:
    int size;

    double diffConstant;

    vector<vector<double> > mirror;

    double diffuse(const vertex<vData> &v);

    void zero();
};

#endif // DIFFUSER_H
