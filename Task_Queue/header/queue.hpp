#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__
#include <iostream>
#include <initializer_list>
#include "queue.h"

template <typename T, typename Container>

Queue<T, Container>::Queue()
        : ob() {}

template <typename T, typename Container>

Queue<T, Container>::Queue(const Queue& rhv)
        : Queue()
{
	this->ob = rhv.ob;
}
template <typename T, typename Container>

const Queue<T, Container>&
Queue<T, Container>::operator=(const Queue& rhv){
if(this != &rhv){
        this->ob = rhv.ob;
}
        return *this;
}


template <typename T, typename Container>

Queue<T, Container>::Queue(Queue&& rhv)
        : Queue() 
{
	this->ob = std::move(rhv.ob);
}

template <typename T, typename Container>

const Queue<T, Container>&
Queue<T, Container>::operator=(Queue&& rhv){
if(this != &rhv){
        this->ob = std::move(rhv.ob);
}
        return *this;
}


template <typename T, typename Container>

Queue<T, Container>::Queue(std::initializer_list<value_type> init)
    : Queue(0){
for(T& i : init){
        push_back(i);
    }
}

template <typename T, typename Container>
template <typename InputIt>
Queue<T, Container>::Queue(InputIt first, InputIt last)
:Queue(first, last)

{}

template <typename T, typename Container>

Queue<T, Container>::~Queue()
{}

template <typename T, typename Container>
void
Queue<T, Container>::push(const_reference val){
        ob.push_back(val);
}

template <typename T, typename Container>
void
Queue<T, Container>::pop(){
        ob.pop_back();
}

template <typename T, typename Container>
Queue<T,Container>::reference
Queue<T, Container>::front(){
        return ob.front();
}

template <typename T, typename Container>
Queue<T,Container>::const_reference
Queue<T, Container>::front() const {
        return ob.front();
}

template <typename T, typename Container>
Queue<T,Container>::reference
Queue<T, Container>::back(){
        return ob.back();
}

template <typename T, typename Container>
Queue<T,Container>::const_reference
Queue<T, Container>::back() const {
        return ob.back();
}

template <typename T, typename Container>

Queue<T,Container>::size_type
Queue<T, Container>::size() const{
       return ob.size();
}

/*template <typename T, typename Container>
Queue<T, Container>::reference Queue<T, Container>::operator[](size_type index)
{
    return ob[index];
}*/

template <typename T, typename Container>

void
Queue<T, Container>::swap(Queue& obj){
ob.swap(obj.ob);
}

template <typename T, typename Container>

bool
Queue<T, Container>:: empty(){
        return ob.empty();
}

template <typename T, typename Container>
bool Queue<T, Container>::operator<(const Queue& rhv){
    return ob < rhv.ob;
}

template <typename T, typename Container>
bool Queue<T, Container>::operator>(const Queue& rhv){
    return ob > rhv.ob;
}

template <typename T, typename Container>
bool Queue<T, Container>::operator==(const Queue& rhv){
    return ob == rhv.ob;
}

template <typename T, typename Container>
bool Queue<T, Container>::operator!=(const Queue& rhv){
    return ob != rhv.ob;
}

template <typename T, typename Container>
bool Queue<T, Container>::operator<=(const Queue& rhv){
    return ob <= rhv.ob;
}

template <typename T, typename Container>
bool Queue<T, Container>::operator>=(const Queue& rhv){
    return ob >= rhv.ob;
}

#endif

