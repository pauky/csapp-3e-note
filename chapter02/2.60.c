#include <stdio.h>
#include <assert.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned m = 0xFF;
    m = m << (i << 3);
    unsigned y = b << (i << 3);
    return (x & ~m) | y;
}

int main()
{
    assert(replace_byte(0x12345678, 2, 0xAB) == 0x12AB5678);
    assert(replace_byte(0x12345678, 0, 0xAB) == 0x123456AB);
    return 1;
}