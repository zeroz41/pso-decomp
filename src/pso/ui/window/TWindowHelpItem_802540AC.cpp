#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"
#include "pso/ui/window/PageIndicator.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowHelpItem_802531A0.h"
#include "pso/ui/window/TWindowHelpItem_802540AC.h"
#include "pso/enemy/dimedian/TObjEneDimedian.h"
#include "pso/unk/text_80253974.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/PlayerRequirementStats.h"


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


struct Stats_802541E0 {
    u8 pad0[0xC];
    s16 atp;
    s16 dfp;
    s16 mst;
    s16 ata;
    s16 evp;
    u8 pad16[2];
};



typedef struct Stats_80254CE4 {
    s16 atp;
    s16 pad2;
    s16 mst;
    s16 ata;
    u8 pad8[0x10];
} Stats_80254CE4;

typedef struct Pmt_80254CE4 {
    u8 pad0[0xE];
    u16 req_atp;
    u16 req_mst;
    u16 req_ata;
} Pmt_80254CE4;


typedef struct Stats_802549B0 {
    s16 atp;
    s16 ata;
    s16 hp;
    s16 dfp;
    s16 evp;
    s16 lck;
    u8 padC[0xC];
} Stats_802549B0;

typedef struct Quest_802549B0 {
    u8 pad0[2];
    s16 f2;
    u8 pad4[8];
    s16 fc;
} Quest_802549B0;



