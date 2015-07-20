#ifndef MEMMRG_H
#define MEMMRG_H

//couldn't figure out how to use static_assert in c++11 style, so use such trick instead
#define STATIC_ASSERT(COND,MSG) typedef char static_assertion_##MSG[(COND)?1:-1]
STATIC_ASSERT(sizeof(char) == 1, required_sizeof_char_eq_1_byte);


class MemMrg
{
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
    bool isInRange(void*);

private:
    char *mrg_buf_;
    void *head_;

    const int item_cnt_;
    static const int item_size_;
};


#endif // MEMMRG_H
