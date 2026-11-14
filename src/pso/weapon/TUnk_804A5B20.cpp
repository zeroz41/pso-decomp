#include "types.h"
#include "pso/weapon/TUnk_804A5B20.h"
#include "pso/player/TObjPlayer_8012D8E4.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/item/TItem.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 scale_current_matrix(void *);
u8 get_item_index__5TItemFv();
s32 post_translate_matrix(void *);
}

void TUnk_804A5B20::vfunc_60() {
    s32 player_list;

    switch ((s32) get_item_index__5TItemFv()) {
    case 5:
        player_list = TObjPlayer::get_player_list();
        switch (player_list) {
        case 1:
            rotate_matrix_x(0, rotation);
            return;
        case 2:
            scale_current_matrix(&scale);
            return;
        }
        break;
    case 7:
        switch (TObjPlayer::get_player_list()) {
        case 4:
            post_translate_matrix(&scale);
            return;
        case 2:
            rotate_matrix_z(0, rotation);
            break;
        }
        break;
    }
}

typedef struct SlicerLaunchData_8012D9C8 {
    u16 player; u16 pad;
    void *textures; void *model; u32 weapon;
    s16 kind, stage; f32 multiplier; f32 color[4];
    s32 facing, spin; f32 first[3], second[3];
} SlicerLaunchData_8012D9C8;

extern "C" {
u8 get_item_index__5TItemFv();
extern const f32 lbl_805DAF38;
extern const f32 lbl_805DAF3C;
extern const f32 lbl_805DAF50;
extern const f32 lbl_805DAF54;
void init_slicer_launch_state(void *arg0);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
s16 get_validated_attack_stage(u8 *arg0);
void get_weapon_color__11TItemWeaponFPv(f32 *, void *);
}
extern const f32 lbl_805DAF40;
extern const f32 lbl_805DAF44;
extern const f32 lbl_805DAF48;
extern const f32 lbl_805DAF4C;

void TUnk_804A5B20::emit_marker_effects() {
    f32 tmp[4];
    SlicerLaunchData_8012D9C8 launch;
    init_slicer_launch_state(&launch);
    launch.player = get_entity_id(owner);
    launch.weapon = get_item_id();
    launch.textures = *(void **)((s8 *)this + 0x24);
    launch.model = *(void **)((s8 *)this + 0x188);
    launch.kind = TObjPlayer__sub_801D2F4C((s16 *)((u8 *)owner + 0x7CC));
    launch.stage = get_validated_attack_stage((u8 *)owner + 0x7CC);
    launch.multiplier = owner->query_extended_state();
    get_weapon_color__11TItemWeaponFPv(tmp, this);
    copy_argb((NJS_ARGB *)launch.color, (NJS_ARGB *)tmp);
    launch.facing = owner->rotation_y;
    get_joint_position(1, launch.first);
    get_joint_position(2, launch.second);
    TTecSlicer::create((u16*)&launch);
}

void TUnk_804A5B20::update_idle() {
    u8 *arg0 = (u8 *)this;
  int new_var;
  switch ((s32) get_item_index__5TItemFv())
  {
    case 5:
    {
      s32 lim;
      TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x1F8), 0x1555, 0x8000);
      new_var = 0x8000;
      if (new_var <= ((s32) (*((s32 *) (((s8 *) arg0) + 0x1F8)))))
      {
        TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x204), (f32)lbl_805DAF40, (f32)lbl_805DAF44);
      }
    }
      break;
    case 6:
      break;
    case 7:
      TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x204), (f32)lbl_805DAF48, (f32)lbl_805DAF4C);
      TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x1F8), -0x1555, -0x8000);
      break;
  }
}

void TUnk_804A5B20::update_attack() {
    switch ((s32)get_item_index__5TItemFv()) {
    case 5:
        TItemEffOrgaFlowShot::approach_value(&scale.z, lbl_805DAF50, lbl_805DAF38);
        if (lbl_805DAF38 <= scale.z) {
            TObjPlayer::add_angle_clamped(&rotation, -0x2AAA, 0);
        }
    case 6:
        return;
    case 7:
        TItemEffOrgaFlowShot::approach_value(&scale.z, lbl_805DAF54, lbl_805DAF3C);
        TObjPlayer::add_angle_clamped(&rotation, 0x2AAA, 0);
        break;
    }
}

TUnk_804A5B20::TUnk_804A5B20(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    rotation = 0;
    switch (item[2]) {
    case 6:
        break;
    case 5:
        scale.x = lbl_805DAF38;
        scale.y = lbl_805DAF38;
        scale.z = lbl_805DAF38;
        break;
    case 7:
        scale.x = lbl_805DAF3C;
        scale.y = lbl_805DAF3C;
        scale.z = lbl_805DAF3C;
        break;
    }
}

u8 *create_slicer_weapon(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A5B20(tl_05, item);
    }
    return NULL;
}

TUnk_804A5B20::~TUnk_804A5B20() {}
