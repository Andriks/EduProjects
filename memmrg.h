#ifndef MEMMRG_H
#define MEMMRG_H


typedef int Data;

class MemMrg
{
    struct MrgItem
    {
        Data *item_val;
        bool item_used;

        MrgItem():item_used(false)
        {
          item_val = new Data;
        }

        ~MrgItem() {
            delete item_val;
        }
    };

public:
    MemMrg(const int max_size = 100);
    ~MemMrg();

    Data* my_alloc(Data init_value = 0);
    void my_free(Data*);

private:
    //copy forbiddance
    MemMrg(const MemMrg&);
    MemMrg &operator=(const MemMrg&);

private:
    const int max_buf_size;
    int cur_buf_size;
    MrgItem *mrg_buf;

};


#endif // MEMMRG_H
