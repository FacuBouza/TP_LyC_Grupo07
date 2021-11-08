.MODEL LARGE
.386
.STACK 200h

.DATA

a                   dd                  ?                   
b                   dq                  ?                   
beta                dt                  ?                   
string1             dt                  ?                   
c                   dq                  ?                   
_327                dd                  327                 
_ 10.55             dd                   10.55              
_"String de prueba" dd                  "String de prueba"  
_"String de prueba dos"dd                  "String de prueba dos"
_-89999.9999        dd                  -89999.9999         
_8                  dd                  8                   
_5                  dd                  5                   
_8888               dd                  8888                
_1                  dd                  1                   
_6                  dd                  6                   
_2                  dd                  2                   
_10                 dd                  10                  
_9                  dd                  9                   
_10000              dd                  10000               
@aux1               dd                  ?                   
@aux2               dd                  ?                   
@aux3               dd                  ?                   
@aux4               dd                  ?                   
@aux5               dd                  ?                   
@aux6               dd                  ?                   
@aux7               dd                  ?                   
@aux8               dd                  ?                   
@aux9               dd                  ?                   
@aux10              dd                  ?                   
@aux11              dd                  ?                   
@aux12              dd                  ?                   
@aux13              dd                  ?                   
@aux14              dd                  ?                   
@aux15              dd                  ?                   
@aux16              dd                  ?                   

.CODE

mov AX,@DATA
mov DS,AX
mov es,ax
fild 327
fstp a
fld  10.55
fstp b
fld "String de prueba"
fstp beta
fld "String de prueba dos"
fstp string1
fld -89999.9999
fstp c
while_esp1:
fild a
fcomp b
fstsw ax
sahf
JE start_while_esp1
fld b
fld c
FMUL
fstp @aux1
ffree
fild a
fild @aux1
FADD
fistp @aux2
ffree
fild a
fcomp @aux2
fstsw ax
sahf
JE start_while_esp1
fld b
fld 8
FADD
fstp @aux3
ffree
fild 5
fild 8
FMUL
fistp @aux4
ffree
fild @aux4
fild 8888
FMUL
fistp @aux5
ffree
fld @aux3
fld @aux5
FSUB
fstp @aux6
ffree
fild a
fcomp @aux6
fstsw ax
sahf
JE start_while_esp1
fild a
fild b
FADD
fistp @aux7
ffree
fild a
fcomp @aux7
fstsw ax
sahf
JE start_while_esp1
JMP endwhile_esp1:
start_while_esp1:
fld c
fld 1
FADD
fstp @aux8
ffree
fld @aux8
fstp c
JMP while_esp1
endwhile_esp1:
while1:
fild a
fcomp 5
fstsw ax
sahf
JAE start_while1
fld c
fcomp 5
fstsw ax
sahf
JBE end_while1
start_while1:
fild a
fild 1
FADD
fistp @aux9
ffree
fild @aux9
fstp a
JMP while1:
end_while1:
while2:
fild a
fcomp 5
fstsw ax
sahf
JB end_while2
fld c
fcomp 5
fstsw ax
sahf
JBE end_while2
start_while2:
fild a
fild 1
FADD
fistp @aux10
ffree
fild @aux10
fstp a
JMP while2:
end_while2:
fild 1
fstp a
for1:
fild a
fcomp 6
fstsw ax
sahf
JE end_for1
fild 1
fstp a
for2:
fild a
fcomp 6
fstsw ax
sahf
JE end_for2
fld b
fld c
FADD
fstp @aux11
ffree
fld @aux11
fstp b
fild a
fild 2
FADD
fistp @aux12
ffree
fild @aux12
fstp a
JMP for2:
end_for2:
fld c
fcomp 8
fstsw ax
sahf
JAE else_part1
then_part1:
fild 10
fstp c
jmp endif_part1:
else_part1:
fild 9
fstp c
endif_part1:
fild a
fild 1
FADD
fistp @aux13
ffree
fild @aux13
fstp a
JMP for1:
end_for1:
fld c
fld a
FMUL
fstp @aux14
ffree
fild 10000
fild 5
FMUL
fistp @aux15
ffree
fld @aux14
fld @aux15
FSUB
fstp @aux16
ffree
fld @aux16
fstp c
displayString beta
displayFloat a
mov ax,4c00h
Int 21h

End