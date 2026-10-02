/* SPDX-License-Identifier: MIT */
/* SPDX-FileCopyrightText: Copyright (c) 2026 commitmaniac */

#define HUID_IMPLEMENTATION
#include "huid.h"

#include <getopt.h>
#include <stdbool.h>
#include <stdlib.h>

static void usage(char *pname)
{
    fprintf(stderr, "usage: %s [-s suffix]\n", pname);
    exit(1);
}

int main(int argc, char **argv)
{
    char *suffix;
    bool append_suffix = false;
    int ch;

    while ((ch = getopt(argc, argv, "hs:")) != -1) {
        switch (ch) {
            case 's':
                suffix = optarg;
                append_suffix = true;
                break;
            case '?':
            default:
                usage(argv[0]);
        }
    }

    char *huid = huid_generate();
    if (append_suffix) huid = huid_append_suffix(huid, suffix);
    printf("%s\n", huid);
    return 0;
}
