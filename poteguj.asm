title The fun Subroutine    (fun2.asm)

; This subroutine links to Visual C++ 6.0.

.386P
.model flat
public _poteguj

.code
_poteguj proc near   
    ; zwraca liczbe podniesion¹ do n-tej potêgi gdzie n to argument wejsciowy
	push ebp
	mov ebp, esp
	mov eax, [ebp + 8]		; pierwszy argument - podstawa
	mov ecx, [ebp + 12]		; drugi argument - wykladnik
	cmp ecx, 0
	je potega_zero
	jl ujemna_potega
	cmp ecx, 1
	je koniec 
	mov edx, eax
	dec ecx
ptl:
	push edx
	mul edx
	pop edx
	loop ptl
	jmp koniec
ujemna_potega:
	mov eax, -32
	jmp koniec
potega_zero:
	mov eax, 1
koniec:
	pop ebp
	ret                   
_poteguj endp
end

