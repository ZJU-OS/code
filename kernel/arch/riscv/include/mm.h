#ifndef __MM_H__
#define __MM_H__

#include <private_kdefs.h>
#include <stddef.h>

/** 页帧号转物理地址 */
#define PFN2PHYS(x) (((uint64_t)(x) << 12) + PHY_START)
/** 物理地址转页帧号 */
#define PHYS2PFN(x) (((uint64_t)(x) - PHY_START) >> 12)

/**
 * @brief 内存管理初始化
 */
void mm_init(void);

/**
 * @brief 分配连续物理页
 * @param nrpages 页数
 * @return 虚拟地址
 */
void *alloc_pages(size_t nrpages);

/**
 * @brief 分配一页物理内存
 * @return 虚拟地址
 */
void *alloc_page(void);

/**
 * @brief 释放物理页
 * @param va 虚拟地址
 */
void free_pages(void *va);

#endif
