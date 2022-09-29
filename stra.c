#include "str.h"
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>

size_t Str_getLength(const char pcSrc[]) {
    size_t uLength = 0;
    assert(pcSrc != NULL);
    while (pcSrc[uLength] != '\0') {
        uLength++;
    }
   return uLength;
}

char *Str_copy(char pcDest[], const char pcSrc[]) { 
    size_t i = 0;
    
    assert(pcDest != NULL);

    while(pcSrc[i] != '\0') {
        pcDest[i] = pcSrc[i];
        i++;
    }
    pcDest[i] = '\0';

    return pcDest;
}

char *Str_concat(char dest[], const char src[]) {
    size_t i = 0;
    size_t destLength = Str_getLength(dest);
    
    assert(src != NULL);
    assert(dest != NULL);

    while(src[i] != '\0') {
        dest[i + destLength] = src[i];
        i++;
    }
    dest[i + destLength] = '\0';

    return dest;
}

int Str_compare(const char s1[], const char s2[]) {
    size_t i = 0;

    while(s1[i] == s2[i]) {
        if(s1[i] == '\0' || s2[i] == '\0') {
            break;
        }
        i++;
    }

    return s1[i] - s2[i];
}

int Needle_cmp(const char haystack[], const char needle[]) {
    size_t i = 0;

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
    
    while(haystack[i] != '\0') {
        
        if(haystack[i] == needle[0] && Needle_cmp(&haystack[i], needle)) {
            return (char*) &haystack[i];
        }
        i++;
    }

    return NULL;
}




