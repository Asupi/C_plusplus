#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
template <class T>
struct BSTNode
{
	BSTNode(const T& val = T())
	:_data(val)
	, _pLeft(nullptr)
	, _pRight(nullptr)
	{}
	T _data;
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
};

template <class T>
class BSTree
{
public:
	typedef BSTNode<T> Node;
	typedef Node* pNode;

	BSTree(const pNode root = nullptr)
		:_root(root)
	{}

	pNode find(const T& val)
	{
		if (_root == nullptr)
			return nullptr;
		pNode cur = _root;
		while (cur)
		{
			if (cur->_data == val)
				return cur;
			else if (cur->data > val)
			{
				cur = cur->_pLeft;
			}
			else
			{
				cur = cur->_pRight;
			}
		}
		return nullptr;
	}

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
		{
			parent->_pLeft = newNode;
		}
		else
			parent->_pRight = newNode;

		return true;
	}

	bool erase(const T& val)
	{
		if (_root == nullptr)
			return false;
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			if (cur->_data == val)
				break;
			else if (cur->_data > val)
			{
				parent = cur;
				cur = cur->_pLeft;
			}
			else
			{
				parent = cur;
				cur = cur->_pRight;
			}
		}

		//删除
		//1. 删除叶子节点
		if (cur->_pLeft == nullptr && cur->_pRight == nullptr)
		{
			//是否删除_root
			if (cur != _root)
			{
				//让父亲节点对应位置置为空
				if (parent->_pLeft == cur)
					parent->_pLeft = nullptr;
				else
					parent->_pRight = nullptr;
			}
			else
			{
				//删除_root, 树为空
				_root = nullptr;
			}
			delete cur;
			cur = nullptr;
		}
		else if (cur->_pLeft == nullptr)
		{
			if (cur != _root)
			{
				//确定当前节点在父亲节点的左边还是右边，对应位置设为cur->_pRight
				if (parent->_pLeft == cur)
					parent->_pLeft = cur->_pRight;
				else
					parent->_pRight = cur->_pRight;
			}
			else
			{
				//更新_root
				_root = _root->_pRight;
			}
			delete cur;
			cur = nullptr;
		}
		else if (cur->_pRight == nullptr)
		{
			if (cur != _root)
			{
				if (parent->_pLeft == cur)
					parent->_pLeft = cur->_pLeft;
				else
					parent->_pRight = cur->_pLeft;
			}
			else
			{
				_root = _root->_pLeft;
			}
			delete cur;
			cur = nullptr;
		}
		else
		{
			//cur 左右孩子都存在
			//1. 寻找替换节点
			pNode pNext = cur->_pLeft;  // 3   5
			parent = cur;
			while (pNext->_pRight)
			{
				parent = pNext;  // 3  4
				pNext = pNext->_pRight;
			}

			//2. 置换
			cur->_data = pNext->_data;
			//指向置换节点的指针置空
			if (parent->_pRight == pNext)
				parent->_pRight = nullptr;
			parent->_pLeft = nullptr;

			//3. 删除置换节点
			delete pNext;
			pNext = nullptr;
		}
		return true;
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

	~BSTree()
	{
		Distory(_root);
	}

	void Distory(pNode root)
	{
		if (root)
		{
			Distory(root->_pLeft);
			Distory(root->_pRight);
			delete root;
			root = nullptr;
		}
	}

private:
	pNode _root;
};

void testTree()
{
	BSTree<int> bt;
	bt.insert(5);
	//bt.Inorder();
	bt.insert(3);
	//bt.Inorder();
	bt.insert(4);
	//bt.Inorder();
	bt.insert(1);
	//bt.Inorder();
	bt.insert(0);
	//bt.Inorder();
	bt.insert(2);
	//bt.Inorder();
	bt.insert(7);
	//bt.Inorder();
	bt.insert(6);
	//bt.Inorder();
	bt.insert(8);
	bt.insert(9);
	bt.Inorder();
	bt.erase(4);
	bt.Inorder();
	bt.erase(8);
	bt.Inorder();
	bt.erase(0);
	bt.Inorder();
	bt.erase(1);
	bt.Inorder();
	bt.erase(2);
	bt.Inorder();
	bt.erase(5);
	bt.Inorder();
	bt.erase(3);
	bt.Inorder();
	bt.erase(7);
	bt.Inorder();
	bt.erase(6);
	bt.Inorder();
	bt.erase(9);
	bt.Inorder();
}
int main()
{
	testTree();
	return 0;
}