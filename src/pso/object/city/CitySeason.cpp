#include "pso/system/BmlResource.h"
#include "pso/unk/text_80184C2C.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/darkfalz/TBoss4Type2_80086C44.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/object/city/CitySeason.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/vector.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/TUnk_804B5E48.h"
#include "pso/object/city/TObjCity_Season_XmasWreath.h"
#include "pso/object/city/TObjCity_Season_EasterEgg.h"
#include "pso/object/city/TObjCity_Season_ValentineHeart.h"
#include "pso/object/city/TObjCity_Season_XmasTree.h"
#include "pso/object/city/TObjCity_Season_HalloweenPumpkin.h"
#include "pso/object/city/TObjCity_Season_21_21.h"
#include "pso/object/city/TObjCity_Season_SonicAdv2.h"
#include "pso/object/city/TObjCity_Season_Board.h"
#include "pso/object/city/TObjCity_Season_FireWorkCtrl.h"
#include "pso/unk/text_803D8F74.h"
#include <stdlib.h>
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/system/task/TObject.h"
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
#include "pso/object/city/TObjCity_Season_FireWork.h"

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

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *, void *);
}

extern "C" {

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

}

struct Obj_8018355C;
extern "C" void sub_8018355C__28TObjCity_Season_FireWorkCtrlFv(struct Obj_8018355C *arg0);

extern "C" {
extern s32 __vt__24TObjCity_Season_FireWork[];
extern saddr TObjCity_Season_FireWork__name;

u8 *__ct__24TObjCity_Season_FireWorkFP7TObjectPvf(u8 *arg0, u8 *arg1, u8 *arg2, f32 farg0);
void debug_printf_at(s32 id, const char *fmt, ...);
}

extern "C" {

void __dl__7TObjectFPv(void *);

extern s32 __vt__24TObjCity_Season_FireWork[];

}


struct Stack_80183604
{
  f32 sp8;
  u8 pad_C[0x4];
  f32 sp10;
  f32 sp14;
  u8 trailing_storage[0x8];
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

struct V4_8018355C { s32 a; s32 b; s32 c; s32 d; };

extern "C" {
f32 vec3_dot(void *, void *);
f32 subtract_vector(void *, void *);
extern f32 lbl_804FF5E8[];
extern TCameraCtrl *camera_ctrl_instance;

void fn_80141CB8(void *, void *, void *, void *);
extern const u32 lbl_804441FC[5];
#define lbl_804441FC ((const V4_8018355C *)lbl_804441FC)

void sub_8018355C__28TObjCity_Season_FireWorkCtrlFv(Obj_8018355C *arg0);
}

extern "C" {

typedef struct Stack_80183604 Stack_80183604;
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma fp_contract on

}

#pragma pop

#pragma push
#include "types.h"

extern "C" {

void __dl__7TObjectFPv(void *);


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

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern const char *TObjCity_Season_FireWorkCtrl__name;
}


#pragma pop

#undef VBase_18_1a504b
#undef VObj_18_1a504b
#pragma push

#include "types.h"

extern "C" {

s32 post_translate_matrix(void *);
s32 scroll_strip_uvs(s32, s16, s32);

extern BmlResource *lbl_805D5B38;
extern saddr lbl_805D5B3C;
extern saddr lbl_805D5B40;
extern GinjaTextureList *lbl_805D5B44;
extern s32 lbl_805D5B48;

}

#pragma pop

#pragma push
#include "types.h"

extern "C" {

void __dl__7TObjectFPv(void *);


}

#pragma pop

#define VObj_18_1a504b VObj_18_1a504b_sf2p625
#define VBase_18_1a504b VBase_18_1a504b_sf2p625
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

struct EntA_80183AF0 { u8 pad[8]; saddr v; u8 padc[4]; };

struct EntB_80183AF0 { u8 pad[4]; saddr v; };

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
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 x60;
    u8 pad64[0xB0 - 0x64];
    f32 xb0;
};

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern const char *TObjCity_Season_Board__name;

int get_anim_frame__13TUnk_804B5E48Fv(void* a0);

}

extern "C" {

#pragma push
#pragma opt_common_subs off
#pragma pop

}

#pragma pop

#undef VBase_18_1a504b
#undef VObj_18_1a504b
#pragma push
#include "types.h"


#pragma pop

#pragma push
#include "types.h"

