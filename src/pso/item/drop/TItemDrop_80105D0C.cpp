#include "pso/system/SubtractiveRng.h"
#include "pso/item/MagStats.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include <stdio.h>
#include <string.h>
#include "pso/system/memory.h"
#include "pso/item/drop/TItemDrop.h"
#include "pso/system/SubtractiveRng.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/item/TItemData.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/city/TShopEquipmentListWindow.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/render_util.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_8010F168.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/map/area/AreaScene.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/system/GslArchive.h"
#include "pso/unk/TLobby_801D6DC4.h"

struct Names_80105DB0 { char *n[4]; };

void *TItemDrop__relocatable_load_buffer;
void *TItemDrop__second_relocatable_load_buffer;
void *TItemDrop__common_probability_table;
struct RareItem_80106A90 { u8 b[4]; };

// ItemRT: the rare drop per enemy type (indexed by type) and the rare box
// drops (count entries, each with its area in types[]).
struct RareTable_80106A90 { RareItem_80106A90 *enemy_items; s32 count; s8 *types; RareItem_80106A90 *items; };

RareTable_80106A90 *TItemDrop__rare_item_table_file;
u8 *TItemDrop__unit_star_classes;
u8 *TItemDrop__unit_star_bucket_counts;
s32 TItemDrop__drop_table_mode_flags;
s32 TItemDrop__section_id;
extern "C" {

s32 get_drop_table_mode_flags(void);
s32 item_drop_cached_offset = -1;
const char *item_drop_class_name = "TItemDrop";
u8 TItemDrop__sub_80107B04(void *);
u8 TLobby__sub_801D6F94(void *);
u8 TLobby__sub_801D6FFC(void *);
u8 fn_801D7168(void *);
u8 fn_801D719C(void *);
u8 fn_801D71D0(void *);
u8 fn_801D7204(void *);
void apply_drop_restrictions(void *arg0, TItemData *it);
void format_drop_table_filename(char *out, const char *prefix);
s32 get_item_star_count(s32 id);
}
void init_item_drop_globals(void);
void unload_item_drop_globals(void);
s32 is_unsealable_item(u8 *id);
void unload_item_drop_globals(void) {  }

    extern int item_desync_detected;

// inferred: the load half of unload_item_drop_globals' pair in item_class_load_unload_table.
void init_item_drop_globals(void) { item_desync_detected = 0; }

void TItemDrop::clear_item_if_player_picked_up(void* p, void* id) { if (is_unsealable_item((u8 *)id) == 1) { ((TItemData *)id)->set_packed_value((u16)0); } }

s32 get_drop_table_mode_flags(void) {
    s32 f = 0;
    if (get_game_play_mode() == 1) {
        f |= 1;
    } else {
        f &= ~1;
    }
    if (TLobby::get_instance() == 1) {
        f |= 2;
    } else {
        f &= ~2;
    }
    return f;
}

void format_drop_table_filename(char *out, const char *prefix) {
    Names_80105DB0 names = {{"n", "h", "v", "u"}};
    char *s1;
    s32 n;
    if (TItemDrop__drop_table_mode_flags & 1) {
        s1 = "c";
        n = 0;
    } else {
        s1 = "";
        n = TItemDrop__section_id;
    }
    sprintf(out, "%s%s%s%s%1d.rel", prefix, s1, (TItemDrop__drop_table_mode_flags & 2) ? "l" : "", names.n[game_difficulty_selection], n);
}

s32 TItemDrop::calc_drop_offset(s32 arg0) {
    s32 var_r31;

    var_r31 = arg0 + (game_difficulty_selection * 0xA);
    if (get_game_play_mode() == 1) {
        var_r31 += 0x50;
    } else if (TLobby::get_instance() == 1) {
        var_r31 += 0x28;
    }
    return var_r31;
}

