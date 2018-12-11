/*
Задача
Генерируем массив случайных чисел размера N типа int arr[N]
Задается числа int value
В массиве надо посчитать количество пар элементов, в сумме дающих value (один элемент сам с собой не складывать!)
вкладываем цикл в цикл
число проходок N*(N-1) = N^2-N
-N можно пренебречь
Парабола.
Оценка сложности О(N^2)
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 256

int main()
{
	int arr[N];
	int value = 50;
	int count = 0;

	srand(time(0));
	for (int i = 0; i < N; i++)
		arr[i] = rand() % 100;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
			if (arr[i] + arr[j] == value)
				count++;
	}
	printf("%d\n", count);


	return 0;
}