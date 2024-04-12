#include <iostream>
#include <vector>
#include <ctime>
#define nElements 10

using namespace std;

int getParent(int index) {
	return (index - 1) / 2;
}

int getLeftChild(int index) {
	return 2 * index + 1;
}

int getRightChild(int index) {
	return 2 * index + 2;
}

int maxChildIndex(vector<int>* arrayToChange, int first, int second) {
	if (arrayToChange->at(first) < arrayToChange->at(second))
		return second;
	return first;
}

void swap(vector<int>* arrayToChange, int first, int second) {
	int copy = arrayToChange->at(first);
	arrayToChange->at(first) = arrayToChange->at(second);
	arrayToChange->at(second) = copy;
}

void siftDown(vector<int>* arrayToChange, int index, int arraySize) {
	int leftChild = getLeftChild(index);
	int rightChild = getRightChild(index);
	int maxChild = leftChild;
	if (leftChild >= arraySize)
		return;
	if (rightChild < arraySize)
		maxChild = maxChildIndex(arrayToChange, leftChild, rightChild);
	if (arrayToChange->at(maxChild) < arrayToChange->at(index))
		return;
	swap(arrayToChange, maxChild, index);
	siftDown(arrayToChange, maxChild, arraySize);
}

void buildHeap(vector<int>* input, int arraySize) {
	int N = arraySize / 2 - 1;
	for (int i = N; i >= 0; i--) {
		siftDown(input, i, arraySize);
	}
}

void sortHeap(vector<int>* input, int arraySize, int k) {
	buildHeap(input, k);
	for (int i = k; i < arraySize; i++) {
		if (input->at(i) < input->at(0)) {
			swap(input, 0, i);
			siftDown(input, 0, k);
		}
	}
}
int kthSmallest(vector<int> input, int k)
{
	sortHeap(&input, input.size(), k);
	for (int i = 0; i < nElements; i++) {
		cout << input[i] << " ";
	}
	return input[0];
}

int main()
{
	srand(time(NULL));
	vector<int> vect;
	int a;
	for (int i = 0; i < nElements; i++) {
		vect.push_back(rand()%100);
		cout << vect[i] << " ";
	}
	cout << endl;
	clock_t timeStart = clock();
	cout << endl << kthSmallest(vect, 4) << endl << endl;
	clock_t timeEnd = clock();
	cout << "HeapSort: " << (float(timeEnd - timeStart)) / CLOCKS_PER_SEC << "c" << endl;

}