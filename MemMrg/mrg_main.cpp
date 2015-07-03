#include <iostream>
#include "memmrg.h"


int main()
{

    MemMrg mrg1(5);

    Data *val1 = reinterpret_cast<Data *> (mrg1.my_alloc(11));
    void *val2 = mrg1.my_alloc(666);

    mrg1.my_free(val2);
    mrg1.my_free(reinterpret_cast<void *> (val1));

    return 0;
}

