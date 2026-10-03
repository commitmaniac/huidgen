/* SPDX-License-Identifier: MIT */
/* SPDX-FileCopyrightText: Copyright (c) 2026 commitmaniac */

#define HUID_IMPLEMENTATION
#include "huid.h"
#include "config.h"

#include <getopt.h>
#include <stdbool.h>
#include <stdlib.h>

static void usage(char *pname)
{
    fprintf(stderr, "usage: %s [-v] [-s suffix]\n", pname);
    exit(1);
}

int main(int argc, char **argv)
{
    char *suffix;
    bool append_suffix = false;
    bool version = false;
    int ch;

    while ((ch = getopt(argc, argv, "hs:v")) != -1) {
        switch (ch) {
            case 's':
                suffix = optarg;
                append_suffix = true;
                break;
            case 'v':
                version = true;
                break;
            case '?':
            default:
                usage(argv[0]);
        }
    }

    if (version) {
        printf("%s %s\n", argv[0], VERSION);
        return 0;
    }

    char *huid = huid_generate();
    if (append_suffix) huid = huid_append_suffix(huid, suffix);
    printf("%s\n", huid);
    return 0;
}
