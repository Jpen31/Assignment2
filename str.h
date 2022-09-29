#ifndef STR_INCLUDED
#define STR_INCLUDED

#include <stdlib.h>

size_t Str_getLength(const char *s);

char *Str_copy(char *restrict dest, const char *restrict src);

char *Str_concat(char *restrict dest, const char *restrict src);

int Str_compare(const char *s1, const char *s2);

char *Str_search(const char *haystack, const char *needle);

#endif
