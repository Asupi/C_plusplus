
#pragma once
#include <stdio.h>

void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void InsertSortGap(int array[], int size, int gap)
{
	for ( int i = gap; i < size; i++)
	{
		int key = array[i];
		int j ;
		for (j = i - gap; j >= 0 && array[j]>key; j -= gap)
		{
			array[j + gap] = array[j];
		}
		array[j + gap] = key;
	}
}
void ShellSort(int array[], int size)
{
	int gap = size;
	while (1)
	{
		gap = (gap / 3) + 1;
		InsertSortGap(array, size, gap);
		if (gap == 1)
		{
			return;
		}
	}
}

void SelectSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int max = 0;
		for (int j = 1; j <size - i; j++)
		{	
			if (array[j]>array[max])
			{
				max = j;
			}
			Swap(array + max, array + size - 1 - i);
		}
		
	}
	
}
void Test()
{
	int array[] = { 6, 4, 5, 3, 2, 8, 9, 1 ,9,7,13,15};
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	SelectSort(array, size);
	PrintArray(array, size);

}
int main()
{
	Test();
	system("pause");
	return 0;
}
