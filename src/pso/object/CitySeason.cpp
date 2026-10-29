#include "types.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss4Type2_80086C44.h"
#include "pso/boss/TBoss8Dragon_8002CC48.h"
#include "pso/object/CitySeason.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/vector.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TNowLoading.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TUnk_804B5E48.h"
#include "pso/object/TObjCity_Season_XmasWreath.h"
#include "pso/object/TObjCity_Season_EasterEgg.h"
#include "pso/object/TObjCity_Season_ValentineHeart.h"
#include "pso/object/TObjCity_Season_XmasTree.h"
#include "pso/object/TObjCity_Season_HalloweenPumpkin.h"
#include "pso/object/TObjCity_Season_21_21.h"
#include "pso/object/TObjCity_Season_SonicAdv2.h"
#include "pso/object/TObjCity_Season_Board.h"
#include "pso/object/TObjCity_Season_FireWorkCtrl.h"
extern "C" void *__ct__14TObjCollidableFP7TObject(void *, s32);
struct RecoveredGlobal_80184B44_lbl_804440B0 { s32 value; u8 remaining[0x28]; };
extern "C" {
const RecoveredGlobal_80184B44_lbl_804440B0 city_season_collision_template = {0, {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
const char TObjCity_Season_EasterEgg__class_name[] = "TObjCity_Season_EasterEgg";
const char TObjCity_Season_ValentineHeart__class_name[] = "TObjCity_Season_ValentineHeart";
const char TObjCity_Season_XmasTree__class_name[] = "TObjCity_Season_XmasTree";
const char TObjCity_Season_XmasWreath__class_name[] = "TObjCity_Season_XmasWreath";
const char TObjCity_Season_HalloweenPumpkin__class_name[] = "TObjCity_Season_HalloweenPumpkin";
const char TObjCity_Season_21_21__class_name[] = "TObjCity_Season_21_21";
const char TObjCity_Season_SonicAdv2__class_name[] = "TObjCity_Season_SonicAdv2";
const char TObjCity_Season_Board__class_name[] = "TObjCity_Season_Board";
const char TObjCity_Season_FireWorkCtrl__class_name[] = "TObjCity_Season_FireWorkCtrl";
const char TObjCity_Season_FireWork__class_name[] = "TObjCity_Season_FireWork";
const u32 lbl_804441FC[5] = {0x3F4CCCCD, 0x3E4CCCCD, 0x3F800000, 0x3F666666, 0x00000000};
}
#include "pso/object/TObjCity_Season_FireWork.h"

#pragma push

#include "types.h"

struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

struct RecoveredGlobal_801830BC_lbl_804B5C08 {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *, void *);
}

extern "C" {

typedef char RecoveredGlobal_801830BC_lbl_804B5C08_size[sizeof(RecoveredGlobal_801830BC_lbl_804B5C08) == 0x38 ? 1 : -1];

typedef struct V3_80183134 { s32 x, y, z; } V3_80183134;
typedef struct Self_80183134 {
    u8 pad0[0x1C];
    f32 pos[3];
    s32 state;
    void *handle;
    f32 limit;
    s32 timer;
    s32 se;
    f32 time;
} Self_80183134;

s32 rand(void);
extern const f32 lbl_805DBC18[1];
extern const f32 lbl_805DBC1C[1];
extern const f32 lbl_805DBC20[1];
extern const f32 lbl_805DBC24[1];
extern const f32 lbl_805DBC28[1];
extern const f32 lbl_805DBC2C[1];

}

void TObjCity_Season_FireWork::run_task() {
    TObjCity_Season_FireWork *self = this;
    switch (self->state) {
    case 0:
        if (self->handle == NULL) {
            self->handle = spawn_continuous_particle_effect_with_flags(self->pos, 0x84, 0x40);
        }
        if (self->handle != NULL) {
            self->riseDistance += lbl_805DBC18[0];
            self->pos[1] += lbl_805DBC18[0];
            if (self->riseDistance >= self->limit) {
                self->riseDistance = lbl_805DBC1C[0];
                self->timer = 0;
                self->state = 1;
                queue_destruction__7TObjectFv(self->handle);
                self->handle = NULL;
            } else {
                ((TParticleCtrl *)self->handle)->set_position(self->pos);
            }
        }
        break;
    case 1:
        if (self->timer == 10) {
            spawn_particle_effect_with_flags(self->pos, 0x85, 0x40);
            spawn_particle_effect_with_flags(self->pos, 0x86, 0x40);
        }
        self->timer++;
        if (self->timer >= 15) {
            f32 r = lbl_805DBC20[0] * (f32)rand();
            self->timer = 0;
            if (r < lbl_805DBC24[0]) {
                self->burstEffectId = 0x87;
                self->state = 2;
            } else if (r < lbl_805DBC28[0]) {
                self->burstEffectId = 0x88;
                self->state = 2;
            } else {
                self->state = 3;
            }
        }
        break;
    case 2:
        if (self->timer == 0 || self->timer == 4 || self->timer == 8) {
            spawn_particle_effect_with_flags(self->pos, self->burstEffectId, 0x40);
        }
        self->timer++;
        self->pos[1] -= lbl_805DBC2C[0];
        if (self->timer > 8) {
            self->state = 4;
        }
        break;
    case 3:
        if (self->timer == 0 || self->timer == 4 || self->timer == 8) {
            V3_80183134 v;
            v.x = 0;
            v.y = TObjPlayer::calc_random_scaled();
            v.z = TObjPlayer::calc_random_scaled();
            create_oneshot_particle_emitter(self->pos, &v, 0x89, 0x40);
        }
        self->timer++;
        self->pos[1] -= lbl_805DBC2C[0];
        if (self->timer > 8) {
            self->state = 4;
        }
        break;
    case 4:
        queue_destruction__7TObjectFv(self);
        break;
    }
}

struct Obj_8018355C;
extern "C" void sub_8018355C__28TObjCity_Season_FireWorkCtrlFv(struct Obj_8018355C *arg0);

struct RecoveredGlobal_8018343C_lbl_804B5C40 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
extern s32 __vt__24TObjCity_Season_FireWork[];
extern s32 TObjCity_Season_FireWork__name;

u8 *__ct__24TObjCity_Season_FireWorkFP7TObjectPvf(u8 *arg0, u8 *arg1, u8 *arg2, f32 farg0);
void debug_printf_at(int, void *, ...);
extern const char lbl_80444218[];
extern const char lbl_80444228[];
extern const char lbl_80444238[];
extern const char lbl_80444248[];
}

extern "C" {

void __dl__7TObjectFPv(void *);

extern s32 __vt__24TObjCity_Season_FireWork[];

}

TObjCity_Season_FireWork::~TObjCity_Season_FireWork() {
    if (handle != NULL) { queue_destruction__7TObjectFv(handle); handle = NULL; }
}

