#ifndef __PRIVATE_KDEFS_H__
#define __PRIVATE_KDEFS_H__

// QEMU virt 机器的时钟频率为 10 MHz
#define TIMECLOCK 10000000

#define PHY_START 0x80000000
#define PHY_SIZE 0x8000000 // 128 MiB
#define PHY_END (PHY_START + PHY_SIZE)

#define PGSIZE 0x1000 // 4 KiB
#define PGROUNDDOWN(addr) ((addr) & ~(PGSIZE - 1))
#define PGROUNDUP(addr) PGROUNDDOWN((addr) + PGSIZE - 1)

#define OPENSBI_SIZE 0x200000

// see proc.h
#define OFFSETOF_TS_THREAD 32
#define PT_REGS_SIZE (33 * 8)

#endif
