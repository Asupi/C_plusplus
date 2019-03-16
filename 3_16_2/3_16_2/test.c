
#pragma once

#include <stdio.h>

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}


//������ array[left,mid] �� array(mid,right] �ϲ����鲢��
void Merge(int array[], int left, int mid, int right, int *extra)
{
	int size = right - left;

	int left_index = left;
	int right_index = mid;
	int extra_index = 0;

	while (left_index < mid && right_index < right)//����array[left,mid]������(mid,right]��û��ȫ����������temp��ȥ
	{
		if (array[left_index] <= array[right_index])//���array[left_index]С�ڵ���array[right_index]
		{
			extra[extra_index++] = array[left_index++];//��array[left_index]��ֵ����extra[extra_index]��֮��left_index��extra_index����һ����ʾ����һλ

		}
		else
		{
			extra[extra_index++] = array[right_index++];//����array[right_index]��ֵ����extra[extra_index]��֮��right_index��extra_index����һ����ʾ����һλ

		}

	}

	while (left_index < mid)//��ʾ����a(mid,right]�Ѿ�ȫ������extra������ȥ�ˣ�������array[left,mid]����ʣ��
	{
		extra[extra_index++] = array[left_index++];//������array[left,mid]ʣ�µ�ֵ����һ��������extra
	}

	while (right_index < right) //��ʾ����array[left,mid]�Ѿ�ȫ������extra������ȥ�ˣ�������array[mid,right]����ʣ��
	{
		extra[extra_index++] = array[right_index++];//������array[mid,right]ʣ�µ�ֵ����һ��������extra
	}

	for (int i = 0; i < size; i++) //���鲢��������ֵ��һ��������array[left,right]
	{
		array[left + i] = extra[i];  //ע�⣬Ӧ��a[left+i]��ʼ��ֵ
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
