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
void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
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

	int mid = left + ((right - left)>>1);
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


int main()
{
	int array[] = {  6, 3, 2, 4, 9, 8, 7, 15, 49 };
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	MergeSort(array, size);
	PrintArray(array, size);

	system("pause");
	return 0;
}
