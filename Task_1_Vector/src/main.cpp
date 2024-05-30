#include "../header/vector.h"
#include <iostream>


/*int main() {
    Vector<int> vec;
    vec.push_back(1);
    vec.insert(vec.cbegin(), 5, 5);
    vec.insert(vec.cbegin(), 6);
    vec.insert(vec.cbegin(), {22, 33, 44, 55});
    vec.erase(vec.cbegin(), vec.cend() - 5);
    vec.erase(vec.cbegin() + 1);

  
    std::cout << std::endl;

    return 0;
}*/

//#include "vector.h"
//#include <iostream>

int main() {
    // Testing the default constructor
    Vector<int> vec1;
    std::cout << "vec1 (default constructor): ";
    std::cout << std::endl;

    // Testing the constructor with size and default value
    Vector<int> vec2(2, 10);
    std::cout << "vec2 (size 2, value 10): ";
    std::cout << std::endl;

    // Testing the initializer list constructor
    Vector<int> vec3 = {1, 2, 3, 4, 5};
    std::cout << "vec3 (initializer list): ";
    std::cout << std::endl;

    // Testing the copy constructor
    Vector<int> vec4(vec3);
    std::cout << "vec4 (copy of vec3): ";
    std::cout << std::endl;

    // Testing the move constructor
    Vector<int> vec5(std::move(vec4));
    std::cout << "vec5 (moved from vec4): ";
    
    std::cout << std::endl;

    // Testing the copy assignment operator
    Vector<int> vec6;
    vec6 = vec3;
    std::cout << "vec6 (copy assigned from vec3): ";

    std::cout << std::endl;

    // Testing the move assignment operator
    Vector<int> vec7;
    vec7 = std::move(vec3);
    std::cout << "vec7 (move assigned from vec3): ";
    
    std::cout << std::endl;

    // Testing push_back
    vec1.push_back(42);
    std::cout << "vec1 after push_back(42): ";
    
    std::cout << std::endl;

    // Testing insert
    vec1.insert(vec1.cbegin(), 24);
    std::cout << "vec1 after insert at begin(24): ";
    
    std::cout << std::endl;

    // Testing erase
    vec1.erase(vec1.cbegin());
    std::cout << "vec1 after erase(begin): ";
    
    std::cout << std::endl;

    // Testing clear
    vec1.clear();
    std::cout << "vec1 after clear: " << vec1.arr_size() << " elements" << std::endl;

    return 0;
}
