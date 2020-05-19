/**
 * 如果x和y异号，x+y肯定不会溢出；
 * 如果x>0,y>0,且x+y<0，说明正溢出；
 * 如果x<0,y<0,且x+y>=0，说明负溢出； 
 * 任何数按位与INT_MIN，可以判断是否正负：x & INT_MIN 为真 说明x<0，反之x>=0
 */
#include <limits.h>
#include <assert.h>

int saturating_add(int x, int y)
{
    int sum = x + y;
    int sig_mask = INT_MIN;

    int pos_over = !(x & sig_mask) && !(y & sig_mask) && (sum & sig_mask);
    int neg_over = (x & sig_mask) && (y & sig_mask) && !(sum & sig_mask);

    (pos_over && (sum = INT_MAX)) || (neg_over && (sum = INT_MIN));
    return sum;
}

int main()
{
    assert(saturating_add(-1, INT_MIN) == INT_MIN);
    assert(saturating_add(1, INT_MAX) == INT_MAX);
    assert(saturating_add(1, 2) == 3);
    return 1;
}