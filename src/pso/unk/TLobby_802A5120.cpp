#include "types.h"
#include "pso/ui/charcreate/TObjCMAssignMenu.h"
#include "pso/unk/TLobby.h"

extern "C" {
void release_texture_list(void*);

extern u32 lbl_805D6668;
extern const s32 lbl_804666DC[];
extern const s32 lbl_804666F0[];
extern const s32 current_language;
void TLobby__sub_8023E4B4(s32, s32);

struct Tbl_802A5154 { s32 v[5]; };

void TLobby::free_dialing_gc() {
    if ((u32) lbl_805D6668 != 0U) {
        release_texture_list((void*)lbl_805D6668);
        lbl_805D6668 = 0U;
    }
}
void TLobby__sub_802A5154(void) {
    if (lbl_805D6668 != 0U) {
        return;
    }
    TLobby::update_menu_cursor();
    Tbl_802A5154 a = *(const Tbl_802A5154 *)lbl_804666DC;
    Tbl_802A5154 b = *(const Tbl_802A5154 *)lbl_804666F0;
    s32 r4 = a.v[current_language];
    lbl_805D6668 = r4;
    TLobby__sub_8023E4B4(b.v[current_language], r4);
}

}
