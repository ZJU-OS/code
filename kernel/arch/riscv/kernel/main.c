#include <stdint.h>
#include <stdnoreturn.h>
#include <printk.h>
#include <sbi.h>
#include <time.h>

noreturn void start_kernel(void)
{
	printk("Hello, ZJU OS 2025!\n");
	printk("SBI spec version: %#08lx\n", sbi_get_spec_version().value);
	printk("SBI impl id: %#lx\n", sbi_get_impl_id().value);
	printk("SBI impl version: %#08lx\n", sbi_get_impl_version().value);
	printk("SBI machine vendor id: %lu\n", sbi_get_mvendorid().value);
	printk("SBI machine arch id: %lu\n", sbi_get_marchid().value);
	printk("SBI machine imp id: %lu\n", sbi_get_mimpid().value);

	/* Lab1 Task3 */

	uint64_t num_loops = 10000;
	uint64_t time_start = clock();
	for (volatile uint64_t i = 0; i < num_loops; i += 1) {
		// do nothing, just waste time
	}
	uint64_t time_end = clock();
	printk("time spent for %lu loops: %lu seconds (%lu clocks)\n",
	       num_loops, (time_end - time_start) / CLOCKS_PER_SEC,
	       time_end - time_start);

	/* Lab1 Task4 */

	__builtin_unreachable();
}
