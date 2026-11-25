#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/player/PhotonBlastRequests.h"
#include "pso/player/PlayerState.h"
#include "pso/player/PlayerRequirementStats.h"
#include "pso/player/PlayerTaskEffects.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/TDeathTintFade.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSnapShot_802A7D68.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/player/Palettex.h"
#include "pso/player/TPlayerFootStamp.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/memory.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/TPlyInventory.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/item/TItemLockCountCtrl_8011E184.h"
#include "pso/player/PlayerSyncRecord.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TPlyDispData.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/PlayerCharDataEntry.h"
#include "pso/player/TPlayerReadyCallback.h"
#include "pso/player/PlayerActionPaletteState.h"
#include "pso/player/TPlayerLobbyMarker.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/text_80072004.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/boss/barbaray/TBoss7Crawfish.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/TPlyPtclObjectLeftHand.h"
#include "pso/player/TPlyPtclObjectRightHand.h"
#include "pso/player/PlayerTechniqueState.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include <string.h>
#include "pso/network/protocol/packet_classes.h"
#include "pso/item/TItemData.h"
#include "pso/item/InventoryEntryCopy.h"
#include "pso/player/PhotonBlastGauge.h"
#include "pso/item/TItemList.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer_80309D80.h"
#include "pso/map/area/AreaScene.h"
#include "pso/enemy/wolf/TObjEneBm5Wolf.h"
#include "pso/player/PlayerLevelTable.h"
#include "pso/player/TPlyItem.h"
#include "pso/technique/TTecLuker.h"
#include "pso/player/CapturedTargetList.h"
#include "pso/player/PlayerTelepipe.h"
#include "pso/player/InventoryItemList.h"

u8 *TObjPlayer::create_player_instance(s32 slot, PlayerCharDataEntry *player) {
    u8 *p;
    p = (u8 *)new TObjPlayer(tl_03, slot & 0xFFFF, player->get_role(), player->get_char_data());
    ((TLobby *)(p + 0xDAC))->copy_header_struct(player->get_lobby_header());
    ((TObjPlayer *)p)->reset_motion_fields();
    return p;
}

TObjPlayer *create_player_object(s32 slot, s32 role, TPlyCharData *record) {
    decode_created_player_inventory(record);
    return new TObjPlayer(tl_03, slot, role, record);
}



extern s32 lbl_805D5D7C;

PhotonBlastRegistry *TObjPlayer__shared_photon_blast_state;
s32 lobby_player_count;

void TObjPlayer::free_shared_data() {
    if (TObjPlayer__shared_photon_blast_state != NULL) {
        delete TObjPlayer__shared_photon_blast_state;
        TObjPlayer__shared_photon_blast_state = NULL;
    }
    if (player_shared_buffer_base != NULL) {
        mem_free(player_shared_buffer_base);
        player_shared_buffer_base = NULL;
    }
    if (shared_model_buffer != NULL) {
        mem_free(shared_model_buffer);
        shared_model_buffer = NULL;
    }
}

void TObjPlayer::alloc_shared_buffers() {
    if (shared_model_buffer == NULL) {
        shared_model_buffer = static_cast<u8 *>(mem_alloc(0x9000));
    }
    if (player_shared_buffer_base == NULL) {
        player_shared_buffer_base = static_cast<PlayerJointMatrixSet *>(mem_alloc(12 * sizeof(PlayerJointMatrixSet)));
    }
    if (TObjPlayer__shared_photon_blast_state == NULL) {
        TObjPlayer__shared_photon_blast_state = new PhotonBlastRegistry();
    }
}

void TObjPlayer::finalize_shared() { TLobby::set_player_count(0); TObjPlayer::set_shared_count(0); TObjPlayer::set_shared_flag(0); lbl_805D5D7C = 0; ((TLobby *)lobby_rule_settings)->reset_settings_to_default(); shared_state_flags[0] = 0; TLockOnCursor::free_cursor_resources(); free_player_motion_directory(); TPlayerFootStamp::free_instance(); TObjPlayer::free_shared_data(); }

void TObjPlayer::init_shared() { TObjPlayer::alloc_shared_buffers(); TLobby::set_player_count(0); TObjPlayer::set_shared_count(1); TObjPlayer::set_shared_flag(0); lbl_805D5D7C = 0; alloc_player_motion_directory(); load_player_motion_data(); copy_player_motion_directory(); upload_player_motion_data(); free_player_motion_archive(); load_target_cursor_models(); load_player_footstamp(); reset_client_quest_slot_table(); shared_state_flags[0] = 0; }

extern "C" {
extern u8 TObjPlayer__char_data_array[];
void __sinit_TObjPlayer_cpp();
void __destroy_arr(void *block, void *dtor, u32 size, u32 n);
void __register_global_object(void *obj, void *dtor, void *chain);
void *__construct_array(void *, void *, void *, u32, u32);
void construct__19PlayerCharDataEntryFv(void *);
void *__dt__19PlayerCharDataEntryFv(void *entry, s16 mode);

}

ArrivalOverride player_arrival_overrides[12];
TObjPlayer *player_slot_table[12];
s32 lobby_rule_settings[9];
u8 lbl_8050EA64[0xC];
u8 TObjPlayer__char_data_array[0x42C * 0xC];


void __sinit_TObjPlayer_cpp() {
    __construct_array(player_arrival_overrides, (void *)init_arrival_override, NULL, sizeof(ArrivalOverride), 12);
    ((TObjPlayer *)lobby_rule_settings)->reset_lobby_settings();
    __construct_array(TObjPlayer__char_data_array, (void *)construct__19PlayerCharDataEntryFv, (void *)__dt__19PlayerCharDataEntryFv, 0x42C, 0xC);
    __register_global_object(NULL, (void *)TObjPlayer::destroy_char_data_array, lbl_8050EA64);
}

void TObjPlayer::destroy_char_data_array() {
    __destroy_arr(TObjPlayer__char_data_array, (void *)__dt__19PlayerCharDataEntryFv, 0x42c, 0xc);
}


__declspec(section ".ctors") static void *const __sinit_TObjPlayer_cpp_ref = (void *)__sinit_TObjPlayer_cpp;



PlayerCharDataEntry::~PlayerCharDataEntry() {}

void TObjPlayer::get_pos(saddr out) {
    this->get_anim_node_position(0x3A, (Vec *)out);
}

void TObjPlayer::spend_photon_blast_charge(f32 charge) { photon_blast_gauge.subtract_photon_blast_charge(charge); }

void TObjPlayer::gain_photon_blast_chain_charge(f32 amount) { add_photon_blast_chain_charge(&photon_blast_gauge, amount); }

s32 TObjPlayer::vfunc_79() { return 0; }
s32 TObjPlayer::check_camera_mode() {
    return (u8)((u8) (is_quest_active() == 1));
}
void TObjPlayer::set_regen_timer(s32 v) { this->regen_timer = v; }
s32 TObjPlayer::get_regen_timer() { return this->regen_timer; }
int TObjPlayer::is_newman() { return (this->class_flags & CLASS_FLAG_NEWMAN) != 0; }
int TObjPlayer::is_android() { return (this->class_flags & CLASS_FLAG_ANDROID) != 0; }
void TObjPlayer::check_stat_flag_41c() { pending_actions.set(32); }
void TObjPlayer::check_flag_at_41c() { pending_actions.set(4); }
void TObjPlayer::set_flag_41c_bit1() { pending_actions.set(2); }
void TObjPlayer::clamp_stat_41c() { pending_actions.set(8); }


s8 TObjPlayer::get_rule_field_0() {
    return ((TLobby *)lobby_rule_settings)->get_rule_field_0();
}



void TObjPlayer::clear_flag_400000() {
    clear_state_flags(0x400000);
}

short TObjPlayer::get_model_field_m25() {
    return action_provider->get_death_action();
}

short TObjPlayer::get_action_animation() {
    return action_provider->get_knockdown_action();
}

short TObjPlayer::call_model_m24() {
    return action_provider->get_hurt_action();
}

short TObjPlayer::get_weapon_stat_c() {
    return action_provider->get_interact_action();
}

short TObjPlayer::call_obj_vt26() {
    return action_provider->get_interact_action();
}

short TObjPlayer::query_child_state() {
    return action_provider->get_use_item_action();
}

short TObjPlayer::query_equip() {
    return action_provider->get_photon_blast_action();
}

short TObjPlayer::get_status() {
    return action_provider->get_technique_action();
}

short TObjPlayer::get_model_state() {
    return action_provider->get_attack3_action();
}

