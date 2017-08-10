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
 * ������������Ӧ�㷨ʵ��
 */
class BTree
{
protected:
	BTreeNode* m_root;

	// �����������������
	void CreateBTree(BTreeNode* &node, int values[]);

	// �������ɾ��������
	void DestroyTree(BTreeNode* &node);

public:
	BTree(int values[]);
	virtual ~BTree();

	BTreeNode* GetRoot() { return m_root; }

	// �������
	void PreOrder(BTreeNode* node);

	// �������
	void InOrder(BTreeNode* node);

	// �������
	void PostOrder(BTreeNode* node);

	// �������
	void LevelOrder();

	/*
	 * �������ĸ߶�
	 * ������˵����
	 * 1����0��ʼ(Ҷ�ڵ�߶�Ϊ0) -- ����
	 * 2����1��ʼ(ҵ����߶�Ϊ1) -- ����
	 */
	int GetHeight(BTreeNode* node);

	// ͳ��Ҷ�ӽڵ���
	int CountLeaf(BTreeNode* node);

	// �Ƿ��Ƕ��������(Binary Search Tree)
	bool IsBST(BTreeNode* node);
};