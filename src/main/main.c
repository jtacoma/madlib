#include "madlib.h"

#include <stdlib.h>
#include <stdio.h>

int main ()
{
    madlib_rand_seed ();

    enum madlib_vocab_type phrase_types [] = {
        madlib_vocab_type_ADJECTIVE,
        madlib_vocab_type_NOUN,
    };

    char * phrase = madlib_rand_phrase_alloc (
                        ' ',
                        phrase_types,
                        sizeof (phrase_types) / sizeof (*phrase_types));

    if (!phrase)
    {
        perror ("madlib_rand_phrase_alloc");
        return -1;
    }

    printf ("phrase: %s\n", phrase);

    free (phrase);
}
