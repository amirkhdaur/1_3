#include <iostream>
using namespace std;

#define SIZE 1000
#define T int

int cursor = -1;
T Stack[SIZE];

bool push(T data) {
	if (cursor < SIZE) {
		Stack[++cursor] = data;
		return true;
	}
	else {
		cout << "Stack overflow";
		return false;
	}
}

T pop() {
	if (cursor != -1) {
		return Stack[cursor--];
	}
	else {
		cout << "Stack is empty";
		return -1;
	}
}

void binary(int n) {
	while (n >= 1) {
		push(n % 2);
		n /= 2;
	}
	while (cursor != -1) {
		cout << pop();
	}
}

int main() {
	int n;
	cin >> n;
	binary(n);
}