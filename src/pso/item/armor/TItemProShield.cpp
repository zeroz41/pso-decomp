#include "pso/object/base/TObjChara.h"
#include "pso/item/drop/TItemDrop_800F93F0.h"
#include "types.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/item/TUnk_804A0628.h"
#include "pso/item/TUnk_804A0648.h"
#include "pso/technique/TechniqueBoost.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/model_render_state.h"
#include "pso/system/byteswap.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer_80117DD8.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_80363BE0.h"
#include "pso/player/PlayerSlots.h"

// What play_shield_sound_cue reads (TObjPlayer::reset_status_block clears it).
struct ShieldSoundCue {
    s8 group;
    u8 index;
    u8 pad_2[2];
    TObjPlayer *owner;
    s32 pad_8[3];
};

extern "C" {
// Defined in files that have no headers yet.
s32 play_shield_sound_cue(ShieldSoundCue *cue);
s16 obj_getS16_2BA(u8 *p);
// The item file helpers (TItemDrop_800F93F0.cpp).
// The class name and the effect table's file name. This object starts at
// 0x80117E50 with the nearby player checks (the last two functions below),
// whose doubles follow these strings in .rodata.
const char *TItemProShield__name = "TItemProShield";
const char *lbl_805D2C3C = "ItemShieldEntry.dat";
// Called with the item index widened to int.
void __ct__18TItemEffShieldAuraFP7TObjectUs(void *effect, TItemHeapObject *parent, u16 client);
void __ct__19TItemEffShieldPulseFP7TObjectUsUc(void *object, TItemHeapObject *parent, u16 client, int index);
}

ShieldEffectEntry *TItemProShield::shield_table;

// The functions below run from the last one in the object back to the first
// (deferred code generation, see configure.py).

TItemProShield::~TItemProShield() {}

void TItemProShield::load_data() {
    s32 i;
    s32 j;
    s32 *word;
    ShieldEffectEntry *entry;
    shield_table = (ShieldEffectEntry *)load_data_file(lbl_805D2C3C);
    i = 0;
    entry = shield_table;
    do {
        word = entry->particle_ids;
        j = 0;
        do {
            bswap_32((u32 *)word);
            j += 1;
            word += 1;
        } while (j < 8);
        bswap_32((u32 *)&entry->first_delay);
        bswap_32((u32 *)&entry->interval);
        bswap_32((u32 *)&entry->burst_count);
        i += 1;
        entry += 1;
    } while (i != 50);
}

void TItemProShield::free() {
    free_data_file(shield_table);
    shield_table = NULL;
}

TItem *TItemProShield::create(u8 *item) {
    if (item != NULL) {
        return new TItemProShield(tl_05, item);
    }
    return NULL;
}

TItemProShield::TItemProShield(TObject *parent, u8 *item) : TItemEquipBase(parent, item) {
    m_name = TItemProShield__name;
    set_attach_slot(3);
    pmt = (ShieldPmtEntry *)lookup_item_pmt_record(item);
    effect_entry = &shield_table[pmt->block_effect];
    technique_boosts = (const TechniqueBoostParam *)TObjPlayer::get_shield_pmt_entry(pmt->technique_boost);
    dfp_range = pmt->dfp_range;
    evp_range = pmt->evp_range;
    dfp_bonus = TItemData::getS16_06(item);
    evp_bonus = TItemData::get_bswap16_field8(item);
    shield_flags = 0;
    set_attach_joint(0x24);
    apply_shield_effect_flags();
}

void TItemProShield::perform_action() {
    ShieldSoundCue cue;
    if (owner != NULL) {
        if (is_hidden() == 0) {
            create_shield_effect(tl_05, get_owner_client(), effect_entry);
            ((TObjPlayer *)&cue)->reset_status_block();
            cue.group = get_item_group();
            cue.index = get_item_index();
            cue.owner = owner;
            play_shield_sound_cue(&cue);
        }
        if (shield_flags & SHIELD_FLAG_BLOCK_RECOVERY) {
            switch (get_item_index()) {
            case 34:
                add_actor_hp(owner, 0.05f * (f32)owner->get_hpmax());
                break;
            case 35:
                add_actor_hp(owner, 0.05f * (f32)owner->get_hpmax());
                add_actor_tp(owner, (s32)(0.05f * (f32)obj_getS16_2BA((u8 *)owner)));
                break;
            }
        }
    }
}

void TItemProShield::on_equip() {
    u8 index;
    void *event;
    if (is_hidden() == 0) {
        play_sound_effect(0x4000B20A, &owner->position, 0, 0);
    }
    if (effect_objects != NULL) {
        index = get_item_index();
        switch ((s32)index) {
        case 39:
            if (effect_objects != NULL) {
                new TUnk_804A0648(effect_objects, get_owner_client(), 450);
                new TUnk_804A0628(effect_objects, get_owner_client(), 450);
            }
            break;
        case 26:
            if (effect_objects != NULL) {
                event = TObject::operator new(0x2C);
                if (event != NULL) {
                    __ct__18TItemEffShieldAuraFP7TObjectUs(event, effect_objects, get_owner_client());
                }
            }
            break;
        }
        if ((index >= 0x53U) && (index <= 0x82U)) {
            event = TObject::operator new(0x30);
            if (event != NULL) {
                __ct__19TItemEffShieldPulseFP7TObjectUsUc(event, effect_objects, get_owner_client(), index);
            }
        }
    }
}

