#include "types.h"
#include "pso/system/memory.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/item/TItemData.h"
#include "pso/misc/TUnk_804CF930.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

struct RecoveredGlobal_80258100_lbl_804CF998 {
    s32 value;
    u8 remaining[0x14];
};

extern unsigned char lbl_804CF998[];

extern "C" {

void* reset_entry__20TWindowSubStatusDispFPv(void* a0, s16 _w1);

    extern const float lbl_805DCEF8;
void* reset_entry__20TWindowSubStatusDispFPv(void* a0, s16 _w1) { ((TUnk_804CF930 *)a0)->sub_80256BDC(_w1); *(int*)((char*)a0 + 0x4) = (int)lbl_804CF998; *(float*)((char*)a0 + 0x8) = lbl_805DCEF8; *(float*)((char*)a0 + 0xc) = lbl_805DCEF8; *(float*)((char*)a0 + 0x10) = lbl_805DCEF8; *(float*)((char*)a0 + 0x14) = lbl_805DCEF8; return a0; }

typedef char RecoveredGlobal_80258100_lbl_804CF998_size[sizeof(RecoveredGlobal_80258100_lbl_804CF998) == 0x18 ? 1 : -1];
u8 *TWindowSubStatusDisp::init_layout_entry_rect(u8 *arg1, s16 arg2) {
    ((TUnk_804CF930 *)((u8 *)this))->sub_80256BDC(arg2);
    *(s32 **)((s8 *)((u8 *)this) + 4) = &(*(RecoveredGlobal_80258100_lbl_804CF998 *)&lbl_804CF998).value;
    *(f32 *)((s8 *)((u8 *)this) + 8) = (f32) *(f32 *)((s8 *)arg1 + 4);
    *(f32 *)((s8 *)((u8 *)this) + 0xC) = (f32) *(f32 *)((s8 *)arg1 + 8);
    *(f32 *)((s8 *)((u8 *)this) + 0x10) = (f32) *(f32 *)((s8 *)arg1 + 0xC);
    *(f32 *)((s8 *)((u8 *)this) + 0x14) = (f32) *(f32 *)((s8 *)arg1 + 0x10);
    return ((u8 *)this);
}

void TWindowSubStatusDisp::advance_state() {
    if ((u8) this->m_1d == 0x14) {
        this->m_1d = 0x15U;
    }
}

void TWindowSubStatusDisp::finalize_state() {
    if ((u8) this->m_1d == 0x15) {
        this->m_1d = 0x14U;
    }
}

void reset__20TWindowSubStatusDispFPv(void *arg0);
void mem_free(void *p);

void reset__20TWindowSubStatusDispFPv(void *arg0) {
    *(s8 *)((s8 *)arg0 + 0x1C) = 0x33;
    *(s8 *)((s8 *)arg0 + 0x1D) = 0x33;
    *(s32 *)((s8 *)arg0 + 0x28) = -1;
    *(s32 *)((s8 *)arg0 + 0x2C) = -1;
    *(s32 *)((s8 *)arg0 + 0x30) = -1;
    *(s32 *)((s8 *)arg0 + 0x34) = -1;
    *(s32 *)((s8 *)arg0 + 0x18) = 0;
    if (((u32) *(u32 *)((s8 *)arg0 + 0x24) != 0U) && (*(u16 *)((s8 *)arg0 + 0) & 0x10)) {
        mem_free((void *)(*(u32 *)((s8 *)arg0 + 0x24)));
    }
    *(u32 *)((s8 *)arg0 + 0x24) = 0U;
    if (((u32) *(u32 *)((s8 *)arg0 + 0x20) != 0U) && (*(u16 *)((s8 *)arg0 + 0) & 8)) {
        mem_free((void *)(*(u32 *)((s8 *)arg0 + 0x20)));
    }
    *(u32 *)((s8 *)arg0 + 0x20) = 0U;
    *(u16 *)((s8 *)arg0 + 0) = (u16) (*(u16 *)((s8 *)arg0 + 0) & ~0x1BFD);
}

void update_stat_line__20TWindowSubStatusDispFPvi(void *arg0, s32 arg1);
s32 get_shared_text_buffer();
s32 TWindowSubStatusDisp__sub_80228F5C(s32);
void text_builder_append(u8 *str);
}
void text_builder_reset(void);
extern "C" {
s32 replace_owned_string__20TWindowSubStatusDispFPviiii(void *, s32, s32, s32, s32);

extern s32 lbl_805DCF00;

void update_stat_line__20TWindowSubStatusDispFPvi(void *window_sub_status_disp, s32 arg1) {
    text_builder_reset();
    text_builder_append((u8 *)&lbl_805DCF00);
    TWindowSubStatusDisp__sub_80228F5C(arg1);
    *(s32 *)((s8 *)window_sub_status_disp + 0x24) = replace_owned_string__20TWindowSubStatusDispFPviiii(window_sub_status_disp, get_shared_text_buffer(), *(s32 *)((s8 *)window_sub_status_disp + 0x24), 0x10, 1);
}

void update_stat_line_if_positive__20TWindowSubStatusDispFPvi(void *arg0, s32 arg1);

void update_stat_line_if_positive__20TWindowSubStatusDispFPvi(void *arg0, s32 arg1) {
    if (arg1 > 0) {
        ((void (*)(void *))update_stat_line__20TWindowSubStatusDispFPvi)(arg0);
    }
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
void update_item_icon_colors__20TWindowSubStatusDispFPvPv(void *arg0, void *arg1);
s32 is_wrapped__9TItemDataFPv(s32);
s32 is_custom_name_srank__9TItemDataFPv(u8 *arg0);
s32 is_rare_item__9TItemDataFPv(u8 *item);
s32 get_usable_action_flags__5TItemFUlUl(void *, s32, s32);
s32 is_boss_area();
void *get_player_by_client_id(s32 i);
s32 check_equip_requirements(s32, s32, s32 *);
u8 calc_display_grade__9TItemDataFv(s32);
s32 is_wrapped__5TItemFv(void *);
s32 check_equip_requirements__5TItemFP10TObjPlayerPs(void *, s32, s16 *);
s32 reset_key_machine_state__10TObjPlayerFv();

void update_item_icon_colors__20TWindowSubStatusDispFPvPv(void *arg0, void *item) {
    s16 sp8;
    s32 temp_r26;
    s32 temp_r27;
    s32 temp_r28;
    s32 temp_r28_2;
    s32 player;

    if (is_wrapped__5TItemFv(item) != 0) {
        *(s32 *)((s8 *)arg0 + 0x30) = -1;
        return;
    }
    player = (s32)get_player_by_client_id(*(s16 *)((s8 *)arg0 + 2));
    if (player != 0) {
        temp_r26 = ((TItem *)item)->test_item_flags(8);
        temp_r28 = get_usable_action_flags__5TItemFUlUl(item, 0x10, player);
        temp_r27 = check_equip_requirements__5TItemFP10TObjPlayerPs(item, player, &sp8);
        temp_r28_2 = ((VObj18B_802582c4_80257784 *) item)->vm8C();
        if (temp_r28 != 0) {
            if (temp_r26 != 0) {
                *(s8 *)((s8 *)arg0 + 0x1C) = 0x30;
            } else {
                *(s8 *)((s8 *)arg0 + 0x1C) = 0x2F;
            }
        } else if (temp_r26 != 0) {
            *(s8 *)((s8 *)arg0 + 0x1C) = 0xC;
        } else {
            if ((temp_r28_2 == 0) && (((TItem *)item)->is_rare_item() != 0)) {
                *(s8 *)((s8 *)arg0 + 0x1C) = 0x19;
            } else if (sp8 & 1) {
                *(s8 *)((s8 *)arg0 + 0x1C) = 0x13;
            } else {
                *(s8 *)((s8 *)arg0 + 0x1C) = 0x33;
            }
            *(s32 *)((s8 *)arg0 + 0x28) = -1;
        }
        if (temp_r28_2 == 0) {
            *(s32 *)((s8 *)arg0 + 0x2C) = -1;
            *(s32 *)((s8 *)arg0 + 0x30) = 0xFF00FFFC;
            return;
        }
        if (temp_r27 != 0) {
            *(s32 *)((s8 *)arg0 + 0x2C) = -1;
            if (((TItem *)item)->is_custom_name_srank() != 0) {
                *(s32 *)((s8 *)arg0 + 0x30) = 0xFFFE3C28;
                return;
            }
            if (((TItem *)item)->get_name_style() == 2) {
                *(u16 *)((s8 *)arg0 + 0) = (u16) (*(u16 *)((s8 *)arg0 + 0) | 0x800);
                return;
            }
            if ((u8)((TItem *)item)->calc_display_grade() >= 9U) {
                *(s32 *)((s8 *)arg0 + 0x30) = -0x1600;
                return;
            }
            if (((TItem *)item)->has_bonus_stats() != 0) {
                *(s32 *)((s8 *)arg0 + 0x30) = 0xFF61E853;
                return;
            }
            if (get_usable_action_flags__5TItemFUlUl(item, 0x10000, player) != 0U) {
                *(s32 *)((s8 *)arg0 + 0x30) = 0xFF909090;
                return;
            }
            *(s32 *)((s8 *)arg0 + 0x30) = -1;
            return;
        }
        if (sp8 & 1) {
            *(s32 *)((s8 *)arg0 + 0x30) = 0xFF909090;
            *(s32 *)((s8 *)arg0 + 0x2C) = 0xFFAAAAAA;
            return;
        }
        *(s32 *)((s8 *)arg0 + 0x30) = 0xFF909090;
        *(s32 *)((s8 *)arg0 + 0x2C) = 0xFFAAAAAA;
    }
}

void TWindowSubStatusDisp::update_item_colors(s32 arg1) {
    s32 sp8;
    s32 temp_r29;
    s32 temp_r30;
    s32 player;

    if (is_wrapped__9TItemDataFPv(arg1) != 0) {
        *(s32 *)((s8 *)this + 0x30) = -1;
        return;
    }
    player = (s32)get_player_by_client_id(*(s16 *)((s8 *)this + 2));
    if (player != 0) {
        temp_r29 = check_equip_requirements(player, arg1, &sp8);
        temp_r30 = ((TItemData *)arg1)->check_item_flags();
        if ((u8) *(u8 *)((s8 *)this + 0x1C) == 0x33) {
            if ((temp_r30 == 0) && (is_rare_item__9TItemDataFPv((u8 *)arg1) != 0)) {
                *(u8 *)((s8 *)this + 0x1C) = 0x19U;
            } else if (sp8 & 1) {
                *(u8 *)((s8 *)this + 0x1C) = 0x13U;
            }
            *(s32 *)((s8 *)this + 0x28) = -1;
        }
        if (temp_r30 == 0) {
            this->m_2c = -1;
            *(s32 *)((s8 *)this + 0x30) = 0xFF00FFFC;
            return;
        }
        if (temp_r29 != 0) {
            this->m_2c = -1;
            if (is_custom_name_srank__9TItemDataFPv((u8 *)arg1) != 0) {
                *(s32 *)((s8 *)this + 0x30) = 0xFFFE3C28;
                return;
            }
            if (((TItemData *)arg1)->get_name_style() == 2) {
                *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x800);
                return;
            }
            if (calc_display_grade__9TItemDataFv(arg1) >= 9U) {
                *(s32 *)((s8 *)this + 0x30) = -0x1600;
                return;
            }
            if (((TItemData *)arg1)->has_bonus_stats() != 0) {
                *(s32 *)((s8 *)this + 0x30) = 0xFF61E853;
                return;
            }
            if (((TItemData *)arg1)->calc_action_flags(0x10000, (u8 *)player) != 0U) {
                *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
                return;
            }
            *(s32 *)((s8 *)this + 0x30) = -1;
            return;
        }
        if (sp8 & 1) {
            *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
            this->m_2c = 0xFFAAAAAA;
            return;
        }
        *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
        this->m_2c = 0xFFAAAAAA;
    }
}

void select_item_icon__20TWindowSubStatusDispFPviUcUci(void *arg0, s32 arg1, u8 arg2, u8 arg3, s32 arg4) {
    if (arg4 != 0) {
        *(s8 *)((s8 *)arg0 + 0x1D) = 8;
        return;
    }
    switch (arg1) {
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
    *(s8 *)&this->unk_1C = 0x33;
    this->m_1d = 0x33;
    *(s32 *)((s8 *)((u8 *)this) + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (s32)((int) (TWindowSubStatusDisp::get_message_10(0xD1))), (s32)((int) (*(s32 *)((s8 *)((u8 *)this) + 0x20))), 8, 1);
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = 0xFF909090;
    *(s32 *)((s8 *)((u8 *)this) + 0x18) = arg1;
    *(u16 *)((s8 *)((u8 *)this) + 0) = (u16) (*(u16 *)((s8 *)((u8 *)this) + 0) | 0xC5);
}

void TWindowSubStatusDisp::setup_entry_msg_d0(s32 arg1) {
    *(f32 *)((s8 *)((u8 *)this) + 8) = (f32) lbl_805DCF08;
    *(s8 *)&this->unk_1C = 0x33;
    this->m_1d = 0x33;
    *(s32 *)((s8 *)((u8 *)this) + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (s32)((int) (TWindowSubStatusDisp::get_message_10(0xD0))), (s32)((int) (*(s32 *)((s8 *)((u8 *)this) + 0x20))), 8, 1);
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = 0xFF909090;
    *(s32 *)((s8 *)((u8 *)this) + 0x18) = arg1;
    *(u16 *)((s8 *)((u8 *)this) + 0) = (u16) (*(u16 *)((s8 *)((u8 *)this) + 0) | 0xC5);
}

void TWindowSubStatusDisp::init_no_item_entry(s32 arg1) {
    *(f32 *)((s8 *)((u8 *)this) + 8) = (f32) lbl_805DCF08;
    *(s8 *)&this->unk_1C = 0x33;
    this->m_1d = 0x33;
    *(s32 *)((s8 *)((u8 *)this) + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (s32)((int) (TWindowSubStatusDisp::get_message_10(0xCF))), (s32)((int) (*(s32 *)((s8 *)((u8 *)this) + 0x20))), 8, 1);
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = 0xFF909090;
    *(s32 *)((s8 *)((u8 *)this) + 0x18) = arg1;
    *(u16 *)((s8 *)((u8 *)this) + 0) = (u16) (*(u16 *)((s8 *)((u8 *)this) + 0) | 0xC5);
}

void TWindowSubStatusDisp::init_entry(s8 arg1, s8 arg2, u8 arg3, u32 src, s32 arg5) {
    *(f32 *)((s8 *)((u8 *)this) + 8) = (f32) lbl_805DCF08;
    *(s8 *)&this->unk_1C = arg1;
    this->m_1d = arg2;
    *(s32 *)((s8 *)((u8 *)this) + 0x28) = (s32) arg3;
    this->m_2c = -1;
    *(s32 *)((s8 *)((u8 *)this) + 0x20) = ((u32)replace_owned_string__20TWindowSubStatusDispFPviiii(this, src, (s32)(*(s32 *)((s8 *)((u8 *)this) + 0x20)), 8, 1));
    *(s32 *)((s8 *)((u8 *)this) + 0x30) = -1;
    *(s32 *)((s8 *)((u8 *)this) + 0x18) = arg5;
    *(u16 *)((s8 *)((u8 *)this) + 0) = (u16) (*(u16 *)((s8 *)((u8 *)this) + 0) | 0x245);
}

void TWindowSubStatusDisp__sub_80258A28(u8 *window_sub_status_disp, s32 arg1, s32 arg2) {
    *(f32 *)((s8 *)window_sub_status_disp + 8) = (f32) lbl_805DCF08;
    *(s8 *)&((TWindowSubStatusDisp *)window_sub_status_disp)->unk_1C = 0x33;
    ((TWindowSubStatusDisp *)window_sub_status_disp)->m_1d = 9;
    text_builder_reset();
    TWindowSubStatusDisp__sub_80228F5C(arg1);
    text_builder_append((u8 *)((s32 *) (TWindowSubStatusDisp::get_download_server())));
    *(s32 *)((s8 *)window_sub_status_disp + 0x24) = replace_owned_string__20TWindowSubStatusDispFPviiii(window_sub_status_disp, (s32)((int) (get_shared_text_buffer())), (s32)((int) (*(s32 *)((s8 *)window_sub_status_disp + 0x24))), 0x10, 1);
    ((TWindowSubStatusDisp *)window_sub_status_disp)->m_34 = -1;
    *(s32 *)((s8 *)window_sub_status_disp + 0x18) = arg2;
    *(u16 *)((s8 *)window_sub_status_disp + 0) = (u16) (*(u16 *)((s8 *)window_sub_status_disp + 0) | 0x45);
}

void TWindowSubStatusDisp::setup_stat_line(s32 src, s32 arg2, s32 arg3) {
    *(f32 *)((s8 *)this + 8) = (f32) lbl_805DCF08;
    *(s8 *)&this->unk_1C = 0x33;
    this->m_1d = 0x2D;
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, src, *(s32 *)((s8 *)this + 0x20), 8, 1);
    update_stat_line__20TWindowSubStatusDispFPvi(this, arg2);
    *(s32 *)((s8 *)this + 0x18) = arg3;
    if (arg2 <= 0) {
        *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
        this->m_2c = 0xFFAAAAAA;
        *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0xC5);
    } else if ((reset_key_machine_state__10TObjPlayerFv() == 0) || (is_boss_area() != 0)) {
        *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
        this->m_2c = 0xFFAAAAAA;
        *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
    } else {
        *(s32 *)((s8 *)this + 0x30) = -1;
        this->m_2c = -1;
        *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
    }
    this->m_34 = (s32) *(s32 *)((s8 *)this + 0x30);
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
    this->m_1d = 0x33;
    *(s32 *)((s8 *)this + 0x28) = -1;
    this->m_2c = -1;
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, src, *(s32 *)((s8 *)this + 0x20), 8, 1);
    *(s32 *)((s8 *)this + 0x30) = -1;
    this->m_34 = -1;
    *(s32 *)((s8 *)this + 0x18) = arg3;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x145);
    if (arg1 == 0x18) {
        *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x80);
        *(s32 *)((s8 *)this + 0x30) = 0xFF909090;
    }
}
void init_status_entry__20TWindowSubStatusDispFPvcUii(u8 *window_sub_status_disp, s8 arg1, u32 src, s32 arg3) {
    *(f32 *)((s8 *)window_sub_status_disp + 8) = (f32) lbl_805DCF04;
    *(s8 *)&((TWindowSubStatusDisp *)window_sub_status_disp)->unk_1C = 0x33;
    ((TWindowSubStatusDisp *)window_sub_status_disp)->m_1d = arg1;
    *(s32 *)((s8 *)window_sub_status_disp + 0x28) = -1;
    ((TWindowSubStatusDisp *)window_sub_status_disp)->m_2c = -1;
    *(s32 *)((s8 *)window_sub_status_disp + 0x20) = ((u32)replace_owned_string__20TWindowSubStatusDispFPviiii(window_sub_status_disp, src, (s32)(*(s32 *)((s8 *)window_sub_status_disp + 0x20)), 8, 1));
    *(s32 *)((s8 *)window_sub_status_disp + 0x30) = -1;
    ((TWindowSubStatusDisp *)window_sub_status_disp)->m_34 = -1;
    *(s32 *)((s8 *)window_sub_status_disp + 0x18) = arg3;
    *(u16 *)((s8 *)window_sub_status_disp + 0) = (u16) (*(u16 *)((s8 *)window_sub_status_disp + 0) | 0x45);
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
#define update_stat_line_if_positive__20TWindowSubStatusDispFPvi ((s32 (*)(void *, s32))update_stat_line_if_positive__20TWindowSubStatusDispFPvi)
#define update_item_icon_colors__20TWindowSubStatusDispFPvPv ((s32 (*)(void *, void *))update_item_icon_colors__20TWindowSubStatusDispFPvPv)
#define select_item_icon__20TWindowSubStatusDispFPviUcUci ((s32 (*)(void *, s32, s32, s32, s32))select_item_icon__20TWindowSubStatusDispFPviUcUci)
void TWindowSubStatusDisp::set_inventory_item(void *arg1, s32 arg2, s32 arg3) {
    s32 temp_r29;

    *(f32 *)((s8 *)this + 8) = (f32) lbl_805DCF08;
    temp_r29 = ((TItem *)arg1)->get_icon_index();
    select_item_icon__20TWindowSubStatusDispFPviUcUci(this, temp_r29, get_item_type__5TItemFv(arg1), get_item_group__5TItemFv(arg1), is_wrapped__5TItemFv(arg1));
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (s32)((TItem *)arg1)->get_name(), *(s32 *)((s8 *)this + 0x20), 8, 1);
    if (TObjPlayer__sub_801C1AC8(arg1) != 0) {
        update_stat_line_if_positive__20TWindowSubStatusDispFPvi(this, arg2);
    }
    update_item_icon_colors__20TWindowSubStatusDispFPvPv(this, arg1);
    this->m_34 = (s32) *(s32 *)((s8 *)this + 0x30);
    *(s32 *)((s8 *)this + 0x18) = arg3;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
}

