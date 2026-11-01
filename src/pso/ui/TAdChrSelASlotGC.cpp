#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/ui/TAdDrawLineCtrl.h"
#include "pso/ui/TAdPlayerLoadGC.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/TAdChrSelASlotGC.h"
#include "pso/TAdChrSelMovePlateGC.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/TAdPlyChrSelPlateGC.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/TAdChrSelSlotGC.h"
#include "pso/ui/TAdMcSelectGC.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/misc/TWindowSubComCard_80265410.h"
#include "pso/quest/TQuestThread.h"

struct RecoveredGlobal_8030DE58_lbl_80475808 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8030DE58_lbl_80475808_size[sizeof(RecoveredGlobal_8030DE58_lbl_80475808) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8030DE58_lbl_80475848 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8030DE58_lbl_80475848_size[sizeof(RecoveredGlobal_8030DE58_lbl_80475848) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8030CEEC_lbl_80475818 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_8030CEEC_lbl_80475858 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_8030CEEC_lbl_80475878 {
    s32 value;
    u8 remaining[0x14];
};

struct Slot_8030C404 { u8 pad[0x34]; void *a; void *b; };

struct G_8030C45C { s32 a; s32 b; s32 c; f32 v[2]; };

struct S_8030C45C { s32 x; s32 y; };

struct V2_8030C750 { f32 x, y; };

struct V2_8030C814 { f32 x, y; };

extern "C" {
s32 free_member__17TWindowSubComCardFv(s32, s32);
s32 forward_slot_selection__16TAdChrSelASlotGCFPvPv(s32, s32, s32, f32);
s32 create__19TWindowMessageYesNoFPvPvPvPv(s32, s32, s32, s32);
extern const f32 lbl_805DF214;
s32 TAdChrSelASlotGC__sub_8030CA84(s32 arg0, s32 arg1);
extern const f32 lbl_805DF20C;
s32 TAdChrSelASlotGC__sub_8030C978(void *arg0, s32 arg1, s32 arg2);
void *__ct__16TAdChrSelASlotGCFP7TObjectPv(void *arg0, void *arg1, void *arg2);
u8 *__nw__7TObjectFUl(s32);
extern u32 TAdChrSel__global_slot_data;
u8 *get_or_create_slot_window__22TAdMultiPlyChrSelectGCFii(s32 arg0, s32 arg1);
s32 __ct__19TAdPlyChrSelPlateGCFv(int, void *, void *);
s32 __ct__15TAdChrSelSlotGCFP7TObject(int, void *);
s32 __ct__15TAdSubPlyItemGCFv(int, void *);
s32 __ct__20TAdChrSelMovePlateGCFv(int, void *);
extern RecoveredGlobal_8030DE58_lbl_80475808 chr_sel_a_slot_plate_layout;
extern RecoveredGlobal_8030DE58_lbl_80475848 chr_sel_a_slot_plate_layout_b;
s32 push_plate_position__19TAdPlyChrSelPlateGCFv(int, void *);
extern RecoveredGlobal_8030CEEC_lbl_80475818 lbl_80475818;
extern RecoveredGlobal_8030CEEC_lbl_80475858 lbl_80475858;
extern RecoveredGlobal_8030CEEC_lbl_80475878 lbl_80475878;
extern const CharacterSlotPosition lbl_80475838;
extern const CharacterSlotPosition lbl_80475890;
extern const CharacterSlotPosition lbl_80475898;
void set_entry_text__15TAdSubPlyItemGCFPvPv(void *item, G_8030C45C *entry);
void add_plate_rect__20TAdChrSelMovePlateGCFPvPv(void *plate, void *position);
extern const f32 lbl_805DF218;
s32 TAdChrSelASlotGC__sub_8030C3C0(TAdChrSelASlotGC *self, u32 arg1);
s32 is_slot_value_ready__19TAdPlyChrSelPlateGCFl(void *, int);
extern G_8030C45C chr_select_a_slot_entry;
G_8030C45C *TAdChrSelASlotGC__sub_8030C45C(TAdChrSelASlotGC *self, s32 arg1, s32 arg2, void *arg3);
int sprintf(char *, const char *, ...);
void *memset(void *, int, unsigned long);
extern char char_select_format_message_buffer[];
extern u8 TAdChrSelASlotGC__data_804758A8[];
extern u8 TAdChrSelASlotGC__data_804758B0[];
extern u8 TAdChrSelASlotGC__data_804758B8[];
extern const f32 TAdChrSelASlotGC__data_805DF208;
u32 TAdChrSelASlotGC__sub_8030CB08(TAdChrSelASlotGC *arg0, s32 kind, s32 text);
s32 TAdChrSelASlotGC__sub_8030C4F8(TAdChrSelASlotGC *self, s32 kind);
s32 TAdChrSelASlotGC__sub_8030C5C0(TAdChrSelASlotGC *self, s32 kind);
s32 TAdChrSelASlotGC__sub_8030C688(TAdChrSelASlotGC *self, s32 kind);
s32 check_room_seq_4__16TAdChrSelASlotGCFl(void *pos, s32 arg1);
s32 TAdChrSelSlotGC__sub_802C7498(s32, s32);
s32 TAdSubPlyItemGC__sub_802D6D88(s32);
s32 play_sound_effect(s32, s32, s32, s32);

extern f32 lbl_805DF210;

void TAdChrSelASlotGC::render() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

s32 TAdChrSelASlotGC__sub_8030C3C0(TAdChrSelASlotGC *self, u32 i) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(TAdSinglePlyChrSelectGC__sub_801FE4BC(i));
    if (temp_r3 == 0) {
        return 0;
    }
    return *(s32 *)((s8 *)temp_r3 + 8) == 1 ? 1 : 0;
}

s32 TAdChrSelASlotGC::get_plate_value_for_slot(s32 k) {
    Slot_8030C404 *o = (Slot_8030C404 *)this;
    switch (k) {
    case 0:
    case 1:
        return is_slot_value_ready__19TAdPlyChrSelPlateGCFl(o->a, 2);
    case 2:
        return is_slot_value_ready__19TAdPlyChrSelPlateGCFl(o->b, 2);
    }
    return 0;
}

G_8030C45C *TAdChrSelASlotGC__sub_8030C45C(TAdChrSelASlotGC *self, s32 arg1, s32 i, void *arg3) {
    S_8030C45C *e = (S_8030C45C *)TAdSinglePlyChrSelectGC__sub_801FE4BC(i);
    chr_select_a_slot_entry.a = arg1;
    chr_select_a_slot_entry.b = e != NULL ? e->x : get_localized_text_entry(0x16, 0x1C);
    chr_select_a_slot_entry.c = e != NULL ? e->y + 1 : 0;
    ((TWindowSubSymbolChatPartsSet *)(chr_select_a_slot_entry.v))->copy_vec2(arg3);
    return &chr_select_a_slot_entry;
}

s32 TAdChrSelASlotGC__sub_8030C4F8(TAdChrSelASlotGC *self, s32 kind) {
    V2_8030C750 pos;
    s32 w;
    switch (kind) {
    case 0:
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(*(s32 *)self->_pad20 == 2 ? TAdChrSelASlotGC__data_804758B0 : TAdChrSelASlotGC__data_804758A8);
        break;
    case 1:
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(TAdChrSelASlotGC__data_804758B8);
        break;
    }
    w = check_room_seq_4__16TAdChrSelASlotGCFl(&pos, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, get_localized_text_entry(0x16, kind + 0x2B), 0x20, 0);
    ((TAdChrSelASlotGC *)w)->set_flag_40();
    TQuestThread::set_status_flag_80((void *)w);
    ((TWindowSubComCard *)w)->calc_layout_height(TAdChrSelASlotGC__data_805DF208);
    return w;
}

s32 TAdChrSelASlotGC__sub_8030C5C0(TAdChrSelASlotGC *self, s32 kind) {
    V2_8030C750 pos;
    s32 w;
    switch (kind) {
    case 0:
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(*(s32 *)self->_pad20 == 2 ? TAdChrSelASlotGC__data_804758B0 : TAdChrSelASlotGC__data_804758A8);
        break;
    case 1:
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(TAdChrSelASlotGC__data_804758B8);
        break;
    }
    w = check_room_seq_4__16TAdChrSelASlotGCFl(&pos, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, get_localized_text_entry(0x16, kind + 0x29), 0x20, 0);
    ((TAdChrSelASlotGC *)w)->set_flag_40();
    TQuestThread::set_status_flag_80((void *)w);
    ((TWindowSubComCard *)w)->calc_layout_height(TAdChrSelASlotGC__data_805DF208);
    return w;
}

s32 TAdChrSelASlotGC__sub_8030C688(TAdChrSelASlotGC *self, s32 kind) {
    V2_8030C750 pos;
    s32 w;
    switch (kind) {
    case 0:
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(*(s32 *)self->_pad20 == 2 ? TAdChrSelASlotGC__data_804758B0 : TAdChrSelASlotGC__data_804758A8);
        break;
    case 1:
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(TAdChrSelASlotGC__data_804758B8);
        break;
    }
    w = check_room_seq_4__16TAdChrSelASlotGCFl(&pos, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, get_localized_text_entry(0x16, kind + 0x27), 0x20, 0);
    ((TAdChrSelASlotGC *)w)->set_flag_40();
    TQuestThread::set_status_flag_80((void *)w);
    ((TWindowSubComCard *)w)->calc_layout_height(TAdChrSelASlotGC__data_805DF208);
    return w;
}

s32 TAdChrSelASlotGC::open_confirm_message(s32 arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    V2_8030C750 pos;
    s32 w;
    w = create__19TWindowMessageYesNoFPvPvPvPv((s32)arg0, arg2, 0, 0);
    switch (arg1) {
    case 0:
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(*(s32 *)(arg0 + 0x20) == 2 ? TAdChrSelASlotGC__data_804758B0 : TAdChrSelASlotGC__data_804758A8);
        break;
    case 1:
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(TAdChrSelASlotGC__data_804758B8);
        break;
    }
    forward_slot_selection__16TAdChrSelASlotGCFPvPv(w, get_localized_text_entry(0x16, arg1 + 0x25), (s32)&pos, TAdChrSelASlotGC__data_805DF208);
    free_member__17TWindowSubComCardFv(w, 1);
    return w;
}

s32 TAdChrSelASlotGC::create_message_window(s32 arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    V2_8030C814 pos;
    s32 w;
    w = create__19TWindowMessageYesNoFPvPvPvPv((s32)arg0, arg2, 0, 0);
    switch (arg1) {
    case 0:
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(*(s32 *)(arg0 + 0x20) == 2 ? TAdChrSelASlotGC__data_804758B0 : TAdChrSelASlotGC__data_804758A8);
        break;
    case 1:
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(TAdChrSelASlotGC__data_804758B8);
        break;
    }
    forward_slot_selection__16TAdChrSelASlotGCFPvPv(w, get_localized_text_entry(0x16, arg1 + 0x23), (s32)&pos, TAdChrSelASlotGC__data_805DF208);
    free_member__17TWindowSubComCardFv(w, 1);
    return w;
}

s32 TAdChrSelASlotGC::create_format_message_window(s32 arg0, s32 arg1, s32 arg2) {
    s32 w;
    w = create__19TWindowMessageYesNoFPvPvPvPv(arg0, arg2, 0, 0);
    memset(char_select_format_message_buffer, 0, 0x100);
    sprintf(char_select_format_message_buffer, (const char *)get_localized_text_entry(0x16, 0x1E), 0x2710);
    forward_slot_selection__16TAdChrSelASlotGCFPvPv(w, (s32)char_select_format_message_buffer, arg1, lbl_805DF20C);
    free_member__17TWindowSubComCardFv(w, 1);
    return w;
}

#pragma push
#pragma fp_contract on
s32 TAdChrSelASlotGC__sub_8030C978(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;
    temp_r31 = create__19TWindowMessageYesNoFPvPvPvPv((s32)arg0, (s32)((void *)arg2), 0, 0);
    forward_slot_selection__16TAdChrSelASlotGCFPvPv(temp_r31, (s32)((int) (get_localized_text_entry(0x16, 0x1D))), arg1, lbl_805DF20C);
    free_member__17TWindowSubComCardFv(temp_r31, 1);
    return temp_r31;
}
#pragma pop

s32 TAdChrSelASlotGC::open_yes_no_window(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    play_sound_effect(0x53F06, 0, 0, 0);
    temp_r31 = create__19TWindowMessageYesNoFPvPvPvPv(arg0, arg2, 0, 0);
    forward_slot_selection__16TAdChrSelASlotGCFPvPv(temp_r31, get_localized_text_entry(0x16, 0x1B), arg1, lbl_805DF210);
    free_member__17TWindowSubComCardFv(temp_r31, 1);
    ((TWindowSubComCard *)temp_r31)->free_windows();
    return temp_r31;
}

s32 TAdChrSelASlotGC__sub_8030CA84(s32 arg0, s32 arg1) {
    s32 temp_r31;
    temp_r31 = create__19TWindowMessageYesNoFPvPvPvPv(arg0, (s32)((int) (TAdMultiPlyChrSelectGC::get_clamped_cursor())), 0, 0);
    forward_slot_selection__16TAdChrSelASlotGCFPvPv(temp_r31, (s32)((int) (get_localized_text_entry(0x16, 0x1A))), arg1, lbl_805DF214);
    free_member__17TWindowSubComCardFv(temp_r31, 1);
    ((TWindowSubComCard *)temp_r31)->free_windows();
    return temp_r31;
}

u32 TAdChrSelASlotGC__sub_8030CB08(TAdChrSelASlotGC *ad_chr_sel_a_slot_gc, s32 kind, s32 text) {
    TAdChrSelASlotGC *self = ad_chr_sel_a_slot_gc;
    V2_8030C750 pos;
    s32 w;
    switch (kind) {
    case 0:
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(*(s32 *)self->_pad20 == 2 ? TAdChrSelASlotGC__data_804758B0 : TAdChrSelASlotGC__data_804758A8);
        break;
    case 1:
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(TAdChrSelASlotGC__data_804758B8);
        break;
    }
    w = check_room_seq_4__16TAdChrSelASlotGCFl(&pos, 1);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, get_localized_text_entry(0x16, text), 0x21, 0);
    ((TAdChrSelASlotGC *)w)->set_flag_40();
    TQuestThread::set_status_flag_80((void *)w);
    ((TWindowSubComCard *)w)->calc_layout_height(TAdChrSelASlotGC__data_805DF208);
    return (u32)w;
}

void TAdChrSelASlotGC::sub_8030CBD0() {}
void TAdChrSelASlotGC::sub_8030CBD4() {}
void TAdChrSelASlotGC::update_load_state() {
    if (TAdPlayerLoadGC::get_instance() == 0) {
        if ((u32) (TAdPlayerLoadGC::get_load_result(0) + 0x10000) == 0xFF81U) {
            this->state = 0x13;
            return;
        }
        this->state = 0x14;
    }
}
void TAdChrSelASlotGC::set_state() {
    write_encrypted_save__23TAdSinglePlyChrSelectGCFv();
    TAdSinglePlyChrSelectGC__sub_801FDAAC();
    this->state = 0x12;
}
void TAdChrSelASlotGC::check_load_state() {
    if (TAdPlayerLoadGC::get_instance() == 0) {
        this->state = 1;
    }
}
void TAdChrSelASlotGC::init_selection() {
    write_encrypted_save__23TAdSinglePlyChrSelectGCFv();
    TAdSinglePlyChrSelectGC__sub_801FDAAC();
    this->state = 0x10;
}
void TAdChrSelASlotGC::sub_8030CCE0() {}

void TAdChrSelASlotGC::sub_8030CCE4() {
    u32 i;
    u32 j;

    if (this->get_plate_value_for_slot(*(s32 *)((s8 *)this + 0x20)) != 0) {
        switch (*(s32 *)((s8 *)this + 0x20)) {
        case 0:
            ((TAdChrSelSlotGC *)*(void **)((s8 *)this + 0x2C))->init_slot_entry(0, (void *)&lbl_80475838);
            for (i = 0; i < 4; i++) {
                set_entry_text__15TAdSubPlyItemGCFPvPv(*(void **)((s8 *)this + 0x3C), TAdChrSelASlotGC__sub_8030C45C(this, i, i, (u8 *)&lbl_80475818.value + i * 8));
                if (TAdChrSelASlotGC__sub_8030C3C0(this, i)) {
                    add_plate_rect__20TAdChrSelMovePlateGCFPvPv(*(void **)((s8 *)this + 0x44), (u8 *)&lbl_80475818.value + i * 8);
                }
            }
            break;
        case 1:
            ((TAdChrSelSlotGC *)*(void **)((s8 *)this + 0x2C))->init_slot_entry(0, (void *)&lbl_80475890);
            ((TAdChrSelSlotGC *)*(void **)((s8 *)this + 0x2C))->init_slot_entry(1, (void *)&lbl_80475898);
            for (i = 0; i < 4; i++) {
                set_entry_text__15TAdSubPlyItemGCFPvPv(*(void **)((s8 *)this + 0x3C), TAdChrSelASlotGC__sub_8030C45C(this, i, i, (u8 *)&lbl_80475858.value + i * 8));
                if (TAdChrSelASlotGC__sub_8030C3C0(this, i)) {
                    add_plate_rect__20TAdChrSelMovePlateGCFPvPv(*(void **)((s8 *)this + 0x44), (u8 *)&lbl_80475858.value + i * 8);
                }
            }
            for (j = 0; j < 3; j++) {
                set_entry_text__15TAdSubPlyItemGCFPvPv(*(void **)((s8 *)this + 0x40), TAdChrSelASlotGC__sub_8030C45C(this, j, j + 4, (u8 *)&lbl_80475878.value + j * 8));
            }
            break;
        case 2:
            ((TAdChrSelSlotGC *)*(void **)((s8 *)this + 0x2C))->init_slot_entry(1, (void *)&lbl_80475890);
            for (j = 0; j < 3; j++) {
                set_entry_text__15TAdSubPlyItemGCFPvPv(*(void **)((s8 *)this + 0x40), TAdChrSelASlotGC__sub_8030C45C(this, j, j + 4, (u8 *)&lbl_80475858.value + j * 8));
            }
            break;
        }
        this->state = 0xE;
    }
}

typedef char RecoveredGlobal_8030CEEC_lbl_80475818_size[sizeof(RecoveredGlobal_8030CEEC_lbl_80475818) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_8030CEEC_lbl_80475858_size[sizeof(RecoveredGlobal_8030CEEC_lbl_80475858) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_8030CEEC_lbl_80475878_size[sizeof(RecoveredGlobal_8030CEEC_lbl_80475878) == 0x18 ? 1 : -1];
void TAdChrSelASlotGC::sub_8030CEEC() {
    if (((TAdChrSelASlotGC *)(*(s32 *)((s8 *)this + 0x30)))->get_slot_index() >= 0xC) {
        switch (*(s32 *)((s8 *)this + 0x20)) {
        case 0:
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x34)), &lbl_80475818.value);
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x34)), (void *) ((u8 *)&lbl_80475818.value + 8));
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x34)), (void *) ((u8 *)&lbl_80475818.value + 0x10));
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x34)), (void *) ((u8 *)&lbl_80475818.value + 0x18));
            break;
        case 1:
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x34)), &lbl_80475858.value);
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x34)), (void *) ((u8 *)&lbl_80475858.value + 8));
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x34)), (void *) ((u8 *)&lbl_80475858.value + 0x10));
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x34)), (void *) ((u8 *)&lbl_80475858.value + 0x18));
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x38)), &lbl_80475878.value);
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x38)), (void *) ((u8 *)&lbl_80475878.value + 8));
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x38)), (void *) ((u8 *)&lbl_80475878.value + 0x10));
            *(s32 *)((s8 *)this + 0x4C) = ((s32)create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)this, 0x12, lbl_805DF218));
            *(s32 *)((s8 *)this + 0x50) = ((s32)create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)this, 0x13, lbl_805DF218));
            break;
        case 2:
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x38)), &lbl_80475858.value);
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x38)), (void *) ((u8 *)&lbl_80475858.value + 8));
            push_plate_position__19TAdPlyChrSelPlateGCFv((int) (*(s32 *)((s8 *)this + 0x38)), (void *) ((u8 *)&lbl_80475858.value + 0x10));
            break;
        }
        this->state = 0xD;
    }
}

