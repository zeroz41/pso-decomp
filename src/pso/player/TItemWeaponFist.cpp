// ---- pso/unk/text_80126740
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80126740.h"
#include "pso/player/PlayerAttackParams.h"


extern "C" {
u8 * baranz_launcher_ct(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
}
extern s32 tl_05;

u8 *create_baranz_launcher(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x200));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(baranz_launcher_ct(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

void fist_reset_attack_rate(u8 *arg0) {
    ((PlayerAttackState *)(*(s32 *)((s8 *)arg0 + 0xF0) + 0x7CC))->set_evp(1.0f);
}

// ---- pso/player/TObjPlayer_801267C4
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerAttackParams.h"

extern "C" {








void TObjPlayer::apply_shield_scale_to_unit() {
    f32 var_f31;
    u8 temp_r3;

    var_f31 = 1.0f;
    temp_r3 = ((TItem *)this)->get_item_index();
    switch ((s32) temp_r3) {
    case 0:
        var_f31 = 1.05f;
        break;
    case 1:
        var_f31 = 1.1f;
        break;
    case 2:
        var_f31 = 1.15f;
        break;
    case 3:
        var_f31 = 1.2f;
        break;
    }
    ((PlayerAttackState *)(*(s32 *)&this->blend.frame[1] + 0x7CC))->set_evp(var_f31);
}

}

// ---- pso/unk/text_8012685C
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"

struct Stack_8012685C {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
};

#include "pso/items/TItemWeaponFist.h"
#include "pso/item/TItemProShield.h"
#include "pso/items/TItemWeapon.h"
struct WeaponPlayerObjectPrefix
{
  char pad[0x18];
};
struct WeaponPlayerAttachmentInterface : WeaponPlayerObjectPrefix {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void sample_joint_position(s32, void *);
};

extern "C" {
s32 reflect_matrix_in_plane(s32, f32 *, f32);
void *spawn_particle_effect(void *pos, s32 id);
s16 get_validated_attack_stage(u8 *arg0);
}
extern s32 knuckle_second_hand_pass;


void reflect_knuckle_second_hand(s32 arg0);
extern s32 knuckle_marker_joint_table[];
extern s32 tl_05;
void reflect_knuckle_second_hand(s32 arg0) {
    Stack_8012685C stack;
    if ((TObjPlayer::get_player_list() == 0) && (((TItem *)arg0)->get_item_index() == 3) && ((s32) knuckle_second_hand_pass != 0)) {
        stack.sp10 = 0.0f;
        stack.spC = 0.0f;
        stack.sp8 = 0.0f;
        stack.sp1C = 0.0f;
        stack.sp18 = 0.0f;
        stack.sp14 = 1.0f;
        reflect_matrix_in_plane(0, &stack.sp8, 0.0f);
    }
}

void TItemWeaponFist::emit_marker_effects() {
  TItemWeaponFist* arg0 = this;
  u8 buf[16];
  s32 k;
  s16 stage;
  s32 index;
  if (((TItem *)arg0)->get_item_index() == 3)
  {
    if (((TItemWeapon *)arg0)->get_attack_stage() == 0)
    {
      ((TObjPlayer *)tl_05)->spawn_cane_effects((TItem*)arg0, -1, -2);
    }
  }
  else
  {
    k = ((TObjPlayer *)(arg0->player))->has_valid_handle() * 3;
    stage = get_validated_attack_stage(((u8 *) arg0->player) + 0x7CC);
    index = stage;
    index += k;
    arg0->player->sample_joint_position(knuckle_marker_joint_table[index], buf);
    spawn_particle_effect(buf, 0x1D0);
  }
}
