/**
 * 题目要求以x为1的位为最高位的掩码
 * 提示先将x转换为[0...01...1]
 * 假设x为0x80000000，转为位级为1000...0，所求掩码为1000...0
 * 思路是将1后面的位都置为1，再异或上其右移一位的值，保留最左边的1
 * 我们可以将x或上x>>1，则结果为x1(11000...0)，再将x1或上x1>>2，则结果为x2(1111000...0)
 * 依此类推，直到x4或上x4>>16时，结果为x5(111...1)
 * 此时再x5^(x5>>1)，此值即是所求
 */

#include <assert.h>

int leftmost_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x ^ (x >> 1);
}

int main()
{
    assert(leftmost_one(0xFF00) == 0x8000);
    assert(leftmost_one(0x8880) == 0x8000);
    assert(leftmost_one(0x0041) == 0x0040);
    return 1;
}