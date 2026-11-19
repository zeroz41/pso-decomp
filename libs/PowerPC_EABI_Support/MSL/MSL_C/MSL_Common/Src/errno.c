#include "libc/errno.h"

// MSL's errno.c: only the error number (.sbss 0x805D7330, between alloc.c and uart_console_io.c).
int errno;
