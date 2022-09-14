#include <iostream>
#include <sstream>
using namespace std;

class R1
{
private:
    /* data */
    int cantidadTokens;
    string forma;
public:
    R1(/* args */);
    ~R1();

    int getCantidadTokens();
    void setCantidadTokens(int value);
    string getForma();
    void setForma(string& value);

    string toString();
};

R1::R1(/* args */)
{
}

R1::~R1()
{
    
}

int R1::getCantidadTokens()
{
    cantidadTokens = 0;
    int largo = forma.length();
    for(int i = 0; i<largo; i++)
    {
        if(forma[i] == ' ')
            cantidadTokens++;
    }
    return cantidadTokens;
}
void R1::setCantidadTokens(int value)
{
    cantidadTokens = value;
}
string R1::getForma()
{
    return forma;
}
void R1::setForma(string& value)
{
    forma = value;
}

string R1::toString()
{
    stringstream ss;
    ss<<"Cantidad tokens: "<<cantidadTokens<<"\nForma: "<<forma<<endl;
    return ss.str();
}
