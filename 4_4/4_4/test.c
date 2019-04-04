#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
void SelectSort_OP(int *array,int size)

{
	int begin = 0;
	int end = size - 1;
	int maxPos = 0;
	int minPos = 0;
	while (begin<end)
	{
		maxPos = begin;
		minPos = begin;
		int j = begin + 1;
		while (j <= end)
		{
			if (array[maxPos]<array[j])
				maxPos = j;
			if (array[minPos]>array[j])
				minPos = j;
			j++;
		}
		if (maxPos != end)
			Swap(&array[maxPos], &array[end]);
		if (minPos == end)
			minPos = maxPos;
		if (minPos != end)
			Swap(&array[minPos], &array[begin]);
		begin++;
		end--;
	}
}
