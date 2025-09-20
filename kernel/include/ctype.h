#ifndef __CTYPE_H__
#define __CTYPE_H__

static inline int iscntrl(int c)
{
	return (c >= 0 && c <= 0x1f) || c == 0x7f;
}

static inline int isdigit(int c)
{
	return c >= '0' && c <= '9';
}

static inline int isgraph(int c)
{
	return c >= 0x21 && c <= 0x7e;
}

static inline int isupper(int c)
{
	return c >= 'A' && c <= 'Z';
}

static inline int islower(int c)
{
	return c >= 'a' && c <= 'z';
}

static inline int isprint(int c)
{
	return c >= 0x20 && c <= 0x7e;
}

static inline int isspace(int c)
{
	return c == ' ' || (c >= '\t' && c <= '\r');
}

static inline int isalpha(int c)
{
	return islower(c) || isupper(c);
}

static inline int isalnum(int c)
{
	return isalpha(c) || isdigit(c);
}

static inline int ispunct(int c)
{
	return isprint(c) && !isalnum(c) && !isspace(c);
}

static inline int isxdigit(int c)
{
	return isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

static inline int isascii(int c)
{
	return c >= 0 && c <= 0x7f;
}

static inline int isblank(int c)
{
	return c == ' ' || c == '\t';
}

static inline int tolower(int c)
{
	if (isupper(c)) {
		return c + ('a' - 'A');
	}
	return c;
}

static inline int toupper(int c)
{
	if (islower(c)) {
		return c - ('a' - 'A');
	}
	return c;
}

#endif
