#include <stdio.h>
#include <assert.h>

/**
 * xsra是算术右移的结果，如果能将第k位左边的位都置为0，则是逻辑右移的结果；
 * 计算第k位左边的nums位
 * 补码的-1的所有位都为1，左移nums位
 * 再按位取反，则得到第k位左边的位都为0，右边都为1，再结果与xsra按位与，则可以将第k位左边置0，同时保持右边的位不变
 */
unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;

    int nums = (sizeof(int) << 3) - k;
    unsigned m = ~((int)-1 << nums);
    return xsra & m;
}

/**
 * 关键在于判断x的最高位是否为1，为1则将k左边的都置1，否则置0；
 * 构建m，使第k位左边都为1，右边都为0；
 * 将1的最低位左移到最高位，则变成TMin；
 * TMin与x按位与，如果为0，则表示最高位是0，为TMin，则表示最高位是1；
 * 如果x最高位为1，则m需要保持不变，可以与上-1（所有位都是1）；
 * 如果x最高位为0，则m的所有位都置为0，可以与上0（所有位都是0）；
 * 则 m &= !(x & TMin) - 1；
 * 此时的m已经是根据x最高位得到的掩码；
 * xsrl | m 即是所求
 */
int sra(int x, int k)
{
    int xsrl = (unsigned)x >> k;

    int w = sizeof(int) << 3;
    unsigned m = (int)-1 << (w - k);
    unsigned TMin = 1 << (w - 1);
    m &= !(x & TMin) - 1;
    return xsrl | m;
}

int equal(unsigned x, unsigned y)
{
    if (x == y)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int k = 3;
    unsigned x = (int)-1 << k;
    assert(srl(x, k) == (x >> k));
    assert(sra(x, k) == (int)x >> k);
    return 1;
}