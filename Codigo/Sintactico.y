%{
    #include <stdio.h>
    #include <stdlib.h>
    FILE *yyin // es el archivo de entrada
%}

%token OP_ASIG 
%token OP_GT 
%token OP_LT 
%token OP_GE 
%token OP_LE 
%token OP_EQ 
%token OP_SUM 
%token OP_MULT 
%token OP_MEN 
%token OP_DIV 

%token OP_OR 
%token OP_AND 
%token NOT
%token OP_DIST 

%token OP_ENDLINE 
%token OP_COMA 
%token OP_PAR 
%token CL_PAR 
%token OP_KEY 
%token CL_KEY 
%token OP_CORC 
%token CL_COR 

%token WHILE 
%token IF 
%token ENDIF 
%token ELSE 
%token DIM 
%token AS 
%token IN
%token DO
%token ENDWHILE
%token FOR
%token TO
%token NEXT

%token INT_TYPE 
%token REAL_TYPE 
%token STRING_TYPE 

%token DIGITO 
%token CARACTER
%token COMMENT 


%token STRING_DEC  
%token INT_NUM 
%token FLOAT_NUM 

%token DISPLAY 
%token GET 
%token ID

%%
programa: main;
main: declaracion_var resto_programa;

declaracion_var: DIM OP_CORC list_var CL_COR AS OP_CORC list_types CL_COR;
list_var: ID {printf("ID: %s \n");} | list_var OP_COMA ID {printf("list_var OP_COMA ID \n")}; 
type_var: INT_TYPE | REAL_TYPE | STRING_TYPE;
list_types: type_var | list_types OP_COMA type_var;

resto_programa: sentencia | resto_programa sentencia;

sentencia: while | if | for | asignacion;

while: WHILE ID IN list_exp DO sentencia ENDWHILE;

exp_while: OP_CORC list_exp CL_COR;
list_exp: expresion | list_exp OP_COMA expresion;

if: IF OP_PAR condicion CL_PAR sentencia ENDIF | IF OP_PAR condicion CL_PAR sentencia ELSE sentencia ENDIF;
condicion: comparacion | condicion OP_AND comparacion | condicion OP_OR comparacion | NOT comparacion;
comparacion: expresion op_comparacion expresion;

expresion: termino | expresion OP_SUM termino | expresion OP_MEN termino;
termino: asig_val | termino OP_MULT asig_val | termino OP_DIV asig_val;

for: FOR ID OP_ASIG asig_val TO asig_val pasos_for sentencia NEXT ID | FOR ID OP_ASIG asig_val TO asig_val sentencia NEXT ID;
pasos_for: OP_CORC expresion CL_COR;

asig_val: ID|INT_NUM|FLOAT_NUM|STRING_DEC;

asignacion: ID OP_ASIG expresion;

display: DISPLAY asig_val;
get_action: GET ID;

op_comparacion: OP_EQ | OP_GE | OP_GT | OP_LE | OP_LT | OP_DIST; 

//condicion_anidada: comparacion OP_AND comparacion | comparacion OP_OR comparacion; 

%%

int yylex(void)
{
    
}

int yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}

int main (int argc, char *argv[])
{
    while(!feof(yyin))
    {
        yyparse();
    }
}

/* YYPARSE() -> lleva adelante el proceso de analisis sintactico. Invoca a YYLEX() para solicitar un token y este le devuelve
Los valores de los tokens (lexemas) los guarda en la variable yylval.
YYPARSE() devuelve 0 cuando ya se analizo todo el archivo
si se detecta un error YYPARSE() devuelve 1. Con yyerrok reestablecemos el analizador al modo normal */