#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;


int maximum(int L, int R, int C) {
	if (L >= R && L >= C)
		return L;
	else if (R >= L && R >= C)
		return R;
	return C;
}

int maxCrossingSum(int arr[], int low, int mid, int high) {
	int leftSum = INT_MIN;
	int sum = 0;
	int i;

	for (int i = mid; i >= low; i--) {
		sum = sum + arr[i];
		if (sum > leftSum)
			leftSum = sum;
	}

	int rightSum = INT_MIN;
	sum = 0;

	for (i = mid + 1; i <= high; i++) {
		sum = sum + arr[i];
		if (sum > rightSum)
			rightSum = sum;
	}

	return (leftSum + rightSum);

}

int maxSubArray(int array[], int low, int high)
{

	if (low == high) {
		return array[low];
	}

	int mid = (low + high) / 2;

	int L = maxSubArray(array, low, mid);
	int R = maxSubArray(array, mid + 1, high);
	int C = maxCrossingSum(array, low, mid, high);

	return maximum(L, R, C);

	if (L >= R && L >= C)
		return L;
	else if (R >= L && R >= C)
		return R;
	return C;
}


int main(int argc, char *argv[])
{
	int len = 0;
	cin >> len;

	int array[len];

	for (int i = 0; i < len; i++) {
		cin >> array[i];
	}

	int maxSum = maxSubArray(array, 0, len - 1);

	cout << maxSum;

	return 0;
}



