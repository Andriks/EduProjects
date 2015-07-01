#ifndef MEMMRG_H
#define MEMMRG_H


typedef int Data;


class MemMrg
{
    struct MrgItem
    {
        MrgItem();

        Data item_val_;
        MrgItem *next_;
    };

public:
    MemMrg(const int max_size = 100);
    ~MemMrg();

    void* my_alloc(Data init_value = 0);
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
