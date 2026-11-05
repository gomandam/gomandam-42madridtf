#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	w, h, k, i, x = 1, y = 1, p = 0;
	char	ch, *b, *t;

	/* Check argument count. */
	if (ac != 4)
		return 1;

	/* Calculate board dimensions. */
	w = atoi(av[1]) + 2;
	h = atoi(av[2]) + 2;

	/* Allocate the initial board. */
	b = calloc(w * h, 1);
	if (b == NULL)
		return 1;

	/*
	 * Read input one character at a time.
	 * Update position/state, and mark the board when the conditions pass.
	 */
	for (; read(0, &ch, 1) > 0;)
		if (
			(
				p ^= (ch == 'x'),
				y += (ch == 's') - (ch == 'w'),
				x += (ch == 'd') - (ch == 'a')
			),
			p &&
			x > 0 &&
			y > 0 &&
			x < w - 1 &&
			y < h - 1
		   )
			b[y * w + x] = 1;

	/*
	 * Run the requested number of generations.
	 * Each generation allocates a new board, computes every cell from
	 * its eight neighbors, then frees the old board and swaps in the new one.
	 */
	for (k = atoi(av[3]); k--; free(b), b = t)
		if ((t = calloc(w * h, 1)) == NULL)
			return 1;
		else
			for (y = 1; y < h - 1; y++)
				for (x = 1; x < w - 1; x++)
					i = y * w + x,
					p = b[i - w - 1] + b[i - w] + b[i - w + 1] +
						b[i - 1]     + b[i + 1] +
						b[i + w - 1] + b[i + w] + b[i + w + 1],
					t[i] = p == 3 || (p == 2 && b[i]);

	/*
	 * Print the board.
	 * The outer loop visits rows; the inner loop prints each cell in a row.
	 */
	for (y = 1; y < h - 1; y++, putchar('\n'))
		for (x = 1; x < w - 1; x++)
			putchar(b[y * w + x] * 47 + 32);

	/* Free the final board then exit. */
	free(b);
	return 0;
}
