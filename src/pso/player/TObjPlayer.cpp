#include "pso/player/TPlayerReadyCallback.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/memory.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlayerLobbyMarker.h"
#include "pso/player/TObjPlayer_801BF548.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/player/TObjPlayer_801BF6B0.h"
#include "pso/player/TObjPlayer_801BF8EC.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer_801BF918.h"
#include "pso/player/TPlyDispData.h"
#include "pso/player/TObjPlayer_801BF978.h"
#include "pso/unk/text_80072004.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/player/TObjPlayer_801BFAD4.h"
#include "pso/player/TObjPlayer_801BFB1C.h"
#include "pso/player/TObjPlayer_801BFBCC.h"
#include "pso/player/TObjPlayer_801BFE50.h"
#include "pso/player/TObjPlayer_801BFED4.h"
#include "pso/unk/TUnk_804DDD28.h"
#include "pso/boss/barbaray/TBoss7Crawfish.h"
#include "pso/unk/TLobby.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/TLobby.h"

#define TOBJECT_OUT_OF_LINE_HELPERS


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

int lbl_805D5D70;
int shared_flag;
void TObjPlayer::set_shared_flag(int a0) { shared_flag = a0; }

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

void TObjPlayer::set_position(f32 a, f32 b, f32 c) { this->position.x = a; this->position.y = b; this->position.z = c; }

void TObjPlayer::set_meseta(s32 arg1) {
    *(s32 *)(this->m_2b0 + 0x20) = arg1;
}

void TObjPlayer::sub_801BEE24(s16 v) { *(s16 *)&this->tp_bonus = v; }

void TObjPlayer::sub_801BEE2C(s16 v) { this->hp_bonus = v; }

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

extern "C" {
extern const f32 TObjPlayer__data_805DC278;
s32 is_timer_running(u8 *p) {
    return (u8) (*(s32 *)((s8 *)p + 4) != -1);
}

s32 TObjPlayer__sub_801BF560(s16 *arg0) {
  s16 temp_r4;
  unsigned int new_var;
  temp_r4 = (*arg0 = (*arg0) - 1);
  new_var = (u32) temp_r4;
  return (new_var >> 0x1FU) ^ 1;
}

s16 TObjPlayer__sub_801BF57C(void* p) { return *(s16*)((char*)p + 0x0); }

s32 TObjPlayer__sub_801BF584(u8 *arg0) {
    if ((TObjPlayer__sub_801BF5F8(arg0, (s32)((int) (TObjPlayer__sub_801BF60C(arg0)))) != 0) && (TObjPlayer__sub_801BF5F8(arg0, (s32)((int) (*(s32 *)((s8 *)arg0 + 8)))) != 0)) {
        TObjPlayer__sub_801BF5F0(arg0, 0x96);
        return 1;
    }
    return 0;
}

void TObjPlayer__sub_801BF5F0(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }

s32 TObjPlayer__sub_801BF5F8(void *arg0, s32 arg1) {
    return (u8) ((arg1 & 0xC) != 0);
}

s32 TObjPlayer__sub_801BF60C(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 8) ^ ((s32)TObjPlayer__sub_801BF640(arg0));
}

int TObjPlayer__sub_801BF640(void* p) { return TObjPlayer__sub_801BFFA0(p); }

void *TObjPlayer__sub_801BF660(void *arg0) {
    TObjPlayer__sub_801BF690((u8 *)arg0);
    return arg0;
}
void TObjPlayer__sub_801BF690(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 0) = 0;
    *(s16 *)((s8 *)arg0 + 2) = 0;
    *(f32 *)((s8 *)arg0 + 8) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)arg0 + 0x10) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)arg0 + 0xC) = (f32) TObjPlayer__data_805DC278;
}

}

