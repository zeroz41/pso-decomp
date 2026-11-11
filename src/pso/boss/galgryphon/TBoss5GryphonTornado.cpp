#include "types.h"
#include "pso/boss/galgryphon/TBoss5GryphonTornado.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/ui/hud/TNowLoading.h"

extern "C" {
extern const f32 lbl_805DFFA8;
void TBoss5GryphonTornado::sub_803554F0(u8 *boss2_tunnel) {
    u8 *arg0 = (u8 *)this;
  unsigned short new_var;
  u16 temp_r3;
  u8 *player;
  *((f32 *) (((s8 *) boss2_tunnel) + 0)) = (f32) lbl_805DFFA8;
  *((f32 *) (((s8 *) boss2_tunnel) + 4)) = (f32) lbl_805DFFA8;
  *((f32 *) (((s8 *) boss2_tunnel) + 8)) = (f32) lbl_805DFFA8;
  temp_r3 = this->m_24;
  new_var = -1U;
  if (temp_r3 != new_var)
  {
    player = (u8 *) get_player_by_client_id(temp_r3);
    if (player != 0)
    {
      *((f32 *) (((s8 *) boss2_tunnel) + 0)) = (f32) ((*((f32 *) (((s8 *) player) + 0x38))) - (*((f32 *) (((s8 *) arg0) + 0x28))));
      *((f32 *) (((s8 *) boss2_tunnel) + 8)) = (f32) ((*((f32 *) (((s8 *) player) + 0x40))) - (this->m_30));
      ((TObjBoss2Tunnel *)boss2_tunnel)->update_scale();
    }
  }
}

}

struct RecoveredGlobal_803558E4___vt__20TBoss5GryphonTornado {
    s32 value;
    u8 remaining[0x14];
};

struct Vec_80355570 { f32 x, y, z; };

struct Inner_80355570 { u8 pad[4]; f32 f4; };

struct Res_80355570 { u8 pad[4]; Inner_80355570 *inner; };

