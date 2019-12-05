#pragma once
#include <iostream>
template <class T> class Node
{
public:

	Node() {};

	T data = NULL;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
};

