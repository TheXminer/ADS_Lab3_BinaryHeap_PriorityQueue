#include "priorityQueue.h"

int MaxHeap::getParent(int index) {
	return (index - 1) / 2;
}

int MaxHeap::getLeftChild(int index) {
	return 2 * index + 1;
}

int MaxHeap::getRightChild(int index) {
	return 2 * index + 2;
}

int MaxHeap::maxChildIndex(int first, int second) {
	if (dataVector[first] < dataVector[second])
		return second;
	return first;
}

void MaxHeap::swap(int first, int second) {
	Data copy = dataVector[first];
	dataVector[first] = dataVector[second];
	dataVector[second] = copy;
}

void MaxHeap::siftUp(int index) {
	if (dataVector.size() - 1 < index || index == 0)
		return;
	int parent = getParent(index);
	if (dataVector[index] < dataVector[parent])
		return;
	swap(parent, index);
	siftUp(parent);
}

void MaxHeap::siftDown(int index) {
	int leftChild = getLeftChild(index);
	int rightChild = getRightChild(index);
	int maxChild = leftChild;
	if (leftChild >= dataVector.size())
		return;
	if (rightChild < dataVector.size())
		maxChild = maxChildIndex(leftChild, rightChild);
	if (dataVector[maxChild] < dataVector[index])
		return;
	swap(maxChild, index);
	siftDown(maxChild);
}