#pragma once
#include<stdio.h>

void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void AdjustDown(int array[], int size, int root)
{
	int i = 2 * root + 1;
	int j = 2 * root + 2;
	if (i >=size)
	{
		return;
	}
	int max = i;
	if  (j < size&&array[j]>array[i])
	{
		max = j;
	}
	if (array[max] < array[root])
	{
		return;
	}
	Swap(array + max, array + root);
	AdjustDown(array, size, max);
}
void CreatHeap(int array[], int size)
{
	for (int i = (size-2)/2; i >= 0; i--)
	{
		AdjustDown(array, size,i );
	}
}

void HeapSort(int array[], int size)
{
	CreatHeap(array, size);

	for (int i = 0; i < size; i++)
	{
		Swap(array,array + size - i - 1);
		AdjustDown(array, size - 1 - i,0 );
	}
}
int main()
{
	int array[] = { 0, 5, 7, 6, 4, 3, 9, 8, 2, 1 };
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	HeapSort(array, size);
	PrintArray(array, size);
	system("pause");
	return 0;
}
