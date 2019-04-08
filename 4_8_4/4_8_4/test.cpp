#define _CRT_SECURE_NO_WARNINGS 
//�������Ĳ�α���I(�Ӹ���Ҷ�ӽڵ�)
//����������һ����ά���飺
//����һ��Žڵ�
//���ж����ÿ���ڵ��Ӧ�Ĳ��
//1.ÿһ�γ��ӵĽڵ㣬��Ӧ�Ĳ��Ҳ���ӣ����ղ�ŷ����Ӧ�Ķ�ά���������
//2.�ѳ��ӽڵ�ĺ��ӽڵ���ӣ���Ӧ�ĺ��ӽڵ�Ĳ�ż�һ��ͬ���ĺ��ӽڵ�Ĳ��Ҳ����һ�����С�Ȼ��ѭ��1.2��
//3.����������Ϊ��



class Solution {
public:

	int getHeight(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		return left > right ? left + 1 : right + 1;
	}
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> treeVec;
		//��ά��������������ĸ߶�һ�£���ֹ����Խ��
		treeVec.resize(getHeight(root));
		//��Žڵ�
		queue<TreeNode*>node;
		//��Ŷ�Ӧ�Ĳ��
		queue<int>index;
		//��Ӹ��ڵ�
		if (root)
		{
			node.push(root);
			index.push(0);
		}
		//��������
		while (!node.empty())
		{
			//��ͷ�ڵ����
			TreeNode* cur = node.front();
			node.pop();
			int curIndex = index.front();
			index.pop();
			//����Ŵ�ŵ�ǰ�ڵ�
			treeVec[curIndex].push_back(cur->val);
			//������һ���ӽڵ�
			if (cur->left)
			{
				node.push(cur->left);
				index.push(curIndex + 1);
			}
			if (cur->right)
			{
				node.push(cur->right);
				index.push(curIndex + 1);
			}
		}
		return treeVec;
	}

};


//�������Ĳ�α���II(��Ҷ�ӵ����ڵ�)
//
//��I����һ����ֻ������ⲿ��vector����

class Solution {
public:

	int getHeight(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		return left > right ? left + 1 : right + 1;
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> treeVec;
		//��ά��������������ĸ߶�һ��
		treeVec.resize(getHeight(root));
		//��Žڵ�
		queue<TreeNode*>node;
		//��Ŷ�Ӧ�Ĳ��
		queue<int>index;
		//��Ӹ��ڵ�
		if (root)
		{
			node.push(root);
			index.push(0);
		}
		//��������
		while (!node.empty())
		{
			//��ͷ�ڵ����
			TreeNode* cur = node.front();
			node.pop();
			int curIndex = index.front();
			index.pop();
			//����Ŵ�ŵ�ǰ�ڵ�
			treeVec[curIndex].push_back(cur->val);
			//������һ���ӽڵ�
			if (cur->left)
			{
				node.push(cur->left);
				index.push(curIndex + 1);
			}
			if (cur->right)
			{
				node.push(cur->right);
				index.push(curIndex + 1);
			}
		}

		reverse(treeVec.begin(), treeVec.end()); //����vector

		return treeVec;
	}

};