/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
    int nand = ~(x & y);
    int a = ~(x & nand);
    int b = ~(y & nand);
    return ~(a & b);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
    return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
    return !~(INT_MIN | x);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
    return !(x & 0x55555555);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
    return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
// x分别与两个临界值的差的符号位，然后判断两个符号位是0还是1
int isAsciiDigit(int x)
{
    return (!((x + ~(0x30) + 1) >> 31)) & !!((x + ~(0x39) + 1) >> 31);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
    /*
     *if x!=0, mask=0x00000000, => y&~mask==y and z&mask==0
     *if x==0, mask=0xffffffff, => y&~mask = y&0 =0; z&mask=z
     */
    int mask = (~(!x)) + 1;
    return (y & ~mask) | (z & mask);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
    /**
     * 1. 判断x,y是否相等：equal_or_not
     * 2. 判断x,y符号位是否不同，若不同且x符号位是1，则x<y => x_l_y 
     * 3. 判断x-y的值的符号位是否为1：temp_nega_or_not
     */

    int mask = 0x1;
    /* Determine if equal */
    int equal_or_not = !(x ^ y);
    /* Determine if x and y have different symbol */
    int x_symbol = (x >> 31) & mask;
    int y_symbol = (y >> 31) & mask;
    int diff_symbol = x_symbol ^ y_symbol;
    /* If so, when x is negative, x is less than y */
    int x_l_y = diff_symbol & x_symbol;
    /* Operation x - y */
    int nega_y = ~y + 1;
    int temp = x + nega_y;
    /* Determine the symbol of difference */
    int temp_nega_or_not = (temp >> 31) & mask;
    /* Attention that with different symbol, the result only relies on x_l_y,
   * we know that they're not equal,
   * and the value of temp_nega_or_not should be screened
   */
    int result = equal_or_not | x_l_y | ((!diff_symbol) & temp_nega_or_not);
    return result;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x)
{
    /**
     * x != 0和INT_MIN时，x与其相反数的符号位相反； 
     * x = INT_MIN时，x=INT_MIN，符号位都是1；
     * 这两种情况的符号位或之后是1，算术右移31位是32位全为1的数，+1则为0；
     * x = 0时，符号位都为0；
     * 这种情况的符号位或之后是0，算术右移31位是32位全为0的数，+1则为1
     */
    return ((x | (~x + 1)) >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
    /**
     * 如果是一个正数，则需要找到它最高的一位（假设是n）是1的，再加上符号位，结果为n+1； 
     * 如果是一个负数，则需要知道其最高的一位是0的
     * （例如4位的1101和三位的101补码表示的是一个值：-3，最少需要3位来表示）。
    */
    int b16, b8, b4, b2, b1, b0;
    int sign = x >> 31;
    x = (sign & ~x) | (~sign & x); //如果x为正则不变，否则按位取反（这样好找最高位为1的，原来是最高位为0的，这样也将符号位去掉了）

    // 不断缩小范围
    b16 = (!!(x >> 16)) << 4; //高十六位是否有1
    x = x >> b16;             //如果有（至少需要16位），则将原数右移16位
    b8 = (!!(x >> 8)) << 3;   //剩余位高8位是否有1
    x = x >> b8;              //如果有（至少需要16+8=24位），则右移8位
    b4 = (!!(x >> 4)) << 2;   //同理
    x = x >> b4;
    b2 = (!!(x >> 2)) << 1;
    x = x >> b2;
    b1 = (!!(x >> 1));
    x = x >> b1;
    b0 = x;

    return b16 + b8 + b4 + b2 + b1 + b0 + 1; //+1表示加上符号位
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
    /**
     * 1. 无穷大和NaN返回自身；
     * 2. 非规格化，frace右移一位
     * 3. 规格化，乘以2溢出，exp=0xff,frac=0,表示无穷大
     * 4. 规格化，乘以2不溢出，exp+1
     */
    unsigned sig = uf >> 31;
    unsigned exp = uf >> 23 & 0xFF;
    unsigned frac = uf & 0x7FFFFF;

    int is_NAN_or_oo = (exp == 0xFF);
    if (is_NAN_or_oo)
    {
        return uf;
    }

    if (exp == 0)
    {
        /* Denormalized */
        frac <<= 1;
    }
    else if (exp == 0xFF - 1)
    {
        /* twice to oo */
        exp = 0xFF;
        frac = 0;
    }
    else
    {
        /* Normalized */
        exp += 1;
    }

    return sig << 31 | exp << 23 | frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    unsigned bias = 0x7F;

    int num;
    unsigned E;
    unsigned M;

    /*
   * consider positive numbers
   *
   * 0 00000000 00000000000000000000000
   *   ===>
   * 0 01111111 00000000000000000000000
   *   0 <= f < 1
   * get integer 0
   *
   * 0 01111111 00000000000000000000000
   *   ===>
   * 0 (01111111+31) 00000000000000000000000
   *   1 <= f < 2^31
   * integer round to 0
   *
   * 0 (01111111+31) 00000000000000000000000
   *   ===>
   * greater
   *   2^31 <= f < oo
   * return 0x80000000
   */
    if (exp >= 0 && exp < 0 + bias)
    {
        /* number less than 1 */
        num = 0;
    }
    else if (exp >= 31 + bias)
    {
        /* number overflow */
        /* or f < 0 and (int)f == INT_MIN */
        num = 0x80000000;
    }
    else
    {
        E = exp - bias;
        M = frac | 0x800000;
        if (E > 23)
        {
            num = M << (E - 23);
        }
        else
        {
            /* whether sig is 1 or 0, round to zero */
            num = M >> (23 - E);
        }
    }

    return sig ? -num : num;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
    int INF = 0x7f800000;
    int exp = x + 127;
    if (exp <= 0)
        return 0;

    if (exp >= 255)
        return INF;

    return exp << 23;
}
