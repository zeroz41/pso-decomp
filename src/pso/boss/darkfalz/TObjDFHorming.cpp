#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/text_8035966C.h"
#include "pso/boss/darkfalz/TBoss4Fade.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz_8004C93C.h"
#include "pso/object/ending/TObjOnlineEnding_802E4B80.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/system/vector.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/enemy/TObjEnemy.h"
#include <stddef.h>
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/boss/darkfalz/TBoss4Type1.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/enemy/TUnk_80486924.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/PlayerSlots.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>


#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TBoss4Thanks_8035C8F0.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/object/TObjControl.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/unk/TLobby_8030A834.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"

#pragma readonly_strings on

struct E_8004AB90 { Vec pos; f32 r; Vec v; f32 s; };

const char *darkfalz_dat_model_names[] = {
    "df_event_tower.nj",
    "df_rikomiraju_body.nj",
    "df1_anzen.nj",
    "df1_s_body.nj",
    "df1_s_da_heada.nj",
    "df1_s_db_heada.nj",
    "df1_s_dc_heada.nj",
    "df1_s_dodai.nj",
    "df1_s_simobe.nj",
    "df1_s_waist.nj",
    "df2_s_body.nj",
    "df2_s_dodai1.nj",
    "df3_s_body.nj",
    "df3_s_wing.nj",
    "df3_sl_body.nj",
    "df3_sl_wing.nj",
    "fd_obj813_face.nj",
    "fd_obj813_flower01.nj",
    "rico_ring3_rico_ring.nj",
    NULL,
};

const char *darkfalz_dat_motion_names[] = {
    "beaml_df1_s_body.njm",
    "beaml_df1_s_root.njm",
    "beaml_df2_s_body.njm",
    "beaml_df2_s_dodai1.njm",
    "beamr_df1_s_body.njm",
    "beamr_df1_s_root.njm",
    "beamr_df2_s_body.njm",
    "beamr_df2_s_dodai1.njm",
    "damage_df1_s_body.njm",
    "damage_df1_s_da_heada.njm",
    "damage_df1_s_dodai.njm",
    "damage_df1_s_root.njm",
    "damage_df2_s_body.njm",
    "damage_df2_s_dodai1.njm",
    "damage_df3_s_body.njm",
    "damage_df3_s_wing.njm",
    "damage_df3_s1_wing.njm",
    "dead_df2_s_body.njm",
    "dead_df2_s_dodai1.njm",
    "dead_df3_s_body.njm",
    "dead1_df1_s_body.njm",
    "dead1_df1_s_da_heada.njm",
    "dead1_df1_s_root.njm",
    "df_rikomiraju_body.njm",
    "df1op_df1_s_body.njm",
    "df1op_df1_s_da_heada.njm",
    "df2op_df1_s_body.njm",
    "df2op_df1_s_da_heada.njm",
    "df2op_df2_s_body.njm",
    "df2op_df2_s_dodai1.njm",
    "df3_op_df2_s_body.njm",
    "df3_op_df2_s_dodai1.njm",
    "df3_op_df3_s_body.njm",
    "df3_op_df3_s_wing.njm",
    "df3_op_df3_s1_wing.njm",
    "df3dead_df_rikomiraju_body.njm",
    "df3dead_df3_s_body.njm",
    "dwntec_df3_s_body.njm",
    "fd_obj813_face.njm",
    "fd_obj813_flower01.njm",
    "haki_df1_s_da_heada.njm",
    "haki_df1_s_root.njm",
    "hakiin_df1_s_da_heada.njm",
    "hakiin_df1_s_root.njm",
    "hakiout_df1_s_da_heada.njm",
    "hakiout_df1_s_root.njm",
    "hoe_df1_s_body.njm",
    "hoe_df1_s_da_heada.njm",
    "hoe_df2_s_body.njm",
    "hoe_df2_s_dodai1.njm",
    "jisin_df2_s_body.njm",
    "jisin_df2_s_dodai1.njm",
    "jyousyou_df3_s_body.njm",
    "jyousyou_df3_s_wing.njm",
    "jyousyou_df3_s1_wing.njm",
    "kakou_df3_s_body.njm",
    "kakou_df3_s_wing.njm",
    "kakou_df3_s1_wing.njm",
    "laser_df3_s_body.njm",
    "laser_df3_s_wing.njm",
    "laser_df3_s1_wing.njm",
    "lhassya_df1_s_body.njm",
    "lhassya_df2_s_body.njm",
    "lhassya_df2_s_dodai1.njm",
    "lkiri_df3_s_body.njm",
    "lkiri_df3_s_wing.njm",
    "lkiri_df3_s1_wing.njm",
    "ltame_df1_s_body.njm",
    "ltame_df2_s_body.njm",
    "rico_ring3_rico_ring.njm",
    "ricoult1_df_rikomiraju_body.njm",
    "ricoult2_df_rikomiraju_body.njm",
    "rkiri_df3_s_body.njm",
    "rkiri_df3_s_wing.njm",
    "rkiri_df3_s1_wing.njm",
    "uptec_df3_s_body.njm",
    "wait_df1_s_body.njm",
    "wait_df1_s_da_heada.njm",
    "wait_df1_s_dodai.njm",
    "wait_df1_s_root.njm",
    "wait_df1_s_waist.njm",
    "wait_df2_s_body.njm",
    "wait_df2_s_dodai1.njm",
    "wait_df3_s_body.njm",
    "wait_df3_s_wing.njm",
    "wait_df3_s1_wing.njm",
    "wing_df2_s_body.njm",
    "wing_df2_s_dodai1.njm",
    "wing_wing_root.njm",
    "yubi_df3_s_body.njm",
    NULL,
};

