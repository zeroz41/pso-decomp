#include "pso/item/MagStats.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "types.h"
#include "pso/ui/window/TWindowHelpItem_802531A0.h"
#include "pso/ui/window/TWindowHelpItem_80255AB4.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"

#include <stddef.h>
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/item/TItemData.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/Language.h"

#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/PlayerRequirementStats.h"
#include "pso/ui/charcreate/CharacterAppearance.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
typedef struct MagData_80253564 { u8 b[16]; } MagData_80253564;

extern "C" {
void draw_action_palette_icon(void *, int, u16);
void text_builder_append();
}
extern u8 lbl_804CF4E4[];
extern void (TWindowHelpItem::*TWindowHelpItem__description_update_callback)();
void set_text_entry_string(u8 *arg0, uaddr str, s32 arg2);
extern u8 window_help_item_layout_entries[];
extern void (TWindowHelpItem::*item_help_description_idle_callback)();
s32 format_item_description(u8 *item);
void text_builder_reset();
extern u8 help_item_tech_disk_window_layout_table[];
extern void (TWindowHelpItem::*item_help_tech_disk_stats_callback)();
extern const f32 TWindowHelpItem__data_805DCDE4;
extern const f32 lbl_805DCDEC;

// Run each frame on pages that show nothing that changes.
void TWindowHelpItem::idle_update() {}

void TWindowHelpItem::init_text(void *str) {
    u8 *e;
    init_window_layout_entries(
        &this->entry_list,
        reinterpret_cast<const void *>(TWindowHelpItem::description_text_layout),
        this->client_index);
    m_callback = TWindowHelpItem__description_update_callback;
    e = (u8 *)this->get_array_entry(0);
    set_text_entry_string(e, (uaddr)str, 0x20);
    ((TWindowHelpItem *)e)->reset_float_field();
}

void TWindowHelpItem::update_displayed_item() {
    this->format_description_with_price();
    this->init_text((void *)(get_shared_text_buffer()));
}
// Run each frame on the technique disk page: shows the player's MST unless
// the class cannot learn techniques (class flag 0x10).
void TWindowHelpItem::update_tech_disk_stats() {
    PlayerRequirementStats stats;
    TObjPlayer *player;
    CharacterAppearanceFields *appearance;
    HelpItemLevelEntry *mst_entry;
    ((TWindowSubStatusDisp *)&stats)->clear_fields();
    player = get_player_by_client_id(client_index);
    if (player != NULL) {
        appearance = (CharacterAppearanceFields *)((u8 *)player + 0x85C);
        if (appearance != NULL) {
            mst_entry = (HelpItemLevelEntry *)get_array_entry(5);
            if (!(appearance->classFlags & 0x10) && (build_player_equipment_requirement_stats(player, &stats) != 0)) {
                mst_entry->value = stats.mst;
            }
        }
    }
}

void TWindowHelpItem::update_tech_disk_details() {
    s32 requirement;
    saddr player;
    u8 *e0;
    WindowSpritePart *e1;
    TWindowHelpItem *e2;
    u8 *e3;
    TWindowHelpItem *e4;
    TWindowHelpItem *e5;
    TWindowHelpItem *e6;
    player = (saddr)get_player_by_client_id(this->client_index);
    if (player != 0) {
        init_window_layout_entries(
            &this->entry_list,
            reinterpret_cast<const void *>(help_item_tech_disk_window_layout_table),
            this->client_index);
        m_callback = item_help_tech_disk_stats_callback;
        e0 = (u8 *)this->get_array_entry(0);
        text_builder_reset();
        format_item_description((u8 *)active_item);
        text_builder_append();
        if (current_language == LANGUAGE_JAPANESE) {
            get_help_text_string(active_item->data1.data_u8[4]);
            text_builder_append();
        }
        set_text_entry_string(e0, (uaddr)((void *)get_shared_text_buffer()), 0x20);
        ((TWindowHelpItem *)e0)->reset_float_field();
        e1 = (WindowSpritePart *)this->get_array_entry(1);
        e2 = (TWindowHelpItem *)this->get_array_entry(2);
        e3 = (u8 *)this->get_array_entry(3);
        e4 = (TWindowHelpItem *)this->get_array_entry(4);
        e5 = (TWindowHelpItem *)this->get_array_entry(5);
        e6 = (TWindowHelpItem *)this->get_array_entry(6);
        check_equip_requirements((void *)player, active_item, &requirement);
        if (requirement & 1) {
            set_sprite_uv_from_pixels(e1, TWindowHelpItem__data_805DCDE4, 152.0f);
            e2->set_flag0_bit2();
            ((TWindowHelpItem *)e3)->set_flag0_bit2();
            e4->set_flag0_bit2();
            e5->set_flag0_bit2();
            e6->set_flag0_bit2();
            return;
        }
        set_sprite_uv_from_pixels(e1, TWindowHelpItem__data_805DCDE4, lbl_805DCDEC);
        e2->reset_float_field();
        e4->reset_float_field();
        e6->reset_float_field();
        ((HelpItemLevelEntry *)e3)->value = (active_item)->get_technique_level();
    }
}

void TWindowHelpItem::show_item_description() {
    u8 *e;
    HelpItemStarRowEntry *e2;
    init_window_layout_entries(
        &this->entry_list,
        reinterpret_cast<const void *>(window_help_item_layout_entries),
        this->client_index);
    m_callback = item_help_description_idle_callback;
    e = (u8 *)this->get_array_entry(0);
    this->format_description_with_price();
    set_text_entry_string((e), (uaddr)(get_shared_text_buffer()), 0x20);
    ((TWindowHelpItem *)e)->reset_float_field();
    e2 = (HelpItemStarRowEntry *)this->get_array_entry(1);
    e2->stars = (u8)(active_item)->calc_display_grade();
}

void TWindowHelpItem::show_mag_photon_blasts() {
    MagData_80253564 mag;
    s32 slot;
    s32 blast;
    ((MagStats *)(&mag))->init();
    init_window_layout_entries(
        &entry_list,
        reinterpret_cast<const void *>(lbl_804CF4E4),
        client_index);
    m_callback = TWindowHelpItem__photon_blast_update_callback;
    TItemData::deserialize_mag(active_item, &mag);
    for (slot = 0; slot < 3; slot++) {
        blast = ((MagStats *)(&mag))->get_photon_blast(slot);
        if (blast != -1) {
            draw_action_palette_icon(((void *)get_array_entry(slot + 1)), 5, (u16) blast);
        } else {
            draw_action_palette_icon(((void *)get_array_entry(slot + 1)), 0, 0);
        }
    }
}

__declspec(section ".sdata2") extern const f32 lbl_805DCDEC = 192.0f;
__declspec(section ".sdata2") extern const f32 lbl_805DCDF0 = 100.0f;
__declspec(section ".sdata2") extern const f32 lbl_805DCDF4 = 110.0f;
__declspec(section ".sdata2") extern const f32 lbl_805DCDF8 = 0.5f;
__declspec(section ".sdata2") extern const char lbl_805DCDFC[4] = "Hit";
__declspec(section ".sdata2") extern const f32 lbl_805DCE00 = 132.0f;
__declspec(section ".sdata2") extern const f32 lbl_805DCE04 = 232.0f;
__declspec(section ".sdata2") extern const f32 lbl_805DCE08 = 172.0f;
__declspec(section ".sdata2") extern const f32 lbl_805DCE0C = 212.0f;
