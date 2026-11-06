#include "types.h"
#include "pso/boss/TObjBoss1Crater.h"
#include "pso/boss/TBoss8Dragon_800BC53C.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/TObject.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TObjBoss1Crater_8002C6B4.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/misc/TLobby.h"
#include "pso/boss/ObjBoss1CommonResource.h"
#include "pso/boss/TBoss4Type2_800874F4.h"

extern "C" {
s32 isV2Mode__12TBoss1DragonFv(void);
s32 load_enemy_bml_resource_named(void *, const char *);
s32 load_enemy_bml_resource(u8 *arg0);
u8 *load_gvm_texture_file(s32 arg0);
s32 lbl_805D4B50;
s32 dragon_common_texture_list;
s32 TObjBoss1Crater__instance_count;
void load_dragon_ground_assets(void);
void load_dragon_ground_assets(void) {
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        lbl_805D4B50 = load_enemy_bml_resource((u8 *)&dragon_ground_resource_descriptor);
        dragon_common_texture_list = (s32)load_gvm_texture_file((s32)dragon_common_texture_filename);
        break;
    case 1:
        lbl_805D4B50 = load_enemy_bml_resource_named(&dragon_ground_resource_descriptor, dragon_common_alternate_bml_filename);
        dragon_common_texture_list = (s32)load_gvm_texture_file((s32)dragon_common_alternate_texture_filename);
        break;
    }
}

}

struct Arg_8002C288 { s32 a; f32 b; f32 c; s32 d[2]; };

// run_task's hit-check argument (kind, radius, height) and the pair it passes next to it; the ct reads the height.
extern const Arg_8002C288 lbl_80435560 = { 1, 50.0f, 20.0f, { 0, 1 } };
const char *TObjBoss1Crater__name = "TObjBoss1Crater";

struct VBase_18_5c1903 { char pad[0x18]; };

struct VObj_18_5c1903 : VBase_18_5c1903 {
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
    virtual s32 m21(s32, s32 *, void *, s32, s32);
    u8 pad1c[0x30 - 0x1C];
    u32 f30;
    u8 pad34[0xA4 - 0x34];
    struct Ent_8002C3FC *ents;
    s32 count;
};

struct Ent_8002C3FC { u8 pad0[0x18]; u32 flags; u8 pad1c[0x2C - 0x1C]; };

struct V2_8002C3FC { s32 a, b; };

struct Src_8002C3FC { u8 pad[0xAC]; s32 fAC; u8 padB0[0xC8 - 0xB0]; s32 fC8; };

struct Sub_8002C544 { u8 pad[0xC]; f32 fC; };

struct Crater_8002C544 {
    const char *f0;
    u8 pad4[0x18 - 0x4];
    s32 *vt;
    u8 pad1c[0x38 - 0x1C];
    u8 pos[0x60 - 0x38];
    s32 f60;
    u8 pad64[0xA4 - 0x64];
    Sub_8002C544 *fA4;
    u8 padA8[0xB0 - 0xA8];
    TParticleCtrl *fB0;
    void *fB4;
    s32 fB8[4];
    s32 fC8;
};

Crater_8002C544 *TObjBoss1Crater__instance_list[20];


struct VBase_8002C288 { u8 pad[0x18]; };

struct Crater_8002C288 : VBase_8002C288 {
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
    virtual s32 m12(void *, Arg_8002C288 *, void *);
    u8 pad1c[0xAC - 0x1C];
    u32 fAC;
    u8 padB0[0xB4 - 0xB0];
    void *fB4;
    s32 fB8[4];
    s32 fC8;
};