void apply_drop_restrictions(void *arg0, TItemData *it) {
    void *p;
    u8 m;
    if (it == NULL) {
        return;
    }
    if (TItemDrop::can_drop() == 0 && TItemData::is_rare_item((u8 *)it) != 0) {
        it->init();
        return;
    }
    if (get_game_play_mode() == 1) {
        if (it->data1.data_u8[0] == 1) {
            if (it->data1.data_u8[1] == 3) {
                if (static_cast<u8>(*reinterpret_cast<const s8 *>(&it->data1.data_u8[2])) >= 0x33 && static_cast<u8>(*reinterpret_cast<const s8 *>(&it->data1.data_u8[2])) <= 0x38) {
                    it->init();
                }
            }
        } else if (it->data1.data_u8[0] == 4) {
            it->init();
        }
    }
    p = lobby_rule_settings;
    if (((TLobby *)lobby_rule_settings)->get_rule_field_0() == TItemDrop__sub_80107B04(p)) {
        return;
    }
    if (it->data1.data_u8[0] == 0 || it->data1.data_u8[0] == 1) {
        switch (fn_801D71D0(p)) {
        case 2:
            it->init();
            return;
        case 3:
            if (TItemData::is_rare_item((u8 *)it) == 1) {
                it->init();
            }
            return;
        }
    }
    if (it->data1.data_u8[0] == 2) {
        if (fn_801D719C(p) == 1) {
            it->init();
        }
    } else if (it->data1.data_u8[0] == 3) {
        if (fn_801D7168(p) == 2) {
            it->init();
        } else if (it->data1.data_u8[1] == 2) {
            switch (fn_801D7204(p)) {
            case 0:
                return;
            case 1:
                it->init();
                break;
            default:
                m = ((TItemDrop *)p)->get_bool_from_1d6ddc();
                if (m != 0) {
                    it->data1.data_u8[2] = it->data1.data_u8[2] % m;
                } else {
                    it->data1.data_u8[2] = 0;
                }
                break;
            }
        } else if (it->data1.data_u8[1] == 9) {
            if (TLobby__sub_801D6F94(p) == 1) {
                it->init();
                return;
            }
            return;
        }
    } else if (it->data1.data_u8[0] == 4) {
        if (TLobby__sub_801D6FFC(p) == 1) {
            it->init();
        }
    }
}

s32 TItemDrop::is_enabled() {
    return (u8) (get_game_play_mode() != 1);
}

s32 TItemDrop::is_not_special(void *) {
    return (u8) (get_game_play_mode() != 1);
}

s32 TItemDrop::can_drop() {
    int var_r31;

    var_r31 = 0;
    if ((get_game_play_mode() != 1) && (TLobby::get_drop_flag() == 0)) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}


void TItemDrop::set_drop_index(void *rng, void *item) {
    *(s8 *)((s8 *)item + 5) = ((TItemDrop *)rng)->select_weighted_byte(*(s32 *)((s8 *)TItemDrop__common_probability_table + 0x14), 0, 5, 1);
}

void TItemDrop::select_unit_drop(u8 kind, u8 *item) {
    u8 *p;
    u32 n;
    s32 i;
    u32 pick;
    s32 r;
    u8 *data;
    s16 v;
    u8 cnt;
    if (kind >= 0xD) {
        return;
    }
    ((TItemData *)item)->init();
    item[0] = 1;
    item[1] = 3;
    TItemDrop::init_drop_table();
    cnt = TItemDrop__unit_star_bucket_counts[kind];
    if (cnt == 0) {
        return;
    }
    pick = roll_channel_below((s32)cnt, (u32)(0xB));
    n = 0;
    for (i = 0; i < 0x88; i++) {
        if (TItemDrop__unit_star_classes[i] == kind) {
            if (n == pick) {
                if (i < 0x50) {
                    item[2] = i / 5;
                    r = (u8)(i % 5);
                    data = (u8 *)lookup_item_pmt_record(item);
                    if (data == NULL) {
                        return;
                    }
                    v = *(s16 *)(data + 0xC);
                    switch (r) {
                    case 0:
                        ((TItemData *)item)->set_unit_modifier(-(v * 2));
                        break;
                    case 1:
                        ((TItemData *)item)->set_unit_modifier(-v);
                        break;
                    case 2:
                        break;
                    case 3:
                        ((TItemData *)item)->set_unit_modifier(v);
                        break;
                    case 4:
                        ((TItemData *)item)->set_unit_modifier(v * 2);
                        break;
                    }
                } else if (kind < 0x88) {
                    item[2] = i - 0x40;
                }
                return;
            }
            n++;
        }
    }
}

void TItemDrop::init_drop_table() {
    s32 i;
    s8 temp_r0;
    u8 *var_r30;
    u8 item_star_count;
    u8 temp_r4;
    u8 temp_r5;

    i = 0;
    var_r30 = TItemDrop__unit_star_classes;
    do {
        item_star_count = get_item_star_count(i + 0x2AF);
        temp_r5 = item_star_count;
        i += 1;
        temp_r4 = temp_r5 - 1;
        *(u8 *)((s8 *)var_r30 + 0) = temp_r4;
        temp_r0 = temp_r5 + 1;
        *(u8 *)((s8 *)var_r30 + 1) = temp_r4;
        *(u8 *)((s8 *)var_r30 + 2) = item_star_count;
        *(s8 *)((s8 *)var_r30 + 3) = temp_r0;
        *(s8 *)((s8 *)var_r30 + 4) = temp_r0;
        var_r30 += 5;
    } while (i != 0x10);
    while (i != 0x48) {
        *var_r30 = get_item_star_count(i + 0x2AF);
        var_r30 += 1;
        i += 1;
    }
}
void TItemDrop::count_unit_star_buckets() {
    s32 i;
    u8 v;
    memset(TItemDrop__unit_star_bucket_counts, 0, 0xD);
    TItemDrop::init_drop_table();
    for (i = 0; i < 0x88; i++) {
        v = TItemDrop__unit_star_classes[i];
        if (v < 0xD) {
            TItemDrop__unit_star_bucket_counts[v]++;
        }
    }
}
void TItemDrop::refresh_drop_table_if_changed() {
    if (item_drop_cached_offset != TItemDrop::calc_drop_offset(leader_selection.get_section_id()) ||
        TItemDrop__drop_table_mode_flags != get_drop_table_mode_flags()) {
        TItemDrop__section_id = leader_selection.get_section_id();
        load_drop_tables();
    }
}

