#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/PhotonBlastRequests.h"
#include "pso/player/PlayerState.h"
#include "types.h"
#include "pso/player/TObjPlayer_801BDF5C.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSnapShot_802A7D68.h"
#include "pso/ui/hud/TLockOnCursor_8013D91C.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/player/Palettex.h"
#include "pso/player/TPlayerFootStamp.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/unk/text_801BE104.h"
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

u8 *TObjPlayer::create_player_instance(s32 arg0, saddr player) {
    u8 *p;
    p = (u8 *)new TObjPlayer(tl_03, arg0 & 0xFFFF, ((PlayerCharDataEntry *)player)->get_role(), ((PlayerCharDataEntry *)player)->get_char_data());
    ((TLobby *)(p + 0xDAC))->copy_header_struct(((PlayerCharDataEntry *)player)->get_lobby_header());
    ((TObjPlayer *)p)->reset_motion_fields();
    return p;
}

TObjPlayer *create_player_object(s32 slot, s32 role, TPlyCharData *record) {
    decode_created_player_inventory(record);
    return new TObjPlayer(tl_03, slot, role, record);
}

extern "C" {


PhotonBlastRegistry *TObjPlayer__shared_photon_blast_state;
s32 lobby_player_count;
extern uaddr TObjPlayer__shared_model_buffer;

void TObjPlayer::free_shared_data() {
    if (TObjPlayer__shared_photon_blast_state != NULL) {
        delete TObjPlayer__shared_photon_blast_state;
        TObjPlayer__shared_photon_blast_state = NULL;
    }
    if (player_shared_buffer_base != NULL) {
        mem_free(player_shared_buffer_base);
        player_shared_buffer_base = NULL;
    }
    if ((u32) TObjPlayer__shared_model_buffer != 0U) {
        mem_free((void*)TObjPlayer__shared_model_buffer);
        TObjPlayer__shared_model_buffer = 0U;
    }
}

void TObjPlayer::alloc_shared_buffers() {
    if ((u32) TObjPlayer__shared_model_buffer == 0U) {
        TObjPlayer__shared_model_buffer = (uaddr)mem_alloc((uaddr)(0x9000));
    }
    if (player_shared_buffer_base == NULL) {
        player_shared_buffer_base = static_cast<PlayerJointMatrixSet *>(mem_alloc(12 * sizeof(PlayerJointMatrixSet)));
    }
    if (TObjPlayer__shared_photon_blast_state == NULL) {
        TObjPlayer__shared_photon_blast_state = new PhotonBlastRegistry();
    }
}

}

    extern unsigned char lobby_rule_settings[];
    extern int lbl_805D5D7C;
    extern int shared_state_flags;
void TObjPlayer::finalize_shared() { TLobby::set_player_count((saddr)(0)); TObjPlayer::set_shared_count((saddr)(0)); TObjPlayer::set_shared_flag((saddr)(0)); lbl_805D5D7C = 0; ((TLobby *)lobby_rule_settings)->reset_settings_to_default(); shared_state_flags = 0; TLockOnCursor::free_cursor_resources(); free_player_motion_directory(); TPlayerFootStamp::free_instance(); TObjPlayer::free_shared_data(); }

void TObjPlayer::init_shared() { TObjPlayer::alloc_shared_buffers(); TLobby::set_player_count((saddr)(0)); TObjPlayer::set_shared_count((saddr)(1)); TObjPlayer::set_shared_flag((saddr)(0)); lbl_805D5D7C = 0; alloc_player_motion_directory(); load_player_motion_data(); copy_player_motion_directory(); upload_player_motion_data(); free_player_motion_archive(); load_target_cursor_models(); load_player_footstamp(); reset_client_quest_slot_table(); shared_state_flags = 0; }

extern "C" {
extern u8 TObjPlayer__char_data_array[];
void __destroy_arr(void *block, void *dtor, u32 size, u32 n);
void __register_global_object(void *obj, void *dtor, void *chain);
void *__construct_array(void *, void *, void *, u32, u32);
void construct__19PlayerCharDataEntryFv(void *);
void *__dt__19PlayerCharDataEntryFv(void *entry, s16 mode);

}

u8 TObjPlayer__arrival_override_table[0xF0];
u8 player_slot_table[0x30];
u8 lobby_rule_settings[0x24];
u8 lbl_8050EA64[0xC];
u8 TObjPlayer__char_data_array[0x42C * 0xC];