void TWindowSubStatusDisp::update_from_player(void *arg1, s32 arg2, s32 arg3) {
    s32 temp_r31;
    s32 temp_r30;
    s32 temp_r29;

    *(f32 *)((s8 *)this + 8) = (f32) lbl_805DCF08;
    temp_r29 = ((TItem *)arg1)->get_icon_index();
    select_item_icon__20TWindowSubStatusDispFPviUcUci(this, temp_r29, get_item_type__5TItemFv(arg1), get_item_group__5TItemFv(arg1), is_wrapped__5TItemFv(arg1));
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (s32)((TItem *)arg1)->get_name(), *(s32 *)((s8 *)this + 0x20), 8, 1);
    if (TCameraCtrl::get_camera_id() <= 2) {
        text_builder_reset();
        TWindowSubStatusDisp__sub_80228F5C(arg2);
        *(s32 *)&this->m_24 = replace_owned_string__20TWindowSubStatusDispFPviiii(this, get_shared_text_buffer(), *(s32 *)&this->m_24, 0x10, 1);
    }
    update_item_icon_colors__20TWindowSubStatusDispFPvPv(this, arg1);
    *(s32 *)((s8 *)this + 0x18) = arg3;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
}
void TWindowSubStatusDisp::init_item_row(void *arg1, s32 arg2) {
    s32 temp_r29;
    *(f32 *)((s8 *)this + 8) = (f32) lbl_805DCF08;
    temp_r29 = ((TItem *)arg1)->get_icon_index();
    select_item_icon__20TWindowSubStatusDispFPviUcUci(this, temp_r29, get_item_type__5TItemFv(arg1), get_item_group__5TItemFv(arg1), is_wrapped__5TItemFv(arg1));
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (s32)((TItem *)arg1)->get_name(), *(s32 *)((s8 *)this + 0x20), 8, 1);
    if (TObjPlayer__sub_801C1AC8(arg1) != 0) {
        s32 v = ((V_80258F34 *) arg1)->m34();
        update_stat_line_if_positive__20TWindowSubStatusDispFPvi(this, v);
    }
    update_item_icon_colors__20TWindowSubStatusDispFPvPv(this, arg1);
    this->m_34 = (s32) *(s32 *)((s8 *)this + 0x30);
    *(s32 *)((s8 *)this + 0x18) = arg2;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
}

