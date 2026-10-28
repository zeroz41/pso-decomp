#include "types.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_804A4F60.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecBarta.h"
#include "pso/misc/TTecFoie.h"
#include "pso/map/FloorArea.h"

struct Owner_8012B9B4 { u8 pad[0x38]; f32 pos[3]; u8 pad44[0x60 - 0x44]; s32 f60; };

struct Self_8012B9B4 {
    u8 pad0[0xF0];
    Owner_8012B9B4 *owner;
    u8 padF4[0x1FC - 0xF4];
    u8 icon[0xC];
    s32 f208;
    s16 f20C;
    s16 f20E;
    u8 pad210[0x264 - 0x210];
    s32 f264;
    f32 f268[3];
};

extern "C" {
s32 get_current_floor();
u8 * init_vtable_and_clear_field1f8__13TUnk_804A4E68Fv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void send_activate_effect__5TItemFl(void *, s32);
s32 get_extended_state__10TObjPlayerFv(void *);
s16 get_captured_target_collider_index(void *p);
s32 get_captured_target_entry(s32, s32);
s32 get_captured_target_count(s32 *arg0);
s32 rand(void);
extern const f32 lbl_805DAEC0;
extern const f32 lbl_805DAEC4;

u8 *TObjPlayer::create_vtable_clear_field1f8(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_vtable_and_clear_field1f8__13TUnk_804A4E68Fv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

void TUnk_804A4F60::vfunc_17(s32 arg1) {
    u8 *arg0 = (u8 *)this;
  s32 new_var;
  s32 temp_r31;
  if (((u32) (*((u32 *) (((s8 *) arg0) + 0xF0)))) != 0U)
  {
    if (is_current_area_item_enabled() != 0)
    {
      temp_r31 = ((TObjPlayer *)(*((u32 *) (((s8 *) arg0) + 0xF0))))->get_field_3e4();
      new_var = get_current_floor();
      if (new_var == temp_r31)
      {
        switch (arg1)
        {
          case 0:
            TObjPlayer::create_tec_zonde((void *)(*((u32 *) (((s8 *) arg0) + 0xF0))), (u8 *)&this->m_1fc, (u8 *)&this->unk_208, (void *)(0xA));
            return;
          case 1:
            TTecFoie::create((void *)(*((u32 *) (((s8 *) arg0) + 0xF0))), (u8 *)&this->m_1fc, (void *)this->m_264, (void *)(0xA));
            return;
          case 2:
            ((TTecBarta *)(*((u32 *) (((s8 *) arg0) + 0xF0))))->create_ex((u8 *)&this->unk_268, (void *)this->m_264, (void *)(0xA));
            break;
        }
      }
    }
  }
}
void TUnk_804A4F60::psycho_wand_roll_extra() {
    s32 ext;
    s32 item;
    ((TItemWeapon *)((Self_8012B9B4 *)this))->get_joint_position(4, (((Self_8012B9B4 *)this)->icon));
    ext = get_extended_state__10TObjPlayerFv(((Self_8012B9B4 *)this)->owner);
    item = get_captured_target_entry(ext, 0);
    if (get_captured_target_count((s32 *)ext) != 0) {
        ((Self_8012B9B4 *)this)->f208 = 1;
        ((Self_8012B9B4 *)this)->f20C = ((TObjPlayer *)item)->get_uid();
        ((Self_8012B9B4 *)this)->f20E = get_captured_target_collider_index((void *)item);
    } else {
        ((Self_8012B9B4 *)this)->f208 = 0;
    }
    ((Self_8012B9B4 *)this)->f264 = ((Self_8012B9B4 *)this)->owner->f60;
    VecCopy((Vec *)(((Self_8012B9B4 *)this)->f268), (const Vec *)(((Self_8012B9B4 *)this)->owner->pos));
    send_activate_effect__5TItemFl(this, lbl_805DAEC0 * (lbl_805DAEC4 * (f32)rand()));
}

}
