#include "types.h"

u32 fn_8000F824(u8 *data, s32 len) {
    u32 crc = 0xFFFFFFFF;
    s32 i;
    s32 bit;
    for (i = 0; i < len; i++, data++) {
        crc ^= *data;
        for (bit = 0; bit < 8; bit++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xEDB88320;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc ^ 0xFFFFFFFF;
}
