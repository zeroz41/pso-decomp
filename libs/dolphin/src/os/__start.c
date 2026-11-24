#include <dolphin/os.h>
#include <dolphin/db.h>
#include <stdlib.h>
#include <string.h>

#include "os/__os.h"

__declspec(section ".init") static void __init_registers(void);
__declspec(section ".init") static void __init_data(void);

__declspec(section ".init") static void __check_pad3(void) {
    if ((*(u16*)0x800030E4 & 0xEEF) == 0xEEF) {
        OSResetSystem(0, 0, 0);
    }
}

__declspec(section ".init") __declspec(weak) asm void __start(void) {
#include "orig_asm/os/__start/__start.inc"
}

__declspec(section ".init") static asm void __init_registers(void) {
#include "orig_asm/os/__start/__init_registers.inc"
}

inline void __copy_rom_section(void* dst, const void* src, size_t size) {
    if (size && (dst != src)) {
        memcpy(dst, src, size);
        __flush_cache(dst, size);
    }
}

inline void __init_bss_section(void* dst, size_t size) {
    if (size) {
        memset(dst, 0, size);
    }
}

__declspec(section ".init") static void __init_data(void) {
    RomSection* rs;
    BssSection* bs;

    rs = _rom_copy_info;
    while (1) {
        if (rs->size == 0) {
            break;
        }

        __copy_rom_section(rs->virtualOfs, rs->romOfs, rs->size);
        rs++;
    }

    bs = _bss_init_info;
    while (1) {
        if (bs->size == 0) {
            break;
        }

        __init_bss_section(bs->virtualOfs, bs->size);
        bs++;
    }
}
