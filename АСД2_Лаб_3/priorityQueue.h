#pragma once
#include <vector>
#include <ctime>

using namespace std;

struct Data {
	int curiosity;
	int usefulness;
	int difficulty;
	int deadline;

	Data() {
		curiosity = rand() % 100;
		usefulness = rand() % 100;
		difficulty = rand() % 100;
		deadline = rand() % 21;
	}

	Data(int curiosity, int usefulness, int difficulty, int deadline) :
		curiosity(curiosity),
		usefulness(usefulness),
		difficulty(difficulty),
		deadline(deadline)	{}

	bool operator<(const Data& second) const {
		if (this->deadline != second.deadline)
			return this->deadline > second.deadline;
		if (this->difficulty != second.difficulty)
			return this->difficulty < second.difficulty;
		if (this->usefulness != second.usefulness)
			return this->usefulness < second.usefulness;
		return this->curiosity < second.curiosity;
	}
	bool operator==(const Data& second) const {
		if (this->deadline != second.deadline)
			return false;
		if (this->difficulty != second.difficulty)
			return false;
		if (this->usefulness != second.usefulness)
			return false;
		return true;
	}
	bool operator>(const Data& second) const {
		return second < *this;
	}
};

struct MaxHeap {
private:
	int maxChildIndex(int first, int second);
public:
	void swap(int first, int second);
	vector<Data> dataVector;
	void siftUp(int index);
	void siftDown(int index);
	int getParent(int index);
	int getLeftChild(int index);
	int getRightChild(int index);
};

struct PriorityQueue {
private:
	MaxHeap heap;
public:
	void push(Data data);
	Data top();
	void pop();
	void clean();
	bool empty();
	int size();
};

struct HeapSort {
private:
	int* arrayToChange;
	int maxChildIndex(int first, int second);
	void siftDown(int index, int arraySize);
	void swap(int first, int second);
	int getParent(int index);
	int getLeftChild(int index);
	int getRightChild(int index);

public:
	void buildHeap(int* array, int arraySize);
	void sortHeap(int* array, int arraySize);
};