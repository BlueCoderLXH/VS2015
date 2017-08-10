#include "BTree/BTree.h"

int main()
{
	//int values[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1 };

	//int values[] = { 1, 2, -1, -1, 3, 4, -1, -1, -1, -1 };

	// BST
	int values[] = { 4, 2, 1, -1, -1, 3, -1, -1, 6, 5, -1, -1, 7, -1, -1 };

	BTree btree(values);

	cout << "Pre Order:\t";
	btree.PreOrder(btree.GetRoot());
	cout << endl;

	cout << "In Order:\t";
	btree.InOrder(btree.GetRoot());
	cout << endl;

	cout << "Post Order:\t";
	btree.PostOrder(btree.GetRoot());
	cout << endl;

	cout << "Level Order:\t";
	btree.LevelOrder();
	cout << endl;

	cout << "Height:\t\t" << btree.GetHeight(btree.GetRoot()) << endl;
	cout << "LeafCount:\t" << btree.CountLeaf(btree.GetRoot()) << endl;

	cout << "Is BST:\t\t" << (btree.IsBST(btree.GetRoot()) ? "true" : "false") << endl;

	return 0;
}