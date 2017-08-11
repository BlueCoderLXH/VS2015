#include "BTree/BTree.h"

int main()
{
	//int values[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1 };

	//int values[] = { 1, 2, -1, -1, 3, 4, -1, -1, -1, -1 };

	// BST
	int values[] = { 4, 2, 1, -1, -1, 3, -1, -1, 6, 5, -1, -1, 7, -1, -1 };

	BTree btree(values);

	Debug::Print("Pre Order:\t");
	btree.PreOrder(btree.GetRoot());
	Debug::PrintLine();

	Debug::Print("In Order:\t");
	btree.InOrder(btree.GetRoot());
	Debug::PrintLine();

	Debug::Print("Post Order:\t");
	btree.PostOrder(btree.GetRoot());
	Debug::PrintLine();

	Debug::Print("Level Order:\t");
	btree.LevelOrder();
	Debug::PrintLine();

	Debug::PrintLine("Height:\t\t" + to_string(btree.GetHeight(btree.GetRoot())));
	Debug::PrintLine("LeafCount:\t" + to_string(btree.CountLeaf(btree.GetRoot())));
	Debug::PrintLine("Is BST:\t\t" + to_string(btree.IsBST(btree.GetRoot())));

	return 0;
}