#include "queue_r.h"

Heap::Heap() : root_(nullptr), size_(0) {}

std::stack<size_t> Heap::ParentPath(size_t size) const {
    std::stack<size_t> stack;
    stack.push(size);
    while (stack.top() != 0) {
        stack.push((stack.top() - 1) / 2);
    }
    return stack;
}

void Heap::SiftUp(const std::shared_ptr<Node>& node) {
    if (node->parent.lock() == nullptr) {
        return;
    }
    auto parent = node->parent.lock();
    if (node->value < parent->value) {
        std::swap(node->value, parent->value);
        SiftUp(parent);
    }
}

void Heap::SiftDown(const std::shared_ptr<Node>& node) {
    if (node->left == nullptr) {
        return;
    }
    auto cond = node;
    if (node->left->value < node->value) {
        cond = node->left;
    }
    if (node->right != nullptr && node->right->value < cond->value) {
        cond = node->right;
    }
    if (cond == node) {
        return;
    }
    std::swap(node->value, cond->value);
    SiftDown(cond);
}

void Heap::Push(int value) {
    if (size_ == 0) {
        root_ = std::shared_ptr<Node>(new Node{ value, nullptr, nullptr, std::shared_ptr<Node>(nullptr) });
        ++size_;
        return;
    }
    auto path = ParentPath(size_);
    size_t current = path.top();
    path.pop();
    auto current_node = root_;
    while (path.size() > 1) {
        if (path.top() == current * 2 + 1) {
            current_node = current_node->left;
        }
        else {
            current_node = current_node->right;
        }
        current = path.top();
        path.pop();
    }
    if (path.top() == current * 2 + 1) {
        current_node->left = std::shared_ptr<Node>(new Node{ value, nullptr, nullptr, std::shared_ptr<Node>(current_node) });
        SiftUp(current_node->left);
    }
    else {
        current_node->right = std::shared_ptr<Node>(new Node{ value, nullptr, nullptr, std::shared_ptr<Node>(current_node) });
        SiftUp(current_node->right);
    }
    ++size_;
}

void Heap::Pop() {
    if (size_ == 1) {
        root_ = nullptr;
        --size_;
        return;
    }
    auto path = ParentPath(size_ - 1);
    size_t current = path.top();
    path.pop();
    auto current_node = root_;
    while (path.size() > 1) {
        if (path.top() == current * 2 + 1) {
            current_node = current_node->left;
        }
        else {
            current_node = current_node->right;
        }
        current = path.top();
        path.pop();
    }
    if (path.top() == current * 2 + 1) {
        std::swap(current_node->left->value, root_->value);
        current_node->left = nullptr;
    }
    else {
        std::swap(current_node->right->value, root_->value);
        current_node->right = nullptr;
    }
    SiftDown(root_);
    --size_;
}

int Heap::Top() const {
    return root_->value;
}