#include "entity.h"

entity::entity()
{
    here = NULL;
    for(int i=0; i<9; ++i)
        direction.push_back(0);
}

entity::entity(vertex<vData> *vIn)
{
    here = vIn;
    for(int i=0; i<9; ++i)
        direction.push_back(0);
}

entity::~entity()
{

}

vertex<vData> *entity::setHere(vertex<vData> *vIn)
{
    here = vIn;
    return here;
}

void entity::evalutateD()
{
//    for(int i=0; i<direction.size(); ++i)
//        direction[i] += here->access().dMaskL;


    for(int i=0; i<direction.size(); ++i)
        direction[i] += here->getEdge(i).getV()->access().dMaskL * 10000;


//                    /here->getEdge(i).getD();
}

void entity::chooseD()
{
    int greatest=greatestD();
    while(greatest>0)
    {//till we find an unoccupied space
        if( !(here->getEdge(greatest).getV()->access().occupant) )
        {
            vertex<vData> *temp=here;
            here->getEdge(greatest).getV()->access().occupant = this;
            here=here->getEdge(greatest).getV();
            temp->access().occupant = NULL;
            greatest=-1;
            for(int i=0; i<direction.size(); ++i)
                direction[i] = 0;
        }
        else if(greatest!=-1)
        {
            direction[greatest] = 0;
            greatest = greatestD();
        }
    }
}

int entity::greatestD()
{
    double greatest=0;
    int index=-1;
    for(int i=0; i<direction.size(); ++i)
    {
        if(direction[i]>greatest)       //DOUBLE UNRELIABLE > OPERATOR, ROUNDING ERRORS
        {
            index=i;
            greatest=direction[i];
        }
    }
    return index;
}


