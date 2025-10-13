#include <list.h>
#include <printk.h>
#include <proc.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <log.h>
#include <stdbool.h>
#include <kthread.h>
#include <string.h>

#define PROC_COUNT 5

struct process {
	uint64_t arrival_time;
	uint64_t burst_time;
	int id;
	bool created;
};

static struct process processes[PROC_COUNT] = { { 0, 10, 1, false },
						{ 1, 1, 2, false },
						{ 4, 2, 3, false },
						{ 5, 1, 4, false },
						{ 8, 5, 5, false } };

static uint64_t initial_clock;
static struct task_struct snapshot[PROC_COUNT];

static int process(void *data)
{
	struct process *proc = (struct process *)data;
	uint64_t current_time = clock() - initial_clock;
	printk("\nProcess %d started at %lu, burst %lu\n", proc->id,
	       current_time / CLOCKS_PER_SEC, proc->burst_time);

	proc->created = true;

	uint64_t last_print_time = 0;
	while (current->se.sum_exec_runtime <
	       proc->burst_time * CLOCKS_PER_SEC) {
		uint64_t now = current->se.sum_exec_runtime;
		if (now >= last_print_time + (CLOCKS_PER_SEC / 10)) {
			printk("%d", proc->id);
			last_print_time = now;
		}
		// 检查新任务
		for (size_t i = 0; i < PROC_COUNT; i++) {
			if (!processes[i].created &&
			    processes[i].arrival_time * CLOCKS_PER_SEC <=
				    (clock() - initial_clock)) {
				processes[i].created = true;
				kthread_create(process, &processes[i]);
			}
		}
	}
	current_time = clock() - initial_clock;
	printk("\nProcess %d finished at %lu\n", proc->id,
	       current_time / CLOCKS_PER_SEC);
	memcpy(&snapshot[proc->id - 1], current, sizeof(struct task_struct));
	return 0;
}

int test_sched(void *)
{
	printk("\n[Lab2 Task5] Priority-based Scheduling Test\n");
	kthread_create(process, &processes[0]);
	return 0;
}
