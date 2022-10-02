/*--------------------------------------------------------------------*/
/* strp.c                                                             */
/* Author: Jacob Penstein                                             */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>

size_t Str_getLength(const char *str) {
   const char *pcEnd;
   
   assert(str != NULL);
   
   pcEnd = str;
   while (*pcEnd != '\0') {
      pcEnd++;
   }

   /* returns size of str */
   return (size_t)(pcEnd - str);
}

char *Str_copy(char *dest, const char *src) {
    char *piStart = dest;

    assert(src != NULL);
    assert(dest != NULL);
    
    while(*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0'; /* adds null byte to end of string */

    return piStart;
}

char *Str_concat(char *dest, const char *src) {
    char *pcStart; 
    
    assert(src != NULL);
    assert(dest != NULL);

    pcStart = dest;
    dest = dest + Str_getLength(dest);

    while(*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0'; /* adds null byte to end of string */

    return pcStart;
}

int Str_compare(const char *s1, const char *s2) {
    assert(s1 != NULL);
    assert(s2 != NULL);
    
    /* finds first instance of a non-matching character or null byte*/
    while(*s1 == *s2) {
        if(*s1 == '\0' || *s2 == '\0') {
            break;
        }
        s1++;
        s2++;
    }

    return (int) *s1 - (int) *s2;
}

/* If string needle occurs at the beginning of string haystack, 
returns 1. Otherwise returns 0. */
static int Needle_cmp(const char *haystack, const char *needle) {
    assert(haystack != NULL);
    assert(needle != NULL);
    
    while(*needle != '\0') {
        if (*needle != *haystack) {
            return 0;
        }

        needle++;
        haystack++;
    }

    return 1;    
}

char *Str_search(const char *haystack, const char *needle) {
    assert(haystack != NULL);
    assert(needle != NULL);
    
    /* returns pointer to haystack if needle is 0 characters long */
    if(*needle == '\0') {
        return (char*) haystack;
    }
    
     /* if needle is found in haystack, return reference*/
    while(*haystack != '\0') {
        if(*haystack == *needle) {
            if(Needle_cmp(haystack, needle)) {
                return (char*) haystack;
            }
        }
        haystack++;
    }

    /* if needle is not found in haystack, return NULL */
    return NULL;
}