extern "C" {

void __dl__7TObjectFPv(void *);


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

extern "C" {

int get_anim_frame__13TUnk_804B5E48Fv(void* a0);

s32 post_translate_matrix(void *);

extern saddr lbl_805D5B34;
}


#pragma pop

#pragma push
#include "types.h"

extern "C" {

void __dl__7TObjectFPv(void *);


}

#pragma pop

#define VObj_18_26a62c VObj_18_26a62c_sf2p1056
#define VBase_18_26a62c VBase_18_26a62c_sf2p1056
#pragma push

#include "types.h"

#include <stddef.h>

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

extern "C" {

int get_anim_frame__13TUnk_804B5E48Fv(void* a0);

s32 post_translate_matrix(void *);

}


#pragma pop

#undef VBase_18_26a62c
#undef VObj_18_26a62c
#pragma push
#include "types.h"

extern "C" {

void __dl__7TObjectFPv(void *);


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

struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

extern "C" {

s32 post_translate_matrix(void *);

s32 __ct__8TObjBaseFP7TObject(void *, void *);
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

struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *, void *);
}

extern "C" {

s32 post_translate_matrix(void *);

void __dl__7TObjectFPv(void *);

int get_anim_frame__13TUnk_804B5E48Fv(void* a0);


}

#pragma pop

#undef VBase_18_1a504b
#undef VObj_18_1a504b
#pragma push

#include "types.h"

#include <stddef.h>

extern "C" {

int get_anim_frame__13TUnk_804B5E48Fv(void* a0);
}

extern "C" {

s32 post_translate_matrix(void *);

void __dl__7TObjectFPv(void *);


}

#pragma pop

#pragma push

#include "types.h"

#include <stddef.h>

extern "C" {

int get_anim_frame__13TUnk_804B5E48Fv(void* a0);
}

extern "C" {

s32 post_translate_matrix(void *);
void __dl__7TObjectFPv(void *);


}

#pragma pop

#pragma push

#include "types.h"

#include <stddef.h>

struct Info_80184A08 { u32 f0; u32 n; };

struct Ent_80184A08 { u32 f0; Info_80184A08 *info; };

struct Anim_80184A08 { u8 pad[0x430]; Ent_80184A08 *ents; };

struct Obj_80184A08 { u8 pad[0xB0]; f32 t; };

extern "C" {

int get_anim_frame__13TUnk_804B5E48Fv(void* a0);

}

extern "C" {

void __dl__7TObjectFPv(void *);


}

#pragma pop

#pragma push

#include "types.h"

extern "C" {

int get_anim_frame__13TUnk_804B5E48Fv(void* a0);
s32 free_collision_body_parts(void *);


}

#pragma pop

#define VObj_18_1a504b VObj_18_1a504b_sf2p1995
#define VBase_18_1a504b VBase_18_1a504b_sf2p1995
#pragma push

#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

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

extern "C" {
s32 init_collision_body_parts(void *, void *, int);

extern const RecoveredGlobal_80184B44_lbl_804440B0 city_season_collision_template;
}

#pragma pop

#undef VBase_18_1a504b
#undef VObj_18_1a504b
extern "C" {
const char *TObjCity_Season_EasterEgg__name = TObjCity_Season_EasterEgg__class_name;
const char *TObjCity_Season_ValentineHeart__name = TObjCity_Season_ValentineHeart__class_name;
const char *TObjCity_Season_XmasTree__name = TObjCity_Season_XmasTree__class_name;
const char *TObjCity_Season_XmasWreath__name = TObjCity_Season_XmasWreath__class_name;
const char *TObjCity_Season_HalloweenPumpkin__name = TObjCity_Season_HalloweenPumpkin__class_name;
const char *TObjCity_Season_21_21__name = TObjCity_Season_21_21__class_name;
const char *TObjCity_Season_SonicAdv2__name = TObjCity_Season_SonicAdv2__class_name;
const char *TObjCity_Season_Board__name = TObjCity_Season_Board__class_name;
const char *TObjCity_Season_FireWorkCtrl__name = TObjCity_Season_FireWorkCtrl__class_name;
saddr TObjCity_Season_FireWork__name = (saddr)TObjCity_Season_FireWork__class_name;
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
TUnk_804B5E48::TUnk_804B5E48(TObject *parent, void *set_data, s32 kind, f32 radius) : TObjCollidable(parent) {
    apply_object_set_data(set_data);
    model_index = kind;
    if (get_anim_frame() != NULL) {
        RecoveredGlobal_80184B44_lbl_804440B0 shape = city_season_collision_template;
        *(f32 *)(shape.remaining + 8) = radius;
        init_collision_body_parts(this, &shape, 1);
        register_object_by_id();
    } else {
        bodies = NULL;
    }
    m_b0 = 0.0f;
}
#pragma pop

TUnk_804B5E48::~TUnk_804B5E48() {
    if (bodies != NULL) {
        unregister_object_by_id();
        free_collision_body_parts(this);
    }
}

void *TUnk_804B5E48::get_anim_frame() { return city_season_easter_egg_model_table[model_index]; }

extern "C" {
s32 TUnk_804B5E48::advance_anim_time(s32 arg1, f32 farg0) {
    Obj_80184A08 *arg0 = (Obj_80184A08 *)this;
    Anim_80184A08 *a;
    f32 lim;
    a = (Anim_80184A08 *)(uaddr)((TUnk_804B5E48 *)arg0)->get_anim_frame();
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

TObjCity_Season_EasterEgg::TObjCity_Season_EasterEgg(TObject *parent, void *set_data)
    : TUnk_804B5E48(parent, set_data, 0, 13.0f) {
    Vec pos;
    m_name = TObjCity_Season_EasterEgg__name;
    unk_B4 = 0;
    if (get_anim_frame() != NULL) {
        VecCopy(&pos, &position);
        pos.y += 4.0f;
        emitter = create_particle_emitter(&pos, 0x90);
        VecCopy(&pos, &position);
        pos.y += 25.0f;
        upper_emitter = create_particle_emitter(&pos, 0x91);
    } else {
        emitter = NULL;
        upper_emitter = NULL;
    }
}

TObjCity_Season_EasterEgg::~TObjCity_Season_EasterEgg() {
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
    if (upper_emitter != NULL) {
        upper_emitter->queue_destruction();
        upper_emitter = NULL;
    }
}

extern "C" {
void *TObjCity_Season_EasterEgg__create(void *arg0) {
    return new TObjCity_Season_EasterEgg(tl_05, arg0);
}
}

extern "C" {
void TObjCity_Season_EasterEgg::run_task() {
    if (get_anim_frame() != NULL) {
        unk_B4 += 2;
        if (unk_B4 >= 0xFF) {
            unk_B4 -= 0xFF;
        }
    }
}
}

extern "C" {
void TObjCity_Season_EasterEgg::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    temp_r3 = (u8 *)((TUnk_804B5E48 *)arg0)->get_anim_frame();
    if ((temp_r3 != NULL) && (this->update_object_view_visibility(800.0f, 50.0f) != 0)) {
        TObjFish::set_global_param((saddr)city_season_xmas_model_table[0]);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_chunk_object(*(void **)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x18));
        draw_chunk_object(*(void **)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x8));
        pop_matrix();
    }
}
}

TObjCity_Season_ValentineHeart::TObjCity_Season_ValentineHeart(TObject *parent, void *set_data)
    : TUnk_804B5E48(parent, set_data, 1, 13.0f) {
    Vec pos;
    m_name = TObjCity_Season_ValentineHeart__name;
    if (get_anim_frame() != NULL) {
        VecCopy(&pos, &position);
        pos.y += 4.0f;
        emitter = create_particle_emitter(&pos, 0x90);
    } else {
        emitter = NULL;
    }
}

TObjCity_Season_ValentineHeart::~TObjCity_Season_ValentineHeart() {
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
}

extern "C" {
void *TObjCity_Season_ValentineHeart__create(void *arg0) {
    return new TObjCity_Season_ValentineHeart(tl_05, arg0);
}
}

extern "C" {
void TObjCity_Season_ValentineHeart::run_task() {
    saddr arg0 = (saddr)this;
    ((TUnk_804B5E48 *)arg0)->advance_anim_time(1, 0.2f);
}
}

extern "C" {
void TObjCity_Season_ValentineHeart::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    temp_r3 = (u8 *)((TUnk_804B5E48 *)arg0)->get_anim_frame();
    if ((temp_r3 != NULL) && (this->update_object_view_visibility(800.0f, 50.0f) != 0)) {
        TObjFish::set_global_param((saddr)city_season_xmas_model_table[1]);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_model_motion(*(void **)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x28), *(void **)((s8 *)(*(void **)((s8 *)temp_r3 + 0x430)) + 0x14), this->m_b0);
        pop_matrix();
    }
}
}

