#include <iostream>

#include "myqueue.h"



int main()
{

    int size = 3;

    MyQueue<short> q;
    for (int i=0; i<size; i++)
        q.push(i);

    q.push(665);

    for (int i=0; i<size; i++) {
        std::cout << q.pop() << std::endl;
    }

    std::cout << q.pop() << std::endl;
    q.push(666);
    q.push(667);
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    //std::cout << q.pop() << std::endl;

    q.push(668);
    q.push(669);
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
   //std::cout << q.pop() << std::endl;


    system("pause");
    return 0;
}

