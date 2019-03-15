#pragma once
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

//冒泡排序
void BubbleSort(int array[], int size)
{
	int end = size;
	while (end - 1 > 0)
	{
		for (int i = 1; i < end; ++i)
		{
			if (array[i -1]>array[i])
			{
				Swap(array + i - 1, array + i);
			}
		}
		end--;
	}
}


//快速排序
// Hover 法
int PartSort1(int array[], int left, int right)
{
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end&&array[begin] <= array[right])
		{
			begin++;
		}
		while (begin < end&&array[end] >= array[right])
		{
			end--;
		}
		Swap(array + begin, array + end);
	}
	Swap(array + begin, array + right);
	return begin;
}
// 挖坑法
int PartSort2(int array[], int left, int right)
{
	int begin = left,  end = right;
	int key = array[right];
	while (begin < end)
	{
		while (begin < end&&array[begin] <= key)
		{
			begin++;
		}
		array[end] = array[begin];
		while (begin < end&&array[end] >= key)
		{
			end--;
		}
		array[begin] = array[end];
	}
	array[begin] = key;//或者end
	return begin;
}
//前后下标
int PartSort3(int array[], int left, int right)
{


	int mid = GetMidIndex(array, left, right);//mid的嵌套
	Swap(array + mid, array + right);


	int prev = left - 1;
	int cur = left;
	int key = array[right];
	while (cur < right)
	{
		if(array[cur] < key && prev++ != cur)
		
			Swap(array + cur, array + prev);
		
		cur++;
	}
	Swap(array + (++prev), array + right);
	return prev;
}

//三数取中法，可以提高快排的效率
int GetMidIndex(int array[], int left, int right)
{
	int mid = left + (right - left) / 2;
	if (array[left] < array[mid])
	{
		if (array[mid] < array[right])
			return mid;
		else if (right < left)//left<mid&&mid>right
			return left;
		else
			return right;
	}
	else //mid<left
	if (array[left] < array[right])
		return left;
	else if (array[mid] < array[right])//mid<left&&left>right
		return right;
	else
		return left;
}

void _QuickSort(int array[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int div = PartSort3(array, left,right);
	_QuickSort(array, left, div - 1);
	_QuickSort(array, div + 1, right);
}

//补充参数
void QuickSort(int array[], int size)
{
	_QuickSort(array, 0, size - 1);
}

int main()
{
	int array[] = { 3, 6, 7, 2, 5, 4, 6, 15, 25 };
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	//BubbleSort(array, size);
	QuickSort(array, size);
	PrintArray(array, size);

	system("pause");
	return 0;
}