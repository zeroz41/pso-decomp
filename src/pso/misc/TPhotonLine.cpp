#include "types.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/misc/TPhotonLine.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"

typedef struct Vec_801ACD14 { f32 x, y, z; } Vec_801ACD14;

struct Params_801ACD14 {
    Vec_801ACD14 pos;
    Vec_801ACD14 dir;
    f32 scale;
    f32 f1C;
};

struct Line_801ACD14 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt18;
    u8 pad1C[0x38 - 0x1C];
    Vec_801ACD14 f38;
    u8 pad44[0x50 - 0x44];
    Vec_801ACD14 f50;
    u8 pad5C[0x334 - 0x5C];
    Vec_801ACD14 f334;
    u8 pad340[4];
    f32 f344;
    u8 pad348[0x350 - 0x348];
    void *f350;
    u16 f354[10];
    s16 f368;
};

struct Flags_801ACB14 {
    u8 pad0[0x18];
    u32 f18;
};

struct Line_801ACB14 {
    u8 pad0[0x38];
    Vec_801ACD14 pos;
    u8 pad44[0xA4 - 0x44];
    Flags_801ACB14 *fA4;
    u8 padA8[0x2FC - 0xA8];
    Vec_801ACD14 f2FC;
    u8 pad308[0x334 - 0x308];
    Vec_801ACD14 vel;
    u8 pad340[4];
    f32 f344;
    u8 pad348[0x354 - 0x348];
    u16 ids[10];
    u16 count;
};

extern "C" {
void __ct__13TUnk_804806E8FP7TObject(void *, void *);
void *find_entity_by_id(u16);
void init_collision_body_parts(void *, void *, s32);
extern u8 photon_line_collision_body_part[];
extern s32 __vt__11TPhotonLine[];
extern s32 lbl_805D3500;
Line_801ACD14 *TPhotonLine__ct(Line_801ACD14 *self, Params_801ACD14 *p, void *parent, u16 arg3);
s32 check_path_obstructed(void *, Vec_801ACD14 *);
u16 get_entity_id(void *);
void queue_destruction__7TObjectFv(void *);
u8 *get_battle_param__10TObjPlayerFi(s32);
void *spawn_particle_effect(void *pos, s32 id);
void queue_photon_blast_hit(s32, s32, s32, f32);
void vec3_add_to(Vec_801ACD14 *, Vec_801ACD14 *);
extern const f32 lbl_805DC1D8;
void run_task__11TPhotonLineFv(Line_801ACB14 *self);
void *__dt__11TPhotonLineFv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);

void TPhotonLine::render() { TParticleCtrl::begin_effect_render(); TParticleCtrl::end_effect_render(); }

void run_task__11TPhotonLineFv(Line_801ACB14 *self) {
    Vec_801ACD14 v = self->pos;
    s32 i;
    u8 *p;
    s32 j;
    vec3_add_to(&v, &self->vel);
    VecCopy((Vec *)&self->f2FC, (const Vec *)&self->pos);
    self->f2FC.y += lbl_805DC1D8;
    v.y += lbl_805DC1D8;
    if (check_path_obstructed(self, &v) == 1) {
        queue_destruction__7TObjectFv(self);
        return;
    }
    TObjPlayer::init_all_slots();
    ((TUnk_804AF8A0 *)self)->mark_enemy_body_contacts();
    if (self->fA4->f18 & 0x100000) {
        for (i = 0; i < 16; i++) {
            p = get_battle_param__10TObjPlayerFi(i);
            if (p == NULL) {
                break;
            }
            for (j = 0; j < self->count; j++) {
                if (self->ids[j] == get_entity_id(p)) {
                    break;
                }
            }
            if (j == self->count) {
                self->ids[self->count++] = get_entity_id(p);
                if ((s32)self->count >= 9) {
                    break;
                }
                queue_photon_blast_hit(get_entity_id(p), 1, 0, self->f344);
                spawn_particle_effect(p + 0x38, 0x162);
                spawn_particle_effect(p + 0x38, 0x163);
            }
        }
    }
    self->pos.x += self->vel.x;
    self->pos.z += self->vel.z;
}

void *__dt__11TPhotonLineFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TPhotonLine;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804806E8 *)arg0)->destroy_motion_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
Line_801ACD14 *TPhotonLine__ct(Line_801ACD14 *self, Params_801ACD14 *p, void *parent, u16 arg3) {
    s32 i;
    __ct__13TUnk_804806E8FP7TObject(self, parent);
    self->vt18 = ((s32 *)&__vt__11TPhotonLine);
    self->f0 = lbl_805D3500;
    VecCopy((Vec *)&self->f50, (const Vec *)(VecCopy((Vec *)((Vec *)&self->f38), (const Vec *)((const Vec *)&p->pos))));
    VecCopy((Vec *)&self->f334, (const Vec *)&p->dir);
    self->f334.x *= p->scale;
    self->f334.y *= p->scale;
    self->f334.z *= p->scale;
    self->f344 = p->f1C;
    self->f350 = find_entity_by_id(arg3);
    init_collision_body_parts(self, photon_line_collision_body_part, 1);
    ((TUnk_804AF8A0 *)self)->refresh_collision_body_centers();
    ((TObjPlayer *)self)->register_object_by_id();
    for (i = 0; i < 10; i++) {
        self->f354[i] = 0xFFFF;
    }
    self->f368 = 0;
    return self;
}

}
