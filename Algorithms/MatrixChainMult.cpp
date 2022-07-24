#include <iostream>
#include <climits>
using namespace std;
int num = 0; 


void printOptimalSequence(int i, int j, int n,
	int *s)
{
	
	if (i == j)
	{
		cout << "A" << num; 
		num++;
		return;

	}

	cout << "(";

	

	printOptimalSequence(i, *((s + i*n) + j), n, s);
	printOptimalSequence(*((s + i*n) + j) + 1, j, n, s);
	cout << ")";
}



void matrixChainOrder(int arr[], int n){

	int m[n][n];


	int s[n][n]; 
	for (int i = 1; i<n; i++)
		m[i][i] = 0; 
	for (int L = 2; L<n; L++)
	{
		for (int i = 1; i<n - L + 1; i++)
		{
			int j = i + L - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)
			{
				
				int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

	cout << m[1][n - 1] << endl;
	printOptimalSequence(1, n - 1, n, (int *)s);
}

int main()
{
	int n;
	cin >> n;
	int arr[n + 1]; 
	for (int i = 0; i <= n; i++) {
		cin >> arr[i];
	}

	int size = n + 1;
	matrixChainOrder(arr, size);
	cout << "\n";
	return 0;
}