extern "C" {

void preview_unequip_stats__10TObjPlayerFv(s32, Stats_802541E0 *, s32);
s32 preview_equip_stats__10TObjPlayerFv(u8 *player, s16 *out, u8 *incoming);
}
extern const f32 TWindowHelpItem__data_805DCDE4;
extern const f32 lbl_805DCE00;
extern const f32 lbl_805DCE04;
extern const f32 lbl_805DCE08;
extern const f32 lbl_805DCDEC;
extern const f32 lbl_805DCE0C;
extern "C" {
extern "C" u8 lbl_8044EDD8[];
extern "C" u8 lbl_8044EDE0[];
extern "C" u8 lbl_8044EDE8[];
extern "C" u8 lbl_8044EDF0[];
extern "C" u8 lbl_805DCDFC[4];
extern "C" u8 lbl_8044EDB8[];
extern "C" u8 lbl_8044EDC0[];
extern "C" u8 localized_alphabet_list[];
extern "C" u8 lbl_805DCDC8[];
extern "C" u8 lbl_805DCDCC[];
extern "C" u8 lbl_805DCDD0[];
extern "C" u8 lbl_805DCDD4[];
extern "C" u8 lbl_805DCDD8[];
extern "C" u8 lbl_805DCDDC[];
}
void *TWindowHelpItem::item_layout_entries[67] = {
    (void *)0xc, (void *)0x1, (void *)0xb, (void *)0x0,
    (void *)0x0, (void *)0xb, (void *)0x0, (void *)0x41a00000,
    (void *)0xb, (void *)0x0, (void *)0x42200000, (void *)0xb,
    (void *)0x0, (void *)0x42700000, (void *)0xb, (void *)0x0,
    (void *)0x42a00000, (void *)0xb, (void *)0x0, (void *)0x42c80000,
    (void *)0x6, (void *)0x0, (void *)0x42f60000, (void *)0x42fe0000,
    (void *)0x41a00000, (void *)0x0, (void *)0x43040000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)&localized_alphabet_list, (void *)0x1, (void *)0x4,
    (void *)0x3, (void *)0x42ce0000, (void *)0x42f80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCDC8, (void *)0x4,
    (void *)0x43170000, (void *)0x42f80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43170000,
    (void *)0x42f80000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)&lbl_805DCDCC, (void *)0x4, (void *)0x43500000, (void *)0x42f80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x43500000, (void *)0x42f80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCDD0,
};
extern "C" {
void *lbl_804CF24C[17] = {
    (void *)0x5, (void *)0x1, (void *)0xb, (void *)0x0,
    (void *)0x0, (void *)0xb, (void *)0x0, (void *)0x41a00000,
    (void *)0xb, (void *)0x0, (void *)0x42200000, (void *)0xb,
    (void *)0x0, (void *)0x42700000, (void *)0xb, (void *)0x0,
    (void *)0x42a00000,
};
}
void *TWindowHelpItem::resistance_layout_entries[31] = {
    (void *)0x7, (void *)0x1, (void *)0xb, (void *)0x0,
    (void *)0x0, (void *)0xb, (void *)0x0, (void *)0x41a00000,
    (void *)0xb, (void *)0x0, (void *)0x42200000, (void *)0xb,
    (void *)0x0, (void *)0x42700000, (void *)0xb, (void *)0x0,
    (void *)0x42a00000, (void *)0x3, (void *)0x425c0000, (void *)0x42f60000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x4, (void *)0x43530000, (void *)0x42f60000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0,
};
extern "C" {
void *lbl_804CF30C[118] = {
    (void *)0x10, (void *)0x1, (void *)0xb, (void *)0x0,
    (void *)0x0, (void *)0xb, (void *)0x0, (void *)0x41a00000,
    (void *)0xb, (void *)0x0, (void *)0x42200000, (void *)0x3,
    (void *)0x0, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DCDD4, (void *)0x4, (void *)0x42ac0000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x2, (void *)0x42c40000, (void *)0x42820000,
    (void *)0x3f000000, (void *)0xff0034ff, (void *)0x18, (void *)0x42c80000,
    (void *)0x42c80000, (void *)0x0, (void *)0xff00ca9e, (void *)0xffff2924,
    (void *)0x3, (void *)0x0, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCDD8, (void *)0x4,
    (void *)0x42ac0000, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x2, (void *)0x42c40000,
    (void *)0x42aa0000, (void *)0x3f000000, (void *)0xffe1000d, (void *)0x18,
    (void *)0x42c80000, (void *)0x42c80000, (void *)0x0, (void *)0xff00ca9e,
    (void *)0xffff2924, (void *)0x3, (void *)0x0, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCDDC,
    (void *)0x4, (void *)0x42ac0000, (void *)0x42c80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x2,
    (void *)0x42c40000, (void *)0x42d20000, (void *)0x3f000000, (void *)0xffffe000,
    (void *)0x18, (void *)0x42c80000, (void *)0x42c80000, (void *)0x0,
    (void *)0xff00ca9e, (void *)0xffff2924, (void *)0x3, (void *)0x0,
    (void *)0x42f00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)&lbl_8044EDB8, (void *)0x4, (void *)0x42ac0000, (void *)0x42f00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x2, (void *)0x42c40000, (void *)0x42fa0000, (void *)0x3f000000,
    (void *)0xff00ff14, (void *)0x18, (void *)0x42c80000, (void *)0x42c80000,
    (void *)0x0, (void *)0xff00ca9e, (void *)0xffff2924, (void *)0x3,
    (void *)0x0, (void *)0x0, (void *)0x3f000000, (void *)0xffffff00,
    (void *)0x0, (void *)&lbl_8044EDC0,
};
void *lbl_804CF4E4[50] = {
    (void *)0x4, (void *)0x1, (void *)0x6, (void *)0x420c0000,
    (void *)0x41900000, (void *)0x43160000, (void *)0x42d60000, (void *)0x0,
    (void *)0x0, (void *)0x3f19999a, (void *)0xffffffff, (void *)&hud_texlist,
    (void *)0x2, (void *)0x4, (void *)0x6, (void *)0x42aa0000,
    (void *)0x42480000, (void *)0x42480000, (void *)0x422c0000, (void *)0x43160000,
    (void *)0x42ac0000, (void *)0x3f333333, (void *)0xffffffff, (void *)&hud_texlist,
    (void *)0x4, (void *)0x4, (void *)0x6, (void *)0x43010000,
    (void *)0x41c00000, (void *)0x42480000, (void *)0x422c0000, (void *)0x43160000,
    (void *)0x42ac0000, (void *)0x3f333333, (void *)0xffffffff, (void *)&hud_texlist,
    (void *)0x4, (void *)0x4, (void *)0x6, (void *)0x42240000,
    (void *)0x42980000, (void *)0x42480000, (void *)0x422c0000, (void *)0x43160000,
    (void *)0x42ac0000, (void *)0x3f333333, (void *)0xffffffff, (void *)&hud_texlist,
    (void *)0x4, (void *)0x4,
};
void *window_help_item_layout_entries[12] = {
    (void *)0x2, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0xa, (void *)0x0, (void *)0x43000000,
};
void *help_item_tech_disk_window_layout_table[56] = {
    (void *)0x7, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x6, (void *)0x0, (void *)0x42f60000,
    (void *)0x42fe0000, (void *)0x41a00000, (void *)0x0, (void *)0x43040000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)&localized_alphabet_list, (void *)0x1,
    (void *)0x4, (void *)0x3, (void *)0x42ce0000, (void *)0x42f80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCDC8,
    (void *)0x4, (void *)0x43170000, (void *)0x42f80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x43170000, (void *)0x42f80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DCDCC, (void *)0x4, (void *)0x43500000,
    (void *)0x42f80000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x43500000, (void *)0x42f80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCDD0,
};
}
void *TWindowHelpItem::description_text_layout[9] = {
    (void *)0x1, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0,
};
extern "C" {
WindowDescriptor window_help_item_layout = {
    {228.0f, 184.0f}, 38900.0f, NULL, 3,
};

void TWindowHelpItem::set_items_and_refresh(void* a1, void* a2) { *(void* *)&this->item_id = a2; *(void* *)&this->item_data = a1; update_cursor_selection(); dispatch_item_help(); }

void TWindowHelpItem::set_displayed_item_data(void* a1, void* a2) { *(void* *)&this->displayed_item_id = a2; *(void* *)&this->displayed_item_data = a1; update_cursor_selection(); dispatch_item_help(); }

void TWindowHelpItem::set_displayed_item_colored(uaddr displayed_item_colored) {
    saddr var_r5;
    var_r5 = -0x100;
    if (displayed_item_colored == 0U) {
        var_r5 = -1;
    }
    set_displayed_item_data((void*)displayed_item_colored, (void*)var_r5);
}

void show_item_by_id__15TWindowHelpItemFPvi(u8 *window_help_item, saddr id) {
    u8 *item;
    if (id == -1) {
        ((TWindowHelpItem *)window_help_item)->set_items_and_refresh(NULL, (void*)((void*)((void *)-1)));
        return;
    }
    item = (u8 *)(find_item_by_id(id));
    if (item == NULL) {
        ((TWindowHelpItem *)window_help_item)->set_items_and_refresh(NULL, (void*)((void*)((void *) id)));
        return;
    }
    ((TItem *)item)->copy_to_item_data((TItemData *)(window_help_item + 0x74));
    ((TWindowHelpItem *)window_help_item)->set_items_and_refresh(window_help_item + 0x74, (void*)((void*)((void *) id)));
}

void TWindowHelpItem::set_displayed_item_by_id(saddr id) {
    TItem *item;
    if (id == -1) {
        set_displayed_item_data(NULL, (void *)-1);
        return;
    }
    item = find_item_by_id(id);
    if (item == NULL) {
        set_displayed_item_data(NULL, (void *)id);
        return;
    }
    item->copy_to_item_data(&displayed_item);
    set_displayed_item_data(&displayed_item, (void *)id);
}

void TWindowHelpItem::dispatch_item_help() {
    static void (TWindowHelpItem::*weapon_pages[3])() = {
        &TWindowHelpItem::show_weapon_requirements,
        &TWindowHelpItem::show_weapon_attributes,
        &TWindowHelpItem::show_item_description,
    };
    static void (TWindowHelpItem::*frame_pages[3])() = {
        &TWindowHelpItem::show_armor_requirements,
        &TWindowHelpItem::show_armor_resistances,
        &TWindowHelpItem::show_item_description,
    };
    static void (TWindowHelpItem::*barrier_pages[3])() = {
        &TWindowHelpItem::show_armor_requirements,
        &TWindowHelpItem::show_shield_resistances,
        &TWindowHelpItem::show_item_description,
    };
    static void (TWindowHelpItem::*mag_pages[3])() = {
        &TWindowHelpItem::show_mag_stats,
        &TWindowHelpItem::show_mag_growth,
        &TWindowHelpItem::show_mag_photon_blasts,
    };
    s8 page;
    u8 sub;

    entry_list.destroy_all_items();
    if (shown_item_id == -1) {
        help_flags &= 0xF8;
        m_callback = NULL;
        return;
    }
    page = page_indicator->get_type();
    help_flags |= 2;
    unlock_page_flip();
    if (active_item == NULL) {
        if ((s32)displayed_item_id == -0xFF) {
            help_flags &= ~2;
            lock_page_flip();
            init_text(TWindowSubStatusDisp::get_message_10(0x10D));
        } else {
            help_flags &= ~2;
            lock_page_flip();
            init_text((void *)(get_localized_text_entry(0x10, ((s32)displayed_item_id & 0xF) + 0x18)));
        }
    } else if (TItemData::is_wrapped(active_item) != 0) {
        help_flags &= ~2;
        lock_page_flip();
        update_displayed_item();
    } else {
        sub = active_item->data1.data_s8[1];
        switch (active_item->data1.data_u8[0]) {
        case 0:
            (this->*weapon_pages[page])();
            break;
        case 1:
            if (sub == 3) {
                help_flags &= ~2;
                lock_page_flip();
                show_item_description();
            } else if (sub == 2) {
                (this->*barrier_pages[page])();
            } else {
                (this->*frame_pages[page])();
            }
            break;
        case 2:
            (this->*mag_pages[page])();
            break;
        case 3:
            help_flags &= ~2;
            lock_page_flip();
            if (sub == 2) {
                update_tech_disk_details();
            } else {
                update_displayed_item();
            }
            break;
        default:
            help_flags &= 0xFC;
            m_callback = NULL;
            break;
        }
    }
    invoke_callback_pmf();
}

void TWindowHelpItem::invoke_callback_pmf() {
    if (m_callback) {
        (this->*m_callback)();
    }
}

void TWindowHelpItem::show_weapon_requirements() {
    TObjPlayer *pl;
    u8 *item;
    s32 flags;
    saddr a;
    TWindowHelpItem *b;
    saddr c;
    TWindowHelpItem *d;
    TWindowHelpItem *e;
    TWindowHelpItem *f;

    pl = get_player_by_client_id(client_index);
    if (pl != NULL) {
        init_help_texts();
        m_callback = &TWindowHelpItem::update_requirements;
        a = reinterpret_cast<saddr>(get_array_entry(6));
        b = (TWindowHelpItem *)(get_array_entry(7));
        c = reinterpret_cast<saddr>(get_array_entry(8));
        d = (TWindowHelpItem *)(get_array_entry(9));
        e = (TWindowHelpItem *)(get_array_entry(10));
        f = (TWindowHelpItem *)(get_array_entry(11));
        item = (u8 *)lookup_item_pmt_record((u8 *)active_item);
        if (check_equip_requirements(pl, active_item, &flags) == 0 && (flags & 1)) {
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(a), TWindowHelpItem__data_805DCDE4, lbl_805DCE00);
            b->set_flag0_bit2();
            ((TWindowHelpItem *)c)->set_flag0_bit2();
            d->set_flag0_bit2();
            e->set_flag0_bit2();
            f->set_flag0_bit2();
            return;
        }
        if (*(u16 *)(item + 0xE) != 0) {
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(a), TWindowHelpItem__data_805DCDE4, lbl_805DCE08);
            b->reset_float_field();
            d->reset_float_field();
            f->reset_float_field();
            *(s32 *)(c + 0x20) = *(u16 *)(item + 0xE);
            return;
        }
        if (*(u16 *)(item + 0x10) != 0) {
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(a), TWindowHelpItem__data_805DCDE4, lbl_805DCDEC);
            b->reset_float_field();
            d->reset_float_field();
            f->reset_float_field();
            *(s32 *)(c + 0x20) = *(u16 *)(item + 0x10);
            return;
        }
        if (*(u16 *)(item + 0x12) != 0) {
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(a), TWindowHelpItem__data_805DCDE4, lbl_805DCE0C);
            b->reset_float_field();
            d->reset_float_field();
            f->reset_float_field();
            *(s32 *)(c + 0x20) = *(u16 *)(item + 0x12);
            return;
        }
        ((TWindowHelpItem *)a)->set_flag0_bit2();
        b->set_flag0_bit2();
        ((TWindowHelpItem *)c)->set_flag0_bit2();
        d->set_flag0_bit2();
        e->set_flag0_bit2();
        f->set_flag0_bit2();
    }
}

