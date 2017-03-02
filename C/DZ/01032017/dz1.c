#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_ARRAY1 3
#define SIZE_ARRAY2 5


/*
Написать функцию, которая получает указатель на статический двумерный массив (3x5) и
его размер. Функция распределяет положительные, отрицательные и нулевые элементы в
3 отдельных массива, указатели на которые также переданы в функцию.
*/





void fillArray(int array[SIZE_ARRAY1][SIZE_ARRAY2], int size1, int size2);
void printArray(int* array[SIZE_ARRAY1][SIZE_ARRAY2], int* size1, int* size2);

void sortArray(int array[SIZE_ARRAY1][SIZE_ARRAY2], int negativArray[SIZE_ARRAY1][SIZE_ARRAY2],
	int pozitivArray[SIZE_ARRAY1][SIZE_ARRAY2], int zerroArray[SIZE_ARRAY1][SIZE_ARRAY2], int size1, int size2);

void printNegativeArray(int* negativArray[SIZE_ARRAY1][SIZE_ARRAY2], int* size1, int* size2);
void printPozitivArray(int pozitivArray[SIZE_ARRAY1][SIZE_ARRAY2], int size1, int size2);
void printZerroArray(int* zerroArray[SIZE_ARRAY1][SIZE_ARRAY2], int* size1, int* size2);

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int size1 = SIZE_ARRAY1;
	int size2 = SIZE_ARRAY2;
	
	int array[SIZE_ARRAY1][SIZE_ARRAY2];
	int negativArray[SIZE_ARRAY1][SIZE_ARRAY2];
	int pozitivArray[SIZE_ARRAY1][SIZE_ARRAY2];
	int zerroArray[SIZE_ARRAY1][SIZE_ARRAY2];

	
	
	fillArray(array, size1, size2);
	printArray(&array, &size1, &size2);

	sortArray(array, negativArray, pozitivArray, zerroArray, size1, size2);
	
	printNegativeArray(&negativArray, &size1, &size2);
	printPozitivArray(pozitivArray, size1, size2);
	printZerroArray(&zerroArray, &size1, &size2);
	
	return 0;
}




void fillArray(int array[SIZE_ARRAY1][SIZE_ARRAY2], int size1, int size2)
{
	
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			array[i][j] = -99+rand() % 199;
		}
	}
}


void printArray(int* array[SIZE_ARRAY1][SIZE_ARRAY2], int* size1, int* size2)
{
	for (int i = 0; i < *size1; i++)
	{
		for (int j = 0; j < *size2; j++)
		{
			printf("%i ", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}



void sortArray(int array[SIZE_ARRAY1][SIZE_ARRAY2], int negativArray[SIZE_ARRAY1][SIZE_ARRAY2],
	int pozitivArray[SIZE_ARRAY1][SIZE_ARRAY2], int zerroArray[SIZE_ARRAY1][SIZE_ARRAY2], int size1, int size2)
{
		

	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{			
			if (array[i][j] < 0)
			{
				negativArray[i][j] = array[i][j];
				
			}
			if (array[i][j] > 0)
			{
				pozitivArray[i][j] = array[i][j];

			}
			if (array[i][j] == 0)
			{
				zerroArray[i][j] = array[i][j];

			}
		}
	}		
}


void printNegativeArray(int* negativArray[SIZE_ARRAY1][SIZE_ARRAY2], int* size1, int* size2)
{
	for (int i = 0; i < *size1; i++)
	{
		for (int j = 0; j < *size2; j++)
		{
			if (negativArray[i][j] < -99)
			{
				printf("");
			}
			else
			{
				printf("%i ", negativArray[i][j]);
			}
		}		
	}
	printf("\n");
}


void printPozitivArray(int pozitivArray[SIZE_ARRAY1][SIZE_ARRAY2], int size1, int size2)
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (pozitivArray[i][j] < -99)
			{
				printf("");
			}
			else
			{
				printf("%i ", pozitivArray[i][j]);
			}
		}
	}
	printf("\n");
}


void printZerroArray(int* zerroArray[SIZE_ARRAY1][SIZE_ARRAY2], int* size1, int* size2)
{
	for (int i = 0; i < *size1; i++)
	{
		for (int j = 0; j < *size2; j++)
		{
			if (zerroArray[i][j] < -99)
			{
				printf("");
			}
			else
			{
				printf("%i ", zerroArray[i][j]);
			}
		}
	}
	printf("\n");
}
