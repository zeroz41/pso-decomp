#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
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
#include "pso/player/PlayerSlots.h"


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

void ItemListRow::advance_state() {
    if ((u8) this->category_icon == 0x14) {
        this->category_icon = 0x15U;
    }
}

void ItemListRow::finalize_state() {
    if ((u8) this->category_icon == 0x15) {
        this->category_icon = 0x14U;
    }
}


void ItemListRow::reset() {
    this->status_icon = 0x33;
    this->category_icon = 0x33;
    this->status_style = -1;
    this->category_style = -1;
    this->style = -1;
    this->suffix_style = -1;
    this->item = 0;
    if (this->suffix != NULL && (this->flags & 0x10)) {
        mem_free(this->suffix);
    }
    this->suffix = NULL;
    if (this->label != NULL && (this->flags & 8)) {
        mem_free(this->label);
    }
    this->label = NULL;
    this->flags = (u16) (this->flags & ~0x1BFD);
}

saddr get_shared_text_buffer();
s32 text_builder_append_int(s32);
void text_builder_append(u8 *str);
}
void text_builder_reset(void);

extern s32 lbl_805DCF00;

void ItemListRow::update_stat_line(s32 value) {
    text_builder_reset();
    text_builder_append((u8 *)&lbl_805DCF00);
    text_builder_append_int(value);
    this->suffix = (char *)replace_owned_string(get_shared_text_buffer(), (saddr)this->suffix, 0x10, 1);
}

