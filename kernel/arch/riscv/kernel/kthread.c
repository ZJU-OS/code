#include <csr.h>
#include <kthread.h>
#include <proc.h>
#include <printk.h>
#include <cache.h>
#include <log.h>

static LIST_HEAD(kthread_create_list);
static struct kmem_cache *kthread_create_info_cache;

noreturn int kthread(void *arg)
{
	struct kthread_create_info *info = arg;
	int (*threadfn)(void *) = info->threadfn;
	void *data = info->data;
	kmem_cache_free(kthread_create_info_cache, info);

	LOG_INFO("started: pid = %" PRIu64 ", fn = %p, data = %p\n",
		 current->pid, threadfn, data);

	int ret = threadfn(data);

	LOG_INFO("finished: pid = %" PRIu64 ", ret = %d\n", current->pid, ret);

	do_exit(ret);
}

int kthreadd(void *unused)
{
	(void)unused;
	for (;;) {
		interrupt_disable();
		while (!list_empty(&kthread_create_list)) {
			struct kthread_create_info *info =
				list_entry(kthread_create_list.next,
					   struct kthread_create_info, list);
			list_del(&info->list);
			struct task_struct *new_task =
				kernel_thread(kthread, info);
			LOG_DEBUG("Created [pid = %" PRIu64
				  ", fn = %p, data = %p, task = %p]\n",
				  new_task->pid, info->threadfn, info->data,
				  (void *)new_task);
		}
		interrupt_enable();
		//	不再占用时间片，让出 CPU 给其他线程
		current->se.runtime = 0;
		schedule();
	}
}

void kthread_create(int (*threadfn)(void *data), void *data)
{
	LOG_DEBUG("Request create [threadfn = %p, data = %p]\n", threadfn,
		  data);
	if (!kthread_create_info_cache) {
		kthread_create_info_cache =
			kmem_cache_create("kthread_create_info",
					  sizeof(struct kthread_create_info));
	}

	struct kthread_create_info *info =
		kmem_cache_alloc(kthread_create_info_cache);

	info->threadfn = threadfn;
	info->data = data;
	list_add_tail(&info->list, &kthread_create_list);
}
