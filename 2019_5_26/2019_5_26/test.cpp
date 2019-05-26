#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
template<class T>
struct AVLNode
{
	AVLNode(const T& val = T())
	:_data(val)
	, _pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _bf(0)
	{}
	T _data;
	AVLNode<T>* _pLeft;
	AVLNode<T>* _pRight;
	AVLNode<T>* _pParent;
	//ƽ������
	int _bf;
};

template <class T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;
	typedef Node* pNode;

	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}

		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data > val)
			{
				cur = cur->_pLeft;
			}
			else if (cur->_data < val)
			{
				cur = cur->_pRight;
			}
			else
				return false;
		}

		pNode newNode = new Node(val);
		if (parent->_data > val)
			parent->_pLeft = newNode;
		else
			parent->_pRight = newNode;
		newNode->_pParent = parent;
		cur = newNode;
		//��������֤ƽ��
		while (parent)
		{
			//���µ�ǰ�ڵ��ƽ������
			if (parent->_pLeft == cur)
				--parent->_bf;
			else
				++parent->_bf;
			//���ƽ�����ӣ�_bf ==0, �߶�û�з����仯��ֹͣ����
			if (parent->_bf == 0)
				break;
			//�߶ȼ�1�����´�·���ϵ����Ƚڵ��ƽ������
			if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_pParent;
			}

			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//��ƽ�⣬��Ҫ����
				//����
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					//����
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					//����˫��

					RotateL(cur);
					RotateR(parent);

				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					pNode subR = parent->_pRight;
					pNode subRL = subR->_pLeft;
					int bf = subRL->_bf;
					//����˫��
					RotateR(cur);
					RotateL(parent);
					if (bf == 1)
					{
						subR->_bf = 0;
						parent->_bf = -1;
					}
					else if (bf == -1)
					{
						parent->_bf = 0;
						subR->_bf = 1;
					}
				}

				//��ת�������Ѿ�ƽ�⣬��������
				break;
			}
		}
		return true;
	}

	void RotateL(pNode parent)
	{
		pNode subR = parent->_pRight;
		pNode subRL = subR->_pLeft;
		//��ת
		subR->_pLeft = parent;
		parent->_pRight = subRL;

		//����������
		//����subRL ��parent
		if (subRL)
			subRL->_pParent = parent;

		//����subR �� parent->_pParent
		if (parent != _root)
		{
			pNode gParent = parent->_pParent;
			//�ж�parent֮ǰ��parent->_pParent����һ�ߵĽڵ�
			//��subR���ӵ���Ӧ�ı�

			if (gParent->_pLeft == parent)
				gParent->_pLeft = subR;
			else
				gParent->_pRight = subR;
			//����subR��pParent
			subR->_pParent = gParent;
		}
		else
		{
			//���parent�Ǹ���subR����µĸ�
			subR->_pParent = nullptr;
			_root = subR;
		}

		//����subR �� parent
		parent->_pParent = subR;

		//����ƽ������
		subR->_bf = parent->_bf = 0;
	}


	void RotateR(pNode parent)
	{
		pNode subL = parent->_pLeft;
		pNode subLR = subL->_pRight;
		// 1. ��������subL, subLR, parent
		subL->_pRight = parent;
		parent->_pLeft = subLR;
		//2 ��������subLR, parent
		if (subLR)
			subLR->_pParent = parent;
		//3. ˫������subL��pParent->_pParent
		if (parent != _root)
		{
			pNode gParent = parent->_pParent;
			if (gParent->_pLeft == parent)
				gParent->_pLeft = subL;
			else
				gParent->_pRight = subL;
			subL->_pParent = gParent;
		}
		else
		{
			subL->_pParent = nullptr;
			_root = subL;
		}
		//4. ��������parent, subL
		parent->_pParent = subL;
		//����ƽ������
		parent->_bf = subL->_bf = 0;

	}

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	void _Inorder(pNode root)
	{
		if (root)
		{
			_Inorder(root->_pLeft);
			cout << root->_data << " ";
			_Inorder(root->_pRight);
		}
	}

	int Height(pNode cur)
	{
		if (cur == nullptr)
			return 0;
		int left = Height(cur->_pLeft);
		int right = Height(cur->_pRight);
		return left > right ? left + 1 : right + 1;
	}

	bool IsBalance()
	{
		return _isBalance(_root);
	}

	bool _isBalance(pNode root)
	{
		if (root == nullptr)
			return true;
		int left = Height(root->_pLeft);
		int right = Height(root->_pRight);

		if (root->_bf != (right - left))
		{
			cout << root->_data << "--->" << root->_bf << "  " << (right - left) << endl;
			return false;
		}


		return abs(root->_bf) < 2 && _isBalance(root->_pLeft)
			&& _isBalance(root->_pRight);
	}

private:
	pNode _root = nullptr;
};

void testAVL()
{
	//int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	AVLTree<int> avl;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		avl.insert(arr[i]);
		cout << arr[i] << "--->" << avl.IsBalance() << endl;
	}


	avl.Inorder();
}

int main()
{
	testAVL();
	return 0;
}