BmlResourceDescriptor darkfalz_dat_resource_descriptor = {
    "darkfalz_dat.bml", darkfalz_dat_model_names, darkfalz_dat_motion_names, 19, 90,
};

const char *TBoss4DarkFalz__name = "TBoss4DarkFalz";

// Read-only start positions (.rodata) of sub_8004B8F8 and sub_8004B7DC. Declared const, the visible
// definition lets CodeWarrior hoist the copy above the stmw in both users, so they are placed explicitly.
__declspec(section ".rodata") Vec dark_falz_player_ring_center_origin = { 0.0f, 10.0f, 0.0f };
__declspec(section ".rodata") Vec dark_falz_player_ring_center = { 10000.0f, 10.0f, 0.0f };

Vec dark_falz_zako_ring_origin_vec = { 0.0f, -13.0f, 0.0f };

E_8004AB90 dark_falz_push_zone_table[3] = {
    { { -10000.0f, 0.0f, 0.0f }, 750.0f, { -10000.0f, 0.0f, 200.0f }, 50.0f },
    { { 0.0f, 0.0f, 0.0f }, 750.0f, { 0.0f, 0.0f, 0.0f }, 50.0f },
    { { 10000.0f, 0.0f, 0.0f }, 750.0f, { 10000.0f, 0.0f, 0.0f }, 200.0f },
};


extern "C" {
s32 subtract_vector(void *, void *);
f32 xyz_distance(void *, void *);
extern s32 lbl_805D5868;
extern s32 lbl_805D5870;

void TBoss4DarkFalz::push_players_out_of_zone(s32 boss4_dark_falz, s32 arg1) {
    Vec v;
    E_8004AB90 *e;
    Vec *ev;
    s32 i;
    u8 *p;
    s32 j;
    u8 *q;
    E_8004AB90 *o;
    f32 r;
    f32 sc;
    f32 orad;
    e = &dark_falz_push_zone_table[arg1];
    r = dark_falz_push_zone_table[arg1].r;
    sc = dark_falz_push_zone_table[arg1].s;
    ev = &dark_falz_push_zone_table[arg1].v;
    for (i = registered_player_count + lbl_805D5870; i < lbl_805D5868; i++) {
        p = (u8 *)TObjPlayer::get_player_data(i);
        if (p == NULL) continue;
        q = *(u8 * *)&((TObjCollidable *)p)->bodies;
        if (q == NULL || !(*(s32 *)((s8 *)q + 0x18) & 0x20000)) continue;
        if (xyz_distance(e, p + 0x38) <= r) continue;
        for (j = 0; j < 3; j++) {
            o = &dark_falz_push_zone_table[j];
            orad = dark_falz_push_zone_table[j].r;
            if (j != arg1 && !(xyz_distance(p + 0x38, o) > orad)) {
                VecCopy((Vec *)&v, (const Vec *)(p + 0x38));
                subtract_vector(&v, o);
                v.y = 0.0f;
                if (vector_length(&v) <= 0.01f) {
                    v.x = 0.0f;
                    v.z = 1.0f;
                } else {
                    normalize_vector(&v);
                }
                break;
            }
        }
        if (j != 3) {
            v.x = v.x * sc;
            v.z = v.z * sc;
            v.y = 7.5f;
            vec3_add_to(&v, ev);
            VecCopy((Vec *)(p + 0x38), (const Vec *)&v);
            ((TObjCollidable *)p)->refresh_collision_body_centers();
        }
    }
}

s16 get_entity_id(void *);
s32 TBoss4Type3__sub_8005254C(s16);


s32 TObjDFHorming::is_boss_active() {
    int var_r31;

    var_r31 = 0;
    if (TBoss4DarkFalz__sub_8004C1AC() != NULL) {
        if (TBoss4DarkFalz__sub_8004C1AC()->get_action_state() != 3) {
            if (TBoss4DarkFalz__sub_8004C1AC()->get_action_state() != 2) {
                var_r31 = 1;
            }
        }
    }
    return (u8)((u8) var_r31);
}

s32 TBoss4DarkFalz::is_state_ready() {
    int var_r31;

    var_r31 = 0;
    if (TBoss4DarkFalz__sub_8004C1B4() != NULL) {
        if (TBoss4DarkFalz__sub_8004C1B4()->get_phase() != 3) {
            if (TBoss4DarkFalz__sub_8004C1B4()->get_phase() != 2) {
                var_r31 = 1;
            }
        }
    }
    return (u8)((u8) var_r31);
}

s32 TBoss4DarkFalz::is_active() {
    int var_r31;

    var_r31 = 0;
    if (TBoss4DarkFalz::get_instance() != NULL) {
        if (TBoss4DarkFalz::get_instance()->get_state() != 3) {
            if (TBoss4DarkFalz::get_instance()->get_state() != 4) {
                var_r31 = 1;
            }
        }
    }
    return (u8)((u8) var_r31);
}
s32 TBoss4Type3::pick_random_target_player() {
    u16 buf[4];
    s32 n;
    s32 i;
    u8 *p;
    n = 0;
    for (i = 0; i < registered_player_count; i++) {
        p = (u8 *)TObjPlayer::get_player_data(i);
        if (p != NULL && TBoss4Type3__sub_8005254C(get_entity_id(p)) != 0) {
            buf[n++] = get_entity_id(p);
            if (n >= 4) {
                break;
            }
        }
    }
    if (n == 0) {
        return (u16)(0xFFFF);
    }
    return (u16)(buf[(s32)(((f32)n - 0.01f) * (3.0517578e-05f * (f32)rand()))]);
}

}

