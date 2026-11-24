#include "misc_io.h"
#include "abort_exit.h"
#include "MSL_C/ansi_files.h"

void __stdio_atexit(void) {
    __stdio_exit = __close_all;
}
