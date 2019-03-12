#pragma once

#ifndef _STACK_H
#define _STACK_H

#include <iostream>

template <class T> class _stack
{
public:
	_stack(int MaxSize = 100);
	~_stack();

	void push(const T &item);
	T pop();
	bool empty();
	const int size();
	const T &top();

private:

	int Size;
	T *Data;
	const int MAX_SIZE;
};

template <class T> _stack<T>::_stack(int MaxSize) : MAX_SIZE(MaxSize)
{
	Size = 0;
	Data = new T[MAX_SIZE];
}

template <class T> _stack<T>::_stack::~_stack()
{
	delete Data;
}

template <class T> void _stack<T>::push(const T &item)
{
	if (Size == MAX_SIZE)
	{
		std::cout << "Stack overflow" << std::endl;
		return;
	}

	Data[Size++] = item;
}

template <class T> T _stack<T>::pop()
{
	if (empty())
	{
		std::cout << "Stack underflow" << std::endl;
		return;
	}

	return Data[--Size];
}

template <class T> bool _stack<T>::empty()
{
	return Size == 0;
}

template <class T> const int _stack<T>::size()
{
	return Size;
}

template <class T> const T &_stack<T>::top()
{
	return Data[Size - 1];
}

#endif // !_STACK_H