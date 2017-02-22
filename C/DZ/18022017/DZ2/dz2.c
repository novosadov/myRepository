#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_ARRAY 5


/*
Создайте двухмерный массив. Заполните его случайными числами и покажите
на экран.
Пользователь выбирает количество сдвигов и положение (влево, вправо, вверх, вниз).
Выполнить сдвиг массива и показать на экран полученный результат. Сдвиг циклический.
Например, если мы имеем следующий массив
1 2 0 4 5 3
4 5 3 9 0 1
и пользователь выбрал сдвиг на 2 разряда вправо, то мы получим
5 3 1 2 0 4
0 1 4 5 3 9
*/


enum Sdvig
{
	Left = 1,
	Right,
	Up,
	Down
};


int creatArray(int array[SIZE_ARRAY][SIZE_ARRAY], int size);
int printArray(int array[SIZE_ARRAY][SIZE_ARRAY], int size);
int sdvigArray(int array[SIZE_ARRAY][SIZE_ARRAY], int size);

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int size = SIZE_ARRAY;
	
	int array[SIZE_ARRAY][SIZE_ARRAY];
	creatArray(array, size);
	printArray(array, size);
	sdvigArray(array, size);
	return 0;
}


//создаёт массив
int creatArray(int array[SIZE_ARRAY][SIZE_ARRAY], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			array[i][j] = rand() % 100;
		}
	}
	return array;
}



//выводит массив
int printArray(int array[SIZE_ARRAY][SIZE_ARRAY], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%i\t", array[i][j]);
		}
		printf("\n");
	}
	return array;
}


//сдвигает элементы массива в выбранном направлении
int sdvigArray(int array[SIZE_ARRAY][SIZE_ARRAY], int size)
{
	enum Sdvig sdvig;
	int kolichestvoSdvigov = 0;
	printf("Введите количество сдвигов\n");
	scanf("%i", &kolichestvoSdvigov);
	printf("Выберите положение сдвига:\n");
	printf("1 - Влево\n2 - Вправо\n3 - Вверх\n4 - Вниз\n");
	scanf("%i", &sdvig);
	switch (sdvig)
	{
	case Left:		

		for (int i = 0; i < kolichestvoSdvigov; i++)
		{
			for (int j = 0; j < size; j++)
			{
				int buf = array[j][0];
				for (int f = 0; f < size- 1; f++)
				{
					array[j][f] = array[j][f + 1];
				}
				array[j][size - 1] = buf;
			}
		}
		printArray(array, size);
		break;
	case Right:	
		
		for (int i = 0; i < kolichestvoSdvigov; i++)
		{
			for (int j = 0; j < size; j++)
			{
				int buf = array[j][size - 1];
				for (int f = size - 1; f > 0; f--)
				{
					array[j][f] = array[j][f - 1];
				}
				array[j][0] = buf;
			}
		}
				
		printArray(array, size);
		break;
	case Up:
		for (int i = 0; i < kolichestvoSdvigov; i++)
		{
			for (int j = 0; j < size; j++)
			{
				int buf = array[0][j];
				for (int f = 0; f < size - 1; f++)
				{
					array[f][j] = array[f + 1][j];
				}
				array[size - 1][j] = buf;
			}
		}

		printArray(array, size);
		break;
	case Down:
		for (int i = 0; i < kolichestvoSdvigov; i++)
		{
			for (int j = 0; j < size; j++)
			{
				int  buf = array[size - 1][j];
				for (int f = size - 1; f > 0; f--)
				{
					array[f][j] = array[f - 1][j];
				}
				array[0][j] = buf;
			}
		}
		printArray(array, size);
		break;
	default:
		printf("Вы ввели не верное значение\n");
		break;
	}
}
