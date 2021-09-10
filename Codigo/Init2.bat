flex Lexico.l

bison -dyv Sintactico.y

gcc lex.yy.c y.tab.c -o programa.exe

programa.exe testCode.txt