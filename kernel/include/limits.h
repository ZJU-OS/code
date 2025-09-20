#ifndef __LIMITS_H__
#define __LIMITS_H__

_Static_assert(__LONG_WIDTH__ == 64, "long is not 64 bits; is your ABI LP64?");

#define CHAR_BIT __CHAR_BIT__

#define CHAR_MIN SCHAR_MIN
#define CHAR_MAX SCHAR_MAX

#define SCHAR_MIN 0x80
#define SHRT_MIN 0x8000
#define INT_MIN 0x80000000
#define LONG_MIN 0x8000000000000000
#define LLONG_MIN 0x8000000000000000

#define SCHAR_MAX 0x7f
#define SHRT_MAX 0x7fff
#define INT_MAX 0x7fffffff
#define LONG_MAX 0x7fffffffffffffff
#define LLONG_MAX 0x7fffffffffffffff

#define UCHAR_MAX 0xff
#define USHRT_MAX 0xffff
#define UINT_MAX 0xffffffff
#define ULONG_MAX 0xffffffffffffffff
#define ULLONG_MAX 0xffffffffffffffff

#endif
