#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <typename T>
struct MyNode
{
	T data;
	MyNode<T>* prev;
	MyNode<T>* next;

	MyNode(T dt, MyNode<T>* p, MyNode<T>* n) {
		this->data = dt;
		prev = p;
		next = n;
	}
};

template <typename T>
struct MyDeque
{
private:
	MyNode<T>* frnt;
	MyNode<T>* bck;
	unsigned elements;
	bool isEmpty;

	void addOne() {
		this->elements++;
		this->isEmpty = false;
	}

	void remOne() {
		this->elements--;
		if (this->elements == 0)
			this->isEmpty = true;
	}

public:
	MyDeque<T>(){
		this->frnt = nullptr;
		this->bck = nullptr;
		this->elements = 0;
		this->isEmpty = true;
	};

	

	void push_back(T data) {

		if (isEmpty) {
			this->bck = new MyNode<T>(data, nullptr, nullptr);
			this->frnt = this->bck;
		}
		else
		{
			this->bck->prev = new MyNode<T>(data, this->bck, nullptr);
			this->bck = this->bck->prev;
		}
		this->addOne();
	};

	void push_front(T data) {
		if (isEmpty) {
			this->bck = new MyNode<T>(data, nullptr, nullptr);
			this->frnt = this->bck;
		}
		else
		{
			this->frnt->next = new MyNode<T>(data, nullptr, this->frnt);
			this->frnt = this->frnt->next;
		}
		this->addOne();
	};

	T pop_back() {
		if (isEmpty) {
			throw "Deque is empty";
		}
		else {
			T tmp = this->bck->data;
			this->bck = this->bck->prev;
			this->remOne();
			return tmp;
		}
	};

	T pop_front() {
		if (isEmpty) {
			throw "Deque is empty";
		}
		else {
			T tmp = this->frnt->data;
			this->frnt = this->frnt->next;
			this->remOne();
			return tmp;
		}
	};

	T front() {
		if (isEmpty) {
			throw "Deque is empty";
		}
		else {
			return this->frnt->data;
		}
	};

	T back() {
		if (isEmpty) {
			throw "Deque is empty";
		}
		else {
			return this->bck->data;
		}
	};

	bool empty() {
		return this->isEmpty;
	}

	int size() {
		return this->elements;
	}
};


int main() {

	MyDeque<int> d; // создание дека
	d.push_back(1); // добавление элемента 1 в конец дека
	d.push_front(2); // добавление элемента 2 в начало дека
	d.push_back(3); // добавление элемента 3 в конец дека
	cout << d.front() << endl; // выводится 2
	cout << d.back() << endl; // выводится 3
	d.pop_front(); // удаляется первый элемент
	cout << d.front() << endl; // выводится 1
	cout << d.size() << endl; // выводится 2
	return 0;
}
