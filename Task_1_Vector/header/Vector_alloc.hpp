#ifndef __VECTOR_ALLOC_HPP__
#define __VECTOR_ALLOC_HPP__
#include "vector_aloc.h"

template <typename T>

    Vector_allocator::pointer
    Vector_allocator<T>::allocate(size_type count){
	if(!flag){
		return static_cast<void*>(storage)
