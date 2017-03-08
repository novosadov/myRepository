#include <stdio.h>
#include <locale.h>


/*
Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.
*/
int delChar(char* str);
void printStr(char* str);


int main()
{
	setlocale(LC_ALL, "rus");
	char str[256];
	fgets(str, 256, stdin);
	delChar(str);
	printStr(str);

	return 0;
}


void printStr(char* str)
{
	printf("%s", str);
}


int delChar(char* str)
{
	int leghtArray = 0;
	char simvol = ' ';
	printf("Введите символ, который хотите удалить\n");
	scanf("%c", &simvol);

	while (*(str + leghtArray) != 0)
	{
		if (*(str + leghtArray) == simvol)
		{
			*(str + leghtArray) = ' ';
		}
		leghtArray++;
	}

	return 0;
}
