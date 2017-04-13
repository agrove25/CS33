/* 
 * CS:APP Data Lab 
 * 
 * Andrew Grove --- 304785991
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  /* we use the special property of negatives, where the negative of zero is zero */
  /*
   * if it is the case that x is nonzero, either x or the negative will have a 1 in
   * the sign bit, allowing the inner equation to become 1. It is then trivial to
   * reverse this sign.
   */
  
  int neg = ~x + 1;

  return ~((x >> 31)| (neg >> 31)) & 1;
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /* this works through the creation of a mask that will do multiple checks for the last order
   * bit in a set at one time. Through this method, the number of ones in every 4 bits is inserted into 
   * the corresponding places. This is totaled up, resulting in a number for every 4 bits that 
   * correspond to how many ones there were orginally. All that is left to do is take parse
   * through said numbers.
   */

  int mask = 0x11 | (0x11 << 8);   //0001000100010001
  int total;
  int count;
  mask = mask | (mask << 16);      //0001 x8 = 32;

  total = x & mask;
  total += (x >> 1) & mask;
  total += (x >> 2) & mask;
  total += (x >> 3) & mask;
  
  
  
  count = total & 0x07;
  count += (total >> 4) & 0x07;
  count += (total >> 8) & 0x07;
  count += (total >> 12) & 0x07;
  count += (total >> 16) & 0x07;
  count += (total >> 20) & 0x07;
  count += (total >> 24) & 0x07;
  count += (total >> 28) & 0x07;
  
  return count;

  // TODO: we can create multiple masks to streamline the procecss.. this does
  // reach a point where it is inefficient though, as due to the constraints
  // it takes ~3 operations to create said mask.
}

/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  /* De Morgan's Law */

  return ~(~x & ~y);
}

/*
 * bitRepeat - repeat x's low-order n bits until word is full.
 *   Can assume that 1 <= n <= 32.
 *   Examples: bitRepeat(1, 1) = -1
 *             bitRepeat(7, 4) = 0x77777777
 *             bitRepeat(0x13f, 8) = 0x3f3f3f3f
 *             bitRepeat(0xfffe02, 9) = 0x10080402
 *             bitRepeat(-559038737, 31) = -559038737
 *             bitRepeat(-559038737, 32) = -559038737
 *   Legal ops: int and unsigned ! ~ & ^ | + - * / % << >>
 *             (This is more general than the usual integer coding rules.)
 *   Max ops: 40
 *   Rating: 4
 */
int bitRepeat(int x, int n) {
  /*  
   *  with the base (which we attain through left shifting then right shifting
   *  in store, we are able to repeatedly append this base to a number. In order
   *  to ensure that n * up to 16 does not excceed the word count, which would have unspecified
   *  consequences, we and it with 0x1F.
   */

  int repeat;
  int offset = 32 - n;
  unsigned base = x << offset;      // this is needs to be unsigned so that right shift
  base = base >> offset;            // is not arithmetic

  repeat = base | base << n;
  repeat = repeat | (repeat << ((n << 1) * !!(16/n)));
  repeat = repeat | (repeat << ((n << 2) * !!(8/n)));
  repeat = repeat | (repeat << ((n << 3) * !!(4/n)));
  repeat = repeat | (repeat << ((n << 4) * !!(2/n)));
  
  return repeat;
}

/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  // neg will be 0 if x is positive, and -1 if x is negative
  // if x > 0, x & ~neg = x, ~x & neg = 0
  // if x < 0, x & ~neg = 0, ~x & neg = -(x + 1) <-- this is important
  
  int neg = x >> 31;
 
  return !((x & ~neg | ~x & neg) >> (n + ~0));      // note: ~0 is equivalent to negative 1, which we need because we aren't
                                                    // allowed to use subtraction
}

/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /* left shifts a number by n*8, and then masks it to take only the last 16 bits */
  return (x >> (n << 3)) & 0xFF;
}

/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /* the return expression resolves if it is less than or equal to zero, so all that
   * needs to happen is that we make x the difference between x and y.
   */

  x = x + ~y + 1;     // x = x - y;
  return !(x & ~(x >> 31));
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  /* if the x is negative, the ~(x >> 31) will be 0, which will evaluate the expression to 0.
   * when double banged it will remain to be zero. if the x is positive, that expression will be -1
   * which when it is AND-ed, will result in x, which will double bang to 1.
   */

  return !!(x & ~(x >> 31));
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  /* we create a mask that is 0111... so that an arithmetic right shift would lead to more zeroes that
   * we can later & with the arithmetically right shifted x to result in a logical shift. We do need to
   * take heed to the special case of if n is 0 however, which we take into account by shifting it left
   * !n, which would result in 1 if n was 0, completing the mask with 1111 and oring it with 1 to fill 
   * the last bit with 1 (it is always 1 due to the limitations on n).
   */

  int mask = (0x7F << 24) | (0xFF << 16) | (0xFF << 8) | 0xFF;
  mask = (mask << !n) >> (n) | 1;

  return (x >> n) & mask; 
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /* shifting 1000 0000 all the way so that the entire bit patter starts with 1 and has remaining zeroes */

  return 0x80 << 24; 
}
