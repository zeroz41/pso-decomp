#include "types.h"
#include "pso/object/TObjCGrass.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/obj_band.h"
#include "pso/system/vector.h"

#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct Rec_800B8B08 { u8 vec[0x18]; s32 f18; u32 flags; };

struct Obj_800B8B08 { u8 pad0[0x24]; s32 f24; u8 pad28[0x34 - 0x28]; s32 f34; u8 pad38[0xC0 - 0x38]; f32 fc0; u8 padc4[0xF8 - 0xC4]; s32 ff8; Rec_800B8B08 *recs; u8 pad100[4]; s32 count; };

struct Vec_800B8BB4 { f32 x, y, z; };

struct Rec_800B8BB4 { Vec_800B8BB4 pos; Vec_800B8BB4 v2; s32 f18; u32 flags; };

struct Hit_800B8BB4 { u8 pad0[4]; Vec_800B8BB4 *pos; };

struct Grass_800B8BB4 {
    u8 pad0[0x3C];
    f32 f3C;
    u8 pad40[4];
    Vec_800B8BB4 f44;
    u8 pad50[0xC0 - 0x50];
    f32 fC0;
    u8 padC4[4];
    f32 fC8;
    u8 padCC[0xFC - 0xCC];
    Rec_800B8BB4 *recs;
    f32 f100;
    s32 count;
    s32 f108;
    u8 f10C[4];
};

struct Vec_800B8EFC { f32 x, y, z; };

struct Rec_800B8EFC { Vec_800B8EFC pos; Vec_800B8EFC v2; s32 f18; u32 flags; };

struct Src_800B8EFC { u8 pad0[8]; s32 f8; s32 fC; };

struct Mgr_800B8EFC { u8 pad0[0x42C]; Src_800B8EFC *src; s32 f430; };

struct Grass_800B8EFC {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    s32 f34;
    Vec_800B8EFC f38;
    u8 pad44[0xC4 - 0x44];
    f32 fC4;
    u8 padC8[0xD8 - 0xC8];
    void *fD8;
    s32 fDC;
    u8 padE0[0xFC - 0xE0];
    Rec_800B8EFC *recs;
    f32 f100;
    s32 count;
    s32 f108;
    u8 f10C[4];
};

extern "C" {
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(int, int);
s32 push_matrix_from(void *src);
s32 pop_matrices(s32 arg0);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
void queue_destruction__7TObjectFv(void *arg0);
u8 *csnVectorUnder(void *, void *, int);
s32 vec3_add_to(void *, void *);
extern s32 actor_frame_tick;
extern const f32 lbl_805D9E60;
extern const f32 TObjCGrass__data_805D9E64;
s32 __ct__10TObjMotionFP7TObject(void *, s32);
void *mem_alloc(u32 size);
s32 rand(void);
s32 rotate_vector_by_matrix(int, void *, void *);
extern s32 cgrass_action_desc[];
extern s32 __vt__10TObjCGrass[];
extern u8 identity_matrix[];
extern s32 lbl_805D2A28;
extern u32 TObjCGrass_bml_resource;
extern s32 tl_06;
extern const f32 lbl_805D9E6C;
extern const f32 lbl_805D9E70;
extern const f32 lbl_805D9E74;
extern const f32 lbl_805D9E78;
u8 *TObjCGrass__ct(Grass_800B8EFC *self, u8 *arg1, s32 arg2, s32 arg3);
void TLobby__sub_8001FE7C(void*, int);
void mem_free(void *);

struct Stack_800B8DC4 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
};
u8 *load_resource_from_descriptor(void *, s32, s32 *, s32, s32, s32);
u8 *load_enemy_bml_resource_named(s32 *, s32 *);
struct RecoveredGlobal_800B8DC4_lbl_8043B628 {
    s32 value;
    u8 remaining[0xC];
};
typedef char RecoveredGlobal_800B8DC4_lbl_8043B628_size[sizeof(RecoveredGlobal_800B8DC4_lbl_8043B628) == 0x10 ? 1 : -1];
extern RecoveredGlobal_800B8DC4_lbl_8043B628 cgrass_anim_binding;
struct RecoveredGlobal_800B8DC4_lbl_8043B638 {
    s32 value;
    u8 remaining[0x10];
};
typedef char RecoveredGlobal_800B8DC4_lbl_8043B638_size[sizeof(RecoveredGlobal_800B8DC4_lbl_8043B638) == 0x14 ? 1 : -1];
extern RecoveredGlobal_800B8DC4_lbl_8043B638 lbl_8043B638;
struct RecoveredGlobal_800B8DC4_lbl_80492500 {
    s32 value;
    u8 remaining[0xC];
};
typedef char RecoveredGlobal_800B8DC4_lbl_80492500_size[sizeof(RecoveredGlobal_800B8DC4_lbl_80492500) == 0x10 ? 1 : -1];
extern RecoveredGlobal_800B8DC4_lbl_80492500 bm_ene_cgrass_resource_descriptor;
extern const f32 lbl_805D9E68;

