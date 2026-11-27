#ifndef PSO_PLAYER_TOBJPLAYER_H
#define PSO_PLAYER_TOBJPLAYER_H

#include "types.h"
#include "dolphin/mtx/GeoTypes.h"

struct NJS_OBJECT;
struct PhotonBlastRequest;
struct PhotonBlastRequestSlot;
struct PhotonBlastRegistry;
#include "pso/player/PhotonBlastGauge.h"
#include "pso/player/PlayerTechniqueState.h"
#include "pso/player/PlayerPadBinding.h"
#include "pso/player/TPlyDispConfig.h"
#include "pso/player/MaterialUsage.h"
#include "pso/player/PlayerFollowParticles.h"
#include "pso/player/PlayerClassFlags.h"
#include "pso/player/PlayerScaleState.h"
#include "pso/player/PlayerMoveSpeed.h"
#include "pso/player/PlayerAnimationState.h"
#include "pso/player/PlayerDeathSink.h"
#include "pso/player/PlayerStats.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/RenderMaterialState.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/PlayerAttackController.h"
#include "pso/player/PlayerTelepipe.h"
#include "pso/player/PlayerGuildCardTag.h"
#include "pso/player/PlayerState.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/PlayerTrapCounts.h"
#include "pso/player/PlayerAppearFade.h"
#include "pso/player/BattleMusicState.h"
#include "pso/player/ContactSurfaceState.h"
#include "pso/player/MovementHold.h"
#include "pso/player/MovementHistory.h"
#include "pso/player/PlayerAppearFade.h"
#include "pso/player/PlayerPkState.h"
#include "pso/player/PhotonChairSeat.h"
#include "pso/player/PlayerActionPaletteState.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/player/PlayerIntraMapWarp.h"
#include "pso/player/PhotonBlastAim.h"
#include "pso/player/PlayerBattleScore.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/ui/charcreate/CharacterCreationTextureCache.h"

struct TItemData;
struct PhotonBlastRequest;
struct SceneSectionAngles;

struct TItem;
class TPlyItem;
struct TItemWeapon;
class TItemShoot;
class TItemShootParticle;
class TItemList;
class TPlayerLobbyMarker;
class TPlyInventoryItem;
struct TechniqueContactList;
struct EndingPlayerRecord;
struct PlayerSyncRecord;
struct PlayerCharDataEntry;
struct TLockOnCursor;
class LockOnActionSlot;
struct TMovie;
struct CapturedTargetList;
class TPlayerLobbyMarker;
struct PlayerRequirementStats;

// The frames a player stays protected from hits (after getting up, being
// hurt, or a mag's invincibility).
struct ProtectionTimer {
    s32 frames;

    ProtectionTimer();
    virtual ~ProtectionTimer();
    s32 get_frames();
    void set_frames(s32 frames);
    void reset_type();
    void reset_lobby_model();
};

LAYOUT_ASSERT(ProtectionTimer_size, sizeof(ProtectionTimer) == 0x8);

// Three factors that start at 1.0; init_action_provider resets them.
struct UnitScale {
    f32 x;
    f32 y;
    f32 z;

    UnitScale();
    void reset();
};

struct PlayerNpcControl {
    u16 controller_client_id;
    u16 reserved;
    s32 state;

    PlayerNpcControl();
};

LAYOUT_ASSERT(PlayerNpcControl_size, sizeof(PlayerNpcControl) == 0x8);

struct ControllerInputContext;

struct StickEscapeDetector {
    s32 last_stick_angle;
    s32 last_turn_frame;
    const ControllerInputContext *input;

    StickEscapeDetector();
    s32 check_input_angle();
};

LAYOUT_ASSERT(StickEscapeDetector_size, sizeof(StickEscapeDetector) == 0xC);
void init_stick_escape_detector(StickEscapeDetector *detector, const ControllerInputContext *input);

class TPlyCharData;
typedef GC_Mtx PlayerJointMatrixSet[32];
extern u32 shared_state_flags[2];
extern int shared_count;
extern int shared_flag;

// Constants the player code shares from its .sdata2 pool.
extern const char *TObjPlayer_name;
extern const f32 player_zero;
extern f32 player_half;
extern f32 player_one;

