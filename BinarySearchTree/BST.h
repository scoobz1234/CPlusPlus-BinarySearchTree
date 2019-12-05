#pragma once
#include "Node.h"
#include <iostream>

template <class T>
class BST {

public:

	//Constructor...
	BST();
	~BST() { mRemoveTree(root); };

public:

	void AddNode(T &value) { mAddNode(value, root); };
	void PrintTree() { mPrintTree(root); };
	void PrintChildren() { mPrintChildren(root); };
	void RemoveNode(T& value) { mRemoveNode(value, root); };

	T ReturnRoot() { return root->data; };
	T FindSmallest() { return mFindSmallest(root); };
	T FindLargest() { return mFindLargest(root); };

protected:

	Node<T>* root;
	Node<T>* mCreateNode(T& value);
	Node<T>* mReturnNode(T& value, Node<T>* currentNode);
	Node<T>* ReturnNode(T& value) { return mReturnNode(value, root); };

	void mAddNode(T& value, Node<T>* currentNode);
	void mPrintTree(Node<T>* currentNode);
	void mPrintChildren(Node<T>* rootNode);
	void mRemoveNode(T& value, Node<T>* parent);
	void mRemoveRoot();
	void mRemoveNodeFound(Node<T>* parentNode, Node<T>* nodeToDelete, bool isLeft);
	void mRemoveTree(Node<T>* currentNode);

	T mFindSmallest(Node<T>* currentNode);
	T mFindLargest(Node<T>* currentNode);
};