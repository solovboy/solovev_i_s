#include <iostream>
#include "queue_r.h"
int main() {
    Heap h;
    h.Push(5);
    h.Push(3);
    std::cout << h.Top() << std::endl;
    h.Pop();
    h.Push(4);
    std::cout << h.Top() << std::endl;
    for (int i = 0; i < 10; ++i) {
        h.Push(i);
    }
    std::cout << h.Top() << std::endl;
    for (int i = 0; i < 10; ++i) {
        h.Pop();
    }
    std::cout << h.Top() << std::endl;
    h.Pop();
    std::cout << h.Top() << std::endl;
    h.Pop();
    h.Push(15);
    std::cout << h.Top() << std::endl;
}