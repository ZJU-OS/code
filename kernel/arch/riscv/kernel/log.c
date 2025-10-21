#include <stdarg.h>
#include <stdio.h>
#include <printk.h>
#include <log.h>
#include <string.h>
#include <proc.h>

static inline const char *get_level_str(int level)
{
	switch (level) {
	case LOG_LEVEL_ERR:
		return "ERR";
	case LOG_LEVEL_WARNING:
		return "WARNING";
	case LOG_LEVEL_INFO:
		return "INFO";
	case LOG_LEVEL_DEBUG:
		return "DEBUG";
	default:
		return "UNKNOWN";
	}
}

static inline const char *get_color(int level)
{
	switch (level) {
	case LOG_LEVEL_ERR:
		return "\x1b[31m"; // 红
	case LOG_LEVEL_WARNING:
		return "\x1b[33m"; // 黄
	case LOG_LEVEL_INFO:
		return "\x1b[32m"; // 绿
	case LOG_LEVEL_DEBUG:
		return "\x1b[34m"; // 蓝
	default:
		return ""; // 默认无颜色
	}
}

void log_print(int level, const char *file, int line, const char *func,
	       const char *fmt, ...)
{
	if (level > LOG_LEVEL)
		return;

	char buf[1024];
	int len;
	const char *level_str = get_level_str(level);
	const char *color = get_color(level);

	// 构建前缀：加粗的彩色[LEVEL] + 灰色的 file:line:func: + 正常颜色的消息
	len = snprintf(
		buf, sizeof(buf),
		"%s\x1b[1m[%s, PID = %lu]\x1b[0m \x1b[90m%s:%d:%s:\x1b[0m %s",
		color, level_str, current ? current->pid : 0, file, line, func,
		color);
	if (len < 0 || (size_t)len >= sizeof(buf)) {
		// 如果前缀太长，直接打印错误
		printk("[LOG] Prefix too long\n");
		return;
	}

	// 添加用户消息
	va_list ap;
	va_start(ap, fmt);
	vsnprintf(buf + len, sizeof(buf) - len, fmt, ap);
	va_end(ap);

	// 输出到内核日志，添加重置颜色
	printk("%s\x1b[0m", buf);
}