void TWindowHelpItem::show_armor_requirements() {
    TObjPlayer *pl;
    u8 *item;
    s32 flags;
    saddr a;
    TWindowHelpItem *b;
    saddr c;
    TWindowHelpItem *d;
    TWindowHelpItem *e;
    TWindowHelpItem *f;

    pl = get_player_by_client_id(client_index);
    if (pl != NULL) {
        init_help_texts();
        m_callback = &TWindowHelpItem::update_level_requirement;
        a = reinterpret_cast<saddr>(get_array_entry(6));
        b = (TWindowHelpItem *)(get_array_entry(7));
        c = reinterpret_cast<saddr>(get_array_entry(8));
        d = (TWindowHelpItem *)(get_array_entry(9));
        e = (TWindowHelpItem *)(get_array_entry(10));
        f = (TWindowHelpItem *)(get_array_entry(11));
        item = (u8 *)lookup_item_pmt_record((u8 *)active_item);
        if (check_equip_requirements(pl, active_item, &flags) == 0 && (flags & 1)) {
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(a), TWindowHelpItem__data_805DCDE4, lbl_805DCE00);
            b->set_flag0_bit2();
            ((TWindowHelpItem *)c)->set_flag0_bit2();
            d->set_flag0_bit2();
            e->set_flag0_bit2();
            f->set_flag0_bit2();
            return;
        }
        if (item[0x10] != 0) {
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(a), TWindowHelpItem__data_805DCDE4, lbl_805DCE04);
            b->reset_float_field();
            d->reset_float_field();
            f->reset_float_field();
            *(s32 *)(c + 0x20) = item[0x10] + 1;
            return;
        }
        ((TWindowHelpItem *)a)->set_flag0_bit2();
        b->set_flag0_bit2();
        ((TWindowHelpItem *)c)->set_flag0_bit2();
        d->set_flag0_bit2();
        e->set_flag0_bit2();
        f->set_flag0_bit2();
    }
}