void TAdChrSelASlotGC::update_window_78() {
    if (((TAdChrSelASlotGC *)(this->m_30))->get_slot_index() > 0xB) {
        if ((u32) this->m_78 != 0U) {
            ((TWindowBase *)this->m_78)->close();
            this->m_78 = 0U;
        }
        this->state = 0xC;
        return;
    }
    if (((s32) this->state_frames > 0xA) && ((u32) this->m_78 == 0U)) {
        this->m_78 = TAdChrSelASlotGC__sub_8030CB08(this, 0, 0x12);
    }
}

void TAdChrSelASlotGC::update_window_7c() {
    if (((TAdChrSelASlotGC *)(*(s32 *)&this->m_30))->get_slot_index() > 0xA) {
        if ((u32) *(u32 *)&this->unk_7C != 0U) {
            ((TWindowBase *)(*(void * *)&this->unk_7C))->close();
            *(u32 *)&this->unk_7C = 0U;
        }
        this->state = 0xB;
        return;
    }
    if (((s32) this->state_frames > 0xF) && ((u32) *(u32 *)&this->unk_7C == 0U)) {
        *(u32 *)&this->unk_7C = TAdChrSelASlotGC__sub_8030CB08(this, 0, 0x14);
    }
}

void TAdChrSelASlotGC::update_window_74() {
    if (((TAdChrSelASlotGC *)(*(s32 *)&this->m_30))->get_slot_index() > 8) {
        if ((u32) *(u32 *)&this->unk_74 != 0U) {
            ((TWindowBase *)(*(void * *)&this->unk_74))->close();
            *(u32 *)&this->unk_74 = 0U;
        }
        this->state = 0xA;
        return;
    }
    if (((s32) this->state_frames > 0xA) && ((u32) *(u32 *)&this->unk_74 == 0U)) {
        *(u32 *)&this->unk_74 = TAdChrSelASlotGC__sub_8030CB08(this, 0, 0x10);
    }
}

