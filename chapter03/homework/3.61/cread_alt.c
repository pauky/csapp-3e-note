long cread_alt(long *xp)
{
    return (!xp ? 0 : *xp);
}

// gcc -O3 -S cread_alt.c
// long cread_alt(long *xp)
// {
//     static long tmp = 0;
//   	if(xp == 0)
//     {
//         xp = &tmp;
//     }
//   	return *xp;
// }