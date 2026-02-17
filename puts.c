// SPDX-License-Identifier: BSD-3-Clause //

#include <stdio.h>
#include <unistd.h>

int puts(const char *str)
{
	const char *p = str;

	while (*p)
		p++;

	int len = p - str;

	if (write(1, str, len) == -1)
		return -1;

	if (write(1, "\n", 1) == -1)
		return -1;

	return 1;
}
