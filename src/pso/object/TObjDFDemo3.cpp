#include "types.h"
#include "pso/TObject.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjFish_800E2FFC.h"
#include "pso/misc/TCameraCtrl_800687BC.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_80052374.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/vector.h"
#include "pso/object/TObjDFDemo3.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss4Uro.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#pragma readonly_strings on

extern "C" {
void *spawn_particle_effect(void *pos, s32 id);
void *create_particle_emitter(void *pos, s32 id);
s32 play_sound_effect(s32, void *, s32, s32);
void run_task__11TObjDFDemo3Fv(u8 *arg0);
s32 clear_render_callback__8TObjFishFv(s32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 post_translate_matrix(void *);
void render__11TObjDFDemo3Fv(u8 *arg0);
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
void set_scripted_camera_pose(void *, void *, void *);
s32 __ct__13TUnk_804B9870FP7TObject(void *, void *);
}

struct Vec_8004F030 { f32 x, y, z; };

struct IVec_8004F030 { s32 x, y, z; };

struct S_EF94 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x90 - 0x1c];
    void *ptr[1];
    u8 pad94[0xb8 - 0x94];
    void *fb8;
};

extern "C" {
s32 is_ending_or_split_screen__14TBoss4DarkFalzFv();
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
s32 vec3_add_to(void *, void *);
f32 vector_length(void *);
s32 normalize_vector(void *);

void render_shadows__7TObjectFv();
void vfunc_6__13TUnk_804B9870FPsl();
void apply_object_set_data__13TUnk_804B9870FPv();
void reset_motion_fields__13TUnk_804B9870Fv();
void get_center__13TUnk_804B9870Fv();
void update_object_view_visibility__13TUnk_804B9870Fff();
void classify_actor_view_detail__13TUnk_804B9870Ffff();
void get_name__13TUnk_804B9870Fv();
S_EF94 *__dt__11TObjDFDemo3Fv(S_EF94 *o, s16 flag);
u8 *TObjDFDemo3__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

const char *TObjDFDemo3__name = "TObjDFDemo3";
__declspec(section ".rodata") IVec_8004F030 lbl_804373A4 = {0, 0, 0};
void *lbl_804856C0[8] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804856E0[3] = {
    (void *)0x60000, (void *)0x0, (void *)0x3f800000,
};
void *__vt__11TObjDFDemo3[13] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__11TObjDFDemo3Fv, (void *)&run_task__11TObjDFDemo3Fv,
    (void *)&render__11TObjDFDemo3Fv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804B9870Fv, (void *)&get_center__13TUnk_804B9870Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__13TUnk_804B9870Fv,
};

void TObjDFDemo3::render() {
    f32 a = 1.0f;
    s32 t = this->m_b0;
    if (t < 5) {
        a = (f32)t / 5.0f;
    } else if (t > 0x86) {
        a = (f32)(0x8B - t) / 5.0f;
    }
    if (a <= 0.0f) {
        return;
    }
    if (a < 1.0f) {
        TObjPlayer__sub_80052390(a);
    }
    push_matrix();
    TObjPlayer::set_global_flag();
    post_translate_matrix((u8 *)&this->m_a0);
    rotate_matrix_y(0, this->m_ac);
    TObjFish::set_global_param(this->m_98);
    ((TObjFish *)(this->m_b8))->set_draw_callback_list();
    set_chunk_render_flags(1);
    draw_model_motion((void *)(*(s32 *)&this->m_94), (void *)(*(s32 *)&this->m_9c), *(f32 *)&this->_padB4);
    clear_render_callback__8TObjFishFv(this->m_b8);
    set_chunk_render_flags(2);
    draw_model_motion((void *)(*(s32 *)&this->m_94), (void *)(*(s32 *)&this->m_9c), *(f32 *)&this->_padB4);
    clear_chunk_render_flags();
    TObjPlayer::clear_global_state();
    pop_matrix();
    if (a < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
}

#pragma push
#pragma opt_common_subs off
void TObjDFDemo3::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 cur;
    f32 nxt;
    s32 temp_r0;
    s32 temp_r0_2;
    u32 temp_r3;
    if ((s32) this->m_b0 >= 0x5A) {
        if ((u32) this->m_90 != 0U) {
            TBoss4Type2::request_destroy(this->m_90);
            this->m_90 = 0U;
        }
    } else {
        temp_r3 = this->m_90;
        if (temp_r3 == 0U) {
            this->m_90 = (u32)create_particle_emitter(&this->m_bc, 0x1BD);
            if ((u32) this->m_90 != 0U) {
                ((TBoss4Type2 *)((void *) this->m_90))->set_flags(0x40);
            }
        } else if (temp_r3 != 0U) {
            ((TNowLoading *)temp_r3)->copy_pos((u8 *)&this->m_bc);
        }
    }
    if ((s32) this->m_b0 == 0x86) {
        temp_r3 = (u32)spawn_particle_effect(&this->m_a0, 0x9B);
        if (temp_r3 != 0U) {
            ((TBoss4Type2 *)temp_r3)->set_flags(0x40);
        }
    }
    temp_r0 = this->m_b0;
    if ((temp_r0 == 0x28) || (temp_r0 == 0x3C)) {
        play_sound_effect(0x4003D03A, (u8 *)&this->m_a0, 0, 1);
    }
    if ((*(f32 *)&this->_padB4 += 1.0f) > 119.0f) {
        *(f32 *)&this->_padB4 = 119.0f;
    }
    temp_r0_2 = this->m_b0 + 1;
    this->m_b0 = temp_r0_2;
    if (temp_r0_2 >= 0x8C) {
        queue_destruction__7TObjectFv(arg0);
    }
}
#pragma pop