void TWindowHelpItem::show_mag_stats() {
    TWindowHelpItem *a;
    TWindowHelpItem *b;
    TWindowHelpItem *c;
    TWindowHelpItem *d;
    TWindowHelpItem *e;
    TWindowHelpItem *f;
    init_help_texts();
    m_callback = &TWindowHelpItem::update_stat_comparison;
    a = (TWindowHelpItem *)(get_array_entry(6));
    b = (TWindowHelpItem *)(get_array_entry(7));
    c = (TWindowHelpItem *)(get_array_entry(8));
    d = (TWindowHelpItem *)(get_array_entry(9));
    e = (TWindowHelpItem *)(get_array_entry(10));
    f = (TWindowHelpItem *)(get_array_entry(11));
    a->set_flag0_bit2();
    b->set_flag0_bit2();
    c->set_flag0_bit2();
    d->set_flag0_bit2();
    e->set_flag0_bit2();
    f->set_flag0_bit2();
}

void TWindowHelpItem::init_help_texts() {
    TWindowHelpItem *temp_r31;
    TWindowHelpItem *temp_r30;
    TWindowHelpItem *temp_r29;
    TWindowHelpItem *temp_r28;
    TWindowHelpItem *temp_r27;
    TWindowHelpItem *temp_r26;

    init_window_layout_entries(
        reinterpret_cast<WindowLayoutEntries *>((void *) ((u8 *) this + 0x24)),
        reinterpret_cast<const void *>(TWindowHelpItem::item_layout_entries),
        this->client_index);
    temp_r31 = (TWindowHelpItem *)(this->get_array_entry(0));
    temp_r30 = (TWindowHelpItem *)(this->get_array_entry(1));
    temp_r29 = (TWindowHelpItem *)(this->get_array_entry(2));
    temp_r28 = (TWindowHelpItem *)(this->get_array_entry(3));
    temp_r27 = (TWindowHelpItem *)(this->get_array_entry(4));
    temp_r26 = (TWindowHelpItem *)(this->get_array_entry(5));
    temp_r31->set_help_text((saddr) (TWindowSubStatusDisp::get_message_10(0x83)));
    temp_r30->set_help_text((saddr) (TWindowSubStatusDisp::get_message_10(0x84)));
    temp_r29->set_help_text((saddr) (TWindowSubStatusDisp::get_message_10(0x85)));
    temp_r28->set_help_text((saddr) (TWindowSubStatusDisp::get_message_10(0x86)));
    temp_r27->set_help_text((saddr) (TWindowSubStatusDisp::get_message_10(0x87)));
    temp_r26->set_help_text((saddr) (TWindowSubStatusDisp::get_message_10(0x88)));
}

