#ifndef __NEW_DEL_T__
#define __NEW_DEL_T__
#include <iostream>
#include <cstdlib>


        void* Operator_New(size_t size){
	    void* p = std::malloc(size);
	    if(!p){
		    
		 throw std::bad_alloc();

		}
	    return p;
	}

        void Operator_Del(void* p){
	     if(p){

		std::free(p);
		
		}
	    return;
	  }


        template <typename T>

        T* Op_New(T s){

	    void* p = Operator_New(s * sizeof(T));
	    T* ptr = static_cast<T*>(p);
	    *ptr = T();

	    return ptr;
	}
   

        template <typename T>

        T* Op_Delete(T, T* ptr){

	    if(ptr){
		::Operator_Del(ptr);
		T::~T(ptr);
		}
	}


        template <typename T>

        T* New_For_Arr(size_t size){
	
	   void* p = Operator_New(size * sizeof(T));
	   T* ptr = static_cast<T*>(p);

	   for(size_t i = 0; i < size; ++i){
		
		new (ptr+i) T();

		}
	    return ptr;
	}

        template <typename T>

        void Del_For_Arr(T* p, size_t size){

	    if(p){

		for(size_t i = size; i != -1; --i){
			(p-1)->~T();
			}
		     Operator_Del(p);
		}
	}

#endif