void TAdChrSelASlotGC::update_window_70() {
    if (((TAdChrSelASlotGC *)(this->m_30))->get_slot_index() > 7) {
        if ((u32) this->m_70 != 0U) {
            ((TWindowBase *)this->m_70)->close();
            this->m_70 = 0U;
        }
        this->state = 9;
        return;
    }
    if (((s32) this->state_frames > 0xA) && ((u32) this->m_70 == 0U)) {
        this->m_70 = TAdChrSelASlotGC__sub_8030CB08(this, 0, 0xE);
    }
}

void TAdChrSelASlotGC::update_window_6c() {
    if (((TAdChrSelASlotGC *)(*(s32 *)&this->m_30))->get_slot_index() > 6) {
        if ((u32) *(u32 *)&this->unk_6C != 0U) {
            ((TWindowBase *)(*(void * *)&this->unk_6C))->close();
            *(u32 *)&this->unk_6C = 0U;
        }
        this->state = 8;
        return;
    }
    if (((s32) this->state_frames > 0xA) && ((u32) *(u32 *)&this->unk_6C == 0U)) {
        *(u32 *)&this->unk_6C = TAdChrSelASlotGC__sub_8030CB08(this, 0, 0xC);
    }
}

void TAdChrSelASlotGC::update_slot5() {
    if (((TAdChrSelASlotGC *)(this->m_30))->get_slot_index() > 5) {
        if ((u32) this->m_68 != 0U) {
            ((TWindowBase *)this->m_68)->close();
            this->m_68 = 0U;
        }
        this->state = 7;
        return;
    }
    if (((s32) this->state_frames > 0xA) && ((u32) this->m_68 == 0U)) {
        this->m_68 = TAdChrSelASlotGC__sub_8030CB08(this, 0, 0xA);
    }
}

