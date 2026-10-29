#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/misc/TCameraCtrl_800687BC.h"
#include "pso/misc/TLobby_802268F4.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_8004FA98.h"
#include "pso/player/TObjPlayer_80052374.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjDFDemo5.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjMotion.h"
#include "pso/TParticleCtrl.h"

extern "C" {
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 clear_render_callback__8TObjFishFv(s32);
void TObjPlayer::release_subobjects() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0xE4) >= 0xB4) {
        TObjPlayer__sub_80052390(0.99f);
        push_matrix();
        TObjPlayer::set_global_flag();
        post_translate_matrix((u8 *)&this->override_blend_speed);
        rotate_matrix_y(0, (*(s32 *)&this->joint_matrices));
        TObjFish::set_global_param(*(s32 *)&this->blend_speed);
        ((TObjFish *)(this->m_108))->set_draw_callback_list();
        draw_model_motion((void *)(*(s32 *)&this->play_speed), (void *)(*(s32 *)&this->override_speed), *(f32 *)&this->blend.motion[1]);
        clear_render_callback__8TObjFishFv(this->m_108);
        TObjPlayer::clear_global_state();
        pop_matrix();
        TObjPlayer::sync_player_globals();
    }
}

int TObjPlayer::draw_fading_motion() {
    u8 *arg0 = (u8 *)this;
    f32 alpha;
    f32 frac;
    s32 t;
    alpha = 1.0f;
    t = *(s32 *)((s8 *)arg0 + 0xE4);
    if (t >= 0xF0) {
        return;
    }
    if (t > 0xA0) {
        alpha = (f32)(0xF0 - t) / 80.0f;
    }
    if (alpha < 1.0f) {
        TObjPlayer__sub_80052390(alpha);
    }
    push_matrix();
    TObjPlayer::set_global_flag();
    post_translate_matrix((u8 *)&this->override_blend_speed);
    rotate_matrix_y(0, (*(s32 *)&this->joint_matrices));
    TObjFish::set_global_param(this->body_count);
    (*(TObjFish **)&this->blend.frame[0])->set_draw_callback_list();
    draw_model_motion((void *)(*(s32 *)&this->bodies), (void *)(*(s32 *)&this->extra), *(f32 *)&this->blend.motion[1]);
    clear_render_callback__8TObjFishFv(*(s32 *)&this->blend.frame[0]);
    frac = (s32)*(f32 *)&this->blend.motion[1] % 30;
    TObjFish::set_global_param(*(s32 *)&this->action_flags);
    draw_model_motion((void *)(*(s32 *)&this->motion_flags), (void *)(*(s32 *)&this->requested_action), frac);
    TObjFish::set_global_param((*(s32 *)&this->frame));
    draw_model_motion((void *)(*(s32 *)&this->previous_action), (void *)(*(s32 *)&this->frame_count), frac);
    TObjPlayer::clear_global_state();
    pop_matrix();
    if (alpha < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
}

void TObjPlayer::update_both() { draw_fading_motion(); release_subobjects(); }

}

typedef struct Obj_8004FD50 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x90 - 0x1C];
    void *items[5];
    u8 pada4[0xEC - 0xA4];
    void *fec;
    u8 padf0[0x108 - 0xF0];
    void *f108;
} Obj_8004FD50;

extern "C" {
s32 is_ending_or_split_screen__14TBoss4DarkFalzFv();
void __dl__7TObjectFPv(void *);
extern u8 lbl_804857F4[];
Obj_8004FD50 *__dt__11TObjDFDemo5Fv(Obj_8004FD50 *arg0, s16 arg1);
#pragma push
#pragma opt_common_subs off
#pragma readonly_strings on
void TObjDFDemo5::run_task() {
    f32 temp_f1;
    s32 temp_r0;
    this->update_particle_emitters();
    if ((s32) this->m_e4 == 0x8C) {
        play_cue_stream_file((s32) "dfdeath.adx");
        start_pad_rumble_all(0xC0, 0xF);
    }
    { f32 k = 0.5f; temp_f1 = *(f32 *)((s8 *)this + 0xE8) + k; }
    *(f32 *)((s8 *)this + 0xE8) = temp_f1;
    if (temp_f1 > 149.0f) {
        *(f32 *)((s8 *)this + 0xE8) = (f32) 149.0f;
    }
    temp_r0 = this->m_e4 + 1;
    this->m_e4 = temp_r0;
    if (temp_r0 >= 0x12C) {
        queue_destruction__7TObjectFv(this);
    }
}
#pragma pop

Obj_8004FD50 *__dt__11TObjDFDemo5Fv(Obj_8004FD50 *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        arg0->vt = lbl_804857F4;
        if (arg0->fec != NULL) {
            TObjFish::init_state_1(arg0->fec);
            arg0->fec = NULL;
        }
        if (arg0->f108 != NULL) {
            TObjFish::init_state_1(arg0->f108);
            arg0->f108 = NULL;
        }
        for (i = 0; i < 5; i++) {
            if (arg0->items[i] != NULL) {
                TParticleCtrl::release(arg0->items[i]);
                arg0->items[i] = NULL;
            }
        }
        if (is_ending_or_split_screen__14TBoss4DarkFalzFv() == 0) {
            restore_player_cameras();
        }
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

 extern const f32 lbl_805D8A1C = -0.5f; }
