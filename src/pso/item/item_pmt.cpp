// The item parameter table (ItemPMT.prs): its loader, the record lookups and
// the item drop rolls that read it.
#pragma readonly_strings on
#include "types.h"
#include "clib/fp_convert.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/drop/TItemDrop.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/object/switch/TOSwitchItem.h"
#include "pso/item/item_param.h"
#include "pso/item/item_pmt.h"
#include "pso/item/TItemLoad.h"
#include "pso/audio/SoundRequests.h"
#include "pso/item/MaterialStats.h"
#include "pso/system/MallocLoadFilePrc.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/TObjBase.h"
#include "pso/item/item_create.h"

void *item_pmt;

ItemPmt *item_pmt_tbl;
TItemDrop *item_mgr;

const char *item_pmt_filename_descriptor = "ItemPMT.prs";

// Channel count per weapon star class, rolled by roll_weapon_special_for_stars.
const s32 weapon_special_roll_channel_table[4] = {8, 10, 11, 11};

// play_shield_sound_cue's view of the ItemPmt root: armors[1].count and
// shield_sounds through ItemPmt give the same code with r5/r6 swapped.
typedef struct ShieldSoundCount { u8 pad[8]; s32 count; } ShieldSoundCount;

typedef struct ShieldSoundEntry { s32 a; s32 b; } ShieldSoundEntry;

typedef struct ItemPmtSoundRoot { u8 pad[4]; ShieldSoundCount *sub; u8 pad2[0x34]; ShieldSoundEntry *tbl; } ItemPmtSoundRoot;


saddr TObjPlayer::get_item_pmt_entry(u8 index) {
    ItemChoiceListTable *table = item_pmt_tbl->random_items;

    if (table->count > index) {
        return (saddr)&table->lists[index];
    }
    return 0;
}
s32 is_unsealable_item(u8 *id) {
    ItemPmtCodeList *l = item_pmt_tbl->unsealable_items;
    s32 n = l->count;
    ItemPmtCode *e = l->codes;
    s32 i;
    for (i = 0; i != n; i++) {
        if (id[0] == e->code[0] && id[1] == e->code[1] && id[2] == e->code[2]) {
            return 1;
        }
        e++;
    }
    return 0;
}

saddr TObjPlayer::get_shield_pmt_entry(u8 index) {
    if (index == 0) {
        return 0;
    }
    return (saddr)&item_pmt_tbl->technique_boosts[index * 0x18];
}

ItemCombination *find_item_combination_recipe(u8 *id, TItem *item) {
    ItemCombination *r;
    s32 n;
    ItemCombinationList *t;
    if (id != NULL && item != NULL) {
        t = item_pmt_tbl->combinations;
        r = t->recipes;
        n = t->count;
        while (n != 0) {
            if ((id[0] == r->use_item[0] || r->use_item[0] == 0xFF) &&
                (id[1] == r->use_item[1] || r->use_item[1] == 0xFF) &&
                (id[2] == r->use_item[2] || r->use_item[2] == 0xFF) &&
                (r->equipped_item[0] == item->get_item_type() || r->equipped_item[0] == 0xFF) &&
                (r->equipped_item[1] == item->get_item_group() || r->equipped_item[1] == 0xFF) &&
                (r->equipped_item[2] == item->get_item_index() || r->equipped_item[2] == 0xFF)) {
                return r;
            }
            r++;
            n--;
        }
    }
    return NULL;
}

u8 get_technique_learn_limit(u8 char_class, u8 technique) {
    return item_pmt_tbl->technique_limits[technique][(s8)char_class];
}

void TItemData::register_item_drop(TItemData *item) {
    if (item != NULL && item_mgr != NULL && item->data1.data_u8[0] == 1 && item->data1.data_u8[1] == 1) {
        item_mgr->set_drop_index(item);
    }
}

