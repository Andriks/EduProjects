#include "memmrg.h"

#include <cassert>

MemMrg::MrgItem::MrgItem():next_(NULL)
{
}


MemMrg::MemMrg(const int max_size):max_size_(max_size),
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

Data *MemMrg::my_alloc(Data alloc_item)
{
    assert(!(head_->next_ == NULL));

    MrgItem* next_head = head_->next_;
    head_->item_val_ = alloc_item;
    head_->next_ = NULL;

    Data* result = &head_->item_val_;

    head_ = next_head;

    return result;
}

void MemMrg::my_free(Data *free_item)
{
    //try to free memory not from current range
    if (&(mrg_buf_->item_val_) > free_item || &((mrg_buf_+max_size_)->item_val_) < free_item)
        assert(false);
}

MemMrg::MemMrg(const MemMrg &mem):max_size_(0)
{
    assert(false);
}

MemMrg &MemMrg::operator=(const MemMrg &mem)
{
    assert(false);
}

