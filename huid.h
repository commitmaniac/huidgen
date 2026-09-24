/* SPDX-License-Identifier: MIT */
/* SPDX-FileCopyrightText: Copyright (c) 2026 commitmaniac */

#ifndef HUID_H_
#define HUID_H_

#include <time.h>
#include <stdio.h>

#define HUID_CAP 16
#define HUID_SUFFIX_CAP 256

char *huid_generate(void);
char *huid_append_suffix(char *id, const char *suffix);

#endif

#ifdef HUID_IMPLEMENTATION

char *huid_generate(void)
{
    time_t rawtime;
    time(&rawtime);
    struct tm *timeinfo = gmtime(&rawtime);
    static char buf[HUID_CAP];
    snprintf(buf, sizeof(buf), "%04d%02d%02d-%02d%02d%02d",
        timeinfo->tm_year + 1900,
        timeinfo->tm_mon + 1,
        timeinfo->tm_mday,
        timeinfo->tm_hour,
        timeinfo->tm_min,
        timeinfo->tm_sec);

    return buf;
}

char *huid_append_suffix(char *id, const char *suffix)
{
    static char buf[HUID_SUFFIX_CAP];
    snprintf(buf, sizeof(buf), "%s-%s", id, suffix);
    return buf;
}

#endif
