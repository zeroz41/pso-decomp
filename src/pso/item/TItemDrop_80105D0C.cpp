#include "types.h"
#include "pso/system/memory.h"
#include "pso/item/TItemDrop.h"
#include "pso/TFontSmallTask.h"
#include "pso/item/TItemData.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TShopEquipmentListWindow.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct Item_80105EA4 { u8 type; u8 b1; u8 b2; };

struct Names_80105DB0 { char *n[4]; };

extern "C" {
s32 get_game_play_mode();
s32 get_drop_table_mode_flags(void);
void *memset(void *dst, int c, u32 n);
extern u8 *TItemDrop__unit_star_classes;
extern u8 *TItemDrop__unit_star_bucket_counts;
void TItemDrop__vt0(void);
extern u8 TLobby__data_805011D8[];
extern s32 item_drop_cached_offset;
extern s32 TItemDrop__drop_table_mode_flags;
extern s32 TItemDrop__section_id;
u8 can_drop__9TItemDropFv(void);
s8 get_bool_from_1d6ddc__9TItemDropFPv(void *p);
u8 TItemDrop__sub_80107B04(void *);
s32 is_rare_item__9TItemDataFPv(u8 *item);
s32 init__9TItemDataFv(void *);
u8 TLobby__sub_801D6F94(void *);
u8 TLobby__sub_801D6FFC(void *);
u8 fn_801D7168(void *);
u8 fn_801D719C(void *);
u8 fn_801D71D0(void *);
u8 fn_801D7204(void *);
extern s32 lobby_rule_settings[];
void apply_drop_restrictions(s32 arg0, Item_80105EA4 *it);
s32 sprintf(void *, void *, ...);
extern Names_80105DB0 item_drop_difficulty_name_table;
extern char lbl_8043E0E4[];
extern s32 game_difficulty_selection;
extern char lbl_805DAAC8;
extern char lbl_805DAACC;
extern char lbl_805DAAD0;
void format_drop_table_filename(void *out, s32 arg1);
u32 roll_channel_below__9TItemDropFPviUi(u8 *arg0, s32 count, u32 arg2);
void *lookup_item_pmt_record(u8 *item);
void TItemDrop__sub_80105D10(void);
u8 is_enabled__9TItemDropFv(void);
u8 is_not_special__9TItemDropFv(void);
s8 select_weighted_byte__9TItemDropFiiiii(s32, s32, s32, s32, s32);
s32 get_item_star_count(s32 id);
}
void unload_item_drop_globals(void);
s32 is_unsealable_item(u8 *id);
void unload_item_drop_globals(void) {  }

    extern int item_desync_detected;

void TItemDrop__sub_80105D10(void) { item_desync_detected = 0; }

void TItemDrop::clear_item_if_player_picked_up(void* p, void* a1) { if (is_unsealable_item((u8 *)a1) == 1) { ((TItemData *)a1)->set_packed_value((u16)((void*)0)); } }

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

