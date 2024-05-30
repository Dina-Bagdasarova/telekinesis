#ifndef __VECTOR_ALLOC__
#define __VECTOR_ALLOC__
#include <iostream>


const int N = 1000;
char storage[N];

template <typename T>
class Vector_allocator{

public:
    using value_type = T;
    using size_type = size_t;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using referance = value_type&;
    using const_referance = const value_type&;
    
    bool flag = false;
public:
    Vector_allocator() = default;
    Vector_allocator(const Vector_allocator& rhv) = default;
    /*Vector_allocator(Vector_allocator&& rhv) = default;
    Vector_allocator& operator=(const Vector_allocator& rhv) = default;
    Vector_allocator& operator=(Vector_allocator&& rhv) = default;*/
    ~Vector_allocator() = default;

public:
     pointer allocate(size_type count);

     void deallocate(pointer ptr, size_type count);
     
     template <typename ...Args>
     void constract(pointer ptr, Args ...args);

     void destroy(pointer ptr);

    /* constexpr*/ size_type max_size(const Vector_allocator); 



};

#include "Vector_alloc.hpp"

#endif
