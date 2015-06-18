#include <iostream>
#include "memmrg.h"


int main()
{
    MemMrg mrg1;
    Data *val0; //bad pointer
    //mrg1.my_free(val0);   //forbidden (mrg1 is empty)

    Data *val1 = mrg1.my_alloc(11);
    *val1 = 21;
    Data *val2 = mrg1.my_alloc(12);
    Data *val3 = mrg1.my_alloc();
    Data *val4 = mrg1.my_alloc(21);

    mrg1.my_free(val3);
    mrg1.my_free(val4);
    mrg1.my_free(val1);

    Data *val5 = mrg1.my_alloc(21);
    Data *val6 = mrg1.my_alloc(22);


    //mrg1.my_free(val0);   //forbidden (val0 not in mrg1)

//    Data *arr[120];   //forbidden (120 > 100)
//    for (int i = 0; i < 120; i++) {
//        arr[i] = mrg1.my_alloc(i);
//    }


//    MemMrg mrg2(mrg1);

//    MemMrg mrg2;
//    mrg2 = mrg1;

    return 0;
}

