#include "types.h"
#include "pso/player/TObjPlayer_8011C000.h"
#include "pso/item/TItemDrop_80105D0C.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemDrop.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TOSwitchItem.h"

struct Tbl_8011C914 { u8 pad[0x2c]; u8 *p; };

struct Rule_8011CB18 { u8 type; u8 slots; u8 idx; u8 mode; };

struct RuleTbl_8011CB18 { s32 count; Rule_8011CB18 *rules; };

struct Entry_8011CB18 { u8 data[0x14]; };

struct Entries_8011CB18 { Entry_8011CB18 a[0xAA]; Entry_8011CB18 b[1]; };

struct Pmt_8011CB18 { u8 pad[0x1C]; Entry_8011CB18 *entries; u8 pad2[0x58 - 0x20]; RuleTbl_8011CB18 *rules; };

struct Base_8011CB18 { u8 pad[0x18]; };

struct Item_8011CB18 : Base_8011CB18 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual s32 m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual u8 m41();
};

struct Entry_8011C030 { u8 id[3]; u8 pad; };

struct List_8011C030 { s32 count; Entry_8011C030 *entries; };

struct Tbl_8011C030 { u8 pad[0x54]; List_8011C030 *list; };

struct Pair_8011C8BC { s16 a; s16 b; };

struct Tbl_8011C8BC { u8 pad[0x30]; Pair_8011C8BC *pairs; };

struct Cue_8011C7C8 { s32 key; s32 pitch; };

struct WeaponSounds_8011C7C8 { Cue_8011C7C8 owner[2]; Cue_8011C7C8 target[2]; };

struct SoundRemap_8011C620 { s32 key; s32 *by_target_type; s32 *by_class; };

struct SoundRemapTable_8011C620 { s32 count; SoundRemap_8011C620 *entries; };

struct Pmt_8011C7C8 { u8 pad[0x34]; WeaponSounds_8011C7C8 *weapons; u8 pad38[0x48 - 0x38]; SoundRemapTable_8011C620 *remaps; };

struct Ctx_8011C7C8 { u8 group; u8 variant; u8 pad[2]; u8 *owner; u8 pad8[4]; u8 *target; s32 part; };

typedef struct Pmt_8011CA10 { u8 pad[0x20]; f32 *t20; f32 *t24; } Pmt_8011CA10;

struct Rule_8011C0B8 { u8 k[6]; u8 pad[10]; };

struct RuleTbl_8011C0B8 { s32 count; Rule_8011C0B8 *rules; };

struct Pmt_8011C0B8 { u8 pad[0x44]; RuleTbl_8011C0B8 *tbl; };

typedef struct Sub_8011C59C { u8 pad[8]; s32 count; } Sub_8011C59C;

typedef struct Ent_8011C59C { s32 a; s32 b; } Ent_8011C59C;

typedef struct Pmt_8011C59C { u8 pad[4]; Sub_8011C59C *sub; u8 pad2[0x34]; Ent_8011C59C *tbl; } Pmt_8011C59C;

typedef struct Obj_8011C59C { u8 pad0; u8 idx; u8 pad[2]; u8 *ptr; } Obj_8011C59C;

typedef struct PmtEnt_8011C234 { s32 id; u8 pad[0x10]; } PmtEnt_8011C234;

typedef struct PmtRow_8011C234 { s32 count; PmtEnt_8011C234 *ents; } PmtRow_8011C234;

typedef struct Pmt_8011C234 { u8 pad[0xC]; PmtRow_8011C234 *rows; } Pmt_8011C234;

