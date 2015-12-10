/* Copyright 2015 Joshua Tacoma
 *
 * This file is part of Madlib.
 *
 * Madlib is free software: you can redistribute it and/or modify it under the
 * terms of the Affero GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * Madlib is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the Affero GNU General Public License for more
 * details.
 *
 * You should have received a copy of the Affero GNU General Public License
 * along with Madlib.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <errno.h>
#include <stdlib.h> // calloc, free, malloc
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
