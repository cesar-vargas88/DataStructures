#pragma once

#ifndef _FORWARD_LIST_H
#define _FORWARD_LIST_H

#include <iostream>

template<class T> class Node
{

public:

	T Data;
	Node<T> *Next;
};

template <class T> class _forward_list
{
public:

	_forward_list();
	~_forward_list();

	bool empty();
	void append(const T &item);
	int pop(int index);
	const int size();
	void reverse();

protected:

	Node<T> *Head;
	int Lenght;
};


template <class T> _forward_list<T>::_forward_list()
{
	Lenght = 0;
	Head = NULL;
}

template <class T> _forward_list<T>::~_forward_list()
{
	delete Head;
}

template <class T> bool _forward_list<T>::empty()
{
	return !size();
}

template <class T> void _forward_list<T>::append(const T &item)
{
	Node<T> *newNode = new Node<T>;
	newNode->Data = item;
	newNode->Next = NULL;

	Node<T> *temp = Head;

	if (temp != NULL)
	{
		while (temp->Next != NULL)
		{
			temp = temp->Next;
		}

		temp->Next = newNode;
		temp = NULL;
	}
	else
		Head = newNode;

	newNode = NULL;
}

template <class T> int _forward_list<T>::pop(int index)
{
	return 0;
}

template <class T> const int _forward_list<T>::size()
{
	return Lenght;
}

template <class T> void _forward_list<T>::reverse()
{
	Node<T> *current = Head;
	Node<T> *next = NULL;
	Node<T> *prev = NULL;

	while (current != NULL)
	{
		// Store next 
		next = current->Next;

		// Reverse current node's pointer 
		current->Next = prev;

		// Move pointers one position ahead. 
		prev = current;
		current = next;
	} 

	Head = prev;
}
#endif  // !_FORWARD_LIST_H