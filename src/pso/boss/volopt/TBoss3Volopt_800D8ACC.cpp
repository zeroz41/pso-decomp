#include "types.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer_800EDB98.h"
#include "pso/system/vector.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/map/FloorArea.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
#include "pso/unk/text_80087278.h"
#include "pso/object/TDeadSpot.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"

const char *bm_ene_common_all_model_names[2] = { "ene_common_all.nj", NULL };
const char *bm_ene_common_all_motion_names[1] = { NULL };
BmlResourceDescriptor corpse_mark_resource_descriptor = { "bm_ene_common_all.bml", bm_ene_common_all_model_names, bm_ene_common_all_motion_names, 1, 0 };
void *player_corpse_mark_resource;
s32 player_particle_effect_enabled;

extern "C" {
s32 TBreakUpMdl__ct(void*, s32, s32, s32, s32, s32, s32);
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void free_bin_model_request(void*, int);

extern s32 tl_05;

void TBoss3Volopt::create_breakup_mdl(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void* obj = TObject::operator new(0x54);
    if (obj != 0) {
        TBreakUpMdl__ct(obj, tl_05, arg0, arg1, arg2, arg3, arg4);
    }
}

void TBoss3Volopt::play_area_variant_sound() {
    s32 arg0 = (s32)this;
    s32 area;
    area = get_current_floor_area();
    switch (area) {
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x3AB3C, (void *)arg0, 0, 0);
        return;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4003AD32, (void *)arg0, 0, 0);
        return;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4003B22A, (void *)arg0, 0, 0);
        return;
    case AREA_TOWER:
        play_sound_effect(0x4003A35A, (void *)arg0, 0, 0);
        return;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x3AD43, (void *)arg0, 0, 0);
        return;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4003AD3F, (void *)arg0, 0, 0);
        return;
    default:
        play_sound_effect((int) (::remap_area_sound_id(0x4003AD06, 0x1E)), (void *)arg0, 0, 0);
        return;
    }
}

void TBoss3Volopt::play_area_se_with_particle() {
    s32 arg0 = (s32)this;
    Vec v;
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x3AB3C, (void *)arg0, 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4003AD32, (void *)arg0, 0, 0);
        break;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4003B22A, (void *)arg0, 0, 0);
        break;
    case AREA_TOWER:
        play_sound_effect(0x4003A35A, (void *)arg0, 0, 0);
        break;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x3AD43, (void *)arg0, 0, 0);
        break;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4003AD3F, (void *)arg0, 0, 0);
        break;
    default:
        play_sound_effect(::remap_area_sound_id(0x4003AD06, 0x1E), (void *)arg0, 0, 0);
        break;
    }
    VecCopy(&v, (const Vec *)arg0);
    v.y += 30.0f;
    spawn_particle_effect(&v, 0xE6);
}

void TBoss3Volopt__sub_800D8D88(s32 arg0) {
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x3AB3C, (void *)arg0, 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4003AB31, (void *)arg0, 0, 0);
        break;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4003B22A, (void *)arg0, 0, 0);
        break;
    case AREA_TOWER:
        play_sound_effect(0x4003A359, (void *)arg0, 0, 0);
        break;
    default:
        play_sound_effect(TBoss3Volopt::remap_area_sound_id(0x4003AB20), (void *)arg0, 0, 0);
        break;
    }
    spawn_particles_at__12TBoss3VoloptFi(arg0);
}

void TBoss3Volopt::play_area_sound_effect() {
    s32 arg0 = (s32)this;
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x3AB3C, (void *)arg0, 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4003AB31, (void *)arg0, 0, 0);
        break;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4003B22A, (void *)arg0, 0, 0);
        break;
    case AREA_TOWER:
        play_sound_effect(0x4003A359, (void *)arg0, 0, 0);
        break;
    default:
        play_sound_effect(TBoss3Volopt::remap_area_sound_id(0x4003AB37), (void *)arg0, 0, 0);
        break;
    }
    spawn_particles_at__12TBoss3VoloptFi(arg0);
}

void spawn_particles_at__12TBoss3VoloptFi(s32 arg0) {
    Vec pos;
    VecCopy(&pos, (const Vec *)arg0);
    create_timed_particle_emitter((void *)arg0, 0xEA, 0xA, 0x1E);
    pos.y += 30.0f;
    spawn_particle_effect(&pos, 0xE9);
}

