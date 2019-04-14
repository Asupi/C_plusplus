#define _CRT_SECURE_NO_WARNINGS 
class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> result;
		if (root == NULL)
			return result;
		int maxValue;
		q.push(root);
		while (!q.empty()){
			int size = q.size();
			TreeNode* p = q.front();
			maxValue = p->val;
			for (int i = 0; i<size; i++){
				q.pop();
				if (p->val > maxValue)
					maxValue = p->val;
				if (p->left) q.push(p->left);
				if (p->right) q.push(p->right);
				p = q.front();
			}
			result.push_back(maxValue);
		}
		return result;
	}
};