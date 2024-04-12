#include "hw1.h"
#include <stdio.h>
#include <string.h>

// You may define any helper functions you want. Place them in helpers.c/.h
// Main program
int main(int argc, char *argv[]) {

    // Insert your hw1 code here
  if (argc <= 1) //empty, no arguments after ./bin/53markdown
    {
      return 1;
    }
  int countMode = 0;
  int i; //counter
  char option;
  if(strcmp(argv[1], "-h") == 0)
    {
      if (argc > 2)
	{
	  fprintf(stderr,"%s", USAGE);
	  return 1;
	}
      option = 'h';
    }
  else if (strcmp(argv[1], "-H") == 0)
    {
      option = 'H';
      if (argc <= 2 || atoi(argv[2]) > 6  || atoi(argv[2]) < 1)
	{
	  fprintf(stderr, "%s",USAGE);
	  return 1;
	}
    }
  else if (strcmp(argv[1], "-E") == 0)
    {
      if (argc == 2)
	{
	  option = 'E';
	}
      else if (argc == 3)
	{
	  if(strcmp(argv[2], "-C") == 0)
	    {
	      option = 'E';
	      countMode = 1;
	    }
	  else
	    {
	      fprintf(stderr, "%s", USAGE);
	      return 1;
	    }
	}
      else
	{
	  fprintf(stderr, "%s", USAGE);
          return 1;
	}
    }
  else if (strcmp(argv[1], "-K") == 0)
    {
      if (argc == 3)
        {
	  option = 'K';
	}
      else  if (argc == 4)
        {
          if(strcmp(argv[3], "-C") == 0)
            {
              option = 'K';
              countMode = 1;
            }
          else
            {
              fprintf(stderr, "%s", USAGE);
              return 1;
            }
        }
      else
        {
          fprintf(stderr, "%s", USAGE);
          return 1;
        }
    }
  else if (strcmp(argv[1], "-O") == 0)
    {
      if (argc > 2)
        {
          fprintf(stderr, "%s", USAGE);
          return 1;
        }
      option = 'O';
    }
  else
    {
      fprintf(stderr, "%s", USAGE);
      return 1;
    }

  int ch = fgetc(stdin);
  if(ch == -1)
    {
      return 2;
    }
  ungetc(ch, stdin);
  
  //test stuff comment out later
  /*for (i = 0; i < argc; i++)
    {
      printf("argv[%d]: %s\n",i,argv[i]); //printing the entire argument
      }*/
  //printf("%c\n", option);

  if (option == 'h')
    {
      printf("%s", USAGE);
    }
  else if(option == 'H')
    {
      printLVLNum(stdin, atoi(argv[2]));
      return 0;
    }
  else if(option == 'O')
    {
      printOutline(stdin);      
    }
  else if (option == 'E')
    {
      printEmoji(stdin, countMode);
    }
  else if (option == 'K')
    {
      printPattern(stdin, argv[2], countMode);
    }
    return 0;
}
