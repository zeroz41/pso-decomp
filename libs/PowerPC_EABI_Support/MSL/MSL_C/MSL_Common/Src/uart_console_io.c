#include "stddef.h"

unsigned long WriteUARTN(void* buf, unsigned long len);
unsigned long ReadUARTN(void* bytes, unsigned long length);
unsigned long InitializeUART(unsigned long baudRate);

static inline int __init_uart_console(void);

int __write_console(int file, unsigned char* buf, size_t* count, int idle_fn) {
    if (__init_uart_console() != 0) {
        return 1;
    }

    if ((long)WriteUARTN(buf, *count) != 0) {
        *count = 0;
        return 1;
    }

    __TRK_write_console(file, buf, count, (void*)idle_fn);

    return 0;
}

static inline int __init_uart_console(void) {
    static int initialized = 0;
    int ret = 0;

    if (initialized == 0) {
        ret = InitializeUART(0xE100);

        if (ret == 0) {
            initialized = 1;
        }
    }

    return ret;
}
