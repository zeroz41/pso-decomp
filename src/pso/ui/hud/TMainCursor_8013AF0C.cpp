#include "types.h"
#include "pso/unk/TLOC_ListClear.h"
#include "pso/unk/TLOC_End.h"
#include "pso/ui/hud/TMainCursor.h"

struct Part_8013AF50 { u8 pad[0x124]; };

struct Cur_8013AF50 {
    u8 pad0[0x5C];
    Part_8013AF50 parts[4];
    u8 pad[0x510 - 0x5C - 4 * 0x124];
    u8 sub[4];
};

struct State_8013AF50 {
    u8 pad[0x424];
    Cur_8013AF50 *cur;
};

extern "C" {
s32 publish_target_list__11TMainCursorFPvi(Cur_8013AF50 *, s32);
State_8013AF50 *get_state__11TMainCursorFv(s32);
s32 TObjPlayer__sub_801C6DAC(u8 *arg0);
int init__13TUnk_804A7260FPvPv(void);

    extern unsigned char lbl_804A71C4[];
    extern int lockon_list_clear_task_name;
void*TLOC_ListClear::init_lockon() { init__13TUnk_804A7260FPvPv(); *(int*)((char*)this + 0x18) = (int)lbl_804A71C4; *(int *)&this->m_name = lockon_list_clear_task_name; return this; }
void TLOC_End::run_task() {
    s32 arg0 = (s32)this;
    s32 i;
    if (TObjPlayer__sub_801C6DAC((u8 *)(arg0 + 0x1C)) == 0) {
        return;
    }
    if (get_state__11TMainCursorFv(arg0 + 0x1C)->cur == NULL) {
        return;
    }
    for (i = 0; i < 4; i++) {
        TMainCursor::sort_list((s32)(get_state__11TMainCursorFv(arg0 + 0x1C)->cur), (s32)i);
        publish_target_list__11TMainCursorFPvi(get_state__11TMainCursorFv(arg0 + 0x1C)->cur, i);
    }
    ((TMainCursor *)(get_state__11TMainCursorFv(arg0 + 0x1C)->cur->sub))->publish_nearest_target();
    for (i = 0; i < 4; i++) {
        ((TMainCursor *)(&get_state__11TMainCursorFv(arg0 + 0x1C)->cur->parts[i]))->reset_cursor_parts();
    }
}

}
