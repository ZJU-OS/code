#include <stdio.h>
#include <string.h>
#include <stdint.h>

#ifdef MIN
#undef MIN
#endif
#define MIN(a, b)                   \
	({                          \
		typeof(a) _a = (a); \
		typeof(b) _b = (b); \
		_a < _b ? _a : _b;  \
	})

struct cookie {
	char *buf;
	size_t len;
};

static int snprintf_write(FILE *restrict fp, const void *restrict buf,
			  size_t len)
{
	struct cookie *c = fp->cookie;
	size_t n = MIN(len, c->len);
	memcpy(c->buf, buf, n);
	c->buf += n;
	c->len -= n;
	*c->buf = 0;
	return len;
}

int vsnprintf(char *restrict s, size_t n, const char *restrict fmt, va_list ap)
{
	char dummy[1];

	struct cookie c = {
		.buf = n ? s : dummy,
		.len = n ? n - 1 : 0,
	};

	FILE snprintf_out = {
		.write = snprintf_write,
		.cookie = &c,
	};

	return vfprintf(&snprintf_out, fmt, ap);
}

int vsprintf(char *restrict s, const char *restrict fmt, va_list ap)
{
	return vsnprintf(s, SIZE_MAX, fmt, ap);
}

int snprintf(char *restrict s, size_t n, const char *restrict fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	int ret = vsnprintf(s, n, fmt, ap);
	va_end(ap);
	return ret;
}

int sprintf(char *restrict s, const char *restrict fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	int ret = vsnprintf(s, SIZE_MAX, fmt, ap);
	va_end(ap);
	return ret;
}
