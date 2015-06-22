#include "memmrg.h"

#include <cassert>

MemMrg::MemMrg(const int max_size):max_buf_size(max_size),
                                   cur_buf_size(0),
                                   mrg_buf(NULL)
{
    mrg_buf = new MrgItem [max_buf_size];
}

MemMrg::~MemMrg()
{
    delete [] mrg_buf;
}

Data *MemMrg::my_alloc(Data init_value)
{
    assert(cur_buf_size < max_buf_size);

    for (int i = 0; i < max_buf_size; i++) {
        MrgItem* cur_item = mrg_buf+i;
        if (!cur_item->item_used) {
            cur_item->item_used = true;
            *(cur_item->item_val) = init_value;
            cur_buf_size++;

            return cur_item->item_val;
        }
    }
}

void MemMrg::my_free(Data *free_item)
{
    assert(cur_buf_size>0);

    for (int i = 0; i < max_buf_size; i++) {
        MrgItem *cur_item = mrg_buf+i;
        if (cur_item->item_val == free_item) {
            cur_item->item_used = false;

            cur_buf_size--;
            return;
        }
    }

    // try to free obj which don't belong this inst of MemMrg
    assert(false);
}

MemMrg::MemMrg(const MemMrg &mem):max_buf_size(0)
{
    assert(false);
}

MemMrg &MemMrg::operator=(const MemMrg &mem)
{
    assert(false);
}

