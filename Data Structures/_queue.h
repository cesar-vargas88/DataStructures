#pragma once

#ifndef _QUEUE_H
#define _QUEUE_H

template <class T> class _queue
{
public:
	_queue(int MaxSize = 100);
	~_queue();

	void push(const T &item);
	const T pop();
	const T &front();
	const T &back();
	bool empty();
	const int size();

private:

	int Size;
	int Front;
	int Back;
	T *Data;
	const int MAX_SIZE;
};

template <class T> _queue<T>::_queue(int MaxSize) : MAX_SIZE(MaxSize)
{
	Size = 0;
	Front = 0;
	Back = 0;
	Data = new T[MAX_SIZE];
}

template <class T> _queue<T>::~_queue()
{
	delete Data;
}

template <class T> void _queue<T>::push(const T &item)
{
	if (Size == MAX_SIZE)
	{
		std::cout << "Stack overflow" << std::endl;
		return;
	}

	if (Front == Back)
	{
		Front = 0;
		Back = 0;
	}

	++Size;

	Data[Back++] = item;
}

template <class T> const T _queue<T>::pop()
{
	if (empty())
	{
		std::cout << "Stack underflow" << std::endl;
		return Data[Front];
	}

	--Size;

	return Data[Front++];
}

template <class T> const T &_queue<T>::front()
{
	return Data[Front];
}

template <class T> const T &_queue<T>::back()
{
	if (empty())
		return Data[Front];

	return Data[Back - 1];
}

template <class T> bool _queue<T>::empty()
{
	if (Front == Back)
		return true;
	else
		return false;
}

template <class T> const int _queue<T>::size()
{
	return Size;
}


#endif // !_QUEUE_H