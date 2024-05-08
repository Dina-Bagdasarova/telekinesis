#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T, typename Container = std::vector<T> >
class Queue{
public:

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

        Queue(const Container& rhv);

        const Queue& operator=(const Container& rhv);

        Queue(Container&& rhv);

        Queue(std::initializer_list<value_type> init);

        ~Queue();

        void push(const_reference val);

        void pop();

        value_type& front();

        size_type _size();

        reference operator[](size_type index);

        void swap(Queue& obj);

        bool empty();

    template <typename C, typename ContainerC>
    friend bool operator<(const Queue<C, ContainerC>& obj, const Queue<C, ContainerC>& obj2);
    template <typename C, typename ContainerC>
    friend bool operator>(const Queue<C, ContainerC>& obj, const Queue<C, ContainerC>& obj2);
    template <typename C, typename ContainerC>
    friend bool operator==(const Queue<C, ContainerC>& obj, const Queue<C, ContainerC>& obj2);
    template <typename C, typename ContainerC>
    friend bool operator!=(const Queue<C, ContainerC>& obj, const Queue<C, ContainerC>& obj2);
    template <typename C, typename ContainerC>
    friend bool operator<=(const Queue<C, ContainerC>& obj, const Queue<C, ContainerC>& obj2);
    template <typename C, typename ContainerC>
    friend bool operator>=(const Queue<C, ContainerC>& obj, const Queue<C, ContainerC>& obj2);
};

 
    template <typename C, typename ContainerC>
    bool operator<(const Queue<C, ContainerC>& obj, const Queue<C, ContainerC>& obj2);

    template <typename C, typename ContainerC>
    bool operator>(const Queue<C, ContainerC>& obj, const Queue<C, ContainerC>& obj2);

    template <typename C, typename ContainerC>
    bool operator==(const Queue<C, ContainerC>& obj, const Queue<C, ContainerC>& obj2);

    template <typename C, typename ContainerC>
    bool operator!=(const Queue<C, ContainerC>& obj, const Queue<C, ContainerC>& obj2);

    template <typename C, typename ContainerC>
    bool operator<=(const Queue<C, ContainerC>& obj, const Queue<C, ContainerC>& obj2);

    template <typename C, typename ContainerC>
    bool operator>=(const Queue<C, ContainerC>& obj, const Queue<C, ContainerC>& obj2);

#include "queue.hpp"

#endif

