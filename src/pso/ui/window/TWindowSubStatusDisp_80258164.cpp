#include "types.h"
#include <string.h>
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TWindowStatusGauge.h"
#include "pso/unk/TUnk_804CF998.h"
#include "pso/ui/window/TWindowSubStatusDisp_80256B94.h"
#include "pso/ui/window/TWindowSubStatusDisp_80257BC0.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/map/FloorArea.h"
#include "pso/render/render_util.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

extern "C" {
void mem_free(void *);
s32 mem_alloc(s32);
}

// Screen x, y of each item icon slot (indexed by get_entry_ptr).
extern const f32 status_disp_item_icon_coord_table[51][2] = {
    { 161.0f, 98.0f },
    { 179.0f, 98.0f },
    { 197.0f, 98.0f },
    { 215.0f, 98.0f },
    { 233.0f, 98.0f },
    { 161.0f, 116.0f },
    { 179.0f, 116.0f },
    { 197.0f, 116.0f },
    { 215.0f, 116.0f },
    { 233.0f, 116.0f },
    { 161.0f, 134.0f },
    { 179.0f, 134.0f },
    { 197.0f, 134.0f },
    { 215.0f, 134.0f },
    { 233.0f, 134.0f },
    { 161.0f, 152.0f },
    { 179.0f, 152.0f },
    { 197.0f, 152.0f },
    { 215.0f, 152.0f },
    { 233.0f, 152.0f },
    { 161.0f, 170.0f },
    { 179.0f, 170.0f },
    { 197.0f, 170.0f },
    { 215.0f, 170.0f },
    { 233.0f, 170.0f },
    { 233.0f, 224.0f },
    { 197.0f, 224.0f },
    { 215.0f, 224.0f },
    { 72.0f, 238.0f },
    { 90.0f, 238.0f },
    { 108.0f, 238.0f },
    { 126.0f, 238.0f },
    { 161.0f, 188.0f },
    { 179.0f, 188.0f },
    { 197.0f, 188.0f },
    { 215.0f, 188.0f },
    { 233.0f, 188.0f },
    { 161.0f, 206.0f },
    { 179.0f, 206.0f },
    { 197.0f, 206.0f },
    { 215.0f, 206.0f },
    { 233.0f, 206.0f },
    { 161.0f, 224.0f },
    { 179.0f, 224.0f },
    { 54.0f, 238.0f },
    { 197.0f, 80.0f },
    { 215.0f, 80.0f },
    { 233.0f, 80.0f },
    { 197.0f, 62.0f },
    { 215.0f, 62.0f },
    { 233.0f, 62.0f },
};

extern "C" {

void TWindowSubStatusDisp::advance_state() {
    if ((u8) reinterpret_cast<ItemListRow *>(this)->category_icon == 0x14) {
        reinterpret_cast<ItemListRow *>(this)->category_icon = 0x15U;
    }
}

void TWindowSubStatusDisp::finalize_state() {
    if ((u8) reinterpret_cast<ItemListRow *>(this)->category_icon == 0x15) {
        reinterpret_cast<ItemListRow *>(this)->category_icon = 0x14U;
    }
}

void mem_free(void *p);

void TWindowSubStatusDisp::reset(void *arg0) {
    *(s8 *)((s8 *)arg0 + 0x1C) = 0x33;
    *(s8 *)((s8 *)arg0 + 0x1D) = 0x33;
    *(s32 *)((s8 *)arg0 + 0x28) = -1;
    *(s32 *)((s8 *)arg0 + 0x2C) = -1;
    *(s32 *)((s8 *)arg0 + 0x30) = -1;
    *(s32 *)((s8 *)arg0 + 0x34) = -1;
    *(s32 *)((s8 *)arg0 + 0x18) = 0;
    if (((u32) *(u32 *)((s8 *)arg0 + 0x24) != 0U) && (*(u16 *)((s8 *)arg0 + 0) & 0x10)) {
        mem_free((void *)(*(uaddr *)((s8 *)arg0 + 0x24)));
    }
    *(u32 *)((s8 *)arg0 + 0x24) = 0U;
    if (((u32) *(u32 *)((s8 *)arg0 + 0x20) != 0U) && (*(u16 *)((s8 *)arg0 + 0) & 8)) {
        mem_free((void *)(*(uaddr *)((s8 *)arg0 + 0x20)));
    }
    *(u32 *)((s8 *)arg0 + 0x20) = 0U;
    *(u16 *)((s8 *)arg0 + 0) = (u16) (*(u16 *)((s8 *)arg0 + 0) & ~0x1BFD);
}

void update_stat_line__20TWindowSubStatusDispFPvi(void *arg0, s32 arg1);
saddr get_shared_text_buffer();
s32 text_builder_append_int(s32);
void text_builder_append(u8 *str);
}
void text_builder_reset(void);

