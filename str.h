/*--------------------------------------------------------------------*/
/* str.h                                                              */
/* Author: Jacob Penstein                                             */
/*--------------------------------------------------------------------*/

#ifndef STR_INCLUDED
#define STR_INCLUDED

#include <stdlib.h>

/* Returns length of string str. Returns error if str point to NULL. */
size_t Str_getLength(const char *str);

/* Copies string src to string dest and returns pointer to dest. 
Returns error if dest and src  point to null */
char *Str_copy(char *dest, const char *src);

/* Appends string src to the end of dest and returns pointer to dest.*/
char *Str_concat(char *dest, const char *src);

/* Compares strings s1 and s2. Returns 0 if they match or the difference 
of the first set of characters if they don't. Returns error if s1 and s2
point to null */
int Str_compare(const char *s1, const char *s2);

/* Finds the first occurance of string needle in string haystack. 
Returns pointer to the location of the occurance, or NULL if there is
none. If needle is 0 characters long, returns pointer to the first
char of haystack. Returns error if needle and haystack point to Null. */ 
char *Str_search(const char *haystack, const char *needle);

#endif
