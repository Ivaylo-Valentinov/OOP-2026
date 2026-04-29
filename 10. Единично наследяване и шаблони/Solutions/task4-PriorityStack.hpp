#ifndef _PRIORITY_STACK_H
#define _PRIORITY_STACK_H
#include "task4-Stack.hpp"

template <typename T>
class PriorityStack: public Stack<T> {
public:
	void push(const T& value) {
    Stack<T> temp;
    while(!this->isEmpty() && value < this->peek()) {
      temp.push(this->peek());
      this->pop();
    }
    Stack<T>::push(value);
    while(!temp.isEmpty()) {
      Stack<T>::push(temp.peek());
      temp.pop();
    }
	}
};

#endif
