#include <assert.h>

int A(int k)
{
    return -1 << k;
}

int B(int k, int j)
{
    return ~A(k) << j;
}

int main()
{
    assert(A(3) == 0xFFFFFFF8);
    assert(B(16, 12) == 0x0FFFF000);
    return 1;
}