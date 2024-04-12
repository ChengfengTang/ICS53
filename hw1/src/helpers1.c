#include "helpers1.h"
#include <stdio.h>
// Define all helper functions for hw1 in this file
#include <stdbool.h>
#include <ctype.h>
#include "hw1.h"
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
        if (newLine)
	  {
	    alreadyStoredTabs = 0; //reset count to 0
            while (temp == '#')
	      {
		alreadyStoredTabs++;
		temp = fgetc(input); // Move to the next character that's not a #
	      }
            if (temp == ' ' && alreadyStoredTabs == NUM)  // Check if it's the correct header level
	      {
		temp = fgetc(input); //Skip the space between # and beginning of text
                while (temp != '\n' && temp != -1)
		  {
                    printf("%c", temp);
                    temp = fgetc(input);
		  }
                printf("\n"); // print a newline after each header
	      }
            newLine = false; 
	  }
        if (temp == '\n') //if we are at the end of a line go through the # check starting next character
	  {
	    newLine = true;
	  }
        temp = fgetc(input);
    }
}

void printEmoji (FILE* input, int countMode)
{
  //printf("%d\n", countMode);
  int count = 0;
  bool newLine = false;
  char tempEmoji [1000];
  int index = 0;
  int temp = fgetc(input);
  int line = 0;
  int lineC = 0;
  int lineCount = 0;
  while (temp != -1)
    {
      if(temp == '\n')
	{
	  line++;
	  lineC = 0;
	}
      if(newLine)
	{
	  if(temp == ':')
	    {
	      if(index > 0)
		{

		  if(lineC == 0 && countMode == 1)
		    {
		      lineCount ++;
		      lineC = 1;
		    }
		  tempEmoji[index] = '\0';
		  printf(":%s:\n", tempEmoji);
		  //printf("%d", lineCount);
		}
	      newLine = false;
	      index = 0;
	    }
	  else if (islower(temp) || isdigit(temp) || temp == '_')
              {
	      
                tempEmoji[index] = temp;
		index ++;
              }
	  else
	    {
	      newLine = false;
	      index = 0;
	    }
	}
      else if (temp == ':') //if we are at the beginning of a :, start checking                            
	{
	  newLine = true;
	  index = 0;
	}
      temp = fgetc(input);
    }
  if(countMode == 1)
    {
      fprintf(stderr, "%d\n", lineCount);
    }
}

void printPattern (FILE* input, char* pattern, int countMode)
{
  //test
  //printf("The pattern is " COLOR_START "%s" COLOR_RESET "..\n", pattern);
  char temp [1000];
  int count = 0;
  while (fgets(temp,1000,input)!=NULL)
    {
      //printf("%s", temp);
      if(strstr(temp, pattern) == NULL)
	{
	  continue;
	}
      int i;
      for(i = 0; i < sizeof(temp) && temp[i] != '\0'; i++)
	{
	  if(temp[i] == pattern[0])
	    {
	      int match = 1;
	      int j;
	      for(j = 0; j < strlen(pattern); j++)
		{
		  if(temp[i+j] == '\0' || temp[i+j] != pattern[j])
		    {
		      match = 0;
		      break;
		    }
		}
	      if(match == 1)
		{
		  count ++;
		  printf( COLOR_START "%s" COLOR_RESET, pattern);
		  i += strlen(pattern)-1;
		  continue;
		}
	    }
	  printf("%c", temp[i]);
	}
    }
  
  if(countMode == 1)
    {
      fprintf(stderr, "%d\n", count);
    }
  
}

