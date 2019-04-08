#define _CRT_SECURE_NO_WARNINGS 
//������ջʵ�ֶ��У�
//1.���ջ��ֻ����������
//2.����ջ��ֻ���������
//push�������ջpush
//pop���������ջΪ�գ������ջԪ��ȫ������������ջ��Ԫ�أ������Ϊ�գ�ֱ�ӳ�ջ��Ԫ��
//
//ʹ��ջʵ�ֶ��е����в�����
//*
//push(x) --��һ��Ԫ�ط�����е�β����
//*
//pop() --�Ӷ����ײ��Ƴ�Ԫ�ء�
//*
//peek() --���ض����ײ���Ԫ�ء�
//*
//empty() --���ض����Ƿ�Ϊ�ա�



class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
		//ϵͳ�Զ������Զ������͵Ĺ��캯��
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		_pushS.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (_popS.empty())
		{
			//�����ջ��Ԫ�ص�����ջ
			while (!_pushS.empty())
			{
				_popS.push(_pushS.top());
				_pushS.pop();
			}
		}
		int val = _popS.top();
		_popS.pop();
		return val;
	}

	/** Get the front element. */
	int peek() {
		if (_popS.empty())
		{
			//�����ջ��Ԫ�ص�����ջ
			while (!_pushS.empty())
			{
				_popS.push(_pushS.top());
				_pushS.pop();
			}
		}
		return _popS.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return _popS.empty() && _pushS.empty();
	}
private:
	stack<int>_pushS;
	stack<int>_popS;
};



//����������ʵ��ջ��
//ջ������ȳ�
//1.ʼ�ձ���һ�������ǿյ�
//2.��ջʱ��Ԫ����ǿ��б����
//3.��ջʱ��Ԫ���ȵ���ն��У����ǿյ����һ��Ԫ��
//
//
//ʹ�ö���ʵ��ջ�����в�����
//*
//push(x) --Ԫ�� x ��ջ
//*
//pop() --�Ƴ�ջ��Ԫ��
//*
//top() --��ȡջ��Ԫ��
//*
//empty() --����ջ�Ƿ�Ϊ��



class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {


	}


	/** Push element x onto stack. */
	void push(int x) {
		//Ԫ�ش�ŵ��ǿյĶ�����
		if (!_a.empty()) {
			_a.push(x);
		}
		else {
			_b.push(x);
		}
	}


	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int ret;
		if (_a.empty()) {
			//�ǿն����е�Ԫ�ص��뵽�ն��У����һ��Ԫ�ز���Ҫ���룬ֱ��pop
			while (_b.size() > 1) {
				_a.push(_b.front());
				_b.pop();
			}
			ret = _b.front();
			_b.pop();
		}
		else {
			while (_a.size() > 1) {
				_b.push(_a.front());
				_a.pop();
			}
			ret = _a.front();
			_a.pop();
		}
		return ret;
	}


	/** Get the top element. */
	int top() {
		int ret;
		if (!_a.empty()) {
			ret = _a.back();
		}
		else {
			ret = _b.back();
		}
		return ret;
	}


	/** Returns whether the stack is empty. */
	bool empty() {
		return _a.empty() && _b.empty();
	}
private:
	queue<int> _a;
	queue<int> _b;
};