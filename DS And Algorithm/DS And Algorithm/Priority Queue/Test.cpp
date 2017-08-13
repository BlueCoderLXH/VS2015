#include "PriorityQueue.h"

int main()
{
	ElementType data[] = { 13, 21, 16, 24, 31, 19, 68, 65, 26, 32 };

	PriorityQueue* priorityQuque = new PriorityQueue(15);

	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		priorityQuque->Insert(data[i]);
	}

	Debug::PrintLine("PriorityQueue:");
	Debug::PrintLine(priorityQuque->ToString());

	Debug::PrintLine();

	Debug::PrintLine("Insert: 14");
	priorityQuque->Insert(14);
	Debug::PrintLine(priorityQuque->ToString());

	Debug::PrintLine();

	Debug::PrintLine("Delete: " + to_string(priorityQuque->FindMin()));
	priorityQuque->DeleteMin();
	Debug::PrintLine(priorityQuque->ToString());

	SAFE_DELETE_PTR(priorityQuque);
	return 0;
}