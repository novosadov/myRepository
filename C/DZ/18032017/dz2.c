#include<stdio.h>
#include<locale.h>
#include <string.h>

#define LEIGHT_ARRAY 1024


/*
Написать функцию, которая определяет, является ли введенное слово анаграммой.
*/

void printString(char* str);
void proveryaetAnagramma(char* str);
void vvodZnacheniya(char* str, int leight);


int main()
{
	setlocale(LC_ALL, "rus");
	int leight = LEIGHT_ARRAY;
	char str[LEIGHT_ARRAY];
	vvodZnacheniya(str, leight);
	printString(str);
	proveryaetAnagramma(str);

	return 0;
}


void  printString(char *str)
{
	printf("%s\n", str);
}


void proveryaetAnagramma(char* str)
{			
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] != str[(strlen(str)) - 1 - i])
		{
			printf("No\n");			
			break;
		}
		else
		{
			printf("Yes\n");
		}
	}
}


void vvodZnacheniya(char* str, int leight)
{
	printf("Введите слово которое необходимо узнать, анаграмма или нет\n");
	fgets(str, leight, stdin);
}
