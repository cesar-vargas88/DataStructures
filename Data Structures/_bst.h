#pragma once

#ifndef _BST_H
#define _BST_H

#include <iostream>

template<class T> class btNode
{

public:

	T Data;
	btNode<T> *Left;
	btNode<T> *Right;
};

template <class T> class _bst
{
public:
	_bst();
	~_bst();

	void addLeaf(const T &item);
	void printPreOrder();
	void printInOrder();
	void printPostOrder();
	btNode<T> *returnNode(const T &item);
	T returnRootKey();
	void printChildren(const T &item);
	T findSmallest();

protected:

	btNode<T> *createLeaf(const T &item);
	void addLeafPrivate(btNode<T> *node, const T &item);
	void printPreOrderPrivate(btNode<T> *node);
	void printInOrderPrivate(btNode<T> *node);
	void printPostOrderPrivate(btNode<T> *node);
	btNode<T> *returnNodePrivate(btNode<T> *node, const T &item);
	T findSmallestPrivate(btNode<T> *node);

	btNode<T> *Root;
};

// Public

template <class T> _bst<T>::_bst()
{
	Root = NULL;
}

template <class T> _bst<T>::~_bst()
{
}

template <class T> void _bst<T>::addLeaf(const T &item)
{
	addLeafPrivate(Root, item);
}

template <class T> void _bst<T>::printPreOrder()
{
	if (Root != NULL)
		printPreOrderPrivate(Root);
	else
		std::cout << "The tree is empty.";
}

template <class T> void _bst<T>::printInOrder()
{
	if (Root != NULL)
		printInOrderPrivate(Root);
	else
		std::cout << "The tree is empty.";
}

template <class T> void _bst<T>::printPostOrder()
{
	if (Root != NULL)
		printPostOrderPrivate(Root);
	else
		std::cout << "The tree is empty.";
}

template <class T> btNode<T> *_bst<T>::returnNode(const T &item)
{
	return returnNodePrivate(Root, item);
}

template <class T> T _bst<T>:: returnRootKey()
{
	if (Root != NULL)
		return Root->Data;
	else
		return (T) -1000;
}

template <class T> void _bst<T>::printChildren(const T &item)
{
	btNode<T> *node = returnNode(item);

	if (node != NULL)
	{
		std::cout << "Parent node " << node->Data << std::endl;

		node->Left == NULL ?
			std::cout << "Left child = NULL " << std::endl	:
			std::cout << "Left child = " << node->Left->Data << std::endl;

		node->Right == NULL ?
			std::cout << "Right child = NULL " << std::endl :
			std::cout << "Right child = " << node->Right->Data << std::endl;

	}
	else
		std::cout << "Key " << item << " is not in the tree" << std::endl;
}

template <class T> T _bst<T>::findSmallest()
{
	if (Root != NULL)
		return findSmallestPrivate(Root);
	else
	{
		std::cout << "The tree is empty.";
		return (T)-1000;
	}
}

// Private

template <class T> btNode<T> *_bst<T>::createLeaf(const T &item)
{
	btNode<T> *node = new btNode<T>;

	node->Data = item;
	node->Left = NULL;
	node->Right = NULL;

	return node;
}

template <class T> void _bst<T>::addLeafPrivate(btNode<T> *node, const T &item)
{
	if (Root == NULL)
		Root = createLeaf(item);
	else if (item < node->Data)
	{
		if (node->Left != NULL)
			addLeafPrivate(node->Left, item);
		else
			node->Left = createLeaf(item);
	}
	else if (item > node->Data)
	{
		if (node->Right != NULL)
			addLeafPrivate(node->Right, item);
		else
			node->Right = createLeaf(item);
	}
	else
		std::cout << "The key " << item << " has already been added to the tree." << std::endl;
}

template <class T> void _bst<T>::printPreOrderPrivate(btNode<T> *node)
{
	if (node == NULL)
		return;

	std::cout << node->Data << " ";
	printPreOrderPrivate(node->Left);
	printPreOrderPrivate(node->Right);
}

template <class T> void _bst<T>::printInOrderPrivate(btNode<T> *node)
{
	if (node == NULL)
		return;

	printInOrderPrivate(node->Left);
	std::cout << node->Data << " ";
	printInOrderPrivate(node->Right);
}

template <class T> void _bst<T>::printPostOrderPrivate(btNode<T> *node)
{
	if (node == NULL)
		return;

	printPostOrderPrivate(node->Left);
	printPostOrderPrivate(node->Right);
	std::cout << node->Data << " ";
}

template <class T> btNode<T> *_bst<T>::returnNodePrivate(btNode<T> *node, const T &item)
{
	if (node != NULL)
	{
		if (node->Data == item)
			return node;
		else
		{
			if (item < node->Data)
				return returnNodePrivate(node->Left, item);
			else
				return returnNodePrivate(node->Right, item);
		}
	}
	else
		return NULL;
}

template <class T> T _bst<T>::findSmallestPrivate(btNode<T> *node)
{
	if (node->Left != NULL)
		return findSmallestPrivate(node->Left);
	else
		return node->Data;
}

#endif // !