#include <iostream>
#include <sstream>
using namespace std;

class Token
{
private:
    int tipo;
    string contenido;
public:
    Token(/* args */);
    ~Token();
    int getTipo();
    void setTipo(int value);
    string getContenido();
    void setContenido(string& value);

    string toString();
};

Token::Token(/* args */)
{
}

Token::~Token()
{
}

int Token::getTipo()
{
    return tipo;
}
void Token::setTipo(int value)
{
    tipo = value;
}
string Token::getContenido()
{
    return contenido;
}
void Token::setContenido(string& value)
{
    contenido = value;
}

string Token::toString()
{
    stringstream ss;
    ss<<"Tipo: "<<tipo<<"\nContenido: "<<contenido<<endl;
    return ss.str();
}