short TObjPlayer::get_state() {
    return action_provider->get_attack2_action();
}

short TObjPlayer::get_attack1_action() {
    return action_provider->get_attack1_action();
}

short TObjPlayer::get_run_action() {
    return action_provider->get_run_action();
}


TObjPlayer *get_local_player() {
    return get_player_by_client_id(local_client_id);
}



void TObjPlayer::clear_flag_200000() {
    clear_state_flags(0x200000);
}
int TObjPlayer::check_flag_4() { return check_flag(4); }
G_SetPlayerInvisible_6x22 &G_SetPlayerInvisible_6x22::operator=(const G_SetPlayerInvisible_6x22 &src) {
    copy_subcommand_header(this, &src);
    return *this;
}
void TObjPlayer::clear_flag_4000_callback(TObjPlayer *player) { player->clear_flag_4000(); }
void TObjPlayer::clear_flag_4000() { clear_state_flags(16384); }
void TObjPlayer::set_flag_4000() { this->set_state_flags(16384); }
void TObjPlayer::set_battle_flag(s32 v) { this->m_3b4 = v; }
s32 TObjPlayer::get_anim_id() { return this->m_3b4; }
int TObjPlayer::check_flag_0x40000000() { return (this->state_flags >> 30) & 0x1; }
void TObjPlayer::clear_flag_0x2() { this->state_flags &= 0xfffffffd; }


int TObjPlayer::is_action_active() { return (this->state_flags >> 1) & 0x1; }
void PlayerSyncRecord::set_class_flag_2(u8 v) { items[15].m_present[3] = v; }
u8 TObjPlayer::get_battle_mode() { return unk_33A[0]; }
void PlayerSyncRecord::set_class_flag_1(u8 v) { items[14].m_present[3] = v; }
u8 TObjPlayer::get_byte_339() { return this->m_339; }
void PlayerSyncRecord::set_class_flag_0(u8 v) { items[13].m_present[3] = v; }
u8 TObjPlayer::get_mag_level() { return unk_338[0]; }
void PlayerSyncRecord::set_luck_materials_used(u8 v) { items[12].m_present[3] = v; }
u8 TObjPlayer::get_luck_materials_used() { return materials.get_luck_used(); }
void PlayerSyncRecord::set_def_materials_used(u8 v) { items[11].m_present[3] = v; }
u8 TObjPlayer::get_def_materials_used() { return materials.get_def_used(); }
void PlayerSyncRecord::set_evade_materials_used(u8 v) { items[10].m_present[3] = v; }
u8 TObjPlayer::get_evade_materials_used() { return materials.get_evade_used(); }
void PlayerSyncRecord::set_mind_materials_used(u8 v) { items[9].m_present[3] = v; }
u8 TObjPlayer::get_mind_materials_used() { return materials.get_mind_used(); }
void PlayerSyncRecord::set_power_materials_used(u8 v) { items[8].m_present[3] = v; }
u8 TObjPlayer::get_power_materials_used() { return materials.get_power_used(); }


InventoryItemList::InventoryItemList() {
    s32 i;
    count = 0;
    for (i = 0; i < 30; i++) {
        items[i].init();
    }
}


void TObjPlayer::set_move_mode(s32 v) { this->m_3dc = v; }
void TObjPlayer::set_input_mode(s32 v) { this->m_3d8 = v; }


s32 has_body_flags(TObjCollidable *obj, s32 body, u32 mask) {
    return (u8)((obj->bodies[body].flags & mask) != 0);
}

void* TObjPlayer::get_position_history_entry(int index, void* x, void* z) { *(float*)x = *(float*)((char*)this + index * 8 + 0x6b0); *(float*)z = *(float*)((char*)this + index * 8 + 0x6b4); return (char*)this + index * 8; }
s32 TObjPlayer::clamp_index_to_max(s32 level) {
    s32 max_level;

    max_level = level;
    if (max_level < 0) {
        max_level = 0;
    } else if (max_level > TObjPlayer::get_max_level()) {
        max_level = TObjPlayer::get_max_level();
    }
    return max_level;
}
s32 TObjPlayer::clamp_nested_index() {
    return TObjPlayer::clamp_index_to_max(this->stat_block->level);
}
void TObjPlayer::clear_flag_20000() {
    clear_state_flags(0x20000);
}
void TObjPlayer::set_flag_20000() {
    set_state_flags(0x20000);
}
void TObjPlayer::clear_flag_2000000() {
    clear_state_flags(0x02000000);
}
int TObjPlayer::check_flag_02000000() {
    return check_flag(0x02000000);
}

void TObjPlayer::set_position_history_entry(s32 index, f32 x, f32 z) {
    u8 *entry = (u8 *)this + index * 8;
    *(f32 *)(entry + 0x6B0) = x;
    *(f32 *)(entry + 0x6B4) = z;
}



void TObjPlayer::set_action_flag_2() { this->state_flags |= 0x2; }
void set_flag_400000(TObjPlayer *player) {
    player->set_state_flags(0x400000);
}
int TObjPlayer::check_flag_48() { return check_flag(48); }
int TObjPlayer::is_status_locked() { return this->actorFlags & 0x10000; }
int TObjPlayer::is_status_flag_200() { return this->actorFlags & 0x200; }
void end_player_camera_pan(TObjPlayer *player) { player->end_camera_pan(); }
void TObjPlayer::start_freeze_self(TObjPlayer *player) { player->start_freeze(); }
void TObjPlayer::set_floor(s32 v) { this->current_floor = v; }
void TObjPlayer::set_floor_index(s32 v) { current_area = v; }



s32 TObjPlayer::get_state_flags() { return this->state_flags; }
int TObjPlayer::unregister_sub() { return unregister_object_by_id(); }
void TObjPlayer::set_control_role(s32 v) { *(s32 *)&this->unk_3E8 = v; }
u8 PlayerSyncRecord::get_class_flag_2() { return items[15].m_present[3]; }
u8 PlayerSyncRecord::get_class_flag_1() { return items[14].m_present[3]; }
u8 PlayerSyncRecord::get_class_flag_0() { return items[13].m_present[3]; }
void TObjPlayer::set_language(s32 v) { this->language = v; }
void TObjPlayer::reset_entrance_id() { entrance_id = -1; }
void TObjPlayer::set_luck_materials_used(u8 v) { materials.set_luck_used(v); }
u8 PlayerSyncRecord::get_luck_materials_used() { return items[12].m_present[3]; }
void TObjPlayer::set_def_materials_used(u8 v) { materials.set_def_used(v); }
u8 PlayerSyncRecord::get_def_materials_used() { return items[11].m_present[3]; }
void TObjPlayer::set_evade_materials_used(u8 v) { materials.set_evade_used(v); }
u8 PlayerSyncRecord::get_evade_materials_used() { return items[10].m_present[3]; }
void TObjPlayer::set_mind_materials_used(u8 v) { materials.set_mind_used(v); }
u8 PlayerSyncRecord::get_mind_materials_used() { return items[9].m_present[3]; }
void TObjPlayer::set_power_materials_used(u8 v) { materials.set_power_used(v); }
u8 PlayerSyncRecord::get_power_materials_used() { return items[8].m_present[3]; }





int TPlyPhotonChair::is_mounted() { return (*(u32*)((char*)this + 0x334) >> 26) & 0x1; }

void PhotonBlastAim::reset() {
    target_id = 0xFFFF;
    pad_2 = 0;
    position.x = position.y = position.z = player_zero;
}

PlayerNpcControl::PlayerNpcControl() {
    controller_client_id = 0xFFFF;
    state = 0;
}

s32 TObjPlayer::get_entrance_id() { return entrance_id; }

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_8 { u8 bytes[0x8]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
void TObjPlayer__sub_801BEEE0(void* p, void* q);
void TObjPlayer__sub_801BEF30(void* p, void* q);
void emit_idle_water_effect(PlayerFollowParticles *particles);
}
void emit_grass_footstep_effect(PlayerFollowParticles *particles);
void emit_water_footstep_effect(PlayerFollowParticles *particles);
void emit_sand_footstep_effect(PlayerFollowParticles *particles);
void emit_photon_blast_feedback_effects(saddr owner, u16 target_id);
int shared_count;
int shared_flag;

#pragma defer_codegen on
ContactSurfaceFlags::~ContactSurfaceFlags() {}

ContactSurfaceState::~ContactSurfaceState() {}

#pragma push
#pragma dont_inline on
PlayerActionPaletteState::~PlayerActionPaletteState() {}

