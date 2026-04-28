#ifndef _STACK_H
#define _STACK_H
#include <stdexcept>

template <typename T>
struct Node {
	Node<T>* next;
	T data;

	Node(const T& data, Node<T>* next = nullptr) : next(next), data(data) {}
};

template <typename T>
class Stack {
private:
	Node<T>* head;

	Node<T>* copy(const Node<T>* const node) const {
		if (node == nullptr) {
			return nullptr;
		}
		else {
			Node<T>* nodeCopy = copy(node->next);
			return new Node{ node->data, nodeCopy };
		}
	}

	void cleanup() {
		while (!isEmpty()) {
			pop();
		}
	}

public:
	Stack() : head(nullptr) {}

	Stack(const Stack<T>& that) : head(copy(that.head)) {}

	Stack& operator=(const Stack<T>& that) {
		if (this != &that) {
			cleanup();
			this->head = copy(that.head);
		}
		return *this;
	}

	Stack(Stack<T>&& that) : head(that.head) {
		that.head = nullptr;
	}

	Stack& operator=(Stack<T>&& that) {
		if (this != &that) {
			this->head = that.head;
			that.head = nullptr;
		}
		return *this;
	}

	~Stack() {
		cleanup();
	}

	void push(const T& value) {
		Node<T>* newNode = new Node<T>{ value, this->head };
		this->head = newNode;
	}

	void pop() {
		if (isEmpty()) {
			throw std::runtime_error("Trying to remove from empty stack!");
		}

		Node<T>* temp = this->head;
		this->head = this->head->next;

		delete temp;
	}

	bool isEmpty() const {
		return this->head == nullptr;
	}

	T& peek() {
		if (isEmpty()) {
			throw std::out_of_range("Head of empty stack!");
		}

		return this->head->data;
	}

	const T& peek() const {
		if (isEmpty()) {
			throw std::out_of_range("Head of empty stack!");
		}

		return this->head->data;
	}
};

#endif
