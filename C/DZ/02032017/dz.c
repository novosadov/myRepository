#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_ARRAY1 10
#define SIZE_ARRAY2 10


enum UserMenu
{
	Max = 1,
	Min,
	Avg
};

/*
Написать программу, которая содержит функцию Action, принимающую в качестве
аргумента, указатели на два массива (А и В) и размеры массивов, а также указатель на
функцию.
Пользователю отображается меню, в котором он может выбрать max, min, avg.
Если выбран max - передается указатель на функцию, которая ищет максимум, если
выбран min - передается указатель на функцию, которая ищет минимум, если выбран avg -
передается указатель на функцию, которая ищет среднее.
Возвращаемое значение функции Action результат выбора пользователя max, min, avg.
*/


float srednee;
void creatArray(int* array, int* size);
void printArray(int* array, int* size);
int fooAction(int* array1, int* array2, int* size1, int* size2);
int maxNumber(int* array, int* size);
int minNumber(int* array, int* size);
int avgNumber(int* array, int* size);

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int size1 = SIZE_ARRAY1;
	int size2 = SIZE_ARRAY2;
	int array1[SIZE_ARRAY1];
	int array2[SIZE_ARRAY2];
	creatArray(&array1, &size1);
	creatArray(&array2, &size2);
	printArray(&array1, &size1);
	printArray(&array2, &size2);

	fooAction(&array1, &array2, &size1, &size2);

	return 0;
}



int fooAction(int* array1, int* array2, int* size1, int* size2) 
{
	enum UserMenu userMenu;
	printf("Выберите, что вы хотите получить:\n");
	printf("1 - Максимальное число\n2 - Минимальное\n3 - Среднее арифметическое\n");
	scanf("%i", &userMenu);
	switch (userMenu)
	{
	case Max:
		if (maxNumber(array1, size1) > maxNumber(array2, size2))
		{
			printf("Максимальное число в массиве = %i\n", maxNumber(array1, size1));
		}
		else
		{
			printf("Максимальное число в массиве = %i\n", maxNumber(array2, size2));
		}
		break;
	case Min:
		if (minNumber(array1, size1) < minNumber(array2, size2))
		{
			printf("Минимальное число в массиве = %i\n", minNumber(array1, size1));
		}
		else
		{
			printf("Минимальное число в массиве = %i\n", minNumber(array2, size2));
		}
		break;
	case Avg:
		srednee = (avgNumber(array1, size1)+ avgNumber(array2, size2))/2;		 
		printf("Среднее арифметическое %0.2f\n", srednee);
		break;
	default:
		printf("Вы ввели не верные данные\n");
		break;
	}
	return 0;
}



//Заполняет массив случайными числами
void creatArray(int* array, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		*(array + i) = rand() % 100;
	}
}

//Выводит массив на экран
void printArray(int* array, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		printf("%i ", *(array + i));
	}
	printf("\n");
}


int maxNumber(int* array, int* size)
{
	int max = *array;

	for (int i = 1; i < *size; i++)
	{
		if (*(array + i) > max)
		{
			max = *(array + i);
		}
	}
	return max;
}


int minNumber(int* array, int* size)
{
	int min = *array;

	for (int i = 0; i < *size; i++)
	{
		if (*(array + i) < min)
		{
			min = *(array + i);
		}	
	}
	return min;
}

int avgNumber(int* array, int* size)
{
	float sum = 0;
	float avg = 0;

	for (int i = 0; i < *size; i++)
	{
		sum += *(array + i);		
	}
	avg = sum / (*size);
	return avg;
}