struct Msg_8004B16C { u8 code; u8 size; u16 id; s16 a; u8 pad6[2]; s32 b; u8 padc[4]; };

struct Msg_8004B1BC { u8 code; u8 size; u16 id; s16 a; u8 pad6[2]; s32 b; u8 padc[4]; };

struct P_8004B5A0 { u8 pad0[0x38]; Vec pos; };

typedef struct Hit_8004B7DC {
    s32 f0;
    s32 f4;
} Hit_8004B7DC;

typedef struct Hit_8004B8F8 {
    s32 f0;
    s32 f4;
} Hit_8004B8F8;

struct Desc_8004BD58 { s16 f0; s16 f2; u8 pad4[0x3C]; };

struct VBase_18_8004B654 { char pad[0x18]; };
struct VObj_18_8004B654 : VBase_18_8004B654 {
#define V(n) virtual void m##n();
V(0)V(1)V(2)V(3)V(4)V(5)V(6)V(7)V(8)V(9)V(10)V(11)V(12)V(13)V(14)V(15)V(16)V(17)V(18)V(19)
V(20)V(21)V(22)V(23)V(24)V(25)V(26)V(27)V(28)V(29)V(30)V(31)V(32)V(33)V(34)V(35)V(36)V(37)V(38)V(39)
V(40)V(41)V(42)V(43)V(44)V(45)V(46)V(47)V(48)V(49)V(50)V(51)V(52)V(53)V(54)V(55)V(56)V(57)V(58)V(59)
V(60)V(61)V(62)V(63)V(64)V(65)V(66)V(67)V(68)V(69)V(70)V(71)V(72)V(73)V(74)V(75)V(76)
#undef V
    virtual s32 m77(s32 *);
};
extern "C" {
s32 is_split_screen();
extern s32 local_client_id;
s32 TBoss4DarkFalz__sub_8004AF5C(u8 *self, s16 *arg1, s16 *arg2);

void release_all_players_control_lock(void);

void TBoss4DarkFalz__sub_8004B5A0(void);
void TBoss4DarkFalz__sub_8004B4F0(void *, void *);
Desc_8004BD58 TBoss4DarkFalz__data_804FF1E8;

}
void reset_cameras_to_actor(void *, s32);

