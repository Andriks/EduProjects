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
    mrg_buf_ = new MrgItem [max_size_];
    head_ = mrg_buf_;

    for (int i = 0; i < max_size_-1; i++) {
        MrgItem* cur_item = mrg_buf_+i;
        cur_item->next_ = cur_item+1;
    }
}

MemMrg::~MemMrg()
{
    delete [] mrg_buf_;
}

void *MemMrg::my_alloc(Data alloc_item)
{
    //no free memory in buffer
    if (head_ == NULL)
        throw std::bad_alloc();


    MrgItem* next_head = head_->next_;
    head_->item_val_ = alloc_item;
    head_->next_ = NULL;

    void* result = reinterpret_cast<void *> (head_);

    head_ = next_head;

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
    if (&(mrg_buf_->item_val_) > item2check)
        return false;

    if (&((mrg_buf_+max_size_)->item_val_) < item2check)
        return false;

    return true;
}
