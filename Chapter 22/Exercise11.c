
/*
The fcopy.c program has one minor flaw: it doesn't check for errors as it's
writing to the destination file. Errors during writing are rare, but do occasionally
occur (the disk might become full, for example). Show how to add the missing
error check to the program, assuming that we want it to display a message and
terminate immediately if an error occurs.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *source_fp, *dest_fp;
  int ch;

  if(argc != 3)
  {
    fprintf(stderr, "usage: fcopy source dest\n");
    exit(EXIT_FAILURE);
  }
  if ((source_fp = fopen(argv[1], "rb")) == NULL)
  {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((dest_fp = fopen(argv[2], "wb")) == NULL)
  {
    fprintf(stderr, "Can't open %s\n", argv[2]);
    fclose(source_fp);
    exit(EXIT_FAILURE);
  }

  /*
  Suppose we neglected some parathesis around ch = getc().
  Would the program compile without error?
  I think it'll have a warning but compile - CORRECT

  Would the program do what we expect it to?
  Yes, it'll break the loop at EOF but not assign EOF to ch. - WRONG
  it applied EOF to ch which resulted in a blank file for dest_fp.
  */
  while((ch = getc(source_fp)) != EOF)
    putc(ch, dest_fp);

  fclose(source_fp);
  fclose(dest_fp);
  return 0;
}
