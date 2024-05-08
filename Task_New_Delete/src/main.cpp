#include "../header/new_del.hpp"

int main() {
    // Using single object new and delete
    int* obj = Op_New<int>(1);
    *obj = 10;
    std::cout << "Object created using single object new: " << *obj << std::endl;
    Operator_Del(obj);

    // Using array new and delete
    int* arr = New_For_Arr<int>(5);
    std::cout << "Array created: ";
    for(int i = 0; i < 5; ++i){
	arr[i] = i * 2;
        std::cout << arr[i] << " ";
    }
    
    Del_For_Arr(arr, 5);

    return 0;
}
