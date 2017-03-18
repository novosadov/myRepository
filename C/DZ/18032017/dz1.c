#include<stdio.h>
#include<locale.h>

/*
Написать функцию, которая вставляет в строку в указанную позицию заданный символ.
*/


void printString(char* str);
void pasteSimbol(char* str);


int main()
{
	setlocale(LC_ALL, "rus");

	char str[] = "Hello World";
	printString(str);
	pasteSimbol(str);
	printString(str);

	return 0;
}


void  printString(char *str)
{
	printf("%s\n", str);
}


void pasteSimbol(char* str)
{
	char simbol;
	int poziciya;
	printf("Введите символ, который хотите вставить\n");
	scanf("%c", &simbol);
	printf("Введите номер позиции в которую хотите вставить символ\n");
	scanf("%i", &poziciya);
	str[poziciya-1] = simbol;
}
