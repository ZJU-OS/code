/* The contents of this file are derived from musl libc.
 *
 * musl libc is licensed under the standard MIT license.
 * See https://git.musl-libc.org/cgit/musl/ for more information.
 */

#include <stdlib.h>
#include <stdint.h>

static uint64_t seed;

void srand(unsigned int s)
{
	seed = s - 1;
}

int rand(void)
{
	seed = 6364136223846793005ULL * seed + 1;
	return seed >> 33;
}