S_EF94 *__dt__11TObjDFDemo3Fv(S_EF94 *o, s16 flag) {
    s32 i;
    if (o != 0) {
        o->vt = __vt__11TObjDFDemo3;
        if (o->fb8 != 0) {
            TObjFish::init_state_1(o->fb8);
            o->fb8 = 0;
        }
        for (i = 0; i < 1; i++) {
            if (o->ptr[i] != 0) {
                TBoss4Type2::request_destroy((u32)o->ptr[i]);
                o->ptr[i] = 0;
            }
        }
        if (is_ending_or_split_screen__14TBoss4DarkFalzFv() == 0) {
            restore_player_cameras();
        }
        __dt__13TUnk_804B9870Fv(o, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(o);
        }
    }
    return o;
}

#define lbl_804856C0 ((u8 *)lbl_804856C0)
u8 *TObjDFDemo3__ct(u8 *arg0, s32 parent, s32 arg2, s32 arg3) {
    s32 cnt;
    __ct__13TUnk_804B9870FP7TObject(arg0, (void *)parent);
    *(void **)((s8 *)arg0 + 0x18) = (void *)__vt__11TObjDFDemo3;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjDFDemo3__name;
    VecCopy((Vec *)(arg0 + 0xA0), (const Vec *)arg2);
    *(f32 *)((s8 *)arg0 + 0xA4) = 0.0f;
    {
        Vec_8004F030 v = *(Vec_8004F030 *)(arg0 + 0xA0);
        v.y = 0.0f;
        if (!(vector_length(&v) <= 0.01f)) {
            normalize_vector(&v);
            v.x *= -50.0f;
            v.z *= -50.0f;
            vec3_add_to(arg0 + 0xA0, &v);
        }
    }
    *(s32 *)((s8 *)arg0 + 0xAC) = arg3;
    cnt = TBoss4Uro::get_instance_count();
    *(s32 *)((s8 *)arg0 + 0x94) = get_bml_model(cnt, 0x12);
    *(s32 *)((s8 *)arg0 + 0x98) = TObjFish__sub_8001EDB0(cnt, 0x12);
    *(s32 *)((s8 *)arg0 + 0x9C) = get_bml_motion(cnt, 0x45);
    *(f32 *)((s8 *)arg0 + 0xB4) = -1.0f;
    *(s32 *)((s8 *)arg0 + 0x90) = 0;
    activate_camera_mode(5);
    {
        IVec_8004F030 c = lbl_804373A4;
        c.y = *(s32 *)((s8 *)arg0 + 0xAC);
        set_scripted_camera_pose(arg0 + 0xA0, arg0 + 0xA0, &c);
    }
    ((TCameraCtrl *)lbl_804856E0)->cache_target_and_forward(0x1555);
    *(s32 *)((s8 *)arg0 + 0xB8) = TObjFish__sub_800E3124(lbl_804856C0, (s32)(arg0 + 0xBC));
    *(s32 *)((s8 *)arg0 + 0xB0) = 0;
    return arg0;
}
#undef lbl_804856C0

void *TObjDFDemo3::create(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0xC8);
    if (o != NULL) {
        o = ((void *(*)(void *, void *, void *, void *))TObjDFDemo3__ct)(o, arg0, arg1, arg2);
    }
    return o;
}

}
