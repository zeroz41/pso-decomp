#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/PlayerState.h"
#include "pso/player/PlayerTaskEffects.h"
#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/MovementHistory.h"
#include "pso/network/client_id.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/network/TLobby.h"
#include "pso/system/vector.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TForceOperate.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/data/FlagWord.h"
#include "pso/item/TItemLockCountCtrl_8011E184.h"
#include "pso/player/PlayerSyncRecord.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/player/LobbyPlayerActionProvider.h"
#include "pso/player/GamePlayerActionProvider.h"
#include "pso/player/PlayerClassTechniques.h"
#include "pso/player/PlayerRequirementStats.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TPlyDispData.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/TPlyCharData.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TPlyDispConfig.h"
#include "pso/player/TObjPlayer_801D6C4C.h"
#include "pso/player/TObjPlayer_80309D80.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/boss/olgaflow/TBoss6Type2_8036DC80.h"
#include "pso/player/TObjEndingPlayer.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/player/TObjPlayerSet.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayerCreate.h"
#include "pso/player/PlayerCharDataEntry.h"
#include "pso/object/TObjWaitEntryHairMoveSim.h"


extern "C" {

s32 get_main_phase();
}
extern "C" {
TObjPlayerSet *find_player_arrival_set(TObjPlayer *player, s32 slot);
void *consume_telepipe_arrival(u16, void *);

void TObjPlayer::place_on_area_entry() {
    void *p;
    ArrivalOverride *e;
    TObjPlayerSet *other;

    if (get_main_phase() == 0xE && TObjPlayer::is_single_screen() == 0 &&
        this->is_locally_controlled() != 0 && this->has_active_camera_event() == 0 &&
        this->check_flag(0x100000) == 0 && TObjPlayer::is_key_machine_ready() != 0) {
        this->set_state_flags(0x100000);
        this->set_position_from(this->get_lobby_entry_ptr());
        this->rotation_y = get_lobby_entry_yaw();
        send_impose_hold(this, 0x1E);
        TObjPlayer::set_camera_mode(3);
        new TForceOperate(tl_02, get_entity_id());
    } else if (this->obj_isState2_324() == 0) {
        p = consume_telepipe_arrival(get_entity_id(), (u8 *)&this->rotation_y);
        if (p != NULL) {
            this->set_position_from(p);
        } else {
            e = &player_arrival_overrides[get_entity_id()];
            if (this->obj_isState2_324() == 0 && e->get_active() == 1) {
                e->set_active(0);
                this->rotation_y = e->get_heading();
                this->set_position_from(e->get_pos());
            } else {
                other = find_player_arrival_set(this, get_entity_id());
                if (other != NULL) {
                    this->set_position_from(&other->position);
                    this->rotation_y = other->rotation_y;
                } else {
                    this->set_position(player_zero, player_zero, player_zero);
                }
            }
        }
    }
    this->save_previous_position();
    this->calc_attach_pos();
    calc_marker_position(&this->marker_position, this);
    this->set_position_history_entry(0, this->position.x, this->position.z);
    clear_movement_history(&this->movement_history);
    if (TObjPlayer::is_single_screen() != 0) {
        reset_cameras_to_actor(this, 0);
    } else if (this->sub_801A1DDC() != 0) {
        TObjPlayer *player;
        if (this->is_locally_controlled() == 0 && (player = get_player_by_client_id(local_client_id)) != NULL) {
            reset_cameras_to_actor(player, 0);
        } else {
            reset_cameras_to_actor(this, 0);
        }
    }
}
void TObjPlayer__sub_801BEEAC(MovementHold *dst, MovementHold *src);
void TObjPlayer__sub_801BEEE0(void *p, void *q);
void TObjPlayer__sub_801BEF30(void *p, void *q);

s32 TObjPlayer::has_active_camera_event() {
    if (TLobby::get_instance() == 0) {
        if ((TObjPlayer::check_camera_mode() == 0) && (TLevelSelect::get_difficulty_flag_bit(0, 0xB) == 0) && (TLevelSelect::get_difficulty_flag_bit(1, 0xB) == 0) && (TLevelSelect::get_difficulty_flag_bit(2, 0xB) == 0) && (TLevelSelect::get_difficulty_flag_bit(3, 0xB) == 0)) {
            return 0;
        }
        goto block_14;
    }
    if ((TLobby::get_instance() == 1) && (TObjPlayer::check_camera_mode() == 0) && (TLevelSelect::get_difficulty_flag_bit(0, 0x5B) == 0) && (TLevelSelect::get_difficulty_flag_bit(1, 0x5B) == 0) && (TLevelSelect::get_difficulty_flag_bit(2, 0x5B) == 0) && (TLevelSelect::get_difficulty_flag_bit(3, 0x5B) == 0)) {
        return 0;
    }
block_14:
    return 1;
}
void TObjPlayer::release_area_placement() {  }
void TObjPlayer::init_from_data(PlayerSyncRecord *record) {
    init_action_provider();
    entity_id = record->client_id;
    alt_room = record->room_id;
    actorFlags = record->game_flags;
    copy_xyz(&rotation_x, record->angle);
    mode = record->phase;
    hp = record->current_hp;
    ((TLobby *)&guild_card_tag)->copy_header_struct(&record->player_tag);
    TObjPlayer__sub_801BEF30(&pk_state, &record->unknown_a6);
    ((TObjPlayer *)&telepipe)->copy_player_record_header((u8 *)&record->telepipe);
    TObjPlayer__sub_801BEEE0(&death_flags, &record->death_flags);
    TObjPlayer__sub_801BEEAC(&movement_hold, (MovementHold *)&record->hold_state);
    set_floor_index(record->area);
    set_floor(record->floor);
    state_flags = record->player_flags;
    set_language(record->language);
}

}