extern "C" {
void TBoss1Dragon__sub_8002AB6C(u8 *arg0);
s32 isV2Mode__12TBoss1DragonFv();
void __ct__13TUnk_804928CCFP7TObjectP8TObjBase(void *);
s32 rand();
extern s32 __vt__15TObjBoss1Crater[];
Crater_8002C544 *TObjBoss1Crater__ct(Crater_8002C544 *self, void *arg1, void *arg2, void *arg3);
f32 TBoss1Dragon__sub_80027634(u32);
s32 TObjBoss1Crater__sub_8002C7E4(void *);
}
void attack_target_list_remove(u8 *arg0, s32 arg1);
extern "C" {
s32 post_translate_matrix(void *);
void draw_chunk_object(void *child);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
void __dl__7TObjectFPv(void *);
void queue_destruction__7TObjectFv(void *);

extern s32 model_render_flags;

void TObjBoss1Crater::render() {
    push_matrix();
    TObjFish::set_global_param(dragon_common_texture_list);
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    model_render_flags |= 0x01000000;
    draw_chunk_object((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)lbl_805D4B50 + 0x42C)) + 8)));
    model_render_flags &= 0xFEFFFFFF;
    pop_matrix();
}

void TObjBoss1Crater::run_task() {
    Crater_8002C288 *self = (Crater_8002C288 *)this;
    s32 n;
    if (self->fAC == 0) {
        return;
    }
    if (((TObject *)((void *)self->fAC))->all_parents_unqueued_for_destruction() == 0) {
        self->fAC = 0;
        return;
    }
    {
        Arg_8002C288 arg = lbl_80435560;
        arg.b = TBoss1Dragon__sub_80027634(self->fAC);
        arg.a = self->fC8;
        n = TObjBoss1Crater__sub_8002C7E4(self->fB4);
        if (self->m12((void *)lbl_80435560.d, &arg, self->fB4) != 0) {
            s32 m = TObjBoss1Crater__sub_8002C7E4(self->fB4);
            for (s32 j = n; j < m; j++) {
                self->fB8[j] = 0x3C;
            }
        }
    }
    {
        n = TObjBoss1Crater__sub_8002C7E4(self->fB4);
        for (s32 i = 0; i < n; i++) {
            if (self->fB8[i] <= 0) {
                attack_target_list_remove((u8 *)self->fB4, i);
                self->fB8[i] = self->fB8[n - 1];
                self->fB8[n - 1] = 0;
                i--;
                n--;
            } else {
                self->fB8[i]--;
            }
        }
    }
}

void TObjBoss1Crater::area_attack_receive_direct(void *self_arg, f32 *arg2, void *arg3_arg) {
    Src_8002C3FC *arg0 = (Src_8002C3FC *)this;
    VObj_18_5c1903 *self = (VObj_18_5c1903 *)self_arg;
    s32 *arg3 = (s32 *)arg3_arg;
    s32 off;
    s32 i;
    Ent_8002C3FC *e;
    off = 0;
    for (i = 0; i < self->count; i++) {
        e = (Ent_8002C3FC *)((u8 *)self->ents + off);
        if (e->flags & 0x04000000) {
            V2_8002C3FC sp8 = *(V2_8002C3FC *)arg3;
            self->m21(arg0->fAC, (s32 *)&sp8, e, -1, -1);
            if (arg0->fC8 == 0x13 && !(self->f30 & 0x20)) {
                TBoss1Dragon__sub_8002AB6C((u8 *)self);
            }
            return;
        }
        off += 0x2C;
    }
}

}
TObjBoss1Crater::~TObjBoss1Crater() {
    if (this->m_b4 != NULL) { __dt__17AreaAttackHistoryFv((s32)(this->m_b4), 1); *(s32 *)((s8 *)this + 0xB4) = 0; }
    if (*(void **)((s8 *)this + 0xB0) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0xB0)); *(s32 *)((s8 *)this + 0xB0) = 0; }
}
extern "C" {

Crater_8002C544 *TObjBoss1Crater__ct(Crater_8002C544 *self, void *arg1, void *arg2, void *arg3) {
    f32 r;
    void *p;
    s32 i;
    __ct__13TUnk_804928CCFP7TObjectP8TObjBase(self);
    self->vt = ((s32 *)&__vt__15TObjBoss1Crater);
    r = lbl_80435560.c;
    self->f0 = TObjBoss1Crater__name;
    self->fA4->fC = r;
    VecCopy((Vec *)self->pos, (const Vec *)arg3);
    self->f60 = (s32)(65536.0f * ((1.0f / 32768.0f) * (f32)rand()));
    self->fB0 = create_particle_emitter(self->pos, 0x40);
    p = ::operator new(0x10);
    if (p != NULL) {
        p = __ct__17AreaAttackHistoryFl((u8 *)p, 4);
    }
    self->fB4 = p;
    for (i = 0; i < 4; i++) {
        self->fB8[i] = 0;
    }
    if (TObjBoss1Crater__instance_count < 0x14) {
        TObjBoss1Crater__instance_list[TObjBoss1Crater__instance_count++] = self;
    }
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        self->fC8 = 1;
        break;
    case 1:
        self->fC8 = 0x13;
        break;
    }
    return self;
}

