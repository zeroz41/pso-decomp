#include "types.h"
#include "pso/ui/window/TWindowSubEquip.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"

#pragma readonly_strings on

const char *TWindowSubEquip__class_name = "TWindowSubEquip";

// Sizes of the equipment list (ctor) and equipment kind (open_equip_kind_list) windows, passed next to
// their layout positions. inferred: names from the create_*_window argument they fill.
static const NJS_POINT2 equip_list_window_size = {308.0f, 184.0f};
static const NJS_POINT2 equip_kind_window_size = {308.0f, 124.0f};


struct VBase_80277F4C { u8 pad[0x18]; };

class VObj_80277F4C : public VBase_80277F4C {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
};

extern "C" {
s32 set_depth__11TWindowBaseFf(int);
f32 TWindowSubEquip__sub_80263AF8(u8 *arg0, u32 arg1);
void *get_window_layout_position(int);
s32 mark_unequippable_items(int);
s32 create_equip_kind_window(void *, const NJS_POINT2 *, int);
void *get_player_by_client_id(s32 i);
s32 play_sound_effect(s32, s32, s32, s32);
s32 fn_80255A38(s32);
s32 TWindowSubEquip__sub_80263AF4(void *, s32);
extern u8 controller_input_state[];
saddr __ct__15TWindowHelpItemFPvUs(void *, void *, s32);
s32 create_equip_list_window(void *, const NJS_POINT2 *, s32);
}

// Built with deferred code generation (the vtable precedes the switch table
// in .data), so the functions are written from the last one back.
TWindowSubEquip::TWindowSubEquip(saddr arg1, s32 arg2) : TObject((TObject *)((void *)arg1)) {
    void *p;
    m_name = TWindowSubEquip__class_name;
    this->m_2c = arg1;
    this->m_28 = arg2;
    this->m_34 = create_equip_list_window(get_window_layout_position(0), &equip_list_window_size, this->m_28);
    ((TWindowBase *)this->m_34)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)this->m_2c, 0));
    ((TWindowSubShortCutList *)(this->m_34))->set_flag70_bit10();
    p = TObject::operator new(0xBC);
    if (p != 0) {
        p = (void *)__ct__15TWindowHelpItemFPvUs(p, get_window_layout_position(2), this->m_28);
    }
    *(void **)((s8 *)this + 0x30) = p;
    ((TWindowBase *)this->m_30)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)this->m_2c, 2));
    this->m_38 = 0;
    this->m_20 = -1;
    this->m_24 = -1;
    this->m_1c = 0;
}

TWindowSubEquip::~TWindowSubEquip() {
    if (*(void **)((s8 *)this + 0x38) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x38)))->close(); this->m_38 = 0; }
    if (*(void **)((s8 *)this + 0x34) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x34)))->close(); this->m_34 = 0; }
    if (*(void **)((s8 *)this + 0x30) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x30)))->close(); this->m_30 = 0; }
}

void TWindowSubEquip::run_task() {
    s32 temp_r3;
    s32 temp_r5;
    u8 temp_r0;
    temp_r3 = is_player_input_active(this->m_28);
    temp_r0 = this->m_1c;
    switch ((s32) temp_r0) {
    case 0:
    case 1:
        if ((u32) this->m_38 != 0U) {
            TWindowSubEquip__sub_80263AF4(*(void * *)&this->m_2c, 1);
            ((TWindowBase *)this->m_38)->close();
            this->m_38 = 0U;
        }
        fn_80255A38(this->m_30);
        this->m_20 = -1;
        this->m_24 = -1;
        ((TWindowSubEquip *)(this->m_34))->update_window();
        ((TWindowMenuIconLine *)(this->m_34))->clear_decided();
        ((TWindowSubMag *)(this->m_34))->start_scroll(188.0f);
        this->m_1c = 2U;
    case 2:
        update();
        if (((TWindowMenuIconLine *)(this->m_34))->is_cancelled() != 0) {
            VObj_80277F4C *o = *(VObj_80277F4C * *)&this->m_2c;
            o->v7();
            this->m_1c = 6U;
            return;
        }
        if (((TWindowMenuIconLine *)(this->m_34))->is_decided() != 0) {
            this->m_1c = 3U;
        }
        break;
    case 3:
        ((TWindowSubStatusDisp *)(this->m_34))->init_scroll_pos();
        if ((u32) this->m_38 == 0U) {
            this->m_38 = open_equip_kind_list(((TWindowMenuIconLine *)this->m_34)->get_cursor_value());
        }
        ((TWindowMenuIconLine *)(this->m_38))->clear_decided();
        this->m_1c = 4U;
    case 4:
        update_displayed_item();
        if (((TWindowMenuIconLine *)(this->m_38))->is_cancelled() != 0) {
            this->m_1c = 1U;
            return;
        }
        if (((TWindowMenuIconLine *)(this->m_38))->is_decided() != 0) {
            this->m_1c = 5U;
            return;
        }
        break;
    case 5:
        temp_r5 = temp_r3 * 0x50;
        if ((TWindowShortListCtrl__check_controller_button(controller_input_state + temp_r5 + 0x20, 2) != 0) || (test_controller_flag_4c_color(controller_input_state + 0x160, 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->m_1c = 3U;
            return;
        }
        void *selected_player;
        if (((selected_player = get_player_by_client_id(this->m_28)) != 0U) && (TWindowSubItem::is_usable((saddr)selected_player) != 0)) {
            apply_slot_selection();
            this->m_1c = 1U;
        }
        break;
    case 6:
        break;
    }
}

void TWindowSubEquip::render() {  }

s32 TWindowSubEquip::open_equip_kind_list(u32 arg1) {
    saddr equip_kind_window;
    equip_kind_window = create_equip_kind_window(get_window_layout_position(1), &equip_kind_window_size, this->m_28);
    TWindowSubEquip__sub_80263AF8((u8 *)this->m_2c, 1);
    set_depth__11TWindowBaseFf(equip_kind_window);
    ((TWindowMenuIconLine *)equip_kind_window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x24)));
    ((TWindowSubShortCutList *)equip_kind_window)->set_flag70_bit10();
    switch (arg1) {
    case 6:
        ((TWindowSubMag *)equip_kind_window)->init_and_setup((void*)0);
        break;
    case 2:
        ((TShopArmorListWindow *)equip_kind_window)->save_and_refresh_cursor((void*)1, (void*)1);
        break;
    case 9:
    case 10:
    case 11:
    case 12:
        ((TShopArmorListWindow *)equip_kind_window)->save_and_refresh_cursor((void*)1, (void*)3);
        break;
    case 3:
        ((TShopArmorListWindow *)equip_kind_window)->save_and_refresh_cursor((void*)1, (void*)2);
        break;
    case 1:
        ((TWindowSubMag *)equip_kind_window)->init_and_setup((void*)2);
        break;
    }
    mark_unequippable_items(equip_kind_window);
    return equip_kind_window;
}

void TWindowSubEquip::apply_slot_selection() {
    s32 temp_r31;
    temp_r31 = ((TWindowMenuIconLine *)this->m_34)->get_cursor_value();
    TWindowShortListCtrl::assign_shortcut(temp_r31, (int) (((TWindowMenuIconLine *)this->m_38)->get_cursor_value()), this->m_28);
}
