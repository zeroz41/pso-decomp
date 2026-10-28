#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/TPlayerReadyCallback.h"
#include "pso/system/FlagWord.h"
#include "pso/system/memory.h"

#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlayerLobbyMarker.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_8 { u8 bytes[0x8]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

struct RecoveredGlobal_801BF414_lbl_804C3FA8 {
    s32 value;
    u8 remaining[0x14];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct RecoveredGlobal_801D2CF4_lbl_804C43CC {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_801D2CF4_lbl_804C43D8 {
    s32 value;
    u8 remaining[0xC];
};

struct Pos_801D2964 { u8 bytes[0x8]; };

struct Pkt_801D2964 { u8 hdr[4]; Pos_801D2964 pos; };

extern "C" {
void bswap_32__FPUl(void *);
void TObjPlayer__sub_801BEEE0(void* p, void* q);
void TObjPlayer__sub_801BEF30(void* p, void* q);
void TObjPlayer__sub_801BEF44(void* p, void* q);
void TObjPlayer__sub_801BEF60(void* p, s32 v);
int create_attached_oneshot_emitter(void*, int, int);
int emit_player_particle(void*, int, int);
void* TObjPlayer__sub_801BF31C(void* p);
int TObjPlayer__sub_801BF3A0(void* p);
int VecCopy__FP3VecPC3Vec(void*);
int has_water_ground_flag(void* p);
int test_flags_any(void*, int);
u8 TObjPlayer__sub_801BF460(s32 *arg0, s32 arg1);
void TObjPlayer__sub_801BF488(s32 *arg0, s32 arg1);
void TObjPlayer__sub_801BF4A0(s32 *arg0, s32 arg1);
void emit_idle_water_effect(s32 arg0);
void TObjPlayer__sub_801BEEAC(u8 *arg0, u8 *arg1);
s32 get_entity_id(int);
}
int emit_zalure_support_effect(void* p, int a1);
int emit_deband_support_effect(void* p, int a1);
void* get_surface_contact_point(void* p);
void emit_grass_footstep_effect(s32 arg0);
void emit_water_step_particles(s32 owner, s32 position);
void emit_water_footstep_effect(s32 arg0);
void emit_sand_step_particles(s32 owner, s32 position);
void emit_sand_footstep_effect(s32 arg0);
void emit_idle_water_splash(s32 owner, s32 position);
void emit_photon_blast_feedback_effects(s32 arg0, s32 arg1);
void prepare_heavy_attack_particles(u8 *arg0);
void emit_jellen_support_effect(u8 *arg0);
void emit_shifta_support_effect(u8 *arg0);
extern "C" {
int TFontSmallLobby__sub_801C0228(void*);
u8 TObjPlayer__sub_801BED70(void* p);
u8 TObjPlayer__sub_801BED78(void* p);
u8 TObjPlayer__sub_801BED80(void* p);
u8 TObjPlayer__sub_801BED88(void* p);
u8 TObjPlayer__sub_801BED90(void* p);
void TObjPlayer__sub_801BED98(void* p, u8 v);
void TObjPlayer__sub_801BEDA0(void* p, u8 v);
void TObjPlayer__sub_801BEDA8(void* p, u8 v);
void TObjPlayer__sub_801BEDB0(void* p, u8 v);
void TObjPlayer__sub_801BEDB8(void* p, u8 v);
void *TObjPlayer__sub_801BEDC0(void *arg0, s16 arg1);
void TObjPlayer__sub_801BF47C(void* p);
int clear__8FlagWordFUl(void*, int);
int set__8FlagWordFUl(void*, int);
int set_mode__20TWindowActionPaletteFUc(void*);
int set_slot__20TWindowActionPaletteFUc(void*);
s32 try_add_item_count__10TObjPlayerFlllUc(s32 a0 = 0, s32 a1 = 0, s32 a2 = 0, s32 a3 = 0);

    extern int shared_flag;
void TObjPlayer::set_shared_flag(int a0) { shared_flag = a0; }

    extern int lbl_805D5D70;
void TObjPlayer::set_shared_count(int a0) { lbl_805D5D70 = a0; }

void TObjPlayer::add_item_count_kind4(s32 arg0, s32 arg1, s32 arg2) {
    try_add_item_count__10TObjPlayerFlllUc(arg0, arg1, 4, arg2);
}
void TObjPlayer::try_add_item_count_kind3(s32 arg0, s32 arg1, s32 arg2) {
    try_add_item_count__10TObjPlayerFlllUc(arg0, arg1, 3, arg2);
}
void TObjPlayer::try_add_item_count_type2(s32 arg0, s32 arg1, s32 arg2) {
    try_add_item_count__10TObjPlayerFlllUc(arg0, arg1, 2, arg2);
}
void TObjPlayer::add_item_count(s32 arg0, s32 arg1, s32 arg2) {
    try_add_item_count__10TObjPlayerFlllUc(arg0, arg1, 1, arg2);
}
void TObjPlayer::try_add_item(s32 arg0, s32 arg1, s32 arg2) {
    try_add_item_count__10TObjPlayerFlllUc(arg0, arg1, 0, arg2);
}
u8 TObjPlayer__sub_801BED70(void* p) { return *(u8*)((char*)p + 0x4); }
u8 TObjPlayer__sub_801BED78(void* p) { return *(u8*)((char*)p + 0x3); }
u8 TObjPlayer__sub_801BED80(void* p) { return *(u8*)((char*)p + 0x2); }
u8 TObjPlayer__sub_801BED88(void* p) { return *(u8*)((char*)p + 0x1); }
u8 TObjPlayer__sub_801BED90(void* p) { return *(u8*)((char*)p + 0x0); }
void TObjPlayer__sub_801BED98(void* p, u8 v) { *(u8*)((char*)p + 0x4) = v; }
void TObjPlayer__sub_801BEDA0(void* p, u8 v) { *(u8*)((char*)p + 0x3) = v; }
void TObjPlayer__sub_801BEDA8(void* p, u8 v) { *(u8*)((char*)p + 0x2) = v; }
void TObjPlayer__sub_801BEDB0(void* p, u8 v) { *(u8*)((char*)p + 0x1) = v; }
void TObjPlayer__sub_801BEDB8(void* p, u8 v) { *(u8*)((char*)p + 0x0) = v; }

extern s32 lbl_804C3E44[];

void *TObjPlayer__sub_801BEDC0(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 8) = lbl_804C3E44;
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

void TObjPlayer::set_position(f32 a, f32 b, f32 c) { this->position[0] = a; this->position[1] = b; this->position[2] = c; }

void TObjPlayer::set_meseta(s32 arg1) {
    *(s32 *)(this->m_2b0 + 0x20) = arg1;
}

void TObjPlayer::sub_801BEE24(s16 v) { *(s16 *)&this->unk_2BE = v; }

void TObjPlayer::sub_801BEE2C(s16 v) { this->m_2bc = v; }

void TObjPlayer::bswap_status_effect_data() {
    bswap_32__FPUl(this);
    bswap_32__FPUl((void *)((char *)this + 4));
}

#pragma push
#pragma opt_common_subs off
#pragma pop
void *TObjPlayer::copy_6x0d_status_effect_packet(void *arg1) {
    TFontSmallLobby__sub_801C0228(this);
    ((Pkt_801D2964 *)this)->pos = ((Pkt_801D2964 *)arg1)->pos;
    return this;
}
#pragma push
#pragma fp_contract on
#pragma pop
typedef char RecoveredGlobal_801D2CF4_lbl_804C43CC_size[sizeof(RecoveredGlobal_801D2CF4_lbl_804C43CC) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_801D2CF4_lbl_804C43D8_size[sizeof(RecoveredGlobal_801D2CF4_lbl_804C43D8) == 0x10 ? 1 : -1];

void TObjPlayer__sub_801BEEAC(u8 *arg0, u8 *arg1) {
    *(s16 *)((s8 *)arg0 + 0) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(f32 *)((s8 *)arg0 + 8) = (f32) *(f32 *)((s8 *)arg1 + 8);
    *(ByteBlock_8 *)((s32) arg0 + 0xC) = *(const ByteBlock_8 *)((s32) arg1 + 0xC);
}

void TObjPlayer__sub_801BEEE0(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); }

void TObjPlayer::copy_player_record_header(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    *(u16 *)((s8 *)arg0 + 0) = (u16) *(u16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(ByteBlock_C *)((s32) (u8 *)&this->m_prev) = *(const ByteBlock_C *)((s32) arg1 + 8);
    *(s32 *)((s8 *)arg0 + 0x14) = (s32) *(s32 *)((s8 *)arg1 + 0x14);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) *(s32 *)((s8 *)arg1 + 0x18);
}

void TObjPlayer__sub_801BEF30(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }

void TObjPlayer__sub_801BEF44(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(f32*)((char*)p + 0x4) = *(f32*)((char*)q + 0x4); *(u32*)((char*)p + 0x8) = *(u32*)((char*)q + 0x8); }

void TObjPlayer__sub_801BEF60(void* p, s32 v) { *(s32*)((char*)p + 0xc) = v; }

void TObjPlayer::prepare_heavy_attack_particles_default() { prepare_heavy_attack_particles((u8 *)((char*)this + 0x4)); }
}

#pragma push
#pragma fp_contract on
void prepare_heavy_attack_particles(u8 *arg0) {
    if (*(u32 *)((s8 *)arg0 + 4) != 0U) {
        TObjPlayer::check_hit_by_id((s32)arg0, (s32)((int)((int) (get_entity_id((int) *(u32 *)((s8 *)arg0 + 4))))), 0x11);
        TObjPlayer::check_hit_by_id((s32)arg0, (s32)((int)((int) (get_entity_id((int) *(u32 *)((s8 *)arg0 + 4))))), 0x12);
    }
}
#pragma pop

int TObjPlayer::emit_zalure_support_effect_at() {
    u16 *arg0 = (u16 *)this; return emit_zalure_support_effect((void*)((s8 *)arg0 + 4), (int)(*arg0)); }

int emit_zalure_support_effect(void* p, int a1) { return create_attached_oneshot_emitter(p, a1, 508); }

int TObjPlayer::emit_deband_support_effect_at() {
    u16 *arg0 = (u16 *)this; return emit_deband_support_effect((void*)((s8 *)arg0 + 4), (int)(*arg0)); }

int emit_deband_support_effect(void* p, int a1) { return TObjPlayer::check_hit_by_id((s32)p, (s32)a1, 508); }

void TObjPlayer::emit_jellen_support_effect_default() { emit_jellen_support_effect((u8 *)((char*)this + 0x4)); }

#pragma push
#pragma fp_contract on
void emit_jellen_support_effect(u8 *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0) != 0U) {
        create_attached_oneshot_emitter(arg0, (int)((int) (get_entity_id((int) *(u32 *)((s8 *)arg0 + 0)))), 0x1C);
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 4) != 0U) {
        create_attached_oneshot_emitter(arg0, (int)((int) (get_entity_id((int) *(u32 *)((s8 *)arg0 + 4)))), 0x1C);
    }
}
#pragma pop

