#include <iostream>
using namespace std;

int punto(string& cadena);
int cadenaF(string& cadena);
int tipoF(string& cadena);
int opSuma(string& cadena);
int opMul(string& cadena);
int opRel(string& cadena);
int opOr(string& cadena);
int opAnd(string& cadena);
int opNot(string& cadena);
int opIgualdad(string& cadena);
//Caracteres
int carPuntoYComa(string& cadena);
int carComa(string& cadena);
int carParentesis1(string& cadena);
int carParentesis2(string& cadena);
int carLlave1(string& cadena);
int carLlave2(string& cadena);
int carIgual(string& cadena);
//Reservadas
int reservadas(string& cadena);

int carPeso(string& cadena);

int letraONum(string& cadena)
{
    if(cadena == "int" || cadena == "float" || cadena == "void")
    {
        int tipo = tipoF(cadena);
        return tipo;
    }
    else if(cadena == "if" || cadena == "while" || cadena == "return" || cadena == "else")
    {
        int tipo = reservadas(cadena);
        return tipo;
    }
    int largo = cadena.length();
    bool puraLetra = true, puroNumero = true;
    for(int i = 0; i < largo; i++)
    {
        if(!isalpha(cadena[i]))
        {
            puraLetra = false;
        }
        else if(!isdigit(cadena[i]))
            puroNumero = false;
    }
    //cout<<cadena;
    if(puraLetra)
    {
        //cout<<" : identificador";
        return 0;
    }
    //NUMEROS
    else if(puroNumero)
    {
        //cout<<" : entero";
        return 5;
    }
    
    if(isdigit(cadena[0]) && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con un numero";
        return -1;
    }
    if(isalpha(cadena[0]) && largo >1)
    {
        //cout<<" : identificador";
        return 0;
    }
    return 0;
}

int caracterEspecial(string& cadena)
{
    int largo = cadena.length(), tipo = -1;
    for(int i = 0; i < largo; i++)
    {
        //Punto
        if(cadena[i] == '.')
            tipo = punto(cadena);
        //Cadena
        else if(cadena[i] == '"')
        {
            tipo = cadenaF(cadena);
            return tipo;
        }
        //Suma
        else if(cadena[i] == '+' || cadena[i] == '-')
        {
            tipo = opSuma(cadena);
            return tipo;
        }
        //Multiplicacion
        else if(cadena[i] == '*' || cadena[i] == '/')
        {
            tipo = opMul(cadena);
            return tipo;
        }
        //Relacional
        else if(cadena[i] == '<' || cadena[i] == '>')
        {
            tipo = opRel(cadena);
            return tipo;
        }
        else if((cadena[i] == '<' && cadena[i+1] == '='))
        {
            tipo = opRel(cadena);
            return tipo;
        }
        else if((cadena[i] == '>' && cadena[i+1] == '='))
        {
            tipo = opRel(cadena);
            return tipo;
        }
        //Or
        else if(cadena[i] == '|')
        {
            tipo = opOr(cadena);
            return tipo;
        }
        //And
        else if(cadena[i] == '&')
        {
            tipo = opAnd(cadena);
            return tipo;
        }
        //Not
        else if(cadena[i] == '!' && cadena[i+1] != '=')
        {
            tipo = opNot(cadena);
            return tipo;
        }
        //Igualdad
        else if((cadena[i] == '=' && cadena[i+1] == '='))
        {
            tipo = opIgualdad(cadena);
            return tipo;
        }
        else if((cadena[i] == '!' && cadena[i+1] == '='))
        {
            tipo = opIgualdad(cadena);
            return tipo;
        }
        //Punto y coma
        else if(cadena[i] == ';')
        {
            tipo = carPuntoYComa(cadena);
            return tipo;
        }
        //Coma
        else if(cadena[i] == ',')
        {
            tipo = carComa(cadena);
            return tipo;
        }
        //Parentesis (
        else if(cadena[i] == '(')
        {
            tipo = carParentesis1(cadena);
            return tipo;
        }
        //Parentesis )
        else if(cadena[i] == ')')
        {
            tipo = carParentesis2(cadena);
            return tipo;
        }
        //Llave {
        else if(cadena[i] == '{')
        {
            tipo = carLlave1(cadena);
            return tipo;
        }
        //Llave }
        else if(cadena[i] == '}')
        {
            tipo = carLlave2(cadena);
            return tipo;
        }
        //Igual 
        else if(cadena[i] == '=')
        {
            tipo = carIgual(cadena);
            return tipo;
        }
        //---Reservadas--- 
        //Peso: $
        else if(cadena[i] == '$')
        {
            tipo = carPeso(cadena);
            return tipo;
        }
    }
    //cout<<"dentro punto";
    return tipo;
}