extern s32 lbl_805DCF00;

void update_stat_line__20TWindowSubStatusDispFPvi(void *window_sub_status_disp, s32 arg1) {
    text_builder_reset();
    text_builder_append((u8 *)&lbl_805DCF00);
    text_builder_append_int(arg1);
    *(s32 *)((s8 *)window_sub_status_disp + 0x24) = replace_owned_string__20TWindowSubStatusDispFPviiii(window_sub_status_disp, get_shared_text_buffer(), *(s32 *)((s8 *)window_sub_status_disp + 0x24), 0x10, 1);
}

void update_stat_line_if_positive__20TWindowSubStatusDispFPvi(void *arg0, s32 arg1);

void update_stat_line_if_positive__20TWindowSubStatusDispFPvi(void *arg0, s32 count) {
    if (count > 0) {
        ((void (*)(void *))update_stat_line__20TWindowSubStatusDispFPvi)(arg0);
    }
}

struct VBase18B_802582c4_80257784 { char pad[0x18]; };
struct VObj18B_802582c4_80257784 : VBase18B_802582c4_80257784 {
    virtual void vpad0(); virtual void vpad1(); virtual void vpad2(); virtual void vpad3();
    virtual void vpad4(); virtual void vpad5(); virtual void vpad6(); virtual void vpad7();
    virtual void vpad8(); virtual void vpad9(); virtual void vpad10(); virtual void vpad11();
    virtual void vpad12(); virtual void vpad13(); virtual void vpad14(); virtual void vpad15();
    virtual void vpad16(); virtual void vpad17(); virtual void vpad18(); virtual void vpad19();
    virtual void vpad20(); virtual void vpad21(); virtual void vpad22(); virtual void vpad23();
    virtual void vpad24(); virtual void vpad25(); virtual void vpad26(); virtual void vpad27();
    virtual void vpad28(); virtual void vpad29(); virtual void vpad30(); virtual void vpad31();
    virtual void vpad32();
    virtual s32 vm8C();
};

struct Obj_80258BB8 { u8 pad[8]; f32 f8; };

extern "C" {
extern const f32 lbl_805DCF04;
extern const f32 lbl_805DCF08;
void TWindowSubStatusDisp__sub_80258A28(u8 *arg0, s32 arg1, s32 arg2);
void init_status_entry__20TWindowSubStatusDispFPvcUii(u8 *arg0, s8 arg1, u32 arg2, s32 arg3);
void select_item_icon__20TWindowSubStatusDispFPviUcUci(void *arg0, s32 arg1, u8 arg2, u8 arg3, s32 arg4);
void *get_player_by_client_id(s32 i);

void TWindowSubStatusDisp::update_item_icon_colors(void *item) {
    s16 sp8;
    s32 temp_r26;
    s32 temp_r27;
    s32 temp_r28;
    s32 temp_r28_2;
    saddr player;

    if (((TItem *)item)->is_wrapped() != 0) {
        *(s32 *)((s8 *)this + 0x30) = -1;
        return;
    }
    player = (saddr)get_player_by_client_id(*(s16 *)((s8 *)this + 2));
    if (player != 0) {
        temp_r26 = ((TItem *)item)->test_item_flags(8);
        temp_r28 = ((TItem *)item)->get_usable_action_flags(0x10, (TObjPlayer *)player);
        temp_r27 = ((TItem *)item)->check_equip_requirements((TObjPlayer *)player, (s16 *)(&sp8));
        temp_r28_2 = ((VObj18B_802582c4_80257784 *) item)->vm8C();
        if (temp_r28 != 0) {
            if (temp_r26 != 0) {
                *(s8 *)((s8 *)this + 0x1C) = 0x30;
            } else {
                *(s8 *)((s8 *)this + 0x1C) = 0x2F;
            }
        } else if (temp_r26 != 0) {
            *(s8 *)((s8 *)this + 0x1C) = 0xC;
        } else {
            if ((temp_r28_2 == 0) && (((TItem *)item)->is_rare_item() != 0)) {
                *(s8 *)((s8 *)this + 0x1C) = 0x19;
            } else if (sp8 & 1) {
                *(s8 *)((s8 *)this + 0x1C) = 0x13;
            } else {
                *(s8 *)((s8 *)this + 0x1C) = 0x33;
            }
            *(s32 *)((s8 *)this + 0x28) = -1;
        }
        if (temp_r28_2 == 0) {
            this->window_flags = -1;
            *(s32 *)((s8 *)this + 0x30) = 0xFF00FFFC;
            return;
        }
        if (temp_r27 != 0) {
            this->window_flags = -1;
            if (((TItem *)item)->is_custom_name_srank() != 0) {
                *(s32 *)((s8 *)this + 0x30) = 0xFFFE3C28;
                return;
            }
            if (((TItem *)item)->get_name_style() == 2) {
                *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x800);
                return;
            }
            if ((u8)((TItem *)item)->calc_display_grade() >= 9U) {
                *(s32 *)((s8 *)this + 0x30) = -0x1600;
                return;
            }
            if (((TItem *)item)->has_bonus_stats() != 0) {
                *(s32 *)((s8 *)this + 0x30) = 0xFF61E853;
                return;
            }
            if (((TItem *)item)->get_usable_action_flags(0x10000, (TObjPlayer *)player) != 0U) {
                *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
                return;
            }
            *(s32 *)((s8 *)this + 0x30) = -1;
            return;
        }
        if (sp8 & 1) {
            *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
            this->window_flags = 0xFFAAAAAA;
            return;
        }
        *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
        this->window_flags = 0xFFAAAAAA;
    }
}

