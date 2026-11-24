#include "pso/player/PlayerState.h"
#include "pso/player/TPlayerReadyCallback.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/memory.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerActionPaletteState.h"
#include "pso/player/TPlayerLobbyMarker.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TPlyDispData.h"
#include "pso/unk/text_80072004.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/unk/TUnk_804DDD28.h"
#include "pso/boss/barbaray/TBoss7Crawfish.h"
#include "pso/unk/TLobby.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/TPlyPtclObjectLeftHand.h"
#include "pso/player/TPlyPtclObjectRightHand.h"


#define TOBJECT_OUT_OF_LINE_HELPERS


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
void TObjPlayer__sub_801BEF60(void* p, s32 v);
int create_attached_oneshot_emitter(void*, u16, int);
int emit_player_particle(void*, int, int);
void* TObjPlayer__sub_801BF31C(void* p);
int TObjPlayer__sub_801BF3A0(void* p);
int VecCopy__FP3VecPC3Vec(void*);
int test_flags_any(void*, int);
u8 TObjPlayer__sub_801BF460(s32 *arg0, s32 arg1);
void TObjPlayer__sub_801BF488(s32 *arg0, s32 arg1);
void TObjPlayer__sub_801BF4A0(s32 *arg0, s32 arg1);
void emit_idle_water_effect(saddr arg0);
void TObjPlayer__sub_801BEEAC(u8 *arg0, u8 *arg1);
}
int emit_zalure_support_effect(void* p, u16 target_id);
int emit_deband_support_effect(void* p, u16 target_id);
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
int lbl_805D5D70;
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

s32 TObjPlayer__sub_801BF918(u8 *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 4) == 2);
}

Vec *TObjPlayer__sub_801BF914(Vec *position) { return position; }

void TObjPlayer__sub_801BF8F8(s32 *p) {
    s32 i;
    for (i = 0; i < 13; i++) {
        *p++ = 0;
    }
}

void set_equip_slot_entry(saddr arg0, s32 val_ext, s32 arg2) {
    *(s32 *)((s8 *)arg0 + (val_ext * 4)) = arg2;
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

void TObjPlayer__sub_801BF4A0(s32 *arg0, s32 arg1) {
    *arg0 |= 1 << arg1;
}

void TObjPlayer__sub_801BF488(s32 *arg0, s32 arg1) {
    *arg0 &= ~(1 << arg1);
}

void TObjPlayer__sub_801BF47C(void* p) { *(s32*)((char*)p + 0x0) = 0; }

u8 TObjPlayer__sub_801BF460(s32 *arg0, s32 arg1) {
    return (u8) ((*arg0 & (1 << arg1)) == 0);
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

int TObjPlayer::check_hit_by_id_276(u16 target_id) { return TObjPlayer::check_hit_by_id((saddr)this, target_id, 276); }

int TObjPlayer::emit_movement_effect_at() {
    u16 *arg0 = (u16 *)this; return ((TObjPlayer *)((s8 *)arg0 + 4))->check_hit_by_id_276(*arg0); }

void* get_surface_contact_point(void* p) { return (char*)p + 0x24; }

void emit_idle_water_effect(saddr arg0) {
    emit_idle_water_splash((arg0 + 4), (saddr)(get_surface_contact_point((void*)arg0)));
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

int emit_deband_support_effect(void* p, u16 target_id) { return TObjPlayer::check_hit_by_id((saddr)p, target_id, 508); }

int TObjPlayer::emit_deband_support_effect_at() {
    u16 *arg0 = (u16 *)this; return emit_deband_support_effect((void*)((s8 *)arg0 + 4), *arg0); }

int emit_zalure_support_effect(void* p, u16 target_id) { return create_attached_oneshot_emitter(p, target_id, 508); }

int TObjPlayer::emit_zalure_support_effect_at() {
    u16 *arg0 = (u16 *)this; return emit_zalure_support_effect((void*)((s8 *)arg0 + 4), *arg0); }

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

void TObjPlayer__sub_801BEF60(void* p, s32 v) { *(s32*)((char*)p + 0xc) = v; }

void TObjPlayer__sub_801BEF44(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(f32*)((char*)p + 0x4) = *(f32*)((char*)q + 0x4); *(u32*)((char*)p + 0x8) = *(u32*)((char*)q + 0x8); }

void TObjPlayer__sub_801BEF30(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }

void TObjPlayer::copy_player_record_header(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    *(u16 *)((s8 *)arg0 + 0) = (u16) *(u16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    __memcpy(&this->m_prev, arg1 + 8, 0xC);
    *(s32 *)((s8 *)arg0 + 0x14) = (s32) *(s32 *)((s8 *)arg1 + 0x14);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) *(s32 *)((s8 *)arg1 + 0x18);
}

void TObjPlayer__sub_801BEEE0(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); }

void TObjPlayer__sub_801BEEAC(u8 *arg0, u8 *arg1) {
    *(s16 *)((s8 *)arg0 + 0) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(f32 *)((s8 *)arg0 + 8) = (f32) *(f32 *)((s8 *)arg1 + 8);
    __memcpy(arg0 + 0xC, arg1 + 0xC, 8);
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

void TObjPlayer::set_meseta(s32 arg1) {
    this->stat_block->meseta = arg1;
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

void TObjPlayer::set_shared_count(int a0) { lbl_805D5D70 = a0; }

void TObjPlayer::set_shared_flag(int a0) { shared_flag = a0; }

#pragma defer_codegen off
#pragma push
#pragma dont_inline on

struct RecoveredGlobal_lbl_804C3E38 { s32 value; s32 pad_4; void *(*dtor)(void *, s16); };
RecoveredGlobal_lbl_804C3E38 lbl_804C3E38 = {0, 0, TObjPlayer__sub_801BFAD4};

void *TObjPlayer__sub_801BFAD4(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 4) = &lbl_804C3E38.value;
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
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

void TObjPlayer__sub_801BFF80(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0) = 0;
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(f32 *)((s8 *)arg0 + 0x10) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)arg0 + 0xC) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)arg0 + 8) = (f32) TObjPlayer__data_805DC278;
}

s32 TObjPlayer__sub_801BFFA0(void* p) { return *(s32*)((char*)p + 0x0); }

u8 *TObjPlayer::copy_hold_params(u8 *arg1) {
    copy_subcommand_header(this);
    this->m_flags = (s16) *(s16 *)((s8 *)arg1 + 4);
    this->m_id = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(ByteBlock_8 *)((saddr) ((u8 *)this) + 8) = *(const ByteBlock_8 *)((saddr) arg1 + 8);
    *(f32 *)((s8 *)((u8 *)this) + 0x10) = (f32) *(f32 *)((s8 *)arg1 + 0x10);
    return ((u8 *)this);
}

s16 TBoss7Crawfish::get_floor() { return this->requested_action; }
s32 *TUnk_804DDD28::get_state_table(s32) { return 0; }
int TUnk_804DDD28::vfunc_10() { return 0; }
int TUnk_804DDD28::vfunc_5(s32) { return 0; }
int TObjPlayer::sub_802a7290_fwd() { return ((TLobby *)this)->get_valid_child(); }
int TObjPlayer::is_handle_valid() { return TLobby::validate_handle((s32 *)this); }