// The init_* / release_* steps the TObjPlayer constructors and destructor run
// for each part of the player.


extern "C" {
// Defined with the player's main code (TObjPlayer.cpp, TObjPlayer_801AF2F0.cpp).
void update_photon_chair__10TObjPlayerFv(void *player);
void TObjPlayer__sub_801BEF44(StatusEffect *dst, StatusEffect *src);
// TObjPlayer.h declares the tech index as int; the callers pass it as a short.
void set_technique_level_clamped__10TObjPlayerFP10TObjPlayerUci(TObjPlayer *player, u8 level, s16 tech);
}

void TObjPlayer::reset_state() {
    ((FlagWord *)((u8 *)this + 0x858))->clear(2);
    battle_music.reset_counter_field4();
    protection.reset_type();
    attack_state.reset();
    movement_hold.reset();
    render_material_state.reset_fade_color();
    death_fade = NULL;
    action_palette_state.init_tag();
    freeze_escape_step = 0;
    clear_state_flags(0x283);
    m_3f4 = 0;
    target_heading = 0;
    m_3ec = 0;
    move_target.z = player_zero;
    move_target.y = player_zero;
    move_target.x = player_zero;
    velocity.z = player_zero;
    velocity.y = player_zero;
    velocity.x = player_zero;
    death_sink.reset();
}

void TObjPlayer::release_child_object() {
    delete action_provider;
}

void TObjPlayer::init_action_provider() {
    if (get_player_action_provider_selector() == 1) {
        action_provider = new GamePlayerActionProvider;
    } else if (get_player_action_provider_selector() == 0) {
        action_provider = new LobbyPlayerActionProvider;
    }
    m_33b = 0;
    unk_33A[0] = 0;
    m_339 = 0;
    unk_338[0] = 0;
    action_state = 0;
    return_city_window = 0;
    regen_timer = 0;
    reset_entrance_id();
    unit_scale.reset();
    frame_timer = player_zero;
    state_flags = 0;
    set_input_mode(0);
    set_move_mode(0);
    lobby_animation = -1;
    lobby_animation_frame = player_zero;
    set_battle_flag(0);
    controller_input = NULL;
    inventory_objects = NULL;
    lock_on_cursor = NULL;
    joint_matrices = NULL;
    item_node_matrices = NULL;
    set_floor_index(0xF);
    set_floor(0xF);
    m_54c = 0;
    lobby_marker = NULL;
    *(s32 *)&unk_420 = 0;
    controller_port = 0;
    reset_state();
    ::set_flag_400000(this);
    if (TObjPlayer::get_player_count() == 1) {
        pk_state.enable();
    }
}

void TObjPlayer::init_battle(void *record) {
    assign_owner_ids();
    ::set_flag_400000(this);
    appear_fade.begin();
}

