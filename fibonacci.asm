title The fun Subroutine    (fun2.asm)

; This subroutine links to Visual C++ 6.0.

.386P
.model flat
public _fibonacci

.code
_fibonacci proc near   
    ; zwraca n-ty wyraz ciagu fibonacciego, gdzie n to argument wejsciowy funkcji
	push ebp
	mov ebp, esp
	mov ecx, [ebp+8]
	mov edx, 1h				; pierwszy wyraz poprzedni
	mov ebx, 1h				; drugi wyraz poprzedni
	cmp ecx, 1h
	je jeden				; dla n = 1, wyraz ciagu - 1
	cmp ecx, 2h
	je jeden				; dla n = 2, wyraz ciagu - 1
	sub ecx, 2h
licz:
	mov eax, edx			; do akumulatora fibonacci(n-1)
	add eax, ebx			; sumowanie fibonacci(n-1)+fibonacci(n-2)
	mov ebx, edx
	mov edx, eax
	loop licz
	jmp koniec
jeden:
	mov eax, 1h
koniec:
    pop ebp
	ret                   
_fibonacci endp
end