struct Tornado_80355570 {
    u8 pad0[0x1C];
    s32 state;
    s32 timer;
    u8 pad24[0x28 - 0x24];
    Vec_80355570 pos;
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[0x4C - 0x40];
    s32 f4C;
    void *p50;
    void *p54;
    void *p58;
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__20TBoss5GryphonTornado[];
extern s32 lbl_805D4398;
s32 get_bml_motion(s32, s32);
s32 get_bml_model(s32, s32);
void TBoss8Dragon__sub_800640A4(s32, Vec_80355570 *);
void attach_particle_model(void *, s32, s32, s32, s32, f32);
Res_80355570 *csnVecterUnder(Vec_80355570 *, s32);
void add_radar_scaled_marker(Vec_80355570 *, s32, s32, s32, f32);
void play_persistent_sound(s32, void *, Vec_80355570 *, s32, s32);
extern s32 boss5_gryphon_bml_resource;
extern s32 boss5_gryphon_texture_list;
extern s32 *gryphon_tornado_particle_id_table;
extern const f32 lbl_805D8D48;
extern const f32 lbl_805DFFAC;
extern const f32 lbl_805DFFB0;
extern const f32 lbl_805DFFB4;
extern const f32 lbl_805DFFB8;

void TBoss5GryphonTornado::render() {  }

#pragma push
#pragma fp_contract on
#pragma fp_contract on
void TBoss5GryphonTornado::run_task() {
    Tornado_80355570 *o = (Tornado_80355570 *)this;
    Vec_80355570 v;
    Res_80355570 *r;
    f32 h;
    if (((TBoss8Dragon *)(o->f4C))->get_flag_bit6() != 0) {
        queue_destruction__7TObjectFv(o);
        return;
    }
    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        o->pos.y = lbl_805D8D48;
        r = csnVecterUnder(&o->pos, 0x16EF);
        if (r == NULL) {
            queue_destruction__7TObjectFv(o);
            return;
        }
        h = r->inner->f4;
        if (h > lbl_805D8D48) {
            o->pos.y = lbl_805D8D48;
        } else {
            o->pos.y = h;
        }
        if (o->p50 == NULL) {
            o->p50 = spawn_continuous_particle_effect_with_flags(&o->pos, gryphon_tornado_particle_id_table[0], 0x40);
        }
        if (o->p54 == NULL) {
            o->p54 = spawn_continuous_particle_effect_with_flags(&o->pos, gryphon_tornado_particle_id_table[1], 0x40);
            if (o->p54 != NULL) {
                attach_particle_model(o->p54, get_bml_model(boss5_gryphon_bml_resource, 0), boss5_gryphon_texture_list, get_bml_motion(boss5_gryphon_bml_resource, 0), 0, lbl_805DFFAC);
            }
        }
        if (o->p58 == NULL) {
            o->p58 = spawn_continuous_particle_effect_with_flags(&o->pos, gryphon_tornado_particle_id_table[2], 0x40);
        }
        if (o->p50 != NULL) {
            ((TParticleCtrl *)o->p50)->set_position(&o->pos);
        }
        if (o->p54 != NULL) {
            ((TParticleCtrl *)o->p54)->set_position(&o->pos);
        }
        if (o->p58 != NULL) {
            ((TParticleCtrl *)o->p58)->set_position(&o->pos);
        }
        if (o->timer > 0x168) {
            o->state = 2;
            o->timer = 0;
        }
        TBoss8Dragon__sub_800640A4(TBoss8Dragon::get_instance_count(), &o->pos);
        ((TBoss5GryphonTornado *)o)->sub_803554F0((u8 *)&v);
        o->f34 = lbl_805DFFB0 * v.x + o->f34;
        o->f3C = lbl_805DFFB0 * v.z + o->f3C;
        o->f34 *= lbl_805DFFB4;
        o->f3C *= lbl_805DFFB4;
        o->pos.x += o->f34;
        o->pos.z += o->f3C;
        add_radar_scaled_marker(&o->pos, -0x5DB4, 1, 1, lbl_805DFFB8);
        play_persistent_sound(0x40032D05, o, &o->pos, 0, 0);
        o->timer++;
        break;
    case 2:
        if (o->p50 != NULL) {
            ((TParticleCtrl *)(o->p50))->enable();
        }
        if (o->p54 != NULL) {
            ((TParticleCtrl *)(o->p54))->enable();
        }
        if (o->p58 != NULL) {
            ((TParticleCtrl *)(o->p58))->enable();
        }
        if (o->timer > 0x3C) {
            queue_destruction__7TObjectFv(o);
        } else {
            o->timer++;
        }
        break;
    }
}
#pragma pop

}
TBoss5GryphonTornado::~TBoss5GryphonTornado() {
    if (*(void **)((s8 *)this + 0x58) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x58)); this->m_58 = 0; }
    if (*(void **)((s8 *)this + 0x54) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x54)); this->m_54 = 0; }
    if (*(void **)((s8 *)this + 0x50) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x50)); this->m_50 = 0; }
}

typedef char RecoveredGlobal_803558E4___vt__20TBoss5GryphonTornado_size[sizeof(RecoveredGlobal_803558E4___vt__20TBoss5GryphonTornado) == 0x18 ? 1 : -1];
u8 *TBoss5GryphonTornado__ct(TBoss5GryphonTornado *boss5_gryphon_tornado, u8 *arg1, s32 arg2, u8 *arg3, s16 arg4) {
    __ct__7TObjectFP7TObject(boss5_gryphon_tornado, arg1);
    *(s32 **)((s8 *)boss5_gryphon_tornado + 0x18) = &(*(RecoveredGlobal_803558E4___vt__20TBoss5GryphonTornado *)&__vt__20TBoss5GryphonTornado).value;
    *(s32 *)((s8 *)boss5_gryphon_tornado + 0) = (s32) lbl_805D4398;
    VecCopy((Vec *)((u8 *)boss5_gryphon_tornado + 0x28), (const Vec *)arg3);
    boss5_gryphon_tornado->m_24 = arg4;
    boss5_gryphon_tornado->m_4c = arg2;
    *(f32 *)((s8 *)boss5_gryphon_tornado + 0x34) = (f32) lbl_805DFFA8;
    boss5_gryphon_tornado->m_38 = (f32) lbl_805DFFA8;
    *(f32 *)((s8 *)boss5_gryphon_tornado + 0x3C) = (f32) lbl_805DFFA8;
    boss5_gryphon_tornado->m_50 = 0;
    boss5_gryphon_tornado->m_54 = 0;
    boss5_gryphon_tornado->m_58 = 0;
    boss5_gryphon_tornado->m_20 = 0;
    boss5_gryphon_tornado->m_1c = 0;
    return (u8 *)boss5_gryphon_tornado;
}