int punto(string& cadena)
{
    int largo = cadena.length(), tipo = 23;
    bool letra = false;
    cout<<cadena;
    if(cadena[0] == '.' && largo == 1)
    {
        cout<<" : .";
        tipo = 24;
        return tipo;
    }
    else if(cadena[0] == '.' && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con '.'";
        tipo = -1;
        return tipo;
    }

    else if(cadena[largo-1] == '.')
    {
        cout<<" : ERROR, un identificador no puede terminar con '.'";
        tipo = -1;
        return tipo;
    }

    for(int i = 0; i < largo; i++)
    {
        if(isalpha(cadena[i]))
            letra = true;
    }

    if(letra)
    {
        cout<<" : ERROR, un identificador no puede contener con un punto";
        tipo = -1;
        return tipo;
    } 
    cout<<" : real";
    return tipo;
}

int cadenaF(string& cadena)
{
    int largo = cadena.length();
    cout<<cadena;
    if(cadena[0] == '"' && cadena[largo-1] == '"')
    {
        cout<<" : Cadena";
        return 3;
    }
    else
    {
        char comilla = 34;
        cout<<" : Error, un identificador no puede contener: ' "<<comilla<<" '";
        return -1;
    }
    return 3;
}

int tipoF(string& cadena)
{
    cout<<cadena<<" : Tipo de dato";
    return 4;
}

int opSuma(string& cadena)
{
    //cout<<cadena;
    bool letra = false;
    int largo = cadena.length();
    if((cadena[0] == '+' && largo == 1) || (cadena[0] == '-' && largo == 1))
    {
        //cout<<" : Operador suma";
        return 1;
    }
    if((cadena[0] == '+' && largo > 1) || (cadena[0] == '-' && largo > 1))
    {
        cout<<" : ERROR, un identificador no puede iniciar con '+' ni con '-'";
        return -1;
    }
    for(int i = 0; i < largo; i++)
    {
        if(!isalnum(cadena[i]))
            letra = true;
    }
    if(letra)
    {
        cout<<" : ERROR, un identificador no puede contener '+' ni '-'";
        return -1;
    }
    //cout<<" : Operador suma";
    return 1;
}

int opMul(string& cadena)
{
    cout<<cadena;
    bool letra = false;
    int largo = cadena.length();
    if((cadena[0] == '*' && largo == 1) || (cadena[0] == '/' && largo == 1))
    {
        cout<<" : Operador multiplicacion";
        return 6;
    }
    if((cadena[0] == '*' && largo > 1) || (cadena[0] == '/' && largo > 1))
    {
        cout<<" : ERROR, un identificador no puede iniciar con '*' ni con '/'";
        return -1;
    }
    for(int i = 0; i < largo; i++)
    {
        if(!isalnum(cadena[i]))
            letra = true;
    }
    if(letra)
    {
        cout<<" : ERROR, un identificador no puede contener '*' ni '/'";
        return -1;
    }
    cout<<cadena<<" : Operador multiplicacion";
    return 6;
}

