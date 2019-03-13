#pragma once

#ifndef _BST_H
#define _BST_H

#include <iostream>

template<class T> class Node
{

public:

	Node(T data)
	{
		Data = data;
		left->NULL;
		right->NULL;
	}
	~Node()
	{

	}

	T Data;
	Node<T> *left;
	Node<T> *right;
};

template <class T> class _bst
{
public:
	_bst();
	~_bst();

	void insert(const T item);
	const Node<T> *remove(const T &item);
	void display();
	Node<T> *search(const T &item);


protected:

	const Node<T> *find(const T*item, T val);

	Node<T> * root;
};

template <class T> _bst<T>::_bst()
{
}

template <class T> _bst<T>::~_bst()
{
}

#endif // !