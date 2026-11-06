#include "pso/system/NinjaTypes.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemMag.h"

#include <stdlib.h>
#include <string.h>

#include "pso/item/TItemAttacker.h"
#include "pso/item/TItemLoad.h"
#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemDrop_800F93F0.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItemLoad_8010FDF0.h"
#include "pso/item/TItemMagGrowEff.h"
#include "pso/item/TItemMagSub.h"
#include "pso/item/TItemProShield.h"
#include "pso/map/FloorArea.h"
#include "pso/menu/TAdRicoRing_8001BEE8.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TLobby_80291D94.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TTecDeband.h"
#include "pso/misc/TTecResta.h"
#include "pso/misc/TTecReverser.h"
#include "pso/misc/TTecSifta.h"
#include "pso/misc/pso_const_ids4.h"
#include "pso/player/PhotonBlastGauge.h"
#include "pso/player/PlayerScaleState.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_8011C000.h"
#include "pso/player/TObjPlayer_80363BE0.h"
#include "pso/player/TargetCursorList.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/byteswap.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/unk/text_801D5DDC.h"
#include "pso/unk/text_801D79DC.h"

const char *item_mag_class_name = "TItemMag";

RelocatedFile *item_mag_edit_file;
// ItemMagEdit.prs's motion tables, one per model variant.
s8 **item_mag_motion_tables;
MagFollowParameters *item_mag_motions;

// The mag levels at which it takes its first, second and third forms.
static const s32 evolution_levels[3] = {10, 35, 50};
// The rare forms evolve_rare_form picks: by the owner's class (6 apart)
// and section id (2 apart), the second of each pair for a female owner.
static const u8 rare_forms[18] = {
    0x39, 0x3B, 0x3A, 0x3B, 0x3A, 0x3B, 0x3D, 0x3C, 0x3D,
    0x3C, 0x3D, 0x3E, 0x41, 0x3F, 0x41, 0x40, 0x41, 0x40,
};

// The functions below run from the last one in the object back to the
// first (deferred code generation, see configure.py).

s32 MagNodeOscillationState::is_disabled() {
    return (flags & 0xE0) - 0xE0 == 0;
}

s16 MagStats::get_def_progress() {
    return def % 100;
}

s16 MagStats::get_pow_progress() {
    return pow % 100;
}

s16 MagStats::get_dex_progress() {
    return dex % 100;
}

s16 MagStats::get_mind_progress() {
    return mind % 100;
}

void MagNodeOscillationState::update() {
    s32 next;
    s16 limit;

    if (is_disabled() == 0) {
        if (flags & 0x10) {
            next = value + maximum;
            value = next;
            if ((s16)next != 0 && maximum < value) {
                value = minimum;
            }
        } else if (flags & 8) {
            value = value + speed;
            limit = maximum;
            if (limit < value) {
                value = limit;
                flags &= ~8;
            }
        } else {
            value = value - speed;
            if (value < (limit = minimum)) {
                value = limit;
                flags |= 8;
            }
        }
    }
}

s16 MagStats::get_level() {
    return get_def_level() + get_pow_level() + get_mind_level() + get_dex_level();
}

void MagStats::clear() {
    def = 500;
    mind = 0;
    dex = 0;
    pow = 0;
    photon_blasts = 0;
    photon_blast_flags = 0;
    iq = 0;
    synchro = 40;
    color = 18;
}

s32 MagStats::get_photon_blast(s32 slot) {
    int packed;
    u8 used[6];
    s32 i;
    u8 rank;

    switch (slot) {
    case 0:
        if (photon_blast_flags & photon_blast_slots[0]) {
            return photon_blasts & photon_blast_masks[0];
        }
        break;
    case 1:
        if (photon_blast_flags & photon_blast_slots[1]) {
            return (photon_blasts & photon_blast_masks[1]) >> 3;
        }
        break;
    case 2:
        if (photon_blast_flags & photon_blast_slots[2]) {
            memset(used, 0, 6);
            packed = photon_blasts;
            u8 blasts = packed;
            used[(u8)(blasts & photon_blast_masks[0])] = 1;
            used[(u8)((blasts & photon_blast_masks[1]) >> 3)] = 1;
            rank = (blasts & photon_blast_masks[2]) >> 6;
            for (i = 0; i < 6; i++) {
                if (used[i] != 1) {
                    if (rank == 0) {
                        return i;
                    }
                    rank--;
                }
            }
        }
        break;
    }
    return -1;
}