void TObjPlayer::emit_shifta_support() { emit_shifta_support_effect((u8 *)((char*)this + 0x4)); }

#pragma push
#pragma fp_contract on
void emit_shifta_support_effect(u8 *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0) != 0U) {
        TObjPlayer::check_hit_by_id((s32)arg0, (s32)((int)((int) (get_entity_id((int) *(u32 *)((s8 *)arg0 + 0))))), 0x1C);
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 4) != 0U) {
        TObjPlayer::check_hit_by_id((s32)arg0, (s32)((int)((int) (get_entity_id((int) *(u32 *)((s8 *)arg0 + 4))))), 0x1C);
    }
}
#pragma pop

void emit_idle_water_effect(s32 arg0) {
    emit_idle_water_splash((arg0 + 4), (s32)(get_surface_contact_point((void*)arg0)));
}

void* get_surface_contact_point(void* p) { return (char*)p + 0x24; }

int TObjPlayer::emit_movement_effect_at() {
    u16 *arg0 = (u16 *)this; return ((TObjPlayer *)((s8 *)arg0 + 4))->check_hit_by_id_276((int)(*arg0)); }

int TObjPlayer::check_hit_by_id_276(int a1) { return TObjPlayer::check_hit_by_id((s32)this, (s32)a1, 276); }

