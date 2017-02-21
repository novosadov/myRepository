#include <stdio.h>
#include <locale.h>


/*
Напишите программу возведения чисел в степень, используйте указатели для передачи
результирующего значения в функцию и из нее. Числа необходимо получать от
пользователя.
*/

void getNumber(int* number);
int vozvedenieVstepen(int* number);

int main()
{
	setlocale(LC_ALL, "rus");
	int number = 0;
	getNumber(&number);
	printf("%i\n", vozvedenieVstepen(&number));

	return 0;
}


void getNumber(int* number)
{
	printf("Введите  значение которое вы хотите ворзвести в степень\n");
	scanf("%i", number);

}



int vozvedenieVstepen(int* number)
{
	int rezult = 1;
	for (int i = 0; i < *number; i++)
	{
		rezult = rezult * *number;
	}
	return rezult;
}