extern "C" {

typedef char RecoveredGlobal_8018343C_lbl_804B5C40_size[sizeof(RecoveredGlobal_8018343C_lbl_804B5C40) == 0x18 ? 1 : -1];
}

TObjCity_Season_FireWork::TObjCity_Season_FireWork(TObject* parent, void* position, f32 riseHeight) : TObject(parent) {
    m_name = (const char*)TObjCity_Season_FireWork__name;
    VecCopy((Vec *)pos, (const Vec *)position);
    state = 0;
    handle = NULL;
    limit = riseHeight;
    timer = 0;
    burstEffectId = 0;
    riseDistance = lbl_805DBC1C[0];
}

extern "C" {

void TObjCity_Season_FireWorkCtrl::vfunc_13(s32) {
    ((void (*)(void))sub_8018355C__28TObjCity_Season_FireWorkCtrlFv)();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x13001C, (void *)lbl_80444218);
    debug_printf_at(0x13001D, (void *)lbl_80444228);
    debug_printf_at(0x13001E, (void *)lbl_80444238);
    debug_printf_at(0x130020, (void *)lbl_80444248);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}
__declspec(section ".rodata") extern const char lbl_80444218[] = "<- AREA WIDTH";
__declspec(section ".rodata") extern const char lbl_80444228[] = "<- RISE HEIGHT";
__declspec(section ".rodata") extern const char lbl_80444238[] = "<- AREA DEPTH";
__declspec(section ".rodata") extern const char lbl_80444248[] = "<- FREQ";

}

struct Stack_80183604
{
  f32 sp8;
  u8 pad_C[0x4];
  f32 sp10;
  f32 sp14;
  u8 trailing_storage[0x8];
};

struct RecoveredGlobal_80183604_lbl_804FF5E8
{
  s32 value;
  u8 remaining[0x24];
};

struct VBase_8018355C { u8 pad[0x18]; };

struct Obj_8018355C : VBase_8018355C {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual s32 v8(f32, f32);
    u8 pad1[0x38 - 0x1C];
    u8 pos[0x5C - 0x38];
    s32 f5C;
    u8 pad2[4];
    s32 f64;
    f32 f68;
    u8 pad3[4];
    f32 f70;
};

struct V3_8018355C { f32 x; f32 y; f32 z; };

struct V4_8018355C { s32 a; s32 b; s32 c; s32 d; };

extern "C" {
s32 TLobby__sub_80184C54();
u32 __nw__7TObjectFUl(int);
s32 rand();
f32 vec3_dot(void *, void *);
f32 subtract_vector(void *, void *);
extern RecoveredGlobal_80183604_lbl_804FF5E8 lbl_804FF5E8;
extern s32 camera_ctrl_instance;

extern const f32 lbl_805DBC38[1];
extern const f32 lbl_805DBC3C[1];
extern const f32 lbl_805DBC40[1];
void fn_80141CB8(void *, void *, void *, void *);
extern const u32 lbl_804441FC[5];
#define lbl_804441FC ((const V4_8018355C *)lbl_804441FC)
extern const f32 lbl_805DBC30[1];
extern const f32 lbl_805DBC34[1];

void sub_8018355C__28TObjCity_Season_FireWorkCtrlFv(Obj_8018355C *arg0);
}

extern "C" {

typedef struct RecoveredGlobal_80183604_lbl_804FF5E8 RecoveredGlobal_80183604_lbl_804FF5E8;
typedef struct Stack_80183604 Stack_80183604;
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma fp_contract on

void TObjCity_Season_FireWorkCtrl::sub_8018355C() {
    Obj_8018355C *arg0 = (Obj_8018355C *)this;
    if (arg0->v8(lbl_805DBC30[0], lbl_805DBC34[0]) != 0) {
        V3_8018355C sp18;
        V4_8018355C sp8 = lbl_804441FC[0];
        arg0->f64 = 0;
        arg0->f5C = 0;
        sp18.x = arg0->f68;
        sp18.y = lbl_805DBC38[0];
        sp18.z = arg0->f70;
        fn_80141CB8(arg0->pos, &arg0->f5C, &sp18, &sp8);
    }
}

void TObjCity_Season_FireWorkCtrl::run_task() {
    u8 *arg0 = (u8 *)this;
  Stack_80183604 stack;
  f32 temp_f30;
  float new_var;
  f32 temp_f31;
  u32 temp_r3;
  f32 temp_f29;
  if (TLobby__sub_80184C54() != 0)
  {
    *((s32 *) (((s8 *) arg0) + 0x90)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x90))) - 1);
    if (((s32) (*((s32 *) (((s8 *) arg0) + 0x90)))) < 0)
    {
      VecCopy((Vec *)(&stack.sp14), (const Vec *)(arg0 + 0x38));
      subtract_vector((void *)&stack.sp14, (void *)(camera_ctrl_instance + 0x178));
      if ((((TObjBoss2Tunnel *)(&stack.sp14))->update_scale() < lbl_805DBC3C[0]) && (vec3_dot((void *)&stack.sp14, (void *) (((u8 *)&lbl_804FF5E8.value) + 0xC)) > lbl_805DBC1C[0]))
      {
        temp_f30 = rand_signed_unit();
        temp_f30 = (this->scale.x) * temp_f30;
        temp_f31 = temp_f30;
        new_var = (*((f32 *) (((s8 *) arg0) + 0x70))) * rand_signed_unit();
        temp_f30 = new_var;
        temp_f29 = (lbl_805DBC40[0] * (lbl_805DBC20[0] * ((f32) rand()))) + (this->scale.y);
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
        stack.sp8 += temp_f31;
        stack.sp10 += temp_f30;
        temp_r3 = __nw__7TObjectFUl(0x40);
        if (temp_r3 != 0U)
        {
          ((s32 (*)(int, void *, void *, f32))__ct__24TObjCity_Season_FireWorkFP7TObjectPvf)((int) temp_r3, (void *) arg0, (void *)&stack.sp8, (f32) temp_f29);
        }
      }
      *((s32 *) (((s8 *) arg0) + 0x90)) = (s32) (lbl_805DBC38[0] * (((f32) ((this->set_params[0]) + 0x3C)) * (lbl_805DBC20[0] * ((f32) rand()))));
    }
  }
}

}

#pragma pop

#pragma push
#include "types.h"

extern "C" {

void __dl__7TObjectFPv(void *);

extern void *tl_05;

void *TObjCity_Season_FireWorkCtrl__create(void *arg0) {
    void *o = ((void * (*)(int))__nw__7TObjectFUl)(0x94);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *))TObjCity_Season_FireWorkCtrl__ct)(o, tl_05, arg0);
    }
    return o;
}

