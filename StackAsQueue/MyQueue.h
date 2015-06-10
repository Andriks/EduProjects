#pragma once

template <typename T>
class MyQueue {
public:
    void push(T);
    T pop();

private:
    void revers(std::stack<T> &);

private:
    std::stack<T> stack_buf;
};

template <typename T>
void MyQueue<T>::push(T val) {
    stack_buf.push(val);
}

template <typename T>
void MyQueue<T>::revers(std::stack<T> & inp) {
    std::stack<T> tmp;
    while (!inp.empty()) {
        tmp.push(inp.top());
        inp.pop();
    }

    inp = tmp;
}

template <typename T>
T MyQueue<T>::pop() {
    revers(stack_buf);
    
    T res = stack_buf.top();
    stack_buf.pop();
    revers(stack_buf);
    
    return res;
}