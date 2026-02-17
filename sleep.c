// SPDX-License-Identifier: BSD-3-Clause //

#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
	int res = syscall(__NR_nanosleep, req, rem);

	if (res < 0) {
		errno = -res;
		return -1;
	}
	return 0;
}

unsigned int sleep(unsigned int seconds)
{
	struct timespec req, rem;

	req.sec = seconds;
	req.nsec = 0;

	while (nanosleep(&req, &rem) == -1) {
		if (errno == EINTR) {
			req = rem;
		} else {
			if (rem.nsec > 0)
				rem.sec++;
			return rem.sec;
		}
	}
	return 0;
}
