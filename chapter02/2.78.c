/**
 * 题目要求计算x除以2^k的值
 * 根据除法规则：(x<0 ? x + (1<<k) - 1 : x) >> k
 */

#include <limits.h>
#include <assert.h>

int divide_power2(int x, int k)
{
    int is_neg = x & INT_MIN;
    (is_neg && (x = x + (1 << k) - 1));
    return x >> k;
}

int main()
{
    assert(divide_power2(100, 2) == 25);
    assert(divide_power2(1024, 10) == 1);
    return 1;
}