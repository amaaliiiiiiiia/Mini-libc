Mini-libc Implementation
This project consists of building a freestanding, minimalistic C standard library for Linux on an x86_64 architecture. The library serves as a low-level replacement for `glibc`, interfacing directly with the Linux kernel via system calls.

## Core Implementation Details
### 1. String & Memory Operations (string.h)
I implemented essential memory and string manipulation functions from scratch:
- String handling: `strcpy`, `strncpy`, `strcat`, `strncat`, `strlen`, `strcmp`, `strncmp`, `strstr`, and `strrstr`.
- Memory blocks: `memcpy`, `memset`, `memmove`, and `memcmp` for direct buffer manipulation.

### 2. System Call Wrapper
At the heart of the library is a custom `syscall()` interface:
- It uses inline assembly to trigger the `syscall` instruction on x86_64.
- This allows the library to request services directly from the kernel without using any outside library calls.

### 3. File I/O & POSIX Primitives
I implemented basic file operations by wrapping their respective Linux system calls:
- File management: `open`, `close`, `lseek`, `stat`, and `fstat` (found in `unistd.h`, `fcntl.h`, and `stat.h`).
- Truncation: `truncate` and `ftruncate` for resizing files.
- Standard Output: A custom `puts` implementation for basic console output.

### 4. Dynamic Memory Management (`stdlib.h`, `sys/mman.h`)
The library includes a memory allocator that manages a process's virtual memory space:
- Back-end: Utilizes `mmap`, `mremap`, and `munmap` syscalls to request pages from the OS.
- Front-end: Provides `malloc`, `calloc`, `realloc` and `free`.
- Tracking: Uses a linked list structure (`mem_list`) to track allocated memory areas and ensure proper management.

### 5. Error Handling & Time (`errno.h`, `time.h`)
- Error Tracking: Implemented the global `errno` variable. Functions are designed to set `errno` correctly based on the return values from the Linux kernel.
- Time & Sleep: Added support for `sleep` and `nanosleep` functions to pause process execution, including the necessary `time.h` header.
