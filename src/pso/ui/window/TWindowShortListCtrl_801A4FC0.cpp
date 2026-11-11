#include "types.h"
#include "pso/unk/TUnk_804C2298.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/window/TWindowShortListCtrl_801A4FC0.h"
#include "pso/system/task/TObject_80019A50.h"

#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowShortListCtrl.h"

struct RecoveredGlobal_801A51C0_lbl_80446980 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
extern RecoveredGlobal_801A51C0_lbl_80446980 short_list_ctrl_interval_table;
void *TWindowOptionCtrl__ct(void *, void *);
void *__ct__10TAdTitleGCFP7TObjectl(void *, void *, int);
void *__ct__12TAdBackTxtGCFv(void *, void *);
void *__ct__9TAdBackGCFv(void *, void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void *__nw__7TObjectFUl(int);
void *get_character_save_record();

extern s32 __vt__13TUnk_804C2298[];

void *TUnk_804C2298::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804C2298;
        TLobby::stop_audio_streams();
        if (*(void * *)&(this->unk_2C) != NULL) { queue_destruction__7TObjectFv(*(void * *)&(this->unk_2C)); *(s32 *)&(this->unk_2C) = 0; }
        if (*(void * *)&(this->m_28) != NULL) { queue_destruction__7TObjectFv(*(void * *)&(this->m_28)); *(s32 *)&(this->m_28) = 0; }
        if (*(void * *)&(*(u32 *)((u8 *)this + 0x24)) != NULL) { queue_destruction__7TObjectFv(*(void * *)&(*(u32 *)((u8 *)this + 0x24))); *(s32 *)&(*(u32 *)((u8 *)this + 0x24)) = 0; }
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

extern void *tl_00;

}
TUnk_804C2298::TUnk_804C2298() : TObject((TObject *)tl_00) {
    void *o;
    void *o2;
    void *o3;
    void *o4;
    o = __nw__7TObjectFUl(0x24);
    if (o != NULL) {
        __ct__9TAdBackGCFv(o, this);
    }
    o2 = __nw__7TObjectFUl(0x28);
    if (o2 != NULL) {
        __ct__12TAdBackTxtGCFv(o2, this);
    }
    o3 = __nw__7TObjectFUl(0x138);
    if (o3 != NULL) {
        __ct__10TAdTitleGCFP7TObjectl(o3, this, 3);
    }
    TKeyBoardControl__sub_8000F90C(9);
    this->m_20 = 4;
    *(u8 *)((s8 *)this + 0x1C) = 0;
    this->m_1e = 0;
    o4 = __nw__7TObjectFUl(0x50);
    if (o4 != NULL) {
        o4 = TWindowOptionCtrl__ct(o4, this);
    }
    *(void **)((s8 *)this + 0x24) = o4;
    *(u32 *)((s8 *)this + 0x28) = 0;
    *(u32 *)((s8 *)this + 0x2C) = 0;
}


s32 TWindowShortListCtrl__sub_801A513C(void* p) { return *(s32*)((char*)p + 0x24); }
int TWindowShortListCtrl__sub_801A5144(void* p) { return *(u8*)((char*)p + 0x1d) & 0x1; }
s32 TWindowShortListCtrl::get_card_window_flags(s32 client_id) {
    void *character_save_record;

    character_save_record = get_character_save_record();
    if (character_save_record == NULL) {
        return 0;
    }
    return ((u32) *(u32 *)((s8 *)character_save_record + 0x10) >> 0x10U) & 3;
}
s32 TWindowShortListCtrl::get_card_status_bits() {
    void *character_save_record;

    character_save_record = get_character_save_record();
    if (character_save_record == NULL) {
        return 0;
    }
    return ((u32) *(u32 *)((s8 *)character_save_record + 0x10) >> 0xDU) & 7;
}

typedef char RecoveredGlobal_801A51C0_lbl_80446980_size[sizeof(RecoveredGlobal_801A51C0_lbl_80446980) == 0x18 ? 1 : -1];
s32 TLobby::get_table_entry_by_index() {
    return *(s32 *)((s8 *)&short_list_ctrl_interval_table.value + (fn_801A51F0() * 4));
}

s32 fn_801A51F0(void) {
    void *character_save_record;

    character_save_record = get_character_save_record();
    if (character_save_record == NULL) {
        return 0;
    }
    return ((u32) *(u32 *)((s8 *)character_save_record + 0x10) >> 0xAU) & 7;
}