void TObjPlayer::check_hit_by_id_431_from_packet() {
    u16 *arg0 = (u16 *)this;
    TObjPlayer::check_hit_by_id_431((s8 *)arg0 + 4, *arg0);
}

void emit_sand_footstep_effect(s32 arg0) {
    emit_sand_step_particles((arg0 + 4), (s32)(get_surface_contact_point((void*)arg0)));
}

void emit_water_footstep_effect(s32 arg0) {
    emit_water_step_particles((arg0 + 4), (s32)(get_surface_contact_point((void*)arg0)));
}

void emit_grass_footstep_effect(s32 arg0) {
    ((TObjPlayer *)(arg0 + 4))->emit_grass_footstep_particle((int)((int) (TObjPlayer__sub_801BF31C((void*)arg0))));
}

int TObjPlayer::emit_grass_footstep_particle(int a1) { return emit_player_particle(this, a1, 570); }

void* TObjPlayer__sub_801BF31C(void* p) { return (char*)p + 0x18; }

void TObjPlayer::emit_photon_blast_feedback_from_packet() {
    u16 *arg0 = (u16 *)this;
    emit_photon_blast_feedback_effects((s32)((s8 *)arg0 + 4), (s32)(*arg0));
}

void emit_photon_blast_feedback_effects(s32 arg0, s32 arg1) {
    TObjPlayer::check_hit_by_id(arg0, arg1, 5);
    TObjPlayer::check_hit_by_id(arg0, arg1, 0x2C);
    TObjPlayer::check_hit_by_id(arg0, arg1, 0x3B);
}

