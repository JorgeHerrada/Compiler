#ifndef PILA_H
#define PILA_H
#include <iostream>
#include <stdexcept>
#include "ldl.h"
#include <sstream>

using namespace std;

template<typename T>
class Pila //stack
{
public:
    Pila()
    {

    }
    ~Pila()
    {
        lista.clear();
    }

    bool empty() const;
    size_t size() const;
    const T& top() const;
    void push(const T& element);
    void pop();
    string toString(); //al reves
    string toString2(); //derecho

    string buffer = "";
    string imprime();

private:
    LDL<T> lista;
};

template<typename T>
bool Pila<T>::empty() const
{
    return lista.empty();
}

template<typename T>
size_t Pila<T>::size() const
{
    return lista.size();
}

template<typename T>
const T& Pila<T>::top() const
{
    if (empty())
    {
        throw runtime_error("Trying top() from empty stack.");
    }
    return lista.front();
}

template<typename T>
void Pila<T>::push(const T& element)
{
    lista.push_front(element);
    buffer += element;
}

template<typename T>
void Pila<T>::pop()
{
    if (empty())
    {
        throw runtime_error("Trying pop() from empty stack.");
    }
    //buffer.erase(buffer.find(lista.front()));
    string aux = buffer; //$0hola
    string aux_r(aux.rbegin(), aux.rend());//aloh0$
    int largo = top().length(); 
    aux_r.erase(0,largo);//0$
    string aux2(aux_r.rbegin(), aux_r.rend());//$0
    buffer = aux2;
    //cout<<"buffer: "<<buffer<<endl;

    lista.pop_front();
}
#endif // PILA_H

template<typename T>
string Pila<T>::toString()
{
    stringstream ss;
    while(!empty())
    {
        ss<<lista.back()<<"";
        lista.pop_back();
    }
    return ss.str();
}

template<typename T>
string Pila<T>::toString2()
{
    stringstream ss;
    while(!empty())
    {
        ss<<lista.back()<<"";
        lista.pop_back();
    }
    return ss.str();
}

template<typename T>
string Pila<T>::imprime()
{
    stringstream ss;
    ss<<buffer;
    return ss.str();
}