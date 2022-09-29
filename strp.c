#include "str.h"
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>

size_t Str_getLength(const char *pcSrc) {
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

char *Str_copy(char *dest, const char *src) {
    char *piStart = dest;

    assert(dest != NULL);
    
    while(src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';

    return piStart;
}

char *Str_concat(char *dest, const char *src) {
    char *piStart; 
    
    assert(dest != NULL);
    
    piStart = dest;
    dest = dest + Str_getLength(dest);

    while(src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';

    return piStart;
}

int Str_compare(const char *s1, const char *s2) {
    
}

char *Str_search(const char *haystack, const char *needle);