#ifndef __STDIO_H__
#define __STDIO_H__

#include <stddef.h>
#include <stdarg.h>

typedef struct FILE {
	int fd;
	int (*read)(struct FILE *, const void *, size_t);
	int (*write)(struct FILE *, const void *, size_t);
	void *cookie;
} FILE;

#define stdin (&__iob[0])
#define stdout (&__iob[1])
#define stderr (&__iob[2])

extern FILE __iob[3];

int fileno(FILE *f);

int printf(const char *restrict fmt, ...) __attribute__((format(printf, 1, 2)));
int fprintf(FILE *restrict f, const char *restrict fmt, ...)
	__attribute__((format(printf, 2, 3)));
int vprintf(const char *restrict fmt, va_list ap);
int vfprintf(FILE *restrict f, const char *restrict fmt, va_list ap);

int fputc(int c, FILE *stream);
int putc(int c, FILE *stream);
int putchar(int c);

int fputs(const char *s, FILE *stream);
int puts(const char *s);

int sprintf(char *restrict s, const char *restrict fmt, ...)
	__attribute__((format(printf, 2, 3)));
int snprintf(char *restrict s, size_t n, const char *restrict fmt, ...)
	__attribute__((format(printf, 3, 4)));
int vsprintf(char *restrict s, const char *restrict fmt, va_list ap);
int vsnprintf(char *restrict s, size_t n, const char *restrict fmt, va_list ap);

#endif
