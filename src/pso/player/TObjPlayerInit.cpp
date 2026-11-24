#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/item/TItemLockCountCtrl_8011E184.h"
#include "pso/player/TObjPlayer_801BF918.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSyncRecord.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/ui/window/TWindowActionPalette_801C1890.h"
#include "pso/unk/TUnk_804ED7D0.h"
#include "pso/unk/TUnk_804DDBF0.h"
#include "pso/unk/TLobby.h"
#include "pso/player/PlayerClassTechniques.h"
#include "pso/player/PlayerRequirementStats.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_801BE778.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TPlyDispData.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/TObjPlayer_801BF978.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_80011014.h"

// The init_* / release_* steps the TObjPlayer constructors and destructor run
// for each part of the player.

extern const f32 TObjPlayer__data_805DC278;
extern const f32 TObjPlayer__data_805DC28C;

extern "C" {
// Defined with the player's main code (TObjPlayer.cpp, TObjPlayer_801AF2F0.cpp, TObjPlayer_801BDF5C.cpp).
void update_photon_chair__10TObjPlayerFv(void *player);
s8 get_class_index__10TObjPlayerFv(TObjPlayer *player);
void TObjPlayer__sub_801BEF44(StatusEffect *dst, const StatusEffect *src);
int TObjPlayer__sub_801BEF60(PlayerPadBinding *binding, int value);
u8 TObjPlayer__sub_801BEB8C(PlayerSyncRecord *record);
u8 TObjPlayer__sub_801BEBB8(PlayerSyncRecord *record);
u8 TObjPlayer__sub_801BEBE4(PlayerSyncRecord *record);
u8 TObjPlayer__sub_801BEC10(PlayerSyncRecord *record);
u8 TObjPlayer__sub_801BEC3C(PlayerSyncRecord *record);
// TObjPlayer.h declares the tech index as int; the callers pass it as a short.
void set_technique_level_clamped__10TObjPlayerFP10TObjPlayerUci(TObjPlayer *player, u8 level, s16 tech);
}

void TObjPlayer::reset_state() {
    ((FlagWord *)((u8 *)this + 0x858))->clear(2);
    battle_music.reset_counter_field4();
    protection.reset_type();
    ((TObjPlayer *)((u8 *)this + 0x7CC))->reset_movement_state();
    movement_hold.reset();
    ((TObjPlayer *)((u8 *)this + 0x608))->set_vec4_const();
    death_fade = NULL;
    action_palette_state.init_tag();
    freeze_escape_step = 0;
    clear_state_flags(0x283);
    m_3f4 = 0;
    target_heading = 0;
    m_3ec = 0;
    move_target.z = TObjPlayer__data_805DC278;
    move_target.y = TObjPlayer__data_805DC278;
    move_target.x = TObjPlayer__data_805DC278;
    velocity.z = TObjPlayer__data_805DC278;
    velocity.y = TObjPlayer__data_805DC278;
    velocity.x = TObjPlayer__data_805DC278;
    death_sink.reset();
}

void TObjPlayer::release_child_object() {
    delete action_provider;
}

void TObjPlayer::init_action_provider() {
    if (TObjPlayer::get_hold_effect_count() == 1) {
        action_provider = new TUnk_804DDBF0;
    } else if (TObjPlayer::get_hold_effect_count() == 0) {
        action_provider = new TUnk_804ED7D0;
    }
    m_33b = 0;
    unk_33A[0] = 0;
    m_339 = 0;
    unk_338[0] = 0;
    action_state = 0;
    m_36c = 0;
    pad_370 = 0;
    reset_entrance_id();
    ((TObjPlayer *)((u8 *)this + 0x66C))->set_vec3_const();
    frame_timer = TObjPlayer__data_805DC278;
    state_flags = 0;
    set_input_mode(0);
    set_move_mode(0);
    lobby_animation = -1;
    *(f32 *)&m_3c4 = TObjPlayer__data_805DC278;
    set_battle_flag(0);
    controller_input = NULL;
    inventory_objects = NULL;
    lock_on_cursor = NULL;
    joint_matrices = NULL;
    item_node_matrices = NULL;
    set_floor_index(0xF);
    set_floor(0xF);
    m_54c = 0;
    *(s32 *)&unk_3B8 = 0;
    *(s32 *)&unk_420 = 0;
    controller_port = 0;
    reset_state();
    ::set_flag_400000(this);
    if (TObjPlayer::get_player_count() == 1) {
        set_player_pk_mode_flag((u8 *)&m_828);
    }
}

void TObjPlayer::init_battle(void *record) {
    assign_owner_ids();
    ::set_flag_400000(this);
    ((TObjPlayer *)((u8 *)this + 0x634))->enter_battle_state();
}

void TObjPlayer::reset_area_entry_state() {
    follow_particles.create_hand_particles(this);
    ((TObjPlayer *)((u8 *)this + 0x634))->enter_battle_state();
    if (TObjPlayer::is_locally_controlled(this) != 0) {
        TObjPlayer::for_each_player_slot(update_photon_chair__10TObjPlayerFv);
    }
}

void TObjPlayer::destroy_owned_object() {
    if (death_fade != NULL) {
        death_fade->queue_destruction();
        death_fade = NULL;
    }
}

void TObjPlayer::assign_owner_ids() {
    TObjPlayer__sub_801BF9E0((u8 *)this + 0x634, get_entity_id());
    follow_particles.set_owner(this);
    chair_seat.set_owner_id(get_entity_id());
}