extern "C" {
s32 select_enemy_drop__9TItemDropFPviiPv(u32, s32, s32, s32);
s32 get_unit_attribute_index__10TObjPlayerFUc(u8 arg0);
s32 get_text_collection(s32);
extern s32 lbl_805D2B10;
s32 __cvt_fp2unsigned(f32);
s32 get_item_star_count(s32 id);
Entry_8011CB18 *get_weapon_range_record(Item_8011CB18 *item, s16 mode);
void update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 play_sound_effect(s32, void *, s32, s32);
void play_weapon_owner_sounds(Ctx_8011C7C8 *c);
void play_weapon_hit_sound(Ctx_8011C7C8 *c);
u16 get_entity_id(void *);
extern const f32 lbl_805DAC74;
extern s32 weapon_special_roll_channel_table[];
Rule_8011C0B8 *find_item_combination_recipe(u8 *id, void *item);
void play_shield_sound_cue(Obj_8011C59C *arg0);
void *get_item_pmt_record__10TObjPlayerFii(u8, u8);
void *get_armor_pmt_record(u8, u8);
}
void normalize_drop_area(s32 *p);
extern void *item_mgr;
extern void *item_pmt_tbl;
s32 get_mag_feed_result(s32 arg0, s32 arg1);
void roll_item_channel_below(u32 arg0, s32 arg1);
s32 is_unsealable_item(u8 *id);
s32 get_item_stat_boost_record(s32 arg0, s32 arg1, s32 arg2);
extern "C" {
s32 rand();
extern const f32 lbl_805DAC70;
typedef struct Thing__8011c1e8_8011C000 { u8 a; u8 b; } Thing;

s32 TObjPlayer::get_item_pmt_entry(u8 arg0) {
    void *temp_r5;

    temp_r5 = *(void **)((s8 *)item_pmt_tbl + 0x50);
    if ((s32) *(s32 *)((s8 *)temp_r5 + 0) > (s32) arg0) {
        return *(s32 *)((s8 *)temp_r5 + 4) + ((arg0 * 8) & 0x7F8);
    }
    return 0;
}
}

s32 is_unsealable_item(u8 *id) {
    List_8011C030 *l = ((Tbl_8011C030 *)item_pmt_tbl)->list;
    s32 n = l->count;
    Entry_8011C030 *e = l->entries;
    s32 i;
    for (i = 0; i != n; i++) {
        if (id[0] == e->id[0] && id[1] == e->id[1] && id[2] == e->id[2]) {
            return 1;
        }
        e++;
    }
    return 0;
}

s32 TObjPlayer::get_shield_pmt_entry(u8 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return *(s32 *)((s8 *)item_pmt_tbl + 0x4C) + (arg0 * 0x18);
}

Rule_8011C0B8 *find_item_combination_recipe(u8 *id, void *item) {
    Rule_8011C0B8 *r;
    s32 n;
    RuleTbl_8011C0B8 *t;
    if (id != NULL && item != NULL) {
        t = ((Pmt_8011C0B8 *)item_pmt_tbl)->tbl;
        r = t->rules;
        n = t->count;
        while (n != 0) {
            if ((id[0] == r->k[0] || r->k[0] == 0xFF) &&
                (id[1] == r->k[1] || r->k[1] == 0xFF) &&
                (id[2] == r->k[2] || r->k[2] == 0xFF) &&
                (r->k[3] == ((TItem *)item)->get_item_type() || r->k[3] == 0xFF) &&
                (r->k[4] == ((TItem *)item)->get_item_group() || r->k[4] == 0xFF) &&
                (r->k[5] == ((TItem *)item)->get_item_index() || r->k[5] == 0xFF)) {
                return r;
            }
            r++;
            n--;
        }
    }
    return NULL;
}

u8 get_technique_learn_limit(s8 arg0, u8 arg1) {
    return (*(u8 (**)[12])((s8 *)(*(u8 * *)&item_pmt_tbl) + 0x40))[arg1][arg0];
}

void TObjPlayer::register_item_drop() {
    Thing *p = (Thing *) this;

    if (p != 0 && item_mgr != 0 && p->a == 1 && p->b == 1) {
        TItemDrop::set_drop_index(item_mgr, p);
    }
}

#define PMT_8011C234 ((Pmt_8011C234 *)item_pmt_tbl)
void find_tool_pmt_base_id(s32 arg0, u8 *arg1) {
    s32 found;
    u8 i;
    u8 j;
    if (arg1 == NULL) {
        return;
    }
    found = 0;
    for (i = 0; i != 0x18 && found != 1; i++) {
        for (j = 0; j != PMT_8011C234->rows[i].count && found != 1; j++) {
            PmtEnt_8011C234 *e = &PMT_8011C234->rows[i].ents[j];
            if (e->id == arg0) {
                arg1[0] = 3;
                found = 1;
                arg1[1] = i;
                arg1[2] = j;
            }
        }
    }
}

