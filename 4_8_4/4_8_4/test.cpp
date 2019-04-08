#define _CRT_SECURE_NO_WARNINGS 
//二叉树的层次遍历I(从根到叶子节点)
//用两个队列一个二维数组：
//队列一存放节点
//队列二存放每个节点对应的层号
//1.每一次出队的节点，对应的层号也出队，按照层号放入对应的二维数组的行中
//2.把出队节点的孩子节点入队，对应的孩子节点的层号加一，同样的孩子节点的层号也入另一个队列。然后循环1.2步
//3.结束：队列为空



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
		//二维数组的行数和树的高度一致，防止访问越界
		treeVec.resize(getHeight(root));
		//存放节点
		queue<TreeNode*>node;
		//存放对应的层号
		queue<int>index;
		//入队根节点
		if (root)
		{
			node.push(root);
			index.push(0);
		}
		//遍历队列
		while (!node.empty())
		{
			//对头节点出队
			TreeNode* cur = node.front();
			node.pop();
			int curIndex = index.front();
			index.pop();
			//按层号存放当前节点
			treeVec[curIndex].push_back(cur->val);
			//带出下一层子节点
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


//二叉树的层次遍历II(从叶子到根节点)
//
//和I基本一样，只需最后将外部的vector逆置

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
		//二维数组的行数和树的高度一致
		treeVec.resize(getHeight(root));
		//存放节点
		queue<TreeNode*>node;
		//存放对应的层号
		queue<int>index;
		//入队根节点
		if (root)
		{
			node.push(root);
			index.push(0);
		}
		//遍历队列
		while (!node.empty())
		{
			//对头节点出队
			TreeNode* cur = node.front();
			node.pop();
			int curIndex = index.front();
			index.pop();
			//按层号存放当前节点
			treeVec[curIndex].push_back(cur->val);
			//带出下一层子节点
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

		reverse(treeVec.begin(), treeVec.end()); //逆置vector

		return treeVec;
	}

};