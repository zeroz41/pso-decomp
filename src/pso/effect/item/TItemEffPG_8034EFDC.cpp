#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/NinjaTypes.h"
#include "pso/weapon/TItemWeapon.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804F0A00.h"
#include "pso/weapon/TUnk_804F0AF8.h"
#include "pso/weapon/TUnk_804F0908.h"
#include "pso/weapon/TUnk_804F0810.h"
#include "pso/player/TUnk_804A2548.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/item/TUnk_804F0BF0.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/render_util.h"
#include "pso/effect/item/TUnk_804F0C08.h"
#include "pso/effect/item/TItemEffPG.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/unk/text_80120908.h"


struct P_8034F020 { u8 pad0[0x1F8]; s32 f1F8; };

typedef struct SlicerLaunchData_8012D9C8 {
    u16 player; u16 pad;
    void *textures; void *model; u32 weapon;
    s16 kind, stage; f32 multiplier; f32 color[4];
    s32 facing, spin; f32 first[3], second[3];
} SlicerLaunchData_8012D9C8;

void init_slicer_launch_state(void *arg0);
extern "C" {
s32 rotate_matrix_z(s32, s32);
u16 get_entity_id(void *);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
s16 get_validated_attack_stage(u8 *arg0);
void get_weapon_color__11TItemWeaponFPv(f32 *, void *);
void *find_entity_by_id(s32);
}

// Rappy's fan (TUnk_804F0908) and the TUnk_804F0810 weapon: its own TU, since its
// 2.0f literal at 0x805DFDF8 is followed by a 4-byte pad before the next pool.
// Built with -inline off,deferred like TItemEffPG.cpp: functions are written last to first.

TItem *TObjPlayer::create_rappys_fan(u8 *item) {
    if (item != NULL) {
        return new TUnk_804F0908(tl_05, item);
    }
    return NULL;
}

TUnk_804F0908::TUnk_804F0908(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    hit_callback = (WeaponHitCallback)TObjPlayer::spawn_particle_at_entity_slot;
    set_weapon_flags(2);
}

TUnk_804F0908::~TUnk_804F0908() {}

void TUnk_804F0908::emit_marker_effects() {
    f32 tmp[4];
    SlicerLaunchData_8012D9C8 launch;
    u8 *t;
    init_slicer_launch_state(&launch);
    launch.player = get_entity_id(*(u8 **)&owner);
    launch.weapon = get_item_id();
    launch.textures = *(void **)((s8 *)this + 0x24);
    launch.model = *(void **)((s8 *)this + 0x188);
    launch.kind = TObjPlayer__sub_801D2F4C((s16 *)(*(u8 **)&owner + 0x7CC));
    launch.stage = get_validated_attack_stage(*(u8 **)&owner + 0x7CC);
    launch.multiplier = ((TObjPlayer *)(*(u8 **)&owner))->query_extended_state();
    get_weapon_color__11TItemWeaponFPv(tmp, this);
    copy_argb((NJS_ARGB *)launch.color, (NJS_ARGB *)tmp);
    launch.facing = *(s32 *)((s8 *)(*(u8 **)&owner) + 0x60);
    launch.spin = 0;
    get_joint_position(3, launch.first);
    get_joint_position(2, launch.second);
    t = ((u8 *)TTecSlicer::create((u16*)&launch));
    if (t != NULL) {
        *(s32 *)((s8 *)t + 0x5C) += 0x4000;
        *(f32 *)((s8 *)t + 0x68) = 2.0f;
        *(f32 *)((s8 *)t + 0x6C) = 2.0f;
        *(f32 *)((s8 *)t + 0x70) = 2.0f;
        *(s32 *)((s8 *)t + 0x13C) = 0;
    }
}

void TObjPlayer::spawn_particle_at_entity_slot(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    TObjCollidable *entity = static_cast<TObjCollidable *>(find_entity_by_id(arg2));
    if (entity != NULL) {
        CollisionBody *bodies = entity->bodies;
        if (bodies != NULL && arg3 < entity->body_count) {
            spawn_particle_effect(&bodies[arg3].center, 0x1BF);
        }
    }
}

TItem *TObjPlayer__sub_8034F1AC(u8 *item) {
    if (item != NULL) {
        return new TUnk_804F0810(tl_05, item);
    }
    return NULL;
}

TUnk_804F0810::TUnk_804F0810(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1);
    unk_1F8 = 13653;
}

TUnk_804F0810::~TUnk_804F0810() {}

void TUnk_804F0810::update_attack() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (saddr)((void*)(-4551)), (saddr)((void*)(0))); }
void TUnk_804F0810::update_idle() { TObjPlayer::add_angle_clamped((s32 *)((char*)this + 0x1f8), (saddr)((void*)(1820)), (saddr)((void*)(13653))); }
void TUnk_804F0810::reserved_53() { draw_weapon_at_joint((saddr)this, 49); update_trail_slot(0); update_trail_slot(1); }

void TUnk_804F0810::vfunc_60() {
    switch (TObjPlayer::get_player_list()) {
    case 1:
        ((s32)rotate_matrix_z(0, (s32)(((P_8034F020 *)this)->f1F8)));
        break;
    }
}

void TUnk_804F0810::emit_marker_effects() {
    Vec joint_samples[2];
    owner->get_anim_node_position(0x30, joint_samples);
    spawn_particle_effect(&joint_samples[0], 0x1D0);
}