f32 TObjPlayer::get_drop_random_float(u32 arg0) {
    if (item_mgr != NULL) {
        return ((f32 (*)(u8 *, u32))roll_table_ratio__9TItemDropFPvUi)((u8 *)item_mgr, arg0);
    }
    return lbl_805DAC70 * (f32) rand();
}

void roll_item_channel_below(u32 count, s32 arg1) {
    if ((u32) (*(u32 *)&item_mgr) != 0U) {
        roll_channel_below__9TItemDropFPviUi((u8 *)((*(u32 *)&item_mgr)), count, arg1);
        return;
    }
    __cvt_fp2unsigned((f32) count * TObjPlayer::get_drop_random_float(arg1));
}

void TObjPlayer::drop_item_from_slot(s32 area, s32 arg1, s32 arg2) {
    s32 sp8;
    s32 temp_r5;
    sp8 = arg1;
    if ((u32) (*(u32 *)&item_mgr) != 0U) {
        normalize_drop_area(&sp8);
        temp_r5 = sp8 - 1;
        sp8 = temp_r5;
        select_enemy_drop__9TItemDropFPviiPv((*(u32 *)&item_mgr), area, temp_r5, arg2);
    }
}
void TObjPlayer::drop_item(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r4;
    sp8 = arg0;
    if ((u32) (*(u32 *)&item_mgr) != 0U) {
        normalize_drop_area(&sp8);
        temp_r4 = sp8 - 1;
        sp8 = temp_r4;
        select_box_item__9TItemDropFiiPv((s32)(*(u32 *)&item_mgr), (s32)temp_r4, (u8 *)arg1);
    }
}
void TObjPlayer::drop_meseta_from_slot(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r4;
    sp8 = arg0;
    if ((u32) (*(u32 *)&item_mgr) != 0U) {
        normalize_drop_area(&sp8);
        temp_r4 = sp8 - 1;
        sp8 = temp_r4;
        generate_drop_item__9TItemDropFPviPv((u8 *)(*(u32 *)&item_mgr), (s32)temp_r4, (u8 *)arg1);
    }
}

s32 get_item_stat_boost_record(s32 arg0, s32 type, s32 id) {
    s32 idx;
    u8 *rec;
    idx = 0;
    switch ((u8) arg0) {
    case 0:
        rec = (u8 *)get_item_pmt_record__10TObjPlayerFii(type, id);
        if (rec != NULL) {
            idx = rec[0x1A];
        }
        break;
    case 1:
        switch ((u8) type) {
        case 1:
        case 2:
            rec = (u8 *)get_armor_pmt_record(type, id);
            if (rec != NULL) {
                idx = rec[0x18];
            }
            break;
        }
        break;
    }
    if (idx > 0) {
        return *(s32 *)((s8 *)item_pmt_tbl + 0x38) + (idx * 6);
    }
    return *(s32 *)((s8 *)item_pmt_tbl + 0x38);
}

s32 get_unit_attribute_index__10TObjPlayerFUc(u8 arg0) {
    if ((arg0 & 0x3F) && !(arg0 & 0x80)) {
        return get_item_star_count(arg0 + 0x1CB);
    }
    return 0;
}

void play_shield_sound_cue(Obj_8011C59C *arg0) {
    Pmt_8011C59C *pmt = (Pmt_8011C59C *)item_pmt_tbl;
    u8 idx = arg0->idx;
    if (idx < pmt->sub->count) {
        s32 off;
        u8 *tbl;
        s32 a;
        u8 *pos;
        tbl = (u8 *)pmt->tbl;
        a = *(s32 *)(tbl + (idx & 0x7f) * 8);
        off = ((idx & 0x7f) * 2 + 1) * 4;
        pos = arg0->ptr + 0x38;
        if (a != 0) {
            s32 r = play_sound_effect(a, pos, 0, 0);
            if (*(s32 *)(tbl + off) != 0) {
                update_technique_slot__10TTecRaFoieFl(r, *(s32 *)(tbl + off), 0);
            }
        }
    }
}

