#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_board { int w, h; char *c; } t_board;

static int nb(t_board *b, int i)
{
	return b->c[i-b->w-1]+b->c[i-b->w]+b->c[i-b->w+1]
		+b->c[i-1]+b->c[i+1]
		+b->c[i+b->w-1]+b->c[i+b->w]+b->c[i+b->w+1];
}

int main(int ac, char **av)
{
	t_board b, t;
	int i, k, x = 1, y = 1, p = 0, n;
	char ch;

	if (ac != 4)
		return 1;
	b.w = atoi(av[1]) + 2;
	b.h = atoi(av[2]) + 2;
	k = atoi(av[3]);
	if (b.w < 3 || b.h < 3 || k < 0)
		return 1;
	if (!(b.c = calloc(b.w * b.h, 1)))
		return 1;

	for (; read(0, &ch, 1) > 0;)
	{
		if (ch == 'x')
			p = !p;
		y += ch == 's' ? 1 : ch == 'w' ? -1 : 0;
		x += ch == 'd' ? 1 : ch == 'a' ? -1 : 0;
		if (p && x > 0 && x < b.w - 1 && y > 0 && y < b.h - 1)
			b.c[y * b.w + x] = 1;
	}
	for (; k--;)
	{
		if (!(t.c = calloc(b.w * b.h, 1)))
			return free(b.c), 1;
		for (y = 1; y < b.h - 1; y++)
			for (x = 1; x < b.w - 1; x++)
			{
				i = y * b.w + x;
				n = nb(&b, i);
				t.c[i] = n == 3 || (n == 2 && b.c[i]);
			}
		free(b.c);
		b.c = t.c;
	}
	for (y = 1; y < b.h - 1; y++)
	{
		for (x = 1; x < b.w - 1; x++)
			putchar(b.c[y * b.w + x] ? 'O' : ' ');
		putchar('\n');
	}
	free(b.c);
}
