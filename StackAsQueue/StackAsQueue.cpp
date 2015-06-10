// StackAsQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

    int size = 3;

    MyQueue<short> q;
    for (int i=0; i<size; i++)
        q.push(i);

    q.push(799);

    for (int i=0; i<size-1; i++) {
        std::cout << q.pop() << std::endl;
    }

    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;

    system("pause");
    return 0;
}

