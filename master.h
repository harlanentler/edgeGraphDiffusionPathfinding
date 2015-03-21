#ifndef MASTER_H
#define MASTER_H

#include <ostream>
#include <iostream>
#include <iomanip>

#include "vdata.h"
#include "entity.h"
#include "graph.h"
#include "diffuser.h"

class master
{
public:
    master(int sizeIn=15);
    ~master();

    void step();

    void print();

    std::ostream &operator <<(std::ostream& out);

private:
    int size;
    graph<vData> g;
    diffuser mask;
};

#endif // MASTER_H
