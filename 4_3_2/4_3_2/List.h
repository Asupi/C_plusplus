




#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#pragma once

typedef int Datatype;

typedef struct Node
{
	struct Node* _pNext;
	Datatype _data;//值域
} Node, *PNode;


#define NULL 0
///////////////不带头结点的单链表//////////////////////////
void SListInit(PNode* pHead);

void SListPushBack(PNode* pHead, Datatype data);
void SListPopBack(PNode* pHead);
PNode BuySListNode(Datatype data);


///////////////////////////////////////////////
void SListInit(PNode* pHead)//改变外部实参的指向所以传的是二级指针
{
	assert(pHead);
	*pHead=NULL;
	
}
void SListPushBack(PNode* pHead, Datatype data)
{
	PNode pNewNode = NULL;

	//空链表需要改变pHead指向
	assert(pHead);

	pNewNode = BuySListNode(data);
	if (NULL == *pHead)
		*pHead =pNewNode ;
	else
	{
		//非空链表不需要改变pHead指向
		PNode pCur = *pHead;
		while (pCur->_pNext)
			pCur = pCur->_pNext;

		pCur->_pNext = pNewNode;

	}
}
void SListPopBack(PNode* pHead)
{
	assert(pHead);
	//空链表
	if (NULL == *pHead)
		return;
	else if (NULL == (*pHead)->_pNext)
	{
		//只有一个节点
		free(*pHead);
		*pHead = NULL;
	}
	//有多个节点
	else
	{
		PNode pCur = *pHead;
		while (pCur->_pNext->_pNext)//找倒数第二个节点
			pCur = pCur->_pNext;

		free(pCur->_pNext);//释放最后一个节点
		pCur->_pNext = NULL;//将倒数第二个节点指向空
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