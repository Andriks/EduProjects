#include "StdAfx.h"
#include "MyStack.h"


MyStack::MyStack(void): s_size(0), s_top(NULL)
{
}

MyStack::MyStack(const MyStack &base): s_size(0), s_top(NULL)
{
    if (base.s_top == NULL)
        return;

    copy_stack(base.s_top);
}

MyStack::~MyStack(void)
{
    clear_stack();
}

MyStack& MyStack::operator=(const MyStack &base)
{
    //no need to do anything
    if (base.s_top == s_top)
        return *this;

    clear_stack();

    if (base.s_top == NULL)
        return *this;

    copy_stack(base.s_top);

    return *this;
}

void MyStack::push(Data val)
{
    UList *p = new UList;
    p->l_data = val;
    p->l_next = s_top;

    s_top = p;
    s_size++;
}


bool MyStack::pop()
{
    if (s_top == NULL)
        return false;

    UList *next_top = s_top->l_next;
    
    delete s_top;

    s_top = next_top;
    s_size--;

    return true;
}

void MyStack::swap(MyStack &sec_stack)
{
    std::swap(sec_stack.s_top, s_top);
    std::swap(sec_stack.s_size, s_size);
}

Data MyStack::top() const
{
    return !empty() ? s_top->l_data : -1;
}

size_t MyStack::size() const
{
    return s_size;
}


bool MyStack::empty() const
{
    return s_size == 0 ? true : false;
}

void MyStack::copy_stack(UList *el)
{
    if (el->l_next != NULL)
        copy_stack(el->l_next);

    push(el->l_data);
}

void MyStack::clear_stack()
{
    while (!empty())
        pop();
}