struct TObjPlayer : public TObjChara {
    TObjPlayer(TObject *parent, PlayerSyncRecord *record);
    TObjPlayer(TObject *parent, EndingPlayerRecord *src);
    TObjPlayer(TObject *parent, s32 slot, s32 role, TPlyCharData *record);
    // The key function: TObjPlayer.cpp defines it, so __vt__10TObjPlayer is emitted
    // with that TU's data.
    virtual void reset_motion_fields();
    virtual ~TObjPlayer();
    s32 calc_joint_matrices(NJS_MOTION *with, f32 at_frame, saddr matrices);
    virtual const char *get_name();
    void update_swim_flag(void *);
    void draw_weapon_if_not_hidden(void *);
    void draw_actor_model(void *);
    s32 destroy_char_data(int, s16);
    CsnHit *apply_wall_response();
    void apply_battle_level_reset(s32 level);
    void set_action_provider_variant(s16);
    void update_position_from_target();
    s16 get_idle_animation();
    s16 get_mode_animation(u32 mode);
    s16 get_current_mode_animation();
    void restore_state_on_area_entry();
    void handle_state2_transitions();
    void clear_state_flags(s32);
    virtual void get_anim_node_position(s32 node, Vec *out);
    virtual CsnHit *update_actor_ground_y();
    virtual CsnHit *update_actor_ground_y_at(Vec *pos);
    virtual void recalc_stats();
    virtual s32 update_slow_status();
    virtual s32 update_attack_stat_status();
    virtual s32 update_defense_stat_status();
    virtual s32 is_actor_cadence_frame(s32);
    virtual s32 add_actor_exp(s32);
    virtual void reset_pose();
    s8 get_class_index();
    s32 can_use_more_materials_for_class();
    virtual void get_pos(saddr out);
    virtual void apply_switch_attack();
    virtual void enemy_spawn_jellen_effect();
    virtual void trigger_switch_attack();
    virtual void enemy_spawn_zalure_effect();
    virtual f32 receive_physical_attack(TObjChara *attacker, f32 scale);
    virtual s32 update_poison_status();
    virtual s32 update_action_hold_status();
    virtual s32 update_flag30_timer();
    virtual s32 update_movement_status();
    virtual s32 update_shock_clock();
    virtual void send_status_effect_add(StatStatusReceipt effect);
    virtual s32 vfunc_79();
    void set_floor(s32);
    void set_input_mode(s32);
    void set_move_mode(s32);
    void set_move_mode_from_class_flags();
    void init_from_source(PlayerSyncRecord *record);
    void init_control_mode(s32);
    s32 get_controller_port();
    void load_char_data(PlayerSyncRecord *record);
    void destroy_owned_object();
    void init_collision_body();
    void create_lockon_cursor();
    void update_lock_on_cursor();
    void clear_lock_on_cursor(void *data);
    void setup_fresh_player_state(u8 *);
    void init_class_flags(PlayerSyncRecord *record);
    void load_pending_actions_from_sync_record(u8 *record);
    void load_pending_actions(TPlyCharData *record);  // restores pending_actions (and record_flags_hi) from a save record; apply_pending_action is the inverse
    s32 setup_control_role(s32);
    s32 is_target_in_facing_cone(Vec *target);
    void create_inventory();
    void select_contextual_pickup_action();
    void init_trait_flags();
    void update_facing_vector();
    void update_rotation();
    void load_action_motions(u16 entity_id);
    s16 get_ata();
    s16 get_dfp();
    // Fire, dark and light resistance (element_resist 0, 3 and 4).
    s16 get_efr();
    s16 get_edk();
    s16 get_elt();
    s16 obj_getS16_116();
    void set_hp_bonus(s16);
    void set_tp_bonus(s16);
    void update_body_parts(void *visual);
    void update_body_parts();
    void free_loaded_buffers();
    void init_body_parts(void *visual);
    void init_model_and_idle_pose();
    void init_model_buffer_and_actions(void *data);
    s32 is_local_or_split_screen();
    void gain_photon_blast_chain_charge(f32 amount);
    void spend_photon_blast_charge(f32 charge);
    void gain_photon_blast_charge(f32);
    int deliver_attack_hits(f32 damage_scale);
    void render_shadows();
    void render();
    void run_task();
    TItemList *find_revival_item();
    void request_inventory_item(TItemData* item);
    TPlyDispConfigSmth *select_action_palette(int secondary);
    s32 add_meseta(s32 amount);
    void request_normal_attack_stage1();
    void show_miss_for_collider(s32 collider);
    u32 state_flags;
    u8 mag_level;     // class flag 0 of a character record (get_mag_level)
    s8 class_flag_1;
    u8 battle_mode;   // class flag 2 of a character record (get_battle_mode)
    s8 m_33b;
    s32 action_state;
    PlayerActionPaletteState action_palette_state;
    PhotonChairSeat chair_seat;
    ContactSurfaceState contact_surface;
    s32 return_city_window;
    s32 regen_timer;  // frames toward the next regeneration tick (tick_regen_timer)
    MaterialUsage materials;
    // Inferred: the action provider init_action_provider creates
    // (GamePlayerActionProvider or LobbyPlayerActionProvider).
    PlayerActionProvider *action_provider;
    PlayerFollowParticles follow_particles;
    s32 m_3b4;
    TPlayerLobbyMarker *lobby_marker;  // set_lobby_marker creates it on the lobby floor
    s32 language;
    s16 lobby_animation;
    u8 pad_3c2[0x2];
    f32 lobby_animation_frame;  // frame the lobby animation (action state 0x17) resumes at
    s32 entrance_id;
    u32 sent_status_flags;  // the status bits of actorFlags last sent as 6x0C/6x0D
    s32 controller_port; // 0-3, set by init_control_mode for a local player
    s32 freeze_escape_step; // added to the freeze timer on each stick escape (negative)
    s32 input_mode;
    s32 move_mode;
    s32 current_area;
    s32 current_floor;
    s32 control_role;
    s32 m_3ec;
    s32 target_heading;
    s32 m_3f4;
    Vec move_target;  // (name inferred) run/walk-to target: calc_movement_target and handle_6x40/6x42 set x/z, update_*_movement steer to it
    Vec facing;  // (sin, 0, cos) of rotation_y (update_facing_vector)
    Vec ground_normal;
    FlagWord pending_actions;  // action bits apply_pending_action copies into the save record
    s32 record_flags_hi;  // (name inferred) load_pending_actions restores it from the packed byte of record items 4-7
    TLockOnCursor *lock_on_cursor;  // created by create_lockon_cursor for local players
    PlayerTechniqueState technique_state;
    PhotonBlastGauge photon_blast_gauge;
    TPlyDispConfig action_palettes;
    TObject *death_fade; // the TDeathTintFade of a dying player
    saddr lobby_label;  // the TFontSmallLobby name label on lobby floor 15
    PlayerPadBinding pad_binding;
    PlayerScaleState scale_state;
    PlayerMoveSpeed move_speed;
    PlayerAnimationState anim_state;
    PlayerDeathSink death_sink;
    RenderMaterialState render_material_state;
    PlayerAppearFade appear_fade;
    BattleMusicState battle_music;
    ProtectionTimer protection;  // frames the player cannot be hurt
    StickEscapeDetector stick_escape_detector;
    PlayerIntraMapWarp intra_map_warp;
    UnitScale unit_scale;
    PlayerNpcControl npc_control;
    CollisionBody collision_body;
    MovementHistory movement_history;
    MovementHold movement_hold;
    PhotonBlastAim photon_blast_aim;
    PlayerBattleScore battle_score;
    PlayerTrapCounts trap_counts;
    PlayerSonarStock sonar_stock;
    PlayerAttackController attack_state;  // the attack accuracy/damage-scale block
    PlayerPkState pk_state;
    PlayerTelepipe telepipe;  // TTecLuker::init_fields, TelepipeState::send_telepipe_packet
    PlayerMarkerPosition marker_position;  // above the head (calc_marker_position), where the lobby marker is drawn
    FlagWord death_flags;
    CharacterAppearanceFields appearance;
    // The part models TChCrLoadReq loads after the body (TObjMotion::model):
    // the hair and head hang from node 0x3B, the attachment from node 0x3A.
    void* hair_model;
    void* head_model;
    uaddr attachment_model;
    // Texture sets TChCrLoadReq fills for the head/hair, the attachment and the body.
    CharacterTextureLoadSet head_textures;
    CharacterTextureLoadSet attachment_textures;
    CharacterTextureLoadSet body_textures;
    s32 model_load_flags;  // nonzero while the models load (update_body_parts sets 255); not drawn until 0
    TPlyItem *inventory_objects;  // created by create_inventory
    EquippedItems equipped_items;  // read through get_equipped_item
    player_stats base_stats;
    AttackParams attack_stats;
    ActorParamBlock resistance_stats;
    // Guild card tag (tag triplet + guild card number) the lobby entry gives the player.
    PlayerGuildCardTag guild_card_tag;
    static void draw_area_chunk_objects();
    static void reset_effect_count();
    static void step_cutscene_frame(NJS_OBJECT *);
    void enter_state_8();
    void tick_freeze_state();
    static void create_render_texture();
    // The photon blast gauge's charge, 0-100.
    s32 get_photon_blast_charge();
    int is_frozen();
    void unequip_item(TItem *item);
    static void send_6x26_unequip_item(TObjPlayer *player, u32 item_id);
    player_class_type get_class_type();
    static void render_tree(void *model);
    s32 get_entrance_id();
    void set_entrance_id(s32 id);
    static void*get_pmt_record(int i);
    static void*get_item_pmt_record(int type, int id);
    static void*get_pmt_record_by_type_id(int type, int id);
    static void*get_pmt_record_by_index(int i);
    s32 is_action_available();
    static s32 is_any_teammate_in_state();
    static void set_shared_flag(int flag);
    // Twelve 0xC00-byte joint matrix blocks, one per player slot.
    static u8 *shared_model_buffer;
    // Twelve PlayerJointMatrixSet blocks of item node matrices, one per player slot.
    static PlayerJointMatrixSet *player_shared_buffer_base;
    // The party's photon blast requests (alloc_shared_buffers makes them, free_shared_data frees them).
    static PhotonBlastRegistry *shared_photon_blast_state;
    // The twelve player slots' characters (create_active_players builds the players from them).
    static PlayerCharDataEntry char_data_array[];
    static void set_shared_count(int count);
    void set_position(f32 a, f32 b, f32 c);
    void set_meseta(s32 meseta);
    u16 get_attacker_id();
    void set_attacker_id(u16 id);
    s32 is_local_player();
    void apply_velocity();
    void damp_planar_velocity();
    s16 clamp_tp();
    static void clear_s16_arrays(TObjChara *p);
    s32 add_capped_counter_999(s32 amount);
    int get_tp_materials_clamped();
    int get_hp_material_points();
    s32 clamp_hp_value(s16 *value);
    void set_hp_clamped(s16 value);
    void spawn_recovery_effect();
    void set_attribute_entry(s32 i, WeaponAttribute *attribute);
    WeaponAttribute *get_attribute_entry(s32 i);
    static f32 calc_distance_to_client(const TObjBase *actor, u16 client, Vec *delta);
    // Thunder and ice resistance (element_resist 1 and 2), named as in the item help window.
    s16 get_eth();
    s16 get_eic();
    s32 get_floor();
    s32 is_on_current_floor();
    s32 get_area();
    static s32 get_player_count();
    static saddr get_battle_param(int index);
    s32 check_player_flag1();
    s32 check_flag(s32 flag);
    // Set while a menu window holds the player's input, with the action buttons masked.
    s32 is_controls_locked();
    s32 is_drop_weapon_on_death_disabled();
    Vec *get_position_ptr();
    // Where the player stood before this frame's move.
    Vec *get_prev_position_ptr();
    static void set_com_card_window(s32 client);
    static s32 check_demo_mode();
    static TItem *get_equipped_weapon(void *player);  // equipped_items[6]
    static TObjPlayer *get_player_data(int index);
    void queue_destruction();
    s32 test_action_mask(s32 bits);
    s32 test_action_4();
    s32 test_action_8000();
    int check_flag_24576();
    int test_flag_16();
    s32 test_action_40000();
    s32 test_action_80000();
    int is_inactive();
    s16 get_atp();
    s16 get_atp_range();
    static void update_effect_sequence(NJS_OBJECT *);
    static void init_render_globals();
    static void push_material_color_override(f32 alpha, f32 r, f32 g, f32 b);
    // attack_state.get_validated_attack_stage(): the pending stage, 0 when it is not valid.
    s16 get_attack_stage();
    void *create_hairmove(void *rope_spec, void *collider_spec);
    void set_tp(s16 tp);
    s32 get_tp_bonus();
    s32 get_hp_bonus();
    TItem *get_equipped_item(s32 slot);
    s32 is_flag_20000_set();
    s32 is_body_collision_inactive();
    static saddr get_slot_value(void *slots, int slot);
    void play_sound_if_on_floor(s32 sound_id);
    u32 pickup_item(TItem *item);
    s32 can_pickup_item_by_id(TItem *item);
    s32 can_pickup_item(TItemData *data);
    static u8 find_adjacent_matching_slot(u8 slot);
    static u8 get_next_matching_special_index(u8 slot);
    static void free_item_globals();
    static void init_game_resources();
    s32 is_script_controlled();
    // equipped_items[1], [2] and [3].
    TItem *get_equipped_mag();
    // The items equipped in the armor and shield slots (2 and 3), or 0.
    TItem *get_equipped_armor();
    TItem *get_equipped_shield();
    static s32 count_nearby_players_with_shield(u16 idx, u8 *item);
    static TItemShootParticle *spawn_shoot_particle(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life);
    static TItemShoot *create_shoot_model(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life);
    static saddr get_item_pmt_entry(u8 index);
    static saddr get_shield_pmt_entry(u8 index);
    static f32 get_drop_random_float(u32 channel);
    static void drop_item_from_slot(s32 area, s32 slot, TItemData *item);
    static void drop_item(s32 slot, TItemData *item);
    static void drop_meseta_from_slot(s32 slot, TItemData *item);
    static saddr get_item_by_slot_flag(u8 flags);
    void set_flag_10000();
    void set_state_flags(u32 v);
    s16 is_status_subsystem_ready();
    CapturedTargetList *get_extended_state();
    f32 query_extended_state();
    int test_flag30_bit0x100000();
    static void notify_hit_target(u32 layer, uaddr player, u32 target, uaddr pos);
    s16 get_kill_count();
    void set_kill_count(s16 count);
    static void set_camera_mode(s32 camera_mode);
    s16 get_evp();
    int check_flag_0x80();
    static s32 is_final_phase();
    static s32 is_camera_ready();
    static s32 is_camera_mode_active();
    static s32 is_single_screen();
    static s32 is_player_valid_target(u16 client_index);
    void update_movement_effects();
    static int get_max_level();
    void update_position(PlayerSyncRecord *record);
    s32 has_active_camera_event();
    void init_from_data(PlayerSyncRecord *record);
    void reset_state();
    void update_state();
    void update_if_active();
    int can_cast_technique();
    void init_player_data(player_stats *src);
    void init_remote_pad_binding(PlayerSyncRecord *record);
    void init_data_table_ptr();
    void update_recobox();
    void destroy_child();
    void load_character_state(TPlyCharData *record);
    void update_action_animation();
    void update_input_and_draw();
    void free_chara_making();
    static TObjPlayer *create(u32 slot, PlayerCharDataEntry *entry);
    static void free_shared_data();
    static s32 check_camera_mode();
    int is_android();
    int is_newman();
    void check_stat_flag_41c();
    void check_flag_at_41c();
    void set_flag_41c_bit1();
    void clamp_stat_41c();
    void clear_flag_400000();
    short get_model_field_m25();
    short get_action_animation();
    short call_model_m24();
    short get_weapon_stat_c();
    short call_obj_vt26();
    short query_child_state();
    short query_equip();
    short get_status();
    short get_model_state();
    short get_state();
    short get_attack1_action();
    short get_run_action();
    // The slow walk while the move speed is slowed (PlayerMoveSpeed flag 8), else the walk.
    s16 get_walk_action();
    void clear_flag_200000();
    int check_flag_4();
    void clear_flag_4000();
    void set_flag_4000();
    s32 is_flag_4000_set();
    void set_battle_flag(s32 v);
    // Quest opcode set_returnhunter: battle flag 1.
    void set_return_hunter();
    s32 get_anim_id();
    int check_flag_0x40000000();
    void clear_flag_0x2();
    int unregister_sub();
    void set_control_role(s32 v);
    s32 get_control_role();
    void set_language(s32 v);
    void reset_entrance_id();
    void set_def_materials_used(u8 v);
    void set_evade_materials_used(u8 v);
    void set_mind_materials_used(u8 v);
    void set_power_materials_used(u8 v);
    int get_action_motion_type();
    static s32 decrement_clamp(s32 *value, s32 amount);
    void set_visible_flag();
    s32 check_flag_04000000();
    void clear_quest_control_flag();
    s32 check_quest_control_flag();
    s32 interpolate_angle(s32 from_angle, s32 to_angle, s32 *step);
    // Turns the player toward its chair seat and moves it along its velocity.
    void turn_toward_chair_seat();
    void update_state_group();
    void start_action_18();
    void start_action();
    void set_attack_state();
    void send_state_sync();
    int try_lobby_chair_change_action();
    void update_lobby_chair_controls();
    s16 select_idle_action();
    void update_dispatch_v76();
    void do_action();
    void update_if_flagged();
    int try_lobby_animation_change_action();
    void init_effects();
    void start_action_21();
    void send_position_update();
    void init_flags_vec4();
    void set_dead_state();
    void send_warp_position();
    u16 get_npc_controller();
    void set_npc_controller(u16 client);
    s32 get_npc_control_state();
    void set_npc_control_state(s32 state);
    void check_state_dead();
    void reset_lobby_state();
    void try_use_mag();
    void enter_freeze_action();
    void send_name_and_state();
    void update_gated_action();
    void update_frozen_release();
    s32 try_change_action();
    void clear_flag();
    void enter_service_hold_action();
    void send_6x52_animation_state();
    static void service_hold_phase8_nop();
    void update_service_hold();
    static void service_hold_phase2_nop();
    void set_motion();
    void init_action();
    void send_6x4F_revived();
    void update_timer_action();
    void update_active_state();
    void send_6x4E_player_revivable();
    void update_action_render();
    void reset_on_death();
    void exit_death_state();
    void update_death_pose();
    void enter_death_state();
    void prepare_death();
    void set_death_marker_pos();
    void request_revival_if_not_dead();
    void check_reopen_return_city_window();
    void exit_fall_reaction();
    void update_fall_reaction();
    void begin_fall_reaction();
    void complete_fall_reaction();
    void check_and_trigger_19_5();
    void set_flag_100000();
    void update_move_state();
    void send_6x4B_hurt_reaction();
    void complete_hurt_reaction();
    void do_action_19_5_if_flag30();
    void begin_action_0xB();
    void run_if_flag_10();
    int try_apply_status_action();
    s32 try_status_action();
    s32 check_flag30_bit20();
    // Action state machine: run_action_state_phase dispatches a state's phase to its handler.
    void run_action_state_phase(s16 state, s16 phase);
    void run_idle_state_phase(s16 phase);
    void run_walk_state_phase(s16 phase);
    void run_action3_phase(s16 phase);
    void dispatch_run_state(s16 phase);
    void run_attack_stage1_phase(s16 phase);
    void run_attack_stage2_phase(s16 phase);
    void run_attack_stage3_phase(s16 phase);
    void dispatch_technique_cast_state(s16 phase);
    void dispatch_photon_blast_action(s16 phase);
    void run_guard_reaction_phase(s16 phase);
    void run_action11_phase(s16 phase);
    void run_switch_interaction_phase(s16 phase);
    void run_hurt_state_phase(s16 phase);
    void run_fall_reaction_phase(s16 phase);
    void run_death_state_phase(s16 phase);
    void run_revival_state_phase(s16 phase);
    void run_service_hold_state_phase(s16 phase);
    void run_freeze_state_phase(s16 phase);
    void run_warp_action_phase(s16 phase);
    void handle_warp_phase(s16 phase);
    void run_off_floor_state_phase(s16 phase);
    void run_lobby_animation_state_phase(s16 phase);
    void run_lobby_chair_state_phase(s16 phase);
    void apply_velocity_if_ready();
    void start_action_c();
    void send_6x50_switch_interaction();
    void update_if_flag_set();
    void set_flag_0x100000();
    static void apply_velocity_if_free(saddr player);
    static void apply_velocity_if_free(TObjPlayer *player);
    void complete_guard_reaction();
    void select_hit_action();
    static void create_photon_blast_party_effects(u16 id);
    static PhotonBlastRequestSlot *find_photon_blast_by_section_id(u16 section_id);
    static u16 get_current_target_id();
    static void update_photon_blast_state();
    static void apply_photon_blast(u16 client_id, s16 kind);
    void update_active_instance(int index);
    static f32 calc_photon_blast_charge(void *player, s32 damage);
    void send_6x37_photon_blast();
    s32 check_conditions(s16 blast);
    void exit_photon_blast_action();
    void update_photon_blast_action();
    void update_band_state();
    void update_target_approach();
    int try_apply_status_action_default();
    void update_cursor(s32 parameter);
    void pay_tp_and_send_6x48_cast();
    void exit_technique_cast();
    void update_technique_cast();
    void check_anim_done();
    void update_state5_action();
    int apply_status_action_a();
    void reset_linked_obj();
    void send_attack_stage3_request();
    void finish_attack_stage3();
    static void check_attack_stage3_input();
    int try_apply_status_action_1();
    void reset_target_link();
    void send_attack_stage2_request();
    void finish_attack_stage2();
    int apply_status_action();
    void start_attack_preparation();
    void setup_attack_stage();
    void send_attack_target_packet();
    s32 check_mode_action(s32 action);
    s32 can_perform_physical_action();
    void update_by_state();
    void apply_movement_if_ready();
    void update_anim_action();
    void reset_lockon();
    void finish_attack_stage1();
    void update_active_item();
    void apply_damage_and_reset();
    void send_6x42_run_to_position();
    void handle_ring_release();
    void try_trigger_effect();
    void select_run_request();
    int apply_status_action_b();
    void calc_movement_target(s32 angle, f32 *out_x, f32 *out_z);
    void reset_and_flag();
    void send_6x40_walk_to_position();
    void handle_ring_hit();
    void check_ring_action();
    void select_walk_request();
    void cleanup_idle_entry();
    static void exit_idle_state();
    void update_action();
    void start_animation();
    void send_6x3E_stop_at_position();
    // 6x3F: tells the other clients the player is at pos, facing angle.
    void send_6x3F_set_position(const Vec *pos, s32 angle);
    static void complete_idle_state();
    int try_apply_status_action_2();
    void update_lobby_chair(s32 value);
    void get_chair_state(s32 value);
    void clear_state_flag();
    short start_action18_sub();
    s32 get_chair_target_angle();
    int get_action_flag();
    void set_chair_seat_animation(s16 value);
    int is_action_flag_28();
    void set_anim_flag();
    void set_action_flag_28();
    void clear_flag_200();
    void set_flag_200();
    void set_float_param(s16 value);
    // The speed of the requested action in the action table.
    f32 get_action_rate_entry();
    void set_field_d4_and_flag_200(f32 value);
    void set_action_flag();
    void set_action_palette_state_mode(u8 mode);
    void clear_flag_128();
    static s32 decrement_timer(s32 *timer);
    static void reset_particle_ctrl(s32 *ctrl);
    s32 get_getup_protection_ticks();
    s32 get_hurt_protection_ticks();
    u8 *get_lobby_entry_ptr();
    s32 get_guild_return_yaw();
    s32 get_hospital_yaw();
    u8 *get_hospital_position();
    long get_anim_table_entry(s32 picture);
    saddr get_table_entry_by_clamped_index();
    s32 get_footstep_floor_index();
    f32 get_photon_blast_complete_threshold();
    f32 get_photon_blast_upper_bound();
    f32 get_photon_blast_hold_frame();
    f32 get_attack_recovery_count();
    static s32 get_current_state_field(s32 cls, s32 lvl);
    s32 get_class_state_field(s32 lvl);
    player_stats *get_class_stat_entry();
    f32 get_tp_class_factor();
    f32 get_class_hp_factor();
    int get_floor_surface_type();
    s32 get_falz_phase();
    s16 get_section_clamped();
    s32 get_section_id();
    static void split_capped_value(u8 level, u8 *capped, u8 *overflow);
    static s32 validate_and_clear_slot(void *techs, s16 tech);
    static s32 is_invalid_slot(u8 level);
    static s32 is_valid_technique_slot(u8 slot);
    static void free_if_valid(saddr texlist);
    static void play_effect_if_v2(s32 pitch);
    static s32 is_valid_and_active(const TObjCollidable *actor);
    static void play_particle_at_active_slot(s32 kind, s32 sampler, s32 scale, s32 alternate, s32 unused, s32 second);
    static void setup_effect_slots(s32 v1_flags, TPlyDispConfigSmth *palette);
    static void begin_action_from_char_select();
    void export_character_data(TPlyCharData *character);
    void export_state_to_record(TPlyCharData *record);
    void copy_battle_mode(TPlyCharData *record);
    void copy_byte_339_to_record(TPlyCharData *record);
    void copy_mag_level_to_record(TPlyCharData *record);
    void apply_pending_action(TPlyCharData *record);
    static s32 sync_char_select_state();
    static void init_battle_selection();
    void set_action_state(s16 state, s16 value);
    void clear_flag_80000();
    void set_flag_80000();
    static void enable_foot_stamp(PlayerFollowParticles *particles, TObjPlayer *player);
    static void clear_foot_stamp(PlayerFollowParticles *particles, TObjPlayer *player);
    // The ending movie's finish callback: TMovie::run_task calls it with the movie.
    static void alloc_and_init(s32 item_id, f32 *position, f32 *direction);
    static void create_and_init_effect(s32 item_id, u32 *hit, f32 *direction);
    static void start_guardianna_hit_card(s32 item_id, u32 *hit, f32 *direction);
    static void create_aux_object(s32 item_id, u32 *hit, f32 *direction);
    static void create_network_object(s32 item_id, u32 *hit, saddr direction);
    void free_indexed_entry(s32 _w1);
    static void create_cleanup_object(void *parent);
    static void free_static_buffer();
    static void alloc_and_run_object();
    static void push_id_to_list(s32 id);
    static void spawn_cleanup_helper(void *parent);
    static void warn_if_gauge_low();
    static void set_model_fade_alpha(f32 alpha);
    static void copy_gauge_warn_vec();
    static void free_global_805D6FB8();
    static void alloc_and_init_object_b4();
    static void draw_player_model_by_client(u16 client_id, saddr motion, f32 frame, f32 alpha);
    static void draw_player_model_by_id(s32 client_id, f32 alpha);
    static void rebuild_players_for_stage(s32 stage);
    static void spawn_appearance_effect(u16 client);
    // A weapon shot callback: news the shoot model that draws the shot.
    static TItemShoot *create_item_shoot_model(TItemWeapon *weapon, const Vec *origin, const Vec *end, f32 frames);
    static void spawn_weapon_casing(TObject *parent, TItem *item, Vec *pos, Vec *velocity, s32 *angle);
    static void launch_weapon_casing(TObject *parent, uaddr item, s32 joint, Vec *velocity, s32 *angle);
    static void clear_photon_blast_slots();
    void place_on_area_entry();
    void release_child_object();
    void init_action_provider();
    void apply_motion_entry();
    void init_idle_animation();
    static void create_active_players();
    static void refresh_player_lobby_headers();
    static TObjPlayer *create_player_instance(s32 slot, PlayerCharDataEntry *player);
    static void alloc_shared_buffers();
    static s8 get_rules_active();
    static void draw_effect();
    void draw_trail_pair();
    static void update_particle_by_phase(NJS_OBJECT *);
    void draw_blob_shadows();
    void set_flag_8_if_check_passes();
    static void new_child_object(u16 player_id);
    int is_flag_b0_4();
    static TItemShoot *spawn_shot_effect(TItemWeapon *owner, const Vec *origin, const Vec *end, f32 frames);
    static void start_photon_blast(s32 kind, s32 client_id);
    s32 get_total_deaths();
    void init_local_pad_binding();
    void stop_force_if_alive();
    void update_battle_control_if_unlocked();
    void update_facing_from_lock();
    f32 get_battle_value(u16 client, s16 technique);
    TPlayerLobbyMarker *set_lobby_marker(u8 material);
    s32 are_traps_full();
    s32 is_alive_and_ready();
    void refill_traps();
    s32 update_movement_by_screen();
    s32 get_battle_place();
    s32 calc_battle_score();
    int get_pk_team();
    void record_kill(TObject *victim, s32 count);
    s32 record_death(TObject *killer, s32 count);
    s16 get_handle_value();
    s32 get_class_flags();
    static s32 check_technique_castable(TObjPlayer *player);
    void sync_current_floor();
    void sync_current_area();
    static int get_key_machine_global_state(void* p);
    void set_flag_drop_weapon_on_death();
    void disable_drop_weapon_on_death();
    static void update_photon_chair(TObjPlayer *player);
    void refresh_equipment_slot();
    void clear_stealth_suit_flags();
    void set_stealth_suit_flags();
    void activate_body_collision();
    void deactivate_body_collision();
    void send_field_state();
    void play_photon_blast_feedback();
    static void spawn_effect(saddr player);
    void draw();
    void set_state_flag_604B();
    static void send_disable_pk_mode(TObjPlayer *player);
    void set_state_flag_6043();
    static void send_enable_pk_mode(TObjPlayer *player);
    void send_use_medical_center();
    void send_medical_center_revive_all_players();
    void send_enable_stealth_suit_effect();
    void send_disable_stealth_suit_effect();
    void send_enable_drop_weapon_on_death();
    void send_disable_drop_weapon_on_death();
    void send_level_up_all_techniques(u8 num_levels);
    int is_pk_enabled();
    static void play_phase_transition_sound(saddr child);
    int check_flag_40000();
    s32 is_in_tl03_state();
    void sync_status_effect_flags();
    void cancel_status_effects();
    s32 get_next_level_exp();
    void prepare_hospital_return();
    void stop_battle();
    s32 create_return_city_window();
    void clear_flag_4096();
    void set_flag_4096();
    void disable_primary_action_input();
    void disable_action_input();
    void enable_action_input();
    s32 is_action_input_disabled();
    void disable_palette_slot(s32 slot);
    void enable_palette_slot(s32 slot);
    void enable_all_palette_slots();
    s32 is_palette_slot_enabled(s32 slot);
    int try_use_item_by_type(int kind, int group, int subgroup);
    s32 check_can_add_item(s8 kind, s8 group);
    s32 can_use_item(TItem *item);
    s32 dispatch_palette_action(u32 act);
    s32 handle_palette_button_input();
    s32 execute_palette_action(s32 mode, void *target);
    void hold_battle_music();
    void release_battle_music();
    void start_battle_music();
    void stop_battle_music();
    s32 classify_action_state();
    void update_foot_stamp(int marker);
    void play_footstep_sound(f32 first_frame, f32 second_frame);
    void revive();
    s32 get_recovery_need_flags();
    s32 can_use_action();
    s32 is_target_valid();
    void update_subsystems();
    static u16 get_battle_ctrl_id(u16 client);
    void clear_action_flag();
    void apply_material_color_override();
    static s32 get_battle_ctrl_flag(u16 id);
    s32 is_outside_movement_hold(f32 *pos);
    static void play_effect(TObjPlayer *player, s32 effect_id, s32 mode);
    s32 get_clamped_index();
    void apply_input_mode();
    void select_class_action_provider();
    int has_valid_handle();
    void reset_equip_slots();
    s32 get_camera_field();
    void release_attached_resource();
    void action_enable_if_present();
    // The lock-on cursor slot that matches the action palette mode and slot, NULL without one.
    LockOnActionSlot *find_palette_lockon_slot();
    s32 is_quest_interaction_blocked();
    s32 has_action_palette_entry();
    static s32 is_effect_channel_active(TObjPlayer *player, s32 index);
    void refresh_party_cursors();
    void set_action_palette_entry(s32 secondary, s32 valid, s32 idx, s32 mode, u16 slot);
    u16 select_action_palette_and_apply(s32 secondary, s32 row, s32 index);
    TPlyDispConfigSmth *refresh_effect();
    void update_ground_contact();
    s32 check_actor_blocking_move();
    saddr resolve_move_collision();
    void rewind_position_history();
    s32 is_matching_id(s16 action);
    static s16 add_stat_clamped(s32 amount, s16 *stat, s16 max);
    s16 add_lck(s32 amount);
    s16 add_evp(s32 amount);
    s16 add_ata(s32 amount);
    s16 add_mst(s32 amount);
    s16 add_hp(s32 amount);
    s16 add_dfp(s32 amount);
    s16 add_stat(s32 amount);
    void update_aim_angle(s32 aim);
    void clamp_stats(player_stats *out, player_stats *class_stats);
    void notify_volopt_if_ready();
    void spawn_level_change_feedback(const char *message);
    s32 apply_exp_level_growth();
    void update_status_effects();
    void update_position_history();
    static void clear_lobby_flag(void *base);
    void init_effect_5f0();
    void get_hand_joint_position(Vec *out_pos);
    void close_sub_window();
    s32 find_inventory_item_id(s8 kind, s8 group);
    s32 try_add_sale_meseta(s32 item_id, s32 amount, s32 count);
    void drop_items_on_death();
    static void send_6x2A_drop_item(TObjPlayer *player, s32 item_id, Vec *pos, s32 amount);
    s32 send_trap_packet(int kind);
    void request_meseta_drop(s32 amount);
    void request_item_drop(s32 key, s32 count);
    s32 count_items_of_type(u8 kind, u8 group, u8 subgroup);
    void dispatch_action(s32 key, s32 amount);
    s32 can_inventory_accept_item(TItemData *item);
    s32 update_target_lock();
    void use_current_item();
    void unequip_all_units();
    void equip_item_to_slot(TItem *item, s32 slot);
    static void bind_saved_inventory_equipment(TObjPlayer *player, TPlyInventoryItem *records, int count);
    static void equip_saved_item_if_slot_empty(TObjPlayer *player, TPlyInventoryItem *record);
    s32 check_switch_available(s32 item_id);
    s32 end_camera_pan();
    static void freeze_all_players();
    // The callers pass the angle to the object as well; this does not use it.
    s32 start_camera_pan(s16 action, s32 angle);
    s32 init_photon_blast(s16 anim);
    s32 start_freeze();
    s32 register_player_slot();
    void apply_state_transform();
    void draw_head_attachments();
    void render_body_pass(f32 f);
    void draw_body(s32 detail);
    void draw_projected_shadow(Vec *scale, s32 force_draw);
    // Empty; every render path calls it after drawing the body, inside the
    // saved material state.
    void draw_body_overlay();
    s32 is_in_lobby();
    s32 check_flag_800000();
    void draw(f32 at_frame);
    void restore_hp_and_tp();
    s32 get_regen_interval(s32 timer);
    void unregister();
    void init_player_substructs(u8 *data);
    void init_action_palette_defaults();
    void send_respawn_position();
    void init_battle(void *data);
    void reset_area_entry_state();
    void send_6x30_change_player_level();
    void swap_inventory_items(s32 first_id, s32 second_id);
    void update_warp_relocation();
    s32 try_camera_action(s32 tech);
    static void update_party_cursors(TPlyDispConfigSmth *palette, TObjPlayer *player);
    s32 can_use_palette_action_for_entry(TObjPlayer *player);
    s32 is_palette_entry_displayable(u8 kind, u8 sub);
    s32 can_use_palette_action(u8 kind, u8 arg);
    void process_trade_target(TItemData *item_data);
    void trade_item_by_group_kind(s16 group, s16 kind);
    f32 select_normal_attack_marker();
    static void spawn_particle_at_entity_slot(s32 layer, s32 weapon, s32 id, s32 body);
    static void spawn_fire_explosion_for_item(s32 id, s32 item);
    static void spawn_fire_explosion_at_item(s32 id, saddr context);
    static void spawn_fire_explosion(uaddr a0, saddr a1);
    void push_model_fade_color();
    static bool is_slot_within_limit(s32 cls, s32 tech, u8 level);
    s32 can_use_camera_field();
    void init_parts();
    u16 get_action_palette_entry(s32 index);
    int is_action_active();
    u8 get_battle_mode();
    u8 get_byte_339();
    u8 get_def_materials_used();
    u8 get_evade_materials_used();
    u8 get_mind_materials_used();
    u8 get_power_materials_used();
    u8 get_luck_materials_used();
    void set_luck_materials_used(u8 v);
    static s32 clamp_index_to_max(s32 level);
    s32 clamp_nested_index();
    void clear_flag_20000();
    void set_flag_20000();
    void clear_flag_2000000();
    int check_flag_02000000();
    void set_position_history_entry(s32 index, f32 x, f32 z);
    void set_action_flag_2();
    int check_flag_48();
    int is_status_locked();
    int is_status_flag_200();
    void set_floor_index(s32 v);
    GC_Mtx *item_node_matrices;
    void revive_or_spawn_marker();
    void add_luck_material(u8 amount);
    void add_dfp_material(u8 amount);
    void add_evp_material(u8 amount);
    void add_mind_material(u8 amount);
    void add_power_material(u8 amount);
    void add_tp_material(u8 amount);
    void add_hp_material(u8 amount);
    s32 try_pickup_item();
    void emit_footstep_effect(f32 first_frame, f32 second_frame);
    void update_target();
    void check_level_up();
    // The stats shown with `incoming` equipped in place of what its slot holds
    // (1 when filled), and with the item `key` taken off (2 when filled).
    s32 preview_equip_stats(PlayerRequirementStats *out, u8 *incoming);
    s32 preview_unequip_stats(PlayerRequirementStats *out, s32 key);
    void send_unequip_held_item();
    void restart_death_pose();
    static PhotonBlastRequest *get_photon_blast_element(s32 index);
    void enter_photon_blast_action();
    void prepare_photon_blast_action();
    void enter_technique_cast();
    void request_technique_cast();
    void update_run_movement();
    void update_walk_movement();
    void check_idle_movement_request();
    void push_to_list(s32 id);
    static saddr run_and_return_arg(saddr queue);
    u8 get_mag_level();
    const Vec *get_guild_return_position();
    static void heap_alloc(void* a0);
    s32 can_guard();
    // Sets the player's cast level of technique `tech`, capped at the level it has learned.
    static void set_technique_level_clamped(TObjPlayer *player, u8 level, s16 tech);
    static void send_6x29_delete_item(TObjPlayer *player, s32 item_id, s32 count);
    void fill_player_record(PlayerSyncRecord *record);
    static void foreach_player(void (*callback)(TObjPlayer *));
    s32 calc_scaled_value(s32 value);
    void prepare_guild_return(s32);
    void apply_camera_shake(TObjCollidable *target, s32 damage);
    static s32 begin_action_state(TPlyCharData *character);
    // Calls callback with each occupied entry of the player table.
    static void for_each_player_slot(void (*callback)(TObjPlayer *));
    // Restores the player to full health and clears its status effects.
    static void recover_player_full(TObjPlayer *player);
    void send_object_id_packet();
    void update_action_state();
    s32 reset_volopt_state();
    s32 is_flag30_8_set();
    s32 is_flag30_10_set();
    void delete_multiple_inventory_items(s32 *item_ids, s32 count);
    static s32 is_key_machine_ready();
    void recover_full();
    void apply_speed_scale(f32 speed);
    s32 test_ordered_anim_markers(f32 first_frame, f32 second_frame);
    void remove_status_effect(StatStatusReceipt effect);
    void send_status_effect_remove(StatStatusReceipt effect);
    void dispatch_status_effect_msg(StatStatusReceipt effect);
    s32 query_state_if_present(void *);

