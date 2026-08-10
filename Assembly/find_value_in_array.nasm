; search.asm - linear search for a value in an array
section .data
    array   dq  10, 25, 3, 47, 8, 99, 15    ; array of 8-byte (qword) values
    arr_len equ 7                            ; number of elements
    target  dq  47                           ; value we're looking for

section .text
    global _start

_start:
    xor     rcx, rcx           ; rcx = index i = 0
    lea     rsi, [array]       ; rsi = pointer to start of array
    mov     rdi, [target]      ; rdi = value we're searching for

search_loop:
    cmp     rcx, arr_len
    jge     not_found          ; if i >= arr_len, exit loop

    mov     rax, [rsi + rcx*8] ; rax = array[i]
    cmp     rax, rdi
    je      found              ; if array[i] == target, jump

    inc     rcx                ; i++
    jmp     search_loop

found:
    ; rcx now holds the index where target was found
    mov     rdi, rcx           ; exit code = index
    mov     rax, 60
    syscall

not_found:
    mov     rdi, -1            ; use -1 (255 as exit code) to signal "not found"
    mov     rax, 60
    syscall