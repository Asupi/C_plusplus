#define _CRT_SECURE_NO_WARNINGS 
/****************************************************************************/
/** ��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö�������    */
/**       ���������ǰ���������������Ľ���ж������ظ������֡�����    */
/**       ����ǰ�����{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}    */
/**       ���ؽ���ͼ2.6��ʾ�Ķ��������������ͷ��㡣                    */
/****************************************************************************/
#include <iostream>

using namespace std;

typedef struct node {
	int value;
	struct node *lchild;
	struct node *rchild;
}BiTree_Node;

/**�����ж�ǰ��������к���������������ƥ��*/
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

/*�ؽ��������ĵݹ����������������⣬��ָ����ӷ��� */
BiTree_Node *Construct(int *pre_start, int *in_start, int len)
{
	/**����ǰ��������У�ֻ��һ���£�ȡ�ø��ڵ�root */
	int root_value = pre_start[0];
	BiTree_Node *root;
	root = new BiTree_Node;
	root->value = root_value;
	root->lchild = NULL;
	root->rchild = NULL;

	/**�����������Ѱ������ȡ�õ�root��λ��*/
	int k = 0;
	int new_len;
	while (root_value != in_start[k] && k < len)
	{
		k++;
	}
	new_len = k;

	/**�������ҵ���λ�ã��ж���������*/
	if (new_len > 0)
	{
		root->lchild = Construct(pre_start + 1, in_start, new_len);
		/*new_len ��ʾ�������ĳ���*/
	}
	if (len - new_len - 1> 0)
	{
		root->rchild = Construct(pre_start + new_len + 1, in_start + new_len + 1, len - new_len - 1);
		/*len-new_len-1 ��ʾ�������ĳ���*/
	}

	return root;
}

/*�ؽ�����������*/
BiTree_Node *Construct_BiTree(int pre[], int in[], int length)
{
	if (pre == NULL || in == NULL || length <= 0 || !Judge_array(pre, in, length))
		return NULL;
	else
		return Construct(pre, in, length);
}

/**���������������ͨ����������ж��ؽ��Ķ������Ƿ���ȷ*/
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