extern "C" {
void TBoss4DarkFalz__sub_8004B7DC(TBoss4DarkFalz *boss4_dark_falz);
void TBoss4DarkFalz__sub_8004B8F8(TBoss4DarkFalz *boss4_dark_falz);
int TBoss4DarkFalz__sub_8004B07C(TBoss4DarkFalz *);
s32 is_local_client_floor_leader();
s32 get_main_phase();

s32 TBoss4DarkFalz__sub_8004AF5C(u8 *self, s16 *arg1, s16 *arg2) {
    s32 temp_r6;
    temp_r6 = *(s32 *)((s8 *)self + 0x384);
    if ((temp_r6 < 1) || (temp_r6 > 0x1FE)) {
        return 0;
    }
    if (temp_r6 > 0x1FD) {
        return 0;
    }
    *arg1 = *(s16 *)((s8 *)self + 0x2C) + temp_r6;
    *arg2 = *(u16 *)((s8 *)self + 0x1C) + *(s32 *)((s8 *)self + 0x384);
    *(s32 *)((s8 *)self + 0x384) = (s32) (*(s32 *)((s8 *)self + 0x384) + 1);
    return 1;
}

void TBoss4DarkFalz::sub_8004AFB8() { this->m_384 = 1; }

s32 TBoss4DarkFalz::count_active_players() {
    s32 count = 0;
    s32 i;
    for (i = 0; i < registered_player_count; i++) {
        if (TObjPlayer::get_player_data(i) != 0) {
            count++;
        }
    }
    if (count == 0 || count > 4) {
        return 1;
    }
    return count;
}

int TBoss4DarkFalz::is_ending_or_split_screen() {
    u8 result;

    result = 0;
    if ((get_main_phase() == 0xF) || (is_split_screen() != 0)) {
        result = 1;
    }
    return result;
}
int TBoss4DarkFalz__sub_8004B07C(TBoss4DarkFalz *) { return 0; }

void TBoss4DarkFalz::sub_8004B084() {
    TBoss4DarkFalzHandler action = dark_falz_state_table[m_37c].update;
    if (action != 0) {
        (this->*action)();
    }
}

void TBoss4DarkFalz::sub_8004B0F8() {
    TBoss4DarkFalzHandler action = dark_falz_state_table[m_37c].update_leader;
    if (action != 0) {
        (this->*action)();
    }
}

void TBoss4DarkFalz::send_code_25_4(s32 arg) {
    TBoss4DarkFalz *self = this;
    Msg_8004B16C msg;
    ((TBoss4DarkFalz *)(&msg))->set_code_25_4();
    msg.id = self->entity_id;
    msg.a = -1;
    msg.b = arg;
    ((TBoss4DarkFalz *)(&msg))->swap_and_send();
}

void TBoss4DarkFalz::send_action_packet(s32 arg) {
    TBoss4DarkFalz *self = this;
    Msg_8004B1BC msg;
    ((TBoss4DarkFalz *)(&msg))->set_code_25_4();
    msg.id = self->entity_id;
    msg.a = arg;
    msg.b = -1;
    ((TBoss4DarkFalz *)(&msg))->swap_and_send();
}

void TBoss4DarkFalz::change_state(s32 arg1) {
    if (arg1 < 0 || arg1 >= 16) {
        return;
    }
    if ((s32)m_37c != -1) {
        TBoss4DarkFalzHandler action = dark_falz_state_table[(s32)m_37c].leave;
        if (action != 0) {
            (this->*action)();
        }
    }
    m_37c = arg1;
    TBoss4DarkFalzHandler action = dark_falz_state_table[(s32)m_37c].enter;
    if (action != 0) {
        (this->*action)();
    }
}

void TBoss4DarkFalz::update_visible_flag() {
    if (is_local_client_floor_leader() != 0) {
        this->m_378 = 0;
        return;
    }
    this->m_378 = 1;
}

s32 TBoss4DarkFalz::calc_rate_from_field() {
    s32 temp_r3;

    temp_r3 = this->m_390;
    if (temp_r3 > 0) {
        return 0x10000 / temp_r3;
    }
    return 0;
}

s32 TBoss4DarkFalz::is_timer_expired() {
    s32 var_r4;

    var_r4 = *(s32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x35)) + 0x18);
    if ((var_r4 < 1) || (var_r4 > 0x13)) {
        var_r4 = 2;
    }
    if ((s32) this->m_38c >= (s32) (var_r4 * this->m_390)) {
        return 1;
    }
    return 0;
}

#pragma fp_contract on
void TBoss4DarkFalz::spawn_zako_rings() {
    TBoss4ZakoSetData p;
    f32 r;
    f32 dr;
    s32 j;
    s32 n;
    s32 ang;
    s32 step;
    s32 i;
    p.owner = this;
    r = 28.571428f;
    dr = 57.142857f;
    TBoss4DarkFalz__sub_8004B4F0(&p.set_index, &TBoss4DarkFalz__data_804FF1E8);
    p.unk_0C = 1;
    if (game_difficulty_selection == 3) {
        r *= 1.25f;
        dr *= 1.25f;
    }
    for (j = 0; j < 4; j++) {
        n = (j * 2 + 1) * 5;
        ang = 0;
        step = 0x10000 / n;
        for (i = 0; i < n; i++) {
            if (TBoss4DarkFalz__sub_8004AF5C(((u8 *)this), &p.set_index, &p.entity_id) == 0) {
                return;
            }
            VecCopy(&p.position, &dark_falz_zako_ring_origin_vec);
            p.position.x += r * sin_table_lookup(ang);
            p.position.z += r * cos_table_lookup(ang);
            TBoss4Zako::create(&p);
            ang += step;
        }
        r += dr;
    }
}