void PlayerDeathSink::set_progress(f32 v) { progress = v; }

void PlayerAppearFade::set_client_id(u16 id) { client_id = id; }

void UnitScale::reset() {
    z = y = x = player_one;
}

void BattleMusicState::reset_counter_field4() {
    timer = 0;
    flags.reset();
}

void PlayerActionPaletteState::init_tag() {
    disabled_slots = 0;
    tag.init();
}

#pragma pop

void PlayerDeathSink::reset() {
    offset = player_zero;
    height = player_zero;
    progress = player_zero;
}

s32 ArrivalOverride::get_active() { return active; }

void ArrivalOverride::set_active(s32 v) { active = v; }

s32 ArrivalOverride::get_heading() { return heading; }

Vec *ArrivalOverride::get_pos() { return &pos; }

void PlayerScaleState::set_actor_id(u16 id) { actor_id = id; }

Vec *PlayerScaleState::get_scale() { return &scale; }

s16 PlayerAnimationState::get_action_id() { return action_id; }

s32 PlayerAppearFade::is_shown() { return (u8)(state == SHOWN); }

Vec *get_marker_position(Vec *position) { return position; }

void clear_equip_slots(s32 *slots) {
    s32 i;
    for (i = 0; i < 13; i++) {
        *slots++ = 0;
    }
}

void set_equip_slot_entry(saddr slots, s32 slot, s32 item) {
    ((s32 *)slots)[slot] = item;
}

void ContactSurfaceState::reset_flags() { word.reset(); }

void ContactSurfaceState::clear_surface() { reset_flags(); }

void ContactSurfaceState::check_flag_2() { word.set(2); }

void ContactSurfaceState::set_flag_4() { word.set(4); }

void ContactSurfaceState::set_sand() { word.set(8); }

void ContactSurfaceState::test_flag_16() { word.set(16); }

f32 PlayerMoveSpeed::get_speed() { return speed; }

void PlayerAnimationState::set_action_id(s16 v) { action_id = v; }

void PlayerAnimationState::set_animation(s16 v) { animation = v; }

void PlayerAnimationState::set_state(s16 v) { state = v; }

void PlayerAnimationState::set_angle(s32 v) { angle = v; }

void ContactSurfaceState::update_field8() {
    prev_flags = get_flags();
}

void ContactSurfaceState::stop_timer() { timer = -1; }

s32 ContactSurfaceState::update_timer() {
    if (is_timer_running() != 0) {
        if (--timer < 0) {
            stop_timer();
        }
    }
    return timer;
}

PlayerLevelStats::PlayerLevelStats() {
    clear_fields();
    hp_max = tp_max = 0;
}

u8 PlayerActionPaletteState::get_mode() const {
    return get_action_palette_tag_mode(&tag);
}

u8 PlayerActionPaletteState::get_slot() const {
    return get_action_palette_tag_slot(&tag);
}

void MovementHold::set_effect_type(s16 v) { effect_type = v; }

void MovementHold::set_frames(s16 v) { frames = v; }

void MovementHold::set_center(f32 x, f32 z) { center_x = x; center_z = z; }

void MovementHold::set_radius_sq(f32 v) { radius_sq = v; }

f32 *MovementHold::get_center() { return &center_x; }

f32 MovementHold::get_radius_sq() { return radius_sq; }

void MovementHold::reset() {
    frames = 0;
    effect_type = 0;
    radius_sq = player_zero;
    center_z = player_zero;
    center_x = player_zero;
}

MovementHold *MovementHold::init() {
    reset();
    return this;
}

int ContactSurfaceState::get_flags() { return word.get_bits(); }

s32 ContactSurfaceState::get_changed_flags() {
    return prev_flags ^ get_flags();
}

s32 ContactSurfaceState::has_water_or_sand(s32 v) {
    return (u8)((v & 0xC) != 0);
}

void ContactSurfaceState::set_timer(s32 v) { timer = v; }

s32 ContactSurfaceState::check_surface_exit() {
    if (has_water_or_sand(get_changed_flags()) != 0 && has_water_or_sand(prev_flags) != 0) {
        set_timer(0x96);
        return 1;
    }
    return 0;
}

s16 MovementHold::get_frames() { return frames; }

s32 MovementHold::count_down() {
    if (--frames < 0) {
        return 0;
    }
    return 1;
}

s32 ContactSurfaceState::is_timer_running() {
    return (u8)(timer != -1);
}

void BattleMusicState::set_flag_2() { flags.set(2); }

void BattleMusicState::clear_flag0_bit1() { flags.clear(2); }

void PlayerActionPaletteState::set_mode(u8 mode) {
    set_action_palette_tag_mode(&tag, mode);
}

void PlayerActionPaletteState::set_slot(u8 slot) {
    set_action_palette_tag_slot(&tag, slot);
}

void PlayerActionPaletteState::disable_slot(s32 slot) {
    disabled_slots |= 1 << slot;
}

void PlayerActionPaletteState::enable_slot(s32 slot) {
    disabled_slots &= ~(1 << slot);
}

void PlayerActionPaletteState::enable_all_slots() { disabled_slots = 0; }

s32 PlayerActionPaletteState::is_slot_enabled(s32 slot) {
    return !(disabled_slots & (1 << slot));
}

TPlayerReadyCallback::TPlayerReadyCallback(TObject* parent, u16 id, void (*fn)(TObjPlayer*)) : TObject(parent) {
    player_id = id;
    callback = fn;
}

void TPlayerLobbyMarker::set_material_index(u8 v) { this->material_index = v; }

int ContactSurfaceState::has_water_ground_flag() { return test_flags_any(&word.bits, 4); }

void PlayerFollowParticles::set_grass_contact_point(const Vec *point) { VecCopy(&contact_points[1], point); }

void PlayerFollowParticles::set_surface_contact_point(const Vec *point) { VecCopy(&contact_points[2], point); }

void emit_photon_blast_feedback_effects(saddr owner, u16 target_id) {
    TObjPlayer::check_hit_by_id(owner, target_id, 5);
    TObjPlayer::check_hit_by_id(owner, target_id, 0x2C);
    TObjPlayer::check_hit_by_id(owner, target_id, 0x3B);
}

void TObjPlayer::emit_photon_blast_feedback_from_packet() {
    u16 *arg0 = (u16 *)this;
    emit_photon_blast_feedback_effects((saddr)((s8 *)arg0 + 4), *arg0);
}

Vec *PlayerFollowParticles::get_grass_contact_point() { return &contact_points[1]; }

TParticleCtrl *PlayerHandParticles::emit_grass_footstep_particle(const Vec *position) { return emit_player_particle(this, position, 570); }

void emit_grass_footstep_effect(PlayerFollowParticles *particles) {
    particles->hands.emit_grass_footstep_particle(particles->get_grass_contact_point());
}

void emit_water_footstep_effect(PlayerFollowParticles *particles) {
    emit_water_step_particles(&particles->hands, particles->get_surface_contact_point());
}

void emit_sand_footstep_effect(PlayerFollowParticles *particles) {
    emit_sand_step_particles(&particles->hands, particles->get_surface_contact_point());
}

void TObjPlayer::check_hit_by_id_431_from_packet() {
    u16 *arg0 = (u16 *)this;
    TObjPlayer::check_hit_by_id_431((s8 *)arg0 + 4, *arg0);
}

int PlayerHandParticles::emit_movement_effect(u16 target_id) { return TObjPlayer::check_hit_by_id((saddr)this, target_id, 276); }

int PlayerFollowParticles::emit_movement_effect() { return hands.emit_movement_effect(owner_id); }

Vec *PlayerFollowParticles::get_surface_contact_point() { return &contact_points[2]; }

void emit_idle_water_effect(PlayerFollowParticles *particles) {
    emit_idle_water_splash(&particles->hands, particles->get_surface_contact_point());
}

#pragma push
#pragma fp_contract on
void PlayerHandParticles::emit_shifta_support_effect() {
    if (left_hand != NULL) {
        TObjPlayer::check_hit_by_id((saddr)this, left_hand->get_entity_id(), 0x1C);
    }
    if (right_hand != NULL) {
        TObjPlayer::check_hit_by_id((saddr)this, right_hand->get_entity_id(), 0x1C);
    }
}
#pragma pop

void PlayerFollowParticles::emit_shifta_support() { hands.emit_shifta_support_effect(); }

