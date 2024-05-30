#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__
#include <iostream>
#include <initializer_list>
#include "vector.h"
#include <memory>

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector()
: size{0},
  capacity{},
  arr{nullptr}
  { }
//
//
template <typename T, typename Allocator>
Vector<T, Allocator>::~Vector() {
  clear();
 }

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(int x, int y) 
     : size(x),
  capacity(x)

{
    arr = alloc.allocate(capacity);
   if(size == 0){
        return;
   }
  //arr = new value_type[capacity];

         for (size_t i = 0; i < size; ++i) {
                alloc.construct(arr + i, y);
    }
}



template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(size_type size, const_reference val)
: size(size),
  capacity(size)

{
    arr = alloc.allocate(capacity);
   if(size == 0){
        return;
   }
  //arr = new value_type[capacity];

         for (size_t i = 0; i < size; ++i) {
                alloc.construct(arr + i, val);
    }
}


template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(std::initializer_list<T> init) 
     
{
    size_type init_size = init.size(); 
    size = init_size;
    capacity = init_size * 2;
    arr = alloc.allocate(capacity);
    
    size_type i = 0;
    for (const_reference item :init)
    {
        alloc.construct(arr+i, item);
        ++i;
    }
}


/*template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(std::initializer_list<value_type> init)
     : Vector()
{
    for (const_reference val : init) {
        push_back(val);
    }

}*/

//template <typename T, typename Allocator>
//Vector<T, Allocator>::Vector(const Vector& ob)
//    : size{ob.size},
//      capacity{ob.capacity},
//      arr{alloc.allocate(capacity)}
//{
//    try {
//        for (size_t i = 0; i < size; ++i) {
//            alloc.construct(arr + i, ob.arr[i]);
//        }
//    } catch (...) {
//        clear();
//        throw;
//    }
//}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(const Vector& ob)
:  size{ob.size},
   capacity{ob.capacity}

 {
    arr = alloc.allocate(capacity);

    for(int i = 0; i < size; ++i){
        alloc.construct(&arr[i], ob.arr[i]);
    }
  }


template <typename T, typename Allocator>
Vector<T, Allocator>&
Vector<T, Allocator>::operator=(const Vector& ob){
 if(this != &ob){
   clear();
   this->size = ob.size;
   this->capacity = ob.capacity;
   arr = alloc.allocate(ob.capacity);

        for(int i = 0; i < size; ++i){
                alloc.construct(arr+i, ob.arr[i]);
                }
        }
   return *this;
}


template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(Vector&& ob)
:
   size{ob.size},
   capacity{ob.capacity},
   arr{ob.arr}
  {
        ob.arr = nullptr;
        ob.size = 0;
        ob.capacity = 0;
  }

template <typename T, typename Allocator>
Vector<T, Allocator>&
Vector<T, Allocator>::operator=(Vector&& ob){
 if(this != &ob){
        clear();
        this->size = ob.size;
        this->capacity = ob.capacity;
        this->arr = alloc.allocate(capacity);
        ob.arr = nullptr;
    }

   return *this;
}

template <typename T, typename Allocator>
template <typename InputIt>
Vector<T, Allocator>::Vector(InputIt first, InputIt last)
    :size(std::distance(first, last)),
     capacity(std::distance(first, last)),
     arr(alloc.allocate(capacity))
{
    size_type i = 0;
    try{
        for(; first != last;  ++first, ++i){
            alloc.construct(arr + i, first);
        }
      } catch(...){
            for(size_t j = 0; j < i; ++j){
                alloc.destroy(arr + j);
            }
        alloc.deallocate(arr, capacity);
        throw;

        }
    }

template <typename T, typename Allocator>
typename Vector<T, Allocator>::allocator_type
Vector<T, Allocator>::get_allocator()
{
    return alloc;
}


template <typename T, typename Allocator>
typename Vector<T, Allocator>::reference
Vector<T, Allocator>::operator[](size_type index){
    return arr[index];
 }


template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reference
Vector<T, Allocator>::operator[](size_type index) const{
    return arr[index];
 }