extern "C" {

int TObjPlayer__sub_801BF8CC(void* p);
int reset__8FlagWordFv(void*);
int get_enabled__11TMainCursorFv(void*);
int get_type__11TMainCursorFv(void*);

f32 TObjPlayer__sub_801BF6B0(void* p) { return *(f32*)((char*)p + 0x8); }
void* TObjPlayer__sub_801BF6B8(void* p) { return (char*)p + 0xc; }
void TObjPlayer__sub_801BF6C0(void* p, f32 v) { *(f32*)((char*)p + 0x8) = v; }
void TObjPlayer__sub_801BF6C8(void* p, f32 a, f32 b) { *(f32*)((char*)p + 0xc) = a; *(f32*)((char*)p + 0x10) = b; }
void TObjPlayer__sub_801BF6D4(void* p, s16 v) { *(s16*)((char*)p + 0x0) = v; }
void TObjPlayer__sub_801BF6DC(void* p, s16 v) { *(s16*)((char*)p + 0x2) = v; }
int TObjPlayer__sub_801BF6E4(void* p) { return get_enabled__11TMainCursorFv((char*)p + 0x4); }
int TObjPlayer::update_main_cursor() { return get_type__11TMainCursorFv((char*)this + 0x4); }
void*TObjPlayer::reset_sub_status_disp() { ((TWindowSubStatusDisp *)this)->clear_fields(); *(short*)((char*)this + 0x18) = 0; *(short*)((char*)this + 0x16) = 0; return this; }
s32 TObjPlayer::update_timer() {
    s32 temp_r0;

    if (is_timer_running((u8 *)this) != 0) {
        temp_r0 = *(s32 *)((s8 *)this + 4) - 1;
        *(s32 *)((s8 *)this + 4) = temp_r0;
        if (temp_r0 < 0) {
            TObjPlayer__sub_801BF7B8(this);
        }
    }
    return *(s32 *)((s8 *)this + 4);
}
void TObjPlayer__sub_801BF7B8(void* p) { *(s32*)((char*)p + 0x4) = -1; }
void TObjPlayer::update_field8() {
    *(s32 *)((s8 *)this + 8) = TObjPlayer__sub_801BF640(this);
}
void TObjPlayer::set_anim_state(s32 v) { *(s32*)((char*)this + 0x4) = v; }
void TObjPlayer::set_state(s16 v) { *(s16*)((char*)this + 0x0) = v; }
void TObjPlayer::set_anim_state(s16 v) { *(s16*)((char*)this + 0x8) = v; }
void TObjPlayer::set_action_id(s16 v) { *(s16*)((char*)this + 0x2) = v; }
f32 TObjPlayer__sub_801BF814(void* p) { return *(f32*)((char*)p + 0x0); }
void TObjPlayer::test_flag_16() { ((FlagWord *)this)->set(16); }
void TObjPlayer__sub_801BF840(void* p) { ((FlagWord *)p)->set(8); }
void TObjPlayer::set_flag_4() { ((FlagWord *)this)->set(4); }
void TObjPlayer::check_flag_2() { ((FlagWord *)this)->set(2); }
int TObjPlayer__sub_801BF8AC(void* p) { return TObjPlayer__sub_801BF8CC(p); }
int TObjPlayer__sub_801BF8CC(void* p) { return reset__8FlagWordFv(p); }

}

void set_equip_slot_entry(s32 arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + (arg1 * 4)) = arg2;
}

void TObjPlayer__sub_801BF8F8(s32 *p) {
    s32 i;
    for (i = 0; i < 13; i++) {
        *p++ = 0;
    }
}

void TObjPlayer__sub_801BF914(void) {  }


u8 TObjPlayer__sub_801BF918(u8 *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 4) == 2);
}

s16 TObjPlayer::get_action_id() { return *(s16*)((char*)this + 0x2); }
void* TObjPlayer__sub_801BF934(void* p) { return (char*)p + 0xc; }
void TObjPlayer__sub_801BF93C(void* p, s16 v) { *(s16*)((char*)p + 0x0) = v; }
void*TObjPlayer::get_sub_object() { return (char*)this + 0x8; }
s32 TObjPlayer::get_lock_timer() { return *(s32*)((char*)this + 0x4); }
void TObjPlayer__sub_801BF954(void* p, s32 v) { *(s32*)((char*)p + 0x0) = v; }
s32 TObjPlayer__sub_801BF95C(void* p) { return *(s32*)((char*)p + 0x0); }

void zero_vec3(void* a0) { *(float*)((char*)a0 + 0x0) = TObjPlayer__data_805DC278; *(float*)((char*)a0 + 0x4) = TObjPlayer__data_805DC278; *(float*)((char*)a0 + 0x8) = TObjPlayer__data_805DC278; }

