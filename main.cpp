// Addem Main Program      (AddMain.cpp) 

#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

extern "C" int poteguj(int a, int b);
extern "C" int fibonacci(int n);

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
	return 0;
}


