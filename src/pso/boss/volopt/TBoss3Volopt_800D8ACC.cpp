#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/enemy/AreaSoundRemap.h"
#include "pso/system/vector.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/map/FloorArea.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/TDeadSpot.h"
#include "pso/unk/TDeadSpotGroundEmitter.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/effect/TAttackTrace.h"

const char *bm_ene_common_all_model_names[2] = { "ene_common_all.nj", NULL };
const char *bm_ene_common_all_motion_names[1] = { NULL };
BmlResourceDescriptor corpse_mark_resource_descriptor = { "bm_ene_common_all.bml", bm_ene_common_all_model_names, bm_ene_common_all_motion_names, 1, 0 };
BmlResource *TDeadSpot::corpse_mark_resource;
s32 player_particle_effect_enabled;

void toggle_particle_effect() {
    if (player_particle_effect_enabled != 0) {
        end_effect_render();
        return;
    }
    begin_effect_render();
}

void disable_player_particle_effect(void) { player_particle_effect_enabled = 0; }

void enable_player_particle_effect(void) { player_particle_effect_enabled = 1; }

TAttackTraceStrip *TAttackTraceStrip::create(u32 color_a, u32 color_b) {
    return new TAttackTraceStrip(tl_05, color_a, color_b);
}

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

void play_appear_effects(Vec *position) {
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
        play_sound_effect(remap_area_sound_id(0x4003AB20), position, 0, 0);
        break;
    }
    spawn_particles_at(position);
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
        play_sound_effect(remap_area_sound_id(0x4003AB37), position, 0, 0);
        break;
    }
    spawn_particles_at(position);
}

void spawn_particles_at(Vec *position) {
    Vec pos;
    VecCopy(&pos, position);
    create_timed_particle_emitter(position, 0xEA, 0xA, 0x1E);
    pos.y += 30.0f;
    spawn_particle_effect(&pos, 0xE9);
}

void create_dead_spot(Vec *pos, s32 duration, f32 radius) {
    new TDeadSpotEmitter((TObject *)tl_05, pos, create_timed_particle_emitter(pos, 0xF8, 0, duration), radius);
}

void spawn_effect_f8(Vec *pos, s32 duration) {
    create_timed_particle_emitter(pos, 0xF8, 0, duration);
}

void create_dead_spot_e4(Vec *pos, s32 duration, f32 radius) {
    create_dead_spot(pos, 0xE4, duration, radius);
}

void create_dead_spot(Vec *pos, s32 particle, s32 duration, f32 radius) {
    new TDeadSpotGroundEmitter((TObject *)tl_05, pos, create_timed_particle_emitter(pos, particle, 0, duration), radius);
}


void create_particle_emitter_pair(Vec *position) {
    create_timed_particle_emitter(position, 232, 10, 1);
    create_timed_particle_emitter(position, 236, 10, 1);
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
// .sdata2 pools 2.5f ahead of 7.5f/15.0f and 25.0f after them,
// which first use by the surviving code cannot give. Bodies and names inferred
// from the family.
void spawn_dead_spot_kind0_scale2_5(const Vec *point, s32 delay) {
    spawn_dead_spot_fade(point, 0, delay, 2.5f);
}
void spawn_dead_spot_kind0_scale7_5(const Vec *point, s32 delay) {
    spawn_dead_spot_fade(point, 0, delay, 7.5f);
}

void spawn_dead_spot_kind0_scale15(const Vec *point, s32 delay) {
    spawn_dead_spot_fade(point, 0, delay, 15.0f);
}

// Dead-stripped, see spawn_dead_spot_kind0_scale2_5.
void spawn_dead_spot_kind0_scale25(const Vec *point, s32 delay) {
    spawn_dead_spot_fade(point, 0, delay, 25.0f);
}
void spawn_dead_spot_kind1_scale2_5(const Vec *point, s32 delay) {
    TDeadSpot::spawn(point, 1, delay, 2.5f);
}

void spawn_dead_spot_kind1_scale7_5(const Vec *point, s32 delay) {
    TDeadSpot::spawn(point, 1, delay, 7.5f);
}

void spawn_dead_spot_kind1_scale15(const Vec *point, s32 delay) {
    TDeadSpot::spawn(point, 1, delay, 15.0f);
}

void spawn_dead_spot_kind1_scale25(const Vec *point, s32 delay) {
    TDeadSpot::spawn(point, 1, delay, 25.0f);
}

void spawn_dead_spot_kind2_scale2_5(const Vec *point, s32 delay) {
    TDeadSpot::spawn(point, 2, delay, 2.5f);
}

void spawn_dead_spot_kind2_scale7_5(const Vec *point, s32 delay) {
    TDeadSpot::spawn(point, 2, delay, 7.5f);
}

void spawn_dead_spot_kind2_scale15(const Vec *point, s32 delay) {
    TDeadSpot::spawn(point, 2, delay, 15.0f);
}

void spawn_dead_spot_kind2_scale25(const Vec *point, s32 delay) {
    TDeadSpot::spawn(point, 2, delay, 25.0f);
}



void spawn_dead_spot_fade(const Vec *point, s32 selector, s32 delay, f32 maxScale) {
    new TDeadSpotFade(tl_05, point, TDeadSpot::corpse_mark_resource->models[0].texlist, selector, delay, maxScale);
}

void TDeadSpot::spawn(const Vec *point, s32 selector, s32 delay, f32 maxScale) {
    new TDeadSpot(tl_05, point, corpse_mark_resource->models[0].texlist, selector, delay, maxScale);
}


void TDeadSpot::free_resource() {
    if (corpse_mark_resource != NULL) {
        delete corpse_mark_resource;
        corpse_mark_resource = NULL;
    }
}

void TDeadSpot::load_resource() {
    corpse_mark_resource = new BmlResource(1, &corpse_mark_resource_descriptor, 0, 0, NULL);
    player_particle_effect_enabled = 1;
}
