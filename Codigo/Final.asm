.MODEL LARGE
.386
.STACK 200h

.DATA

a                   dd                  ?                   
b                   dd                  ?                   
c                   dd                  ?                   
d                   dd                  ?                   
e                   dd                  ?                   
_8                  dd                  8                   
_7                  dd                  7                   
_8                  dd                  8                   
_5                  dd                  5                   
_8                  dd                  8                   
_7                  dd                  7                   
_8                  dd                  8                   
@aux1               dd                  ?                   
@aux2               dd                  ?                   
@aux3               dd                  ?                   

.CODE

mov AX,@DATA
mov DS,AX
mov es,ax
while_esp1:
fild z
fild h
FADD
fistp @aux1
ffree
fild b
fcomp @aux1
fstsw ax
sahf
JE start_while_esp2
JMP endwhile_esp1:
start_while_esp1:
fild b
fild 7
FADD
fistp @aux2
ffree
fild @aux2
fstp b
while_esp2:
JMP endwhile_esp2:
start_while_esp2:
fild c
fild 8
FSUB
fistp @aux3
ffree
fild @aux3
fstp c
JMP while_esp2
endwhile_esp2:
JMP while_esp1
endwhile_esp1:
mov ax,4c00h
Int 21h

End