struct C12_8004B4F0 { u32 w[3]; };
struct C20_8004B4F0 { u32 w[5]; };
struct S_8004B4F0 {
  s16 a0;
  s16 a2;
  s16 a4;
  u16 a6;
  s16 a8;
  s16 aa;
  s16 ac;
  s16 ae;
  struct C12_8004B4F0 c10;
  struct C12_8004B4F0 c1c;
  struct C20_8004B4F0 c28;
  s16 a3c;
  s16 a3e;
};

#pragma push
#pragma cplusplus off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss4DarkFalz__sub_8004B4F0(void *arg0p, void *arg1p) {
#define o ((struct S_8004B4F0 *)arg0p)
#define s ((struct S_8004B4F0 *)arg1p)
  struct S_8004B4F0 *new_var;
  struct S_8004B4F0 *new_var2;
  struct C20_8004B4F0 *dc = &o->c28;
  struct C20_8004B4F0 *sc = &s->c28;
  o->a0 = s->a0;
  new_var2 = (new_var = o);
  new_var2->a2 = s->a2;
  o->a4 = s->a4;
  new_var->a6 = s->a6;
  o->a8 = s->a8;
  o->aa = s->aa;
  new_var->ac = s->ac;
  o->ae = s->ae;
  new_var->c10 = s->c10;
  o->c1c = s->c1c;
  *dc = *sc;
  new_var->a3c = s->a3c;
  o->a3e = s->a3e;
}
#undef o
#undef s
#pragma pop

void TBoss4DarkFalz__sub_8004B5A0(void) {
    Vec v;
    P_8004B5A0 *p;
    s32 i;
    f32 k;
    if (TBoss4Thanks__sub_8035C96C() != 0) {
        play_sound_effect(0x40033231, 0, 0, 0);
        k = 12.5f;
        for (i = 0; i < registered_player_count; i++) {
            p = (P_8004B5A0 *)TObjPlayer::get_player_data(i);
            if (p != 0 && ((TObjPlayer *)p)->get_area() == 0xE) {
                VecCopy((Vec *)&v, (const Vec *)&p->pos);
                v.y += k;
                spawn_particle_effect(&v, 0x28);
            }
        }
    }
}

struct V3_8004B654 { u32 w[3]; };
#pragma inline_depth(4)
#pragma dont_inline off
#pragma auto_inline on
void TBoss4DarkFalz::handle_defeat() {
    u8 *self = (u8 *)this;
    struct V3_8004B654 save;
    s32 flags[3];
    TObjPlayer *p;

    TBoss4DarkFalz__sub_8004B5A0();
    if (is_split_screen() != 0) {
        ((TObjEnemy *)self)->distribute_experience();
    } else {
        p = get_player_by_client_id((u16)local_client_id);
        if (p != 0) {
            save = *(struct V3_8004B654 *)(self + 0x2FC);
            VecCopy(&this->body_center, &p->body_center);
            ((TObjEnemy *)self)->distribute_experience();
            VecCopy(&this->body_center, (const Vec *)&save);
        }
    }
    flags[0] = 0x800;
    ((TObjEnemy *)self)->send_6x0A_enemy_state(flags);
    ((TObjEnemy *)self)->exchange_object_state(flags, 0);
    ((VObj_18_8004B654 *)(self))->m77(flags);
    ((TObjEnemy *)self)->send_entity_set_flags();
    ((TObject *)self)->queue_destruction();
}

void TBoss4DarkFalz__sub_8004B730(TBoss4DarkFalz *controller, s32 color, f32 alpha) {
    f32 var_f1;
    TBoss4Fade *temp_r3;
    var_f1 = alpha;
    temp_r3 = controller->fade;
    if ((temp_r3 != NULL) && !(var_f1 <= 0.0f)) {
        if (var_f1 > 1.0f) {
            var_f1 = 1.0f;
        }
        fn_803594B4(temp_r3, color, var_f1);
    }
}
void TBoss4DarkFalz::refresh_player_equipment(void *self) {
    s32 i;
    void *p;
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != 0) {
            if (((TObjPlayer *)p)->get_area() == 0xE) {
                ((TObjPlayer *)p)->refresh_equipment_slot();
            }
        }
    }
}

