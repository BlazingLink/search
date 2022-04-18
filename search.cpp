#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string>

using namespace std;

int
main (int argc, char **argv) {
  int directoryFlag, recursiveFlag, fromFlag, opt, searchFrom;
  string searchTerm;

  static struct option long_options[] =
    {
      // These options set a flag.
      {"recursive", required_argument,       &recursiveFlag, 1},
      {"directory", required_argument,       &directoryFlag, 1},
      {"from", required_argument, &fromFlag, 1},

      {0, 0, 0, 0}
    };
  /* getopt_long stores the option index here. */
  int option_index = 0;
  opterr = 0;

  while ((opt = getopt_long (argc, argv, "r:d:f", long_options, &option_index)) != -1)
    switch (opt)
      {
      case 'r':
        recursiveFlag = 1;
        printf ("Recursive search.\n");
        if (fromFlag && directoryFlag) {}
        else if (fromFlag) {
          searchTerm = argv[1];
        }
        else {
          searchTerm = argv[0];
        }

        break;
      case 'd':
        directoryFlag = 1;
        printf ("Directory search.\n");
        if (fromFlag && recursiveFlag) {}
        else if (fromFlag) {
          searchTerm = argv[1];
        }
        else {
          searchTerm = argv[0];
        }
        break;
      case 'f':
        fromFlag = 1;
        if (recursiveFlag || directoryFlag) {
          searchFrom = argv[1];
        }
        else {
          searchFrom = argv[0];
        }
        break:
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

  if ((recursiveFlag && directoryFlag) || recursiveFlag) {
    printf ("Too many flags! Defaulting to recursive.\n");
    if (fromFlag) {
      system(("find " + searchFrom + " | grep " + serchTerm).c_str());
    }
    else {
      system(("find | grep " + searchTerm).c_str());
    }
  }
}