#pragma push
#pragma fp_contract on
void PlayerHandParticles::emit_jellen_support_effect() {
    if (left_hand != NULL) {
        create_attached_oneshot_emitter(this, left_hand->get_entity_id(), 0x1C);
    }
    if (right_hand != NULL) {
        create_attached_oneshot_emitter(this, right_hand->get_entity_id(), 0x1C);
    }
}
#pragma pop

void PlayerFollowParticles::emit_jellen_support_effect_default() { hands.emit_jellen_support_effect(); }

int PlayerHandParticles::emit_deband_support_effect(u16 target_id) { return TObjPlayer::check_hit_by_id((saddr)this, target_id, 508); }

int PlayerFollowParticles::emit_deband_support() { return hands.emit_deband_support_effect(owner_id); }

TParticleCtrl *PlayerHandParticles::emit_zalure_support_effect(u16 target_id) { return create_attached_oneshot_emitter(this, target_id, 508); }

TParticleCtrl *PlayerFollowParticles::emit_zalure_support() { return hands.emit_zalure_support_effect(owner_id); }

#pragma push
#pragma fp_contract on
void PlayerHandParticles::prepare_heavy_attack_particles() {
    if (right_hand != NULL) {
        TObjPlayer::check_hit_by_id((saddr)this, right_hand->get_entity_id(), 0x11);
        TObjPlayer::check_hit_by_id((saddr)this, right_hand->get_entity_id(), 0x12);
    }
}
#pragma pop

void PlayerFollowParticles::prepare_heavy_attack_particles_default() { hands.prepare_heavy_attack_particles(); }

void PlayerPadBinding::set_controller(ControllerInputContext *context) { controller = context; }

StatusEffect &StatusEffect::operator=(StatusEffect &src) {
    type = src.type;
    amount = src.amount;
    timer = src.timer;
    return *this;
}

void TObjPlayer__sub_801BEF30(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }

void TObjPlayer::copy_player_record_header(u8 *src) {
    u8 *dst = (u8 *)this;
    *(u16 *)((s8 *)dst + 0) = (u16) *(u16 *)((s8 *)src + 0);
    *(s16 *)((s8 *)dst + 2) = (s16) *(s16 *)((s8 *)src + 2);
    *(s32 *)((s8 *)dst + 4) = (s32) *(s32 *)((s8 *)src + 4);
    __memcpy(&this->m_prev, src + 8, 0xC);
    *(s32 *)((s8 *)dst + 0x14) = (s32) *(s32 *)((s8 *)src + 0x14);
    *(s32 *)((s8 *)dst + 0x18) = (s32) *(s32 *)((s8 *)src + 0x18);
}

void TObjPlayer__sub_801BEEE0(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); }

MovementHold &MovementHold::operator=(MovementHold &src) {
    frames = src.frames;
    effect_type = src.effect_type;
    unused = src.unused;
    radius_sq = src.radius_sq;
    __memcpy(&center_x, &src.center_x, 8);
    return *this;
}

G_RemoveStatusEffect_6x0D &G_RemoveStatusEffect_6x0D::operator=(G_RemoveStatusEffect_6x0D &src) {
    copy_subcommand_header(this, &src);
    __memcpy(&effect, &src.effect, sizeof(effect));
    return *this;
}

void StatusEffectChange::bswap() {
    bswap_32(&effect_type);
    bswap_32(&unknown_a1);
}

void TObjPlayer::sub_801BEE2C(s16 v) { this->hp_bonus = v; }

void TObjPlayer::sub_801BEE24(s16 v) { this->tp_bonus = v; }

void TObjPlayer::set_meseta(s32 meseta) {
    this->stat_block->meseta = meseta;
}

void TObjPlayer::set_position(f32 a, f32 b, f32 c) { this->position.x = a; this->position.y = b; this->position.z = c; }

MaterialUsage::~MaterialUsage() {}

void MaterialUsage::set_power_used(u8 v) { counts[0] = v; }

void MaterialUsage::set_mind_used(u8 v) { counts[1] = v; }

void MaterialUsage::set_evade_used(u8 v) { counts[2] = v; }

void MaterialUsage::set_def_used(u8 v) { counts[3] = v; }

void MaterialUsage::set_luck_used(u8 v) { counts[4] = v; }

u8 MaterialUsage::get_power_used() { return counts[0]; }

u8 MaterialUsage::get_mind_used() { return counts[1]; }

u8 MaterialUsage::get_evade_used() { return counts[2]; }

u8 MaterialUsage::get_def_used() { return counts[3]; }

u8 MaterialUsage::get_luck_used() { return counts[4]; }

void MaterialUsage::try_add_item(s32 class_index, u8 amount) {
    try_add_item_count(class_index, 0, amount);
}

void MaterialUsage::add_item_count(s32 class_index, u8 amount) {
    try_add_item_count(class_index, 1, amount);
}

void MaterialUsage::try_add_item_count_type2(s32 class_index, u8 amount) {
    try_add_item_count(class_index, 2, amount);
}

void MaterialUsage::try_add_item_count_kind3(s32 class_index, u8 amount) {
    try_add_item_count(class_index, 3, amount);
}

void MaterialUsage::add_item_count_kind4(s32 class_index, u8 amount) {
    try_add_item_count(class_index, 4, amount);
}

void TObjPlayer::set_shared_count(int count) { shared_count = count; }

void TObjPlayer::set_shared_flag(int flag) { shared_flag = flag; }

#pragma defer_codegen off
#pragma push
#pragma dont_inline on

ProtectionTimer::~ProtectionTimer() {}
#pragma pop


s32 TObjPlayer::reset_and_return(saddr p) {
    clear_equip_slots((s32 *)p);
    return p;
}

void clear_marker_position(Vec *position) {
    position->z = player_zero;
    position->y = player_zero;
    position->x = player_zero;
}

void TObjPlayer::clear_base() { *(s32*)((char*)this + 0x0) = 0; }
MovementHistory::MovementHistory() { clear_movement_history(this); }
UnitScale::UnitScale() { reset(); }



extern const f32 player_scale_initial;


PlayerIntraMapWarp::PlayerIntraMapWarp() {
    destination.z = player_zero;
    destination.y = player_zero;
    destination.x = player_zero;
    yaw = 0;
    timer = 0;
}

ProtectionTimer::ProtectionTimer() { reset_type(); }

BattleMusicState::BattleMusicState() { reset_counter_field4(); }
PlayerAppearFade::PlayerAppearFade() { reset(); }

void PlayerAppearFade::reset() {
    state = WAITING;
    client_id = 0xFFFF;
    delay = 0;
}

RenderMaterialState::RenderMaterialState() { reset_fade_color(); }
PlayerDeathSink::PlayerDeathSink() { reset(); }
PlayerAnimationState::PlayerAnimationState() { reset(); }
void PlayerAnimationState::reset() {
    state = 0;
    action_id = 0;
    angle = 0;
    animation = 0;
}
PlayerMoveSpeed::PlayerMoveSpeed() { reset(); }
PlayerScaleState::PlayerScaleState() { init(); }
void PlayerScaleState::init() {
    actor_id = 0xFFFF;
    flags.reset();
    set_scalar(player_scale_initial);
}


void PlayerScaleState::set_scalar(f32 scalar) {
    this->scalar = scalar;
    set_scale(scalar);
}


void PlayerScaleState::set_scale(f32 scale) {
    this->scale.z = scale;
    this->scale.y = scale;
    this->scale.x = scale;
}

PlayerCameraOffsets::PlayerCameraOffsets() {}

PlayerCameraOffset::PlayerCameraOffset() {
    z = player_zero;
    y = player_zero;
    x = player_zero;
}

ContactSurfaceState::ContactSurfaceState() {
    init_timer();
}


void ContactSurfaceState::init_timer() { timer = -1; }
ContactSurfaceFlags::ContactSurfaceFlags() {
    reset();
}
void ContactSurfaceFlags::reset() { word.reset(); }


PlayerActionPaletteState::PlayerActionPaletteState() {
    disabled_slots = 0;
}

void init_arrival_override(ArrivalOverride *entry) {
    entry->active = 0;
    entry->heading = 0;
    entry->pos.z = player_zero;
    entry->pos.y = player_zero;
    entry->pos.x = player_zero;
}

s32 FlagWord::get_bits() { return bits; }

u8 *TObjPlayer::copy_hold_params(u8 *src) {
    copy_subcommand_header(this, src);
    this->m_flags = (s16) *(s16 *)((s8 *)src + 4);
    this->m_id = (s16) *(s16 *)((s8 *)src + 6);
    *(ByteBlock_8 *)((saddr) ((u8 *)this) + 8) = *(const ByteBlock_8 *)((saddr) src + 8);
    *(f32 *)((s8 *)((u8 *)this) + 0x10) = (f32) *(f32 *)((s8 *)src + 0x10);
    return ((u8 *)this);
}

