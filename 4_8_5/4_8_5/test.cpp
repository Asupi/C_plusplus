#define _CRT_SECURE_NO_WARNINGS 
//�������ľ���

class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		queue<TreeNode*> q;
		//�ȷŸ��ڵ�
		if (pRoot)
			q.push(pRoot);
		while (!q.empty())
		{
			TreeNode* cur = q.front();
			q.pop();//����
			swap(cur->left, cur->right);//�������ҽڵ�
			if (cur->left)//�������
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
		}
	}
};