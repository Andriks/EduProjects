#include "memmrg.h"

#include <stdexcept>

const int MemMrg::item_size_(32);


MemMrg::MemMrg(const int max_size):
    item_cnt_(max_size),
    mrg_buf_(NULL),
    head_(NULL)
{
    mrg_buf_ = new char[item_size_*item_cnt_];;
    head_ = reinterpret_cast<void*> (mrg_buf_);


    for (int i = 0; i < item_size_*(item_cnt_-1); i+=item_size_) {
        void **curr = reinterpret_cast<void**> (mrg_buf_+i);
        *curr = reinterpret_cast<void*> (mrg_buf_ + i + item_size_);
    }

    void **last = reinterpret_cast<void**> (mrg_buf_ + item_size_*(item_cnt_-1));
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
    head_ = *reinterpret_cast<void**> (head_);

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

bool MemMrg::isInRange(void *item_to_check)
{
    if (reinterpret_cast<void*> (mrg_buf_) > item_to_check)
        return false;

    if (reinterpret_cast<void*> (mrg_buf_+item_size_*item_cnt_) < item_to_check)
        return false;

    return true;
}