void TAdChrSelASlotGC::update_slot4() {
    if (((TAdChrSelASlotGC *)(*(s32 *)&this->m_30))->get_slot_index() > 4) {
        if ((u32) *(u32 *)&this->unk_64 != 0U) {
            ((TWindowBase *)(*(void * *)&this->unk_64))->close();
            *(u32 *)&this->unk_64 = 0U;
        }
        this->state = 6;
        return;
    }
    if (((s32) this->state_frames > 0xA) && ((u32) *(u32 *)&this->unk_64 == 0U)) {
        *(u32 *)&this->unk_64 = TAdChrSelASlotGC__sub_8030CB08(this, 0, 8);
    }
}

void TAdChrSelASlotGC::update_slot3() {
    if (((TAdChrSelASlotGC *)(this->m_30))->get_slot_index() > 3) {
        if ((u32) this->m_60 != 0U) {
            ((TWindowBase *)this->m_60)->close();
            this->m_60 = 0U;
        }
        this->state = 5;
        return;
    }
    if (((s32) this->state_frames > 0xA) && ((u32) this->m_60 == 0U)) {
        this->m_60 = TAdChrSelASlotGC__sub_8030CB08(this, 0, 6);
    }
}

void TAdChrSelASlotGC::update_slot2() {
    if (((TAdChrSelASlotGC *)(*(s32 *)&this->m_30))->get_slot_index() > 2) {
        if ((u32) *(u32 *)&this->unk_5C != 0U) {
            ((TWindowBase *)(*(void * *)&this->unk_5C))->close();
            *(u32 *)&this->unk_5C = 0U;
        }
        this->state = 4;
        return;
    }
    if (((s32) this->state_frames > 0xA) && ((u32) *(u32 *)&this->unk_5C == 0U)) {
        *(u32 *)&this->unk_5C = TAdChrSelASlotGC__sub_8030CB08(this, 0, 4);
    }
}

