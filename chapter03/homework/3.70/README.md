
A.

|field|offset|
|--|--|
|e1.p|0|
|e1.y|8|
|e2.x|0|
|e2.next|8|

B.
16 bytes

C.
```
union ele {
  struct {
    long *p;
    long y;
  } e1;
  struct {
    long x;
    union ele *next;
  } e2;
};

void proc(union ele *up) {
  /* up->  = *(    ) -     ; */
  up->e2.x = *( *(up->e2.next).e1.p ) - *(up->e2.next).e1.y;
}
```