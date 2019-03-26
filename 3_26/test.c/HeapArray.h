#pragma once

#include <stdio.h>

/*
向下调整
array 数组的开始位置
size  数组的长度
root  要调整的结点的下标
*/
void AdjustDown(int array[], int size, int root)
{
	while (1) {
		// 判断 root 是否是叶子结点
		// 因为 堆是完全二叉树，所有没有左孩子一定没有右孩子
		// 又因为堆是顺序存储的
		// 所以，找到左孩子的下标，如果左孩子的下标越界了，则没有左孩子
		int left = 2 * root + 1;
		if (left >= size) {	// 不要漏掉 ==
			// 是叶子结点
			return;
		}

		// 找到左右孩子最小的一个
		// 这里一定有左孩子，判断是否有右孩子
		int right = 2 * root + 2;
		int min = left;
		if (right < size // 有右孩子
			&& array[right] > array[left]) {	/* 右孩子的值小于左孩子*/
			min = right;
		}

		// 比较 array[min]	array[root]
		if (array[root] >= array[min]) {
			return;
		}

		// 交换值
		int t = array[root];
		array[root] = array[min];
		array[min] = t;

		// 需要继续向下调整，以 min 作为结点
		root = min;
	}
}

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}


// 精确的是 O(n)
// 粗略看成 O(nlogn)
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
向上调整
array 数组
size  数组长度
child 要向上调整的结点下标

1. 比不过 parent
2. 已经登基了
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

// 堆排序
// 升序，建大堆
// O(n logn)
void HeapSort(int array[], int size) {
	CreateHeap(array, size);		// n * logn

	// i 表示被找出的最大的数的个数
	for (int i = 0; i < size - 1; i++) {	// 循环 n 次
		// 每次循环，会找出最大的一个数放到最后

		// O(1)
		int t = array[0];
		array[0] = array[size - i - 1];
		array[size - i - 1] = t;

		// 进行向下调整，数据规模是 size - 1 - i
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
类似伪代码，实际中，size 是海量的，内存中是放不下的，需要借助文件操作
*/
void TopK(int array[], int size, int k) {
	int *heap = (int *)malloc(sizeof(int)* k);
	for (int i = 0; i < k; i++) {
		heap[i] = array[i];
	}

	// 针对 heap 建小堆
	CreateHeap(heap, k);

	for (int j = k; j < size; j++) {
		if (array[j] > heap[0]) {
			heap[0] = array[j];
			AdjustDown(heap, k, 0);
		}
	}
}