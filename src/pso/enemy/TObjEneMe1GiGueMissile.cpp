#include "types.h"
#include "pso/enemy/TObjEneMe1GiGueMissile.h"
#include "pso/enemy/TObjEneMe1GiGue.h"

#include "pso/TParticleCtrl.h"
#include "pso/misc/TNeedleShoot.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_802CE428___vt__22TObjEneMe1GiGueMissile {
    s32 value;
    u8 remaining[0x24];
};

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
s32 get_bml_motion(void *, int);
s32 get_bml_model(void *, int);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 pop_matrix();
f32 post_translate_matrix(void *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern int TObjEneMe1GiGue_barrier_count;
u16 get_entity_id(void *);
s32 play_sound_effect(s32, u32, s16, s32);
u8 * TNeedleShoot__ct(void *, s32, void *, void *);
extern s32 __vt__22TObjEneMe1GiGueMissile[];
extern s32 lbl_805D3F20;
extern const f32 lbl_805DE6DC;
u8 *TObjEneMe1GiGueMissile__ct(u8 *arg0, s32 arg1, u8 *arg2, u8 *arg3, f32 farg0, f32 farg1);
void *find_entity_by_id(u16 id);
s32 TObjPlayer__sub_802A445C(void *, int);
extern const f32 lbl_805DE6E0;
void TObjEneMe1GiGue__sub_802CE4E8(void);
void TObjEneMe1GiGue__sub_802CE4EC(void);
u32 __nw__7TObjectFUl(s32);

struct Hit_802CE088 { s32 kind; f32 power; };
struct VBase_802CE088 { u8 pad[0x18]; };
struct VEnt_802CE088 : VBase_802CE088 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual f32 m21(void *src, Hit_802CE088 *hit, s32 a, s32 b, s32 c);
};
void *get_player_by_client_id(s32 i);
f32 horizontal_distance_squared(void *, void *);
void obj_setFlags30(void *, int);
void create_fire_explosion_effect(void *, f32, void *, int, void *);
extern void *tl_07;
extern const f32 lbl_805DE6D0;
extern const f32 lbl_805DE6D4;
extern const f32 lbl_805DE6D8;

#pragma push
#pragma opt_common_subs off
void TObjEneMe1GiGueMissile::explode(void *pos) {
    void *fx;
    VEnt_802CE088 *p;
    s32 i;
    fx = (void *)__nw__7TObjectFUl(0x64);
    if (fx != NULL) {
        create_fire_explosion_effect(fx, lbl_805DE6D0, pos, 0, tl_07);
    }
    for (i = 0; i < 4; i++) {
        p = (VEnt_802CE088 *)get_player_by_client_id(i);
        if (p != NULL && horizontal_distance_squared((u8 *)p + 0x38, pos) <= lbl_805DE6D4) {
            Hit_802CE088 h;
            h.kind = 0;
            h.power = this->m_c0;
            {
                Hit_802CE088 h1 = h;
                if (p->m21(*(void * *)&this->m_1c, &h1, 0, -1, -1) > lbl_805DE6D8) {
                    obj_setFlags30(p, 0x600);
                }
            }
            if (TOKeyMachine01::get_global_state() == 0x23) {
                play_sound_effect(0x4003A312, (u32)((u8 *)p + 0x38), 0, 0);
            } else {
                play_sound_effect(0x3A81F, (u32)((u8 *)p + 0x38), 0, 0);
            }
        }
    }
}
#pragma pop

int TObjEneMe1GiGueMissile::vfunc_6() { this->explode((char*)this + 0x6c); queue_destruction__7TObjectFv(this); }

void TObjEneMe1GiGueMissile::vfunc_9(void *a1) { this->explode((char*)a1 + 0x38); queue_destruction__7TObjectFv(this); }

void TObjEneMe1GiGueMissile::create(s32 arg0, s32 from, s32 arg2, f32 farg0, f32 farg1) {
    void *temp_r3;
    temp_r3 = (void *) __nw__7TObjectFUl(0xC4);
    if ((u32) temp_r3 != 0U) {
        TObjEneMe1GiGueMissile__ct((u8 *)temp_r3, (s32)arg0, (u8 *)from, (u8 *)arg2, farg0, farg1);
    }
}

}
TObjEneMe1GiGueMissile::~TObjEneMe1GiGueMissile() {

}


