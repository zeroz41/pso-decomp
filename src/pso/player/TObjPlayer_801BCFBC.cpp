#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_801BD314.h"
#include "pso/object/base/TObjMotion.h"

extern "C" {

s32 is_lobby_floor_15__15TFontSmallLobbyFv();
s32 test_flags_any(void *, s32);
s32 is_on_current_floor__10TObjPlayerFi(void *);
s32 run_action_state_phase__10TObjPlayerFisi(void *, s32, s32);

s32 obj_isState2_324__9TObjCharaFv();
extern const f32 TObjPlayer__data_805DC294;

void TObjPlayer::update_action_animation() {
    u8 *arg0 = (u8 *)this;
    if (obj_isState2_324__9TObjCharaFv() == 0) {
        ((TObjPlayer *)arg0)->update_position_from_target();
        return;
    }
    if (is_on_current_floor__10TObjPlayerFi(arg0) != 0) {
        ((TObjPlayer *)arg0)->sub_8011E204(4);
        if (((TObjCollidable *)arg0)->obj_testFlags30(0x800) != 0) {
            run_action_state_phase__10TObjPlayerFisi(arg0, 0xF, 0);
            if (test_flags_any((u8 *)&this->m_858, 1) != 0) {
                this->requested_action = ((TObjPlayer *)arg0)->get_action_animation();
            } else {
                ((TObjPlayer *)arg0)->restart_death_pose();
            }
            ((TObjPlayer *)(arg0 + 0x5FC))->set_pos_z(TObjPlayer__data_805DC294);
            ((TObjPlayer *)arg0)->revive_or_spawn_marker();
            return;
        }
        if ((is_lobby_floor_15__15TFontSmallLobbyFv() != 0) && (((TPlyPhotonChair *)arg0)->is_mounted() != 0)) {
            run_action_state_phase__10TObjPlayerFisi(arg0, 0x18, 0);
            return;
        }
        run_action_state_phase__10TObjPlayerFisi(arg0, 1, 0);
    }
}

}

struct B_801BD240 { u8 pad[8]; };

struct V_801BD240 : B_801BD240 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void m3(s32);
};

struct P_801BD240 { u8 pad0[0xE0]; s32 fE0; u8 pad1[0x380 - 0xE4]; V_801BD240 *f380; };

struct VBase_8_c75954 { char pad[0x8]; };

struct VObj_8_c75954 : VBase_8_c75954 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32, s16);
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
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual s32 m74();
};

typedef struct Player_801BD1B4 {
    u8 pad0[0x380];
    VObj_8_c75954 *anim;
} Player_801BD1B4;

struct VBase_801BD0C0 { char pad[0x8]; };

struct VObj_801BD0C0 : VBase_801BD0C0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4();
    virtual s32 m5(s32, s16);
};

typedef struct Anim_801BD0C0 {
    s16 id;
    u8 pad2[6];
    f32 speed;
    u32 flags;
} Anim_801BD0C0;

typedef struct Motion_801BD0C0 {
    u8 pad0[4];
    u32 frames;
} Motion_801BD0C0;

typedef struct Player_801BD0C0 {
    u8 pad0[0xB0];
    u32 fb0;
    u32 fb4;
    s16 anim;
    u8 padba[0xC0 - 0xBA];
    f32 frame;
    f32 end;
    f32 speed;
    u8 padcc[0xF4 - 0xCC];
    s16 fid;
    u8 padf6[2];
    Motion_801BD0C0 *motion;
    u8 padfc[0x380 - 0xFC];
    VObj_801BD0C0 *ctrl;
} Player_801BD0C0;

extern "C" {
u16 get_entity_id(void *);
void select_class_action_provider__10TObjPlayerFv(void *, s32);
extern s32 TObjPlayer__shared_model_buffer;
s32 get_handle_value__10TObjPlayerFv(void *);
Anim_801BD0C0 *get_anim_entry__10TObjMotionFi(void *, s32);
extern const f32 TObjPlayer__data_805DC278;

void TObjPlayer::apply_motion_entry() {
    Player_801BD0C0 *self = (Player_801BD0C0 *)this;
    Anim_801BD0C0 *a;
    ((TObjMotion *)self)->set_field_d8(self->ctrl->m5(((TObjPlayer *)self)->has_valid_handle(), get_handle_value__10TObjPlayerFv(self)));
    ((TObjMotion *)self)->set_action_motion(this->requested_action);
    a = get_anim_entry__10TObjMotionFi(self, this->requested_action);
    this->play_speed = a->speed;
    self->fid = a->id;
    self->end = self->motion->frames;
    this->motion_flags &= ~4;
    this->action_flags = a->flags;
    if (this->action_flags & 0x20000000) {
        ((TObjMotion *)self)->set_motion_interpolation_flag();
    }
    if (this->frame >= self->end) {
        this->frame = TObjPlayer__data_805DC278;
    }
}

void TObjPlayer::init_idle_animation() {
    Player_801BD1B4 *arg0 = (Player_801BD1B4 *)this;
    ((TObjPlayer *)arg0)->init_motion((TObjMotionAction *)arg0->anim->m5(((TObjPlayer *)arg0)->has_valid_handle(), get_handle_value__10TObjPlayerFv(arg0)), (BmlMotionEntry *)arg0->anim->m74(), get_idle_animation());
}

void TObjPlayer::sub_801BD240() {
    P_801BD240 *arg0 = (P_801BD240 *)this;
    s32 t = get_entity_id(arg0) * 0xC00;
    arg0->fE0 = TObjPlayer__shared_model_buffer + t;
    select_class_action_provider__10TObjPlayerFv(arg0, t);
    arg0->f380->m3(get_entity_id(arg0));
    ((TObjPlayer *)arg0)->init_idle_animation();
    ((TObjPlayer *)arg0)->update_input_and_draw();
}

}

extern "C" {

int TObjPlayer__sub_801C2114(void);

extern "C" {

void TObjPlayer::update_input_and_draw() {
    s32 ctl = (s32)this;
    if (is_current_area_item_enabled() == 0) {
        ((TObjPlayer *)ctl)->set_action_provider_variant((int) (TObjPlayer__sub_801C2114()));
    }
    ((TObjPlayer *)ctl)->init_idle_animation();
    ((TObjPlayer *)ctl)->draw();
    ((TObjPlayer *)ctl)->update_action_animation();
}

}

}

void TObjPlayer__sub_801BD314(void) {  }