void find_tool_pmt_base_id(s32 tool_id, u8 *item) {
    s32 found;
    u8 i;
    u8 j;
    if (item == NULL) {
        return;
    }
    found = 0;
    for (i = 0; i != 0x18 && found != 1; i++) {
        for (j = 0; j != item_pmt_tbl->tools[i].count && found != 1; j++) {
            ItemPmtTool *e = &item_pmt_tbl->tools[i].records[j];
            if (e->id == tool_id) {
                item[0] = 3;
                found = 1;
                item[1] = i;
                item[2] = j;
            }
        }
    }
}

f32 TObjPlayer::get_drop_random_float(u32 channel) {
    if (item_mgr != NULL) {
        return item_mgr->roll_table_ratio(channel);
    }
    return 3.0517578e-05f * (f32) rand();
}

void roll_item_channel_below(u32 count, s32 channel) {
    if (item_mgr != NULL) {
        item_mgr->roll_channel_below(count, channel);
        return;
    }
    __cvt_fp2unsigned((f32) count * TObjPlayer::get_drop_random_float(channel));
}

void TObjPlayer::drop_item_from_slot(s32 area, s32 slot, TItemData *item) {
    s32 floor_slot;
    s32 idx;
    floor_slot = slot;
    if (item_mgr != NULL) {
        normalize_drop_area(&floor_slot);
        idx = floor_slot - 1;
        floor_slot = idx;
        item_mgr->select_enemy_drop(area, idx, item);
    }
}
void TObjPlayer::drop_item(s32 slot, TItemData *item) {
    s32 floor_slot;
    s32 off;
    floor_slot = slot;
    if (item_mgr != NULL) {
        normalize_drop_area(&floor_slot);
        off = floor_slot - 1;
        floor_slot = off;
        item_mgr->select_box_item(off, item);
    }
}
void TObjPlayer::drop_meseta_from_slot(s32 slot, TItemData *item) {
    s32 floor_slot;
    s32 idx;
    floor_slot = slot;
    if (item_mgr != NULL) {
        normalize_drop_area(&floor_slot);
        idx = floor_slot - 1;
        floor_slot = idx;
        item_mgr->generate_drop_item(idx, item);
    }
}

ItemStatBoost *get_item_stat_boost_record(s32 item_type, s32 type, s32 id) {
    s32 idx;
    u8 *rec;
    idx = 0;
    switch ((u8) item_type) {
    case 0:
        rec = (u8 *)TObjPlayer::get_item_pmt_record((u8)type, (u8)id);
        if (rec != NULL) {
            idx = rec[0x1A];
        }
        break;
    case 1:
        switch ((u8) type) {
        case 1:
        case 2:
            rec = (u8 *)get_armor_pmt_record((u8)type, (u8)id);
            if (rec != NULL) {
                idx = rec[0x18];
            }
            break;
        }
        break;
    }
    if (idx > 0) {
        return &item_pmt_tbl->stat_boosts[idx];
    }
    return item_pmt_tbl->stat_boosts;
}

s32 get_weapon_special_star_count(u8 special) {
    if ((special & 0x3F) && !(special & 0x80)) {
        return get_item_star_count(special + 0x1CB);
    }
    return 0;
}

void play_shield_sound_cue(ItemSoundRequest *cue) {
    ItemPmtSoundRoot *pmt = (ItemPmtSoundRoot *)item_pmt_tbl;
    u8 idx = cue->index;
    if (idx < pmt->sub->count) {
        s32 off;
        u8 *tbl;
        s32 a;
        const Vec *pos;
        tbl = (u8 *)pmt->tbl;
        a = *(s32 *)(tbl + (idx & 0x7f) * 8);
        off = ((idx & 0x7f) * 2 + 1) * 4;
        pos = &cue->player->position;
        if (a != 0) {
            s32 r = play_sound_effect(a, pos, 0, 0);
            if (*(s32 *)(tbl + off) != 0) {
                set_sound_pitch_request(r, *(s32 *)(tbl + off), 0);
            }
        }
    }
}