void TWindowSubStatusDisp::update_item_colors(saddr item) {
    s32 sp8;
    s32 temp_r29;
    s32 temp_r30;
    saddr player;

    if (TItemData::is_wrapped((void *)item) != 0) {
        *(s32 *)((s8 *)this + 0x30) = -1;
        return;
    }
    player = (saddr)get_player_by_client_id(*(s16 *)((s8 *)this + 2));
    if (player != 0) {
        temp_r29 = check_equip_requirements((void *)player, (TItemData *)item, &sp8);
        temp_r30 = ((TItemData *)item)->check_item_flags();
        if ((u8) *(u8 *)((s8 *)this + 0x1C) == 0x33) {
            if ((temp_r30 == 0) && (TItemData::is_rare_item((u8 *)item) != 0)) {
                *(u8 *)((s8 *)this + 0x1C) = 0x19U;
            } else if (sp8 & 1) {
                *(u8 *)((s8 *)this + 0x1C) = 0x13U;
            }
            *(s32 *)((s8 *)this + 0x28) = -1;
        }
        if (temp_r30 == 0) {
            reinterpret_cast<ItemListRow *>(this)->category_style = -1;
            *(s32 *)((s8 *)this + 0x30) = 0xFF00FFFC;
            return;
        }
        if (temp_r29 != 0) {
            reinterpret_cast<ItemListRow *>(this)->category_style = -1;
            if (TItemData::is_custom_name_srank((u8 *)item) != 0) {
                *(s32 *)((s8 *)this + 0x30) = 0xFFFE3C28;
                return;
            }
            if (((TItemData *)item)->get_name_style() == 2) {
                *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x800);
                return;
            }
            if ((u8)((TItemData *)item)->calc_display_grade() >= 9U) {
                *(s32 *)((s8 *)this + 0x30) = -0x1600;
                return;
            }
            if (((TItemData *)item)->has_bonus_stats() != 0) {
                *(s32 *)((s8 *)this + 0x30) = 0xFF61E853;
                return;
            }
            if (((TItemData *)item)->calc_action_flags(0x10000, (u8 *)player) != 0U) {
                *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
                return;
            }
            *(s32 *)((s8 *)this + 0x30) = -1;
            return;
        }
        if (sp8 & 1) {
            *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
            reinterpret_cast<ItemListRow *>(this)->category_style = 0xFFAAAAAA;
            return;
        }
        *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
        reinterpret_cast<ItemListRow *>(this)->category_style = 0xFFAAAAAA;
    }
}

void select_item_icon__20TWindowSubStatusDispFPviUcUci(void *arg0, s32 item_data, u8 arg2, u8 arg3, s32 arg4) {
    if (arg4 != 0) {
        *(s8 *)((s8 *)arg0 + 0x1D) = 8;
        return;
    }
    switch (item_data) {
    case 1:
        *(s8 *)((s8 *)arg0 + 0x1D) = 0;
        return;
    case 3:
        *(s8 *)((s8 *)arg0 + 0x1D) = 1;
        return;
    case 2:
        *(s8 *)((s8 *)arg0 + 0x1D) = 2;
        return;
    default:
        switch ((s32) arg2) {
        case 1:
            if (arg3 == 3) {
                *(s8 *)((s8 *)arg0 + 0x1D) = 4;
                return;
            }
            if (arg3 == 2) {
                *(s8 *)((s8 *)arg0 + 0x1D) = 0xA;
                return;
            }
            *(s8 *)((s8 *)arg0 + 0x1D) = 0xB;
            return;
        case 2:
            *(s8 *)((s8 *)arg0 + 0x1D) = 3;
            return;
        case 3:
            if (arg3 == 0) {
                *(s8 *)((s8 *)arg0 + 0x1D) = 5;
                return;
            }
            if (arg3 == 1) {
                *(s8 *)((s8 *)arg0 + 0x1D) = 7;
                return;
            }
            if (arg3 == 2) {
                *(s8 *)((s8 *)arg0 + 0x1D) = 6;
                return;
            }
            *(s8 *)((s8 *)arg0 + 0x1D) = 8;
            return;
        case 4:
            *(s8 *)((s8 *)arg0 + 0x1D) = 9;
            return;
        case 0:
        default:
            *(s8 *)((s8 *)arg0 + 0x1D) = 0x33;
            return;
        }
        break;
    }
}

