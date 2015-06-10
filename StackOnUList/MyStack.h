#pragma once

typedef int Data;

struct UList {
    Data l_data;
    UList *l_next;
};

class MyStack
{
public:
    MyStack(void);
    ~MyStack(void);

    void push(Data);
    bool pop();

    Data top() const;
    size_t size() const;
    bool empty() const;

private:
    size_t s_size;
    UList *s_top;
};

