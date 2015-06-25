#include <iostream>
#include "memmrg.h"


int main()
{
    MemMrg mrg1(5);
    Data *val0; //bad pointer
    //mrg1.my_free(val0);   //forbidden (mrg1 is empty)

    Data *val1 = mrg1.my_alloc(11);
    Data *val2 = mrg1.my_alloc(12);
    Data *val3 = mrg1.my_alloc();
    Data *val4 = mrg1.my_alloc(21);

    mrg1.my_free(val3);
    mrg1.my_free(val4);
    mrg1.my_free(val1);

    //try to free obj not from our mrg1
//    Data *err = new Data;
//    *err = 11;
//    mrg1.my_free(err);

    Data *val5 = mrg1.my_alloc(25);
    Data *val6 = mrg1.my_alloc(26);
    Data *val7 = mrg1.my_alloc(27);
    Data *val8 = mrg1.my_alloc(28);

    //try to alloc from empty buffer
//    Data *val9 = mrg1.my_alloc(29);

    mrg1.my_free(val5);
    mrg1.my_free(val6);


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

