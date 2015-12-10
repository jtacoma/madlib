Madlib
======

A command-line tool to randomly fill in custom madlibs to create random yet
plausible phrases.

Motivation
----------

I started this project as an experiment in code organization, particularly in
defining only one function per C file.
Since I didn't have anything else in mind, I wasn't sure what to call the
project.
The result is a tool that can generate random names for new projects when
they're still too poorly defined to be given meaningful names.

Format Strings
--------------

Madlib uses `%` as a special character in its format strings.

 * `%a` means *adjective*
 * `%n` means *noun*
 * `%%` means `%`

The default format string is `%a %n`

    $ madlib
    uniform rendering
    $ madlib '%a %n, %n!'
    lively capsule, panel!
    $ madlib '%%a'
    %a

Generating Word Lists
---------------------

Given a WordNet index file on input, sort words by number of senses (to
approximate familiarity and frequency) then print the first 500.

    grep '^[a-z]' \
    | awk '{ if (4<length($1) && length($1)<10) print $3 " " $1 }' \
    | sort -rn \
    | head -n 500 \
    | cut -d' ' -f 2

This was used to determine the adjectives and nouns currently hard-coded in
`src/vocab/vocab.c`.

Building
--------

If your default C compiler supports the C11 standard, there's nothing to it:

    make

Otherwise, you'll have to specify a compiler that works:

    make CC=~/bin/clang-3.8

