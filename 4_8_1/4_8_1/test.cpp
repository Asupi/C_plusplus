#define _CRT_SECURE_NO_WARNINGS 
//ǰ��������ǵݹ飩��
//1.�ȱ�����ڵ㣬��ڵ�ȫ��ѹջ����ڵ�������
//
//2.����ջ��˳�����ȳ���ȡ��ÿһ��ѹջ�Ľڵ㣬�������ϱ����ҽڵ�
//
//����ջ����ȳ���ɽڵ����ϻ��ݵĹ���

while (cur || !st.empty())
{
	//�ȱ�����ߵĽڵ�
	while (cur){
		st.push(cue);//ѹջ
		v.push_back(cur->val);//���ڵ��ֵ����vector��
		cur = cur->left;
	}
	cur = st.top();
	st.pop();//ȡ��ջ��Ԫ��
	cur = cur->right;