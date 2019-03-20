#include<iostream>
using namespace std;

struct node{
	int val;
	struct node* next;
	node(int x) :val(x){}
};
/***非递归方式***/
node* reverseList(node* H)
{
	if (H == NULL || H->next == NULL) //链表为空或者仅1个数直接返回
		return H;
	node* p = H, *newH = NULL;
	while (p != NULL)                 //一直迭代到链尾
	{
		node* tmp = p->next;          //暂存p下一个地址，防止变化指针指向后找不到后续的数
		p->next = newH;               //p->next指向前一个空间
		newH = p;                     //新链表的头移动到p，扩长一步链表
		p = tmp;                   //p指向原始链表p指向的下一个空间
	}
	return newH;
}
/***递归方式***/
node* In_reverseList(node* H)
{
	if (H == NULL || H->next == NULL)       //链表为空直接返回，而H->next为空是递归基
		return H;
	node* newHead = In_reverseList(H->next); //一直循环到链尾 
	H->next->next = H;                       //翻转链表的指向
	H->next = NULL;                          //记得赋值NULL，防止链表错乱
	return newHead;                          //新链表头永远指向的是原链表的链尾
}
int main()
{
	node* first = new node(1);
	node* second = new node(2);
	node* third = new node(3);
	node* forth = new node(4);
	node* fifth = new node(5);
	first->next = second;
	second->next = third;
	third->next = forth;
	forth->next = fifth;
	fifth->next = NULL;
	//非递归实现
	node* H1 = first;
	H1 = reverseList(H1);    //翻转
	//递归实现
	node* H2 = H1;    //请在此设置断点查看H1变化，否则H2再翻转，H1已经发生变化
	H2 = In_reverseList(H2); //再翻转
	
	return 0;
}