%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <string.h>
  #include "Simbolos.h"
  #include "Arbol.h"
  extern int yylex(void);
  extern char *yytext;
  extern int linea;
  extern FILE *yyin;
  void yyerror(char *s);
  void inicializarTabla();
  void crearTabla();

  //Punteros para arbol sintáctico
  structNodo* programaPtr;
  structNodo* mainPtr;
  structNodo* bloquePtr;
  structNodo* sentenciaPtr;
  structNodo* declaracion_varPtr;
  structNodo* list_varPtr;
  structNodo* type_varPtr;
  structNodo* list_typesPtr;
  structNodo* whilePtr;
  structNodo* while_especialPtr;
  structNodo* exp_whilePtr;
  structNodo* list_expPtr;
  structNodo* ifPtr;
  structNodo* ifCuerpoPtr;
  structNodo* condicionPtr;
  structNodo* condicion_anidadaPtr;
  structNodo* comparacion_simplePtr;
  structNodo* expresionPtr;
  structNodo* terminoPtr;
  structNodo* termino_parPtr;
  structNodo* forPtr;
  structNodo* forCuerpoPtr;
  structNodo* pasos_forPtr;
  structNodo* asig_valPtr;
  structNodo* asignacionPtr;
  structNodo* displayPtr;
  structNodo* get_actionPtr;
  structNodo* op_comparacionPtr;

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
programa: main {printf("\nmain"); programaPtr = mainPtr; escribirGragh(programaPtr);};
main: bloque {printf("\nbloque"); mainPtr = bloquePtr;};
bloque: sentencia {printf("\nsentencia"); bloquePtr = sentenciaPtr;} 
                | bloque sentencia {printf("\nbloque sentencia"); bloquePtr = crearNodo("bloque", bloquePtr, sentenciaPtr);};

sentencia: while {printf("\nwhile:"); sentenciaPtr = whilePtr;}
            | while_especial {printf("\nwhile_especial:"); sentenciaPtr = while_especialPtr;} 
            | if {printf("\nif:"); sentenciaPtr = ifPtr;} 
            | for {printf("\nfor"); sentenciaPtr = forPtr;} 
            | asignacion OP_ENDLINE {printf("\nasginacion"); sentenciaPtr = asignacionPtr;} 
            | declaracion_var OP_ENDLINE {printf("\ndeclaracion_var");sentenciaPtr = declaracion_varPtr;}
            | expresion OP_ENDLINE {printf("\ndeclaracion_var");sentenciaPtr = expresionPtr;}
            | display OP_ENDLINE {printf("\ndeclaracion_var");sentenciaPtr = displayPtr;}
            | get_action OP_ENDLINE {printf("\ndeclaracion_var");sentenciaPtr = get_actionPtr;};

declaracion_var: DIM OP_CORC list_var CL_COR AS OP_CORC list_types CL_COR {printf("\nDIM OP_CORC list_var CL_COR AS OP_CORC list_types CL_COR "); declaracion_varPtr = crearNodo("DEC_VAR", list_varPtr, list_typesPtr);};
list_var: ID {printf("\nID"); list_varPtr = crearHoja("ID");}
        | list_var OP_COMA ID {printf("\nlist_var OP_COMA ID "); list_varPtr = crearNodo(",", list_varPtr, crearHoja("ID"));}; 
type_var: INT_TYPE {printf("\nINT_TYPE:");type_varPtr = crearHoja("INT_TYPE");}
        | REAL_TYPE {printf("\nREAL_TYPE");type_varPtr = crearHoja("REAL_TYPE");} 
        | STRING_TYPE {printf("\nSTRING_TYPE");type_varPtr = crearHoja("STRING_TYPE");};
list_types: type_var {printf("\ntype_var");list_typesPtr = type_varPtr;} 
            | list_types OP_COMA type_var {printf("\nlist_types OP_COMA type_var");crearNodo(",", list_typesPtr, type_varPtr);};

