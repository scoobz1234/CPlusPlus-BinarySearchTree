#include <iostream>
#include <cstdlib>
#include "BST.cpp"

using namespace std;

int main(int argc, char* argv) 
{
	int treeList[16] = { 5,25,16,17,18,85,82,99,67,42,38,24,26,27,28,31 };
	BST<int> tree;
	int input = 0;

	for (int i = 0; i < 16; i++) 
	{
		tree.AddNode(treeList[i]);
	}


	cout << "Please select a command from the list (-1 to exit)\n";
	cout << "(1) Add a Node\n";
	cout << "(2) Remove a Node\n";
	cout << "(3) Print Tree\n";
	cout << "(4) Print Children\n";
	cout << "(-1) Exit\n";

	while (input != -1) 
	{
		cout << "--> ";
		cin >> input;
		switch (input) {

		case 1:
			cout << "Enter a value to add. (-1 to cancel)\n";
			cout << "--> ";
			cin >> input;
			if (input != -1) {
				tree.AddNode(input);
				cout << "Node: " << input << " added successfully!" << endl;
			}
			break;

		case 2:
			cout << "Enter a value to delete. (-1 to cancel)\n";
			cout << "Delete Node: ";
			cin >> input;
			if (input != -1)
			{
				tree.RemoveNode(input);
				cout << "Node: " << input << " removed successfully!" << endl;
			}
			break;

		case 3:
			tree.PrintTree();
			cout << "\n-- END OF LIST --\n";
			break;

		case 4:
			tree.PrintChildren();
			break;

		case -1:
			break;
		}
	}

	return 0;
}