struct Stats_802541E0;
void TWindowHelpItem::update_requirements() {
    s32 flags;
    Stats_80254CE4 st;
    TObjPlayer *pl;
    u8 *entry;
    Pmt_80254CE4 *pmt;
    ((TWindowSubStatusDisp *)((struct Stats_802541E0 *)&st))->clear_fields();
    pl = get_player_by_client_id(client_index);
    if (pl == NULL) {
        return;
    }
    update_stat_comparison();
    entry = (u8 *)get_array_entry(10);
    pmt = (Pmt_80254CE4 *)lookup_item_pmt_record((u8 *)active_item);
    if (check_equip_requirements(pl, active_item, &flags) == 0 && (flags & 1)) {
        return;
    }
    if (pmt->req_atp != 0) {
        if (build_player_equipment_requirement_stats(pl, (PlayerRequirementStats *)&st) != 0) {
            *(s32 *)(entry + 0x20) = st.atp;
        }
    } else if (pmt->req_mst != 0) {
        if (build_player_equipment_requirement_stats(pl, (PlayerRequirementStats *)&st) != 0) {
            *(s32 *)(entry + 0x20) = st.mst;
        }
    } else if (pmt->req_ata != 0) {
        if (build_player_equipment_requirement_stats(pl, (PlayerRequirementStats *)&st) != 0) {
            *(s32 *)(entry + 0x20) = st.ata;
        }
    }
}

