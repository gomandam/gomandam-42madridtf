#include <unistd.h>
#include <stdarg.h>

int putstr(char *str, int c)
{
	if (!str)	{ return putstr("(null)", c); }
	if (!str[c])	{ return c; }
	return putstr(str, c + write(1, &str[c], 1));
}

int putnum(long num, int base)
{
	char *b = "0123456789abcdef";
	
	if (num < 0 && base == 10)
		return write(1, "-", 1) + putnum(num * -1, base);
	if (num < 0 && base == 16)
		return putnum((unsigned int)num, base);
	if (num/base == 0)
		return write(1, &b[num%base], 1);
	return putnum(num/base, base) + putnum(num % base, base);
}

int ptf(char *s, va_list args, int c, int n)
{
	if (!s[c])	{ return n; }
	if (s[c] == '%' && s[c + 1] == 's')
		return ptf(s, args, c + 2, n + putstr(va_arg(args, char *), 0));
	if (s[c] == '%' && s[c + 1] == 'd')
		return ptf(s, args, c + 2, n + putnum(va_arg(args, int), 10));
	if (s[c] == '%' && s[c + 1] == 'x')
		return ptf(s, args, c + 2, n + putnum(va_arg(args, int), 16));
	return ptf(s, args, c + 1, n + write(1, &s[c], 1));
}

int ft_printf(char *s, ...)
{
	va_list args;
	return va_start(args, s), va_end(args), ptf(s, args, 0, 0);
}