int opRel(string& cadena)
{
    cout<<cadena;
    bool letra = false;
    int largo = cadena.length();
    if((cadena[0] == '<' && largo == 1) || (cadena[0] == '>' && largo == 1))
    {
        cout<<" : Operador relacional";
        return 7;
    }
    else if((cadena[0] == '<' && cadena[1] == '=' && largo == 2))
    {
        cout<<" : Operador relacional";
        return 7;
    }
    else if((cadena[0] == '>' && cadena[1] == '=' && largo == 2))
    {
        cout<<" : Operador relacional";
        return 7;
    }
    else if((cadena[0] == '<' && largo > 1) || (cadena[0] == '>' && largo > 1))
    {
        cout<<" : ERROR, un identificador no puede iniciar con '<' ni con '>'";
        return -1;
    }
    else if(cadena[0] == '=' && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con '='";
        return -1;
    }
    for(int i = 0; i < largo; i++)
    {
        if(!isalnum(cadena[i]))
            letra = true;
    }
    if(letra)
    {
        cout<<" : ERROR, un identificador no puede contener '<', '>', '<=', ni '>='";
        return -1;
    }
    cout<<cadena<<" : Operador relacional";
    return 7;
}

int opOr(string& cadena)
{
    cout<<cadena;
    bool letra = false;
    int largo = cadena.length();
    if(cadena[0] == '|' && largo == 1)
    {
        cout<<" : ERROR, quisiste decir '||' ?";
        return -1;
    }
    else if(cadena[0] == '|' && cadena[1] == '|' && largo == 2)
    {
        cout<<" : Operador OR";
        return 8;
    }
    else if(cadena[0] == '|' && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con '|'";
        return -1;
    }
    for(int i = 0; i < largo; i++)
    {
        if(!isalnum(cadena[i]))
            letra = true;
    }
    if(letra)
    {
        cout<<" : ERROR, un identificador no puede contener '|'";
        return -1;
    }
    cout<<cadena<<" : Operador OR";
    return 8;
}

int opAnd(string& cadena)
{
    cout<<cadena;
    bool letra = false;
    int largo = cadena.length();
    if(cadena[0] == '&' && largo == 1)
    {
        cout<<" : ERROR, quisiste decir '&&' ?";
        return -1;
    }
    else if(cadena[0] == '&' && cadena[1] == '&' && largo == 2)
    {
        cout<<" : Operador AND";
        return 9;
    }
    else if(cadena[0] == '&' && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con '&'";
        return -1;
    }
    for(int i = 0; i < largo; i++)
    {
        if(!isalnum(cadena[i]))
            letra = true;
    }
    if(letra)
    {
        cout<<" : ERROR, un identificador no puede contener '&'";
        return -1;
    }
    cout<<cadena<<": Operador AND";
    return 9;
}

int opNot(string& cadena)
{
    cout<<cadena;
    bool letra = false;
    int largo = cadena.length();
    if(cadena[0] == '!' && largo == 1)
    {
        cout<<" : Operador Not";
        return 10;
    }
    else if(cadena[0] == '!' && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con '!'";
        return -1;
    }
    for(int i = 0; i < largo; i++)
    {
        if(!isalnum(cadena[i]))
            letra = true;
    }
    if(letra)
    {
        cout<<" : ERROR, un identificador no puede contener '!'";
        return -1;
    }
    cout<<cadena<<" : Operador Not";
    return 10;
}

int opIgualdad(string& cadena)
{
    cout<<cadena;
    int largo = cadena.length();
    if(largo == 2)
    {
        cout<<" : Operador igualdad";
        return 11;
    }
    if(largo > 2 && isalpha(cadena[0]))
    {
        cout<<" : ERROR, un identificador no puede contener '!=' ni '=='";
        return -1;
    }
    else
    {
        cout<<" : ERROR, un identificador no puede iniciar con '!=' ni con '=='";
        return -1;
    }
    cout<<cadena<<" : Operador igualdad";
    return 11;
}

