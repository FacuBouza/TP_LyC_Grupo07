
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Sintactico.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <string.h>
  #include "Simbolos.h"
  #include "Pila.h"
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


/* Line 189 of yacc.c  */
#line 140 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OP_ASIG = 258,
     OP_GT = 259,
     OP_LT = 260,
     OP_GE = 261,
     OP_LE = 262,
     OP_EQ = 263,
     OP_SUM = 264,
     OP_MULT = 265,
     OP_MEN = 266,
     OP_DIV = 267,
     OP_OR = 268,
     OP_AND = 269,
     NOT = 270,
     OP_DIST = 271,
     OP_ENDLINE = 272,
     OP_COMA = 273,
     OP_PAR = 274,
     CL_PAR = 275,
     OP_KEY = 276,
     CL_KEY = 277,
     OP_CORC = 278,
     CL_COR = 279,
     WHILE = 280,
     IF = 281,
     ENDIF = 282,
     ELSE = 283,
     DIM = 284,
     AS = 285,
     IN = 286,
     DO = 287,
     ENDWHILE = 288,
     FOR = 289,
     TO = 290,
     NEXT = 291,
     INT_TYPE = 292,
     REAL_TYPE = 293,
     STRING_TYPE = 294,
     DIGITO = 295,
     CARACTER = 296,
     COMMENT = 297,
     STRING_DEC = 298,
     INT_NUM = 299,
     FLOAT_NUM = 300,
     DISPLAY = 301,
     GET = 302,
     ID = 303
   };
#endif
/* Tokens.  */
#define OP_ASIG 258
#define OP_GT 259
#define OP_LT 260
#define OP_GE 261
#define OP_LE 262
#define OP_EQ 263
#define OP_SUM 264
#define OP_MULT 265
#define OP_MEN 266
#define OP_DIV 267
#define OP_OR 268
#define OP_AND 269
#define NOT 270
#define OP_DIST 271
#define OP_ENDLINE 272
#define OP_COMA 273
#define OP_PAR 274
#define CL_PAR 275
#define OP_KEY 276
#define CL_KEY 277
#define OP_CORC 278
#define CL_COR 279
#define WHILE 280
#define IF 281
#define ENDIF 282
#define ELSE 283
#define DIM 284
#define AS 285
#define IN 286
#define DO 287
#define ENDWHILE 288
#define FOR 289
#define TO 290
#define NEXT 291
#define INT_TYPE 292
#define REAL_TYPE 293
#define STRING_TYPE 294
#define DIGITO 295
#define CARACTER 296
#define COMMENT 297
#define STRING_DEC 298
#define INT_NUM 299
#define FLOAT_NUM 300
#define DISPLAY 301
#define GET 302
#define ID 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 67 "Sintactico.y"

    int intval;
    float val;
    char *str_val;



