#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
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
			}
		}
	}

private:
	//pNode _root;
	pNode _header;
};