void TWindowSubStatusDisp::setup_entry_msg_d1(s32 arg1) {
    *(f32 *)((s8 *)((u8 *)this) + 8) = (f32) lbl_805DCF04;
    *(s8 *)&reinterpret_cast<ItemListRow *>(this)->status_icon = 0x33;
    reinterpret_cast<ItemListRow *>(this)->category_icon = 0x33;
    *(s32 *)((s8 *)((u8 *)this) + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (s32)((saddr) (TWindowSubStatusDisp::get_message_10(0xD1))), (s32)((int) (*(s32 *)((s8 *)((u8 *)this) + 0x20))), 8, 1);
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = 0xFF909090;
    *(s32 *)((s8 *)((u8 *)this) + 0x18) = arg1;
    *(u16 *)((s8 *)((u8 *)this) + 0) = (u16) (*(u16 *)((s8 *)((u8 *)this) + 0) | 0xC5);
}

void TWindowSubStatusDisp::setup_entry_msg_d0(s32 arg1) {
    *(f32 *)((s8 *)((u8 *)this) + 8) = (f32) lbl_805DCF08;
    *(s8 *)&reinterpret_cast<ItemListRow *>(this)->status_icon = 0x33;
    reinterpret_cast<ItemListRow *>(this)->category_icon = 0x33;
    *(s32 *)((s8 *)((u8 *)this) + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (s32)((saddr) (TWindowSubStatusDisp::get_message_10(0xD0))), (s32)((int) (*(s32 *)((s8 *)((u8 *)this) + 0x20))), 8, 1);
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = 0xFF909090;
    *(s32 *)((s8 *)((u8 *)this) + 0x18) = arg1;
    *(u16 *)((s8 *)((u8 *)this) + 0) = (u16) (*(u16 *)((s8 *)((u8 *)this) + 0) | 0xC5);
}

void TWindowSubStatusDisp::init_no_item_entry(s32 arg1) {
    *(f32 *)((s8 *)((u8 *)this) + 8) = (f32) lbl_805DCF08;
    *(s8 *)&reinterpret_cast<ItemListRow *>(this)->status_icon = 0x33;
    reinterpret_cast<ItemListRow *>(this)->category_icon = 0x33;
    *(s32 *)((s8 *)((u8 *)this) + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (s32)((saddr) (TWindowSubStatusDisp::get_message_10(0xCF))), (s32)((int) (*(s32 *)((s8 *)((u8 *)this) + 0x20))), 8, 1);
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = 0xFF909090;
    *(s32 *)((s8 *)((u8 *)this) + 0x18) = arg1;
    *(u16 *)((s8 *)((u8 *)this) + 0) = (u16) (*(u16 *)((s8 *)((u8 *)this) + 0) | 0xC5);
}

void TWindowSubStatusDisp::init_entry(s8 arg1, s8 arg2, u8 arg3, u32 src, s32 arg5) {
    *(f32 *)((s8 *)((u8 *)this) + 8) = (f32) lbl_805DCF08;
    *(s8 *)&reinterpret_cast<ItemListRow *>(this)->status_icon = arg1;
    reinterpret_cast<ItemListRow *>(this)->category_icon = arg2;
    *(s32 *)((s8 *)((u8 *)this) + 0x28) = (s32) arg3;
    reinterpret_cast<ItemListRow *>(this)->category_style = -1;
    *(s32 *)((s8 *)((u8 *)this) + 0x20) = ((u32)replace_owned_string__20TWindowSubStatusDispFPviiii(this, src, (s32)(*(s32 *)((s8 *)((u8 *)this) + 0x20)), 8, 1));
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = -1;
    *(s32 *)((s8 *)((u8 *)this) + 0x18) = arg5;
    *(u16 *)((s8 *)((u8 *)this) + 0) = (u16) (*(u16 *)((s8 *)((u8 *)this) + 0) | 0x245);
}