struct RecoveredGlobal_801BF9F0_lbl_804C3E50 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
extern RecoveredGlobal_801BF9F0_lbl_804C3E50 lbl_804C3E50;

void TObjPlayer::init_tag() {
    s32 *arg0 = (s32 *)this;
    *arg0 = 0;
    init__6gc_tagFv((char *)arg0 + 4);
}

void TObjPlayer::reset_counter_field4() {
    *(s32 *)((s8 *)this + 4) = 0;
    ((FlagWord *)this)->FlagWord::reset();
}

    extern const float TObjPlayer__data_805DC294;
void TObjPlayer::set_vec3_const() { *(float*)((char*)this + 0x0) = TObjPlayer__data_805DC294; *(float*)((char*)this + 0x4) = TObjPlayer__data_805DC294; *(float*)((char*)this + 0x8) = TObjPlayer__data_805DC294; }

void TObjPlayer__sub_801BF9E0(void* p, s16 v) { *(s16*)((char*)p + 0x0) = v; }
void TObjPlayer::set_pos_z(f32 v) { *(f32*)((char*)this + 0x8) = v; }

typedef char RecoveredGlobal_801BF9F0_lbl_804C3E50_size[sizeof(RecoveredGlobal_801BF9F0_lbl_804C3E50) == 0x10 ? 1 : -1];
u8 *TObjPlayer__sub_801BF9F0(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 8) = &lbl_804C3E50.value;
        TPlyDispConfig::free_if_valid((s32)(arg0 + 4), -1);
        if (arg1 > 0) {
            ::operator delete((arg0));
        }
    }
    return arg0;
}

s32 TObjPlayer__sub_801BFA4C(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        TObjPlayer::free_if_valid(arg0, 0);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

}

s32 TObjPlayer::free_if_valid(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

struct RecoveredGlobal_801BFBEC_lbl_804C3E38 {
    s32 value;
    u8 remaining[0x8];
};

extern RecoveredGlobal_801BFBEC_lbl_804C3E38 lbl_804C3E38;

void *TObjPlayer__sub_801BFAD4(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 4) = &lbl_804C3E38.value;
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {
int clear_movement_history(void*);

s32 TObjPlayer::reset_and_return(s32 p) {
    TObjPlayer__sub_801BF8F8((s32 *)p);
    return p;
}

void TObjPlayer__sub_801BFB4C(u8 *arg0) {
    *(f32 *)((s8 *)arg0 + 8) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)arg0 + 4) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)arg0 + 0) = (f32) TObjPlayer__data_805DC278;
}

void TObjPlayer::clear_base() { *(s32*)((char*)this + 0x0) = 0; }
void*TObjPlayer::forward_release() { clear_movement_history(this); return this; }
void*TObjPlayer::set_vec3_const_wrapper() { set_vec3_const(); return this; }

}


struct O_801BFC90 { u16 a; u16 b; s32 c; };

extern "C" {
void TObjPlayer__sub_801BFC90(O_801BFC90 *p);
extern const f32 lbl_805DC2DC;
void reset_stat_scale_and_ring__10TObjPlayerFi(s32 arg0);


void TObjPlayer::reset_scale_vector() {
    *(f32 *)((s8 *)this + 0x10) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)this + 0xC) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)this + 8) = (f32) TObjPlayer__data_805DC278;
    *(s32 *)((s8 *)this + 4) = 0;
    *(s32 *)((s8 *)this + 0) = 0;
}

typedef char RecoveredGlobal_801BFBEC_lbl_804C3E38_size[sizeof(RecoveredGlobal_801BFBEC_lbl_804C3E38) == 0xC ? 1 : -1];
u8 *TObjPlayer::construct_hurt_timer() {
    u8 *arg0 = (u8 *)this;
    *(s32 **)((s8 *)arg0 + 4) = &lbl_804C3E38.value;
    ((TObjPlayer *)arg0)->reset_type();
    return arg0;
}

void*TObjPlayer::reset_and_clear() { __ct__8FlagWordFv(this); reset_counter_field4(); return this; }
void*TObjPlayer::wrap_update() { TObjPlayer__sub_801BFC90((O_801BFC90 *)(this)); return this; }

