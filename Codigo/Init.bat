flex Lexico.l

bison -dyv Sintactico.y

gcc lex.yy.c y.tab.c Simbolos.c Arbol.c Pila.c -o Segunda.exe

Segunda.exe Prueba.txt

"C:\Program Files\Graphviz\bin\dot" -Tpng gragh.dot -o intermedia.png