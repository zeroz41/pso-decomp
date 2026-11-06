#include "types.h"
#include "pso/unk/TLobby_802A0F3C.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/unk/TLobby.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_14 { s32 v[5]; };

extern "C" {
extern const s32 lbl_804661E4[];
extern const s32 lbl_804661F8[];
extern const s32 current_language;
extern u32 lbl_805D6630;
void release_texture_list(void*);

void TLobby::free_dialog_global() {
    if ((u32) lbl_805D6630 != 0U) {
        release_texture_list((void*)lbl_805D6630);
        lbl_805D6630 = 0U;
    }
}

    extern int lobby_cursor_active_flag;

void TLobby__sub_802A0F70(void) {
    TLobby::update_menu_cursor();
    ByteBlock_14 a = *(const ByteBlock_14 *)lbl_804661E4;
    ByteBlock_14 b = *(const ByteBlock_14 *)lbl_804661F8;
    s32 r4 = b.v[current_language];
    lbl_805D6630 = r4;
    TLobby__sub_8023E4B4(a.v[current_language], r4);
}

int TObjPlayer__sub_802A1018(void) {  return lobby_cursor_active_flag; }

}
