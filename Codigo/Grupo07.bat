flex Lexico.l

bison -dyv Sintactico.y

gcc lex.yy.c y.tab.c Simbolos.c Arbol.c Pila.c Assembler.c -o Grupo07.exe

Grupo07.exe Prueba.txt

dot -Tpng gragh.dot -o intermedia.png

del lex.yy.c
del y.tab.c
del y.output
del y.tab.h
del gragh.dot