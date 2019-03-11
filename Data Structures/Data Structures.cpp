// Data Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "_stack.h"
#include "_queue.h"
#include "_heap.h"

int main()
{
	_stack<int> myStack;

	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.peek(2);
	myStack.pop();

	_queue<int> myQueue;

	myQueue.enqueue(1);
	myQueue.enqueue(2);
	myQueue.enqueue(3);
	myQueue.dequeue();
	myQueue.elementNum();

	_heap<int> myHeap;

	myHeap.add(5);
	myHeap.add(4);
	myHeap.add(3);
	myHeap.add(2);
	myHeap.add(1);
	myHeap.remove();
	myHeap.sort();

	return 0;
}
