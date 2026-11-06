#include "types.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/TMainTask.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/TObject.h"
#include "pso/misc/TFogCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TUnk_804835D8.h"
#include "pso/player/TObjPlayer_8002E784.h"
#pragma defer_codegen on

struct Base_8003B138 { char pad[0x18]; };
struct VObj_8003B138 : Base_8003B138 {
    virtual void m0();
    virtual void m1();
};

extern "C" {

struct Obj_8003B250;
void release_children__15TObjBoss2TunnelFPvf(Obj_8003B250 *arg0, f32 farg0);
void *__nw__7TObjectFUl(s32);


}

#undef release_children__15TObjBoss2TunnelFPvf

struct Child_8003B250 { u8 pad0[0x44]; f32 f44; };
struct Obj_8003B250 { u8 pad0[0x14]; Child_8003B250 *child; };
struct Obj_8003B1FC { u8 pad[0x14]; Obj_8003B1FC *child; u8 pad2[0x3c - 0x18]; u8 xf[0xC]; };

extern "C" {
s32 vec3_add_to(void *, void *);
extern void *TObjBoss2Tunnel_parent_object;
void TObjBoss2Tunnel__sub_8003B1D8(void);

extern const f32 lbl_805D85D8;


}

struct S_8003C108 {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[0xC8 - 0x24];
    u32 ptr[4];
};

struct Rec_8003C108 { f32 x, y, z; };

struct Vec_8003B2EC { f32 x, y, z; };

struct Model_8003B2EC { s32 a; s32 b; s32 obj; s32 c; };

struct Models_8003B2EC { u8 pad[0x42C]; Model_8003B2EC *models; };

struct Fog_8003B2EC { s32 a; s32 b; s32 c; };

struct Tunnel_8003B2EC {
    u8 pad0[0x1C];
    f32 f1c;
    u8 pad20[0x4];
    s32 f24;
    u8 pad28[0x4];
    s32 f2c[6];
    u8 pad44[0x1C];
    f32 f60;
    u8 pad64[0x34];
    f32 f98;
    u8 pad9c[0x4];
    s32 fa0;
    u8 pada4[0x4];
    s32 fa8;
    f32 fac;
};

typedef struct Tunnel_8003B6E8 {
    u8 pad0[0x1C];
    f32 f1c;
    f32 f20;
    s32 f24;
    s32 f28;
    u8 pad2c[0x34 - 0x2C];
    s32 f34;
    s32 f38;
    u8 pad3c[0x44 - 0x3C];
    s32 f44;
    s32 f48;
    f32 f4c;
    f32 f50;
    f32 f54;
    s32 f58;
    s32 f5c;
    f32 f60;
    s32 f64;
    u8 f68[0x94 - 0x68];
    f32 f94;
    f32 f98;
    s32 f9c;
    s32 fa0;
    s32 fa4;
    s32 fa8;
    f32 fac;
    s32 fb0;
    s32 fb4;
    s32 fb8;
    s32 fbc;
    u8 padc0[0xD8 - 0xC0];
    s32 fd8;
} Tunnel_8003B6E8;

typedef struct Col_8003B6E8 {
    s32 a;
    f32 r;
    f32 g;
    f32 b;
} Col_8003B6E8;

typedef struct Vec_8003B6E8 {
    f32 x, y, z;
} Vec_8003B6E8;

