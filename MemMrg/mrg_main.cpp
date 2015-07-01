#include <iostream>
#include "memmrg.h"


int main()
{
    std::cout << sizeof(char[32]) << std::endl;

    MemMrg mrg1(5);
//    Data *val0; //bad pointer
//    mrg1.my_free(val0);   //forbidden (mrg1 is empty)

    Data *val1 = reinterpret_cast<Data *> (mrg1.my_alloc(11));

    void *val2 = mrg1.my_alloc(12);
    void *val3 = mrg1.my_alloc();
    void *val4 = mrg1.my_alloc(21);


    mrg1.my_free(val3);
    mrg1.my_free(val4);
    mrg1.my_free(reinterpret_cast<void *> (val1));

    void *val5 = mrg1.my_alloc(25);
    void *val6 = mrg1.my_alloc(26);
    void *val7 = mrg1.my_alloc(27);
    void *val8 = mrg1.my_alloc(28);

    //try to alloc from empty buffer
//    void *val9 = mrg1.my_alloc(29);

    mrg1.my_free(val5);
    mrg1.my_free(val6);

    //try to free obj not from our mrg1
//    Data *err = new Data;
//    *err = 11;
//    mrg1.my_free(err);

//    mrg1.my_free(val0);   //forbidden (val0 not in mrg1)

//    void *arr[120];   //forbidden (120 > 100)
//    for (int i = 0; i < 120; i++) {
//        arr[i] = mrg1.my_alloc(i);
//    }


    // test on copy constractors
//    MemMrg mrg2(mrg1);

//    MemMrg mrg2;
//    mrg2 = mrg1;

    return 0;
}

