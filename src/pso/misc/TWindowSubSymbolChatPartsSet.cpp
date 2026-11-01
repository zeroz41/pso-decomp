#include "types.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/misc/TWindowChatSymbol_802486A8.h"
#include "pso/misc/TWindowBase.h"

#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChat.h"

struct RecoveredGlobal_80286824_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct Set_8028625C {
    u8 pad0[0x69];
    s8 mode;
    s16 x;
    s16 y;
    s16 color;
    s8 *p70;
    s32 cur;
    u32 sel;
    s32 *p7C;
    s32 *p80;
    s32 *p84;
};

struct Win_802864C4 {
    u8 pad0[0x69];
    u8 f69;
    s16 x;
    s16 y;
    u8 pad6e[0x74 - 0x6E];
    s32 f74;
};

typedef struct T_8028642C {
    u8 pad[0x69];
    s8 f69;
    u8 pad6a[0x78 - 0x6A];
    u32 f78;
    u8 pad7c[0x84 - 0x7C];
    s32 *f84;
} T_8028642C;

typedef struct T_802869BC {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    u8 pad1c[0x20 - 0x1C];
    s16 f20;
    u8 pad22[0x2C - 0x22];
    u32 f2c;
    u8 pad30[0x68 - 0x30];
    s8 f68;
    u8 pad69;
    s16 f6a;
    s16 f6c;
    s16 f6e;
    s32 f70;
    u8 pad74[0x7C - 0x74];
    s32 f7c;
    s32 f80;
    u8 pad84[0x88 - 0x84];
    void *f88;
    f32 f8c;
    f32 f90;
    f32 f94;
} T_802869BC;

struct V2_80286120 { f32 x, y; };

struct Pt_80286120 { u8 pad[8]; f32 f8; f32 fc; };

struct Ps_80286120 { u8 pad[0x69]; s8 f69; u8 pad6a[0xA]; s32 f74; };

extern "C" {
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(int, int);
extern RecoveredGlobal_80286824_lbl_8050E208 controller_input_state;
extern const f32 lbl_805DD820;
u16 *get_entry_offset_d__28TWindowSubSymbolChatPartsSetFl(void *, s32);
void setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(void *, void *, void *, u16, s32, s32, s32, s32);
void *TWindowSubSymbolChatPartsSet__sub_802482B8(void *, s32);
void *get_parts_entry__28TWindowSubSymbolChatPartsSetFl(void *, s32);
void *get_parts_entry__28TWindowSubSymbolChatPartsSetFii(void *, s32);
s32 is_flag_set__11TLoadingCurFv(void *, s32);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
s32 update_visibility__28TWindowSubSymbolChatPartsSetFv(void *, s16);
s32 get_message_10__20TWindowSubStatusDispFl(s32);
extern u8 lbl_8044FC30[];
extern s32 __vt__28TWindowSubSymbolChatPartsSet[];
extern s32 TWindowSubSymbolChatPartsSet__name;
extern const f32 lbl_805DD824;
extern const f32 lbl_805DD828;
extern const f32 lbl_805DD82C;
extern const f32 lbl_805DD830;
T_802869BC *TWindowSubSymbolChatPartsSet__ct(T_802869BC *self, void *parent, s16 arg2, s32 arg3, s32 arg4);
void TWindowSubSymbolChatFaceType__sub_80283C84(void *, void *, f32, f32);
extern const f32 lbl_805DD814;
extern const f32 lbl_805DD818;
extern const f32 lbl_805DD81C;
struct Vec2_80286708_802861AC { f32 x; f32 y; };

void render__28TWindowSubSymbolChatPartsSetFv(TWindowSubSymbolChatPartsSet *arg0);
s32 play_sound_effect(s32, s32, s32, s32);
s32 draw_visible_window_entries(void *, void *, int, f32);
u8 *draw_default_entry__9TWindowDDFl();
s32 forward_render__20TWindowSubStatusDispFv(int, int);

s32 TWindowSubSymbolChatPartsSet::draw_selected_part_cursor(int arg1) {
#define arg0 ((Ps_80286120 *)this)
    V2_80286120 sp;
    Pt_80286120 *e;
    switch (arg0->f69) {
    case 1:
    case 3:
        e = (Pt_80286120 *)get_parts_entry__28TWindowSubSymbolChatPartsSetFii(arg0, arg0->f74);
        sp.x = e->f8 - lbl_805DD814;
        sp.y = e->fc - lbl_805DD814;
        TWindowSubSymbolChatFaceType__sub_80283C84((void *)arg1, &sp, lbl_805DD818, lbl_805DD81C);
        break;
    case 0:
    case 2:
        return;
    }
#undef arg0
}

void TWindowSubSymbolChatPartsSet::handle_cancel() {
    if (is_active() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_68 = (u8) (this->m_68 | 2);
    }
}

void TWindowSubSymbolChatPartsSet::handle_decide() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->m_68 = (u8) (this->m_68 | 1);
    ((TWindowSubStatusDisp *)(this->m_88))->set_entry_state(2);
}

