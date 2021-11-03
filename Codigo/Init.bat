flex Lexico.l

bison -dyv Sintactico.y

gcc lex.yy.c y.tab.c Simbolos.c Arbol.c Pila.c Assembler.c -o Segunda.exe

Segunda.exe Prueba3.txt

dot -Tpng gragh.dot -o intermedia.png