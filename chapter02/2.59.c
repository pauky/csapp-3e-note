#include <stdio.h>
#include <assert.h>

int main()
{
    size_t m = 0xFF; // the same as: unsigned m = 0xFF;
    size_t x = 0x89ABCDEF;
    size_t y = 0x76543210;
    size_t res = (x & m) | (y & ~m);
    assert(res == 0x765432EF);
    return 1;
}