void ItemListRow::update_stat_line_if_positive(s32 count) {
    if (count > 0) {
        update_stat_line(count);
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

extern "C" {
extern const f32 lbl_805DCF04;
extern const f32 lbl_805DCF08;
void TWindowSubStatusDisp__sub_80258A28(ItemListRow *row, s32 arg1, s32 arg2);

void ItemListRow::update_item_icon_colors(void *item) {
    s16 sp8;
    s32 temp_r26;
    s32 temp_r27;
    s32 usable_action_flags;
    s32 temp_r28_2;
    saddr player;

    if (((TItem *)item)->is_wrapped() != 0) {
        this->style = -1;
        return;
    }
    player = (saddr)get_player_by_client_id(this->client);
    if (player != 0) {
        temp_r26 = ((TItem *)item)->test_item_flags(8);
        usable_action_flags = ((TItem *)item)->get_usable_action_flags(0x10, (TObjPlayer *)player);
        temp_r27 = ((TItem *)item)->check_equip_requirements((TObjPlayer *)player, (s16 *)(&sp8));
        temp_r28_2 = ((VObj18B_802582c4_80257784 *) item)->vm8C();
        if (usable_action_flags != 0) {
            if (temp_r26 != 0) {
                this->status_icon = 0x30;
            } else {
                this->status_icon = 0x2F;
            }
        } else if (temp_r26 != 0) {
            this->status_icon = 0xC;
        } else {
            if ((temp_r28_2 == 0) && (((TItem *)item)->is_rare_item() != 0)) {
                this->status_icon = 0x19;
            } else if (sp8 & 1) {
                this->status_icon = 0x13;
            } else {
                this->status_icon = 0x33;
            }
            this->status_style = -1;
        }
        if (temp_r28_2 == 0) {
            this->category_style = -1;
            this->style = 0xFF00FFFC;
            return;
        }
        if (temp_r27 != 0) {
            this->category_style = -1;
            if (((TItem *)item)->is_custom_name_srank() != 0) {
                this->style = 0xFFFE3C28;
                return;
            }
            if (((TItem *)item)->get_name_style() == 2) {
                this->flags |= 0x800;
                return;
            }
            if ((u8)((TItem *)item)->calc_display_grade() >= 9U) {
                this->style = -0x1600;
                return;
            }
            if (((TItem *)item)->has_bonus_stats() != 0) {
                this->style = 0xFF61E853;
                return;
            }
            if (((TItem *)item)->get_usable_action_flags(0x10000, (TObjPlayer *)player) != 0U) {
                this->style = 0xFF909090;
                return;
            }
            this->style = -1;
            return;
        }
        if (sp8 & 1) {
            this->style = 0xFF909090;
            this->category_style = 0xFFAAAAAA;
            return;
        }
        this->style = 0xFF909090;
        this->category_style = 0xFFAAAAAA;
    }
}

void ItemListRow::update_item_colors(saddr item) {
    s32 requirement;
    s32 temp_r29;
    s32 temp_r30;
    saddr player;

    if (TItemData::is_wrapped((void *)item) != 0) {
        this->style = -1;
        return;
    }
    player = (saddr)get_player_by_client_id(this->client);
    if (player != 0) {
        temp_r29 = check_equip_requirements((void *)player, (TItemData *)item, &requirement);
        temp_r30 = ((TItemData *)item)->check_item_flags();
        if ((u8) this->status_icon == 0x33) {
            if ((temp_r30 == 0) && (TItemData::is_rare_item((u8 *)item) != 0)) {
                this->status_icon = 0x19U;
            } else if (requirement & 1) {
                this->status_icon = 0x13U;
            }
            this->status_style = -1;
        }
        if (temp_r30 == 0) {
            this->category_style = -1;
            this->style = 0xFF00FFFC;
            return;
        }
        if (temp_r29 != 0) {
            this->category_style = -1;
            if (TItemData::is_custom_name_srank((u8 *)item) != 0) {
                this->style = 0xFFFE3C28;
                return;
            }
            if (((TItemData *)item)->get_name_style() == 2) {
                this->flags |= 0x800;
                return;
            }
            if ((u8)((TItemData *)item)->calc_display_grade() >= 9U) {
                this->style = -0x1600;
                return;
            }
            if (((TItemData *)item)->has_bonus_stats() != 0) {
                this->style = 0xFF61E853;
                return;
            }
            if (((TItemData *)item)->calc_action_flags(0x10000, (u8 *)player) != 0U) {
                this->style = 0xFF909090;
                return;
            }
            this->style = -1;
            return;
        }
        if (requirement & 1) {
            this->style = 0xFF909090;
            this->category_style = 0xFFAAAAAA;
            return;
        }
        this->style = 0xFF909090;
        this->category_style = 0xFFAAAAAA;
    }
}

void ItemListRow::select_item_icon(s32 item_data, u8 arg2, u8 arg3, s32 arg4) {
    if (arg4 != 0) {
        this->category_icon = 8;
        return;
    }
    switch (item_data) {
    case 1:
        this->category_icon = 0;
        return;
    case 3:
        this->category_icon = 1;
        return;
    case 2:
        this->category_icon = 2;
        return;
    default:
        switch ((s32) arg2) {
        case 1:
            if (arg3 == 3) {
                this->category_icon = 4;
                return;
            }
            if (arg3 == 2) {
                this->category_icon = 0xA;
                return;
            }
            this->category_icon = 0xB;
            return;
        case 2:
            this->category_icon = 3;
            return;
        case 3:
            if (arg3 == 0) {
                this->category_icon = 5;
                return;
            }
            if (arg3 == 1) {
                this->category_icon = 7;
                return;
            }
            if (arg3 == 2) {
                this->category_icon = 6;
                return;
            }
            this->category_icon = 8;
            return;
        case 4:
            this->category_icon = 9;
            return;
        case 0:
        default:
            this->category_icon = 0x33;
            return;
        }
        break;
    }
}

void ItemListRow::setup_entry_msg_d1(s32 arg1) {
    this->x = (f32) lbl_805DCF04;
    this->status_icon = 0x33;
    this->category_icon = 0x33;
    this->label = (char *)replace_owned_string((s32)((saddr) (TWindowSubStatusDisp::get_message_10(0xD1))), (s32)((int) ((saddr)this->label)), 8, 1);
    this->style = 0xFF909090;
    this->item = arg1;
    this->flags |= 0xC5;
}

void ItemListRow::setup_entry_msg_d0(s32 arg1) {
    this->x = (f32) lbl_805DCF08;
    this->status_icon = 0x33;
    this->category_icon = 0x33;
    this->label = (char *)replace_owned_string((s32)((saddr) (TWindowSubStatusDisp::get_message_10(0xD0))), (s32)((int) ((saddr)this->label)), 8, 1);
    this->style = 0xFF909090;
    this->item = arg1;
    this->flags |= 0xC5;
}

void ItemListRow::init_no_item_entry(s32 arg1) {
    this->x = (f32) lbl_805DCF08;
    this->status_icon = 0x33;
    this->category_icon = 0x33;
    this->label = (char *)replace_owned_string((s32)((saddr) (TWindowSubStatusDisp::get_message_10(0xCF))), (s32)((int) ((saddr)this->label)), 8, 1);
    this->style = 0xFF909090;
    this->item = arg1;
    this->flags |= 0xC5;
}

void ItemListRow::init_entry(u8 arg1, u8 arg2, u8 arg3, u32 src, s32 arg5) {
    this->x = (f32) lbl_805DCF08;
    this->status_icon = arg1;
    this->category_icon = arg2;
    this->status_style = (s32) arg3;
    this->category_style = -1;
    this->label = (char *)replace_owned_string(src, (saddr)this->label, 8, 1);
    this->style = -1;
    this->item = arg5;
    this->flags |= 0x245;
}

void TWindowSubStatusDisp__sub_80258A28(ItemListRow *row, s32 arg1, s32 arg2) {
    row->x = (f32) lbl_805DCF08;
    row->status_icon = 0x33;
    row->category_icon = 9;
    text_builder_reset();
    text_builder_append_int(arg1);
    text_builder_append((u8 *)((s32 *) (TWindowSubStatusDisp::get_download_server())));
    row->suffix = (char *)row->replace_owned_string((s32)((int) (get_shared_text_buffer())), (s32)((int) ((saddr)row->suffix)), 0x10, 1);
    row->suffix_style = -1;
    row->item = arg2;
    row->flags |= 0x45;
}

void ItemListRow::setup_stat_line(s32 src, s32 arg2, s32 arg3) {
    this->x = (f32) lbl_805DCF08;
    this->status_icon = 0x33;
    this->category_icon = 0x2D;
    this->label = (char *)replace_owned_string(src, (saddr)this->label, 8, 1);
    update_stat_line(arg2);
    this->item = arg3;
    if (arg2 <= 0) {
        this->style = 0xFF909090;
        this->category_style = 0xFFAAAAAA;
        this->flags |= 0xC5;
    } else if ((is_current_area_item_enabled() == 0) || (is_boss_area() != 0)) {
        this->style = 0xFF909090;
        this->category_style = 0xFFAAAAAA;
        this->flags |= 0x45;
    } else {
        this->style = -1;
        this->category_style = -1;
        this->flags |= 0x45;
    }
    this->suffix_style = (s32) this->style;
}
void ItemListRow::init_status_entry_by_flag(s32 flag, u32 src, s32 item) {
    u8 category_icon;
    if (flag) {
        category_icon = 0x14;
    } else {
        category_icon = 0x15;
    }
    init_status_entry(category_icon, src, item);
    this->x = lbl_805DCF04;
}

void ItemListRow::init_list_entry(u8 icon, s32 src, s32 arg3) {
    u8 var_r0;

    var_r0 = icon;
    this->x = (f32) lbl_805DCF04;
    if (icon == 0x18) {
        var_r0 = 0x16;
    }
    this->status_icon = var_r0;
    this->category_icon = 0x33;
    this->status_style = -1;
    this->category_style = -1;
    this->label = (char *)replace_owned_string(src, (saddr)this->label, 8, 1);
    this->style = -1;
    this->suffix_style = -1;
    this->item = arg3;
    this->flags |= 0x145;
    if (icon == 0x18) {
        this->flags |= 0x80;
        this->style = 0xFF909090;
    }
}
void ItemListRow::init_status_entry(u8 category_icon, u32 src, s32 item) {
    this->x = lbl_805DCF04;
    this->status_icon = 0x33;
    this->category_icon = category_icon;
    this->status_style = -1;
    this->category_style = -1;
    this->label = (char *)replace_owned_string(src, (saddr)this->label, 8, 1);
    this->style = -1;
    this->suffix_style = -1;
    this->item = item;
    this->flags |= 0x45;
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
s32 TObjPlayer__sub_801C1AC8(void *);
void ItemListRow::set_inventory_item(void *item, s32 count, s32 sid) {
    s32 item_data;

    this->x = (f32) lbl_805DCF08;
    item_data = ((TItem *)item)->get_icon_index();
    select_item_icon(item_data, ((TItem *)item)->get_item_type(), ((TItem *)item)->get_item_group(), ((TItem *)item)->is_wrapped());
    this->label = (char *)replace_owned_string((saddr)((TItem *)item)->get_name(), (saddr)this->label, 8, 1);
    if (TObjPlayer__sub_801C1AC8(item) != 0) {
        update_stat_line_if_positive(count);
    }
    update_item_icon_colors(item);
    this->suffix_style = (s32) this->style;
    this->item = sid;
    this->flags |= 0x45;
}

void ItemListRow::update_from_player(void *item, s32 price, s32 index) {
    s32 temp_r31;
    s32 temp_r30;
    s32 item_data;

    this->x = (f32) lbl_805DCF08;
    item_data = ((TItem *)item)->get_icon_index();
    select_item_icon(item_data, ((TItem *)item)->get_item_type(), ((TItem *)item)->get_item_group(), ((TItem *)item)->is_wrapped());
    this->label = (char *)replace_owned_string((saddr)((TItem *)item)->get_name(), (saddr)this->label, 8, 1);
    if (TCameraCtrl::get_camera_id() <= 2) {
        text_builder_reset();
        text_builder_append_int(price);
        this->suffix = (char *)replace_owned_string(get_shared_text_buffer(), (saddr)this->suffix, 0x10, 1);
    }
    update_item_icon_colors(item);
    this->item = index;
    this->flags |= 0x45;
}
void ItemListRow::init_item_row(void *item, s32 arg2) {
    s32 item_data;
    this->x = (f32) lbl_805DCF08;
    item_data = ((TItem *)item)->get_icon_index();
    select_item_icon(item_data, ((TItem *)item)->get_item_type(), ((TItem *)item)->get_item_group(), ((TItem *)item)->is_wrapped());
    this->label = (char *)replace_owned_string((saddr)((TItem *)item)->get_name(), (saddr)this->label, 8, 1);
    if (TObjPlayer__sub_801C1AC8(item) != 0) {
        s32 v = ((V_80258F34 *) item)->m34();
        update_stat_line_if_positive(v);
    }
    update_item_icon_colors(item);
    this->suffix_style = (s32) this->style;
    this->item = arg2;
    this->flags |= 0x45;
}



    extern const float lbl_805DCF08;

void ItemListRow::set_item_info(void *a1, s32 index, s32 count) {
    saddr item_data;
    saddr temp_r3;

    this->x = lbl_805DCF08;
    this->status_icon = 51;
    item_data = TLobby::get_item_data((uaddr)a1);
    temp_r3 = TItemData::is_wrapped(a1);
    select_item_icon(item_data, *(unsigned char*)((char*)a1 + 0x0), *(unsigned char*)((char*)a1 + 0x1), temp_r3);
    TLobby::forward_message(get_shared_text_buffer(), (uaddr)(void *)a1);
    this->label = (char *)replace_owned_string(get_shared_text_buffer(), (saddr)this->label, 8, 1);
    update_stat_line_if_positive(count);
    update_item_colors((saddr)a1);
    this->suffix_style = this->style;
    this->item = index;
    this->flags = (this->flags | 0x45);
}

}


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

void ItemListRow::set_ground_item(void *it, s32 index) {
    s32 item_data;

    this->x = (f32) lbl_805DCF08;
    this->status_icon = 0x33;
    item_data = TLobby::get_item_data((uaddr)it);
    select_item_icon(item_data, *(u8 *)((s8 *)it + 0), *(u8 *)((s8 *)it + 1), TItemData::is_wrapped(it));
    TLobby::forward_message(get_shared_text_buffer(), (uaddr)(void *)it);
    this->label = (char *)replace_owned_string(get_shared_text_buffer(), (saddr)this->label, 8, 1);
    if (TCameraCtrl::get_camera_id() <= 2) {
        text_builder_reset();
        text_builder_append_int(*(s32 *)((s8 *)it + 0x10));
        this->suffix = (char *)replace_owned_string(get_shared_text_buffer(), (saddr)this->suffix, 0x10, 1);
    }
    update_item_colors((saddr)it);
    this->item = index;
    this->flags |= 0x45;
}

extern const f32 lbl_805DCF0C;

void ItemListRow::init_display(s32 src, s32 arg2) {
    this->x = (f32) lbl_805DCF0C;
    this->status_icon = 0x33;
    this->category_icon = 0x33;
    this->label = (char *)replace_owned_string(src, (s32)((saddr)this->label), 8, 1);
    this->style = -1;
    this->item = arg2;
    this->flags |= 0x45;
}

saddr ItemListRow::replace_owned_string(saddr src, saddr buf, s32 mask, s32 copy) {
    s32 n;
    if (buf != 0 && (this->flags & mask)) {
        this->flags &= ~mask;
        mem_free((void *)buf);
    }
    if ((u32)src != 0 && copy != 0) {
        n = (s32)measure_string_len((const char *)(src));
        buf = reinterpret_cast<saddr>(mem_alloc(n + 1U));
        strncpy((char *)buf, (const char *)src, n + 1);
        this->flags |= mask;
    } else {
        buf = src;
    }
    return buf;
}

void ItemListRow::calc_row_width() {
    this->width = lbl_805DCF08;
    if (this->is_flag_4_set() != 0) {
        if (this->status_icon != 0x33) {
            this->width += lbl_805DCF10;
        } else if (this->category_icon != 0x33) {
            this->width += lbl_805DCF14;
        }
        if (this->label != 0) {
            this->width += (f32)calc_text_width(this->label);
        }
        if (this->suffix != 0) {
            this->width += lbl_805DCF18;
            this->width += (f32)calc_text_width(this->suffix);
        }
    }
}

void*TWindowSubStatusDisp::get_entry_ptr(int a0) {  return (char*)status_disp_item_icon_coord_table + (unsigned char)(a0) * 8; }

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
        TObjFish::set_global_param(hud_texlist);
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

ItemListRow::ItemListRow(u8 *rec, s32 client) : TUnk_804CF998(client) {
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
