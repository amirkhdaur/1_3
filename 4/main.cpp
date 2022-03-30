#include <iostream>
using namespace std;

int pow_(int a, int b) {
	int i = a;
	if (b > 1) {
		b--;
		if (b % 2 == 0) {
			i *= pow_(a * a, b / 2);
		}
		else {
			i *= pow_(a * a, (b - 1) / 2) * a;
		}
	}
	return i;
}

void binary_(int n) {
	if (n > 0) {
		binary_(n / 2);
		cout << n % 2;
	}
}

int chess_(int** board, int size) {
	for (int i = 0; i < size; i++) {
		board[i][0] = 1;
		board[0][i] = 1;
	}
	for (int i = 1; i < size; i++) {
		for (int j = 1; j < size; j++) {
			board[i][j] = board[i - 1][j] + board[i][j - 1];
		}
	}
	return board[size - 1][size - 1];
}

int main() {
	cout << pow_(5, 3) << endl;

	binary_(10);


	size_t size = 3;
	int** board = new int* [size];
	for (int i = 0; i < size; i++)
		board[i] = new int[size];

	cout << endl << chess_(board, 3);

	for (int i = 0; i < size; i++)
		delete[] board[i];
	delete[] board;
}