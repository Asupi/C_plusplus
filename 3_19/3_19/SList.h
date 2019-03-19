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

// ��ʼ��
void SListInit(SList *list) {
	assert(list != NULL);
	list->first = NULL;
}
// ����
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

// �����½��
SListNode * SListBuyNode(SLDataType value)
{
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	node->value = value;
	node->next = NULL;

	return node;
}

// ��
// ͷ��
void SListPushFront(SList *list, SLDataType value)
{
	assert(list != NULL);
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	node->value = value;
	node->next = list->first;
	list->first = node;
}

// β��
void SListPushBack(SList *list, SLDataType value)
{
	assert(list != NULL);
	if (list->first == NULL) {
		SListPushFront(list, value);
		return;
	}

	// �������н������
	// �������е����һ�����
	SListNode *cur;
	for (cur = list->first; cur->next != NULL; cur = cur->next) {
	}

	// cur �������һ�����
	SListNode *node = SListBuyNode(value);
	cur->next = node;
}

// ɾ
// ͷɾ
void SListPopFront(SList *list)
{
	assert(list != NULL);			// ��֤�������е�
	assert(list->first != NULL);	// ��֤����Ϊ��

	SListNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}

void SListPopBack(SList *list)
{
	assert(list != NULL);			// ��֤�������е�
	assert(list->first != NULL);	// ��֤����Ϊ��
	// ���ֻ��һ�����
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

// pos һ���������е�һ����Ч���
void SListInsertAfter(SListNode *pos, SLDataType value) {
	// �� value ������
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

	// cur ָ�� pos ��ǰһ�����

	SListNode *node = SListBuyNode(value);

	cur->next = node;
	node->next = pos;
}

// ��
void SListUpdate(SListNode *node, SLDataType value) {
	node->value = value;
}

// ��
// ȥ�ҵ������������ĵ�һ�� value�����û�ҵ������� NULL
SListNode * SListFind(const SList *list, SLDataType value) {
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		if (cur->value == value) {
			return cur;
		}
	}

	return NULL;
}

// ��ӡ
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

	printf("��ɹ�\n");
}

