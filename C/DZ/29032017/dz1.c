#include<stdio.h>
#include<locale.h>



#define STUDENT 3

/* Написать программу, которая дает пользователю ввести 5 фамилий студентов и хранит их
в динамическом массиве, а затем сортирует их по возрастанию.
*/


void zapolnenieDannih(char** list, int studentCount);
void printSpisok(char** list, int studentCount);
void sort(char** list, int studentCount);


int main()
{
	setlocale(LC_ALL, "rus");

	int studentCount = STUDENT;
	char** list = malloc(sizeof(char*) * STUDENT);
	for (int i = 0; i < STUDENT; i++)
	{
		list[i] = malloc(50 * sizeof(char));
	}

	zapolnenieDannih(list, studentCount);
	
	sort(list, studentCount);
	printSpisok(list, studentCount);

	return 0;
}


void zapolnenieDannih(char** list, int studentCount)
{
	for (int i = 0; i < studentCount; i++)
	{

		printf("Введите ФИО студента\n");
		fgets(list[i], 50, stdin);	
		
	}
}



void printSpisok(char** list, int studentCount)
{
	for (int i = 0; i < studentCount; i++)
	{
		printf("ФИО студента %s\n", list[i]);		
	}
}



void sort(char** list, int studentCount)
{
	for (int i = 0; i < studentCount - 1; i++)
	{
		for (int j = 0; j < studentCount - 1 - i; j++)
		{
			if (strcmp(list[j]))
			{
				char* temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}