void TObjEneMe1GiGueMissile::render() {
    u8 *arg0 = (u8 *)this;
  s32 bml_motion;
  if (((void *) (*(u8 * *)&TObjEneMe1GiGue_barrier_count)) == 0)
  {
    queue_destruction__7TObjectFv(((void *) arg0));
    return;
  }
  push_matrix();
  TParticleCtrl::begin_effect_render();
  post_translate_matrix((u8 *)&this->m_6c);
  bml_motion = this->m_a4;
  rotate_matrix_y(0, bml_motion);
  rotate_matrix_x(0, this->m_a0);
  TObjFish::set_global_param((s32)((void *) (*((s32 *) (((s8 *) (*((u8 **) (((s8 *) (*(u8 * *)&TObjEneMe1GiGue_barrier_count)) + 0x42C)))) + 0x1C)))));
  TObjPlayer::set_global_flag();
  bml_motion = get_bml_motion((void *) (*(u8 * *)&TObjEneMe1GiGue_barrier_count), 5);
  draw_model_motion((void *) get_bml_model((void *) (*(u8 * *)&TObjEneMe1GiGue_barrier_count), 1), (void *)bml_motion, (f32) (*((f32 *) (((s8 *) arg0) + 0xBC))));
  TObjPlayer::clear_global_state();
  TParticleCtrl::end_effect_render();
  pop_matrix();
}

typedef char RecoveredGlobal_802CE428___vt__22TObjEneMe1GiGueMissile_size[sizeof(RecoveredGlobal_802CE428___vt__22TObjEneMe1GiGueMissile) == 0x28 ? 1 : -1];

#pragma push
#pragma opt_common_subs off
void TObjEneMe1GiGueMissile::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    this->m_1c = (u32)find_entity_by_id((this->m_34));
    if ((u32) this->m_1c == 0U) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    *(f32 *)&this->unk_BC = (f32) (*(f32 *)&this->unk_BC + lbl_805DE6DC);
    temp_f1 = *(f32 *)&this->unk_BC;
    if (temp_f1 >= lbl_805DE6E0) {
        *(f32 *)&this->unk_BC = (f32) (temp_f1 - lbl_805DE6E0);
    }
    ((TNeedleShoot *)arg0)->update_position();
    ((TObjEneMe1GiGueMissile *)arg0)->update_lifetime();
    TObjPlayer__sub_802A445C(arg0, 1);
}
#pragma pop

u8 *TObjEneMe1GiGueMissile__ct(u8 *arg0, s32 arg1, u8 *from, u8 *to, f32 farg0, f32 farg1) {
    u8 *temp_r3;
    u8 *temp_r3_2;
    TNeedleShoot__ct(arg0, arg1, from, to);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_802CE428___vt__22TObjEneMe1GiGueMissile *)&__vt__22TObjEneMe1GiGueMissile).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D3F20;
    ((TObjEneMe1GiGueMissile *)arg0)->m_c0 = farg1;
    *(f32 *)((s8 *)arg0 + 0xAC) = farg0;
    play_sound_effect(0x4002A600, (u32)(arg0 + 0x6C), 0, 0);
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x1C));
    if (temp_r3 != NULL) {
        ((TObjEneMe1GiGueMissile *)arg0)->m_34 = get_entity_id(temp_r3);
    }
    temp_r3_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x68));
    if (temp_r3_2 != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3_2 + 0xA4)) + 0xC) = (f32) lbl_805DE6DC;
    }
    ((TObjEneMe1GiGueMissile *)arg0)->m_b0 = 1;
    return arg0;
}

void TObjEneMe1GiGue__sub_802CE4E8(void) {  }

void TObjEneMe1GiGue__sub_802CE4EC(void) { TObjEneMe1GiGue_barrier_count = TObjEneMe1GiGue::get_barrier_count(); }