void TWindowHelpItem::update_level_requirement() {
    s32 requirement;
    u8 *temp_r30;
    u8 *item_pmt_record;
    u8 *player;
    player = (u8 *)(((u8 *)get_player_by_client_id(client_index)));
    if (player != NULL) {
        if (((TObjPlayer *)player)->get_stats() != 0U) {
            update_stat_comparison();
            temp_r30 = (u8 *)(((u8 *)get_array_entry(0xA)));
            item_pmt_record = (u8 *)(lookup_item_pmt_record((u8 *)active_item));
            if (check_equip_requirements(player, active_item, &requirement) == 0) {
                if (!(requirement & 1)) {
                    goto block_4;
                }
            } else {
block_4:
                if ((u8) *(u8 *)((s8 *)item_pmt_record + 0x10) != 0) {
                    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) (((TObjPlayer *)(player))->get_actor_level_index() + 1);
                }
            }
        }
    }
}

void TWindowHelpItem::update_stat_comparison() {
    s32 flags;
    Stats_802549B0 st;
    saddr e0;
    saddr e3;
    saddr e1;
    saddr e4;
    saddr e2;
    saddr e5;
    Quest_802549B0 *q;
    saddr pl;
    ((TWindowSubStatusDisp *)((struct Stats_802541E0 *)&st))->clear_fields();
    pl = (saddr)get_player_by_client_id(client_index);
    if (pl == 0) {
        return;
    }
    q = (Quest_802549B0 *)((TObjPlayer *)pl)->get_stats();
    if (q == NULL) {
        return;
    }
    e0 = reinterpret_cast<saddr>(get_array_entry(0));
    e3 = reinterpret_cast<saddr>(get_array_entry(3));
    e1 = reinterpret_cast<saddr>(get_array_entry(1));
    e4 = reinterpret_cast<saddr>(get_array_entry(4));
    e2 = reinterpret_cast<saddr>(get_array_entry(2));
    e5 = reinterpret_cast<saddr>(get_array_entry(5));
    ((TWindowHelpItem *)e0)->set_value(((TObjPlayer *)pl)->get_atp() + ((TObjPlayer *)pl)->get_actor_attack_params_atp_min() + ((TObjPlayer *)pl)->get_atp_range());
    ((TWindowHelpItem *)e3)->set_value(((TObjPlayer *)pl)->get_ata());
    ((TWindowHelpItem *)e1)->set_value(((TWindowSubStatusDisp *)pl)->get_value());
    ((TWindowHelpItem *)e4)->set_value(((TObjPlayer *)pl)->get_evp());
    ((TWindowHelpItem *)e2)->set_value(q->f2);
    ((TWindowHelpItem *)e5)->set_value(q->fc);
    if (displayed_item_data == 0) {
        return;
    }
    if (is_item_already_equipped() != 0) {
        preview_unequip_stats__10TObjPlayerFv(pl, (Stats_802541E0 *)((struct Stats_802541E0 *)&st), displayed_item_id);
    } else {
        preview_equip_stats__10TObjPlayerFv((u8 *)pl, (s16 *)((Stats_802541E0 *)((struct Stats_802541E0 *)&st)), (u8 *)displayed_item_data);
    }
    ((TWindowHelpItem *)e0)->set_compare_value(st.atp);
    ((TWindowHelpItem *)e3)->set_compare_value(st.dfp);
    ((TWindowHelpItem *)e1)->set_compare_value(st.ata);
    ((TWindowHelpItem *)e4)->set_compare_value(st.evp);
    ((TWindowHelpItem *)e2)->set_compare_value(st.hp);
    ((TWindowHelpItem *)e5)->set_compare_value(st.lck);
    if (check_equip_requirements((void *)pl, (TItemData *)displayed_item_data, &flags) != 0) {
        TWindowHelpItem::set_flag_0x10((u16 *)e0, 1);
        TWindowHelpItem::set_flag_0x10((u16 *)e3, 1);
        TWindowHelpItem::set_flag_0x10((u16 *)e1, 1);
        TWindowHelpItem::set_flag_0x10((u16 *)e4, 1);
        TWindowHelpItem::set_flag_0x10((u16 *)e2, 1);
        TWindowHelpItem::set_flag_0x10((u16 *)e5, 1);
    } else {
        TWindowHelpItem::set_flag_0x10((u16 *)e0, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)e3, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)e1, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)e4, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)e2, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)e5, 0);
    }
}

