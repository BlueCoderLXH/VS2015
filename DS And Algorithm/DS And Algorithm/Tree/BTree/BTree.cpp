#include "BTree.h"

BTree::BTree(int values[])
{
	CreateBTree(m_root, values);
}

BTree::~BTree()
{
	DestroyTree(m_root);
}

void BTree::CreateBTree(BTreeNode* &node, int values[])
{
	static int index = -1;

	index++;

	if (values[index] == InvalidValue)
	{
		node = nullptr;
	}
	else
	{
		node = static_cast<BTreeNode*>(malloc(sizeof(BTreeNode)));
		node->Val = values[index];

		CreateBTree(node->Left, values);
		CreateBTree(node->Right, values);
	}
}

void BTree::DestroyTree(BTreeNode* &node)
{
	if (node)
	{
		DestroyTree(node->Left);
		DestroyTree(node->Right);

		SAFE_FREE_PTR(node);
	}
}

void BTree::PreOrder(BTreeNode* node)
{
	if (node)
	{
		Debug::Print(to_string(node->Val) + " ");

		PreOrder(node->Left);
		PreOrder(node->Right);
	}
}

void BTree::InOrder(BTreeNode* node)
{
	if (node)
	{
		InOrder(node->Left);

		Debug::Print(to_string(node->Val) + " ");

		InOrder(node->Right);
	}
}

void BTree::PostOrder(BTreeNode* node)
{
	if (node)
	{
		PostOrder(node->Left);
		PostOrder(node->Right);

		Debug::Print(to_string(node->Val) + " ");
	}
}

void BTree::LevelOrder()
{
	queue<BTreeNode*> nodeQueue;

	nodeQueue.push(m_root);

	while (!nodeQueue.empty())
	{
		BTreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		Debug::Print(to_string(node->Val) + " ");

		if (node->Left)
		{
			nodeQueue.push(node->Left);
		}

		if (node->Right)
		{
			nodeQueue.push(node->Right);
		}
	}
}

int BTree::GetHeight(BTreeNode* node)
{
	if (!node)
	{
		return 0;
	}

	int leftHeight = GetHeight(node->Left);
	int rightHeight = GetHeight(node->Right);

	return max(leftHeight, rightHeight) + ((node == m_root) ? 0 : 1);
}

int BTree::CountLeaf(BTreeNode* node)
{
	if (!node)
	{
		return 0;
	}

	int leafCount = 0;

	if (!node->Left && !node->Right)
	{
		leafCount = 1;
	}

	leafCount += CountLeaf(node->Left);
	leafCount += CountLeaf(node->Right);

	return leafCount;
}

bool BTree::IsBST(BTreeNode* node)
{
	if (!node)
	{
		return true;
	}

	bool isBST = true;
	isBST &= (node->Left ? (node->Left->Val < node->Val) : true);
	isBST &= (node->Right ? (node->Right->Val > node->Val) : true);

	isBST &= IsBST(node->Left);
	isBST &= IsBST(node->Right);

	return isBST;
}