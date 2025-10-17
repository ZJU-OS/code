#include <sched.h>
#include <stdnoreturn.h>
#include <mm.h>
#include <proc.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <printk.h>
#include <sbi.h>
#include <private_kdefs.h>
#include <time.h>
#include <list.h>
#include <cache.h>
#include <log.h>
#include <csr.h>
#include <kthread.h>

#ifndef __MAX
#define __MAX(a, b)                 \
	({                          \
		typeof(a) _a = (a); \
		typeof(b) _b = (b); \
		_a > _b ? _a : _b;  \
	})
#endif

// 外部符号
extern char _sbss[]; /* kernel stack bottom */
void __switch_to(struct task_struct *prev, struct task_struct *next);
// 全局变量
LIST_HEAD(task_list);
struct task_struct *idle_task;
// 本地变量
static struct kmem_cache *task_cache;

static unsigned pm_nr_tasks = 1;

int create_pid(void)
{
	return pm_nr_tasks++;
}

void task_init(void)
{
	task_cache =
		kmem_cache_create("task_struct", sizeof(struct task_struct));

	/* Lab2 Task2 */
}

void switch_to(struct task_struct *next)
{
	struct task_struct *prev = current;

	LOG_DEBUG("Switch to [PID = %" PRIu64 "]\n", next->pid);
	__switch_to(prev, next);
	LOG_DEBUG("Switch done\n");
}

struct task_struct *copy_process(struct task_struct *old)
{
	/* Lab2 Task3 */

	return NULL;
}

noreturn void do_exit(int exit_code)
{
	/* Lab2 Task4 */

	(void)exit_code;

	__builtin_unreachable();
}

void release_task(struct task_struct *task)
{
	int pid = task->pid;
	LOG_DEBUG("Release [PID = %" PRIu64 "]\n", pid);

	/* Lab2 Task4 */

	LOG_DEBUG("Release [PID = %" PRIu64 "] Done\n", pid);
}

struct task_struct *kernel_thread(int (*fn)(void *), void *arg)
{
	struct task_struct *new_task = copy_process(NULL);

	/* Lab2 Task3 */

	return new_task;
}
