#pragma once

#include <stdio.h>

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}



// 归并排序
// 时间复杂度
// 最好 | 平均 | 最坏	O(n * log(n))
// 空间复杂度 O(n)
// 稳定性: 稳定
// 外部排序（可以对硬盘的数据进行归并）

// 合并两个有序数组
// array[left, mid)
// array[mid, right)
// 时间复杂度 O(n)
// 空间复杂度 O(n)
void Merge(int array[], int left, int mid, int right, int *extra) {
	int size = right - left;

	int left_index = left;
	int right_index = mid;
	int extra_index = 0;

	while (left_index < mid && right_index < right) {
		if (array[left_index] <= array[right_index]) {
			extra[extra_index] = array[left_index];
			left_index++;
		}
		else {
			extra[extra_index] = array[right_index];
			right_index++;
		}
		extra_index++;
	}

	while (left_index < mid) {
		extra[extra_index++] = array[left_index++];
	}

	while (right_index < right) {
		extra[extra_index++] = array[right_index++];
	}

	for (int i = 0; i < size; i++) {
		array[left + i] = extra[i];
	}
}

// 区间是 array[left, right)
// 左闭右开的区间
void __MergeSort(int array[], int left, int right, int *extra) {
	if (right == left + 1) {
		// 区间内还剩一个数
		// 有序
		return;
	}

	if (left >= right) {
		// 区间内没有数
		return;
	}

	int mid = left + (right - left) / 2;
	// 区间被分成左右两个小区间
	// [left, mid)
	// [mid, right)
	// 先把左右两个小区间进行排序，分治算法，递归解决
	__MergeSort(array, left, mid, extra);
	__MergeSort(array, mid, right, extra);

	// 左右两个小区间已经有序了
	// 合并两个有序数组
	Merge(array, left, mid, right, extra);
}

void MergeSort(int array[], int size) {
	int *extra = (int *)malloc(sizeof(int)* size);
	__MergeSort(array, 0, size, extra);
	free(extra);
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

void Test() {
	int array[] = { 3, 4, 9, 8, 7, 11, 12, 4, 5, 1, 0, 2, 6 };
	//int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	//int array[] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//int array[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	//MergeSortNor(array, size);
	MergeSort(array, size);
	PrintArray(array, size);
}



int main() {
	Test();
	system("pause");
}