/* Line 214 of yacc.c  */
#line 280 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 292 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   184

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    14,    16,    19,
      22,    25,    28,    31,    33,    35,    37,    39,    48,    50,
      54,    56,    58,    60,    62,    66,    67,    74,    75,    76,
      86,    90,    92,    96,    97,   105,   106,   116,   118,   120,
     122,   125,   129,   133,   134,   139,   141,   145,   149,   151,
     155,   159,   161,   165,   166,   174,   175,   182,   183,   189,
     193,   195,   197,   199,   201,   205,   208,   211,   213,   215,
     217,   219,   221
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,    52,    -1,    53,    -1,    52,
      53,    -1,    54,    -1,    55,    -1,    85,    17,    -1,    86,
      17,    -1,    56,    17,    -1,    75,    17,    -1,    87,    17,
      -1,    60,    -1,    62,    -1,    67,    -1,    80,    -1,    29,
      23,    57,    24,    30,    23,    59,    24,    -1,    48,    -1,
      57,    18,    48,    -1,    37,    -1,    38,    -1,    39,    -1,
      58,    -1,    59,    18,    58,    -1,    -1,    25,    70,    32,
      52,    61,    33,    -1,    -1,    -1,    25,    48,    63,    31,
      65,    32,    52,    64,    33,    -1,    23,    66,    24,    -1,
      75,    -1,    66,    18,    75,    -1,    -1,    26,    19,    70,
      20,    52,    68,    27,    -1,    -1,    26,    19,    70,    20,
      52,    28,    52,    69,    27,    -1,    71,    -1,    73,    -1,
      72,    -1,    15,    73,    -1,    71,    14,    73,    -1,    71,
      13,    73,    -1,    -1,    75,    74,    88,    75,    -1,    76,
      -1,    75,     9,    76,    -1,    75,    11,    76,    -1,    77,
      -1,    76,    10,    77,    -1,    76,    12,    77,    -1,    84,
      -1,    19,    75,    20,    -1,    -1,    34,    48,     3,    84,
      79,    35,    84,    -1,    -1,    78,    83,    81,    52,    36,
      48,    -1,    -1,    78,    52,    82,    36,    48,    -1,    23,
      75,    24,    -1,    48,    -1,    44,    -1,    45,    -1,    43,
      -1,    48,     3,    75,    -1,    46,    84,    -1,    47,    48,
      -1,     8,    -1,     6,    -1,     4,    -1,     7,    -1,     5,
      -1,    16,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   129,   129,   130,   131,   132,   135,   136,   138,   139,
     140,   141,   142,   144,   145,   146,   147,   149,   152,   153,
     154,   155,   156,   157,   158,   160,   160,   162,   162,   162,
     163,   164,   165,   167,   167,   168,   168,   170,   171,   172,
     173,   174,   175,   176,   176,   178,   179,   180,   181,   182,
     183,   184,   185,   187,   187,   189,   189,   191,   191,   192,
     194,   195,   196,   197,   199,   201,   202,   204,   205,   206,
     207,   208,   209
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OP_ASIG", "OP_GT", "OP_LT", "OP_GE",
  "OP_LE", "OP_EQ", "OP_SUM", "OP_MULT", "OP_MEN", "OP_DIV", "OP_OR",
  "OP_AND", "NOT", "OP_DIST", "OP_ENDLINE", "OP_COMA", "OP_PAR", "CL_PAR",
  "OP_KEY", "CL_KEY", "OP_CORC", "CL_COR", "WHILE", "IF", "ENDIF", "ELSE",
  "DIM", "AS", "IN", "DO", "ENDWHILE", "FOR", "TO", "NEXT", "INT_TYPE",
  "REAL_TYPE", "STRING_TYPE", "DIGITO", "CARACTER", "COMMENT",
  "STRING_DEC", "INT_NUM", "FLOAT_NUM", "DISPLAY", "GET", "ID", "$accept",
  "programa", "main", "bloque", "sentencia", "sentencia_simple",
  "sentencia_compuesta", "declaracion_var", "list_var", "type_var",
  "list_types", "while", "$@1", "while_especial", "$@2", "$@3",
  "exp_while", "list_exp", "if", "$@4", "$@5", "condicion_prima",
  "condicion", "condicion_anidada", "comparacion_simple", "$@6",
  "expresion", "termino", "termino_par", "inicializacion_for", "$@7",
  "for", "$@8", "$@9", "pasos_for", "asig_val", "asignacion", "display",
  "get_action", "op_comparacion", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    52,    52,    53,    53,    54,    54,
      54,    54,    54,    55,    55,    55,    55,    56,    57,    57,
      58,    58,    58,    59,    59,    61,    60,    63,    64,    62,
      65,    66,    66,    68,    67,    69,    67,    70,    71,    71,
      71,    72,    72,    74,    73,    75,    75,    75,    76,    76,
      76,    77,    77,    79,    78,    81,    80,    82,    80,    83,
      84,    84,    84,    84,    85,    86,    87,    88,    88,    88,
      88,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     8,     1,     3,
       1,     1,     1,     1,     3,     0,     6,     0,     0,     9,
       3,     1,     3,     0,     7,     0,     9,     1,     1,     1,
       2,     3,     3,     0,     4,     1,     3,     3,     1,     3,
       3,     1,     3,     0,     7,     0,     6,     0,     5,     3,
       1,     1,     1,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    63,    61,    62,     0,
       0,    60,     0,     2,     3,     4,     6,     7,     0,    13,
      14,    15,     0,    45,    48,     0,    16,    51,     0,     0,
       0,    60,     0,     0,    60,     0,    37,    39,    38,    43,
       0,     0,     0,    65,    66,     0,     1,     5,    10,     0,
       0,    11,     0,     0,     0,    57,    55,     8,     9,    12,
      52,    40,     0,     0,     0,     0,     0,     0,    18,     0,
       0,    64,    46,    47,    49,    50,     0,     0,     0,     0,
      25,    42,    41,    69,    71,    68,    70,    67,    72,     0,
       0,     0,     0,    53,    59,     0,     0,     0,     0,     0,
      44,    33,    19,     0,     0,    58,     0,     0,    31,     0,
      26,     0,     0,     0,     0,    56,     0,    30,    28,    35,
      34,    20,    21,    22,    23,     0,    54,    32,     0,     0,
       0,    17,    29,    36,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,    18,    69,   124,
     125,    19,    99,    20,    62,   128,    98,   107,    21,   112,
     129,    35,    36,    37,    38,    66,    22,    23,    24,    25,
     104,    26,    78,    77,    56,    27,    28,    29,    30,    89
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -24
static const yytype_int16 yypact[] =
{
     136,    42,   -10,   -16,    -7,    -8,   -24,   -24,   -24,    26,
       9,    47,    36,   -24,   136,   -24,   -24,   -24,    37,   -24,
     -24,   -24,    20,    15,   -24,    33,   -24,   -24,    49,    75,
      77,   -24,     8,    42,    80,    68,    69,   -24,   -24,    64,
       3,    70,   105,   -24,   -24,    42,   -24,   -24,   -24,    42,
      42,   -24,    42,    42,    42,   136,   -24,   -24,   -24,   -24,
     -24,   -24,    85,   136,    42,    42,     7,    97,   -24,     2,
      26,    64,    15,    15,   -24,   -24,    -3,    90,   136,   104,
     136,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,    42,
     136,    81,    98,   -24,   -24,    82,    76,    42,   101,   103,
      64,   106,   -24,   114,   107,   -24,    91,     6,    64,   136,
     -24,   136,   111,    60,    26,   -24,    42,   -24,   136,   136,
     -24,   -24,   -24,   -24,   -24,    31,   -24,    64,   108,   116,
      60,   -24,   -24,   -24,   -24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -24,   -24,   -24,   -18,   -12,   -24,   -24,   -24,   -24,    14,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   117,   -24,   -24,   -23,   -24,    -1,    54,    61,   -24,
     -24,   -24,   -24,   -24,   -24,    -5,   -24,   -24,   -24,   -24
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -28
static const yytype_int16 yytable[] =
{
      32,    39,    47,    40,    43,    33,    49,    55,    50,     1,
      61,    83,    84,    85,    86,    87,    41,    49,    33,    50,
      91,    94,     1,    88,   116,    52,    92,    53,    60,    49,
     117,    50,    39,     6,     7,     8,    46,    51,    34,    39,
      42,    81,    82,    47,    71,    80,     6,     7,     8,   130,
      45,    31,     1,    76,    48,   131,    54,    44,     2,     3,
      96,     1,     4,    39,    39,    93,    57,     5,    47,     6,
       7,     8,   101,    49,    31,    50,     6,     7,     8,     9,
      10,    11,    64,    65,    47,     6,     7,     8,   100,    47,
      31,   118,    58,   119,    59,     1,   108,   121,   122,   123,
      63,     2,     3,    72,    73,     4,    47,    47,    70,   126,
       5,   -27,   106,    74,    75,   127,    79,    90,    68,     6,
       7,     8,     9,    10,    11,     1,    95,    97,   103,   102,
     105,     2,     3,   109,   111,     4,   110,   113,   120,   115,
       5,   132,   114,   133,   134,     0,     0,     0,     0,     6,
       7,     8,     9,    10,    11,     1,     0,    67,     0,     0,
       0,     2,     3,     0,     0,     4,     0,     0,     0,     0,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     8,     9,    10,    11
};

static const yytype_int16 yycheck[] =
{
       1,     2,    14,    19,     9,    15,     9,    25,    11,    19,
      33,     4,     5,     6,     7,     8,    23,     9,    15,    11,
      18,    24,    19,    16,    18,    10,    24,    12,    20,     9,
      24,    11,    33,    43,    44,    45,     0,    17,    48,    40,
      48,    64,    65,    55,    45,    63,    43,    44,    45,    18,
       3,    48,    19,    54,    17,    24,    23,    48,    25,    26,
      78,    19,    29,    64,    65,    70,    17,    34,    80,    43,
      44,    45,    90,     9,    48,    11,    43,    44,    45,    46,
      47,    48,    13,    14,    96,    43,    44,    45,    89,   101,
      48,   109,    17,   111,    17,    19,    97,    37,    38,    39,
      32,    25,    26,    49,    50,    29,   118,   119,     3,   114,
      34,    31,    36,    52,    53,   116,    31,    20,    48,    43,
      44,    45,    46,    47,    48,    19,    36,    23,    30,    48,
      48,    25,    26,    32,    28,    29,    33,    23,    27,    48,
      34,    33,    35,    27,   130,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    19,    -1,    40,    -1,    -1,
      -1,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    25,    26,    29,    34,    43,    44,    45,    46,
      47,    48,    50,    51,    52,    53,    54,    55,    56,    60,
      62,    67,    75,    76,    77,    78,    80,    84,    85,    86,
      87,    48,    75,    15,    48,    70,    71,    72,    73,    75,
      19,    23,    48,    84,    48,     3,     0,    53,    17,     9,
      11,    17,    10,    12,    23,    52,    83,    17,    17,    17,
      20,    73,    63,    32,    13,    14,    74,    70,    48,    57,
       3,    75,    76,    76,    77,    77,    75,    82,    81,    31,
      52,    73,    73,     4,     5,     6,     7,     8,    16,    88,
      20,    18,    24,    84,    24,    36,    52,    23,    65,    61,
      75,    52,    48,    30,    79,    48,    36,    66,    75,    32,
      33,    28,    68,    23,    35,    48,    18,    24,    52,    52,
      27,    37,    38,    39,    58,    59,    84,    75,    64,    69,
      18,    24,    33,    27,    58
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 129 "Sintactico.y"
    {printf("\nmain"); programaPtr = mainPtr; escribirGragh(programaPtr);}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 130 "Sintactico.y"
    {printf("\nbloque"); mainPtr = bloquePtr;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 131 "Sintactico.y"
    {printf("\nsentencia"); bloquePtr = sentenciaPtr; apilar(&pilaPtr, bloquePtr); printf("\nLo que vos quieras");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 132 "Sintactico.y"
    {printf("\nbloque sentencia"); bloquePtr = crearNodo("bloque", desapilar(&pilaPtr), sentenciaPtr); apilar(&pilaPtr, bloquePtr); printf("\nGenera bloque");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 135 "Sintactico.y"
    { sentenciaPtr = sentenciaSimpleptr; }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 136 "Sintactico.y"
    { sentenciaPtr = sentenciaCompuestaptr; }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 138 "Sintactico.y"
    {printf("\nasginacion"); sentenciaSimpleptr = asignacionPtr;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 139 "Sintactico.y"
    {printf("\ndeclaracion_var");sentenciaSimpleptr = displayPtr;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 140 "Sintactico.y"
    {printf("\ndeclaracion_var");sentenciaSimpleptr = declaracion_varPtr;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 141 "Sintactico.y"
    {printf("\ndeclaracion_var");sentenciaSimpleptr = expresionPtr;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 142 "Sintactico.y"
    {printf("\ndeclaracion_var");sentenciaSimpleptr = get_actionPtr;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 144 "Sintactico.y"
    {printf("\nwhile:"); sentenciaCompuestaptr = whilePtr;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 145 "Sintactico.y"
    {printf("\nwhile_especial:"); sentenciaCompuestaptr = while_especialPtr;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 146 "Sintactico.y"
    {printf("\nif:"); sentenciaCompuestaptr = ifPtr;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 147 "Sintactico.y"
    {printf("\nfor"); sentenciaCompuestaptr = forPtr;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 149 "Sintactico.y"
    {printf("\nDIM OP_CORC list_var CL_COR AS OP_CORC list_types CL_COR "); declaracion_varPtr = crearNodo("DEC_VAR", list_varPtr, list_typesPtr); 
if(_cant_types != _cant_var) return 1; _cant_types = _cant_var = 0;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 152 "Sintactico.y"
    {printf("\nID"); list_varPtr = crearHoja((yyvsp[(1) - (1)].str_val)); _cant_var = 1;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 153 "Sintactico.y"
    {printf("\nlist_var OP_COMA ID "); list_varPtr = crearNodo(",", list_varPtr, crearHoja((yyvsp[(3) - (3)].str_val))); _cant_var++;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 154 "Sintactico.y"
    {printf("\nINT_TYPE:");type_varPtr = crearHoja("INT_TYPE");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 155 "Sintactico.y"
    {printf("\nREAL_TYPE");type_varPtr = crearHoja("REAL_TYPE");}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 156 "Sintactico.y"
    {printf("\nSTRING_TYPE");type_varPtr = crearHoja("STRING_TYPE");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 157 "Sintactico.y"
    {printf("\ntype_var");list_typesPtr = type_varPtr; _cant_types = 1; }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 158 "Sintactico.y"
    {printf("\nlist_types OP_COMA type_var");crearNodo(",", list_typesPtr, type_varPtr); _cant_types++;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 160 "Sintactico.y"
    {whilePtr = crearNodo("WHILE", desapilar(&pilaPtr), desapilar(&pilaPtr));}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 160 "Sintactico.y"
    {printf("\nWHILE condicion DO bloque ENDWHILE");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 162 "Sintactico.y"
    {idPtr = crearHoja((yyvsp[(2) - (2)].str_val));}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 162 "Sintactico.y"
    { while_especialPtr = crearNodo("WHILE_ESP", exp_whilePtr, desapilar(&pilaPtr));}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 162 "Sintactico.y"
    {printf("\nWHILE ID IN list_exp DO bloque ENDWHILE");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 163 "Sintactico.y"
    {printf("\nOP_CORC list_exp CL_CO"); exp_whilePtr = list_expPtr;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 164 "Sintactico.y"
    {printf("\nLIST_EXP: ID"); list_expPtr = crearNodo("COND", crearNodo("==", idPtr, expresionPtr), NULL);}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 165 "Sintactico.y"
    {printf("\nLIST_EXP: list_exp OP_COMA ID"); list_expPtr = crearNodo("COND", crearNodo("==", idPtr, expresionPtr), list_expPtr);}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 167 "Sintactico.y"
    {bloquePtr = desapilar(&pilaPtr); ifPtr = crearNodo("IF", desapilar(&pilaPtr), bloquePtr);}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 167 "Sintactico.y"
    {printf("\nIF OP_PAR condicion CL_PAR bloque ENDIF");}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 168 "Sintactico.y"
    {ifCuerpoPtr = crearNodo("Cuerpo", desapilar(&pilaPtr), bloquePtr); ifPtr = crearNodo("IF", desapilar(&pilaPtr), ifCuerpoPtr);}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 168 "Sintactico.y"
    {printf("\nIF OP_PAR condicion CL_PAR bloque ELSE bloque ENDIF");}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 170 "Sintactico.y"
    {printf("\ncondicion_prima"); condicion_primaPtr = condicionPtr; apilar(&pilaPtr, condicion_primaPtr);}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 171 "Sintactico.y"
    {printf("\ncomparacion_simple"); condicionPtr = comparacion_simplePtr; }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 172 "Sintactico.y"
    {printf("\ncondicion_anidada"); condicionPtr = condicion_anidadaPtr; }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 173 "Sintactico.y"
    {printf("\nNOT comparacion_simple"); condicionPtr = crearNodo("NOT", comparacion_simplePtr, NULL);}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 174 "Sintactico.y"
    {printf("\ncondicion OP_AND comparacion_simple"); condicion_anidadaPtr = crearNodo("AND", condicionPtr, comparacion_simplePtr);}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 175 "Sintactico.y"
    {printf("\ncondicion OP_OR comparacion_simple"); condicion_anidadaPtr = crearNodo("OR", condicionPtr, comparacion_simplePtr);}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 176 "Sintactico.y"
    {expAuxPtr = expresionPtr;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 176 "Sintactico.y"
    {printf("\nexpresion op_comparacion expresion"); comparacion_simplePtr = crearNodo2(op_comparacionPtr, expAuxPtr, expresionPtr);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 178 "Sintactico.y"
    {printf("\ntermino"); expresionPtr = terminoPtr;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 179 "Sintactico.y"
    {printf("\nexpresion OP_SUM termino"); expresionPtr = crearNodo("+", expresionPtr, terminoPtr);}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 180 "Sintactico.y"
    {printf("\nexpresion OP_MEN termino"); expresionPtr = crearNodo("-", expresionPtr, terminoPtr);}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 181 "Sintactico.y"
    {printf("\ntermino_par"); terminoPtr = termino_parPtr;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 182 "Sintactico.y"
    {printf("\ntermino OP_MULT termino_par"); terminoPtr = crearNodo("*", terminoPtr, termino_parPtr);}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 183 "Sintactico.y"
    {printf("\ntermino OP_DIV termino_par"); terminoPtr = crearNodo("/", terminoPtr, termino_parPtr);}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 184 "Sintactico.y"
    {printf("\nasig_val"); termino_parPtr = asig_valPtr;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 185 "Sintactico.y"
    {printf("\nOP_PAR expresion CL_PAR"); termino_parPtr = expresionPtr;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 187 "Sintactico.y"
    { idIni = (yyvsp[(2) - (4)].str_val);  iniVar = crearNodo(":=", crearHoja((yyvsp[(2) - (4)].str_val)), asig_valPtr); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 187 "Sintactico.y"
    { condicionFor = crearNodo("!=", crearHoja((yyvsp[(2) - (7)].str_val)), asig_valPtr); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 189 "Sintactico.y"
    { stepNodo = crearNodo(":=", crearHoja(idIni), crearNodo("+", crearHoja(idIni), pasos_forPtr)); cuerpo2 = crearNodo("CUERPO", condicionFor, stepNodo); ini = crearNodo("INI", iniVar, cuerpo2); }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 190 "Sintactico.y"
    {printf("\nFOR ID OP_ASIG asig_val TO asig_val pasos_for bloque NEXT ID");  forPtr = crearNodo("FOR", ini, desapilar(&pilaPtr));}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 191 "Sintactico.y"
    { stepNodo = crearNodo(":=", crearHoja(idIni), crearNodo("+", crearHoja(idIni), crearHoja("1"))); printf("\nInicializa stepNodo"); cuerpo2 = crearNodo("CUERPO", condicionFor, stepNodo); printf("\nInicializa cuerpo2"); ini = crearNodo("INI", iniVar, cuerpo2); printf("\nInicializa ini"); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 191 "Sintactico.y"
    {printf("\nFOR ID OP_ASIG asig_val TO asig_val bloque NEXT ID");  forPtr = crearNodo("FOR", ini, desapilar(&pilaPtr)); printf("\nInicializa forPtr");}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 192 "Sintactico.y"
    {printf("\nOP_CORC expresion CL_COR"); pasos_forPtr = expresionPtr; }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 194 "Sintactico.y"
    {printf("\nID"); asig_valPtr = crearHoja((yyvsp[(1) - (1)].str_val));}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 195 "Sintactico.y"
    {printf("\nINT_NUM"); asig_valPtr = crearHoja((yyvsp[(1) - (1)].str_val));}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 196 "Sintactico.y"
    {printf("\nFLOAT_NUM");asig_valPtr = crearHoja((yyvsp[(1) - (1)].str_val));}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 197 "Sintactico.y"
    {printf("\nSTRING_DEC");asig_valPtr = crearHoja((yyvsp[(1) - (1)].str_val));}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 199 "Sintactico.y"
    {printf("\nID OP_ASIG expresion");asignacionPtr = crearNodo(":=", crearHoja((yyvsp[(1) - (3)].str_val)), expresionPtr);}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 201 "Sintactico.y"
    {printf("\nDISPLAY asig_val");crearNodo("display", crearHoja("DISPLAY"), asig_valPtr);}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 202 "Sintactico.y"
    {printf("\nGET ID"); get_actionPtr = crearNodo("get_action", crearHoja("GET"), crearHoja((yyvsp[(2) - (2)].str_val)));}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 204 "Sintactico.y"
    {printf("\nOP_EQ"); op_comparacionPtr = crearHoja("==");}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 205 "Sintactico.y"
    {printf("\nOP_GE"); op_comparacionPtr = crearHoja(">=");}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 206 "Sintactico.y"
    {printf("\nOP_GT"); op_comparacionPtr = crearHoja(">");}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 207 "Sintactico.y"
    {printf("\nOP_LE"); op_comparacionPtr = crearHoja("<=");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 208 "Sintactico.y"
    {printf("\nOP_LT"); op_comparacionPtr = crearHoja("<");}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 209 "Sintactico.y"
    {printf("\nOP_DIST"); op_comparacionPtr = crearHoja("!=");}
    break;



/* Line 1455 of yacc.c  */
#line 2120 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 211 "Sintactico.y"


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
