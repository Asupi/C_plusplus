
#pragma once
#include<stdio.h>
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++){
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
//²åÈëÅÅÐò
void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = array[i];
		int j = i - 1;
		for (; j >= 0 && array[j]>key; j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = key;
	}
}
void Test() {
	int array[] = { 3, 4, 9, 8, 7, 11, 12, 4, 5, 1, 0, 2, 6 };
	//int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	//int array[] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//int array[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	InsertSort(array, size);
	PrintArray(array, size);
}
int main()
{
	Test();
	system("pause");
	return 0;
}