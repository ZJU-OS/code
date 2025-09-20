#ifndef __STDINT_H__
#define __STDINT_H__

#include <limits.h>

typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int64_t;

typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;

typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef int64_t intmax_t;

typedef int64_t intptr_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;

typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;

typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

typedef uint64_t uintmax_t;

typedef uint64_t uintptr_t;

#define INT8_MIN SCHAR_MIN
#define INT16_MIN SHRT_MIN
#define INT32_MIN INT_MIN
#define INT64_MIN LLONG_MIN

#define INT_FAST8_MIN INT8_MIN
#define INT_FAST16_MIN INT16_MIN
#define INT_FAST32_MIN INT32_MIN
#define INT_FAST64_MIN INT64_MIN

#define INT_LEAST8_MIN INT8_MIN
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST64_MIN INT64_MIN

#define INTPTR_MIN INT64_MIN

#define INTMAX_MIN INT64_MIN

#define INT8_MAX SCHAR_MAX
#define INT16_MAX SHRT_MAX
#define INT32_MAX INT_MAX
#define INT64_MAX LLONG_MAX

#define INT_FAST8_MAX INT8_MAX
#define INT_FAST16_MAX INT16_MAX
#define INT_FAST32_MAX INT32_MAX
#define INT_FAST64_MAX INT64_MAX

#define INT_LEAST8_MAX INT8_MAX
#define INT_LEAST16_MAX INT16_MAX
#define INT_LEAST32_MAX INT32_MAX
#define INT_LEAST64_MAX INT64_MAX

#define INTPTR_MAX INT64_MAX

#define INTMAX_MAX INT64_MAX

#define UINT8_MAX UCHAR_MAX
#define UINT16_MAX USHRT_MAX
#define UINT32_MAX UINT_MAX
#define UINT64_MAX ULLONG_MAX

#define UINT_FAST8_MAX UINT8_MAX
#define UINT_FAST16_MAX UINT16_MAX
#define UINT_FAST32_MAX UINT32_MAX
#define UINT_FAST64_MAX UINT64_MAX

#define UINT_LEAST8_MAX UINT8_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST64_MAX UINT64_MAX

#define UINTPTR_MAX UINT64_MAX

#define UINTMAX_MAX UINT64_MAX

#define INT8_C(c) ((int8_t)(c))
#define INT16_C(c) ((int16_t)(c))
#define INT32_C(c) ((int32_t)(c))
#define INT64_C(c) ((int64_t)(c))

#define INTMAX_C(c) INT64_C(c)

#define UINT8_C(c) ((uint8_t)(c))
#define UINT16_C(c) ((uint16_t)(c))
#define UINT32_C(c) ((uint32_t)(c))
#define UINT64_C(c) ((uint64_t)(c))

#define UINTMAX_C(c) UINT64_C(c)

#define PTRDIFF_MIN __PTRDIFF_MIN__
#define PTRDIFF_MAX __PTRDIFF_MAX__
#define SIZE_MAX __SIZE_MAX__

#endif
