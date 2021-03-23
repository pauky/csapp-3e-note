
long decode2(long x, long y, long z)
{
    y = z - y;
    x = (z - y) * x;
    long ret = x << 63 >> 63;
    return ret ^ x;
}
