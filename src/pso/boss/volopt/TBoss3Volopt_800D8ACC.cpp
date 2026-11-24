#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer_800EDB98.h"
#include "pso/system/vector.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/map/FloorArea.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/TDeadSpot.h"
#include "pso/unk/TUnk_804949D8.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/TBreakUpMdl.h"

const char *bm_ene_common_all_model_names[2] = { "ene_common_all.nj", NULL };
const char *bm_ene_common_all_motion_names[1] = { NULL };
BmlResourceDescriptor corpse_mark_resource_descriptor = { "bm_ene_common_all.bml", bm_ene_common_all_model_names, bm_ene_common_all_motion_names, 1, 0 };
BmlResource *player_corpse_mark_resource;
s32 player_particle_effect_enabled;

void TBoss3Volopt::create_breakup_mdl(TBreakUpMdlData *model, const BreakUpParamRow *params, NJS_TEXLIST *texlist,
                                    const Vec *position, s32 rotation_y) {
    new TBreakUpMdl(tl_05, model, const_cast<BreakUpParamRow *>(params), texlist,
                    const_cast<Vec *>(position), rotation_y);
}
void play_area_variant_sound(Vec *position) {
    s32 area;
    area = get_current_floor_area();
    switch (area) {
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x3AB3C, position, 0, 0);
        return;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4003AD32, position, 0, 0);
        return;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4003B22A, position, 0, 0);
        return;
    case AREA_TOWER:
        play_sound_effect(0x4003A35A, position, 0, 0);
        return;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x3AD43, position, 0, 0);
        return;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4003AD3F, position, 0, 0);
        return;
    default:
        play_sound_effect((int) (::remap_area_sound_id(0x4003AD06, 0x1E)), position, 0, 0);
        return;
    }
}

void play_area_se_with_particle(Vec *position) {
    Vec v;
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x3AB3C, position, 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4003AD32, position, 0, 0);
        break;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4003B22A, position, 0, 0);
        break;
    case AREA_TOWER:
        play_sound_effect(0x4003A35A, position, 0, 0);
        break;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x3AD43, position, 0, 0);
        break;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4003AD3F, position, 0, 0);
        break;
    default:
        play_sound_effect(::remap_area_sound_id(0x4003AD06, 0x1E), position, 0, 0);
        break;
    }
    VecCopy(&v, position);
    v.y += 30.0f;
    spawn_particle_effect(&v, 0xE6);
}
extern "C" {

void TBoss3Volopt__sub_800D8D88(saddr position) {
    const Vec *sound_position = reinterpret_cast<const Vec *>(position);
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x3AB3C, sound_position, 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4003AB31, sound_position, 0, 0);
        break;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4003B22A, sound_position, 0, 0);
        break;
    case AREA_TOWER:
        play_sound_effect(0x4003A359, sound_position, 0, 0);
        break;
    default:
        play_sound_effect(TBoss3Volopt::remap_area_sound_id(0x4003AB20), sound_position, 0, 0);
        break;
    }
    spawn_particles_at__12TBoss3VoloptFi(position);
}

}
void play_area_sound_effect(Vec *position) {
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x3AB3C, position, 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4003AB31, position, 0, 0);
        break;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4003B22A, position, 0, 0);
        break;
    case AREA_TOWER:
        play_sound_effect(0x4003A359, position, 0, 0);
        break;
    default:
        play_sound_effect(TBoss3Volopt::remap_area_sound_id(0x4003AB37), position, 0, 0);
        break;
    }
    spawn_particles_at__12TBoss3VoloptFi((saddr)position);
}
extern "C" {

void spawn_particles_at__12TBoss3VoloptFi(saddr position) {
    Vec pos;
    VecCopy(&pos, (const Vec *)position);
    create_timed_particle_emitter((void *)position, 0xEA, 0xA, 0x1E);
    pos.y += 30.0f;
    spawn_particle_effect(&pos, 0xE9);
}

}

void create_dead_spot(Vec *pos, s32 duration, f32 radius) {
    new TUnk_804949F4((TObject *)tl_05, pos, create_timed_particle_emitter(pos, 0xF8, 0, duration), radius);
}

void spawn_effect_f8(Vec *pos, s32 duration) {
    create_timed_particle_emitter(pos, 0xF8, 0, duration);
}

