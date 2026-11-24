#include "pso/system/SubtractiveRng.h"
#include "pso/item/MagStats.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include <stdio.h>
#include <string.h>
#include "pso/system/memory.h"
#include "pso/item/drop/TItemDrop.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/item/TItemData.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/city/TShopEquipmentListWindow.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyCharData.h"
#include "pso/item/item_pmt.h"
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
#include "pso/item/item_create.h"

struct DifficultyLetters { char *n[4]; };

void *TItemDrop::relocatable_load_buffer;
void *TItemDrop::second_relocatable_load_buffer;
ItemDropTable *TItemDrop::common_probability_table;
ItemDropRareTable *TItemDrop::rare_item_table_file;
u8 *TItemDrop::unit_star_classes;
u8 *TItemDrop::unit_star_bucket_counts;
s32 TItemDrop::drop_table_mode_flags;
s32 TItemDrop::section_id;

s32 item_drop_cached_offset = -1;
const char *item_drop_class_name = "TItemDrop";

extern "C" {
u8 TLobby__sub_801D6F94(void *);
u8 TLobby__sub_801D6FFC(void *);
u8 fn_801D7168(void *);
u8 fn_801D719C(void *);
u8 fn_801D71D0(void *);
u8 fn_801D7204(void *);
u32 subtractive_rng_next(void *);
s32 __cvt_fp2unsigned(f32);
}

extern const f32 item_drop_u16_scale;
extern const f32 item_drop_u32_scale;
extern const f32 item_drop_one;
extern const u8 item_unidentified_flag;
extern const f32 item_drop_rand_reciprocal;

void unload_item_drop_globals() {  }

extern int item_desync_detected;

void init_item_drop_globals() { item_desync_detected = 0; }

void TItemDrop::clear_item_if_player_picked_up(TItemData *item) {
    if (is_unsealable_item((u8 *)item) == 1) {
        item->set_packed_value((u16)0);
    }
}

