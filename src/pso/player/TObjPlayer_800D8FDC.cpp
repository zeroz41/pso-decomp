#include "pso/unk/SampledMotionPoints.h"
#include "pso/math/FloatRounding.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/object/TDeadSpot.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/memory.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 __nw__7TObjectFUl(s32);
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
extern void * player_corpse_mark_resource;
#define create_dead_spot__10TObjPlayerFiiif ((s32 (*)(s32, s32, s32))create_dead_spot__10TObjPlayerFiiif)

extern s32 tl_05;

void TObjPlayer::create_dead_spot(s32 arg0, s32 arg1, f32 farg0) {
    s32 temp_r3;

    temp_r3 = __nw__7TObjectFUl(0x38);
    if (temp_r3 != 0) {
        construct_fire_base__9TDeadSpotFPvPvPvif((u8 *)temp_r3, (u8 *)tl_05, (u8 *)arg0, (s32)(create_timed_particle_emitter((void *)arg0, 0xF8, 0, (arg1))), (f32)farg0);
    }
}

void TObjPlayer::spawn_effect_f8(s32 arg1, s32 arg2) {
    create_timed_particle_emitter((void *)arg1, 0xF8, 0, (arg2));
}

void TObjPlayer::set_field_e4(s32 arg1, s32 arg2) {
    create_dead_spot__10TObjPlayerFiiif(arg1, 0xE4, arg2);
}

#undef create_dead_spot__10TObjPlayerFiiif

void *spawn_particle_effect(void *pos, s32 id);

void create_dead_spot__10TObjPlayerFiiif(s32 arg0, s32 arg1, s32 arg2, f32 farg0) {
    s32 temp_r3;

    temp_r3 = __nw__7TObjectFUl(0x38);
    if (temp_r3 != 0) {
        init__9TDeadSpotFPv((void *)temp_r3, (u8 *)tl_05, (u8 *)arg0, (s32)(create_timed_particle_emitter((void *)arg0, (arg1), 0, (arg2))), (f32)farg0);
    }
}

void fn_800D911C(Vec *position) {
    create_timed_particle_emitter(position, 232, 10, 1);
    create_timed_particle_emitter(position, 236, 10, 1);
}

void TObjPlayer::trigger_dell_biter_events() { spawn_particle_effect(this, (s32)((void*)251)); spawn_particle_effect(this, (s32)((void*)252)); spawn_particle_effect(this, (s32)((void*)227)); }

void TObjPlayer::spawn_ground_effect(s32 arg1) {
    s32 sp8;

    TObjBoss2Tunnel::adjust_to_ground((s32)this, &sp8);
    create_timed_particle_emitter((&sp8), 0xE5, 0, (arg1));
}

void TObjPlayer::spawn_effect_at_ground(s32 arg1) {
    s32 sp8;

    TObjBoss2Tunnel::adjust_to_ground((s32)this, &sp8);
    create_timed_particle_emitter(&sp8, 0xE4, 0, arg1);
}

extern const f32 lbl_805DA3C8;

void TObjPlayer::apply_effect_variant_a(s32 point, s32 delay) {
    TObjPlayer__sub_800D93F0(point, 0, delay, lbl_805DA3C8);
}

extern const f32 lbl_805DA3CC;

void TObjPlayer::apply_effect_variant_b(s32 point, s32 delay) {
    TObjPlayer__sub_800D93F0(point, 0, delay, lbl_805DA3CC);
}

extern const f32 lbl_805DA3C4;

void TObjPlayer__sub_800D9290(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 1, delay, lbl_805DA3C4);
}

void TObjPlayer__sub_800D92BC(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 1, delay, lbl_805DA3C8);
}

void TObjPlayer::spawn_dead_spot_default(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 1, delay, lbl_805DA3CC);
}

extern const f32 lbl_805DA3D0;

void TObjPlayer::spawn_dead_spot_here(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 1, delay, lbl_805DA3D0);
}
}

void spawn_landing_dead_spot(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 2, delay, lbl_805DA3C4);
}
extern "C" {

void TObjPlayer::spawn_dead_spot_type2(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 2, delay, lbl_805DA3C8);
}

void spawn_dead_spot_scale15(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 2, delay, lbl_805DA3CC);
}

void TObjPlayer__sub_800D93C4(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 2, delay, lbl_805DA3D0);
}

#define __nw__7TObjectFUl ((void * (*)(s32))__nw__7TObjectFUl)
s32 init_corner_vertices__9TDeadSpotFPv(void *, s32, s32, s32, s32, s32, f32);
s32 __ct__9TDeadSpotFv(void *, s32, s32, s32, s32, s32, f32);

extern void *player_corpse_mark_resource;

