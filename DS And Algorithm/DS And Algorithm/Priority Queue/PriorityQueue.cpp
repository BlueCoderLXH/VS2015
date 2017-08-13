#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(uint capacity)
{
	if (capacity < MinPQSize)
	{
		Debug::LogWarning("capacity:" + to_string(capacity) + " is too small!");
		return;
	}

	m_elements = new ElementType[capacity];
	if (m_elements == nullptr)
	{
		Debug::LogError("Can't allocate memory for Priority Queue!");
		return;
	}

	m_capacity = capacity;
	m_size = 0;

	m_elements[0] = MinTypeData;
}

PriorityQueue::~PriorityQueue()
{
	Destroy();
}

void PriorityQueue::MakeEmpty()
{
	for (uint i = 0; i < m_size; i++)
	{
		m_elements[i] = MinTypeData;
	}

	m_size = 0;
}

void PriorityQueue::Destroy()
{
	MakeEmpty();

	if (m_elements)
	{
		delete m_elements;
		m_elements = nullptr;

		m_size = 0;
		m_capacity = 0;
	}
}

bool PriorityQueue::IsEmpty()
{
	return m_size == 0u;
}

bool PriorityQueue::IsFull()
{
	return m_size == m_capacity;
}

void PriorityQueue::Insert(ElementType element)
{
	if (IsFull())
	{
		Debug::Log("Priority Queue is full!");
		return;
	}

	uint i;
	for (i = ++m_size; element < m_elements[i / 2] && i > RootIndex; i /= 2)
	{
		m_elements[i] = m_elements[i / 2];
	}

	m_elements[i] = element;
}

void PriorityQueue::DeleteMin()
{
	if (IsEmpty())
	{
		Debug::Log("Priority Queue is empty!");
		return;
	}

	ElementType lastElement = m_elements[m_size--];

	uint i, child;
	for (i = RootIndex; i * 2 < m_size; i = child)
	{
		child = i * 2;
		if (child + 1 < m_size && m_elements[child + 1] < m_elements[child])
		{
			child++;
		}

		if (lastElement > m_elements[child])
		{
			m_elements[i] = m_elements[child];
		}
		else
		{
			break;
		}
	}

	m_elements[i] = lastElement;
}

ElementType PriorityQueue::FindMin()
{
	if (IsEmpty())
	{
		Debug::Log("Priority Queue is empty!");
		return MinTypeData;
	}

	return m_elements[RootIndex];
}