#undef update_stat_line_if_positive__20TWindowSubStatusDispFPvi
#undef update_item_icon_colors__20TWindowSubStatusDispFPvPv
#undef select_item_icon__20TWindowSubStatusDispFPviUcUci

#define is_wrapped__9TItemDataFPv ((int (*)(void*))is_wrapped__9TItemDataFPv)
#define get_shared_text_buffer ((int (*)(void))get_shared_text_buffer)
#define update_stat_line_if_positive__20TWindowSubStatusDispFPvi ((int (*)(void*, void*))update_stat_line_if_positive__20TWindowSubStatusDispFPvi)
#define select_item_icon__20TWindowSubStatusDispFPviUcUci ((int (*)(void*, void*, void*, void*, void*))select_item_icon__20TWindowSubStatusDispFPviUcUci)
#define replace_owned_string__20TWindowSubStatusDispFPviiii ((int (*)(void*, void*, void*, void*, void*))replace_owned_string__20TWindowSubStatusDispFPviiii)
int forward_message__6TLobbyFlUl(int, void*);
int get_item_data__6TLobbyFUl(void*);

    extern const float lbl_805DCF08;

void TWindowSubStatusDisp::set_item_info(void* a1, int a2, void* a3) {
    int temp_r31;
    int temp_r3;

    *(float*)((char*)this + 0x8) = lbl_805DCF08;
    *(unsigned char *)&this->unk_1C = 51;
    temp_r31 = get_item_data__6TLobbyFUl(a1);
    temp_r3 = is_wrapped__9TItemDataFPv(a1);
    select_item_icon__20TWindowSubStatusDispFPviUcUci(this, (void*)temp_r31, (void*)(*(unsigned char*)((char*)a1 + 0x0)), (void*)(*(unsigned char*)((char*)a1 + 0x1)), (void*)temp_r3);
    forward_message__6TLobbyFlUl(get_shared_text_buffer(), a1);
    *(int*)((char*)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (void*)get_shared_text_buffer(), (void*)(*(int*)((char*)this + 0x20)), (void*)8, (void*)1);
    update_stat_line_if_positive__20TWindowSubStatusDispFPvi(this, a3);
    update_item_colors((s32)a1);
    this->m_34 = *(int*)((char*)this + 0x30);
    *(int*)((char*)this + 0x18) = a2;
    *(short*)((char*)this + 0x0) = (*(unsigned short*)((char*)this + 0x0) | 0x45);
}

}

