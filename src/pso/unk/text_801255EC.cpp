#include "types.h"
#include "pso/unk/text_801255EC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/vector.h"
#include "pso/misc/TParticleCtrl_800867E4.h"

struct Elem_80125628 { u8 pad[0x1c]; u8 f1c[0x2c - 0x1c]; };

struct Obj_80125628 { u8 pad[0xa4]; Elem_80125628 *elems; };

struct Ctx_80125628 { Obj_80125628 *obj; s32 idx; };

struct Info_80125678 {
    Vec pos;
    u8 pad0c[0x10 - 0xC];
    s32 f10;
    u8 pad14[0x80 - 0x14];
};

struct Self_8012573C { u8 pad[0x23c]; u32 f23c; };

struct Out_8012573C { u8 pad[0x40]; u32 f40; u8 pad44[0x50 - 0x44]; s32 f50; u8 pad54[0x70 - 0x54]; void *f70; void *f74; s32 f78; s32 f7c; };

extern "C" {
void config_faust_attack_collider__10TObjPlayerFPvPv(Self_8012573C *self, Out_8012573C *out);
}
s32 spawn_faust_explosion(u32 a0, const Vec &pos);
void TObjPlayer::spawn_faust_wall_explosion(s32 arg0, s32 arg1) {
    u32 temp_r3 = (u32)find_item_by_id(arg0);
    if (temp_r3 != 0U) {
        spawn_faust_explosion(temp_r3, *(const Vec *)arg1);
    }
}
void spawn_faust_hit_explosion(s32 arg0, s32 arg1) {
    Ctx_80125628 *ctx = (Ctx_80125628 *)arg1;
    u32 p = (u32)find_item_by_id(arg0);
    if (p != 0U) {
        spawn_faust_explosion(p, *(const Vec *)ctx->obj->elems[ctx->idx].f1c);
    }
}

extern "C" {
void *TObjPlayer__sub_802E449C(void *a0);
void *__nw__7TObjectFUl(u32);
s32 construct_explosion_collider__13TUnk_804A2548Fv(void *, TObject *, void *);
extern TObject *tl_05;
}

s32 spawn_faust_explosion(u32 a0, const Vec &pos) {
    if (((TItem *)a0)->get_item_index() == 1) {
        Info_80125678 info;
        void *o;
        TObjPlayer__sub_802E449C(&info);
        ((TObjPlayer *)a0)->fill_status_info(&info);
        VecCopy(&info.pos, &pos);
        info.f10 = 0xA;
        o = __nw__7TObjectFUl(0xC8);
        if (o != NULL) {
            construct_explosion_collider__13TUnk_804A2548Fv(o, tl_05, &info);
        }
        create_timed_particle_emitter(&info, 0x17F, 0, 10);
    } else {
        Vec v = pos;
        create_timed_particle_emitter(&v, 0x17E, 0, 10);
    }
}

void config_faust_attack_collider__10TObjPlayerFPvPv(Self_8012573C *self, Out_8012573C *out) {
    out->f74 = (void *)spawn_faust_hit_explosion;
    out->f70 = (void *)TObjPlayer::spawn_faust_wall_explosion;
    out->f50 = -0x4000;
    out->f40 |= self->f23c;
    out->f78 = 0x1bb;
    out->f7c = 0x1bc;
}
