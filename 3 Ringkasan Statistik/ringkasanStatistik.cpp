#include <iostream>
#include <math.h>
using namespace std;
void bubblesort(int A[], int n);

int main() {
	int N;
	cout << "Masukkan banyak data: "; cin >> N;
	int A[N];
	float sum = 0, mean, median, SD, sum1 = 0;
	for (int i = 0; i < N; i++) {
		cout << "Masukkan data ke-" << i+1 << ": "; cin >> A[i];
	}
	bubblesort(A, N);
	cout << "Data setelah diurutkan: " << endl;
	for (int i = 0; i < N; i++) cout << A[i] << " ";
	cout << endl;
	
	if (N % 2 == 0) median = (float)(A[N/2] + A[N/2-1])/2;
	else median = A[N/2];
	
	for (int i = 0; i < N; i++) sum = sum + A[i];
	mean = sum / N;
	
	for (int i = 0; i < N; i++) sum1 = sum1 + pow((A[i] - mean), 2);
	SD = sqrt(sum1 / N);
	
	cout << "Mean: " << mean << endl;
	cout << "Median: " << median << endl;
	cout << "Standar deviasi: " << SD << endl;
	return 0;
}

void bubblesort(int A[], int n) {
	int i, j, temp;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n-1; j++) {
			if (A[j] > A[j+1]) {
				temp = A[j]; A[j] = A[j+1]; A[j+1] = temp;
			}
		}
	}
}
