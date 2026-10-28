#include "types.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_80129B60.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/player/TObjPlayer_80129CA0.h"

void s_rank_bazooka_slide_barrel(void *arg0) {
    if (TObjPlayer::get_player_list() == 1) {
        translate_matrix(0, 0.0f, (-1.0f) * *(f32 *)((s8 *)arg0 + 0x1FC), 0.0f);
    }
}

struct Owner_80129BB0 { u8 pad[0x60]; s32 f60; };

struct Self_80129BB0 {
    u8 pad0[0xF0];
    Owner_80129BB0 *owner;
    u8 padF4[0x1FC - 0xF4];
    f32 f1FC;
    s32 state;
};

struct Vec_80129BB0 { f32 x, y, z; };

struct Ang_80129BB0 { s32 x, y, z; };

extern "C" {
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern s32 tl_05;

void s_rank_bazooka_recoil(Self_80129BB0 *self);
void s_rank_bazooka_recoil(Self_80129BB0 *self) {
    s32 ang;
    Vec_80129BB0 v;
    Ang_80129BB0 a;
    if (self->state == 1) {
        TItemEffOrgaFlowShot::approach_value(&self->f1FC, (-0.5f), (-2.0f));
        if ((-2.0f) == self->f1FC) {
            self->state = 2;
            ang = self->owner->f60 + 0x4000;
            v.x = sin_table_lookup(ang);
            v.y = 0.0f;
            v.z = cos_table_lookup(ang);
            a.x = 0x4000;
            a.y = self->owner->f60;
            a.z = 0;
            TObjPlayer::launch_weapon_casing((s32)tl_05, (u32)self, 3, (u32)&v, (u32)&a);
        }
    } else if (self->state == 2) {
        TItemEffOrgaFlowShot::approach_value(&self->f1FC, 0.2f, 0.0f);
        if (0.0f == self->f1FC) {
            self->state = 0;
        }
    }
}

}

extern "C" {

int construct_srank_weapon(void);

    extern unsigned char play_effect__13TItemEffFlameFllll[];
    extern unsigned char create_shoot_model_with_particles[];
    extern unsigned char s_rank_bazooka_weapon_vtable[];
    
void* init_s_rank_bazooka(void* a0) { construct_srank_weapon(); *(int*)((char*)a0 + 0x18) = (int)s_rank_bazooka_weapon_vtable; *(float*)((char*)a0 + 0x1fc) = 0.0f; *(int*)((char*)a0 + 0x1ec) = (int)play_effect__13TItemEffFlameFllll; *(int*)((char*)a0 + 0x200) = 0; *(int*)((char*)a0 + 0x1f4) = (int)play_target_impact_effect; *(int*)((char*)a0 + 0x1f0) = (int)create_shoot_model_with_particles; *(float*)((char*)a0 + 0x1e4) = 15.0f; return a0; }

}
