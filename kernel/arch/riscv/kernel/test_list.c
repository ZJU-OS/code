#include <printk.h>
#include <stdlib.h>
#include <list.h>

#define MAX_NODES 10
struct list_snapshot {
	int ids[MAX_NODES];
	int count;
};

struct test_node {
	int id;
	struct list_head list;
};

static struct list_snapshot snapshot;

static void record_list(struct list_head *head)
{
	struct list_head *pos;
	struct test_node *entry;
	int i = 0;
	snapshot.count = 0;

	list_for_each(pos, head)
	{
		entry = list_entry(pos, struct test_node, list);
		if (i < MAX_NODES) {
			snapshot.ids[i++] = entry->id;
		}
	}
	snapshot.count = i;
}

int test_list(void *)
{
	printk("\n[Lab2 Task1] Doubly-linked List Test\n");
	static struct test_node nodes[MAX_NODES];
	static int next_node = 0;

	// 1. 静态声明并初始化一个链表头
	LIST_HEAD(test_list_head);

	// 2. 添加节点
	for (int i = 10; i <= 30; i += 10) {
		struct test_node *new_node = &nodes[next_node++];
		new_node->id = i;
		list_add(&new_node->list, &test_list_head); // 头插法
	}
	for (int i = 40; i <= 60; i += 10) {
		struct test_node *new_node = &nodes[next_node++];
		new_node->id = i;
		list_add_tail(&new_node->list, &test_list_head); // 尾插法
	}
	record_list(&test_list_head);

	// 3. 删除一个指定的节点
	struct list_head *pos, *n;
	struct test_node *target_node = NULL;

	list_for_each_safe(pos, n, &test_list_head)
	{
		target_node = list_entry(pos, struct test_node, list);
		if (target_node->id == 20) {
			list_del(&target_node->list);
			// free(target_node); // not needed for static allocation
			break;
		}
	}
	record_list(&test_list_head);

	// 4. 清空整个链表并释放所有节点内存
	list_for_each_safe(pos, n, &test_list_head)
	{
		struct test_node *entry =
			list_entry(pos, struct test_node, list);
		list_del(&entry->list);
		// free(entry); // not needed for static allocation
	}

	record_list(&test_list_head);

	return 0;
}
