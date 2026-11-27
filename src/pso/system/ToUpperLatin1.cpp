#include "types.h"
#include "pso/system/ToUpperLatin1.h"

char to_upper_latin1(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 0xC0 && c <= 0xFF)) {
        c -= 0x20;
    }
    return c;
}
