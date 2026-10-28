#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/TBoss6Mine.h"
#include "pso/system/vector.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#include <stddef.h>
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TNowLoading.h"
extern "C" TObjEnemy *__ct__9TObjEnemyFP7TObject(void *, void *);
struct Stack_803242C0 {
    f32 sp8;
    f32 spC;
    u8 pad_10[0x4];
    f32 sp14;
    f32 sp18;
    f32 sp1C;
};

struct VBase_18_b27ba1 { char pad[0x18]; };

struct VObj_18_b27ba1 : VBase_18_b27ba1 {
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
    virtual s32 m21(void *, void *, s32, s32, s32);
};

struct Vec_803240F8 { f32 x, y, z; };

struct Hit_803240F8 { s32 a; s32 b; s32 c; f32 d; };

struct Vec_80324440 { f32 x, y, z; };

struct Vec_80323FA4 { f32 x, y, z; };

struct Tmp_80324A00 { s32 a; u8 pad4[2]; s16 b; u8 pad8[8]; };

extern "C" {
f32 vector_length(void *);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
s32 render_shadows__9TObjEnemyFv();
s32 VecCopy__FP3VecPC3Vec(s32, s32);
s32 project_actor_to_ground(void *, void *, int);
f32 vec3_add_to(void *, void *);
f32 subtract_vector(void *, void *);
f32 normalize_vector(void *);
int get_player_data__10TObjPlayerFi(int a0);
s32 play_sound_effect(int, void *, int, int);
f64 atan2_float(f32, f32);
s32 approach_angle_limited(s32, s32, s32);
f64 TBoss5GryphonLightningWing__sub_80324CEC(f32);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
f32 *dispatch_shared_handler_a__6TLobbyFl(s32);
s32 exchange_object_state__9TObjEnemyFls(void *, void *, int);
void *create_particle_emitter(void *pos, s32 id);
s32 init_collision_body_parts(void *, void *, int);
static u32 TBoss6Mine__collision_body_template[11] = {
    0, 0, 0, 0x41700000, 0, 0, 0x801B, 0, 0, 0, 0,
};
extern s32 __vt__10TBoss6Mine[];
extern s32 lbl_805D4178;
void TBoss6PlotFalz__sub_802AC008(f32 farg0, f32 farg1);
void TBoss6Type1__sub_802B5DD4(void *);
int post_translate_matrix(void*);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
int rotate_matrix_x(void*, void*);
s32 TObjControl__ct(s32, s32);
void free_collision_body_parts(void *);
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
int rotate_matrix_y(void*, void*);
int push_matrix(void*);
void __dl__7TObjectFPv(void *);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
s32 __nw__7TObjectFUl(s32);

void TBoss6Mine::render_shadows() {
    u8 *arg0 = (u8 *)this;
    if (*(f32 *)((s8 *)arg0 + 0x3C) >= (0.0f)) {
        render_shadows__9TObjEnemyFv();
    }
}

void TBoss6Mine::vfunc_63() {
    if (this->state != 7) {
        this->state = 7;
    }
}

void TBoss6Mine::vfunc_62() { this->actorFlags = (this->actorFlags & 0xfffffdff); this->fade_amount = 1.0f; }

void TBoss6Mine::copy_pos() {
    s32 arg0 = (s32)this;
    VecCopy__FP3VecPC3Vec(arg0 + 0x2FC, arg0 + 0x38);
}

void TBoss6Mine::draw() {
    s32 temp_r31;
    s32 bml_motion;
    s32 bml_model;

    TObjPlayer::set_global_flag();
    temp_r31 = TObjFish__sub_8001EDB0(this->m_374, 2);
    bml_model = get_bml_model(this->m_374, 2);
    bml_motion = get_bml_motion(this->m_374, 0);
    TObjFish::set_global_param(temp_r31);
    TBoss6PlotFalz__sub_802AC008(this->fade_amount, 0.0f);
    draw_model_motion((void *)bml_model, (void *)bml_motion, this->anim_frame);
    TBoss6PlotFalz::update_camera_target();
    TObjPlayer::clear_global_state();
}

void TBoss6Mine::render() { push_matrix(this); post_translate_matrix((char*)this + 0x38); rotate_matrix_y((void*)0, *(void* *)&this->m_390); rotate_matrix_x((void*)0, *(void* *)&this->m_394); rotate_matrix_y((void*)0, *(void* *)&this->m_398); draw(); pop_matrix(); }

void TBoss6Mine::update_facing_angles() {
    u8 *arg0 = (u8 *)this;
    Vec_80323FA4 v;
    s32 a;
    s32 b;
    switch (this->state) {
    case 5:
    case 6:
        VecCopy__FP3VecPC3Vec((s32) &v, (s32)(arg0 + 0x38));
        subtract_vector(&v, (u8 *)&this->prev_position);
        if (vector_length(&v) <= 0.00001f) {
            a = 0;
            b = 0;
        } else {
            normalize_vector(&v);
            a = (10430.38043493439) * atan2_float(-v.x, -v.z);
            b = (10430.38043493439) * TBoss5GryphonLightningWing__sub_80324CEC(v.y);
            if (b < -0x2000) {
                b = -0x2000;
            } else if (b > 0x2000) {
                b = 0x2000;
            }
        }
        this->m_390 = approach_angle_limited(this->m_390, a, 0x1111);
        this->m_394 = approach_angle_limited(this->m_394, b, 0x444);
        this->m_398 += 0x888;
        break;
    }
}

s32 TBoss6Mine::is_far_from_origin() {
    s32 arg0 = (s32)this;
    return vector_length((void *)(arg0 + 0x38)) > 500.0f;
}

void TBoss6Mine::explode_damage_players() {
    s32 n;
    s32 i;
    u8 *pl;
    u8 *arg0 = (u8 *)this;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        pl = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (((TBoss6PlotFalz *)pl)->is_active() != 0) {
            Vec_803240F8 v = *(Vec_803240F8 *) (arg0 + 0x38);
            subtract_vector(&v, pl + 0x38);
            v.y = 0.0f;
            if (!(vector_length(&v) > 22.5f)) {
                Hit_803240F8 h;
                s32 r = TBoss6PlotFalz::rand_vary_count(this->m_384, 0.1f);
                h.a = 1;
                h.c = 1;
                h.d = r;
                h.b = *(s32 *) &h.d;
                ((VObj_18_b27ba1 *) pl)->m21(arg0, &h, 0, -1, -1);
            }
        }
    }
    play_sound_effect(0x4003BA1E, (u8 *)&this->position, 0, 0);
}

