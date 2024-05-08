#ifndef __STACK_HPP__
#define __STACK_HPP__
#include <iostream>
#include <vector>
#include <initializer_list>
#include "stack.h"

template <typename T, typename Container>

Stack<T, Container>::Stack()
        : ob() 
	{}


template <typename T, typename Container>

Stack<T, Container>:: Stack(const Stack& rhv)
        : ob(rhv.ob) 
	{}


template <typename T, typename Container>

const Stack<T, Container>& 
Stack<T, Container>::operator=(const Stack<T, Container>& rhv){
if(this != &rhv){
        ob.clear;
        ob = rhv.ob;
}
        return *this;
}

template <typename T, typename Container>

Stack<T, Container>::Stack(Stack&& rhv)
        : Stack() 
    {
	this->ob = std::move(rhv.ob);
}

template <typename T, typename Container>

Stack<T, Container>::Stack(std::initializer_list<T> init): Stack(0){
for(T& i : init){
        ob.push_back(i);
	}
}

template<typename T , typename Container>
Stack<T,Container>& 
Stack<T,Container>::operator=(Stack&& rhv){
    if (this != &rhv) {        
        ob = std::move(rhv.ob);
    }

    return *this; 
}

template <typename T, typename Container>

Stack<T, Container>::~Stack(){
ob.clear();
}

template <typename T, typename Container>

void 
Stack<T, Container>::push(size_type val){
        ob.push_back(val);
}

template <typename T, typename Container>

void 
Stack<T, Container>::pop(){
        ob.pop_back();
}

template <typename T, typename Container>

Stack<T,Container>::referance
 Stack<T, Container>::top(){
        return ob.back();
}

template <typename T, typename Container>

Stack<T,Container>::size_type
Stack<T, Container>::size(){
        return ob.size();
}

template <typename T, typename Container>

void
Stack<T, Container>:: swap(Stack& obj){
std::swap(ob, obj.ob);
}

template <typename T, typename Container>

bool
Stack<T, Container>:: empty(){
        return ob.empty();
}

template <typename T, typename Container>
bool
Stack<T, Container>:: operator==(const Stack& other) {
    return this->ob == other.ob ;
}

template <typename T, typename Container>
bool 
Stack<T, Container>::operator!=(const Stack& other) {
    return ! (this->ob == other.ob) ;
}

template <typename T, typename Container>
bool
Stack<T, Container>:: operator<(const Stack& other) {
    return this->ob < other.ob ;
}

template <typename T, typename Container>
bool 
Stack<T, Container>::operator<=(const Stack& other) {
    return this->ob <= other.ob ;
}

template <typename T, typename Container>
bool 
Stack<T, Container>::operator>(const Stack& other) {
    return this->ob >other.ob ;
}

template <typename T, typename Container>
bool 
Stack<T, Container>::operator>=(const Stack& other) {
    return this->ob >= other.ob ;
}

#endif
