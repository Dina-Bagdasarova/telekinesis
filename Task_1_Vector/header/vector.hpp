
#ifndef __VECTOR_TPP__
#define __VECTOR_TPP__

#include <iostream>
#include <initializer_list>
//#include "vector.h"

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector()
    : size{0},
      capacity{0},
      arr{nullptr} 
{ }

template <typename T, typename Allocator>
Vector<T, Allocator>::~Vector() {
    clear();
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(size_type size, const_reference val)
    : size(size),
      capacity(size),
      arr{alloc.allocate(capacity)} 
{
    if (size == 0) {
        return;
    }
    for (size_t i = 0; i < size; ++i) {
        alloc.construct(arr [i], val);
    }
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(std::initializer_list<value_type> init)
    : Vector()
{
    for (const_reference val : init) {
        push_back(val);
    }
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(const Vector& ob)
    : size{ob.size},
      capacity{ob.capacity},
      arr{alloc.allocate(ob.capacity)} 
{
    for (size_type i = 0; i < size; ++i) {
        alloc.construct(arr + i, ob.arr[i]);
    }
}

template <typename T, typename Allocator>
Vector<T, Allocator>& 
Vector<T, Allocator>::operator=(const Vector& ob) {
    if (this != &ob) {
        clear();
        size = ob.size;
        capacity = ob.capacity;
        arr = alloc.allocate(capacity);
        for (size_type i = 0; i < size; ++i) {
            alloc.construct(arr + i, ob.arr[i]);
        }
    }
    return *this;
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(Vector&& ob) noexcept
    : size{ob.size},
      capacity{ob.capacity},
      arr{ob.arr} 
{
    ob.arr = nullptr;
    ob.size = 0;
    ob.capacity = 0;
}

template <typename T, typename Allocator>
Vector<T, Allocator>&
Vector<T, Allocator>::operator=(Vector&& ob) noexcept {
    if (this != &ob) {
        clear();
        size = ob.size;
        capacity = ob.capacity;
        arr = ob.arr;
        ob.arr = nullptr;
        ob.size = 0;
        ob.capacity = 0;
    }
    return *this;
}

template <typename T, typename Allocator>
template <typename InputIt>
Vector<T, Allocator>::Vector(InputIt first, InputIt last)
    : size(std::distance(first, last)),
      capacity(size),
      arr(alloc.allocate(capacity)) 
{
    size_type i = 0;
    try {
        for (; first != last; ++first, ++i) {
            alloc.construct(arr + i, *first);
        }
    } catch (...) {
        for (size_type j = 0; j < i; ++j) {
            alloc.destroy(arr + j);
        }
        alloc.deallocate(arr, capacity);
        throw;
    }
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::allocator_type 
Vector<T, Allocator>::get_allocator() const {
    return alloc;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reference
Vector<T, Allocator>::operator[](size_type index) {
    return arr[index];
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reference
Vector<T, Allocator>::operator[](size_type index) const {
    return arr[index];
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reference
Vector<T, Allocator>::at(size_type index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reference
Vector<T, Allocator>::at(size_type index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reference
Vector<T, Allocator>::front() {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return arr[0];
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reference
Vector<T, Allocator>::front() const {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return arr[0];
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reference
Vector<T, Allocator>::back() {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return arr[size - 1];
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reference
Vector<T, Allocator>::back() const {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return arr[size - 1];
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator 
Vector<T, Allocator>::begin() {
    return iterator(arr);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator 
Vector<T, Allocator>::begin() const {
    return const_iterator(arr);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator 
Vector<T, Allocator>::cbegin() const {
    return const_iterator(arr);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::end() {
    return iterator(arr + size);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator
Vector<T, Allocator>::end() const {
    return const_iterator(arr + size);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator
Vector<T, Allocator>::cend() const {
    return const_iterator(arr + size);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reverse_iterator
Vector<T, Allocator>::rbegin() {
    return reverse_iterator(arr + size - 1);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reverse_iterator
Vector<T, Allocator>::rbegin() const {
    return const_reverse_iterator(arr + size - 1);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reverse_iterator
Vector<T, Allocator>::crbegin() const {
    return const_reverse_iterator(arr + size - 1);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reverse_iterator
Vector<T, Allocator>::rend() {
    return reverse_iterator(arr - 1);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reverse_iterator
Vector<T, Allocator>::rend() const {
    return const_reverse_iterator(arr - 1);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reverse_iterator
Vector<T, Allocator>::crend() const {
    return const_reverse_iterator(arr - 1);
}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::empty() const {
    return size == 0;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::size_type
Vector<T, Allocator>::arr_size() const {
    return size;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::size_type
Vector<T, Allocator>::arr_capacity() const {
    return capacity;
}

template <typename T, typename Allocator>
void 
Vector<T, Allocator>::reserve(size_type new_cap) {
    if (new_cap > capacity) {
        pointer new_arr = alloc.allocate(new_cap);
        for (size_type i = 0; i < size; ++i) {
            alloc.construct(new_arr + i, arr[i]);
            alloc.destroy(arr + i);
        }
        alloc.deallocate(arr, capacity);
        arr = new_arr;
        capacity = new_cap;
    }
}

template <typename T, typename Allocator>
void 
Vector<T, Allocator>::clear() noexcept {
    for (size_type i = 0; i < size; ++i) {
        alloc.destroy(arr + i);
    }
    alloc.deallocate(arr, capacity);
    size = 0;
    capacity = 0;
    arr = nullptr;
}

template <typename T, typename Allocator>
void
Vector<T, Allocator>::push_back(const_reference val) {
    if (size == capacity) {
        reserve(capacity > 0 ? capacity * 2 : 1);
    }
    alloc.construct(arr + size, val);
    ++size;
}

template <typename T, typename Allocator>
void
Vector<T, Allocator>::pop_back() {
    if (size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    alloc.destroy(arr + size - 1);
    --size;
}

template <typename T, typename Allocator>
void
Vector<T, Allocator>::resize(size_type new_size, const_reference val) {
    if (new_size > capacity) {
        reserve(new_size);
    }
    if (new_size > size) {
        for (size_type i = size; i < new_size; ++i) {
            alloc.construct(arr + i, val);
        }
    } else {
        for (size_type i = new_size; i < size; ++i) {
            alloc.destroy(arr + i);
        }
    }
    size = new_size;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::insert(const_iterator pos, const_reference val) {
    size_type index = pos - cbegin();
    if (size == capacity) {
        reserve(capacity > 0 ? capacity * 2 : 1);
    }
    for (size_type i = size; i > index; --i) {
        alloc.construct(arr + i, arr[i - 1]);
        alloc.destroy(arr + i - 1);
    }
    alloc.construct(arr + index, val);
    ++size;
    return iterator(arr + index);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::erase(const_iterator pos) {
    size_type index = pos - cbegin();
    alloc.destroy(arr + index);
    for (size_type i = index; i < size - 1; ++i) {
        alloc.construct(arr + i, arr[i + 1]);
        alloc.destroy(arr + i + 1);
    }
    --size;
    return iterator(arr + index);
}

/*template <typename T, typename Allocator>
void
Vector<T, Allocator>::swap(Vector& other) noexcept {
    using std::swap;
    swap(size, other.size);
    swap(capacity, other.capacity);
    swap(arr, other.arr);
    swap(alloc, other.alloc);
}*/

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::operator==(const Vector& other) const {
    if (size != other.size) {
        return false;
    }
    for (size_type i = 0; i < size; ++i) {
        if (!(arr[i] == other.arr[i])) {
            return false;
        }
    }
    return true;
}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::operator!=(const Vector& other) const {
    return !(*this == other);
}

template <typename T, typename Allocator>
std::ostream& operator<<(std::ostream& os, const Vector<T, Allocator>& v) {
    os << "[";
    for (size_t i = 0; i < v.size; ++i) {
        if (i != 0) {
            os << ", ";
        }
        os << v[i];
    }
    os << "]";
    return os;
}

#endif // __VECTOR_TPP__