#undef is_wrapped__9TItemDataFPv
#undef get_shared_text_buffer
#undef update_stat_line_if_positive__20TWindowSubStatusDispFPvi
#undef select_item_icon__20TWindowSubStatusDispFPviUcUci
#undef replace_owned_string__20TWindowSubStatusDispFPviiii

#include "pso/ui/ItemListRow.h"

typedef struct Row_8025930C {
    u8 pad0[0x10];
    f32 width;
    u8 pad14[8];
    u8 kind1c;
    u8 kind1d;
    u8 pad1e[2];
    char *label;
    char *suffix;
} Row_8025930C;

extern "C" {
u32 calc_text_width(char *s);
void set_text_draw_params(s32 arg0, s32 arg1, s32 arg2, f32 farg0, f32 farg1);
void draw_item_list_icon(s32, u8 *, s32, s32, f32);
}
s32 draw_window_text(f32 *pos, const char *s, s32 color, s32 mode, f32 width);
extern const f32 lbl_805DCF14;
extern const f32 lbl_805DCF20;
extern const f32 lbl_805DCF24;
extern const f32 lbl_805DCF28;
extern const f32 lbl_805DCF2C;
void draw_item_list_row(ItemListRow *row, ItemListWindowView *win);
extern const f32 lbl_805DCF10;
extern const f32 lbl_805DCF18;
extern "C" {
void calc_row_width__20TWindowSubStatusDispFv(Row_8025930C *arg0);
s32 mem_alloc(s32);
s32 measure_string_len__20TWindowSubStatusDispFv(s32);
char *strncpy(char *, const char *, unsigned long);
s32 replace_owned_string__20TWindowSubStatusDispFPviiii(void *arg0, s32 src, s32 buf, s32 mask, s32 copy);
#define is_wrapped__9TItemDataFPv ((s32 (*)(void *))is_wrapped__9TItemDataFPv)
#define select_item_icon__20TWindowSubStatusDispFPviUcUci ((s32 (*)(void *, s32, u8, u8, s32))select_item_icon__20TWindowSubStatusDispFPviUcUci)
#define forward_message__6TLobbyFlUl ((s32 (*)(s32, void *))forward_message__6TLobbyFlUl)
#define get_item_data__6TLobbyFUl ((s32 (*)(void *))get_item_data__6TLobbyFUl)

void TWindowSubStatusDisp::set_ground_item(void *it, s32 arg2) {
    s32 temp_r31;

    *(f32 *)((s8 *)this + 8) = (f32) lbl_805DCF08;
    *(s8 *)&this->unk_1C = 0x33;
    temp_r31 = get_item_data__6TLobbyFUl(it);
    select_item_icon__20TWindowSubStatusDispFPviUcUci(this, temp_r31, *(u8 *)((s8 *)it + 0), *(u8 *)((s8 *)it + 1), is_wrapped__9TItemDataFPv(it));
    forward_message__6TLobbyFlUl(get_shared_text_buffer(), it);
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (s32)(get_shared_text_buffer()), (s32)(*(s32 *)((s8 *)this + 0x20)), 8, 1);
    if (TCameraCtrl::get_camera_id() <= 2) {
        text_builder_reset();
        TWindowSubStatusDisp__sub_80228F5C(*(s32 *)((s8 *)it + 0x10));
        *(s32 *)&this->m_24 = replace_owned_string__20TWindowSubStatusDispFPviiii(this, (s32)(get_shared_text_buffer()), (s32)(*(s32 *)&this->m_24), 0x10, 1);
    }
    update_item_colors((s32)it);
    *(s32 *)((s8 *)this + 0x18) = arg2;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
}

