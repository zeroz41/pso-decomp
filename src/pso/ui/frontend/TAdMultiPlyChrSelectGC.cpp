#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"

struct RecoveredGlobal_802DFF0C___vt__22TAdMultiPlyChrSelectGC {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_802DFD9C___vt__22TAdMultiPlyChrSelectGC { s32 value; u8 remaining[0x14]; };

struct O_802DFFE8 { u8 pad[0x4ac]; s32 tbl[4][3]; u8 pad2[0x4ec - 0x4ac - 0x30]; s32 idx; };

struct O_802E0024 { u8 pad[0x4ac]; s32 tbl[4][3]; u8 pad2[0x4ec - 0x4ac - 0x30]; s32 idx; };

extern "C" {
u8 *__nw__7TObjectFUl(s32);
extern u8 *TAdMultiPlyChrSelectGC__instance;
u8 *get_or_create__22TAdMultiPlyChrSelectGCFii(s32 arg0, s32 arg1);
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_802DFF0C___vt__22TAdMultiPlyChrSelectGC __vt__22TAdMultiPlyChrSelectGC;
extern s32 lbl_805D3F68;
u8 *TAdMultiPlyChrSelectGC__ct(TAdMultiPlyChrSelectGC *arg0, u8 *arg1, s32 arg2);
void __dl__7TObjectFPv(s32);
s32 __dt__7TObjectFv(void *, int);
u8 *__dt__22TAdMultiPlyChrSelectGCFv(u8 *arg0, s16 arg1);
extern s32 multi_ply_chr_select_active_player;
s32 TAdMultiPlyChrSelectGC__sub_802DFFE8(O_802DFFE8 *self);
void TAdMultiPlyChrSelectGC__sub_802E0024(O_802E0024 *self, s32 v);
extern s32 lbl_805D68C8;
s32 TAdMultiPlyChrSelectGC__sub_802C658C();
int TAdMultiPlyChrSelectGC__sub_802C6920(void);
s32 is_slot_active__23TAdSinglePlyChrSelectGCFUi();

void TAdMultiPlyChrSelectGC::handle_event(s32 arg1) {
    void *temp_r3;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;

    switch (arg1) {
    case 10:
        temp_r3 = (void *)TAdMultiPlyChrSelectGC__sub_802C6920();
        TAdMultiPlyChrSelectGC::split_slot_index((s32)temp_r3, &sp14, &sp10);
        TAdMultiPlyChrSelectGC::init();
        ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_field_4ec(sp14);
        TAdMultiPlyChrSelectGC__sub_802E0024((O_802E0024 *)(this->m_5c), sp10);
        this->m_9c = 1;
        return;
    case 4:
        TAdMultiPlyChrSelectGC__sub_802C6920();
        TAdMultiPlyChrSelectGC__sub_802C658C();
        if (is_slot_active__23TAdSinglePlyChrSelectGCFUi() == 0) {
            temp_r3 = (void *)TAdMultiPlyChrSelectGC__sub_802C6920();
            TAdMultiPlyChrSelectGC::split_slot_index((s32)temp_r3, &spC, &sp8);
            TAdMultiPlyChrSelectGC::init();
            ((TAdMultiPlyChrSelectGC *)(this->m_5c))->set_field_4ec(spC);
            TAdMultiPlyChrSelectGC__sub_802E0024((O_802E0024 *)(this->m_5c), sp8);
        }
        this->m_9c = 1;
        return;
    }
}

    extern int TAdMultiPlyChrSelectGC__selected_slot;

typedef char RecoveredGlobal_802DFF0C___vt__22TAdMultiPlyChrSelectGC_size[sizeof(RecoveredGlobal_802DFF0C___vt__22TAdMultiPlyChrSelectGC) == 0x18 ? 1 : -1];

#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
#pragma dont_inline on
void TAdMultiPlyChrSelectGC::initialize_selection_state(s32 arg1) {
    s32 v;
    *(s32 *)&this->m_1c = 0;
    *(s32 *)&this->unk_30 = -1;
    this->m_34 = -1;
    *(s32 *)&this->_pad44 = 2;
    *(s32 *)&this->unk_38 = 0;
    *(s32 *)&this->unk_58 = 0;
    v = TAdMultiPlyChrSelectGC::get_clamped_cursor();
    *(s32 *)&this->m_4c = v;
    *(s32 *)&this->m_2c = 2;
    v = 0;
    *(s32 *)&this->m_48 = arg1;
    *(s32 *)&this->m_74 = v;
    lbl_805D68C8 = v;
    *(s32 *)&this->unk_50 = v;
    this->m_54 = 1;
    *(s32 *)&this->unk_68 = v;
    *(s32 *)&this->unk_60 = v;
    this->m_5c = v;
    *(s32 *)&this->unk_78 = v;
    *(s32 *)&this->unk_70 = v;
    this->m_7c = v;
    *(s32 *)&this->unk_80 = v;
    *(s32 *)&this->m_84 = v;
    *(s32 *)&this->unk_88 = v;
    this->m_8c = v;
    *(s32 *)&this->unk_90 = v;
    *(s32 *)&this->m_94 = v;
    *(s32 *)&this->unk_98 = v;
    *(s32 *)&this->m_3c = v;
    *(s32 *)&this->m_40 = v;
    this->m_9c = v;
    if (*(s32 *)&this->m_48 == 1) {
        v = 0x1D;
    }
    *(s32 *)&this->m_20 = v;
}
#pragma pop

u8 *__dt__22TAdMultiPlyChrSelectGCFv(u8 *arg0, s16 arg1) {
    u8 *global_state;
    u8 *temp_r3_10;
    u8 *temp_r3_11;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    u8 *temp_r3_5;
    u8 *temp_r3_6;
    u8 *temp_r3_7;
    u8 *temp_r3_8;
    u8 *temp_r3_9;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_802DFD9C___vt__22TAdMultiPlyChrSelectGC *)&__vt__22TAdMultiPlyChrSelectGC).value;
        global_state = (u8 *)(TAdMultiPlyChrSelectGC::get_global_state());
        if (global_state != NULL) {
            queue_destruction__7TObjectFv(global_state);
        }
        temp_r3_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x5C));
        if (temp_r3_2 != NULL) {
            queue_destruction__7TObjectFv(temp_r3_2);
            *(u8 **)((s8 *)arg0 + 0x5C) = NULL;
        }
        temp_r3_3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x78));
        if (temp_r3_3 != NULL) {
            queue_destruction__7TObjectFv(temp_r3_3);
            *(u8 **)((s8 *)arg0 + 0x78) = NULL;
        }
        temp_r3_4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x88));
        if (temp_r3_4 != NULL) {
            queue_destruction__7TObjectFv(temp_r3_4);
            *(u8 **)((s8 *)arg0 + 0x88) = NULL;
        }
        temp_r3_5 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x8C));
        if (temp_r3_5 != NULL) {
            queue_destruction__7TObjectFv(temp_r3_5);
            *(u8 **)((s8 *)arg0 + 0x8C) = NULL;
        }
        temp_r3_6 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x90));
        if (temp_r3_6 != NULL) {
            queue_destruction__7TObjectFv(temp_r3_6);
            *(u8 **)((s8 *)arg0 + 0x90) = NULL;
        }
        temp_r3_7 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x94));
        if (temp_r3_7 != NULL) {
            queue_destruction__7TObjectFv(temp_r3_7);
            *(u8 **)((s8 *)arg0 + 0x94) = NULL;
        }
        temp_r3_8 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x98));
        if (temp_r3_8 != NULL) {
            queue_destruction__7TObjectFv(temp_r3_8);
            *(u8 **)((s8 *)arg0 + 0x98) = NULL;
        }
        temp_r3_9 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x7C));
        if (temp_r3_9 != NULL) {
            queue_destruction__7TObjectFv(temp_r3_9);
            *(u8 **)((s8 *)arg0 + 0x7C) = NULL;
        }
        temp_r3_10 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x80));
        if (temp_r3_10 != NULL) {
            queue_destruction__7TObjectFv(temp_r3_10);
            *(u8 **)((s8 *)arg0 + 0x80) = NULL;
        }
        temp_r3_11 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x84));
        if (temp_r3_11 != NULL) {
            queue_destruction__7TObjectFv(temp_r3_11);
            *(u8 **)((s8 *)arg0 + 0x84) = NULL;
        }
        if ((u32) (*(u32 *)&TAdMultiPlyChrSelectGC__instance) != 0U) {
            (*(u32 *)&TAdMultiPlyChrSelectGC__instance) = 0U;
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

u8 *TAdMultiPlyChrSelectGC__ct(TAdMultiPlyChrSelectGC *ad_multi_ply_chr_select_gc, u8 *arg1, s32 arg2) {
    __ct__7TObjectFP7TObject(ad_multi_ply_chr_select_gc, arg1);
    *(s32 **)((s8 *)ad_multi_ply_chr_select_gc + 0x18) = &__vt__22TAdMultiPlyChrSelectGC.value;
    *(s32 *)((s8 *)ad_multi_ply_chr_select_gc + 0) = (s32) lbl_805D3F68;
    ad_multi_ply_chr_select_gc->initialize_selection_state(arg2);
    ad_multi_ply_chr_select_gc->create_widgets();
    ad_multi_ply_chr_select_gc->handle_event(TAdMultiPlyChrSelectGC::get_select_flag());
    return (u8 *)ad_multi_ply_chr_select_gc;
}

u8 *get_or_create__22TAdMultiPlyChrSelectGCFii(s32 arg0, s32 arg1) {
    u8 *ad_multi_ply_chr_select_gc;
    u8 *var_r0;
    if ((void *) TAdMultiPlyChrSelectGC__instance != NULL) {
        return TAdMultiPlyChrSelectGC__instance;
    }
    ad_multi_ply_chr_select_gc = (u8 *)(__nw__7TObjectFUl(0xA0));
    var_r0 = ad_multi_ply_chr_select_gc;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TAdMultiPlyChrSelectGC__ct((TAdMultiPlyChrSelectGC *)((u8 *)ad_multi_ply_chr_select_gc), (u8 *)((u8 *)arg0), (s32)((s32)arg1)));
    }
    TAdMultiPlyChrSelectGC__instance = var_r0;
    return var_r0;
}

