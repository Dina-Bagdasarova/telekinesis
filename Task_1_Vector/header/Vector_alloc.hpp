#ifndef __VECTOR_ALLOC_HPP__
#define __VECTOR_ALLOC_HPP__
#include "Vector_aloc.h"
#include <iostream>

template <typename T>

    Vector_allocator<T>::pointer
    Vector_allocator<T>::allocate(size_type count){
        if(!flag){
            flag = !flag;
		    return static_cast<pointer>(static_cast<void*>(storage));
        } else {
            return static_cast<pointer>(static_cast<void*>(storage+500));
        }
        flag = !flag;
    }

    template <typename T>
    void 
    Vector_allocator<T>::deallocate(pointer ptr, size_t count )
    {}


    template <typename T>
    template <typename ...Args>
    void 
    Vector_allocator<T>::constract(pointer ptr, Args ...args){
        __constract_at(ptr, std::forward<Args>(args)...);
    }
    
    
    template <typename T>
    void 
    Vector_allocator<T>::destroy(pointer ptr){
        std::destroy_at(ptr);
    }

    template <typename T>
    Vector_allocator<T>::/*constexpr*/ size_type 
    Vector_allocator<T>::max_size(const Vector_allocator){
        return static_cast<size_type>(N) / 2;
    }

#endif
