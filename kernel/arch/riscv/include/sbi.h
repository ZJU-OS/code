#ifndef __SBI_H__
#define __SBI_H__

#include <stdint.h>
#include <stdnoreturn.h>

/** SBI 错误码 */
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

/**
 * @brief SBI 调用返回值结构体
 */
struct sbiret {
	long error; /**< 错误码 */
	long value; /**< 返回值 */
};

/**
 * @brief SBI ECALL
 * @param eid 扩展 ID
 * @param fid 函数 ID
 * @param arg0-5 参数5
 * @return sbiret
 */
struct sbiret sbi_ecall(uint64_t eid, uint64_t fid, uint64_t arg0,
			uint64_t arg1, uint64_t arg2, uint64_t arg3,
			uint64_t arg4, uint64_t arg5);

// base extension
/**
 * @brief 获取 SBI 规范版本
 * @return sbiret
 */
struct sbiret sbi_get_spec_version(void);
/**
 * @brief 获取实现 ID
 * @return sbiret
 */
struct sbiret sbi_get_impl_id(void);
/**
 * @brief 获取实现版本
 * @return sbiret
 */
struct sbiret sbi_get_impl_version(void);
/**
 * @brief 探测扩展
 * @param ext 扩展 ID
 * @return sbiret
 */
struct sbiret sbi_probe_extension(uint64_t ext);
/**
 * @brief 获取机器供应商 ID
 * @return sbiret
 */
struct sbiret sbi_get_mvendorid(void);
/**
 * @brief 获取机器架构 ID
 * @return sbiret
 */
struct sbiret sbi_get_marchid(void);
/**
 * @brief 获取机器实现 ID
 * @return sbiret
 */
struct sbiret sbi_get_mimpid(void);

// time extension
/**
 * @brief 设置定时器
 * @param stime_value 时间值
 * @return sbiret
 */
struct sbiret sbi_set_timer(uint64_t stime_value);

// debug console extension
/**
 * @brief 调试控制台写
 * @param num_bytes 字节数
 * @param base_addr_lo 地址低32位
 * @param base_addr_hi 地址高32位
 * @return sbiret
 */
struct sbiret sbi_debug_console_write(unsigned long num_bytes,
				      unsigned long base_addr_lo,
				      unsigned long base_addr_hi);
/**
 * @brief 调试控制台读
 * @param num_bytes 字节数
 * @param base_addr_lo 地址低32位
 * @param base_addr_hi 地址高32位
 * @return sbiret
 */
struct sbiret sbi_debug_console_read(unsigned long num_bytes,
				     unsigned long base_addr_lo,
				     unsigned long base_addr_hi);
/**
 * @brief 调试控制台写字节
 * @param byte 字节
 * @return sbiret
 */
struct sbiret sbi_debug_console_write_byte(uint8_t byte);

// system reset extension
/** 重置类型 */
#define SBI_SRST_RESET_TYPE_SHUTDOWN 0
#define SBI_SRST_RESET_TYPE_COLD_REBOOT 1
#define SBI_SRST_RESET_TYPE_WARM_REBOOT 2
/** 重置原因 */
#define SBI_SRST_RESET_REASON_NONE 0
#define SBI_SRST_RESET_REASON_SYSTEM_FAILURE 1
/**
 * @brief 系统重置
 * @param reset_type 重置类型
 * @param reset_reason 重置原因
 */
noreturn void sbi_system_reset(uint32_t reset_type, uint32_t reset_reason);

// hart state management extension
/** Hart 状态 */
#define SBI_HSM_STATE_STARTED 0
#define SBI_HSM_STATE_STOPPED 1
#define SBI_HSM_STATE_START_PENDING 2
#define SBI_HSM_STATE_STOP_PENDING 3
#define SBI_HSM_STATE_SUSPENDED 4
#define SBI_HSM_STATE_SUSPEND_PENDING 5
#define SBI_HSM_STATE_RESUME_PENDING 6
/**
 * @brief 启动 hart
 * @param hartid hart ID
 * @param start_addr 启动地址
 * @param opaque 不透明参数
 * @return sbiret
 */
struct sbiret sbi_hart_start(unsigned long hartid, unsigned long start_addr,
			     unsigned long opaque);
/**
 * @brief 停止 hart
 * @return sbiret
 */
struct sbiret sbi_hart_stop(void);
/**
 * @brief 获取 hart 状态
 * @param hartid hart ID
 * @return sbiret
 */
struct sbiret sbi_hart_get_status(unsigned long hartid);
/**
 * @brief 挂起 hart
 * @param suspend_type 挂起类型
 * @param resume_addr 恢复地址
 * @param opaque 不透明参数
 * @return sbiret
 */
struct sbiret sbi_hart_suspend(uint32_t suspend_type, unsigned long resume_addr,
			       unsigned long opaque);

#endif
