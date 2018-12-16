/*
Задача
Генерируем массив случайных чисел размера N типа int arr[N]
Задается числа int value
В массиве надо посчитать количество пар элементов, в сумме дающих value (один элемент сам с собой не складывать!)

Значения упорядочиваем по возрастанию

Дома надо запилить вариант подсчета с одним циклом while(left<right)
И всякие считалки выкинуть в отдельную функцию
Оставить считалку через два фора и добавить вторую через вайл шоб сравнить
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#define N 50000
unsigned long iter1 = 0;
unsigned long iter2 = 0;

int count2(int *arr,int size, int value)
{
	int left = 0, right = size - 1;
	int count = 0;
	
	
	while (left < right)
	{
		iter2++;
		if (arr[left] + arr[right]>value)
		{
			right--;
			left = 0;
		}
		else if (arr[left] + arr[right] < value)
			left++;
		else
		{
			count++;
			if (left == right - 1)
			{
				right--;
				left = 0;
			}
			else
			{
				left++;
			}
		}
		
	}
	return count;
}

int main()
{
	int arr[N];
	int value = 50;
	int size = 0;
	int count = 0;
	int insert;
	int j;
	srand(time(0));

	FILE *fp = fopen("data.xls", "w");
	if (fp == NULL)
	{
		puts("File error");
		return 1;
	}

	for (size = 1000; size < N; size += 1000)
	{
		
		clock_t t1, t2, t3, t4;
		t1 = clock();



		for (int i = 0; i < size; i++)
		{
			insert = rand() % 100;
			j = i - 1;
			while (j >= 0 && arr[j]>insert)
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = insert;
		}
		t2 = clock();
		int b = 0;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				iter1++;

				if (arr[i] + arr[j] == value)
					count++;
			}
		}

	//	for (int i = 0; i < size; i++)
		//	printf("%d ", arr[i]);
		//putchar('\n');
		//printf("%d\t", count);
		//printf("%lu\n", iter1);
		//putchar('\n');
		t3 = clock();
		//printf("%d\t", count2(arr, size, value));
		count2(arr, size, value);
		//printf("%lu\n", iter2);
		//putchar('\n');
		t4 = clock();

		fprintf(fp,"%lu\t%.3f\t%.3f\t%.3f\t\n", size,
								(double)(t2 - t1) / CLOCKS_PER_SEC,
								(double)(t3 - t2) / CLOCKS_PER_SEC,
								(double)(t4 - t3) / CLOCKS_PER_SEC);
	}

	return 0;
}