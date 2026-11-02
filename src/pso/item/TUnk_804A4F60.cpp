#include "types.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_804A4F60.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecBarta.h"
#include "pso/misc/TTecFoie.h"
#include "pso/map/FloorArea.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8012BC28.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/unk/text_8012BCD4.h"
#include "pso/player/TObjPlayer_8012BDA8.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012BDC0.h"

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

void TUnk_804A4F60::activate_effect(s32 arg1) {
    u8 *arg0 = (u8 *)this;
  s32 new_var;
  s32 temp_r31;
  if (((u32) (*((u32 *) (((s8 *) arg0) + 0xF0)))) != 0U)
  {
    if (is_current_area_item_enabled() != 0)
    {
      temp_r31 = ((TObjPlayer *)(*((u32 *) (((s8 *) arg0) + 0xF0))))->get_floor();
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
    send_activate_effect__5TItemFl(this, 3.0f * (3.0517578e-05f * (f32)rand()));
}

}

void psycho_wand_node_callback(void *arg0);
extern "C" {
s32 rotate_matrix_z(s32, s32);
s32 add_actor_tp(u8 *arg0, s32 arg1);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 TObjectV8047c128_subtract_hp(u8 *arg0, s16 arg1);
s16 get_actor_tp(u8 *p);

void TUnk_804A4F60::update_weapon() {
    s16 temp_r0;
    s16 temp_r3;

    if (is_current_area_item_enabled() != 0) {
        temp_r3 = get_actor_tp((u8 *)this->owner);
        temp_r0 = *(s16 *)((s8 *)this + 0x1F8) - temp_r3;
        if (temp_r0 != 0) {
            *(s16 *)((s8 *)this + 0x1F8) = temp_r3;
        }
        if (temp_r0 > 0) {
            TObjectV8047c128_subtract_hp((u8 *)this->owner, temp_r0);
            add_actor_tp((u8 *)this->owner, (s16) (temp_r0 / 2));
        }
    }
}

extern s32 tl_05;

void TUnk_804A4F60::emit_marker_effects() {
    s32 item = (s32)this;
    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect((TItem*)item, 4);
    }
    if (((TItemWeapon *)item)->is_mode_two_and_ready() != 0) {
        ((TUnk_804A4F60 *)item)->psycho_wand_roll_extra();
        return;
    }
    ((TObjPlayer *)item)->update_active_game_effect();
}
}

void psycho_wand_node_callback(void *arg0) {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 2:
        rotate_matrix_z(0, *(s32 *)((s8 *)arg0 + 0x278));
        return;
    case 5:
        rotate_matrix_z(0, -*(s32 *)((s8 *)arg0 + 0x278));
        return;
    case 1:
        translate_matrix(0, 0.0f, (-1.0f) * ((TUnk_804A4F60 *)arg0)->m_274, 0.0f);
        return;
    case 3:
    case 4:
    case 6:
        TItem::begin_effect_render();
        return;
    }
}

void TUnk_804A4F60::update_idle() {
    u8 *arg0 = (u8 *)this;
    TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x278), 0x38E, 0x2AAA);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x278) == 0x2AAA) {
        TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x274), (f32)0.5f, (f32)6.0f);
    }
}

void TUnk_804A4F60::update_attack() {
    u8 *arg0 = (u8 *)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x274), (f32)(-2.0f), (f32)0.0f);
    if (0.0f == this->m_274) {
        TObjPlayer::add_angle_clamped((s32 *)(arg0 + 0x278), -0x71C, 0);
    }
}

struct RecoveredGlobal_8012BCD4_lbl_804A4F60 { s32 value; u8 remaining[0xF4]; };
typedef char RecoveredGlobal_8012BCD4_lbl_804A4F60_size[sizeof(RecoveredGlobal_8012BCD4_lbl_804A4F60) == 0xF8 ? 1 : -1];

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 * __ct__11TItemWeaponFP7TObjectPUc(void *, void *);
}
extern RecoveredGlobal_8012BCD4_lbl_804A4F60 psycho_wand_weapon_vtable;

u8 *psycho_wand_ct(u8 *arg0, u8 *arg1, s32 _w2) {
    __ct__11TItemWeaponFP7TObjectPUc(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &psycho_wand_weapon_vtable.value;
    ((TObjPlayer *)(arg0 + 0x208))->construct_target_cursor_records();
    ((TItemWeapon *)arg0)->set_weapon_flags(0x22);
    *(s32 *)((s8 *)arg0 + 0x278) = 0;
    ((TUnk_804A4F60 *)arg0)->m_274 = (f32) 0.0f;
    *(s16 *)((s8 *)arg0 + 0x1F8) = -1;
    ((TUnk_804A4F60 *)arg0)->m_204 = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0x200) = (f32) 0.0f;
    ((TUnk_804A4F60 *)arg0)->m_1fc = (f32) 0.0f;
    ((TUnk_804A4F60 *)arg0)->m_264 = 0;
    *(s32 *)((s8 *)arg0 + 0x208) = 0;
    return arg0;
}

u8 *create_psycho_wand(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x27c));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(psycho_wand_ct((u8 *)temp_r3, (u8 *)tl_05, (s32)arg0));
        }
        return var_r0;
    }
    return NULL;
}

void psycho_wand_equip(void* p) { *(s16*)((char*)p + 0x1f8) = -1; }
void psycho_wand_unequip(void* p) { *(s16*)((char*)p + 0x1f8) = -1; }


void *__dt__13TUnk_804A4F60Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &psycho_wand_weapon_vtable.value;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
