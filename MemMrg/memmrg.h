#ifndef MEMMRG_H
#define MEMMRG_H


typedef char Data;


class MemMrg
{
    struct MrgItem
    {
        MrgItem();

        MrgItem *next_;
        char item_val_[28];

    };

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
