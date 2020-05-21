/**
 * 二进制乘法，乘以常数的规则
 * A. 17 = 0x10001 = (x<<4) + x
 * B. -7 = 1 - 8 = 0x1 - 0x1000 = x - (x<<3)
 * C. 60 = 0x1000000 - 0x100 = (x<<6) - (x<<2)
 * D. -112 = 0x10000 - 0x10000000 = (x<<4) - (x<<7)
 */
#include <assert.h>
#include <stdlib.h>

int A(x)
{
    return (x << 4) + x;
}

int B(x)
{
    return x - (x << 3);
}

int C(x)
{
    return (x << 6) - (x << 2);
}

int D(x)
{
    return (x << 4) - (x << 7);
}

int main()
{
    int r = rand();
    assert(A(r) == r * 17);
    assert(B(r) == r * -7);
    assert(C(r) == r * 60);
    assert(D(r) == r * -112);
    return 1;
}