%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <string.h>
  #include "simbolos.h"
  extern int yylex(void);
  extern char *yytext;
  extern int linea;
  extern FILE *yyin;
  void yyerror(char *s);
  void inicializarTabla();
  void crearTabla();
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
programa: main {printf("\nmain");};
main: resto_programa {printf("\nresto_programa");};
resto_programa: sentencia {printf("\nsentencia");} 
                | resto_programa sentencia {printf("\nresto_programa sentencia");};

sentencia: while {printf("\nwhile:");} 
            | if {printf("\nif:");} 
            | for {printf("\nfor");} 
            | asignacion OP_ENDLINE {printf("\nasginacion");} 
            | declaracion_var OP_ENDLINE {printf("\ndeclaracion_var");}
            | expresion OP_ENDLINE {printf("\ndeclaracion_var");}
            | display OP_ENDLINE {printf("\ndeclaracion_var");}
            | get_action OP_ENDLINE {printf("\ndeclaracion_var");};

declaracion_var: DIM OP_CORC list_var CL_COR AS OP_CORC list_types CL_COR {printf("\nDIM OP_CORC list_var CL_COR AS OP_CORC list_types CL_COR ");};
list_var: ID {printf("\nID");}
        | ID OP_COMA list_var {printf("\nlist_var OP_COMA ID ");}; 
type_var: INT_TYPE {printf("\nINT_TYPE:");}
        | REAL_TYPE {printf("\nREAL_TYPE");} 
        | STRING_TYPE {printf("\nSTRING_TYPE");};
list_types: type_var {printf("\ntype_var");} 
            | list_types OP_COMA type_var {printf("\nlist_types OP_COMA type_var");};

while: WHILE ID IN exp_while DO sentencia ENDWHILE {printf("\nWHILE ID IN list_exp DO sentencia ENDWHILE");};
exp_while: OP_CORC list_exp CL_COR {printf("\nOP_CORC list_exp CL_CO");};
list_exp: ID {printf("\nID");} 
          | ID OP_COMA list_exp {printf("\nlist_exp OP_COMA ID");};

if: IF OP_PAR condicion CL_PAR sentencia ENDIF {printf("\nIF OP_PAR condicion CL_PAR sentencia ENDIF");} 
    | IF OP_PAR condicion CL_PAR sentencia ELSE sentencia ENDIF {printf("\nIF OP_PAR condicion CL_PAR sentencia ELSE sentencia ENDIF");};
condicion: comparacion {printf("\nexpresion");} 
            | condicion_anidada {printf("\nexpresion");} 
            | NOT comparacion {printf("\nexpresion");};
condicion_anidada: comparacion OP_AND comparacion {printf("\ncomparacion OP_AND comparacion");} 
                  | comparacion OP_OR comparacion {printf("\ncomparacion OP_OR comparacion");}; 
comparacion: expresion op_comparacion expresion {printf("\nexpresion op_comparacion expresion");};

expresion: termino {printf("\ntermino");} 
            | expresion OP_SUM termino {printf("\nexpresion OP_SUM termino");} 
            | expresion OP_MEN termino {printf("\nexpresion OP_MEN termino");};
termino: termino_par {printf("\ntermino_par");} 
          | termino OP_MULT termino_par {printf("\ntermino OP_MULT termino_par");} 
          | termino OP_DIV termino_par {printf("\ntermino OP_DIV termino_par");};
termino_par: asig_val {printf("\nasig_val");} 
            | OP_PAR expresion CL_PAR {printf("\nOP_PAR expresion CL_PAR");};

for: FOR ID OP_ASIG asig_val TO asig_val pasos_for sentencia NEXT ID {printf("\nFOR ID OP_ASIG asig_val TO asig_val pasos_for sentencia NEXT ID");} 
    | FOR ID OP_ASIG asig_val TO asig_val sentencia NEXT ID {printf("\nFOR ID OP_ASIG asig_val TO asig_val sentencia NEXT ID");};
pasos_for: OP_CORC expresion CL_COR {printf("\nOP_CORC expresion CL_COR");};

asig_val: ID {printf("\nID");}
          | INT_NUM {printf("\nINT_NUM");}
          | FLOAT_NUM {printf("\nFLOAT_NUM");}
          | STRING_DEC {printf("\nSTRING_DEC");};

asignacion: ID OP_ASIG expresion {printf("\nID OP_ASIG expresion");};

display: DISPLAY asig_val {printf("\nDISPLAY asig_val");};
get_action: GET ID {printf("\nGET ID");};

op_comparacion: OP_EQ {printf("\nOP_EQ");} 
              | OP_GE {printf("\nOP_GE");} 
              | OP_GT {printf("\nOP_GT");} 
              | OP_LE {printf("\nOP_LE");} 
              | OP_LT {printf("\nOP_LT");} 
              | OP_DIST {printf("\nOP_DIST");}; 

%%

void yyerror(char *s)
{
  printf("\nError sintactico %s",s);
}
// int yyerror(char *s)
// {
//     fprintf(stderr, "%s\n", s);
// }
int main(int argc,char **argv)
{
  inicializarTabla();
  if (argc>1)
                yyin=fopen(argv[1],"rt");
  else
                yyin=stdin;
  yyparse();
  crearTabla();
  system("Pause");
  return 0;
}

void inicializarTabla(){
  simbolos[0].lexema = (char*) malloc(30);
  strcpy(simbolos[0].lexema, "Lexema");

  simbolos[0].tipoDato = (char*) malloc(30);
  strcpy(simbolos[0].tipoDato, "Tipo");

  simbolos[0].valor = (char*) malloc(30);
  strcpy(simbolos[0].valor, "Valor");

  simbolos[0].longitud = (char*) malloc(30);
  strcpy(simbolos[0].longitud, "Longitud");

  simbolos[0].token = (char*) malloc(30);
  strcpy(simbolos[0].token, "Token");
}

void crearTabla(){
  int i;
  FILE* pf;
  pf = fopen("ts.txt", "wt");
  printf("\nLargo de la tabla de simbolos: %d\n", cantActual);
  for(i = 0; i < cantActual; i++){
    fprintf(pf, "%-20s%-20s%-20s%-20s%-20s\n", simbolos[i].lexema, simbolos[i].tipoDato, simbolos[i].valor, simbolos[i].longitud, simbolos[i].token);
  }
  fclose(pf);
}

/* YYPARSE() -> lleva adelante el proceso de analisis sintactico. Invoca a YYLEX() para solicitar un token y este le devuelve
Los valores de los tokens (lexemas) los guarda en la variable yylval.
YYPARSE() devuelve 0 cuando ya se analizo todo el archivo
si se detecta un error YYPARSE() devuelve 1. Con yyerrok reestablecemos el analizador al modo normal */