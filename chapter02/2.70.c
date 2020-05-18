/**
 * 题目要求 当x能代表n位二进制补码时返回1，否则返回0
 * 要想x能代表n位二进制补码，相当于对n位二进制补码进行符号扩展，如果补码最高位为1，则扩展的位都为1，否则都为0
 * 说明x需要第n-1位（位从0计数）开始全为1或0，且与第n-1的位值一致
 * 假如int是32位，可以先将x左移32-n位，只保留所需要的n位补码，这时候再算术右移32-n位
 * 如果移动后的两个数相等，则x符合要求，返回1，否则返回0
 */

#include <assert.h>

int fits_bits(int x, int n)
{
    int w = sizeof(int) << 3;
    int offset = w - n;
    return x == (x << offset >> offset);
}

int main()
{
    assert(fits_bits(0b0010, 3));
    assert(!fits_bits(0b1010, 3));
    assert(!fits_bits(0b0110, 3));
    return 1;
}