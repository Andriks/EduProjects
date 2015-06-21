#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stack>

template <typename T>
class MyQueue {
public:

    void push(T);
    T pop();

private:
    void refresh_stacks();

private:
    std::stack<T> dstack_buf;	//direct stack
    std::stack<T> rstack_buf;	//revers stack (to make access to first member)
};

template <typename T>
void MyQueue<T>::push(T val) {
    dstack_buf.push(val);
}

template <typename T>
T MyQueue<T>::pop() {
    if (rstack_buf.empty())
        refresh_stacks();

    T res = rstack_buf.top();
    rstack_buf.pop();

    return res;
}

template <typename T>
void MyQueue<T>::refresh_stacks() {
    while (!dstack_buf.empty()) {
        rstack_buf.push(dstack_buf.top());
        dstack_buf.pop();
    }
}


#endif // MYQUEUE_H