void TAdChrSelASlotGC::update_slot1() {
    if (((TAdChrSelASlotGC *)(this->m_30))->get_slot_index() > 1) {
        if ((u32) this->m_58 != 0U) {
            ((TWindowBase *)this->m_58)->close();
            this->m_58 = 0U;
        }
        this->state = 3;
        return;
    }
    if (((s32) this->state_frames > 0xA) && ((u32) this->m_58 == 0U)) {
        this->m_58 = TAdChrSelASlotGC__sub_8030CB08(this, 0, 2);
    }
}

void TAdChrSelASlotGC::sub_8030D5DC() {

    if ((u32) *(u32 *)((s8 *)this + 0x58) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x58)))->close();
        *(u32 *)((s8 *)this + 0x58) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x5C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x5C)))->close();
        *(u32 *)((s8 *)this + 0x5C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x60) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x60)))->close();
        *(u32 *)((s8 *)this + 0x60) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x64) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x64)))->close();
        *(u32 *)((s8 *)this + 0x64) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x68) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x68)))->close();
        *(u32 *)((s8 *)this + 0x68) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x6C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x6C)))->close();
        *(u32 *)((s8 *)this + 0x6C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x70) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x70)))->close();
        *(u32 *)((s8 *)this + 0x70) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x74) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x74)))->close();
        *(u32 *)((s8 *)this + 0x74) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x78) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x78)))->close();
        *(u32 *)((s8 *)this + 0x78) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x7C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)this + 0x7C)))->close();
        *(u32 *)((s8 *)this + 0x7C) = 0U;
    }
    switch (*(s32 *)((s8 *)this + 0x20)) {
    case 0:
        ((TAdPlyChrSelPlateGC *)(*(s32 *)((s8 *)this + 0x34)))->reset_selection_slots();
        TAdSubPlyItemGC__sub_802D6D88(*(s32 *)((s8 *)this + 0x3C));
        ((TAdChrSelMovePlateGC *)(*(s32 *)((s8 *)this + 0x44)))->clear_entries();
        break;
    case 1:
        ((TAdPlyChrSelPlateGC *)(*(s32 *)((s8 *)this + 0x34)))->reset_selection_slots();
        ((TAdPlyChrSelPlateGC *)(*(s32 *)((s8 *)this + 0x38)))->reset_selection_slots();
        TAdSubPlyItemGC__sub_802D6D88(*(s32 *)((s8 *)this + 0x3C));
        TAdSubPlyItemGC__sub_802D6D88(*(s32 *)((s8 *)this + 0x40));
        ((TAdChrSelMovePlateGC *)(*(s32 *)((s8 *)this + 0x44)))->clear_entries();
        if ((u32) *(u32 *)((s8 *)this + 0x4C) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x4C));
            *(u32 *)((s8 *)this + 0x4C) = 0U;
        }
        if ((u32) *(u32 *)((s8 *)this + 0x50) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x50));
            *(u32 *)((s8 *)this + 0x50) = 0U;
        }
        break;
    case 2:
        ((TAdPlyChrSelPlateGC *)(*(s32 *)((s8 *)this + 0x38)))->reset_selection_slots();
        TAdSubPlyItemGC__sub_802D6D88(*(s32 *)((s8 *)this + 0x40));
        break;
    }
    TAdChrSelSlotGC__sub_802C7498(*(s32 *)((s8 *)this + 0x2C), 0);
    TAdChrSelSlotGC__sub_802C7498(*(s32 *)((s8 *)this + 0x2C), 1);
    TAdChrSelSlotGC__sub_802C7498(*(s32 *)((s8 *)this + 0x2C), 2);
    if (((TAdChrSelASlotGC *)(*(s32 *)((s8 *)this + 0x30)))->get_slot_index() > 0) {
        if ((u32) *(u32 *)((s8 *)this + 0x54) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)this + 0x54)))->close();
            *(u32 *)((s8 *)this + 0x54) = 0U;
        }
        this->state = 2;
        return;
    }
    if (((s32) this->state_frames > 0xA) && ((u32) *(u32 *)((s8 *)this + 0x54) == 0U)) {
        *(u32 *)((s8 *)this + 0x54) = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)this, 0, 0);
    }
}

