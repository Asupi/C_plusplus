#pragma once
#include "HeapArray.h"

// 顺序表的基础的有部分规则
typedef struct Heap {
	int array[100];
	int size;
}	Heap;

// 初始化
void HeapInit(Heap *heap, int array[], int size) {
	memcpy(heap->array, array, size * sizeof(int));
	heap->size = size;
	CreateHeap(heap->array, size);
}

// 插入
void HeapPush(Heap *heap, int val) {
	heap->array[heap->size++] = val;

	AdjustUp(heap->array, heap->size, heap->size - 1);
}

// 删除
void HeapPop(Heap *heap) {
	heap->array[0] = heap->array[heap->size - 1];
	AdjustDown(heap->array, heap->size - 1, 0);
	heap->size--;
}

// 返回堆顶元素（返回最值）
int HeapTop(Heap *heap) {
	return heap->array[0];
}

void Test() {
	Heap heap;
	int array[] = { 15, 37, 2, 45, 63, 9, 18, 7, 16, 13 };
	int size = sizeof array / sizeof(int);
	HeapInit(&heap, array, size);

	PrintArray(heap.array, heap.size);

	HeapPop(&heap, 1);

	PrintArray(heap.array, heap.size);
}