void play_weapon_hit_sound(ItemSoundRequest *request) {
    s32 key[2];
    s32 pitch[2];
    u8 group = request->group;
    u8 *target;
    u32 mode;
    u8 *pos;
    u16 type;
    s32 cls;
    s32 i;
    if (request->group == 2 && request->index == 6) {
        group = 0x32;
    }
    if (request->group == 0x89 && request->index == 3) {
        group = 0x10;
    }
    if (group < 0xAA) {
        target = (u8 *)request->target;
        key[0] = item_pmt_tbl->weapon_sounds[group].target[0].key;
        pitch[0] = item_pmt_tbl->weapon_sounds[group].target[0].pitch;
        key[1] = item_pmt_tbl->weapon_sounds[group].target[1].key;
        pitch[1] = item_pmt_tbl->weapon_sounds[group].target[1].pitch;
        pos = (u8 *)((TObjCollidable *)target)->bodies + request->collider * 0x2C + 0x1C;
        type = ((TObjBase *)(target))->get_entity_id();
        if (type < 0x1000) {
            cls = ((TObjPlayer *)target)->appearance.classId;
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
                ItemSoundRemapList *remaps = item_pmt_tbl->sound_remaps;
                s32 n = remaps->count;
                ItemSoundRemap *e = remaps->entries;
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
                s32 handle = play_sound_effect(k, reinterpret_cast<const Vec *>(pos), 0, 0);
                if (p != 0) {
                    set_sound_pitch_request(handle, p, 0);
                }
            }
        }
    }
}

void play_weapon_owner_sounds(ItemSoundRequest *request) {
    s32 key[2];
    s32 pitch[2];
    u8 group = request->group;
    const Vec *pos;
    s32 i;
    if (request->group == 2 && request->index == 6) {
        group = 0x32;
    }
    if (request->group == 0x89 && request->index == 3) {
        group = 0x10;
    }
    if (group < 0xAA) {
        pos = &request->player->position;
        key[0] = item_pmt_tbl->weapon_sounds[group].owner[0].key;
        pitch[0] = item_pmt_tbl->weapon_sounds[group].owner[0].pitch;
        key[1] = item_pmt_tbl->weapon_sounds[group].owner[1].key;
        pitch[1] = item_pmt_tbl->weapon_sounds[group].owner[1].pitch;
        for (i = 0; i != 2; i++) {
            s32 k = key[i];
            s32 p = pitch[i];
            if (k != 0) {
                s32 handle = play_sound_effect(k, pos, 0, 0);
                if (p != 0) {
                    set_sound_pitch_request(handle, p, 0);
                }
            }
        }
    }
}

void get_weapon_special_type_amount(u8 x, s16 *a, s16 *b) {
    u8 idx = x & 0x3f;
    if (idx < 0x29 && a != 0 && b != 0) {
        *a = item_pmt_tbl->weapon_specials[idx].type;
        *b = item_pmt_tbl->weapon_specials[idx].amount;
        return;
    }
    *a = -1;
    *b = -1;
}

s32 get_item_star_count(s32 id) {
    if (id >= 0x94 && id < 0x2f7) {
        return item_pmt_tbl->star_counts[id - 0x94];
    }
    return 0;
}

saddr get_mag_feed_result(s32 feed_table, s32 food_id) {
    if ((feed_table >= 0) && (feed_table < 8)) {
        return (saddr)&item_pmt_tbl->mag_feed_tables[feed_table][food_id * 8];
    }
    return 0;
}

