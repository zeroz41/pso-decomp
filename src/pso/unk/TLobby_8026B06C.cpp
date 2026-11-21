#include "types.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMessageQuest.h"
#include "pso/unk/TLobby_8026B06C.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"

extern "C" {
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

saddr create_quest_message_window_at(s32 arg0, saddr arg1) {
    TLobby__sub_80269DA4((void *)arg1, 1);
    return (saddr)new TWindowMessageQuest(arg0);
}
