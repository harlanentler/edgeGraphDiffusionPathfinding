#include <QCoreApplication>

#include <iostream>

//#include "vdata.h"
//#include "graph.h"

#include "master.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    master test(10);

    test.print();
    test.step();
    test.print();
    test.step();
    test.print();
    test.step();
    test.print();
    test.step();
    test.print();
    test.step();
    test.print();
    test.step();
    test.print();
    test.step();
    test.print();
    test.step();
    test.print();
    test.step();
    test.print();
    test.step();
    test.print();
    test.step();
    test.print();
    test.step();
    //test.print();

//    std::cout << test << std::endl;

//    graph<vData> test(15);
//    test.getInfo(14,14);
//    test.access(14,14).dMaskL = 5.0;

//    std::cout << test.access(14,14).dMaskL << std::endl;

    return a.exec();
}
