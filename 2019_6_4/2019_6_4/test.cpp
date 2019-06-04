#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <time.h>
using namespace std;
//pair
enum Color
{
	Red,
	Black
};

template <class K, class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	Color _color = Red;

	RBTreeNode<K, V>* _pLeft = nullptr;
	RBTreeNode<K, V>* _pRight = nullptr;
	RBTreeNode<K, V>* _pParent = nullptr;
};

template <class K, class V>
class RBTree
{
public:
	typedef RBTreeNode<K, V> Node;
	typedef Node* pNode;

	RBTree()
		:_header(new Node)
	{
		_header->_pLeft = _header;
		_header->_pRight = _header;
	}

	bool Insert(pair<K, V>& kv)
	{
		//�����������Ĳ���

		if (_header->_pParent == nullptr)
		{
			//������������ڵ㣬��ɫΪ��
			pNode root = new Node;
			root->_kv = kv;
			root->_color = Black;
			_header->_pParent = root;
			root->_pParent = _header;
			_header->_pLeft = root;
			_header->_pRight = root;
			return true;
		}

		pNode cur = _header->_pParent;
		pNode parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_pLeft;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_pRight;
			}
			else
				return false;
		}

		cur = new Node;
		cur->_kv = kv;
		if (parent->_kv.first > cur->_kv.first)
			parent->_pLeft = cur;
		else
			parent->_pRight = cur;

		cur->_pParent = parent;
		//��������ɫ
		while (cur != _header->_pParent && cur->_pParent->_color == Red)
		{
			pNode parent = cur->_pParent;
			pNode gParent = parent->_pParent;
			if (gParent->_pLeft == parent)
			{
				pNode uncle = gParent->_pRight;
				//u������Ϊ��
				if (uncle && uncle->_color == Red)
				{
					parent->_color = uncle->_color = Black;
					gParent->_color = Red;
					cur = gParent;
				}
				else
				{
					// u������ / u������Ϊ��
					//����Ƿ���˫������: ����˫��
					//����������swap, --> �ҵ���
					if (parent->_pRight == cur)
					{
						RotateL(parent);
						swap(parent, cur);
					}

					RotateR(gParent);
					parent->_color = Black;
					gParent->_color = Red;
					break;
				}
			}
			else
			{
				pNode uncle = gParent->_pLeft;
				if (uncle && uncle->_color == Red)
				{
					parent->_color = uncle->_color = Black;
					gParent->_color = Red;
					cur = gParent;
				}
				else
				{
					// u������Ϊ�� / u������
					if (parent->_pLeft == cur)
					{
						RotateR(parent);
						swap(cur, parent);
					}

					RotateL(gParent);
					gParent->_color = Red;
					parent->_color = Black;
					break;
				}
			}
		}

		//�������ʼ���Ǻ�ɫ��
		_header->_pParent->_color = Black;
		//Ϊ��ʵ�ֺ����ĵ�����
		_header->_pLeft = leftMost();
		_header->_pRight = rightMost();
		return true;
	}

	pNode leftMost()
	{
		pNode cur = _header->_pParent;
		while (cur && cur->_pLeft)
		{
			cur = cur->_pLeft;
		}
		return cur;
	}

	pNode rightMost()
	{
		pNode cur = _header->_pParent;
		while (cur && cur->_pRight)
		{
			cur = cur->_pRight;
		}
		return cur;
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
		if (parent != _header->_pParent)
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
			_header->_pParent = subR;
		}

		//����subR �� parent
		parent->_pParent = subR;

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
		if (parent != _header->_pParent)
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
			_header->_pParent = subL;
		}
		//4. ��������parent, subL
		parent->_pParent = subL;

	}

	void Inorder()
	{
		_Inorder(_header->_pParent);
		cout << endl;
	}

	void _Inorder(pNode root)
	{
		if (root)
		{
			_Inorder(root->_pLeft);
			cout << root->_kv.first << " ";
			_Inorder(root->_pRight);
		}
	}

	bool IsValidRBTree()
	{
		pNode pRoot = _header->_pParent;
		// ����Ҳ�Ǻ����
		if (nullptr == pRoot)
			return true;
		// �����ڵ��Ƿ��������
		if (Black != pRoot->_color)
		{
			cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
			return false;
		}
		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		pNode pCur = pRoot;
		while (pCur)
		{
			if (Black == pCur->_color)
				blackCount++;
			pCur = pCur->_pLeft;
		}
		// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}
	bool _IsValidRBTree(pNode pRoot, size_t k, const size_t blackCount)
	{
		//�ߵ�null֮���ж�k��black�Ƿ����
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
				return false;
			}
			return true;
		}
		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (Black == pRoot->_color)
			k++;
		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		pNode pParent = pRoot->_pParent;
		if (pParent && Red == pParent->_color && Red == pRoot->_color)
		{
			cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
			_IsValidRBTree(pRoot->_pRight, k, blackCount);
	}

private:
	//pNode _header->_pParent;
	pNode _header;
};

//int main()
//
//{
//	RBTree<int, int> rbt;
//	srand(time(nullptr));
//	/*int arr[] = { 5, 7, 9, 1, 3, 4, 10, 6, 8 };
//	for (const auto& e : arr)
//	{
//	rbt.Insert(make_pair(e, e));
//	}*/
//
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		int num = rand();
//		cout << num << " ";
//		rbt.Insert(make_pair(num, n));
//		/*if (!rbt.IsValidRBTree())
//		{
//			cout << "����ڵ��쳣��" << num << endl;
//		}*/
//	}
//	cout << endl;
//	/*rbt.Inorder();*/
//	cout <<"IsValidRBTree: "<< rbt.IsValidRBTree() << endl;
//	return 0;
//}