extern s32 __vt__28TObjCity_Season_FireWorkCtrl[];

void *TObjCity_Season_FireWorkCtrl::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__28TObjCity_Season_FireWorkCtrl;
        __dt__8TObjBaseFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}

#pragma pop

#define VObj_18_1a504b VObj_18_1a504b_sf2p417
#define VBase_18_1a504b VBase_18_1a504b_sf2p417
#pragma push

#include "types.h"

struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

struct RecoveredGlobal_8018386C_lbl_804B5C58 {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 TObjCity_Season_FireWorkCtrl__name;
}

extern "C" {

typedef char RecoveredGlobal_8018386C_lbl_804B5C58_size[sizeof(RecoveredGlobal_8018386C_lbl_804B5C58) == 0x38 ? 1 : -1];
u8 *TObjCity_Season_FireWorkCtrl__ct(u8 *city_season_fire_work_ctrl, s32 parent, s32 arg2) {
    __ct__8TObjBaseFP7TObject((void *)city_season_fire_work_ctrl, (void *)parent);
    *(s32 **)((s8 *)city_season_fire_work_ctrl + 0x18) = &(*(RecoveredGlobal_8018386C_lbl_804B5C58 *)&__vt__28TObjCity_Season_FireWorkCtrl).value;
    *(s32 *)((s8 *)city_season_fire_work_ctrl + 0) = (s32) TObjCity_Season_FireWorkCtrl__name;
    ((TObjCity_Season_FireWorkCtrl *)(city_season_fire_work_ctrl))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)city_season_fire_work_ctrl + 0x90) = 0;
    return city_season_fire_work_ctrl;
}

}

#pragma pop

#undef VBase_18_1a504b
#undef VObj_18_1a504b
#pragma push

#include "types.h"

struct Fn801838D4Base_801838d4 { char pad[0x18]; };
struct Fn801838D4VObj_801838d4 : Fn801838D4Base_801838d4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

extern "C" {

s32 post_translate_matrix(void *);
s32 scroll_strip_uvs(s32, s16, s32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();

extern u32 lbl_805D5B38;
extern s32 lbl_805D5B3C;
extern s32 lbl_805D5B40;
extern s32 lbl_805D5B44;
extern s32 lbl_805D5B48;
extern const f32 lbl_805DBC44[1];
extern const f32 lbl_805DBC48[1];

void TObjCity_Season_Board::render() {
    u8 *arg0 = (u8 *)this;
    if (((u32) lbl_805D5B38 != 0U) && (((Fn801838D4VObj_801838d4*)arg0)->m8(lbl_805DBC44[0], lbl_805DBC48[0]) != 0)) {
        TObjFish::set_global_param(lbl_805D5B44);
        scroll_strip_uvs(lbl_805D5B48, (s16) *(s32 *)&this->unk_90, 0);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_chunk_object((void *)lbl_805D5B3C);
        draw_chunk_object((void *)lbl_805D5B40);
        pop_matrix();
    }
}

void TObjCity_Season_Board::run_task() {
    s32 temp_r4;

    *(s32 *)&this->unk_90 = (s32) (*(s32 *)&this->unk_90 + 2);
    temp_r4 = *(s32 *)&this->unk_90;
    if (temp_r4 >= 0x100) {
        *(s32 *)&this->unk_90 = (temp_r4 - 0x100);
    }
}

}

#pragma pop

#pragma push
#include "types.h"

extern "C" {

void __dl__7TObjectFPv(void *);

extern void *tl_05;

void *TObjCity_Season_Board__create(void *arg0) {
    void *o = ((void * (*)(int))__nw__7TObjectFUl)(0x94);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *))TObjCity_Season_Board__ct)(o, tl_05, arg0);
    }
    return o;
}

extern s32 __vt__21TObjCity_Season_Board[];

void *TObjCity_Season_Board::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__21TObjCity_Season_Board;
        __dt__8TObjBaseFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}

#pragma pop

#define VObj_18_1a504b VObj_18_1a504b_sf2p625
#define VBase_18_1a504b VBase_18_1a504b_sf2p625
#pragma push