extern "C" {
s32 create_particle__20TAdLoadQuestPrtTxtGCFPvll(void *, s32, s32);
extern const f32 lbl_805D85B0;
struct O_8003C21C;
u8 * sub_8003C21C__15TObjBoss2TunnelFv(O_8003C21C *self);
s32 rotate_matrix_z(s32, s32);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_object(void *child);
extern Vec_8003B2EC boss2_tunnel_render_zero_vec[];
extern s32 boss2_tunnel_model_index_table[];
extern s32 boss2_tunnel_model_order_table[];
extern Models_8003B2EC *boss2_tunnel_instance;
extern Fog_8003B2EC **lbl_805D4BEC;
void render__15TObjBoss2TunnelFv(u8 *arg0);
f32 sin_table_lookup(s32);
s32 check_flag_or_state__15TObjBoss2TunnelFi(s32 arg0);
s32 is_flag_set__15TObjBoss2TunnelFv(s32 _w0);
void init_piecewise_curve(void *, f32, f32, f32, f32, f32);
f32 fabs_float(f32);
f32 update_position__15TObjBoss2TunnelFv(void *);
struct S_8003C2E4;
void copy_ring_buffer_window__15TObjBoss2TunnelFv(S_8003C2E4 *o);
struct Obj_8003C374;
void init_queue_from_start__15TObjBoss2TunnelFv(Obj_8003C374 *self);
struct Obj_8003C2A0;
void shift_queue_push_next__15TObjBoss2TunnelFPv(Obj_8003C2A0 *self);
void * init__13TUnk_804835D8Fv(void *arg0);
f32 rand_signed_unit(void);
int rand(void);
void *__ct__13TObjBoss2DustFv(void *, void *, Vec_8003B6E8 *);
void play_sound_effect(int, void *, int, int);
void play_persistent_sound(int, void *, int, int, int);
void enable_fog__15TObjBoss2TunnelFv(void);
void enable_fog__15TObjBoss2TunnelFPv(TObjBoss2Tunnel *arg0);
void TObjBoss2Tunnel__sub_801339EC(f32, f32, f32);
extern u32 TObjBoss2Tunnel__global_flags;
void run_task__15TObjBoss2TunnelFv(Tunnel_8003B6E8 *o);
#define release_children__15TObjBoss2TunnelFPvf ((void (*)(u32, f32))release_children__15TObjBoss2TunnelFPvf)
#define sub_8003C21C__15TObjBoss2TunnelFv ((s32 (*)(void *, void *))sub_8003C21C__15TObjBoss2TunnelFv)
#define check_flag_or_state__15TObjBoss2TunnelFi ((s32 (*)(void *))check_flag_or_state__15TObjBoss2TunnelFi)
#define is_flag_set__15TObjBoss2TunnelFv ((s32 (*)(void *))is_flag_set__15TObjBoss2TunnelFv)
#define copy_ring_buffer_window__15TObjBoss2TunnelFv ((void (*)(void *))copy_ring_buffer_window__15TObjBoss2TunnelFv)
#define init_queue_from_start__15TObjBoss2TunnelFv ((void (*)(void *))init_queue_from_start__15TObjBoss2TunnelFv)
#define shift_queue_push_next__15TObjBoss2TunnelFPv ((void (*)(void *))shift_queue_push_next__15TObjBoss2TunnelFPv)
#define __nw__7TObjectFUl ((void * (*)(int))__nw__7TObjectFUl)
#define init__13TUnk_804835D8Fv ((void (*)(void *, void *))init__13TUnk_804835D8Fv)
#define enable_fog__15TObjBoss2TunnelFv ((void (*)(void *))enable_fog__15TObjBoss2TunnelFv)
void TObjBoss2Tunnel__sub_8003B2B0(void);
void *__ct__7TObjectFP7TObject(void *, void *);




struct S_8003C108;
s32 boss2_tunnel_model_index_table[6] = {
    0x14, 0xe, 0xf, 0x10,
    0x11, 0x13,
};
s32 boss2_tunnel_model_order_table[12] = {
    0xc, 0x6, 0x7, 0x8,
    0x9, 0xb, 0x5, 0x0,
    0x1, 0x2, 0x3, 0x4,
};
void *boss2_tunnel_color_table[28] = {
    (void *)0x3f800000, (void *)0x3f800000, (void *)0x3f19999a, (void *)0x3ecccccd,
    (void *)0x3f800000, (void *)0x3f800000, (void *)0x3f4ccccd, (void *)0x3f000000,
    (void *)0x3f800000, (void *)0x3f4ccccd, (void *)0x3f19999a, (void *)0x3e99999a,
    (void *)0x3f800000, (void *)0x3f19999a, (void *)0x3f800000, (void *)0x3ecccccd,
    (void *)0x3f800000, (void *)0x3f800000, (void *)0x3f4ccccd, (void *)0x3ecccccd,
    (void *)0x3f800000, (void *)0x3f800000, (void *)0x3f19999a, (void *)0x3ecccccd,
    (void *)0x3f800000, (void *)0x3f800000, (void *)0x3f19999a, (void *)0x3ecccccd,
};
void *boss2_tunnel_color[4] = {
    (void *)0x3f800000, (void *)0x3f4ccccd, (void *)0x3f4ccccd, (void *)0x3f4ccccd,
};
void *lbl_80483480[15] = {
    (void *)0x1, (void *)0xa, (void *)0x1, (void *)0x5,
    (void *)0x1, (void *)0x2, (void *)0x2, (void *)0x14,
    (void *)0x2, (void *)0x14, (void *)0x4, (void *)0x5,
    (void *)0x4, (void *)0x2, (void *)0xffffffff,
};
static s32 boss2_tunnel_queue_table[6] = {
    2, 2, 3, 1, 2, 4,
};
static s32 boss2_tunnel_ring_queue_table[31] = {
    1, 3, 3, 1, 2, 2, 4, 3,
    3, 1, 1, 2, 3, 3, 1, 4,
    3, 2, 2, 2, 1, 4, 3, 3,
    1, 3, 1, 2, 1, 2, 4,
};
static s32 boss2_tunnel_shift_queue_table[10] = {
    6, 5, 5, 0, 5, 5, 5, 5, 5, 0,
};
static f32 boss2_tunnel_raft_splash_positions[2][3] = {
    {78.0f, lbl_805D825C, 83.0f},
    {-78.0f, lbl_805D825C, 83.0f},
};
static Rec_8003C108 boss2_tunnel_particle_pos_table[4] = {
    {26.0f, -19.0f, 62.0f},
    {-26.0f, -19.0f, 62.0f},
    {26.0f, -19.0f, 0.0f},
    {-26.0f, -19.0f, 0.0f},
};
#define boss2_tunnel_color_table ((Col_8003B6E8 *)boss2_tunnel_color_table)
#define boss2_tunnel_color ((Col_8003B6E8 *)boss2_tunnel_color)
#define lbl_80483480 ((s32 *)lbl_80483480)


}

