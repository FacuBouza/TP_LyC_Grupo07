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
_20                 dd                  20                  
_9                  dd                  9                   
_8                  dd                  8                   
_20                 dd                  20                  

.CODE

mov AX,@DATA
mov DS,AX
mov es,ax

a                   
b                   
,                   
c                   
,                   
d                   
,                   
e                   
,                   
INT_TYPE            
INT_TYPE            
,                   
INT_TYPE            
,                   
INT_TYPE            
,                   
INT_TYPE            
,                   
DEC_VAR             
c                   
a                   
8                   
8                   
MOV R1, 8
MUL R1, 8
MOV @aux1, R1
@aux1               
MOV R1, a
ADD R1, @aux1
MOV @aux2, R1
@aux2               
>                   
c                   
10                  
MOV R1, 10
MOV c, R1
:=                  
b                   
20                  
>                   
d                   
9                   
MOV R1, 9
MOV d, R1
:=                  
e                   
8                   
MOV R1, 8
MOV e, R1
:=                  
Cuerpo              
IF                  
bloque              
c                   
20                  
MOV R1, 20
MOV c, R1
:=                  
Cuerpo              
IF                  
bloque              mov ax,4c00h
Int 21h

End