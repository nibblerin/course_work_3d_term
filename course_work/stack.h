#pragma once
template <typename T>
class Stack {
private:
	struct Node
	{
		T data;
		unique_ptr<Node> next;
		Node(T item) : data(item), next(nullptr) {};
	};
	unique_ptr<Node> top;
	int count = 0;
public:
	void push(const T& item) {
		auto ptr = make_unique<Node>(item);
		ptr->next = move(top);
		top = move(ptr);
		++count;
	}
	T pop() {
		if (!top) {
			throw runtime_error("Cannot pop from empty stack");
		}
		T value = move(top->data);
		top = move(top->next);
		--count;
		return value;
	}
	bool empty() const {
		return !top;
	}
	void print() const {
		for (auto current = top.get();current != nullptr; current = current->next.get()) {
			cout << current->data << " ";
		}
		cout << endl;
	}
	int size() const { return count; }
};
