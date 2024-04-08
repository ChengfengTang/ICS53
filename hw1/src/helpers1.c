#include "helpers1.h"
#include <stdio.h>
// Define all helper functions for hw1 in this file
#include <stdbool.h>

/*void printUsageStatement()
{
  printf("53markdown [option] ... \n");
  printf("  -h            Print the current message.\n"); 
  printf("  -O            Print an outline for the document based on the markdown heading.\n");
  printf("  -H [NUM]      Print level NUM headings, one per line. NUM must be [1-6].\n");
  printf("  -E            Print all classic markup emoji occurrences within the markdown file, 1 per line.\n");
  printf("  -K [PATTERN]  Print all lines of the markdown file which contain one or more instances of PATTERN.\n");
  printf("  -C            Signifies count mode. This option is only used with -E and -K options. With -E, it prints the number of lines of the input stream that contribute to the requested output to the standard error stream (STDERR). With -K, it prints the number of occurrences of the PATTERN to the standard error (STDERR)\n");
}
*/

void printOutline(FILE* input)
{
  int temp = fgetc(input);
  bool newLine = true;
  int alreadyStoredTabs;
  while(temp != -1)
    {
      if(newLine == true)
	{
	  if(temp == ' ') //if the line starts with space, it doesn't matter it is not a header
	    {
	      newLine = false;
	      temp = fgetc(input);
	      continue;
	    }
	  alreadyStoredTabs = 0;
	  while(temp == '#') 
	    {
	       alreadyStoredTabs += 1;
	       temp = fgetc(input); 
	     }
	  newLine = false;
	  if(alreadyStoredTabs <= 6 && alreadyStoredTabs > 0)
	    {
	      if (temp == ' ')
		{
		  temp = fgetc(input);
		  if (temp == -1)
		    {
		      break;
		    }
		}
	      //print these tabs
	      int i;
	      for(i = 0; i < alreadyStoredTabs -1; i++)
		{
		  printf("\t");
		}
	    }
	  else
	    {
	      continue;
	    }
	}
      //time for a newLine
      if(temp == '\n')
	{
	  if (alreadyStoredTabs > 0 && alreadyStoredTabs <= 6)
	    {
	      printf("\n");
	    }
	  newLine = true;
	}
      else if (!newLine && alreadyStoredTabs > 0 && alreadyStoredTabs <= 6)
	{
	  printf("%c", temp);
	}
      temp = fgetc(input);
    }
}


void printLVLNum(FILE * input, int NUM)
{
  int temp = fgetc(input);
  bool newLine = true;
  int alreadyStoredTabs = 0;
  while (temp != -1)
    {
        if (newLine) {
            alreadyStoredTabs = 0; // Reset hash count at the start of each new line
            while (temp == '#') { // Count '#' characters
                alreadyStoredTabs++;
                temp = fgetc(input); // Move to the next character
            }
            if (temp == ' ' && alreadyStoredTabs == NUM) { // Check if it's the correct header level
                temp = fgetc(input); // Skip the space before starting to print
                while (temp != '\n' && temp != EOF) { // Print until the end of the line
                    printf("%c", temp);
                    temp = fgetc(input);
                }
                printf("\n"); // Make sure to print a newline after each header
            }
            newLine = false; // Now we're no longer at the start of a line
        }
        if (temp == '\n') { // If we encounter a newline, reset to new line status
            newLine = true;
        }
        temp = fgetc(input); // Read the next character
    }
}
