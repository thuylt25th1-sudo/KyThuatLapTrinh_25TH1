#include "LinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
struct Linkedlist<T>: :Show() {
	if (head == NULL) {
		cout << "No data avaiable" << endl;
		return;
	}
		Node<T*> item = head;
		while (item != NULL) {
			cout << item->data << endl;
			item = item->next;
		}
	}
