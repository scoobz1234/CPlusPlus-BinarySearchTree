#include "BST.h"

using namespace std;

template <class T> BST<T>::BST() 
{
	root = nullptr;
}

/*/ SUMMARY ///
This function creates a new node with no children pointers.
/// SUMMARY /*/
/// <summary>
/// 
/// </summary>
/// <param name="value"></param>
/// <returns></returns>
template <class T> Node<T>* BST<T>::mCreateNode(T& value)
{
	Node<T>* n = new Node<T>;
	n->data = value;
	n->leftChild = nullptr;
	n->rightChild = nullptr;

	return n;
}

/*/ SUMMARY ///
Internal or private function that calls itself Recursively
checks if the root node exists, if it doesnt, it will create a new
node and assignt rootnode to the new node that was created...
next we check if the value were trying to add is less or greater than
the rootnode.
/// SUMMARY /*/
/// <summary>
/// 
/// </summary>
/// <param name="value"></param>
/// <param name="currentNode"></param>
template <class T> void BST<T>::mAddNode(T& value, Node<T>* currentNode) 
{
	if (root == nullptr)
	{
		root = mCreateNode(value);
	}
	else if (value < currentNode->data) 
	{
		if (currentNode->leftChild != nullptr)
		{
			mAddNode(value, currentNode->leftChild);
		}
		else 
		{
			currentNode->leftChild = mCreateNode(value);
		}
	}
	else if (value > currentNode->data) 
	{
		if (currentNode->rightChild != nullptr)
		{
			mAddNode(value, currentNode->rightChild);
		}
		else 
		{
			currentNode->rightChild = mCreateNode(value);
		}
	}
	else 
	{ 
		cout << "Value of: " << value << " Already exists in the tree" << endl;
	}
}

/*/ SUMMARY ///
This function prints the entire tree in order...
First we check if the tree is empty
next we check if the current node has a left node
if it does we call the function recursively and print the function with the left node..
then we move right and call recursively to do the same...
/// SUMMARY /*/
/// <summary>
/// 
/// </summary>
/// <param name="currentNode"></param>
template <class T> void BST<T>::mPrintTree(Node<T>* currentNode) 
{
	if (root != nullptr)
	{
		if (currentNode->leftChild != nullptr)
		{
			mPrintTree(currentNode->leftChild);
		}

		cout << currentNode->data << ", ";

		if (currentNode->rightChild != nullptr)
		{
			mPrintTree(currentNode->rightChild);
		}
	}

	else 
	{
		cout << "Tree is empty!" << endl;
	}
}

/*/ SUMMARY ///
This function returns a node if its found in the tree..
we check if the node is not null, if the node = the value,
we return the node, else we keep iterating through Recursivly
/// SUMMARY /*/
/// <summary>
/// 
/// </summary>
/// <param name="value"></param>
/// <param name="currentNode"></param>
/// <returns></returns>
template <class T> Node<T>* BST<T>::mReturnNode(T& value, Node<T>* currentNode) 
{
	if (currentNode != nullptr)
	{
		if (currentNode->data == value) 
		{
			return currentNode;
		}
		else 
		{
			if (value < currentNode->data) 
			{
				return mReturnNode(value, currentNode->leftChild);
			}
			else 
			{
				return mReturnNode(value, currentNode->rightChild);
			}
		}
	}
	else 
	{
		return nullptr;
	}
}


/*/ SUMMARY ///
This function prints the children of a given value...
We create a node and set it to the return value of ReturnNode function...
Then as long as its not a nullpointer, meaning it does exist, we print the info
/// SUMMARY /*/
/// <summary>
/// 
/// </summary>
/// <param name="currentNode"></param>
template <class T> void BST<T>::mPrintChildren(Node<T>* currentNode) 
{

	if (currentNode != nullptr)
	{
		cout << "Node value = " << currentNode->data << endl;

		currentNode->leftChild == nullptr ? 
			cout << "No Left Child\n" :
			cout << "Left Child = " << currentNode->leftChild->data << endl;

		currentNode->rightChild == nullptr ? 
			cout << "No Right Child\n" :
			cout << "Right Child = " << currentNode->rightChild->data << endl;

			cout << "\n";

		if (currentNode->leftChild != nullptr) {
			mPrintChildren(currentNode->leftChild);
		}
		if (currentNode->rightChild != nullptr) {
			mPrintChildren(currentNode->rightChild);
		}
	}
}

/*/ SUMMARY ///
This function finds and returns the smallest value in the tree..
we check if the tree is not empty, and if its not we traverse
through the left side of the list, the left most node will be the smallest value.
/// SUMMARY /*/
template <class T> T BST<T>::mFindSmallest(Node<T>* currentNode) 
{

	if (root == nullptr)
	{
		cout << "Tree is empty" << endl;
		return -1000;
	}
	else {
		if (currentNode->leftChild != nullptr)
		{
			return mFindSmallest(currentNode->leftChild);
		}
		else 
		{
			return currentNode->data;
		}
	}
}

/*/ SUMMARY ///
This function will find the largest value in a tree.
Checks for empty list, then iterates recursivly
through the right side of the list, right most node is largest value.
/// SUMMARY /*/
template <class T> T BST<T>::mFindLargest(Node<T>* currentNode) 
{

	if (root == nullptr)
	{
		cout << "Tree is empty" << endl;
		return NULL;
	}
	else 
	{
		if (currentNode->rightChild != nullptr)
		{
			return mFindLargest(currentNode->rightChild);
		}
		else 
		{
			return currentNode->data;
		}
	}
}

