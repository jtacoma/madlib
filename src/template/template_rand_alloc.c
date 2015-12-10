#include <stdlib.h> // rand, malloc
#include <string.h> // strlen, strncpy

#include "madlib.h"

#include "template_impl.h"

char * madlib_template_rand_alloc
    ( struct madlib_template const * t
    )
{
    char const * strs [t->nchunks];
    unsigned strlens [t->nchunks];
    unsigned len = 0;

    for (int i=0; i<t->nchunks; ++i)
    {
        if (t->chunks[i].literal)
        {
            strs[i] = t->chunks[i].literal;
        }
        else
        {
            strs[i] = madlib_vocab_term (t->chunks[i].vocab_type, rand());
        }

        strlens[i] = strlen(strs[i]);
        len += strlens[i];
    }

    char * phrase = malloc (len+1);

    if (!phrase)
    {
        return NULL;
    }

    char * dst = phrase;

    for (int i=0; i<t->nchunks; ++i)
    {
        strncpy (dst, strs[i], strlens[i]);
        dst += strlens[i];
    }

    *dst = '\0';

    return phrase;
}
