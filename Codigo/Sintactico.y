%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <string.h>
  #include "Assembler.h"
  
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
  structNodo* bloquePtr, *bloqueIfPtr;
  structNodo* sentenciaPtr;
  structNodo* sentenciaSimpleptr;
  structNodo* sentenciaCompuestaptr;
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
  structNodo* expresionPtr, *expAuxPtr;
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

  structNodo* bloqueAuxPtr;
  structNodo* forAux;

  structNodo* condNodo;
  structNodo* idPtr;

  structNodo* condicion_primaPtr;

  int _cant_var = 0;
  int _cant_types = 0;
  int _operador;

  structNodo* iniVar, *stepNodo, *condicionFor, *cuerpo2, *ini;

  const char* idIni;

  struct pila pilaPtr;
%}

%union {
    int intval;
    float val;
    char *str_val;
}

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


%token <str_val> STRING_DEC  
%token <str_val> INT_NUM 
%token <str_val> FLOAT_NUM 

%token DISPLAY 
%token GET 
%token <str_val> ID

%%
programa: main {printf("\nmain"); programaPtr = mainPtr; escribirGragh(programaPtr); generarIntermedia(programaPtr); generarAssembler(programaPtr);};
main: bloque {printf("\nbloque"); mainPtr = bloquePtr;};
bloque: sentencia {printf("\nsentencia"); bloquePtr = sentenciaPtr; apilar(&pilaPtr, bloquePtr); printf("\nLo que vos quieras");}
        | bloque sentencia {printf("\nbloque sentencia"); bloquePtr = crearNodo("bloque", desapilar(&pilaPtr), sentenciaPtr); apilar(&pilaPtr, bloquePtr); printf("\nGenera bloque");};


sentencia: sentencia_simple { sentenciaPtr = sentenciaSimpleptr; }
          | sentencia_compuesta { sentenciaPtr = sentenciaCompuestaptr; };

sentencia_simple: asignacion OP_ENDLINE {printf("\nasginacion"); sentenciaSimpleptr = asignacionPtr;} 
                  | display OP_ENDLINE {printf("\ndeclaracion_var");sentenciaSimpleptr = displayPtr;}
                  | declaracion_var OP_ENDLINE {printf("\ndeclaracion_var");sentenciaSimpleptr = declaracion_varPtr;}
                  | expresion OP_ENDLINE {printf("\ndeclaracion_var");sentenciaSimpleptr = expresionPtr;}
                  | get_action OP_ENDLINE {printf("\ndeclaracion_var");sentenciaSimpleptr = get_actionPtr;};

sentencia_compuesta: while {printf("\nwhile:"); sentenciaCompuestaptr = whilePtr;}
            | while_especial {printf("\nwhile_especial:"); sentenciaCompuestaptr = while_especialPtr;} 
            | if {printf("\nif:"); sentenciaCompuestaptr = ifPtr;} 
            | for {printf("\nfor"); sentenciaCompuestaptr = forPtr;};

declaracion_var: DIM OP_CORC list_var CL_COR AS OP_CORC list_types CL_COR {printf("\nDIM OP_CORC list_var CL_COR AS OP_CORC list_types CL_COR "); declaracion_varPtr = crearNodo("DEC_VAR", list_varPtr, list_typesPtr); 
if(_cant_types != _cant_var) return 1; _cant_types = _cant_var = 0;};

list_var: ID {printf("\nID"); list_varPtr = crearHoja($1); _cant_var = 1;}
        | list_var OP_COMA ID {printf("\nlist_var OP_COMA ID "); list_varPtr = crearNodo(",", list_varPtr, crearHoja($3)); _cant_var++;}; 
type_var: INT_TYPE {printf("\nINT_TYPE:");type_varPtr = crearHoja("INT_TYPE");}
        | REAL_TYPE {printf("\nREAL_TYPE");type_varPtr = crearHoja("REAL_TYPE");} 
        | STRING_TYPE {printf("\nSTRING_TYPE");type_varPtr = crearHoja("STRING_TYPE");};
