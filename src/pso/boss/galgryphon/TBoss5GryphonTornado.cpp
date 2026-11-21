#include "pso/system/BmlAccessors.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/boss/galgryphon/Boss5GryphonBehavior.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/boss/galgryphon/TBoss5GryphonTornado.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/goldragon/TBoss8Dragon_8005D700.h"
#include "pso/unk/text_80355970.h"
#include "pso/unk/text_80355A1C.h"
#include "pso/ui/hud/TRaderMapCore.h"


void TBoss5GryphonTornado::sub_803554F0(u8 *boss2_tunnel) {
    u8 *arg0 = (u8 *)this;
  unsigned short new_var;
  u16 temp_r3;
  u8 *player;
  *((f32 *) (((s8 *) boss2_tunnel) + 0)) = 0.0f;
  *((f32 *) (((s8 *) boss2_tunnel) + 4)) = 0.0f;
  *((f32 *) (((s8 *) boss2_tunnel) + 8)) = 0.0f;
  temp_r3 = this->m_24;
  new_var = -1U;
  if (temp_r3 != new_var)
  {
    player = (u8 *) get_player_by_client_id(temp_r3);
    if (player != 0)
    {
      *((f32 *) (((s8 *) boss2_tunnel) + 0)) = (f32) ((*((f32 *) (((s8 *) player) + 0x38))) - (*((f32 *) (((s8 *) arg0) + 0x28))));
      *((f32 *) (((s8 *) boss2_tunnel) + 8)) = (f32) ((*((f32 *) (((s8 *) player) + 0x40))) - (this->m_30));
      normalize_vector_safe((Vec *)boss2_tunnel);
    }
  }
}


struct Inner_80355570 { u8 pad[4]; f32 f4; };

struct Res_80355570 { u8 pad[4]; Inner_80355570 *inner; };

struct Tornado_80355570 {
    u8 pad0[0x1C];
    s32 state;
    s32 timer;
    u8 pad24[0x28 - 0x24];
    Vec pos;
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[0x4C - 0x40];
    saddr f4C;
    void *p50;
    void *p54;
    void *p58;
};

// The particle ids run_task spawns (installed by TBoss8Dragon__sub_80355A20 at the end of
// the file). Defined first: the table opens the unit's .rodata, before the class name.
static const s32 gryphon_tornado_particle_ids[3] = {0x203, 0x204, 0x205};
const char *TBoss5GryphonTornado__class_name = "TBoss5GryphonTornado";
extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__20TBoss5GryphonTornado[];

Res_80355570 *csnVecterUnder(Vec *, s32);
void play_persistent_sound(s32, void *, Vec *, s32, s32);
const s32 *gryphon_tornado_particle_id_table;
extern const f32 lbl_805D8D48;

void TBoss5GryphonTornado::render() {  }

#pragma push
#pragma fp_contract on
#pragma fp_contract on
void TBoss5GryphonTornado::run_task() {
    Tornado_80355570 *o = (Tornado_80355570 *)this;
    Vec v;
    Res_80355570 *r;
    f32 h;
    if (((TBoss5Gryphon *)(o->f4C))->get_flag_bit6() != 0) {
        ((TObject *)o)->queue_destruction();
        return;
    }
    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        o->pos.y = lbl_805D8D48;
        r = csnVecterUnder(&o->pos, 0x16EF);
        if (r == NULL) {
            ((TObject *)o)->queue_destruction();
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
                attach_particle_model(o->p54, (saddr)get_bml_model(boss5_gryphon_bml_resource, 0), boss5_gryphon_texture_list, (saddr)get_bml_motion(boss5_gryphon_bml_resource, 0), 0, 1.0f);
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
        apply_tornado_hit(TBoss8Dragon::get_instance_count(), (saddr)&o->pos);
        ((TBoss5GryphonTornado *)o)->sub_803554F0((u8 *)&v);
        o->f34 = 0.01f * v.x + o->f34;
        o->f3C = 0.01f * v.z + o->f3C;
        o->f34 *= 0.995f;
        o->f3C *= 0.995f;
        o->pos.x += o->f34;
        o->pos.z += o->f3C;
        add_radar_scaled_marker(&o->pos, -0x5DB4, 1, 1, 1.5f);
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
            ((TObject *)o)->queue_destruction();
        } else {
            o->timer++;
        }
        break;
    }
}
#pragma pop

}
TBoss5GryphonTornado::~TBoss5GryphonTornado() {
    if (*(void **)((s8 *)this + 0x58) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x58)))->queue_destruction(); this->m_58 = 0; }
    if (*(void **)((s8 *)this + 0x54) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x54)))->queue_destruction(); this->m_54 = 0; }
    if (*(void **)((s8 *)this + 0x50) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x50)))->queue_destruction(); this->m_50 = 0; }
}

u8 *TBoss5GryphonTornado__ct(TBoss5GryphonTornado *boss5_gryphon_tornado, u8 *arg1, s32 arg2, u8 *arg3, u16 arg4) {
    __ct__7TObjectFP7TObject(boss5_gryphon_tornado, arg1);
    *(s32 **)((s8 *)boss5_gryphon_tornado + 0x18) = __vt__20TBoss5GryphonTornado;
    *(s32 *)((s8 *)boss5_gryphon_tornado + 0) = (saddr) TBoss5GryphonTornado__class_name;
    VecCopy((Vec *)((u8 *)boss5_gryphon_tornado + 0x28), (const Vec *)arg3);
    boss5_gryphon_tornado->m_24 = arg4;
    boss5_gryphon_tornado->m_4c = arg2;
    *(f32 *)((s8 *)boss5_gryphon_tornado + 0x34) = 0.0f;
    boss5_gryphon_tornado->m_38 = 0.0f;
    *(f32 *)((s8 *)boss5_gryphon_tornado + 0x3C) = 0.0f;
    boss5_gryphon_tornado->m_50 = 0;
    boss5_gryphon_tornado->m_54 = 0;
    boss5_gryphon_tornado->m_58 = 0;
    boss5_gryphon_tornado->m_20 = 0;
    boss5_gryphon_tornado->m_1c = 0;
    return (u8 *)boss5_gryphon_tornado;
}

extern "C" {
saddr spawn_gryphon_tornado(saddr parent, saddr gryphon, const Vec *pos_src, u16 kind) {
    Vec pos;
    Res_80355570 *under;
    f32 y;
    TBoss5GryphonTornado *tornado;
    VecCopy(&pos, pos_src);
    pos.y = lbl_805D8D48;
    under = csnVecterUnder(&pos, 0x16EF);
    if (under == NULL) {
        return 0;
    }
    y = under->inner->f4;
    if (y > lbl_805D8D48) {
        return 0;
    }
    pos.y = y;
    tornado = (TBoss5GryphonTornado *)TObject::operator new(0x5C);
    if (tornado != NULL) {
        tornado = (TBoss5GryphonTornado *)TBoss5GryphonTornado__ct(tornado, (u8 *)parent, gryphon, (u8 *)&pos, kind);
    }
    return (saddr)tornado;
}
}

void TBoss8Dragon__sub_80355A1C(void) {  }
void TBoss8Dragon__sub_80355A20(void) {
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        gryphon_tornado_particle_id_table = gryphon_tornado_particle_ids;
        break;
    }
}
