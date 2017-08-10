#pragma once

#include <iostream>
using namespace std;

#include <queue>

#define FREE_PTR(ptr)\
if(ptr)\
{\
    free(ptr);\
    ptr = nullptr;\
}

static const int InvalidValue = -1;

typedef struct BinaryTreeNode BTreeNode;
struct BinaryTreeNode
{
	int Val;
	BTreeNode* Left;
	BTreeNode* Right;
};

/*
 * BTree
 * 二叉树及其相应算法实现
 */
class BTree
{
protected:
	BTreeNode* m_root;

	// 先序遍历创建二叉树
	void CreateBTree(BTreeNode* &node, int values[]);

	// 后序遍历删除二叉树
	void DestroyTree(BTreeNode* &node);

public:
	BTree(int values[]);
	virtual ~BTree();

	BTreeNode* GetRoot() { return m_root; }

	// 先序遍历
	void PreOrder(BTreeNode* node);

	// 中序遍历
	void InOrder(BTreeNode* node);

	// 后序遍历
	void PostOrder(BTreeNode* node);

	// 层序遍历
	void LevelOrder();

	/*
	 * 二叉树的高度
	 * 有两种说法：
	 * 1、从0开始(叶节点高度为0) -- 国外
	 * 2、从1开始(业绩点高度为1) -- 国内
	 */
	int GetHeight(BTreeNode* node);

	// 统计叶子节点数
	int CountLeaf(BTreeNode* node);

	// 是否是二叉查找树(Binary Search Tree)
	bool IsBST(BTreeNode* node);
};