int carPuntoYComa(string& cadena)
{
    cout<<cadena;
    int largo = cadena.length();
    if(cadena[0] == ';' && largo == 1)
    {
        cout<<" : ;";
        return 12;
    }
    if(cadena[0] == ';' && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con ';'";
        return -1;
    }
    else
    {
        cout<<" : ERROR, un identificador no puede contener ';'";
        return -1;
    }
    cout<<cadena<<" : ;";
    return 12;
}

int carComa(string& cadena)
{
    cout<<cadena;
    int largo = cadena.length();
    if(cadena[0] == ',' && largo == 1)
    {
        cout<<" : ,";
        return 13;
    }
    if(cadena[0] == ',' && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con ','";
        return -1;
    }
    else
    {
        cout<<" : ERROR, un identificador no puede contener ','";
        return -1;
    }
    cout<<cadena<<" : ;";
    return 13;
}

int carParentesis1(string& cadena)
{
    cout<<cadena;
    int largo = cadena.length();
    if(cadena[0] == '(' && largo == 1)
    {
        cout<<" : (";
        return 14;
    }
    if(cadena[0] == '(' && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con '('";
        return -1;
    }
    else
    {
        cout<<" : ERROR, un identificador no puede contener '('";
        return -1;
    }
    cout<<cadena<<" : (";
    return 14;
}

int carParentesis2(string& cadena)
{
    cout<<cadena;
    int largo = cadena.length();
    if(cadena[0] == ')' && largo == 1)
    {
        cout<<" : )";
        return 15;
    }
    if(cadena[0] == ')' && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con ')'";
        return -1;
    }
    else
    {
        cout<<" : ERROR, un identificador no puede contener ')'";
        return -1;
    }
    cout<<cadena<<" : )";
    return 15;
}

int carLlave1(string& cadena)
{
    cout<<cadena;
    int largo = cadena.length();
    if(cadena[0] == '{' && largo == 1)
    {
        cout<<" : {";
        return 16;
    }
    if(cadena[0] == '{' && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con '{'";
        return -1;
    }
    else
    {
        cout<<" : ERROR, un identificador no puede contener '{'";
        return -1;
    }
    cout<<cadena<<" : {";
    return 16;
}

int carLlave2(string& cadena)
{
    cout<<cadena;
    int largo = cadena.length();
    if(cadena[0] == '}' && largo == 1)
    {
        cout<<" : }";
        return 17;
    }
    if(cadena[0] == '}' && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con '}'";
        return -1;
    }
    else
    {
        cout<<" : ERROR, un identificador no puede contener '}'";
        return -1;
    }
    cout<<cadena<<" : }";
    return 17;
}

int carIgual(string& cadena)
{
    cout<<cadena;
    int largo = cadena.length();
    if(cadena[0] == '=' && largo == 1)
    {
        cout<<" : =";
        return 18;
    }
    if(cadena[0] == '=' && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con '='";
        return -1;
    }
    else
    {
        cout<<" : ERROR, un identificador no puede contener '='";
        return -1;
    }
    cout<<cadena<<" : =";
    return 18;
}

int reservadas(string& cadena)
{
    cout<<cadena<<" : Reservada";
    if(cadena == "if")
        return 19;
    else if(cadena == "while")
        return 20;
    else if(cadena == "return")
        return 21;
    else if( cadena == "else")
        return 22;
    return -1;
}

int carPeso(string& cadena)
{
    cout<<cadena;
    int largo = cadena.length();
    if(cadena[0] == '$' && largo == 1)
    {
        cout<<" : $";
        return 2;
    }
    if(cadena[0] == '$' && largo > 1)
    {
        cout<<" : ERROR, un identificador no puede iniciar con '$'";
        return -1;
    }
    else
    {
        cout<<" : ERROR, un identificador no puede contener '$'";
        return -1;
    }
    cout<<cadena<<" : $";
    return 2;
}
