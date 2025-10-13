#ifndef __PRIVATE_KDEFS_H__
#define __PRIVATE_KDEFS_H__

/** 时钟频率 10MHz */
#define TIMECLOCK 10000000
/** 物理内存起始地址 */
#define PHY_START 0x80000000
/** 物理内存大小 128MiB */
#define PHY_SIZE 0x8000000
/** 物理内存结束地址 */
#define PHY_END (PHY_START + PHY_SIZE)
/** 页大小 4KiB */
#define PGSIZE 0x1000
/** 向下取整到页边界 */
#define PGROUNDDOWN(addr) ((addr) & ~(PGSIZE - 1))
/** 向上取整到页边界 */
#define PGROUNDUP(addr) PGROUNDDOWN((addr) + PGSIZE - 1)
/** OpenSBI 大小 */
#define OPENSBI_SIZE 0x200000

#endif
