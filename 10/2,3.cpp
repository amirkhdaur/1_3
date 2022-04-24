#include <iostream>
using namespace std;

typedef struct Node {
	int dat;
	struct Node* next;
} Node;

typedef struct {
	Node* head;
	int size;
} List;

void init(List* lst) {
	lst->head = nullptr;
	lst->size = 0;
}

void ins(List* lst, int data) {
	Node* node = new Node;
	node->dat = data;
	node->next = nullptr;

	Node* current = lst->head;
	if (current == nullptr) {
		lst->head = node;
		lst->size++;
		return;
	}
	else {
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = node;
		lst->size++;
	}
}

void rm(List* lst, int data) {
	Node* current = lst->head;
	Node* parent = nullptr;
	if (current == nullptr)
		return;

	while (current->next != nullptr && current->dat != data) {
		parent = current;
		current = current->next;
	}
	if (current->dat != data) {
		return;
	}
	if (current == lst->head) {
		lst->head = current->next;
		lst->size--;
		return;
	}
	parent->next = current->next;
	lst->size--;
	return;
}

void printNode(Node* n) {
	if (n == nullptr) {
		cout << "[]";
		return;
	}
	cout << "[" << n->dat << "] ";
}

void printList(List* lst) {
	Node* current = lst->head;
	if (current == nullptr) {
		printNode(current);
	}
	else {
		while (current != nullptr) {
			printNode(current);
			current = current->next;
		}
	}
	cout << " Size: " << lst->size << endl;
}

void freeList(List* lst) {
	if (lst == nullptr) return;
	Node* current = lst->head;
	Node* parent = nullptr;
	while (current != nullptr) {
		parent = current;
		current = current->next;
		delete parent;
	}
	delete lst;
}

void copyList(List* lst, List* lst_copy) {
	init(lst_copy);
	Node* current = lst->head;
	while (current != nullptr) {
		ins(lst_copy, current->dat);
		current = current->next;
	}
}

bool checkSort(List* lst) {
	Node* current = lst->head;
	int previous = current->dat;
	while (current != nullptr) {
		if (previous > current->dat)
			return false;
		previous = current->dat;
		current = current->next;
	}
	return true;
}

int main() {
	List* lst = new List;
	init(lst);
	printList(lst);
	ins(lst, 1);
	printList(lst);
	ins(lst, 10);
	printList(lst);
	rm(lst, 10);
	printList(lst);

	List* lst_copy = new List;
	copyList(lst, lst_copy);
	printList(lst_copy);

	ins(lst, 2);
	ins(lst, 3);
	ins(lst, 4);
	printList(lst);
	cout << checkSort(lst) << endl;
	ins(lst, 1);
	printList(lst);
	cout << checkSort(lst) << endl;

	freeList(lst_copy);
	freeList(lst);
}