s32 MagStats::has_photon_blast(u8 blast) {
    s32 slot;

    if (blast < 6) {
        for (slot = 0; slot != 3; slot++) {
            if (blast == get_photon_blast(slot)) {
                return 1;
            }
        }
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void MagStats::add_def(s16 amount) {
    s16 progress;
    s16 level;
    s16 room;

    progress = get_def_progress();
    if (amount > 0 || (amount < 0 && -amount < progress)) {
        level = get_level();
        if (level < 200) {
            def = def + amount;
            return;
        }
        if (level == 200) {
            room = 99 - progress;
            if (room < amount) {
                amount = room;
            }
            def = def + amount;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation off
void MagStats::add_pow(s16 amount) {
    s16 progress;
    s16 level;
    s16 room;

    progress = get_pow_progress();
    if (amount > 0 || (amount < 0 && -amount < progress)) {
        level = get_level();
        if (level < 200) {
            pow = pow + amount;
            return;
        }
        if (level == 200) {
            room = 99 - progress;
            if (room < amount) {
                amount = room;
            }
            pow = pow + amount;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void MagStats::add_dex(s16 amount) {
    s16 progress;
    s16 level;
    s16 room;

    progress = get_dex_progress();
    if (amount > 0 || (amount < 0 && -amount < progress)) {
        level = get_level();
        if (level < 200) {
            dex = dex + amount;
            return;
        }
        if (level == 200) {
            room = 99 - progress;
            if (room < amount) {
                amount = room;
            }
            dex = dex + amount;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation off
void MagStats::add_mind(s16 amount) {
    s16 progress;
    s16 level;
    s16 room;

    progress = get_mind_progress();
    if (amount > 0 || (amount < 0 && -amount < progress)) {
        level = get_level();
        if (level < 200) {
            mind = mind + amount;
            return;
        }
        if (level == 200) {
            room = 99 - progress;
            if (room < amount) {
                amount = room;
            }
            mind = mind + amount;
        }
    }
}
#pragma pop

void MagStats::add_iq(s32 amount) {
    iq += amount;
    if (iq < 0) {
        iq = 0;
    }
    if (iq > 200) {
        iq = 200;
    }
}

void MagStats::add_synchro(s32 amount) {
    synchro = synchro + amount;
    if (synchro < 0) {
        synchro = 0;
    }
    if (synchro > 120) {
        synchro = 120;
    }
}

void MagStats::add_photon_blast(u8 blast) {
    u8 rank;

    if (blast >= 6) {
        return;
    }
    if (has_photon_blast(blast) != 0) {
        return;
    }
    if (!(photon_blast_flags & photon_blast_slots[0])) {
        photon_blasts |= blast;
        photon_blast_flags |= photon_blast_slots[0];
    } else if (!(photon_blast_flags & 2)) {
        photon_blasts |= blast << 3;
        photon_blast_flags |= photon_blast_slots[1];
    } else if (!(photon_blast_flags & 4)) {
        rank = blast;
        if ((photon_blasts & photon_blast_masks[0]) < blast) {
            rank--;
        }
        if (((photon_blasts & photon_blast_masks[1]) >> 3) < blast) {
            rank--;
        }
        if (rank < 4) {
            photon_blasts |= rank << 6;
        }
        photon_blast_flags |= photon_blast_slots[2];
    }
}

u32 MagOwnerWatch::test_flags(u32 mask) { return flags & mask; }
void MagOwnerWatch::set_flags(u32 mask) { flags |= mask; }
void MagOwnerWatch::clear_flags(u32 mask) { flags &= ~mask; }

int PlayerScaleState::is_scaled() { return test_flags_any(&flags, 1); }
f32 PlayerScaleState::get_scalar() { return scalar; }

s32 ProtectionTimer::get_frames() { return frames; }

void PhotonBlastGauge::clear_charge() {
    charge = 0.0f;
}

f32 PhotonBlastGauge::get_charge() { return charge; }

void PhotonBlastGauge::set_blast_level(s16 blast, s8 level) {
    blast_levels[blast] = level;
}

s32 TObjChara::is_in_fixed_pose() {
    return control_state == 7;
}

s32 TObjPlayer::get_photon_blast_charge() {
    return photon_blast_gauge.get_charge();
}
int TObjPlayer::is_frozen() { return (m_334 >> 9) & 1; }
s16 MagStats::get_synchro() { return synchro; }
s16 MagStats::get_iq() { return iq; }
u8 MagStats::get_color() { return color; }

void MagNodeOscillationState::copy_from(MagNodeOscillationState *src) {
    flags = src->flags;
    speed = src->speed;
    value = src->value;
    minimum = src->minimum;
    maximum = src->maximum;
}

void MagNodeOscillationState::disable() { flags = -32; }
int TItemMag::is_local() { return state & MAG_LOCAL; }

s16 TItemMag::get_def_level() { return stats.get_def_level(); }
s16 TItemMag::get_pow_level() { return stats.get_pow_level(); }
s16 TItemMag::get_dex_level() { return stats.get_dex_level(); }
s16 TItemMag::get_mind_level() { return stats.get_mind_level(); }
s16 TItemMag::get_iq() { return stats.iq; }
s16 TItemMag::get_synchro() { return stats.synchro; }
u32 TItemMagSub::test_flags(u32 mask) { return flags & mask; }

int TItemMagSub::is_growth_inactive() { return test_flags(0x40) == 0; }

void TItemMagSub::scale_owner_height(f32 factor) { owner_height_scale *= factor; }

void TItemMagSub::set_model(void *model_arg, u32 textures_arg, void *animation_arg) {
    model = model_arg;
    textures = textures_arg;
    animation = animation_arg;
    if (animation != NULL) {
        animation_frame = 0.0f;
        animation_length = (f32)((NJS_MOTION *)animation)->nbFrame - 1.0f;
    }
}

void TItemMagSub::set_material_node(s32 node, void *parameters) {
    node_ids[0] = node;
    if (parameters != 0) {
        copy_argb((NJS_ARGB *)material_parameters, (NJS_ARGB *)parameters);
    }
}

void TItemMagSub::set_node_id(s32 index, s32 id) { node_ids[index] = id; }

void TItemMagSub::set_flags(u32 value) { flags |= value; }

void TItemMag::load_data_files() {
    s32 i;
    s32 j;
    MagFollowParameters *motion;
    MagAxisOscillationParameters *axis;
    MagEditData *edit;

    item_mag_motions = (MagFollowParameters *)load_data_file(item_mag_motion_path);
    motion = item_mag_motions;
    for (i = 0; i < 90; i++, motion++) {
        bswap_32((u32 *)&motion->joint_index);
        bswap_32((u32 *)&motion->follow_scale);
        bswap_32((u32 *)&motion->drift_amplitude[0]);
        bswap_32((u32 *)&motion->drift_amplitude[1]);
        bswap_32((u32 *)&motion->drift_amplitude[2]);
        bswap_32((u32 *)&motion->base_rotation[0]);
        bswap_32((u32 *)&motion->base_rotation[1]);
        bswap_32((u32 *)&motion->base_rotation[2]);
        bswap_32((u32 *)&motion->drift_velocity[0]);
        bswap_32((u32 *)&motion->drift_velocity[1]);
        bswap_32((u32 *)&motion->drift_velocity[2]);
        axis = motion->translation;
        for (j = 0; j < 3; j++, axis++) {
            bswap_32((u32 *)&axis->amplitude);
            bswap_32((u32 *)&axis->unknown04);
            bswap_32((u32 *)&axis->phase_offset);
            bswap_32((u32 *)&axis->phase_velocity);
        }
    }
    edit = NULL;
    item_mag_edit_file = new RelocatedFile(item_mag_edit_path, 0x1000);
    if (item_mag_edit_file != NULL) {
        edit = (MagEditData *)item_mag_edit_file->get_root();
    }
    if (edit != NULL) {
        item_mag_motion_tables = edit->motion_tables;
    }
}

void TItemMag::cleanup() {
    delete item_mag_edit_file;
    free_data_file(item_mag_motions);
    item_mag_edit_file = NULL;
    item_mag_motion_tables = NULL;
    item_mag_motions = NULL;
}

TItem *TItemMag::create(u8 *item) {
    if (item != NULL) {
        return new TItemMag(tl_05, item);
    }
    return NULL;
}

#pragma push
#pragma opt_common_subs off
TItemMag::TItemMag(TObject *parent, u8 *item) : TItemEquipBase(parent, item) {
    s32 i;
    stats.init();
    m_name = item_mag_class_name;
    action_cooldown = 0.0f;
    fullness_frames = 6300.0f;
    feeds_while_full = 2.0f;
    TItemData::deserialize_mag(item, &stats);
    stats.photon_blast_flags &= ~0x40;
    set_item_index(stats.get_level());
    set_attach_slot(1);
    state = 0;
    for (i = 0; i < 2; i++) {
        children[i] = NULL;
        motion_types[i] = NULL;
    }
    load_param_record();
}
#pragma pop

TItemMag::~TItemMag() {}

void TItemMag::request_equipped_model() {
    u8 group = get_item_group();
    if (group >= 0x42) {
        group = 0x42;
    }
    request_model_load(group);
}

void TItemMag::release_model() {
    s32 i;
    for (i = 0; i != 2; i++) {
        if (children[i] != NULL) {
            children[i]->release_model_and_destroy();
            children[i] = NULL;
        }
    }
    TItemEquipBase::release_model();
}

void TItemMag::on_equip() {
    state = 0;
    if (owner->obj_isState2_324() == 0) {
        state = MAG_LOCAL;
        register_photon_blasts();
    }
    request_action(MAG_ACTION_IDLE);
    owner_watch.owner_level = owner->get_actor_level_index();
    if (owner_watch.area == -1) {
        owner_watch.area = get_current_floor_area();
    }
    owner_watch.hp = get_actor_hp(owner);
    owner_watch.tp = get_actor_tp(owner);
    if (test_flags_any(&effect_flags.bits, 1) != 0) {
        state &= ~MAG_INACTIVE;
    } else {
        state |= MAG_INACTIVE;
    }
    if (is_hidden() == 0 && owner->is_in_fixed_pose() == 0) {
        play_sound_effect(0x4000B20A, &owner->position, 0, 0);
    }
}

void TItemMag::on_unequip() {
    s32 slot;
    s32 blast;

    if (owner->obj_isState2_324() == 0) {
        assign_default_photon_blast_palette_slots((u8 *)owner->action_palettes);
        slot = 0;
        do {
            blast = stats.get_photon_blast(slot);
            if (blast != -1) {
                owner->photon_blast_gauge.set_blast_level(blast, -1);
            }
            slot += 1;
        } while (slot != 3);
        if (owner->is_flag_20000_set() == 0) {
            owner->photon_blast_gauge.clear_charge();
            send_6x3A_clear_photon_blast_ready_flag((u16 *)&owner->photon_blast_gauge);
        }
    }
    end_invincibility();
}

void TItemMag::write_item_data(TItemData *data) {
    TItemData::serialize_mag(data, &stats);
}

void TItemMag::render_equipped() {
    s32 scaled;
    TItemMagSub *child;
    s32 i;
    f32 scale;

    if (owner != NULL && obj_testFlags30(0x08000000) == 0 && is_hidden() == 0) {
        scaled = owner->scale_state.is_scaled();
        scale = owner->scale_state.get_scalar();
        push_matrix();
        TObjPlayer__sub_80364198();
        TObjPlayer::set_model_fade_alpha(get_owner_alpha());
        for (i = 0; i != 2; i++) {
            if (children[i] != NULL && children[i]->is_growth_inactive() != 0) {
                child = children[i];
                if (scaled != 0) {
                    child->scale_owner_height(scale);
                    child->render();
                    child->scale_owner_height(1.0f / scale);
                } else {
                    child->render();
                }
            }
        }
        TObjPlayer::warn_if_gauge_low();
        TObjPlayer__sub_8036414C();
        pop_matrix();
    }
}

void TItemMag::render_equipped_shadow() {
    s32 scaled;
    TItemMagSub *child;
    s32 i;
    f32 scale;

    if (owner != NULL && obj_testFlags30(0x08000000) == 0 && is_hidden() == 0) {
        scaled = owner->scale_state.is_scaled();
        scale = owner->scale_state.get_scalar();
        push_matrix();
        for (i = 0; i != 2; i++) {
            if (children[i] != NULL && children[i]->is_growth_inactive() != 0) {
                child = children[i];
                if (scaled != 0) {
                    child->scale_owner_height(scale);
                    child->render_shadows();
                    child->scale_owner_height(1.0f / scale);
                } else {
                    child->render_shadows();
                }
            }
        }
        pop_matrix();
    }
}

void TItemMag::update_owned() {
    if (stats.get_level() > 200 || (s16)stats.get_def_level() < 0 || (s16)stats.get_pow_level() < 0 ||
        (s16)stats.get_dex_level() < 0 || (s16)stats.get_mind_level() < 0) {
        refresh_if_current_player();
    }
}

void TItemMag::update_in_inventory() { tick_fullness_timer(); }

void TItemMag::update_equipped() {
    s8 events;

    tick_fullness_timer();
    bind_loaded_resources();
    if (state & MAG_INACTIVE) {
        return;
    }
    events = collect_owner_events();
    if (is_local() != 0) {
        if (is_current_area_item_enabled() != 0) {
            react_to_events(events);
            on_events_handled();
        } else {
            return;
        }
    }
    switch (state & MAG_ACTION_MASK) {
    case MAG_ACTION_IDLE:
        update_idle_action();
        break;
    case MAG_ACTION_SHIFTA_DEBAND:
        update_shifta_deband_action();
        break;
    case MAG_ACTION_RESTA:
        update_resta_action();
        break;
    case MAG_ACTION_REVERSER:
        update_reverser_action();
        break;
    case MAG_ACTION_WAIT:
        update_wait_action();
        break;
    case MAG_ACTION_LEVEL_UP:
        update_short_action();
        break;
    case MAG_ACTION_FED:
        update_long_action();
        break;
    case MAG_ACTION_INVINCIBILITY:
        update_invincibility_action();
        break;
    }
    action_frames++;
}

void TItemMag::update_idle_action() {
    f32 cooldown;

    cooldown = action_cooldown;
    if (0.0f < cooldown) {
        action_cooldown = cooldown - 1.0f;
    }
    if (obj_testFlags30(0x08000000) == 0) {
        set_subs_visible(1);
        return;
    }
    set_subs_visible(0);
}

void TItemMag::update_shifta_deband_action() {
    s32 frames;

    frames = action_frames;
    if (frames == 90) {
        cast_support_technique(13);
        cast_support_technique(10);
        return;
    }
    if (frames > 90) {
        request_action(MAG_ACTION_IDLE);
    }
}

void TItemMag::update_resta_action() {
    s32 frames;

    frames = action_frames;
    if (frames == 90) {
        if (get_actor_hp(owner) > 0) {
            cast_support_technique(15);
        }
    } else if (frames > 90) {
        request_action(MAG_ACTION_IDLE);
    }
}

void TItemMag::update_reverser_action() {
    s32 frames;

    frames = action_frames;
    if (frames == 90) {
        cast_support_technique(17);
        return;
    }
    if (frames > 90) {
        request_action(MAG_ACTION_IDLE);
    }
}

void TItemMag::update_wait_action() {
    s32 frames;

    frames = action_frames;
    if (frames != 90 && frames > 90) {
        request_action(MAG_ACTION_IDLE);
    }
}

void TItemMag::update_short_action() {
    if (action_frames > 45) {
        request_action(MAG_ACTION_IDLE);
    }
}

void TItemMag::update_long_action() {
    if (action_frames > 90) {
        request_action(MAG_ACTION_IDLE);
    }
}

void TItemMag::update_invincibility_action() {
    if (action_frames == 0) {
        start_invincibility();
    }
    refresh_invincibility();
    if (invincibility_frames <= action_frames) {
        end_invincibility();
        request_action(MAG_ACTION_IDLE);
    }
    if (action_frames % 60 == 0) {
        apply_switch_attack(0x6C);
    }
}

void TItemMag::start_invincibility() {
    invincibility_frames = 30.0f * (f32)((stats.get_synchro() + stats.get_iq()) / 3 + 40);
    if (invincibility_frames > 900) {
        invincibility_frames = 900;
    }
    if (owner != NULL && owner->protection.get_frames() < invincibility_frames) {
        owner->protection.set_frames(invincibility_frames);
        owner_watch.set_flags(0x100);
    }
}

void TItemMag::end_invincibility() {
    s32 left;

    if (owner != NULL && owner_watch.test_flags(0x100) != 0) {
        left = invincibility_frames - action_frames;
        if (left > 0) {
            TObjPlayer::decrement_clamp(&owner->protection.frames, left);
        }
        owner_watch.clear_flags(0x100);
    }
}

void TItemMag::refresh_invincibility() {
    TObjPlayer *player;
    s32 left;

    player = owner;
    if (player != NULL && player->protection.get_frames() == 0) {
        left = invincibility_frames - action_frames;
        if (left > 0) {
            owner->protection.set_frames(left);
        }
    }
}

void TItemMag::request_action(s32 action) {
    if ((TLobby::is_flag_set() != 0 || is_challenge_mode_active() != 0) &&
        (action == MAG_ACTION_REVERSER || action == MAG_ACTION_RESTA)) {
        return;
    }
    if (is_quest_active() != 0 && action == MAG_ACTION_REVERSER) {
        return;
    }
    if (action != MAG_ACTION_IDLE) {
        if (is_local() != 0 && !(0.0f < action_cooldown) && can_perform_action(action) != 0) {
            send_activate_effect(action);
        }
    } else {
        start_action(action);
    }
}

void TItemMag::start_action(s32 action) {
    end_invincibility();
    state &= 0xF0;
    state |= action;
    action_cooldown = 30.0f;
    action_frames = 0;
    set_action_motion();
    set_subs_visible(1);
}

void TItemMag::activate_effect(s32 action) { start_action(action); }

s32 TItemMag::apply_feed(MagStats *change) {
    TItem *weapon;

    if (change != NULL) {
        stats.add_def(change->def);
        stats.add_pow(change->pow);
        stats.add_mind(change->mind);
        stats.add_dex(change->dex);
        stats.add_iq(change->iq);
        stats.add_synchro(change->synchro);
        set_item_index(stats.get_level());
        if (get_mode() == 2) {
            refresh_owner_stats();
            if (owner->obj_isState2_324() == 0) {
                weapon = (TItem *)get_item_field_6__10TObjPlayerFPv(owner);
                if (weapon != NULL && weapon->check_equip_requirements(owner, NULL) == 0) {
                    TObjPlayer::send_6x26_unequip_item(owner, (void *)weapon->get_item_id());
                }
            }
        }
        evolve_by_level();
        return 1;
    }
    return 0;
}

void TItemMag::cast_support_technique(s32 technique) {
    TargetCursorList targets;
    s32 level = stats.iq / 40;

    if (owner == NULL) {
        return;
    }
    switch (technique) {
    case 13:
        TTecSifta::create(owner, &owner->position, (void *)level);
        break;
    case 10:
        TTecDeband::create((s32)owner, (s32)&owner->position, level);
        break;
    case 15:
        TTecResta::create(owner, &owner->position, (void *)level);
        break;
    case 17:
        ((TObjPlayer *)&targets)->construct_target_cursor_records();
        targets.count = 1;
        targets.records[0].id = get_entity_id(owner);
        targets.records[0].flag = 0;
        TTecReverser::create(owner, &owner->position, &targets, (void *)level);
        break;
    case 11:
        return;
    case 12:
        return;
    case 14:
        return;
    case 16:
        return;
    }
}

s32 TItemMag::feed(TItemData *food) {
    MagStats change;
    Vec pos;
    s32 *record;
    s8 *table;
    s32 i;

    if (food == NULL) {
        return 0;
    }
    change.init();
    change.iq = 0;
    change.synchro = 0;
    change.mind = 0;
    change.dex = 0;
    change.pow = 0;
    change.def = 0;
    if (food->data1.data_u8[0] == 3) {
        record = (s32 *)lookup_item_pmt_record(food->data1.data_u8);
        if (record != NULL) {
            table = (s8 *)get_mag_feed_result(feed_table, *record);
            if (table != NULL) {
                change.def = table[0];
                change.pow = table[1];
                change.dex = table[2];
                change.mind = table[3];
                change.iq = table[4];
                change.synchro = table[5];
                owner_watch.set_flags(MAG_EVENT_FED);
                if (0.0f != fullness_frames) {
                    feeds_while_full += 1.0f;
                } else {
                    fullness_frames = 6300.0f;
                }
            }
        }
    }
    if (is_hidden() == 0) {
        for (i = 0; i != 2; i++) {
            if (children[i] != NULL && children[i]->get_world_position(&pos) != 0) {
                spawn_particle_effect(&pos, 0x9B);
            }
        }
        play_sound_effect(0x5B211, &owner->position, 0, 0);
    }
    return apply_feed(&change);
}

s8 TItemMag::collect_owner_events() {
    s16 loss;
    s16 hp;
    s16 max_hp;
    s32 area;
    s8 events;

    if (!(state & MAG_ACTION_IDLE)) {
        return 0;
    }
    loss = 0;
    hp = get_actor_hp(owner);
    max_hp = ((TItemProShield *)owner)->get_field_2b8();
    events = 0;
    if (owner_watch.hp != hp) {
        if (hp < owner_watch.hp) {
            loss = owner_watch.hp - hp;
        }
        owner_watch.hp = hp;
    }
    if (hp == 0) {
        if (owner_watch.test_flags(MAG_EVENT_DEATH) == 0) {
            if (get_main_phase() == 0xE) {
                events |= MAG_EVENT_DEATH;
            }
            owner_watch.set_flags(MAG_EVENT_DEATH);
            stats.add_synchro(-5);
        }
    } else if (owner_watch.test_flags(MAG_EVENT_DEATH) != 0) {
        owner_watch.clear_flags(MAG_EVENT_DEATH);
    }
    if (hp * 10 < max_hp && max_hp <= loss * 5) {
        if (owner_watch.test_flags(MAG_EVENT_LOW_HP) == 0) {
            events |= MAG_EVENT_LOW_HP;
            owner_watch.set_flags(MAG_EVENT_LOW_HP);
        }
    } else if (owner_watch.test_flags(MAG_EVENT_LOW_HP) != 0) {
        owner_watch.clear_flags(MAG_EVENT_LOW_HP);
    }
    if (stats.synchro < 30) {
        if (owner_watch.test_flags(MAG_EVENT_LOW_SYNCHRO) == 0) {
            events |= MAG_EVENT_LOW_SYNCHRO;
            owner_watch.set_flags(MAG_EVENT_LOW_SYNCHRO);
        }
    } else if (stats.synchro > 100) {
        if (owner_watch.test_flags(MAG_EVENT_HIGH_SYNCHRO) == 0) {
            events |= MAG_EVENT_HIGH_SYNCHRO;
            owner_watch.set_flags(MAG_EVENT_HIGH_SYNCHRO);
        }
    } else {
        owner_watch.clear_flags(MAG_EVENT_LOW_SYNCHRO | MAG_EVENT_HIGH_SYNCHRO);
    }
    if (owner_watch.owner_level < owner->get_actor_level_index()) {
        owner_watch.owner_level = owner->get_actor_level_index();
        events |= MAG_EVENT_LEVEL_UP;
    }
    area = get_current_floor_area();
    if (owner_watch.area != area) {
        owner_watch.area = area;
        if (is_boss_area() == 1) {
            events |= MAG_EVENT_BOSS_AREA;
        }
    }
    if (100.0f == (f32)owner->get_photon_blast_charge() && owner_watch.test_flags(MAG_EVENT_PB_FULL) == 0) {
        owner_watch.set_flags(MAG_EVENT_PB_FULL);
        events |= MAG_EVENT_PB_FULL;
    } else if ((f32)owner->get_photon_blast_charge() < 100.0f && owner_watch.test_flags(MAG_EVENT_PB_FULL) != 0) {
        owner_watch.clear_flags(MAG_EVENT_PB_FULL);
    }
    if (owner_watch.test_flags(MAG_EVENT_FED) != 0) {
        owner_watch.clear_flags(MAG_EVENT_FED);
        events |= MAG_EVENT_FED;
    }
    return events;
}

void TItemMag::on_events_handled() {}

void TItemMag::react_to_events(s8 events) {
    rand();
    if (events & MAG_EVENT_PB_FULL) {
        if (roll_trigger(0) != 0) {
            request_action(trigger_actions[0]);
        }
    } else if (events & MAG_EVENT_LOW_HP) {
        if (roll_trigger(1) != 0) {
            request_action(trigger_actions[1]);
        }
    } else if (events & MAG_EVENT_DEATH) {
        if (roll_trigger(2) != 0) {
            request_action(trigger_actions[2]);
        }
    } else if (events & MAG_EVENT_BOSS_AREA) {
        if (roll_trigger(3) != 0) {
            request_action(trigger_actions[3]);
        }
    } else {
        if (events & MAG_EVENT_LEVEL_UP) {
            request_action(MAG_ACTION_LEVEL_UP);
            return;
        }
        if (events & MAG_EVENT_FED) {
            request_action(MAG_ACTION_FED);
            return;
        }
        if (events & MAG_EVENT_LOW_SYNCHRO) {
            request_action(MAG_ACTION_WAIT);
            return;
        }
        if (events & MAG_EVENT_HIGH_SYNCHRO) {
            request_action(MAG_ACTION_SHIFTA_DEBAND);
        }
    }
}

void TItemMag::evolve_by_level() {
    s8 stage;
    s16 level;
    u8 before;

    stage = get_evolution_stage();
    level = stats.get_level();
    before = get_item_group();
    if (evolution_levels[0] <= level && level < evolution_levels[1]) {
        if (stage < 1) {
            evolve_first_form();
        }
    } else if (evolution_levels[1] <= level && level < evolution_levels[2]) {
        if (stage < 2) {
            evolve_second_form();
        }
    } else if (evolution_levels[2] <= level && level % 5 == 0 && stage <= 3 && evolve_rare_form() == 0) {
        evolve_third_form();
    }
    if (before != get_item_group()) {
        on_form_changed();
    }
}

void TItemMag::on_form_changed() {
    MagPmtRecord *record;

    record = (MagPmtRecord *)TObjPlayer::get_pmt_record(get_item_group());
    if (record != NULL) {
        stats.add_photon_blast(record->photon_blast);
    }
    if (get_mode() == 2) {
        release_model();
        state |= MAG_FORM_CHANGED;
        request_equipped_model();
        register_photon_blasts();
    }
    if (is_hidden() == 0) {
        play_sound_effect(0x4000B20A, &owner->position, 0, 0);
    }
    load_param_record();
}

void TItemMag::evolve_first_form() {
    TObjPlayer *player;

    player = owner;
    if (player != NULL) {
        if (check_class_equip_permission(player, 0xF9) != 0) {
            evolve_into(1);
            return;
        }
        if (check_class_equip_permission(owner, 0xFA) != 0) {
            evolve_into(0xD);
            return;
        }
        if (check_class_equip_permission(owner, 0xFC) != 0) {
            evolve_into(0x19);
        }
    }
}

void TItemMag::evolve_second_form() {
    s32 dominant;
    u8 group;

    dominant = get_dominant_stats();
    group = get_item_group();
    switch (group) {
    case 1:
        if (dominant & 0x108) {
            evolve_into(0xE);
            return;
        }
        if (dominant & 0x10) {
            evolve_into(0xF);
            return;
        }
        if (dominant & 0x20) {
            evolve_into(4);
        }
        break;
    case 13:
        if (dominant & 0x110) {
            evolve_into(2);
            return;
        }
        if (dominant & 8) {
            evolve_into(3);
            return;
        }
        if (dominant & 0x20) {
            evolve_into(0xB);
            return;
        }
        break;
    case 25:
        if (dominant & 0x120) {
            evolve_into(0x1A);
            return;
        }
        if (dominant & 8) {
            evolve_into(0x1B);
            return;
        }
        if (dominant & 0x10) {
            evolve_into(0x14);
        }
        break;
    }
}

void TItemMag::evolve_third_form() {
    s16 def;
    s16 pow;
    s16 dex;
    s16 mind;
    s32 dominant;
    s8 section_id;
    TObjPlayer *player;

    if (owner != NULL) {
        dominant = get_dominant_stats();
        player = owner;
        section_id = player->section_id;
        pow = get_pow_level();
        dex = get_dex_level();
        mind = get_mind_level();
        def = get_def_level();
        if (check_class_equip_permission(owner, 0xF9) != 0) {
            if (dominant & 0x108) {
                if (!(section_id & 1)) {
                    if (mind <= dex) {
                        evolve_into(5);
                        return;
                    }
                    evolve_into(0xC);
                    return;
                }
                if (mind <= dex) {
                    evolve_into(6);
                    return;
                }
                evolve_into(8);
                return;
            }
            if (dominant & 0x10) {
                if (!(section_id & 1)) {
                    if (pow <= mind) {
                        evolve_into(0x13);
                        return;
                    }
                    evolve_into(0x17);
                    return;
                }
                if (pow <= mind) {
                    evolve_into(0x10);
                    return;
                }
                evolve_into(0x12);
                return;
            }
            if (dominant & 0x20) {
                if (!(section_id & 1)) {
                    if (dex <= pow) {
                        evolve_into(0x1E);
                        return;
                    }
                    evolve_into(7);
                    return;
                }
                if (dex <= pow) {
                    evolve_into(0x24);
                    return;
                }
                evolve_into(0x16);
            }
        } else if (check_class_equip_permission(owner, 0xFA) != 0) {
            if (dominant & 0x110) {
                if (!(section_id & 1)) {
                    if (pow <= mind) {
                        evolve_into(6);
                        return;
                    }
                    evolve_into(0xC);
                    return;
                }
                if (pow <= mind) {
                    evolve_into(5);
                    return;
                }
                evolve_into(0xA);
                return;
            }
            if (dominant & 8) {
                if (!(section_id & 1)) {
                    if (mind <= dex) {
                        evolve_into(6);
                        return;
                    }
                    evolve_into(0xC);
                    return;
                }
                if (mind <= dex) {
                    evolve_into(0x26);
                    return;
                }
                evolve_into(0xA);
                return;
            }
            if (dominant & 0x20) {
                if (!(section_id & 1)) {
                    if (dex <= pow) {
                        evolve_into(5);
                        return;
                    }
                    evolve_into(8);
                    return;
                }
                if (dex <= pow) {
                    evolve_into(0x1E);
                    return;
                }
                evolve_into(0x18);
            }
        } else if (check_class_equip_permission(owner, 0xFC) != 0) {
            if (dominant & 0x120) {
                if (def <= 44) {
                    if (!(section_id & 1)) {
                        if (dex <= pow) {
                            evolve_into(0x1C);
                            return;
                        }
                        evolve_into(0x1E);
                        return;
                    }
                    if (dex <= pow) {
                        evolve_into(9);
                        return;
                    }
                    evolve_into(0x17);
                    return;
                }
                evolve_into(0x24);
                return;
            }
            if (dominant & 8) {
                if (def <= 44) {
                    if (!(section_id & 1)) {
                        if (mind <= dex) {
                            evolve_into(0x25);
                            return;
                        }
                        evolve_into(0x1F);
                        return;
                    }
                    if (mind <= dex) {
                        evolve_into(0x20);
                        return;
                    }
                    evolve_into(0x1C);
                    return;
                }
                evolve_into(0x23);
                return;
            }
            if (dominant & 0x10) {
                if (def <= 44) {
                    if (!(section_id & 1)) {
                        if (pow <= mind) {
                            evolve_into(0x11);
                            return;
                        }
                        evolve_into(0x15);
                        return;
                    }
                    if (pow <= mind) {
                        evolve_into(0xC);
                        return;
                    }
                    evolve_into(0x12);
                    return;
                }
                evolve_into(0x24);
            }
        }
    }
}

s32 TItemMag::evolve_rare_form() {
    s16 def;
    s16 mind;
    s16 dex;
    u8 before;
    s32 index;
    s16 pow;
    s8 section;

    before = get_item_group();
    if (owner != NULL && stats.get_level() >= 100) {
        section = (s8)owner->section_id % 3;
        pow = get_pow_level();
        dex = get_dex_level();
        mind = get_mind_level();
        def = get_def_level();
        index = (u32)__cntlzw(check_class_equip_permission(owner, 0x7F)) >> 5;
        index += section * 2;
        if (check_class_equip_permission(owner, 0xF9) == 0) {
            if (check_class_equip_permission(owner, 0xFA) != 0) {
                index += 6;
            } else if (check_class_equip_permission(owner, 0xFC) != 0) {
                index += 12;
            }
        }
        if (check_class_equip_permission(owner, 0xF9) != 0) {
            switch (section) {
            case 0:
                if (pow + mind == def + dex) {
                    evolve_into(rare_forms[index]);
                }
                break;
            case 1:
                if (pow + dex == mind + def) {
                    evolve_into(rare_forms[index]);
                }
                break;
            case 2:
                if (pow + def == mind + dex) {
                    evolve_into(rare_forms[index]);
                }
                break;
            }
        } else if (check_class_equip_permission(owner, 0xFA) != 0) {
            switch (section) {
            case 0:
                if (pow + mind == def + dex) {
                    evolve_into(rare_forms[index]);
                }
                break;
            case 1:
                if (pow + dex == mind + def) {
                    evolve_into(rare_forms[index]);
                }
                break;
            case 2:
                if (pow + def == mind + dex) {
                    evolve_into(rare_forms[index]);
                }
                break;
            }
        } else if (check_class_equip_permission(owner, 0xFC) != 0) {
            switch (section) {
            case 0:
                if (pow + mind == def + dex) {
                    evolve_into(rare_forms[index]);
                }
                break;
            case 1:
                if (pow + dex == mind + def) {
                    evolve_into(rare_forms[index]);
                }
                break;
            case 2:
                if (pow + def == mind + dex) {
                    evolve_into(rare_forms[index]);
                }
                break;
            }
        }
    }
    return get_item_group() != before;
}

s32 TItemMag::get_dominant_stats() {
    s32 dominant;
    s16 pow;
    s16 dex;
    s16 mind;
    s16 highest;
    s32 ties;

    dominant = 0;
    pow = get_pow_level();
    dex = get_dex_level();
    mind = get_mind_level();
    get_def_level();
    if (dex < pow && mind < pow) {
        dominant |= 8;
    }
    if (pow < dex && mind < dex) {
        dominant |= 0x10;
    }
    if (dex < mind && pow < mind) {
        dominant |= 0x20;
    }
    highest = dex;
    ties = 0;
    if (pow > dex) {
        highest = pow;
    }
    if (highest > mind) {
        highest = dex;
        if (pow > dex) {
            highest = pow;
        }
    } else {
        highest = mind;
    }
    {
        s32 max32 = highest;
        if (pow == max32) {
            ties = 1;
        }
        if (dex == max32) {
            ties += 1;
        }
        if (mind == max32) {
            ties += 1;
        }
    }
    if (ties >= 2) {
        dominant |= 0x100;
    }
    return dominant;
}

s32 TItemMag::get_evolution_stage() {
    u8 group;
    u8 model;

    group = get_item_group();
    model = group;
    if (group >= 0x42) {
        model = 0x42;
    }
    if (model <= 0x42) {
        return ((MagEditData *)item_mag_edit_file->get_root())->evolution_stages[model];
    }
    return 0;
}

void TItemMag::set_subs_visible(s32 visible) {
    s32 i;
    for (i = 0; i != 2; i++) {
        if (children[i] != NULL) {
            if (visible) {
                ((TQuestVmDownLoadServer *)children[i])->clear_flag4_bit4();
            } else {
                children[i]->suspend_update();
            }
        }
    }
}

void TItemMag::on_model_loaded() {
    u8 group = get_item_group();
    MagEditData *edit;
    s8 *ids;
    s32 motion;
    NJS_ARGB *color;
    MagNodeOscillationState *oscillations;
    s32 i;
    s32 row;

    if (group >= 0x42) {
        group = 0x42;
    }
    if (stats.get_color() >= 18) {
        resolve_color();
    }
    row = group * 12;
    for (i = 0; i != 2; i++) {
        motion_types[i] = item_mag_motion_tables[get_model_variant()];
        motion_types[i] += row + i * 6;
        motion = *motion_types[i];
        if (motion != -1) {
            children[i] = new TItemMagSub(owner, this);
            if (children[i] != NULL) {
                children[i]->set_motion_type(motion);
                if (i == 1 && second_model != NULL) {
                    children[i]->set_model(second_model, texlist, model_motion);
                } else {
                    children[i]->set_model(item_model, texlist, model_motion);
                }
                edit = (MagEditData *)item_mag_edit_file->get_root();
                color = &edit->colors[stats.get_color()];
                children[i]->set_material_node((s8)edit->material_nodes[group], color);
                switch (group) {
                case 0x0E:
                    children[i]->set_node_id(1, 2);
                    children[i]->set_node_id(2, 4);
                    break;
                case 0x13:
                    children[i]->set_node_id(1, 3);
                    break;
                case 0x15:
                    children[i]->set_node_id(1, 3);
                    break;
                case 0x1E:
                    children[i]->set_node_id(1, 3);
                    children[i]->set_node_id(2, 5);
                    break;
                case 0x25:
                    children[i]->set_node_id(1, 3);
                    break;
                case 0x40:
                    children[i]->set_node_id(1, 2);
                    children[i]->set_node_id(2, 5);
                    break;
                case 0x41:
                    children[i]->set_node_id(1, 3);
                    break;
                }
            }
        }
    }
    edit = (MagEditData *)item_mag_edit_file->get_root();
    oscillations = edit->oscillations;
    ids = edit->oscillation_ids + group * 2;
    for (i = 0; i != 2; i++) {
        if (children[i] != NULL) {
            if (second_model != NULL && ids[1] != -1) {
                if (i == 0) {
                    if (ids[0] != -1) {
                        children[i]->oscillations[0].copy_from(&oscillations[ids[0]]);
                    } else {
                        children[i]->oscillations[0].disable();
                    }
                    children[i]->oscillations[1].disable();
                } else {
                    children[i]->oscillations[0].copy_from(&oscillations[ids[1]]);
                    children[i]->oscillations[1].disable();
                }
            } else {
                if (ids[0] != -1) {
                    children[i]->oscillations[0].copy_from(&oscillations[ids[0]]);
                } else {
                    children[i]->oscillations[0].disable();
                }
                if (ids[1] != -1) {
                    children[i]->oscillations[1].copy_from(&oscillations[ids[1]]);
                } else {
                    children[i]->oscillations[1].disable();
                }
            }
            if ((state & MAG_FORM_CHANGED) && is_hidden() == 0) {
                new TItemMagGrowEff(tl_05, children[i]);
            }
        }
    }
    state &= ~MAG_FORM_CHANGED;
}

void TItemMag::set_action_motion() {
    s32 i;
    TItemMagSub *child;
    s16 action;

    for (i = 0; i != 2; i++) {
        child = children[i];
        if (child != NULL) {
            action = state & MAG_ACTION_MASK;
            if (action > 0 && action < 6) {
                child->transition_motion_type(motion_types[i][action - 1]);
            } else if (action >= 6 && action < 8) {
                child->transition_motion_type(motion_types[i][5]);
            } else if (action == 8) {
                child->transition_motion_type(motion_types[i][3]);
            }
        }
    }
}

s32 TItemMag::get_model_variant() { return 0; }

void TItemMag::evolve_special_form(u8 kind) {
    u8 before;

    before = get_item_group();
    switch (kind) {
    case 0:
        if (owner->section_id & 1) {
            evolve_into(0x1D);
        } else {
            evolve_into(0x21);
        }
        break;
    case 1:
        if (owner->section_id & 1) {
            evolve_into(0x22);
        } else {
            evolve_into(0x27);
        }
        break;
    case 2:
        evolve_into(0x28);
        break;
    case 3:
        evolve_into(0x29);
        break;
    case 4:
        evolve_into(0x2A);
        break;
    case 5:
        evolve_into(0x2B);
        break;
    }
    if (before != get_item_group()) {
        on_form_changed();
    }
}

void TItemMag::set_triggers(const u8 *actions, const u8 *modes) {
    memcpy(trigger_actions, actions, 4);
    memcpy(trigger_modes, modes, 4);
}

s32 TItemMag::roll_trigger(s32 trigger) {
    s16 synchro;
    u8 rate;
    u8 synchro_rate;
    u8 base;

    synchro = stats.synchro;
    if (synchro < 31) {
        synchro_rate = 0;
    } else if (synchro < 61) {
        synchro_rate = 15;
    } else if (synchro < 81) {
        synchro_rate = 25;
    } else if (synchro < 101) {
        synchro_rate = 30;
    } else {
        synchro_rate = 35;
    }
    rate = 0;
    if (trigger_actions[trigger] != 0) {
        switch (trigger_modes[trigger]) {
        case 0:
            rate = activation_rate;
            break;
        case 1:
            rate = activation_rate + synchro_rate;
            break;
        case 2:
            rate = synchro_rate;
            break;
        case 3:
            base = activation_rate;
            if (base > 10) {
                rate = base - 10;
            } else {
                rate = 0;
            }
            break;
        case 4:
            if (synchro_rate > 10) {
                rate = synchro_rate - 10;
            } else {
                rate = 0;
            }
            break;
        }
        if ((u8)(s32)(100.0f * (3.05175781e-05f * (f32)rand())) < rate) {
            return 1;
        }
    }
    return 0;
}

s32 TItemMag::is_owner_frozen() {
    s32 frozen;

    frozen = 0;
    if (owner != NULL && owner->is_frozen() != 0) {
        frozen = 1;
    }
    return frozen;
}

u32 TItemMag::is_owner_acting() {
    u8 acting;

    acting = 0;
    if (owner->test_action_mask(4) || owner->test_action_mask(0x10)) {
        acting = 1;
    }
    return acting;
}

void TItemMag::tick_fullness_timer() {
    if (0.0f != fullness_frames) {
        fullness_frames -= 1.0f;
        if (0.0f == fullness_frames) {
            feeds_while_full = 0.0f;
        }
    }
}

void TItemMag::register_photon_blasts() {
    s32 blast;
    s32 slot;

    assign_default_photon_blast_palette_slots((u8 *)owner->action_palettes);
    slot = 0;
    do {
        blast = stats.get_photon_blast(slot);
        if (blast != -1) {
            owner->photon_blast_gauge.set_blast_level(blast, get_item_index());
            assign_photon_blast_palette_slot((u8 *)owner->action_palettes, (s16)blast);
        }
        slot += 1;
    } while (slot != 3);
}

void TItemMag::load_param_record() {
    MagPmtRecord *record;

    record = (MagPmtRecord *)TObjPlayer::get_pmt_record(get_item_group());
    if (record != NULL) {
        feed_table = record->feed_table;
        activation_rate = record->activation_rate;
        set_triggers(record->trigger_actions, record->trigger_modes);
    }
}

s32 TItemMag::can_perform_action(s32 action) {
    s16 hp;

    hp = get_actor_hp(owner);
    if (action == MAG_ACTION_REVERSER) {
        if (hp != 0) {
            return 0;
        }
    } else if (hp == 0) {
        return 0;
    }
    return 1;
}

s32 TItemMag::check_evolution_cond(TObjPlayer *player, s32 kind) {
    TItemMag *mag;
    s32 count;

    if (player != NULL && (mag = (TItemMag *)player->activate_d04_slot()) != NULL) {
        switch (kind) {
        case 0:
            if (mag->get_item_index() >= 100) {
                return 1;
            }
            break;
        case 1:
            if (mag->get_item_index() >= 100) {
                return 1;
            }
            break;
        case 2:
            count = 0;
            if (mag->get_def_level() >= 70) {
                count = 1;
            }
            if (mag->get_pow_level() >= 70) {
                count += 1;
            }
            if (mag->get_dex_level() >= 70) {
                count += 1;
            }
            if (mag->get_mind_level() >= 70) {
                count += 1;
            }
            if (count >= 2) {
                return 1;
            }
            break;
        case 3:
            if (mag->get_item_index() >= 100) {
                return 1;
            }
            break;
        case 4:
            if (mag->get_item_index() >= 120 && mag->get_iq() >= 180 && mag->get_synchro() >= 110) {
                return 1;
            }
            break;
        case 5:
            if (mag->get_def_level() >= 35 && mag->get_pow_level() >= 35 && mag->get_dex_level() >= 35 &&
                mag->get_mind_level() >= 35) {
                return 1;
            }
            break;
        }
    }
    return 0;
}

void TItemMag::snap_to_owner() {
    s32 i;
    for (i = 0; i != 2; i++) {
        if (children[i] != NULL) {
            children[i]->set_flags(2);
            TItemAttacker::spawn_item_timer(children[i], (ItemTimerCallback)TItemMagSub::clear_optional_oscillation_flag, 30);
        }
    }
}

void TItemMag::evolve_into(u8 form) {
    if (get_evolution_stage() < 4) {
        set_item_group(form);
    }
}

void TItemMag::carry_over_stats(TItemData *data, TItem *mag) {
    u8 type = data->data1.data_u8[1];
    mag->copy_to_item_data(data);
    data->data1.data_u8[1] = type;
}

#pragma push
#pragma opt_lifetimes off
void TItemMag::resolve_color() {
    u8 color;

    if (check_class_equip_permission(owner, 0xD7) != 0) {
        color = owner->skin;
    } else {
        color = owner->costume;
    }
    color = color % 9;
    if (color >= 7) {
        color = 9.0f * (3.05175781e-05f * (f32)rand());
    }
    if (3.05175781e-05f * (f32)rand() < 0.5f) {
        color += 9;
    }
    stats.color = color;
}
#pragma pop
