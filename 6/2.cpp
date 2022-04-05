#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int arr[11];

	for (int i = 0; i < 11; i++) {
		cin >> arr[i];
	}

	for (int i = 10; i >= 0; i--) {
		int n = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);
		if (n > 400) {
			cout << 11 - i << " элемент  число " << arr[i] << " превышает 400" << endl;
		}
	}
}