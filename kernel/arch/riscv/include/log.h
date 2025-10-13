#ifndef __LOG_H__
#define __LOG_H__

/** 错误日志级别 */
#define LOG_LEVEL_ERR 0
/** 警告日志级别 */
#define LOG_LEVEL_WARNING 1
/** 信息日志级别 */
#define LOG_LEVEL_INFO 2
/** 调试日志级别 */
#define LOG_LEVEL_DEBUG 3

/** 默认日志级别 */
#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_WARNING
#endif

/**
 * @brief 错误日志宏
 * @param fmt 格式字符串
 * @param ... 参数
 */
#define LOG_ERR(fmt, ...)                                           \
	log_print(LOG_LEVEL_ERR, __FILE__, __LINE__, __func__, fmt, \
		  ##__VA_ARGS__)

/**
 * @brief 警告日志宏
 * @param fmt 格式字符串
 * @param ... 参数
 */
#define LOG_WARNING(fmt, ...)                                           \
	log_print(LOG_LEVEL_WARNING, __FILE__, __LINE__, __func__, fmt, \
		  ##__VA_ARGS__)

/**
 * @brief 信息日志宏
 * @param fmt 格式字符串
 * @param ... 参数
 */
#define LOG_INFO(fmt, ...)                                           \
	log_print(LOG_LEVEL_INFO, __FILE__, __LINE__, __func__, fmt, \
		  ##__VA_ARGS__)

/**
 * @brief 调试日志宏
 * @param fmt 格式字符串
 * @param ... 参数
 */
#define LOG_DEBUG(fmt, ...)                                           \
	log_print(LOG_LEVEL_DEBUG, __FILE__, __LINE__, __func__, fmt, \
		  ##__VA_ARGS__)

/**
 * @brief 打印日志信息
 * @param level 日志级别
 * @param file 源文件名
 * @param line 行号
 * @param func 函数名
 * @param fmt 格式字符串
 * @param ... 参数
 */
void log_print(int level, const char *file, int line, const char *func,
	       const char *fmt, ...);

#endif