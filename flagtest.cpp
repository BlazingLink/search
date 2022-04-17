#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main (int argc, char **argv)
{
  int bflag = 0;
  int sflag = 0;
  int index;
  int c;

  opterr = 0;

  system ("echo 'using system() command'")

  while ((c = getopt (argc, argv, "bs")) != -1)
    switch (c)
      {
      case 'b':
        bflag = 1;
        break;
      case 's':
        sflag = 1;
        break;
      case '?':
        if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

  printf ("bflag = %d, sflag = %d\n", bflag, sflag);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);
  return 0;
}
