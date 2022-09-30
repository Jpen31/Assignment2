/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: ???                                                        */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo)
{
    size_t replacements = 0;
    char *pcTicker;

    if(Str_getLength(pcFrom) == 0) {
        printf("%s", pcLine);
        return 0;
    }
    
    pcTicker = (*char) pcLine;
    while(*pcTicker != '\0') {
        char *nextInstance;
        nextInstance = Str_search(pcTicker, pcFrom);

        if(nextInstance == NULL) {
            printf("%s", pcTicker);
            break;
        }
        else {
            replacements++;
            while(pcTicker != nextInstance) {
                putchar(*pcTicker);
                pcTicker++;
            }
            printf("%s", pcTo);
        }
        pcTicker++;
    }
    
    return replacements;

}

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3};

   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   char *pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

    while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL) {
        if(argc != 3) {
            fprintf(stderr, "argc does not equal 3.\n");
            return EXIT_FAILURE;
        }
        if(Str_getLength(argv[1]) == 0) {
            char c;
            while(c = getchar() != EOF) {
                putchar(c);
            }
            fprintf(stderr, "0 replacements were made.\n");
            return 0;
        }
        else {
            char pcLine[SIZE_MAX];
            char c;
            size_t replacements;
            
            while(c = getchar() != EOF) {
                *pcLine = c;
                pcLine++;
            }

            replacements = replaceAndWrite(pcLine, argv[1], argv[2]);
            fprintf(stderr, "%zu replacements were made.\n", replacements);

        }
    }

   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
