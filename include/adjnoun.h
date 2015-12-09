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
adjnoun_vocab_item
    ( enum adjnoun_vocab_type type
    , unsigned i
    );

#endif //ADJNOUN
