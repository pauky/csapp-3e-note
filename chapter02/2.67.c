/**
 * A. 位移超32位的操作在c中没有定义
 * B. 见函数 bad_int_size_is_32
 * C. 见函数 bad_int_size_is_32_for_16_bit
 */

#include <assert.h>

int bad_int_size_is_32()
{
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

int bad_int_size_is_32_for_16_bit()
{
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

int main()
{
    assert(bad_int_size_is_32());
    assert(bad_int_size_is_32_for_16_bit());
    return 1;
}