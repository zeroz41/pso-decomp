#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

s32 count_chars_since_newline__9TWindowDDFPl();

void TWindowDD::show_message_by_count(s32 arg0, s32 arg1) {
    if (count_chars_since_newline__9TWindowDDFPl() > 0xF) {
        TWindowDD::append_char((s8)0xA, (s32)arg0, (s32 *)arg1);
        return;
    }
    TWindowDD::append_char((s8)0x20, (s32)arg0, (s32 *)arg1);
}

}
