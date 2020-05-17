/**
 * 题目要求给定一个数字n，返回第n位右边及其右边的位都为1的数
 */

#include <assert.h>

/**
 * 解法1
 * 2左移n-1位，强制转为无符号数，再-1，即得到所求的数
 * n-1位是为了兼容n=32的情况，因为int为32位，不能移动的位数不能是32位或以上
 */
int lower_one_mask(int n)
{
    return (unsigned)(2 << (n - 1)) - 1;
}

/**
 * 解法2
 * 全位级为1的数，左移32-n位，即可得所求
 */
int lower_one_mask_2(int n)
{
    int w = sizeof(int) << 3;
    return (unsigned)-1 >> (w - n);
}

int main()
{
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    assert(lower_one_mask(32) == 0xFFFFFFFF);

    assert(lower_one_mask_2(6) == 0x3F);
    assert(lower_one_mask_2(17) == 0x1FFFF);
    assert(lower_one_mask_2(32) == 0xFFFFFFFF);
    return 1;
}