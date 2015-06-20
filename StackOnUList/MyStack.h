#pragma once

typedef int Data;

class MyStack
{
    struct UList {
        Data l_data;
        UList *l_next;
    };

public:
    MyStack(void);
    MyStack(const MyStack&);
    ~MyStack(void);

    MyStack& operator=(const MyStack&);

    void push(Data);
    bool pop();

    void swap(MyStack&);

    Data top() const;
    size_t size() const;
    bool empty() const;

private:
    void copy_stack(UList*);
    void clear_stack();

private:
    size_t s_size;
    UList *s_top;
};

//don't works ((
//namespace std {
//    template<class MyStack>
//    void swap(MyStack &a, MyStack &b) {
//        a.swap(b);
//    }
//}
