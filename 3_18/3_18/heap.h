#pragma once
#include "HeapArray.h"

// ˳���Ļ������в��ֹ���
typedef struct Heap {
	int array[100];
	int size;
}	Heap;

// ��ʼ��
void HeapInit(Heap *heap, int array[], int size) {
	memcpy(heap->array, array, size * sizeof(int));
	heap->size = size;
	CreateHeap(heap->array, size);
}

// ����
void HeapPush(Heap *heap, int val) {
	heap->array[heap->size++] = val;

	AdjustUp(heap->array, heap->size, heap->size - 1);
}

// ɾ��
void HeapPop(Heap *heap) {
	heap->array[0] = heap->array[heap->size - 1];
	AdjustDown(heap->array, heap->size - 1, 0);
	heap->size--;
}

// ���ضѶ�Ԫ�أ�������ֵ��
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
