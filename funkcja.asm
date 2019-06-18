title The fun Subroutine    (fun2.asm)

; This subroutine links to Visual C++ 6.0.

.386P
.model flat
public _funkcja

.code
_funkcja proc near   
    ; zwraca liczbe podniesion¹ do n-tej potêgi gdzie n to argument wejsciowy
	push ebp
	mov ebp, esp
	mov esi, dword PTR[ebp + 8]		; pierwszy argument - podstawa

poczatek:
	mov al, [esi]
	cmp al, 0
	je koniec
	cmp al, '0'
	jl nastepny
	cmp al, '9'
	jle liczba
	cmp al, 'A'
	jl nastepny
	cmp al, 'Z'
	jle duza
	cmp al, 'a'
	jl nastepny
	cmp al, 'z'
	jle mala
	jmp nastepny
liczba:
	mov al, 'x'
	mov [esi], al
	jmp nastepny
duza:
	add al, 32
	mov [esi], al
	jmp nastepny
mala:
	sub al, 32
	mov [esi], al
	jmp nastepny
nastepny:
	inc esi
	jmp poczatek
koniec:
	pop ebp
	ret                   
_funkcja endp
end