#undef release_children__15TObjBoss2TunnelFPvf
#undef sub_8003C21C__15TObjBoss2TunnelFv
#undef check_flag_or_state__15TObjBoss2TunnelFi
#undef is_flag_set__15TObjBoss2TunnelFv
#undef copy_ring_buffer_window__15TObjBoss2TunnelFv
#undef init_queue_from_start__15TObjBoss2TunnelFv
#undef shift_queue_push_next__15TObjBoss2TunnelFPv
#undef __nw__7TObjectFUl
#undef init__13TUnk_804835D8Fv
#undef enable_fog__15TObjBoss2TunnelFv

struct S_8003C21C { u8 pad[0x1f]; u8 x; };

struct O_8003C21C { u8 pad[0x5c]; s32 p; };

extern "C" {
s32 TObjBoss2Tunnel__sub_8003C1C8(void);



}

struct Obj_8003C374 { u8 pad[0x28]; s32 start; s32 q[6]; };

struct Obj_8003C2A0 { u8 pad[0x2c]; s32 q[6]; s32 idx; };

struct S_8003C2E4 {
    u8 pad0[0x28];
    s32 f28;
    s32 t[6];
};







#define init_queue_from_start__15TObjBoss2TunnelFv ((void (*)(Tunnel_8003C45C *))init_queue_from_start__15TObjBoss2TunnelFv)
#define __nw__7TObjectFUl ((void * (*)(int))__nw__7TObjectFUl)
#define __ct__7TObjectFP7TObject ((void (*)(void *))__ct__7TObjectFP7TObject)

struct Tunnel_8003C45C {
    s32 name;
    u8 pad4[0x18 - 4];
    void *vt;
    f32 f1C;
    f32 f20;
    s32 i24;
    s32 i28;
    u8 pad2C[0x44 - 0x2C];
    s32 i44;
    u8 pad48[4];
    f32 f4C;
    f32 f50;
    f32 f54;
    s32 i58;
    s32 i5C;
    f32 f60;
    s32 i64;
    u8 sub68[0x94 - 0x68];
    f32 f94;
    f32 f98;
    s32 i9C;
    s32 iA0;
    s32 iA4;
    s32 iA8;
    f32 fAC;
    s32 iB0;
    s32 iB4;
    s32 iB8;
    s32 iBC;
    void *splash[2];
    s32 c8[4];
    s32 d8;
};

extern "C" {
void queue_destruction__7TObjectFv(void *);
extern s32 *lbl_805D4C04;
extern s32 *lbl_805D4C08;
void TObjBoss2Tunnel__sub_8003C5F8(void);
void TObjBoss2Tunnel__sub_8003C610(void);
u8 *TObjBoss2RaftSplash__ct(u8 *arg0, u8 *arg1, f32 *arg2, u8 *arg3, f32 *arg4);
void reset_floats__15TObjBoss2TunnelFv(void *a0);
extern u8 boss2_tunnel_raft_splash_offsets[];
extern s32 __vt__15TObjBoss2Tunnel[];
extern s32 lbl_805D2708;
void *TObjBoss2Tunnel__ct(void *arg0, void *arg1);
void TObjBoss2Tunnel__sub_8003C648(void);
void *__dt__15TObjBoss2TunnelFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

}
extern "C" {














extern s32 __vt__13TUnk_804835D8[];




}

#undef init_queue_from_start__15TObjBoss2TunnelFv
#undef __nw__7TObjectFUl
#undef __ct__7TObjectFP7TObject

#undef boss2_tunnel_instance


#define init_queue_from_start__15TObjBoss2TunnelFv ((void (*)(Tunnel_8003C45C *))init_queue_from_start__15TObjBoss2TunnelFv)
#define __nw__7TObjectFUl ((void * (*)(int))__nw__7TObjectFUl)
#define __ct__7TObjectFP7TObject ((void (*)(void *))__ct__7TObjectFP7TObject)
extern "C" {
void *TUnk_804835D8::init() {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804835D8;
    *(u32 *)&this->unk_1C = 0;
    this->m_20 = (0.0f);
    return this;
}

TUnk_804835D8::~TUnk_804835D8() {}

}
#pragma push
#pragma opt_common_subs off
extern "C" {
void TUnk_804835D8::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    *(s32 *)&this->unk_1C = (s32) (*(s32 *)&this->unk_1C + 1);
    if ((s32) *(s32 *)&this->unk_1C > 0x1E) {
        this->m_20 += (1.0f);
        temp_f1 = this->m_20;
        if (temp_f1 > (7e+01f)) {
            this->m_20 = (f32) (7e+01f);
            queue_destruction__7TObjectFv(arg0);
            return;
        }
        *(f32 *)((s8 *)(*(u8 * *)&lbl_805D4C04) + 8) = (f32) -temp_f1;
        *(f32 *)((s8 *)(*(u8 * *)&lbl_805D4C08) + 8) = (f32) this->m_20;
    }
}

}
#pragma pop
extern "C" {
void TObjBoss2Tunnel::clear_target_flags() {
    s32 *temp_r3;
    s32 *temp_r3_2;

    (*(s32 *)&TObjBoss2Tunnel__global_flags) = 0;
    temp_r3 = *(s32 **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)&boss2_tunnel_instance) + 0x42C)) + 0xA8)) + 0x2C)) + 0x30);
    lbl_805D4C08 = temp_r3;
    temp_r3_2 = *(s32 **)((s8 *)temp_r3 + 0x30);
    lbl_805D4C04 = temp_r3_2;
    *temp_r3_2 &= 0xFFFFFFFE;
    *lbl_805D4C08 &= 0xFFFFFFFE;
}

