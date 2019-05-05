#define _CRT_SECURE_NO_WARNINGS 
/****************************************************************************/
/** 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。    */
/**       假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如    */
/**       输入前序遍历{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}    */
/**       则重建出图2.6所示的二叉树并输出它的头结点。                    */
/****************************************************************************/
#include <iostream>

using namespace std;

typedef struct node {
	int value;
	struct node *lchild;
	struct node *rchild;
}BiTree_Node;

/**用于判断前序遍历序列和中序遍历数列书否匹配*/
bool Judge_array(int *pre, int *in, int n)
{
	int i, j;
	int k = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (pre[i] == in[j])
				k++;
		}
	}
	if (k != n)
		return false;
	else
		return true;
}

/*重建二叉树的递归操作，对于这个问题，用指针更加方便 */
BiTree_Node *Construct(int *pre_start, int *in_start, int len)
{
	/**对于前序遍历数列，只做一件事，取得根节点root */
	int root_value = pre_start[0];
	BiTree_Node *root;
	root = new BiTree_Node;
	root->value = root_value;
	root->lchild = NULL;
	root->rchild = NULL;

	/**在中序遍历中寻找上面取得的root的位置*/
	int k = 0;
	int new_len;
	while (root_value != in_start[k] && k < len)
	{
		k++;
	}
	new_len = k;

	/**根据所找到的位置，判断左右子树*/
	if (new_len > 0)
	{
		root->lchild = Construct(pre_start + 1, in_start, new_len);
		/*new_len 表示左子树的长度*/
	}
	if (len - new_len - 1> 0)
	{
		root->rchild = Construct(pre_start + new_len + 1, in_start + new_len + 1, len - new_len - 1);
		/*len-new_len-1 表示右子树的长度*/
	}

	return root;
}

/*重建二叉树函数*/
BiTree_Node *Construct_BiTree(int pre[], int in[], int length)
{
	if (pre == NULL || in == NULL || length <= 0 || !Judge_array(pre, in, length))
		return NULL;
	else
		return Construct(pre, in, length);
}

/**二叉树后序遍历，通过后序遍历判断重建的二叉树是否正确*/
void Postorder(BiTree_Node *root)
{
	if (NULL == root)
		return;
	else{
		Postorder(root->lchild);
		Postorder(root->rchild);
		cout << root->value << ' ';
	}
}

int main()
{
	int pre[8] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int in[8] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	//int pre[5] = {1,2,3,4,5};
	//int in[5] = {5,4,3,2,1};

	//int pre[6] = {1,2,3,6,7,8};
	//int in[6] = {3,2,1,6,7,8};

	//int pre[5] = {1,2,3,4,5};
	//int in[5] = {1,2,3,4,6};

	BiTree_Node *root = Construct_BiTree(pre, in, 8);
	Postorder(root);
	return 0;
}
