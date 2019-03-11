#pragma once

#include <assert.h> 

#ifndef _QUEUE_H
#define _QUEUE_H

template <class T> class _queue
{
public:
	_queue(int MaxSize = 500);
	_queue(const _queue<T> &otherQueue);
	~_queue();

	void enqueue(const T &item);
	T dequeue(void);
	inline int elementNum(void);

protected:
	T *data;
	const int MAX_NUM;
	int beginning;
	int end;
	int elementCount;
};

template <class T> _queue<T>::_queue(int MaxSize) : MAX_NUM(MaxSize)
{ 
	data = new T[MAX_NUM + 1];
	beginning = 0;
	end = 0;
	elementCount = 0;
}

template <class T>  _queue<T>::_queue(const _queue &otherQueue) : MAX_NUM(otherQueue.MAX_NUM)
{
	beginning = otherQueue.beginning;
	end = otherQueue.end;
	elementCount = otherQueue.elementCount;

	data = new T[MAX_NUM + 1];

	for (int index = 0; index < MAX_NUM; index++)
		data[index] = otherQueue.data[index];
}

template <class T> _queue<T>::~_queue()
{
	delete[] data;
}

template <class T> void _queue<T>::enqueue(const T &item)
{
	// Error Check : Make sure we aren't exceeding our maximum storage space
	assert(elementCount < MAX_NUM);

	data[end++] = item;
	++elementCount;

	// Check for wrap-around
	if (end > MAX_NUM)
		end -= (MAX_NUM + 1);
}

template <class T> T _queue<T>::dequeue(void)
{
	// Error Check: Make sure we aren't dequeueing from an empty queue
	assert(elementCount > 0);

	T ReturnValue = data[beginning++];
	--elementCount;

	// Check for wrap-around
	if (beginning > MAX_NUM)
		beginning -= (MAX_NUM + 1);

	return ReturnValue;
}

template <class T> inline int _queue<T>::elementNum(void)
{
	return elementCount;
}

#endif