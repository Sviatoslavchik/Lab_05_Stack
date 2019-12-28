#include "header.hpp"

template <typename T>
class Stack : public ParentStack <T>
{
public:
	//
	void push(const T& value) {
		if (this->headStack == nullptr) {
			StackValue<T> *temp = new StackValue<T>{ value, nullptr };
			this->headStack = temp;
		}
		else {
			StackValue<T> *temp = new StackValue<T>{ value, this->headStack };
			this->headStack = temp;

		}
	}

	void pop()
	{
		if (!this->headStack) {
			throw std::runtime_error("Stack is nullptr");
		}

		auto *prevNode = this->headStack;
		this->headStack = this->headStack->prev;

		delete prevNode;
	}
};
