#include <stdio.h>
#include <assert.h>

/**
* x按位取位，再取非；
* 只有当x=0xFF时，按位取反才会得到0，0取非才为1；
* 当x的某一位是非1时，A的结果都是0；
*/
int A(int x)
{
    return !~x;
}

/**
 * x=0x00，按位取反则为1
 */
int B(int x)
{
    return !x;
}

/**
 * 0xFF按位取反，保证最低有效位为0，其它都为1
 * x按位或上上述结果，如果x最低有效字节的位都是1，则结果是32位的1
 * 再按位取反则是0，再取非则是1
 */
int C(int x)
{
    return !~(x | ~0xFF);
}

/**
 * 右移int字节数-1个（字节乘8转为bit数量），取最高有效位
 * 最高有效位与0xFF按位与，再取非
 * 如果为1，说明最高有效位的bit都为0
 */
int D(int x)
{
    char high_byte = (x >> ((sizeof(int) - 1) << 3));
    return !(high_byte & 0xFF);
}

int main()
{
    assert(A((int)0xFFFFFFFF));

    assert(B((int)0x00));

    unsigned x = 0xFF;
    assert(C((int)x));

    x = 0x00;
    assert(D((int)x));
    return 1;
}