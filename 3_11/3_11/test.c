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



// �鲢����
// ʱ�临�Ӷ�
// ��� | ƽ�� | �	O(n * log(n))
// �ռ临�Ӷ� O(n)
// �ȶ���: �ȶ�
// �ⲿ���򣨿��Զ�Ӳ�̵����ݽ��й鲢��

// �ϲ�������������
// array[left, mid)
// array[mid, right)
// ʱ�临�Ӷ� O(n)
// �ռ临�Ӷ� O(n)
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

// ������ array[left, right)
// ����ҿ�������
void __MergeSort(int array[], int left, int right, int *extra) {
	if (right == left + 1) {
		// �����ڻ�ʣһ����
		// ����
		return;
	}

	if (left >= right) {
		// ������û����
		return;
	}

	int mid = left + (right - left) / 2;
	// ���䱻�ֳ���������С����
	// [left, mid)
	// [mid, right)
	// �Ȱ���������С����������򣬷����㷨���ݹ���
	__MergeSort(array, left, mid, extra);
	__MergeSort(array, mid, right, extra);

	// ��������С�����Ѿ�������
	// �ϲ�������������
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