void* fn_800B8B00(void* p) { return (char*)p + 0x3e8; }

void TObjCGrass::render() {
    Obj_800B8B08 *arg0 = (Obj_800B8B08 *)this;
    s32 i;
    TObjFish::set_global_param(this->texlist);
    for (i = 0; i < *(s32 *)&this->m_104; i++) {
        if (!(arg0->recs[i].flags & 1)) {
            push_matrix_from(0);
            translate_matrix_vec3((u8 *)(0), (u8 *)&arg0->recs[i]);
            rotate_matrix_y(0, arg0->recs[i].f18);
            draw_model_motion((void *)arg0->f34, (void *)*(s32 *)&this->unknownF8, this->m_c0);
            set_default_alpha_blend();
            pop_matrices(1);
        }
    }
}

void TObjCGrass::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 i;
    Grass_800B8BB4 *self = (Grass_800B8BB4 *)arg0;
    Vec_800B8BB4 a;
    Vec_800B8BB4 b;
    Hit_800B8BB4 *hit;
    self->fC0 += self->fC8;
    if (self->f100 < self->fC0) {
        self->fC0 -= self->f100;
    }
    for (i = 0; i < self->count; i++) {
        VecCopy((Vec *)&a, (const Vec *)&self->recs[i].pos);
        VecCopy((Vec *)&b, (const Vec *)&self->recs[i].v2);
        VecCopy((Vec *)&self->f44, (const Vec *)&a);
        vec3_add_to(&a, &b);
        if (i == actor_frame_tick % self->count) {
            hit = (Hit_800B8BB4 *)csnVectorUnder(&a, self->f10C, 1);
            if (hit != NULL) {
                VecCopy((Vec *)&a, (const Vec *)hit->pos);
                b.y += lbl_805D9E60;
                self->f44.y += b.y;
                if (a.y < self->f44.y) {
                    a.y = self->f44.y;
                } else {
                    b.y = TObjCGrass__data_805D9E64;
                }
                VecCopy((Vec *)&self->recs[i].pos, (const Vec *)&a);
                VecCopy((Vec *)&self->recs[i].v2, (const Vec *)&b);
            } else {
                self->recs[i].flags |= 1;
            }
        } else if (self->f3C <= a.y) {
            b.y = TObjCGrass__data_805D9E64;
        } else {
            b.y += lbl_805D9E60;
        }
        VecCopy((Vec *)&self->recs[i].pos, (const Vec *)&a);
        VecCopy((Vec *)&self->recs[i].v2, (const Vec *)&b);
    }
    if (self->f108-- < 0) {
        queue_destruction__7TObjectFv(self);
    }
}

void TObjCGrass::release_global_805D5130() {
    if ((u32) TObjCGrass_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjCGrass_bml_resource, 1);
        TObjCGrass_bml_resource = 0U;
    }
}

