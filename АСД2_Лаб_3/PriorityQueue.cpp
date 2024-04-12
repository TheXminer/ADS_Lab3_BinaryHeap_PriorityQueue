#include "priorityQueue.h"

void PriorityQueue::push(Data data) {
	heap.dataVector.push_back(data);
	heap.siftUp(heap.dataVector.size() - 1);
}

Data PriorityQueue::top() {
	return heap.dataVector.front();
}

void PriorityQueue::pop() {
	heap.swap(0, heap.dataVector.size() - 1);
	heap.dataVector.pop_back();
	heap.siftDown(0);
}

void PriorityQueue::clean() {
	heap.dataVector.clear();
}

bool PriorityQueue::empty() {
	return heap.dataVector.empty();
}

int PriorityQueue::size() {
	return heap.dataVector.size();
}