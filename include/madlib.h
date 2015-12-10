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
 * FORA PARTICULAR PURPOSE.  See the Affero GNU General Public License for more
 * details.
 *
 * You should have received a copy of the Affero GNU General Public License
 * along with Madlib.  If not, see <http://www.gnu.org/licenses/>.
 */

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
