#pragma once

#ifndef _HEAP_H
#define _HEAP_H

#include <assert.h>

template <class T> class _heap
{
public:
	_heap(int MaxSize = 500);
	_heap(const _heap<T> &otherHeap);
	_heap(T *Array, int ElementNum, int MaxSize);
	~_heap();
	
	T *sort(void);
	bool add(const T &item);
	T remove(void);
	inline int getSize(void);

protected:
	T *data;
	int CurrentNumber;
	const int MAX_SIZE;

	void shiftUp(int node);
	void shiftDown(int node);
	inline int parentOf(int node);
	inline int leftChildOf(int node);
};

template<class T> _heap<T>::_heap(int MaxSize) : MAX_SIZE(MaxSize)
{
	data = new T[MAX_SIZE];
	CurrentNumber = 0;
}

template<class T> _heap<T>::_heap(const _heap<T> &otherHeap) : MAX_SIZE(otherHeap.MaxSize)
{
	data = new T[MAX_SIZE];
	CurrentNumber = otherHeap.CurrentNumber;

	// Copy the array
	for (int index = 0; index < otherHeap.CurrentNumber; ++index)
		data[index] = otherHeap.data[index];
}

template<class T> _heap<T>::_heap(T *Array, int ElementNum, int MaxSize) : MAX_SIZE(MaxSize)
{
	data = new T[MAX_SIZE];
	CurrentNumber = ElementNum;

	// Copy the array
	for (int index = 0; index < ElementNum; ++index)
		data[index] = Array[index];

	for (int index = parentOf(CurrentNumber - 1); index >= 0; --index)
		shiftDown(index);

}

template<class T> _heap<T>::~_heap()
{
	if (data)
		delete data;
}

template<class T> T *_heap<T>::sort(void)
{
	// This is the array that will be returned
	T *NewArray = new T[CurrentNumber];

	// The algorithm works back to front, with the sorted
	// elements being stored in NewArray
	for (int ElemNum = CurrentNumber - 1; ElemNum >= 0; --ElemNum)
	{
		// Since the Remove() function alters CurrentNum by subtracting 1
		// from it each time, we must use a seperate variable to
		// index NewArray.
		NewArray[ElemNum] = remove();
	}

	return NewArray;
}

template<class T> bool _heap<T>::add(const T &item)
{
	if (CurrentNumber >= MAX_SIZE)    // If we have reached our maximum capacity
		return false;

	data[CurrentNumber] = item;
	//shiftUp(CurrentNumber++);
	shiftUp(++CurrentNumber);
	return true;
}

template<class T> T _heap<T>::remove(void)
{
	assert(CurrentNumber > 0);

	T Temp = data[0];
	data[0] = data[--CurrentNumber];  // Replace with the last element
	shiftDown(0);
	return Temp;
}

template<class T> inline int  _heap<T>::getSize(void)
{
	return CurrentNumber;
}

template<class T> void _heap<T>::shiftUp(int node)
{
	int Current = node;
	int Parent = parentOf(Current);
	T Item = data[Current];

	while (Current > 0)  // While Current is not the RootNode
	{
		if (data[Parent] < Item)
		{
			data[Current] = data[Parent];
			Current = Parent;
			Parent = parentOf(Current);
		}
		else
			break;
	}

	data[Current] = Item;
}

template<class T> void _heap<T>::shiftDown(int node)
{
	int Current = node;
	int Child = leftChildOf(Current);
	T Item = data[Current];    // Used to compare values

	while (Child < CurrentNumber)
	{
		if (Child < (CurrentNumber - 1))
			if (data[Child] < data[Child + 1])  // Set Child to largest Child node
				++Child;

		if (Item < data[Child])
		{    // Switch the Current node and the Child node
			data[Current] = data[Child];
			Current = Child;
			Child = leftChildOf(Current);
		}
		else
			break;
	}
	data[Current] = Item;
}

template<class T> inline int _heap<T>::parentOf(int node)
{
	assert(node > 0);
	// This uses the fact that decimals are truncated during
	// the division of integers. Thus, (12 - 1) / 2 == 5
	return (node - 1) / 2;
}

template<class T> inline int _heap<T>::leftChildOf(int node)
{
	return (node * 2) + 1;
}

#endif