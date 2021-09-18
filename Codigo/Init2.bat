flex Lexico.l

bison -dyv Sintactico.y

gcc lex.yy.c y.tab.c Simbolos.c -o Primera.exe

Primera.exe testCode.txt

del Primera.exe
del y.tab.c
del y.tab.h
del lex.yy.c
del y.output