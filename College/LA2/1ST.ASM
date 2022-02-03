; Program to show use of interrupts
;14Write X86/64 ALP to perform 16 bit multiplication and
;32 bit multiplication using simulator.
;PRN:2020BTECS00090
;NAME:VISHAL CHAUHAN
MOV SI,3000H
MOV AX,[SI]
MOV BX,[SI+2]
MUL BX
MOV [SI+4],AX
MOV [SI+6],DX
HLT