void create_dead_spot_e4(Vec *pos, s32 duration, f32 radius) {
    create_dead_spot(pos, 0xE4, duration, radius);
}

void create_dead_spot(Vec *pos, s32 particle, s32 duration, f32 radius) {
    new TUnk_804949D8((TObject *)tl_05, pos, create_timed_particle_emitter(pos, particle, 0, duration), radius);
}

extern "C" {

void fn_800D911C(Vec *position) {
    create_timed_particle_emitter(position, 232, 10, 1);
    create_timed_particle_emitter(position, 236, 10, 1);
}

}

void trigger_dell_biter_events(const Vec *pos) { spawn_particle_effect(pos, 251); spawn_particle_effect(pos, 252); spawn_particle_effect(pos, 227); }

void spawn_ground_effect(const Vec *pos, s32 duration) {
    Vec ground;

    TObjBoss2Tunnel::adjust_to_ground(pos, &ground);
    create_timed_particle_emitter(&ground, 0xE5, 0, duration);
}

void spawn_effect_at_ground(const Vec *pos, s32 duration) {
    Vec ground;

    TObjBoss2Tunnel::adjust_to_ground(pos, &ground);
    create_timed_particle_emitter(&ground, 0xE4, 0, duration);
}

// Dead-stripped from the DOL: the selector-0 corner dead spots come in the same
// 2.5/7.5/15/25 scale set as the selector-1 and selector-2 families below, and
// only the 7.5 and 15 wrappers survive. The two missing ones left their literals:
// .sdata2 pools 2.5f ahead of 7.5f/15.0f and 25.0f after them (0x805DA3C4-D0),
// which first use by the surviving code cannot give. Bodies and names inferred
// from the family.
void spawn_corner_dead_spot_scale2_5(const Vec *point, s32 delay) {
    TObjPlayer__sub_800D93F0(point, 0, delay, 2.5f);
}
extern "C" {

void TObjPlayer::apply_effect_variant_a(const Vec *point, s32 delay) {
    TObjPlayer__sub_800D93F0(point, 0, delay, 7.5f);
}

void TObjPlayer::apply_effect_variant_b(const Vec *point, s32 delay) {
    TObjPlayer__sub_800D93F0(point, 0, delay, 15.0f);
}

// Dead-stripped, see spawn_corner_dead_spot_scale2_5.
}
void spawn_corner_dead_spot_scale25(const Vec *point, s32 delay) {
    TObjPlayer__sub_800D93F0(point, 0, delay, 25.0f);
}
extern "C" {

void TObjPlayer__sub_800D9290(const Vec *point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 1, delay, 2.5f);
}

void TObjPlayer__sub_800D92BC(const Vec *point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 1, delay, 7.5f);
}

void TObjPlayer::spawn_dead_spot_default(const Vec *point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 1, delay, 15.0f);
}

void TObjPlayer::spawn_dead_spot_here(const Vec *point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 1, delay, 25.0f);
}
}

void spawn_landing_dead_spot(const Vec *point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 2, delay, 2.5f);
}
extern "C" {

void TObjPlayer::spawn_dead_spot_type2(const Vec *point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 2, delay, 7.5f);
}

void spawn_dead_spot_scale15(const Vec *point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 2, delay, 15.0f);
}

void TObjPlayer__sub_800D93C4(const Vec *point, s32 delay) {
    TObjPlayer::spawn_dead_spot(point, 2, delay, 25.0f);
}



void TObjPlayer__sub_800D93F0(const Vec *point, s32 selector, s32 delay, f32 maxScale) {
    new TUnk_80494A10(tl_05, point, player_corpse_mark_resource->models[0].texlist, selector, delay, maxScale);
}

void TObjPlayer::spawn_dead_spot(const Vec *point, s32 selector, s32 delay, f32 maxScale) {
    new TDeadSpot(tl_05, point, player_corpse_mark_resource->models[0].texlist, selector, delay, maxScale);
}


void TObjPlayer::destroy_static_lobby() {
    if (player_corpse_mark_resource != NULL) {
        delete player_corpse_mark_resource;
        player_corpse_mark_resource = NULL;
    }
}
}

void load_corpse_mark_resource(void) {
    player_corpse_mark_resource = new BmlResource(1, &corpse_mark_resource_descriptor, 0, 0, NULL);
    player_particle_effect_enabled = 1;
}
