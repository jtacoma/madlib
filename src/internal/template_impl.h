#ifndef MADLIB_TEMPLATE_IMPL_H
#define MADLIB_TEMPLATE_IMPL_H

#include "madlib.h"

struct madlib_template_chunk
{
    char const * literal;
    enum madlib_vocab_type vocab_type; // if literal == NULL
};

struct madlib_template
{
    char * buffer;
    unsigned nchunks;
    struct madlib_template_chunk chunks [];
};

#endif //MADLIB_TEMPLATE_IMPL_H
