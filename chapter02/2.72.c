/**
 * A. 有符号数与无符号数运算时，会将有符号数强制转为无符号数，无符号数总是大于或等于0
 * B. 代码如下 
 */
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void copy_int(int val, void *buf, int maxbytes)
{
    if (maxbytes - (int)sizeof(val) >= 0)
    {
        memcpy(buf, (void *)&val, sizeof(val));
    }
}

int main()
{
    int maxbytes = sizeof(int) * 10;
    void *buf = malloc(maxbytes);
    int val;

    val = 0x12345678;
    copy_int(val, buf, maxbytes);
    assert(*(int *)buf == val);

    val = 0x12345679;
    copy_int(val, buf, 0);
    assert(*(int *)buf != val);

    free(buf);
    return 1;
}