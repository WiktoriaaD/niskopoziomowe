section .text
    global asm_min
    global asm_max

asm_min:
    cmp rsi, 0
    jz end    
    mov eax, [rdi] ;1
    mov rcx, 1 ;indeks 1
    jmp loop

loop:
    cmp rcx, rsi ; 2 ? dlugosc
    jge done 
    mov edx, [rdi + 4*rcx] ; edx = 3
    cmp eax, edx ; 1 ? 3
    jl less 
    mov eax, edx
    inc rcx
    jmp loop


less:
    inc rcx ; indeks 3
    jmp loop


end:
    mov eax, 0
    ret

done:
    ret
    

asm_max:
    cmp rsi, 0
    jz end    
    mov eax, [rdi] ;1
    mov rcx, 1 ;indeks 1
    jmp maxloop

maxloop:
    cmp rcx, rsi ; 2 ? dlugosc
    jge maxdone 
    mov edx, [rdi + 4*rcx] ; edx = 2
    cmp eax, edx ; 1 ? 2
    jg more 
    mov eax, edx
    inc rcx
    jmp maxloop


more:
    inc rcx ; indeks 3
    jmp maxloop


maxdone:
    ret
    