void TWindowSubSymbolChatPartsSet::sub_8028625C() {
    Set_8028625C *arg0 = (Set_8028625C *)this;
    u16 *e2;
    void *b3;
    void *a1;
    void *a3;
    void *b1;
    u16 *e;
    void *c;
    switch (arg0->mode) {
    case 0:
    case 2:
        e = get_entry_offset_d__28TWindowSubSymbolChatPartsSetFl(arg0, arg0->cur);
        ((TWindowSubSymbolChatPartsSet *)e)->set_pos(arg0->x, arg0->y);
        TWindowSubSymbolChatPartsSet::set_part_sprite(e, arg0->color, *arg0->p7C, *arg0->p80);
        if (*arg0->p84 != 0) {
            e2 = get_entry_offset_d__28TWindowSubSymbolChatPartsSetFl(arg0, arg0->sel);
            *e2 &= ~2;
            ((TWindowSubSymbolChatPartsSet *)e2)->set_pos((s16)(0x40 - arg0->x), arg0->y);
            TWindowSubSymbolChatPartsSet::set_part_sprite(e2, arg0->color, *arg0->p7C == 0, *arg0->p80);
        } else if (arg0->sel < 0xC) {
            *get_entry_offset_d__28TWindowSubSymbolChatPartsSetFl(arg0, arg0->sel) |= 2;
        }
        break;
    case 3:
        a3 = get_parts_entry__28TWindowSubSymbolChatPartsSetFii(arg0, arg0->sel);
        b3 = get_parts_entry__28TWindowSubSymbolChatPartsSetFl(arg0, arg0->sel);
        c = TWindowSubSymbolChatPartsSet__sub_802482B8(arg0, arg0->sel);
        setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(a3, b3, c, 0xFF, 0, 0, 0, 0);
    case 1:
        a1 = get_parts_entry__28TWindowSubSymbolChatPartsSetFii(arg0, arg0->cur);
        b1 = get_parts_entry__28TWindowSubSymbolChatPartsSetFl(arg0, arg0->cur);
        c = TWindowSubSymbolChatPartsSet__sub_802482B8(arg0, arg0->cur);
        setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(a1, b1, c, arg0->color, *arg0->p70, *arg0->p7C, *arg0->p80, arg0->cur);
        break;
    }
}

void TWindowSubSymbolChatPartsSet::toggle_selected_part() {
    T_8028642C *arg0 = (T_8028642C *)this;
    switch (arg0->f69) {
    case 0:
    case 2:
        if (arg0->f78 < 12 && TWindowShortListCtrl__check_controller_button((int)((u8 *)&controller_input_state.value + 0x20), 0x400) != 0) {
            if (*arg0->f84 != 0) {
                *arg0->f84 = 0;
            } else {
                *arg0->f84 = 1;
            }
        }
        break;
    case 1:
        break;
    case 3:
        break;
    }
}