#include "types.h"
extern "C" {
__declspec(section ".sdata2") extern const f32 lbl_805DBC18[1] = { 4.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC1C[1] = { 0.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC20[1] = { 3.0517578e-05f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC24[1] = { 0.33f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC28[1] = { 0.66f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC2C[1] = { 0.8f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC30[1] = { 250.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC34[1] = { 10.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC38[1] = { 3.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC3C[1] = { 450.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC40[1] = { 50.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC44[1] = { 800.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC48[1] = { 200.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC4C[1] = { 20.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC50[1] = { 0.037f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC54[1] = { 1.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC58[1] = { 1.3f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC5C[1] = { 0.3f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC60[1] = { 60.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC64[1] = { 23.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC68[1] = { 80.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC6C[1] = { 400.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC70[1] = { 0.2f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC74[1] = { 22.5f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC78[1] = { 13.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DBC7C[1] = { 25.0f };
}
struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

struct RecoveredGlobal_80183A38_lbl_804B5C90 {
    s32 value;
    u8 remaining[0x30];
};

struct Vec_80183AF0 { f32 x, y, z; };

struct EntA_80183AF0 { u8 pad[8]; s32 v; u8 padc[4]; };

struct EntB_80183AF0 { u8 pad[4]; s32 v; };

struct Res_80183AF0 { u8 pad[0x42C]; EntA_80183AF0 *a; EntB_80183AF0 *b; };

struct VBase_80183AF0 { u8 pad[0x18]; };

struct Obj_80183AF0 : VBase_80183AF0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
    u8 pad1c[0x38 - 0x1C];
    Vec_80183AF0 pos;
    u8 pad44[0x60 - 0x44];
    s32 x60;
    u8 pad64[0xB0 - 0x64];
    f32 xb0;
};

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 TObjCity_Season_Board__name;

extern const char lbl_80444250[];

int get_anim_frame__13TUnk_804B5E48Fv(void* a0);

extern s32 city_season_xmas_model_table[];
}

extern "C" {

typedef char RecoveredGlobal_80183A38_lbl_804B5C90_size[sizeof(RecoveredGlobal_80183A38_lbl_804B5C90) == 0x34 ? 1 : -1];
u8 *TObjCity_Season_Board__ct(u8 *city_season_board, s32 parent, s32 arg2) {
    __ct__8TObjBaseFP7TObject((void *)city_season_board, (void *)parent);
    *(s32 **)((s8 *)city_season_board + 0x18) = &(*(RecoveredGlobal_80183A38_lbl_804B5C90 *)&__vt__21TObjCity_Season_Board).value;
    *(s32 *)((s8 *)city_season_board + 0) = (s32) TObjCity_Season_Board__name;
    ((TObjCity_Season_Board *)(city_season_board))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)city_season_board + 0x90) = 0;
    return city_season_board;
}
void TObjCity_Season_SonicAdv2::debug_draw_model_index() {
    sub_80183C38();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    ((void (*)(s32 id, const char *fmt, ...))debug_printf_at)(0x130020, lbl_80444250);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}
__declspec(section ".rodata") extern const char lbl_80444250[] = "<- MDL IDX";
#pragma push
#pragma opt_common_subs off
void TObjCity_Season_SonicAdv2::render() {
    Obj_80183AF0 *self = (Obj_80183AF0 *)this;
    Res_80183AF0 *res;
    s32 idx;
    Vec_80183AF0 pos;
    Vec_80183AF0 a;
    Vec_80183AF0 b;
    res = ((Res_80183AF0 * (*)(void *))get_anim_frame__13TUnk_804B5E48Fv)(self);
    if (res != NULL && self->m8(lbl_805DBC44[0], lbl_805DBC4C[0]) != 0) {
        TObjFish::set_global_param(city_season_xmas_model_table[5]);
        idx = ((TObjCity_Season_SonicAdv2 *)self)->sub_80183C38();
        ((void (*)())push_matrix)();
        ((void (*)(void *))post_translate_matrix)(&self->pos);
        ((void (*)(int, s32))rotate_matrix_y)(0, self->x60);
        draw_model_motion((void *)res->a[idx].v, (void *)res->b[idx].v, self->xb0);
        ((void (*)())pop_matrix)();
        VecCopy((Vec *)&pos, (const Vec *)&self->pos);
        pos.y += lbl_805DBC50[0];
        a.x = lbl_805DBC1C[0];
        a.y = lbl_805DBC54[0];
        a.z = lbl_805DBC1C[0];
        b.x = lbl_805DBC54[0];
        b.y = lbl_805DBC1C[0];
        b.z = lbl_805DBC58[0];
        ((TObjEneDD *)(&pos))->draw_oriented_shadow((s32)&a, self->x60, (u32)&b);
    }
}
#pragma pop

}

#pragma pop

#undef VBase_18_1a504b
#undef VObj_18_1a504b
#pragma push
#include "types.h"

extern "C" {

void TObjCity_Season_SonicAdv2::run_task() { advance_anim_time(sub_80183C38(), lbl_805DBC5C[0]); }
s32 TObjCity_Season_SonicAdv2::sub_80183C38() {
    if (this->set_params[0] < 0) {
        return 0;
    }
    if (this->set_params[0] < 4) {
        return this->set_params[0];
    }
    return 3;
}

}

#pragma pop

#pragma push
#include "types.h"

extern "C" {

void __dl__7TObjectFPv(void *);

extern void *tl_05;

void *TObjCity_Season_SonicAdv2__create(void *arg0) {
    void *o = ((void * (*)(int))__nw__7TObjectFUl)(0xB4);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *))TObjCity_Season_SonicAdv2__ct)(o, tl_05, arg0);
    }
    return o;
}

extern s32 __vt__25TObjCity_Season_SonicAdv2[];

void *TObjCity_Season_SonicAdv2::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__25TObjCity_Season_SonicAdv2;
        this->destroy_seasonal_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}

#pragma pop

#pragma push

#include "types.h"

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_80183D4C_lbl_8050DC50 { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_80183D4C_lbl_8050DC50_size[sizeof(RecoveredGlobal_80183D4C_lbl_8050DC50) == 0x18 ? 1 : -1];

struct RecoveredGlobal_80183D00_lbl_804B5CC4 {
    s32 value;
    u8 remaining[0x38];
};

extern "C" {

int get_anim_frame__13TUnk_804B5E48Fv(void* a0);

s32 push_matrix();
s32 post_translate_matrix(void *);

extern s32 lbl_805D5B34;
extern s32 TObjCity_Season_SonicAdv2__name;
}

extern "C" {

typedef char RecoveredGlobal_80183D00_lbl_804B5CC4_size[sizeof(RecoveredGlobal_80183D00_lbl_804B5CC4) == 0x3C ? 1 : -1];
u8 *TObjCity_Season_SonicAdv2__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((s32 (*)(void *, void *, void *, int, f32))init_city_season_object)((void *)arg0, (void *)arg1, (void *)arg2, 5, (f32)lbl_805DBC38[0]);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80183D00_lbl_804B5CC4 *)&__vt__25TObjCity_Season_SonicAdv2).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjCity_Season_SonicAdv2__name;
    return arg0;
}

void TObjCity_Season_21_21::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    temp_r3 = (u8 *)(((u8 * (*)())get_anim_frame__13TUnk_804B5E48Fv)());
    if (temp_r3 != NULL) {
        if (((VObj_18_26a62c *)(arg0))->m8(lbl_805DBC44[0], lbl_805DBC60[0]) != 0) {
            TObjFish::set_global_param((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80183D4C_lbl_8050DC50 *)&city_season_xmas_model_table).value) + 0x10)));
            ((s32 (*)(void *, int, int))scroll_strip_uvs)((void *)lbl_805D5B34, 0, (int) ((s16) *(s32 *)((s8 *)arg0 + 0xB4)));
            push_matrix();
            post_translate_matrix((u8 *)&this->position);
            ((s32 (*)(int, int))rotate_matrix_y)(0, this->rotation_y);
            draw_chunk_object((void *)(*(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0x42C)) + 0x18)));
            draw_model_motion((void *)(*(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0x42C)) + 8)), (void *)(*(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0x430)) + 4)), this->m_b0);
            pop_matrix();
        }
    }
}

void TObjCity_Season_21_21::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    if (((TUnk_804B5E48 *)arg0)->advance_anim_time(0, lbl_805DBC5C[0]) != 0) {
        *(s32 *)((s8 *)arg0 + 0xB4) = (s32) (*(s32 *)((s8 *)arg0 + 0xB4) + 2);
        temp_r3 = *(s32 *)((s8 *)arg0 + 0xB4);
        if (temp_r3 >= 0xFF) {
            *(s32 *)((s8 *)arg0 + 0xB4) = (temp_r3 - 0xFF);
        }
    }
}

}

#pragma pop

#pragma push
#include "types.h"

extern "C" {

void __dl__7TObjectFPv(void *);

extern void *tl_05;

void *TObjCity_Season_21_21__create(void *arg0) {
    void *o = ((void * (*)(int))__nw__7TObjectFUl)(0xBC);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *))TObjCity_Season_21_21__ct)(o, tl_05, arg0);
    }
    return o;
}

extern s32 __vt__21TObjCity_Season_21_21[];

void *__dt__21TObjCity_Season_21_21Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__21TObjCity_Season_21_21;
        if (*(void **)((s8 *)arg0 + 0xB8) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xB8)); ((TObjCity_Season_21_21 *)arg0)->m_b8 = 0; }
        ((TUnk_804B5E48 *)arg0)->destroy_seasonal_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

