#include "types.h"
#include <stddef.h>
#include "pso/weapon/TUnk_804ECDC0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/NinjaTypes.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"


typedef struct SlicerLaunchData_8012D9C8 {
    u16 player; u16 pad;
    void *textures; void *model; u32 weapon;
    s16 kind, stage; f32 multiplier; f32 color[4];
    s32 facing, spin; f32 first[3], second[3];
} SlicerLaunchData_8012D9C8;

void init_slicer_launch_state(void *arg0);
extern "C" {
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
void get_weapon_color__11TItemWeaponFPv(f32 *, void *);
}

void TUnk_804ECDC0::emit_marker_effects() {
    f32 tmp[4];
    SlicerLaunchData_8012D9C8 launch;
    init_slicer_launch_state(&launch);
    launch.player = owner->get_entity_id();
    launch.weapon = this->get_item_id();
    launch.textures = *(void **)((s8 *)this + 0x24);
    launch.model = second_model;
    launch.kind = TObjPlayer__sub_801D2F4C((s16 *)((u8 *)owner + 0x7CC));
    launch.stage = owner->attack_state.get_validated_attack_stage();
    launch.multiplier = owner->query_extended_state();
    get_weapon_color__11TItemWeaponFPv(tmp, this);
    copy_argb((NJS_ARGB *)launch.color, (NJS_ARGB *)tmp);
    launch.facing = *(s32 *)((s8 *)owner + 0x60);
    this->get_joint_position(0x2, launch.first);
    this->get_joint_position(0x1, launch.second);
    TTecSlicer::create((u16*)&launch);
}

TUnk_804ECDC0::~TUnk_804ECDC0() {}

TUnk_804ECDC0::TUnk_804ECDC0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
}

TItem *TObjPlayer__sub_803265C0(u8 *item) {
    if (item != NULL) {
        return new TUnk_804ECDC0(tl_05, item);
    }
    return NULL;
}
