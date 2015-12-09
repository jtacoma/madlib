#include "adjnoun.h"

#include <stdlib.h>
#include <stdio.h>

int main ()
{
    adjnoun_rand_seed ();

    enum adjnoun_vocab_type phrase_types [] = {
        adjnoun_vocab_type_ADJECTIVE,
        adjnoun_vocab_type_NOUN,
    };

    char * phrase = adjnoun_rand_phrase_alloc (
                        ' ',
                        phrase_types,
                        sizeof (phrase_types) / sizeof (*phrase_types));

    if (!phrase)
    {
        perror ("adjnoun_rand_phrase_alloc");
        return -1;
    }

    printf ("phrase: %s\n", phrase);

    free (phrase);
}