void *TObjBoss2Tunnel::create() {
    void *o = __nw__7TObjectFUl(0xDC);
    if (o != NULL) {
        o = TObjBoss2Tunnel__ct(o, tl_02);
    }
    return o;
}

void TObjBoss2Tunnel__sub_8003C648(void) {  }

void TObjBoss2Tunnel::set_global_flag_400() {
    (*(s32 *)&TObjBoss2Tunnel__global_flags) |= 0x400;
}

void TObjBoss2Tunnel::set_global_flag_800() {
    (*(s32 *)&TObjBoss2Tunnel__global_flags) |= 0x800;
}

void TObjBoss2Tunnel__sub_8003C610(void) {
    (*(u32 *)&(*(s32 *)&TObjBoss2Tunnel__global_flags)) |= 0x1000;
    (*(u32 *)&(*(s32 *)&TObjBoss2Tunnel__global_flags)) &= ~0x2000;
}

void TObjBoss2Tunnel__sub_8003C5F8(void) {
    (*(u32 *)&(*(s32 *)&TObjBoss2Tunnel__global_flags)) |= 0x2000;
    (*(u32 *)&(*(s32 *)&TObjBoss2Tunnel__global_flags)) &= ~0x1000;
}

void TObjBoss2Tunnel::clear_global_flag_3000() {
    (*(s32 *)&TObjBoss2Tunnel__global_flags) &= 0xFFFFCFFF;
}

s32 TObjBoss2Tunnel::is_active() {
    return (*(s32 *)&TObjBoss2Tunnel__global_flags) & 1;
}

void TObjBoss2Tunnel::set_global_flag_100() {
    (*(s32 *)&TObjBoss2Tunnel__global_flags) |= 0x100;
}

void TObjBoss2Tunnel::set_global_flag_200() {
    (*(s32 *)&TObjBoss2Tunnel__global_flags) |= 0x200;
}

void *TObjBoss2Tunnel__ct(void *object, void *arg1) {
    Tunnel_8003C45C *self = (Tunnel_8003C45C *)object;
    s32 i;
    s32 j;
    __ct__7TObjectFP7TObject(object);
    self->vt = ((s32 *)&__vt__15TObjBoss2Tunnel);
    TObjBoss2Tunnel::reset_floats((s32)self->sub68);
    self->name = lbl_805D2708;
    self->i24 = 0;
    (*(s32 *)&TObjBoss2Tunnel__global_flags) = 0;
    self->f1C = (0.0f);
    self->f20 = (0.0f);
    self->i28 = 0;
    init_queue_from_start__15TObjBoss2TunnelFv(self);
    self->i5C = 0;
    self->f60 = (0.0f);
    self->i44 = 0;
    self->f4C = (0.0f);
    self->f50 = (0.0f);
    self->f54 = (0.0f);
    self->i58 = 0;
    self->i64 = 0;
    reset_floats__15TObjBoss2TunnelFv(self->sub68);
    self->f94 = (1.0f);
    self->f98 = (0.0f);
    self->iB0 = 0x21;
    self->iB4 = 0;
    self->iB8 = 0;
    self->iBC = 0;
    self->i9C = 0;
    self->iA4 = 0;
    self->iA0 = 0;
    self->iA8 = 0;
    self->fAC = (0.0f);
    for (i = 0; i < 2; i++) {
        u8 *o = (u8 *)__nw__7TObjectFUl(0x40);
        if (o != NULL) {
            o = TObjBoss2RaftSplash__ct(o, (u8 *)self, boss2_tunnel_raft_splash_positions[i], boss2_tunnel_raft_splash_offsets + i * 0xC, &self->f20);
        }
        self->splash[i] = o;
    }
    for (j = 0; j < 4; j++) {
        self->c8[j] = 0;
    }
    self->d8 = 0xA;
    return self;
}

}
TObjBoss2Tunnel::~TObjBoss2Tunnel() {
    TObjBoss2Tunnel::dt((s32)((s8 *)this + 0x68), (s16)(-1));
}

#undef init_queue_from_start__15TObjBoss2TunnelFv
#undef __nw__7TObjectFUl
#undef __ct__7TObjectFP7TObject
void TObjBoss2Tunnel::init_queue_from_start() {
    s32 k = ((Obj_8003C374 *)this)->start;
    s32 n = 6 - k;
    s32 i;
    s32 j;
    for (i = 0; i < n; i++) {
        ((Obj_8003C374 *)this)->q[i] = boss2_tunnel_queue_table[k++];
    }
    for (j = 0; i < 6; i++, j++) {
        ((Obj_8003C374 *)this)->q[i] = boss2_tunnel_ring_queue_table[j];
    }
}

void TObjBoss2Tunnel::copy_ring_buffer_window() {
    s32 idx = ((S_8003C2E4 *)this)->f28;
    s32 n = 6;
    s32 i;
    s32 j;
    if (idx + 6 > 0x1F) {
        n = 0x1F - idx;
    }
    s32 k = idx;
    for (i = 0; i < n; i++, k++) {
        ((S_8003C2E4 *)this)->t[i] = boss2_tunnel_ring_queue_table[k];
    }
    for (j = 0; i < 6; i++, j++) {
        ((S_8003C2E4 *)this)->t[i] = boss2_tunnel_ring_queue_table[j];
    }
}

