#include <sched.h>
#include <list.h>
#include <proc.h>
#include <printk.h>
#include <stdint.h>
#include <time.h>
#include <log.h>

void schedule(void)
{
	struct task_struct *next_task = NULL;

	/* Lab2 Task4 */

	if (next_task) {
		if (next_task != current) {
			LOG_DEBUG("Schedule to [PID = %" PRIu64 "]\n",
				  next_task->pid);
			switch_to(next_task);
		}
	} else {
		LOG_ERR("No suitable task found.\n");
		for (;;)
			;
	}
}
