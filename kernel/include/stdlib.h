#ifndef __STDLIB_H__
#define __STDLIB_H__

#define RAND_MAX 0x7fffffff

int rand(void);
void srand(unsigned int seed);

#define alloca(size) __builtin_alloca(size)

#endif