void TWindowSubStatusDisp__sub_80258A28(u8 *window_sub_status_disp, s32 arg1, s32 arg2) {
    *(f32 *)((s8 *)window_sub_status_disp + 8) = (f32) lbl_805DCF08;
    *(s8 *)&reinterpret_cast<ItemListRow *>(window_sub_status_disp)->status_icon = 0x33;
    reinterpret_cast<ItemListRow *>(window_sub_status_disp)->category_icon = 9;
    text_builder_reset();
    text_builder_append_int(arg1);
    text_builder_append((u8 *)((s32 *) (TWindowSubStatusDisp::get_download_server())));
    *(s32 *)((s8 *)window_sub_status_disp + 0x24) = replace_owned_string__20TWindowSubStatusDispFPviiii(window_sub_status_disp, (s32)((int) (get_shared_text_buffer())), (s32)((int) (*(s32 *)((s8 *)window_sub_status_disp + 0x24))), 0x10, 1);
    reinterpret_cast<ItemListRow *>(window_sub_status_disp)->suffix_style = -1;
    *(s32 *)((s8 *)window_sub_status_disp + 0x18) = arg2;
    *(u16 *)((s8 *)window_sub_status_disp + 0) = (u16) (*(u16 *)((s8 *)window_sub_status_disp + 0) | 0x45);
}

void TWindowSubStatusDisp::setup_stat_line(s32 src, s32 arg2, s32 arg3) {
    *(f32 *)((s8 *)this + 8) = (f32) lbl_805DCF08;
    *(s8 *)&reinterpret_cast<ItemListRow *>(this)->status_icon = 0x33;
    reinterpret_cast<ItemListRow *>(this)->category_icon = 0x2D;
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, src, *(s32 *)((s8 *)this + 0x20), 8, 1);
    update_stat_line__20TWindowSubStatusDispFPvi(this, arg2);
    *(s32 *)((s8 *)this + 0x18) = arg3;
    if (arg2 <= 0) {
        *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
        reinterpret_cast<ItemListRow *>(this)->category_style = 0xFFAAAAAA;
        *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0xC5);
    } else if ((is_current_area_item_enabled() == 0) || (is_boss_area() != 0)) {
        *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
        reinterpret_cast<ItemListRow *>(this)->category_style = 0xFFAAAAAA;
        *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
    } else {
        *(s32 *)((s8 *)this + 0x30) = -1;
        reinterpret_cast<ItemListRow *>(this)->category_style = -1;
        *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
    }
    reinterpret_cast<ItemListRow *>(this)->suffix_style = (s32) *(s32 *)((s8 *)this + 0x30);
}
void TWindowSubStatusDisp::init_status_entry_by_flag(s32 x) {
    ((void (*)(Obj_80258BB8 *, s32))init_status_entry__20TWindowSubStatusDispFPvcUii)(((Obj_80258BB8 *)this), x ? 0x14 : 0x15);
    ((Obj_80258BB8 *)this)->f8 = lbl_805DCF04;
}

void TWindowSubStatusDisp::init_list_entry(u8 arg1, s32 src, s32 arg3) {
    u8 var_r0;

    var_r0 = arg1;
    *(f32 *)((s8 *)this + 8) = (f32) lbl_805DCF04;
    if (arg1 == 0x18) {
        var_r0 = 0x16;
    }
    *(u8 *)((s8 *)this + 0x1C) = var_r0;
    reinterpret_cast<ItemListRow *>(this)->category_icon = 0x33;
    *(s32 *)((s8 *)this + 0x28) = -1;
    reinterpret_cast<ItemListRow *>(this)->category_style = -1;
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, src, *(s32 *)((s8 *)this + 0x20), 8, 1);
    *(s32 *)((s8 *)this + 0x30) = -1;
    reinterpret_cast<ItemListRow *>(this)->suffix_style = -1;
    *(s32 *)((s8 *)this + 0x18) = arg3;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x145);
    if (arg1 == 0x18) {
        *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x80);
        *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
    }
}
void init_status_entry__20TWindowSubStatusDispFPvcUii(u8 *window_sub_status_disp, s8 arg1, u32 src, s32 arg3) {
    ItemListRow *row = (ItemListRow *)window_sub_status_disp;
    row->x = lbl_805DCF04;
    row->status_icon = 0x33;
    *(s8 *)&row->category_icon = arg1;
    row->status_style = -1;
    row->category_style = -1;
    row->label = (char *)replace_owned_string__20TWindowSubStatusDispFPviiii(row, src, (saddr)row->label, 8, 1);
    row->style = -1;
    row->suffix_style = -1;
    row->item = arg3;
    row->flags |= 0x45;
}

}

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define PADV virtual void CAT(f,__LINE__)();
struct Base_80258F34 { char pad[0x18]; };

struct V_80258F34 : Base_80258F34 {
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    virtual s32 m10();
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    virtual s32 m34();
};

