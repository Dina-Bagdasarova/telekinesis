#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T, typename Container = std::vector<T> >
class Stack{
public:

        using size_type = size_t;
        using value_type = T;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using referance = value_type&;
        using const_referance = const value_type&;

private:
        Container ob;
public:
	Stack();

	Stack(const Stack& rhv);
	
	const Stack<T, Container>&  operator=(const Stack<T, Container>& rhv);
	
	Stack<T, Container>& operator=(Stack<T, Container>&& rhv);

	Stack(Stack&& rhv);

	Stack(std::initializer_list<T> init);

	~Stack();

	void push(size_type val);

	void pop();

	value_type& top();

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
