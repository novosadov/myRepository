#include <stdio.h>
#include <locale.h>
#include <string.h>
 
 
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
 
 
void zapolnenieStructure(struct Book* books, int* kolichestvo);
void menu(struct Book* books, int* kolichestvo);
void printStructure(struct Book* books, int* kolichestvo);
void sort(struct Book* books, int* kolichestvo, enum Sortirovka sortBy);
void copyBook(struct Book const* from, struct Book* to);
 
 
int main()
{
    setlocale(LC_ALL, "rus");
 
    struct Book books[KOLICHESTVO];
    int kolichestvo = 0;
    menu(books, &kolichestvo);
 
    return 0;
}
 
void menu(struct Book* books, int* kolichestvo)
{
    enum Sortirovka sortirovka;
    enum Menu menu;
    while (true)
    {
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
            break;
        case Vivod:
            printStructure(books, kolichestvo);
            break;
        case Sortirovka:
            printf("Выберите как требуется отсортировать\n");
            printf("1 - по имени\n2 - по автору\n3 - по жанру\n4 - по году\n");
            scanf("%i", &sortirovka);
            sort(books, kolichestvo, sortirovka);
            break;
        case Vihod:
            return;
        default:
            printf("Введите правильное значение\n");
            break;
        }
    }
}
 
 
 
 
 
void zapolnenieStructure(struct Book* books, int* kolichestvo)
{
    printf("Введите название книги\n");
    fgets(books[*kolichestvo].name, 50, stdin);
 
    printf("Введите автора книги\n");
    fgets(books[*kolichestvo].author, 50, stdin);
 
    printf("Введите жанр книги\n");
    fgets(books[*kolichestvo].genre, 50, stdin);
 
    printf("Введите год книги\n");
    scanf("%i", &(books[*kolichestvo].year));
 
    (*kolichestvo)++;
 
    char ch;
    do {
        ch = getchar();
    } while (ch != '\n' && ch != EOF);
}
 
 
 
 
void printStructure(struct Book* books, int* kolichestvo)
{
 
    for (int i = 0; i < *kolichestvo; i++)
    {
 
        printf("Название %i книги:\t%s\n", i + 1, books[i].name);
        printf("Автор %i книги:\t\t%s\n", i + 1, books[i].author);
        printf("Жанр %i книги:\t\t%s\n", i + 1, books[i].genre);
        printf("Год %i книги\t\t%i\n", i + 1, books[i].year);
        printf("\n\n\n");
    }
 
}
 
void copyBook(struct Book const* from, struct Book* to)
{
    strcpy(to->name, from->name);
    strcpy(to->author, from->author);
    strcpy(to->genre, from->genre);
    to->year = from->year;
}
 
void sort(struct Book* books, int* kolichestvo,
    enum Sortirovka sortBy)
{
    struct Book temp;
 
    for (int i = 0; i < *kolichestvo - 1; i++)
    {
        for (int j = 0; j < *kolichestvo - 1 - i; j++)
        {
            if (sortBy == Name && (books[j].name, books[j + 1].name) > 0 ||
                sortBy == Author && (books[j].author, books[j + 1].author) > 0 ||
                sortBy == Genre && (books[j].genre, books[j + 1].genre) > 0 ||
                sortBy == Year && (books[j].year, books[j + 1].year) > 0)
            {
                copyBook(&books[j], &temp);
                copyBook(&books[j + 1], &books[j]);
                copyBook(&temp, &books[j + 1]);
            }
        }
    }
}
