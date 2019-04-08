#define _CRT_SECURE_NO_WARNINGS 
//前序遍历（非递归）：
//1.先遍历左节点，左节点全部压栈，左节点遍历完成
//
//2.按照栈的顺序后进先出，取出每一个压栈的节点，从下向上遍历右节点
//
//借助栈后进先出完成节点向上回溯的过程

while (cur || !st.empty())
{
	//先遍历左边的节点
	while (cur){
		st.push(cue);//压栈
		v.push_back(cur->val);//将节点的值放入vector中
		cur = cur->left;
	}
	cur = st.top();
	st.pop();//取出栈顶元素
	cur = cur->right;