    // Placeholder-named members defined in the player units.
    static void draw_capture_caption_bar();
    static int is_shadow_pass_requested();
    static void request_shadow_pass();
    static void clear_shadow_pass_request();
    static void load_capture_texture();
    static void end_screen_quad();
    s32 get_language();
    void record_meseta_pickup(s32 amount);
    static void send_local_player_visible();
    static void send_local_player_invisible();
    void resend_status_effects();
    void reset_pending_action();
    void release_pending_action();
    void reset_action_input();
    void release_action_palettes();
    void release_lock_on_cursor();
    void send_selected_spawn_position(u16 id);
    void release_area_placement();
    void assign_owner_ids();
    void reset_technique_caps();
    void release_technique_caps();
    void release_area_sync();
    void release_char_data();
    void reset_pad_binding();
    void release_pad_binding();
    void release_motion();
    void reset_body_parts();
    void set_regen_timer(s32 v);
    void get_position_history_entry(int index, f32 *x, f32 *z);
    s32 get_state_flags();
    int check_player_state_flag_2();
    static int default_action_provider_variant();
    void lobby_chair_phase8_nop();
    void finish_chair_sit_down();
    void lobby_animation_phase1_nop();
    void send_6x58_lobby_animation();
    void send_6x57();
    void lobby_animation_phase8_nop();
    void lobby_animation_phase2_nop();
    void enter_off_floor_state();
    void update_off_floor_state();
    void fade_out_off_floor();
    void deactivate_off_floor_body();
    void off_floor_phase2_nop();
    void off_floor_phase7_nop();
    void warp_phase8_nop();
    void warp_phase2_nop();
    void warp_phase7_nop();
    void return_to_idle_when_unfrozen();
    void freeze_phase2_nop();
    void revival_phase2_nop();
    void revival_phase7_nop();
    void death_phase7_nop();
    void fall_reaction_phase8_nop();
    void fall_reaction_phase2_nop();
    void hurt_phase8_nop();
    void hurt_phase2_nop();
    void action11_phase6_nop();
    void update_action11_movement();
    void send_6x51_set_player_angle();
    void action11_phase8_nop();
    void action11_phase2_nop();
    void switch_interaction_phase6_nop();
    void switch_interaction_phase8_nop();
    void switch_interaction_phase2_nop();
    int try_switch_interaction_status_action();
    void guard_reaction_phase8_nop();
    void guard_reaction_phase2_nop();
    void photon_blast_phase2_nop();
    void technique_cast_phase2_nop();
    void update_attack_stage3();
    void attack_stage3_phase8_nop();
    void update_attack_stage2();
    void attack_stage2_phase8_nop();
    void update_attack_stage();
    void enter_attack_stage1();
    void enter_attack_stage2();
    void enter_attack_stage3();
    void start_action_0e();
    void end_freeze_action();
    void start_use_item_action();
    s32 try_equip_item(s16 tech);
    s32 can_start_technique(s32 tech);
    void check_attack_stage2_input();
    s32 select_attack_palette_slot();
    void attack_stage1_phase8_nop();
    int try_attack_stage1_status_action();
    int try_run_status_action();
    void action3_phase6_nop();
    void action3_phase1_nop();
    void action3_phase0_nop();
    void action3_phase5_nop();
    void action3_phase8_nop();
    void action3_phase3_nop();
    void action3_phase2_nop();
    int try_walk_status_action();
    void idle_phase8_nop();
    void leave_chair_seat();
    void clear_chair_seated();
    void clear_anim_flag();
    int create_photon_chair();
    void set_chair_seated();
    // The chair-seated bit set_chair_seated sets.
    int is_mounted();
    void clear_lobby_pose_hold();
    s32 get_lobby_entry_yaw();
    u8 * get_cast_motion_record();
    static void restore_model_render_state();
    static void save_model_render_state();
    s32 can_equip_item(s32 tech);
    void clear_links();
    void ensure_default();
    int get_flag();
    s32 is_action_channel_available(s32 channel);
    void notify_lobby();
    short query_child_state2();
    s32 update_aim_target();
    s32 update_combat_stats();
    void update_timer_state();
    s32 tick_regen_timer();
    void send_6xA1_player_id();
    s32 get_regen_timer();
    int is_motion_paused();
    // End of placeholder-named members.

