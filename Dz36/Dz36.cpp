#include <iostream>
#include <string>


template <typename T>
class Stack {
private:
    T* arr;
    int topIndex;
    int capacity;

public:
    Stack(int capacity) : capacity(capacity), topIndex(-1) {
        arr = new T[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    T top() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return arr[topIndex];
    }

    void push(const T& value) {
        if (topIndex == capacity - 1) {
            throw std::runtime_error("Stack is full");
        }
        arr[++topIndex] = value;
    }

    void pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        --topIndex;
    }

    void show() const {
        for (int i = 0; i <= topIndex; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    int size() const {
        return topIndex + 1;
    }

    const T& get(int index) const {
        if (index < 0 || index > topIndex) {
            throw std::runtime_error("Index out of bounds");
        }
        return arr[index];
    }
};

int main() {
    Stack<std::string> stack(10);

    stack.push("abc");
    stack.push("fx");
    stack.push("glc");
    stack.push("hi");
    stack.push("gogo");

    std::cout << "Initial stack: ";
    stack.show();

    stack.pop();

    stack.push("the end");

    std::cout << "Stack after pop and push: ";
    stack.show();

    int count = 0;
    for (int i = 0; i < stack.size(); ++i) {
        if (stack.get(i).size() == 2) {
            ++count;
        }
    }

    std::cout << "Number of strings with 2 characters: " << count << std::endl;

    return 0;
}