#pragma fp_contract on
void TBoss4DarkFalz__sub_8004B7DC(TBoss4DarkFalz *boss4_dark_falz) {
    Vec base = dark_falz_player_ring_center;
    s32 rate;
    s32 ang;
    s32 i;
    void *p;
    rate = boss4_dark_falz->calc_rate_from_field();
    ang = 0;
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != NULL && ((TObjPlayer *)p)->get_area() == 0xE) {
            Vec v = base;
            v.x += 2.5e+02f * sin_table_lookup(ang);
            v.z += 2.5e+02f * cos_table_lookup(ang);
            ((TObjBase *)p)->set_position_from(&v);
            ((TObjBase *)p)->save_previous_position();
            ((Hit_8004B7DC *)((TObjBase *)p)->get_rotation())->f4 = ang + 0x8000;
            ((TObjPlayer *)p)->refresh_equipment_slot();
            if (TObjPlayer::is_locally_controlled(p) != 0) {
                reset_cameras_to_actor(p, 0);
            }
            ang += rate;
        }
    }
}

#pragma fp_contract on
void TBoss4DarkFalz__sub_8004B8F8(TBoss4DarkFalz *boss4_dark_falz) {
    Vec base = dark_falz_player_ring_center_origin;
    s32 rate;
    s32 ang;
    s32 i;
    void *p;
    rate = boss4_dark_falz->calc_rate_from_field();
    ang = rate / 2;
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != NULL && ((TObjPlayer *)p)->get_area() == 0xE) {
            Vec v = base;
            v.x += 12.5f * sin_table_lookup(ang);
            v.z += 12.5f * cos_table_lookup(ang);
            ((TObjBase *)p)->set_position_from(&v);
            ((TObjBase *)p)->save_previous_position();
            ((Hit_8004B8F8 *)((TObjBase *)p)->get_rotation())->f4 = 0x8000;
            ((TObjPlayer *)p)->refresh_equipment_slot();
            if (TObjPlayer::is_locally_controlled(p) != 0) {
                reset_cameras_to_actor(p, 0);
            }
            ang += rate;
        }
    }
}

void TBoss4DarkFalz::end_player_camera_pans(void *self) {
    s32 i;
    void *p;
    TWindowCtrl::init_all_slots2();
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != 0) {
            ((TObjPlayer *)p)->end_camera_pan();
        }
    }
    release_all_players_control_lock();
}
void TBoss4DarkFalz::freeze_all_players(void *self) {
    s32 i;
    void *p;
    TWindowCtrl::init_all_slots();
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != 0) {
            ((TObjPlayer *)p)->start_freeze();
        }
    }
}
#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
void TBoss4DarkFalz::update_roar_sound_timer() {
    s32 temp_r0;
    s32 temp_r0_2;
    temp_r0 = this->m_37c;
    if (temp_r0 >= 9 || temp_r0 < 4) {
        return;
    }
    {
        temp_r0_2 = this->m_374 - 1;
        this->m_374 = temp_r0_2;
        if (temp_r0_2 < 0) {
            if ((3.0517578e-05f * (f32) rand()) < 0.5f) {
                play_sound_effect(0x3A300, 0, 0, 0);
            } else {
                play_sound_effect(0x3A801, 0, 0, 0);
            }
            {
                f32 r = 3.0517578e-05f * (f32) rand();
                this->m_374 = (s32) ((3e+02f * r) + 3e+02f);
            }
        }
    }
}
}
#pragma pop

#pragma push
#pragma fp_contract on

#pragma pop

// back to the unit's -inline off defaults after TObjDFHorming's inline pragmas
#pragma dont_inline on
#pragma auto_inline off
#pragma fp_contract off


typedef struct Msg_8004BFA4 {
    u8 code;
    u8 size;
    u16 id;
    s16 action;
    u8 pad6[2];
    s32 arg;
} Msg_8004BFA4;