    // Per-part init steps: from a joining player's record and from a saved character.
    void init_session_technique_caps(PlayerSyncRecord *record);
    void init_saved_technique_caps(TPlyCharData *record);
    void init_session_area_sync(void *record);
};

u8 get_item_count_max();

void start_freeze_self(TObjPlayer *player);

void clear_flag_4000_callback(TObjPlayer *player);

#include <stddef.h>
LAYOUT_ASSERT(PlayerPaletteModifierOffset, offsetof(TObjPlayer, photon_blast_gauge) == 0x4AC);
LAYOUT_ASSERT(PlayerActionPalettesOffset, offsetof(TObjPlayer, action_palettes) == 0x500);
LAYOUT_ASSERT(PlayerStateAfterPalettes, offsetof(TObjPlayer, pad_binding) == 0x550);
LAYOUT_ASSERT(PlayerCollisionBodyOffset, offsetof(TObjPlayer, collision_body) == 0x680);
LAYOUT_ASSERT(PlayerAppearanceOffset, offsetof(TObjPlayer, appearance) == 0x85C);
LAYOUT_ASSERT(PlayerHairModelOffset, offsetof(TObjPlayer, hair_model) == 0x8AC);
LAYOUT_ASSERT(PlayerHeadTexturesOffset, offsetof(TObjPlayer, head_textures) == 0x8B8);
LAYOUT_ASSERT(PlayerAttachmentTexturesOffset, offsetof(TObjPlayer, attachment_textures) == 0xA24);
LAYOUT_ASSERT(PlayerBodyTexturesOffset, offsetof(TObjPlayer, body_textures) == 0xB90);
LAYOUT_ASSERT(PlayerModelLoadFlagsOffset, offsetof(TObjPlayer, model_load_flags) == 0xCFC);
LAYOUT_ASSERT(PlayerInventoryObjectOffset, offsetof(TObjPlayer, inventory_objects) == 0xD00);
LAYOUT_ASSERT(PlayerBaseStatsOffset, offsetof(TObjPlayer, base_stats) == 0xD38);
LAYOUT_ASSERT(PlayerAttackStatsOffset, offsetof(TObjPlayer, attack_stats) == 0xD5C);
LAYOUT_ASSERT(PlayerResistanceStatsOffset, offsetof(TObjPlayer, resistance_stats) == 0xD8C);

