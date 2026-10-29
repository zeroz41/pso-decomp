#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_802F3CA0_lbl_80474508 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_802F3CA0_lbl_80474530 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_802F3CA0_lbl_80474558 {
    s32 value;
    u8 remaining[0x24];
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

typedef struct A_802F3D6C { u8 pad0[4]; s32 idx; u8 pad8[8]; } A_802F3D6C;

typedef struct Anim_802F3D6C { u8 pad0[4]; u32 nframes; } Anim_802F3D6C;

typedef struct B_802F3D6C { u8 pad0[4]; Anim_802F3D6C *anim; } B_802F3D6C;

struct Pair_802F3D18 { s32 a; s32 b; };

extern "C" {
extern RecoveredGlobal_802F3CA0_lbl_80474508 boss8_dragon_mode_params;
extern RecoveredGlobal_802F3CA0_lbl_80474530 dragon_mode_params_a;
extern RecoveredGlobal_802F3CA0_lbl_80474558 dragon_mode_params_b;
void TObjLight__sub_801337F8(s32);
void scale_matrix(s32, f32, f32, f32);
void rotate_matrix_y(s32, s32);
void push_matrix(void);
void post_translate_matrix(void *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern s32 current_scene_light;
extern s32 model_render_flags;
extern const f32 TBoss8Dragon__data_805DED50;
extern const f32 lbl_805DED54;
extern const f32 TBoss8Dragon__data_805DED58;
extern const f32 lbl_805DED5C;
extern const f32 TBoss8Dragon__data_805DED60;
f32 receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(void *, void *, Pair_802F3D18 *, s32, s32, s32);
f32 calc_direct_attack_damage__12TBoss8DragonFPvPvPviii(void *a, void *b, Pair_802F3D18 *p, s32 x, s32 y, s32 z);
typedef char RecoveredGlobal_802F3CA0_lbl_80474508_size[sizeof(RecoveredGlobal_802F3CA0_lbl_80474508) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_802F3CA0_lbl_80474530_size[sizeof(RecoveredGlobal_802F3CA0_lbl_80474530) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_802F3CA0_lbl_80474558_size[sizeof(RecoveredGlobal_802F3CA0_lbl_80474558) == 0x28 ? 1 : -1];
void TBoss8Dragon::set_mode_params(s8 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x3E8) = (s32) arg1;
    switch (*(s32 *)((s8 *)arg0 + 0x3E8)) {
    case 0:
        *(s32 *)&this->unk_75C = 1;
        this->m_760 = &boss8_dragon_mode_params.value;
        return;
    case 1:
        *(s32 *)&this->unk_75C = 2;
        this->m_760 = &dragon_mode_params_a.value;
        return;
    case 2:
        *(s32 *)&this->unk_75C = 3;
        this->m_760 = &dragon_mode_params_b.value;
        return;
    }
}

f32 calc_direct_attack_damage__12TBoss8DragonFPvPvPviii(void *a, void *b, Pair_802F3D18 *p, s32 x, s32 y, s32 z) {
    switch (p->a) {
    case 0xB:
    case 0xC:
        return TBoss8Dragon__data_805DED50;
    }
    Pair_802F3D18 t = *p;
    return receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(a, b, &t, x, y, z);
}

void TBoss8Dragon::draw_motion_model() {
    u8 *arg0 = (u8 *)this;
    f32 f;
    s32 idx;
    Anim_802F3D6C *anim;
    if (((VObj_18_26a62c *)(arg0))->m8(lbl_805DED54, TBoss8Dragon__data_805DED58) != 0) {
        TObjFish::set_global_param(*(s32 *)(arg0 + 0x24));
        push_matrix();
        post_translate_matrix((u8 *)&this->m_38);
        rotate_matrix_y(0, *(s32 *)(arg0 + 0x60));
        push_matrix();
        scale_matrix(0, lbl_805DED5C, TBoss8Dragon__data_805DED60, lbl_805DED5C);
        pop_matrix();
        scale_matrix(0, TBoss8Dragon__data_805DED60, TBoss8Dragon__data_805DED60, TBoss8Dragon__data_805DED60);
        model_render_flags &= ~0x400;
        idx = *(f32 *)(arg0 + 0x354);
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 0x1C) {
            idx = 0x1B;
        }
        anim = (*(B_802F3D6C **)(arg0 + 0xDC))[(*(A_802F3D6C **)(arg0 + 0xD8))[idx].idx].anim;
        f = *(f32 *)(arg0 + 0x358);
        if (f < TBoss8Dragon__data_805DED50) {
            f = TBoss8Dragon__data_805DED50;
        } else if (f > (f32)(anim->nframes - 1)) {
            f = anim->nframes;
        }
        set_motion_packed_rotation();
        draw_model_motion((void *)(*(s32 *)(arg0 + 0x34)), anim, f);
        clear_motion_packed_rotation();
        TObjLight__sub_801337F8(current_scene_light);
        pop_matrix();
    }
}

}