u8 roll_weapon_special_for_stars(u8 stars) {
    u32 n;
    s32 key;
    u8 result;
    u32 c;
    s32 i;
    result = 0;
    if (stars < 4U) {
        n = ((u32 (*)(int, int))roll_item_channel_below)(weapon_special_roll_channel_table[stars], 0xF);
        key = stars + 1;
        c = 0;
        i = 1;
        do {
            if (key == (u8)get_weapon_special_star_count(i)) {
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

f32 get_item_price_coefficient(u8 type, u8 sub) {
    switch (type) {
    case 0:
        if (sub < 0xAA) {
            return item_pmt_tbl->weapon_price_coefficients[sub];
        }
        break;
    case 1:
        if (sub != 0 && sub < 4) {
            return item_pmt_tbl->price_coefficients[sub - 1];
        }
        break;
    case 2:
        return item_pmt_tbl->price_coefficients[3];
    }
    return 0.0f;
}

u8 get_weapon_class_motion_type(u8 group) {
    if (group < 0xAAU) {
        return item_pmt_tbl->weapon_motion_types[group];
    }
    return 0U;
}

saddr TObjPlayer::get_item_by_slot_flag(u8 flags) {
    if (flags & 0x3F) {
        if (flags & 0x80) {
            return (saddr)get_text_collection(0x1F4);
        }
        if ((flags != 0) && (flags < 0x29U)) {
            return (saddr)get_text_collection(flags + 0x1CB);
        }
        goto block_6;
    }
block_6:
    return (saddr)empty_string;
}
WeaponRangeRecord *get_weapon_range_record(TItem *item, s16 mode) {
    if (item != 0) {
        u8 id = item->get_item_group();
        if (id < 0xAA) {
            u8 slots = item->get_item_index();
            WeaponRangeRule *r = item_pmt_tbl->weapon_range_rules->rules;
            s32 v = item->is_identified();
            s32 i;
            for (i = 0; i != item_pmt_tbl->weapon_range_rules->count; i++) {
                if (r->group == id && (r->index == 0xFF || r->index == slots) &&
                    (r->mode == 1 || (r->mode == 0 && mode == 2 && v == 1))) {
                    return &item_pmt_tbl->weapon_ranges->specials[r->record];
                }
                r++;
            }
            return &item_pmt_tbl->weapon_ranges->groups[id];
        }
        return &item_pmt_tbl->weapon_ranges->groups[item->get_motion_type()];
    }
    return item_pmt_tbl->weapon_ranges->groups;
}


void*TObjPlayer::get_pmt_record(int i) {
    ItemPmtList *c = item_pmt_tbl->mags;
    if (i < c->count) {
        return &c->records[i * 24];
    }
    return &c->records[c->count * 24];
}

void*TObjPlayer::get_item_pmt_record(int type, int id) {
    if (type > 0) {
        ItemPmtList *lists = item_pmt_tbl->weapons;
        if (type < 170) {
            ItemPmtList *s = &lists[type];
            if (id < s->count) {
                return &s->records[id * 40];
            }
        }
        return lists[170].records;
    }
    return NULL;
}

void*TObjPlayer::get_pmt_record_by_type_id(int type, int id) {
    ItemPmtToolList *lists = item_pmt_tbl->tools;
    if (type < 24) {
        ItemPmtToolList *s = &lists[type];
        if (id < s->count) {
            return &s->records[id];
        }
    }
    return lists[24].records;
}

void*TObjPlayer::get_pmt_record_by_index(int i) {
    ItemPmtList *c = item_pmt_tbl->units;
    if (i < c->count) {
        return &c->records[i * 0x10];
    }
    return &c->records[c->count * 0x10];
}

void* get_armor_pmt_record(int type, int id) {
    if (type > 0 && type < 3) {
        ItemPmtList *s = &item_pmt_tbl->armors[type - 1];
        if (id < s->count) {
            return &s->records[id * 28];
        }
        return &s->records[s->count * 28];
    }
    return NULL;
}

void* get_photon_color_record(int i) {
    if (i < 32) {
        return &item_pmt_tbl->photon_colors[i * 36];
    }
    return NULL;
}


void free_item_pmt() {
    delete (RelocatedFile *)item_pmt;
    item_pmt = NULL;
    item_pmt_tbl = NULL;
}

void unload_items() {
    delete item_mgr;
    item_mgr = NULL;
    free_item_pmt();
}

void load_item_pmt() {
    RelocatedFile *p = new RelocatedFile(item_pmt_filename_descriptor, 0x10000);
    item_pmt = p;
    if (p != NULL) {
        item_pmt_tbl = (ItemPmt *)p->get_root();
    }
}

void load_items() {
    load_item_pmt();
    item_mgr = TItemDrop::create_drop(NULL);
}

void ItemSoundRequest::clear() {
    group = 0;
    player = NULL;
    unused = 0;
    target = NULL;
    collider = 0;
}