void play_weapon_hit_sound(Ctx_8011C7C8 *c) {
    s32 key[2];
    s32 pitch[2];
    u8 group = c->group;
    u8 *target;
    u32 mode;
    u8 *pos;
    u16 type;
    s32 cls;
    s32 i;
    if (c->group == 2 && c->variant == 6) {
        group = 0x32;
    }
    if (c->group == 0x89 && c->variant == 3) {
        group = 0x10;
    }
    if (group < 0xAA) {
        target = c->target;
        key[0] = ((Pmt_8011C7C8 *)item_pmt_tbl)->weapons[group].target[0].key;
        pitch[0] = ((Pmt_8011C7C8 *)item_pmt_tbl)->weapons[group].target[0].pitch;
        key[1] = ((Pmt_8011C7C8 *)item_pmt_tbl)->weapons[group].target[1].key;
        pitch[1] = ((Pmt_8011C7C8 *)item_pmt_tbl)->weapons[group].target[1].pitch;
        pos = (u8 *)((TObjCollidable *)target)->bodies + c->part * 0x2C + 0x1C;
        type = get_entity_id(target);
        if (type < 0x1000) {
            cls = *(s8 *)&((TObjPlayer *)target)->m_88d;
            mode = 1;
        } else if (type < 0x4000) {
            cls = *(s32 *)(target + 0x370);
            mode = 3;
        } else {
            mode = 3;
            cls = 0x30;
        }
        for (i = 0; i != 2; i++) {
            s32 k = key[i];
            s32 p = pitch[i];
            if (mode & 1) {
                SoundRemapTable_8011C620 *remaps = ((Pmt_8011C7C8 *)item_pmt_tbl)->remaps;
                s32 n = remaps->count;
                SoundRemap_8011C620 *e = remaps->entries;
                for (; n != 0; n--, e++) {
                    if (k == e->key) {
                        if (mode & 2) {
                            k = e->by_target_type[cls];
                        } else {
                            k = e->by_class[cls];
                        }
                    }
                }
            }
            if (k != 0) {
                s32 handle = play_sound_effect(k, pos, 0, 0);
                if (p != 0) {
                    update_technique_slot__10TTecRaFoieFl(handle, p, 0);
                }
            }
        }
    }
}

void play_weapon_owner_sounds(Ctx_8011C7C8 *c) {
    s32 key[2];
    s32 pitch[2];
    u8 group = c->group;
    u8 *pos;
    s32 i;
    if (c->group == 2 && c->variant == 6) {
        group = 0x32;
    }
    if (c->group == 0x89 && c->variant == 3) {
        group = 0x10;
    }
    if (group < 0xAA) {
        pos = c->owner + 0x38;
        key[0] = ((Pmt_8011C7C8 *)item_pmt_tbl)->weapons[group].owner[0].key;
        pitch[0] = ((Pmt_8011C7C8 *)item_pmt_tbl)->weapons[group].owner[0].pitch;
        key[1] = ((Pmt_8011C7C8 *)item_pmt_tbl)->weapons[group].owner[1].key;
        pitch[1] = ((Pmt_8011C7C8 *)item_pmt_tbl)->weapons[group].owner[1].pitch;
        for (i = 0; i != 2; i++) {
            s32 k = key[i];
            s32 p = pitch[i];
            if (k != 0) {
                s32 handle = play_sound_effect(k, pos, 0, 0);
                if (p != 0) {
                    update_technique_slot__10TTecRaFoieFl(handle, p, 0);
                }
            }
        }
    }
}

void get_weapon_special_type_amount(u32 x, s16 *a, s16 *b) {
    u8 idx = x & 0x3f;
    if (idx < 0x29 && a != 0 && b != 0) {
        *a = ((Tbl_8011C8BC *)item_pmt_tbl)->pairs[idx].a;
        *b = ((Tbl_8011C8BC *)item_pmt_tbl)->pairs[idx].b;
        return;
    }
    *a = -1;
    *b = -1;
}

