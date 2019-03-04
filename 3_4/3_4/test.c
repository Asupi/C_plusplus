//����ϲ������
//����������

// ������
// N * logN
// ���ȶ�
void AdjustDown(int array[], int size, int root) {
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (left >= size) {
		// Խ���ˣ�û�����ӣ���û���Һ���
		// root ��Ҷ��
		return;
	}

	// ȷ��˭�Ǵ�ĺ���
	int max = left;
	if (right < size /* ���Һ��� */ && array[right] > array[left]) {
		max = right;
	}

	// ����������ĺ��Ӵ�
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
		// ������һ���� array[0]
		// �����������������ȥ
		int t = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = t;

		// ǰ�沿�֣�ֻ�� array[0] ������ѵ�����
		AdjustDown(array, size - 1 - i, 0);
	}
}
