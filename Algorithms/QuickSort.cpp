#include <iostream>
#include <stdio.h>

using namespace std;

void heapify(int array[], int len, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < len && array[left] > array[largest]) {
		largest = left;
	}

	if (right < len && array[right] > array[largest]) {
		largest = right;
	}
	if (largest != i) {
		swap(array[i], array[largest]);
		heapify(array, len, largest);
	}
}

/*void buildMaxHeap(int array[], int len) {
for (int i = len / 2 - 1; i >= 0; i--) {
heapify(array, len, i);
}

}*/

void heapSort(int array[], int len) {
	//	buildMaxHeap(array, len);

	for (int i = len / 2 - 1; i >= 0; i--) {
		heapify(array, len, i);
	}

	for (int i = len - 1; i >= 0; i--) {
		swap(array[0], array[i]);

		heapify(array, i, 0);

	}
}

int main(int argc, char *argv) {

	int len;
	cin >> len;

	int array[len];

	for (int i = 0; i < len; i++) {
		cin >> array[i];
	}

	heapSort(array, len);

	for (int i = 0; i < len; i++) {
		cout << array[i] << ";";
	}


	return 0;
}

