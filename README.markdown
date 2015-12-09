adjnoun
=======

Given a WordNet index file on input, sort words by number of senses (to
approximate familiarity and frequency) then print the first 500.

    grep '^[a-z]' \
    | awk '{ if (4<length($1) && length($1)<10) print $3 " " $1 }' \
    | sort -rn \
    | head -n 500 \
    | cut -d' ' -f 2

Do this for `index.adj` and `index.noun` from the WordNet 3.0 or 3.1 database
files, producing `adjectives.txt` and `nouns.txt`.

