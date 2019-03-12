// Data Structures C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "_stack.h"
#include "_queue.h"
#include "_forward_list.h"

using namespace std;

int factorial(int item);
int fibonacci(int item);
int binary_search(int a[], int x, int low, int high);

int main()
{
	_forward_list<int> myForward_List;

	myForward_List.append(1);
	myForward_List.append(2);
	myForward_List.append(3);
	myForward_List.append(4);
	myForward_List.append(5);

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