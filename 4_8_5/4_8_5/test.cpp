#define _CRT_SECURE_NO_WARNINGS 
//二叉树的镜像

class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		queue<TreeNode*> q;
		//先放根节点
		if (pRoot)
			q.push(pRoot);
		while (!q.empty())
		{
			TreeNode* cur = q.front();
			q.pop();//出队
			swap(cur->left, cur->right);//交换左右节点
			if (cur->left)//继续入队
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
		}
	}
};