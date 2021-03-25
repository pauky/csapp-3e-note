#include <stdio.h>
typedef enum
{
    MODE_A,
    MODE_B,
    MODE_C,
    MODE_D,
    MODE_E
} mode_t;

long switch3(long *p1, long *p2, mode_t action)
{
    long result = 0;
    switch (action)
    {
    case MODE_A:
        result = *p2;
        *p2 = *p1;
        break;
    case MODE_B:
        *p1 = *p1 + *p2;
        result = *p1;
        break;
    case MODE_C:
        *p1 = 59;
        result = *p2;
        break;
    case MODE_D:
        *p1 = *p2;
        result = 27;
        break;
    case MODE_E:
        result = 27;
        break;
    default:
        result = 12;
        break;
    }
    return result;
}

int main()
{
    long *p1, *p2;
    *p1 = 1;
    *p2 = 2;
    long result = switch3(p1, p2, MODE_A);
    printf("result: %ld\n", result);
}