
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


