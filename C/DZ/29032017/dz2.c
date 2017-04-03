#include<stdio.h>
#include<locale.h>
#include <string.h>

#define STRUCT_SIZE 3


/*
Написать программу, которая хранит информацию об автомобиле (марка, модель, цвет
(enum), тип топлива (enum) и год) в динамическом массиве. Пользователь определяет
размерность массива и вводит 5 автомобилей. Реализовать возможность поиска всех
автомобилей младше определенного года.
*/


enum FuelType
{
	FuelTypeBenz80 = 80,
	FuelTypeBenz92 = 92,
	FuelTypeBenz95 = 95	
};

struct Car
{
	char* Brand;
	char* Model;
	char* Color;
	enum FuelType FuelType;
	int Year;
};

void getString(char* message, char* st, int maxStringSize);
void clean();
void printCarsFilteredByYear(struct Car* cars, int carsCount, int year);
void getInt(char* message, int* value);

int main()
{
	setlocale(LC_ALL, "rus");
	printf("Введите количество автомобилей: ");
	int carCount;
	scanf("%i", &carCount);
	clean();

	struct Car* car = malloc(carCount * sizeof(struct Car));

	int i = 0;
	while (i < carCount)
	{
		printf("Введите #%i автомобиль: \n", i + 1);
		car[i].Brand = malloc(30);
		getString("Марка: ", car[i].Brand, 30);
		car[i].Model = malloc(30);
		getString("Модель: ", car[i].Model, 30);
		car[i].Color = malloc(30);
		getString("Цвет: ", car[i].Color, 30);
		getInt("Год выпуска: ", (int*)&car[i].Year);		
		getInt("Вид топлива: \n80\n92\n95\n", (int*)&car[i].FuelType);
		clean();
		i++;
	}

	printf("Введите год, младше которого надо вывести автомобили: ");
	int year;
	scanf("%i", &year);
	printCarsFilteredByYear(car, carCount, year);
	
}

void getString(char* message, char* st, int maxStringSize)
{
	char* find;

	printf("%s", message);
	char* result = fgets(st, maxStringSize, stdin);
	if (result != NULL)
	{
		find = strchr(st, '\n');
		if (find != NULL)
		{
			*find = 0;
		}
		else
		{
			clean();
		}
	}
}

void getInt(char* message, int* value)
{
	printf("%s", message);
	scanf("%i", value);
}

void clean()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}

void printCar(struct Car* car)
{
	printf("Марка:\t%s\n", car->Brand);
	printf("Модель:\t%s\n", car->Model);
	printf("Тип топлива:\t%i\n", car->FuelType);
	printf("Цвет:\t%s\n", car->Color);
	printf("Год:\t%i\n\n", car->Year);
}

void printCarsFilteredByYear(struct Car* cars, int carsCount, int year)
{
	for (int i = 0; i < carsCount; i++)
	{
		if (cars[i].Year > year)
		{
			printCar(&cars[i]);
		}
	}
}