/*/ SUMMARY ///
This function removes a node from the tree...
First we check if the list is empty, then we check if the value is the root node.
if its the root node, we call the RemoveRoot function which will remove the root node.
If the value is not the root node, we check if the value is greater than or less than the root node
If its less we move left until we find it. if its more we move right until we find it.
This function is recursive.
/// SUMMARY /*/
template <class T> void BST<T>::mRemoveNode(T& value, Node<T>* currentNode) 
{
	if (root != nullptr)
	{
		if (root->data == value) 
		{
			mRemoveRoot();
		}
		else 
		{
			if (value < currentNode->data && currentNode->leftChild != nullptr)
			{
				currentNode->leftChild->data == value ?
					mRemoveNodeFound(currentNode, currentNode->leftChild, true) :
					mRemoveNode(value, currentNode->leftChild);
			}
			else if (value > currentNode->data && currentNode->rightChild != nullptr)
			{
				currentNode->rightChild->data == value ?
					mRemoveNodeFound(currentNode, currentNode->rightChild, false) :
					mRemoveNode(value, currentNode->rightChild);
			}
			else 
			{
				cout << "Value of: " << value << " Not found!" << endl;
			}
		}
	}
	else 
	{
		cout << "Tree is empty" << endl;
	}
}

/*/ SUMMARY ///
This function is specific to removing the root node..
If the root node is not null we can move forward..
First we make a copy of the node were deleting which in this case is the root.
Next we create a variable to hold the smallest value in the right side of the list.
Next there are three cases we check for, if the root node has 0 children, 1 child, or 2 children.
if there are no children we just delete the node and set the root to null
if there are 1 child, we check to see if its a right child or a left child and act accodringly.
if there are two children we find the smallest value in the right tree, set the variable smallestvalue to that value
and we set the root node to the value we copied, this replaces the node instead of deleting it.
/// SUMMARY /*/
template <class T> void BST<T>::mRemoveRoot() 
{
	if (root != nullptr)
	{
		Node<T>* nodeToDelete = root;
		T smallestValueInRight;

		if (root->leftChild == nullptr && root->rightChild == nullptr)
		{
			root = nullptr;
			delete nodeToDelete;
		}

		else if (root->leftChild == nullptr && root->rightChild != nullptr)
		{
			root = root->rightChild;
			nodeToDelete->rightChild = nullptr;
			delete nodeToDelete;
			cout << "Root Node was deleted" << "\nNew root key is: " << root->data << endl;
		}

		else if (root->leftChild != nullptr && root->rightChild == nullptr)
		{
			root = root->leftChild;
			nodeToDelete->leftChild = nullptr;
			delete nodeToDelete;
			cout << "Root Node was deleted" << "\nNew root key is: " << root->data << endl;
		}

		else 
		{
			smallestValueInRight = mFindSmallest(root->rightChild);
			mRemoveNode(smallestValueInRight, root);
			root->data = smallestValueInRight;
			cout << "The Root value was replaced with " << root->data << endl;
		}
	}
	else 
	{
		cout << "Tree is empty, could not remove the root node" << endl;
	}
}

/*/ SUMMARY ///
This function removes the node found in the Internal Remove Node function.
there are again three cases, 0,1, and 2 children.
if there is 1 child, we check which side right or left.
/// SUMMARY /*/
template <class T> void BST<T>::mRemoveNodeFound(Node<T>* parentNode, Node<T>* selectedNode, bool isLeft)
{
	if (root != nullptr)
	{
		Node<T>* nodeToDelete = nullptr;
		T smallestValueInRight;

		if (selectedNode->leftChild == nullptr && selectedNode->rightChild == nullptr)
		{
			nodeToDelete = selectedNode;
			isLeft == true ? parentNode->leftChild = nullptr : parentNode->rightChild = nullptr;
			delete nodeToDelete;
			cout << "Node was removed!" << endl;
		}

		else if (selectedNode->leftChild == nullptr && selectedNode->rightChild != nullptr)
		{
			isLeft == true ? parentNode->leftChild = selectedNode->rightChild :
				parentNode->rightChild = selectedNode->rightChild;
			selectedNode->rightChild = nullptr;
			nodeToDelete = selectedNode;
			delete nodeToDelete;
			cout << "Node was removed!" << endl;
		}

		else if (selectedNode->leftChild != nullptr && selectedNode->rightChild == nullptr)
		{
			isLeft == true ? parentNode->leftChild = selectedNode->leftChild :
				parentNode->rightChild = selectedNode->leftChild;
			selectedNode->leftChild = nullptr;
			nodeToDelete = selectedNode;
			delete nodeToDelete;
			cout << "Node was removed!" << endl;
		}

		else
		{
			smallestValueInRight = mFindSmallest(selectedNode->rightChild);
			mRemoveNode(smallestValueInRight, selectedNode);
			selectedNode->data = smallestValueInRight;
		}
	}
	else
	{
		cout << "Tree is empty or Node not found" << endl;
	}
}

/*/ SUMMARY ///
This function acts as post order traversal
It will check if the tree is empty, then delete the nodes starting from
the left most node, moving to the right.
lastly it deletes the rootnode.
/// SUMMARY /*/
template <class T> void BST<T>::mRemoveTree(Node<T>* rootNode) 
{
	if (rootNode != nullptr)
	{
		if (rootNode->leftChild != nullptr) {
			mRemoveTree(rootNode->leftChild);
		}
		if (rootNode->rightChild != nullptr) {
			mRemoveTree(rootNode->rightChild);
		}
		cout << "Deleting node: " << rootNode->data << endl;
		delete rootNode;
	}
}