s16 TBoss7Crawfish::get_floor() { return this->requested_action; }
BmlMotionEntry *PlayerActionProvider::get_motion_list(s32) { return 0; }
int PlayerActionProvider::is_male() { return 0; }
int PlayerActionProvider::load_motions(s32) { return 0; }
int TObjPlayer::sub_802a7290_fwd() { return ((PlayerMotionKey *)this)->get_motion_type(); }
int TObjPlayer::is_handle_valid() { return ((PlayerMotionKey *)this)->get_body_type(); }

// Data-only unit split off the shared player model buffers at 0x805D5D78.
// Plain uninitialized globals (-sdata 8) land in .sbss; the referencing unit
// keeps these extern.

u32 town_npc_shared_resource;
s32 lbl_805D5D7C;
u8 *TObjPlayer::shared_model_buffer;
PlayerJointMatrixSet *player_shared_buffer_base;
u32 shared_state_flags[2];

int PlayerActionProvider::load_motion_set(s32, s32, s32) { return 0; }
int PlayerActionProvider::get_death_action() { return -1; }
int PlayerActionProvider::get_knockdown_action() { return -1; }
int PlayerActionProvider::get_hurt_action() { return -1; }
int PlayerActionProvider::get_interact_action() { return -1; }
int PlayerActionProvider::get_use_item_action() { return -1; }
int PlayerActionProvider::get_photon_blast_action() { return -1; }
int PlayerActionProvider::get_technique_action() { return -1; }
int PlayerActionProvider::get_attack3_action() { return -1; }
int PlayerActionProvider::get_attack2_action() { return -1; }
int PlayerActionProvider::get_attack1_action() { return -1; }
int PlayerActionProvider::get_run_action() { return -1; }


void PlayerActionProvider::set_body_type(s32 body_type) { key.set_body_type(body_type); }

s32 is_action_id_none(s32 animation_number) {
    return (u8) (animation_number == -1);
}


int get_player_action_provider_selector() { return player_action_provider_selector; }


const TObjMotionAction *PlayerActionProvider::get_motion_actions(s32, s32) { return 0; }
BmlMotionEntry *PlayerActionProvider::get_current_motion_list() { return NULL; }

u8 PlayerTechniqueState::get_technique_level(s16 technique) const {
    return levels[technique];
}

void PlayerTechniqueState::set_technique_id(s16 v) { technique = v; }

u8 PlayerTechniqueState::get_learned_level(s16 technique) const {
    return learned_levels[technique];
}

u8 TObjPlayer::get_item_count_max() { return 255; }


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" void __copy(void *, void *, int);

void PlayerTechniqueState::enable_techniques() { flags.clear(2); }

PlayerTechniqueState::PlayerTechniqueState() {
    reset_tech_state();
}

extern "C" {

void bswap_g_client_id_header(void *header) { ((G_ClientIDHeader *)header)->bswap(); }

G_LevelUpAllTechniques_6x9B &G_LevelUpAllTechniques_6x9B::operator=(G_LevelUpAllTechniques_6x9B &src) {
    copy_subcommand_header(this, &src);
    num_levels = src.num_levels;
    __copy(unused, src.unused, 3);
    return *this;
}

}

void *copy_subcommand_header(void *dst, const void *src) { assign_subcommand_header(dst, const_cast<void *>(src)); return dst; }

extern "C" {

void assign_subcommand_header(void *destination, void *source) {
    u8 *out = static_cast<u8 *>(destination);
    const u8 *in = static_cast<const u8 *>(source);
    out[0] = in[0];
    out[1] = in[1];
#ifdef __MWERKS__
    __memcpy(out + 2, in + 2, 2);
#else
    memcpy(out + 2, in + 2, 2);
#endif
}

void G_LevelUpAllTechniques_6x9B::init() {
    num_levels = 0;
    unused[0] = 0;
    unused[1] = 0;
    unused[2] = 0;
    header.subcommand = 0x9B;
    header.size = 2;
}

void G_LevelUpAllTechniques_6x9B::send() { bswap_g_client_id_header(&header); send_subcommand(this); }

void G_AddBattleDamageScores_6x8F::bswap() { header.bswap(); bswap_16(&target_entity_id); bswap_16((u16 *)&amount); }

G_AddBattleDamageScores_6x8F &G_AddBattleDamageScores_6x8F::operator=(G_AddBattleDamageScores_6x8F &src) {
    copy_subcommand_header(this, &src);
    target_entity_id = src.target_entity_id;
    amount = src.amount;
    return *this;
}

void G_AddBattleDamageScores_6x8F::init() {
    target_entity_id = 0xFFFF;
    amount = 0;
    header.subcommand = 0x8F;
    header.size = 2;
}

void G_AddBattleDamageScores_6x8F::send() { bswap(); ((game_command *)this)->send(); }

void G_SetPlayerBattleTeam_6x90::bswap() { header.bswap(); bswap_32(&team_number); }

G_SetPlayerBattleTeam_6x90 &G_SetPlayerBattleTeam_6x90::operator=(G_SetPlayerBattleTeam_6x90 &src) {
    copy_subcommand_header(this, &src);
    team_number = src.team_number;
    return *this;
}

void G_SetPlayerBattleTeam_6x90::init() {
    team_number = 0;
    header.subcommand = 0x90;
    header.size = 2;
}

void G_EnableDropWeaponOnDeath_6x82::init() { header.subcommand = 0x82; header.size = 1; }

void G_EnableDropWeaponOnDeath_6x82::send() { bswap_g_client_id_header(&header); send_subcommand(this); }

void G_DisableDropWeaponOnDeath_6x81::init() { header.subcommand = 0x81; header.size = 1; }

void G_DisableDropWeaponOnDeath_6x81::send() { bswap_g_client_id_header(&header); send_subcommand(this); }

void G_DisableStealthSuitEffect_6x7B::init() { header.subcommand = 0x7B; header.size = 1; }

void G_DisableStealthSuitEffect_6x7B::send() { bswap_g_client_id_header(&header); send_subcommand(this); }

void G_EnableStealthSuitEffect_6x7A::init() { header.subcommand = 0x7A; header.size = 1; }

void G_EnableStealthSuitEffect_6x7A::send() { bswap_g_client_id_header(&header); send_subcommand(this); }

void G_DisablePKModeForPlayer_6x1C::init() { header.subcommand = 0x1C; header.size = 1; }

void G_DisablePKModeForPlayer_6x1C::send() { bswap_g_client_id_header(&header); send_subcommand(this); }

void G_EnablePKModeForPlayer_6x1B::init() { header.subcommand = 0x1B; header.size = 1; }

void G_EnablePKModeForPlayer_6x1B::send() { bswap_g_client_id_header(&header); send_subcommand(this); }

void G_SetPlayerVisible_6x23::init() { header.subcommand = 0x23; header.size = 1; }

void G_SetPlayerVisible_6x23::send() { bswap_g_client_id_header(&header); send_subcommand(this); }

void G_SetPlayerInvisible_6x22::init() { header.subcommand = 0x22; header.size = 1; }

void G_SetPlayerInvisible_6x22::send() { bswap_g_client_id_header(&header); send_subcommand(this); }

void G_ChangePlayerHP_6x2F::bswap() {
    header.bswap();
    bswap_32((u32 *)&type);
    bswap_16((u16 *)&amount);
    bswap_16(&client_id);
}

G_ChangePlayerHP_6x2F &G_ChangePlayerHP_6x2F::operator=(G_ChangePlayerHP_6x2F &src) {
    copy_subcommand_header(this, &src);
    type = src.type;
    amount = src.amount;
    client_id = src.client_id;
    return *this;
}

void G_ChangePlayerHP_6x2F::init() {
    type = 0;
    amount = 0;
    client_id = 0xFFFF;
    header.subcommand = 0x2F;
    header.size = 3;
}

void G_ChangePlayerHP_6x2F::send() { bswap(); send_subcommand(this); }

void G_TeleportPlayer_6x24::bswap() {
    header.bswap();
    bswap_32(&angle_y);
    bswap_32((u32 *)&pos.x);
    bswap_32((u32 *)&pos.y);
    bswap_32((u32 *)&pos.z);
}
G_TeleportPlayer_6x24 &G_TeleportPlayer_6x24::operator=(G_TeleportPlayer_6x24 &src) {
    copy_subcommand_header(this, &src);
    angle_y = src.angle_y;
    __memcpy(&pos, &src.pos, sizeof(pos));
    return *this;
}

}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off





