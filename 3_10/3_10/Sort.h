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
// ��������
// ʱ�临�Ӷ�
// ��� | ƽ�� O(n * log(n))  � O(n^2)
// �ռ临�Ӷ�
// ��� | ƽ�� O(log(n)) � O(n)
// �ȶ��ԣ����ȶ� Partition �������޷���֤
// Hover ��
int Parition_1(int array[], int left, int right) {
	int begin = left;
	int end = right;
	// ��׼ֵ�� array[right]

	while (begin < end) {
		// ���������
		while (begin < end && array[begin] <= array[right]) {
			begin++;
		}
		// һ������߿�ס��

		// �����ұ�
		while (begin < end && array[end] >= array[right]) {
			end--;
		}
		// һ�����ұ�Ҳ��ס��

		Swap(array + begin, array + end);
	}

	// ���䱻�ֳ� С���󣬻�׼
	Swap(array + begin, array + right);

	// ���ص�ǰ��׼ֵ����λ��
	return begin;
}

// �ڿӷ�
int Partition_2(int array[], int left, int right) {
	int begin = left, end = right;
	int pivot = array[right];	// ��׼ֵ

	while (begin < end) {
		while (begin < end && array[begin] <= pivot) {
			begin++;
		}

		// �Ҳ��
		array[end] = array[begin];

		while (begin < end && array[end] >= pivot) {
			end--;
		}

		// ����
		array[begin] = array[end];
	}

	// [begin] �� [end]
	array[begin] = pivot;

	return begin;
}

// ǰ���±귨
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

// ����ȡ�У����غ��ʵ��±�
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

// Ҫ����������� array[left, right]
void __QuickSort(int array[], int left, int right) {
	// ��ֹ���� size == 0 || size == 1
	// left == right	�����ڻ�ʣһ����
	// left > right		������û����
	if (left == right) {
		return;
	}

	if (left > right) {
		return;
	}

	int pivot_index = PickMid(array, left, right);
	Swap(array + pivot_index, array + right);
	int div; // �Ȼ�׼ֵС�ķŻ�׼ֵ��ߣ���ķ��ұߺ󣬻�׼ֵ���ڵ��±�
	div = Partition_3(array, left, right);	// ���� array[left, right]����С�ķ��󣬴�ķ���
	__QuickSort(array, left, div - 1);	// ���ν����ߵ�С����
	__QuickSort(array, div + 1, right);	// ���ν���ұߵ�С����
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