#pragma pop

#define VObj_18_26a62c VObj_18_26a62c_sf2p1056
#define VBase_18_26a62c VBase_18_26a62c_sf2p1056
#pragma push

#include "types.h"

#include <stddef.h>
struct Stack_80183F24 {
    s32 sp8;
    f32 spC;
};

struct RecoveredGlobal_80183F24_lbl_804B5D00 { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_80183F24_lbl_804B5D00_size[sizeof(RecoveredGlobal_80183F24_lbl_804B5D00) == 0x38 ? 1 : -1];

struct RecoveredGlobal_80184054_lbl_8050DC38 {
    s32 value;
    u8 remaining[0x14];
};

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_80183FC0_lbl_8050DC38 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_80183FC0_lbl_8050DC50 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {

void *create_particle_emitter(void *pos, s32 id);
int get_anim_frame__13TUnk_804B5E48Fv(void* a0);
extern s32 TObjCity_Season_21_21__name;
extern RecoveredGlobal_80184054_lbl_8050DC38 city_season_easter_egg_model_table;

s32 push_matrix();
s32 post_translate_matrix(void *);

extern RecoveredGlobal_80184054_lbl_8050DC38 city_season_easter_egg_model_table;
}

extern "C" {

u8 *TObjCity_Season_21_21__ct(u8 *city_season_21_21, s32 arg1, s32 arg2) {
    typedef char sp8_offset[(offsetof(Stack_80183F24, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80183F24, spC) == 0x4) ? 1 : -1];
    Stack_80183F24 stack;
    ((s32 (*)(void *, void *, void *, int, f32))init_city_season_object)((void *)city_season_21_21, (void *)arg1, (void *)arg2, 4, (f32)lbl_805DBC64[0]);
    *(s32 **)((s8 *)city_season_21_21 + 0x18) = &(*(RecoveredGlobal_80183F24_lbl_804B5D00 *)&__vt__21TObjCity_Season_21_21).value;
    *(s32 *)((s8 *)city_season_21_21 + 0) = (s32) TObjCity_Season_21_21__name;
    *(s32 *)((s8 *)city_season_21_21 + 0xB4) = 0;
    if (((u32 (*)(void *))get_anim_frame__13TUnk_804B5E48Fv)(city_season_21_21) != 0U) {
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(city_season_21_21 + 0x38));
        stack.spC += lbl_805DBC4C[0];
        ((TObjCity_Season_21_21 *)city_season_21_21)->m_b8 = (s32)create_particle_emitter((&stack.sp8), 0x90);
    } else {
        ((TObjCity_Season_21_21 *)city_season_21_21)->m_b8 = 0;
    }
    return city_season_21_21;
}
typedef char RecoveredGlobal_80184054_lbl_8050DC38_size[sizeof(RecoveredGlobal_80184054_lbl_8050DC38) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_80183FC0_lbl_8050DC38_size[sizeof(RecoveredGlobal_80183FC0_lbl_8050DC38) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_80183FC0_lbl_8050DC50_size[sizeof(RecoveredGlobal_80183FC0_lbl_8050DC50) == 0x18 ? 1 : -1];
void TObjCity_Season_HalloweenPumpkin::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r31;
    temp_r31 = (u8 *)(*(u8 **)((s8 *)(&(*(RecoveredGlobal_80183FC0_lbl_8050DC38 *)&city_season_easter_egg_model_table).value) + 0xC));
    if ((temp_r31 != NULL) && (((VObj_18_26a62c *)(arg0))->m8(lbl_805DBC44[0], lbl_805DBC68[0]) != 0)) {
        TObjFish::set_global_param((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80183FC0_lbl_8050DC50 *)&city_season_xmas_model_table).value) + 0xC)));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        ((s32 (*)(int, int))rotate_matrix_y)(0, this->rotation_y);
        draw_chunk_object((void *)(*(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r31 + 0x42C)) + 8)));
        pop_matrix();
    }
}

void TObjCity_Season_HalloweenPumpkin::run_task() {
    if ((u32) *(u32 *)((s8 *)&city_season_easter_egg_model_table.value + 0xC) != 0U) {
        this->rotation_y = (this->rotation_y + 0x40);
    }
}

}

#pragma pop

#undef VBase_18_26a62c
#undef VObj_18_26a62c
#pragma push
#include "types.h"

extern "C" {

void __dl__7TObjectFPv(void *);

extern void *tl_05;

void *TObjCity_Season_HalloweenPumpkin__create(void *arg0) {
    void *o = ((void * (*)(int))__nw__7TObjectFUl)(0x90);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *))TObjCity_Season_HalloweenPumpkin__ct)(o, tl_05, arg0);
    }
    return o;
}

extern s32 __vt__32TObjCity_Season_HalloweenPumpkin[];

void *TObjCity_Season_HalloweenPumpkin::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__32TObjCity_Season_HalloweenPumpkin;
        __dt__8TObjBaseFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}

#pragma pop

#define VObj_18_1a504b VObj_18_1a504b_sf2p1248
#define VBase_18_1a504b VBase_18_1a504b_sf2p1248
#define VObj_18_26a62c VObj_18_26a62c_sf2p1248
#define VBase_18_26a62c VBase_18_26a62c_sf2p1248
#pragma push

#include "types.h"

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_8018417C_lbl_8050DC38 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8018417C_lbl_8050DC50 {
    s32 value;
    u8 remaining[0x14];
};

struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

struct RecoveredGlobal_8018411C_lbl_804B5D38 {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {

s32 push_matrix();
s32 post_translate_matrix(void *);

s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 TObjCity_Season_HalloweenPumpkin__name;
}

extern "C" {

typedef char RecoveredGlobal_8018417C_lbl_8050DC38_size[sizeof(RecoveredGlobal_8018417C_lbl_8050DC38) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8018417C_lbl_8050DC50_size[sizeof(RecoveredGlobal_8018417C_lbl_8050DC50) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8018411C_lbl_804B5D38_size[sizeof(RecoveredGlobal_8018411C_lbl_804B5D38) == 0x34 ? 1 : -1];
u8 *TObjCity_Season_HalloweenPumpkin__ct(u8 *city_season_halloween_pumpkin, s32 parent, s32 arg2) {
    __ct__8TObjBaseFP7TObject((void *)city_season_halloween_pumpkin, (void *)parent);
    *(s32 **)((s8 *)city_season_halloween_pumpkin + 0x18) = &(*(RecoveredGlobal_8018411C_lbl_804B5D38 *)&__vt__32TObjCity_Season_HalloweenPumpkin).value;
    *(s32 *)((s8 *)city_season_halloween_pumpkin + 0) = (s32) TObjCity_Season_HalloweenPumpkin__name;
    ((TObjCity_Season_HalloweenPumpkin *)(city_season_halloween_pumpkin))->apply_object_set_data((void *)arg2);
    return city_season_halloween_pumpkin;
}

void TObjCity_Season_XmasWreath::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r31;
    temp_r31 = (u8 *)(*(u8 **)((s8 *)(&(*(RecoveredGlobal_8018417C_lbl_8050DC38 *)&city_season_easter_egg_model_table).value) + 8));
    if ((temp_r31 != NULL) && (((VObj_18_26a62c *)(arg0))->m8(lbl_805DBC6C[0], lbl_805DBC4C[0]) != 0)) {
        TObjFish::set_global_param((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_8018417C_lbl_8050DC50 *)&city_season_xmas_model_table).value) + 8)));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        ((s32 (*)(int, int))rotate_matrix_y)(0, this->rotation_y);
        draw_chunk_object((void *)(*(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r31 + 0x42C)) + 0x58)));
        pop_matrix();
    }
}

}

