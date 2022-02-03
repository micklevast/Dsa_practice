include 'C:\EMU8086\inc\emu8086.inc'

.satck 100h
.model small

.data   ;section for to store variable



.code  ;main code section  
    main proc
         
        ;these data will sore in al register
        print 'Enter first Number:' 
        
        mov ah,01h
        int 21h  ;by these we print user's data to screen
        
        mov bl,al
        sub bl,48 ;since the value enter by user is in asscii(char) form
        
        mov dl,10
        mov ah,02h
        int 21h ;for to go in new line
        
        mov dl,13
        mov ah,02h
        int 21h ;for to go in new line
        
        print 'Enter second Number:'
        
        mov ah,01h
        int 21h ;by these we print user's data to screen
        sub al,48 ;change char to number in asscii form
       
        mul bl  ;al=al*bl
        mov bl,al
        add bl,48 ;to change in asscii value again for output
        
        ;print new line
        mov dl,10
        mov ah,02h
        int 21h ;for to go in new line
        
        mov dl,13
        mov ah,02h
        int 21h ;for to go in new line 
        ;print new line done
        
        print 'Product:'
        mov dl,bl ;since to print we have to move data in dl
        mov ah,02h
        int 21h  ;data printed
        
        
        
    main endp
    
    
end main