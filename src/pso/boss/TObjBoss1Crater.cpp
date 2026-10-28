#include "types.h"
#include "pso/boss/TBoss8Dragon_800BC53C.h"
#include "pso/system/vector.h"
#include "pso/boss/TObjBoss1Crater.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/TObject.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

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
    s32 f0;
    u8 pad4[0x18 - 0x4];
    s32 *vt;
    u8 pad1c[0x38 - 0x1C];
    u8 pos[0x60 - 0x38];
    s32 f60;
    u8 pad64[0xA4 - 0x64];
    Sub_8002C544 *fA4;
    u8 padA8[0xB0 - 0xA8];
    s32 fB0;
    void *fB4;
    s32 fB8[4];
    s32 fC8;
};

struct V3_8002C544 { f32 x, y, z; };

struct Arg_8002C288 { s32 a; f32 b; s32 c[3]; };

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
s32 create_particle_emitter(void *, int, f32);
void construct_collision_body(void *);
s32 rand();
extern const V3_8002C544 lbl_80435560;
extern s32 __vt__15TObjBoss1Crater[];
extern Crater_8002C544 *TObjBoss1Crater__instance_list[];
extern s32 TObjBoss1Crater__name;
extern s32 TObjBoss1Crater__instance_count;
extern const f32 lbl_805D8160;
extern const f32 lbl_805D8164;
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

extern u8 *lbl_805D4B50;
extern s32 dragon_common_texture_list;
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
        Arg_8002C288 arg = *(Arg_8002C288 *)&lbl_80435560;
        arg.b = TBoss1Dragon__sub_80027634(self->fAC);
        arg.a = self->fC8;
        n = TObjBoss1Crater__sub_8002C7E4(self->fB4);
        if (self->m12((u8 *)&lbl_80435560 + 0xC, &arg, self->fB4) != 0) {
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

void *__dt__15TObjBoss1CraterFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TObjBoss1Crater;
        if (((TObjBoss1Crater *)arg0)->m_b4 != NULL) { delete_buffer__12TBoss8DragonFis((s32)(((TObjBoss1Crater *)arg0)->m_b4), 1); *(s32 *)((s8 *)arg0 + 0xB4) = 0; }
        if (*(void **)((s8 *)arg0 + 0xB0) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xB0)); *(s32 *)((s8 *)arg0 + 0xB0) = 0; }
        ((TUnk_804928CC *)arg0)->destroy_enemy_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

Crater_8002C544 *TObjBoss1Crater__ct(Crater_8002C544 *self, void *arg1, void *arg2, void *arg3) {
    f32 r;
    void *p;
    s32 i;
    construct_collision_body(self);
    self->vt = ((s32 *)&__vt__15TObjBoss1Crater);
    r = lbl_80435560.z;
    self->f0 = TObjBoss1Crater__name;
    self->fA4->fC = r;
    VecCopy((Vec *)self->pos, (const Vec *)arg3);
    r = lbl_805D8164 * (f32)rand();
    self->f60 = (s32)(lbl_805D8160 * r);
    self->fB0 = create_particle_emitter(self->pos, 0x40, r);
    p = ::operator new(0x10);
    if (p != NULL) {
        p = TBoss8Dragon__sub_800BC5EC((u8 *)p, 4);
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
