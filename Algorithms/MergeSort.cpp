#include <stdio.h>
#include <iostream>

using namespace std;

void merge(int array[], int left, int q, int right) {
	int n1 = q - left + 1;
	int n2 = right - q;

	int L[n1], R[n2];
	int i, j, k;

	for (i = 0; i < n1; i++)
		L[i] = array[left + i];

	for (j = 0; j < n2; j++)
		R[j] = array[q + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			array[k] = L[i];
			i++;
		}
		else {
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		array[k] = R[j];
		j++;
		k++;
	}
	//	for (k = left; k < right; k++) {
	//		if (L[i] <= R[j]) {
	//			array[k] = L[i];
	//			i = i + 1;
	//		}
	//		else {
	//			array[k] = R[j];
	//			j = j + 1;
	//		}
	//	}
}

void mergeSort(int array[], int left, int right) {

	if (left < right) {
		int q = (left + right) / 2;

		mergeSort(array, left, q);
		mergeSort(array, q + 1, right);

		merge(array, left, q, right);
	}
}



int main(int argc, char *argv[])
{
	int len;
	cin >> len;

	int array[len];

	for (int i = 0; i < len; i++) {
		cin >> array[i];
	}

	mergeSort(array, 0, len - 1);

	int i;
	for (i = 0; i < len; i++) {
		cout << array[i] << ";";
	}

}

