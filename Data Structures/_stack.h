#pragma once

#include <assert.h> 

#ifndef _STACK_H
#define _STACK_H

template <class T> class _stack
{
public:
	_stack(int MaxSize = 500);
	_stack(const _stack<T> &otherStack);
	~_stack();

	inline void push(const T &item);
	inline T pop(void);
	inline const T &peek(int depth) const;
	inline bool isEmpty();

protected:
	T *data;
	int CurrentElementNumber;
	const int MAX_NUM;
};

template <class T> _stack<T>::_stack(int MaxSize) : MAX_NUM(MaxSize)
{
	data = new T[MAX_NUM];
	CurrentElementNumber = 0;
}

template <class T> _stack<T>::_stack(const _stack<T> &otherStack) : MAX_NUM(otherStack.MAX_NUM)
{
	data = new T[MAX_NUM];
	CurrentElementNumber = otherStack.CurrentElementNumber;
}

template <class T> _stack<T>::~_stack()
{
	delete[] data;
}

template <class T> inline void _stack<T>::push(const T &item) 
{
	// Error Check: Make sure we aren't exceeding the maximum storage space
	assert(CurrentElementNumber < MAX_NUM);

	data[CurrentElementNumber++] = item;
}

template <class T> inline T _stack<T>::pop(void)
{
	// Error Check: Make sure we aren't popping from an empty Stack
	assert(CurrentElementNumber > 0);

	return data[--CurrentElementNumber];
}

template <class T> inline const T &_stack<T>::peek(int depth) const
{
	// Error Check: Make sure the depth doesn't exceed the number of elements
	assert(depth < CurrentElementNumber);

	return data[CurrentElementNumber - (depth + 1)];
}

template <class T> inline bool _stack<T>::isEmpty()
{
	if (CurrentElementNumber == 0)
		return true;
	else
		false;
}

#endif