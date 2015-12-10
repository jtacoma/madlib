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

#include <stdlib.h> // malloc, rand
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
