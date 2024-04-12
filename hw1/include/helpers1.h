// Below is a headerguard. It uses MACROS to prevent circular inclusion of this file when compiling
# ifndef HW1_HELPERS
# define HW1_HELPERS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare all helper functions for hw1 here
//void printUsageStatement();
void printOutline(FILE * input);
void printLVLNum(FILE * input, int NUM);
void printEmoji(FILE * input, int countMode);
void printPattern(FILE * input, char* pattern, int countMode);
# endif
