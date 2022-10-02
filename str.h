#ifndef STR_INCLUDED
#define STR_INCLUDED

#include <stdlib.h>

/* Returns length of string str. */
size_t Str_getLength(const char *str);

/* Copies string src to string dest and returns pointer to dest. */
char *Str_copy(char *dest, const char *src);

/* Appends string src to the end of dest and returns pointer to dest.*/
char *Str_concat(char *dest, const char *src);

/* Compares strings s1 and s2. Returns 0 if they match or the difference 
of the first set of charactors if they don't.*/
int Str_compare(const char *s1, const char *s2);

/* FInds the first occurance of string needle in string haystack. 
Returns pointer to the location of the occurance, or NULL if there is
none. */ 
char *Str_search(const char *haystack, const char *needle);

#endif