void format_drop_table_filename(void *out, s32 arg1) {
    Names_80105DB0 names = item_drop_difficulty_name_table;
    char *s1;
    char *s2;
    s32 n;
    if (TItemDrop__drop_table_mode_flags & 1) {
        s1 = &lbl_805DAAC8;
        n = 0;
    } else {
        s1 = &lbl_805DAACC;
        n = TItemDrop__section_id;
    }
    sprintf(out, lbl_8043E0E4, arg1, s1, (TItemDrop__drop_table_mode_flags & 2) ? &lbl_805DAAD0 : &lbl_805DAACC, names.n[game_difficulty_selection], n);
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

void apply_drop_restrictions(s32 arg0, Item_80105EA4 *it) {
    void *p;
    u8 m;
    u8 t;
    if (it == NULL) {
        return;
    }
    if (((s32 (*)(void))can_drop__9TItemDropFv)() == 0 && is_rare_item__9TItemDataFPv((u8 *)it) != 0) {
        init__9TItemDataFv(it);
        return;
    }
    if (get_game_play_mode() == 1) {
        if (it->type == 1) {
            if (it->b1 == 3) {
                if ((u8)*(s8 *)((s8 *)it + 2) >= 0x33 && (u8)*(s8 *)((s8 *)it + 2) <= 0x38) {
                    init__9TItemDataFv(it);
                }
            }
        } else if (it->type == 4) {
            init__9TItemDataFv(it);
        }
    }
    p = lobby_rule_settings;
    if (((TLobby *)lobby_rule_settings)->get_rule_field_0() == TItemDrop__sub_80107B04(p)) {
        return;
    }
    if (it->type == 0 || it->type == 1) {
        switch (fn_801D71D0(p)) {
        case 2:
            init__9TItemDataFv(it);
            return;
        case 3:
            if (is_rare_item__9TItemDataFPv((u8 *)it) == 1) {
                init__9TItemDataFv(it);
            }
            return;
        }
    }
    if (it->type == 2) {
        if (fn_801D719C(p) == 1) {
            init__9TItemDataFv(it);
        }
    } else if (it->type == 3) {
        if (fn_801D7168(p) == 2) {
            init__9TItemDataFv(it);
        } else if (it->b1 == 2) {
            switch (fn_801D7204(p)) {
            case 0:
                return;
            case 1:
                init__9TItemDataFv(it);
                break;
            default:
                m = get_bool_from_1d6ddc__9TItemDropFPv(p);
                if (m != 0) {
                    it->b2 = it->b2 % m;
                } else {
                    it->b2 = 0;
                }
                break;
            }
        } else if (it->b1 == 9) {
            if (TLobby__sub_801D6F94(p) == 1) {
                init__9TItemDataFv(it);
                return;
            }
            return;
        }
    } else if (it->type == 4) {
        if (TLobby__sub_801D6FFC(p) == 1) {
            init__9TItemDataFv(it);
        }
    }
}

u8 is_enabled__9TItemDropFv(void) {
    return (u8) (get_game_play_mode() != 1);
}

u8 is_not_special__9TItemDropFv(void) {
    return (u8) (get_game_play_mode() != 1);
}

u8 can_drop__9TItemDropFv(void) {
    int var_r31;

    var_r31 = 0;
    if ((get_game_play_mode() != 1) && (TLobby::get_drop_flag() == 0)) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}

extern void *TItemDrop__common_probability_table;

void TItemDrop::set_drop_index(void *rng, void *arg1) {
    *(s8 *)((s8 *)arg1 + 5) = select_weighted_byte__9TItemDropFiiiii((s32)rng, *(s32 *)((s8 *)TItemDrop__common_probability_table + 0x14), 0, 5, 1);
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
    init__9TItemDataFv(item);
    item[0] = 1;
    item[1] = 3;
    TItemDrop::init_drop_table();
    cnt = TItemDrop__unit_star_bucket_counts[kind];
    if (cnt == 0) {
        return;
    }
    pick = roll_channel_below__9TItemDropFPviUi((u8 *)this, (s32)cnt, (u32)(0xB));
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
    s32 var_r31;
    s8 temp_r0;
    u8 *var_r30;
    u8 item_star_count;
    u8 temp_r4;
    u8 temp_r5;

    var_r31 = 0;
    var_r30 = TItemDrop__unit_star_classes;
    do {
        item_star_count = get_item_star_count(var_r31 + 0x2AF);
        temp_r5 = item_star_count;
        var_r31 += 1;
        temp_r4 = temp_r5 - 1;
        *(u8 *)((s8 *)var_r30 + 0) = temp_r4;
        temp_r0 = temp_r5 + 1;
        *(u8 *)((s8 *)var_r30 + 1) = temp_r4;
        *(u8 *)((s8 *)var_r30 + 2) = item_star_count;
        *(s8 *)((s8 *)var_r30 + 3) = temp_r0;
        *(s8 *)((s8 *)var_r30 + 4) = temp_r0;
        var_r30 += 5;
    } while (var_r31 != 0x10);
    while (var_r31 != 0x48) {
        *var_r30 = get_item_star_count(var_r31 + 0x2AF);
        var_r30 += 1;
        var_r31 += 1;
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
    if (item_drop_cached_offset != TItemDrop::calc_drop_offset(((TFontSmallTask *)TLobby__data_805011D8)->get_task_id()) ||
        TItemDrop__drop_table_mode_flags != get_drop_table_mode_flags()) {
        TItemDrop__section_id = ((TFontSmallTask *)TLobby__data_805011D8)->get_task_id();
        TItemDrop__vt0();
    }
}

#pragma push
namespace P1_80105D0C {

struct RecoveredGlobal_80107840_lbl_8049EF88
{
  s32 value;
  u8 remaining[0x14];
};

struct Pair_80106F4C { u8 type; u8 level; };

struct Obj_80106F4C { u8 pad[6]; Pair_80106F4C e[3]; };

struct RareItem_80106A90 { u8 b[4]; };

struct RareTable_80106A90 { u8 pad[4]; s32 count; s8 *types; RareItem_80106A90 *items; };

struct Tbl_80106E04 {
    u8 pad[0x34];
    u8 *chance;
    u8 *rate;
};

struct TItemDrop_80107900 {
    s32 name;
    u8 pad4[0x14];
    void *vt;
    s32 unk1C;
    s32 *list;
};

struct Item_8010663C { u8 type; u8 sub; u8 pad2[0xE]; u32 id; };

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
s32 apply_drop_restrictions(void *, void *);
void init_rare_item_data__9TItemDropFPvPv(void *arg0, void *arg1);
void handle_type3__9TItemDropFPvPv(void* p, void* a1);
void apply_item_data__9TItemDropFPvPv(void *arg0, void *arg1);
void roll_armor_bonuses__9TItemDropFv(s32, void *);
void set_flag__9TItemDropFPvPv(void *arg0, void *arg1);
s32 try_generate_rare_item__9TItemDropFiPvPv(s32 arg0, u8 *arg1, u8 *arg2);
void init_rare_item_data__9TItemDropFPvPv(void *arg0, void *arg1);
void handle_type3__9TItemDropFPvPv(void* p, void* a1);
u8 roll_technique_level__9TItemDropFv(s32 self, s32 table, s32 row, s32 col, s32 stride);
u8 select_weighted_column_u16__9TItemDropFiiiii(s32, s32, s32, s32, s32);
s32 init__9TItemDataFv(void *);
s32 find_tool_pmt_base_id(u8, void *);
extern void *TItemDrop__common_probability_table;
void generate_tool_drop__9TItemDropFiiPv(s32 arg0, s32 arg1, void *arg2);
s32 get_char_index__23TAdSinglePlyChrSelectGCFUi(u32);
u8 *__nw__7TObjectFUl(s32);
u8 *create_drop__9TItemDropFi(s32 arg0);
u32 subtractive_rng_next(void *);
s32 __cvt_fp2unsigned(f32);
extern const f32 lbl_805DAAD8;
s32 item_drop_rng_below(s32 arg0, u32 arg1);
u32 roll_channel_below__9TItemDropFPviUi(u8 *arg0, s32 arg1, u32 arg2);
s32 calc_random_ratio__10TObjPlayerFv(void *);
void roll_table_ratio__9TItemDropFPvUi(u8 *arg0, u32 arg1);
s32 __dt__7TObjectFv(void *, int);
void *TItemDrop__sub_8010F168(void *arg0, s16 arg1);
void mem_free(void *p);
s32 __dl__7TObjectFPv(void *);
extern RecoveredGlobal_80107840_lbl_8049EF88 lbl_8049EF88;
extern s32 TItemDrop__relocatable_load_buffer;
extern s32 TItemDrop__second_relocatable_load_buffer;
u8 *TItemDrop__sub_80107840(u8 *arg0, s16 arg1);
u32 roll_channel_below__9TItemDropFPviUi(u8 *arg0, s32 arg1, u32 arg2);
u8 select_weighted_byte__9TItemDropFiiiii(s32 rng, s32 base, s32 off, s32 count, s32 stride);
void prune_weapon_attributes__9TItemDropFPvPv(void *self, Obj_80106F4C *o);
s32 can_drop__9TItemDropFv();
s32 try_generate_rare_item__9TItemDropFiPvPv(s32 arg0, u8 *arg1, u8 *arg2);
extern s32 *TItemDrop__rare_item_table_file;
s32 select_rare_box_item__9TItemDropFiiPv(s32 arg0, s32 arg1, u8 *arg2);
void roll_table_ratio__9TItemDropFPvUi(u8 *arg0, u32 arg1);
u32 roll_channel_below__9TItemDropFPviUi(u8 *arg0, s32 arg1, u32 arg2);
s32 is_rare_item__9TItemDataFPv(u8 *item);
u8 roll_weapon_special_for_stars(u8);
extern void *TItemDrop__common_probability_table;
void roll_weapon_special__9TItemDropFiPvi(s32 rng, u8 *item, s32 idx);
s32 apply_drop_restrictions(void *, void *);
void roll_table_ratio__9TItemDropFPvUi(u8 *arg0, u32 arg1);
void calc_drop_rarity__9TItemDropFiiPv(s32 arg0, s32 arg1, void *arg2);
void apply_item_data__9TItemDropFPvPv(void *arg0, void *arg1);
void generate_tool_drop__9TItemDropFiiPv(s32 arg0, s32 arg1, void *arg2);
s32 init__9TItemDataFv(void *);
extern void *TItemDrop__common_probability_table;
extern const f32 lbl_805DAADC;
void generate_drop_item__9TItemDropFPviPv(u8 *self, s32 idx, u8 *item);
s32 run_step__9TItemDropFl(s32, u32);
s32 fn_8010F210(void *);
void *mem_alloc(u32 size);
void __ct__7TObjectFP7TObject(void *, void *);
s32 __cvt_fp2unsigned(f32);
s32 rand();
extern s32 __vt__9TItemDrop[];
extern RecoveredGlobal_80107840_lbl_8049EF88 lbl_8049EF88;
extern s32 item_drop_class_name;
extern s32 TItemDrop__relocatable_load_buffer;
extern s32 TItemDrop__second_relocatable_load_buffer;
extern s32 TItemDrop__section_id;
extern const f32 lbl_805DAAD4;
extern const f32 lbl_805DAAD8;
extern const f32 lbl_805DAAE4;
TItemDrop_80107900 *TItemDrop__ct(TItemDrop_80107900 *self, void *parent, s8 arg2);
s32 is_not_special__9TItemDropFv(u8 *);
u32 roll_channel_below__9TItemDropFPviUi(u8 *arg0, s32 arg1, u32 arg2);
void generate_drop_item__9TItemDropFPviPv(u8 *self, s32 idx, u8 *item);
s32 drop_item__9TItemDropFiii(s32 arg0, s32 arg1, s32 arg2);
s32 init__9TItemDataFv(void *);
extern void *TItemDrop__common_probability_table;
void select_enemy_drop__9TItemDropFPviiPv(u8 *self, s32 area, s32 idx, Item_8010663C *item);
void generate_drop_item__9TItemDropFPviPv(u8 *self, s32 idx, u8 *item);
s32 select_rare_box_item__9TItemDropFiiPv(s32 arg0, s32 arg1, u8 *arg2);
u8 select_weighted_byte__9TItemDropFiiiii(s32 rng, s32 base, s32 off, s32 count, s32 stride);
s32 init__9TItemDataFv(void *);
extern void *TItemDrop__common_probability_table;
void select_box_item__9TItemDropFiiPv(s32 arg0, s32 arg1, u8 *arg2);
void prune_weapon_attributes__9TItemDropFPvPv(void *self, Obj_80106F4C *o);
u8 select_weighted_column_u16__9TItemDropFiiiii(s32 rng, s32 base, s32 off, s32 count, s32 stride);
u8 select_weighted_byte__9TItemDropFiiiii(s32 rng, s32 base, s32 off, s32 count, s32 stride);
extern void *TItemDrop__common_probability_table;
void roll_rare_weapon_attributes__9TItemDropFiPvi(s32 rng, Obj_80106F4C *item, s32 idx);
u32 roll_channel_below__9TItemDropFPviUi(u8 *arg0, s32 arg1, u32 arg2);
u16 roll_meseta_range__9TItemDropFPviiii(void *self, s32 arg1, s32 a, s32 b, s32 c);
void roll_weapon_special__9TItemDropFiPvi(s32 rng, u8 *item, s32 idx);
void set_flag__9TItemDropFPvPv(void *arg0, void *arg1);
void build_weapon_type_weights__9TItemDropFiPvi(s32 rng, Obj_80106F4C *item, s32 idx);
void calc_drop_item__9TItemDropFiPvi(s32 arg0, void *arg1, s32 arg2);
u8 select_weighted_byte__9TItemDropFiiiii(s32 rng, s32 base, s32 off, s32 count, s32 stride);
s32 init__9TItemDataFv(void *);
void *memcpy(void *, const void *, u32);
extern void *TItemDrop__common_probability_table;
void select_weapon_drop__9TItemDropFv(s32 rng, s32 level, u8 *item);
void *load_relocatable_file(char *, s32);
void close_gsl_archive(void);
void open_gsl_archive(char *);
s32 get_drop_table_mode_flags(void);
void format_drop_table_filename(char *, char *);
extern char lbl_8043E0F4[];
extern char lbl_8043E100[];
extern char lbl_8043E108[];
extern char lbl_8043E114[];
extern s32 item_drop_cached_offset;
extern s32 TItemDrop__relocatable_load_buffer;
extern s32 TItemDrop__second_relocatable_load_buffer;
extern void *TItemDrop__common_probability_table;
extern s32 *TItemDrop__rare_item_table_file;
extern s32 TItemDrop__drop_table_mode_flags;
extern s32 TItemDrop__section_id;
void TItemDrop__vt0(void);
int TItemDrop__sub_80107B04(void);
void TItemDrop__vt1(void);
void __dt__9TItemDropFv(void);
void apply_item_data__9TItemDropFPvPv(void *arg0, void *arg1);
void calc_drop_item__9TItemDropFiPvi(s32 arg0, void *arg1, s32 arg2);
void calc_drop_rarity__9TItemDropFiiPv(s32 arg0, s32 arg1, void *arg2);
s32 drop_item__9TItemDropFiii(s32 arg0, s32 arg1, s32 arg2);
s8 get_bool_from_1d6ddc__9TItemDropFPv(void* p);
void handle_type3__9TItemDropFPvPv(void* p, void* a1);
void init_rare_item_data__9TItemDropFPvPv(void *arg0, void *arg1);
void run_task__9TItemDropFv(void);
void set_flag__9TItemDropFPvPv(void *arg0, void *arg1);
s32 serialize_mag__9TItemDataFPvPv(void *, s32 *);
s32 is_rare_item__9TItemDataFPv(u8 *item);
void roll_armor_bonuses__9TItemDropFv(s32, void *);
u8 TLobby__sub_801D6DDC(void *arg0);
void *mem_alloc(u32 size);
s32 can_drop__9TItemDropFv();
void mem_free(void *p);
s32 init__9TItemDataFv(void *);
s32 is_enabled__9TItemDropFv();

extern s32 TItemDrop__unit_star_classes;
extern s32 TItemDrop__unit_star_bucket_counts;

void run_task__9TItemDropFv(void) {
    mem_free((void *)TItemDrop__unit_star_bucket_counts);
    TItemDrop__unit_star_bucket_counts = 0;
    mem_free((void *)TItemDrop__unit_star_classes);
    TItemDrop__unit_star_classes = 0;
}

extern s32 TItemDrop__unit_star_classes;
extern s32 TItemDrop__unit_star_bucket_counts;

void __dt__9TItemDropFv(void) {
    TItemDrop__unit_star_classes = (s32)mem_alloc(0x88);
    TItemDrop__unit_star_bucket_counts = (s32)mem_alloc(0xD);
    TItemDrop::count_unit_star_buckets();
}

void TItemDrop__vt1(void) {  }

extern s32 *TItemDrop__rare_item_table_file;

void TItemDrop__vt0(void) {
    char path[0x48];
    item_drop_cached_offset = TItemDrop::calc_drop_offset(TItemDrop__section_id);
    TItemDrop__drop_table_mode_flags = get_drop_table_mode_flags();
    if (item_drop_cached_offset >= 0 && item_drop_cached_offset <= 0xA0) {
        open_gsl_archive(lbl_8043E0F4);
        format_drop_table_filename(path, lbl_8043E100);
        TItemDrop__common_probability_table = load_relocatable_file(path, TItemDrop__relocatable_load_buffer);
        close_gsl_archive();
        open_gsl_archive(lbl_8043E108);
        format_drop_table_filename(path, lbl_8043E114);
        TItemDrop__rare_item_table_file = (s32 *)load_relocatable_file(path, TItemDrop__second_relocatable_load_buffer);
        close_gsl_archive();
    }
}

void roll_table_ratio__9TItemDropFPvUi(u8 *arg0, u32 arg1) {
    if (arg1 < 0x10U) {
        calc_random_ratio__10TObjPlayerFv((void *) (*(s32 *)((s8 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x20)) + (arg1 * 4)) + 0)));
        return;
    }
    calc_random_ratio__10TObjPlayerFv((void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x20)) + 0x40)));
}

