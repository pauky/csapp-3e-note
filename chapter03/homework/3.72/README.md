  +------------------+
  |        i         |
  +------------------+
  |      no use      |
  +------------------+
  |        e1        |
  +------------------+
  |         p        |
  +------------------+
  |        e2        |
  +------------------+
  |         s2       |
  +------------------+


A.

when n is odd => s_2 = s_1 - (n * 8 + 24)

when n is even => s_2 = s_1 - (n * 8 + 16)


B.

p = (s2 + 15) & 0xfffffff0


C.

|which|e1|n|s1|
|-|-|-|-|
|least|1|even|n%16==1|
|greatest|24|odd|n%16==0|

least:

e1 can't be 0, if e1 == 0, p should equal to s2

when n is even, e1 + e2 == 16, if e2 is 15, e1 will be least that can reach,
so s1 == n that n%16==1

greatest:

when n is odd, e1 + e2 == 24. if p == s2, e2 == 0, so e1 will be the greatest
value 24 that can reach. s1 == n that n%16 == 0

D.

p is aligned by 16

s2 is the least multiple of 16 that preserve 8*n size space

