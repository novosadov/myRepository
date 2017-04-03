#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <locale.h>


/*
Написать программу, которая дает пользователю вести домашнюю бухгалтерию. В начале
программа спрашивает текущий баланс счета. Затем программа выводит меню:
1. Снять со счета
2. Положить на счет
3. Вывести на экран список транзакций
4. Вывести баланс
5. Выход
Сумма вводится как вещественное число (BYN). К каждой транзакции можно писать
комментарий с указанием типа/содержания транзакции.
Используйте структуры и динамические массивы.
*/



struct Transaction
{
	float Summ;
	char* To;
	char* Reason;
};

enum Operation
{
	Exit = 0,
	Add,
	Pay,
	PrintTransactions,
	PrintTotal
};

enum Operation getOperation()
{
	printf("==== Меню ====\n");
	printf("1. Внести деньги\n");
	printf("2. Снять деньги\n");
	printf("3. Печать транзакций\n");
	printf("4. Баланс\n");
	printf("0. Выход\n\n");

	enum Operation result;
	scanf("%i", &result);

	return result;
}


void addTransaction(struct Transaction* const transations,
	int* const transactionsCount, float summ,
	char* to, char* reason);


void payTransaction(struct Transaction* const transations,
	int* const transactionsCount, float summ,
	char* to, char* reason);

void printTransactions(struct Transaction* const transations,
	int* const transactionsCount);

void printTotal(struct Transaction* const transations,
	int* const transactionsCount);

void operation();



void main()
{
	setlocale(LC_ALL, "rus");

	struct Transaction* transations =
		calloc(50, sizeof(struct Transaction));
	int transationsCount = 0;

	float money;
	printf("Введите начальный баланс: ");
	scanf("%f", &money);
	addTransaction(transations, &transationsCount, money,
		NULL, NULL);

	while (true)
	{
		enum Operation operation = getOperation();
		switch (operation)
		{
		case Exit:
			return;
			break;
		case Add:
			printf("Введите сумму: ");
			scanf("%f", &money);
			addTransaction(transations, &transationsCount, money,
				NULL, NULL);
			break;
		case Pay:
			printf("Введите сумму: ");
			scanf("%f", &money);
			payTransaction(transations, &transationsCount, money,
				NULL, NULL);
			break;
		case PrintTransactions:
			printTransactions(transations, &transationsCount);
			break;
		case PrintTotal:
			printTotal(transations, &transationsCount);
			break;
		default:
			break;
		}
	}
}




void addTransaction(struct Transaction* const transations,
	int* const transactionsCount, float summ,
	char* to, char* reason)
{
	transations[*transactionsCount].Summ = summ;
	if (to != NULL)
	{
		transations[*transactionsCount].To = calloc(1, 100);
		strcpy(transations[*transactionsCount].To,
			to);
	}
	if (reason != NULL)
	{
		transations[*transactionsCount].Reason = calloc(1, 50);
		strcpy(transations[*transactionsCount].Reason,
			reason);
	}

	(*transactionsCount)++;
}


void payTransaction(struct Transaction* const transations,
	int* const transactionsCount, float summ,
	char* to, char* reason)
{
	transations[*transactionsCount].Summ = -summ;
	if (to != NULL)
	{
		transations[*transactionsCount].To = calloc(1, 100);
		strcpy(transations[*transactionsCount].To,
			to);
	}
	if (reason != NULL)
	{
		transations[*transactionsCount].Reason = calloc(1, 50);
		strcpy(transations[*transactionsCount].Reason,
			reason);
	}

	(*transactionsCount)++;
}


void printTransactions(struct Transaction* const transations,
	int* const transactionsCount)
{
	printf("Сумма\t| Куда\t| Назначение платежа\n");
	for (int i = 0; i < *transactionsCount; i++)
	{
		printf("%.2f\t| %s\t| %s\n", transations[i].Summ,
			transations[i].To ? transations[i].To : "-",
			transations[i].Reason ? transations[i].Reason : "-");
	}
}


void printTotal(struct Transaction* const transations,
	int* const transactionsCount)
{
	float summ = 0;
	printf("\n");
	for (int i = 0; i < *transactionsCount; i++)
	{
		summ = transations[i].Summ + transations[i - 1].Summ;

	}
	printf("%.2f\n", summ);
}