LAYOUT_ASSERT(TObjPlayer_area_offset, offsetof(TObjPlayer, current_area) == 0x3E0);
LAYOUT_ASSERT(TObjPlayer_render_material_state_offset, offsetof(TObjPlayer, render_material_state) == 0x608);
LAYOUT_ASSERT(TObjPlayer_appear_fade_offset, offsetof(TObjPlayer, appear_fade) == 0x634);
LAYOUT_ASSERT(TObjPlayer_protection_offset, offsetof(TObjPlayer, protection) == 0x644);
LAYOUT_ASSERT(TObjPlayer_unit_scale_offset, offsetof(TObjPlayer, unit_scale) == 0x66C);
LAYOUT_ASSERT(TObjPlayer_intra_map_warp_offset, offsetof(TObjPlayer, intra_map_warp) == 0x658);
LAYOUT_ASSERT(TObjPlayer_npc_control_offset, offsetof(TObjPlayer, npc_control) == 0x678);
LAYOUT_ASSERT(TObjPlayer_movement_history_offset, offsetof(TObjPlayer, movement_history) == 0x6AC);
LAYOUT_ASSERT(TObjPlayer_movement_hold_offset, offsetof(TObjPlayer, movement_hold) == 0x730);
LAYOUT_ASSERT(TObjPlayer_photon_blast_aim_offset, offsetof(TObjPlayer, photon_blast_aim) == 0x744);
LAYOUT_ASSERT(TObjPlayer_battle_score_offset, offsetof(TObjPlayer, battle_score) == 0x754);
LAYOUT_ASSERT(TObjPlayer_pk_state_offset, offsetof(TObjPlayer, pk_state) == 0x828);
LAYOUT_ASSERT(PlayerItemNodeMatricesOffset, offsetof(TObjPlayer, item_node_matrices) == 0xDB4);
LAYOUT_ASSERT(TObjPlayer_size, sizeof(TObjPlayer) == 0xDB8);

