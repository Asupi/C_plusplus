#pragma once

#include <stdio.h>

/*
���µ���
array ����Ŀ�ʼλ��
size  ����ĳ���
root  Ҫ�����Ľ����±�
*/
void AdjustDown(int array[], int size, int root)
{
	while (1) {
		// �ж� root �Ƿ���Ҷ�ӽ��
		// ��Ϊ ������ȫ������������û������һ��û���Һ���
		// ����Ϊ����˳��洢��
		// ���ԣ��ҵ����ӵ��±꣬������ӵ��±�Խ���ˣ���û������
		int left = 2 * root + 1;
		if (left >= size) {	// ��Ҫ©�� ==
			// ��Ҷ�ӽ��
			return;
		}

		// �ҵ����Һ�����С��һ��
		// ����һ�������ӣ��ж��Ƿ����Һ���
		int right = 2 * root + 2;
		int min = left;
		if (right < size // ���Һ���
			&& array[right] > array[left]) {	/* �Һ��ӵ�ֵС������*/
			min = right;
		}

		// �Ƚ� array[min]	array[root]
		if (array[root] >= array[min]) {
			return;
		}

		// ����ֵ
		int t = array[root];
		array[root] = array[min];
		array[min] = t;

		// ��Ҫ�������µ������� min ��Ϊ���
		root = min;
	}
}

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}


// ��ȷ���� O(n)
// ���Կ��� O(nlogn)
void CreateHeap(int array[], int size) {
	for (int i = (size - 2) / 2; i >= 0; i--) {
		AdjustDown(array, size, i);
	}
}

void TestAdjustDown()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int size = sizeof array / sizeof(int);

	PrintArray(array, size);

	AdjustDown(array, size, 0);
	PrintArray(array, size);


}


void TestCreateHeap() {
	int array[] = { 15, 37, 2, 45, 63, 9, 18, 7, 16, 13 };
	int size = sizeof array / sizeof(int);

	CreateHeap(array, size);

	PrintArray(array, size);
}


/*
���ϵ���
array ����
size  ���鳤��
child Ҫ���ϵ����Ľ���±�

1. �Ȳ��� parent
2. �Ѿ��ǻ���
*/
void AdjustUp(int array[], int size, int child) {
	while (child != 0) {
		int parent = (child - 1) / 2;
		if (array[parent] >= array[child]) {
			return;
		}

		int t = array[parent];
		array[parent] = array[child];
		array[child] = t;

		child = parent;
	}
}

// ������
// ���򣬽����
// O(n logn)
void HeapSort(int array[], int size) {
	CreateHeap(array, size);		// n * logn

	// i ��ʾ���ҳ����������ĸ���
	for (int i = 0; i < size - 1; i++) {	// ѭ�� n ��
		// ÿ��ѭ�������ҳ�����һ�����ŵ����

		// O(1)
		int t = array[0];
		array[0] = array[size - i - 1];
		array[size - i - 1] = t;

		// �������µ��������ݹ�ģ�� size - 1 - i
		AdjustDown(array, size - i - 1, 0);	// logn
	}
}

void TestHeapSort() {
	int array[] = { 39, 129, 12, 38, 27, 9, 33, 2, 14 };
	int size = sizeof array / sizeof(int);

	HeapSort(array, size);

	PrintArray(array, size);
}

void BubbleSort(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int sorted = 1;
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				int t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;

				sorted = 0;
			}
		}

		if (sorted == 1) {
			break;
		}
	}
}

#define SIZE	200000

void TestSortSpeed() {
	srand(20190104);

	int array[SIZE];

	for (int i = 0; i < SIZE; i++) {
		array[i] = rand() % 10 * 10000;
	}

	int s = time();
	BubbleSort(array, SIZE);
	int e = time();

	printf("%d\n", e - s);
}



/*
����α���룬ʵ���У�size �Ǻ����ģ��ڴ����ǷŲ��µģ���Ҫ�����ļ�����
*/
void TopK(int array[], int size, int k) {
	int *heap = (int *)malloc(sizeof(int)* k);
	for (int i = 0; i < k; i++) {
		heap[i] = array[i];
	}

	// ��� heap ��С��
	CreateHeap(heap, k);

	for (int j = k; j < size; j++) {
		if (array[j] > heap[0]) {
			heap[0] = array[j];
			AdjustDown(heap, k, 0);
		}
	}
}