void TWindowSubSymbolChatPartsSet::handle_cursor_input() {
    s16 temp_r4;
    u8 temp_r0;
    void *camera_ctrl;
    Win_802864C4 *w = (Win_802864C4 *)this;
    camera_ctrl = (u8 *)&controller_input_state.value + 0x20;
    if ((is_on_current_screen__11TCameraCtrlFv(camera_ctrl, 0xF0) != 0) || (is_flag_set__11TLoadingCurFv((u8 *)&controller_input_state.value + 0x160, 0xF0) != 0)) {
        if ((is_on_current_screen__11TCameraCtrlFv(camera_ctrl, 0x80) != 0) || (is_flag_set__11TLoadingCurFv((u8 *)&controller_input_state.value + 0x160, 0x80) != 0)) {
            *(s16 *)&this->m_6a = (s16) (*(s16 *)&this->m_6a + 1);
        }
        if ((is_on_current_screen__11TCameraCtrlFv(camera_ctrl, 0x40) != 0) || (is_flag_set__11TLoadingCurFv((u8 *)&controller_input_state.value + 0x160, 0x40) != 0)) {
            *(s16 *)&this->m_6a = (s16) (*(s16 *)&this->m_6a - 1);
        }
        if ((is_on_current_screen__11TCameraCtrlFv(camera_ctrl, 0x10) != 0) || (is_flag_set__11TLoadingCurFv((u8 *)&controller_input_state.value + 0x160, 0x10) != 0)) {
            *(s16 *)&this->m_6c = (s16) (*(s16 *)&this->m_6c - 1);
        }
        if ((is_on_current_screen__11TCameraCtrlFv(camera_ctrl, 0x20) != 0) || (is_flag_set__11TLoadingCurFv((u8 *)&controller_input_state.value + 0x160, 0x20) != 0)) {
            *(s16 *)&this->m_6c = (s16) (*(s16 *)&this->m_6c + 1);
        }
        switch ((s8)w->f69) {
        case 0:
        case 2:
            if (w->x < 0) {
                w->x = 0;
            }
            if (w->x >= 0x40) {
                w->x = 0x3F;
            }
            if (w->y < 0) {
                w->y = 0;
            }
            if (w->y >= 0x40) {
                w->y = 0x3F;
            }
            break;
        case 1:
        case 3:
            if (w->x < 0) {
                w->x = 0;
            }
            if (w->x >= 2) {
                w->x = 1;
            }
            if (w->y < 0) {
                w->y = 0;
            }
            if (w->y >= 2) {
                w->y = 1;
            }
            temp_r4 = w->x;
            w->f74 = temp_r4 + w->y * 2;
            update_visibility__28TWindowSubSymbolChatPartsSetFv(this, temp_r4);
            break;
        }
    }
}