extern s32 lbl_80475840[];
extern s32 lbl_804758A0[];

void TAdChrSelASlotGC::close_windows() {

    ((TAdChrSelSlotGC *)(*(s32 *)&this->_pad2C))->reset_all_slots();
    if ((u32) this->m_48 != 0U) {
        queue_destruction__7TObjectFv(*(void * *)&this->m_48);
        this->m_48 = 0U;
    }
    if ((u32) *(u32 *)&this->unk_4C != 0U) {
        queue_destruction__7TObjectFv(*(void * *)&this->unk_4C);
        *(u32 *)&this->unk_4C = 0U;
    }
    if ((u32) this->m_50 != 0U) {
        queue_destruction__7TObjectFv(*(void * *)&this->m_50);
        this->m_50 = 0U;
    }
    if ((u32) *(u32 *)&this->unk_54 != 0U) {
        ((TWindowBase *)(*(void * *)&this->unk_54))->close();
        *(u32 *)&this->unk_54 = 0U;
    }
    if ((u32) this->m_58 != 0U) {
        ((TWindowBase *)(*(void * *)&this->m_58))->close();
        this->m_58 = 0U;
    }
    if ((u32) *(u32 *)&this->unk_5C != 0U) {
        ((TWindowBase *)(*(void * *)&this->unk_5C))->close();
        *(u32 *)&this->unk_5C = 0U;
    }
    if ((u32) this->m_60 != 0U) {
        ((TWindowBase *)(*(void * *)&this->m_60))->close();
        this->m_60 = 0U;
    }
    if ((u32) *(u32 *)&this->unk_64 != 0U) {
        ((TWindowBase *)(*(void * *)&this->unk_64))->close();
        *(u32 *)&this->unk_64 = 0U;
    }
    if ((u32) this->m_68 != 0U) {
        ((TWindowBase *)(*(void * *)&this->m_68))->close();
        this->m_68 = 0U;
    }
    if ((u32) *(u32 *)&this->unk_6C != 0U) {
        ((TWindowBase *)(*(void * *)&this->unk_6C))->close();
        *(u32 *)&this->unk_6C = 0U;
    }
    if ((u32) this->m_70 != 0U) {
        ((TWindowBase *)(*(void * *)&this->m_70))->close();
        this->m_70 = 0U;
    }
    if ((u32) *(u32 *)&this->unk_74 != 0U) {
        ((TWindowBase *)(*(void * *)&this->unk_74))->close();
        *(u32 *)&this->unk_74 = 0U;
    }
    if ((u32) this->m_78 != 0U) {
        ((TWindowBase *)(*(void * *)&this->m_78))->close();
        this->m_78 = 0U;
    }
    if ((u32) *(u32 *)&this->unk_7C != 0U) {
        ((TWindowBase *)(*(void * *)&this->unk_7C))->close();
        *(u32 *)&this->unk_7C = 0U;
    }
    switch (*(s32 *)&this->_pad20) {
    case 0:
        ((TAdPlyChrSelPlateGC *)(*(s32 *)&this->unk_34))->reset_selection_slots();
        TAdSubPlyItemGC__sub_802D6D88(*(s32 *)&this->unk_3C);
        break;
    case 1:
        ((TAdPlyChrSelPlateGC *)(*(s32 *)&this->unk_34))->reset_selection_slots();
        ((TAdPlyChrSelPlateGC *)(this->m_38))->reset_selection_slots();
        TAdSubPlyItemGC__sub_802D6D88(*(s32 *)&this->unk_3C);
        TAdSubPlyItemGC__sub_802D6D88(this->m_40);
        break;
    case 2:
        ((TAdPlyChrSelPlateGC *)(this->m_38))->reset_selection_slots();
        TAdSubPlyItemGC__sub_802D6D88(this->m_40);
        break;
    }
    switch (*(s32 *)&this->_pad20) {
    case 0:
        *(u32 *)&this->unk_4C = (u32)create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)this, 0xC, (f32)lbl_805DF218);
        ((TAdMcSelectGC *)(*(s32 *)&this->_pad2C))->init_slot(0, lbl_80475840);
        this->m_48 = (u32)create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)this, 0xB, (f32)lbl_805DF218);
        break;
    case 1:
        ((TAdMcSelectGC *)(*(s32 *)&this->_pad2C))->init_slot(0, lbl_80475840);
        this->m_48 = (u32)create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)this, 0xB, (f32)lbl_805DF218);
        break;
    case 2:
        ((TAdMcSelectGC *)(*(s32 *)&this->_pad2C))->init_slot(0, lbl_804758A0);
        this->m_48 = (u32)create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)this, 0xD, (f32)lbl_805DF218);
        *(u32 *)&this->unk_4C = (u32)create_draw_line_ctrl__13TAdMcSelectGCFiif((s32)this, 0x14, (f32)lbl_805DF218);
        break;
    }
    this->state = 1;
}