void __sinit_TObjPlayer_801BDF5C_cpp(void) {
    __construct_array(TObjPlayer__arrival_override_table, (void *)TObjPlayer__sub_801BFF80, NULL, 0x14, 0xC);
    ((TObjPlayer *)lobby_rule_settings)->reset_lobby_settings();
    __construct_array(TObjPlayer__char_data_array, (void *)construct__19PlayerCharDataEntryFv, (void *)__dt__19PlayerCharDataEntryFv, 0x42C, 0xC);
    __register_global_object(NULL, (void *)TObjPlayer::destroy_char_data_array, lbl_8050EA64);
}

void TObjPlayer::destroy_char_data_array() {
    __destroy_arr(TObjPlayer__char_data_array, (void *)__dt__19PlayerCharDataEntryFv, 0x42c, 0xc);
}


__declspec(section ".ctors") static void *const __sinit_TObjPlayer_801BDF5C_cpp_ref = (void *)__sinit_TObjPlayer_801BDF5C_cpp;

extern "C" {

int subtract_photon_blast_charge(void*, f32);

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
void TObjPlayer::check_stat_flag_41c() { m_41c.set(32); }
void TObjPlayer::check_flag_at_41c() { m_41c.set(4); }
void TObjPlayer::set_flag_41c_bit1() { m_41c.set(2); }
void TObjPlayer::clamp_stat_41c() { m_41c.set(8); }

}

s8 TObjPlayer::get_rule_field_0() {
    return ((TLobby *)lobby_rule_settings)->get_rule_field_0();
}

extern "C" {


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

short TObjPlayer::call_subobject_m15() {
    return action_provider->get_attack1_action();
}

short TObjPlayer::get_vobj_state_28() {
    return action_provider->get_run_action();
}

extern "C" TObjPlayer *get_local_player() {
    return get_player_by_client_id(local_client_id);
}

int copy_subcommand_header(void*);

void TObjPlayer::clear_flag_200000() {
    clear_state_flags(0x200000);
}
int TObjPlayer::check_flag_4() { return check_flag(4); }
void*TObjPlayer::set_invisible() { copy_subcommand_header(this); return this; }
void TObjPlayer::clear_flag_4000_callback() { clear_flag_4000(); }
void TObjPlayer::clear_flag_4000() { clear_state_flags(16384); }
void TObjPlayer::set_flag_4000() { this->set_state_flags(16384); }
void TObjPlayer::set_battle_flag(s32 v) { this->m_3b4 = v; }
s32 TObjPlayer::get_anim_id() { return this->m_3b4; }
int TObjPlayer::check_flag_0x40000000() { return (this->state_flags >> 30) & 0x1; }
void TObjPlayer::clear_flag_0x2() { this->state_flags &= 0xfffffffd; }


int TObjPlayer::is_action_active() { return (this->state_flags >> 1) & 0x1; }
void TObjPlayer__sub_801BE784(void* p, u8 v) { *(u8*)((char*)p + 0x2e7) = v; }
u8 TObjPlayer::get_battle_mode() { return unk_33A[0]; }
void TObjPlayer__sub_801BE794(void* p, u8 v) { *(u8*)((char*)p + 0x2cb) = v; }
u8 TObjPlayer::get_byte_339() { return this->m_339; }
void TObjPlayer__sub_801BE7A4(void* p, u8 v) { *(u8*)((char*)p + 0x2af) = v; }
u8 TObjPlayer::get_mag_level() { return unk_338[0]; }
void TObjPlayer__sub_801BE7B4(void* p, u8 v) { *(u8*)((char*)p + 0x293) = v; }
u8 TObjPlayer::get_luck_materials_used() { return materials.get_luck_used(); }
void TObjPlayer__sub_801BE7E0(void* p, u8 v) { *(u8*)((char*)p + 0x277) = v; }
u8 TObjPlayer::get_def_materials_used() { return materials.get_def_used(); }
void TObjPlayer__sub_801BE80C(void* p, u8 v) { *(u8*)((char*)p + 0x25b) = v; }
u8 TObjPlayer::get_evade_materials_used() { return materials.get_evade_used(); }
void TObjPlayer__sub_801BE838(void* p, u8 v) { *(u8*)((char*)p + 0x23f) = v; }
u8 TObjPlayer::get_mind_materials_used() { return materials.get_mind_used(); }
void TObjPlayer__sub_801BE864(void* p, u8 v) { *(u8*)((char*)p + 0x223) = v; }
u8 TObjPlayer::get_power_materials_used() { return materials.get_power_used(); }

}