#pragma pop

#undef VBase_18_26a62c
#undef VObj_18_26a62c
#undef VBase_18_1a504b
#undef VObj_18_1a504b
#define VObj_18_1a504b VObj_18_1a504b_sf2p1365
#define VBase_18_1a504b VBase_18_1a504b_sf2p1365
#pragma push

#include "types.h"

struct Base_80184314_80184210 { char pad[0x18]; };
struct VObj_80184314_80184210 : Base_80184314_80184210 { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual s32 m8(f32, f32); };

struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

struct RecoveredGlobal_801842B4_lbl_804B5D6C {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 __vt__26TObjCity_Season_XmasWreath[];
extern s32 TObjCity_Season_XmasWreath__name;
}

extern "C" {

s32 post_translate_matrix(void *);

s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
void __dl__7TObjectFPv(void *);

int get_anim_frame__13TUnk_804B5E48Fv(void* a0);

extern void *tl_05;

void *TObjCity_Season_XmasWreath__create(void *arg0) {
    void *o = ((void * (*)(int))__nw__7TObjectFUl)(0x90);
    if (o != NULL) {
        o = TObjCity_Season_XmasWreath__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

extern s32 __vt__26TObjCity_Season_XmasWreath[];

void *TObjCity_Season_XmasWreath::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__26TObjCity_Season_XmasWreath;
        __dt__8TObjBaseFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

extern s32 city_season_xmas_model_table[];

typedef char RecoveredGlobal_801842B4_lbl_804B5D6C_size[sizeof(RecoveredGlobal_801842B4_lbl_804B5D6C) == 0x34 ? 1 : -1];
u8 *TObjCity_Season_XmasWreath__ct(u8 *city_season_xmas_wreath, s32 parent, s32 arg2) {
    __ct__8TObjBaseFP7TObject((void *)city_season_xmas_wreath, (void *)parent);
    *(s32 **)((s8 *)city_season_xmas_wreath + 0x18) = &(*(RecoveredGlobal_801842B4_lbl_804B5D6C *)&__vt__26TObjCity_Season_XmasWreath).value;
    *(s32 *)((s8 *)city_season_xmas_wreath + 0) = (s32) TObjCity_Season_XmasWreath__name;
    ((TObjCity_Season_XmasWreath *)(city_season_xmas_wreath))->apply_object_set_data((void *)arg2);
    return city_season_xmas_wreath;
}

void TObjCity_Season_XmasTree::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    temp_r3 = ((u8 * (*)())get_anim_frame__13TUnk_804B5E48Fv)();
    if ((temp_r3 != NULL) && (((VObj_80184314_80184210 *)arg0)->m8(lbl_805DBC44[0], lbl_805DBC40[0]) != 0)) {
        TObjFish::set_global_param(*(s32 *)((s8 *)city_season_xmas_model_table + 8));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_model_motion((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x78)), (void *)(*(s32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 0x430)) + 0xC)), this->m_b0);
        draw_model_motion((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x68)), (void *)(*(s32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 0x430)) + 4)), this->m_b0);
        draw_chunk_object((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x88)));
        draw_chunk_object((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x98)));
        pop_matrix();
    }
}

void TObjCity_Season_XmasTree::run_task() {
    s32 arg0 = (s32)this;
    ((TUnk_804B5E48 *)arg0)->advance_anim_time(1, lbl_805DBC70[0]);
}

}

#pragma pop

#undef VBase_18_1a504b
#undef VObj_18_1a504b
#pragma push

#include "types.h"

#include <stddef.h>
struct Stack_801844C8 {
    s32 sp8;
    f32 spC;
};

struct RecoveredGlobal_801844C8_lbl_804B5DA0 { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_801844C8_lbl_804B5DA0_size[sizeof(RecoveredGlobal_801844C8_lbl_804B5DA0) == 0x38 ? 1 : -1];

extern "C" {

void *create_particle_emitter(void *pos, s32 id);
int get_anim_frame__13TUnk_804B5E48Fv(void* a0);
extern s32 __vt__24TObjCity_Season_XmasTree[];
extern s32 TObjCity_Season_XmasTree__name;
}

extern "C" {

struct VBase_8018455c_80184408 { char pad[0x18]; };
struct VObj_8018455c_80184408 : VBase_8018455c_80184408 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

s32 post_translate_matrix(void *);

s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
void __dl__7TObjectFPv(void *);

extern void *tl_05;

void *TObjCity_Season_XmasTree__create(void *arg0) {
    void *o = ((void * (*)(int))__nw__7TObjectFUl)(0xB8);
    if (o != NULL) {
        o = TObjCity_Season_XmasTree__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

extern s32 __vt__24TObjCity_Season_XmasTree[];

void *TObjCity_Season_XmasTree::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__24TObjCity_Season_XmasTree;
        if (*(void * *)&this->unk_B4 != NULL) { queue_destruction__7TObjectFv(*(void * *)&this->unk_B4); *(s32 *)&this->unk_B4 = 0; }
        this->destroy_seasonal_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

extern s32 city_season_xmas_model_table[];

u8 *TObjCity_Season_XmasTree__ct(u8 *arg0, s32 arg1, s32 arg2) {
    typedef char sp8_offset[(offsetof(Stack_801844C8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_801844C8, spC) == 0x4) ? 1 : -1];
    Stack_801844C8 stack;
    ((s32 (*)(void *, void *, void *, int, f32))init_city_season_object)((void *)arg0, (void *)arg1, (void *)arg2, 2, (f32)lbl_805DBC74[0]);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_801844C8_lbl_804B5DA0 *)&__vt__24TObjCity_Season_XmasTree).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjCity_Season_XmasTree__name;
    if (((u32)((u8 * (*)(void *))get_anim_frame__13TUnk_804B5E48Fv)(arg0)) != 0U) {
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
        stack.spC += lbl_805DBC18[0];
        *(s32 *)((s8 *)arg0 + 0xB4) = (s32)create_particle_emitter((&stack.sp8), 0x90);
    } else {
        *(s32 *)((s8 *)arg0 + 0xB4) = 0;
    }
    return arg0;
}

void TObjCity_Season_ValentineHeart::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    temp_r3 = ((u8 * (*)(void *))get_anim_frame__13TUnk_804B5E48Fv)(arg0);
    if ((temp_r3 != NULL) && (((VObj_8018455c_80184408*)arg0)->m8(lbl_805DBC44[0], lbl_805DBC40[0]) != 0)) {
        TObjFish::set_global_param(*(s32 *)((s8 *)city_season_xmas_model_table + 4));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_model_motion((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x28)), (void *)(*(s32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 0x430)) + 0x14)), this->m_b0);
        pop_matrix();
    }
}