TObjCity_Season_XmasTree::TObjCity_Season_XmasTree(TObject *parent, void *set_data)
    : TUnk_804B5E48(parent, set_data, 2, 22.5f) {
    Vec pos;
    m_name = TObjCity_Season_XmasTree__name;
    if (get_anim_frame() != NULL) {
        VecCopy(&pos, &position);
        pos.y += 4.0f;
        emitter = create_particle_emitter(&pos, 0x90);
    } else {
        emitter = NULL;
    }
}

TObjCity_Season_XmasTree::~TObjCity_Season_XmasTree() {
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
}

extern "C" {
void *TObjCity_Season_XmasTree__create(void *arg0) {
    return new TObjCity_Season_XmasTree(tl_05, arg0);
}
}

#define VObj_18_1a504b VObj_18_1a504b_sf2p1365
#define VBase_18_1a504b VBase_18_1a504b_sf2p1365
extern "C" {
void TObjCity_Season_XmasTree::run_task() {
    saddr arg0 = (saddr)this;
    ((TUnk_804B5E48 *)arg0)->advance_anim_time(1, 0.2f);
}
}
#undef VObj_18_1a504b
#undef VBase_18_1a504b

#define VObj_18_1a504b VObj_18_1a504b_sf2p1365
#define VBase_18_1a504b VBase_18_1a504b_sf2p1365
extern "C" {
void TObjCity_Season_XmasTree::render() {
    u8 *temp_r3;

    temp_r3 = ((u8 * (*)())get_anim_frame__13TUnk_804B5E48Fv)();
    if ((temp_r3 != NULL) && (this->update_object_view_visibility(800.0f, 50.0f) != 0)) {
        TObjFish::set_global_param((saddr)city_season_xmas_model_table[2]);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_model_motion(*(void **)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x78), *(void **)((s8 *)(*(void **)((s8 *)temp_r3 + 0x430)) + 0xC), this->m_b0);
        draw_model_motion(*(void **)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x68), *(void **)((s8 *)(*(void **)((s8 *)temp_r3 + 0x430)) + 4), this->m_b0);
        draw_chunk_object(*(void **)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x88));
        draw_chunk_object(*(void **)((s8 *)(*(void **)((s8 *)temp_r3 + 0x42C)) + 0x98));
        pop_matrix();
    }
}
}
#undef VObj_18_1a504b
#undef VBase_18_1a504b