void TAdChrSelASlotGC::run_task() {
    if ((s32)this->state < 0 || (s32)this->state >= 21) {
        this->state = 1;
    }
    this->prev_state = this->state;
    if (((TAdChrSelASlotGC *)this->m_30)->get_slot_index() == 0 && (s32)this->state > 1) {
        this->state = 1;
    }
    static void (TAdChrSelASlotGC::*handlers[21])() = {
        &TAdChrSelASlotGC::close_windows,
        &TAdChrSelASlotGC::sub_8030D5DC,
        &TAdChrSelASlotGC::update_slot1,
        &TAdChrSelASlotGC::update_slot2,
        &TAdChrSelASlotGC::update_slot3,
        &TAdChrSelASlotGC::update_slot4,
        &TAdChrSelASlotGC::update_slot5,
        &TAdChrSelASlotGC::update_window_6c,
        &TAdChrSelASlotGC::update_window_70,
        &TAdChrSelASlotGC::update_window_74,
        &TAdChrSelASlotGC::update_window_7c,
        &TAdChrSelASlotGC::update_window_78,
        &TAdChrSelASlotGC::sub_8030CEEC,
        &TAdChrSelASlotGC::sub_8030CCE4,
        &TAdChrSelASlotGC::sub_8030CCE0,
        &TAdChrSelASlotGC::init_selection,
        &TAdChrSelASlotGC::check_load_state,
        &TAdChrSelASlotGC::set_state,
        &TAdChrSelASlotGC::update_load_state,
        &TAdChrSelASlotGC::sub_8030CBD4,
        &TAdChrSelASlotGC::sub_8030CBD0,
    };
    (this->*handlers[this->state])();
    if ((s32)this->state != (s32)this->prev_state) {
        this->state_frames = 0;
    }
    this->state_frames++;
}

void TAdChrSelASlotGC::create_children(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    s32 temp_r3_10;
    s32 temp_r3_11;
    s32 object;
    s32 temp_r3_13;
    s32 temp_r3_14;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 temp_r3_6;
    s32 temp_r3_7;
    s32 temp_r3_8;
    s32 temp_r3_9;
    s32 var_r0;
    s32 var_r0_10;
    s32 var_r0_11;
    s32 var_r0_12;
    s32 var_r0_13;
    s32 var_r0_14;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r0_6;
    s32 var_r0_7;
    s32 var_r0_8;
    s32 var_r0_9;
    temp_r3 = ((s32)__nw__7TObjectFUl(0x128));
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = __ct__15TAdChrSelSlotGCFP7TObject(temp_r3, arg0);
    }
    *(s32 *)&this->_pad2C = var_r0;
    switch (arg1) {
    case 0:
        temp_r3_2 = ((s32)__nw__7TObjectFUl(0x24));
        var_r0_2 = temp_r3_2;
        if (var_r0_2 != 0) {
            var_r0_2 = (s32)__ct__15TAdPlayerLoadGCFv((void *)temp_r3_2, (arg0), (void *)(0));
        }
        this->m_30 = var_r0_2;
        temp_r3_3 = ((s32)__nw__7TObjectFUl(0x3B4));
        var_r0_3 = temp_r3_3;
        if (var_r0_3 != 0) {
            var_r0_3 = __ct__19TAdPlyChrSelPlateGCFv(temp_r3_3, arg0, &chr_sel_a_slot_plate_layout.value);
        }
        *(s32 *)&this->unk_34 = var_r0_3;
        temp_r3_4 = ((s32)__nw__7TObjectFUl(0x48C));
        var_r0_4 = temp_r3_4;
        if (var_r0_4 != 0) {
            var_r0_4 = __ct__15TAdSubPlyItemGCFv(temp_r3_4, arg0);
        }
        *(s32 *)&this->unk_3C = var_r0_4;
        temp_r3_5 = ((s32)__nw__7TObjectFUl(0x208));
        var_r0_5 = temp_r3_5;
        if (var_r0_5 != 0) {
            var_r0_5 = __ct__20TAdChrSelMovePlateGCFv(temp_r3_5, arg0);
        }
        *(s32 *)&this->unk_44 = var_r0_5;
        return;
    case 1:
        temp_r3_6 = ((s32)__nw__7TObjectFUl(0x24));
        var_r0_6 = temp_r3_6;
        if (var_r0_6 != 0) {
            var_r0_6 = (s32)__ct__15TAdPlayerLoadGCFv((void *)temp_r3_6, (arg0), (void *)(1));
        }
        this->m_30 = var_r0_6;
        temp_r3_7 = ((s32)__nw__7TObjectFUl(0x3B4));
        var_r0_7 = temp_r3_7;
        if (var_r0_7 != 0) {
            var_r0_7 = __ct__19TAdPlyChrSelPlateGCFv(temp_r3_7, arg0, &chr_sel_a_slot_plate_layout.value);
        }
        *(s32 *)&this->unk_34 = var_r0_7;
        temp_r3_8 = ((s32)__nw__7TObjectFUl(0x3B4));
        var_r0_8 = temp_r3_8;
        if (var_r0_8 != 0) {
            var_r0_8 = __ct__19TAdPlyChrSelPlateGCFv(temp_r3_8, arg0, &chr_sel_a_slot_plate_layout_b.value);
        }
        this->m_38 = var_r0_8;
        temp_r3_9 = ((s32)__nw__7TObjectFUl(0x48C));
        var_r0_9 = temp_r3_9;
        if (var_r0_9 != 0) {
            var_r0_9 = __ct__15TAdSubPlyItemGCFv(temp_r3_9, arg0);
        }
        *(s32 *)&this->unk_3C = var_r0_9;
        temp_r3_10 = ((s32)__nw__7TObjectFUl(0x48C));
        var_r0_10 = temp_r3_10;
        if (var_r0_10 != 0) {
            var_r0_10 = __ct__15TAdSubPlyItemGCFv(temp_r3_10, arg0);
        }
        this->m_40 = var_r0_10;
        temp_r3_11 = ((s32)__nw__7TObjectFUl(0x208));
        var_r0_11 = temp_r3_11;
        if (var_r0_11 != 0) {
            var_r0_11 = __ct__20TAdChrSelMovePlateGCFv(temp_r3_11, arg0);
        }
        *(s32 *)&this->unk_44 = var_r0_11;
        return;
    case 2:
        object = ((s32)__nw__7TObjectFUl(0x24));
        var_r0_12 = object;
        if (var_r0_12 != 0) {
            var_r0_12 = (s32)__ct__15TAdPlayerLoadGCFv((void *)object, (arg0), (void *)(1));
        }
        this->m_30 = var_r0_12;
        temp_r3_13 = ((s32)__nw__7TObjectFUl(0x3B4));
        var_r0_13 = temp_r3_13;
        if (var_r0_13 != 0) {
            var_r0_13 = __ct__19TAdPlyChrSelPlateGCFv(temp_r3_13, arg0, &chr_sel_a_slot_plate_layout_b.value);
        }
        this->m_38 = var_r0_13;
        temp_r3_14 = ((s32)__nw__7TObjectFUl(0x48C));
        var_r0_14 = temp_r3_14;
        if (var_r0_14 != 0) {
            var_r0_14 = __ct__15TAdSubPlyItemGCFv(temp_r3_14, arg0);
        }
        this->m_40 = var_r0_14;
        return;
    }
}

