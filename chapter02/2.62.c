#include <stdio.h>
#include <assert.h>

/**
 * -1的位级是32位的1；
 * 假如是算术右移1位，还是全为1，按位取反为0，再非则为1；
 * 或者算术右移1位后与-1异或（相同为0，不同为1），则全为0，再非则为1； 
 */
int int_shifts_are_arithmetic()
{
    // return !~(-1 >> 1);
    // or
    return !(-1 ^ (-1 >> 1));
}

int main()
{
    assert(int_shifts_are_arithmetic());
    return 1;
}