list_types: type_var {printf("\ntype_var");list_typesPtr = type_varPtr; _cant_types = 1; } 
            | list_types OP_COMA type_var {printf("\nlist_types OP_COMA type_var");list_typesPtr = crearNodo(",", list_typesPtr, type_varPtr); _cant_types++;};

while: WHILE condicion_prima DO bloque {whilePtr = crearNodo("WHILE", desapilar(&pilaPtr), desapilar(&pilaPtr));}ENDWHILE {printf("\nWHILE condicion DO bloque ENDWHILE");};

while_especial: WHILE ID {idPtr = crearHoja($2);} IN exp_while DO bloque { while_especialPtr = crearNodo("WHILE_ESP", exp_whilePtr, desapilar(&pilaPtr));} ENDWHILE {printf("\nWHILE ID IN list_exp DO bloque ENDWHILE");};
exp_while: OP_CORC list_exp CL_COR {printf("\nOP_CORC list_exp CL_CO"); exp_whilePtr = list_expPtr;};
list_exp: expresion {printf("\nLIST_EXP: ID"); list_expPtr = crearNodo("COND", crearNodo("==", idPtr, expresionPtr), NULL);} 
          | list_exp OP_COMA expresion {printf("\nLIST_EXP: list_exp OP_COMA ID"); list_expPtr = crearNodo("COND", crearNodo("==", idPtr, expresionPtr), list_expPtr);};

if: IF OP_PAR condicion_prima CL_PAR bloque {bloquePtr = desapilar(&pilaPtr); ifPtr = crearNodo("IF", desapilar(&pilaPtr), bloquePtr);} ENDIF {printf("\nIF OP_PAR condicion CL_PAR bloque ENDIF");} 
    | IF OP_PAR condicion_prima CL_PAR bloque ELSE bloque {ifCuerpoPtr = crearNodo("Cuerpo", desapilar(&pilaPtr), desapilar(&pilaPtr)); ifPtr = crearNodo("IF", desapilar(&pilaPtr), ifCuerpoPtr);} ENDIF {printf("\nIF OP_PAR condicion CL_PAR bloque ELSE bloque ENDIF");};

condicion_prima: condicion {printf("\ncondicion_prima"); condicion_primaPtr = condicionPtr; apilar(&pilaPtr, condicion_primaPtr);};
condicion: comparacion_simple {printf("\ncomparacion_simple"); condicionPtr = comparacion_simplePtr; } 
            | condicion_anidada {printf("\ncondicion_anidada"); condicionPtr = condicion_anidadaPtr; } 
            | NOT comparacion_simple {printf("\nNOT comparacion_simple"); condicionPtr = crearNodo("NOT", comparacion_simplePtr, NULL);};
condicion_anidada: condicion OP_AND comparacion_simple {printf("\ncondicion OP_AND comparacion_simple"); condicion_anidadaPtr = crearNodo("AND", condicionPtr, comparacion_simplePtr);} 
                  | condicion OP_OR comparacion_simple {printf("\ncondicion OP_OR comparacion_simple"); condicion_anidadaPtr = crearNodo("OR", condicionPtr, comparacion_simplePtr);};
comparacion_simple: expresion {expAuxPtr = expresionPtr;} op_comparacion expresion {printf("\nexpresion op_comparacion expresion"); comparacion_simplePtr = crearNodo2(op_comparacionPtr, expAuxPtr, expresionPtr);};

expresion: termino {printf("\ntermino"); expresionPtr = terminoPtr;} 
            | expresion OP_SUM termino {printf("\nexpresion OP_SUM termino"); expresionPtr = crearNodo("+", expresionPtr, terminoPtr);} 
            | expresion OP_MEN termino {printf("\nexpresion OP_MEN termino"); expresionPtr = crearNodo("-", expresionPtr, terminoPtr);};
