/*
 * 3.64
 *
 * A. &A[i][j][k] = l_A + L(S*T*i + T*j + k)
      l_A is the begin location of array A, L=sizeof(long)=8;
 * B. R = 7, S = 5, T = 13;
 */
#define R 7
#define S 5
#define T 13

long A[R][S][T];

long store_ele(long i, long j, long k, long *dest)
{
    *dest = A[i][j][k];
    return sizeof(A);
}