extern "C" {
void TBoss4Type2__sub_80056EA8(void *, s32);
void TBoss4Type3__sub_80059DCC(TBoss4Type3 *self, u32 packed);
void handle_6x19_dark_falz_actions(Msg_8004BFA4 *arg0);
extern s32 __vt__14TBoss4DarkFalz[];
void TBoss4DarkFalz__sub_8004B4F0(void *arg0p, void *arg1p);
s32 __ct__9TObjEnemyFP7TObject();
s32 TBoss4DarkFalz__ct(saddr a0, s32 arg1, saddr a2);
int TBoss4DarkFalz__sub_8030AD38(void);
s32 __ct__11TObjControlFP7TObject(s32, s32);

void TBoss4DarkFalz::render() {  }

void TBoss4DarkFalz::run_task() {
    u8 *self = (u8 *)this;
    if (((s32) this->m_37c != 0) && (TObjPlayer::check_demo_mode() != 0)) {
        ((TBoss4DarkFalz *)self)->change_state(0);
    }
    if (TObjEneDD::query_teammate_state() == 0) {
        ((TBoss4DarkFalz *)self)->update_visible_flag();
        if ((s32) this->m_378 == 0) {
            ((TBoss4DarkFalz *)self)->sub_8004B0F8();
        }
        ((TBoss4DarkFalz *)self)->sub_8004B084();
        ((TBoss4DarkFalz *)self)->update_roar_sound_timer();
    }
}

void TBoss4DarkFalz::run_death_reaction() {  }
}
void init_music_sequencer(s32 program);
BmlResource *darkfalz_dat_resource;
TBoss4Type1 *TBoss4DarkFalz__type1_instance;
TUnk_80486924 *TBoss4DarkFalz__type2_instance;
TBoss4Type3 *TBoss4DarkFalz__type3_instance;
s32 dark_falz_form_index;
s32 lbl_805D4D6C;
s32 lbl_805D4D70;
s32 dark_falz_controller_instance;
TBoss4DarkFalz::~TBoss4DarkFalz() {
    s32 temp_r0;
    TBoss4Fade *object;
    switch (*(s32 *)((s8 *)this + 0x37C)) {
    case 10:
    case 14:
    case 15:
        this->send_entity_set_flags();
        break;
    }
    TBoss4DarkFalz::end_player_camera_pans(this);
    restore_player_cameras();
    if (TBoss4DarkFalz::is_ending_or_split_screen() == 0) {
        TLobby::stop_audio_streams();
    }
    object = fade;
    if (object != NULL) {
        object->queue_destruction();
        fade = NULL;
    }
    if (TBoss4DarkFalz__type1_instance != NULL) {
        TBoss4DarkFalz__type1_instance->queue_destruction();
        TBoss4DarkFalz__type1_instance = NULL;
    }
    if (TBoss4DarkFalz__type2_instance != NULL) {
        TBoss4DarkFalz__type2_instance->queue_destruction();
        TBoss4DarkFalz__type2_instance = NULL;
    }
    if (TBoss4DarkFalz__type3_instance != NULL) {
        TBoss4DarkFalz__type3_instance->queue_destruction();
        TBoss4DarkFalz__type3_instance = NULL;
    }
    dark_falz_controller_instance = 0;
}


s32 TBoss4DarkFalz__ct(saddr a0, s32 arg1, saddr a2) {
    u8 *boss4_dark_falz = (u8 *)a0;
    u8 *arg2 = (u8 *)a2;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r29;
    s32 temp_r29_2;
    s32 temp_r30;
    s32 temp_r30_2;
    __ct__9TObjEnemyFP7TObject();
    *(s32 **)((s8 *)boss4_dark_falz + 0x18) = __vt__14TBoss4DarkFalz;
    *(s32 *)((s8 *)boss4_dark_falz + 0) = (saddr) TBoss4DarkFalz__name;
    ((TBoss4DarkFalz *)boss4_dark_falz)->sub_8004AFB8();
    if ((s16) *(s16 *)((s8 *)arg2 + 2) != 0x200) {
        return (saddr)boss4_dark_falz;
    }
    dark_falz_controller_instance = (saddr)boss4_dark_falz;
    ((TBoss4DarkFalz *)(boss4_dark_falz))->apply_set_data(arg2);
    TBoss4DarkFalz__sub_8004B4F0(&TBoss4DarkFalz__data_804FF1E8, arg2);
    TBoss4DarkFalz__data_804FF1E8.f2 = 0;
    ((TBoss4DarkFalz *)(boss4_dark_falz))->clear_lobby_object_state();
    VecCopy((Vec *)(boss4_dark_falz + 0x44), (const Vec *)(VecCopy((Vec *)(boss4_dark_falz + 0x50), (const Vec *)(VecCopy((Vec *)(boss4_dark_falz + 0x74), (const Vec *)(boss4_dark_falz + 0x38))))));
    VecCopy((Vec *)(boss4_dark_falz + 0x2FC), (const Vec *)(boss4_dark_falz + 0x38));
    *(f32 *)((s8 *)boss4_dark_falz + 0x310) = (f32) 0.0f;
    ((TBoss4DarkFalz *)boss4_dark_falz)->y_speed = (f32) 0.0f;
    *(f32 *)((s8 *)boss4_dark_falz + 0x308) = (f32) 0.0f;
    *(s32 *)((s8 *)boss4_dark_falz + 0x2A8) = 0;
    if ((s32) game_difficulty_selection == 0) {
        ((TObjEnemy *)boss4_dark_falz)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(0x37)), (u8 *)(TLobby::dispatch_shared_handler_b(0x37)), (u8 *)(TLobby::register_object(0x37)));
    } else {
        ((TObjEnemy *)boss4_dark_falz)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(0x38)), (u8 *)(TLobby::dispatch_shared_handler_b(0x38)), (u8 *)(TLobby::register_object(0x38)));
    }
    register_entity_by_id((boss4_dark_falz));
    *(s32 *)((s8 *)boss4_dark_falz + 0x30) = (s32) (*(s32 *)((s8 *)boss4_dark_falz + 0x30) | 0x02000000);
    ((TBoss4DarkFalz *)boss4_dark_falz)->update_visible_flag();
    *(s32 *)((s8 *)boss4_dark_falz + 0x390) = TBoss4DarkFalz::count_active_players();
    TBoss4DarkFalz__type1_instance = 0;
    TBoss4DarkFalz__type2_instance = 0;
    TBoss4DarkFalz__type3_instance = 0;
    reinterpret_cast<TBoss4DarkFalz *>(boss4_dark_falz)->intro_tower = NULL;
    reinterpret_cast<TBoss4DarkFalz *>(boss4_dark_falz)->fade = create_boss4_fade();
    *(s32 *)((s8 *)boss4_dark_falz + 0x388) = 0;
    *(s32 *)((s8 *)boss4_dark_falz + 0x38C) = 0;
    fn_8030A83C((boss4_dark_falz));
    init_music_sequencer(4);
    dark_falz_form_index = 0;
    *(s32 *)((s8 *)boss4_dark_falz + 0x374) = 0;
    temp_r0 = *(s32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x36)) + 0x18);
    lbl_805D4D6C = temp_r0;
    if ((temp_r0 < 0) || (temp_r0 > 0xE)) {
        lbl_805D4D6C = 0;
    }
    temp_r0_2 = *(s32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x36)) + 0x1C);
    lbl_805D4D70 = temp_r0_2;
    if ((temp_r0_2 < 0) || (temp_r0_2 > 0xE)) {
        lbl_805D4D70 = 0;
    }
    TBoss4DarkFalz::push_players_out_of_zone((saddr)boss4_dark_falz, 0);
    *(s32 *)((s8 *)boss4_dark_falz + 0x37C) = -1;
    ((TBoss4DarkFalz *)boss4_dark_falz)->change_state(1);
    return (saddr)boss4_dark_falz;
}