extern "C" {
s32 get_item_group__5TItemFv(void *);
s32 get_item_type__5TItemFv(void *);
s32 TObjPlayer__sub_801C1AC8(void *);
#define select_item_icon__20TWindowSubStatusDispFPviUcUci ((s32 (*)(void *, s32, s32, s32, s32))select_item_icon__20TWindowSubStatusDispFPviUcUci)
void TWindowSubStatusDisp::set_inventory_item(void *item, s32 count, s32 sid) {
    s32 item_data;

    *(f32 *)((s8 *)this + 8) = (f32) lbl_805DCF08;
    item_data = ((TItem *)item)->get_icon_index();
    select_item_icon__20TWindowSubStatusDispFPviUcUci(this, item_data, get_item_type__5TItemFv(item), get_item_group__5TItemFv(item), ((TItem *)item)->is_wrapped());
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (saddr)((TItem *)item)->get_name(), *(s32 *)((s8 *)this + 0x20), 8, 1);
    if (TObjPlayer__sub_801C1AC8(item) != 0) {
        update_stat_line_if_positive__20TWindowSubStatusDispFPvi(this, count);
    }
    update_item_icon_colors(item);
    reinterpret_cast<ItemListRow *>(this)->suffix_style = (s32) *(s32 *)((s8 *)this + 0x30);
    *(s32 *)((s8 *)this + 0x18) = sid;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
}

void TWindowSubStatusDisp::update_from_player(void *item, s32 arg2, s32 arg3) {
    s32 temp_r31;
    s32 temp_r30;
    s32 item_data;

    *(f32 *)((s8 *)this + 8) = (f32) lbl_805DCF08;
    item_data = ((TItem *)item)->get_icon_index();
    select_item_icon__20TWindowSubStatusDispFPviUcUci(this, item_data, get_item_type__5TItemFv(item), get_item_group__5TItemFv(item), ((TItem *)item)->is_wrapped());
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (saddr)((TItem *)item)->get_name(), *(s32 *)((s8 *)this + 0x20), 8, 1);
    if (TCameraCtrl::get_camera_id() <= 2) {
        text_builder_reset();
        text_builder_append_int(arg2);
        *(s32 *)&reinterpret_cast<ItemListRow *>(this)->suffix = replace_owned_string__20TWindowSubStatusDispFPviiii(this, get_shared_text_buffer(), *(s32 *)&reinterpret_cast<ItemListRow *>(this)->suffix, 0x10, 1);
    }
    update_item_icon_colors(item);
    *(s32 *)((s8 *)this + 0x18) = arg3;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
}
void TWindowSubStatusDisp::init_item_row(void *item, s32 arg2) {
    s32 item_data;
    *(f32 *)((s8 *)this + 8) = (f32) lbl_805DCF08;
    item_data = ((TItem *)item)->get_icon_index();
    select_item_icon__20TWindowSubStatusDispFPviUcUci(this, item_data, get_item_type__5TItemFv(item), get_item_group__5TItemFv(item), ((TItem *)item)->is_wrapped());
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (saddr)((TItem *)item)->get_name(), *(s32 *)((s8 *)this + 0x20), 8, 1);
    if (TObjPlayer__sub_801C1AC8(item) != 0) {
        s32 v = ((V_80258F34 *) item)->m34();
        update_stat_line_if_positive__20TWindowSubStatusDispFPvi(this, v);
    }
    update_item_icon_colors(item);
    reinterpret_cast<ItemListRow *>(this)->suffix_style = (s32) *(s32 *)((s8 *)this + 0x30);
    *(s32 *)((s8 *)this + 0x18) = arg2;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
}

#undef select_item_icon__20TWindowSubStatusDispFPviUcUci

#define update_stat_line_if_positive__20TWindowSubStatusDispFPvi ((int (*)(void*, void*))update_stat_line_if_positive__20TWindowSubStatusDispFPvi)
#define select_item_icon__20TWindowSubStatusDispFPviUcUci ((int (*)(void*, void*, void*, void*, void*))select_item_icon__20TWindowSubStatusDispFPviUcUci)
#define replace_owned_string__20TWindowSubStatusDispFPviiii ((int (*)(void*, void*, void*, void*, void*))replace_owned_string__20TWindowSubStatusDispFPviiii)

    extern const float lbl_805DCF08;

void TWindowSubStatusDisp::set_item_info(void* a1, int a2, void* a3) {
    saddr item_data;
    saddr temp_r3;

    *(float*)((char*)this + 0x8) = lbl_805DCF08;
    *(unsigned char *)&reinterpret_cast<ItemListRow *>(this)->status_icon = 51;
    item_data = TLobby::get_item_data((uaddr)a1);
    temp_r3 = TItemData::is_wrapped(a1);
    select_item_icon__20TWindowSubStatusDispFPviUcUci(this, (void*)item_data, (void*)(uaddr)(*(unsigned char*)((char*)a1 + 0x0)), (void*)(uaddr)(*(unsigned char*)((char*)a1 + 0x1)), (void*)temp_r3);
    TLobby::forward_message(get_shared_text_buffer(), (uaddr)(void *)a1);
    *(int*)((char*)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (void*)get_shared_text_buffer(), (void*)(*(saddr *)((char*)this + 0x20)), (void*)8, (void*)1);
    update_stat_line_if_positive__20TWindowSubStatusDispFPvi(this, a3);
    update_item_colors((saddr)a1);
    reinterpret_cast<ItemListRow *>(this)->suffix_style = *(int*)((char*)this + 0x30);
    *(int*)((char*)this + 0x18) = a2;
    *(short*)((char*)this + 0x0) = (*(unsigned short*)((char*)this + 0x0) | 0x45);
}

}

