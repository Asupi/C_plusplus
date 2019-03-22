#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void vPrintArr(int array[], int n){
	int i = 0;
	for (i = 0; i<n; i++) {
		printf("%d,", array[i]);
	}
	printf("\n");
}

void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size; i++) {
		int sorted = 1;
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				Swap(array + j, array + j + 1);
				sorted = 0;
			}
		}
		if (sorted == 1) {
			return;
		}
	}
}
int BinarySearch(int array[], int size, int value)
{
	int left = 0;
	int right = size;

	while (left < right){
		int mid = (right - left) / 2 + left;

		if (array[mid] == value)
			return mid;
		else if (array[mid]>value)
			right = mid;
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = 9, value = 1;

	printf("%d BinarySearch\n", BinarySearch(array, size, value));
	system("pause");
	return 0;
}

