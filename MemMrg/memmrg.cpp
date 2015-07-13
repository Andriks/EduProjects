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
    mrg_buf_ = new MrgItem[max_size_];
    head_ = mrg_buf_;

    for (int i = 0; i < max_size_-1; i++) {
        mrg_buf_[i].next_ = &mrg_buf_[i+1];
    }

    mrg_buf_[max_size_-1].next_ = NULL;
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

    void* result = reinterpret_cast<void *> (head_);

    head_ = head_->next_;

    return result;
}

void MemMrg::my_free(void *free_item)
{
    //try to free memory not from current range
    if (!isInRange(free_item))
        throw std::out_of_range("item not in range");


    MrgItem *add2listItem = reinterpret_cast<MrgItem *> (free_item);
    add2listItem->next_ = head_;
    head_ = add2listItem;
}

bool MemMrg::isInRange(void *item2check)
{
    if (reinterpret_cast<void *> (mrg_buf_) > item2check)
        return false;

    if (reinterpret_cast<void *> (mrg_buf_+max_size_) < item2check)
        return false;

    return true;
}