s32 TObjBoss1Crater::is_count_below_limit() {
    return TObjBoss1Crater__instance_count < 0x14;
}
}


struct Ent_8002C730 { u8 pad0[0x38]; f32 f38; u8 pad3c[4]; f32 f40; };

struct Obj_8002C730 { f32 x; u8 pad[4]; f32 z; };

extern "C" {
f32 newton_sqrtf(f32);
f32 calc_nearest_crater_distance(Obj_8002C730 *self);
void *__nw__7TObjectFUl(int);
void *get_instance__12TBoss1DragonFv(void);
int is_count_below_limit__15TObjBoss1CraterFv(void *, void *);

void *TObjBoss1Crater::create(void *arg1) {
    void *x1;
    void *o;
    if (is_count_below_limit__15TObjBoss1CraterFv(this, arg1) == 0) {
        return NULL;
    }
    x1 = get_instance__12TBoss1DragonFv();
    if (x1 == NULL) {
        return NULL;
    }
    o = __nw__7TObjectFUl(0xCC);
    if (o != NULL) {
        o = TObjBoss1Crater__ct((Crater_8002C544 *)o, this, x1, arg1);
    }
    return o;
}

#pragma push
#pragma fp_contract on
f32 calc_nearest_crater_distance(Obj_8002C730 *self) {
    f32 best;
    s32 i;
    f32 x;
    f32 z;
    f32 d;
    f32 dx;
    f32 dz;
    best = 100000000.0f;
    if (TObjBoss1Crater__instance_count == 0) {
        return 0.0f;
    }
    x = self->x;
    z = self->z;
    for (i = 0; i < TObjBoss1Crater__instance_count; i++) {
        Ent_8002C730 *e = (Ent_8002C730 *)TObjBoss1Crater__instance_list[i];
        dx = e->f38 - x;
        dz = e->f40 - z;
        d = dx * dx + dz * dz;
        if (d < best) {
            best = d;
        }
    }
    return newton_sqrtf(best);
}
#pragma pop

void TObjBoss1Crater__sub_8002C7B4(void) {  }

void TObjBoss1Crater__sub_8002C7B8(void) {
    s32 i;
    TObjBoss1Crater__instance_count = 0;
    for (i = 0; i < 20; i++) {
        TObjBoss1Crater__instance_list[i] = 0;
    }
}

s32 TObjBoss1Crater__sub_8002C7E4(void* p) { return *(s32*)((char*)p + 0x8); }
}
void attack_target_list_remove(u8 *arg0, s32 arg1) {
    s32 temp_r5;
    s32 temp_r5_2;
    if (arg1 >= 0) {
        temp_r5 = *(s32 *)((s8 *)arg0 + 8);
        if (arg1 < temp_r5) {
            *(s32 *)((s8 *)arg0 + 8) = (temp_r5 - 1);
            temp_r5_2 = *(s32 *)((s8 *)arg0 + 0);
            *(s32 *)((s8 *)temp_r5_2 + (arg1 * 4)) = *(s32 *)((s8 *)temp_r5_2 + (*(s32 *)((s8 *)arg0 + 8) * 4));
            *(s32 *)((s8 *)(*(s32 *)((s8 *)arg0 + 0)) + (*(s32 *)((s8 *)arg0 + 8) * 4)) = *(s32 *)((s8 *)arg0 + 4);
        }
    }
}
