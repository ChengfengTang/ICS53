#include "hw0.h"

int printArg(char* arg_str, int pos);
int main (int argc, char *argv[])
{
  int sum = 0;
  for(int i = 0; i < argc; i++)
    {
      int len = printArg(argv[i],i);
      if (i > 0)
	{
	  sum += len;
	}
    }
  printf("Total characters: %d\n", sum);
  return 0;
}
