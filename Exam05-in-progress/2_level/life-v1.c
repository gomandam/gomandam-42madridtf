#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_board { int w, h; char *c; } t_board;

static int nb(t_board *b, int x, int y)
{
	int dx, dy, n = 0;
	for (dy = -1; dy <= 1; dy++)
		for (dx = -1; dx <= 1; dx++)
			if ((dx || dy) && x + dx >= 0 && x + dx < b->w && y + dy >= 0 && y + dy < b->h)
				n += b->c[(y + dy) * b->w + (x + dx)];
	return n;
}

int main(int ac, char **av)
{
	t_board b, t;
	int i, k, x = 0, y = 0, p = 0, n;
	char ch;

	if (ac != 4) return 1;
	b.w = atoi(av[1]); b.h = atoi(av[2]); k = atoi(av[3]);
	if (b.w < 1 || b.h < 1 || k < 0 || (long)b.w * b.h > 2000000000L) return 1;
	b.c = (char *)calloc((size_t)b.w * b.h, 1);
	if (!b.c) return 1;

	while (read(0, &ch, 1) > 0)
	{
		if (ch == 'x') p = !p;
		y += (ch == 's') - (ch == 'w');
		x += (ch == 'd') - (ch == 'a');
		if (p && x >= 0 && x < b.w && y >= 0 && y < b.h) b.c[y * b.w + x] = 1;
	}
	while (k-- > 0)
	{
		t.c = (char *)calloc((size_t)b.w * b.h, 1);
		if (!t.c) return (free(b.c), 1);
		for (i = 0; i < b.w * b.h; i++)
		{
			n = nb(&b, i % b.w, i / b.w);
			t.c[i] = (n == 3 || (n == 2 && b.c[i]));
		}
		free(b.c); b.c = t.c;
	}
	for (i = 0; i < b.w * b.h; i++) { putchar(b.c[i] ? 'O' : ' '); if (i % b.w == b.w - 1) putchar('\n'); }
	free(b.c);
	return 0;
}
