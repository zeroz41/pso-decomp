#include "types.h"
#include "pso/ui/window/TWindowDD_80348794.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {
s32 TWindowDD__sub_80348B70();
void TWindowDD::maybe_scroll(void* a1) { if (count_chars_since_newline((s32 *)a1) > 15) { TWindowDD::append_char((s8)((void*)10), (s32)this, (s32 *)a1); } }

s32 TWindowDD::count_chars_since_newline(s32 *len) {
    u8 *buf = (u8 *)this;
    s32 n = 0;
    s32 i;
    for (i = *len - 1; i >= 0; i--) {
        if (buf[i] == '\n') {
            break;
        }
        n++;
    }
    return n;
}

void TWindowDD::append_char(s8 arg0, s32 arg1, s32 *arg2) {
    s32 temp_r3;
    if (TWindowDD::can_append_chars(1, (s32 *)arg2) != 0) {
        temp_r3 = *(s32 *)((s8 *)arg2 + 0);
        *(s32 *)((s8 *)arg2 + 0) = temp_r3 + 1;
        *(s8 *)((s8 *)(arg1 + temp_r3) + 0) = arg0;
    }
}

void TWindowDD__sub_8034886C(s32 arg0, s32 arg1, void *arg2) {
    TWindowDD::append_string((s32)(TWindowDD__sub_80348B70()), (s32)arg1, (s32 *)arg2);
}

}