TObjCity_Season_XmasWreath::TObjCity_Season_XmasWreath(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjCity_Season_XmasWreath__name;
    apply_object_set_data(set_data);
}

TObjCity_Season_XmasWreath::~TObjCity_Season_XmasWreath() {}

extern "C" {
void *TObjCity_Season_XmasWreath__create(void *arg0) {
    return new TObjCity_Season_XmasWreath(tl_05, arg0);
}
}

#define VObj_18_1a504b VObj_18_1a504b_sf2p1248
#define VBase_18_1a504b VBase_18_1a504b_sf2p1248
#define VObj_18_26a62c VObj_18_26a62c_sf2p1248
#define VBase_18_26a62c VBase_18_26a62c_sf2p1248
extern "C" {
void TObjCity_Season_XmasWreath::render() {
    BmlResource *resource;
    resource = city_season_easter_egg_model_table[2];
    if ((resource != NULL) && (this->update_object_view_visibility(400.0f, 20.0f) != 0)) {
        TObjFish::set_global_param((saddr)city_season_xmas_model_table[2]);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        ((s32 (*)(int, int))rotate_matrix_y)(0, this->rotation_y);
        draw_chunk_object((void *)resource->models[5].model);
        pop_matrix();
    }
}
}
#undef VObj_18_1a504b
#undef VBase_18_1a504b
#undef VObj_18_26a62c
#undef VBase_18_26a62c

TObjCity_Season_HalloweenPumpkin::TObjCity_Season_HalloweenPumpkin(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjCity_Season_HalloweenPumpkin__name;
    apply_object_set_data(set_data);
}

TObjCity_Season_HalloweenPumpkin::~TObjCity_Season_HalloweenPumpkin() {}

extern "C" {
void *TObjCity_Season_HalloweenPumpkin__create(void *arg0) {
    return new TObjCity_Season_HalloweenPumpkin(tl_05, arg0);
}
}

