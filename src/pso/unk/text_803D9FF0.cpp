#include "types.h"
#include "pso/unk/text_803D9FF0.h"
extern u8 __upper_map[];
void convert_string_chars_via_table(u8 *arg0) {
    u8 *p = arg0;
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
