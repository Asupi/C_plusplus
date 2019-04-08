#define _CRT_SECURE_NO_WARNINGS 
//用两个栈实现队列：
//1.入队栈：只负责入数据
//2.出队栈：只负责出数据
//push：给入队栈push
//pop：如果出队栈为空，把入队栈元素全部倒过来，出栈顶元素；如果不为空，直接出栈顶元素
//
//使用栈实现队列的下列操作：
//*
//push(x) --将一个元素放入队列的尾部。
//*
//pop() --从队列首部移除元素。
//*
//peek() --返回队列首部的元素。
//*
//empty() --返回队列是否为空。



class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
		//系统自动调用自定义类型的构造函数
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		_pushS.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (_popS.empty())
		{
			//到入队栈的元素到出队栈
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
			//到入队栈的元素到出队栈
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



//用两个队列实现栈：
//栈：后进先出
//1.始终保持一个队列是空的
//2.入栈时，元素向非空列表入队
//3.出栈时，元素先导入空队列，出非空的最后一个元素
//
//
//使用队列实现栈的下列操作：
//*
//push(x) --元素 x 入栈
//*
//pop() --移除栈顶元素
//*
//top() --获取栈顶元素
//*
//empty() --返回栈是否为空



class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {


	}


	/** Push element x onto stack. */
	void push(int x) {
		//元素存放到非空的队列中
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
			//非空队列中的元素导入到空队中，最后一个元素不需要导入，直接pop
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