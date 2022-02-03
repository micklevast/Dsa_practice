MOV CL,00H ;for to count number of positive number
MOV BL,00H ;for to count number of negative number
MOV DL,09H ;set size  of array as 9
LEA SI,[2000H] ;start array from 2000H memory loaction
LOOP1:MOV AL, [SI]
SHL AL,01 ;left shifting in AL
JNC JUMP1 ;Jump only if carry flaf is not Set
INC BL
JMP JUMP2
JUMP1:INC CL
JUMP2:INC SI ;access next value from next memory location
DEC DL
JNZ LOOP1
MOV [2070H],CL ;store positive number as 2070H memory location
MOV [2072H],BL ;store negative number as 2072H memory location
HLT