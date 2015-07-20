#include "memmrg.h"

#include <stdexcept>


MemMrg::MrgItem::MrgItem():
    next_(NULL)
{
}


MemMrg::MemMrg(const int max_size):
    max_size_(max_size),
    mrg_buf_(NULL),
    head_(NULL)
{
    mrg_buf_ = new char[32*max_size];;
    head_ = reinterpret_cast<void*> (mrg_buf_);


    for (int i = 0; i < 32*max_size_-32; i+=32) {
        char **curr = reinterpret_cast<char**> (mrg_buf_+i);
        *curr = mrg_buf_+i+32;
    }

    char **last = reinterpret_cast<char**> (mrg_buf_+32*max_size_-32);
    *last = NULL;
}

MemMrg::~MemMrg()
{
    delete [] mrg_buf_;
}

void *MemMrg::my_alloc()
{
    //no free memory in buffer
    if (head_ == NULL)
        throw std::bad_alloc();

    void *result = head_;

    void **tmp = reinterpret_cast<void**> (head_);
    head_ = *tmp;

    return result;
}

void MemMrg::my_free(void *free_item)
{
    //try to free memory not from current range
    if (!isInRange(free_item))
        throw std::out_of_range("item not in range");

    void **ptr_to_item = reinterpret_cast<void**> (free_item);
    *ptr_to_item = head_;

    head_ = free_item;
}

bool MemMrg::isInRange(void *item2check)
{
    if (reinterpret_cast<void*> (mrg_buf_) > item2check)
        return false;

    if (reinterpret_cast<void*> (mrg_buf_+max_size_*32) < item2check)
        return false;

    return true;
}
