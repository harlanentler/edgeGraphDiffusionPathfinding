#ifndef ENTITY_H
#define ENTITY_H

#include "vertex.h"
#include "vdata.h"
#include <vector>

class entity
{
public:
    entity();
    entity(vertex<vData> *vIn);
    ~entity();

    vertex<vData> *setHere(vertex<vData> *vIn);

    void evalutateD();

    void chooseD();

private:
    vertex<vData> *here;

    std::vector<double> direction;

    int greatestD();
};

#endif // ENTITY_H
