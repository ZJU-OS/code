#ifndef __KTHREAD_H__
#define __KTHREAD_H__

#include <stdnoreturn.h>
#include <list.h>

/**
 * @brief 内核线程创建信息结构体
 */
struct kthread_create_info {
	struct list_head list; /**< 链表节点 */
	int (*threadfn)(void *); /**< 线程函数 */
	void *data; /**< 线程函数参数 */
};

/**
 * @brief 内核线程 trampoline
 *
 * 该函数实现在 entry.S 中，用于从内核线程初始上下文跳转到内核线程函数
 */
void __kthread(void);

/**
 * @brief 内核线程 wrapper
 *
 * 调用内核线程函数，并在其返回后调用 do_exit 退出线程
 *
 * @param info 线程信息
 * @return 不返回
 */
noreturn int kthread(void *info);

/**
 * @brief 内核线程守护进程
 *
 * 作为第一个内核线程运行，轮询内核线程创建队列，创建内核线程
 *
 * @param unused 未使用参数
 * @return 退出码
 */
int kthreadd(void *unused);

/**
 * @brief 创建内核线程
 *
 * 将内核线程创建请求加入创建队列，由 kthreadd 线程处理
 *
 * @param threadfn 线程函数
 * @param data 线程函数参数
 * @return 新创建的线程
 */
void kthread_create(int (*threadfn)(void *), void *data);

#endif