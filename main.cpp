// Addem Main Program      (AddMain.cpp) 

#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

extern "C" int poteguj(int a, int b);
extern "C" int fibonacci(int n);
extern "C" void funkcja(char *strx);

int main()
{
	const int tabLength = 20;
	int a = 2;
	int b = 30;
	int n = 13;
	int x = poteguj(a, b);
	srand(time(NULL));
	int tablica[tabLength];
	int bufor[tabLength];
	printf("######################################################################################\n");
	printf("#Witaj w przykladowym programie demonstrujacym laczenie kodu C z jezykiem assemblera!#\n");
	printf("######################################################################################\n\n");
	for (int i = 0; i < tabLength; i++)
	{
		tablica[i] = 1 + (rand() % 100);
		bufor[i] = 0;
	}
	printf("----------Dzialanie assemblerowej funkcji potegowanie.asm----------\n");
	printf("%d do potegi %d wynosi %d\n", a, b, x);
	printf("\n----------Dzialanie assemblerowej funkcji fibonacci.asm----------\n");
	printf("Wartosc ciagu fibonacciego dla n = %d wynosi %d\n", n, fibonacci(n));
	printf("\n----------Dzialanie kodu assemblerowego liczacego sume kumulowana elementow tablicy----------\n");
	__asm { // liczy sume kumulowan¹ elementów w tablicy
		push esi
		push edi
		push ecx
		push eax
		push edx
		lea esi, tablica
		lea edi, bufor
		mov ecx, tabLength
		; pierwszy element bez zmiany
		dec ecx
		mov eax, [esi]
		mov[edi], eax
		add esi, 4
		add edi, 4
	ptl:
		mov edx, eax
		mov eax, [esi]
		add eax, edx
		mov[edi], eax
		add esi, 4
		add edi, 4
		loop ptl
		pop edx
		pop eax
		pop ecx
		pop edi
		pop esi
	}
	printf("Tablica wejsciowa : \n");
	for (int i = 0; i < tabLength; i++)
	{
		printf("%6.0d", tablica[i]);
	}
	printf("\nTablica wyjsciowa : \n");
	for (int i = 0; i < tabLength; i++)
	{
		printf("%6.0d", bufor[i]);
	}
	printf("\n");
	int c, d, e;
	c = 2;
	d = 3;
	e = 6;
	bool trojkat = true;
	printf("\n----------Dzialanie kodu assemblerowego sprawdzajacego czy mozna z podanych bokow mozna zbudowac trojkat----------\n");
	__asm { // sprawdza czy mozna stworzyc z podanych bokow trojkat
			mov eax, c
			mov ebx, d
			mov edx, e
			push eax
			add eax, ebx
			cmp eax, edx
			jl niemozna
			pop eax
			push ebx
			add ebx, edx
			cmp ebx, eax 
			jl niemozna
			pop ebx
			add eax, edx
			cmp eax, ebx
			jl niemozna
			jmp mozna
		niemozna:
			mov trojkat, 0
		mozna:
	}
	if (trojkat) printf("Mozna zbudowac trojkat z bokow o dlugosciach %d, %d, %d.\n", c, d, e);
	else printf("Nie mozna zbudowac trojkata z bokow o dlugosciach %d, %d, %d.\n", c, d, e);
	printf("\n");
	int pole = 0;
	int podstawa = 5;
	int wysokosc = 6;
	printf("\n----------Dzialanie kodu assemblerowego liczacego pole rownolegloboku----------\n");
	__asm { // liczenie pola rownolegloboku o wysokosciach 
		mov eax, podstawa
		mov ebx, wysokosc
		mul ebx
		mov ebx, 2 
		div ebx
		mov pole, eax
	}
	printf("Pole rownolegloboku o podstawie dlugosci %d i wysokosci %d wynosi %d.\n", podstawa, wysokosc, pole);
	printf("\n----------Dzialanie assemblerowej funkcji funkcja.asm (zamiana duzych liter na male, malych na duze, cyfr na x----------\n");
	char buffor[] = "Zg29Fg_xli3dad1234FasdXDads11";
	printf("Tablica oryginalna: \n");
	for (int i = 0; i < 29; i++)
	{
		printf("%c", buffor[i]);
	}
	printf("\nTablica zmodyfikowana:\n");
	funkcja(buffor);
	for (int i = 0; i < 29; i++) 
	{
		printf("%c", buffor[i]);
	}
	return 0;
}