#define VObj_18_26a62c VObj_18_26a62c_sf2p1056
#define VBase_18_26a62c VBase_18_26a62c_sf2p1056
extern "C" {
void TObjCity_Season_HalloweenPumpkin::run_task() {
    if (city_season_easter_egg_model_table[3] != NULL) {
        this->rotation_y = (this->rotation_y + 0x40);
    }
}
}
#undef VObj_18_26a62c
#undef VBase_18_26a62c

#define VObj_18_26a62c VObj_18_26a62c_sf2p1056
#define VBase_18_26a62c VBase_18_26a62c_sf2p1056
extern "C" {
void TObjCity_Season_HalloweenPumpkin::render() {
    BmlResource *resource;
    resource = city_season_easter_egg_model_table[3];
    if ((resource != NULL) && (this->update_object_view_visibility(800.0f, 80.0f) != 0)) {
        TObjFish::set_global_param((saddr)city_season_xmas_model_table[3]);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        ((s32 (*)(int, int))rotate_matrix_y)(0, this->rotation_y);
        draw_chunk_object((void *)resource->models[0].model);
        pop_matrix();
    }
}
}
#undef VObj_18_26a62c
#undef VBase_18_26a62c

TObjCity_Season_21_21::TObjCity_Season_21_21(TObject *parent, void *set_data)
    : TUnk_804B5E48(parent, set_data, 4, 23.0f) {
    Vec pos;
    m_name = TObjCity_Season_21_21__name;
    uv_scroll = 0;
    if (get_anim_frame() != NULL) {
        VecCopy(&pos, &position);
        pos.y += 20.0f;
        emitter = create_particle_emitter(&pos, 0x90);
    } else {
        emitter = NULL;
    }
}

TObjCity_Season_21_21::~TObjCity_Season_21_21() {
    if (emitter != NULL) {
        emitter->queue_destruction();
        emitter = NULL;
    }
}

extern "C" {
void *TObjCity_Season_21_21__create(void *arg0) {
    return new TObjCity_Season_21_21(tl_05, arg0);
}
}

extern "C" {
void TObjCity_Season_21_21::run_task() {
    if (advance_anim_time(0, 0.3f) != 0) {
        uv_scroll += 2;
        if (uv_scroll >= 0xFF) {
            uv_scroll -= 0xFF;
        }
    }
}
}

extern "C" {
void TObjCity_Season_21_21::render() {
    u8 *temp_r3;
    temp_r3 = (u8 *)(((u8 * (*)())get_anim_frame__13TUnk_804B5E48Fv)());
    if (temp_r3 != NULL) {
        if (this->update_object_view_visibility(800.0f, 60.0f) != 0) {
            TObjFish::set_global_param((saddr)city_season_xmas_model_table[4]);
            ((s32 (*)(void *, int, int))scroll_strip_uvs)((void *)lbl_805D5B34, 0, (int) ((s16) uv_scroll));
            push_matrix();
            post_translate_matrix((u8 *)&this->position);
            ((s32 (*)(int, int))rotate_matrix_y)(0, this->rotation_y);
            draw_chunk_object(*(void **)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0x42C)) + 0x18));
            draw_model_motion(*(void **)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0x42C)) + 8), *(void **)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0x430)) + 4), this->m_b0);
            pop_matrix();
        }
    }
}
}

TObjCity_Season_SonicAdv2::TObjCity_Season_SonicAdv2(TObject *parent, void *set_data)
    : TUnk_804B5E48(parent, set_data, 5, 3.0f) {
    m_name = TObjCity_Season_SonicAdv2__name;
}

TObjCity_Season_SonicAdv2::~TObjCity_Season_SonicAdv2() {}

extern "C" {
void *TObjCity_Season_SonicAdv2__create(void *arg0) {
    return new TObjCity_Season_SonicAdv2(tl_05, arg0);
}
}

