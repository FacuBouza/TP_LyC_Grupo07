flex Lexico.l

bison -dyv Sintactico.y

gcc lex.yy.c y.tab.c Simbolos.c Arbol.c -o Primera.exe

Primera.exe Prueba2.txt