/**
 * 题目要求指定word的某个字节，将它进行符号扩展，转为32位的int。
 * 这里需要特别注意该指定字节转为int后的符号位问题，如果该字节最高位为1，则符号扩展位需要补1；
 * 则需要先将word转为int, 然后将指定字节右移到word的最高字节处，再右移到最低字节，才能满足有符号数进行符号扩展的要求；
 */
#include <assert.h>
#include <stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    int ret = word << ((3 - bytenum) << 3);
    // printf("%.2x\n", ret);
    return ret >> 24;
}

int main()
{
    printf("%d\n", xbyte(0x00008000, 1));
    printf("%.2x\n", xbyte(0x00008000, 1));
    assert(xbyte(0x00008000, 1) == 0xFFFFFF80);
    return 1;
}