void TWindowHelpItem::show_weapon_attributes() {
    saddr player;
    TWindowHelpItem *a;
    TWindowHelpItem *b;
    TWindowHelpItem *c;
    TWindowHelpItem *d;
    TWindowHelpItem *e;

    player = (saddr)get_player_by_client_id(client_index);
    if (player != 0) {
        init_window_layout_entries(
            &entry_list,
            reinterpret_cast<const void *>(lbl_804CF24C),
            client_index);
        m_callback = &TWindowHelpItem::update_stat_disp2;
        a = (TWindowHelpItem *)(get_array_entry(0));
        b = (TWindowHelpItem *)(get_array_entry(1));
        c = (TWindowHelpItem *)(get_array_entry(2));
        d = (TWindowHelpItem *)(get_array_entry(3));
        e = (TWindowHelpItem *)(get_array_entry(4));
        a->set_help_text((saddr)lbl_8044EDD8);
        b->set_help_text((saddr)lbl_8044EDE0);
        c->set_help_text((saddr)lbl_8044EDE8);
        d->set_help_text((saddr)lbl_8044EDF0);
        e->set_help_text((saddr)lbl_805DCDFC);
        a->set_flag0_bit20();
        b->set_flag0_bit20();
        c->set_flag0_bit20();
        d->set_flag0_bit20();
        e->set_flag0_bit20();
        set_percentage_rows((WeaponAttribute *)((TObjPlayer *)player)->get_attribute_entry(0), &TWindowHelpItem::set_value);
        if (displayed_item_data != 0) {
            if (is_item_already_equipped() != 0) {
                set_percentage_rows(NULL, &TWindowHelpItem::set_compare_value);
            } else {
                set_percentage_rows((WeaponAttribute *)(displayed_item_data + 6), &TWindowHelpItem::set_compare_value);
            }
            e->update_visible_flags();
        }
    }
}

void TWindowHelpItem::update_stat_disp2() {
    s32 requirement;
    saddr temp_r31;
    saddr temp_r30;
    saddr temp_r29;
    saddr temp_r28;
    saddr temp_r27;
    saddr player;
    uaddr item;
    player = (saddr)get_player_by_client_id(client_index);
    if ((player != 0) && (temp_r31 = reinterpret_cast<saddr>(get_array_entry(0)), temp_r30 = reinterpret_cast<saddr>(get_array_entry(1)), temp_r29 = reinterpret_cast<saddr>(get_array_entry(2)), temp_r28 = reinterpret_cast<saddr>(get_array_entry(3)), temp_r27 = reinterpret_cast<saddr>(get_array_entry(4)), (item = displayed_item_data, (item == 0U) == 0))) {
        if (check_equip_requirements((void *)player, (TItemData *)item, &requirement) != 0) {
            TWindowHelpItem::set_flag_0x10((u16 *)temp_r31, 1);
            TWindowHelpItem::set_flag_0x10((u16 *)temp_r30, 1);
            TWindowHelpItem::set_flag_0x10((u16 *)temp_r29, 1);
            TWindowHelpItem::set_flag_0x10((u16 *)temp_r28, 1);
            TWindowHelpItem::set_flag_0x10((u16 *)temp_r27, 1);
            return;
        }
        TWindowHelpItem::set_flag_0x10((u16 *)temp_r31, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)temp_r30, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)temp_r29, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)temp_r28, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)temp_r27, 0);
    }
}

void TWindowHelpItem::set_percentage_rows(WeaponAttribute *attributes, void (TWindowHelpItem::*set)(s32)) {
    u32 i;
    TWindowHelpItem *e0;
    TWindowHelpItem *e1;
    TWindowHelpItem *e2;
    TWindowHelpItem *e3;
    TWindowHelpItem *e4;

    e0 = (TWindowHelpItem *)get_array_entry(0);
    e1 = (TWindowHelpItem *)get_array_entry(1);
    e2 = (TWindowHelpItem *)get_array_entry(2);
    e3 = (TWindowHelpItem *)get_array_entry(3);
    e4 = (TWindowHelpItem *)get_array_entry(4);
    (e0->*set)(0);
    (e1->*set)(0);
    (e2->*set)(0);
    (e3->*set)(0);
    if (attributes != NULL) {
        for (i = 0; i < 3; i++, attributes++) {
            switch (attributes->area) {
            case 1:
                (e0->*set)(attributes->percent);
                break;
            case 2:
                (e1->*set)(attributes->percent);
                break;
            case 3:
                (e2->*set)(attributes->percent);
                break;
            case 4:
                (e3->*set)(attributes->percent);
                break;
            case 5:
                (e4->*set)(attributes->percent);
                break;
            }
        }
    }
}

void TWindowHelpItem::show_armor_resistances() {
    void *temp_r30;
    void *temp_r31;
    update_resistance_rows();
    temp_r30 = (get_array_entry(5));
    temp_r31 = (get_array_entry(6));
    TWindowDuelResult::set_default_status(temp_r30, (saddr)TWindowSubStatusDisp::get_message_10(0xA1));
    ((TWindowHelpItem *)temp_r30)->reset_float_field();
    *(s32 *)((s8 *)temp_r31 + 0x20) = active_item->data1.data_u8[5];
}