void G_TeleportPlayer_6x24::init() {
    angle_y = 0;
    pos.z = player_zero;
    pos.y = player_zero;
    pos.x = player_zero;
    header.subcommand = 0x24;
    header.size = 5;
}

void G_TeleportPlayer_6x24::send() { bswap(); send_subcommand(this); }
void G_RemoveStatusEffect_6x0D::bswap() { header.bswap(); effect.bswap(); }
void G_RemoveStatusEffect_6x0D::init() { header.subcommand = 0x0D; header.size = 3; }
void G_RemoveStatusEffect_6x0D::send() { bswap(); send_subcommand(this); }
void G_ClearNegativeStatusEffects_6x0E::init() { header.subcommand = 0x0E; header.size = 1; }
void G_AddStatusEffect_6x0C::bswap() { header.bswap(); effect.bswap(); }
G_AddStatusEffect_6x0C &G_AddStatusEffect_6x0C::operator=(G_AddStatusEffect_6x0C &src) {
    copy_subcommand_header(this, &src);
    __memcpy(&effect, &src.effect, sizeof(effect));
    return *this;
}
void G_AddStatusEffect_6x0C::init() { header.subcommand = 0x0C; header.size = 3; }
void G_AddStatusEffect_6x0C::send() { bswap(); send_subcommand(this); }
void G_RevivePlayer_V3_BB_6xA1::init() { header.subcommand = 0xA1; header.size = 1; }
void G_RevivePlayer_V3_BB_6xA1::send() { bswap_g_client_id_header(&header); send_subcommand(this); }
void G_MedicalCenterReviveAllPlayers_6x32::send() { bswap_g_client_id_header(&header); send_subcommand(this); }
void G_MedicalCenterReviveAllPlayers_6x32::init() { header.subcommand = 0x32; header.size = 1; }
void G_UseMedicalCenter_6x31::init() { header.subcommand = 0x31; header.size = 1; }
void G_UseMedicalCenter_6x31::send() { bswap_g_client_id_header(&header); send_subcommand(this); }
void G_ReleaseHold_6x2D::init() { header.subcommand = 0x2D; header.size = 1; }
void G_ReleaseHold_6x2D::send() { bswap_g_client_id_header(&header); send_subcommand(this); }
void G_ImposeHold_6x2C::bswap() { header.bswap(); bswap_16(&unknown_a1); bswap_16(&unknown_a2); bswap_32((u32 *)&trigger_radius2); pos.bswap(); }
void G_ImposeHold_6x2C::init() {
    unknown_a1 = 0;
    unknown_a2 = 0;
    pos.z = player_zero;
    pos.x = player_zero;
    header.subcommand = 0x2C;
    header.size = 5;
}

void G_ImposeHold_6x2C::send() {
    bswap();
    send_subcommand(this);
}
void G_SetOrClearPlayerFlags_6x2E::bswap() {
    header.bswap();
    bswap_32(&and_mask);
    bswap_32(&or_mask);
}
G_SetOrClearPlayerFlags_6x2E &G_SetOrClearPlayerFlags_6x2E::operator=(G_SetOrClearPlayerFlags_6x2E &src) {
    copy_subcommand_header(this, &src);
    and_mask = src.and_mask;
    or_mask = src.or_mask;
    return *this;
}

void G_SetOrClearPlayerFlags_6x2E::init() {
    and_mask = 0;
    or_mask = 0;
    header.subcommand = 0x2E;
    header.size = 3;
}

void G_ChangePlayerLevel_6x30::send() { bswap(); send_subcommand(this); }

void G_ChangePlayerLevel_6x30::bswap() {
    header.bswap();
    bswap_16((u16 *)&atp);
    bswap_16((u16 *)&mst);
    bswap_16((u16 *)&evp);
    bswap_16((u16 *)&hp);
    bswap_16((u16 *)&dfp);
    bswap_16((u16 *)&ata);
    bswap_16((u16 *)&level);
    bswap_16((u16 *)&is_level_down);
}

void G_ChangePlayerLevel_6x30::init() {
    atp = 0;
    mst = 0;
    evp = 0;
    hp = 0;
    dfp = 0;
    ata = 0;
    level = 0;
    is_level_down = 0;
    header.subcommand = 0x30;
    header.size = 5;
}

void G_FeedMag_6x28::bswap() {
    header.bswap();
    bswap_32(&mag_item_id);
    bswap_32(&fed_item_id);
}
G_FeedMag_6x28 &G_FeedMag_6x28::operator=(G_FeedMag_6x28 &src) {
    copy_subcommand_header(this, &src);
    mag_item_id = src.mag_item_id;
    fed_item_id = src.fed_item_id;
    return *this;
}

void G_FeedMag_6x28::init() {
    mag_item_id = -1;
    fed_item_id = -1;
    header.subcommand = 0x28;
    header.size = 3;
}

void G_FeedMag_6x28::send() { bswap(); send_subcommand(this); }

void G_UseItem_6x27::bswap() {
    header.bswap();
    bswap_32(&item_id);
}
G_UseItem_6x27 &G_UseItem_6x27::operator=(G_UseItem_6x27 &src) {
    copy_subcommand_header(this, &src);
    item_id = src.item_id;
    return *this;
}

void G_UseItem_6x27::init() {
    item_id = -1;
    header.subcommand = 0x27;
    header.size = 2;
}

void G_UseItem_6x27::send() { bswap(); send_subcommand(this); }


void G_CreateInventoryItem_PC_V3_BB_6x2B::bswap() {
    header.bswap();
    item_data.bswap();
}

G_CreateInventoryItem_PC_V3_BB_6x2B &G_CreateInventoryItem_PC_V3_BB_6x2B::operator=(G_CreateInventoryItem_PC_V3_BB_6x2B &src) {
    G_CreateInventoryItem_DC_6x2B::operator=(src);
    unused1 = src.unused1;
    equip_item = src.equip_item;
    *(u16 *)unused2 = *(const u16 *)src.unused2;
    return *this;
}

G_CreateInventoryItem_DC_6x2B &G_CreateInventoryItem_DC_6x2B::operator=(G_CreateInventoryItem_DC_6x2B &src) {
    copy_subcommand_header(this, &src);
    __memcpy(&item_data, &src.item_data, sizeof(item_data));
    return *this;
}

G_CreateInventoryItem_PC_V3_BB_6x2B *G_CreateInventoryItem_PC_V3_BB_6x2B::init() {
    G_CreateInventoryItem_DC_6x2B::init();
    header.subcommand = 0x2B;
    unused1 = 2;
    equip_item = 0;
    unused2[0] = 0;
    unused2[1] = 0;
    header.size = 7;
    return this;
}

void G_CreateInventoryItem_DC_6x2B::init() { header.subcommand = 0x2B; header.size = 6; }

void G_CreateInventoryItem_PC_V3_BB_6x2B::send() { bswap(); send_subcommand(this); }

void G_DropItem_6x2A::bswap() {
    header.bswap();
    bswap_16((u16 *)&floor);
    bswap_16((u16 *)&amount);
    bswap_32(&item_id);
    bswap_32((u32 *)&pos.x);
    bswap_32((u32 *)&pos.y);
    bswap_32((u32 *)&pos.z);
}

G_DropItem_6x2A &G_DropItem_6x2A::operator=(G_DropItem_6x2A &src) {
    copy_subcommand_header(this, &src);
    amount = src.amount;
    floor = src.floor;
    item_id = src.item_id;
    __memcpy(&pos, &src.pos, sizeof(pos));
    return *this;
}

void G_DropItem_6x2A::init() {
    amount = 0;
    floor = 0;
    item_id = -1;
    pos.z = player_zero;
    pos.y = player_zero;
    pos.x = player_zero;
    header.subcommand = 0x2A;
    header.size = 6;
}

void G_DropItem_6x2A::send() { bswap(); send_subcommand(this); }

void G_PlaceTrap_6x83::bswap() { header.bswap(); bswap_16((u16 *)&trap_type); bswap_16((u16 *)&trap_index); }

G_PlaceTrap_6x83 &G_PlaceTrap_6x83::operator=(G_PlaceTrap_6x83 &src) {
    copy_subcommand_header(this, &src);
    trap_type = src.trap_type;
    trap_index = src.trap_index;
    return *this;
}