#define create_dead_spot__10TObjPlayerFiiif ((s32 (*)(s32, s32, s32))create_dead_spot__10TObjPlayerFiiif)

void TObjPlayer::create_dead_spot(s32 arg0, s32 arg1, f32 farg0) {
    s32 temp_r3;

    temp_r3 = (s32)TObject::operator new(0x38);
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



void create_dead_spot__10TObjPlayerFiiif(s32 arg0, s32 arg1, s32 arg2, f32 farg0) {
    s32 temp_r3;

    temp_r3 = (s32)TObject::operator new(0x38);
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

// Dead-stripped from the DOL: the selector-0 corner dead spots come in the same
// 2.5/7.5/15/25 scale set as the selector-1 and selector-2 families below, and
// only the 7.5 and 15 wrappers survive. The two missing ones left their literals:
// .sdata2 pools 2.5f ahead of 7.5f/15.0f and 25.0f after them (0x805DA3C4-D0),
// which first use by the surviving code cannot give. Bodies and names inferred
// from the family.
void spawn_corner_dead_spot_scale2_5(s32 point, s32 delay) {
    TObjPlayer__sub_800D93F0(point, 0, delay, 2.5f);
}

void TObjPlayer::apply_effect_variant_a(s32 point, s32 delay) {
    TObjPlayer__sub_800D93F0(point, 0, delay, 7.5f);
}

void TObjPlayer::apply_effect_variant_b(s32 point, s32 delay) {
    TObjPlayer__sub_800D93F0(point, 0, delay, 15.0f);
}

// Dead-stripped, see spawn_corner_dead_spot_scale2_5.
void spawn_corner_dead_spot_scale25(s32 point, s32 delay) {
    TObjPlayer__sub_800D93F0(point, 0, delay, 25.0f);
}

void TObjPlayer__sub_800D9290(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 1, delay, 2.5f);
}

void TObjPlayer__sub_800D92BC(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 1, delay, 7.5f);
}

void TObjPlayer::spawn_dead_spot_default(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 1, delay, 15.0f);
}

void TObjPlayer::spawn_dead_spot_here(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 1, delay, 25.0f);
}
}

void spawn_landing_dead_spot(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 2, delay, 2.5f);
}
extern "C" {

void TObjPlayer::spawn_dead_spot_type2(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 2, delay, 7.5f);
}

void spawn_dead_spot_scale15(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 2, delay, 15.0f);
}

void TObjPlayer__sub_800D93C4(s32 point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 2, delay, 25.0f);
}

s32 init_corner_vertices__9TDeadSpotFPv(void *, s32, s32, s32, s32, s32, f32);
s32 __ct__9TDeadSpotFv(void *, s32, s32, s32, s32, s32, f32);


void TObjPlayer__sub_800D93F0(s32 point, s32 selector, s32 delay, f32 farg0) {
    void *obj = TObject::operator new(0xCC);
    if (obj != NULL) {
        init_corner_vertices__9TDeadSpotFPv(obj, tl_05, point, *(s32 *)((s8 *)(*(void **)((s8 *)player_corpse_mark_resource + 0x42C)) + 0xC), selector, delay, farg0);
    }
}

void TObjPlayer::spawn_dead_spot(s32 point, s32 selector, s32 delay, f32 farg0) {
    void *obj = TObject::operator new(0xC8);
    if (obj != NULL) {
        __ct__9TDeadSpotFv(obj, tl_05, point, *(s32 *)((s8 *)(*(void **)((s8 *)player_corpse_mark_resource + 0x42C)) + 0xC), selector, delay, farg0);
    }
}



void TObjPlayer::destroy_static_lobby() {
    if ((u32) (*(u32 *)&player_corpse_mark_resource) != 0U) {
        free_bin_model_request((void*)(*(u32 *)&player_corpse_mark_resource), 1);
        (*(u32 *)&player_corpse_mark_resource) = 0U;
    }
}
}

void load_corpse_mark_resource(void) {
    u8 *p = (u8 *)::operator new(0x440);
    if (p != 0) {
        p = load_resource_from_descriptor(p, 1, &corpse_mark_resource_descriptor, 0, 0, 0);
    }
    (*(u32 *)&player_corpse_mark_resource) = (u32)p;
    player_particle_effect_enabled = 1;
}
