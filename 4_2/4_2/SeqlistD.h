#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
#pragma once

typedef int DataType;
typedef unsigned int size_t;
typedef struct SeqlistD
{
	DataType*_array;//�ռ����ʼλ��
	size_t _capacity;//�ײ�ռ�Ĵ�С
	size_t _size; //��ЧԪ�صĸ���
}SeqlistD, *PSeqlistD;

///////////////////////////////////////////
void SeqlistDInit(PSeqlistD sSeq);
void SeqlistDPushBack(PSeqlistD pSeq, DataType data);
void SeqlistDPopBack(PSeqlistD pSeq);
int SeqlistDEmpty(PSeqlistD pSeq);
int SeqlistDSize(PSeqlistD pSeq);
void SeqlistDClear(PSeqlistD pSeq);
int SeqlistDCapacity(PSeqlistD pSeq);
void SeqlistDDestory(PSeqlistD pSeq);//����˳���
int CheckCapacity(PSeqlistD pSeq);
///////////////////////////////////////////
void SeqlistDInit(PSeqlistD pSeq)
{
	if (NULL == pSeq)
		return;

	/*pSeq->_array = NULL;
	pSeq->_capacity = 0;
	pSeq->_size = 0;*/

	pSeq->_array = (DataType*)malloc(3 * sizeof(DataType));
	if (NULL == pSeq->_array)
		return;
	pSeq->_size=0;
	pSeq->_capacity = 3;
}
void SeqlistDPushBack(PSeqlistD pSeq, DataType data)
{
	if (NULL == pSeq)
		return;
	if (!CheckCapacity(pSeq))
		return;
	pSeq->_array[pSeq->_size++] = data;//����Ԫ��
	
}


int CheckCapacity(PSeqlistD pSeq)
{
	if (NULL == pSeq)
		return;
	if (pSeq->_size == pSeq->_capacity)
	{
		//����
		size_t newCapacity = pSeq->_capacity * 2;
		DataType* pTemp = (DataType*)malloc(newCapacity*sizeof(DataType));
		if (NULL == pTemp)
			return 0;

		//���ɿռ�Ԫ�ذ��Ƶ��¿ռ�
		memcpy(pTemp, pSeq->_array, pSeq->_size*sizeof(DataType));

		//�ͷžɿռ�
		free(pSeq->_array);

		pSeq->_array = pTemp;
		pSeq->_capacity = newCapacity;
	}
	return 1;

}
void SeqlistDPopBack(PSeqlistD pSeq)
{
	if (SeqlistDEmpty(pSeq))
		return;
	pSeq->_size--;
}

int SeqlistDEmpty(PSeqlistD pSeq)
{
	return 0 == pSeq->_size;
}
int SeqlistDSize(PSeqlistD pSeq)
{
	return pSeq->_size;
}
int SeqlistDCapacity(PSeqlistD pSeq)
{
	return pSeq->_capacity;
}
void SeqlistDClear(PSeqlistD pSeq)
{
	pSeq->_size = 0;
}
void SeqlistDDestory(PSeqlistD pSeq)
{
	if (pSeq->_array)
	{
		free(pSeq->_array);
		pSeq->_capacity = 0;
		pSeq->_size = 0;
	}
}
void PrintSeqlistD(PSeqlistD pSeq)
{
	size_t i = 0;
	for (; i < pSeq->_size; ++i)
	{
		printf("%d ", pSeq->_array[i]);
	}
	printf("\n");
}
void TestSeqlistD()
{
	SeqlistD s;
	SeqlistDInit(&s);
	SeqlistDPushBack(&s, 1);
	SeqlistDPushBack(&s, 2);
	SeqlistDPushBack(&s, 3);
	PrintSeqlistD(&s);
	printf("size=%d\n", SeqlistDSize(&s));
	printf("capacity=%d\n", SeqlistDCapacity(&s));

	SeqlistDPushBack(&s, 4);
	printf("size=%d\n", SeqlistDSize(&s));
	printf("capacity=%d\n", SeqlistDCapacity(&s));

	SeqlistDPopBack(&s);
	printf("size=%d\n", SeqlistDSize(&s));
	printf("capacity=%d\n", SeqlistDCapacity(&s));

	SeqlistDClear(&s);
	printf("size=%d\n", SeqlistDSize(&s));
	printf("capacity=%d\n", SeqlistDCapacity(&s));

	SeqlistDDestory(&s);
}