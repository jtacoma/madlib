#ifndef MADLIB_H
#define MADLIB_H

enum madlib_vocab_type {
	madlib_vocab_type_ADJECTIVE,
	madlib_vocab_type_NOUN,
};

unsigned
madlib_vocab_len
    ( enum madlib_vocab_type type
    );

char const *
madlib_vocab_term
    ( enum madlib_vocab_type type
    , unsigned i
    );

void
madlib_rand_seed
    ();

char *
madlib_rand_phrase_alloc
    ( char delim
    , enum madlib_vocab_type const * types
    , unsigned ntypes
    );

struct madlib_template;

struct madlib_template *
madlib_template_parse_alloc
    ( char const * fmt
    );

void
madlib_template_free
    ( struct madlib_template * t
    );

char * madlib_template_rand_alloc
    ( struct madlib_template const * t
    );

#endif //MADLIB_H