template <typename T, typename Allocator>
typename Vector<T, Allocator>::reference
Vector<T, Allocator>::at(size_type index) {
    if(index > size){
        throw 1;
    } else {
    return arr[index];
    }
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reference
Vector<T, Allocator>::at(size_type index) const {
    if(index > size){
        throw 0;
    } else {
    return this->arr[index];
    }
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reference
Vector<T, Allocator>::front() {
if(!empty()){
        throw 0;
    } else {

    return this->arr[0];

    }
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reference
Vector<T, Allocator>::front() const{
if(!empty()){
    throw 0;
    } else {

    return this->arr[0];
    }
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reference
Vector<T, Allocator>::back() {
    if(!empty()){
        throw 0;
    } else {
    return arr[size - 1];
    }
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reference
Vector<T, Allocator>::back() const {
    if(!empty()){
        throw 0;
    } else {
    return arr[size - 1];
    }
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::begin(){

    return iterator(arr);
}


template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator
Vector<T, Allocator>::begin() const{

 return const_iterator(arr);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator
Vector<T, Allocator>::cbegin() const {

    const_iterator iter = arr;
    return iter;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::end(){

    return iterator(arr + size);
}


template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator
Vector<T, Allocator>::end() const{

 return const_iterator(arr + size);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator
Vector<T, Allocator>::cend() const{

    const_iterator iter = arr + size;
    return iter;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::rbegin(){

    return iterator(arr + size - 1);
}


template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator
Vector<T, Allocator>::rbegin() const{

 return const_iterator(arr + size - 1);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator
Vector<T, Allocator>::crbegin() const{

    const_iterator iter = arr + size - 1;
    return iter;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::rend(){

    return iterator(arr - 1);
}


template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator
Vector<T, Allocator>::rend() const{

 return const_iterator(arr - 1);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator
Vector<T, Allocator>::crend() const{

    const_iterator iter = arr - 1;
    return iter;

}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::empty() const{
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

template <typename T, typename Allocator>
typename Vector<T, Allocator>::size_type
Vector<T, Allocator>::arr_size() const{
    return this->size;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::size_type
Vector<T, Allocator>::arr_capacity()  const{
    return this->capacity;
}


template <typename T, typename Allocator>
void Vector<T, Allocator>::reserve(size_type new_cap)
{
    if (new_cap > capacity) {
        pointer new_arr = alloc.allocate(new_cap);

        for (size_type i = 0; i < size; ++i) {
           alloc.construct(new_arr + i, std::move(arr[i]));
            alloc.destroy(arr + i);
        }

        alloc.deallocate(arr, capacity);
        arr = new_arr;
        capacity = new_cap;
    }
}


template <typename T, typename Allocator>
void
Vector<T, Allocator>::clear() noexcept
{
    for(size_type i = 0; i < size; ++i) {
        alloc.destroy(&arr[i]);
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
        reserve(capacity == 0 ? 1 : capacity*2);
    }
    alloc.construct(arr + size, val);
    ++size;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::insert(const_iterator pos, const_reference val) {
    size_type index = pos.ptr - arr;
    
    if(index > size ){
        throw std::out_of_range("index is out of range");
    }

    if(index == size){
        push_back(val);
        return end() - 1; 
    }
        if(size >= capacity){
            reserve(capacity*2);
    }

        for(size_type i = size; i > index; --i ){
            arr[i] = arr[i - 1];
        }

        alloc.construct(arr + index, val);
        
		++size;

        return begin() + index;
 
	}


/*template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::insert(const_iterator pos, size_type count,  const_reference val) {
    int index = pos - begin();
    
    if (index > size) {
        throw "out of range";
    }

    if (size >= capacity) {
        reserve(capacity * 2);
    }

    
    for(size_type j = 0; j < count; ++j ){
        for (int i = size; i > index; --i) {
            arr[i] = arr[i - 1];
            ++index;
        }
    }
    
    arr[index] = val;
    ++size;

}*/


template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::insert(const_iterator pos, size_type count,  const_reference val) {

    for(int i = 0; i < count; ++i){
         pos = insert(pos, val);
         ++pos;
    }
}


template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::insert(const_iterator pos,std::initializer_list<value_type> init) {

    for(const_reference i : init){
        pos = insert(pos, i);
        ++pos;
    }
}


template<typename T, typename Allocator>
template <typename InputIt>
typename Vector<T, Allocator>::iterator 
Vector<T, Allocator>::insert(const_iterator pos, InputIt first, InputIt last){

        for(; first < last; ++first){
            pos = insert(pos, first);
            ++pos;
        }
}
    
template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::erase(const_iterator pos) {
    size_type index = pos.ptr - arr; 

    if (index >= size) { 
        throw std::out_of_range("index out of range");
    }

    for (size_type i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    alloc.destroy(&arr[size - 1]); 
    --size;

    return begin() + index;
}


template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::erase(const_iterator first, const_iterator last) {
    size_type index_first = first.ptr - arr; 
    size_type index_last = last.ptr - arr; 

    if (index_first >= size || index_last > size || index_first >= index_last) { 
        throw std::out_of_range("erase range out of range");
    }

    size_type count = index_last - index_first;

    
    for (size_type i = index_first; i < size - count; ++i) {
        arr[i] = std::move(arr[i + count]);
        //alloc.construct(&arr[i], arr[i + count]);
        //alloc.destroy(&arr[i + count]);
    }

    
    for (size_type i = size - count; i < size; ++i) {
        alloc.destroy(&arr[i]);
    }

    size -= count;

    return begin() + index_first;
}  
    

template < typename T, typename Allocator >
void
Vector<T, Allocator>::pop_back() {
    if (size == 0) {
        throw 0;
    }
    alloc.destroy(arr + size - 1);
    --size;
}


template <typename T, typename Allocator>
void Vector<T, Allocator>::resize(size_type new_size, const_reference val){
	if(new_size > capacity){
		size_type tmp = new_size / capacity;
    	reserve(tmp + 1);
	}
	while ( new_size > size){
		arr[size] = val;
		++size;
	}

	if(new_size < size){
    	size = new_size;
	}
}

template <typename T, typename Allocator>
 bool
Vector<T, Allocator>::operator<(const Vector<T>& rvl) const {
return compare(rvl) < 0;
}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::operator>(const Vector<T>& rvl) const {
return compare(rvl) > 0;
}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::operator==(const Vector<T>& rvl) const{
return  compare(rvl) == 0;
}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::operator!=(const Vector<T>& rvl) const{
return !(compare(rvl) == 0);
}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::operator<=(const Vector<T>& rvl) const {
return  compare(rvl) <= 0;
}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::operator>=(const Vector<T>& rvl) const{
return  compare(rvl) >= 0;

}

template <typename T, typename Allocator>
int
Vector<T, Allocator>::compare(const Vector& other) const{
     if (this->size < other.size) {
        return -1;
    } else if (this->size > other.size) {
        return 1;
    }

    for(int i = 0; i < size; ++i){
      if ( this->arr[i] < other.arr[i]){
            return -1;
     }
        if(this->arr[i] < other.arr[i]){
            return 1;
        }
    }
    return 0;
}

template <typename T, typename Allocator>
Vector<T, Allocator>::const_iterator::const_iterator(pointer ptr)
: ptr{ptr}
{}


template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator//::const_iterator
Vector<T, Allocator>::const_iterator::operator+(size_type n) const {
 return const_iterator(ptr + n);
} //p.s. es chem haskanum inchn e sxal :( : minute later sxal chkar urish tex er :D


template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator//::const_iterator
 Vector<T, Allocator>::const_iterator::operator-(size_type n) const {

    return const_iterator(ptr - n);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator&//::const_iterator&
Vector<T, Allocator>::const_iterator::operator++() {

    ++ptr;
    return *this;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator//::const_iterator
Vector<T, Allocator>::const_iterator::operator++(int){

    const_iterator tmp = *this;
    ++ptr;
    return tmp;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator&//::const_iterator&
Vector<T, Allocator>::const_iterator::operator--(){

    --ptr;
    return *this;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_iterator//::const_iterator
Vector<T, Allocator>::const_iterator::operator--(int){

    const_iterator tmp = *this;
    --ptr;
    return tmp;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reference
Vector<T, Allocator>::const_iterator::operator*() const{

    return *ptr;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_pointer
Vector<T, Allocator>::const_iterator::operator->() const{

    return ptr;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reference
Vector<T, Allocator>::const_iterator::operator[](size_type pos) const{

    return ptr[pos];
}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::const_iterator::operator==(const const_iterator& other) const{

    return ptr == other.ptr;
}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::const_iterator::operator!=(const const_iterator& other) const{

    return !(ptr == other.ptr);
}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::const_iterator::operator<(const const_iterator& other) const{

    return ptr < other.ptr;
}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::const_iterator::operator<=(const const_iterator& other) const{

    return ptr < other.ptr || ptr == other.ptr;
}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::const_iterator::operator>(const const_iterator& other) const{

    return ptr > other.ptr;
}

template <typename T, typename Allocator>
bool
Vector<T, Allocator>::const_iterator::operator>=(const const_iterator& other) const{

    return ptr > other.ptr || ptr == other.ptr;
}

//________________________________________________________________________________________________________________________________________________
template <typename T, typename Allocator>
Vector<T, Allocator>::iterator::iterator(pointer ptr) {

    this->ptr = ptr;

}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::iterator::operator+(size_type n) const {

    return iterator(this->ptr+n);

}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::iterator::operator-(size_type n) const {

    return iterator(this->ptr - n);

}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator&
Vector<T, Allocator>::iterator::operator++() {

    ++this->ptr;
    return *this;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::iterator::operator++(int){

    iterator tmp = *this;
    ++this->ptr;
    return tmp;

 }

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator&
Vector<T, Allocator>::iterator::operator--(){

    --this->ptr;
    return *this;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator
Vector<T, Allocator>::iterator::operator--(int){

    iterator tmp = *this;
    --this->ptr;
    return tmp;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reference
Vector<T, Allocator>::iterator::operator*() {

    return *this->ptr;
 }

template <typename T, typename Allocator>
typename Vector<T, Allocator>::pointer
Vector<T, Allocator>::iterator::operator->() {

    return this->ptr;
 }

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reference
Vector<T, Allocator>::iterator::operator[](size_type pos) const{

    return this->ptr[pos];

}

/*template <typename T, typename Allocator>
 Vector<T, Allocator>::iterator::iterator(pointer ptr) {

    this->ptr = ptr;

}*/

//________________________________________________________________________________________________________________________________________________
template <typename T, typename Allocator>
Vector<T, Allocator>::const_reverse_iterator::const_reverse_iterator(pointer ptr)
: ptr{ptr}
{}


template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reverse_iterator//::const_reverse_iterator
Vector<T, Allocator>::const_reverse_iterator::operator+(size_type n) const {

    return const_reverse_iterator(ptr - n);
}


template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reverse_iterator//::const_reverse_iterator
Vector<T, Allocator>::const_reverse_iterator::operator-(size_type n) const {

    return const_iterator(ptr + n);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reverse_iterator&//::const_reverse_iterator&
Vector<T, Allocator>::const_reverse_iterator::operator++() {

    --this->ptr;
    return *this;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reverse_iterator//::const_reverse_iterator
Vector<T, Allocator>::const_reverse_iterator::operator++(int){

    const_reverse_iterator tmp = *this;
    --this->ptr;
    return tmp;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reverse_iterator&//::const_reverse_iterator&
Vector<T, Allocator>::const_reverse_iterator::operator--(){

    ++this->ptr;
    return *this;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reverse_iterator//::const_reverse_iterator
Vector<T, Allocator>::const_reverse_iterator::operator--(int){

    const_reverse_iterator tmp = *this;
    ++this->ptr;
    return tmp;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_reference
Vector<T, Allocator>::const_reverse_iterator::operator*() const{

    return *this->ptr;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::const_pointer
Vector<T, Allocator>::const_reverse_iterator::operator->() const{

    return this->ptr;
}

template <typename T, typename Allocator>
const T& Vector<T, Allocator>::const_reverse_iterator::operator[](size_type pos) const{

    return this->ptr[pos];
}

template <typename T, typename Allocator>
bool Vector<T, Allocator>::const_reverse_iterator::operator==(const const_reverse_iterator& other) const{

    return !(ptr == other.ptr);
}

template <typename T, typename Allocator>
bool Vector<T, Allocator>::const_reverse_iterator::operator!=(const const_reverse_iterator& other) const{

    return (ptr == other.ptr);
}

template <typename T, typename Allocator>
bool Vector<T, Allocator>::const_reverse_iterator::operator<(const const_reverse_iterator& other) const{

    return ptr > other.ptr;
}

template <typename T, typename Allocator>
bool Vector<T, Allocator>::const_reverse_iterator::operator<=(const const_reverse_iterator& other) const{

    return ptr > other.ptr || ptr == other.ptr;
}

template <typename T, typename Allocator>
bool Vector<T, Allocator>::const_reverse_iterator::operator>(const const_reverse_iterator& other) const{

    return ptr < other.ptr;
}

template <typename T, typename Allocator>
bool Vector<T, Allocator>::const_reverse_iterator::operator>=(const const_reverse_iterator& other) const{

    return ptr < other.ptr || ptr == other.ptr;
}
//_________________________________________________________________________________________________________________________________

template <typename T, typename Allocator>
 Vector<T, Allocator>::reverse_iterator::reverse_iterator(pointer ptr) {

    this->ptr = ptr;

}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reverse_iterator
Vector<T, Allocator>::reverse_iterator::operator+(size_type n) const {

    return reverse_iterator(this->ptr-n);

}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reverse_iterator
Vector<T, Allocator>::reverse_iterator::operator-(size_type n) const {

    return reverse_iterator(this->ptr + n);

}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reverse_iterator&
Vector<T, Allocator>::reverse_iterator::operator++() {

    --this->ptr;
    return *this;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reverse_iterator
Vector<T, Allocator>::reverse_iterator::operator++(int){

    reverse_iterator tmp = *this;
    --this->ptr;
    return tmp;

 }

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reverse_iterator&
Vector<T, Allocator>::reverse_iterator::operator--(){

    ++this->ptr;
    return *this;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reverse_iterator
Vector<T, Allocator>::reverse_iterator::operator--(int){

    reverse_iterator tmp = *this;
    ++this->ptr;
    return tmp;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reference
Vector<T, Allocator>::reverse_iterator::operator*() {

    return *this->ptr;
 }

template <typename T, typename Allocator>
typename Vector<T, Allocator>::pointer
Vector<T, Allocator>::reverse_iterator::operator->() {

    return this->ptr;
 }

template <typename T, typename Allocator>
typename Vector<T, Allocator>::reference
Vector<T, Allocator>::reverse_iterator::operator[](size_type pos) const{

    return this->ptr[pos];

}
//__________________________________________________________________________
#endif