void TObjPlayer__sub_801BFC90(O_801BFC90 *p) {
    p->c = 0;
    p->a = 0xFFFF;
    p->b = 0;
}

void*TObjPlayer::set_vec4_const_wrapper() { set_vec4_const(); return this; }
void*TObjPlayer::init_members() { zero_vec3(this); return this; }
void*TObjPlayer::init_wrapper() { TObjPlayer__sub_801BFD3C(this); return this; }
void TObjPlayer__sub_801BFD3C(void* p) { *(s16*)((char*)p + 0x0) = 0; *(s16*)((char*)p + 0x2) = 0; *(s32*)((char*)p + 0x4) = 0; *(s16*)((char*)p + 0x8) = 0; }
void*TObjPlayer::init_sub() { __ct__8FlagWordFv(((char*)this + 0xc)); reset_stat_scale_and_ring__10TObjPlayerFi((s32)this); return this; }
void*TObjPlayer::init_subobjects() { __ct__8FlagWordFv(((char*)this + 0x4)); ((TObjPlayer *)((char*)this + 0x18))->init_pair(); init_player_scale_state(this); return this; }
}
int init_player_scale_state(TObjPlayer *player) {
    *(u16 *)player = 0xFFFF;
    ((FlagWord *)((u8 *)player + 4))->reset();
    player->set_speed(lbl_805DC2DC);
}

extern "C" {


void TObjPlayer::set_speed(f32 farg0) {
    *(f32 *)((s8 *)this + 8) = farg0;
    set_scale_xyz(farg0);
}

}

void TObjPlayer::set_scale_xyz(f32 farg0) {
    *(f32 *)((s8 *)this + 0x14) = farg0;
    *(f32 *)((s8 *)this + 0x10) = farg0;
    *(f32 *)((s8 *)this + 0xC) = farg0;
}

extern "C" {

void*TObjPlayer::init_pair() { TObjPlayer__sub_801BFE88((u8 *)this); TObjPlayer__sub_801BFE88((u8 *)((char*)this + 0xc)); return this; }

extern "C" {

void TObjPlayer__sub_801BFE88(u8 *arg0) {
    *(f32 *)((s8 *)arg0 + 8) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)arg0 + 4) = (f32) TObjPlayer__data_805DC278;
    *(f32 *)((s8 *)arg0 + 0) = (f32) TObjPlayer__data_805DC278;
}

s32 init_state__10TObjPlayerFi(s32 p) {
    ((TObjPlayer *)p)->setup_state();
    TObjPlayer__sub_801BFED4((void *)p);
    return p;
}

}

}

extern "C" {

void TObjPlayer__sub_801BFED4(void* p) { *(s32*)((char*)p + 0x4) = -1; }
s32 TObjPlayer::setup_state() {
    s32 arg0 = (s32)this;
    __ct__8FlagWordFv(this);
    setup_state_helper();
    return arg0;
}
void TObjPlayer::setup_state_helper() { ((FlagWord *)this)->reset(); }


u8 *TObjPlayer::init_subobject() {
    u8 *arg0 = (u8 *)this;
    *(s32 * *)&this->m_prev = &lbl_804C3E50.value;
    init_gc_tag((s32)(arg0 + 4));
    *(s32 *)((s8 *)arg0 + 0) = 0;
    return arg0;
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
    TFontSmallLobby__sub_801C0228(this);
    this->m_flags = (s16) *(s16 *)((s8 *)arg1 + 4);
    this->m_id = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(ByteBlock_8 *)((s32) ((u8 *)this) + 8) = *(const ByteBlock_8 *)((s32) arg1 + 8);
    *(f32 *)((s8 *)((u8 *)this) + 0x10) = (f32) *(f32 *)((s8 *)arg1 + 0x10);
    return ((u8 *)this);
}

s16 TBoss7Crawfish::get_floor() { return this->requested_action; }
int TUnk_804DDD28::vfunc_77(s32) { return 0; }
int TUnk_804DDD28::vfunc_10() { return 0; }
int TUnk_804DDD28::vfunc_5(s32) { return 0; }
int TObjPlayer::sub_802a7290_fwd() { return ((TLobby *)this)->get_valid_child(); }
int TObjPlayer::is_handle_valid() { return TLobby::validate_handle((s32 *)this); }

}
