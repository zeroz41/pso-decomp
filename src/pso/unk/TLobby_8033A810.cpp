#include "types.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/unk/TLobby.h"

struct Tbl_8033A844 { s32 v[5]; };

extern "C" {
extern const s32 lobby_menu_cursor_resource_name_table[];
extern const s32 menu_cursor_resource_name_table_b[];
extern const s32 current_language;
extern u32 lbl_805D6D78;
void release_texture_list(void*);

void TLobby::free_global_object() {
    if ((u32) lbl_805D6D78 != 0U) {
        release_texture_list((void*)lbl_805D6D78);
        lbl_805D6D78 = 0U;
    }
}
void TLobby::update_menu_cursor_selection() {
    TLobby::update_menu_cursor();
    Tbl_8033A844 a = *(const Tbl_8033A844 *)lobby_menu_cursor_resource_name_table;
    Tbl_8033A844 b = *(const Tbl_8033A844 *)menu_cursor_resource_name_table_b;
    s32 r4 = b.v[current_language];
    lbl_805D6D78 = r4;
    TLobby__sub_8023E4B4(a.v[current_language], r4);
}

}
