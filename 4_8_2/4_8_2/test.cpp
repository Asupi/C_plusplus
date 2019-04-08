#define _CRT_SECURE_NO_WARNINGS 

//�������������������
//
//Ѱ�ҽڵ�·������ջ��¼·�����Ҹ������ϻ���·��
//1.�Ӹ��ڵ㿪ʼ������ÿ��һ���ڵ㣬����ջ
//2.�����ǰ�ڵ㲻��Ҫ�ҵĽڵ㣬��ȥ�����������Ƿ����Ҫ�ҵĽڵ�
//3.�����ǰ�ڵ�����������������������Ľڵ㣬˵����ǰ�ڵ㲻��Ŀ��ڵ��·���ϣ��ų��˽ڵ㣬��ջ
class Solution {
public:
	bool getPath(TreeNode*cur, TreeNode*node, stack<TreeNode*>&s)
	{
		if (cur == nullptr)
			return false;
		//����ջ
		s.push(cur);
		//��ǰ�ڵ���Ҫ�ҵĽڵ㣬˵��·���������
		if (cur == node)
			return true;
		//��ǰ�ڵ㲻��Ҫ�ҵĽڵ㣬��ȥ�������ҽڵ�
		if (getPath(cur->left, node, s))
			return true;
		if (getPath(cur->right, node, s))
			return true;
		//��ǰ�ڵ㲻������ҪѰ�ҵĽڵ��·���ϣ���ջ
		s.pop();
		return false;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*>path1;
		stack<TreeNode*>path2;
		//��ȡ·��
		getPath(root, p, path1);
		getPath(root, q, path2);
		//·���ü���ʹ·���ĳ���һ��
		/*�Ե����ϱȶ�����·���Ľڵ㣺
			1.����ȷ������·���ĳ�����ȣ���Ϊ�Ӹ��ڵ㵽����������ȵ�·����һ�µĳ��ȿ϶���ȣ����������ȣ��õ���·���ϵ�ջ�����
			2.��һ����ַ��ȵĽڵ��������Ĺ�������*/
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
		//Ѱ�ҵ�һ����ͬ�Ľڵ㣬��Ϊ��������
		while (!path1.empty())
		{
			if (path1.top() == path2.top())
				break;
			path1.pop();//�׳�ջ��Ԫ�أ��������±Ƚ�
			path2.pop();
		}

		return path1.top();
	}
};