void shift_queue_push_next__15TObjBoss2TunnelFPv(Obj_8003C2A0 *self) {
    s32 i;
    for (i = 0; i < 5; i++) {
        self->q[i] = self->q[i + 1];
    }
    self->q[5] = boss2_tunnel_shift_queue_table[self->idx++];
}

void enable_fog__15TObjBoss2TunnelFv(void) {
    TFogCtrl::update_all(0xB, 1);
    (*(s32 *)&TObjBoss2Tunnel__global_flags) |= 2;
}

void enable_fog__15TObjBoss2TunnelFPv(TObjBoss2Tunnel *boss2_tunnel) {
    TFogCtrl::update_all(boss2_tunnel->m_b0, 1);
    (*(s32 *)&TObjBoss2Tunnel__global_flags) |= 4;
}

extern "C" {
u8 *TObjBoss2Tunnel::sub_8003C21C() {
    if (((O_8003C21C *)this)->p == 0) {
        return 0;
    }
    return &((S_8003C21C *)((O_8003C21C *)this)->p)->x;
}

s32 check_flag_or_state__15TObjBoss2TunnelFi(s32 arg0) {
    s32 temp_r31;
    s32 temp_r3;
    temp_r31 = TObjBoss2Tunnel__sub_8003C1C8();
    temp_r3 = is_flag_set__15TObjBoss2TunnelFv(arg0);
    return temp_r3 | temp_r31;
}

s32 is_flag_set__15TObjBoss2TunnelFv(s32 _w0) {
    return ((u32) TObjBoss2Tunnel__global_flags >> 0xCU) & 1;
}

s32 TObjBoss2Tunnel__sub_8003C1C8(void) {
    return ((u32) TObjBoss2Tunnel__global_flags >> 0xDU) & 1;
}

#define release_children__15TObjBoss2TunnelFPvf ((void (*)(u32, f32))release_children__15TObjBoss2TunnelFPvf)
#define sub_8003C21C__15TObjBoss2TunnelFv ((s32 (*)(void *, void *))sub_8003C21C__15TObjBoss2TunnelFv)
#define check_flag_or_state__15TObjBoss2TunnelFi ((s32 (*)(void *))check_flag_or_state__15TObjBoss2TunnelFi)
#define is_flag_set__15TObjBoss2TunnelFv ((s32 (*)(void *))is_flag_set__15TObjBoss2TunnelFv)
#define copy_ring_buffer_window__15TObjBoss2TunnelFv ((void (*)(void *))copy_ring_buffer_window__15TObjBoss2TunnelFv)
#define init_queue_from_start__15TObjBoss2TunnelFv ((void (*)(void *))init_queue_from_start__15TObjBoss2TunnelFv)
#define shift_queue_push_next__15TObjBoss2TunnelFPv ((void (*)(void *))shift_queue_push_next__15TObjBoss2TunnelFPv)
#define __nw__7TObjectFUl ((void * (*)(int))__nw__7TObjectFUl)
#define init__13TUnk_804835D8Fv ((void (*)(void *, void *))init__13TUnk_804835D8Fv)
#define enable_fog__15TObjBoss2TunnelFv ((void (*)(void *))enable_fog__15TObjBoss2TunnelFv)
void TObjBoss2Tunnel::update_particles() {
    f32 t;
    s32 i;
    u32 r;
    u32 p;
    if (((S_8003C108 *)this)->f20 < lbl_805D85B0) {
        t = (-5.0f) * (((S_8003C108 *)this)->f20 / lbl_805D85B0);
    } else {
        t = (-5.0f);
    }
    for (i = 0; i < 4; i++) {
        p = ((S_8003C108 *)this)->ptr[i];
        if (p == 0) {
            r = create_particle__20TAdLoadQuestPrtTxtGCFPvll(&boss2_tunnel_particle_pos_table[i], 0x171, 1);
            if (r != 0) {
                ((TParticleCtrl *)r)->enable();
                ((S_8003C108 *)this)->ptr[i] = r;
            }
        } else {
            release_children__15TObjBoss2TunnelFPvf(p, t);
        }
    }
}

}
#pragma push
#pragma fp_contract on
extern "C" {
void run_task__15TObjBoss2TunnelFv(Tunnel_8003B6E8 *o) {
    f32 tmp;
    s32 flag;
    f32 prev;
    o->f5c++;
    if (o->f5c >= 30) {
        o->f5c = 0;
    }
    f32 k = 512.0f;
    o->f9c = (s32)((f32)o->f9c + k);
    o->fa4 = (s32)((f32)o->fa4 + k);
    o->fa0 = (s32)((546.0f) * sin_table_lookup(o->fa4));
    o->fac = (3.0f) * sin_table_lookup(o->f9c) + (2.0f);
    if (check_flag_or_state__15TObjBoss2TunnelFi(o) != 0) {
        o->fa8 = (o->fa0 * 2) / 3;
    } else {
        o->fa8 = o->fa0 / 2;
    }
    switch (o->f64) {
    case 0:
        if (check_flag_or_state__15TObjBoss2TunnelFi(o) != 0) {
            if (is_flag_set__15TObjBoss2TunnelFv(o) != 0) {
                o->f94 = (-1.0f);
            } else {
                o->f94 = (1.0f);
            }
            o->f64 = 1;
            init_piecewise_curve(o->f68, (0.1f), (-0.1f), (1.5e+02f), (5.0f), (2.0f));
            o->f98 = (0.0f);
        }
        break;
    case 1:
        if (check_flag_or_state__15TObjBoss2TunnelFi(o) == 0) {
            o->f64 = 3;
            tmp = fabs_float(o->f98);
            init_piecewise_curve(o->f68, (0.1f), (-0.1f), o->f98, -update_position__15TObjBoss2TunnelFv(o->f68), (2.0f));
        } else {
            if (((TObjBoss2Tunnel *)o->f68)->advance_phase(&tmp) != 0) {
                o->f64 = 2;
            }
            o->f98 = tmp * o->f94;
        }
        break;
    case 2:
        if (check_flag_or_state__15TObjBoss2TunnelFi(o) == 0) {
            o->f64 = 3;
            init_piecewise_curve(o->f68, (0.1f), (-0.1f), (1.5e+02f), (0.0f), (2.0f));
        }
        break;
    case 3:
        if (((TObjBoss2Tunnel *)o->f68)->advance_phase(&tmp) != 0) {
            o->f98 = (0.0f);
            o->f64 = 0;
        } else {
            o->f98 = o->f94 * ((1.5e+02f) - tmp);
        }
        break;
    }
    switch (o->f24) {
    case 0:
        TObjBoss2Tunnel::set_global_flag_100();
        if (TObjBoss2Tunnel__global_flags & 0x100) {
            TObjBoss2Tunnel__global_flags &= ~0x100;
            o->f24 = 1;
        }
        break;
    case 1:
        o->f20 += (0.05f);
        if (o->f20 > lbl_805D85B0) {
            o->f20 = lbl_805D85B0;
        }
        o->f1c += o->f20;
        o->f60 += o->f20;
        if (o->f1c >= 600.0f) {
            o->f1c -= 600.0f;
            o->f28++;
            if (o->f28 >= 6) {
                o->f28 = 0;
                copy_ring_buffer_window__15TObjBoss2TunnelFv(o);
                o->f24 = 2;
                o->fb0 = TFogCtrl::update_first_active_fog();
            } else {
                init_queue_from_start__15TObjBoss2TunnelFv(o);
            }
        }
        break;
    case 2: {
        o->f20 += (0.05f);
        if (o->f20 > lbl_805D85B0) {
            o->f20 = lbl_805D85B0;
        }
        o->f1c += o->f20;
        if (o->f1c >= 600.0f) {
            o->f1c -= 600.0f;
            o->f28++;
            if (o->f28 >= 31) {
                o->f28 = 0;
            }
            copy_ring_buffer_window__15TObjBoss2TunnelFv(o);
        }
        if (TObjBoss2Tunnel__global_flags & 0x200) {
            void *p;
            TObjBoss2Tunnel__global_flags &= ~0x200;
            o->f24 = 3;
            o->f44 = 0;
            o->f50 = (4.4e+03f) - ((0.5f) * (o->f20 * o->f20)) / (0.02f);
            o->f4c = o->f1c;
            o->f54 = o->f20;
            o->f48 = 0;
            p = __nw__7TObjectFUl(0x24);
            if (p != 0) {
                init__13TUnk_804835D8Fv(p, o);
            }
        }
        o->fd8--;
        if (o->fd8 <= 0) {
            Vec_8003B6E8 v;
            void *p;
            v.x = (2e+02f) * rand_signed_unit();
            v.y = (9e+01f) * ((3.0517578e-05f) * (f32)rand()) + (1e+01f);
            v.z = (6e+02f);
            p = __nw__7TObjectFUl(0x30);
            if (p != 0) {
                __ct__13TObjBoss2DustFv(p, tl_05, &v);
            }
            o->fd8 = 10;
        }
        break;
    }
    case 3:
        flag = 0;
        prev = o->f4c;
        if ((f32)o->f48 <= (0.0f)) {
            o->f4c = prev + o->f54;
            if (o->f4c > o->f50) {
                o->f48 = 1;
                o->f50 = o->f4c;
                play_sound_effect(0x4003A80E, 0, 0, 0);
            } else {
                play_persistent_sound(0x4003B20C, o, 0, 0, 0);
            }
        } else {
            f32 lim;
            o->f4c = (f32)o->f48 * (o->f54 - (0.01f) * (f32)o->f48) + o->f50;
            { f32 one = 1.0f; o->f48 = (s32)((f32)o->f48 + one); }
            lim = o->f54 / (0.02f);
            if ((f32)o->f48 >= lim) {
                o->f48 = (s32)lim;
                o->f58 = 0;
                o->f24 = 4;
            }
        }
        o->f20 = o->f4c - prev;
        o->f1c += o->f4c - prev;
        if (o->f34 == 6 || o->f38 == 6) {
            if (o->f1c >= 700.0f) {
                o->f1c -= 700.0f;
                flag = 1;
            }
        } else if (o->f1c >= 600.0f) {
            o->f1c -= 600.0f;
            flag = 1;
        }
        if (flag) {
            shift_queue_push_next__15TObjBoss2TunnelFPv(o);
        }
        break;
    case 4:
        break;
    }
    if (o->f24 == 1 || o->f24 == 2) {
        play_persistent_sound(0x4003B20C, o, 0, 0, 0);
    }
    ((TObjBoss2Tunnel *)o)->update_particles();
    if (TObjBoss2Tunnel__global_flags & 2) {
        TObjBoss2Tunnel__global_flags &= ~2;
        TObjBoss2Tunnel__global_flags |= 1;
    } else if (TObjBoss2Tunnel__global_flags & 4) {
        TObjBoss2Tunnel__global_flags &= ~4;
        TObjBoss2Tunnel__global_flags &= ~1;
    }
    switch (o->fb4) {
    case 0:
        if (TObjBoss2Tunnel__global_flags & 0x400) {
            TObjBoss2Tunnel__global_flags &= ~0x400;
            o->fb4 = 1;
            o->fb8 = 0;
            o->fbc = 0;
            enable_fog__15TObjBoss2TunnelFv(o);
        }
        break;
    case 1:
        o->fb8++;
        if (lbl_80483480[o->fbc] <= o->fb8) {
            o->fb8 = 0;
            o->fbc++;
            if (o->fbc & 1) {
                enable_fog__15TObjBoss2TunnelFPv((TObjBoss2Tunnel *)o);
            } else {
                enable_fog__15TObjBoss2TunnelFv(o);
                play_sound_effect(0x4003A80B, 0, 0, 0);
                if (lbl_80483480[o->fbc] == -1) {
                    o->fb4 = 2;
                }
            }
        }
        break;
    case 2:
        if (TObjBoss2Tunnel__global_flags & 0x800) {
            TObjBoss2Tunnel__global_flags &= ~0x800;
            o->fb4 = 3;
            o->fb8 = 0;
            o->fbc = 0;
            enable_fog__15TObjBoss2TunnelFPv((TObjBoss2Tunnel *)o);
        }
        break;
    case 3:
        o->fb8++;
        if (lbl_80483480[o->fbc] <= o->fb8) {
            o->fbc++;
            o->fb8 = 0;
            if (o->fbc & 1) {
                enable_fog__15TObjBoss2TunnelFv(o);
            } else {
                enable_fog__15TObjBoss2TunnelFPv((TObjBoss2Tunnel *)o);
                play_sound_effect(0x4003A80B, 0, 0, 0);
                if (lbl_80483480[o->fbc] == -1) {
                    o->fb4 = 0;
                }
            }
        }
        break;
    }
    if (TObjBoss2Tunnel::is_active() == 0) {
        f32 d = o->f1c;
        Col_8003B6E8 *a = &boss2_tunnel_color_table[o->f34];
        Col_8003B6E8 *b = &boss2_tunnel_color_table[o->f38];
        if (d <= (2e+02f)) {
            TObjBoss2Tunnel__sub_801339EC(a->r, a->g, a->b);
        } else if (d <= (4e+02f)) {
            f32 u;
            f32 t;
            t = (d - (2e+02f)) / (2e+02f);
            u = (1.0f) - t;
            TObjBoss2Tunnel__sub_801339EC(a->r * u + b->r * t, a->g * u + b->g * t, a->b * u + b->b * t);
        } else {
            TObjBoss2Tunnel__sub_801339EC(b->r, b->g, b->b);
        }
    } else {
        TObjBoss2Tunnel__sub_801339EC(boss2_tunnel_color->r, boss2_tunnel_color->g, boss2_tunnel_color->b);
    }
}

}
#pragma pop
#undef boss2_tunnel_color_table
#undef boss2_tunnel_color
#undef lbl_80483480
extern "C" {
void render__15TObjBoss2TunnelFv(u8 *arg0) {
    s32 saved;
    s32 i;
    Tunnel_8003B2EC *o = (Tunnel_8003B2EC *)arg0;
    Vec_8003B2EC v = boss2_tunnel_render_zero_vec[0];
    if (TObjPlayer::is_any_teammate_in_state() == 0 && TMainTask::get_render_pass() == 0) {
    push_matrix();
    {
        Fog_8003B2EC *f = *lbl_805D4BEC;
        saved = f->c;
        f->c = f[sub_8003C21C__15TObjBoss2TunnelFv(o, lbl_805D4BEC)].c;
    }
    TObjFish::set_global_param((s32)lbl_805D4BEC);
    if (o->f24 == 0 || o->f24 == 1) {
        push_matrix();
        translate_matrix(0, (0.0f), (0.0f), -o->f60);
        draw_ginja_object((void *)boss2_tunnel_instance->models[13].obj);
        pop_matrix();
    }
    if (o->f24 == 3) {
        v.z = -o->f1c;
        if (o->f2c[0] == 6) {
            v.z -= (4e+02f);
        } else {
            v.z -= (3e+02f);
        }
        if (o->f2c[1] == 6) {
            v.z -= (8e+02f);
        } else {
            v.z -= (6e+02f);
        }
        if (o->f2c[2] == 6) {
            v.z -= (4e+02f);
        } else {
            v.z -= (3e+02f);
        }
    } else {
        v.z = -((1.2e+03f) + o->f1c);
    }
    post_translate_matrix(&v);
    v.z = (6e+02f);
    for (i = 0; i < 6; i++) {
        s32 t = o->f2c[i];
        if (t == 6) {
            if (i != 0) {
                translate_matrix(0, (0.0f), (0.0f), (1e+02f));
            }
            translate_matrix(0, (0.0f), (0.0f), (-3e+02f));
            push_matrix();
            translate_matrix(0, (0.0f), o->fac, (0.0f));
            rotate_matrix_z(0, o->fa0);
            translate_matrix(0, o->f98, (0.0f), (0.0f));
            draw_ginja_object((void *)boss2_tunnel_instance->models[18].obj);
            draw_ginja_object((void *)boss2_tunnel_instance->models[21].obj);
            pop_matrix();
            push_matrix();
            rotate_matrix_z(0, o->fa8);
            translate_matrix(0, o->f98, (0.0f), (0.0f));
            draw_ginja_object((void *)boss2_tunnel_instance->models[10].obj);
            pop_matrix();
            translate_matrix(0, (0.0f), (0.0f), (4e+02f));
            push_matrix();
            translate_matrix(0, (0.0f), o->fac, (0.0f));
            rotate_matrix_z(0, o->fa0);
            translate_matrix(0, o->f98, (0.0f), (0.0f));
            draw_ginja_object((void *)boss2_tunnel_instance->models[19].obj);
            pop_matrix();
            push_matrix();
            rotate_matrix_z(0, o->fa8);
            translate_matrix(0, o->f98, (0.0f), (0.0f));
            draw_ginja_object((void *)boss2_tunnel_instance->models[11].obj);
            pop_matrix();
            post_translate_matrix(&v);
        } else {
            push_matrix();
            translate_matrix(0, (0.0f), o->fac, (0.0f));
            rotate_matrix_z(0, o->fa0);
            translate_matrix(0, o->f98, (0.0f), (0.0f));
            draw_ginja_object((void *)(boss2_tunnel_instance->models[boss2_tunnel_model_index_table[t]].obj));
            pop_matrix();
            push_matrix();
            rotate_matrix_z(0, o->fa8);
            translate_matrix(0, o->f98, (0.0f), (0.0f));
            draw_ginja_object((void *)(boss2_tunnel_instance->models[boss2_tunnel_model_order_table[t]].obj));
            pop_matrix();
            post_translate_matrix(&v);
        }
    }
    (*lbl_805D4BEC)->c = saved;
    pop_matrix();
    }
}

void TObjBoss2Tunnel__sub_8003B2B0(void) {
    void *o;
    o = __nw__7TObjectFUl(0x1C);
    if (o != NULL) {
        o = __ct__7TObjectFP7TObject(o, tl_07);
    }
    TObjBoss2Tunnel_parent_object = o;
}

#undef release_children__15TObjBoss2TunnelFPvf
#undef sub_8003C21C__15TObjBoss2TunnelFv
#undef check_flag_or_state__15TObjBoss2TunnelFi
#undef is_flag_set__15TObjBoss2TunnelFv
#undef copy_ring_buffer_window__15TObjBoss2TunnelFv
#undef init_queue_from_start__15TObjBoss2TunnelFv
#undef shift_queue_push_next__15TObjBoss2TunnelFPv
#undef __nw__7TObjectFUl
#undef init__13TUnk_804835D8Fv
#undef enable_fog__15TObjBoss2TunnelFv
void release_children__15TObjBoss2TunnelFPvf(Obj_8003B250 *arg0, f32 farg0) {
    Child_8003B250 *c;
    while ((c = arg0->child) != NULL) {
        c->f44 = c->f44 + farg0;
        ((TObject *)c)->set_parent((TObject *)TObjBoss2Tunnel_parent_object);
    }
}

void TObjBoss2Tunnel::detach_children(void *arg) {
    Obj_8003B1FC *c;
    while ((c = ((Obj_8003B1FC *)this)->child) != 0) {
        vec3_add_to(c->xf, arg);
        ((TObject *)c)->set_parent((TObject *)TObjBoss2Tunnel_parent_object);
    }
}

void TObjBoss2Tunnel__sub_8003B1D8(void) {
    ((void (*)(f32))release_children__15TObjBoss2TunnelFPvf)(lbl_805D85D8);
}

void TObjBoss2Tunnel::create_particle_effect(s32 position, s32 arg1, f32 farg0) {
    void *var_r31;

    var_r31 = __nw__7TObjectFUl(0x78);
    if (var_r31 != NULL) {
        var_r31 = ((TParticleCtrl *)var_r31)->initialize_with_flags((const void *)position, (s32)(TParticleCtrl::get_particle_by_index(arg1)), 1, 0, 0, 1, (u16)0x40);
    }
#define release_children__15TObjBoss2TunnelFPvf ((s32 (*)(void *, f32))release_children__15TObjBoss2TunnelFPvf)
    if (var_r31 != NULL) {
        ((VObj_8003B138 *)var_r31)->m1();
        release_children__15TObjBoss2TunnelFPvf(var_r31, farg0);
    }
}

}
#undef release_children__15TObjBoss2TunnelFPvf
