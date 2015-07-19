#ifndef MEMMRG_H
#define MEMMRG_H

//couldn't figure out how to use static_assert in c++11 style, so use such trick instead
#define STATIC_ASSERT(COND,MSG) typedef char static_assertion_##MSG[(COND)?1:-1]
STATIC_ASSERT(sizeof(char) == 1, sizeof_char_should_be_one_byte);


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
    MrgItem *mrg_buf_;
    MrgItem *head_;

};


#endif // MEMMRG_H
