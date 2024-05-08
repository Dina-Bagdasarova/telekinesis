#include "../header/queue.h"

int main() {
    Queue<int, std::vector<int>> que;
    que.push(1);
    que.push(2);
    que.push(3);
    
    std::cout << "Front element: " << que.front() << std::endl;
    std::cout << "Size: " << que._size() << std::endl;
    
    que.pop();
    
    std::cout << "Front element after pop: " << que.front() << std::endl;
    std::cout << "Size after pop: " << que._size() << std::endl;
    
    Queue<int, std::vector<int>> que2;
    que2.push(4);
    que2.push(5);
    
    std::cout << "Comparing the two queues: " << std::endl;
    
    std::cout << "que1 == que2 : " << (que == que2) << std::endl; // false
    std::cout << "que1 > que2 : " << (que > que2) << std::endl; // true
    std::cout << "que1 < que2 : " << (que < que2) << std::endl; // false
    std::cout << "que1 >= que2 : " << (que >= que2) << std::endl; // true
    std::cout << "que1 <= que2 : " << (que <= que2) << std::endl; // false
    std::cout << "que1 != que2 : " << (que != que2) << std::endl; // true



       
    que.swap(que2);
    
    std::cout << "After swapping: " << std::endl;
    std::cout << "Front element of que: " << que.front() << std::endl;
    std::cout << "Front element of que2: " << que2.front() << std::endl;
    
    return 0;
}