struct Inv_801BE890 { s32 f0; TPlyInventoryItem items[0x1E]; };

extern "C" {
Inv_801BE890 *init_inventory_list__10TObjPlayerFPv(Inv_801BE890 *arg0);

Inv_801BE890 *init_inventory_list__10TObjPlayerFPv(Inv_801BE890 *arg0) {
    s32 i;
    arg0->f0 = 0;
    for (i = 0; i < 0x1E; i++) {
        arg0->items[i].init();
    }
    return arg0;
}

void TObjPlayer::set_move_mode(s32 v) { this->m_3dc = v; }
void TObjPlayer::set_input_mode(s32 v) { this->m_3d8 = v; }

}

struct E_801BE8F4 { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };

struct O_801BE8F4 { u8 pad[0xa4]; E_801BE8F4 *entries; };

extern "C" {
u8 TObjPlayer__sub_801BE8F4(O_801BE8F4 *self, s32 i, u32 mask);

u8 TObjPlayer__sub_801BE8F4(O_801BE8F4 *self, s32 i, u32 mask) {
    return (self->entries[i].flags & mask) != 0;
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

}


void TObjPlayer::set_action_flag_2() { this->state_flags |= 0x2; }
void set_flag_400000(TObjPlayer *player) {
    player->set_state_flags(0x400000);
}
int TObjPlayer::check_flag_48() { return check_flag(48); }
int TObjPlayer::is_status_locked() { return this->actorFlags & 0x10000; }
int TObjPlayer::is_status_flag_200() { return this->actorFlags & 0x200; }
int TObjPlayer__sub_801BEABC(void* p) { return ((TObjPlayer *)p)->end_camera_pan(); }
int TObjPlayer::start_freeze_self() { return start_freeze(); }
void TObjPlayer::set_floor(s32 v) { this->current_floor = v; }
void TObjPlayer::set_floor_index(s32 v) { current_area = v; }

extern "C" {


s32 TObjPlayer::get_state_flags() { return this->state_flags; }
int TObjPlayer::unregister_sub() { return unregister_object_by_id(); }
void TObjPlayer::set_control_role(s32 v) { *(s32 *)&this->unk_3E8 = v; }
u8 TObjPlayer__sub_801BEB3C(void* p) { return *(u8*)((char*)p + 0x2e7); }
u8 TObjPlayer__sub_801BEB44(void* p) { return *(u8*)((char*)p + 0x2cb); }
u8 TObjPlayer__sub_801BEB4C(void* p) { return *(u8*)((char*)p + 0x2af); }
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

}


struct O_801BEC50 { u16 a; u16 b; f32 x; f32 y; f32 z; };


extern const f32 TObjPlayer__data_805DC278;
int TPlyPhotonChair::is_mounted() { return (*(u32*)((char*)this + 0x334) >> 26) & 0x1; }

void TObjPlayer::init_vec_record() {
    O_801BEC50 *p = (O_801BEC50 *)this;
    p->a = 0xFFFF;
    p->b = 0;
    p->x = p->y = p->z = TObjPlayer__data_805DC278;
}

void PlayerNpcControl::reset() {
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

struct Pos_801D2964 { u8 bytes[0x8]; };

struct Pkt_801D2964 { u8 hdr[4]; Pos_801D2964 pos; };

extern "C" {
void TObjPlayer__sub_801BEEE0(void* p, void* q);
void TObjPlayer__sub_801BEF30(void* p, void* q);
void TObjPlayer__sub_801BEF44(void* p, void* q);
int create_attached_oneshot_emitter(void*, u16, int);
int emit_player_particle(void*, int, int);
void* TObjPlayer__sub_801BF31C(void* p);
int TObjPlayer__sub_801BF3A0(void* p);
int VecCopy__FP3VecPC3Vec(void*);
int test_flags_any(void*, int);
u8 TObjPlayer__sub_801BF460(s32 *arg0, s32 arg1);
void TObjPlayer__sub_801BF488(s32 *arg0, s32 arg1);
void TObjPlayer__sub_801BF4A0(s32 *arg0, s32 arg1);
void emit_idle_water_effect(saddr particles);
void TObjPlayer__sub_801BEEAC(u8 *arg0, u8 *arg1);
}
void* get_surface_contact_point(void* p);
void emit_grass_footstep_effect(saddr arg0);
void emit_water_step_particles(saddr owner, saddr position);
void emit_water_footstep_effect(saddr arg0);
void emit_sand_step_particles(saddr owner, saddr position);
void emit_sand_footstep_effect(saddr arg0);
void emit_idle_water_splash(s32 owner, saddr position);
void emit_photon_blast_feedback_effects(saddr owner, u16 target_id);
extern "C" {
int copy_subcommand_header(void*);
void TObjPlayer__sub_801BF47C(void* p);
int shared_count;
int shared_flag;
extern const f32 TObjPlayer__data_805DC278;
}
extern const float TObjPlayer__data_805DC294;

#pragma defer_codegen on
ContactSurfaceFlags::~ContactSurfaceFlags() {}

ContactSurfaceState::~ContactSurfaceState() {}

#pragma push
#pragma dont_inline on
PlayerActionPaletteState::~PlayerActionPaletteState() {}

void PlayerDeathSink::set_progress(f32 v) { progress = v; }

void TObjPlayer__sub_801BF9E0(void* p, u16 v) { *(s16*)((char*)p + 0x0) = v; }

void TObjPlayer::set_vec3_const() { *(float*)((char*)this + 0x0) = TObjPlayer__data_805DC294; *(float*)((char*)this + 0x4) = TObjPlayer__data_805DC294; *(float*)((char*)this + 0x8) = TObjPlayer__data_805DC294; }

void BattleMusicState::reset_counter_field4() {
    timer = 0;
    ((FlagWord *)&flags)->reset();
}

void PlayerActionPaletteState::init_tag() {
    prefix = 0;
    tag.init();
}

#pragma pop

void PlayerDeathSink::reset() {
    offset = TObjPlayer__data_805DC278;
    height = TObjPlayer__data_805DC278;
    progress = TObjPlayer__data_805DC278;
}

s32 TObjPlayer__sub_801BF95C(void* p) { return *(s32*)((char*)p + 0x0); }

void TObjPlayer__sub_801BF954(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }

s32 TObjPlayer::get_lock_timer() { return *(s32*)((char*)this + 0x4); }

void*TObjPlayer::get_sub_object() { return (char*)this + 0x8; }

void PlayerScaleState::set_actor_id(u16 id) { actor_id = id; }

Vec *PlayerScaleState::get_scale() { return &scale; }

s16 PlayerAnimationState::get_action_id() { return action_id; }

s32 TObjPlayer__sub_801BF918(u8 *record) {
    return (u8) (*(s32 *)((s8 *)record + 4) == 2);
}

Vec *TObjPlayer__sub_801BF914(Vec *position) { return position; }

void TObjPlayer__sub_801BF8F8(s32 *p) {
    s32 i;
    for (i = 0; i < 13; i++) {
        *p++ = 0;
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

void*TObjPlayer::reset_sub_status_disp() { ((TWindowSubStatusDisp *)this)->clear_fields(); *(short*)((char*)this + 0x18) = 0; *(short*)((char*)this + 0x16) = 0; return this; }

u8 get_player_action_palette_mode(const PlayerActionPaletteState *state) {
    return get_action_palette_tag_mode(&state->tag);
}

u8 get_player_action_palette_slot(const PlayerActionPaletteState *state) {
    return get_action_palette_tag_slot(&state->tag);
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
    radius_sq = TObjPlayer__data_805DC278;
    center_z = TObjPlayer__data_805DC278;
    center_x = TObjPlayer__data_805DC278;
}

MovementHold *MovementHold::init() {
    reset();
    return this;
}

int ContactSurfaceState::get_flags() { return TObjPlayer__sub_801BFFA0(&word); }

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

void BattleMusicState::set_flag_2() { ((FlagWord *)&flags)->set(2); }

void BattleMusicState::clear_flag0_bit1() { ((FlagWord *)&flags)->clear(2); }

void set_player_action_palette_mode(PlayerActionPaletteState *state, u8 mode) {
    set_action_palette_tag_mode(&state->tag, mode);
}

void set_player_action_palette_slot(PlayerActionPaletteState *state, u8 slot) {
    set_action_palette_tag_slot(&state->tag, slot);
}

void TObjPlayer__sub_801BF4A0(s32 *bits, s32 bit) {
    *bits |= 1 << bit;
}

void TObjPlayer__sub_801BF488(s32 *bits, s32 bit) {
    *bits &= ~(1 << bit);
}

void TObjPlayer__sub_801BF47C(void* p) { *(s32*)((char*)p + 0x0) = 0; }

u8 TObjPlayer__sub_801BF460(s32 *bits, s32 bit) {
    return (u8) ((*bits & (1 << bit)) == 0);
}

TPlayerReadyCallback::TPlayerReadyCallback(TObject* parent, u16 id, void (*fn)(TObjPlayer*)) : TObject(parent) {
    player_id = id;
    callback = fn;
}

void TPlayerLobbyMarker::set_material_index(u8 v) { this->material_index = v; }

int ContactSurfaceState::has_water_ground_flag() { return test_flags_any(&word.bits, 4); }

int TObjPlayer::copy_vec_at_18() { return VecCopy__FP3VecPC3Vec((char*)this + 0x18); }

int TObjPlayer__sub_801BF3A0(void* p) { return VecCopy__FP3VecPC3Vec((char*)p + 0x24); }

void emit_photon_blast_feedback_effects(saddr owner, u16 target_id) {
    TObjPlayer::check_hit_by_id(owner, target_id, 5);
    TObjPlayer::check_hit_by_id(owner, target_id, 0x2C);
    TObjPlayer::check_hit_by_id(owner, target_id, 0x3B);
}

void TObjPlayer::emit_photon_blast_feedback_from_packet() {
    u16 *arg0 = (u16 *)this;
    emit_photon_blast_feedback_effects((saddr)((s8 *)arg0 + 4), *arg0);
}

void* TObjPlayer__sub_801BF31C(void* p) { return (char*)p + 0x18; }

int TObjPlayer::emit_grass_footstep_particle(int position) { return emit_player_particle(this, position, 570); }

void emit_grass_footstep_effect(saddr arg0) {
    ((TObjPlayer *)(arg0 + 4))->emit_grass_footstep_particle((int)((saddr) (TObjPlayer__sub_801BF31C((void*)arg0))));
}

void emit_water_footstep_effect(saddr arg0) {
    emit_water_step_particles((arg0 + 4), (saddr)(get_surface_contact_point((void*)arg0)));
}

void emit_sand_footstep_effect(saddr arg0) {
    emit_sand_step_particles((arg0 + 4), (saddr)(get_surface_contact_point((void*)arg0)));
}

void TObjPlayer::check_hit_by_id_431_from_packet() {
    u16 *arg0 = (u16 *)this;
    TObjPlayer::check_hit_by_id_431((s8 *)arg0 + 4, *arg0);
}

int PlayerHandParticles::emit_movement_effect(u16 target_id) { return TObjPlayer::check_hit_by_id((saddr)this, target_id, 276); }

int PlayerFollowParticles::emit_movement_effect() { return hands.emit_movement_effect(owner_id); }

void* get_surface_contact_point(void* p) { return (char*)p + 0x24; }

void emit_idle_water_effect(saddr particles) {
    emit_idle_water_splash((particles + 4), (saddr)(get_surface_contact_point((void*)particles)));
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

int PlayerHandParticles::emit_zalure_support_effect(u16 target_id) { return create_attached_oneshot_emitter(this, target_id, 508); }

int PlayerFollowParticles::emit_zalure_support() { return hands.emit_zalure_support_effect(owner_id); }

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

void TObjPlayer__sub_801BEF44(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(f32*)((char*)p + 0x4) = *(f32*)((char*)q + 0x4); *(u32*)((char*)p + 0x8) = *(u32*)((char*)q + 0x8); }

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

void TObjPlayer__sub_801BEEAC(u8 *dst, u8 *src) {
    *(s16 *)((s8 *)dst + 0) = (s16) *(s16 *)((s8 *)src + 0);
    *(s16 *)((s8 *)dst + 2) = (s16) *(s16 *)((s8 *)src + 2);
    *(s32 *)((s8 *)dst + 4) = (s32) *(s32 *)((s8 *)src + 4);
    *(f32 *)((s8 *)dst + 8) = (f32) *(f32 *)((s8 *)src + 8);
    __memcpy(dst + 0xC, src + 0xC, 8);
}

void *TObjPlayer::copy_6x0d_status_effect_packet(void *command) {
    copy_subcommand_header(this);
    __memcpy(&((Pkt_801D2964 *)this)->pos, &((Pkt_801D2964 *)command)->pos, 8);
    return this;
}

void TObjPlayer::bswap_status_effect_data() {
    bswap_32((u32 *)this);
    bswap_32((u32 *)((void *)((char *)this + 4)));
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

struct RecoveredGlobal_lbl_804C3E38 { s32 value; s32 pad_4; void *(*dtor)(void *, s16); };
RecoveredGlobal_lbl_804C3E38 lbl_804C3E38 = {0, 0, TObjPlayer__sub_801BFAD4};

void *TObjPlayer__sub_801BFAD4(void *timer, s16 flags) {
    if (timer != NULL) {
        *(s32 **)((s8 *)timer + 4) = &lbl_804C3E38.value;
        if (flags > 0) {
            ::operator delete(timer);
        }
    }
    return timer;
}
#pragma pop

extern "C" {
int clear_movement_history(void*);

s32 TObjPlayer::reset_and_return(saddr p) {
    TObjPlayer__sub_801BF8F8((s32 *)p);
    return p;
}

void TObjPlayer__sub_801BFB4C(Vec *position) {
    position->z = TObjPlayer__data_805DC278;
    position->y = TObjPlayer__data_805DC278;
    position->x = TObjPlayer__data_805DC278;
}

void TObjPlayer::clear_base() { *(s32*)((char*)this + 0x0) = 0; }
void*TObjPlayer::forward_release() { clear_movement_history(this); return this; }
void*TObjPlayer::set_vec3_const_wrapper() { set_vec3_const(); return this; }

}


struct O_801BFC90 { u16 a; u16 b; s32 c; };

extern "C" {
void TObjPlayer__sub_801BFC90(O_801BFC90 *p);
extern const f32 lbl_805DC2DC;


void TObjPlayer::reset_scale_vector() {
    *(f32 *)((s8 *)this + 0x10) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)this + 0xC) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)this + 8) = (f32) TObjPlayer__data_805DC278;
    *(s32 *)((s8 *)this + 4) = 0;
    *(s32 *)((s8 *)this + 0) = 0;
}

u8 *TObjPlayer::construct_hurt_timer() {
    u8 *arg0 = (u8 *)this;
    *(s32 **)((s8 *)arg0 + 4) = &lbl_804C3E38.value;
    ((ProtectionTimer *)this)->reset_type();
    return arg0;
}

BattleMusicState *BattleMusicState::reset_and_clear() { __ct__8FlagWordFv(&flags); reset_counter_field4(); return this; }
void*TObjPlayer::wrap_update() { TObjPlayer__sub_801BFC90((O_801BFC90 *)(this)); return this; }

void TObjPlayer__sub_801BFC90(O_801BFC90 *p) {
    p->c = 0;
    p->a = 0xFFFF;
    p->b = 0;
}

void*TObjPlayer::set_vec4_const_wrapper() { set_vec4_const(); return this; }
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
}
void PlayerScaleState::init() {
    actor_id = 0xFFFF;
    flags.reset();
    set_scalar(lbl_805DC2DC);
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
    z = TObjPlayer__data_805DC278;
    y = TObjPlayer__data_805DC278;
    x = TObjPlayer__data_805DC278;
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
    prefix = 0;
}

void TObjPlayer__sub_801BFF80(u8 *record) {
    *(s32 *)((s8 *)record + 0) = 0;
    *(s32 *)((s8 *)record + 4) = 0;
    *(f32 *)((s8 *)record + 0x10) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)record + 0xC) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)record + 8) = (f32) TObjPlayer__data_805DC278;
}

s32 TObjPlayer__sub_801BFFA0(void* p) { return *(s32*)((char*)p + 0x0); }

u8 *TObjPlayer::copy_hold_params(u8 *src) {
    copy_subcommand_header(this);
    this->m_flags = (s16) *(s16 *)((s8 *)src + 4);
    this->m_id = (s16) *(s16 *)((s8 *)src + 6);
    *(ByteBlock_8 *)((saddr) ((u8 *)this) + 8) = *(const ByteBlock_8 *)((saddr) src + 8);
    *(f32 *)((s8 *)((u8 *)this) + 0x10) = (f32) *(f32 *)((s8 *)src + 0x10);
    return ((u8 *)this);
}

s16 TBoss7Crawfish::get_floor() { return this->requested_action; }
s32 *PlayerActionProvider::get_state_table(s32) { return 0; }
int PlayerActionProvider::vfunc_10() { return 0; }
int PlayerActionProvider::vfunc_5(s32) { return 0; }
int TObjPlayer::sub_802a7290_fwd() { return ((TLobby *)this)->get_valid_child(); }
int TObjPlayer::is_handle_valid() { return TLobby::validate_handle((s32 *)this); }
