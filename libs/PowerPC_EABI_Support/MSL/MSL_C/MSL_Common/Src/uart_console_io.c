#include "MSL_C/ansi_files.h"
#include "PowerPC_EABI_Support/MetroTRK/UART.h"

static inline int __init_uart_console(void);

int __write_console(__file_handle file, unsigned char* buf, size_t* count, __idle_proc idle_fn) {
    if (__init_uart_console() != 0) {
        return 1;
    }

    if (WriteUARTN(buf, *count) != UART_NoError) {
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
        ret = InitializeUART(kBaud57600);

        if (ret == 0) {
            initialized = 1;
        }
    }

    return ret;
}
