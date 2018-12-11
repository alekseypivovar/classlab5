/*
������
���������� ������ ��������� ����� ������� N ���� int arr[N]
�������� ����� int value
� ������� ���� ��������� ���������� ��� ���������, � ����� ������ value (���� ������� ��� � ����� �� ����������!)

�������� ������������� �� �����������

���� ���� �������� ������� �������� � ����� ������ while(left<right)
� ������ �������� �������� � ��������� �������
�������� �������� ����� ��� ���� � �������� ������ ����� ���� ��� ��������
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
	int insert;
	int j;

	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		insert = rand() % 100;
		j = i - 1;
		while (j >= 0 && arr[j]>insert)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = insert;
	}
	
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		if (arr[i] + arr[j] == value)
			count++;
	}
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	putchar('\n');
	printf("%d\t", count);
	putchar('\n');


	return 0;
}