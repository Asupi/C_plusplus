#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int DLDataType;

// 定义链表结点结构
typedef struct DListNode {
	DLDataType value;		// 头结点的 value 没有意义
	struct DListNode *prev;	// 指向前一个结点
	struct DListNode *next;	// 指向后一个结点
}	DListNode;

// 定义双向链表结构
typedef struct DList {
	DListNode *head;		// 表示链表的头结点
}	DList;

DListNode * DListBuyNode(DLDataType value) {
	DListNode * node = (DListNode *)malloc(sizeof(DListNode));
	node->value = value;
	node->next = node->prev = NULL;

	return node;
}

// 初始化
void DListInit(DList * dlist) {
	dlist->head = DListBuyNode(0);	// 0 其实没有意思
	// 这里是头结点
	dlist->head->next = dlist->head;
	dlist->head->prev = dlist->head;
}

// 销毁
// 1. 清空链表
void DListClear(DList *dlist) {
	DListNode *cur, *next;
	cur = dlist->head->next;
	while (cur != dlist->head) {
		next = cur->next;
		free(cur);
		cur = next;
	}

	dlist->head->next = dlist->head->prev = dlist->head;
}

// 2. 彻底销毁链表
void DListDestroy(DList *dlist) {
	DListClear(dlist);
	free(dlist->head);
	dlist->head = NULL;
}

// 增

void DListInsert(DListNode *pos, DLDataType value) {
	DListNode *node = DListBuyNode(value);

	node->prev = pos->prev;
	node->next = pos;
	node->prev->next = node;
	pos->prev = node;
}

void DListErase(DListNode *pos) {
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

// 头插
void DListPushFront(DList * dlist, DLDataType value) {
#if 0
	DListNode *node = DListBuyNode(value);
	node->prev = dlist->head;
	node->next = dlist->head->next;
	dlist->head->next->prev = node;
	dlist->head->next = node;
#endif
	DListInsert(dlist->head->next, value);
}
//尾插
void DListPushBack(DList *dlist, DLDataType value) {
#if 0
	DListNode *node = DListBuyNode(value);
	node->prev = dlist->head->prev;
	node->next = dlist->head;
	node->prev->next = node;
	node->next->prev = node;
#endif
	DListInsert(dlist->head, value);
}
//头删
void DListPopFront(DList *dlist)
{
	assert(dlist->head->next != dlist->head);
#if 0
	DListNode *cur = dlist->head->next;

	dlist->head->next = cur->next;
	cur->next->prev = dlist->head;

	free(cur);
#endif
	DListErase(dlist->head->next);
}
//尾删
void DListPopBack(DList *dlist)
{
	assert(dlist->head->next != dlist->head);	// 确保链表不为空

#if 0
	DListNode *cur = dlist->head->prev;
	cur->prev->next = dlist->head;	//dlist->head->prev->prev->next;
	cur->next->prev = cur->prev;	//dlist->head->prev;


	free(cur);
#endif

	DListErase(dlist->head->prev);
}


DListNode * DListFind(const DList *dlist, DLDataType value) {
	DListNode *cur;
	for (cur = dlist->head->next; cur != dlist->head; cur = cur->next) {

		if (cur->value == value) {
			return cur;
		}
	}

	return NULL;
}


void DListPrint(const DList *dlist) {
	for (DListNode *cur = dlist->head->next;
		cur != dlist->head; cur = cur->next) {


		printf("%d --> ", cur->value);
	}

	printf("\n");
}

void TestDList() {
	DList list;

	DListInit(&list);

	DListPrint(&list);

	DListPushBack(&list, 1);
	DListPushBack(&list, 2);
	DListPushBack(&list, 3);

	DListPrint(&list);
	// 1 2 3

	DListPushFront(&list, 11);
	DListPushFront(&list, 13);
	DListPushFront(&list, 13);

	DListPrint(&list);
	// 13 12 11 1 2 3

	DListPopFront(&list, 13);
	DListPopFront(&list, 12);
    DListPrint(&list);
	//11 1 2 3
	DListPopBack(&list);
	DListPrint(&list);
	//11 1 2
	
}

