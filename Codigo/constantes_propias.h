#define CONSTANTES_PROPIAS_H

//Cotas
#define MAXLENID 16
#define MAXLENSTR 32
#define LIM_INT_POS 32767
#define LIM_INT_NEG -32767

// Errores
#define ARCHIVO_OK 5
#define ERROR -1

//Numero arbitrarios para tipos de datos
#define TOKEN_NULL 10
#define TOKEN_CTE_INTEGER 20
#define TOKEN_CTE_FLOAT 30
#define TOKEN_CTE_STRING 40
#define TOKEN_ID 50
#define VARIABLE_AUXILIAR 60

#define TIPO_ERROR 0
#define TIPO_INTEGER 1
#define TIPO_FLOAT 2
#define TIPO_STRING 3

static const int typeCompatibility [4][4] =
{	//ERROR			INT			FLOAT		STRING			
	{ TIPO_ERROR, 		TIPO_ERROR, 	TIPO_ERROR, 	TIPO_ERROR },
	{ TIPO_ERROR,		TIPO_INTEGER, 	TIPO_FLOAT, 	TIPO_ERROR },
	{ TIPO_ERROR,		TIPO_FLOAT, 	TIPO_FLOAT, 	TIPO_ERROR },
	{ TIPO_ERROR, 		TIPO_ERROR, 	TIPO_ERROR, 	TIPO_STRING }
};


#define LABEL_IF 70
#define LABEL_WHILE 80


#endif