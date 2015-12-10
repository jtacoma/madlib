#include <stdlib.h>

#include "madlib.h"

#include "template_impl.h"

void
madlib_template_free
    ( struct madlib_template * t
    )
{
    free (t->buffer);
    free (t);
}
