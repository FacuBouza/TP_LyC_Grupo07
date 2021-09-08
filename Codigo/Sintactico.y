%{

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

list_var: ID | list_var OP_COMA ID; 
type_var: INT_TYPE | REAL_TYPE | STRING_TYPE;
asig_val: ID|INT_NUM|FLOAT_NUM|STRING_DEC;
list_types: type_var | list_types OP_COMA type_var;
declaracion: DIM OP_CORC list_var CL_COR AS OP_CORC list_types CL_COR;

asignacion: ID OP_ASIG asig_val;

display: DISPLAY asig_val;
get_action: GET ID;

expresion: asig_val | OPERACION DE SUMA | OPERACION DE RESTA | OPERACION MULT | OP DIV;
op_comparacion: OP_EQ | OP_GE | OP_GT | OP_LE | OP_LT | OP_DIST; 

comparacion:  expresion op_comparacion expresion;
condicion_anidada: comparacion OP_AND comparacion | comparacion OP_OR comparacion; 
condicion: comparacion | condicion_anidada | NOT expresion;
sentencia: seleccion ...}
seleccion: IF condicion sentencia ENDIF | IF condicion sentencia ELSE sentencia ENDIF;

%%
