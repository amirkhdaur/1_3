#include <iostream>
using namespace std;

void quicksort(int* arr, int l, int r) {
	int i = l;
	int j = r;

	int p = arr[(l + r) / 2];

	do {
		while (arr[i] < p) i++;
		while (arr[j] > p) j--;

		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (i < r) quicksort(arr, i, r);
	if (j > l) quicksort(arr, l, j);
}
/*
void bucketsort(int* arr) {
	const int max = 12;
	const int b = 10;

	int buckets[b][max + 1];
	for (int i = 0; i < b; i++) {
		buckets[i][max] = 0;
	}

	for (int digit = 1; digit < 1000000000; digit *= 10) {
		for (int i = 0; i < max; i++) {
			int d = (arr[i] / digit) % b;
			buckets[d][buckets[d][max]++] = arr[i];
		}
		int idx = 0;
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < buckets[i][max]; j++) {
				arr[idx++] = buckets[i][j];
			}
			buckets[i][max];
		}
	}
}
*/

int main() {
	setlocale(LC_ALL, "rus");

	int arr[12]{ 0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3 };
	//bucketsort(arr);
	for (int i = 0; i < 12; i++) {
		cout << arr[i] << " ";
	}
}