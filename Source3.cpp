/*
������
���������� ������ ��������� ����� ������� N ���� int arr[N]
�������� ����� int value
� ������� ���� ��������� ���������� ��� ���������, � ����� ������ value (���� ������� ��� � ����� �� ����������!)
���������� ���� � ����
����� �������� N*(N-1) = N^2-N
-N ����� ����������
��������.
������ ��������� �(N^2)
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