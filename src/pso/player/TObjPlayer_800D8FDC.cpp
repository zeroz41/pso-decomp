#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/misc/TDeadSpot.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/memory.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

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

void TObjPlayer::request_two_effects() { create_timed_particle_emitter(this, (s32)((void*)232), (s32)((void*)10), (s32)((void*)1)); create_timed_particle_emitter(this, (s32)((void*)236), (s32)((void*)10), (s32)((void*)1)); }

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
    u8 *p = (u8 *)((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
    if (p != 0) {
        p = load_resource_from_descriptor(p, 1, corpse_mark_resource_descriptor, 0, 0, 0);
    }
    (*(u32 *)&player_corpse_mark_resource) = (u32)p;
    player_particle_effect_enabled = 1;
}
extern "C" {

s32 TUnk_80494AE0::vfunc_10() {
    f32 *arg0 = (f32 *)this;
    return *arg0 > lbl_805DA3D8;
}

void TUnk_80494AE0::clear_flag_and_notify() {
    model_render_flags &= 0xFFFF77DF;
    set_chunk_material_override_pair(0xFF00, 0);
    set_chunk_blend(0x2500);
}


void TObjPlayer::set_flags_and_apply_damage_color() {
    model_render_flags |= 0x8820;
    ((void (*)(void))set_constant_material)();
    set_chunk_material_override_pair(0xFF00, 0x800);
}

extern const f32 lbl_805DA3DC;

s32 TUnk_80494AE0::advance_toward_max() {
    f32 temp_f1;
    s32 var_r0;

    temp_f1 = *(f32 *)&this->unk_0;
    var_r0 = 0;
    if (temp_f1 < lbl_805DA3DC) {
        *(f32 *)&this->unk_0 = (f32) (temp_f1 + *(f32 *)&this->unk_10);
    } else {
        *(f32 *)&this->unk_0 = (f32) lbl_805DA3DC;
        var_r0 = 1;
    }
    return var_r0;
}

s32 TUnk_80494AE0::decay_value_toward_floor() {
    f32 temp_f1;
    s32 var_r0;

    temp_f1 = *(f32 *)&this->unk_0;
    var_r0 = 0;
    if (temp_f1 > lbl_805DA3D8) {
        *(f32 *)&this->unk_0 = (f32) (temp_f1 - *(f32 *)&this->unk_10);
    } else {
        *(f32 *)&this->unk_0 = (f32) lbl_805DA3D8;
        var_r0 = 1;
    }
    return var_r0;
}

void TUnk_80494AE0::reset_obstruction_fade() { *(float *)&this->unk_0 = lbl_805DA3D8; this->m_4 = lbl_805DA3DC; *(float *)&this->unk_8 = lbl_805DA3DC; this->m_c = lbl_805DA3DC; }
}

struct Raw_800D9718 { u8 pad[0x10]; f32 f10; s32 *vt; };

struct B_800D9718 { u8 pad[0x14]; };

struct V_800D9718 : B_800D9718 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

extern "C" {
extern s32 lbl_80494AE0[];
extern const f32 lbl_805DA3E4;
V_800D9718 *TObjPlayer__sub_800D9718(V_800D9718 *self);
f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32, f32);

void TUnk_80494AE0::vfunc_4() { *(float *)&this->unk_0 = lbl_805DA3DC; this->m_4 = lbl_805DA3DC; *(float *)&this->unk_8 = lbl_805DA3DC; this->m_c = lbl_805DA3DC; }

extern const f32 lbl_805DA3E0;

void TUnk_80494AE0::set_rate_from_divisor(s32 arg1) {
    *(f32 *)&this->unk_10 = (f32) (lbl_805DA3E0 / (f32) arg1);
}

void *__dt__13TUnk_80494AE0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x14) = lbl_80494AE0;
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

extern const f32 lbl_805DA3E8;

V_800D9718 *TObjPlayer__sub_800D9718(V_800D9718 *self) {
    ((Raw_800D9718 *)self)->vt = ((s32 *)&lbl_80494AE0);
    ((Raw_800D9718 *)self)->f10 = lbl_805DA3E4;
    self->m2();
    return self;
}

s32 TObjPlayer::lookup_entry_by_value(void *arg0, f32 farg0) {
    void *var_r31;
    f32 temp_f2;
    f32 temp_f_sda;
    s32 temp_r4;
    s32 temp_r0;
    s32 temp_r3;

    var_r31 = arg0;
    temp_f2 = *(f32 *)((s8 *)var_r31 + 0xC);
    if ((farg0 < temp_f2) || (farg0 > *(f32 *)((s8 *)var_r31 + 0x10))) {
        return 0;
    }
    temp_f_sda = lbl_805DA3E8;
    {
        f32 temp_sub = farg0 - temp_f2;
        temp_r4 = (s32) get_random_float__21TObjEneMe3ShinowaRealFv((temp_sub + lbl_805DA3E8) / *(f32 *)((s8 *)var_r31 + 0x14), lbl_805DA3E8);
    }
    temp_r0 = *(s32 *)((s8 *)var_r31 + 0x4);
    temp_r3 = *(s32 *)((s8 *)var_r31 + 0x0);
    return temp_r3 + temp_r0 * temp_r4 * 0xC;
}

}
