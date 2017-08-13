#pragma once
#include "../Common/Common.h"

typedef unsigned int uint;
typedef int ElementType;

/*
 * PriorityQueue
 * 优先队列
 * (这里默认是小根堆)
 *     优先队列是用二叉堆实现的, 由于是一颗完全二叉树, 所以使用数组实现,
 * 为了保持堆性质, 下标从1开始.
 */
class  PriorityQueue
{
private:
	static const uint MinPQSize = 1;
	static const uint RootIndex = 1;
	static const ElementType MinTypeData = -1000000;
	static const ElementType MaxTypeData = 1000000;

private:
	uint m_capacity;
	uint m_size;
	ElementType* m_elements;

public:
	PriorityQueue(uint capacity);
	~PriorityQueue();

	void MakeEmpty();
	void Destroy();

	bool IsEmpty();
	bool IsFull();
	
	/*
	    插入算法思想(上滤策略):
		先将element插入堆的尾部, 从这个节点往父节点遍历, 如果发现比父节点小, 交换;
	否则, 插入成功.
	*/
	void Insert(ElementType element);

	/*
	    删除算法思想(下滤策略):
		删除树根节点, 获取尾节点tail, 每次获得当前根节点root的孩子节点中较小的一个minChild,
	并与tail节点比较, 如果小之, child节点放到root节点上; child作为下一层的根节点, 继续上诉
	操作, 直至tail节点小于minChild节点
	*/
	void DeleteMin();

	ElementType FindMin();

	string ToString()
	{
		string ret = "";
		for (uint i = RootIndex; i <= m_size; i++)
		{
			ret += to_string(m_elements[i]) + " ";
		}

		return ret;
	}
};