#include "pso/system/TLanguage.h"
#include "pso/player/PlayerStats.h"
#include "pso/weapon/TItemWeapon.h"
#include "types.h"
#include <stddef.h>
#include "pso/item/MagStats.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemData.h"
#include "pso/item/armor/TItemProArmor.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/PlayerRequirementStats.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/PlayerStats.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/ui/font/TFontSmallHelp.h"
#include "pso/ui/Language.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/window/PageIndicator.h"
#include "pso/ui/window/ListPageIndicator.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/HelpItemStatCompareRow.h"
#include "pso/ui/window/HelpItemRarityStarRow.h"
#include "pso/unk/TWindowLayoutNumber.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/unk/TWindowStatusGaugeFeedback.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/enemy/BattleParamTables.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/item/item_create.h"
#include "pso/ui/window/HelpWindowToggle.h"
#include "pso/enemy/dimedian/TObjEneDimedian.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/weapon/TItemWeapon.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

saddr format_item_description(u8 *item);

const char *TWindowHelpItem::class_name = "TWindowHelpItem";

HelpItemLayout TWindowHelpItem::item_layout_entries = {
    12, 1,
    {{11, {0.0f, 0.0f}}, {11, {0.0f, 20.0f}}, {11, {0.0f, 40.0f}},
     {11, {0.0f, 60.0f}}, {11, {0.0f, 80.0f}}, {11, {0.0f, 100.0f}}},
    {6, {0.0f, 123.0f}, {127.0f, 20.0f}, 0.0f, 132.0f, 0.5f, -1, &localized_alphabet_list, 1, 4},
    {3, {103.0f, 124.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {151.0f, 124.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {151.0f, 124.0f}, 0.5f, 0xFFFFFFFF, 0, "("},
    {4, {208.0f, 124.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {208.0f, 124.0f}, 0.5f, 0xFFFFFFFF, 0, ")"},
};
HelpItemLinesLayout help_item_lines_layout = {
    5, 1,
    {{11, {0.0f, 0.0f}}, {11, {0.0f, 20.0f}}, {11, {0.0f, 40.0f}},
     {11, {0.0f, 60.0f}}, {11, {0.0f, 80.0f}}},
};
HelpItemResistanceLayout TWindowHelpItem::resistance_layout_entries = {
    7, 1,
    {{11, {0.0f, 0.0f}}, {11, {0.0f, 20.0f}}, {11, {0.0f, 40.0f}},
     {11, {0.0f, 60.0f}}, {11, {0.0f, 80.0f}}},
    {3, {55.0f, 123.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {4, {211.0f, 123.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
};
HelpItemStatsLayout help_item_stats_layout = {
    16, 1,
    {{11, {0.0f, 0.0f}}, {11, {0.0f, 20.0f}}, {11, {0.0f, 40.0f}}},
    {
        {{3, {0.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, "DEF"},
         {4, {86.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
         {{2, {98.0f, 65.0f}, 0.5f, 0xFF0034FF, 0x18, 100.0f, 100.0f, 0.0f}, 0xFF00CA9E, 0xFFFF2924}},
        {{3, {0.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, "POW"},
         {4, {86.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
         {{2, {98.0f, 85.0f}, 0.5f, 0xFFE1000D, 0x18, 100.0f, 100.0f, 0.0f}, 0xFF00CA9E, 0xFFFF2924}},
        {{3, {0.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, "DEX"},
         {4, {86.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
         {{2, {98.0f, 105.0f}, 0.5f, 0xFFFFE000, 0x18, 100.0f, 100.0f, 0.0f}, 0xFF00CA9E, 0xFFFF2924}},
        {{3, {0.0f, 120.0f}, 0.5f, 0xFFFFFFFF, 0, "MIND"},
         {4, {86.0f, 120.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
         {{2, {98.0f, 125.0f}, 0.5f, 0xFF00FF14, 0x18, 100.0f, 100.0f, 0.0f}, 0xFF00CA9E, 0xFFFF2924}},
    },
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFF00, 0, "Level Up!"},
};
HelpItemSpritesLayout help_item_sprites_layout = {
    4, 1,
    {
        {6, {35.0f, 18.0f}, {150.0f, 107.0f}, 0.0f, 0.0f, 0.6f, -1, &hud_texlist, 2, 4},
        {6, {85.0f, 50.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.7f, -1, &hud_texlist, 4, 4},
        {6, {129.0f, 24.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.7f, -1, &hud_texlist, 4, 4},
        {6, {41.0f, 76.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.7f, -1, &hud_texlist, 4, 4},
    },
};
HelpItemTextLayout window_help_item_layout_entries = {
    2, 1,
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {10, {0.0f, 128.0f}},
};
HelpItemTechDiskLayout help_item_tech_disk_window_layout_table = {
    7, 1,
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {6, {0.0f, 123.0f}, {127.0f, 20.0f}, 0.0f, 132.0f, 0.5f, -1, &localized_alphabet_list, 1, 4},
    {3, {103.0f, 124.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {151.0f, 124.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {151.0f, 124.0f}, 0.5f, 0xFFFFFFFF, 0, "("},
    {4, {208.0f, 124.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {208.0f, 124.0f}, 0.5f, 0xFFFFFFFF, 0, ")"},
};
HelpItemDescriptionLayout TWindowHelpItem::description_text_layout = {
    1, 1,
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
};
WindowDescriptor window_help_item_layout = {
    {228.0f, 184.0f}, 38900.0f, NULL, 3,
};

void TWindowHelpItem::unlock_page_flip() {
    u8 flags;
    flags = this->help_flags;
    if (flags & 2) {
        this->help_flags = (u8) (flags & 0xFFFFFFFB);
    }
}

void TWindowHelpItem::lock_page_flip() { this->help_flags |= 0x4; }

s16 TObjPlayer::get_dfp() { return dfp; }

s16 TObjPlayer::get_efr() { return element_resist[0]; }

s16 TObjPlayer::get_edk() { return element_resist[3]; }

s16 TObjPlayer::get_elt() { return element_resist[4]; }

void HelpItemStatCompareRow::set_flag0_bit20() { flags |= 0x20; }

s32 HelpItemStatCompareRow::get_value() { return value; }

const char *get_help_text_string(s32 id) {
    return text_language_group_table[6][id];
}

TWindowHelpItem::TWindowHelpItem(const NJS_POINT2 *pos, s32 idx) : TWindowBase((u8 *)&window_help_item_layout, (s16)idx, (u8 *)pos) {
    this->m_name = class_name;
    copy_vec2(target_position, (void *)pos);
    this->save_position();
    this->help_flags = 0;
    page_indicator = new PageIndicator(0, 3, client_index);
    active_item = NULL;
    this->secondary_item = 0;
    this->primary_item = 0;
    this->active_id = -1;
    this->secondary_id = -1;
    this->primary_id = -1;
    this->m_callback = NULL;
    this->scale_x = 1.0f;
    this->scale_y = 1.0f;
    this->dispatch_item_help();
    call_if_split_screen(this, this->client_index);
}

TWindowHelpItem::~TWindowHelpItem() {
    delete_if_allocated(this->page_indicator, 1);
}

void TWindowHelpItem::run_task() {
    if (!(this->window_flags & 2)) {
        this->open_tick = 0x01000000;
    }
    if ((this->help_flags & 1) && (this->is_open_and_unblocked() != 0) && !(this->window_flags & 4)) {
        if (!(this->help_flags & 4)) {
            if (handle_list_page_flip_input(this->page_indicator) != 0) {
                this->dispatch_item_help();
            }
        } else {
            decay_page_arrow_offset(this->page_indicator);
        }
        this->invoke_callback_pmf();
    }
    update_window();
    this->update_fade();
    this->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
    if (!(this->help_flags & 8)) {
        toggle_help_window_on_button(this, this->client_index);
    }
}

void TWindowHelpItem::render() {
    WindowDrawContext *context;
    u8 flags;

    context = this->setup_window_draw_context(&scale_x);
    this->draw_window_frame(context);
    draw_visible_window_entries(
        this,
        &entry_list,
        context);
    flags = this->help_flags;
    if ((flags & 1) && (flags & 2)) {
        draw_list_page_indicator(page_indicator, context);
    }
}

void TWindowHelpItem::update_cursor_selection() {
    this->help_flags = (u8) (this->help_flags | 1);
    if ((s32) this->primary_id != -1) {
        active_item = primary_item;
        this->active_id = (s32) this->primary_id;
        return;
    }
    if ((s32) this->secondary_id != -1) {
        active_item = secondary_item;
        this->active_id = (s32) this->secondary_id;
        return;
    }
    this->help_flags = (u8) (this->help_flags & 0xFE);
    active_item = NULL;
    this->active_id = -1;
}

void TWindowHelpItem::clear_help_item() {
    entry_list.destroy_all_items();
    help_flags &= ~1;
    active_item = NULL;
    secondary_item = 0;
    primary_item = 0;
    active_id = -1;
    secondary_id = -1;
    primary_id = -1;
    m_callback = NULL;
}

void TWindowHelpItem::update_help_item(s8 page) { if (set_list_page(page_indicator, page) != 0) { this->dispatch_item_help(); } }

void TWindowHelpItem::set_items_and_refresh(TItemData *item, s32 id) { this->secondary_id = id; this->secondary_item = item; update_cursor_selection(); dispatch_item_help(); }

void TWindowHelpItem::set_displayed_item_data(TItemData *item, s32 id) { this->primary_id = id; this->primary_item = item; update_cursor_selection(); dispatch_item_help(); }

void TWindowHelpItem::set_displayed_item_colored(TItemData *item) {
    saddr id;
    id = -0x100;
    if (item == NULL) {
        id = -1;
    }
    set_displayed_item_data(item, id);
}

void TWindowHelpItem::show_item_by_id(saddr id) {
    TItem *item;
    if (id == -1) {
        set_items_and_refresh(NULL, -1);
        return;
    }
    item = find_item_by_id(id);
    if (item == NULL) {
        set_items_and_refresh(NULL, id);
        return;
    }
    item->copy_to_item_data(&item_copy);
    set_items_and_refresh(&item_copy, id);
}

void TWindowHelpItem::set_displayed_item_by_id(saddr id) {
    TItem *item;
    if (id == -1) {
        set_displayed_item_data(NULL, -1);
        return;
    }
    item = find_item_by_id(id);
    if (item == NULL) {
        set_displayed_item_data(NULL, id);
        return;
    }
    item->copy_to_item_data(&displayed_item);
    set_displayed_item_data(&displayed_item, id);
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
    if (active_id == -1) {
        help_flags &= 0xF8;
        m_callback = NULL;
        return;
    }
    page = page_indicator->get_type();
    help_flags |= 2;
    unlock_page_flip();
    if (active_item == NULL) {
        if ((s32)primary_id == -0xFF) {
            help_flags &= ~2;
            lock_page_flip();
            init_text(TWindowSubStatusDisp::get_message_10(0x10D));
        } else {
            help_flags &= ~2;
            lock_page_flip();
            init_text((void *)(get_localized_text_entry(0x10, ((s32)primary_id & 0xF) + 0x18)));
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
    WeaponParams *pmt;
    s32 flags;
    WindowSpritePart *a;
    WindowTextEntry *b;
    TWindowLayoutNumber *c;
    WindowTextEntry *d;
    TWindowLayoutNumber *e;
    WindowTextEntry *f;

    pl = get_player_by_client_id(client_index);
    if (pl != NULL) {
        init_help_texts();
        m_callback = &TWindowHelpItem::update_requirements;
        a = (WindowSpritePart *)get_array_entry(6);
        b = (WindowTextEntry *)get_array_entry(7);
        c = (TWindowLayoutNumber *)get_array_entry(8);
        d = (WindowTextEntry *)get_array_entry(9);
        e = (TWindowLayoutNumber *)get_array_entry(10);
        f = (WindowTextEntry *)get_array_entry(11);
        pmt = (WeaponParams *)lookup_item_pmt_record((u8 *)active_item);
        if (check_equip_requirements(pl, active_item, &flags) == 0 && (flags & 1)) {
            a->set_sprite_uv_from_pixels(0.0f, 132.0f);
            b->hide();
            c->hide();
            d->hide();
            e->hide();
            f->hide();
            return;
        }
        if (pmt->atp_required != 0) {
            a->set_sprite_uv_from_pixels(0.0f, 172.0f);
            b->reveal_all();
            d->reveal_all();
            f->reveal_all();
            c->value = pmt->atp_required;
            return;
        }
        if (pmt->mst_required != 0) {
            a->set_sprite_uv_from_pixels(0.0f, 192.0f);
            b->reveal_all();
            d->reveal_all();
            f->reveal_all();
            c->value = pmt->mst_required;
            return;
        }
        if (pmt->ata_required != 0) {
            a->set_sprite_uv_from_pixels(0.0f, 212.0f);
            b->reveal_all();
            d->reveal_all();
            f->reveal_all();
            c->value = pmt->ata_required;
            return;
        }
        a->hide();
        b->hide();
        c->hide();
        d->hide();
        e->hide();
        f->hide();
    }
}

void TWindowHelpItem::show_armor_requirements() {
    TObjPlayer *pl;
    u8 *item;
    s32 flags;
    WindowSpritePart *a;
    WindowTextEntry *b;
    TWindowLayoutNumber *c;
    WindowTextEntry *d;
    TWindowLayoutNumber *e;
    WindowTextEntry *f;

    pl = get_player_by_client_id(client_index);
    if (pl != NULL) {
        init_help_texts();
        m_callback = &TWindowHelpItem::update_level_requirement;
        a = (WindowSpritePart *)get_array_entry(6);
        b = (WindowTextEntry *)get_array_entry(7);
        c = (TWindowLayoutNumber *)get_array_entry(8);
        d = (WindowTextEntry *)get_array_entry(9);
        e = (TWindowLayoutNumber *)get_array_entry(10);
        f = (WindowTextEntry *)get_array_entry(11);
        item = (u8 *)lookup_item_pmt_record((u8 *)active_item);
        if (check_equip_requirements(pl, active_item, &flags) == 0 && (flags & 1)) {
            a->set_sprite_uv_from_pixels(0.0f, 132.0f);
            b->hide();
            c->hide();
            d->hide();
            e->hide();
            f->hide();
            return;
        }
        if (item[0x10] != 0) {
            a->set_sprite_uv_from_pixels(0.0f, 232.0f);
            b->reveal_all();
            d->reveal_all();
            f->reveal_all();
            c->value = item[0x10] + 1;
            return;
        }
        a->hide();
        b->hide();
        c->hide();
        d->hide();
        e->hide();
        f->hide();
    }
}

void TWindowHelpItem::show_mag_stats() {
    WindowSpritePart *a;
    WindowTextEntry *b;
    TWindowLayoutNumber *c;
    WindowTextEntry *d;
    TWindowLayoutNumber *e;
    WindowTextEntry *f;
    init_help_texts();
    m_callback = &TWindowHelpItem::update_stat_comparison;
    a = (WindowSpritePart *)get_array_entry(6);
    b = (WindowTextEntry *)get_array_entry(7);
    c = (TWindowLayoutNumber *)get_array_entry(8);
    d = (WindowTextEntry *)get_array_entry(9);
    e = (TWindowLayoutNumber *)get_array_entry(10);
    f = (WindowTextEntry *)get_array_entry(11);
    a->hide();
    b->hide();
    c->hide();
    d->hide();
    e->hide();
    f->hide();
}

void TWindowHelpItem::init_help_texts() {
    HelpItemStatCompareRow *atp_row;
    HelpItemStatCompareRow *dfp_row;
    HelpItemStatCompareRow *mst_row;
    HelpItemStatCompareRow *ata_row;
    HelpItemStatCompareRow *evp_row;
    HelpItemStatCompareRow *lck_row;

    init_window_layout_entries(
        &entry_list,
        &TWindowHelpItem::item_layout_entries,
        this->client_index);
    atp_row = (HelpItemStatCompareRow *)(this->get_array_entry(0));
    dfp_row = (HelpItemStatCompareRow *)(this->get_array_entry(1));
    mst_row = (HelpItemStatCompareRow *)(this->get_array_entry(2));
    ata_row = (HelpItemStatCompareRow *)(this->get_array_entry(3));
    evp_row = (HelpItemStatCompareRow *)(this->get_array_entry(4));
    lck_row = (HelpItemStatCompareRow *)(this->get_array_entry(5));
    atp_row->set_help_text((saddr) (TWindowSubStatusDisp::get_message_10(0x83)));
    dfp_row->set_help_text((saddr) (TWindowSubStatusDisp::get_message_10(0x84)));
    mst_row->set_help_text((saddr) (TWindowSubStatusDisp::get_message_10(0x85)));
    ata_row->set_help_text((saddr) (TWindowSubStatusDisp::get_message_10(0x86)));
    evp_row->set_help_text((saddr) (TWindowSubStatusDisp::get_message_10(0x87)));
    lck_row->set_help_text((saddr) (TWindowSubStatusDisp::get_message_10(0x88)));
}

void TWindowHelpItem::update_requirements() {
    s32 flags;
    PlayerRequirementStats st;
    TObjPlayer *pl;
    TWindowLayoutNumber *entry;
    WeaponParams *pmt;
    st.clear_fields();
    pl = get_player_by_client_id(client_index);
    if (pl == NULL) {
        return;
    }
    update_stat_comparison();
    entry = (TWindowLayoutNumber *)get_array_entry(10);
    pmt = (WeaponParams *)lookup_item_pmt_record((u8 *)active_item);
    if (check_equip_requirements(pl, active_item, &flags) == 0 && (flags & 1)) {
        return;
    }
    if (pmt->atp_required != 0) {
        if (build_player_equipment_requirement_stats(pl, &st) != 0) {
            entry->value = st.atp;
        }
    } else if (pmt->mst_required != 0) {
        if (build_player_equipment_requirement_stats(pl, &st) != 0) {
            entry->value = st.mst;
        }
    } else if (pmt->ata_required != 0) {
        if (build_player_equipment_requirement_stats(pl, &st) != 0) {
            entry->value = st.ata;
        }
    }
}

void TWindowHelpItem::update_level_requirement() {
    s32 requirement;
    TWindowLayoutNumber *level_value;
    ArmorPmtEntry *item_pmt_record;
    TObjPlayer *player;
    player = get_player_by_client_id(client_index);
    if (player != NULL) {
        if (player->get_stats() != 0U) {
            update_stat_comparison();
            level_value = (TWindowLayoutNumber *)get_array_entry(0xA);
            item_pmt_record = (ArmorPmtEntry *)lookup_item_pmt_record((u8 *)active_item);
            if (check_equip_requirements(player, active_item, &requirement) == 0) {
                if (!(requirement & 1)) {
                    goto block_4;
                }
            } else {
block_4:
                if (item_pmt_record->required_level != 0) {
                    level_value->value = (s32) (player->get_actor_level_index() + 1);
                }
            }
        }
    }
}

void TWindowHelpItem::update_stat_comparison() {
    s32 flags;
    PlayerRequirementStats st;
    HelpItemStatCompareRow *e0;
    HelpItemStatCompareRow *e3;
    HelpItemStatCompareRow *e1;
    HelpItemStatCompareRow *e4;
    HelpItemStatCompareRow *e2;
    HelpItemStatCompareRow *e5;
    player_stats *q;
    TObjPlayer *pl;
    st.clear_fields();
    pl = get_player_by_client_id(client_index);
    if (pl == NULL) {
        return;
    }
    q = pl->get_stats();
    if (q == NULL) {
        return;
    }
    e0 = (HelpItemStatCompareRow *)get_array_entry(0);
    e3 = (HelpItemStatCompareRow *)get_array_entry(3);
    e1 = (HelpItemStatCompareRow *)get_array_entry(1);
    e4 = (HelpItemStatCompareRow *)get_array_entry(4);
    e2 = (HelpItemStatCompareRow *)get_array_entry(2);
    e5 = (HelpItemStatCompareRow *)get_array_entry(5);
    e0->set_value(pl->get_atp() + pl->get_actor_attack_params_atp_min() + pl->get_atp_range());
    e3->set_value(pl->get_ata());
    e1->set_value(pl->get_dfp());
    e4->set_value(pl->get_evp());
    e2->set_value(q->stats.mst);
    e5->set_value(q->stats.lck);
    if (primary_item == 0) {
        return;
    }
    if (is_item_already_equipped() != 0) {
        pl->preview_unequip_stats(&st, primary_id);
    } else {
        pl->preview_equip_stats(&st, (u8 *)primary_item);
    }
    e0->set_compare_value(st.atp);
    e3->set_compare_value(st.ata);
    e1->set_compare_value(st.dfp);
    e4->set_compare_value(st.evp);
    e2->set_compare_value(st.mst);
    e5->set_compare_value(st.lck);
    if (check_equip_requirements(pl, primary_item, &flags) != 0) {
        e0->set_compare_enabled(1);
        e3->set_compare_enabled(1);
        e1->set_compare_enabled(1);
        e4->set_compare_enabled(1);
        e2->set_compare_enabled(1);
        e5->set_compare_enabled(1);
    } else {
        e0->set_compare_enabled(0);
        e3->set_compare_enabled(0);
        e1->set_compare_enabled(0);
        e4->set_compare_enabled(0);
        e2->set_compare_enabled(0);
        e5->set_compare_enabled(0);
    }
}

void TWindowHelpItem::show_weapon_attributes() {
    TObjPlayer *player;
    HelpItemStatCompareRow *a;
    HelpItemStatCompareRow *b;
    HelpItemStatCompareRow *c;
    HelpItemStatCompareRow *d;
    HelpItemStatCompareRow *e;

    player = get_player_by_client_id(client_index);
    if (player != 0) {
        init_window_layout_entries(
            &entry_list,
            &help_item_lines_layout,
            client_index);
        m_callback = &TWindowHelpItem::update_stat_disp2;
        a = (HelpItemStatCompareRow *)(get_array_entry(0));
        b = (HelpItemStatCompareRow *)(get_array_entry(1));
        c = (HelpItemStatCompareRow *)(get_array_entry(2));
        d = (HelpItemStatCompareRow *)(get_array_entry(3));
        e = (HelpItemStatCompareRow *)(get_array_entry(4));
        a->set_help_text((saddr)native_attribute_label);
        b->set_help_text((saddr)abeast_attribute_label);
        c->set_help_text((saddr)machine_attribute_label);
        d->set_help_text((saddr)dark_attribute_label);
        e->set_help_text((saddr)"Hit");
        a->set_flag0_bit20();
        b->set_flag0_bit20();
        c->set_flag0_bit20();
        d->set_flag0_bit20();
        e->set_flag0_bit20();
        set_percentage_rows(player->get_attribute_entry(0), &HelpItemStatCompareRow::set_value);
        if (primary_item != 0) {
            if (is_item_already_equipped() != 0) {
                set_percentage_rows(NULL, &HelpItemStatCompareRow::set_compare_value);
            } else {
                set_percentage_rows((WeaponAttribute *)&primary_item->data1.data_u8[6], &HelpItemStatCompareRow::set_compare_value);
            }
            e->update_visible_flags();
        }
    }
}

void TWindowHelpItem::update_stat_disp2() {
    s32 requirement;
    HelpItemStatCompareRow *native_row;
    HelpItemStatCompareRow *abeast_row;
    HelpItemStatCompareRow *machine_row;
    HelpItemStatCompareRow *dark_row;
    HelpItemStatCompareRow *hit_row;
    TObjPlayer *player;
    TItemData *item;
    player = get_player_by_client_id(client_index);
    if ((player != 0) && (native_row = (HelpItemStatCompareRow *)get_array_entry(0), abeast_row = (HelpItemStatCompareRow *)get_array_entry(1), machine_row = (HelpItemStatCompareRow *)get_array_entry(2), dark_row = (HelpItemStatCompareRow *)get_array_entry(3), hit_row = (HelpItemStatCompareRow *)get_array_entry(4), (item = primary_item, (item == NULL) == 0))) {
        if (check_equip_requirements(player, item, &requirement) != 0) {
            native_row->set_compare_enabled(1);
            abeast_row->set_compare_enabled(1);
            machine_row->set_compare_enabled(1);
            dark_row->set_compare_enabled(1);
            hit_row->set_compare_enabled(1);
            return;
        }
        native_row->set_compare_enabled(0);
        abeast_row->set_compare_enabled(0);
        machine_row->set_compare_enabled(0);
        dark_row->set_compare_enabled(0);
        hit_row->set_compare_enabled(0);
    }
}

void TWindowHelpItem::set_percentage_rows(WeaponAttribute *attributes, void (HelpItemStatCompareRow::*set)(s32)) {
    u32 i;
    HelpItemStatCompareRow *e0;
    HelpItemStatCompareRow *e1;
    HelpItemStatCompareRow *e2;
    HelpItemStatCompareRow *e3;
    HelpItemStatCompareRow *e4;

    e0 = (HelpItemStatCompareRow *)get_array_entry(0);
    e1 = (HelpItemStatCompareRow *)get_array_entry(1);
    e2 = (HelpItemStatCompareRow *)get_array_entry(2);
    e3 = (HelpItemStatCompareRow *)get_array_entry(3);
    e4 = (HelpItemStatCompareRow *)get_array_entry(4);
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
    WindowTextEntry *label;
    TWindowLayoutNumber *value_entry;
    update_resistance_rows();
    label = (WindowTextEntry *)get_array_entry(5);
    value_entry = (TWindowLayoutNumber *)get_array_entry(6);
    TWindowDuelResult::set_default_status(label, (saddr)TWindowSubStatusDisp::get_message_10(0xA1));
    label->reveal_all();
    value_entry->value = active_item->data1.data_u8[5];
}

void TWindowHelpItem::show_shield_resistances() {
    WindowTextEntry *label;
    TWindowLayoutNumber *value_entry;
    update_resistance_rows();
    label = (WindowTextEntry *)get_array_entry(5);
    value_entry = (TWindowLayoutNumber *)get_array_entry(6);
    label->hide();
    value_entry->hide();
}

void TWindowHelpItem::update_resistance_rows() {
    PlayerRequirementStats st;
    HelpItemStatCompareRow *a;
    HelpItemStatCompareRow *b;
    HelpItemStatCompareRow *c;
    HelpItemStatCompareRow *d;
    HelpItemStatCompareRow *e;
    TObjPlayer *pl;
    st.clear_fields();
    pl = get_player_by_client_id(client_index);
    if (pl != NULL) {
        init_window_layout_entries(
            &entry_list,
            &TWindowHelpItem::resistance_layout_entries,
            client_index);
        m_callback = &TWindowHelpItem::update_stat_disp;
        a = (HelpItemStatCompareRow *)(get_array_entry(0));
        b = (HelpItemStatCompareRow *)(get_array_entry(1));
        c = (HelpItemStatCompareRow *)(get_array_entry(2));
        d = (HelpItemStatCompareRow *)(get_array_entry(3));
        e = (HelpItemStatCompareRow *)(get_array_entry(4));
        a->set_help_text((uaddr)TWindowSubStatusDisp::get_message_10(0x89));
        b->set_help_text((uaddr)TWindowSubStatusDisp::get_message_10(0x8A));
        c->set_help_text((uaddr)TWindowSubStatusDisp::get_message_10(0x8B));
        d->set_help_text((uaddr)TWindowSubStatusDisp::get_message_10(0x8C));
        e->set_help_text((uaddr)TWindowSubStatusDisp::get_message_10(0x8D));
        a->set_value(pl->get_efr());
        b->set_value(pl->get_eic());
        c->set_value(pl->get_eth());
        d->set_value(pl->get_edk());
        e->set_value(pl->get_elt());
        if (primary_item != 0) {
            if (is_item_already_equipped() != 0) {
                pl->preview_unequip_stats(&st, primary_id);
            } else {
                pl->preview_equip_stats(&st, (u8 *)primary_item);
            }
            a->set_compare_value(st.resist[0]);
            b->set_compare_value(st.resist[1]);
            c->set_compare_value(st.resist[2]);
            d->set_compare_value(st.resist[4]);
            e->set_compare_value(st.resist[3]);
        }
    }
}

void TWindowHelpItem::update_stat_disp() {
    s32 requirement;
    HelpItemStatCompareRow *a;
    HelpItemStatCompareRow *b;
    HelpItemStatCompareRow *c;
    HelpItemStatCompareRow *d;
    HelpItemStatCompareRow *e;
    TObjPlayer *player;

    player = get_player_by_client_id(this->client_index);
    if (player != 0) {
        a = (HelpItemStatCompareRow *)this->get_array_entry(0);
        b = (HelpItemStatCompareRow *)this->get_array_entry(1);
        c = (HelpItemStatCompareRow *)this->get_array_entry(2);
        d = (HelpItemStatCompareRow *)this->get_array_entry(3);
        e = (HelpItemStatCompareRow *)this->get_array_entry(4);
        if (this->primary_item != 0) {
            if (check_equip_requirements(player, this->primary_item, &requirement) != 0) {
                a->set_compare_enabled(1);
                b->set_compare_enabled(1);
                c->set_compare_enabled(1);
                d->set_compare_enabled(1);
                e->set_compare_enabled(1);
                return;
            }
            a->set_compare_enabled(0);
            b->set_compare_enabled(0);
            c->set_compare_enabled(0);
            d->set_compare_enabled(0);
            e->set_compare_enabled(0);
        }
    }
}

#pragma push
#pragma fp_contract on
void TWindowHelpItem::show_mag_growth() {
    MagStats mag;
    WindowTextEntry *a;
    TWindowLayoutNumber *b;
    TWindowStatusGaugeFeedback *c;
    HelpItemStatCompareRow *lv;
    HelpItemStatCompareRow *sy;
    HelpItemStatCompareRow *iq;
    WindowTextEntry *up;
    mag.init();
    init_window_layout_entries(
        &entry_list,
        &help_item_stats_layout,
        client_index);
    m_callback = &TWindowHelpItem::idle_update;
    TItemData::deserialize_mag(active_item, &mag);
    lv = (HelpItemStatCompareRow *)get_array_entry(0);
    sy = (HelpItemStatCompareRow *)get_array_entry(1);
    iq = (HelpItemStatCompareRow *)get_array_entry(2);
    up = (WindowTextEntry *)get_array_entry(0xF);
    lv->set_help_text((uaddr)TWindowSubStatusDisp::get_message_10(0xA2));
    sy->set_help_text((uaddr)TWindowSubStatusDisp::get_message_10(0xA3));
    iq->set_help_text((uaddr)TWindowSubStatusDisp::get_message_10(0xA4));
    sy->set_flag0_bit20();
    lv->set_value(mag.get_level());
    sy->set_value(mag.get_synchro());
    iq->set_value(mag.get_iq());
    measure_message_text_width_default(up);
    up->x = 110.0f - 0.5f * up->width;
    up->hide();
    a = (WindowTextEntry *)get_array_entry(3);
    b = (TWindowLayoutNumber *)get_array_entry(4);
    c = (TWindowStatusGaugeFeedback *)get_array_entry(5);
    a->reveal_all();
    b->value = mag.get_def_level();
    c->target = (f32) mag.get_def_progress();
    c->calc_bar_width();
    a = (WindowTextEntry *)get_array_entry(6);
    b = (TWindowLayoutNumber *)get_array_entry(7);
    c = (TWindowStatusGaugeFeedback *)get_array_entry(8);
    a->reveal_all();
    b->value = mag.get_pow_level();
    c->target = (f32) mag.get_pow_progress();
    c->calc_bar_width();
    a = (WindowTextEntry *)get_array_entry(9);
    b = (TWindowLayoutNumber *)get_array_entry(0xA);
    c = (TWindowStatusGaugeFeedback *)get_array_entry(0xB);
    a->reveal_all();
    b->value = mag.get_dex_level();
    c->target = (f32) mag.get_dex_progress();
    c->calc_bar_width();
    a = (WindowTextEntry *)get_array_entry(0xC);
    b = (TWindowLayoutNumber *)get_array_entry(0xD);
    c = (TWindowStatusGaugeFeedback *)get_array_entry(0xE);
    a->reveal_all();
    b->value = mag.get_mind_level();
    c->target = (f32) mag.get_mind_progress();
    c->calc_bar_width();
}
#pragma pop

s32 TWindowHelpItem::update_mag_status_gauges() {
    MagStats mag;
    TWindowLayoutEntry *panel;
    HelpItemStatCompareRow *synchro;
    HelpItemStatCompareRow *iq;
    TWindowLayoutEntry *growth;
    TWindowLayoutNumber *level;
    TWindowStatusGaugeFeedback *gauge;
    s32 changed;
    mag.init();
    changed = 0;
    TItemData::deserialize_mag(active_item, &mag);
    panel = (TWindowLayoutEntry *)get_array_entry(0);
    synchro = (HelpItemStatCompareRow *)get_array_entry(1);
    iq = (HelpItemStatCompareRow *)get_array_entry(2);
    growth = (TWindowLayoutEntry *)get_array_entry(0xF);
    panel->show();
    growth->hide();
    synchro->set_compare_color((s32) mag.get_synchro());
    iq->set_compare_color((s32) mag.get_iq());
    level = (TWindowLayoutNumber *)get_array_entry(4);
    gauge = (TWindowStatusGaugeFeedback *)get_array_entry(5);
    if (level->value < mag.get_def_level()) {
        changed = 1;
        gauge->target = 100.0f;
    } else {
        if (gauge->target != (f32) mag.get_def_progress()) {
            changed = 1;
        }
        gauge->target = (f32) mag.get_def_progress();
    }
    level = (TWindowLayoutNumber *)get_array_entry(7);
    gauge = (TWindowStatusGaugeFeedback *)get_array_entry(8);
    if (level->value < mag.get_pow_level()) {
        changed = 1;
        gauge->target = 100.0f;
    } else {
        if (gauge->target != (f32) mag.get_pow_progress()) {
            changed = 1;
        }
        gauge->target = (f32) mag.get_pow_progress();
    }
    level = (TWindowLayoutNumber *)get_array_entry(0xA);
    gauge = (TWindowStatusGaugeFeedback *)get_array_entry(0xB);
    if (level->value < mag.get_dex_level()) {
        changed = 1;
        gauge->target = 100.0f;
    } else {
        if (gauge->target != (f32) mag.get_dex_progress()) {
            changed = 1;
        }
        gauge->target = (f32) mag.get_dex_progress();
    }
    level = (TWindowLayoutNumber *)get_array_entry(0xD);
    gauge = (TWindowStatusGaugeFeedback *)get_array_entry(0xE);
    if (level->value < mag.get_mind_level()) {
        changed = 1;
        gauge->target = 100.0f;
    } else {
        if (gauge->target != (f32) mag.get_mind_progress()) {
            changed = 1;
        }
        gauge->target = (f32) mag.get_mind_progress();
    }
    return changed;
}

// Steps each shown mag level one towards the mag's own level; 1 while any still moves.
s32 TWindowHelpItem::advance_mag_levels() {
    MagStats mag;
    HelpItemStatCompareRow *level_row;
    TWindowLayoutEntry *panel;
    TWindowStatusGaugeFeedback *bar;
    TWindowLayoutNumber *num;
    s32 count;
    mag.init();
    TItemData::deserialize_mag(active_item, &mag);
    level_row = (HelpItemStatCompareRow *)get_array_entry(0);
    panel = (TWindowLayoutEntry *)get_array_entry(0xF);
    count = level_row->get_value();
    num = (TWindowLayoutNumber *)get_array_entry(4);
    bar = (TWindowStatusGaugeFeedback *)get_array_entry(5);
    if (num->value < mag.get_def_level()) {
        num->value++;
        bar->target = 0.0f;
        count++;
        bar->calc_bar_width();
    }
    num = (TWindowLayoutNumber *)get_array_entry(7);
    bar = (TWindowStatusGaugeFeedback *)get_array_entry(8);
    if (num->value < mag.get_pow_level()) {
        num->value++;
        count++;
        bar->target = 0.0f;
        bar->calc_bar_width();
    }
    num = (TWindowLayoutNumber *)get_array_entry(0xA);
    bar = (TWindowStatusGaugeFeedback *)get_array_entry(0xB);
    if (num->value < mag.get_dex_level()) {
        num->value++;
        bar->target = 0.0f;
        count++;
        bar->calc_bar_width();
    }
    num = (TWindowLayoutNumber *)get_array_entry(0xD);
    bar = (TWindowStatusGaugeFeedback *)get_array_entry(0xE);
    if (num->value < mag.get_mind_level()) {
        num->value++;
        bar->target = 0.0f;
        count++;
        bar->calc_bar_width();
    }
    update_mag_status_gauges();
    if (count != level_row->get_value()) {
        level_row->set_value(count);
        level_row->hide();
        panel->show();
        return 1;
    }
    return 0;
}

s32 TWindowHelpItem::are_status_entries_ready() {
    TWindowStatusGaugeFeedback *def_gauge = (TWindowStatusGaugeFeedback *)get_array_entry(5);
    TWindowStatusGaugeFeedback *pow_gauge = (TWindowStatusGaugeFeedback *)get_array_entry(8);
    TWindowStatusGaugeFeedback *dex_gauge = (TWindowStatusGaugeFeedback *)get_array_entry(0xB);
    TWindowStatusGaugeFeedback *mind_gauge = (TWindowStatusGaugeFeedback *)get_array_entry(0xE);
    s32 ready;
    if (!(def_gauge->flags & 4)) {
        ready = 0;
    } else if (!(pow_gauge->flags & 4)) {
        ready = 0;
    } else if (!(dex_gauge->flags & 4)) {
        ready = 0;
    } else {
        ready = (mind_gauge->flags >> 2) & 1;
    }
    return ready;
}

void TWindowHelpItem::refresh_copied_items() {
    s32 id;
    s32 displayed_id;
    u8 *item;
    u8 *displayed;
    id = this->secondary_id;
    if (id != -1) {
        item = (u8 *)(find_item_by_id(id));
        if (item != NULL) {
            ((TItem *)item)->copy_to_item_data(&this->item_copy);
        }
    }
    displayed_id = this->primary_id;
    if (displayed_id != -1) {
        displayed = (u8 *)(find_item_by_id(displayed_id));
        if (displayed != NULL) {
            ((TItem *)displayed)->copy_to_item_data(&this->displayed_item);
        }
    }
}

void TWindowHelpItem::show_mag_photon_blasts() {
    MagStats mag;
    s32 slot;
    s32 blast;
    mag.init();
    init_window_layout_entries(
        &entry_list,
        &help_item_sprites_layout,
        client_index);
    m_callback = &TWindowHelpItem::idle_update;
    TItemData::deserialize_mag(active_item, &mag);
    for (slot = 0; slot < 3; slot++) {
        blast = mag.get_photon_blast(slot);
        if (blast != -1) {
            draw_action_palette_icon((WindowSpritePart *)get_array_entry(slot + 1), 5, blast);
        } else {
            draw_action_palette_icon((WindowSpritePart *)get_array_entry(slot + 1), 0, 0);
        }
    }
}

void TWindowHelpItem::show_item_description() {
    WindowTextEntry *e;
    HelpItemRarityStarRow *e2;
    init_window_layout_entries(
        &this->entry_list,
        &window_help_item_layout_entries,
        this->client_index);
    m_callback = &TWindowHelpItem::idle_update;
    e = (WindowTextEntry *)this->get_array_entry(0);
    this->format_description_with_price();
    set_text_entry_string((e), (uaddr)(get_shared_text_buffer()), 0x20);
    e->reveal_all();
    e2 = (HelpItemRarityStarRow *)this->get_array_entry(1);
    e2->stars = (u8)(active_item)->calc_display_grade();
}

void TWindowHelpItem::update_tech_disk_details() {
    s32 requirement;
    TObjPlayer *player;
    WindowTextEntry *e0;
    WindowSpritePart *e1;
    WindowTextEntry *e2;
    TWindowLayoutNumber *e3;
    WindowTextEntry *e4;
    TWindowLayoutNumber *e5;
    WindowTextEntry *e6;
    player = get_player_by_client_id(this->client_index);
    if (player != 0) {
        init_window_layout_entries(
            &this->entry_list,
            &help_item_tech_disk_window_layout_table,
            this->client_index);
        m_callback = &TWindowHelpItem::update_tech_disk_stats;
        e0 = (WindowTextEntry *)this->get_array_entry(0);
        text_builder_reset();
        text_builder_append((const char *)format_item_description((u8 *)active_item));
        if (current_language == LANGUAGE_JAPANESE) {
            text_builder_append(get_help_text_string(active_item->data1.data_u8[4]));
        }
        set_text_entry_string(e0, (uaddr)((void *)get_shared_text_buffer()), 0x20);
        e0->reveal_all();
        e1 = (WindowSpritePart *)this->get_array_entry(1);
        e2 = (WindowTextEntry *)this->get_array_entry(2);
        e3 = (TWindowLayoutNumber *)this->get_array_entry(3);
        e4 = (WindowTextEntry *)this->get_array_entry(4);
        e5 = (TWindowLayoutNumber *)this->get_array_entry(5);
        e6 = (WindowTextEntry *)this->get_array_entry(6);
        check_equip_requirements(player, active_item, &requirement);
        if (requirement & 1) {
            e1->set_sprite_uv_from_pixels(0.0f, 152.0f);
            e2->hide();
            e3->hide();
            e4->hide();
            e5->hide();
            e6->hide();
            return;
        }
        e1->set_sprite_uv_from_pixels(0.0f, 192.0f);
        e2->reveal_all();
        e4->reveal_all();
        e6->reveal_all();
        e3->value = (active_item)->get_technique_level();
    }
}

// Run each frame on the technique disk page: shows the player's MST unless
// the class cannot learn techniques (class flag 0x10).
void TWindowHelpItem::update_tech_disk_stats() {
    PlayerRequirementStats stats;
    TObjPlayer *player;
    CharacterAppearanceFields *appearance;
    TWindowLayoutNumber *mst_entry;
    stats.clear_fields();
    player = get_player_by_client_id(client_index);
    if (player != NULL) {
        appearance = (CharacterAppearanceFields *)player->name;
        if (appearance != NULL) {
            mst_entry = (TWindowLayoutNumber *)get_array_entry(5);
            if (!(appearance->classFlags & 0x10) && (build_player_equipment_requirement_stats(player, &stats) != 0)) {
                mst_entry->value = stats.mst;
            }
        }
    }
}

void TWindowHelpItem::update_displayed_item() {
    this->format_description_with_price();
    this->init_text((get_shared_text_buffer()));
}

void TWindowHelpItem::init_text(void *str) {
    WindowTextEntry *e;
    init_window_layout_entries(
        &this->entry_list,
        &TWindowHelpItem::description_text_layout,
        this->client_index);
    m_callback = &TWindowHelpItem::idle_update;
    e = (WindowTextEntry *)this->get_array_entry(0);
    set_text_entry_string(e, (uaddr)str, 0x20);
    e->reveal_all();
}

// Run each frame on pages that show nothing that changes.
void TWindowHelpItem::idle_update() {}

void TWindowHelpItem::format_description_with_price() {
    text_builder_reset();
    text_builder_append((const char *)format_item_description(reinterpret_cast<u8 *>(active_item)));
    text_builder_append("\n");
    text_builder_append((const char *)(active_item->calc_buy_price()));
}

s32 TWindowHelpItem::is_item_already_equipped() {
    TItem *item;
    s32 field;
    u32 diff;
    field = this->primary_id;
    if (field == -1) {
        return 0;
    }
    item = find_item_by_id(field);
    if (item == 0) {
        return 0;
    }
    if (item->test_item_flags(8) == 0U) {
        return 0;
    }
    diff = (u32) item->get_owner_client() - (u32) (s32) this->client_index;
    return (s32) ((u32) __cntlzw(diff) >> 5);
}