void TObjCity_Season_ValentineHeart::run_task() {
    s32 arg0 = (s32)this;
    ((TUnk_804B5E48 *)arg0)->advance_anim_time(1, lbl_805DBC70[0]);
}

}

#pragma pop

#pragma push

#include "types.h"

#include <stddef.h>
struct Stack_801846E0 {
    s32 sp8;
    f32 spC;
};

struct RecoveredGlobal_801846E0_lbl_804B5DD8 { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_801846E0_lbl_804B5DD8_size[sizeof(RecoveredGlobal_801846E0_lbl_804B5DD8) == 0x38 ? 1 : -1];

extern "C" {

void *create_particle_emitter(void *pos, s32 id);
int get_anim_frame__13TUnk_804B5E48Fv(void* a0);
extern s32 __vt__30TObjCity_Season_ValentineHeart[];
extern s32 TObjCity_Season_ValentineHeart__name;
}

extern "C" {

struct VBase_8018455c_80184620 { char pad[0x18]; };
struct VObj_8018455c_80184620 : VBase_8018455c_80184620 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
void __dl__7TObjectFPv(void *);

extern void *tl_05;

void *TObjCity_Season_ValentineHeart__create(void *arg0) {
    void *o = ((void * (*)(int))__nw__7TObjectFUl)(0xB8);
    if (o != NULL) {
        o = TObjCity_Season_ValentineHeart__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

extern s32 __vt__30TObjCity_Season_ValentineHeart[];

void *__dt__30TObjCity_Season_ValentineHeartFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__30TObjCity_Season_ValentineHeart;
        if (*(void **)((s8 *)arg0 + 0xB4) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xB4)); *(s32 *)((s8 *)arg0 + 0xB4) = 0; }
        ((TUnk_804B5E48 *)arg0)->destroy_seasonal_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 city_season_xmas_model_table[];

u8 *TObjCity_Season_ValentineHeart__ct(u8 *arg0, s32 arg1, s32 arg2) {
    typedef char sp8_offset[(offsetof(Stack_801846E0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_801846E0, spC) == 0x4) ? 1 : -1];
    Stack_801846E0 stack;
    ((s32 (*)(void *, void *, void *, int, f32))init_city_season_object)((void *)arg0, (void *)arg1, (void *)arg2, 1, (f32)lbl_805DBC78[0]);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_801846E0_lbl_804B5DD8 *)&__vt__30TObjCity_Season_ValentineHeart).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjCity_Season_ValentineHeart__name;
    if (((u32)((u8 * (*)(void *))get_anim_frame__13TUnk_804B5E48Fv)(arg0)) != 0U) {
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
        stack.spC += lbl_805DBC18[0];
        *(s32 *)((s8 *)arg0 + 0xB4) = (s32)create_particle_emitter((&stack.sp8), 0x90);
    } else {
        *(s32 *)((s8 *)arg0 + 0xB4) = 0;
    }
    return arg0;
}

void TObjCity_Season_EasterEgg::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    temp_r3 = ((u8 * (*)(void *))get_anim_frame__13TUnk_804B5E48Fv)(arg0);
    if ((temp_r3 != NULL) && (((VObj_8018455c_80184620*)arg0)->m8(lbl_805DBC44[0], lbl_805DBC40[0]) != 0)) {
        TObjFish::set_global_param(city_season_xmas_model_table[0]);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_chunk_object((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x18)));
        draw_chunk_object((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x8)));
        pop_matrix();
    }
}

}

#pragma pop

#pragma push

#include "types.h"

#include <stddef.h>
struct Stack_8018493C {
    s32 sp8;
    f32 spC;
};

