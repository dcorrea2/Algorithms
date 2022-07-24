#include<iostream>
#include<stdio.h>
#include<vector>


using namespace std;

void countSort(int arr[][10], int size, int pos) {

	int i;
	int count[4] = { 0 };

	int newArr[size][10];

	for (i = 0; i < size; i++) {
		count[arr[i][pos] % 4]++;
	}

	for (i = 1; i < 4; i++) {
		count[i] += count[i - 1];
	}

	for (i = size - 1; i >= 0; i--) {
		for (int j = 10; j >= 0; j--) {
			newArr[count[arr[i][pos] % 4] - 1] = arr[i];
			count[arr[i][pos] % 4]--;
		}
	}

	for (i = 0; i < size; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = newArr[i][j];
		}
	}

}

void radixSort(int arr[][10], int n) {
	int row = 10;

	for (int i = row - 1; i >= 0; i--) {
		countSort(arr, n, i);
	}
}

int main() {
	int numVec;
	cin >> numVec;

	int array[numVec][10];
	

	for (int i = 0; i < numVec; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> array[i][j];
		}
	}

	radixSort(array, numVec);

	for (int i = 0; i < numVec; i++) {
		for(int j = 0; j<10;j++){
			cout << array[i][j] << ";";
		}
		cout << endl;
	}
}