// A remote player's technique levels (with their bonus) and status effects.
void TObjPlayer::init_session_technique_caps(PlayerSyncRecord *record) {
    s32 i;

    TObjPlayer__sub_801C1F78(&photon_blast_gauge, get_entity_id());
    init_class_technique_caps(&technique_state, get_class_index__10TObjPlayerFv(this));
    ((TObjPlayer *)&technique_state)->copy_all_technique_entries((void *)0x1D);
    for (i = 0; i < 0x13; i++) {
        set_technique_level_clamped__10TObjPlayerFP10TObjPlayerUci(this, record->technique_levels[i] + record->items[i].m_present[2], i);
    }
    for (i = 0; i < 5; i++) {
        TObjPlayer__sub_801BEF44(&status_effects[i], &record->status_effects[i]);
    }
}

void TObjPlayer::reset_technique_caps() {}

void TObjPlayer::release_technique_caps() {}

extern "C" s32 get_record_byte_at(void *record, s32 index);

// A saved character's technique levels.
void TObjPlayer::init_saved_technique_caps(TPlyCharData *record) {
    s32 i;

    TObjPlayer__sub_801C1F78(&photon_blast_gauge, get_entity_id());
    init_class_technique_caps(&technique_state, get_class_index__10TObjPlayerFv(this));
    ((TObjPlayer *)&technique_state)->copy_all_technique_entries((void *)0x1D);
    i = 0;
    do {
        set_technique_level_clamped__10TObjPlayerFP10TObjPlayerUci(this, ((TObjPlayer *)record)->get_slot_value_checked(i) + get_record_byte_at(record, i), i);
        i += 1;
    } while (i < 0x13);
}

void TObjPlayer::init_session_area_sync(void *record) {}

void TObjPlayer::update_state() {
    if (obj_isState2_324() != 0) {
        clear_flag_400000();
    } else {
        sync_current_area();
        sync_current_floor();
    }
    if (TObjPlayer::is_final_phase() != 0 && sub_801A1DDC() != 0) {
        apply_state_transform();
    }
}

void TObjPlayer::release_area_sync() {}

void TObjPlayer::update_if_active() {
    if (is_script_controlled() != 0) {
        sync_current_area();
        sync_current_floor();
    }
}

void TObjPlayer::load_char_data(PlayerSyncRecord *record) {
    sub_801BEE2C(record->hp_material_bonus);
    sub_801BEE24(record->tp_material_bonus);
    set_field_374(TObjPlayer__sub_801BEC3C(record));
    set_field_374_state(TObjPlayer__sub_801BEC10(record));
    set_inventory_state(TObjPlayer__sub_801BEBE4(record));
    set_equip_flags(TObjPlayer__sub_801BEBB8(record));
    set_luck_materials_used(TObjPlayer__sub_801BEB8C(record));
    init_player_data(&record->stats);
    hp = record->current_hp;
    resend_status_effects();
}

int TObjPlayer::can_cast_technique() { return TObjPlayer::check_technique_castable((saddr)this); }

void TObjPlayer::release_char_data() {}

void TObjPlayer::init_player_data(void *src) {
    f32 proportions;
    f32 tp_factor;

    proportions = base_stats.proportions;
    TLobby::copy_data(&base_stats, src);
    base_stats.proportions = proportions;
    stat_block = &base_stats;
    apply_input_mode();
    set_move_mode_from_class_flags();
    init_trait_flags();
    ((TLobby *)((u8 *)this + 0xD5C))->copy_from((void *)get_class_attack_template(this));
    ((TLobby *)((u8 *)this + 0xD8C))->copy_entry((void *)get_class_defense_template(this));
    tp_factor = get_tp_class_factor();
    recalc_combat_stats(stat_block, &attack_stats, &resistance_stats, get_class_hp_factor(), tp_factor);
    *(f32 *)((u8 *)bodies + 4) = TObjPlayer__data_805DC28C * stat_block->proportions;
}

int TObjPlayer::is_flag_set_550(void *record) { return TObjPlayer__sub_801BEF60(&pad_binding, 0); }

void TObjPlayer::reset_pad_binding() {}

void TObjPlayer::release_pad_binding() {}

void TObjPlayer::init_control_mode(s32 role) {
    if (TObjPlayer::is_locally_controlled(this) != 0) {
        controller_port = role & 3;
        pad_binding.init(get_entity_id(), controller_port);
        return;
    }
    TObjPlayer__sub_801BEF60(&pad_binding, 0);
}

void TObjPlayer::init_data_table_ptr() {
    create_inventory();
    set_action_provider_variant(default_action_provider_variant());
    item_node_matrices = player_shared_buffer_base[get_entity_id()];
}

void TObjPlayer::init_from_source(PlayerSyncRecord *record) {
    inventory_objects = NULL;
    create_inventory();
    set_action_provider_variant(default_action_provider_variant());
    bind_saved_inventory_equipment(this, record->items, record->item_count);
    item_node_matrices = player_shared_buffer_base[get_entity_id()];
}

void TObjPlayer::update_recobox(saddr player) {
    if (is_current_area_item_enabled() != 0) {
        ((TObjPlayer *)player)->clear_flag_20000();
        return;
    }
    ((TObjPlayer *)player)->set_flag_20000();
}

void TObjPlayer::destroy_child() {
    if (inventory_objects != NULL) {
        ((TObject *)inventory_objects)->queue_destruction();
    }
}