termino: termino_par {printf("\ntermino_par"); terminoPtr = termino_parPtr;} 
          | termino OP_MULT termino_par {printf("\ntermino OP_MULT termino_par"); terminoPtr = crearNodo("*", terminoPtr, termino_parPtr);} 
          | termino OP_DIV termino_par {printf("\ntermino OP_DIV termino_par"); terminoPtr = crearNodo("/", terminoPtr, termino_parPtr);};
termino_par: asig_val {printf("\nasig_val"); termino_parPtr = asig_valPtr;} 
            | OP_PAR expresion CL_PAR {printf("\nOP_PAR expresion CL_PAR"); termino_parPtr = expresionPtr;};

inicializacion_for: FOR ID OP_ASIG asig_val { idIni = $2;  iniVar = crearNodo(":=", crearHoja($2), asig_valPtr); } TO asig_val { condicionFor = crearNodo("!=", crearHoja($2), asig_valPtr); };

for: inicializacion_for pasos_for { stepNodo = crearNodo(":=", crearHoja(idIni), crearNodo("+", crearHoja(idIni), pasos_forPtr)); cuerpo2 = crearNodo("CUERPO", condicionFor, stepNodo); ini = crearNodo("INI", iniVar, cuerpo2); } bloque NEXT ID 
    {printf("\nFOR ID OP_ASIG asig_val TO asig_val pasos_for bloque NEXT ID");  forPtr = crearNodo("FOR", ini, desapilar(&pilaPtr));} 
    | inicializacion_for bloque { stepNodo = crearNodo(":=", crearHoja(idIni), crearNodo("+", crearHoja(idIni), crearHoja("1"))); printf("\nInicializa stepNodo"); cuerpo2 = crearNodo("CUERPO", condicionFor, stepNodo); printf("\nInicializa cuerpo2"); ini = crearNodo("INI", iniVar, cuerpo2); printf("\nInicializa ini"); } NEXT ID {printf("\nFOR ID OP_ASIG asig_val TO asig_val bloque NEXT ID");  forPtr = crearNodo("FOR", ini, desapilar(&pilaPtr)); printf("\nInicializa forPtr");};
pasos_for: OP_CORC expresion CL_COR {printf("\nOP_CORC expresion CL_COR"); pasos_forPtr = expresionPtr; };

asig_val: ID {printf("\nID"); asig_valPtr = crearHoja($1);}
          | INT_NUM {printf("\nINT_NUM"); asig_valPtr = crearHoja($1);}
          | FLOAT_NUM {printf("\nFLOAT_NUM");asig_valPtr = crearHoja($1);}
          | STRING_DEC {printf("\nSTRING_DEC");asig_valPtr = crearHoja($1);};

asignacion: ID OP_ASIG expresion {printf("\nID OP_ASIG expresion");asignacionPtr = crearNodo(":=", crearHoja($1), expresionPtr);};

display: DISPLAY asig_val {printf("\nDISPLAY asig_val"); displayPtr = crearNodo("display", crearHoja("DISPLAY"), asig_valPtr);};
get_action: GET ID {printf("\nGET ID"); get_actionPtr = crearNodo("get_action", crearHoja("GET"), crearHoja($2));};

op_comparacion: OP_EQ {printf("\nOP_EQ"); op_comparacionPtr = crearHoja("==");} 
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
  crear(&pilaPtr);
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
  printf("Creando tabla de simbolos...\n");
  for(i = 0; i < getCantSimbolos(); i++){
    printf("Nombre simbolo: %s\n", simbolos[i].nombre);
    fprintf(pf, "%-20s%-20s%-20s%-20s%-20s\n", simbolos[i].nombre, simbolos[i].tipoDato, simbolos[i].valor, simbolos[i].longitud, simbolos[i].token);
  }
  fclose(pf);
}

/* YYPARSE() -> lleva adelante el proceso de analisis sintactico. Invoca a YYLEX() para solicitar un token y este le devuelve
Los valores de los tokens (lexemas) los guarda en la variable yylval.
YYPARSE() devuelve 0 cuando ya se analizo todo el archivo
si se detecta un error YYPARSE() devuelve 1. Con yyerrok reestablecemos el analizador al modo normal */