
#include <../memmrg.h>
#define BOOST_TEST_MODULE TEST_MODULE_1
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>


//try to release some object when buffer is empty
BOOST_AUTO_TEST_CASE( test_1 )
{
    MemMrg mrg;
    Data *val;
    BOOST_CHECK_THROW( mrg.my_free(val), std::out_of_range );    // not very logic exception in this case
}

//try to free object not from our mrg
BOOST_AUTO_TEST_CASE( test_2 )
{
    MemMrg mrg;
    void *val1 = mrg.my_alloc();
    void *val2 = mrg.my_alloc();

    MemMrg other_mrg;
    void *other_val = other_mrg.my_alloc();

    BOOST_CHECK_THROW( mrg.my_free(other_val), std::out_of_range );
}

//try to allocate in mrg more elements that it can store
BOOST_AUTO_TEST_CASE( test_3 )
{
    MemMrg mrg(2);
    void *val1 = mrg.my_alloc();
    void *val2 = mrg.my_alloc();

    BOOST_CHECK_THROW( mrg.my_alloc(), std::bad_alloc );
}

//checking normal behavior
BOOST_AUTO_TEST_CASE( test_4 )
{
    MemMrg mrg1(5);

    Data *val1 = reinterpret_cast<Data *> (mrg1.my_alloc());
    void *val2 = mrg1.my_alloc();
    void *val3 = mrg1.my_alloc();
    void *val4 = mrg1.my_alloc();


    BOOST_CHECK_NO_THROW( mrg1.my_free(val3) );
    BOOST_CHECK_NO_THROW( mrg1.my_free(val4) );
    BOOST_CHECK_NO_THROW( mrg1.my_free(reinterpret_cast<void *> (val1)) );
}