s32 get_item_star_count(s32 id) {
    if (id >= 0x94 && id < 0x2f7) {
        return (*(Tbl_8011C914 * *)&item_pmt_tbl)->p[id - 0x94];
    }
    return 0;
}

s32 get_mag_feed_result(s32 arg0, s32 arg1) {
    if ((arg0 >= 0) && (arg0 < 8)) {
        return *(s32 *)((s8 *)(*(s32 *)((s8 *)(*(u8 * *)&item_pmt_tbl) + 0x28)) + (arg0 * 4)) + (arg1 * 8);
    }
    return 0;
}

u8 roll_weapon_special_for_stars(u8 arg0) {
    u32 n;
    s32 key;
    u8 result;
    u32 c;
    s32 i;
    result = 0;
    if (arg0 < 4U) {
        n = ((u32 (*)(int, int))roll_item_channel_below)(weapon_special_roll_channel_table[arg0], 0xF);
        key = arg0 + 1;
        c = 0;
        i = 1;
        do {
            if (key == ((u8 (*)(u8))get_unit_attribute_index__10TObjPlayerFUc)((u8)i)) {
                if (c == n) {
                    result = (u8)i;
                    break;
                }
                c++;
            }
            i++;
        } while (i != 0x29);
    }
    return result;
}

f32 get_item_price_coefficient(u8 arg0, u8 arg1) {
    switch (arg0) {
    case 0:
        if (arg1 < 0xAA) {
            return (*(Pmt_8011CA10 * *)&item_pmt_tbl)->t20[arg1];
        }
        break;
    case 1:
        if (arg1 != 0 && arg1 < 4) {
            return (*(Pmt_8011CA10 * *)&item_pmt_tbl)->t24[arg1 - 1];
        }
        break;
    case 2:
        return (*(Pmt_8011CA10 * *)&item_pmt_tbl)->t24[3];
    }
    return lbl_805DAC74;
}

u8 get_weapon_class_motion_type(u8 arg0) {
    if (arg0 < 0xAAU) {
        return *(u8 *)((s8 *)(*(s32 *)((s8 *)(*(u8 * *)&item_pmt_tbl) + 0x14) + arg0) + 0);
    }
    return 0U;
}

s32 TObjPlayer::get_item_by_slot_flag(u8 arg0) {
    if (arg0 & 0x3F) {
        if (arg0 & 0x80) {
            return get_text_collection(0x1F4);
        }
        if ((arg0 != 0) && (arg0 < 0x29U)) {
            return get_text_collection(arg0 + 0x1CB);
        }
        goto block_6;
    }
block_6:
    return lbl_805D2B10;
}
Entry_8011CB18 *get_weapon_range_record(Item_8011CB18 *item, s16 mode) {
    if (item != 0) {
        u8 id = ((TItem *)item)->get_item_group();
        if (id < 0xAA) {
            u8 slots = ((TItem *)item)->get_item_index();
            Rule_8011CB18 *r = (*(Pmt_8011CB18 **)&item_pmt_tbl)->rules->rules;
            s32 v = item->m33();
            s32 i;
            for (i = 0; i != (*(Pmt_8011CB18 **)&item_pmt_tbl)->rules->count; i++) {
                if (r->type == id && (r->slots == 0xFF || r->slots == slots) &&
                    (r->mode == 1 || (r->mode == 0 && mode == 2 && v == 1))) {
                    return &((Entries_8011CB18 *)(*(Pmt_8011CB18 **)&item_pmt_tbl)->entries)->b[r->idx];
                }
                r++;
            }
            return &(*(Pmt_8011CB18 **)&item_pmt_tbl)->entries[id];
        }
        return &(*(Pmt_8011CB18 **)&item_pmt_tbl)->entries[item->m41()];
    }
    return (*(Pmt_8011CB18 **)&item_pmt_tbl)->entries;
}
