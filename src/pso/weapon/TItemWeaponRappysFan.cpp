#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/math/ClampedStep.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/NinjaTypes.h"
#include "pso/weapon/TItemWeapon.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeaponGiGueBazooka.h"
#include "pso/weapon/TItemWeaponNeisClaw.h"
#include "pso/weapon/TItemWeaponRappysFan.h"
#include "pso/weapon/TItemWeaponRikasClaw.h"
#include "pso/weapon/TExplosionCollider.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/effect/item/TItemEffPG.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/SoundEffect.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/render_util.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/item/TItemAttackColBase.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/unk/text_80120908.h"
#include "pso/object/base/TObjBase.h"
#include "pso/system/MatrixOps.h"


#define SLICER_LAUNCH_STATE_OUT_OF_LINE
#include "pso/weapon/SlicerLaunchState.h"

extern "C" {
void get_weapon_color__11TItemWeaponFv(f32 *, void *);
void *find_entity_by_id(s32);
}

// Rappy's fan (TItemWeaponRappysFan) and the TItemWeaponRikasClaw weapon: its own TU, since its
// 2.0f literal at 0x805DFDF8 is followed by a 4-byte pad before the next pool.
// Built with -inline off,deferred like TItemEffPG.cpp: functions are written last to first.

TItem *TItemWeaponRappysFan::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponRappysFan(tl_05, item);
    }
    return NULL;
}

TItemWeaponRappysFan::TItemWeaponRappysFan(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    hit_callback = (WeaponHitCallback)TObjPlayer::spawn_particle_at_entity_slot;
    set_weapon_flags(2);
}

TItemWeaponRappysFan::~TItemWeaponRappysFan() {}

void TItemWeaponRappysFan::emit_marker_effects() {
    f32 color_tmp[4];
    SlicerLaunchState launch;
    TTecSlicer *slicer;
    init_slicer_launch_state(&launch);
    launch.player_id = owner->get_entity_id();
    launch.item_id = get_item_id();
    launch.texlist = texlist;
    launch.model = second_model;
    launch.attack_kind = owner->attack_state.get_validated_attack_kind();
    launch.combo_stage = owner->attack_state.get_validated_attack_stage();
    launch.damage_multiplier = owner->query_extended_state();
    get_weapon_color__11TItemWeaponFv(color_tmp, this);
    copy_argb(&launch.color, (NJS_ARGB *)color_tmp);
    launch.facing = owner->rotation_y;
    launch.spin_velocity = 0;
    get_joint_position(3, &launch.first_joint);
    get_joint_position(2, &launch.second_joint);
    slicer = TTecSlicer::create(&launch);
    if (slicer != NULL) {
        slicer->rotation_x += 0x4000;
        slicer->scale.x = 2.0f;
        slicer->scale.y = 2.0f;
        slicer->scale.z = 2.0f;
        slicer->useColorOverride = 0;
    }
}

void TObjPlayer::spawn_particle_at_entity_slot(s32 layer, s32 weapon, s32 id, s32 body) {
    TObjCollidable *entity = static_cast<TObjCollidable *>(find_entity_by_id(id));
    if (entity != NULL) {
        CollisionBody *bodies = entity->bodies;
        if (bodies != NULL && body < entity->body_count) {
            spawn_particle_effect(&bodies[body].center, 0x1BF);
        }
    }
}

TItem *TItemWeaponRikasClaw::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponRikasClaw(tl_05, item);
    }
    return NULL;
}

TItemWeaponRikasClaw::TItemWeaponRikasClaw(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1);
    spin_angle = 13653;
}

TItemWeaponRikasClaw::~TItemWeaponRikasClaw() {}

void TItemWeaponRikasClaw::update_attack() { add_angle_clamped(&spin_angle, -4551, 0); }
void TItemWeaponRikasClaw::update_idle() { add_angle_clamped(&spin_angle, 1820, 13653); }
void TItemWeaponRikasClaw::draw_held_model() { draw_weapon_at_joint((saddr)this, 49); update_trail_slot(0); update_trail_slot(1); }

void TItemWeaponRikasClaw::transform_model_node() {
    switch (TObjPlayer::get_player_list()) {
    case 1:
        rotate_matrix_z(0, spin_angle);
        break;
    }
}

void TItemWeaponRikasClaw::emit_marker_effects() {
    Vec joint_samples[2];
    owner->get_anim_node_position(0x30, joint_samples);
    spawn_particle_effect(&joint_samples[0], 0x1D0);
}