extern "C" {
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

extern "C" {
void TObjCity_Season_SonicAdv2::run_task() { advance_anim_time(sub_80183C38(), 0.3f); }
}

#define VObj_18_1a504b VObj_18_1a504b_sf2p625
#define VBase_18_1a504b VBase_18_1a504b_sf2p625
#pragma push
#pragma opt_common_subs off
extern "C" {
void TObjCity_Season_SonicAdv2::render() {
    Obj_80183AF0 *self = (Obj_80183AF0 *)this;
    Res_80183AF0 *res;
    s32 idx;
    Vec pos;
    Vec a;
    Vec b;
    res = (Res_80183AF0 *)((TUnk_804B5E48 *)self)->get_anim_frame();
    if (res != NULL && self->m8(800.0f, 20.0f) != 0) {
        TObjFish::set_global_param((saddr)city_season_xmas_model_table[5]);
        idx = ((TObjCity_Season_SonicAdv2 *)self)->sub_80183C38();
        push_matrix();
        ((void (*)(void *))post_translate_matrix)(&self->pos);
        ((void (*)(int, s32))rotate_matrix_y)(0, self->x60);
        draw_model_motion((void *)res->a[idx].v, (void *)res->b[idx].v, self->xb0);
        pop_matrix();
        VecCopy((Vec *)&pos, (const Vec *)&self->pos);
        pos.y += 0.037f;
        a.x = 0.0f;
        a.y = 1.0f;
        a.z = 0.0f;
        b.x = 1.0f;
        b.y = 0.0f;
        b.z = 1.3f;
        TObjEneDD::draw_oriented_shadow(&pos, &a, self->x60, &b);
    }
}
}
#pragma pop
#undef VObj_18_1a504b
#undef VBase_18_1a504b

#define VObj_18_1a504b VObj_18_1a504b_sf2p625
#define VBase_18_1a504b VBase_18_1a504b_sf2p625
extern "C" {
void TObjCity_Season_SonicAdv2::debug_draw_model_index() {
    sub_80183C38();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, "<- MDL IDX");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}
}
#undef VObj_18_1a504b
#undef VBase_18_1a504b

TObjCity_Season_Board::TObjCity_Season_Board(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjCity_Season_Board__name;
    apply_object_set_data(set_data);
    uv_scroll = 0;
}

TObjCity_Season_Board::~TObjCity_Season_Board() {}

extern "C" {
void *TObjCity_Season_Board__create(void *arg0) {
    return new TObjCity_Season_Board(tl_05, arg0);
}
}

extern "C" {
void TObjCity_Season_Board::run_task() {
    s32 temp_r4;

    this->uv_scroll = (s32) (this->uv_scroll + 2);
    temp_r4 = this->uv_scroll;
    if (temp_r4 >= 0x100) {
        this->uv_scroll = (temp_r4 - 0x100);
    }
}
}

extern "C" {
void TObjCity_Season_Board::render() {
    if ((lbl_805D5B38 != NULL) && (this->update_object_view_visibility(800.0f, 200.0f) != 0)) {
        TObjFish::set_global_param((saddr)lbl_805D5B44);
        scroll_strip_uvs(lbl_805D5B48, (s16) this->uv_scroll, 0);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_chunk_object((void *)lbl_805D5B3C);
        draw_chunk_object((void *)lbl_805D5B40);
        pop_matrix();
    }
}
}

TObjCity_Season_FireWorkCtrl::TObjCity_Season_FireWorkCtrl(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjCity_Season_FireWorkCtrl__name;
    apply_object_set_data(set_data);
    unk_90 = 0;
}

TObjCity_Season_FireWorkCtrl::~TObjCity_Season_FireWorkCtrl() {}

