/*--------------------------------------------------------------------*/
/* stra.c                                                             */
/* Author: Jacob Penstein                                             */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>

size_t Str_getLength(const char str[]) {
    size_t uLength = 0;

    assert(str != NULL);

    while (str[uLength] != '\0') {
        uLength++;
    }

    return uLength;
}

char *Str_copy(char dest[], const char src[]) { 
    size_t i = 0;
    
    assert(src != NULL);
    assert(dest != NULL);

    while(src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; /* adds null byte to end of string */

    return dest;
}

char *Str_concat(char dest[], const char src[]) {
    size_t i = 0; /* incrementor */
    size_t destLength = Str_getLength(dest);
    
    assert(dest != NULL);
    assert(src != NULL);


    while(src[i] != '\0') {
        dest[i + destLength] = src[i];
        i++;
    }
    dest[i + destLength] = '\0'; /* adds null byte to end of string */

    return dest;
}

int Str_compare(const char s1[], const char s2[]) {
    size_t i = 0;

    assert(s1 != NULL);
    assert(s2 != NULL);

    /* finds first instance of a non-matching character or null byte*/
    while(s1[i] == s2[i]) {
        if(s1[i] == '\0' || s2[i] == '\0') {
            break;
        }
        i++;
    }

    /* returns difference of first non-matching characters or 0 */
    return (int) s1[i] - (int) s2[i];
}

/* If string needle occurs at the beginning of string haystack, 
returns 1. Otherwise returns 0. Returns error if needle or haystack
point to null */
static int Str_needle_cmp(const char haystack[], const char needle[]) {
    size_t i = 0;

    assert(haystack != NULL);
    assert(needle != NULL);

    while(needle[i] != '\0') {
        if (needle[i] != haystack[i]) {
            return 0;
        }

        i++;
    }

    return 1;    
}

char *Str_search(const char haystack[], const char needle[]) {
    size_t i = 0;
    
    assert(haystack != NULL);
    assert(needle != NULL);

    /* returns pointer to haystack if needle is 0 characters long */
    if(*needle == '\0') {
        return (char*) haystack;
    }
    

    while(haystack[i] != '\0') {
        
        /* if needle is found in haystack, return reference*/
        if(haystack[i] == needle[0]) {
            if(Str_needle_cmp(&haystack[i], needle)) {
                return (char*) &haystack[i];
            }
        }

        i++;
    }

    /* if needle is not found in haystack, return NULL */
    return NULL;
}




