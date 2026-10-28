#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/item/TItemEffectWeapon_803631A0.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_80087278.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TUnk_804F28E0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEffectWeapon_803632B4.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/item/TItemEffectWeapon.h"

struct Obj_803631E8 {
    u8 pad0[0x10]; s32 i10; u8 pad14[0x2C]; u32 flags; s32 i44; u8 pad48[4]; f32 f4C; u8 pad50[0x10]; u8 v60[0x10]; void *fn70;
};

struct Src_803631E8 { u8 pad[0x188]; s32 i188; };

extern "C" {
void get_weapon_color__11TItemWeaponFPv(void *, void *);

void s_rank_launcher_collider_block(Src_803631E8 *arg0, Obj_803631E8 *arg1);
}

void s_rank_launcher_slide_node(void *arg0) {
    if (TObjPlayer::get_player_list() == 1) {
        translate_matrix(0, 0.0f, *(f32 *)((s8 *)arg0 + 0x1FC), 0.0f);
    }
}

void s_rank_launcher_collider_block(Src_803631E8 *weapon, Obj_803631E8 *arg1) {
    u8 sp8[16];
    arg1->flags |= 0x39C;
    get_weapon_color__11TItemWeaponFPv(sp8, weapon);
    ((TRaderMapCore *)(arg1->v60))->copy_vec4(sp8);
    arg1->i44 = weapon->i188;
    arg1->i10 = 4;
    arg1->f4C = 2.0f;
    arg1->fn70 = (void *)TObjPlayer::forward_item_effect_callback;
}

void TUnk_804F28E0::emit_marker_effects() {
    s32 arg0 = (s32)this;
    s32 sp8;

    ((TObjPlayer *)arg0)->draw_status_icon((s32)&sp8);
    spawn_particle_effect(&sp8, 9);
    ((TItemWeapon *)arg0)->spawn_light_task();
    ((TItemWeapon *)arg0)->fire_shot_at_target(&sp8, 0, 0);
}

void TUnk_804F28E0::update_idle() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1FC), (f32)0.5f, (f32)4.0f);
}

void TUnk_804F28E0::update_attack() {
    s32 arg0 = (s32)this;
    TItemEffOrgaFlowShot::approach_value((f32 *)(arg0 + 0x1FC), (f32)(-1.0f), (f32)0.0f);
}

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
int set_status_flags__10TObjPlayerFUl(void*, void*);
int construct_srank_weapon(void);

    extern unsigned char lbl_804F28E0[];
    
void*TUnk_804F28E0::init(s32 _w1, void *_w2) { construct_srank_weapon(); *(int*)((char*)this + 0x18) = (int)lbl_804F28E0; set_status_flags__10TObjPlayerFUl(this, (void*)2); *(float*)((char*)this + 0x1fc) = 0.0f; return this; }
u8 *TItemEffectWeapon::create_instance() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x200));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_804F28E0 *)temp_r3)->init(tl_05, arg0)));
        }
        return var_r0;
    }
    return NULL;
}

}