void set_flag_400000(TObjPlayer *player);

class TDeathTintFade;
// Runs when a dying player's tint fade reaches full: the player of the fade's viewport goes down.
void complete_deferred_player_death(TDeathTintFade *fade);

// Sends 6x2D: releases the movement hold on the player.
void send_release_hold(TObjPlayer *player);
// Sends 6x2C: holds the player in place for `frames` frames (-1: until released).
void send_impose_hold(TObjPlayer *player, int frames);

// The owner joint each item attach slot hangs the equipped model from
// (TItemEquipBase::set_attach_slot); defined with the player.
extern s16 item_equip_attach_equip_flag_table[];

// The demo camera check_demo_mode tests; TCameraDebugView looks at its entry of
// demo_camera_params_table.
extern s16 demo_camera_index;

// The player object of each client id (NULL while the slot is empty).
extern TObjPlayer *player_slot_table[12];

void send_6x25_equip_item(TObjPlayer *player, s32 item_id, s32 slot);
void assign_inventory_item_ids(TObjPlayer *player, TPlyInventoryItem *records, s32 count);
void rebuild_player_inventory(TObjPlayer *player);

// Clears the player's control-lock flag (0x200); run on every player slot.
void release_control_lock(TObjPlayer *player);

// Empty; pickup_item calls it as an item joins the inventory, with the slot it takes.
void on_inventory_item_added(TItem *item, s32 slot);

// Whether any of mask is set in the flags of collision body `body` (name inferred).
s32 has_body_flags(TObjCollidable *obj, s32 body, u32 mask);
void emit_sand_footstep_effect(PlayerFollowParticles *particles);

void emit_water_footstep_effect(PlayerFollowParticles *particles);

void emit_grass_footstep_effect(PlayerFollowParticles *particles);

// Photon blast motion frames of one weapon handle.
struct PhotonBlastMotionTiming {
    f32 hold_frame;
    f32 upper_bound;
    f32 complete_threshold;
};

#endif
