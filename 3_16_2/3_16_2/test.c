
#pragma once

#include <stdio.h>

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}


//将数组 array[left,mid] 与 array(mid,right] 合并（归并）
void Merge(int array[], int left, int mid, int right, int *extra)
{
	int size = right - left;

	int left_index = left;
	int right_index = mid;
	int extra_index = 0;

	while (left_index < mid && right_index < right)//数组array[left,mid]与数组(mid,right]均没有全部归入数组temp中去
	{
		if (array[left_index] <= array[right_index])//如果array[left_index]小于等于array[right_index]
		{
			extra[extra_index++] = array[left_index++];//则将array[left_index]的值赋给extra[extra_index]，之后left_index和extra_index各加一，表示后移一位

		}
		else
		{
			extra[extra_index++] = array[right_index++];//否则将array[right_index]的值赋给extra[extra_index]，之后right_index和extra_index各加一，表示后移一位

		}

	}

	while (left_index < mid)//表示数组a(mid,right]已经全部归入extra数组中去了，而数组array[left,mid]还有剩余
	{
		extra[extra_index++] = array[left_index++];//将数组array[left,mid]剩下的值，逐一归入数组extra
	}

	while (right_index < right) //表示数组array[left,mid]已经全部归入extra数组中去了，而数组array[mid,right]还有剩余
	{
		extra[extra_index++] = array[right_index++];//将数组array[mid,right]剩下的值，逐一归入数组extra
	}

	for (int i = 0; i < size; i++) //将归并后的数组的值逐一赋给数组array[left,right]
	{
		array[left + i] = extra[i];  //注意，应从a[left+i]开始赋值
	}

}

void MergeSortNor(int array[], int size) {
	int *extra = (int *)malloc(sizeof(int)* size);
	for (int i = 1; i < size; i *= 2) {
		for (int j = 0; j < size; j += 2 * i) {
			int left = j;
			int mid = left + i;
			if (mid >= size) {
				continue;
			}

			int right = mid + i;
			if (right > size) {
				right = size;
			}

			Merge(array, left, mid, right, extra);
		}
	}
	free(extra);
}

int main() {
	
	int array[] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	MergeSortNor(array, size);
	PrintArray(array, size);
	system("pause");
	return 0;
}