void render__28TWindowSubSymbolChatPartsSetFv(TWindowSubSymbolChatPartsSet *window_sub_symbol_chat_parts_set) {
    struct Vec2_80286708_802861AC sp10;
    struct Vec2_80286708_802861AC sp8;
    f32 ctx;
    u8 *c_arg;

    c_arg = draw_default_entry__9TWindowDDFl();
    ((TWindowSubSymbolChatPartsSet *)(&sp10))->copy_vec2(c_arg + 0x10);
    ((TWindowSubSymbolChatPartsSet *)(&sp8))->copy_vec2(c_arg + 0x28);
    if ((s32) *(s32 *)((s8 *)c_arg + 0x30) < 0) {
        *(f32 *)((s8 *)c_arg + 0x28) = (f32) ((f32) *(s32 *)&window_sub_symbol_chat_parts_set->m_5c / lbl_805DD820);
        *(f32 *)((s8 *)c_arg + 0x2C) = (f32) *(f32 *)((s8 *)c_arg + 0x28);
    }
    ((TWindowBase *)window_sub_symbol_chat_parts_set)->draw_quest_message_frame((void *)c_arg);
    *(f32 *)((s8 *)c_arg + 0x10) = (f32) (*(f32 *)((s8 *)c_arg + 0x10) + *(f32 *)((s8 *)window_sub_symbol_chat_parts_set + 0x8C));
    *(f32 *)((s8 *)c_arg + 0x14) = (f32) (*(f32 *)((s8 *)c_arg + 0x14) + window_sub_symbol_chat_parts_set->m_90);
    *(f32 *)((s8 *)c_arg + 0x28) = (f32) (*(f32 *)((s8 *)c_arg + 0x28) * *(f32 *)((s8 *)window_sub_symbol_chat_parts_set + 0x94));
    ctx = *(f32 *)((s8 *)c_arg + 0x2C);
    *(f32 *)((s8 *)c_arg + 0x2C) = (f32) (ctx * *(f32 *)((s8 *)window_sub_symbol_chat_parts_set + 0x94));
    draw_visible_window_entries((void *)window_sub_symbol_chat_parts_set, (u8 *)window_sub_symbol_chat_parts_set + 0x24, (int)c_arg, (f32)ctx);
    window_sub_symbol_chat_parts_set->draw_selected_part_cursor((int)c_arg);
    ((TWindowSubSymbolChatPartsSet *)(c_arg + 0x10))->copy_vec2(&sp10);
    ((TWindowSubSymbolChatPartsSet *)(c_arg + 0x28))->copy_vec2(&sp8);
    forward_render__20TWindowSubStatusDispFv((int) (*(s32 *)&window_sub_symbol_chat_parts_set->m_88), (int)c_arg);
}

typedef char RecoveredGlobal_80286824_lbl_8050E208_size[sizeof(RecoveredGlobal_80286824_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowSubSymbolChatPartsSet::run_task() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r31;
    if (!(this->m_2c & 2)) {
        *(s32 *)&this->m_5c = 0x01000000;
    }
    if (((TWindowSubSymbolChatPartsSet *)arg0)->is_active() == 0) {
        handle_cursor_input();
        temp_r31 = (u8 *)&controller_input_state.value + 0x20;
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r31, 4) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 4) != 0)) {
            handle_decide();
        }
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r31, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0)) {
            handle_cancel();
        }
    }
    toggle_selected_part();
    ((TWindowSubSymbolChatPartsSet *)arg0)->sub_8028625C();
    if ((f32) *(s32 *)&this->m_5c >= lbl_805DD820) {
        ((TWindowSubStatusDisp *)(*(s32 *)&this->m_88))->update_subwindow();
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_window_entry_list((u8 *)&this->m_24);
}

}
TWindowSubSymbolChatPartsSet::~TWindowSubSymbolChatPartsSet() {
    TWindowSubStatusDisp::destroy_status_display((s32)(*(void **)((s8 *)this + 0x88)), (s16)1);
}

T_802869BC *TWindowSubSymbolChatPartsSet__ct(T_802869BC *self, void *parent, s16 arg2, s32 arg3, s32 arg4) {
    void *h;
    TWindowChatSymbol__ct((TWindowChatSymbol *)((u8 *)self), (s32)parent, (s32)lbl_8044FC30);
    self->vt = ((s32 *)&__vt__28TWindowSubSymbolChatPartsSet);
    self->f0 = TWindowSubSymbolChatPartsSet__name;
    ((TWindowBase *)self)->set_depth(lbl_805DD824);
    self->f68 = 0;
    self->f6a = 0;
    self->f6c = 0;
    self->f6e = arg2;
    self->f70 = 0;
    self->f7c = arg3;
    self->f80 = arg4;
    h = ::operator new(0x24);
    if (h != 0) {
        h = ((TWindowSubStatusDisp *)h)->construct_type1_heading(get_message_10__20TWindowSubStatusDispFl(0x34), self->f20);
    }
    self->f88 = h;
    self->f8c = lbl_805DD828;
    self->f90 = lbl_805DD82C;
    self->f94 = lbl_805DD830;
    self->f2c |= 0x40;
    ((TWindowSubSymbolChatPartsSet *)self)->set_selection(TWindowSubSymbolChat::get_instance());
    return self;
}