void TItemProShield::on_unequip() { clear_technique_boosts(); }

void TItemProShield::write_item_data(TItemData *data) {
    data->set_dfp_bonus(dfp_bonus);
    data->set_bswapped_field_8(evp_bonus);
}

void TItemProShield::update_equipped() {
    on_update_equipped();
    register_technique_boosts(technique_boosts);
    if (shield_flags & SHIELD_FLAG_REFRESH_STATS) {
        refresh_owner_stats();
    }
    bind_loaded_resources();
}

void TItemProShield::update_owned() {
    if (dfp_range < dfp_bonus) {
        dfp_bonus = 0;
    }
    if (evp_range < evp_bonus) {
        evp_bonus = 0;
    }
}

void TItemProShield::carry_over_stats(TItemData *data, TItem *item) {
    data->set_dfp_bonus(((TItemProShield *)item)->dfp_bonus);
    data->set_bswapped_field_8(((TItemProShield *)item)->evp_bonus);
}

void TItemProShield::on_update_equipped() {}

void TItemProShield::request_equipped_model() { request_item_model(); }

void TItemProShield::draw_at_joint(s32 joint) {
    if ((item_model != NULL) && (owner != NULL) && (test_actor_flags(0x08000000) == 0) && (is_hidden() == 0)) {
        push_matrix_from((void *)owner->get_joint_matrix(joint));
        TObjPlayer::save_model_render_state();
        model_render_flags &= ~0x10;
        TObjPlayer::set_model_fade_alpha(get_owner_alpha());
        if (shield_flags & SHIELD_FLAG_EFFECT_RENDER) {
            TParticleCtrl::begin_effect_render();
        }
        set_texlist(texlist);
        draw_ginja_object(item_model);
        if (shield_flags & SHIELD_FLAG_EFFECT_RENDER) {
            TParticleCtrl::end_effect_render();
        }
        TObjPlayer::warn_if_gauge_low();
        TObjPlayer::restore_model_render_state();
        pop_matrix();
    }
}

void TItemProShield::render_equipped() {
    NJS_OBJECT *model;
    if (shield_flags & SHIELD_FLAG_TWO_MODELS) {
        draw_at_joint(0x13);
        model = item_model;
        item_model = second_model;
        draw_at_joint(0xA);
        item_model = model;
        return;
    }
    draw_at_joint(get_attach_joint());
}

void TItemProShield::apply_shield_effect_flags() {
    u8 index = get_item_index();
    switch (index) {
    case 34:
    case 35:
        shield_flags |= SHIELD_FLAG_BLOCK_RECOVERY;
        break;
    case 22:
        effect_flags.set(0x80);
        break;
    case 49:
        set_attach_joint(0x3A);
        effect_flags.set(0x2);
        shield_flags |= SHIELD_FLAG_EFFECT_RENDER;
        break;
    case 48:
        set_attach_joint(0x28);
        break;
    case 42:
        shield_flags |= SHIELD_FLAG_EFFECT_RENDER;
        break;
    case 50:
        set_attach_joint(0x3A);
        shield_flags |= SHIELD_FLAG_EFFECT_RENDER;
        break;
    }
    if ((index == 0x27) || ((index >= 0x33U) && (index <= 0x39U)) || ((index >= 0x53U) && (index <= 0x82U)) ||
        (index == 0x52)) {
        set_attach_joint(0x22);
        shield_flags |= SHIELD_FLAG_EFFECT_RENDER;
    }
    switch (pmt->model_type) {
    case 1:
        shield_flags |= SHIELD_FLAG_REFRESH_STATS;
        return;
    case 3:
        shield_flags |= SHIELD_FLAG_TWO_MODELS;
    case 2:
    case 0:
        return;
    }
}

s32 TObjPlayer::count_nearby_players_with_shield(u16 idx, u8 *item) {
    s32 key;
    TObjPlayer *me;
    s32 count;
    u16 i;
    TObjPlayer *other;
    void *it;
    count = 0;
    me = get_player_by_client_id(idx);
    if (me != NULL && item != NULL) {
        key = me->get_floor();
        for (i = 0; i != 4; i++) {
            if (i != idx) {
                other = get_player_by_client_id(i);
                if (other != NULL && key == other->get_floor() &&
                    horizontal_distance_squared(&me->position, &other->position) < 2500.0 &&
                    (it = (void *)((TItemData *)other)->test_flag3()) != NULL &&
                    item[2] == ((TItem *)it)->get_item_index()) {
                    count++;
                }
            }
        }
    }
    return count;
}

s32 is_opposite_sex_player_near(u16 idx) {
    TObjPlayer *me;
    s32 mask;
    s32 found = 0;
    s32 floor;
    u16 i;
    TObjPlayer *other;
    me = get_player_by_client_id(idx);
    if (me != NULL) {
        mask = (me->class_flags & 1) ? 2 : 1;
        floor = me->get_floor();
        for (i = 0; i != 4; i++) {
            if (i != idx) {
                other = get_player_by_client_id(i);
                if (other != NULL && (other->class_flags & mask) && floor == other->get_floor() &&
                    horizontal_distance_squared(&me->position, &other->position) < 400.0) {
                    found = 1;
                    break;
                }
            }
        }
    }
    return found;
}