void TBoss6Mine::state_7() {
    spawn_particle_effect_with_flags(&this->position, 0xFC, 0x40);
    queue_destruction();
}

void TBoss6Mine::state_6() {
    explode_damage_players();
    spawn_particle_effect_with_flags(&this->position, 0xFB, 0x40);
    spawn_particle_effect_with_flags(&this->position, 0xFC, 0x40);
    TBoss6PlotFalz::apply_radial_effect_to_players(&this->position, (s16)0xC0, (s16)0xF, 100.0f);
    queue_destruction();
}

#pragma push
#pragma opt_common_subs off
void TBoss6Mine::state_5() {
    typedef char sp8_offset[(offsetof(Stack_803242C0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_803242C0, spC) == 0x4) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_803242C0, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_803242C0, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_803242C0, sp1C) == 0x14) ? 1 : -1];
    Stack_803242C0 stack;
    f32 ground_y;
    VecCopy((Vec *)&stack.sp14, &this->target_pos);
    subtract_vector(&stack.sp14, &this->position);
    if (vector_length(&stack.sp14) <= 8.333333f) {
        this->state_frames = 0;
        this->state = 6;
        return;
    }
    normalize_vector(&stack.sp14);
    stack.sp14 *= 8.333333f;
    stack.sp18 *= 8.333333f;
    stack.sp1C *= 8.333333f;
    vec3_add_to(&this->position, &stack.sp14);
    VecCopy((Vec *)&stack.sp8, &this->position);
    ground_y = stack.spC - 10.0f;
    stack.spC = ground_y;
    if ((project_actor_to_ground(this, &stack.sp8, 0) != 0) && (ground_y < stack.spC)) {
        stack.spC += 10.0f;
        VecCopy(&this->position, (Vec *)&stack.sp8);
        this->state_frames = 0;
        this->state = 6;
    }
}
#pragma pop

void TBoss6Mine::state_4() {
    s32 frames = this->state_frames + 1;
    this->state_frames = frames;
    if (frames > (s32)this->arm_delay) {
        this->state_frames = 0;
        this->state = 5;
        play_sound_effect(0x4003B51D, &this->position, 0, 0);
    }
}

void TBoss6Mine::state_3() {
    Vec_80324440 v;
    f32 len;
    f32 remaining;
    f32 radius;
    remaining = (f32)((s32)this->spread_frames - this->state_frames + 1);
    VecCopy((Vec *)&v, &this->position);
    v.y = 0.0f;
    len = vector_length(&v);
    if (len > 0.00001f) {
        normalize_vector(&v);
    }
    radius = len + (120.0f - len) / remaining;
    this->position.x = radius * v.x;
    this->position.z = radius * v.z;
    this->anim_frame += 0.8333334f;
    if (this->anim_frame >= 9.0f) {
        this->anim_frame = 9.0f;
    }
    if (++this->state_frames > (s32)this->spread_frames) {
        this->state_frames = 0;
        this->state = 4;
    }
}

