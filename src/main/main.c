#include "adjnoun.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main () {
	struct timespec ts;
	timespec_get (&ts, TIME_UTC);
	srand (ts.tv_sec + ts.tv_nsec);
	int ai = rand() % adjnoun_vocab_len (adjnoun_vocab_type_ADJECTIVE);
	char const * a = adjnoun_vocab_item (adjnoun_vocab_type_ADJECTIVE, ai);
	int ni = rand() % adjnoun_vocab_len (adjnoun_vocab_type_NOUN);
	char const * n = adjnoun_vocab_item (adjnoun_vocab_type_NOUN, ni);
	printf ("%s %s\n", a, n);
}
