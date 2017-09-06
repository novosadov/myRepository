#include <stdio.h>
#include <locale.h>
#define ARRAY_SIZE_ARRAY

/*
Используя указатель на массив целых чисел, изменить порядок следования элементов
массива на противоположный. Использовать в программе арифметику указателей для
продвижения по массиву, а также оператор разыменования.
*/

void printArray(int* array, int* size);
void reverseArray(int* array, int* size);

int main()
{
	setlocale(LC_ALL, "rus");
	int size = SIZE_ARRAY;

	int array[SIZE_ARRAY] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	

	printArray(&array, &size);
	

	smenaArray(&array, &size);

	printArray(&array, &size);
	

	return 0;
}

void printArray(int* array, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		printf("%i ", *(array + i));
	}
	printf("\n");
}



void reverseArray(int* array, int* size)
{
	for (int i = 0, j = *size / 2; i<j; i++)
	{
		int d = *(array+i);
		*(array + i) = *(array+(*size - 1 - i));
		*(array + (*size - 1 - i)) = d;
	}
}
