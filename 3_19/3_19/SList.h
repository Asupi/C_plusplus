#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int SLDataType;


typedef struct SLNode {
	SLDataType	value;
	struct SLNode *next;
}	SListNode;

typedef struct SList {
	SListNode *first;		// SLNode *head;
}	SList;

// 初始化
void SListInit(SList *list) {
	assert(list != NULL);
	list->first = NULL;
}
// 销毁
void SListDestroy(SList *list) {
	assert(list != NULL);

	SListNode *cur = list->first;
	SListNode *next;
	while (cur != NULL) {
		next = cur->next;
		free(cur);
		cur = next;
	}

	list->first = NULL;
}

// 申请新结点
SListNode * SListBuyNode(SLDataType value)
{
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	node->value = value;
	node->next = NULL;

	return node;
}

// 增
// 头插
void SListPushFront(SList *list, SLDataType value)
{
	assert(list != NULL);
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	node->value = value;
	node->next = list->first;
	list->first = node;
}

// 尾插
void SListPushBack(SList *list, SLDataType value)
{
	assert(list != NULL);
	if (list->first == NULL) {
		SListPushFront(list, value);
		return;
	}

	// 链表中有结点的情况
	// 找链表中的最后一个结点
	SListNode *cur;
	for (cur = list->first; cur->next != NULL; cur = cur->next) {
	}

	// cur 就是最后一个结点
	SListNode *node = SListBuyNode(value);
	cur->next = node;
}

// 删
// 头删
void SListPopFront(SList *list)
{
	assert(list != NULL);			// 保证链表是有的
	assert(list->first != NULL);	// 保证链表不为空

	SListNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}

void SListPopBack(SList *list)
{
	assert(list != NULL);			// 保证链表是有的
	assert(list->first != NULL);	// 保证链表不为空
	// 如果只有一个结点
	if (list->first->next == NULL) {
		SListPopFront(list);
		return;
	}

	SListNode *cur = list->first;
	while (cur->next->next != NULL) {
		cur = cur->next;
	}

	free(cur->next);
	cur->next = NULL;
}

// pos 一定是链表中的一个有效结点
void SListInsertAfter(SListNode *pos, SLDataType value) {
	// 给 value 申请结点
	SListNode *node = SListBuyNode(value);

	node->next = pos->next;
	pos->next = node;
}

void SListEraseAfter(SListNode *pos) {
	SListNode *next = pos->next;
	pos->next = next->next;
	free(next);
}

void SListInsertBefore(SList *list, SListNode *pos, SLDataType value)
{
	SListNode *cur = list->first;
	while (cur->next != pos) {
		cur = cur->next;
	}

	// cur 指向 pos 的前一个结点

	SListNode *node = SListBuyNode(value);

	cur->next = node;
	node->next = pos;
}

// 改
void SListUpdate(SListNode *node, SLDataType value) {
	node->value = value;
}

// 查
// 去找到链表中遇到的第一个 value，如果没找到，返回 NULL
SListNode * SListFind(const SList *list, SLDataType value) {
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		if (cur->value == value) {
			return cur;
		}
	}

	return NULL;
}

// 打印
void SListPrint(const SList *list) {
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		printf("%d --> ", cur->value);
	}

	printf("NULL\n");
}




void TestSList1() {
	SList list;
	SListInit(&list);
	assert(list.first == NULL);

	SListPushBack(&list, 11);
	SListPushBack(&list, 12);
	SListPushBack(&list, 13);

	SListNode *n12 = SListFind(&list, 12);
	assert(n12 != NULL);

	SListPrint(&list);
	// 11 12 13

	SListInsertAfter(n12, 103);


	SListPrint(&list);
	// 11 12 103 13

	SListEraseAfter(n12);

	SListPrint(&list);
	// 11 12 13

	SListInsertBefore(&list, n12, 101);

	SListPrint(&list);
	// 11 101 12 13

	printf("大成功\n");
}

