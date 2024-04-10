  #ifndef __VECTOR_H__
  #define __VECTOR_H__
  #include <iostream>
  #include <initializer_list>

  template <typename T>
  struct Vector {
  public:

	using size_type =  size_t;
	using value_type = T;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	using reference = value_type&;
	using const_reference = const value_type&;

  private:
	size_type size;
	size_type capacity;
	pointer arr = nullptr;

	void recap(size_type newSize);
	
  public:
	Vector();

	~Vector();

	Vector(size_type size);

	Vector(size_type size, const_reference val);
	
	Vector(std::initializer_list<value_type> init);

	Vector(const Vector& ob);//copy ctor
	
	const Vector& operator=(const Vector& ob);//copy assignment
	 
	Vector(Vector&& ob);//move ctor
	
	const Vector& operator=( Vector&& ob);//move assignment

	referance operator[](size_type);

	void clear();

	void resize(size_type s, const_reference val);

	void push_back(const_reference val);

	void pop_back();

	void insert(size_type index, const_reference val);

	void erase(size_type index);

	reference at(size_type index);

	bool empty();

	reference front();

	reference back();

	size_type arr_size();

	size_type arr_capacity();

	void swap(Vector& ob);

	void print();

	friend bool operator<(const Vector<T>& lvl, const Vector<T>& rvl);
	friend bool operator>(const Vector<T>& lvl, const Vector<T>& rvl);
	friend bool operator==(const Vector<T>& lvl, const Vector<T>& rvl);
	friend bool operator!=(const Vector<T>& lvl, const Vector<T>& rvl);
	friend bool operator<=(const Vector<T>& lvl, const Vector<T>& rvl);
	friend bool operator>=(const Vector<T>& lvl, const Vector<T>& rvl);

};

	template<typename T>
	bool operator>(const Vector<T>& lhv, const Vector<T>& rhv);

	template<typename T>
        bool operator<(const Vector<T>& lhv, const Vector<T>& rhv);

	template<typename T>
        bool operator==(const Vector<T>& lhv , const Vector<T>& rhv);

        template<typename T>
        bool operator!=(const Vector<T>& lhv, const Vector<T>& rhv);

	template<typename T>
        bool operator>=(const Vector<T>& lhv, const Vector<T>& rhv);

	template<typename T>
	bool operator<=(const Vector<T>& lhv, const Vector<T>& rhv);


#include "vector.hpp"
#endif
