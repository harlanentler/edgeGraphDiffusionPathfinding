#ifndef VDATA_H
#define VDATA_H

class entity;

struct vData
{
public:
    vData();
    ~vData();

    entity* occupant;
    double dMaskL;
};

#endif // VDATA_H