int TObjPlayer__sub_801BF3A0(void* p) { return VecCopy__FP3VecPC3Vec((char*)p + 0x24); }

int TObjPlayer::copy_vec_at_18() { return VecCopy__FP3VecPC3Vec((char*)this + 0x18); }

int has_water_ground_flag(void* p) { return test_flags_any(p, 4); }

void TPlayerLobbyMarker::set_material_index(u8 v) { this->material_index = v; }

typedef char RecoveredGlobal_801BF414_lbl_804C3FA8_size[sizeof(RecoveredGlobal_801BF414_lbl_804C3FA8) == 0x18 ? 1 : -1];
TPlayerReadyCallback::TPlayerReadyCallback(TObject* parent, u16 id, void (*fn)(TObjPlayer*)) : TObject(parent) {
    player_id = id;
    callback = fn;
}

u8 TObjPlayer__sub_801BF460(s32 *arg0, s32 arg1) {
    return (u8) ((*arg0 & (1 << arg1)) == 0);
}

void TObjPlayer__sub_801BF47C(void* p) { *(s32*)((char*)p + 0x0) = 0; }

void TObjPlayer__sub_801BF488(s32 *arg0, s32 arg1) {
    *arg0 &= ~(1 << arg1);
}

void TObjPlayer__sub_801BF4A0(s32 *arg0, s32 arg1) {
    *arg0 |= 1 << arg1;
}

int TObjPlayer::update_action_palette() { return set_slot__20TWindowActionPaletteFUc((char*)this + 0x4); }
int TObjPlayer::set_action_palette_mode() { return set_mode__20TWindowActionPaletteFUc((char*)this + 0x4); }
void TObjPlayer::clear_flag0_bit1() { ((FlagWord *)this)->clear(2); }
void TObjPlayer::set_flag_2() { ((FlagWord *)this)->set(2); }