void TBoss6Mine::state_2() {
    this->anim_frame += 0.33333334f;
    if (this->anim_frame >= 10.0f) {
        this->anim_frame -= 10.0f;
    }
    this->position.y += 0.6944444f;
    if (this->position.y >= 75.0f) {
        this->position.y = 75.0f;
        this->state_frames = 0;
        this->state = 3;
    }
    play_persistent_sound(0x4003B21C, (s32)this, (u32)&this->position, 0, 0);
}

void TBoss6Mine::state_1() {
    s32 frames = this->state_frames + 1;
    this->state_frames = frames;
    if (frames > (s32)this->rise_delay) {
        this->state_frames = 0;
        this->state = 2;
    }
}

#pragma push
#pragma fp_contract on
void TBoss6Mine::state_0() {
    f32 step;
    f32 height;
    s32 frames;
    s32 left;
    frames = this->state_frames;
    step = this->travel_distance / 30.0f;
    if (frames > 0xF) {
        left = 0x1E - frames;
        if (left > 0) {
            height = this->start_pos.y;
            this->start_pos.y = (f32)(height + ((-50.0f - height) / (f32)left));
        }
    }
    this->position.x = (f32)((step * sin_table_lookup(this->heading)) + this->position.x);
    this->position.z = (f32)((step * cos_table_lookup(this->heading)) + this->position.z);
    this->position.y = (f32)((-100.0f * sin_table_lookup((s32)(this->state_frames << 0xF) / 30)) + this->start_pos.y);
    frames = this->state_frames + 1;
    this->state_frames = frames;
    if (frames > 0x1E) {
        this->state_frames = 0;
        this->state = 1;
    }
}
#pragma pop

int query_teammate_state__9TObjEneDDFv(void);
void submit_cursor_candidate(void *obj, s32 id);
void add_radar_scaled_marker(void *pos, u32 color, s32 a2, s32 a3, f32 scale);

void TBoss6Mine::run_task() {
    u32 color;
    if (TObjPlayer::check_demo_mode() != 0) {
        return;
    }
    if (TBoss6PlotFalz__sub_802ABADC() == 0) {
        this->m_378 = 0;
        queue_destruction();
        return;
    }
    if (query_teammate_state__9TObjEneDDFv() != 0) {
        return;
    }
    VecCopy(&this->prev_position, &this->position);
    static void (TBoss6Mine::*const handlers[8])() = {
        &TBoss6Mine::state_0, &TBoss6Mine::state_1, &TBoss6Mine::state_2, &TBoss6Mine::state_3,
        &TBoss6Mine::state_4, &TBoss6Mine::state_5, &TBoss6Mine::state_6, &TBoss6Mine::state_7,
    };
    void (TBoss6Mine::*handler)() = handlers[this->state];
    if (handler != 0) {
        (this->*handler)();
    }
    copy_pos();
    if (this->state == 2) {
        ((TObjPlayer *)this)->update_collisions();
        submit_cursor_candidate(this, -1);
    }
    color = 0xFF7F5126;
    if (this->state == 2) {
        color = 0xFFFFA24C;
    }
    add_radar_scaled_marker(&this->position, color, 1, 1, 1.0f);
    update_facing_angles();
    this->fade_amount += -0.06666667f;
    if (this->fade_amount < 0.0f) {
        this->fade_amount = 0.0f;
    }
    if (this->emitter != 0) {
        ((TNowLoading *)this->emitter)->copy_pos(&this->position);
    }
    if (is_far_from_origin() != 0) {
        queue_destruction();
    }
}

void *__dt__10TBoss6MineFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__10TBoss6Mine;
        if (*(void **)((s8 *)arg0 + 0x3CC) != NULL) { TBoss4Type2::request_destroy((u32)(*(void **)((s8 *)arg0 + 0x3CC))); ((TBoss6Mine *)arg0)->emitter = 0; }
        free_collision_body_parts(arg0);
        if (*(void **)((s8 *)arg0 + 0x378) != NULL) { TBoss6Type1__sub_802B5DD4(*(void **)((s8 *)arg0 + 0x378)); }
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 tl_04;