void TAdChrSelASlotGC::init(s32 arg1) {
    this->state = 0;
    this->prev_state = 0;
    *(s32 *)&this->_pad20 = arg1;
    this->state_frames = -1;
    *(s32 *)&this->_pad2C = 0;
    this->m_30 = 0;
    *(s32 *)&this->unk_34 = 0;
    this->m_38 = 0;
    *(s32 *)&this->unk_3C = 0;
    this->m_40 = 0;
    *(s32 *)&this->unk_44 = 0;
    this->m_48 = 0;
    *(s32 *)&this->unk_4C = 0;
    this->m_50 = 0;
    *(s32 *)&this->unk_54 = 0;
    this->m_58 = 0;
    *(s32 *)&this->unk_5C = 0;
    this->m_60 = 0;
    *(s32 *)&this->unk_64 = 0;
    this->m_68 = 0;
    *(s32 *)&this->unk_6C = 0;
    this->m_70 = 0;
    *(s32 *)&this->unk_74 = 0;
    this->m_78 = 0;
    *(s32 *)&this->unk_7C = 0;
}

}
TAdChrSelASlotGC::~TAdChrSelASlotGC() {
    if ((u32) *(u32 *)((s8 *)this + 0x54) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x54));
        *(u32 *)((s8 *)this + 0x54) = 0U;
    }
    if ((u32) this->m_58 != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x58));
        this->m_58 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x5C) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x5C));
        *(u32 *)((s8 *)this + 0x5C) = 0U;
    }
    if ((u32) this->m_60 != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x60));
        this->m_60 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x64) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x64));
        *(u32 *)((s8 *)this + 0x64) = 0U;
    }
    if ((u32) this->m_68 != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x68));
        this->m_68 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x6C) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x6C));
        *(u32 *)((s8 *)this + 0x6C) = 0U;
    }
    if ((u32) this->m_70 != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x70));
        this->m_70 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x74) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x74));
        *(u32 *)((s8 *)this + 0x74) = 0U;
    }
    if ((u32) this->m_78 != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x78));
        this->m_78 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x7C) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x7C));
        *(u32 *)((s8 *)this + 0x7C) = 0U;
    }
    if ((u32) TAdChrSel__global_slot_data != 0U) {
        TAdChrSel__global_slot_data = 0U;
    }
}
extern void *TAdChrSelASlotGC__name;
TAdChrSelASlotGC::TAdChrSelASlotGC(TObject *object, void *arg2) : TObject(object) {
    *(void * *)&this->m_name = TAdChrSelASlotGC__name;
    this->init((s32)arg2);
    this->create_children((s32)arg2);
}

u8 *get_or_create_slot_window__22TAdMultiPlyChrSelectGCFii(s32 arg0, s32 arg1) {
    u8 *ad_chr_sel_a_slot_gc;
    u8 *var_r0;
    if ((void *) (*(u8 * *)&TAdChrSel__global_slot_data) != NULL) {
        return (*(u8 * *)&TAdChrSel__global_slot_data);
    }
    ad_chr_sel_a_slot_gc = (u8 *)(__nw__7TObjectFUl(0x80));
    var_r0 = ad_chr_sel_a_slot_gc;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(((u8 *)__ct__16TAdChrSelASlotGCFP7TObjectPv((void *)ad_chr_sel_a_slot_gc, (void *)arg0, (void *)arg1)));
    }
    (*(u8 * *)&TAdChrSel__global_slot_data) = var_r0;
    return var_r0;
}

s32 TAdChrSelASlotGC::get_slot_index() { return this->state_frames; }
