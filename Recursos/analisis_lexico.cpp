#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* Son los tokens que reconocerá el analizador */
enum {  
    FIN = 0, 
    ID = 256, 
    NUM, 
    FOR, 
    IF, 
    THEN, 
    ELSE, 
    INT, 
    WHILE,
    RETURN,
    INCLUDE,
    DEFINE
};
char buffer[500];
char * yytext;
char * p;
int yyleng;
#define MAXIMO 9
struct {
    char * nombre;
    int token;
} tabla[MAXIMO] = {"for", FOR, "if", IF, "then", THEN, "else", ELSE,"int", INT, "while",WHILE,"return",RETURN,"include",INCLUDE,"define",DEFINE};

int yylex(void);

int main() {
    int t;
    printf("Comienza el programa\n");
    while ((t=yylex()) != FIN)
    {

        switch(t) {
        case NUM:
            printf("Numero '%s' de %d digitos\n", yytext, yyleng);
            break;
        case ID:
            printf("ID '%s' de %d caracteres\n", yytext, yyleng);
            break;
        case FOR:
        case IF:
        case THEN:
        case ELSE:
        case INT:
        case WHILE:
        case RETURN:
        case INCLUDE:
        case DEFINE:
        printf("palabra reservada '%s' de %d caracteres\n", yytext, yyleng);
        break;
        default:
        printf("Es el caracter '%c'\n",t);
        break;
        }
    }
    return EXIT_SUCCESS;
}

int yylex(void)
{
    int c;
    /*Filtramos los espacios*/
    while((c=getchar()) == ' ' || c == '\n' || c == '\t');
        if(c==EOF) return FIN;
        yytext = buffer;
        p = buffer;
        if(isdigit(c)) 
        {
            do 
            {
                *p = c;
                p++;
                c = getchar();
            }while(isdigit(c));

            if(c != EOF) ungetc(c,stdin);
            *p = 0;
            yyleng = p - yytext;
            return NUM;
        }
        else if (isalpha(c)) 
        {
            int i;
            do 
            {
                *p = c;
                p++;
                c = getchar();
            }while(isalnum(c));
            
            if(c != EOF) ungetc(c,stdin);
            
            *p = 0;
            
            yyleng = p - yytext;
            
            for(i = 0; i < MAXIMO; i++)
                if(strcmp(tabla[i].nombre, yytext) == 0)
                    return tabla[i].token;
            
            return ID;
        }
    else return c;
}