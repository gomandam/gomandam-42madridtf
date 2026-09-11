#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int w, h, k, x = 1, y = 1, p = 0, i;
    char ch, *b, *t;

    if ( ac ^ 4 || !(b = calloc((w = atoi(av[1]) + 2) * (h = atoi(av[2]) + 2), 1)))
        return 1;

    for (; read(0, &ch, 1) > 0;)
        if (
             (
                p ^= ch == 'x',
                y += (ch == 's') - (ch == 'w'),
                x += (ch == 'd') - (ch == 'a')
	     ),
            		p &&
            		x > 0 &&
            		x < w - 1 &&
            		y > 0 &&
            		y < h - 1
           )
     b[y * w + x] = 1;

    for (k = atoi(av[3]); k--; free(b), b = t)
        if (!(t = calloc(w * h, 1)))
            return 1;
        else
            for (y = 1; y < h - 1; y++)
                for (x = 1; x < w - 1; x++)
                    i = y * w + x,
                    p =
                        b[i - w - 1] +
                        b[i - w] +
                        b[i - w + 1] +
                        b[i - 1] +
                        b[i + 1] +
                        b[i + w - 1] +
                        b[i + w] +
                        b[i + w + 1],
                    t[i] = p == 3 || (p == 2 && b[i]);

    for (y = 1; y < h - 1; y++, putchar(10))
        for (x = 1; x < w - 1; x++)
            putchar(b[y * w + x] * 47 + 32);

    free(b);
}
