#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_ARRAY 10



/*
Написать программу, которая содержит функцию, принимающую в качестве аргумента,
указатели на три массива и размер массивов. Функция заносит в массив C суммы
элементов массивов А и В. Размер массивов одинаковый.
*/




void fillArray(int array[SIZE_ARRAY], int size);
void printArray(int array[SIZE_ARRAY], int size);
void summaMassivov(int array[SIZE_ARRAY], int* array2[SIZE_ARRAY], int* array3[SIZE_ARRAY], int* size);


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int size = SIZE_ARRAY;
	int array[SIZE_ARRAY];
	int array2[SIZE_ARRAY];
	int array3[SIZE_ARRAY];
	
	fillArray(array, size);
	printArray(array, size);

	fillArray(array2, size);
	printArray(array2, size);

	summaMassivov(array, &array2, &array3, &size);
	printArray(array3, size);
	
	return 0;
}




void fillArray(int array[SIZE_ARRAY], int size)
{

	for (int i = 0; i < size; i++)
	{		
			array[i] = rand() % 100;		
	}
}


void printArray(int array[SIZE_ARRAY], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%i ", array[i]);
			
	}
	printf("\n");
}



void summaMassivov(int array[SIZE_ARRAY], int* array2[SIZE_ARRAY], int* array3[SIZE_ARRAY], int* size)
{
	
	for (int i = 0; i < *size; i++)

	{
		array3[i]= array[i] + array2[i];
		
	}
	printf("\n");
}
