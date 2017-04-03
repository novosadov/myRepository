#include<stdio.h>
#include<locale.h>

#define STRUCT_SIZE 3


/*
Написать программу, которая хранит информацию об автомобиле (марка, модель, цвет
(enum), тип топлива (enum) и год) в динамическом массиве. Пользователь определяет
размерность массива и вводит 5 автомобилей. Реализовать возможность поиска всех
автомобилей младше определенного года.
*/


enum Type
{
	BeginType,
	Brand,
	Model,
	Color,
	FuelType,
	Year,
	EndType
};

union Data
{
	char* valueStr;
	int valueYear;
};

struct DataItem
{
	enum valueType type;
	union Data data;
};



void print(struct DataItem* values);
void clearChar();



void main()
{
	setlocale(LC_ALL, "rus");
	struct DataItem values[STRUCT_SIZE];
	printf("Характеристики:\n %i - Марка\n %i - Модель\n %i - Цвет\n%i - Топливо\n%i - Год\n",
		Brand, Model, Color, FuelType, Year);
	enum Type type;
	for (int i = 0; i < STRUCT_SIZE; i++)
	{
		do
		{
			printf("# Введите характеристики %i автомобиля\n", i + 1);
			scanf("%i", &type);
		} while (type >= EndType || type <= BeginType);
		clearChar();
		switch (type)
		{
		case Brand:
			printf("Введите марку автомобиля: ");
			scanf("%s\n", &values[i].data.valueStr);
			values[i].type = Brand;
			break;
		case Model:
			printf("Введите модель автомобиля: ");
			scanf("%s\n", &values[i].data.valueStr);
			values[i].type = Model;
			break;
		case Color:
			printf("Введите цвет автомобиля: ");
			scanf("%s\n", &values[i].data.valueStr);
			values[i].type = Color;
			break;
		case FuelType:
			printf("Введите вид топлива: ");
			scanf("%s\n", &values[i].data.valueStr);
			values[i].type = Brand;
			break;
		case Year:
			printf("Введите год автомобиля: ");
			scanf("%i\n", &values[i].data.valueYear);
			values[i].type = Brand;
			break;
		default:
			printf("Error ");

			break;
		}
	}
	print(values);
}



void print(struct DataItem* values)
{
	for (int i = 0; i < STRUCT_SIZE; i++)
	{
		switch (values[i].type)
		{
		case Brand:
			printf("%s\n", values[i].data.valueStr);
			break;
		case Model:
			printf("%s\n", values[i].data.valueStr);
			break;
		case Color:
			printf("%s\n", values[i].data.valueStr);
			break;
		case FuelType:
			printf("%s\n", values[i].data.valueStr);
			break;
		case Year:
			printf("%i\n", values[i].data.valueYear);
			break;
		default:
			printf("%s\n", values[i].data.valueStr);
			break;
		}
	}
}


void clearChar()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}
