#ifndef MEMMRG_H
#define MEMMRG_H

//couldn't figure out how to use static_assert in c++11 style, so use such trick instead
#define STATIC_ASSERT(COND,MSG) typedef char static_assertion_##MSG[(COND)?1:-1]



class MemMrg
{
#pragma pack(push, 1)
    struct MrgItem
    {
        MrgItem();

        MrgItem *next_;
        char item_val_[28];

    };
#pragma pack(pop)

STATIC_ASSERT(sizeof(char) == 1, required_sizeof_char_eq_1_byte);
STATIC_ASSERT(sizeof(MrgItem) == 32, required_sizeof_MrgItem_eq_32_bytes);

public:
    MemMrg(const int max_size = 100);
    ~MemMrg();

    void* my_alloc();
    void my_free(void*);

private:
    //copy forbiddance
    MemMrg(const MemMrg&);
    MemMrg &operator=(const MemMrg&);

    //checking if free obj in range of memory of our buffer
    bool isInRange(void *);

private:
    const int max_size_;
    char *mrg_buf_;
    char *head_;

};


#endif // MEMMRG_H
