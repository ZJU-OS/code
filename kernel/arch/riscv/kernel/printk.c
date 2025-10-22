#include <stdio.h>
#include <printk.h>
#include <sbi.h>
#include <vm.h>

static int printk_sbi_write(FILE *restrict fp, const void *restrict buf,
			    size_t len)
{
	(void)fp;
	sbi_debug_console_write(len, VA2PA((unsigned long)buf), 0);
	return len;
}

void printk(const char *fmt, ...)
{
	FILE printk_out = {
		.write = printk_sbi_write,
	};

	va_list ap;
	va_start(ap, fmt);
	vfprintf(&printk_out, fmt, ap);
	va_end(ap);
}