struct RecoveredGlobal_8018493C_lbl_804B5E10 { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_8018493C_lbl_804B5E10_size[sizeof(RecoveredGlobal_8018493C_lbl_804B5E10) == 0x38 ? 1 : -1];

struct Info_80184A08 { u32 f0; u32 n; };

struct Ent_80184A08 { u32 f0; Info_80184A08 *info; };

struct Anim_80184A08 { u8 pad[0x430]; Ent_80184A08 *ents; };

struct Obj_80184A08 { u8 pad[0xB0]; f32 t; };

extern "C" {

void *create_particle_emitter(void *pos, s32 id);
int get_anim_frame__13TUnk_804B5E48Fv(void* a0);
extern s32 __vt__25TObjCity_Season_EasterEgg[];
extern s32 TObjCity_Season_EasterEgg__name;

}

extern "C" {

void __dl__7TObjectFPv(void *);

void TObjCity_Season_EasterEgg::run_task() {
    s32 temp_r3;

    if (((u32 (*)(void *))get_anim_frame__13TUnk_804B5E48Fv)(this) != 0U) {
        *(s32 *)((s8 *)this + 0xB4) = (s32) (*(s32 *)((s8 *)this + 0xB4) + 2);
        temp_r3 = *(s32 *)((s8 *)this + 0xB4);
        if (temp_r3 >= 0xFF) {
            *(s32 *)((s8 *)this + 0xB4) = (temp_r3 - 0xFF);
        }
    }
}

extern void *tl_05;

void *TObjCity_Season_EasterEgg__create(void *arg0) {
    void *o = ((void * (*)(int))__nw__7TObjectFUl)(0xC0);
    if (o != NULL) {
        o = TObjCity_Season_EasterEgg__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

extern s32 __vt__25TObjCity_Season_EasterEgg[];

void *__dt__25TObjCity_Season_EasterEggFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__25TObjCity_Season_EasterEgg;
        if (*(void **)((s8 *)arg0 + 0xB8) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xB8)); ((TObjCity_Season_EasterEgg *)arg0)->m_b8 = 0; }
        if (*(void **)((s8 *)arg0 + 0xBC) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xBC)); *(s32 *)((s8 *)arg0 + 0xBC) = 0; }
        ((TUnk_804B5E48 *)arg0)->destroy_seasonal_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TObjCity_Season_EasterEgg__ct(u8 *city_season_easter_egg, s32 arg1, s32 arg2) {
    typedef char sp8_offset[(offsetof(Stack_8018493C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8018493C, spC) == 0x4) ? 1 : -1];
    Stack_8018493C stack;
    ((s32 (*)(void *, void *, void *, int, f32))init_city_season_object)((void *)city_season_easter_egg, (void *)arg1, (void *)arg2, 0, (f32)lbl_805DBC78[0]);
    *(s32 **)((s8 *)city_season_easter_egg + 0x18) = &(*(RecoveredGlobal_8018493C_lbl_804B5E10 *)&__vt__25TObjCity_Season_EasterEgg).value;
    *(s32 *)((s8 *)city_season_easter_egg + 0) = (s32) TObjCity_Season_EasterEgg__name;
    *(s32 *)((s8 *)city_season_easter_egg + 0xB4) = 0;
    if (((u32 (*)(void *))get_anim_frame__13TUnk_804B5E48Fv)(city_season_easter_egg) != 0U) {
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(city_season_easter_egg + 0x38));
        stack.spC += lbl_805DBC18[0];
        ((TObjCity_Season_EasterEgg *)city_season_easter_egg)->m_b8 = (s32)create_particle_emitter((&stack.sp8), 0x90);
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(city_season_easter_egg + 0x38));
        stack.spC += lbl_805DBC7C[0];
        *(s32 *)((s8 *)city_season_easter_egg + 0xBC) = (s32)create_particle_emitter((&stack.sp8), 0x91);
    } else {
        ((TObjCity_Season_EasterEgg *)city_season_easter_egg)->m_b8 = 0;
        *(s32 *)((s8 *)city_season_easter_egg + 0xBC) = 0;
    }
    return city_season_easter_egg;
}
s32 TUnk_804B5E48::advance_anim_time(s32 arg1, f32 farg0) {
    Obj_80184A08 *arg0 = (Obj_80184A08 *)this;
    Anim_80184A08 *a;
    f32 lim;
    a = (Anim_80184A08 *)((u32 (*)(void *))get_anim_frame__13TUnk_804B5E48Fv)(arg0);
    if (a != NULL) {
        lim = (a->ents[arg1].info->n - 1);
        this->m_b0 += farg0;
        if (this->m_b0 >= lim) {
            this->m_b0 -= lim;
        }
        return 1;
    }
    return 0;
}

}

#pragma pop

#pragma push

#include "types.h"

extern "C" {

int get_anim_frame__13TUnk_804B5E48Fv(void* a0);
s32 free_collision_body_parts(void *);

#define city_season_easter_egg_model_table (*(int (*)[1])&city_season_easter_egg_model_table)
int TUnk_804B5E48::get_anim_frame() {  return city_season_easter_egg_model_table[*(int *)&this->unk_AC]; }

extern s32 lbl_804B5E48[];

void *TUnk_804B5E48::destroy_seasonal_object(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804B5E48;
        if (((u32) this->bodies) != 0U) {
            unregister_object_by_id();
            free_collision_body_parts(this);
        }
        __dt__14TObjCollidableFv(this, 0);
        if (arg1 > 0) {
            ((s32 (*)(void *))__dl__7TObjectFPv)(this);
        }
    }
    return this;
}

}

#pragma pop

#undef city_season_easter_egg_model_table
#define VObj_18_1a504b VObj_18_1a504b_sf2p1995
#define VBase_18_1a504b VBase_18_1a504b_sf2p1995
#pragma push

#include "types.h"
#include "pso/player/TObjPlayer.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

struct ByteBlock_2C { u8 bytes[0x2C]; };

struct RecoveredGlobal_80184B44_lbl_804B5E48 {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
s32 init_collision_body_parts(void *, void *, int);

extern const RecoveredGlobal_80184B44_lbl_804440B0 city_season_collision_template;
}

extern "C" {

typedef char RecoveredGlobal_80184B44_lbl_804440B0_size[sizeof(RecoveredGlobal_80184B44_lbl_804440B0) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80184B44_lbl_804B5E48_size[sizeof(RecoveredGlobal_80184B44_lbl_804B5E48) == 0x38 ? 1 : -1];
u8 *init_city_season_object(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0) {
    struct CopyStack_80184B44 { u8 bytes[0x2C]; };
    CopyStack_80184B44 copy_storage_80184B44;
    __ct__14TObjCollidableFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80184B44_lbl_804B5E48 *)&lbl_804B5E48).value;
    ((TUnk_804B5E48 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0xAC) = arg3;
    if (((u32 (*)(void *))get_anim_frame__13TUnk_804B5E48Fv)(arg0) != 0U) {
        *(ByteBlock_2C *)(copy_storage_80184B44.bytes) = *(const ByteBlock_2C *)((s32) ((u8 *)&city_season_collision_template.value - 4) + 4);
        (*(f32 *)(copy_storage_80184B44.bytes + 0xC)) = farg0;
        init_collision_body_parts(arg0, (void *) ((copy_storage_80184B44.bytes)), 1);
        ((TObjPlayer *)arg0)->register_object_by_id();
    } else {
        *(s32 *)((s8 *)arg0 + 0xA4) = 0;
    }
    ((TUnk_804B5E48 *)arg0)->m_b0 = (f32) lbl_805DBC1C[0];
    return arg0;
}

}

#pragma pop

#undef VBase_18_1a504b
#undef VObj_18_1a504b
#undef lbl_804441FC
extern "C" {
s32 TObjCity_Season_EasterEgg__name = (s32)TObjCity_Season_EasterEgg__class_name;
s32 TObjCity_Season_ValentineHeart__name = (s32)TObjCity_Season_ValentineHeart__class_name;
s32 TObjCity_Season_XmasTree__name = (s32)TObjCity_Season_XmasTree__class_name;
s32 TObjCity_Season_XmasWreath__name = (s32)TObjCity_Season_XmasWreath__class_name;
s32 TObjCity_Season_HalloweenPumpkin__name = (s32)TObjCity_Season_HalloweenPumpkin__class_name;
s32 TObjCity_Season_21_21__name = (s32)TObjCity_Season_21_21__class_name;
s32 TObjCity_Season_SonicAdv2__name = (s32)TObjCity_Season_SonicAdv2__class_name;
s32 TObjCity_Season_Board__name = (s32)TObjCity_Season_Board__class_name;
s32 TObjCity_Season_FireWorkCtrl__name = (s32)TObjCity_Season_FireWorkCtrl__class_name;
s32 TObjCity_Season_FireWork__name = (s32)TObjCity_Season_FireWork__class_name;
}
