%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

#define MIN_INT -32768
#define MAX_INT 32767
#define MAX_LEN_STRING 30
#define MIN_FLOAT -100000
#define MAX_FLOAT 100000

FILE *yyin;

void procesarID();
void procesarInt();
void procesarFloat();
void procesarString();
void agregarSimbolo(char* lexema, char* tipoDato, char* valor, int longitud, char* token);

%}

%option noyywrap
%option yylineno

DIGITO [0-9]
CARACTER [A-Za-z]

OP_ASIG ":="
OP_GT ">"
OP_LT "<"
OP_GE ">="
OP_LE "<="
OP_EQ "=="
OP_SUM "+"
OP_MULT "*"
OP_MEN "-"
OP_DIV "/"
OP_DIST "!=" 

OP_OR "OR"
OP_AND "AND"
NOT "NOT"


OP_ENDLINE ";"
OP_COMA ","
OP_PAR "("
CL_PAR ")"
OP_KEY "{"
CL_KEY "}"
OP_CORC "["
CL_COR "]"

WHILE "WHILE"
IF "IF"
ENDIF "ENDIF"
ELSE "ELSE"
DIM "DIM"
AS "AS"
IN "IN"
DO "DO"
ENDWHILE "ENDWHILE"
FOR "FOR"
TO "TO"
NEXT "NEXT"

INT_TYPE "integer"
REAL_TYPE "real"
STRING_TYPE "string"

COMMENT [/][*].*[*][/]

ID {CARACTER}({DIGITO}|{CARACTER})*

STRING_DEC  ["].*["]

INT_NUM -?{DIGITO}*
FLOAT_NUM -?[1-9]?.([0-9]*{5}).[.].([0-9]*{6})

DISPLAY "DISPLAY"
GET "GET"

SALTO_LINEA [\t\r\f]


%%

{COMMENT} {printf("\nCOMMENT: %s", yytext);}

{GET} {printf("\nGET: %s", yytext); return GET;}
{IN} {printf("\nIN: %s", yytext); return IN;}
{DO} {printf("\nDO: %s", yytext); return DO;}
{ENDWHILE} {printf("\nENDWHILE: %s", yytext); return ENDWHILE;}
{FOR} {printf("\nFOR: %s", yytext); return FOR;}
{NEXT} {printf("\nNEXT: %s", yytext); return NEXT;}
{TO} {printf("\nTO: %s", yytext); return TO;}
{DISPLAY} {printf("\nDISPLAY: %s", yytext); return DISPLAY;}
{OP_ASIG} {printf("\nOP_ASIG: %s", yytext); return OP_ASIG;}
{OP_GT} {printf("\nOP_GT: %s", yytext); return OP_GT;}
{OP_LT} {printf("\nOP_LT: %s", yytext); return OP_LT;}
{OP_GE} {printf("\nOP_GE: %s", yytext); return OP_GE;}
{OP_LE} {printf("\nOP_LE: %s", yytext); return OP_LE;}
{OP_EQ} {printf("\nOP_EQ: %s", yytext); return OP_EQ;}
{OP_SUM} {printf("\nOP_SUM: %s", yytext); return OP_SUM;}
{OP_MULT} {printf("\nOP_MULT: %s", yytext); return OP_MULT;}
{OP_MEN} {printf("\nOP_MEN: %s", yytext); return OP_MEN;}
{OP_DIV} {printf("\nOP_DIV: %s", yytext); return OP_DIV;}
{OP_DIST} {printf("\nOP_DIST: %s", yytext); return OP_DIST;}
{OP_OR} {printf("\nOP_OR: %s", yytext); return OP_OR;}
{OP_AND} {printf("\nOP_AND: %s", yytext); return OP_AND;}
{NOT} {printf("\nNOT: %s", yytext); return NOT;}
{OP_ENDLINE} {printf("\nOP_ENDLINE: %s", yytext); return OP_ENDLINE;}
{OP_COMA} {printf("\nOP_COMA: %s", yytext); return OP_COMA;}
{OP_PAR} {printf("\nOP_PAR: %s", yytext); return OP_PAR;}
{CL_PAR} {printf("\nCL_PAR: %s", yytext); return CL_PAR;}
{OP_KEY} {printf("\nOP_KEY: %s", yytext); return OP_KEY;}
{CL_KEY} {printf("\nCL_KEY: %s", yytext); return CL_KEY;}
{OP_CORC} {printf("\nOP_CORC: %s", yytext); return OP_CORC;}
{CL_COR} {printf("\nCL_COR: %s", yytext); return CL_COR;}
{WHILE} {printf("\nWHILE: %s", yytext); return WHILE;}
{IF} {printf("\nIF: %s", yytext); return IF;}
{ENDIF} {printf("\nENDIF: %s", yytext); return ENDIF;}
{ELSE} {printf("\nELSE: %s", yytext); return ELSE;}
{DIM} {printf("\nDIM: %s", yytext); return DIM;}
{AS} {printf("\nAS: %s", yytext); return AS;}
{INT_TYPE} {printf("\nINT_TYPE: %s", yytext); return INT_TYPE;}
{REAL_TYPE} {printf("\nREAL_TYPE: %s", yytext); return REAL_TYPE;}
{STRING_TYPE} {printf("\nSTRING_TYPE: %s", yytext); return STRING_TYPE;}

{ID}    {procesarID(); return ID;}
{STRING_DEC}  {procesarString(); return STRING_DEC;}
{INT_NUM} {procesarInt(); return INT_NUM;}
{FLOAT_NUM} {procesarFloat(); return FLOAT_NUM;}

{SALTO_LINEA} {printf("\nSALTO_LINEA: %s", yytext);};

%%


// int main(int argc,char *argv[])
// {
//     if ((yyin = fopen(argv[1], "rt")) == NULL)
//     {
//         printf("No se puede abrir el archivo: %s n", argv[1]);
//     }
//     else
//     {
//         yylex();
//     }
//     fclose(yyin);

// }
// int yylex (void)
// {
//     estado = 0
// }
// int yyerror(void)
// {
//     printf("Error léxico: Caracter inválido: %s\n", yytext);
//     exit (1);
// }

void procesarID(){
    printf("\nID: %s", yytext);
    agregarSimbolo(yytext, "Entero", yytext, strlen(yytext), "ID");
}

void procesarInt(){
    int num_int = atoi(yytext);
    if(num_int > MAX_INT || num_int < MIN_INT){
        printf("\nError, el numero %s excede el rango entero", yytext);
        exit(-1);
    }else{
        printf("\nINT_NUM: %s", yytext);
        agregarSimbolo(yytext, "Entero", yytext, strlen(yytext), "INT_NUM");
    }
}

void procesarFloat(){
    int num_float = atof(yytext);
    if(num_float > MAX_FLOAT || num_float < MIN_FLOAT){
        printf("\nError, el numero %s excede el rango float", yytext);
        exit(-1);
    }else{
        printf("\nFLOAT_NUM: %s", yytext);
        agregarSimbolo(yytext, "Float", yytext, strlen(yytext), "FLOAT_NUM");
    }
}

void procesarString(){
    int long_string = strlen(yytext);
    if(long_string > MAX_LEN_STRING){
        printf("\nError, el string %s excede el tamanio maximo de %d caracteres", yytext, MAX_LEN_STRING);
        exit(-1);
    }else{
        printf("\nSTRING_TYPE: %s", yytext);
        agregarSimbolo(yytext, "String", yytext, strlen(yytext), "STRING_DEC");
    }
}