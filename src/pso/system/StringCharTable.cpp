#include "types.h"
#include "pso/system/StringCharTable.h"
#include "clib/ctype.h"
void convert_string_chars_via_table(u8 *buf) {
    u8 *p = buf;
    u8 t;
    s32 v;
    while ((s8)(t = *p) != 0) {
        if ((s8)t == -1) {
            v = -1;
        } else {
            v = __upper_map[(u8)(s8)t];
        }
        *(s8 *)p = v;
        p++;
    }
}
