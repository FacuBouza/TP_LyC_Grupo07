flex Lexico.l

bison -dyv Sintactico.y

gcc lex.yy.c y.tab.c Simbolos.c Arbol.c -o Segunda.exe

Segunda.exe Prueba.txt