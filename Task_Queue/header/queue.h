#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <iostream>
#include <initializer_list>
#include <deque> 


template <typename T, typename Container = std::deque<T> >
class Queue{
public:
    using container_type = Container;
    using size_type = size_t;
    using value_type = T;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using reference = value_type&;
    using const_reference = const value_type&;

private:
    Container ob;

public:
    Queue();

    Queue(const Queue& rhv);

    const Queue& operator=(const Queue& rhv);

    Queue(Queue&& rhv);

    const Queue& operator=(Queue&& rhv);

    Queue(std::initializer_list<value_type> init);

    template <typename InputIt>

    Queue(InputIt first, InputIt last);

    ~Queue();

public:

    void push(const_reference val);

    void pop();

    reference front();
    const_reference front() const;


    reference back();
    const_reference back() const;

    size_type size() const;

    //reference operator[](size_type index);

    void swap(Queue& obj);

     bool empty();


    bool operator==(const Queue& rhv);
    bool operator!=(const Queue& rhv);
    bool operator<(const Queue& rhv);
    bool operator<=(const Queue& rhv);
    bool operator>(const Queue& rhv);
    bool operator>=(const Queue& rhv);

};

#include "queue.hpp"

#endif

