#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define SIZEARRAY 10

/*
Задание 1: Написать программу «справочник». Создать два одномерных массива. Один
массив хранит номера ICQ, второй – телефонные номера. Реализовать меню для
пользователя:
• Отсортировать по номерам ICQ
• Отсортировать по номерам телефона
• Вывести список пользователей
• Выход
*/

enum Menu
{
	SortirovkaIcq = 1,
	SortirovkaTelNumber,
	SpisokPolzovateley,
	Exit
};


void swap(int array[], int dlinaMassiva);
void arraySort(int array[], int dlinaMassiva);
int vivodMassiva(int array[], int dlinaMassiva);
int sozdaetMassiv(int array[], int dlinaMassiva);

int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	enum Menu menu;
	
	int user;
	int icqNumber[SIZEARRAY];
	int telNumber[SIZEARRAY];
	int dlinaMassiva = SIZEARRAY;

	sozdaetMassiv(icqNumber, dlinaMassiva);
	vivodMassiva(icqNumber, dlinaMassiva);
	sozdaetMassiv(telNumber, dlinaMassiva);
	vivodMassiva(telNumber, dlinaMassiva);

	printf("Выберите пункт меню: \n");
	printf("1 - Отсортировать список ICQ\n2 - Отсортировать по номерам телефона\n3 - Вывести список пользователей\n"
	"4 - Выход\n");
	scanf("%i", &menu);
	switch (menu)
	{
	case SortirovkaIcq:
		arraySort(icqNumber, dlinaMassiva);		
		break;
	case SortirovkaTelNumber:
		arraySort(telNumber, dlinaMassiva);		
		break;
	case SpisokPolzovateley:
		vivodMassiva(icqNumber, dlinaMassiva);
		vivodMassiva(telNumber, dlinaMassiva);
		break;
	case Exit:
		break;
	default:
		printf("Введите правильное значение\n");
		break;
	}	
	
	return 0;
}


//сортирует массив
void arraySort(int array[], int dlinaMassiva)
{
	swap(array, dlinaMassiva);
	vivodMassiva(array, dlinaMassiva);
}


// Меняет значения местами
void swap(int array[], int dlinaMassiva)
{
	for (int i = 0; i < dlinaMassiva - 1; i++)
	{
		for (int j = 0; j < dlinaMassiva - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

//выводит массив
int vivodMassiva(int array[], int dlinaMassiva)
{
	for (int i = 0; i < dlinaMassiva; i++)
	{
		printf("%i,  ", array[i]);		
		printf("\n");
	}
	
	printf("\n");
	return array;
}

//создаёт массив
int sozdaetMassiv(int array[], int dlinaMassiva)
{
	for (int i = 0; i < dlinaMassiva; i++)
	{
		array[i] = 7770000 + rand() % 9999999;
	}
	return array;
}
