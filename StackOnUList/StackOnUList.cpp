// StackOnUList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void show_top_info(MyStack &s)
{
    std::cout << s.top() << "  ||  " << s.size() << std::endl;
}

void foo(MyStack s)
{
    std::cout << "foo" << std::endl;
    while (!s.empty()) {
        std::cout << s.top() << "  ||  " << s.size() << std::endl;
        s.pop();
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    MyStack s1;
    s1.push(10);
    s1.push(11);
    s1.push(12);
    
    foo(s1);

    MyStack s2;
    s2.push(20);
    s2.push(21);
    s2.push(22);

    MyStack s3(s2);
    MyStack s4;
    s4 = s2;
    s4 = s4;

    std::cout << "swap test" << std::endl;
    show_top_info(s1);   s1.pop();
    show_top_info(s2);   s2.pop();

    s1.swap(s2);
    show_top_info(s1);   s1.pop();
    show_top_info(s2);   s2.pop();


    std::cout << "copy constr test" << std::endl;
    show_top_info(s3);   s3.pop();
    show_top_info(s3);   s3.pop();
    show_top_info(s3);   s3.pop();

    std::cout << "oper= test" << std::endl;
    show_top_info(s4);   s4.pop();
    show_top_info(s4);   s4.pop();
    show_top_info(s4);   s4.pop();


    MyStack s5;
    s5.push(50);    s5.push(51);    s5.push(52);
    MyStack s6;
    s6.push(60);    s6.push(61);
    s5 = s6;

    std::cout << "test for not empty stack" << std::endl;
    show_top_info(s5);   s5.pop();
    show_top_info(s5);   s5.pop();
    show_top_info(s5);   s5.pop();

    //MyStack s;
    //int size = 20;

    //for (int i=0; i<size; i++)
    //    s.push(i);

    //for (int i=0; i<size+2; i++) {
    //    show_top_info(s);   s.pop();
    //}

    //s.push(20);
    //s.push(21);
    //show_top_info(s);   s.pop();
    //s.push(23);
    //s.push(24);
    //show_top_info(s);   s.pop();
    //show_top_info(s);   s.pop();

    //s.push(25);

    system("pause");

	return 0;
}

