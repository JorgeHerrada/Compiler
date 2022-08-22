#include <iostream>
#include <string>
#include "funciones.h"
using namespace std;

int compararLetraNum(string& cadena);
int compararPunto(string& cadena);

int main()
{
    //string cadena1 = "hola 22 2.2 CADENA int + * < >= | || && ! == ; , ( ) { } = if $";
    string cadena1;
    cout<<"Ingresa cadena: ";
    getline(cin,cadena1);
    string cadena2 = "";
    int largo1 = cadena1.length(), largo2;
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
                {
                    //cout<<"dentro";
                    especial = true;
                }
            }
            if(!especial)
                tipo = letraONum(cadena2);
            else if(especial)
                tipo = caracterEspecial(cadena2);
            cout<<" | tipo: "<<tipo<<endl;
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
    
    cout <<" | tipo: "<<tipo<<endl;
    return 0;
}