#undef update_stat_line_if_positive__20TWindowSubStatusDispFPvi
#undef select_item_icon__20TWindowSubStatusDispFPviUcUci
#undef replace_owned_string__20TWindowSubStatusDispFPviiii

struct Quad_8025941C { f32 v[8]; };

extern "C" {
u32 calc_text_width(char *s);
}
s32 draw_window_text(f32 *pos, const char *s, s32 color, s32 mode, f32 width);
extern const f32 lbl_805DCF14;
extern const f32 lbl_805DCF20;
extern const f32 lbl_805DCF24;
extern const f32 lbl_805DCF28;
extern const f32 lbl_805DCF2C;
extern const f32 lbl_805DCF10;
extern const f32 lbl_805DCF18;
extern "C" {
void calc_row_width__20TWindowSubStatusDispFv(ItemListRow *arg0);

void TWindowSubStatusDisp::set_ground_item(void *it, s32 arg2) {
    s32 item_data;

    *(f32 *)((s8 *)this + 8) = (f32) lbl_805DCF08;
    *(s8 *)&reinterpret_cast<ItemListRow *>(this)->status_icon = 0x33;
    item_data = TLobby::get_item_data((uaddr)it);
    select_item_icon__20TWindowSubStatusDispFPviUcUci(this, item_data, *(u8 *)((s8 *)it + 0), *(u8 *)((s8 *)it + 1), TItemData::is_wrapped(it));
    TLobby::forward_message(get_shared_text_buffer(), (uaddr)(void *)it);
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (s32)(get_shared_text_buffer()), (s32)(*(s32 *)((s8 *)this + 0x20)), 8, 1);
    if (TCameraCtrl::get_camera_id() <= 2) {
        text_builder_reset();
        text_builder_append_int(*(s32 *)((s8 *)it + 0x10));
        *(s32 *)&reinterpret_cast<ItemListRow *>(this)->suffix = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (s32)(get_shared_text_buffer()), (s32)(*(s32 *)&reinterpret_cast<ItemListRow *>(this)->suffix), 0x10, 1);
    }
    update_item_colors((saddr)it);
    *(s32 *)((s8 *)this + 0x18) = arg2;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
}

extern const f32 lbl_805DCF0C;

void TWindowSubStatusDisp::init_display(s32 src, s32 arg2) {
    *(f32 *)((s8 *)this + 8) = (f32) lbl_805DCF0C;
    *(s8 *)&reinterpret_cast<ItemListRow *>(this)->status_icon = 0x33;
    reinterpret_cast<ItemListRow *>(this)->category_icon = 0x33;
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, src, (s32)(*(s32 *)((s8 *)this + 0x20)), 8, 1);
    *(s32 *)((s8 *)this + 0x30) = -1;
    *(s32 *)((s8 *)this + 0x18) = arg2;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
}

saddr replace_owned_string__20TWindowSubStatusDispFPviiii(void *window_sub_status_disp, saddr src, saddr buf, s32 mask, s32 copy) {
    u16 *flags = (u16 *)window_sub_status_disp;
    s32 n;
    if (buf != 0 && (*flags & mask)) {
        *flags &= ~mask;
        mem_free((void *)buf);
    }
    if ((u32)src != 0 && copy != 0) {
        n = (s32)measure_string_len((const char *)(src));
        buf = mem_alloc(n + 1);
        strncpy((char *)buf, (const char *)src, n + 1);
        *flags |= mask;
    } else {
        buf = src;
    }
    return buf;
}

void calc_row_width__20TWindowSubStatusDispFv(ItemListRow *arg0) {
    arg0->width = lbl_805DCF08;
    if (arg0->is_flag_4_set() != 0) {
        if (arg0->status_icon != 0x33) {
            arg0->width += lbl_805DCF10;
        } else if (arg0->category_icon != 0x33) {
            arg0->width += lbl_805DCF14;
        }
        if (arg0->label != 0) {
            arg0->width += (f32)calc_text_width(arg0->label);
        }
        if (arg0->suffix != 0) {
            arg0->width += lbl_805DCF18;
            arg0->width += (f32)calc_text_width(arg0->suffix);
        }
    }
}

void*TWindowSubStatusDisp::get_entry_ptr(int a0) {  return (char*)status_disp_item_icon_coord_table + (unsigned char)(a0) * 8; }

extern s32 hud_texlist;
extern const f32 lbl_805DCF1C;

