#include "types.h"
#include "pso/item/TItemProShield.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/misc/TechniqueBoost.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/model_render_state.h"
#include "pso/system/byteswap.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"

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
void *lookup_item_pmt_record(u8 *item);
s32 play_sound_effect(s32 id, Vec *position, s32 a, s32 b);
s32 play_shield_sound_cue(ShieldSoundCue *cue);
s32 add_actor_hp(TObjPlayer *actor, s16 amount);
s32 add_actor_tp(TObjPlayer *actor, s32 amount);
s16 obj_getS16_2BA(TObjPlayer *actor);
s32 push_matrix_from(void *src);
void TObjPlayer__sub_8036414C(void);
void TObjPlayer__sub_80364198(void);
// The item file helpers (TItemDrop_800F93F0.cpp).
s32 fn_800F953C(void *data);
ShieldEffectEntry *fn_800F955C(const char *name);
// The class name and the effect table's file name. This object really starts
// at 0x80117E50: TObjPlayer_80117DD8.cpp's last two functions (the nearby
// player checks, whose doubles follow these strings in .rodata) belong here
// and are not folded until the first of them matches.
extern const char *lbl_805D2C38;
extern const char *lbl_805D2C3C;
// The timer events a shield starts. Their classes are still written as C
// functions on the raw object (TItemTimerEvent has no real constructor).
void init_item_timer_event__13TUnk_804A0648Fv(void *event, TItemHeapObject *parent, u16 client, s32 duration);
void construct_timer_event__13TUnk_804A0628Fv(void *event, TItemHeapObject *parent, u16 client, s32 duration);
// Called with the client unextended and the item index widened to int, as
// this TU saw TItemEffShield::ct_init and the TUnk_8049F130 constructor.
void ct_init__14TItemEffShieldFPUcs(void *effect, TItemHeapObject *parent, u16 client);
void __ct__13TUnk_8049F130FP7TObjectsUc(void *object, TItemHeapObject *parent, u16 client, int index);
}

ShieldEffectEntry *TItemProShield::shield_table;

// The functions below run from the last one in the object back to the first
// (deferred code generation, see configure.py).

TItemProShield::~TItemProShield() {}

void TItemProShield::load_data() {
    s32 i;
    s32 j;
    u32 *word;
    ShieldEffectEntry *entry;
    shield_table = fn_800F955C(lbl_805D2C3C);
    i = 0;
    entry = shield_table;
    do {
        word = entry->words;
        j = 0;
        do {
            bswap_32(word);
            j += 1;
            word += 1;
        } while (j < 8);
        bswap_32(&entry->words[8]);
        bswap_32(&entry->words[9]);
        bswap_32(&entry->words[10]);
        i += 1;
        entry += 1;
    } while (i != 50);
}

void TItemProShield::free() {
    fn_800F953C(shield_table);
    shield_table = NULL;
}

TItem *TItemProShield::create(u8 *item) {
    if (item != NULL) {
        return new TItemProShield(tl_05, item);
    }
    return NULL;
}

TItemProShield::TItemProShield(TObject *parent, u8 *item) : TItemEquipBase(parent, item) {
    m_name = lbl_805D2C38;
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
            create_shield_effect((s32)tl_05, get_owner_client(), (u32)effect_entry);
            ((TObjPlayer *)&cue)->reset_status_block();
            cue.group = get_item_group();
            cue.index = get_item_index();
            cue.owner = owner;
            play_shield_sound_cue(&cue);
        }
        if (shield_flags & SHIELD_FLAG_BLOCK_RECOVERY) {
            switch (get_item_index()) {
            case 34:
                add_actor_hp(owner, 0.05f * (f32)((TItemProShield *)owner)->get_field_2b8());
                break;
            case 35:
                add_actor_hp(owner, 0.05f * (f32)((TItemProShield *)owner)->get_field_2b8());
                add_actor_tp(owner, (s32)(0.05f * (f32)obj_getS16_2BA(owner)));
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
                event = TItemHeapObject::operator new(0x2C);
                if (event != NULL) {
                    init_item_timer_event__13TUnk_804A0648Fv(event, effect_objects, get_owner_client(), 450);
                }
                event = TItemHeapObject::operator new(0x2C);
                if (event != NULL) {
                    construct_timer_event__13TUnk_804A0628Fv(event, effect_objects, get_owner_client(), 450);
                }
            }
            break;
        case 26:
            if (effect_objects != NULL) {
                event = TObject::operator new(0x2C);
                if (event != NULL) {
                    ct_init__14TItemEffShieldFPUcs(event, effect_objects, get_owner_client());
                }
            }
            break;
        }
        if ((index >= 0x53U) && (index <= 0x82U)) {
            event = TObject::operator new(0x30);
            if (event != NULL) {
                __ct__13TUnk_8049F130FP7TObjectsUc(event, effect_objects, get_owner_client(), index);
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
    if ((item_model != NULL) && (owner != NULL) && (obj_testFlags30(0x08000000) == 0) && (is_hidden() == 0)) {
        push_matrix_from((void *)owner->get_item_ptr(joint));
        TObjPlayer__sub_80364198();
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
        TObjPlayer__sub_8036414C();
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
