#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int A;
	int B = 2;
	bool C = true;

	cin >> A;

	while (B < A && C == true) {
		if (A % B == 0)
			C = false;
		B++;
	}

	if (C)
		cout << "Число " << A << " простое";
	else
		cout << "Число " << A << " не простое";
}