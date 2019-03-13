// Data Structures C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
// Sequence containers
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
// Associative containers
#include <set>
#include <map>
// Unordered associative containers
#include <unordered_set>
#include <unordered_map>
// Container adaptors
#include <stack>
#include <queue>

#include "_stack.h"
#include "_queue.h"
#include "_forward_list.h"

using namespace std;

int factorial(int item);
int fibonacci(int item);
int binary_search(int a[], int x, int low, int high);

// List

list<int> reverseList(list<int> List);

int main()
{
	array<int, 5> myArray{ 0, 1, 2, 3, 4};
	vector<int> myVector{ 0, 1, 2, 3, 4 };
	deque<int> myDeque{ 0, 1, 2, 3, 4 };
	forward_list<int> myForward_list{ 0, 1, 2, 3, 4 };
	list<int> myList{ 0, 1, 2, 3, 4 };

	reverseList(myList);

	_forward_list<int> _my_Forward_List;

	_my_Forward_List.append(0);
	_my_Forward_List.append(1);
	_my_Forward_List.append(2);
	_my_Forward_List.append(3);
	_my_Forward_List.append(4);
	_my_Forward_List.reverse();


	return 0;
}


int factorial(int item)
{
	if (item == 0)
		return 1;
	else
		return factorial(item - 1) * item;
}

int fibonacci(int item)
{
	if (item <= 0)
		return 0;
	else if (item == 1)
		return 1;
	else
		return fibonacci(item - 1) + fibonacci(item - 2);
}

int binary_search(int a[], int x, int low, int high)
{
	if (low < high)
		return -1;

	int mid = (low + high) / 2;

	return (x == a[mid] ? mid : x < a[mid] ? binary_search(a, x, low, mid - 1) : binary_search(a, x, mid + 1, high));
}

list<int> reverseList(list<int> List)
{
	list<int> myList;

	for (std::list<int>::iterator it = List.begin(); it != List.end(); ++it)
		myList.push_front(*it);

	return myList;
}