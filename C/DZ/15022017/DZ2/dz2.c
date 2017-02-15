#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_ARRAY 10

/*
Задание 2: Есть стопка оладий различного радиуса. Единственная операция, проводимая с
ними - между любыми двумя суем лопатку и меняем порядок оладий над лопаткой на
обратный. Необходимо за минимальное количество операций таких отсортировать снизу-
вверх по убыванию радиуса.
*/

int sozdaemMassiv(int array[], int dlinaMassiva);
int vivodMassiva(int array[], int dlinaMassiva);
int vstavkaLopatki();
int sortirovka(int array[], int dlinaDoLopatki, int dlinaMassiva);

int lopatka = 0;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int stopkaBlinov[SIZE_ARRAY];
	int dlinaMassiva = SIZE_ARRAY;
	sozdaemMassiv(stopkaBlinov, dlinaMassiva);
	vivodMassiva(stopkaBlinov, dlinaMassiva);
	int dlinaDoLopatki = vstavkaLopatki();
	printf("Вставляем лопатку между %i и %i блином\n", dlinaDoLopatki - 1, dlinaDoLopatki);
	
	sortirovka(stopkaBlinov, dlinaDoLopatki, dlinaMassiva);

	return 0;
}


int vivodMassiva(int array[], int dlinaMassiva)
{
	for (int i = 0; i < dlinaMassiva; i++)
	{
		printf("%i  ", array[i]);
		printf("\n");
	}

	printf("\n");
	return array;
}


int sozdaemMassiv(int array[], int dlinaMassiva)
{
	for (int i = 0; i < dlinaMassiva; i++)
	{
		array[i] = rand() % 10;
	}
	return array;
}


int vstavkaLopatki()
{
	lopatka = rand() % 10;
	return lopatka;
}


int sortirovka(int array[],int dlinaDoLopatki, int dlinaMassiva)
{
	for (int i = 0; i < dlinaDoLopatki; i++)
	{
		int x = array[i];
		int j = i;
		while (j > 0 && array[j - 1] > x)
		{
			array[j] = array[j - 1];
			j = j - 1;
		}
		array[j] = x;
	}
	vivodMassiva(array, dlinaMassiva);
	return array;
}