void TObjPlayer__sub_800D93F0(s32 point, s32 selector, s32 delay, f32 farg0) {
    void *obj = __nw__7TObjectFUl(0xCC);
    if (obj != NULL) {
        init_corner_vertices__9TDeadSpotFPv(obj, tl_05, point, *(s32 *)((s8 *)(*(void **)((s8 *)player_corpse_mark_resource + 0x42C)) + 0xC), selector, delay, farg0);
    }
}

void TObjPlayer::spawn_dead_spot(s32 point, s32 selector, s32 delay, f32 farg0) {
    void *obj = __nw__7TObjectFUl(0xC8);
    if (obj != NULL) {
        __ct__9TDeadSpotFv(obj, tl_05, point, *(s32 *)((s8 *)(*(void **)((s8 *)player_corpse_mark_resource + 0x42C)) + 0xC), selector, delay, farg0);
    }
}

#undef __nw__7TObjectFUl

extern const f32 lbl_805DA3D8;
extern s32 player_particle_effect_enabled;
extern u8 corpse_mark_resource_descriptor[];
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void TLobby__sub_8001FE7C(void*, int);
void set_chunk_material_override_pair(s32 arg0, s32 arg1);

void TObjPlayer::destroy_static_lobby() {
    if ((u32) (*(u32 *)&player_corpse_mark_resource) != 0U) {
        TLobby__sub_8001FE7C((void*)(*(u32 *)&player_corpse_mark_resource), 1);
        (*(u32 *)&player_corpse_mark_resource) = 0U;
    }
}
}
void set_chunk_blend(u32 x);
extern s32 model_render_flags;

void load_corpse_mark_resource(void) {
    u8 *p = (u8 *)::operator new(0x440);
    if (p != 0) {
        p = load_resource_from_descriptor(p, 1, corpse_mark_resource_descriptor, 0, 0, 0);
    }
    (*(u32 *)&player_corpse_mark_resource) = (u32)p;
    player_particle_effect_enabled = 1;
}
extern "C" {

s32 MaterialColorFade::has_visible_opacity() {
    return color.a > lbl_805DA3D8;
}

void MaterialColorFade::clear_flag_and_notify() {
    model_render_flags &= 0xFFFF77DF;
    set_chunk_material_override_pair(0xFF00, 0);
    set_chunk_blend(0x2500);
}


void MaterialColorFade::set_flags_and_apply_damage_color() {
    model_render_flags |= 0x8820;
    set_constant_material(&color);
    set_chunk_material_override_pair(0xFF00, 0x800);
}

extern const f32 lbl_805DA3DC;

s32 MaterialColorFade::advance_toward_max() {
    f32 temp_f1;
    s32 var_r0;

    temp_f1 = this->color.a;
    var_r0 = 0;
    if (temp_f1 < lbl_805DA3DC) {
        this->color.a = (f32) (temp_f1 + this->rate);
    } else {
        this->color.a = (f32) lbl_805DA3DC;
        var_r0 = 1;
    }
    return var_r0;
}

s32 MaterialColorFade::decay_value_toward_floor() {
    f32 temp_f1;
    s32 var_r0;

    temp_f1 = this->color.a;
    var_r0 = 0;
    if (temp_f1 > lbl_805DA3D8) {
        this->color.a = (f32) (temp_f1 - this->rate);
    } else {
        this->color.a = (f32) lbl_805DA3D8;
        var_r0 = 1;
    }
    return var_r0;
}

void MaterialColorFade::reset_obstruction_fade() {
    this->color.a = lbl_805DA3D8;
    this->color.r = lbl_805DA3DC;
    this->color.g = lbl_805DA3DC;
    this->color.b = lbl_805DA3DC;
}
}

extern "C" {
extern const f32 lbl_805DA3E4;

void MaterialColorFade::reset_color() {
    this->color.a = lbl_805DA3DC;
    this->color.r = lbl_805DA3DC;
    this->color.g = lbl_805DA3DC;
    this->color.b = lbl_805DA3DC;
}

extern const f32 lbl_805DA3E0;

void MaterialColorFade::set_rate_from_divisor(s32 arg1) {
    this->rate = (f32) (lbl_805DA3E0 / (f32) arg1);
}

MaterialColorFade::~MaterialColorFade() {}

MaterialColorFade::MaterialColorFade() {
    rate = lbl_805DA3E4;
    reset_color();
}
extern const f32 lbl_805DA3E8;

Vec *SampledMotionPoints::lookup(f32 frame) {
    f32 first = start;
    if ((frame < first) || (frame > end)) {
        return 0;
    }
    f32 sample_position = frame - first;
    sample_position += lbl_805DA3E8;
    sample_position /= step;
    s32 index = (s32)floor_to_float(sample_position);
    return points + points_per_sample * index;
}

}
