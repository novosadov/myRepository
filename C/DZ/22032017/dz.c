#include<stdio.h>
#include<locale.h>

#define KOLICHESTVO 2


/*
Разработать программу для управления библиотекой книг (имя, автор, жанр, год) со
следующими возможностями:
• Добавление книг
• Вывод списка книг
• Сортировка по заданному критерию (имя, автор, жанр, год) с указанием
направления сортировки
*/

struct Book
{
	char name[50];
	char author[50];
	char genre[50];
	int year;	
	char temp[50];
};

enum Menu
{
	Dobavlenie = 1,
	Vivod,
	Sortirovka,
	Vihod

};

enum Sortirovka
{
	Name = 1,
	Author,
	Genre,
	Year
};


void zapolnenieStructure(struct Book books[], int kolichestvo);
void menu(struct Book books[], int kolichestvo);
void printStructure(struct Book books[], int kolichestvo);
void sortName(struct Book books[], int kolichestvo);



int main()
{
	setlocale(LC_ALL, "rus");

	struct Book books[KOLICHESTVO] = {0,0,0,0};
	int kolichestvo = KOLICHESTVO;
	menu(books, kolichestvo);

	return 0;
}



void menu(struct Book books[], int kolichestvo)
{
	enum Sortirovka sortirovka;
	enum Menu menu;
	   a:	
		printf("Выберите действие:\n");
		printf("1 - Добавление книги\n2 - Вывод списка книг\n3 - Отсортировать книги\n4 - Выход\n");
		scanf("%i", &menu);
		char ch;
		do {
			ch = getchar();
		} while (ch != '\n' && ch != EOF);
		
		switch (menu)
		{
		case Dobavlenie:
			zapolnenieStructure(books, kolichestvo);
			goto a;
		case Vivod:
			printStructure(books, kolichestvo);
			goto a;
		case Sortirovka:
			printf("Выберите как требуется отсортировать\n");
			printf("1 - по имени\n2 - по автору\n3 - по жанру\n4 - по году\n");
			scanf("%i", &sortirovka);
			switch (sortirovka)
			{
			case Name:
				printf(" ");
				break;
			case Author:
				printf(" ");
				break;
			case Genre:
				printf(" ");
				break;
			case Year:
				printf(" ");
				break;
			default:
				break;
			}
			goto a;
		case Vihod:
			
			break;
		default:
			printf("Введите правильное значение\n");
			goto a;
		}
	}





void zapolnenieStructure(struct Book books[], int kolichestvo)
{
	
	for (int i = 0; i < kolichestvo; i++)
	{

		printf("Введите название книги\n");
		fgets(books[i].name, 50, stdin);

		printf("Введите автора книги\n");
		fgets(books[i].author, 50, stdin);

		printf("Введите жанр книги\n");
		fgets(books[i].genre, 50, stdin);

		printf("Введите год книги\n");
		scanf("%i", &books[i].year);

		char ch;
		do {
			ch = getchar();
		} while (ch != '\n' && ch != EOF);
	}
}




void printStructure(struct Book books[], int kolichestvo)
{
	
	for (int i = 0; i < kolichestvo; i++)
	{

		printf("Название %i книги:\t%s\n", i + 1, books[i].name);
		printf("Автор %i книги:\t\t%s\n", i + 1, books[i].author);
		printf("Жанр %i книги:\t\t%s\n", i + 1, books[i].genre);
		printf("Год %i книги\t\t%i\n", i + 1, books[i].year);
		printf("\n\n\n");
	}

}



void sortName(struct Book books[], int kolichestvo)
{

	struct Rezultat temp;
	
	for (int i = 0; i < kolichestvo; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (strcmp(books[j - 1].name && books[j].name) > 0) 
			{
				temp = books[j - 1];
				books[j - 1] = books[j];
				books[i] = temp;
			}
		}
	}
}