extern const f32 lbl_805DCF0C;

void TWindowSubStatusDisp::init_display(s32 src, s32 arg2) {
    *(f32 *)((s8 *)this + 8) = (f32) lbl_805DCF0C;
    *(s8 *)&this->unk_1C = 0x33;
    this->m_1d = 0x33;
    *(s32 *)((s8 *)this + 0x20) = replace_owned_string__20TWindowSubStatusDispFPviiii(this, src, (s32)(*(s32 *)((s8 *)this + 0x20)), 8, 1);
    *(s32 *)((s8 *)this + 0x30) = -1;
    *(s32 *)((s8 *)this + 0x18) = arg2;
    *(u16 *)((s8 *)this + 0) = (u16) (*(u16 *)((s8 *)this + 0) | 0x45);
}

    extern unsigned char status_disp_item_icon_coord_table[];

s32 replace_owned_string__20TWindowSubStatusDispFPviiii(void *arg0, s32 src, s32 buf, s32 mask, s32 copy) {
    u16 *flags = (u16 *)arg0;
    s32 n;
    if (buf != 0 && (*flags & mask)) {
        *flags &= ~mask;
        mem_free((void *)buf);
    }
    if ((u32)src != 0 && copy != 0) {
        n = measure_string_len__20TWindowSubStatusDispFv(src);
        buf = mem_alloc(n + 1);
        strncpy((char *)buf, (const char *)src, n + 1);
        *flags |= mask;
    } else {
        buf = src;
    }
    return buf;
}

