#include "priorityQueue.h"

int HeapSort::getParent(int index) {
	return (index - 1) / 2;
}

int HeapSort::getLeftChild(int index) {
	return 2 * index + 1;
}

int HeapSort::getRightChild(int index) {
	return 2 * index + 2;
}

int HeapSort::maxChildIndex(int first, int second) {
	if (arrayToChange[first] < arrayToChange[second])
		return second;
	return first;
}

void HeapSort::swap(int first, int second) {
	int copy = arrayToChange[first];
	arrayToChange[first] = arrayToChange[second];
	arrayToChange[second] = copy;
}

void HeapSort::siftDown(int index, int arraySize) {
	int leftChild = getLeftChild(index);
	int rightChild = getRightChild(index);
	int maxChild = leftChild;
	if (leftChild >= arraySize)
		return;
	if (rightChild < arraySize)
		maxChild = maxChildIndex(leftChild, rightChild);
	if (arrayToChange[maxChild] < arrayToChange[index])
		return;
	swap(maxChild, index);
	siftDown(maxChild, arraySize);
}

void HeapSort::buildHeap(int* array, int arraySize) {
	arrayToChange = array;
	int N = (arraySize) / 2 - 1;
	for (int i = N; i >= 0; i--) {
		siftDown(i, arraySize);
	}
}

void HeapSort::sortHeap(int* array, int arraySize) {
	int currentSize = arraySize;
	buildHeap(array, arraySize);
	for (int i = 0; i < arraySize; i++) {
		swap(0, currentSize - 1);
		currentSize--;
		siftDown(0, currentSize);
	}
}