extern "C" {
void *TObjCity_Season_FireWorkCtrl__create(void *arg0) {
    return new TObjCity_Season_FireWorkCtrl(tl_05, arg0);
}
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma fp_contract on
extern "C" {
void TObjCity_Season_FireWorkCtrl::run_task() {
    u8 *arg0 = (u8 *)this;
  Stack_80183604 stack;
  f32 temp_f30;
  float new_var;
  f32 temp_f31;
  uaddr temp_r3;
  f32 temp_f29;
  if (TLobby__sub_80184C54() != 0)
  {
    *((s32 *) (((s8 *) arg0) + 0x90)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x90))) - 1);
    if (((s32) (*((s32 *) (((s8 *) arg0) + 0x90)))) < 0)
    {
      VecCopy((Vec *)(&stack.sp14), (const Vec *)(arg0 + 0x38));
      subtract_vector((void *)&stack.sp14, &camera_ctrl_instance->pos_x);
      if ((normalize_vector_safe((Vec *)&stack.sp14) < 450.0f) && (vec3_dot((void *)&stack.sp14, (void *) ((u8 *)&lbl_804FF5E8 + 0xC)) > 0.0f))
      {
        temp_f30 = rand_signed_unit();
        temp_f30 = (this->scale.x) * temp_f30;
        temp_f31 = temp_f30;
        new_var = (*((f32 *) (((s8 *) arg0) + 0x70))) * rand_signed_unit();
        temp_f30 = new_var;
        temp_f29 = (50.0f * (3.0517578e-05f * ((f32) rand()))) + (this->scale.y);
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
        stack.sp8 += temp_f31;
        stack.sp10 += temp_f30;
        temp_r3 = (uaddr)TObject::operator new(0x40);
        if (temp_r3 != 0U)
        {
          ((s32 (*)(int, void *, void *, f32))__ct__24TObjCity_Season_FireWorkFP7TObjectPvf)((int) temp_r3, (void *) arg0, (void *)&stack.sp8, (f32) temp_f29);
        }
      }
      *((s32 *) (((s8 *) arg0) + 0x90)) = (s32) (3.0f * (((f32) ((this->set_params[0]) + 0x3C)) * (3.0517578e-05f * ((f32) rand()))));
    }
  }
}
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma fp_contract on
extern "C" {
void TObjCity_Season_FireWorkCtrl::sub_8018355C() {
    Obj_8018355C *arg0 = (Obj_8018355C *)this;
    if (arg0->v8(250.0f, 10.0f) != 0) {
        Vec sp18;
        V4_8018355C sp8 = lbl_804441FC[0];
        arg0->f64 = 0;
        arg0->f5C = 0;
        sp18.x = arg0->f68;
        sp18.y = 3.0f;
        sp18.z = arg0->f70;
        fn_80141CB8(arg0->pos, &arg0->f5C, &sp18, &sp8);
    }
}
}
#pragma pop

extern "C" {
void TObjCity_Season_FireWorkCtrl::vfunc_13(s32) {
    ((void (*)(void))sub_8018355C__28TObjCity_Season_FireWorkCtrlFv)();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x13001C, "<- AREA WIDTH");
    debug_printf_at(0x13001D, "<- RISE HEIGHT");
    debug_printf_at(0x13001E, "<- AREA DEPTH");
    debug_printf_at(0x130020, "<- FREQ");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}
}

TObjCity_Season_FireWork::TObjCity_Season_FireWork(TObject* parent, void* position, f32 riseHeight) : TObject(parent) {
    m_name = (const char*)TObjCity_Season_FireWork__name;
    VecCopy(&pos, (const Vec *)position);
    state = 0;
    handle = NULL;
    limit = riseHeight;
    timer = 0;
    burstEffectId = 0;
    riseDistance = 0.0f;
}

TObjCity_Season_FireWork::~TObjCity_Season_FireWork() {
    if (handle != NULL) { handle->queue_destruction(); handle = NULL; }
}

void TObjCity_Season_FireWork::run_task() {
    TObjCity_Season_FireWork *self = this;
    switch (self->state) {
    case 0:
        if (self->handle == NULL) {
            self->handle = spawn_continuous_particle_effect_with_flags(&self->pos, 0x84, 0x40);
        }
        if (self->handle != NULL) {
            self->riseDistance += 4.0f;
            self->pos.y += 4.0f;
            if (self->riseDistance >= self->limit) {
                self->riseDistance = 0.0f;
                self->timer = 0;
                self->state = 1;
                self->handle->queue_destruction();
                self->handle = NULL;
            } else {
                self->handle->set_position(&self->pos);
            }
        }
        break;
    case 1:
        if (self->timer == 10) {
            spawn_particle_effect_with_flags(&self->pos, 0x85, 0x40);
            spawn_particle_effect_with_flags(&self->pos, 0x86, 0x40);
        }
        self->timer++;
        if (self->timer >= 15) {
            f32 r = 3.0517578e-05f * (f32)rand();
            self->timer = 0;
            if (r < 0.33f) {
                self->burstEffectId = 0x87;
                self->state = 2;
            } else if (r < 0.66f) {
                self->burstEffectId = 0x88;
                self->state = 2;
            } else {
                self->state = 3;
            }
        }
        break;
    case 2:
        if (self->timer == 0 || self->timer == 4 || self->timer == 8) {
            spawn_particle_effect_with_flags(&self->pos, self->burstEffectId, 0x40);
        }
        self->timer++;
        self->pos.y -= 0.8f;
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
            create_oneshot_particle_emitter(&self->pos, &v, 0x89, 0x40);
        }
        self->timer++;
        self->pos.y -= 0.8f;
        if (self->timer > 8) {
            self->state = 4;
        }
        break;
    case 4:
        self->queue_destruction();
        break;
    }
}
