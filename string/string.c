// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	while (*source) {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	while (*source && len > 0) {
		*(destination) = *(source);
		destination++;
		source++;
		len--;
	}
	while (len > 0) {
        *destination = '\0';
        destination++;
        len--;
    }
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	while (*destination) {
		destination++;
	}
	while (*source) {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	while (*destination) {
		destination++;
	}
	while (*source && len > 0) {
		*destination = *source;
		destination++;
		source++;
		len--;
	}
	*destination = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 || *str2) {
        if (*str1 > *str2)
            return 1;
        if (*str1 < *str2)
            return -1;
        str1++;
        str2++;
    }
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while (*str1 && *str2 && len > 0) {
        if (*str1 > *str2)
            return 1;
        if (*str1 < *str2)
            return -1;
        str1++;
        str2++;
		len--;
    }
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while (*str) {
		if (*str == (char)c) {
			return (char*)str;
		}
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *copy = NULL;
	while (*str) {
		if (*str == (char)c) {
			copy = (char*)str;
		}
		str++;
	}
	return copy;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	while (*haystack) {
		if (strncmp(haystack, needle, strlen(needle)) == 0) {
			return (char*)haystack;
		}
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *copy = NULL;
	while (*haystack) {
		if (strncmp(haystack, needle, strlen(needle)) == 0 && strlen(haystack) >= strlen(needle)) {
			copy = (char*)haystack;
		}
		haystack++;
	}
	return copy;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	while (num > 0) {
		*(char*)destination = *(char*)source;
		destination++;
		source++;
		num--;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char*)destination;
	const char *src = (const char*)source;
	if (dest < src) {
		while (num > 0) {
			*dest = *src;
			dest++;
			src++;
			num--;
		}
	} else if (dest > src) {
		dest = dest + num;
		src = src + num;
		while (num > 0) {
			dest--;
			src--;
			*dest = *src;
			num--;
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const char *p1 = (const char *)ptr1;
    const char *p2 = (const char *)ptr2;
	while (num > 0) {
		if (*p1 < *p2)
			return -1;
		if (*p1 > *p2)
			return 1;

		p1++;
		p2++;
		num--;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *src = (unsigned char*)source;
	unsigned char val = (unsigned char)value;
	while (num > 0) {
		*src = val;
		src++;
		num--;
	}
	return source;
}
