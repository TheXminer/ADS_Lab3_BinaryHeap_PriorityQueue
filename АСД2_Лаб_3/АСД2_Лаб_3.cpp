#include "priorityQueue.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstdlib>
#define N 30000

template <typename T>

float testPriorityQueueSpeed(T&& priorityQueue)
{
	const int iters = 100000;
	clock_t timeStart = clock();
	for (int i = 0; i < iters; i++)
	{
		int insertDataAmount = rand() % 6 + 5;
		for (int j = 0; j < insertDataAmount; j++)
		{
			priorityQueue.push(Data());
		}
		priorityQueue.top();
		priorityQueue.pop();
	}
	clock_t timeEnd = clock();
	float time = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;
	return time;
}

bool testPriorityQueue()
{
	const int iters = 20000;
	PriorityQueue myPriorQueue;

	priority_queue<Data> stlPriorQueue;
	bool isDataEqual = true;
	for (int i = 0; i < iters; i++)
	{
		int insertDataAmount = rand() % 6 + 5;
		for (int j = 0; j < insertDataAmount; j++)
		{
			Data randData = Data();
			myPriorQueue.push(randData);
			stlPriorQueue.push(randData);
		}
		if (!(myPriorQueue.top() == stlPriorQueue.top()))
		{
			isDataEqual = false;
			cerr << "Comparing failed on iteration " << i << endl << endl;
			break;
		}
		int removeDataAmount = rand() % insertDataAmount;
		for (int j = 0; j < removeDataAmount; j++)
		{
			myPriorQueue.pop();
			stlPriorQueue.pop();
		}
	}
	int myQueueSize = myPriorQueue.size();
	int stlQueueSize = stlPriorQueue.size();
	float stlTime =	testPriorityQueueSpeed<priority_queue<Data>>(priority_queue<Data>());
	float myTime = testPriorityQueueSpeed<PriorityQueue>(PriorityQueue());
	cout << "My PriorityQueue:" << endl;
	cout << "Time: " << myTime << ", size: " << myQueueSize << endl;
	cout << "STL priority_queue:" << endl;
	cout << "Time: " << stlTime << ", size: " << stlQueueSize << endl << endl;
	if (isDataEqual && myQueueSize == stlQueueSize)
	{
		cout << "The lab is completed" << endl << endl;
		return true;
	}
	cerr << ":(" << endl << endl;
	return false;
}

void bubbleSort(int* arrSort, const int arrLength)
{
	for (int i = 0; i < arrLength; i++) {
		bool isSorted = true;
		for (int j = 0; j < arrLength - i - 1; j++)
			if (arrSort[j] > arrSort[j + 1]) {
				swap(arrSort[j], arrSort[j + 1]);
				isSorted = false;
			}
		if (isSorted)
			return;
	}
	return;
}


void chooseSort(int* parray, const int arrayLength)
{
	for (int i = 0; i < arrayLength - 1; i++)
	{
		int min = parray[i];
		int nMin = i;
		int sumMin = 0;
		do {
			sumMin += min % 10;
			min /= 10;
		} while (min > 0);
		for (int j = i + 1; j < arrayLength; j++) {
			int a = parray[j];
			int sumA = 0;
			do {
				sumA += a % 10;
				a /= 10;
			} while (a > 0);
			if (sumA < sumMin)
			{
				sumMin = sumA;
				nMin = j;
			}
			else if (sumA == sumMin && parray[j] < parray[nMin]) {
				sumMin = sumA;
				nMin = j;
			}
		}
		swap(parray[i], parray[nMin]);
	}
	return;
}


int main()
{
	srand(time(NULL));

	PriorityQueue prior;
	testPriorityQueue();

	//sort
	int sort1[N], sort2[N], sort3[N], sort4[N];
	for (int i = 0; i < N; i++) {
		int rnd = rand() % 1000;
		sort1[i] = rnd;
		sort2[i] = rnd;
		sort3[i] = rnd;
		sort4[i] = rnd;
	}
	HeapSort heapSort;

	cout << "Sort test for 30 000 elements:" << endl << endl;
	//
	cout << "Average case:" << endl;
	clock_t timeStart = clock();
	heapSort.sortHeap(sort1, N);
	clock_t timeEnd = clock();
	cout << "HeapSort: " << (float(timeEnd - timeStart)) / CLOCKS_PER_SEC << "c" << endl;

	timeStart = clock();
	bubbleSort(sort2, N);
	timeEnd = clock();
	cout << "BubbleSort: " << (float(timeEnd - timeStart)) / CLOCKS_PER_SEC << "c" << endl;

	timeStart = clock();
	chooseSort(sort3, N);
	timeEnd = clock();
	cout << "ChooseSort: " << (float(timeEnd - timeStart)) / CLOCKS_PER_SEC << "c" << endl;

	timeStart = clock();
	sort(sort4, sort4 + N);
	timeEnd = clock();
	cout << "Std sort: " << (float(timeEnd - timeStart)) / CLOCKS_PER_SEC << "c" << endl << endl;
	
	//
	cout << "Best case:" << endl;
	timeStart = clock();
	heapSort.sortHeap(sort1, N);
	timeEnd = clock();
	cout << "HeapSort: " << (float(timeEnd - timeStart)) / CLOCKS_PER_SEC << "c" << endl;

	timeStart = clock();
	bubbleSort(sort2, N);
	timeEnd = clock();
	cout << "BubbleSort: " << (float(timeEnd - timeStart)) / CLOCKS_PER_SEC << "c" << endl;

	timeStart = clock();
	chooseSort(sort3, N);
	timeEnd = clock();
	cout << "ChooseSort: " << (float(timeEnd - timeStart)) / CLOCKS_PER_SEC << "c" << endl;

	timeStart = clock();
	sort(sort4, sort4 + N);
	timeEnd = clock();
	cout << "Std sort: " << (float(timeEnd - timeStart)) / CLOCKS_PER_SEC << "c" << endl << endl;

	//
	cout << "Worst case:" << endl;

	for (int i = 0; i < N - 1; i++) {
		sort1[N - 1 - i] = i;
		sort2[N - 1 - i] = i;
		sort3[N - 1 - i] = i;
		sort4[N - 1 - i] = i;
	}

	timeStart = clock();
	heapSort.sortHeap(sort1, N);
	timeEnd = clock();
	cout << "HeapSort: " << (float(timeEnd - timeStart)) / CLOCKS_PER_SEC << "c" << endl;

	timeStart = clock();
	bubbleSort(sort2, N);
	timeEnd = clock();
	cout << "BubbleSort: " << (float(timeEnd - timeStart)) / CLOCKS_PER_SEC << "c" << endl;

	timeStart = clock();
	chooseSort(sort3, N);
	timeEnd = clock();
	cout << "ChooseSort: " << (float(timeEnd - timeStart)) / CLOCKS_PER_SEC << "c" << endl;

	timeStart = clock();
	sort(sort4, sort4 + N);
	timeEnd = clock();
	cout << "Std sort: " << (float(timeEnd - timeStart)) / CLOCKS_PER_SEC << "c" << endl;
}