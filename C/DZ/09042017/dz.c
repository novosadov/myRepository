#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

/*
Написать программу, которая получает от пользователя количество дней измерений
температуры (дата, температура), затем получает эти измерения и записывает их в
динамический массив. Затем программа спрашивает еще несколько дней измерений и
программа, используя realloc перевыделяет память. Вывести полученный массив на экран.
Пример:
1. Пользователь вводит количество дней – 5
2. Программа выделяет динамический массив из 5 элементов
3. Программа спрашивает еще количество дней – 3
4. Программа перевыделяет динамический массив на 8 элементов (5+3)
*/


struct Day
{
	int date;
	float temperature;
};

void main()
{
	setlocale(LC_ALL, "rus");


	int daycount = 0;
	printf("Введите количество дней\n");
	scanf("%i", &daycount);

	struct Day** day = malloc(sizeof(struct Day*) * daycount);
	if (day == NULL)
	{
		printf("ERROR");
		return;
	}


	for (int i = 0; i < daycount; i++)
	{
		day[i] = malloc(sizeof(struct Day));
	}

	for (int i = 0; i < daycount; i++)
	{
		printf("Введите данные за %i день\n", i + 1);
		for (int j = 0; j < 2; j++)
		{
			printf("Введите дату");
			scanf("%i", &((*day[i]).date));
			printf("Введите температуру");
			scanf("%f", &((*day[i]).temperature));
		}

	}
}
