#ifndef __CSR_H__
#define __CSR_H__

/** CSR 寄存器位，可用于汇编代码 */
#define SSTATUS_SIE (1UL << 1)
#define SSTATUS_SPIE (1UL << 5)
#define SSTATUS_SPP (1UL << 8)
#define SIE_SSIE (1UL << 1)
#define SIE_STIE (1UL << 5)
#define SIE_SEIE (1UL << 9)
#define SIP_SSIP (1UL << 1)
#define SIP_STIP (1UL << 5)
#define SIP_SEIP (1UL << 9)

#ifndef __ASSEMBLER__

#include <stdint.h>

/**
 * @brief 读取 CSR 寄存器
 * @param csr CSR 寄存器名
 * @return 读取的值
 */
#define csr_read(csr)                           \
	({                                      \
		uint64_t __v;                   \
		asm volatile(/* Lab1 Task3 */); \
		__v;                            \
	})

/**
 * @brief 写入 CSR 寄存器
 * @param csr CSR 寄存器名
 * @param val 要写入的值
 */
#define csr_write(csr, val)                     \
	({                                      \
		uint64_t __v = (uint64_t)(val); \
		asm volatile(/* Lab1 Task3 */); \
	})

/**
 * @brief 设置 CSR 寄存器位
 * @param csr CSR 寄存器名
 * @param val 要设置的位
 */
#define csr_set(csr, val)                          \
	({                                         \
		uint64_t __v = (uint64_t)(val);    \
		asm volatile("" /* Lab1 Task3 */); \
	})

/**
 * @brief 清除 CSR 寄存器位
 * @param csr CSR 寄存器名
 * @param val 要清除的位
 */
#define csr_clear(csr, val)                        \
	({                                         \
		uint64_t __v = (uint64_t)(val);    \
		asm volatile("" /* Lab1 Task3 */); \
	})

/**
 * @brief 全局使能中断
 */
static inline void interrupt_enable(void)
{
	csr_set(sstatus, SSTATUS_SIE);
}

/**
 * @brief 全局禁用中断
 */
static inline void interrupt_disable(void)
{
	csr_clear(sstatus, SSTATUS_SIE);
}

#endif // __ASSEMBLER__

#endif