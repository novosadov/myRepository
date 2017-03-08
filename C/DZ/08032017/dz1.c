#include <stdio.h>
#include <locale.h>


/*
Написать функцию, которая удаляет из строки символ с заданным номером.
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
	int num = 0;
	printf("Введите номер символа, который хотите удалить\n");
	scanf("%i", &num);	

	while (*(str + leghtArray) != 0)
	{
		
		if (*(str + leghtArray) == *(str + num-1))
		{
			*(str + leghtArray) = ' ';
		}
		leghtArray++;
	}	

	return 0;
}


