#ifndef PRIORITY_QUEUE_RAW_H_2022_10_08
#define PRIORITY_QUEUE_RAW_H_2022_10_08

#include <memory>
#include <stack>
class Heap
{
private:
    struct Node
    {
        int value;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::weak_ptr<Node> parent;
    };
private:
    std::shared_ptr<Node> root_;
    size_t size_;
private:
    std::stack<size_t> ParentPath(size_t size) const;
    void SiftUp(const std::shared_ptr<Node>& node);
    void SiftDown(const std::shared_ptr<Node>& node);
public:
    Heap();
    void Push(int value);
    void Pop();
    int Top() const;
};
#endif