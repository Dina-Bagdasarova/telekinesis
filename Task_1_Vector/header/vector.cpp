#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__
#include <iostream>
#include <initializer_list>
#include "vector.h"
template <typename T>
void
Vector<T>::recap(size_type newSize) {
    if (newSize == capacity) {
        capacity *= 2;
        value_type* tmp = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
    }
}

template <typename T>
Vector<T>::Vector()
: size(0),
  capacity(0),
  arr(new T[capacity])
  { }

template <typename T>
Vector<T>::~Vector() {
  size(0);
  capacity(0);
  delete[] arr;
 }

template <typename T>
Vector<T>::Vector(size_type s)
:Vector(s, value_type{})
 {
    if (arr != nullptr) {
        clear();
    }
}

template <typename T>
Vector<T>::Vector(size_type size, const_reference val)
: size{0},
  capacity{0},
  arr{nullptr}
{
   if(size == 0){
        return;
        }
  arr = new value_type[capacity];

         for (size_t i = 0; i < size; ++i) {
                arr[i] = val;
    }
}


template <typename T>
Vector<T>::Vector(const Vector& ob)
:
   size{ob.size},
   capacity{ob.capacity},
   arr{new T[this->capacity]}
  {
        for(int i = 0; i < size; ++i){
                this->arr[i] = ob.arr[i];
        }
  }

template <typename T>

const  Vector<T>& Vector<T>::operator=(const Vector& ob){
 if(this != &ob){
   clear();
   this->size = ob.size;
   this->capacity = ob.capacity;
   this->arr = new T[this->capacity];

        for(int i = 0; i < size; ++i){
                this->arr[i] = ob.arr[i];
                }
        }
   return *this;
}

template <typename T>
Vector<T>::Vector(Vector&& ob)
:
   size{ob.size},
   capacity{ob.capacity},
   arr{ob.arr}
  {
        ob.arr = nullptr;
        ob.size = 0;
        ob.capacity = 0;
  }

template <typename T>

const Vector<T>& Vector<T>::operator=(Vector&& ob){
 if(this != &ob){
   clear();
   this->size = ob.size;
   this->capacity = ob.capacity;
   this->arr = ob.arr;
   ob.arr = nullptr;
        }
   return *this;
}


template <typename T>
void
Vector<T>::clear() {
    delete[] arr;
    arr = nullptr;
    size = 0;
}

template <typename T>
void
Vector<T>::resize(size_type s, const_reference val2) {
    if (s < size) {
        size = s;
    }
    if (s > size) {
        while (capacity < s) {
            recap(s);
        }
        for (size_t i = 0; i < s; ++i) {
            arr[i] = val2;
        }
    }
}

template <typename T>
void
Vector<T>::push_back(const_reference val) {
    if (size == capacity) {
        clear();
        recap();
    }
    arr[size] = val;
    ++size;
}

template <typename T>
void
Vector<T>::pop_back() {
    if (size != 0) {
        --size;
    }
}

template <typename T>
void
Vector<T>::insert(size_type index, const_reference val) {
    if (size == capacity) {
        clear();
        recap();
    }
    ++size;
    for (size_t i = size - 1; i > index; --i) {
        T tmp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = tmp;
    }
    arr[index] = val;
}

template <typename T>
void
Vector<T>::erase(size_type index) {
    for (size_t i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --size;
}

template <typename T>
Vector<T>::reference
Vector<T>::at(size_type index) {
    return arr[index];
}

template <typename T>
bool
Vector<T>::empty() {
    if (arr == nullptr) {
        return true;
    } else {
        return false;
    }
    if (size == 0) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
Vector<T>::reference
Vector<T>::front() {
    return arr[0];
}

template <typename T>
Vector<T>::reference
Vector<T>::back() {
    return arr[size - 1];
}

template <typename T>
Vector<T>::size_type
Vector<T>::arr_size() {
    return size;
}

template <typename T>
Vector<T>::size_type
Vector<T>::arr_capacity() {
    return capacity;
}

template <typename T>
 bool operator<(const Vector<T>& lvl, const Vector<T>& rvl) {
return &lvl < &rvl;
}

template <typename T>
bool operator>(const Vector<T>& lvl, const Vector<T>& rvl) {
return &lvl > &rvl;
}

template <typename T>
bool operator==(const Vector<T>& lvl, const Vector<T>& rvl) {
return &lvl == &rvl; }

template <typename T>
bool operator!=(const Vector<T>& lvl, const Vector<T>& rvl) {
return !(&lvl == &rvl); }

template <typename T>
bool operator<=(const Vector<T>& lvl, const Vector<T>& rvl) {
return &lvl <= &rvl; }

template <typename T>
bool operator>=(const Vector<T>& lvl, const Vector<T>& rvl) {
return &lvl >= &rvl; }



#endif
