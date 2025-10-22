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
#define SATP_MODE_BARE (0UL << 60)
#define SATP_MODE_SV39 (8UL << 60)
#define SATP_MODE_SV48 (9UL << 60)
#define SATP_MODE_SV57 (10UL << 60)
#define SATP_MODE_SV64 (11UL << 60)

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
 * @brief 读取并设置 CSR 寄存器位
 * @param csr CSR 寄存器名
 * @param val 要设置的位
 * @return 读取的原值
 */
#define csr_read_clear(csr, val)                      \
	({                                            \
		uint64_t __v = (uint64_t)(val);       \
		asm volatile("csrrc %0, " #csr ", %1" \
			     : "=r"(__v)              \
			     : "rK"(__v)              \
			     : "memory");             \
		__v;                                  \
	})

/**
 * @brief 全局使能中断
 */
static inline void interrupt_restore(uint64_t *flags)
{
	csr_set(sstatus, *flags & SSTATUS_SIE);
}

/**
 * @brief 全局禁用中断
 */
static inline void interrupt_save(uint64_t *flags)
{
	*flags = csr_read_clear(sstatus, SSTATUS_SIE);
}

#endif // __ASSEMBLER__

#endif