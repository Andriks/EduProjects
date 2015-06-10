#include "StdAfx.h"
#include "MyStack.h"


MyStack::MyStack(void): s_size(0)
{
}


MyStack::~MyStack(void)
{
    while(!empty())
        pop();
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
    if (empty())
        return false;

    UList *next_top = s_top->l_next;
    
    delete s_top;

    s_top = next_top;
    s_size--;

    return true;
}

void MyStack::swap(MyStack &sec_stack)
{
    size_t tmp_s_size = s_size;
    UList *tmp_s_top = s_top;

    s_size = sec_stack.s_size;
    s_top = sec_stack.s_top;

    sec_stack.s_size = tmp_s_size;
    sec_stack.s_top = tmp_s_top;
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