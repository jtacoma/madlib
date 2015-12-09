#ifndef ADJNOUN
#define ADJNOUN

enum adjnoun_vocab_type {
	adjnoun_vocab_type_ADJECTIVE,
	adjnoun_vocab_type_NOUN,
};

unsigned
adjnoun_vocab_len
    ( enum adjnoun_vocab_type type
    );

char const *
adjnoun_vocab_term
    ( enum adjnoun_vocab_type type
    , unsigned i
    );

void
adjnoun_rand_seed
    ();

char *
adjnoun_rand_phrase_alloc
    ( char delim
    , enum adjnoun_vocab_type const * types
    , unsigned ntypes
    );

#endif //ADJNOUN
