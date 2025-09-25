#include <stdint.h>
#include <sbi.h>

// https://github.com/riscv-non-isa/riscv-sbi-doc/blob/master/riscv-sbi.adoc

#define SBI_EXT_BASE 0x10
#define SBI_BASE_GET_SPEC_VERSION 0
#define SBI_BASE_GET_IMPL_ID 1
#define SBI_BASE_GET_IMPL_VERSION 2
#define SBI_BASE_PROBE_EXT 3
#define SBI_BASE_GET_MVENDORID 4
#define SBI_BASE_GET_MARCHID 5
#define SBI_BASE_GET_MIMPID 6

#define SBI_EXT_TIME 0x54494d45 // "TIME"
#define SBI_TIME_SET_TIMER 0

#define SBI_EXT_DEBUG_CONSOLE 0x4442434e // "DBCN"
#define SBI_DBCN_WRITE 0
#define SBI_DBCN_READ 1
#define SBI_DBCN_WRITE_BYTE 2

#define SBI_EXT_SYSTEM_RESET 0x53525354 // "SRST"
#define SBI_SRST_SYSTEM_RESET 0

#define SBI_EXT_HSM 0x48534d // "HSM"
#define SBI_HSM_HART_START 0
#define SBI_HSM_HART_STOP 1
#define SBI_HSM_HART_GET_STATUS 2
#define SBI_HSM_HART_SUSPEND 3

struct sbiret sbi_ecall(uint64_t eid, uint64_t fid, uint64_t arg0,
			uint64_t arg1, uint64_t arg2, uint64_t arg3,
			uint64_t arg4, uint64_t arg5)
{
	/* Lab1 Task2 */
	return (struct sbiret){
		.error = -1,
		.value = 0,
	};
}

struct sbiret sbi_get_spec_version(void)
{
	return sbi_ecall(SBI_EXT_BASE, SBI_BASE_GET_SPEC_VERSION, 0, 0, 0, 0, 0,
			 0);
}

struct sbiret sbi_get_impl_id(void)
{
	return sbi_ecall(SBI_EXT_BASE, SBI_BASE_GET_IMPL_ID, 0, 0, 0, 0, 0, 0);
}

struct sbiret sbi_get_impl_version(void)
{
	return sbi_ecall(SBI_EXT_BASE, SBI_BASE_GET_IMPL_VERSION, 0, 0, 0, 0, 0,
			 0);
}

struct sbiret sbi_probe_extension(uint64_t ext)
{
	return sbi_ecall(SBI_EXT_BASE, SBI_BASE_PROBE_EXT, ext, 0, 0, 0, 0, 0);
}

struct sbiret sbi_get_mvendorid(void)
{
	return sbi_ecall(SBI_EXT_BASE, SBI_BASE_GET_MVENDORID, 0, 0, 0, 0, 0,
			 0);
}

struct sbiret sbi_get_marchid(void)
{
	return sbi_ecall(SBI_EXT_BASE, SBI_BASE_GET_MARCHID, 0, 0, 0, 0, 0, 0);
}

struct sbiret sbi_get_mimpid(void)
{
	return sbi_ecall(SBI_EXT_BASE, SBI_BASE_GET_MIMPID, 0, 0, 0, 0, 0, 0);
}

struct sbiret sbi_set_timer(uint64_t stime_value)
{
	return sbi_ecall(SBI_EXT_TIME, SBI_TIME_SET_TIMER, stime_value, 0, 0, 0,
			 0, 0);
}

struct sbiret sbi_debug_console_write(unsigned long num_bytes,
				      unsigned long base_addr_lo,
				      unsigned long base_addr_hi)
{
	return sbi_ecall(/* Lab1 Task2 */ 0, 0, 0, 0, 0, 0, 0, 0);
}

struct sbiret sbi_debug_console_read(unsigned long num_bytes,
				     unsigned long base_addr_lo,
				     unsigned long base_addr_hi)
{
	return sbi_ecall(/* Lab1 Task2 */ 0, 0, 0, 0, 0, 0, 0, 0);
}

struct sbiret sbi_debug_console_write_byte(uint8_t byte)
{
	return sbi_ecall(/* Lab1 Task2 */ 0, 0, 0, 0, 0, 0, 0, 0);
}

void sbi_system_reset(uint32_t reset_type, uint32_t reset_reason)
{
	sbi_ecall(SBI_EXT_SYSTEM_RESET, SBI_SRST_SYSTEM_RESET, reset_type,
		  reset_reason, 0, 0, 0, 0);
	__builtin_unreachable();
}

struct sbiret sbi_hart_start(unsigned long hartid, unsigned long start_addr,
			     unsigned long opaque)
{
	return sbi_ecall(SBI_EXT_HSM, SBI_HSM_HART_START, hartid, start_addr,
			 opaque, 0, 0, 0);
}

struct sbiret sbi_hart_stop(void)
{
	return sbi_ecall(SBI_EXT_HSM, SBI_HSM_HART_STOP, 0, 0, 0, 0, 0, 0);
}

struct sbiret sbi_hart_get_status(unsigned long hartid)
{
	return sbi_ecall(SBI_EXT_HSM, SBI_HSM_HART_GET_STATUS, hartid, 0, 0, 0,
			 0, 0);
}

struct sbiret sbi_hart_suspend(uint32_t suspend_type, unsigned long resume_addr,
			       unsigned long opaque)
{
	return sbi_ecall(SBI_EXT_HSM, SBI_HSM_HART_SUSPEND, suspend_type,
			 resume_addr, opaque, 0, 0, 0);
}