void TObjPlayer::reset_area_entry_state() {
    follow_particles.create_hand_particles(this);
    appear_fade.begin();
    if (this->is_locally_controlled() != 0) {
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
    appear_fade.set_client_id(get_entity_id());
    follow_particles.set_owner(this);
    chair_seat.set_owner_id(get_entity_id());
}

// A remote player's technique levels (with their bonus) and status effects.
void TObjPlayer::init_session_technique_caps(PlayerSyncRecord *record) {
    s32 i;

    photon_blast_gauge.set_client_id(get_entity_id());
    init_class_technique_caps(&technique_state, get_class_index());
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

extern "C" s32 get_record_byte_at(TPlyCharData *data, s32 tech);

// A saved character's technique levels.
void TObjPlayer::init_saved_technique_caps(TPlyCharData *record) {
    s32 i;

    photon_blast_gauge.set_client_id(get_entity_id());
    init_class_technique_caps(&technique_state, get_class_index());
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
    set_power_materials_used(record->get_power_materials_used());
    set_mind_materials_used(record->get_mind_materials_used());
    set_evade_materials_used(record->get_evade_materials_used());
    set_def_materials_used(record->get_def_materials_used());
    set_luck_materials_used(record->get_luck_materials_used());
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
    bodies->offset.y = player_half * stat_block->proportions;
}

void TObjPlayer::init_remote_pad_binding(PlayerSyncRecord *record) { pad_binding.set_controller(NULL); }

void TObjPlayer::reset_pad_binding() {}

void TObjPlayer::release_pad_binding() {}

void TObjPlayer::init_control_mode(s32 role) {
    if (this->is_locally_controlled() != 0) {
        controller_port = role & 3;
        pad_binding.init(get_entity_id(), controller_port);
        return;
    }
    pad_binding.set_controller(NULL);
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

extern "C" {


void TObjPlayer::load_character_state(TPlyCharData *record) {
    u8 count;
    TPlyInventoryItem *records;

    count = record->m_inventory.m_num_items;
    records = record->m_inventory.get_items();
    create_inventory();
    set_action_provider_variant((s16) default_action_provider_variant());
    if ((obj_isState2_324() == 0) || (TFontSmallLobby::is_lobby_floor_15() == 0)) {
        if (!(shared_state_flags[0] & 1)) {
            assign_inventory_item_ids(this, records, count);
        }
        bind_saved_inventory_equipment(this, records, count);
    }
    this->item_node_matrices = player_shared_buffer_base[get_entity_id()];
}

}

extern "C" {



void TObjPlayer::update_action_animation() {
    u8 *arg0 = (u8 *)this;
    if (this->obj_isState2_324() == 0) {
        this->update_position_from_target();
        return;
    }
    if (is_on_current_floor() != 0) {
        this->clear_state_flags(4);
        if (this->test_actor_flags(0x800) != 0) {
            run_action_state_phase(0xF, 0);
            if (test_flags_any((s32 *)&this->death_flags, 1) != 0) {
                this->requested_action = this->get_action_animation();
            } else {
                this->restart_death_pose();
            }
            death_sink.set_progress(player_one);
            this->revive_or_spawn_marker();
            return;
        }
        if ((TFontSmallLobby::is_lobby_floor_15() != 0) && (((TPlyPhotonChair *)arg0)->is_mounted() != 0)) {
            run_action_state_phase(0x18, 0);
            return;
        }
        run_action_state_phase(1, 0);
    }
}

}

extern "C" {

void TObjPlayer::apply_motion_entry() {
    TObjMotionAction *a;
    set_action_table(const_cast<TObjMotionAction *>(action_provider->get_motion_actions(has_valid_handle(), get_handle_value())));
    set_action_motion(requested_action);
    a = get_anim_entry(requested_action);
    play_speed = a->speed;
    play_mode = a->mode;
    frame_count = current_motion->nbFrame;
    motion_flags &= ~4;
    action_flags = a->flags;
    if (action_flags & 0x20000000) {
        set_motion_interpolation_flag();
    }
    if (frame >= frame_count) {
        frame = player_zero;
    }
}

void TObjPlayer::init_idle_animation() {
    init_motion(const_cast<TObjMotionAction *>(action_provider->get_motion_actions(has_valid_handle(), get_handle_value())), action_provider->get_current_motion_list(), get_idle_animation());
}

void TObjPlayer::init_model_buffer_and_actions(void *data) {
    joint_matrices = shared_model_buffer + get_entity_id() * 0xC00;
    select_class_action_provider();
    action_provider->load_motions(get_entity_id());
    init_idle_animation();
    update_input_and_draw();
}


extern "C" {

void TObjPlayer::update_input_and_draw() {
    if (is_current_area_item_enabled() == 0) {
        set_action_provider_variant(default_action_provider_variant());
    }
    init_idle_animation();
    draw();
    update_action_animation();
}

}

}

void TObjPlayer::release_motion() {  }

extern "C" {
void copy_player_visual_record(void *dst, void *src);
}

void TObjPlayer::init_model_and_idle_pose() {
    joint_matrices = shared_model_buffer + get_entity_id() * 0xC00;
    select_class_action_provider();
    load_action_motions(get_entity_id());
    init_idle_animation();
    draw();
}

void TObjPlayer::init_body_parts(void *visual) { update_body_parts(visual); }
void TObjPlayer::reset_body_parts() {  }
void TObjPlayer::free_chara_making() { restore_boss6_player_snapshot(this); ((TCharaMaking *)this)->free_loaded_buffers(); }
void TObjPlayer::update_body_parts(void *visual) { copy_player_visual_record((char*)this + 0x85c, visual); this->model_load_flags = 255; ((TCharaMaking *)this)->update_body_parts(); create_hair_move_sim(this); }

TObjPlayer::~TObjPlayer() {
    release_child_object();
    free_chara_making();
    destroy_child();
    release_pad_binding();
    release_char_data();
    release_area_sync();
    release_technique_caps();
    destroy_owned_object();
    release_motion();
    release_area_placement();
    release_lock_on_cursor();
    release_action_palettes();
    release_pending_action();
    unregister();
    TObjPlayer::free_owned_buffer_b((saddr)&this->attack_state, (s16)(-1));
    destroy__10TObjPlayerFis((saddr)((s8 *)this + 0x754), -1);
}

extern "C" {
void TObjPlayer__sub_801BB85C(TObjPlayer *player, u8 *record);
void TObjPlayer__sub_801BBB70(TObjPlayer *player, PlayerSyncRecord *record);
extern const char *TObjPlayer_name;
}

TObjPlayer::TObjPlayer(TObject *parent, EndingPlayerRecord *src) : TObjChara(parent) {
    movement_hold.init();
    photon_blast_aim.reset();
    ((TObjPlayer *)((char *)this + 1876))->init_sub_objects();
    trap_counts.init();
    ((TObjPlayer *)((char *)this + 1992))->clear_base();
    attack_state.init();
    pk_state.init();
    telepipe.init();
    clear_marker_position(&marker_position);
    __ct__8FlagWordFv(((char *)this + 2136));
    TObjPlayer::reset_and_return((saddr)(((char *)this + 3332)));
    ((TObjPlayer *)((char *)this + 3500))->clear_header_struct();
    this->m_name = TObjPlayer_name;
    this->init_action_provider();
    this->entity_id = 0;
    this->setup_control_role(7);
    this->update_body_parts(src);
    this->init_player_data(src->stats);
    this->init_data_table_ptr();
}

TObjPlayer::TObjPlayer(TObject *parent, PlayerSyncRecord *record) : TObjChara(parent) {
    movement_hold.init();
    photon_blast_aim.reset();
    ((TObjPlayer *)((char *)this + 1876))->init_sub_objects();
    trap_counts.init();
    ((TObjPlayer *)((char *)this + 1992))->clear_base();
    attack_state.init();
    pk_state.init();
    telepipe.init();
    clear_marker_position(&marker_position);
    __ct__8FlagWordFv(((char *)this + 2136));
    TObjPlayer::reset_and_return((saddr)(((char *)this + 3332)));
    ((TObjPlayer *)((char *)this + 3500))->clear_header_struct();
    this->m_name = TObjPlayer_name;
    this->init_from_data(record);
    this->setup_control_role(4);
    init_body_parts(&record->visual);
    this->load_char_data(record);
    this->update_position(record);
    clear_lock_on_cursor(record);
    init_model_buffer_and_actions(record);
    init_remote_pad_binding(record);
    init_session_technique_caps(record);
    this->init_from_source(record);
    init_session_area_sync(record);
    init_battle(record);
    TObjPlayer__sub_801BBB70(this, record);
    this->init_class_flags(record);
    TObjPlayer__sub_801BB85C(this, (u8 *)record);
    this->hp = record->current_hp;
}

TObjPlayer::TObjPlayer(TObject *parent, s32 slot, s32 role, TPlyCharData *record) : TObjChara(parent) {
    movement_hold.init();
    photon_blast_aim.reset();
    ((TObjPlayer *)(((u8 *)this) + 0x754))->init_sub_objects();
    trap_counts.init();
    ((TObjPlayer *)(((u8 *)this) + 0x7C8))->clear_base();
    attack_state.init();
    pk_state.init();
    telepipe.init();
    clear_marker_position(&marker_position);
    __ct__8FlagWordFv((((u8 *)this) + 0x858));
    TObjPlayer::reset_and_return((saddr)((((u8 *)this) + 0xD04)));
    ((TObjPlayer *)(((u8 *)this) + 0xDAC))->clear_header_struct();
    m_name = TObjPlayer_name;
    this->init_action_provider();
    this->entity_id = slot;
    this->setup_control_role(role);
    update_body_parts(&record->m_disp_part2);
    sub_801BEE2C(record->m_inventory.m_hp_materials_used);
    sub_801BEE24(record->m_inventory.m_tp_materials_used);
    this->set_power_materials_used(record->get_power_materials_used());
    this->set_mind_materials_used(record->get_mind_materials_used());
    this->set_evade_materials_used(record->get_evade_materials_used());
    this->set_def_materials_used(record->get_def_materials_used());
    this->set_luck_materials_used(record->get_luck_materials_used());
    this->init_player_data(&record->m_stats);
    this->create_lockon_cursor();
    this->init_model_and_idle_pose();
    this->init_control_mode(role);
    init_saved_technique_caps(record);
    init_player_substructs(reinterpret_cast<u8 *>(&record->m_config));
    this->load_character_state(record);
    this->update_if_active();
    assign_owner_ids();
    this->setup_fresh_player_state((u8 *)record);
    this->sub_801BB8B0((u8 *)record);
    TObjPlayer::set_com_card_window((saddr)((this->get_entity_id())));
}


extern const char *TObjPlayer__player_set_class_name;

// C linkage: TObjPlayer_801BC194.cpp declares it unmangled.
extern "C" TObjPlayerSet *find_player_arrival_set(TObjPlayer *player, s32 slot) {
    TObjPlayerSet *set;
    s32 side;

    side = player->get_entrance_id();
    if (side != -1) {
        player->reset_entrance_id();
    } else {
        switch (select_area_entrance(&floor_transition_state)) {
        case 0:
            side = 1;
            break;
        case 1:
        case 2:
            side = 0;
            break;
        case 4:
        default:
            side = 1;
            break;
        }
    }
    for (set = (TObjPlayerSet *)tl_06->m_down; set != NULL; set = (TObjPlayerSet *)set->m_next) {
        if (set->check_value_equals(TObjPlayer__player_set_class_name) != 0 &&
            slot == (s32)set->scale.x && set->set_params[0] == side) {
            return set;
        }
    }
    return NULL;
}

void TObjPlayer::create_active_players() {
    s32 slot;
    PlayerCharDataEntry *entry;
    slot = 0;
    entry = TObjPlayer__char_data_array;
    do {
        if (entry->has_character() != 0) {
            create(slot & 0xFFFF, entry);
        }
        slot++;
        entry++;
    } while (slot < 12);
}

void TObjPlayer::refresh_player_lobby_headers() {
    s32 client;
    TObjPlayer *player;
    PlayerCharDataEntry *entry;
    client = 0;
    entry = TObjPlayer__char_data_array;
    do {
        ((TObjPlayer *)entry)->init_select_txt();
        player = get_player_by_client_id(client);
        if (player != NULL) {
            if (player->is_locally_controlled() != 0) {
                ((TObjPlayer *)entry)->copy_lobby_header((saddr)player);
            }
            delete player;
        }
        client++;
        entry++;
    } while (client < 12);
}

TObjPlayer *create_remote_player_object(void *record) {
    decode_remote_player_inventory(record);
    return new TObjPlayer(tl_03, (PlayerSyncRecord *)record);
}

s32 TObjPlayer::create(u32 slot, PlayerCharDataEntry *entry) {
    TObjPlayer *created;

    created = new TObjPlayer(tl_03, slot & 0xFFFF, entry->get_role(), entry->get_char_data());
    ((TLobby *)&created->guild_card_tag)->copy_header_struct(entry->get_lobby_header());
    return (s32)created;
}
