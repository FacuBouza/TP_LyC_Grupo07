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
_8                  dd                  8                   
_10                 dd                  10                  
_3                  dd                  3                   
_30                 dd                  30                  
_40                 dd                  40                  
_20                 dd                  20                  
@aux1               dd                  ?                   
@aux2               dd                  ?                   

.CODE

mov AX,@DATA
mov DS,AX
mov es,ax
fild 8
fild 8
FMUL
fistp @aux1
ffree
fild a
fild @aux1
FADD
fistp @aux2
ffree
fild c
fcomp @aux2
fstsw ax
sahf
JBE else_part1
then_part:
fild 10
fstp c
fild b
fcomp 3
fstsw ax
sahf
JBE else_part2
then_part:
fild 30
fstp d
jmp end_if2:
else_part2:
fild 40
fstp e
end_if2:
jmp end_if2:
else_part1:
fild 20
fstp c
end_if1:
mov ax,4c00h
Int 21h

End