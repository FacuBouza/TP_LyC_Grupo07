.MODEL LARGE
.386
.STACK 200h

.DATA

a                   dd                  ?                   
b                   dd                  ?                   
c                   dd                  ?                   
_3                  dd                  3                   
_8                  dd                  8                   
_8                  dd                  8                   
_8                  dd                  8                   
_8                  dd                  8                   
_10                 dd                  10                  
_20                 dd                  20                  
_9                  dd                  9                   
_8                  dd                  8                   

.CODE

mov AX,@DATA
mov DS,AX
mov es,ax

,                   
c                   
,                   
,                   
INT_TYPE            
,                   
DEC_VAR             
:=                  
bloque              
:=                  
bloque              
*                   
a                   
+                   
c                   
:=                  
bloque              
*                   
a                   
+                   
c                   
>                   
:=                  
>                   
:=                  
:=                  
Cuerpo              
IF                  
bloque              
IF                  
bloque              mov ax,4c00h
Int 21h

End