void handle_6x19_dark_falz_actions(Msg_8004BFA4 *arg0) {
    void *ent;
    s32 arg;
    ((TBoss4DarkFalz *)arg0)->swap_bytes();
    ent = get_enemy_entity(arg0->id);
    if (ent == NULL) {
        return;
    }
    if (arg0->action != -1 && arg0->action >= 0 && arg0->action < 16 &&
        arg0->action != ((TBoss4DarkFalz *)ent)->get_phase()) {
        ((TBoss4DarkFalz *)ent)->change_state(arg0->action);
    }
    arg = arg0->arg;
    if (arg == -1) {
        return;
    }
    switch (((TBoss4DarkFalz *)ent)->get_phase()) {
    case 5:
    case 6:
        if (TBoss4DarkFalz__type1_instance != NULL) {
            TBoss4DarkFalz__type1_instance->apply_packed_state(arg);
        }
        break;
    case 7:
    case 8:
    case 9:
        if (TBoss4DarkFalz__type2_instance != NULL) {
            TBoss4Type2__sub_80056EA8(TBoss4DarkFalz__type2_instance, arg);
        }
        break;
    case 12:
    case 13:
    case 14:
        if (TBoss4DarkFalz__type3_instance != NULL) {
            TBoss4Type3__sub_80059DCC(TBoss4DarkFalz__type3_instance, arg);
        }
        break;
    }
}

void TBoss4DarkFalz::cleanup_global() { TBoss4DarkFalz::free_global_instance(); TBoss4DarkFalz__sub_8030AD38(); delete (BmlResource *)darkfalz_dat_resource; darkfalz_dat_resource = 0; }

extern saddr tl_04;

void TBoss4DarkFalz::load_resources() {
    BmlResource *resource = new BmlResource(5, &darkfalz_dat_resource_descriptor, 0, 0, NULL);
    darkfalz_dat_resource = resource;
    if (resource != NULL) {
        TBoss4DarkFalz::init_uro_link();
        fn_802E52AC();
    }
}

s32 TBoss4DarkFalz::create(s32 arg0) {
    saddr var_r31;
    saddr var_r4;

    var_r31 = (saddr)TObject::operator new(sizeof(TBoss4DarkFalz));
    if (var_r31 != 0) {
        var_r4 = (saddr)TObject::operator new(0x20);
        if (var_r4 != 0) {
            var_r4 = __ct__11TObjControlFP7TObject(var_r4, tl_04);
        }
        var_r31 = TBoss4DarkFalz__ct(var_r31, var_r4, arg0);
    }
    return var_r31;
}

s32 TBoss4DarkFalz::get_phase() { return m_37c; }

saddr TBoss4Uro::get_instance_count() { return reinterpret_cast<saddr>(darkfalz_dat_resource); }