void calc_row_width__20TWindowSubStatusDispFv(Row_8025930C *arg0) {
    arg0->width = lbl_805DCF08;
    if (((TWindowSubStatusDisp *)arg0)->is_flag_4_set() != 0) {
        if (arg0->kind1c != 0x33) {
            arg0->width += lbl_805DCF10;
        } else if (arg0->kind1d != 0x33) {
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
}

typedef struct ItemListRow ItemListRow;
typedef struct ItemListPosition ItemListPosition;
typedef struct ItemListWindowView ItemListWindowView;
#pragma fp_contract on
void draw_item_list_row(ItemListRow *row, ItemListWindowView *win) {
  ItemListPosition pos;
  ItemListRow *new_var;
  f32 y;
  f32 depth;
  s32 style;
  if (((TWindowSubStatusDisp *)row)->is_flag_4_set() != 0)
  {
    y = win->y + row->y;
    if (((!((row->height + y) < win->clip_top)) && (!((win->y + row->y) > win->clip_bottom))) && (win->visible >= 0))
    {
      pos.x = win->x + row->x;
      pos.y = win->y + row->y;
      depth = lbl_805DCF20 / (lbl_805DCF24 + win->depth);
      if (row->flags & 0x200)
      {
        draw_item_list_icon((s32) win, (u8 *)&pos, row->status_icon, -1, depth);
        pos.x += lbl_805DCF14;
        draw_item_list_icon((s32) win, (u8 *)&pos, row->category_icon, -1, depth);
        pos.x += lbl_805DCF14;
        draw_item_list_icon((s32) win, (u8 *)&pos, (u8) row->status_style, -1, depth);
        pos.x += lbl_805DCF14;
      }
      else
      {
        TObjPlayer::init_xyz_limits();
        if (row->flags & 0x100)
        {
          pos.x += lbl_805DCF14;
          draw_item_list_icon((s32) win, (u8 *)&pos, row->status_icon, row->status_style, depth);
        }
        else
        {
          draw_item_list_icon((s32) win, (u8 *)&pos, row->status_icon, row->status_style, depth);
          pos.x += lbl_805DCF14;
        }
        TObjPlayer::reset_transform_state();
        draw_item_list_icon((s32) win, (u8 *)&pos, row->category_icon, row->category_style, depth);
        pos.x += lbl_805DCF14;
      }
      new_var = row;
      if (new_var->flags & 0x1000)
      {
        set_text_draw_params((s32)win, 1, 0, (f32)depth, (f32)win->text_clip);
      }
      else
      {
        set_text_draw_params((s32)win, 1, 1, (f32)depth, (f32)lbl_805DCF28);
      }
      if (new_var->flags & 0x400)
      {
        pos.x = (lbl_805DCF2C * win->width) + win->x;
        pos.x = -((lbl_805DCF2C * ((f32) calc_text_width((char *)new_var->label))) - pos.x);
      }
      if (row->flags & 0x800)
      {
        style = TWindowCtrl::get_field24();
      }
      else
      {
        style = new_var->style;
      }
      if (new_var->flags & 0x1000)
      {
        draw_window_text((f32 *)&pos, (const char *)row->label, style, 0, (f32)lbl_805DCF28);
      }
      else
      {
        draw_window_text((f32 *)&pos, (const char *)new_var->label, style, 1, (f32)lbl_805DCF28);
      }
      f32 width = (f32) calc_text_width((char *)new_var->suffix);
      pos.x = (win->x + win->width) - width;
      draw_window_text((f32 *)&pos, (const char *)row->suffix, new_var->suffix_style, 1, (f32)lbl_805DCF28);
    }
  }
}
extern "C" {

void TWindowSubStatusDisp::check_flag_4_noop() {
    if (this->is_flag_4_set()) return;
}

#undef is_wrapped__9TItemDataFPv
#undef select_item_icon__20TWindowSubStatusDispFPviUcUci
#undef forward_message__6TLobbyFlUl
#undef get_item_data__6TLobbyFUl

s32 deleting_destructor__20TWindowSubStatusDispFs(void *, s32);

extern s32 lbl_804CF9B0[];

void *TWindowSubStatusDisp::dispose(s16 arg1) {
    u16 temp_r3;
    u16 temp_r3_2;

    if (this != NULL) {
        *(s32 * *)&this->m_flags = lbl_804CF9B0;
        if ((u32) *(u32 *)&this->m_24 != 0U) {
            temp_r3 = *(u16 *)&this->m_name;
            if (temp_r3 & 0x10) {
                *(u16 *)&this->m_name = (u16) (temp_r3 & 0xFFFFFFEF);
                mem_free((void *)(*(u32 *)&this->m_24));
            }
        }
        if ((u32) *(u32 *)&this->m_20 != 0U) {
            temp_r3_2 = *(u16 *)&this->m_name;
            if (temp_r3_2 & 8) {
                *(u16 *)&this->m_name = (u16) (temp_r3_2 & 0xFFFFFFF7);
                mem_free((void *)(*(u32 *)&this->m_20));
            }
        }
        deleting_destructor__20TWindowSubStatusDispFs(this, 0);
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}
}
