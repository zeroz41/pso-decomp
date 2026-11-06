#include "types.h"
#include "pso/enemy/TObjEneRe2Flower_EffCurse3.h"
#include "pso/enemy/TObjEneRe2Flower_800C4B78.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/TObject.h"

#include "pso/enemy/TUnk_80493450.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjEneRe2Flower_Bomb.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneBeast.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TNowLoading.h"
#include "pso/effect/TParticleCtrl.h"

typedef struct Vec_800C4A5C {
    f32 x, y, z;
} Vec_800C4A5C;

typedef struct Coll_800C4A5C {
    u8 pad0[0xC];
    f32 radius;
} Coll_800C4A5C;

typedef struct Obj_800C4A5C {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vptr;
    u8 pad1C[0x38 - 0x1C];
    Vec_800C4A5C pos;
    u8 pad44[0xA4 - 0x44];
    Coll_800C4A5C *coll;
    u8 padA8[0xB0 - 0xA8];
    u16 ownerId;
    u8 padB2[0xB4 - 0xB2];
    Vec_800C4A5C start;
    Vec_800C4A5C velA;
    Vec_800C4A5C velB;
    Vec_800C4A5C accel;
    f32 fE4;
    s32 fE8;
    s32 angle;
    f32 fF0;
    s32 fF4;
    s32 fF8;
    s32 fFC;
    s32 f100;
} Obj_800C4A5C;

typedef struct Vec_800C4B78 {
    f32 x, y, z;
} Vec_800C4B78;

typedef struct Ent_800C4B78 {
    u8 pad0[0x38];
    Vec_800C4B78 pos;
} Ent_800C4B78;

typedef struct Obj_800C4B78 {
    u8 pad0[0x1C];
    s32 timer;
    Ent_800C4B78 *target;
    s32 effect;
} Obj_800C4B78;

typedef struct Obj_800C55E0 {
    u8 pad0[0xB8];
    s16 fB8;
    u8 padBA[0x326 - 0xBA];
    s16 state;
    s16 f328;
    u8 pad32A[0x34C - 0x32A];
    void *f34C;
} Obj_800C55E0;

extern "C" {
s32 subtract_vector(void *, void *);

extern void *player_render_texture_buffer;
void release_texture_list(void *);
void mem_free(void *);
s32 is_alive__8TObjBaseFv(s32);
extern u8 *camera_ctrl_instance;
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);

extern const char lbl_8043BC48[0x1C] = "TObjEneRe2Flower_EffCurse3";
s32 lbl_805D2A58 = (s32)lbl_8043BC48;
extern void *__vt__26TObjEneRe2Flower_EffCurse3[];
#define __vt__26TObjEneRe2Flower_EffCurse3 ((s32 *)__vt__26TObjEneRe2Flower_EffCurse3)
#pragma push
#pragma fp_contract on
void TObjEneRe2Flower_EffCurse3::run_task() {
    Obj_800C4B78 *o = (Obj_800C4B78 *)this;
    Vec_800C4B78 a;
    Vec_800C4B78 b;
    o->timer++;
    if (o->timer > 20) {
        queue_destruction__7TObjectFv((o));
        return;
    }
    if (is_alive__8TObjBaseFv((s32)o->target) != 0) {
        VecCopy((Vec *)&a, (const Vec *)&o->target->pos);
        a.y += (14.0f);
        VecCopy((Vec *)&b, (const Vec *)(camera_ctrl_instance + 0x178));
        subtract_vector(&b, &a);
        ((TObjBoss2Tunnel *)(&b))->update_scale();
        a.x = (2e+01f) * b.x + a.x;
        a.y = (2e+01f) * b.y + a.y;
        a.z = (2e+01f) * b.z + a.z;
        ((TParticleCtrl *)o->effect)->set_position(&a);
    }
}
#pragma pop

}
TObjEneRe2Flower_EffCurse3::~TObjEneRe2Flower_EffCurse3() {
    if (*(void * *)&this->unk_24 != NULL) { queue_destruction__7TObjectFv((*(void * *)&this->unk_24)); *(s32 *)&this->unk_24 = 0; }
}
TObjEneRe2Flower_EffCurse3::TObjEneRe2Flower_EffCurse3(s32 arg1, s32 arg2) : TObject((TObject *)arg1) {
    *(s32 *)&this->m_name = (s32) lbl_805D2A58;
    *(s32 *)((s8 *)this + 0x1C) = 0;
    (this->m_20) = arg2;
    if (is_alive__8TObjBaseFv((this->m_20)) != 0) {
        *(s32 *)&this->unk_24 = (s32)spawn_continuous_particle_effect_with_flags((void *)((this->m_20) + 0x38), 0xDE, 0x40);
    }
}
extern "C" {

struct Node_800C4D88 { void *p; s32 v; };
struct A_800C4D88 { u8 x[0x24]; };
struct B_800C4D88 { u8 x[0xC]; };
A_800C4D88 player_render_target;
B_800C4D88 player_render_texture_name;
__declspec(section ".data") Node_800C4D88 lbl_80500C30;
#define lbl_80500C30 ((u8 *)&lbl_80500C30)

void TObjPlayer__sub_800C4D44(void) {
    void *p = lbl_80500C30;
    if (p != 0) {
        release_texture_list(p);
    }
    if (player_render_texture_buffer != 0) {
        mem_free(player_render_texture_buffer);
        player_render_texture_buffer = 0;
    }
}

void *mem_alloc(u32 size);
void pso_load_texture__6TLobbyFv(void *, void *);
void set_texture_name(void *, void *, s32, s32);
void TObjPlayer::create_render_texture() {
    ((TObjPlayer *)(&player_render_target))->set_render_rect((s32)(player_render_texture_buffer = mem_alloc(0x800)), 0x902, 0x20, 0x20);
    set_texture_name(&player_render_texture_name, &player_render_target, 0x18696, 0x40800000);
    ((Node_800C4D88 *)lbl_80500C30)->p = &player_render_texture_name;
    ((Node_800C4D88 *)lbl_80500C30)->v = 1;
    pso_load_texture__6TLobbyFv(lbl_80500C30, &player_render_texture_name);
}
}
