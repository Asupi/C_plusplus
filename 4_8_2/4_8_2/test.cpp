#define _CRT_SECURE_NO_WARNINGS 

//二叉树的最近公共祖先
//
//寻找节点路径：用栈记录路径并且辅助向上回溯路径
//1.从根节点开始搜索，每到一个节点，先入栈
//2.如果当前节点不是要找的节点，再去看左右子树是否存在要找的节点
//3.如果当前节点和左右子树都不包含搜索的节点，说明当前节点不在目标节点的路径上，排除此节点，出栈
class Solution {
public:
	bool getPath(TreeNode*cur, TreeNode*node, stack<TreeNode*>&s)
	{
		if (cur == nullptr)
			return false;
		//先入栈
		s.push(cur);
		//当前节点是要找的节点，说明路径搜索完成
		if (cur == node)
			return true;
		//当前节点不是要找的节点，再去看看左右节点
		if (getPath(cur->left, node, s))
			return true;
		if (getPath(cur->right, node, s))
			return true;
		//当前节点不存在于要寻找的节点的路径上，出栈
		s.pop();
		return false;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*>path1;
		stack<TreeNode*>path2;
		//获取路径
		getPath(root, p, path1);
		getPath(root, q, path2);
		//路径裁剪，使路径的长度一致
		/*自底向上比对两个路径的节点：
			1.首先确保两个路径的长度相等（因为从根节点到最近公共祖先的路径是一致的长度肯定相等），如果不想等，裁掉长路径上的栈顶结点
			2.第一个地址相等的节点就是最近的公共祖先*/
		while (path1.size() != path2.size())
		{
			if (path1.size()>path2.size())
			{
				path1.pop();
			}
			else
			{
				path2.pop();
			}
		}
		//寻找第一个相同的节点，即为公共祖先
		while (!path1.empty())
		{
			if (path1.top() == path2.top())
				break;
			path1.pop();//抛出栈顶元素，继续向下比较
			path2.pop();
		}

		return path1.top();
	}
};