while: WHILE condicion DO bloque {whilePtr = crearNodo("WHILE", condicionPtr, bloquePtr);}ENDWHILE {printf("\nWHILE condicion DO bloque ENDWHILE");};

while_especial: WHILE ID IN exp_while DO bloque {while_especialPtr = crearNodo("WHILE_ESP", crearNodo("IN", crearHoja("ID"), exp_whilePtr), bloquePtr);} ENDWHILE {printf("\nWHILE ID IN list_exp DO bloque ENDWHILE");};
exp_while: OP_CORC list_exp CL_COR {printf("\nOP_CORC list_exp CL_CO"); exp_whilePtr = crearNodo("[", list_expPtr, crearHoja("]"));};
list_exp: expresion {printf("\nID"); list_expPtr = expresionPtr;}
          | list_exp OP_COMA expresion {printf("\nlist_exp OP_COMA ID"); list_expPtr = crearNodo(",", list_expPtr, expresionPtr);};

if: IF OP_PAR condicion CL_PAR bloque {ifPtr = crearNodo("IF", condicionPtr, bloquePtr);} ENDIF {printf("\nIF OP_PAR condicion CL_PAR bloque ENDIF");} 
    | IF OP_PAR condicion CL_PAR bloque ELSE bloque {ifCuerpoPtr = crearNodo("Cuerpo", bloquePtr, bloquePtr); ifPtr = crearNodo("IF", condicionPtr, ifCuerpoPtr);} ENDIF {printf("\nIF OP_PAR condicion CL_PAR bloque ELSE bloque ENDIF");};
condicion: comparacion_simple {printf("\ncomparacion_simple"); condicionPtr = comparacion_simplePtr;} 
            | condicion_anidada {printf("\ncondicion_anidada"); condicionPtr = condicion_anidadaPtr;} 
            | NOT comparacion_simple {printf("\nNOT comparacion_simple");};
condicion_anidada: condicion OP_AND comparacion_simple {printf("\ncondicion OP_AND comparacion_simple"); condicion_anidadaPtr = crearNodo("AND", condicionPtr, comparacion_simplePtr);} 
                  | condicion OP_OR comparacion_simple {printf("\ncondicion OP_OR comparacion_simple"); condicion_anidadaPtr = crearNodo("OR", condicionPtr, comparacion_simplePtr);};
comparacion_simple: expresion op_comparacion expresion {printf("\nexpresion op_comparacion expresion"); comparacion_simplePtr = crearNodo2(op_comparacionPtr, expresionPtr, expresionPtr);};

expresion: termino {printf("\ntermino"); expresionPtr = terminoPtr;} 
            | expresion OP_SUM termino {printf("\nexpresion OP_SUM termino"); expresionPtr = crearNodo("+", expresionPtr, terminoPtr);} 
            | expresion OP_MEN termino {printf("\nexpresion OP_MEN termino"); expresionPtr = crearNodo("-", expresionPtr, terminoPtr);};
termino: termino_par {printf("\ntermino_par"); terminoPtr = termino_parPtr;} 
          | termino OP_MULT termino_par {printf("\ntermino OP_MULT termino_par"); terminoPtr = crearNodo("*", terminoPtr, termino_parPtr);} 
          | termino OP_DIV termino_par {printf("\ntermino OP_DIV termino_par"); terminoPtr = crearNodo("/", terminoPtr, termino_parPtr);};
termino_par: asig_val {printf("\nasig_val"); termino_parPtr = asig_valPtr;} 
            | OP_PAR expresion CL_PAR {printf("\nOP_PAR expresion CL_PAR");termino_parPtr = crearNodo("(", expresionPtr, crearHoja(")"));};

