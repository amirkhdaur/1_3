#include <iostream>
using namespace std;

#define SZ 10

typedef struct {
	int pr;
	int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

void init() {
	Node node;

	for (int i = 0; i < SZ; i++) {
		arr[i] = nullptr;
	}
	head = 0;
	tail = 0;
	items = 0;
}

void ins(int pr, int dat) {
	Node* node = new Node;
	node->pr = pr;
	node->dat = dat;
	int flag;

	if (items == 0) {
		arr[tail++] = node;
		items++;
	}
	else if (items == SZ) {
		cout << "Queue is full";
		return;
	}
	else {
		int i = 0;
		int idx = 0;
		Node* tmp;
		for (i = head; i < tail; i++) {
			idx = i % SZ;
			if (arr[idx]->pr > pr)
				break;
			else
				idx++;
		}
		flag = idx % SZ;
		i++;
		while (i <= tail) {
			idx = i % SZ;
			tmp = arr[idx];
			arr[idx] = arr[flag];
			arr[flag] = tmp;
			i++;
		}
		arr[flag] = node;
		items++;
		tail++;
	}
}

Node* rem() {
	if (items == 0) {
		return nullptr;
	}
	else {
		int idx = head++ % SZ;
		Node* tmp = arr[idx];
		delete arr[idx];
		arr[idx] = nullptr;
		items--;
		return tmp;
	}
}

void freeNode() {
	for (int i = 0; i < SZ; i++) {
		delete arr[i];
	}
}

void printQueue() {
	cout << "[ ";
	for (int i = 0; i < SZ; i++) {
		if (arr[i] == nullptr) {
			cout << "[*, *] ";
		}
		else {
			cout << "[" << arr[i]->pr << ", " << arr[i]->dat << "] ";
		}
		cout << " ]" << endl;
	}

}

int main() {
	init();
	printQueue();
	cout << endl;
	ins(1, 11);
	ins(3, 22);
	ins(5, 44);
	ins(4, 33);
	ins(6, 66);
	ins(1, 44);
	ins(3, 11);
	ins(2, 77);
	ins(6, 55);
	ins(2, 99);
	printQueue();
	cout << endl;
	rem();
	printQueue();
	freeNode();
}