u32 roll_channel_below__9TItemDropFPviUi(u8 *arg0, s32 count, u32 arg2) {
    u8 *var_r3;
    if (arg2 < 0x10U) {
        var_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x20));
        var_r3 = (u8 *)(*(s32 *)((s8 *)var_r3 + (arg2 * 4)));
        return (u32)item_drop_rng_below((s32)var_r3, count);
    }
    var_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x20));
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x40));
    return (u32)item_drop_rng_below((s32)var_r3, count);
}

void select_enemy_drop__9TItemDropFPviiPv(u8 *self, s32 area, s32 idx, Item_8010663C *item) {
    s32 r;
    u8 kind;
    if (item == NULL) {
        return;
    }
    init__9TItemDataFv(item);
    if (area > 0x58) {
        return;
    }
    if (roll_channel_below__9TItemDropFPviUi(self, 0x64, 0) >= ((Tbl_8010663C *)TItemDrop__common_probability_table)->chance[area]) {
        return;
    }
    if (drop_item__9TItemDropFiii((s32)self, area, (s32)item) != 0) {
        return;
    }
    if (is_not_special__9TItemDropFv(self) == 1) {
        r = roll_channel_below__9TItemDropFPviUi(self, 3, 1);
    } else {
        r = roll_channel_below__9TItemDropFPviUi(self, 2, 1) + 1;
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
        item->type = 0;
        break;
    case 1:
        item->sub = item->type = 1;
        break;
    case 2:
        item->type = 1;
        item->sub = 2;
        break;
    case 3:
        item->type = 1;
        item->sub = 3;
        break;
    case 4:
        item->type = 3;
        break;
    case 5:
        item->type = 4;
        item->id = roll_meseta_range__9TItemDropFPviiii(self, (s32)(((Tbl_8010663C *)TItemDrop__common_probability_table)->f18), area, 0, 1);
        break;
    default:
        return;
    }
    if (item->type != 4) {
        generate_drop_item__9TItemDropFPviPv(self, idx, (u8 *)item);
    }
}

