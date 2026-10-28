#include "types.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLOC_End.h"
#include "pso/misc/TLOC_Start.h"
#include "pso/misc/TMainCursor.h"
#include "pso/player/TObjPlayer.h"

struct Cur_8013B0F0 {
    u8 pad0[0x4EC];
    u8 pos[0x4F8 - 0x4EC];
    u8 target[0x510 - 0x4F8];
    u8 sub[4];
};

struct Pl_8013B0F0 {
    u8 pad[0x424];
    Cur_8013B0F0 *cur;
};

extern "C" {
u16 TMainCursor__sub_8013E03C(void *p);
s32 set_target_index__11TMainCursorFs(void *, int);
s32 reset_nearest_target_record(void *);
s32 submit_cursor_candidate(Pl_8013B0F0 *, int);
void *get_player_by_client_id(s32 i);
extern Pl_8013B0F0 *player_slot_table[12];
int init__13TUnk_804A7260FPvPv(void);

    extern unsigned char lbl_804A7278[];
    extern int lbl_805D2CC0;
void*TLOC_End::init_vtable() { init__13TUnk_804A7260FPvPv(); *(int*)((char*)this + 0x18) = (int)lbl_804A7278; *(int *)&this->m_name = lbl_805D2CC0; return this; }
void TLOC_Start::run_task() {
    s32 arg0 = (s32)this;
    Pl_8013B0F0 *pl;
    Cur_8013B0F0 *cur;
    s32 i;
    pl = (Pl_8013B0F0 *)get_player_by_client_id((s32)(TMainCursor__sub_8013E03C((void *)(arg0 + 0x1C))));
    if (pl == NULL) {
        return;
    }
    cur = pl->cur;
    if (cur == NULL) {
        return;
    }
    reset_nearest_target_record(cur->sub);
    ((TMainCursor *)(cur->pos))->update_cursor_pos();
    set_target_index__11TMainCursorFs(cur->target, 0xFFFF);
    ((TMainCursor *)cur)->init_slots();
    ((TMainCursor *)cur)->bind_action_channels();
    if (get_main_phase() == 0xF) {
        for (i = 0; i < 12; i++) {
            Pl_8013B0F0 *p = player_slot_table[i];
            if (p != NULL && ((TObjPlayer *)p)->is_body_collision_inactive() == 0) {
                submit_cursor_candidate(p, -1);
            }
        }
    } else {
        submit_cursor_candidate(pl, -1);
    }
}

}