void TWindowHelpItem::show_shield_resistances() {
    TWindowHelpItem *temp_r31;
    TWindowHelpItem *temp_r31_2;
    update_resistance_rows();
    temp_r31 = (TWindowHelpItem *)(get_array_entry(5));
    temp_r31_2 = (TWindowHelpItem *)(get_array_entry(6));
    temp_r31->set_flag0_bit2();
    temp_r31_2->set_flag0_bit2();
}

void TWindowHelpItem::update_resistance_rows() {
    Stats_802541E0 st;
    TWindowHelpItem *a;
    TWindowHelpItem *b;
    TWindowHelpItem *c;
    TWindowHelpItem *d;
    TWindowHelpItem *e;
    saddr pl;
    ((TWindowSubStatusDisp *)(&st))->clear_fields();
    pl = (saddr)get_player_by_client_id(client_index);
    if (pl != 0) {
        init_window_layout_entries(
            &entry_list,
            reinterpret_cast<const void *>(TWindowHelpItem::resistance_layout_entries),
            client_index);
        m_callback = item_help_resistance_stat_callback;
        a = (TWindowHelpItem *)(get_array_entry(0));
        b = (TWindowHelpItem *)(get_array_entry(1));
        c = (TWindowHelpItem *)(get_array_entry(2));
        d = (TWindowHelpItem *)(get_array_entry(3));
        e = (TWindowHelpItem *)(get_array_entry(4));
        a->set_help_text((uaddr)TWindowSubStatusDisp::get_message_10(0x89));
        b->set_help_text((uaddr)TWindowSubStatusDisp::get_message_10(0x8A));
        c->set_help_text((uaddr)TWindowSubStatusDisp::get_message_10(0x8B));
        d->set_help_text((uaddr)TWindowSubStatusDisp::get_message_10(0x8C));
        e->set_help_text((uaddr)TWindowSubStatusDisp::get_message_10(0x8D));
        a->set_value(((TWindowSubStatusDisp *)pl)->get_stat());
        b->set_value(((TObjPlayer *)pl)->get_class_id());
        c->set_value(((TObjPlayer *)pl)->get_item_index());
        d->set_value(((TWindowSubStatusDisp *)pl)->get_field_2F8());
        e->set_value(((TWindowSubStatusDisp *)pl)->get_item_type());
        if (displayed_item_data != 0) {
            if (is_item_already_equipped() != 0) {
                preview_unequip_stats__10TObjPlayerFv(pl, &st, displayed_item_id);
            } else {
                preview_equip_stats__10TObjPlayerFv((u8 *)pl, (s16 *)&st, (u8 *)displayed_item_data);
            }
            a->set_compare_value(st.atp);
            b->set_compare_value(st.dfp);
            c->set_compare_value(st.mst);
            d->set_compare_value(st.evp);
            e->set_compare_value(st.ata);
        }
    }
}

void TWindowHelpItem::update_stat_disp() {
    s32 requirement;
    saddr a;
    saddr b;
    saddr c;
    saddr d;
    saddr e;
    saddr player;

    player = (saddr)get_player_by_client_id(this->client_index);
    if (player != 0) {
        a = reinterpret_cast<saddr>(this->get_array_entry(0));
        b = reinterpret_cast<saddr>(this->get_array_entry(1));
        c = reinterpret_cast<saddr>(this->get_array_entry(2));
        d = reinterpret_cast<saddr>(this->get_array_entry(3));
        e = reinterpret_cast<saddr>(this->get_array_entry(4));
        if (this->displayed_item_data != 0) {
            if (check_equip_requirements((void *)player, (TItemData *)this->displayed_item_data, &requirement) != 0) {
                TWindowHelpItem::set_flag_0x10((u16 *)a, 1);
                TWindowHelpItem::set_flag_0x10((u16 *)b, 1);
                TWindowHelpItem::set_flag_0x10((u16 *)c, 1);
                TWindowHelpItem::set_flag_0x10((u16 *)d, 1);
                TWindowHelpItem::set_flag_0x10((u16 *)e, 1);
                return;
            }
            TWindowHelpItem::set_flag_0x10((u16 *)a, 0);
            TWindowHelpItem::set_flag_0x10((u16 *)b, 0);
            TWindowHelpItem::set_flag_0x10((u16 *)c, 0);
            TWindowHelpItem::set_flag_0x10((u16 *)d, 0);
            TWindowHelpItem::set_flag_0x10((u16 *)e, 0);
        }
    }
}
}
