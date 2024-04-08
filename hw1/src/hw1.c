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
  int i; //counter
  char option;
  if(strcmp(argv[1], "-h") == 0)
    {
      option = 'h';
    }
  else if (strcmp(argv[1], "-H") == 0)
    {
      option = 'H';
      if (argc <= 2 || atoi(argv[2]) == '0')
	{
	  printf("%s",USAGE);
	  return 1;
	}
    }
  else if (strcmp(argv[1], "-E") == 0)
    {
      option = 'E';
    }
  else if (strcmp(argv[1], "-K") == 0)
    {
      option = 'K';
    }
  else if (strcmp(argv[1], "-O") == 0)
    {
      option = 'O';
    }
  else if (strcmp(argv[1], "-C") == 0)
    {
      option = 'C';
    }
  else
    {
      printf("%s", USAGE);
      return 1;
    }
  for (i = 0; i < argc; i++)
    {
      printf("argv[%d]: %s\n",i,argv[i]); //printing the entire argument
    }
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
  
         
    return 0;
}
