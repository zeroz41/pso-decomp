#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/item/TItem.h"
#include "pso/unk/TUnk_804A5B20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/misc/TTecSlicer.h"

struct RecoveredGlobal_8012DBF4_lbl_804A5B20 {
    s32 value;
    u8 remaining[0xF4];
};

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
u8 *__nw__5TItemFUl(s32);
u8 * TItemWeapon__ct(void *, void *);
void init_slicer_launch_state(void *arg0);
u16 obj_getField1c(void *);
s16 TObjPlayer__sub_801D2F4C(s16 *arg0);
s16 get_validated_attack_stage(u8 *arg0);
f32 query_extended_state__10TObjPlayerFv(void *);
void get_weapon_color__11TItemWeaponFPv(f32 *, void *);
}
extern s32 tl_05;
u8 *create_slicer_weapon(u8 *arg0);
extern const f32 lbl_805DAF40;
extern const f32 lbl_805DAF44;
extern const f32 lbl_805DAF48;
extern const f32 lbl_805DAF4C;
extern RecoveredGlobal_8012DBF4_lbl_804A5B20 lbl_804A5B20;
u8 *construct_slicer_weapon(u8 *arg0, u8 *arg1, u8 *arg2);
void launch_slicer_shot(u8 *weapon);

void launch_slicer_shot(u8 *weapon) {
    f32 tmp[4];
    SlicerLaunchData_8012D9C8 launch;
    init_slicer_launch_state(&launch);
    launch.player = obj_getField1c(*(u8 * *)&((TUnk_804A5B20 *)weapon)->player);
    launch.weapon = ((TItem *)weapon)->get_item_id();
    launch.textures = *(void **)((s8 *)weapon + 0x24);
    launch.model = *(void **)((s8 *)weapon + 0x188);
    launch.kind = TObjPlayer__sub_801D2F4C((s16 *)(*(u8 * *)&((TUnk_804A5B20 *)weapon)->player + 0x7CC));
    launch.stage = get_validated_attack_stage(*(u8 * *)&((TUnk_804A5B20 *)weapon)->player + 0x7CC);
    launch.multiplier = query_extended_state__10TObjPlayerFv(*(u8 * *)&((TUnk_804A5B20 *)weapon)->player);
    get_weapon_color__11TItemWeaponFPv(tmp, weapon);
    copy_argb((NJS_ARGB *)launch.color, (NJS_ARGB *)tmp);
    launch.facing = *(s32 *)((s8 *)(*(u8 * *)&((TUnk_804A5B20 *)weapon)->player) + 0x60);
    ((TObjPlayer *)weapon)->draw_icon(1, (s32)launch.first);
    ((TObjPlayer *)weapon)->draw_icon(2, (s32)launch.second);
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
    u8 *arg0 = (u8 *)this;
  switch ((s32) get_item_index__5TItemFv())
  {
    case 5:
      TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x204), (f32)((f32) lbl_805DAF50), (f32)((f32) lbl_805DAF38));
      if (lbl_805DAF38 <= (this->m_204))
    {
      TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x1F8), -0x2AAA, 0);
    }
    case 6:
      return;
    return;
    case 7:
      TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x204), (f32)((f32) lbl_805DAF54), (f32)((f32) lbl_805DAF3C));
      TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x1F8), 0x2AAA, 0);
      break;
  }
}

typedef char RecoveredGlobal_8012DBF4_lbl_804A5B20_size[sizeof(RecoveredGlobal_8012DBF4_lbl_804A5B20) == 0xF8 ? 1 : -1];
u8 *construct_slicer_weapon(u8 *arg0, u8 *arg1, u8 *arg2) {
    TItemWeapon__ct(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804A5B20.value;
    ((TObjPlayer *)arg0)->set_status_flags(2);
    *(s32 *)((s8 *)arg0 + 0x1F8) = 0;
    switch ((s32) (*(u8 *)((s8 *)arg2 + 2))) {
    case 6:
        break;
    case 5:
        ((TUnk_804A5B20 *)arg0)->m_1fc = (f32) lbl_805DAF38;
        *(f32 *)((s8 *)arg0 + 0x200) = (f32) lbl_805DAF38;
        ((TUnk_804A5B20 *)arg0)->m_204 = (f32) lbl_805DAF38;
        break;
    case 7:
        ((TUnk_804A5B20 *)arg0)->m_1fc = (f32) lbl_805DAF3C;
        *(f32 *)((s8 *)arg0 + 0x200) = (f32) lbl_805DAF3C;
        ((TUnk_804A5B20 *)arg0)->m_204 = (f32) lbl_805DAF3C;
        break;
    }
    return arg0;
}

u8 *create_slicer_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x208));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_slicer_weapon((u8 *)temp_r3, (u8 *)tl_05, (u8 *)arg0));
        }
        return var_r0;
    }
    return NULL;
}
