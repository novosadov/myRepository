#include <stdio.h>
#include <locale.h>
#define SIZE_ARRAY 10


/*
Используя два указателя на массив целых чисел, скопировать один массив в другой.
Использовать в программе арифметику указателей для продвижения по массиву, а также
оператор разыменования.
*/

void printArray(int* array, int* size);
void copyArray(int* array1, int* array2, int* size);

int main()
{
	setlocale(LC_ALL, "rus");
	int size = SIZE_ARRAY;

	int array1[SIZE_ARRAY] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	int array2[SIZE_ARRAY] = { 0, 0, 0, 0, 0,  0,  0,  0,  0,  0 };

	printArray(&array1, &size);
	printArray(&array2, &size);

	copyArray(&array1, &array2, &size);

	printArray(&array1, &size);
	printArray(&array2, &size);

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



void copyArray(int* array1, int* array2, int* size)
{
	int *ptrArray1 = array1;
	int *ptrArray2 = array2;
	int *endArray = ptrArray1 + *size;
	for (; ptrArray1 != endArray; ++ptrArray1, ++ptrArray2)
		*ptrArray2 = *ptrArray1;
}
