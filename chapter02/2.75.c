/**
*  假如 x'、y' 分别表示 2 的补码表示的有符号数 x、y 对应的无符号数，xw-1、yw-1 分别表示有符号数 x、y 的最高位符号位，则在数据类型 unsigned 是 w 位的机器上，有如下结论：
* x' = x + xw-1 * 2w
* y' = y + yw-1 * 2w
* x'y' = xy + x * yw-1 * 2w + y * xw-1 * 2w + xw-1 * yw-1 * 22w
* 
* 我们知道，在 w 位机器上，无论是有符号数，还是无符号数，乘法的本质是将结果 2w 位截断为低 w 位，然后再用相应的有符号数或无符号数表示。所以，乘法结果的高 w 位表示需要在乘法结果的基础上右移 w 位，即除以 2w，假设 x'y'_h、xy_h 分别为其乘积的高位表示，则有如下结论：
* x'y'_h = xy_h + x * yw-1 + y * xw-1 + xw-1 * yw-1 * 2w
* 由于 x'y'_h 只有 w 位，所以 xw-1 * yw-1 * 2w 最后会被截断掉，对结果没有影响，则有如下结论：
* x'y'_h = xy_h + x * yw-1 + y * xw-1
* 
* 由于本题要求遵循位级编码规则，即不能使用乘号，所以可以进行如下变换，巧妙的使用 int 进行移位，并进行与运算：
* x * yw-1 = x * (y>>(w-1)) = ((int)y >> (w-1)) & x
* y * xw-1 = y * (x>>(w-1)) = ((int)x >> (w-1)) & y
* 
* 所以最后结果为：
* x'y'_h = xy_h + ((int)y >> (w-1)) & x + ((int)x >> (w-1)) & y
* 
* 作者：gfson
* 链接：https://www.jianshu.com/p/51f407e84c1c
* 来源：简书
* 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

#include <assert.h>
#include <stdio.h>

int signed_high_prod(int x, int y)
{
    int64_t mul = (int64_t)x * y;
    return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int w = sizeof(int) << 3;
    return signed_high_prod(x, y) + ((int)x >> (w - 1)) & y + ((int)y >> (w - 1)) & x;
}

int main()
{
    printf("%.2x\n", unsigned_high_prod(0x7FFFFFFF, 100));
}