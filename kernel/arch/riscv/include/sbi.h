#ifndef __SBI_H__
#define __SBI_H__

#include <stdint.h>
#include <stdnoreturn.h>

#define SSTATUS_SIE (1UL << 1)
#define SSTATUS_SPIE (1UL << 5)
#define SSTATUS_SPP (1UL << 8)
#define SIE_SSIE (1UL << 1)
#define SIE_STIE (1UL << 5)
#define SIE_SEIE (1UL << 9)
#define SIP_SSIP (1UL << 1)
#define SIP_STIP (1UL << 5)
#define SIP_SEIP (1UL << 9)

#define csr_read(csr)                           \
	({                                      \
		uint64_t __v;                   \
		asm volatile(/* Lab1 Task3 */); \
		__v;                            \
	})

#define csr_write(csr, val)                     \
	({                                      \
		uint64_t __v = (uint64_t)(val); \
		asm volatile(/* Lab1 Task3 */); \
	})

#define csr_set(csr, val)                       \
	({                                      \
		uint64_t __v = (uint64_t)(val); \
		asm volatile(/* Lab1 Task3 */); \
	})

#define SBI_SUCCESS 0
#define SBI_ERR_FAILED -1
#define SBI_ERR_NOT_SUPPORTED -2
#define SBI_ERR_INVALID_PARAM -3
#define SBI_ERR_DENIED -4
#define SBI_ERR_INVALID_ADDRESS -5
#define SBI_ERR_ALREADY_AVAILABLE -6
#define SBI_ERR_ALREADY_STARTED -7
#define SBI_ERR_ALREADY_STOPPED -8
#define SBI_ERR_NO_SHMEM -9

struct sbiret {
	long error;
	long value;
};

struct sbiret sbi_ecall(uint64_t eid, uint64_t fid, uint64_t arg0,
			uint64_t arg1, uint64_t arg2, uint64_t arg3,
			uint64_t arg4, uint64_t arg5);

// base extension
struct sbiret sbi_get_spec_version(void);
struct sbiret sbi_get_impl_id(void);
struct sbiret sbi_get_impl_version(void);
struct sbiret sbi_probe_extension(uint64_t ext);
struct sbiret sbi_get_mvendorid(void);
struct sbiret sbi_get_marchid(void);
struct sbiret sbi_get_mimpid(void);

// time extension
struct sbiret sbi_set_timer(uint64_t stime_value);

// debug console extension
struct sbiret sbi_debug_console_write(unsigned long num_bytes,
				      unsigned long base_addr_lo,
				      unsigned long base_addr_hi);
struct sbiret sbi_debug_console_read(unsigned long num_bytes,
				     unsigned long base_addr_lo,
				     unsigned long base_addr_hi);
struct sbiret sbi_debug_console_write_byte(uint8_t byte);

// system reset extension
#define SBI_SRST_RESET_TYPE_SHUTDOWN 0
#define SBI_SRST_RESET_TYPE_COLD_REBOOT 1
#define SBI_SRST_RESET_TYPE_WARM_REBOOT 2
#define SBI_SRST_RESET_REASON_NONE 0
#define SBI_SRST_RESET_REASON_SYSTEM_FAILURE 1
noreturn void sbi_system_reset(uint32_t reset_type, uint32_t reset_reason);

// hart state management extension
#define SBI_HSM_STATE_STARTED 0
#define SBI_HSM_STATE_STOPPED 1
#define SBI_HSM_STATE_START_PENDING 2
#define SBI_HSM_STATE_STOP_PENDING 3
#define SBI_HSM_STATE_SUSPENDED 4
#define SBI_HSM_STATE_SUSPEND_PENDING 5
#define SBI_HSM_STATE_RESUME_PENDING 6
struct sbiret sbi_hart_start(unsigned long hartid, unsigned long start_addr,
			     unsigned long opaque);
struct sbiret sbi_hart_stop(void);
struct sbiret sbi_hart_get_status(unsigned long hartid);
struct sbiret sbi_hart_suspend(uint32_t suspend_type, unsigned long resume_addr,
			       unsigned long opaque);

#endif
