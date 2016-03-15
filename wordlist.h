#ifndef LIBWALLY_WORDLIST_H
#define LIBWALLY_WORDLIST_H

#include <stdint.h>
#include <stdlib.h>

/**
 * struct words- structure representing a parsed list of words
 */
struct words {
    /* Number of words in the list */
    size_t len;
    /* The underlying string */
    const char* str;
   /* Pointers to the individual words */
    const char **indices;
 };

/**
 * wordlist_init - Initialise a words structure.
 * @text: List of words to initialise from, split by single @sep characters
 *         and terminated by NUL. Must be UTF-8 encoded, sorted, and contain
 *         a power of two number of words.
 * @sep: The Non-NUL ASCII character separating words in @text.
 *
 * The returned structure contains a copy of @text.
 */
struct words *wordlist_init(const char *text, char sep);

/**
 * wordlist_lookup_word - Find a word in a wordlist.
 * @w: Parsed list of words to look up in.
 * @word: The word to look up.
 *
 * Returns 0 if not found, index + 1 otherwise.
 */
size_t wordlist_lookup_word(const struct words *w, const char *word);

/**
 * wordlist_lookup_index - Return the Nth word in a wordlist.
 * @w: Parsed list of words to look up in.
 * @index: The index to look up.
 *
 * Returns NULL if not found, the word otherwise.
 */
const char* wordlist_lookup_index(const struct words *w, size_t index);

/**
 * wordlist_free - Free a words structure.
 * @w: structure to free.
 */
void wordlist_free(struct words *w);

#endif /* LIBWALLY_WORDLIST_H */