#pragma push
#pragma fp_contract on
#define VecCopyP ((u8 *(*)(void *, void *))VecCopy__FP3VecPC3Vec)
#define THIS self
s32 TBoss6Mine__ct(s32 arg0, s32 parent, s32 arg2) {
    u8 *self;
    Tmp_80324A00 tmp;
    f32 f;
    self = (u8 *)arg0;
    __ct__9TObjEnemyFP7TObject((TObjEnemy *)arg0, (void*)parent);
    *(s32 **)((s8 *)THIS + 0x18) = __vt__10TBoss6Mine;
    *(s32 *)((s8 *)THIS + 0) = lbl_805D4178;
    ((TBoss3Volopt *)THIS)->m_378 = *(s32 *)((s8 *)arg2 + 0x40);
    VecCopyP(THIS + 0x38, (u8 *)arg2 + 0x44);
    VecCopyP(THIS + 0x3BC, (u8 *)arg2 + 0x50);
    ((TBoss3Volopt *)THIS)->state = *(s32 *)((s8 *)arg2 + 0x5C);
    ((TBoss3Volopt *)THIS)->m_388 = *(s32 *)((s8 *)arg2 + 0x60);
    ((TObjChara *)THIS)->add_flags_2e4(8);
    ((TBoss3Volopt *)THIS)->apply_set_data((void *)arg2);
    if (exchange_object_state__9TObjEnemyFls(THIS, &tmp, 1) != 0) {
        tmp.a = 0;
        tmp.b = 0;
        exchange_object_state__9TObjEnemyFls(THIS, &tmp, 0);
    }
    ((TBoss3Volopt *)THIS)->next_action = TObjFish::get_fish_count();
    ((TBoss3Volopt *)THIS)->texlist = 0;
    *(s32 *)((s8 *)THIS + 0x34) = 0;
    VecCopyP(THIS + 0x44, VecCopyP(THIS + 0x50, VecCopyP(THIS + 0x74, THIS + 0x38)));
    init_collision_body_parts(THIS, TBoss6Mine__collision_body_template, 1);
    VecCopyP(THIS + 0x2FC, THIS + 0x38);
    ((TBoss3Volopt *)THIS)->m_310 = 0.0f;
    *(f32 *)((s8 *)THIS + 0x30C) = 0.0f;
    *(f32 *)((s8 *)THIS + 0x308) = 0.0f;
    *(s32 *)((s8 *)THIS + 0x2A8) = 0;
    ((TObjEnemy *)THIS)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(0x2D)), (u8 *)(TLobby::dispatch_shared_handler_b(0x2D)), (u8 *)(TLobby::register_object(0x2D)));
    ((TBoss3Volopt *)THIS)->referenceHp = ((TBoss3Volopt *)THIS)->hp;
    ((TBoss3Volopt *)THIS)->reset_photon_effect();
    ((TObjEnemy *)THIS)->set_param(0);
    ((TBoss6Mine *)THIS)->rise_delay = (s32)(136.0f * TBoss6Mine::next_random_float((s32 *)(THIS + 0x388)) + 7.0f);
    *(s32 *)((s8 *)THIS + 0x3A4) = 0x96 - ((TBoss6Mine *)THIS)->rise_delay;
    ((TBoss6Mine *)THIS)->arm_delay = (s32)(57.0f * TBoss6Mine::next_random_float((s32 *)(THIS + 0x388)) + 3.0f);
    *(f32 *)((s8 *)THIS + 0x3AC) = 80.0f * TBoss6Mine::next_random_float((s32 *)(THIS + 0x388)) + 120.0f;
    f = *dispatch_shared_handler_a__6TLobbyFl(0x2D);
    ((TBoss3Volopt *)THIS)->m_384 = f;
    if (0.0f == f) {
        ((TBoss3Volopt *)THIS)->m_384 = 0x14;
    }
    ((TBoss6Mine *)THIS)->fade_amount = 0.0f;
    VecCopyP(THIS + 0x3B0, THIS + 0x38);
    *(f32 *)((s8 *)THIS + 0x39C) = (1.0f);
    ((TBoss6Mine *)THIS)->m_390 = 0;
    *(s32 *)((s8 *)THIS + 0x394) = 0;
    ((TBoss6Mine *)THIS)->m_398 = 0;
    *(s32 *)((s8 *)THIS + 0x38C) = 0;
    ((TBoss3Volopt *)THIS)->m_380 = 0;
    *(u32 *)((s8 *)THIS + 0x3CC) = (u32)create_particle_emitter(THIS + 0x38, 0x146);
    if (*(u32 *)((s8 *)THIS + 0x3CC) != 0) {
        ((TBoss4Type2 *)(*(u32 *)((s8 *)THIS + 0x3CC)))->set_flags(0x40);
    }
    return arg0;
}
#pragma pop

s32 TBoss6Mine::create(s32 arg0) {
    s32 var_r31;
    s32 var_r4;

    var_r31 = __nw__7TObjectFUl(0x3D0);
    if (var_r31 != 0) {
        var_r4 = __nw__7TObjectFUl(0x20);
        if (var_r4 != 0) {
            var_r4 = TObjControl__ct(var_r4, tl_04);
        }
        var_r31 = TBoss6Mine__ct(var_r31, var_r4, arg0);
    }
    return var_r31;
}

}