int TAdMultiPlyChrSelectGC::get_instance() {  return TAdMultiPlyChrSelectGC__selected_slot; }

s32 TAdMultiPlyChrSelectGC__sub_802DFFE8(O_802DFFE8 *self) {
    return self->tbl[multi_ply_chr_select_active_player][self->idx];
}

void TAdMultiPlyChrSelectGC::set_state_ready() { *(s32*)((char*)this + 0x4fc) = 1; }
s32 TAdMultiPlyChrSelectGC::get_cursor() { return *(s32*)((char*)this + 0x4ec); }
void TAdMultiPlyChrSelectGC::set_state(s32 v) { *(s32*)((char*)this + 0x4f8) = v; }

void TAdMultiPlyChrSelectGC__sub_802E0024(O_802E0024 *self, s32 v) {
    self->tbl[multi_ply_chr_select_active_player][self->idx] = v;
}

s32 TAdMultiPlyChrSelectGC::get_card_index() { return *(s32*)((char*)this + 0x4e8); }

    extern int ad_chr_sel_ply_plate_instance;
int TAdMultiPlyChrSelectGC::get_card_instance() {  return ad_chr_sel_ply_plate_instance; }

s32 TAdMultiPlyChrSelectGC::get_selection() { return *(s32*)((char*)this + 0x4f8); }

    extern int TAdMultiPlyChrSelectGC__select_mode;
void TAdMultiPlyChrSelectGC::set_select_mode(int a0, int a1) { TAdMultiPlyChrSelectGC__select_mode = a1; }

}