s32 TItemDrop::get_drop_table_mode_flags() {
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

void TItemDrop::format_drop_table_filename(char *out, const char *prefix) {
    DifficultyLetters names = {{"n", "h", "v", "u"}};
    char *challenge;
    s32 section;
    if (drop_table_mode_flags & 1) {
        challenge = "c";
        section = 0;
    } else {
        challenge = "";
        section = section_id;
    }
    sprintf(out, "%s%s%s%s%1d.rel", prefix, challenge, (drop_table_mode_flags & 2) ? "l" : "", names.n[game_difficulty_selection], section);
}

s32 TItemDrop::calc_drop_offset(s32 section) {
    s32 offset;

    offset = section + (game_difficulty_selection * 0xA);
    if (get_game_play_mode() == 1) {
        offset += 0x50;
    } else if (TLobby::get_instance() == 1) {
        offset += 0x28;
    }
    return offset;
}

void TItemDrop::apply_drop_restrictions(TItemData *it) {
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

s32 TItemDrop::is_not_special() {
    return (u8) (get_game_play_mode() != 1);
}

s32 TItemDrop::can_drop() {
    int enabled;

    enabled = 0;
    if ((get_game_play_mode() != 1) && (get_drop_flag() == 0)) {
        enabled = 1;
    }
    return (u8)enabled;
}

void TItemDrop::set_drop_index(TItemData *item) {
    item->data1.data_u8[5] = select_weighted_byte(common_probability_table->slot_count_weights, 0, 5, 1);
}

void TItemDrop::select_unit_drop(u8 stars, TItemData *item) {
    u32 n;
    s32 i;
    u32 pick;
    s32 r;
    u8 *data;
    s16 v;
    u8 cnt;
    if (stars >= 0xD) {
        return;
    }
    item->init();
    item->data1.data_u8[0] = 1;
    item->data1.data_u8[1] = 3;
    TItemDrop::init_drop_table();
    cnt = unit_star_bucket_counts[stars];
    if (cnt == 0) {
        return;
    }
    pick = roll_channel_below((s32)cnt, (u32)(0xB));
    n = 0;
    for (i = 0; i < 0x88; i++) {
        if (unit_star_classes[i] == stars) {
            if (n == pick) {
                if (i < 0x50) {
                    item->data1.data_u8[2] = i / 5;
                    r = (u8)(i % 5);
                    data = (u8 *)lookup_item_pmt_record(item->data1.data_u8);
                    if (data == NULL) {
                        return;
                    }
                    v = *(s16 *)(data + 0xC);
                    switch (r) {
                    case 0:
                        item->set_unit_modifier(-(v * 2));
                        break;
                    case 1:
                        item->set_unit_modifier(-v);
                        break;
                    case 2:
                        break;
                    case 3:
                        item->set_unit_modifier(v);
                        break;
                    case 4:
                        item->set_unit_modifier(v * 2);
                        break;
                    }
                } else if (stars < 0x88) {
                    item->data1.data_u8[2] = i - 0x40;
                }
                return;
            }
            n++;
        }
    }
}

void TItemDrop::init_drop_table() {
    s32 i;
    s8 above;
    u8 *out;
    u8 item_star_count;
    u8 below;
    u8 stars;

    i = 0;
    out = unit_star_classes;
    do {
        item_star_count = get_item_star_count(i + 0x2AF);
        stars = item_star_count;
        i += 1;
        below = stars - 1;
        out[0] = below;
        above = stars + 1;
        out[1] = below;
        out[2] = item_star_count;
        out[3] = above;
        out[4] = above;
        out += 5;
    } while (i != 0x10);
    while (i != 0x48) {
        *out = get_item_star_count(i + 0x2AF);
        out += 1;
        i += 1;
    }
}

void TItemDrop::count_unit_star_buckets() {
    s32 i;
    u8 v;
    memset(unit_star_bucket_counts, 0, 0xD);
    TItemDrop::init_drop_table();
    for (i = 0; i < 0x88; i++) {
        v = unit_star_classes[i];
        if (v < 0xD) {
            unit_star_bucket_counts[v]++;
        }
    }
}

void TItemDrop::refresh_drop_table_if_changed() {
    if (item_drop_cached_offset != TItemDrop::calc_drop_offset(leader_selection.get_section_id()) ||
        drop_table_mode_flags != get_drop_table_mode_flags()) {
        section_id = leader_selection.get_section_id();
        load_drop_tables();
    }
}

void TItemDrop::free_unit_star_tables() {
    mem_free((void *)unit_star_bucket_counts);
    unit_star_bucket_counts = 0;
    mem_free((void *)unit_star_classes);
    unit_star_classes = 0;
}

void TItemDrop::alloc_unit_star_tables() {
    unit_star_classes = (u8 *)mem_alloc(0x88);
    unit_star_bucket_counts = (u8 *)mem_alloc(0xD);
    TItemDrop::count_unit_star_buckets();
}

void TItemDrop::unload_drop_tables() {  }

void TItemDrop::load_drop_tables() {
    char path[0x48];
    item_drop_cached_offset = TItemDrop::calc_drop_offset(section_id);
    drop_table_mode_flags = get_drop_table_mode_flags();
    if (item_drop_cached_offset >= 0 && item_drop_cached_offset <= 0xA0) {
        open_gsl_archive("ItemPT.gsl");
        format_drop_table_filename(path, "ItemPT");
        common_probability_table = (ItemDropTable *)load_relocatable_file(path, relocatable_load_buffer);
        close_gsl_archive();
        open_gsl_archive("ItemRT.gsl");
        format_drop_table_filename(path, "ItemRT");
        rare_item_table_file = (ItemDropRareTable *)load_relocatable_file(path, second_relocatable_load_buffer);
        close_gsl_archive();
    }
}

f32 TItemDrop::roll_table_ratio(u32 channel) {
    if (channel < 0x10U) {
        return calc_random_ratio__10TObjPlayerFv(rngs[channel]);
    }
    return calc_random_ratio__10TObjPlayerFv(rngs[0x10]);
}

u32 TItemDrop::roll_channel_below(s32 count, u32 channel) {
    if (channel < 0x10U) {
        return (u32)item_drop_rng_below(rngs[channel], count);
    }
    return (u32)item_drop_rng_below(rngs[0x10], count);
}

void TItemDrop::select_enemy_drop(s32 enemy_type, s32 area, TItemData *item) {
    s32 r;
    u8 kind;
    if (item == NULL) {
        return;
    }
    item->init();
    if (enemy_type > 0x58) {
        return;
    }
    if (roll_channel_below(0x64, 0) >= common_probability_table->enemy_drop_chance[enemy_type]) {
        return;
    }
    if (drop_item(enemy_type, item) != 0) {
        return;
    }
    if (is_not_special() == 1) {
        r = roll_channel_below(3, 1);
    } else {
        r = roll_channel_below(2, 1) + 1;
    }
    switch (r) {
    case 0:
        kind = 5;
        break;
    case 1:
        kind = 4;
        break;
    case 2:
        kind = common_probability_table->enemy_drop_kind[enemy_type];
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
        item->data2.data_u32 = roll_meseta_range(common_probability_table->enemy_meseta, enemy_type, 0, 1);
        break;
    default:
        return;
    }
    if (item->data1.data_u8[0] != 4) {
        generate_drop_item(area, item);
    }
}

void TItemDrop::select_box_item(s32 area, TItemData *item) {
    if (item == NULL) {
        return;
    }
    item->init();
    if (select_rare_box_item(area, item) != 0) {
        return;
    }
    switch (select_weighted_byte(common_probability_table->box_kind_weights, area, 7, 0xA)) {
    case 0:
        item->data1.data_u8[0] = 0;
        break;
    case 1:
        item->data1.data_u8[0] = 1;
        item->data1.data_u8[1] = 1;
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
        break;
    default:
        return;
    }
    generate_drop_item(area, item);
}

void TItemDrop::generate_drop_item(s32 area, TItemData *item) {
    f32 f;
    if (item == NULL) {
        return;
    }
    switch (item->data1.data_u8[0]) {
    case 0:
        select_weapon_drop(area, item);
        break;
    case 1:
        if (item->data1.data_u8[1] == 3) {
            f = item_drop_one + (f32)common_probability_table->unit_max_stars[area];
            select_unit_drop((u8)(s32)(f * roll_table_ratio(0xE)), item);
            if (item->data1.data_u8[2] == 0xFF) {
                item->init();
            }
        } else {
            calc_drop_rarity(area, item);
        }
        break;
    case 3:
        generate_tool_drop(area, item);
        break;
    case 4:
        item->data2.data_u32 = roll_meseta_range(common_probability_table->box_meseta, area, 0, 1);
        break;
    case 2:
        apply_item_data(item);
        break;
    default:
        item->init();
        item->data1.data_u8[0] = 5;
        break;
    }
    apply_drop_restrictions(item);
    clear_item_if_player_picked_up(item);
}

s32 TItemDrop::select_rare_box_item(s32 area, TItemData *item) {
    s32 target;
    s32 i;
    if (rare_item_table_file != NULL && TItemDrop::can_drop() == 1) {
        target = area + 1;
        for (i = 0; i != rare_item_table_file->box_count; i++) {
            if (target == rare_item_table_file->box_areas[i]) {
                if (try_generate_rare_item(&rare_item_table_file->box_items[i], item) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 TItemDrop::drop_item(s32 enemy_type, TItemData *item) {
    if ((TItemDrop::can_drop() == 1) && (rare_item_table_file != NULL) && (enemy_type > 0) && (enemy_type < 0x58)) {
        return try_generate_rare_item(&rare_item_table_file->enemy_items[enemy_type], item);
    }
    return 0;
}

void TItemDrop::calc_drop_rarity(s32 area, TItemData *item) {
    u8 level;
    u8 bonus;

    roll_armor_bonuses(item);
    bonus = (u8) select_weighted_byte(common_probability_table->armor_level_weights, 0, 5, 1);
    item->data1.data_u8[2] = (u8) (area + bonus + common_probability_table->armor_level_bias);
    level = item->data1.data_u8[2];
    if (level < 3U) {
        item->data1.data_u8[2] = 0U;
    } else {
        item->data1.data_u8[2] = (level - 3);
    }
}

void TItemDrop::init_rare_item_data(TItemData *item) {
    if ((item->data1.data_u8[1] == 2) && ((item->data1.data_u8[4] >= 0x13U) || (item->data1.data_u8[2] >= 0x1EU))) {
        item->init();
    }
}

void TItemDrop::handle_type3(TItemData *item) {
    if (item->data1.data_u8[0] == 3) {
        item->set_stack_count(1);
    }
}

void TItemDrop::apply_item_data(TItemData *item) {
    s32 mag;

    if (item->data1.data_u8[0] == 2) {
        ((MagStats *)(&mag))->init();
        item->data1.data_u8[1] = 0;
        TItemData::serialize_mag(item, &mag);
    }
}

struct Def_80106D0C {
    u8 pad[0x16];
    u8 a;
    u8 b;
};

void TItemDrop::roll_armor_bonuses(TItemData *item) {
    Def_80106D0C *def;

    if (item->data1.data_u8[0] != 1) {
        return;
    }
    switch (item->data1.data_u8[1]) {
    case 1:
        set_drop_index(item);
    case 2:
        def = (Def_80106D0C *)lookup_item_pmt_record(item->data1.data_u8);
        if (def != NULL) {
            f32 r;
            r = roll_table_ratio(12);
            item->set_dfp_bonus((s16)(def->a * r));
            r = roll_table_ratio(13);
            item->set_bswapped_field_8((s16)(def->b * r));
        }
        break;
    }
}

void TItemDrop::roll_weapon_special(TItemData *item, s32 area) {
    u8 *stars;
    if (item->data1.data_u8[0] == 0 && TItemData::is_rare_item(item) == 0) {
        stars = common_probability_table->special_stars;
        if (stars[area] != 0 && roll_channel_below(100, 9) < common_probability_table->special_chance[area]) {
            item->data1.data_u8[4] = roll_weapon_special_for_stars((u8)(s32)((f32)stars[area] * roll_table_ratio(10)));
        }
    }
}

void TItemDrop::set_flag(TItemData *item) {
    u8 special;

    if ((TItemDrop::is_enabled() == 1) && (item->data1.data_u8[0] == 0)) {
        if (TItemData::is_rare_item(item) != 0) {
            item->data1.data_u8[4] = (u8) (item->data1.data_u8[4] | item_unidentified_flag);
            return;
        }
        special = item->data1.data_u8[4];
        if (special != 0) {
            item->data1.data_u8[4] = (u8) (special | item_unidentified_flag);
        }
    }
}

void TItemDrop::prune_weapon_attributes(TItemData *item) {
    s32 i;
    s32 j;
    for (i = 0; i != 3; i++) {
        for (j = 0; j != i; j++) {
            if (item->data1.data_u8_pair[3 + j][0] == 0) {
                item->data1.data_u8_pair[3 + i][0] = 0;
            } else if (item->data1.data_u8_pair[3 + i][0] == item->data1.data_u8_pair[3 + j][0]) {
                item->data1.data_u8_pair[3 + i][0] = 0;
            }
        }
        if (item->data1.data_u8_pair[3 + i][0] == 0) {
            item->data1.data_u8_pair[3 + i][1] = 0;
        }
    }
}

void TItemDrop::roll_rare_weapon_attributes(TItemData *item, s32 area) {
    s32 i;
    if (item->data1.data_u8[0] == 0) {
        for (i = 0; i != 3; i++) {
            item->data1.data_u8_pair[3 + i][0] = select_weighted_byte(common_probability_table->attribute_kind_weights, area, 6, 10);
            item->data1.data_u8_pair[3 + i][1] = (s8)select_weighted_column_u16(common_probability_table->attribute_value_weights, 5, 0x17, 6) * 5 - 10;
            if (item->data1.data_u8_pair[3 + i][0] == 5) {
                item->data1.data_u8_pair[3 + i][1] = (s8)item->data1.data_u8_pair[3 + i][1] / 5;
                item->data1.data_u8_pair[3 + i][1] = item->data1.data_u8_pair[3 + i][1] * 5;
            }
        }
        prune_weapon_attributes(item);
    }
}

void TItemDrop::build_weapon_type_weights(TItemData *item, s32 area) {
    s32 i;
    s32 row[1];

    if (item->data1.data_u8[0] == 0) {
        for (i = 0; i != 3; i++) {
            row[0] = common_probability_table->attribute_rows[i * 10 + area];
            if (row[0] != -1) {
                item->data1.data_u8_pair[3 + i][0] = select_weighted_byte(common_probability_table->attribute_kind_weights, area, 6, 10);
                item->data1.data_u8_pair[3 + i][1] = (s8)select_weighted_column_u16(common_probability_table->attribute_value_weights, row[0], 0x17, 6) * 5 - 10;
            }
            if (item->data1.data_u8_pair[3 + i][0] == 5) {
                item->data1.data_u8_pair[3 + i][1] = (s8)item->data1.data_u8_pair[3 + i][1] / 5;
                item->data1.data_u8_pair[3 + i][1] = item->data1.data_u8_pair[3 + i][1] * 5;
            }
        }
        prune_weapon_attributes(item);
    }
}

void TItemDrop::calc_drop_item(TItemData *item, s32 grind_column) {
    if (item->data1.data_u8[0] == 0) {
        item->data1.data_u8[3] = select_weighted_byte(common_probability_table->grind_weights, clamp_s32(grind_column, 0, 3), 9, 4);
    }
}

void TItemDrop::select_weapon_drop(s32 area, TItemData *item) {
  u8 w[13];
  s32 i;
  s32 v;
  u32 k;
  s8 off;
  u8 div;
  item->init();
  item->data1.data_u8[0] = 0;
  w[0] = 0;
  memcpy(&w[1], common_probability_table->weapon_kind_weights, 0xC);
  for (i = 1; i < 13; i++)
  {
    if ((area + common_probability_table->weapon_tier_bases[i - 1]) < 0)
    {
      w[i] = 0;
    }
  }
  item->data1.data_u8[1] = select_weighted_byte(w, 0, 0xD, 1);
  k = item->data1.data_u8[1];
  if (k == 0)
  {
    item->init();
    return;
  }
  {
    ItemDropTable *t = common_probability_table;
    div = t->weapon_tier_lengths[k - 1];
    off = t->weapon_tier_bases[k - 1];
  }
  if (off < 0)
  {
    v = area - (-off);
    item->data1.data_u8[2] = v / div;
    calc_drop_item(item, v % div);
  }
  else
  {
    item->data1.data_u8[2] = off + (area / ((s8) div));
    calc_drop_item(item, area % div);
  }
  build_weapon_type_weights(item, area);
  roll_weapon_special(item, area);
  set_flag(item);
}

#pragma push
#pragma fp_contract on
void TItemDrop::generate_tool_drop(s32 area, TItemData *item) {
    s32 tool;
    item->init();
    tool = select_weighted_column_u16(common_probability_table->tool_weights, area, 0x1C, 0xA);
    switch (tool) {
    case 0x1A:
        tool = 0x73;
        break;
    }
    find_tool_pmt_base_id(tool, item->data1.data_u8);
    if (item->data1.data_u8[1] == 2) {
        item->data1.data_u8[4] = select_weighted_byte(common_probability_table->technique_weights, area, 0x13, 0xA);
        item->data1.data_u8[2] = roll_technique_level(common_probability_table->technique_levels, item->data1.data_u8[4], area, 0xA);
        init_rare_item_data(item);
    }
    handle_type3(item);
}
#pragma pop

s32 TItemDrop::try_generate_rare_item(ItemDropRareEntry *entry, TItemData *item) {
    s32 exponent;
    u32 roll;
    u8 chance;
    u32 attribute_area;
    if ((entry != NULL) && (item != NULL)) {
        chance = entry->chance;
        if (chance != 0) {
            roll = roll_channel_below(-1, 6);
            exponent = ((chance >> 3U) & 0x1F) - 4;
            if (exponent < 0) {
                exponent = 0;
            }
            if (roll < (u32) ((2 << exponent) * ((chance & 7) + 7))) {
                item->data1.data_u8[0] = entry->type[0];
                item->data1.data_u8[1] = entry->type[1];
                item->data1.data_u8[2] = entry->type[2];
                switch ((s32) (item->data1.data_u8[0])) {
                case 0:
                    attribute_area = roll_channel_below(0xA, 7);
                    roll_rare_weapon_attributes(item, attribute_area);
                    set_flag(item);
                    break;
                case 1:
                    roll_armor_bonuses(item);
                    break;
                case 2:
                    apply_item_data(item);
                    break;
                case 3:
                    init_rare_item_data(item);
                    handle_type3(item);
                    break;
                }
                apply_drop_restrictions(item);
                clear_item_if_player_picked_up(item);
                return 1;
            }
        }
    }
    return 0;
}

u16 TItemDrop::roll_meseta_range(ItemDropMesetaRange *ranges, s32 row, s32 column, s32 stride) {
    u32 lo = ranges[column + row * stride].lo;
    u32 hi = ranges[column + row * stride].hi;
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

u8 TItemDrop::roll_technique_level(ItemDropLevelRange *ranges, s32 row, s32 column, s32 stride) {
    u32 lo = ranges[column + row * stride].lo;
    u32 hi = ranges[column + row * stride].hi;
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

u8 TItemDrop::select_weighted_column_u16(u16 *weights, s32 column, s32 count, s32 stride) {
    u32 total = 0;
    u32 r;
    u8 i;

    for (i = 0; i != count; i++) {
        total += weights[column + i * stride];
    }
    if (total == 0) {
        return 0xFF;
    }
    r = roll_channel_below((s32)total, (u32)(3));
    for (i = 0; i != count; i++) {
        u16 w = weights[column + i * stride];
        if (w != 0) {
            if (r < w) {
                return i;
            }
            r -= w;
        }
    }
    return 0xFF;
}

u8 TItemDrop::select_weighted_byte(u8 *weights, s32 column, s32 count, s32 stride) {
    u8 *p = weights + column;
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
    safe_free(relocatable_load_buffer);
    relocatable_load_buffer = 0;
    safe_free(second_relocatable_load_buffer);
    second_relocatable_load_buffer = 0;
    for (i = 0; i != 0x11; i++) {
        delete rngs[i];
    }
    mem_free(rngs);
    rngs = 0;
}

// The drop tables' resource set (the ctor hands it to create_load_unload_set):
// {load, unload} the drop tables, {allocate, free} the unit star tables.
ItemClassLoadUnloadEntry item_drop_load_unload_table[3] = {
    { TItemDrop::load_drop_tables, TItemDrop::unload_drop_tables },
    { TItemDrop::alloc_unit_star_tables, TItemDrop::free_unit_star_tables },
    { NULL, NULL },
};

TItemDrop::TItemDrop(TObject *parent, s8 section) : TObject(parent) {
    s32 i;
    u32 a;
    u32 b;
    m_name = item_drop_class_name;
    section_id = section;
    rngs = (SubtractiveRng **)mem_alloc(0x44);
    for (i = 0; i != 0x11; i++) {
        a = __cvt_fp2unsigned(item_drop_u32_scale * (item_drop_rand_reciprocal * (f32)rand()));
        b = __cvt_fp2unsigned(item_drop_u16_scale * (item_drop_rand_reciprocal * (f32)rand()));
        rngs[i] = new SubtractiveRng(a | b);
    }
    second_relocatable_load_buffer = TQuestVmDownLoadServer::alloc(0xC00);
    relocatable_load_buffer = TQuestVmDownLoadServer::alloc(0xC00);
    load_unload_set = create_load_unload_set(item_drop_load_unload_table);
}

TItemDrop *TItemDrop::create_drop(TObject *parent) {
    u8 section;
    TPlyCharData *char_data;
    char_data = TAdSinglePlyChrSelectGC::get_char_index(0U);
    if (char_data != NULL) {
        section = char_data->m_disp_part2.section_id;
        if (((s8) section >= 0) && ((s8) section < 0xA)) {
            return new TItemDrop(parent, (s8)section);
        }
    }
    return NULL;
}

s8 TItemDrop::get_bool_from_1d6ddc() { return (s8)(TLobby__sub_801D6DDC(this)); }

extern "C" u8 TItemDrop__sub_80107B04(void *) { return 0; }

s32 item_drop_rng_below(SubtractiveRng *rng, u32 count) {
    return __cvt_fp2unsigned((f32) (((f32) count * (f32) subtractive_rng_next(rng)) / item_drop_u32_scale));
}

__declspec(section ".sdata2") extern const f32 item_drop_u16_scale = 65536.0f;
__declspec(section ".sdata2") extern const f32 item_drop_u32_scale = 4294967296.0f;
__declspec(section ".sdata2") extern const f32 item_drop_one = 1.0f;
__declspec(section ".sdata2") extern const u8 item_unidentified_flag = 0x80;
__declspec(section ".sdata2") extern const f32 item_drop_rand_reciprocal = 3.0517578e-05f;
