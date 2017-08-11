#pragma once
typedef unsigned int uint;
typedef int ElementType;

/*
 * PriorityQueue
 * ���ȶ���
 * (����Ĭ����С����)
 *     ���ȶ������ö����ʵ�ֵ�, ������һ����ȫ������, ����ʹ������ʵ��,
 * Ϊ�˱��ֶ�����, �±��1��ʼ.
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
	    �����㷨˼��(���˲���):
		�Ƚ�element����ѵ�β��, ������ڵ������ڵ����, ������ֱȸ��ڵ�С, ����;
	����, ����ɹ�.
	*/
	void Insert(ElementType element);

	/*
	    ɾ���㷨˼��(���˲���):
	*/
	void DeleteMin();

	ElementType FindMin();
};