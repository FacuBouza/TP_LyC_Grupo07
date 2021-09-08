%{

#include <stdio.h>
#include <stdlib.h>
FILE *yyin;

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


%%

{COMMENT} {printf("\nCOMMENT: %s", yytext);}

{GET} {printf("\nGET: %s", yytext);}
{IN} {printf("\nIN: %s", yytext);}
{DO} {printf("\nDO: %s", yytext);}
{ENDWHILE} {printf("\nENDWHILE: %s", yytext);}
{FOR} {printf("\nFOR: %s", yytext);}
{NEXT} {printf("\nNEXT: %s", yytext);}
{TO} {printf("\nTO: %s", yytext);}
{DISPLAY} {printf("\nDISPLAY: %s", yytext);}
{OP_ASIG} {printf("\nOP_ASIG: %s", yytext);}
{OP_GT} {printf("\nOP_GT: %s", yytext);}
{OP_LT} {printf("\nOP_LT: %s", yytext);}
{OP_GE} {printf("\nOP_GE: %s", yytext);}
{OP_LE} {printf("\nOP_LE: %s", yytext);}
{OP_EQ} {printf("\nOP_EQ: %s", yytext);}
{OP_SUM} {printf("\nOP_SUM: %s", yytext);}
{OP_MULT} {printf("\nOP_MULT: %s", yytext);}
{OP_MEN} {printf("\nOP_MEN: %s", yytext);}
{OP_DIV} {printf("\nOP_DIV: %s", yytext);}
{OP_DIST} {printf("\nOP_DIST: %s", yytext);}
{OP_OR} {printf("\nOP_OR: %s", yytext);}
{OP_AND} {printf("\nOP_AND: %s", yytext);}
{NOT} {printf("\nNOT: %s", yytext);}
{OP_ENDLINE} {printf("\nOP_ENDLINE: %s", yytext);}
{OP_COMA} {printf("\nOP_COMA: %s", yytext);}
{OP_PAR} {printf("\nOP_PAR: %s", yytext);}
{CL_PAR} {printf("\nCL_PAR: %s", yytext);}
{OP_KEY} {printf("\nOP_KEY: %s", yytext);}
{CL_KEY} {printf("\nCL_KEY: %s", yytext);}
{OP_CORC} {printf("\nOP_CORC: %s", yytext);}
{CL_COR} {printf("\nCL_COR: %s", yytext);}
{WHILE} {printf("\nWHILE: %s", yytext);}
{IF} {printf("\nIF: %s", yytext);}
{ENDIF} {printf("\nENDIF: %s", yytext);}
{ELSE} {printf("\nELSE: %s", yytext);}
{DIM} {printf("\nDIM: %s", yytext);}
{AS} {printf("\nAS: %s", yytext);}
{INT_TYPE} {printf("\nINT_TYPE: %s", yytext);}
{REAL_TYPE} {printf("\nREAL_TYPE: %s", yytext);}
{STRING_TYPE} {printf("\nSTRING_TYPE: %s", yytext);}

{ID}    {printf("\nID: %s", yytext);}
{STRING_DEC}  {printf("\nSTRING_DEC: %s", yytext);}
{INT_NUM} {printf("\nINT_NUM: %s", yytext);}
{FLOAT_NUM} {printf("\nFLOAT_NUM: %s", yytext);}


%%


int main(int argc,char *argv[])
{
    if ((yyin = fopen(argv[1], "rt")) == NULL)
    {
        printf("No se puede abrir el archivo: %s n", argv[1]);
    }
    else
    {
        yylex();
    }
    fclose(yyin);

}
int yyerror(void)
{
    printf("Error léxico: Caracter inválido: %s\n", yytext);
    exit (1);
}

