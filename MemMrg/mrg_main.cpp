#include <iostream>
#include "memmrg.h"


int main()
{

    MemMrg mrg1(5);

    int *val1 = reinterpret_cast<int *> (mrg1.my_alloc());
    void *val2 = mrg1.my_alloc();

    mrg1.my_free(val2);
    mrg1.my_free(reinterpret_cast<void *> (val1));

    return 0;
}


