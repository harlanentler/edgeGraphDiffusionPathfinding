#include "master.h"

master::master(int sizeIn)
{
    size=sizeIn;
    g.resize(size);
    mask.resize(size);

    g.access(8,4).occupant = new entity(g.getV(8,4));
}

master::~master()
{

}

void master::step()
{
    //
    g.access(5,5).dMaskL = 100;
    //

    int steps=20;
    while(steps--)
        mask.step(g);


    vector<entity *> toMove;

    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            if(g.access(j,i).occupant)
            {
                g.access(j,i).occupant->evalutateD();
                toMove.push_back( g.access(j,i).occupant );
            }
    for(int i=0; i<toMove.size(); ++i)
        toMove[i]->chooseD();
}

void master::print()
{
    for(int i=0; i<size; ++i)
    {
        for(int j=0; j<size; ++j)
        {
            if(g.access(j,i).occupant)
                cout << std::setw(6) << "GUY  ";
            else
                cout << std::setw(6) << std::fixed << std::setprecision(2) << (g.access(j,i).dMaskL*10000) << "  ";
        }
        cout << endl;
    }
    cout << endl << endl << endl;
}

std::ostream &master::operator <<(std::ostream &out)
{
    for(int i=0; i<size; ++i)
    {
        for(int j=0; j<size; ++j)
            out << g.access(j,i).dMaskL << "  ";
        out << "\n";
    }
    return out;
}

