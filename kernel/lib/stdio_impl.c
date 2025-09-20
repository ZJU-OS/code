#include <stdio.h>
#include <string.h>

int fileno(FILE *f)
{
	return f->fd;
}

int fprintf(FILE *restrict f, const char *restrict fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	int ret = vfprintf(f, fmt, ap);
	va_end(ap);
	return ret;
}

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
{
	return stream->write(stream, ptr, size * nmemb);
}

int fputc(int c, FILE *stream)
{
	return stream->write(stream, &c, 1);
}

int putc(int c, FILE *stream) __attribute__((alias("fputc")));

int fputs(const char *s, FILE *stream)
{
	return stream->write(stream, s, strlen(s));
}
