#include <iostream>
using namespace std;

int** InitArray(size_t x, size_t y) {
	int** arr = new int* [x];
	for (int i = 0; i < x; i++) {
		arr[i] = new int[y];
	}
	return arr;
}

void FreeArray(int** arr, size_t x) {
	for (int i = 0; i < x; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

void PrintArray(int** arr, size_t x, size_t y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void FillArray(int** arr, size_t x, size_t y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arr[i][j] = rand() % 100;
		}
	}
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void BubbleSort(int** arr, size_t x, size_t y) {
	for (int q = 0; q < x * y; q++) {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (j != y - 1) {
					if (arr[i][j] > arr[i][j + 1]) {
						swap(arr[i][j], arr[i][j + 1]);
					}
				}
				else if (i != x - 1) {
					if (arr[i][j] > arr[i + 1][0]) {
						swap(arr[i][j], arr[i + 1][0]);
					}
				}

			}
		}
	}
}

int main() {
	size_t x = 3;
	size_t y = 3;

	int** arr = InitArray(x, y);

	FillArray(arr, x, y);
	PrintArray(arr, x, y);
	BubbleSort(arr, x, y);
	PrintArray(arr, x, y);

	FreeArray(arr, x);
}