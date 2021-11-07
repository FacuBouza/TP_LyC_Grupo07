.MODEL LARGE
.386
.STACK 200h

.DATA

a                   dd                  ?                   
b                   dq                  ?                   
c                   dt                  ?                   
d                   dq                  ?                   
e                   dd                  ?                   
f                   dd                  ?                   
_1                  dd                  1                   
_9                  dd                  9                   
_2                  dd                  2                   
_10                 dd                  10                  
_8                  dd                  8                   
@aux1               dd                  ?                   
@aux2               dd                  ?                   

.CODE

mov AX,@DATA
mov DS,AX
mov es,ax
fild 1
fstp a
for1:
fild a
fcomp 9
fstsw ax
sahf
JE end_for1
fild 2
fstp b
for2:
fld b
fcomp 10
fstsw ax
sahf
JE end_for2
fild 8
fstp d
fld b
fld 1
FADD
fstp @aux1
ffree
fld @aux1
fstp b
JMP for2:
end_for2:
fild a
fild 1
FADD
fistp @aux2
ffree
fild @aux2
fstp a
JMP for1:
end_for1:
mov ax,4c00h
Int 21h

End