void draw_item_list_icon(WindowDrawContext *win, ItemListPosition *pos, s32 icon, s32 style, f32 depth) {
    Quad_8025941C q;
    ItemListPosition *p;
    f32 *entry;
    f32 scale;
    f32 offset;
    f32 edge;

    if ((u8)icon != 0x33) {
        p = pos;
        begin_screen_draw(1);
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(hud_texlist));
        set_draw_texture_and_color(1, style);
        entry = (f32 *)TWindowSubStatusDisp::get_entry_ptr(icon);
        offset = lbl_805DCF14;
        scale = lbl_805DCF1C;
        q.v[0] = p->x;
        q.v[1] = p->y;
        q.v[2] = offset + p->x;
        q.v[3] = offset + p->y;
        q.v[4] = entry[0] * scale;
        q.v[5] = entry[1] * scale;
        edge = offset + entry[0];
        q.v[6] = edge * scale;
        edge = offset + entry[1];
        q.v[7] = edge * scale;
        if (win->clip_and_transform_quad((TexturedQuad *)&q) != 0) {
            draw_textured_quad_at_depth(q.v, depth);
        }
        TWindowSubStatusDisp::get_player();
    }
}
}

typedef struct ItemListPosition ItemListPosition;
#pragma fp_contract on
void ItemListRow::render(WindowDrawContext *context) {
  WindowDrawContext *win = context;
  ItemListPosition pos;
  f32 y;
  f32 depth;
  s32 style;
  if (is_flag_4_set() != 0)
  {
    y = win->inner_y + this->y;
    if (((!((this->height + y) < win->clip_y0)) && (!((win->inner_y + this->y) > win->clip_y1))) && (win->open_tick >= 0))
    {
      pos.x = win->inner_x + this->x;
      pos.y = win->inner_y + this->y;
      depth = lbl_805DCF20 / (lbl_805DCF24 + win->depth);
      if (this->flags & 0x200)
      {
        draw_item_list_icon(win, &pos, this->status_icon, -1, depth);
        pos.x += lbl_805DCF14;
        draw_item_list_icon(win, &pos, this->category_icon, -1, depth);
        pos.x += lbl_805DCF14;
        draw_item_list_icon(win, &pos, (u8) this->status_style, -1, depth);
        pos.x += lbl_805DCF14;
      }
      else
      {
        set_additive_blend();
        if (this->flags & 0x100)
        {
          pos.x += lbl_805DCF14;
          draw_item_list_icon(win, &pos, this->status_icon, this->status_style, depth);
        }
        else
        {
          draw_item_list_icon(win, &pos, this->status_icon, this->status_style, depth);
          pos.x += lbl_805DCF14;
        }
        set_default_alpha_blend();
        draw_item_list_icon(win, &pos, this->category_icon, this->category_style, depth);
        pos.x += lbl_805DCF14;
      }
      if (this->flags & 0x1000)
      {
        set_text_draw_params(win, 1, 0, (f32)depth, (f32)win->clip_x1);
      }
      else
      {
        set_text_draw_params(win, 1, 1, (f32)depth, (f32)lbl_805DCF28);
      }
      if (this->flags & 0x400)
      {
        pos.x = (lbl_805DCF2C * win->inner_w) + win->inner_x;
        pos.x = -((lbl_805DCF2C * ((f32) calc_text_width(this->label))) - pos.x);
      }
      if (this->flags & 0x800)
      {
        style = TWindowCtrl::get_field24();
      }
      else
      {
        style = this->style;
      }
      if (this->flags & 0x1000)
      {
        draw_window_text((f32 *)&pos, this->label, style, 0, (f32)lbl_805DCF28);
      }
      else
      {
        draw_window_text((f32 *)&pos, this->label, style, 1, (f32)lbl_805DCF28);
      }
      f32 width = (f32) calc_text_width(this->suffix);
      pos.x = (win->inner_x + win->inner_w) - width;
      draw_window_text((f32 *)&pos, this->suffix, this->suffix_style, 1, (f32)lbl_805DCF28);
    }
  }
}
void ItemListRow::update() {
    if (is_flag_4_set()) return;
}


ItemListRow::~ItemListRow() {
    u16 flags;

    if (this->suffix != 0) {
        flags = this->flags;
        if (flags & 0x10) {
            this->flags = flags & ~0x10;
            mem_free(this->suffix);
        }
    }
    if (this->label != 0) {
        flags = this->flags;
        if (flags & 8) {
            this->flags = flags & ~8;
            mem_free(this->label);
        }
    }
}

ItemListRow::ItemListRow(u8 *rec, s32 m_2) : TUnk_804CF998(m_2) {
    this->height = lbl_805DCF14;
    this->status_icon = 51;
    this->category_icon = 51;
    this->label = 0;
    this->suffix = 0;
    this->status_style = -1;
    this->category_style = -1;
    this->style = -1;
    this->suffix_style = -1;
    this->item = 0;
}