for: FOR ID OP_ASIG asig_val TO asig_val pasos_for {forCuerpoPtr = crearNodo("TO", asig_valPtr, crearNodo("STEP", asig_valPtr, pasos_forPtr));} bloque NEXT ID {printf("\nFOR ID OP_ASIG asig_val TO asig_val pasos_for bloque NEXT ID");} 
    | FOR ID OP_ASIG asig_val TO asig_val {forCuerpoPtr = crearNodo("TO", asig_valPtr, asig_valPtr);} bloque NEXT ID {printf("\nFOR ID OP_ASIG asig_val TO asig_val bloque NEXT ID"); forPtr = crearNodo("FOR", forCuerpoPtr, bloquePtr);};
pasos_for: OP_CORC expresion CL_COR {printf("\nOP_CORC expresion CL_COR"); pasos_forPtr = crearHoja("expresion");};

asig_val: ID {printf("\nID"); asig_valPtr = crearHoja("ID");}
          | INT_NUM {printf("\nINT_NUM"); asig_valPtr = crearHoja("INT_NUM");}
          | FLOAT_NUM {printf("\nFLOAT_NUM");asig_valPtr = crearHoja("FLOAT_NUM");}
          | STRING_DEC {printf("\nSTRING_DEC");asig_valPtr = crearHoja("STRING_DEC");};

asignacion: ID OP_ASIG expresion {printf("\nID OP_ASIG expresion");asignacionPtr = crearNodo(":=", crearHoja("ID"), expresionPtr);};

display: DISPLAY asig_val {printf("\nDISPLAY asig_val");crearNodo("display", crearHoja("DISPLAY"), asig_valPtr);};
get_action: GET ID {printf("\nGET ID"); get_actionPtr = crearNodo("get_action", crearHoja("GET"), crearHoja("ID"));};

op_comparacion: OP_EQ {printf("\nOP_EQ"); op_comparacionPtr = crearHoja($1);} 
              | OP_GE {printf("\nOP_GE"); op_comparacionPtr = crearHoja(">=");} 
              | OP_GT {printf("\nOP_GT"); op_comparacionPtr = crearHoja(">");} 
              | OP_LE {printf("\nOP_LE"); op_comparacionPtr = crearHoja("<=");} 
              | OP_LT {printf("\nOP_LT"); op_comparacionPtr = crearHoja("<");} 
              | OP_DIST {printf("\nOP_DIST"); op_comparacionPtr = crearHoja("!=");}; 

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
  return 0;
}

void inicializarTabla(){
  simbolos[0].nombre = (char*) malloc(31);
  strcpy(simbolos[0].nombre, "Nombre");

  simbolos[0].tipoDato = (char*) malloc(31);
  strcpy(simbolos[0].tipoDato, "Tipo");

  simbolos[0].valor = (char*) malloc(31);
  strcpy(simbolos[0].valor, "Valor");

  simbolos[0].longitud = (char*) malloc(31);
  strcpy(simbolos[0].longitud, "Longitud");

  simbolos[0].token = (char*) malloc(31);
  strcpy(simbolos[0].token, "Token");
}

void crearTabla(){
  int i;
  FILE* pf;
  pf = fopen("ts.txt", "wt");
  // printf("\nLargo de la tabla de simbolos: %d\n", getCantActual());
  for(i = 0; i < getCantActual(); i++){
    printf("%d\n", i);
    fprintf(pf, "%-20s%-20s%-20s%-20s%-20s\n", simbolos[i].nombre, simbolos[i].tipoDato, simbolos[i].valor, simbolos[i].longitud, simbolos[i].token);
  }
  fclose(pf);
}

/* YYPARSE() -> lleva adelante el proceso de analisis sintactico. Invoca a YYLEX() para solicitar un token y este le devuelve
Los valores de los tokens (lexemas) los guarda en la variable yylval.
YYPARSE() devuelve 0 cuando ya se analizo todo el archivo
si se detecta un error YYPARSE() devuelve 1. Con yyerrok reestablecemos el analizador al modo normal */