void select_box_item__9TItemDropFiiPv(s32 arg0, s32 arg1, u8 *item) {
    if (item == NULL) {
        return;
    }
    init__9TItemDataFv(item);
    if (select_rare_box_item__9TItemDropFiiPv(arg0, arg1, item) != 0) {
        return;
    }
    switch (select_weighted_byte__9TItemDropFiiiii(arg0, *(s32 *)((s8 *)TItemDrop__common_probability_table + 0x50), arg1, 7, 0xA)) {
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
    generate_drop_item__9TItemDropFPviPv((u8 *)arg0, arg1, item);
}

void generate_drop_item__9TItemDropFPviPv(u8 *self, s32 idx, u8 *item) {
    f32 f;
    if (item == NULL) {
        return;
    }
    switch (item[0]) {
    case 0:
        select_weapon_drop__9TItemDropFv((s32)((s32)self), idx, item);
        break;
    case 1:
        if (item[1] == 3) {
            f = lbl_805DAADC + (f32)(*(u8 **)((u8 *)TItemDrop__common_probability_table + 0x4C))[idx];
            ((TItemDrop *)self)->select_unit_drop((u8)(s32)(f * ((f32 (*)(u8 *, u32))roll_table_ratio__9TItemDropFPvUi)(self, 0xE)), item);
            if (item[2] == 0xFF) {
                init__9TItemDataFv(item);
            }
        } else {
            calc_drop_rarity__9TItemDropFiiPv((s32)self, idx, item);
        }
        break;
    case 3:
        generate_tool_drop__9TItemDropFiiPv((s32)self, idx, item);
        break;
    case 4:
        *(u32 *)(item + 0x10) = roll_meseta_range__9TItemDropFPviiii(self, (s32)(*(s32 *)((u8 *)TItemDrop__common_probability_table + 0x24)), idx, 0, 1);
        break;
    case 2:
        apply_item_data__9TItemDropFPvPv(self, item);
        break;
    default:
        init__9TItemDataFv(item);
        item[0] = 5;
        break;
    }
    apply_drop_restrictions(self, item);
    TItemDrop::clear_item_if_player_picked_up(self, item);
}

s32 select_rare_box_item__9TItemDropFiiPv(s32 arg0, s32 arg1, u8 *arg2) {
    s32 target;
    s32 i;
    if ((*(RareTable_80106A90 * *)&TItemDrop__rare_item_table_file) != NULL && can_drop__9TItemDropFv() == 1) {
        target = arg1 + 1;
        for (i = 0; i != (*(RareTable_80106A90 * *)&TItemDrop__rare_item_table_file)->count; i++) {
            if (target == (*(RareTable_80106A90 * *)&TItemDrop__rare_item_table_file)->types[i]) {
                if (try_generate_rare_item__9TItemDropFiPvPv(arg0, (u8 *)&(*(RareTable_80106A90 * *)&TItemDrop__rare_item_table_file)->items[i], arg2) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 drop_item__9TItemDropFiii(s32 arg0, s32 arg1, s32 arg2) {
    if ((can_drop__9TItemDropFv() == 1) && ((s32 *) TItemDrop__rare_item_table_file != NULL) && (arg1 > 0) && (arg1 < 0x58)) {
        return try_generate_rare_item__9TItemDropFiPvPv((s32)arg0, (u8 *)(*TItemDrop__rare_item_table_file + (arg1 * 4)), (u8 *)arg2);
    }
    return 0;
}

extern void *TItemDrop__common_probability_table;

void calc_drop_rarity__9TItemDropFiiPv(s32 rng, s32 arg1, void *item_) {
    u8 temp_r3;
    u8 call_res;

    roll_armor_bonuses__9TItemDropFv(rng, item_);
    call_res = (u8) select_weighted_byte__9TItemDropFiiiii(rng, (s32)((s32)(*(s32 *)((s8 *)TItemDrop__common_probability_table + 0x10))), 0, 5, 1);
    *(u8 *)((s8 *)item_ + 2) = (u8) (arg1 + call_res + *(u8 *)((s8 *)TItemDrop__common_probability_table + 0x48));
    temp_r3 = *(u8 *)((s8 *)item_ + 2);
    if (temp_r3 < 3U) {
        *(u8 *)((s8 *)item_ + 2) = 0U;
    } else {
        *(u8 *)((s8 *)item_ + 2) = (temp_r3 - 3);
    }
}

void init_rare_item_data__9TItemDropFPvPv(void *arg0, void *item_data) {
    if (((u8) *(u8 *)((s8 *)item_data + 1) == 2) && (((u8) *(u8 *)((s8 *)item_data + 4) >= 0x13U) || ((u8) *(u8 *)((s8 *)item_data + 2) >= 0x1EU))) {
        init__9TItemDataFv(item_data);
    }
}

void handle_type3__9TItemDropFPvPv(void* p, void* a1) { if (*(unsigned char*)(a1) == 3) { ((TItemData *)a1)->set_stack_count(1); } }

void apply_item_data__9TItemDropFPvPv(void *arg0, void *item) {
    s32 sp8;

    if ((u8) *(u8 *)((s8 *)item + 0) == 2) {
        ((TItemData *)(&sp8))->initialize_mag_data();
        *(s8 *)((s8 *)item + 1) = 0;
        serialize_mag__9TItemDataFPvPv(item, &sp8);
    }
}

struct Def_80106D0C {
    u8 pad[0x16];
    u8 a;
    u8 b;
};
void *lookup_item_pmt_record(u8 *item);
void set_dfp_bonus__9TItemDataFs(u8 *, s32);
void set_bswapped_field_8__9TItemDataFs(u8 *, s32);

#define item ((u8 *)item_)
void roll_armor_bonuses__9TItemDropFv(s32 rng, void *item_) {
    Def_80106D0C *def;

    if (item[0] != 1) {
        return;
    }
    switch (item[1]) {
    case 1:
        TItemDrop::set_drop_index((void *)rng, item);
    case 2:
        def = (P1_80105D0C::Def_80106D0C *)lookup_item_pmt_record(item);
        if (def != NULL) {
            f32 r;
            r = ((f32 (*)(u8 *, u32))roll_table_ratio__9TItemDropFPvUi)((u8 *)rng, 12);
            set_dfp_bonus__9TItemDataFs(item, (s32)(def->a * r));
            r = ((f32 (*)(u8 *, u32))roll_table_ratio__9TItemDropFPvUi)((u8 *)rng, 13);
            set_bswapped_field_8__9TItemDataFs(item, (s32)(def->b * r));
        }
        break;
    }
}
#undef item

extern u8 lbl_805DAAE0;

void roll_weapon_special__9TItemDropFiPvi(s32 rng, u8 *item, s32 idx) {
    u8 *chance;
    if (item[0] == 0 && is_rare_item__9TItemDataFPv(item) == 0) {
        chance = ((Tbl_80106E04 *)TItemDrop__common_probability_table)->chance;
        if (chance[idx] != 0 && roll_channel_below__9TItemDropFPviUi(((u8 *)rng), 100, 9) < ((Tbl_80106E04 *)TItemDrop__common_probability_table)->rate[idx]) {
            item[4] = roll_weapon_special_for_stars((u8)(s32)((f32)chance[idx] * ((f32 (*)(u8 *, u32)) roll_table_ratio__9TItemDropFPvUi)((u8 *)rng, 10)));
        }
    }
}

void set_flag__9TItemDropFPvPv(void *arg0, void *item) {
    u8 temp_r3;

    if ((is_enabled__9TItemDropFv() == 1) && ((u8) *(u8 *)((s8 *)item + 0) == 0)) {
        if (is_rare_item__9TItemDataFPv((u8 *)item) != 0) {
            *(u8 *)((s8 *)item + 4) = (u8) (*(u8 *)((s8 *)item + 4) | lbl_805DAAE0);
            return;
        }
        temp_r3 = *(u8 *)((s8 *)item + 4);
        if (temp_r3 != 0) {
            *(u8 *)((s8 *)item + 4) = (u8) (temp_r3 | lbl_805DAAE0);
        }
    }
}

extern void *TItemDrop__common_probability_table;

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

void roll_rare_weapon_attributes__9TItemDropFiPvi(s32 rng, Obj_80106F4C *item, s32 idx) {
    s32 i;
    if (item->pad[0] == 0) {
        for (i = 0; i != 3; i++) {
            item->e[i].type = select_weighted_byte__9TItemDropFiiiii(rng, ((Tbl_80106FC8 *)TItemDrop__common_probability_table)->types, idx, 6, 10);
            item->e[i].level = (s8)select_weighted_column_u16__9TItemDropFiiiii(rng, ((Tbl_80106FC8 *)TItemDrop__common_probability_table)->levels, 5, 0x17, 6) * 5 - 10;
            if (item->e[i].type == 5) {
                item->e[i].level = (s8)item->e[i].level / 5;
                item->e[i].level = item->e[i].level * 5;
            }
        }
        prune_weapon_attributes__9TItemDropFPvPv((void *)rng, item);
    }
}

void build_weapon_type_weights__9TItemDropFiPvi(s32 rng, Obj_80106F4C *item, s32 idx) {
    s32 i;
    s32 kind[1];

    if (item->pad[0] == 0) {
        for (i = 0; i != 3; i++) {
            kind[0] = ((Tbl_801070A4 *)TItemDrop__common_probability_table)->kinds[i * 10 + idx];
            if (kind[0] != -1) {
                item->e[i].type = select_weighted_byte__9TItemDropFiiiii(rng, ((Tbl_801070A4 *)TItemDrop__common_probability_table)->types, idx, 6, 10);
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

void calc_drop_item__9TItemDropFiPvi(s32 rng, void *arg1, s32 arg2) {
    if ((u8) *(u8 *)((s8 *)arg1 + 0) == 0) {
        *(s8 *)((s8 *)arg1 + 3) = select_weighted_byte__9TItemDropFiiiii(rng, (s32)((s32)(*(s32 *)((s8 *)TItemDrop__common_probability_table + 0xC))), (s32)((s32)(clamp_s32(arg2, 0, 3))), 9, 4);
    }
}

typedef struct Tbl_80107210 Tbl_80107210;
void select_weapon_drop__9TItemDropFv(s32 rng, s32 level, u8 *item) {
  u8 w[13];
  s32 i;
  s32 v;
  u32 k;
  s8 off;
  u8 div;
  init__9TItemDataFv(item);
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
  item[1] = select_weighted_byte__9TItemDropFiiiii(rng, (s32) w, 0, 0xD, 1);
  k = item[1];
  if (k == 0)
  {
    init__9TItemDataFv(item);
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
    calc_drop_item__9TItemDropFiPvi(rng, item, v % div);
  }
  else
  {
    item[2] = off + (level / ((s8) div));
    calc_drop_item__9TItemDropFiPvi(rng, item, level % div);
  }
  build_weapon_type_weights__9TItemDropFiPvi(rng, (Obj_80106F4C *)(item), level);
  roll_weapon_special__9TItemDropFiPvi(rng, item, level);
  set_flag__9TItemDropFPvPv((void *) rng, item);
}

#pragma push
#pragma fp_contract on
void generate_tool_drop__9TItemDropFiiPv(s32 arg0, s32 off, void *arg2) {
    u8 var_r3;
    init__9TItemDataFv(arg2);
    var_r3 = ((s32 (*)(s32, s32, s32, s32, s32))select_weighted_column_u16__9TItemDropFiiiii)(arg0, *(s32 *)((s8 *)TItemDrop__common_probability_table + 0x3C), off, 0x1C, 0xA);
    switch (var_r3) {
    case 0x1A:
        var_r3 = 0x73;
        break;
    }
    find_tool_pmt_base_id(var_r3, arg2);
    if ((u8) *(u8 *)((s8 *)arg2 + 1) == 2) {
        *(u8 *)((s8 *)arg2 + 4) = ((u8)select_weighted_byte__9TItemDropFiiiii(arg0, (s32)(*(s32 *)((s8 *)TItemDrop__common_probability_table + 0x40)), off, 0x13, 0xA));
        *(s8 *)((s8 *)arg2 + 2) = roll_technique_level__9TItemDropFv(arg0, *(s32 *)((s8 *)TItemDrop__common_probability_table + 0x44), *(u8 *)((s8 *)arg2 + 4), off, 0xA);
        init_rare_item_data__9TItemDropFPvPv((void *)arg0, (void *)arg2);
    }
    handle_type3__9TItemDropFPvPv((void*)arg0, (void*)arg2);
}
#pragma pop

s32 try_generate_rare_item__9TItemDropFiPvPv(s32 arg0, u8 *arg1, u8 *arg2) {
    s32 var_r5;
    u32 temp_r3;
    u8 temp_r31;
    u32 tmp;
    if ((arg1 != NULL) && (arg2 != NULL)) {
        temp_r31 = *(u8 *)((s8 *)arg1 + 0);
        if (temp_r31 != 0) {
            temp_r3 = roll_channel_below__9TItemDropFPviUi((u8 *)arg0, -1, 6);
            var_r5 = ((temp_r31 >> 3U) & 0x1F) - 4;
            if (var_r5 < 0) {
                var_r5 = 0;
            }
            if (temp_r3 < (u32) ((2 << var_r5) * ((temp_r31 & 7) + 7))) {
                *(u8 *)((s8 *)arg2 + 0) = (u8) *(u8 *)((s8 *)arg1 + 1);
                *(u8 *)((s8 *)arg2 + 1) = (u8) *(u8 *)((s8 *)arg1 + 2);
                *(u8 *)((s8 *)arg2 + 2) = (u8) *(u8 *)((s8 *)arg1 + 3);
                switch ((s32) (*(u8 *)((s8 *)arg2 + 0))) {
                case 0:
                    tmp = roll_channel_below__9TItemDropFPviUi((u8 *)arg0, 0xA, 7);
                    roll_rare_weapon_attributes__9TItemDropFiPvi(arg0, (Obj_80106F4C *)(arg2), tmp);
                    set_flag__9TItemDropFPvPv((void *)arg0, (void *)arg2);
                    break;
                case 1:
                    roll_armor_bonuses__9TItemDropFv(arg0, arg2);
                    break;
                case 2:
                    apply_item_data__9TItemDropFPvPv((void *)arg0, (void *)arg2);
                    break;
                case 3:
                    init_rare_item_data__9TItemDropFPvPv((void *)arg0, (void *)arg2);
                    handle_type3__9TItemDropFPvPv((void*)arg0, (void*)arg2);
                    break;
                }
                apply_drop_restrictions((void *)arg0, (void *)arg2);
                TItemDrop::clear_item_if_player_picked_up((void *)arg0, (void *)arg2);
                return 1;
            }
            goto block_18;
        }
    }
block_18:
    return 0;
}

u16 roll_meseta_range__9TItemDropFPviiii(void *self, s32 arg1, s32 a, s32 b, s32 c) {
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
        u16 r = roll_channel_below__9TItemDropFPviUi(((u8 *)self), (hi - lo + 1), 5);
        return r + base;
    }
}

u8 roll_technique_level__9TItemDropFv(s32 self, s32 table, s32 row, s32 col, s32 stride) {
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
        u8 r = roll_channel_below__9TItemDropFPviUi(((u8 *)self), (hi - lo + 1), 4);
        return r + base;
    }
}

u8 select_weighted_column_u16__9TItemDropFiiiii(s32 rng, s32 base, s32 off, s32 count, s32 stride) {
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
    r = roll_channel_below__9TItemDropFPviUi((u8 *)rng, (s32)total, (u32)(3));
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

typedef struct RecoveredGlobal_80107840_lbl_8049EF88 RecoveredGlobal_80107840_lbl_8049EF88;

u8 select_weighted_byte__9TItemDropFiiiii(s32 rng, s32 base, s32 off, s32 count, s32 stride) {
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
    r = roll_channel_below__9TItemDropFPviUi(((u8 *)rng), (total), 2);
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

u8 *TItemDrop__sub_80107840(u8 *arg0, s16 arg1) {
  s32 var_r30;
  s32 var_r31;
  if (arg0 != 0)
  {
    *((s32 **) (((s8 *) arg0) + 0x18)) = &lbl_8049EF88.value;
    var_r31 = (int) (((TItemDrop *)arg0)->m_1c);
    TItemDrop__sub_8010F168((void *)var_r31, 1);
    ((TItemDrop *)arg0)->m_1c = 0;
    TAdSinglePlyChrSelectGC::safe_free((int) TItemDrop__relocatable_load_buffer);
    TItemDrop__relocatable_load_buffer = 0;
    TAdSinglePlyChrSelectGC::safe_free((int) TItemDrop__second_relocatable_load_buffer);
    var_r31 = 0;
    var_r30 = 0;
    TItemDrop__second_relocatable_load_buffer = 0;
    do
    {
      ::operator delete((void *)(*((s32 *) (((s8 *) (((TItemDrop *)arg0)->m_20)) + var_r31))));
      var_r30 += 1;
      var_r31 += 4;
    }
    while (var_r30 != 0x11);
    mem_free((void *)((int) (((TItemDrop *)arg0)->m_20)));
    ((TItemDrop *)arg0)->m_20 = 0;
    __dt__7TObjectFv((void *) arg0, 0);
    if (arg1 > 0)
    {
      __dl__7TObjectFPv((void *) arg0);
    }
  }
  return arg0;
}

TItemDrop_80107900 *TItemDrop__ct(TItemDrop_80107900 *self, void *parent, s8 arg2) {
    s32 i;
    u32 a;
    u32 b;
    s32 obj;
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = &lbl_8049EF88.value;
    self->name = item_drop_class_name;
    TItemDrop__section_id = arg2;
    self->list = (s32 *)mem_alloc(0x44);
    for (i = 0; i != 0x11; i++) {
        a = __cvt_fp2unsigned(lbl_805DAAD8 * (lbl_805DAAE4 * (f32)rand()));
        b = __cvt_fp2unsigned(lbl_805DAAD4 * (lbl_805DAAE4 * (f32)rand()));
        obj = (int)::operator new(0xE8);
        if (obj != 0) {
            obj = run_step__9TItemDropFl(obj, a | b);
        }
        self->list[i] = obj;
    }
    TItemDrop__second_relocatable_load_buffer = ((TQuestVmDownLoadServer *)0xC00)->alloc();
    TItemDrop__relocatable_load_buffer = ((TQuestVmDownLoadServer *)0xC00)->alloc();
    self->unk1C = fn_8010F210(__vt__9TItemDrop);
    return self;
}

u8 *create_drop__9TItemDropFi(s32 parent) {
    u8 temp_r0;
    u8 *temp_r3;
    u8 *temp_r3_2;
    u8 *var_r0;
    temp_r3 = (u8 *)(get_char_index__23TAdSinglePlyChrSelectGCFUi(0U));
    if (temp_r3 != NULL) {
        temp_r0 = *(u8 *)((s8 *)temp_r3 + 0x3A0);
        if (((s8) temp_r0 >= 0) && ((s8) temp_r0 < 0xA)) {
            temp_r3_2 = (u8 *)(__nw__7TObjectFUl(0x24));
            var_r0 = temp_r3_2;
            if (var_r0 != NULL) {
                var_r0 = (u8 *)(TItemDrop__ct((TItemDrop_80107900 *)(temp_r3_2), (void *)parent, (s8)((s8) temp_r0)));
            }
            return var_r0;
        }
    }
    return NULL;
}

s8 get_bool_from_1d6ddc__9TItemDropFPv(void* p) { return (s8)(TLobby__sub_801D6DDC(p)); }
int TItemDrop__sub_80107B04(void) { return 0; }
s32 item_drop_rng_below(s32 arg0, u32 arg1) {
    __cvt_fp2unsigned((f32) (((f32) arg1 * (f32) subtractive_rng_next((void *)arg0)) / lbl_805DAAD8));
}

}
}
#pragma pop
