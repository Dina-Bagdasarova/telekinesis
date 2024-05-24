#include "../header/vector.h"

int main() {
    Vector<int> v1{1, 2, 3, 4, 5};
    Vector<int> v2{6, 7, 8, 9, 10};
    Vector<int> v3{11, 12, 13, 14, 15};

    Vector<int> v4 = v1;
    Vector<int> v5{v2};

    v1.push_back(6);
    v2.pop_back();

    Vector<int> v6 = v3;

    for (const auto& element : v1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    for (const auto& element : v2) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    for (const auto& element : v3) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}



/*
int main() { 
Vector<int> vec1(5); // creating a vector of size 5 
std::cout << "Initial size of vec1: " << vec1.arr_size() << std::endl; 
// pushing elements into vec1
vec1.push_back(1);
vec1.push_back(2);
vec1.push_back(3);
std::cout << "Size of vec1 after pushing elements: " << vec1.arr_size() << std::endl;

// accessing elements in vec1
std::cout << "Element at index 1 in vec1: " << vec1.at(1) << std::endl;

// creating a new vector vec2 using copy constructor
Vector<int> vec2(vec1);
std::cout << "Size of vec2 created using copy constructor: " << vec2.arr_size() << std::endl;

// resizing vec1
vec1.resize(8, 5);
std::cout << "Size of vec1 after resizing: " << vec1.arr_size() << std::endl;

// inserting element at index 2 in vec1
vec1.insert(2, 10);
std::cout << "Size of vec1 after inserting element: " << vec1.arr_size() << std::endl;

// erasing element at index 3 in vec1
vec1.erase(3);
std::cout << "Size of vec1 after erasing element: " << vec1.arr_size() << std::endl;

// checking if vec1 is empty
std::cout << "Is vec1 empty? " << (vec1.empty() ? "Yes" : "No") << std::endl;

// accessing front and back elements of vec1
std::cout << "Front element of vec1: " << vec1.front() << std::endl;
std::cout << "Back element of vec1: " << vec1.back() << std::endl;

// comparing vec1 and vec2
std::cout << "Is vec1 less than vec2? " << (vec1 < vec2 ? "Yes" : "No") << std::endl;

return 0;
}*/
