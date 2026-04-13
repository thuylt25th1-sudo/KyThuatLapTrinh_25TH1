template <typename T>
struct node {
	T data;
	Node* next;
};
template <typename T>
struct Linkedlist {
	Node<T>* head;
	void Show() {
		if (head == NULL) {
			cout << "No item available" << endl;
			return;
		}
		Node<T*> item = head;
		while (item != NULL) {
			cout << item->data << endl;
			item = item->next;
		}
	}
};
