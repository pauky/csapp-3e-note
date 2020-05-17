/**
 * rotaing left shift，旋转左移
 * x左移n位，按位或 x右移w-n位
 * 但考虑到n=0时，w-n为32，右移32位是非法的，所以先右移w-n-1，再右移1位
 */

#include <assert.h>

unsigned rotate_left(unsigned x, int n)
{
    int w = sizeof(int) << 3;
    return x << n | x >> (w - n - 1) >> 1;
}

int main()
{
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);
    return 1;
}