void TObjCGrass::load_resources() {
    Stack_800B8DC4 stack;

    u8 *temp_r3;
    u8 *temp_r5;
    u8 *var_r0;

    if (TObjEneDD::check_v2_mode() != 0) {
        TObjCGrass_bml_resource = (u32) load_enemy_bml_resource_named(&bm_ene_cgrass_resource_descriptor.value, &lbl_8043B638.value);
    } else {
        temp_r3 = (u8 *)((int)::operator new(0x440));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(load_resource_from_descriptor(temp_r3, 1, &bm_ene_cgrass_resource_descriptor.value, 0, 0, 0));
        }
        TObjCGrass_bml_resource = (u32) var_r0;
    }
    stack.sp8 = *(s32 *)((s8 *)&cgrass_anim_binding.value + 0);
    stack.spC = *(s32 *)((s8 *)&cgrass_anim_binding.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&cgrass_anim_binding.value + 8);
    stack.sp14 = *(s32 *)((s8 *)&cgrass_anim_binding.value + 0xC);
    stack.sp8 = *(s32 *)((s8 *)TObjCGrass_bml_resource + 0x430);
    temp_r5 = (u8 *)(*(u8 **)((s8 *)TObjCGrass_bml_resource + 0x42C));
    TLobby::spawn_npc_enemy((s16)(0x36), (s32)((int) (*(s32 *)((s8 *)temp_r5 + 8))), (s32)((int) (*(s32 *)((s8 *)temp_r5 + 0xC))), (s32)((void *)&stack.sp8), (f32)lbl_805D9E68, (f32)TObjCGrass__data_805D9E64);
}

}
TObjCGrass::~TObjCGrass() {
    if (*(void **)((s8 *)this + 0xFC) != NULL) { mem_free(*(void **)((s8 *)this + 0xFC)); }
}

#pragma push
#pragma fp_contract on
u8 *TObjCGrass__ct(Grass_800B8EFC *self, u8 *arg1, s32 arg2, s32 arg3) {
    u8 *hit;
    __ct__10TObjMotionFP7TObject(self, tl_06);
    self->vt = __vt__10TObjCGrass;
    ((TObjPlayer *)(self->f10C))->register_object();
    self->f0 = lbl_805D2A28;
    hit = csnVectorUnder(arg1, self->f10C, 1);
    if (hit != NULL) {
        VecCopy((Vec *)&self->f38, (const Vec *)(*(void **)(hit + 4)));
    } else {
        VecCopy((Vec *)&self->f38, (const Vec *)arg1);
    }
    self->f34 = (*(Mgr_800B8EFC * *)&TObjCGrass_bml_resource)->src->f8;
    self->f24 = (*(Mgr_800B8EFC * *)&TObjCGrass_bml_resource)->src->fC;
    self->fDC = (*(Mgr_800B8EFC * *)&TObjCGrass_bml_resource)->f430;
    self->fD8 = cgrass_action_desc;
    ((TObjMotion *)self)->set_field_d8((s32)self->fD8);
    ((TObjMotion *)self)->set_animation(0);
    self->f100 = self->fC4 - lbl_805D9E6C;
    self->count = arg2;
    if (arg2 != 0) {
        self->recs = (Rec_800B8EFC *)mem_alloc(self->count << 5);
    } else {
        self->recs = NULL;
    }
    {
    s32 i;
    for (i = 0; i < self->count; i++) {
        s32 a;
        Vec_800B8EFC v;
        VecCopy((Vec *)&self->recs[i].pos, (const Vec *)&self->f38);
        v.x = TObjCGrass__data_805D9E64;
        v.y = lbl_805D9E70 * (f32)rand();
        v.z = lbl_805D9E70 * (f32)rand() + lbl_805D9E6C;
        a = (s32)(lbl_805D9E74 * (lbl_805D9E78 * (lbl_805D9E70 * (f32)rand())));
        self->recs[i].f18 = a;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, a);
        rotate_vector_by_matrix(0, &v, &self->recs[i].v2);
        pop_matrices(1);
        self->recs[i].flags = 0;
    }
    }
    self->f108 = arg3;
    return (u8 *)self;
}
#pragma pop

