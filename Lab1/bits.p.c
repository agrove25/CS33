#line 142 "bits.c"
int bang(int x) {
#line 150
  int neg=  ~x + 1;

  return ~((x >> 31)|( neg >> 31)) & 1;
}
#line 162
int bitCount(int x) {
#line 170
  int mask=  0x11 |( 0x11 << 8);
  int total;
  int count;
  mask = mask |( mask << 16);

  total = x & mask;
  total +=( x >> 1) & mask;
  total +=( x >> 2) & mask;
  total +=( x >> 3) & mask;
#line 182
  count = total & 0x07;
  count +=( total >> 4) & 0x07;
  count +=( total >> 8) & 0x07;
  count +=( total >> 12) & 0x07;
  count +=( total >> 16) & 0x07;
  count +=( total >> 20) & 0x07;
  count +=( total >> 24) & 0x07;
  count +=( total >> 28) & 0x07;

  return count;
#line 196
}
#line 205
int bitOr(int x, int y) {


  return ~(~x & ~y);
}
#line 225
int bitRepeat(int x, int n) {
#line 233
  int repeat;
  int offset=  32 - n;
  unsigned base=  x << offset;
  base = base >> offset;

  repeat = base | base << n;
  repeat = repeat |( repeat <<(( n << 1) * !!(16/n)));
  repeat = repeat |( repeat <<(( n << 2) * !!(8/n)));
  repeat = repeat |( repeat <<(( n << 3) * !!(4/n)));
  repeat = repeat |( repeat <<(( n << 4) * !!(2/n)));

  return repeat;
}
#line 256
int fitsBits(int x, int n) {
#line 261
  int neg=  x >> 31;

  return !((x & ~neg | ~x & neg) >>( n + ~0));

}
#line 275
int getByte(int x, int n) {

  return (x >>( n << 3)) & 0xFF;
}
#line 287
int isLessOrEqual(int x, int y) {
#line 299
  int signx=  x >> 31;
  int signy=  y >> 31;
  int diff=  x + ~y + 1;
  int signMismatch=  signx ^ signy;

  return !!((signMismatch) & signx) |( !(signMismatch) &( diff >> 31)) | !(x ^ y);
}
#line 313
int isPositive(int x) {
#line 318
  return !!(x & ~(x >> 31));
}
#line 328
int logicalShift(int x, int n) {
#line 337
  int mask=(  0x7F << 24) |( 0xFF << 16) |( 0xFF << 8) | 0xFF;
  mask =(( mask << !n) >>(( n + ~0) & mask)) | 1;

  return (x >> n) & mask;
}
#line 348
int tmin(void) {


  return 0x80 << 24;
}
