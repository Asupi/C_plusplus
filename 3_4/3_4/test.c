//张敏喜欢高兴
//张敏爱高兴

// 堆排序
// N * logN
// 不稳定
void AdjustDown(int array[], int size, int root) {
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (left >= size) {
		// 越界了，没有左孩子，就没有右孩子
		// root 是叶子
		return;
	}

	// 确定谁是大的孩子
	int max = left;
	if (right < size /* 有右孩子 */ && array[right] > array[left]) {
		max = right;
	}

	// 如果根比最大的孩子大
	if (array[root] > array[max]) {
		return;
	}

	int t = array[root];
	array[root] = array[max];
	array[max] = t;

	AdjustDown(array, size, max);
}

void CreateHeap(int array[], int size) {
	for (int i = (size - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(array, size, i);
	}
}


void HeapSort(int array[], int size) {
	CreateHeap(array, size);

	for (int i = 0; i < size; i++) {
		// 最大的数一定在 array[0]
		// 把最大的数交换到最后去
		int t = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = t;

		// 前面部分，只有 array[0] 不满足堆的性质
		AdjustDown(array, size - 1 - i, 0);
	}
}
