// StackOnUList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void show_top_info(MyStack &s)
{
    std::cout << s.top() << "  ||  " << s.size() << "  ||  " << s.empty() << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    MyStack s;
    int size = 20;

    for (int i=0; i<size; i++)
        s.push(i);

    for (int i=0; i<size+2; i++) {
        show_top_info(s);   s.pop();
    }

    s.push(20);
    s.push(21);
    show_top_info(s);   s.pop();
    s.push(23);
    s.push(24);
    show_top_info(s);   s.pop();
    show_top_info(s);   s.pop();

    s.push(25);

    system("pause");

	return 0;
}

