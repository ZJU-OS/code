#ifndef __PRINTK_H__
#define __PRINTK_H__

#include <inttypes.h>

/**
 * @brief 内核打印函数
 * @param fmt 格式字符串
 * @param ... 参数
 */
void printk(const char *fmt, ...) __attribute__((format(printf, 1, 2)));

#endif
