#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "funciones.h"
#include "token.h"
#include "tabla.h"
#include "pila.h"
using namespace std;

string cortarEntrada(string& cadena1);
static void analizadorLexico();
static void analizadorSintactico(Token& token, string& cadena1);
Token token;
Pila<string> pila;
int contador = 0;
ofstream fout;
R1 reduccion1;

int main()
{
    analizadorLexico();
    cout<<"\nExito!";
    return 0;
}

string cortarEntrada(string& cadena1)
{
    stringstream leerArchivo;
    if(contador == 0)
    {
        cadena1 += "$";
        fout.open("archivo.txt");
        fout<<cadena1;
        fout.close();
        contador++;
    }
    ifstream fin("archivo.txt");
    leerArchivo << fin.rdbuf();
    return leerArchivo.str();
}

static void analizadorLexico()
{
    //string cadena1 = "hola + mundo";
    string cadena1 = "a + b + c + d + e + f";
    //cout<<"Cadena: ";
    //getline(cin, cadena1);
    string cadena2 = "";
    int largo1 = cadena1.length();
    int largo2;
    bool especial = false; 
    int tipo;

    for(int i = 0; i<largo1; i++)
    {
        if(cadena1[i] == ' ')
        {
            largo2 = cadena2.length();
            for(int j = 0; j < largo2; j++)
            {
                if(!isalnum(cadena2[j]))
                    especial = true;
            }
            if(!especial)
                tipo = letraONum(cadena2);
            else if(especial)
                tipo = caracterEspecial(cadena2);
            //cout<<" | tipo: "<<tipo<<endl;
            //Analisis sintactico
            token.setTipo(tipo);
            token.setContenido(cadena2);
            analizadorSintactico(token, cadena1);
            cadena2 = "";
            especial = false;
        }
        else
            cadena2 += cadena1[i];
    }
    largo2 = cadena2.length();
    for(int i=0; i<largo2; i++)
    {
        if(!isalnum(cadena2[i]))
            especial = true;
    }
    if(!especial)
        tipo = letraONum(cadena2);
    else if(especial)
        tipo = caracterEspecial(cadena2);

    //cout<<" | tipo: "<<tipo<<endl;
    //Analisis sintactico
    cadena2 += "$";
    token.setTipo(tipo);
    token.setContenido(cadena2);
    analizadorSintactico(token, cadena1);
}
static void analizadorSintactico(Token& token, string& cadena1)
{
    string aux2;
    aux2 = cortarEntrada(cadena1);
    bool comparacion = false;
    Token tokenFinal;
    if(pila.empty())
    {
        pila.push("$");
        pila.push("0");
    }
    string aux = token.getContenido(), peso = "$";
    int largoAux = aux.length();
    
    if(aux[largoAux-1] == '$')
    {
        token.setContenido(token.getContenido().erase(token.getContenido().find(peso)));
        tokenFinal.setTipo(2);
        tokenFinal.setContenido(peso);
    }
    //auto t1 = tabla1();
    auto t1 = tabla2();
    string forma1 = "E-> <id> + <id>";
    int fila = stoi(pila.top());
    int columna = token.getTipo();
    //Casos comunes (no negativos)
    if(t1[fila][columna] != 0) 
    {
        int largoToken = token.getContenido().length() + 1;
        cout<<"pila.imprime: "<<pila.imprime();
        cout<<"\tEntrada: "<<aux2;
        pila.push(token.getContenido());
        pila.push(to_string(t1[fila][columna]));
        aux2.erase(0,largoToken);
        fout.open("archivo.txt");
        fout<<aux2;
        fout.close();
    }
    cout<<"\tSalida: d"<<t1[fila][columna]<<endl;

    if(tokenFinal.getContenido() != "")
    {
        fila = stoi(pila.top());
        columna = tokenFinal.getTipo();
        cout<<"pila.imprime: "<<pila.imprime();
        cout<<"\tEntrada: $";
        reduccion1 = reglasTab2(t1[fila][columna]);
        cout<<"\tSalida: "<<reduccion1.getForma()<<endl;
        comparacion = true;
    }
    if(reduccion1.getForma() != "")
    {
        int tamanoPila = pila.size()-2;
        int tokens;
        for(int i = 0; i<tamanoPila; i++)
        {
            fila = stoi(pila.top());
            if(comparacion)
            {
                columna = 3;
                tokens = reduccion1.getCantidadTokens() * 2;
                //cout<<"tokens: "<<tokens;
                while(tokens > 0)
                {
                    pila.pop();
                    tokens--;
                    //cout<<"PPPPpila.imprime: "<<pila.imprime()<<endl;
                }
                fila = stoi(pila.top());
                pila.push("E");
                pila.push(to_string(t1[fila][columna]));
                //cout<<"PPPPpila.imprime: "<<pila.imprime()<<endl;
                comparacion = false;  
            }
            else if(reduccion1.getForma() != "r0(acept)")
            {
                columna = 2;
                reduccion1 = reglasTab2(t1[fila][columna]);
                cout<<"pila.imprime: "<<pila.imprime();
                cout<<"\tEntrada: $";
                cout<<"\tSalida: "<<reduccion1.getForma()<<endl;
                comparacion = true;
            }
        }
    }

}
