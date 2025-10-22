#include "private_kdefs.h"
#include <vm.h>
#include <mm.h>
#include <string.h>
#include <sbi.h>
#include <printk.h>
#include <csr.h>
#include <log.h>

/** vmlinux.lds 各段 */
extern uint8_t _stext[];
extern uint8_t _srodata[];
extern uint8_t _sdata[];

/** 直接映射大页表 */
uint64_t early_pg_dir[PGSIZE / 8] __attribute__((__aligned__(PGSIZE)));
/**  */
uint64_t swapper_pg_dir[PGSIZE / 8] __attribute__((__aligned__(PGSIZE)));

uint64_t setup_vm(void)
{
	memset(early_pg_dir, 0, PGSIZE);

	/* Lab3 Task1 */

	return 0;
}

uint64_t setup_vm_final(void)
{
	memset(swapper_pg_dir, 0, PGSIZE);

	/* Lab3 Task2 */

	return 0;
}

void create_mapping(uint64_t pgtbl[static PGSIZE / 8], void *va, void *pa,
		    uint64_t sz, uint64_t perm)
{
	/* Lab3 Task2 */
}
