




#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#pragma once

typedef int Datatype;

typedef struct Node
{
	struct Node* _pNext;
	Datatype _data;//ֵ��
} Node, *PNode;


#define NULL 0
///////////////����ͷ���ĵ�����//////////////////////////
void SListInit(PNode* pHead);

void SListPushBack(PNode* pHead, Datatype data);
void SListPopBack(PNode* pHead);
PNode BuySListNode(Datatype data);


///////////////////////////////////////////////
void SListInit(PNode* pHead)//�ı��ⲿʵ�ε�ָ�����Դ����Ƕ���ָ��
{
	assert(pHead);
	*pHead=NULL;
	
}
void SListPushBack(PNode* pHead, Datatype data)
{
	PNode pNewNode = NULL;

	//��������Ҫ�ı�pHeadָ��
	assert(pHead);

	pNewNode = BuySListNode(data);
	if (NULL == *pHead)
		*pHead =pNewNode ;
	else
	{
		//�ǿ�������Ҫ�ı�pHeadָ��
		PNode pCur = *pHead;
		while (pCur->_pNext)
			pCur = pCur->_pNext;

		pCur->_pNext = pNewNode;

	}
}
void SListPopBack(PNode* pHead)
{
	assert(pHead);
	//������
	if (NULL == *pHead)
		return;
	else if (NULL == (*pHead)->_pNext)
	{
		//ֻ��һ���ڵ�
		free(*pHead);
		*pHead = NULL;
	}
	//�ж���ڵ�
	else
	{
		PNode pCur = *pHead;
		while (pCur->_pNext->_pNext)//�ҵ����ڶ����ڵ�
			pCur = pCur->_pNext;

		free(pCur->_pNext);//�ͷ����һ���ڵ�
		pCur->_pNext = NULL;//�������ڶ����ڵ�ָ���
	}
}

PNode BuySListNode(Datatype data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == pNewNode)
		return NULL;

	pNewNode->_pNext = NULL;
	pNewNode->_data = data;
}
void TestSList()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
}