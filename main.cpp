#include "../header//stack.hpp"

int main() {
    Stack<int, std::vector<int>> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    std::cout << "Size of stack1: " << stack1.size() << std::endl;
    std::cout << "Top element of stack1: " << stack1.top() << std::endl;

    Stack<int, std::vector<int>> stack2 = stack1;
    std::cout << "Create stack2" << std::endl;

    stack1.pop();

    std::cout << "Size of stack1 after pop: " << stack1.size() << std::endl;
    std::cout << "Top element of stack1 after pop: " << stack1.top() << std::endl;
   
    std::cout << "Top element of stack2: " << stack2.top() << std::endl;

    //std::cout << "Is stack1 empty? " << (stack1.empty() ? "Yes" : "No") << std::endl;

    if(stack1 < stack2) {
        std::cout << "stack1 is less than stack2" << std::endl;
    } else if(stack1 > stack2) {
        std::cout << "srack1 is greater than stack2" << std::endl;
    } else if(stack1 == stack2) {
        std::cout << "stac1 is equal to stack2" << std::endl;
    }

    stack1.swap(stack2);

    std::cout << "Swapping stack1 and stack2" << std::endl;
    std::cout << "Top element of stack1 after swap: " << stack1.top() << std::endl;
    std::cout << "Top element of stack2 after swap: " << stack2.top() << std::endl;

    return 0;
}
