#pragma once

#include <stdio.h>
#include<stdlib.h>
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
// 快速排序
// 时间复杂度
// 最好 | 平均 O(n * log(n))  最坏 O(n^2)
// 空间复杂度
// 最好 | 平均 O(log(n)) 最坏 O(n)
// 稳定性：不稳定 Partition 过程中无法保证
// Hover 法
int Parition_1(int array[], int left, int right) {
	int begin = left;
	int end = right;
	// 基准值是 array[right]

	while (begin < end) {
		// 优先走左边
		while (begin < end && array[begin] <= array[right]) {
			begin++;
		}
		// 一定是左边卡住了

		// 再走右边
		while (begin < end && array[end] >= array[right]) {
			end--;
		}
		// 一定是右边也卡住了

		Swap(array + begin, array + end);
	}

	// 区间被分成 小，大，基准
	Swap(array + begin, array + right);

	// 返回当前基准值所在位置
	return begin;
}

// 挖坑法
int Partition_2(int array[], int left, int right) {
	int begin = left, end = right;
	int pivot = array[right];	// 基准值

	while (begin < end) {
		while (begin < end && array[begin] <= pivot) {
			begin++;
		}

		// 右侧坑
		array[end] = array[begin];

		while (begin < end && array[end] >= pivot) {
			end--;
		}

		// 左侧坑
		array[begin] = array[end];
	}

	// [begin] 或 [end]
	array[begin] = pivot;

	return begin;
}

// 前后下标法
int Partition_3(int array[], int left, int right) {
	int d = left;
	for (int i = left; i < right; i++) {
		if (array[i] < array[right]) {
			Swap(array + d, array + i);
			d++;
		}
	}

	Swap(array + d, array + right);

	return d;
}

// 三数取中，返回合适的下标
int PickMid(int array[], int left, int right) {
	int mid = left + (right - left) / 2;
	if (array[left] > array[right] && array[left] > array[mid]) {
		if (array[mid] > array[right]) {
			return mid;
		}
		else {
			return right;
		}
	}
	else if (array[mid] > array[right]) {
		if (array[left] > array[right]) {
			return left;
		}
		else {
			return right;
		}
	}
	else {
		if (array[mid] > array[left]) {
			return mid;
		}
		else {
			return left;
		}
	}
}

// 要排序的区间是 array[left, right]
void __QuickSort(int array[], int left, int right) {
	// 终止条件 size == 0 || size == 1
	// left == right	区间内还剩一个数
	// left > right		区间内没有数
	if (left == right) {
		return;
	}

	if (left > right) {
		return;
	}

	int pivot_index = PickMid(array, left, right);
	Swap(array + pivot_index, array + right);
	int div; // 比基准值小的放基准值左边，大的放右边后，基准值所在的下标
	div = Partition_3(array, left, right);	// 遍历 array[left, right]，把小的放左，大的放右
	__QuickSort(array, left, div - 1);	// 分治解决左边的小区间
	__QuickSort(array, div + 1, right);	// 分治解决右边的小区间
}

//#include <stack>
//void __QuickSortNor(int array[], int left, int right) {
//	std::stack<int>	s;
//	s.push(right);
//	s.push(left);
//
//	int _left;
//	int _right;
//
//	while (!s.empty()) {
//		_left = s.top(); s.pop();
//		_right = s.top(); s.pop();
//
//		if (_left >= _right) {
//			continue;
//		}
//
//		int pivot_index = PickMid(array, left, right);
//		Swap(array + pivot_index, array + right);
//		int d = Partition_2(array, _left, _right);
//
//		// d + 1, right
//		s.push(_right);
//		s.push(d + 1);
//		// _left, d - 1
//		s.push(d - 1);
//		s.push(_left);
//	}
//}

void QuickSort(int array[], int size) {
	__QuickSort(array, 0, size - 1);
}
void Test() {
	int array[] = { 3, 4, 9, 8, 7, 11, 12, 4, 5, 1, 0, 2, 6 };
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	QuickSort(array, size);
	PrintArray(array, size);
}

int main() {
	Test();
	system("pause");
}
