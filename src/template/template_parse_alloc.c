#include <errno.h>
#include <stdlib.h> // malloc, free
#include <string.h> // strlen

#include "madlib.h"

#include "template_impl.h"

struct madlib_template *
madlib_template_parse_alloc (
    char const * fmt)
{
    unsigned const fmtlen = strlen (fmt);

    // The highest possible density of tokens in the format string can be
    // achieved by interspersing single-character literals with percent-encoded
    // terms e.g. "_%a_%a_%a".  So divide fmtlen by 3 and multiply by 2 to find
    // a maximum value for nchunks.  Don't forget to round up!
    unsigned maxchunks = fmtlen/3 * 2 + ((fmtlen%3) ? 2 : 0);

    struct madlib_template * t
        = malloc (sizeof (*t) + maxchunks * sizeof(*t->chunks));

    if (!t)
    {
        return NULL; // see errno
    }

    t->nchunks = 0;
    t->buffer = calloc (fmtlen+1, 1);

    if (!t->buffer)
    {
        free (t);
        return NULL; // see errno
    }

    char * w = t->buffer;

    for (char const * r=fmt; *r!='\0'; ++r)
    {
        if (*r=='%')
        {
            switch (*++r)
            {
                case '%':
                    if (t->nchunks==0
                        || t->chunks[t->nchunks-1].literal == NULL)
                    {
                        t->chunks[t->nchunks++].literal = w;
                    }
                    *w++ = '%';
                    break;
                case 'a':
                    *w++ = '\0';
                    t->chunks[t->nchunks].literal = NULL;
                    t->chunks[t->nchunks].vocab_type
                        = madlib_vocab_type_ADJECTIVE;
                    t->nchunks += 1;
                    break;
                case 'n':
                    *w++ = '\0';
                    t->chunks[t->nchunks].literal = NULL;
                    t->chunks[t->nchunks].vocab_type
                        = madlib_vocab_type_NOUN;
                    t->nchunks += 1;
                    break;
                default:
                    errno = EINVAL;
                    free (t->buffer);
                    free (t);
                    return NULL;
            }
        }
        else
        {
            if (t->nchunks==0 || t->chunks[t->nchunks-1].literal == NULL)
            {
                t->chunks[t->nchunks++].literal = w;
            }
            *w++ = *r;
        }
    }

    return t;
}
