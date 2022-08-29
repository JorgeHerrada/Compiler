#include <iostream>
#include <string>
#include <Windows.h> // Para usar sleep()
#include "funciones.h"
using namespace std;

int main()
{
    //string cadena1 = "hola 22 2.2 entero + * < >= | || && ! == ; , ( ) { } = si $";
    string cadena1;
    
    while(true)
    {    
        cout<<"Para salir escribe 'SALIR'\nIngresa cadena: ";
        getline(cin,cadena1);

        if(cadena1 == "SALIR")
            break;

        string cadena2 = "";

        //
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
    }

    cout<<"Saliendo";
    for(int i = 0; i < 3; i++)
    {
        Sleep(1000);
        cout << ".";
    }
    Sleep(1000);
    return 0;
}