void G_PlaceTrap_6x83::init() {
  trap_type = 0;
  trap_index = 0;
  header.subcommand = 0x83;
  header.size = 2;
}

void G_PlaceTrap_6x83::send() { bswap(); send_subcommand(this); }

void G_DeleteMultipleInventoryItems_6xAC::bswap() { header.bswap(); bswap_32((u32 *)&num_items); { int i; for (i = 0; i < 30; i++) { bswap_32(&item_ids.id[i]); } } }

G_DeleteMultipleInventoryItems_6xAC &G_DeleteMultipleInventoryItems_6xAC::operator=(G_DeleteMultipleInventoryItems_6xAC &src) {
    copy_subcommand_header(this, &src);
    num_items = src.num_items;
    item_ids = src.item_ids;
    return *this;
}

void G_DeleteMultipleInventoryItems_6xAC::init() {
    s32 i;
    num_items = 0;
    for (i = 0; i < 30; i++) {
        item_ids.id[i] = -1;
    }
    header.subcommand = 0xAC;
    header.size = 0x20;
}

void G_DeleteInventoryItem_6x29::bswap() { header.bswap(); bswap_32(&item_id); bswap_32(&amount); }

G_DeleteInventoryItem_6x29 &G_DeleteInventoryItem_6x29::operator=(G_DeleteInventoryItem_6x29 &src) {
    copy_subcommand_header(this, &src);
    item_id = src.item_id;
    amount = src.amount;
    return *this;
}

void G_DeleteInventoryItem_6x29::init() {
    item_id = -1;
    amount = 0;
    header.subcommand = 0x29;
    header.size = 3;
}

void G_DeleteInventoryItem_6x29::send() { bswap(); send_subcommand(this); }

void G_UnequipItem_6x26::send() { bswap(); send_subcommand(this); }

void G_UnequipItem_6x26::bswap() { header.bswap(); bswap_32(&item_id); bswap_32((u32 *)&equip_slot); }

void G_UnequipItem_6x26::init() {
    item_id = -1;
    equip_slot = 0;
    header.subcommand = 0x26;
    header.size = 3;
}

void G_EquipItem_6x25::bswap() { header.bswap(); bswap_32(&item_id); bswap_32((u32 *)&equip_slot); }

G_EquipItem_6x25 &G_EquipItem_6x25::operator=(G_EquipItem_6x25 &src) {
    copy_subcommand_header(this, &src);
    item_id = src.item_id;
    equip_slot = src.equip_slot;
    return *this;
}

void G_EquipItem_6x25::init() {
    item_id = -1;
    equip_slot = 0;
    header.subcommand = 0x25;
    header.size = 3;
}

void G_EquipItem_6x25::send() { bswap(); send_subcommand(this); }

void G_SetAnimationState_6xAE::bswap() { header.bswap(); bswap_16((u16 *)&animation_number); bswap_16(&unused); bswap_32(&player_flags); bswap_32((u32 *)&animation_timer); }

G_SetAnimationState_6xAE &G_SetAnimationState_6xAE::operator=(G_SetAnimationState_6xAE &src) {
    copy_subcommand_header(this, &src);
    animation_number = src.animation_number;
    unused = src.unused;
    player_flags = src.player_flags;
    animation_timer = src.animation_timer;
    return *this;
}

void G_SetAnimationState_6xAE::init() {
    animation_number = 0;
    unused = 0;
    player_flags = 0;
    animation_timer = player_zero;
    header.subcommand = 0xAE;
    header.size = 4;
}

void G_SetPosition_6x20::bswap() { header.bswap(); bswap_32((u32 *)&floor); bswap_32((u32 *)&pos.x); bswap_32((u32 *)&pos.y); bswap_32((u32 *)&pos.z); bswap_32(&angle_y); }

G_SetPosition_6x20 &G_SetPosition_6x20::operator=(G_SetPosition_6x20 &src) {
    copy_subcommand_header(this, &src);
    floor = src.floor;
    __memcpy(&pos, &src.pos, sizeof(pos));
    angle_y = src.angle_y;
    return *this;
}

void G_SetPosition_6x20::init() {
    floor = 0;
    pos.z = player_zero;
    pos.y = player_zero;
    pos.x = player_zero;
    angle_y = 0;
    header.subcommand = 0x20;
    header.size = 6;
}

void G_SetAnimationState_6xAE::send_to(u32 client) { bswap(); ((game_command *)this)->send_to_client(client); }

void G_SetPosition_6x20::send() { bswap(); ((game_command *)this)->send(); }

void G_SetPlayerFloor_6x1F::bswap() { header.bswap(); bswap_32((u32 *)&floor); }

G_SetPlayerFloor_6x1F &G_SetPlayerFloor_6x1F::operator=(const G_SetPlayerFloor_6x1F &src) {
    copy_subcommand_header(this, &src);
    floor = src.floor;
    return *this;
}

void G_SetPlayerFloor_6x1F::init() {
    floor = 0;
    header.subcommand = 0x1F;
    header.size = 2;
}

void G_SetPlayerFloor_6x1F::send() { bswap(); ((game_command *)this)->send(); }

void G_InterLevelWarp_6x21::bswap() { header.bswap(); bswap_32((u32 *)&floor); }

