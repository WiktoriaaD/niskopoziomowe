section .text
    global asmpow

asmpow:
    mov rax, 1
    cmp rsi, 0
    jz zerojump
    cmp rsi, 1
    je onejump
    jmp multiply

multiply:
    imul rax, rdi 
    sub rsi,1
    cmp rsi, 0
    jz end
    jmp multiply


zerojump:
    ret

onejump:
    mov rax,rdi
    ret

end:
    ret