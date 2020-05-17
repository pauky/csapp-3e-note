/**
 * 题目要求：
 * 如果x的某个奇数位为1，则返回1，否则返回0
 * 
 * 如果能只保留x的所有奇数位，并判断是否全为0，则说明x的奇数位都为0，返回1，否则返回0
 * 对数取两次非能判断该数的位是否全为0
 * A的位级表示是1010，与其按位与则是只保留奇数位
 */

#include <assert.h>

int any_odd_one(unsigned x)
{
    return !!(0xAAAAAAAA & x);
}

int main()
{
    assert(any_odd_one(0x2));
    assert(!any_odd_one(0x4));
    assert(any_odd_one(0x8));
    return 1;
}