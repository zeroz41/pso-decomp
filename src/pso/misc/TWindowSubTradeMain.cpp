#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneMorfos.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct Stack_80332594 {
    s32 sp8;
    f32 spC;
};

struct VBase_803323D8 { char pad[0x18]; };

struct VObj_803323D8 : VBase_803323D8 {
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

struct V3_803323D8 { f32 x, y, z; };

struct Anim_803323D8 { s32 a; u32 count; };

struct Bone_803323D8 { s32 a; Anim_803323D8 *anim; };

struct Mot_803323D8 { s32 a; s32 bone; s32 c; s32 d; };

struct O_803323D8 {
    u8 pad0[0x24]; s32 f24;
    u8 pad28[0x34 - 0x28]; s32 f34;
    u8 pad38[0x60 - 0x38]; s32 f60;
    u8 pad64[0xD8 - 0x64]; Mot_803323D8 *mots; Bone_803323D8 *bones;
    u8 padE0[0x326 - 0xE0]; s16 f326;
    u8 pad328[0x354 - 0x328]; f32 f354; f32 frame;
};

extern "C" {
extern s32 actor_frame_tick;
extern const f32 TObjEneMorfos__data_805DF870;
void update_player_state__9TObjEneDDFv(void *, V3_803323D8 *, int);
s32 rotate_matrix_y(int, int);
void push_matrix(void);
int post_translate_matrix(void *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern const V3_803323D8 lbl_804775F0;
extern const f32 TObjEneMorfos__data_805DF86C;
extern const f32 TObjEneMorfos__data_805DF874;
void* TObjEneMorfosArm__sub_803326B4(void* p);
s32 TObjEneMorfosArm__sub_803326BC(void* p);
void TWindowSubTradeMain__sub_803323A8(void* p);
void TWindowSubTradeMain__sub_803323B8(void* p);
void TWindowSubTradeMain__sub_803323C8(void* p);

void TWindowSubTradeMain__sub_803323A8(void* p) { *(u16*)((char*)p + 0x60) |= 0x40; }
void TWindowSubTradeMain__sub_803323B8(void* p) { *(u16*)((char*)p + 0x60) &= 0xffffffbf; }
void TWindowSubTradeMain__sub_803323C8(void* p) { *(u16*)((char*)p + 0x70) &= 0xfffffffb; }

void TObjEneMorfos::vfunc_106() {
    O_803323D8 *arg0 = (O_803323D8 *)this;
    s32 idx;
    f32 frame;
    Anim_803323D8 *anim;
    ((TObjEneDD *)arg0)->get_target_info();
    if (((VObj_803323D8 *)arg0)->m8(TObjEneMorfos__data_805DF86C, TObjEneMorfos__data_805DF870) != 0) {
        if (arg0->f326 != 0xB) {
            V3_803323D8 v = lbl_804775F0;
            update_player_state__9TObjEneDDFv(arg0, &v, 0);
        }
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(arg0->f24);
        push_matrix();
        post_translate_matrix((u8 *)arg0 + 0x38);
        rotate_matrix_y(0, arg0->f60);
        idx = (s32)arg0->f354;
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 5) {
            idx = 4;
        }
        anim = arg0->bones[arg0->mots[idx].bone].anim;
        frame = arg0->frame;
        if (frame < TObjEneMorfos__data_805DF874) {
            frame = TObjEneMorfos__data_805DF874;
        } else if (frame > (anim->count - 1)) {
            frame = (f32)anim->count;
        }
        set_motion_packed_rotation();
        draw_model_motion((void *)arg0->f34, anim, frame);
        clear_motion_packed_rotation();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

s32 TObjEneMorfos::vfunc_83() { if (get_target_info() != 0) { this->init_target_offsets(); } }

void TObjEneMorfos::update_ground_probe() {
    u8 *arg0 = (u8 *)this;
    Stack_80332594 stack;
    u8 *temp_r3;
    if ((actor_frame_tick % 5) == 0) {
        VecCopy((Vec *)&stack.sp8, (const Vec *)&this->position);
        stack.spC += TObjEneMorfos__data_805DF870;
        temp_r3 = (u8 *)(csnVectorUnder((Vec *)&stack.sp8, (u32 *)&this->m_120, 0x4000));
        if (temp_r3 != NULL) {
            *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) *(s32 *)((s8 *)temp_r3 + 0);
            VecCopy((Vec *)(arg0 + 0x3C8), (const Vec *)(*(u8 **)((s8 *)temp_r3 + 4)));
        } else {
            VecCopy((Vec *)(arg0 + 0x3C8), (const Vec *)&this->position);
        }
    }
    if (*(s32 *)((s8 *)arg0 + 0x3C4) & 0x4000) {
        TObjEneRecon::set_active();
    }
}

u8 TObjEneMorfos::check_value_in_range(void *arg0, u16 arg1, u16 arg2, u16 arg3) {
    s32 r;
    s32 d;
    s32 c;
    s32 b;
    s32 a;
    a = arg1;
    b = arg2;
    if (a > b) {
        c = arg3;
        r = 0;
        d = a - c;
        if ((d >= 0 && b - c >= 0) || (d <= 0 && b - c <= 0)) {
            r = 1;
        }
        return r;
    } else {
        s32 r2;
        s32 d2;
        s32 c2;
        c2 = arg3;
        r2 = 0;
        d2 = a - c2;
        if ((d2 <= 0 && b - c2 >= 0) || (d2 >= 0 && b - c2 <= 0)) {
            r2 = 1;
        }
        return r2;
    }
}

void* TObjEneMorfosArm__sub_803326B4(void* p) { return (char*)p + 0x4a4; }
s32 TObjEneMorfosArm__sub_803326BC(void* p) { return *(s32*)((char*)p + 0x60); }

}
