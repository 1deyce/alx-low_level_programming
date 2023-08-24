section .data
    format db "Hello, Holberton", 0
    fmt db "%s", 0

section .text
    extern printf

global main

main:
    ; Prepare arguments for printf
    mov edi, fmt
    mov rsi, format

    ; Call printf
    xor eax, eax
    call printf

    ; Exit the program
    xor eax, eax
    ret