G_InterLevelWarp_6x21 &G_InterLevelWarp_6x21::operator=(const G_InterLevelWarp_6x21 &src) {
    copy_subcommand_header(this, &src);
    floor = src.floor;
    return *this;
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct C_801C1BA8 { u32 w[5]; };

struct S_801C1BA8 { u8 a; u8 b; u8 c; u8 d; s32 e; C_801C1BA8 f; };


void G_InterLevelWarp_6x21::init() {
    floor = 0;
    header.subcommand = 0x21;
    header.size = 2;
}

void G_InterLevelWarp_6x21::send() { bswap(); send_subcommand(this); }

void G_SetPosition_6x3F::send() { bswap(); send_subcommand(this); }

void G_SetPosition_6x3F::bswap() {
    header.bswap();
    bswap_16((u16 *)&is_near_enemy);
    bswap_16((u16 *)&angle);
    bswap_16((u16 *)&floor);
    bswap_16((u16 *)&room);
    bswap_32((u32 *)&pos.x);
    bswap_32((u32 *)&pos.y);
    bswap_32((u32 *)&pos.z);
}

void G_SetPosition_6x3F::init() {
    is_near_enemy = 0;
    angle = 0;
    floor = -1;
    room = -1;
    header.subcommand = 0x3F;
    header.size = 6;
}

f32 DamageStatSlot::get_bonus_weight() { return bonus_weight; }

s32 DamageStatSlot::get_total() {
    return (s32)total;
}

void DamageStatSlot::set_total(f32 v) { total = v; }

s32 PlayerPkState::get_team() { return team; }

void PlayerPkState::set_team(s32 id) { team = id; }

void PlayerBattleScore::set_timer(s32 v) { timer = v; }

void PlayerPkState::disable() { enabled = 0; }

void PlayerPkState::enable() { enabled = 1; }

PlayerPkState *PlayerPkState::init() { reset(); return this; }

void PlayerPkState::reset() { enabled = 0; team = 0; }

void *TObjPlayer::reset_lobby_settings() {
    ((TLobby *)this)->reset_settings_to_default();
    return this;
}

s32 TItem::is_equipped() {
    u8 equipped = 0;
    if (test_item_flags(4) != 0U && test_item_flags(8) != 0U) {
        equipped = 1;
    }
    return equipped;
}

s32 TItem::is_stackable() {
    return is_item_stackable(get_item_type(), get_item_group());
}

void on_inventory_item_added(TItem *item, s32 slot) {}

void TObjPlayer::set_flags_bit2() { ((FlagWord *)((char*)this + 0x1c))->set(2); }

void TObjPlayer::set_flags_bit1() { ((FlagWord *)((char*)this + 0x1c))->set(1); }

void TObjPlayer::clear_flag_1_at_1c() { ((FlagWord *)((char*)this + 0x1c))->clear(1); }

s32 LockOnNearestTarget::get_candidate_part_index() { return candidate_part_index; }

f32 LockOnNearestTarget::get_published_target_dist() { return published_target_dist; }

u16 LockOnNearestTarget::get_published_target_id() { return published_target_id; }

s32 TDeathTintFade::get_viewport_index() { return viewport_index; }

TPlyInventoryItem *fn_801C1BA8(TPlyInventoryItem *destination, const TPlyInventoryItem *source) {
    S_801C1BA8 *dst = (S_801C1BA8 *)destination;
    const S_801C1BA8 *src = (const S_801C1BA8 *)source;
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    return destination;
}

int TPlyDispConfig::is_primary_first_bank() { return m_smth.is_first_bank(); }

int TPlyDispConfigSmth::is_first_bank() { return bank == 0; }

s32 TPlyDispConfigSmth::is_channel_active_at(s32 row, s32 index) {
    return ((TMainCursor *)(get_row(row) + index))->is_channel_active();
}

gc_tag *TPlyDispConfigSmth::get_row(s32 row) {
    if (row == 0) {
        return m_tags;
    }
    return m_tags1;
}

s32 TPlyDispConfigSmth::is_channel_active(s32 index) {
    return is_channel_active_at(bank, index);
}

void TPlyDispConfigSmth::set_tag(s32 row, s32 index, s32 mode, u16 slot) {
    ActionPaletteTag *tag = get_row(row) + index;
    set_action_palette_tag_mode(tag, static_cast<u8>(mode));
    set_action_palette_tag_slot(tag, static_cast<u8>(slot));
}

void TPlyDispConfigSmth::set_tag_slot(s32 row, s32 index, s32 slot) {
    set_action_palette_tag_slot(get_row(row) + index, static_cast<u8>(slot));
}

void TPlyDispConfigSmth::set_tag_mode(s32 row, s32 index, s32 mode) {
    set_action_palette_tag_mode(get_row(row) + index, static_cast<u8>(mode));
}

u16 TPlyDispConfigSmth::get_tag_slot(s32 row, s32 index) {
    return get_action_palette_tag_slot(get_row(row) + index);
}

u16 TPlyDispConfigSmth::get_current_tag_slot(s32 index) {
    return get_tag_slot(bank, index);
}

u16 TPlyDispConfigSmth::get_tag_mode(s32 row, s32 index) {
    return get_action_palette_tag_mode(get_row(row) + index);
}

u16 TPlyDispConfigSmth::get_current_tag_mode(s32 index) {
    return get_tag_mode(bank, index);
}

TPlyDispConfigSmth *TPlyDispConfig::ref_primary_palette() { return &m_smth; }

TPlyDispConfigSmth *TPlyDispConfig::ref_secondary_palette() { return &m_smth1; }

int TPlyDispConfig::test_photon_blast_modifier() { return m_smth1.is_first_bank(); }

void TPlyDispConfig::clear_secondary_bank() { m_smth1.clear_bank(); }

void TPlyDispConfigSmth::clear_bank() { bank = 0; }

void TPlyDispConfig::clear_primary_bank() { m_smth.clear_bank(); }

void TPlyDispConfig::set_secondary_bank() { m_smth1.set_bank(); }

void TPlyDispConfigSmth::set_bank() { bank = 1; }

void TPlyDispConfig::set_primary_bank() { m_smth.set_bank(); }

void PhotonBlastGauge::set_blast(s16 v) { blast = v; }

void PhotonBlastGauge::decrement_donation_state() { donation.decrement_state(); }

void PhotonBlastDonation::decrement_state() {
    state -= 1;
}

int PhotonBlastGauge::has_ready_flag() { return test_flags_any(&flags.bits, 2); }

void PhotonBlastGauge::set_client_id(u16 id) { client_id = id; }

PhotonBlastGauge::~PhotonBlastGauge() {}

s32 TObjPlayer::free_owned_buffer_b(saddr buffer, s16 flags) {
    if ((buffer != 0) && (flags > 0)) {
        __dl__FPv();
    }
    return buffer;
}


extern "C" {
s32 __ct__12TPlyCharDataFv(s32 arg0);
void is_slot_within_limit__10TObjPlayerFllUc(u8 cls, s16 tech, u8 level);


PlayerAttackController *PlayerAttackController::init() {
    __ct__8FlagWordFv(&flags);
    TObjPlayer__sub_8012AF00(&lockon_targets);
    evp_scale = player_one;
    reset();
    return this;
}

}

s32 is_count_positive(s32 *count) {
    return *count > 0;
}


TItemData *TPlyInventoryItem::get_data() { return &m_data; }
void PendingItemDrop::set_source_id(s32 id) { source_id = id; }
PendingItemDrop::PendingItemDrop() {}
PlacementSlot::PlacementSlot() { state = 0; }

PlayerTelepipe *PlayerTelepipe::init() {
    __ct__8FlagWordFv(&flags);
    state.owner_client_id = 0xFFFF;
    state.room_id = 0;
    state.pos.x = player_zero;
    state.pos.y = player_zero;
    state.pos.z = player_zero;
    state.angle_y = 0;
    state.floor = 0;
    ((TTecLuker *)&flags)->set_state(0xFFFF);
    return this;
}

void PlayerMotionKey::set_body_type(s32 body_type) { this->body_type = body_type; }
int TObjPlayer::default_action_provider_variant() { return 0; }
u8 PlayerLevelTableRow::get_ata_growth() const { return growth[5]; }
u8 PlayerLevelTableRow::get_dfp_growth() const { return growth[4]; }
u8 PlayerLevelTableRow::get_hp_growth() const { return growth[3]; }
u8 PlayerLevelTableRow::get_evp_growth() const { return growth[2]; }
u8 PlayerLevelTableRow::get_mst_growth() const { return growth[1]; }
u8 PlayerLevelTableRow::get_atp_growth() const { return growth[0]; }
s32 PlayerLevelTableRow::get_exp_threshold() const { return experience; }

u32 TObjPlayer::unpack_u32_hi() {
    TPlyInventoryItem *items = reinterpret_cast<TPlyCharData *>(this)->m_inventory.m_items;
    u32 r = (u8)items[4].m_present[3];
    r |= (u8)items[5].m_present[3] << 8;
    r |= (u8)items[6].m_present[3] << 16;
    r |= (u8)items[7].m_present[3] << 24;
    return r;
}

u32 TObjPlayer::unpack_u32_lo() {
    TPlyInventoryItem *items = reinterpret_cast<TPlyCharData *>(this)->m_inventory.m_items;
    u32 r = (u8)items[0].m_present[3];
    r |= (u8)items[1].m_present[3] << 8;
    r |= (u8)items[2].m_present[3] << 16;
    r |= (u8)items[3].m_present[3] << 24;
    return r;
}

u8 TPlyCharData::get_class_flag_2() { return m_inventory.m_items[15].m_present[3]; }
u8 TPlyCharData::get_class_flag_1() { return m_inventory.m_items[14].m_present[3]; }
u8 TPlyCharData::get_class_flag_0() { return m_inventory.m_items[13].m_present[3]; }

s32 TPlyCharData::get_record_byte_at(s32 tech) {
    return (u8)m_inventory.m_items[tech].m_present[2];
}

s32 TPlyCharData::get_technique_level(s32 tech) {
    u8 level = m_tech_levels[tech];
    is_slot_within_limit__10TObjPlayerFllUc(m_disp_part2.char_class, tech, level);
    return level;
}

TPlyInventoryItem *TPlyInventory::get_items() { return m_items; }
u8 TPlyCharData::get_luck_materials_used() { return m_inventory.m_items[12].m_present[3]; }
u8 TPlyCharData::get_def_materials_used() { return m_inventory.m_items[11].m_present[3]; }
u8 TPlyCharData::get_evade_materials_used() { return m_inventory.m_items[10].m_present[3]; }
u8 TPlyCharData::get_mind_materials_used() { return m_inventory.m_items[9].m_present[3]; }
u8 TPlyCharData::get_power_materials_used() { return m_inventory.m_items[8].m_present[3]; }
void PhotonChairSeat::set_owner_id(u16 id) { owner_id = id; }
PhotonChairSeat::PhotonChairSeat() { reset(); }

int PlayerCharDataEntry::has_character() { return test_flags_any((s32 *)&flags, 1); }
u8 *PlayerCharDataEntry::get_lobby_header() { return lobby_header; }
TPlyCharData *PlayerCharDataEntry::get_char_data() { return &char_data; }
s32 PlayerCharDataEntry::get_role() { return role; }
PlayerCharDataEntry *PlayerCharDataEntry::construct() { ((TObjPlayer *)lobby_header)->clear_header_struct(); __ct__12TPlyCharDataFv((saddr)&char_data); __ct__8FlagWordFv(&flags); role = 0; return this; }


PhotonBlastRegistry::~PhotonBlastRegistry() {}

PhotonBlastRegistry::PhotonBlastRegistry() {}
