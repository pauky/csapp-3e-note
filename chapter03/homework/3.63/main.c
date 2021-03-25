/*
 * According the table val, you can find the code of cases.
 * 0x3c is 60.
 * cmp $0x5, %rsi; ja 4005c3; will decide the position of default.
 */

long switch_prob(long x, long n)
{
    long result = x;
    switch (n)
    {
    case 60:
    case 62:
        result = x * 8;
        break;
    case 63:
        result = x >> 3;
        break;
    case 64:
        x = x << 4 - x;
    case 65:
        x = x * x;
    default:
        result = x + 0x4B;
    }
    return result;
}
