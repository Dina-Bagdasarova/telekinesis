#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>
#include <deque>
#include <initializer_list>

template <typename T, typename Container = std::deque<T> >
class Stack{
public:

    using container_type = Container;
    using size_type = size_t;
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;

private:
    
    Container ob;

public:
	Stack();

	Stack(const Stack& rhv);

    const Stack& operator=(const Stack& rhv);

    Stack(Stack&& rhv);	

	const Stack& operator=(Stack&& rhv);

	Stack(std::initializer_list<T> init);

    template <typename InputIt>
    Stack(InputIt first, InputIt last);    

	~Stack();

public:

	void push(size_type val);

	void pop();

	reference top();
    const_reference top() const;

	size_type size();

	void swap(Stack& obj);

	bool empty();

public:

    bool operator==(const Stack& other);
    bool operator!=(const Stack& other);
    bool operator<(const Stack& other);
    bool operator<=(const Stack& other);
    bool operator>(const Stack& other);
    bool operator>=(const Stack& other);

};

#include "stack.hpp"
#endif
