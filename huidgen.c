/* SPDX-License-Identifier: MIT */
/* SPDX-FileCopyrightText: Copyright (c) 2026 commitmaniac */

#define HUID_IMPLEMENTATION
#include "huid.h"

int main(void)
{
    char *huid = huid_generate();
    printf("%s\n", huid);
    return 0;
}
