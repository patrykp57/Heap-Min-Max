#include <stdio.h>
#include <iostream>




const int MAX_N = 65536;
int tab[MAX_N];
int heapSize = 0;
bool maxHeap = true;


using namespace std;

void addNumber(int temp_number) {

	int temp;
	int index;

	heapSize++;
	tab[heapSize] = temp_number;
	index = heapSize;


	if (maxHeap) {
		while (index > 1) {
			if (tab[index / 2] < tab[index]) {
				temp = tab[index / 2];
				tab[index / 2] = tab[index];
				tab[index] = temp;
			}

			index = index / 2;
		}
	}

	else {

		while (index > 1) {
			if (tab[index / 2] > tab[index]) {
				temp = tab[index / 2];
				tab[index / 2] = tab[index];
				tab[index] = temp;
			}

			index = index / 2;
		}

	}
}

void addNumberUnsorted(int temp_number) {

	heapSize++;
	tab[heapSize] = temp_number;
}

void printHeap() {

	if (heapSize != 0) {
		for (int i = 1; i <= heapSize; i++)
		{
			cout << tab[i] << " ";
		}
	}
	cout << endl;
}

void repairHeapDown(int parent) {
	int temp = 0;
	int index = parent;
	int left = index * 2;
	int right = index * 2 + 1;

	if (maxHeap) {

		if (left <= heapSize && tab[index] < tab[left]) index = left;
		if (right <= heapSize && tab[index] < tab[right]) index = right;
		if (index != parent) {
			temp = tab[index];
			tab[index] = tab[parent];
			tab[parent] = temp;
			repairHeapDown(index);
		}
	}
	else {
		if (left <= heapSize && tab[index] > tab[left]) index = left;
		if (right <= heapSize && tab[index] > tab[right]) index = right;
		if (index != parent) {
			temp = tab[index];
			tab[index] = tab[parent];
			tab[parent] = temp;
			repairHeapDown(index);
		}

	}
}


void repairHeapUp(int parent) {


}

void removeMaxMin() {


	if (heapSize > 1) {
		cout << tab[1] << endl;
		tab[1] = tab[heapSize];
		tab[heapSize] = 0;
		heapSize--;
		repairHeapDown(1);
	}
	else if (heapSize == 1) {
		cout << tab[1] << endl;
		tab[1] = 0;
		heapSize--;
	}
	else cout << " " << endl;



}

void removeAll() {
	if (heapSize != 0) {
		for (int i = 1; i <= heapSize; i++)
		{
			tab[i] = 0;
		}
		heapSize = 0;
	}


}

void buildHeap(int parent) {

	for (int i = parent; i > 0; i--)
	{
		repairHeapDown(i);
	}

}


void changeHeap() {
	maxHeap = !maxHeap;
	buildHeap(heapSize / 2);
}





int main() {
	char znak;
	int number, n;



	while (cin >> noskipws >> znak) {

		switch (znak)
		{
		case '+':
			scanf_s("%d", &number);
			addNumber(number);
			break;
		case '-':
			removeMaxMin();
			break;
		case 'p':
			printHeap();
			break;
		case 'r':
			scanf_s(" %d", &n);
			removeAll();
			for (int i = 0; i < n; i++)
			{
				scanf_s(" %d", &number);
				addNumberUnsorted(number);
			}
			buildHeap(heapSize / 2);

			break;
		case 's':
			changeHeap();
			break;
		case 'q':
			return 0;
			break;
		}

	}
}