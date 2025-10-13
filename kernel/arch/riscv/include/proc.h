#ifndef __PROC_H__
#define __PROC_H__

/** task_struct 中 thread 字段偏移 */
#define OFFSETOF_TS_THREAD 24

#ifndef __ASSEMBLER__

#include <stdint.h>
#include <stddef.h>
#include <private_kdefs.h>
#include <list.h>
#include <sched.h>
#include <stdnoreturn.h>

register struct task_struct *current asm("tp");
extern struct task_struct *idle_task;
extern struct list_head task_list;

/**
 * @brief 线程上下文结构体
 */
struct thread_struct {
	uint64_t ra;
	uint64_t sp;
	uint64_t s[12];
};

/**
 * @brief 进程结构体
 */
struct task_struct {
	struct list_head list; /**< 进程链表 */
	uint64_t pid; /**< 进程 ID */
	struct thread_struct thread; /**< 线程上下文 */
	void *stack; /**< 栈指针 */
	uint64_t state; /**< 进程状态 */
	struct sched_entity se; /**< 调度实体 */
};

_Static_assert(offsetof(struct task_struct, thread) == OFFSETOF_TS_THREAD,
	       "thread offset error");

/**
 * @brief 进程初始化
 */
void task_init(void);

/**
 * @brief 切换到下一个进程
 * @param next 下一个进程
 */
void switch_to(struct task_struct *next);

/**
 * @brief 创建内核线程
 * @param fn 线程函数
 * @param arg 参数
 * @return 新线程
 */
struct task_struct *kernel_thread(int (*fn)(void *), void *arg);

/**
 * @brief 克隆进程
 * @param to_copy 要克隆的进程
 * @return 新进程
 */
struct task_struct *copy_process(struct task_struct *to_copy);

/**
 * @brief 进程退出
 * @param exit_code 退出码
 */
noreturn void do_exit(int exit_code);

/**
 * @brief 释放进程
 * @param task 要释放的进程
 */
void release_task(struct task_struct *task);

#endif /* __ASSEMBLER__ */

#endif
