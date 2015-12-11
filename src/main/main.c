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

#include "madlib.h"

#include <stdlib.h>
#include <stdio.h>

void madlib_rand_seed ();

static const char * default_fmt = "%a %n";

int
main
    ( int argc
    , const char * const * argv
    )
{
    if (argc > 2)
    {
        fprintf (stderr, "usage: madlib [FORMAT]\n");
        return -1;
    }

    const char * fmt = default_fmt;

    if (argc == 2)
    {
        fmt = argv[1];
    }

    struct madlib_template * t = madlib_template_alloc (fmt);

    if (!t)
    {
        perror ("madlib_template_parse_alloc");
        return -1;
    }

    madlib_rand_seed ();

    char * phrase = madlib_template_rand_alloc (t);

    madlib_template_free (t);
    t = NULL;

    if (!phrase)
    {
        perror ("madlib_template_rand_alloc");
        free (phrase);
        phrase = NULL;
        return -1;
    }

    printf ("%s\n", phrase);

    free (phrase);
    phrase = NULL;
}
