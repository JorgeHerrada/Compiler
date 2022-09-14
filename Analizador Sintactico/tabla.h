#ifndef TABLA_H
#define TABLA_H
#include <iostream>
#include "r1.h"
using namespace std;
R1 r1;
auto tabla1()
{
    static int t1[5][4] = { //E-> <id> + <id>
    2,0, 0,1,
    0,0,-1,0,
    0,3, 0,0,
    4,0, 0,0,
    0,0,-2,0
    };
    return t1;
}

auto tabla2()
{
    static int t2[5][4] = { //E-> <id> + <id>
    2,0, 0,1,
    0,0,-1,0,
    0,3,-3,0,
    2,0, 0,4,
    0,0,-2,0
    };
    return t2;
}

auto reglasTab1(int value)
{
    string forma; 
    switch(value)
    {
        case -2:
        {
            forma = "r1=E-> <id> + <id>";
            r1.setForma(forma);
            break;
        }
        case -1:
        {
            forma = "r0(acept)";
            r1.setForma(forma);
            break;
        }
    }
    return r1;
}

auto reglasTab2(int value)
{
    string forma; 
    switch(value)
    {
        case -3:
        {
            forma = "r2=E-> <id>";
            r1.setForma(forma);
            break;
        }
        case -2:
        {
            forma = "r1=E-> <id> + E";
            r1.setForma(forma);
            break;
        }
        case -1:
        {
            forma = "r0(acept)";
            r1.setForma(forma);
            break;
        }
    }
    return r1;
}

#endif // PILA_H