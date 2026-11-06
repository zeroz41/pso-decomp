#include "types.h"
#include "pso/unk/TLOC_Start.h"
#include "pso/ui/charcreate/PaletteCursorAction.h"
#include "pso/ui/hud/TMainCursor.h"

struct Ent_8013B2C8 { s32 w; };

extern "C" {
void fn_80044330(void *);
extern const f32 TMainCursor__data_805DB0C0;
s32 is_channel_active__11TMainCursorFv(PaletteCursorOverride*);
s32 can_start_technique__10TObjPlayerFPvi(TObjPlayer*, s32);
s32 canSetMenuCursorAction(PaletteCursorOverride* cursor, TObjPlayer* player, u8 kind, u8 parameter);
void TMainCursor__sub_8013B398(void *arg0, void *arg1);
s16 TMainCursor__sub_8013E298(void *p);
s32 TMainCursor__sub_8013E2A0(void *);
Ent_8013B2C8 *get_index__11TMainCursorFv(void *);
void TMainCursor__sub_8013E2B0(void *);
void TMainCursor__sub_8013B2A4(u16 *arg0);
void *get_player_by_client_id(s32 i);
int init__13TUnk_804A7260FPvPv(void);

    extern unsigned char lbl_804A7290[];
    extern int lbl_805D2CBC;
void*TLOC_Start::init() { init__13TUnk_804A7260FPvPv(); *(int*)((char*)this + 0x18) = (int)lbl_804A7290; *(int *)&this->m_name = lbl_805D2CBC; return this; }

void TMainCursor__sub_8013B2A4(u16 *arg0) {
    get_player_by_client_id(*arg0);
}

s32 TMainCursor::sort_actions_by_priority() {
    s32 k;
    s32 n;
    s32 i;
    Ent_8013B2C8 *p;
    Ent_8013B2C8 *q;
    Ent_8013B2C8 tmp;
    TMainCursor__sub_8013E2B0(&tmp);
    if (get_index__11TMainCursorFv(this) == NULL) {
        return 0;
    }
    n = TMainCursor__sub_8013E2A0(this);
    while (--n > 0) {
        p = get_index__11TMainCursorFv(this);
        for (i = 0; i < n; p++, i++) {
            q = p + 1;
            k = TMainCursor__sub_8013E298(q);
            if (TMainCursor__sub_8013E298(p) > k) {
                TMainCursor__sub_8013B398(&tmp, p);
                TMainCursor__sub_8013B398(p, q);
                TMainCursor__sub_8013B398(q, &tmp);
            }
        }
    }
    return 1;
}

void TMainCursor__sub_8013B398(void *arg0, void *arg1) {
    *(s16 *)((s8 *)arg0 + 0) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
}
void TMainCursor::reset_state() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)&this->m_24 = (f32) TMainCursor__data_805DB0C0;
    *(f32 *)&this->m_20 = (f32) TMainCursor__data_805DB0C0;
    *(f32 *)&this->m_1c = (f32) TMainCursor__data_805DB0C0;
    *(f32 *)&this->unk_28 = (f32) TMainCursor__data_805DB0C0;
    this->m_2c = (f32) TMainCursor__data_805DB0C0;
    *(f32 *)&this->unk_30 = (f32) TMainCursor__data_805DB0C0;
    this->m_34 = 0;
    *(s32 *)&this->unk_38 = 0;
    this->m_3c = (f32) TMainCursor__data_805DB0C0;
    *(f32 *)((s8 *)arg0 + 0x18) = (f32) TMainCursor__data_805DB0C0;
    ((TMainCursor *)arg0)->set_type(0);
    fn_80044330((u8 *)&this->m_40);
    ((TMainCursor *)(arg0 + 0x9C))->reset_slot();
}
s32 canSetMenuCursorAction(PaletteCursorOverride* cursor, TObjPlayer* player, u8 kind, u8 parameter) {
    if (is_channel_active__11TMainCursorFv(cursor) != 0) {
        return 0;
    }
    switch ((s32) kind) {
    case 4:
        switch (parameter) {
        case 9: case 10: return 1;
        default: return 0;
        }
    case 3:
        return can_start_technique__10TObjPlayerFPvi(player, parameter);
    default:
        return 0;
    }
}

}
