#include "types.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/unk/text_8026B260.h"
#include "pso/misc/TLobby_8026B06C.h"
#include "pso/misc/TLobby.h"

extern "C" {
s32 __nw__7TObjectFUl(int);
s32 TLobby__sub_80269DA4(void *, int);
int append_message_window_line(void *w, int text, int flags, int color);
void TLobby::set_field_90(s32 v) { *(s32*)((char*)this + 0x90) = v; }
}

int dispatch_message_window_text(void *w, int text, int flags) {
    switch (*(s32 *)((u8 *)w + 0x90)) {
    case 0:
        return append_message_window_line(w, text, flags, 0xFF000000);
    case 1:
    case 2:
        return ((TWindowMessage *)w)->append_line(text, flags);
    default:
        return 0;
    }
}

s32 create_quest_message_window_at(s32 arg0, s32 arg1) {
    s32 temp_r3;
    s32 var_r0;
    TLobby__sub_80269DA4((void *)arg1, 1);
    temp_r3 = __nw__7TObjectFUl(0x94);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (s32)TWindowMessageQuest__ct((u8 *)temp_r3, (arg0));
    }
    return var_r0;
}
