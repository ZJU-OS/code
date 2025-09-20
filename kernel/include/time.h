#ifndef __TIME_H__
#define __TIME_H__

// POSIX requires that CLOCKS_PER_SEC equals 1000000 independent of the actual resolution
#define CLOCKS_PER_SEC 1000000

typedef unsigned long clock_t;

clock_t clock(void);

#endif
