#include "madlib.h"

#include <stdlib.h>
#include <stdio.h>

static const char * default_fmt = "%a %n";

int main (int argc, char const * const * argv)
{
    madlib_rand_seed ();

    if (argc > 2)
    {
        fprintf (stderr, "usage: madlib [FORMAT]\n");
        return -1;
    }

    char const * fmt = default_fmt;

    if (argc == 2)
    {
        fmt = argv[1];
    }

    struct madlib_template * t = madlib_template_parse_alloc (fmt);

    if (!t)
    {
        perror ("madlib_template_parse_alloc");
        return -1;
    }

    char * phrase = madlib_template_rand_alloc (t);

    if (!phrase)
    {
        perror ("madlib_template_rand_alloc");
        return -1;
    }

    madlib_template_free (t); t = NULL;

    printf ("%s\n", phrase);

    free (phrase); phrase = NULL;
}
