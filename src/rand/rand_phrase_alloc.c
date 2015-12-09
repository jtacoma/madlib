#include "adjnoun.h"

#include <stdlib.h> // rand
#include <string.h> // strlen, strcpy

char *
adjnoun_rand_phrase_alloc (
        char delim,
        enum adjnoun_vocab_type const * types,
        unsigned ntypes)
{
    char const * terms [ntypes];
    unsigned lens [ntypes];
    unsigned len = 0;

    for (unsigned i=0; i<ntypes; ++i)
    {
        unsigned r = rand();
        terms[i] = adjnoun_vocab_term (types[i], r);
        lens[i] = strlen (terms[i]);
        len += lens[i];
        if (i) len += 1; // for delim
    }

    char * phrase = malloc (len+1);

    if (phrase == NULL)
    {
        return NULL; // see errno
    }

    char * p = phrase;

    for (unsigned i=0; i<ntypes; ++i)
    {
        if (i) *p++ = delim;
        strncpy (p, terms[i], lens[i]);
        p += lens[i];
    }
    
    *p = '\0';

    return phrase;
}