#pragma push


struct Pair_80106F4C { u8 type; u8 level; };

struct Obj_80106F4C { u8 pad[6]; Pair_80106F4C e[3]; };


struct Tbl_80106E04 {
    u8 pad[0x34];
    u8 *chance;
    u8 *rate;
};

struct Tbl_8010663C { u8 pad[0x18]; s32 f18; u8 *chance; u8 *kind; };

struct Tbl_80106FC8 {
    u8 pad[0x28];
    s32 levels;
    s8 *kinds;
    s32 types;
};

struct Pair_801075B4 { u16 lo; u16 hi; };

struct Pair_80107640 { u8 lo; u8 hi; };

struct Tbl_80107210
{
  u8 *weights;
  s8 *offs;
  s8 *divs;
};

extern "C" {
void roll_armor_bonuses__9TItemDropFv(saddr, void *);
s32 try_generate_rare_item__9TItemDropFiPvPv(saddr arg0, u8 *arg1, u8 *arg2);
u8 select_weighted_column_u16__9TItemDropFiiiii(saddr, saddr, s32, s32, s32);
s32 find_tool_pmt_base_id(u8, void *);
void generate_tool_drop__9TItemDropFiiPv(saddr item_drop, s32 arg1, void *item_data);
u8 *create_drop__9TItemDropFi(saddr arg0);
u32 subtractive_rng_next(void *);
s32 __cvt_fp2unsigned(f32);
extern const f32 lbl_805DAAD8;
s32 item_drop_rng_below(SubtractiveRng *rng, u32 count);
void prune_weapon_attributes__9TItemDropFPvPv(void *self, Obj_80106F4C *o);
u8 roll_weapon_special_for_stars(u8);
void roll_weapon_special__9TItemDropFiPvi(saddr rng, u8 *item, s32 idx);
extern const f32 lbl_805DAADC;
extern const f32 lbl_805DAAD4;
extern const f32 lbl_805DAAE4;

void select_box_item__9TItemDropFiiPv(saddr rng, s32 arg1, u8 *arg2);
u8 select_weighted_column_u16__9TItemDropFiiiii(saddr rng, saddr base, s32 off, s32 count, s32 stride);
void roll_rare_weapon_attributes__9TItemDropFiPvi(saddr rng, Obj_80106F4C *item, s32 idx);
void build_weapon_type_weights__9TItemDropFiPvi(saddr rng, Obj_80106F4C *item, s32 idx);
void select_weapon_drop__9TItemDropFv(saddr rng, s32 level, u8 *item);


void TItemDrop::free_unit_star_tables() {
    mem_free((void *)TItemDrop__unit_star_bucket_counts);
    TItemDrop__unit_star_bucket_counts = 0;
    mem_free((void *)TItemDrop__unit_star_classes);
    TItemDrop__unit_star_classes = 0;
}


void TItemDrop::alloc_unit_star_tables() {
    TItemDrop__unit_star_classes = (u8 *)mem_alloc(0x88);
    TItemDrop__unit_star_bucket_counts = (u8 *)mem_alloc(0xD);
    TItemDrop::count_unit_star_buckets();
}

void TItemDrop::unload_drop_tables() {  }


void TItemDrop::load_drop_tables() {
    char path[0x48];
    item_drop_cached_offset = TItemDrop::calc_drop_offset(TItemDrop__section_id);
    TItemDrop__drop_table_mode_flags = get_drop_table_mode_flags();
    if (item_drop_cached_offset >= 0 && item_drop_cached_offset <= 0xA0) {
        open_gsl_archive("ItemPT.gsl");
        format_drop_table_filename(path, "ItemPT");
        TItemDrop__common_probability_table = load_relocatable_file(path, TItemDrop__relocatable_load_buffer);
        close_gsl_archive();
        open_gsl_archive("ItemRT.gsl");
        format_drop_table_filename(path, "ItemRT");
        TItemDrop__rare_item_table_file = (RareTable_80106A90 *)load_relocatable_file(path, TItemDrop__second_relocatable_load_buffer);
        close_gsl_archive();
    }
}

f32 TItemDrop::roll_table_ratio(u32 channel) {
    if (channel < 0x10U) {
        return calc_random_ratio__10TObjPlayerFv(entries[channel]);
    }
    return calc_random_ratio__10TObjPlayerFv(entries[0x10]);
}

u32 TItemDrop::roll_channel_below(s32 count, u32 channel) {
    if (channel < 0x10U) {
        return item_drop_rng_below(entries[channel], count);
    }
    return item_drop_rng_below(entries[0x10], count);
}

void select_enemy_drop__9TItemDropFPviiPv(u8 *self, s32 area, s32 idx, TItemData *item) {
    s32 r;
    u8 kind;
    if (item == NULL) {
        return;
    }
    item->init();
    if (area > 0x58) {
        return;
    }
    if (((TItemDrop *)self)->roll_channel_below(0x64, 0) >= ((Tbl_8010663C *)TItemDrop__common_probability_table)->chance[area]) {
        return;
    }
    if (TItemDrop::drop_item((saddr)self, area, (saddr)item) != 0) {
        return;
    }
    if (TItemDrop::is_not_special(self) == 1) {
        r = ((TItemDrop *)self)->roll_channel_below(3, 1);
    } else {
        r = ((TItemDrop *)self)->roll_channel_below(2, 1) + 1;
    }
    switch (r) {
    case 0:
        kind = 5;
        break;
    case 1:
        kind = 4;
        break;
    case 2:
        kind = ((Tbl_8010663C *)TItemDrop__common_probability_table)->kind[area];
        break;
    default:
        return;
    }
    switch (kind) {
    case 0:
        item->data1.data_u8[0] = 0;
        break;
    case 1:
        item->data1.data_u8[1] = item->data1.data_u8[0] = 1;
        break;
    case 2:
        item->data1.data_u8[0] = 1;
        item->data1.data_u8[1] = 2;
        break;
    case 3:
        item->data1.data_u8[0] = 1;
        item->data1.data_u8[1] = 3;
        break;
    case 4:
        item->data1.data_u8[0] = 3;
        break;
    case 5:
        item->data1.data_u8[0] = 4;
        item->data2.data_u32 = ((TItemDrop *)self)->roll_meseta_range((s32)(((Tbl_8010663C *)TItemDrop__common_probability_table)->f18), area, 0, 1);
        break;
    default:
        return;
    }
    if (item->data1.data_u8[0] != 4) {
        ((TItemDrop *)self)->generate_drop_item(idx, (u8 *)item);
    }
}

void select_box_item__9TItemDropFiiPv(saddr rng, s32 off, u8 *item) {
    if (item == NULL) {
        return;
    }
    ((TItemData *)item)->init();
    if (TItemDrop::select_rare_box_item(rng, off, item) != 0) {
        return;
    }
    switch (((TItemDrop *)rng)->select_weighted_byte(*(s32 *)((s8 *)TItemDrop__common_probability_table + 0x50), off, 7, 0xA)) {
    case 0:
        item[0] = 0;
        break;
    case 1:
        item[0] = 1;
        item[1] = 1;
        break;
    case 2:
        item[0] = 1;
        item[1] = 2;
        break;
    case 3:
        item[0] = 1;
        item[1] = 3;
        break;
    case 4:
        item[0] = 3;
        break;
    case 5:
        item[0] = 4;
        break;
    default:
        return;
    }
    ((TItemDrop *)rng)->generate_drop_item(off, item);
}

void TItemDrop::generate_drop_item(s32 idx, u8 *item) {
    f32 f;
    if (item == NULL) {
        return;
    }
    switch (item[0]) {
    case 0:
        select_weapon_drop__9TItemDropFv((s32)((saddr)((u8 *)this)), idx, item);
        break;
    case 1:
        if (item[1] == 3) {
            f = lbl_805DAADC + (f32)(*(u8 **)((u8 *)TItemDrop__common_probability_table + 0x4C))[idx];
            ((TItemDrop *)((u8 *)this))->select_unit_drop((u8)(s32)(f * roll_table_ratio(0xE)), item);
            if (item[2] == 0xFF) {
                ((TItemData *)item)->init();
            }
        } else {
            TItemDrop::calc_drop_rarity((saddr)((u8 *)this), idx, item);
        }
        break;
    case 3:
        generate_tool_drop__9TItemDropFiiPv((saddr)((u8 *)this), idx, item);
        break;
    case 4:
        *(u32 *)(item + 0x10) = roll_meseta_range((s32)(*(s32 *)((u8 *)TItemDrop__common_probability_table + 0x24)), idx, 0, 1);
        break;
    case 2:
        TItemDrop::apply_item_data(((u8 *)this), item);
        break;
    default:
        ((TItemData *)item)->init();
        item[0] = 5;
        break;
    }
    apply_drop_restrictions(((u8 *)this), (TItemData *)item);
    TItemDrop::clear_item_if_player_picked_up(((u8 *)this), item);
}

s32 TItemDrop::select_rare_box_item(s32 rng, s32 off, u8 *item) {
    s32 target;
    s32 i;
    if (TItemDrop__rare_item_table_file != NULL && TItemDrop::can_drop() == 1) {
        target = off + 1;
        for (i = 0; i != TItemDrop__rare_item_table_file->count; i++) {
            if (target == TItemDrop__rare_item_table_file->types[i]) {
                if (try_generate_rare_item__9TItemDropFiPvPv(rng, (u8 *)&TItemDrop__rare_item_table_file->items[i], item) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 TItemDrop::drop_item(s32 rng, s32 area, saddr item) {
    if ((TItemDrop::can_drop() == 1) && (TItemDrop__rare_item_table_file != NULL) && (area > 0) && (area < 0x58)) {
        return try_generate_rare_item__9TItemDropFiPvPv((s32)rng, (u8 *)&TItemDrop__rare_item_table_file->enemy_items[area], (u8 *)item);
    }
    return 0;
}


void TItemDrop::calc_drop_rarity(saddr rng, s32 idx, void *item_) {
    u8 temp_r3;
    u8 call_res;

    roll_armor_bonuses__9TItemDropFv(rng, item_);
    call_res = (u8) ((TItemDrop *)rng)->select_weighted_byte((s32)((s32)(*(s32 *)((s8 *)TItemDrop__common_probability_table + 0x10))), 0, 5, 1);
    *(u8 *)((s8 *)item_ + 2) = (u8) (idx + call_res + *(u8 *)((s8 *)TItemDrop__common_probability_table + 0x48));
    temp_r3 = *(u8 *)((s8 *)item_ + 2);
    if (temp_r3 < 3U) {
        *(u8 *)((s8 *)item_ + 2) = 0U;
    } else {
        *(u8 *)((s8 *)item_ + 2) = (temp_r3 - 3);
    }
}

void TItemDrop::init_rare_item_data(void *arg0, void *item_data) {
    if (((u8) *(u8 *)((s8 *)item_data + 1) == 2) && (((u8) *(u8 *)((s8 *)item_data + 4) >= 0x13U) || ((u8) *(u8 *)((s8 *)item_data + 2) >= 0x1EU))) {
        ((TItemData *)item_data)->init();
    }
}

void TItemDrop::handle_type3(void* p, void* a1) { if (*(unsigned char*)(a1) == 3) { ((TItemData *)a1)->set_stack_count(1); } }

void TItemDrop::apply_item_data(void *arg0, void *item) {
    s32 mag;

    if ((u8) *(u8 *)((s8 *)item + 0) == 2) {
        ((MagStats *)(&mag))->init();
        *(s8 *)((s8 *)item + 1) = 0;
        TItemData::serialize_mag(item, &mag);
    }
}

struct Def_80106D0C {
    u8 pad[0x16];
    u8 a;
    u8 b;
};

#define item ((u8 *)item_)
void roll_armor_bonuses__9TItemDropFv(saddr rng, void *item_) {
    Def_80106D0C *def;

    if (item[0] != 1) {
        return;
    }
    switch (item[1]) {
    case 1:
        TItemDrop::set_drop_index((void *)rng, item);
    case 2:
        def = (Def_80106D0C *)lookup_item_pmt_record(item);
        if (def != NULL) {
            f32 r;
            r = reinterpret_cast<TItemDrop *>(rng)->roll_table_ratio(12);
            ((TItemData *)item)->set_dfp_bonus((s16)(def->a * r));
            r = reinterpret_cast<TItemDrop *>(rng)->roll_table_ratio(13);
            ((TItemData *)item)->set_bswapped_field_8((s16)(def->b * r));
        }
        break;
    }
}
#undef item

extern const u8 lbl_805DAAE0;

void roll_weapon_special__9TItemDropFiPvi(saddr rng, u8 *item, s32 idx) {
    u8 *chance;
    if (item[0] == 0 && TItemData::is_rare_item(item) == 0) {
        chance = ((Tbl_80106E04 *)TItemDrop__common_probability_table)->chance;
        if (chance[idx] != 0 && ((TItemDrop *)rng)->roll_channel_below(100, 9) < ((Tbl_80106E04 *)TItemDrop__common_probability_table)->rate[idx]) {
            item[4] = roll_weapon_special_for_stars((u8)(s32)((f32)chance[idx] * reinterpret_cast<TItemDrop *>(rng)->roll_table_ratio(10)));
        }
    }
}

void TItemDrop::set_flag(void *rng, void *item) {
    u8 temp_r3;

    if ((TItemDrop::is_enabled() == 1) && ((u8) *(u8 *)((s8 *)item + 0) == 0)) {
        if (TItemData::is_rare_item((u8 *)item) != 0) {
            *(u8 *)((s8 *)item + 4) = (u8) (*(u8 *)((s8 *)item + 4) | lbl_805DAAE0);
            return;
        }
        temp_r3 = *(u8 *)((s8 *)item + 4);
        if (temp_r3 != 0) {
            *(u8 *)((s8 *)item + 4) = (u8) (temp_r3 | lbl_805DAAE0);
        }
    }
}


void prune_weapon_attributes__9TItemDropFPvPv(void *self, Obj_80106F4C *o) {
    s32 i;
    s32 j;
    for (i = 0; i != 3; i++) {
        for (j = 0; j != i; j++) {
            if (o->e[j].type == 0) {
                o->e[i].type = 0;
            } else if (o->e[i].type == o->e[j].type) {
                o->e[i].type = 0;
            }
        }
        if (o->e[i].type == 0) {
            o->e[i].level = 0;
        }
    }
}

struct Tbl_801070A4 {
    u8 pad[0x28];
    s32 levels;
    s8 *kinds;
    s32 types;
};

void roll_rare_weapon_attributes__9TItemDropFiPvi(saddr rng, Obj_80106F4C *item, s32 idx) {
    s32 i;
    if (item->pad[0] == 0) {
        for (i = 0; i != 3; i++) {
            item->e[i].type = ((TItemDrop *)rng)->select_weighted_byte(((Tbl_80106FC8 *)TItemDrop__common_probability_table)->types, idx, 6, 10);
            item->e[i].level = (s8)select_weighted_column_u16__9TItemDropFiiiii(rng, ((Tbl_80106FC8 *)TItemDrop__common_probability_table)->levels, 5, 0x17, 6) * 5 - 10;
            if (item->e[i].type == 5) {
                item->e[i].level = (s8)item->e[i].level / 5;
                item->e[i].level = item->e[i].level * 5;
            }
        }
        prune_weapon_attributes__9TItemDropFPvPv((void *)rng, item);
    }
}

void build_weapon_type_weights__9TItemDropFiPvi(saddr rng, Obj_80106F4C *item, s32 idx) {
    s32 i;
    s32 kind[1];

    if (item->pad[0] == 0) {
        for (i = 0; i != 3; i++) {
            kind[0] = ((Tbl_801070A4 *)TItemDrop__common_probability_table)->kinds[i * 10 + idx];
            if (kind[0] != -1) {
                item->e[i].type = ((TItemDrop *)rng)->select_weighted_byte(((Tbl_801070A4 *)TItemDrop__common_probability_table)->types, idx, 6, 10);
                item->e[i].level = (s8)select_weighted_column_u16__9TItemDropFiiiii(rng, ((Tbl_801070A4 *)TItemDrop__common_probability_table)->levels, kind[0], 0x17, 6) * 5 - 10;
            }
            if (item->e[i].type == 5) {
                item->e[i].level = (s8)item->e[i].level / 5;
                item->e[i].level = item->e[i].level * 5;
            }
        }
        prune_weapon_attributes__9TItemDropFPvPv((void *)rng, item);
    }
}

void TItemDrop::calc_drop_item(saddr rng, void *item, s32 value) {
    if ((u8) *(u8 *)((s8 *)item + 0) == 0) {
        *(s8 *)((s8 *)item + 3) = ((TItemDrop *)rng)->select_weighted_byte((s32)((s32)(*(s32 *)((s8 *)TItemDrop__common_probability_table + 0xC))), (s32)((s32)(clamp_s32(value, 0, 3))), 9, 4);
    }
}

typedef struct Tbl_80107210 Tbl_80107210;
void select_weapon_drop__9TItemDropFv(saddr rng, s32 level, u8 *item) {
  u8 w[13];
  s32 i;
  s32 v;
  u32 k;
  s8 off;
  u8 div;
  ((TItemData *)item)->init();
  item[0] = 0;
  w[0] = 0;
  memcpy(&w[1], ((Tbl_80107210 *) TItemDrop__common_probability_table)->weights, 0xC);
  for (i = 1; i < 13; i++)
  {
    if ((level + ((Tbl_80107210 *) TItemDrop__common_probability_table)->offs[i - 1]) < 0)
    {
      w[i] = 0;
    }
  }
  item[1] = ((TItemDrop *)rng)->select_weighted_byte((saddr) w, 0, 0xD, 1);
  k = item[1];
  if (k == 0)
  {
    ((TItemData *)item)->init();
    return;
  }
  {
    Tbl_80107210 *t = (Tbl_80107210 *) TItemDrop__common_probability_table;
    div = t->divs[k - 1];
    off = t->offs[k - 1];
  }
  if (off < 0)
  {
    v = level - (-off);
    item[2] = v / div;
    TItemDrop::calc_drop_item(rng, item, v % div);
  }
  else
  {
    item[2] = off + (level / ((s8) div));
    TItemDrop::calc_drop_item(rng, item, level % div);
  }
  build_weapon_type_weights__9TItemDropFiPvi(rng, (Obj_80106F4C *)(item), level);
  roll_weapon_special__9TItemDropFiPvi(rng, item, level);
  TItemDrop::set_flag((void *) rng, item);
}

#pragma push
#pragma fp_contract on
void generate_tool_drop__9TItemDropFiiPv(saddr item_drop, s32 off, void *item_data) {
    u8 var_r3;
    ((TItemData *)item_data)->init();
    var_r3 = ((s32 (*)(s32, s32, s32, s32, s32))select_weighted_column_u16__9TItemDropFiiiii)(item_drop, *(s32 *)((s8 *)TItemDrop__common_probability_table + 0x3C), off, 0x1C, 0xA);
    switch (var_r3) {
    case 0x1A:
        var_r3 = 0x73;
        break;
    }
    find_tool_pmt_base_id(var_r3, item_data);
    if ((u8) *(u8 *)((s8 *)item_data + 1) == 2) {
        *(u8 *)((s8 *)item_data + 4) = ((u8)((TItemDrop *)item_drop)->select_weighted_byte((s32)(*(s32 *)((s8 *)TItemDrop__common_probability_table + 0x40)), off, 0x13, 0xA));
        *(s8 *)((s8 *)item_data + 2) = ((TItemDrop *)item_drop)->roll_technique_level(*(s32 *)((s8 *)TItemDrop__common_probability_table + 0x44), *(u8 *)((s8 *)item_data + 4), off, 0xA);
        TItemDrop::init_rare_item_data((void *)item_drop, (void *)item_data);
    }
    TItemDrop::handle_type3((void*)item_drop, (void*)item_data);
}
#pragma pop

s32 try_generate_rare_item__9TItemDropFiPvPv(saddr rng, u8 *arg1, u8 *item) {
    s32 var_r5;
    u32 temp_r3;
    u8 temp_r31;
    u32 tmp;
    if ((arg1 != NULL) && (item != NULL)) {
        temp_r31 = *(u8 *)((s8 *)arg1 + 0);
        if (temp_r31 != 0) {
            temp_r3 = ((TItemDrop *)rng)->roll_channel_below(-1, 6);
            var_r5 = ((temp_r31 >> 3U) & 0x1F) - 4;
            if (var_r5 < 0) {
                var_r5 = 0;
            }
            if (temp_r3 < (u32) ((2 << var_r5) * ((temp_r31 & 7) + 7))) {
                *(u8 *)((s8 *)item + 0) = (u8) *(u8 *)((s8 *)arg1 + 1);
                *(u8 *)((s8 *)item + 1) = (u8) *(u8 *)((s8 *)arg1 + 2);
                *(u8 *)((s8 *)item + 2) = (u8) *(u8 *)((s8 *)arg1 + 3);
                switch ((s32) (*(u8 *)((s8 *)item + 0))) {
                case 0:
                    tmp = ((TItemDrop *)rng)->roll_channel_below(0xA, 7);
                    roll_rare_weapon_attributes__9TItemDropFiPvi(rng, (Obj_80106F4C *)(item), tmp);
                    TItemDrop::set_flag((void *)rng, (void *)item);
                    break;
                case 1:
                    roll_armor_bonuses__9TItemDropFv(rng, item);
                    break;
                case 2:
                    TItemDrop::apply_item_data((void *)rng, (void *)item);
                    break;
                case 3:
                    TItemDrop::init_rare_item_data((void *)rng, (void *)item);
                    TItemDrop::handle_type3((void*)rng, (void*)item);
                    break;
                }
                apply_drop_restrictions((void *)rng, reinterpret_cast<TItemData *>(item));
                TItemDrop::clear_item_if_player_picked_up((void *)rng, (void *)item);
                return 1;
            }
            goto block_18;
        }
    }
block_18:
    return 0;
}

u16 TItemDrop::roll_meseta_range(saddr arg1, s32 a, s32 b, s32 c) {
    Pair_801075B4 *tbl = (Pair_801075B4 *)arg1;
    u32 lo = tbl[b + a * c].lo;
    u32 hi = tbl[b + a * c].hi;
    u16 base = lo;
    if (lo == 0xFF || hi == 0xFF || hi < lo) {
        return 0xFF;
    }
    if (lo == hi) {
        return lo;
    }
    {
        u16 r = roll_channel_below((hi - lo + 1), 5);
        return r + base;
    }
}

u8 TItemDrop::roll_technique_level(saddr table, s32 row, s32 col, s32 stride) {
    Pair_80107640 *tbl = (Pair_80107640 *)table;
    u32 lo = tbl[col + row * stride].lo;
    u32 hi = tbl[col + row * stride].hi;
    u8 base = lo;
    if (lo == 0xFF || hi == 0xFF || hi < lo) {
        return 0xFF;
    }
    if (lo == hi) {
        return lo;
    }
    {
        u8 r = roll_channel_below((hi - lo + 1), 4);
        return r + base;
    }
}

u8 select_weighted_column_u16__9TItemDropFiiiii(saddr rng, saddr base, s32 off, s32 count, s32 stride) {
    u16 *p = (u16 *)base;
    u32 total = 0;
    u32 r;
    u8 i;

    for (i = 0; i != count; i++) {
        total += p[off + i * stride];
    }
    if (total == 0) {
        return 0xFF;
    }
    r = ((TItemDrop *)rng)->roll_channel_below((s32)total, (u32)(3));
    for (i = 0; i != count; i++) {
        u16 w = p[off + i * stride];
        if (w != 0) {
            if (r < w) {
                return i;
            }
            r -= w;
        }
    }
    return 0xFF;
}

u8 TItemDrop::select_weighted_byte(saddr base, s32 off, s32 count, s32 stride) {
    u8 *p = (u8 *)(base + off);
    u32 total = 0;
    u32 r;
    u8 i;
    for (i = 0; i != count; i++) {
        total += p[i * stride];
    }
    if (total == 0) {
        return 0xFF;
    }
    r = roll_channel_below((total), 2);
    for (i = 0; i != count; i++) {
        u8 w = p[i * stride];
        if (w != 0) {
            if (r < w) {
                return i;
            }
            r -= w;
        }
    }
    return 0xFF;
}

TItemDrop::~TItemDrop() {
    s32 i;
    TItemDrop__sub_8010F168((void *)load_unload_set, 1);
    load_unload_set = 0;
    safe_free(TItemDrop__relocatable_load_buffer);
    TItemDrop__relocatable_load_buffer = 0;
    safe_free(TItemDrop__second_relocatable_load_buffer);
    TItemDrop__second_relocatable_load_buffer = 0;
    for (i = 0; i != 0x11; i++) {
        ::operator delete(entries[i]);
    }
    mem_free(entries);
    entries = 0;
}

// The drop tables' resource set (the ctor hands it to create_load_unload_set):
// {load, unload} the drop tables, {allocate, free} the unit star tables.
// Name inferred from item_class_load_unload_table.
ItemClassLoadUnloadEntry item_drop_load_unload_table[3] = {
    { TItemDrop::load_drop_tables, TItemDrop::unload_drop_tables },
    { TItemDrop::alloc_unit_star_tables, TItemDrop::free_unit_star_tables },
    { NULL, NULL },
};

TItemDrop::TItemDrop(TObject *parent, s8 section) : TObject(parent) {
    s32 i;
    u32 a;
    u32 b;
    SubtractiveRng *obj;
    m_name = item_drop_class_name;
    TItemDrop__section_id = section;
    entries = static_cast<SubtractiveRng **>(mem_alloc(0x11 * sizeof(*entries)));
    for (i = 0; i != 0x11; i++) {
        a = __cvt_fp2unsigned(lbl_805DAAD8 * (lbl_805DAAE4 * (f32)rand()));
        b = __cvt_fp2unsigned(lbl_805DAAD4 * (lbl_805DAAE4 * (f32)rand()));
        obj = static_cast<SubtractiveRng *>(::operator new(sizeof(SubtractiveRng)));
        if (obj != 0) {
            obj = obj->reseed(a | b);
        }
        entries[i] = obj;
    }
    TItemDrop__second_relocatable_load_buffer = TQuestVmDownLoadServer::alloc(0xC00);
    TItemDrop__relocatable_load_buffer = TQuestVmDownLoadServer::alloc(0xC00);
    load_unload_set = create_load_unload_set(item_drop_load_unload_table);
}

u8 *create_drop__9TItemDropFi(saddr parent) {
    u8 section;
    u8 *char_index;
    char_index = (u8 *)(TAdSinglePlyChrSelectGC::get_char_index(0U));
    if (char_index != NULL) {
        section = *(u8 *)((s8 *)char_index + 0x3A0);
        if (((s8) section >= 0) && ((s8) section < 0xA)) {
            return (u8 *)new TItemDrop((TObject *)parent, (s8)section);
        }
    }
    return NULL;
}

s8 TItemDrop::get_bool_from_1d6ddc() { return (s8)(TLobby__sub_801D6DDC(this)); }
u8 TItemDrop__sub_80107B04(void *) { return 0; }
s32 item_drop_rng_below(SubtractiveRng *rng, u32 count) {
    return __cvt_fp2unsigned((f32)(((f32)count * (f32)subtractive_rng_next(rng)) / lbl_805DAAD8));
}

}

#pragma pop

__declspec(section ".sdata2") extern const f32 lbl_805DAAD4 = 65536.0f;
__declspec(section ".sdata2") extern const f32 lbl_805DAAD8 = 4294967296.0f;
__declspec(section ".sdata2") extern const f32 lbl_805DAADC = 1.0f;
__declspec(section ".sdata2") extern const u8 lbl_805DAAE0 = 0x80;
__declspec(section ".sdata2") extern const f32 lbl_805DAAE4 = 3.0517578e-05f;
