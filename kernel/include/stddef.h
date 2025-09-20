#ifndef __STDDEF_H__
#define __STDDEF_H__

typedef __PTRDIFF_TYPE__ ptrdiff_t;
typedef __SIZE_TYPE__ size_t;
typedef __WCHAR_TYPE__ wchar_t;

#define NULL ((void *)0)
#define offsetof(type, member) __builtin_offsetof(type, member)

#endif
