#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/system/PadRumble.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/system/BmlResourceDescriptor.h"

extern char lbl_8046FDB8[];
extern char lbl_8046FDC8[];
extern char lbl_8046FDDC[];
extern char lbl_8046FDF4[];
extern char lbl_8046FE08[];
extern char lbl_8046FE1C[];
extern char lbl_8046FE34[];
extern char lbl_8046FE48[];
extern char lbl_8046FE58[];
extern char lbl_8046FE6C[];
extern char lbl_8046FE7C[];
extern char lbl_8046FE94[];
extern char lbl_8046FEA8[];
extern char lbl_8046FEB8[];
extern char lbl_8046FED0[];
extern char lbl_8046FEF0[];
extern char lbl_8046FF0C[];
extern char lbl_8046FF28[];
extern char lbl_8046FF40[];
extern char lbl_8046FF5C[];
extern char lbl_8046FF78[];
extern char lbl_8046FF94[];
extern char lbl_8046FFB0[];
extern char lbl_8046FFC4[];
extern char lbl_8046FFDC[];
extern char lbl_8046FFF4[];
extern char lbl_8047000C[];
extern char lbl_80470028[];
extern char lbl_80470044[];
extern char lbl_80470060[];
extern char lbl_80470078[];
extern char lbl_80470094[];
extern char lbl_804700B0[];
extern char lbl_804700CC[];
extern char lbl_804700E8[];
extern char lbl_80470104[];
extern char lbl_80470120[];
extern char lbl_8047013C[];
extern char lbl_8047015C[];
extern char lbl_80470178[];
extern char lbl_80470194[];
extern char lbl_804701B0[];
extern char lbl_804701CC[];
extern char lbl_804701E8[];
extern char lbl_80470204[];
extern char lbl_80470220[];
extern char lbl_80470238[];
extern char lbl_80470250[];
extern char lbl_80470268[];
extern char lbl_8047027C[];
extern char lbl_80470294[];
extern char lbl_804702AC[];
extern char lbl_804702C8[];
extern char lbl_804702E4[];
extern char lbl_80470300[];
extern char lbl_80470320[];
extern char lbl_80470340[];
extern char lbl_8047035C[];
extern char lbl_80470378[];
extern char lbl_80470394[];
extern char lbl_804703B0[];
extern char lbl_804703CC[];
extern char lbl_804703E8[];
extern char lbl_80470404[];
extern char lbl_8047041C[];
extern char lbl_80470438[];
extern char lbl_80470454[];
extern char lbl_80470470[];
extern char lbl_80470490[];
extern char lbl_804704A8[];
extern char lbl_804704C4[];
extern char lbl_804704E4[];
extern char lbl_80470504[];
extern char lbl_80470520[];
extern char lbl_8047053C[];
extern char lbl_8047055C[];
extern char lbl_80470574[];
extern const char *boss06_plotfalz_dat_model_names[15];
extern const char *boss06_plotfalz_dat_motion_names[63];
extern BmlResourceDescriptor boss6_plot_falz_resource_descriptor;
#include <stddef.h>
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss6EmptyWarp.h"
#include "pso/boss/TBoss6Mine.h"
#include "pso/object/TObjFish.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/boss/TBoss6GravBall.h"
#include "pso/boss/TBoss6Rock.h"
#include "pso/boss/TBoss6Tube.h"
#include "pso/boss/TBoss6Type2.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowCtrl.h"

struct Color_802ABF44 { f32 a, b, c, d; };

extern "C" {
void *get_player_data__10TObjPlayerFi(s32 i);
s32 is_state_1f__14TBoss6PlotFalzFUi(u32 arg0);
s16 obj_getField1c(void *);
u8 *get_player_by_client_id(s32);
s32 get_field_3e0__12TBoss3VoloptFv(void *p);
extern u8 lbl_8047059C[];
extern u32 TBoss6PlotFalz__type1_instance;
extern u32 TBoss6PlotFalz__type2_instance;
int queue_destruction__7TObjectFv(void *);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern s32 plot_falz_phase;
extern s32 lbl_805D586C;
void set_chunk_material_override_pair(int, int, s32, s32);
void set_chunk_material_color__13TUnk_80494AE0Fv(Color_802ABF44 *);
s32 alloc__23TAdSinglePlyChrSelectGCFv(int);
s32 rand(void);
}

#define get_player_data__10TObjPlayerFi ((Player_802AAE78 *(*)(s32))get_player_data__10TObjPlayerFi)
#define is_state_1f__14TBoss6PlotFalzFUi ((s32 (*)())is_state_1f__14TBoss6PlotFalzFUi)

struct Player_802AAE78 { u8 pad[0x32C]; s16 f32c; };

struct VBase_18_a328de { char pad[0x18]; };

struct VObj_18_a328de : VBase_18_a328de {
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
    virtual s32 m73();
};

extern "C" {
extern u16 boss6_plot_falz_player_order_table[];
u16 TBoss6PlotFalz__sub_802AAE48(s32 i);
s32 obj_isState2_324__13TUnk_804806E8Fv(void *);
s16 obj_getS16_32C(void *);
s32 send_6x2F_change_player_hp(int, s32, s16);

struct TBoss6PlotFalz_802AACF4 { u8 pad[0x3D0]; s32 f3D0; s32 f3D4; s32 f3D8; };
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void update_random_shake__14TBoss6PlotFalzFPv(TBoss6PlotFalz_802AACF4 *o) {
    if (o->f3D0 != 0) {
        s32 n = o->f3D4 - 1;
        o->f3D4 = n;
        if (n < 0) {
            TCameraCtrl::set_shake_preset(o->f3D8);
            o->f3D4 = (s32)(60.0f * (3.0517578125e-05f * (f32)rand()) + 60.0f);
        }
    }
}
#pragma pop

s32 TBoss6PlotFalz::damage_player_hp(s32 arg0, u32 arg1) {
    u32 v;
    u8 *p;
    s32 hp;
    u16 id;
    id = arg0;
    v = arg1;
    if (id == 0xFFFF || (p = get_player_by_client_id(id)) == NULL || ((TBoss6PlotFalz *)p)->is_active() == 0) {
        return 0;
    }
    hp = obj_getS16_32C(p);
    if ((u32)hp < v) {
        v = hp;
    }
    if (obj_isState2_324__13TUnk_804806E8Fv(p) != 0) {
        return v;
    }
    hp -= v;
    send_6x2F_change_player_hp(0xFFFF, arg0, hp);
    TObjPlayer::calc_photon_blast_charge(p, v);
    ((VObj_18_a328de *)p)->m73();
    return v;
}

u16 TBoss6PlotFalz__sub_802AAE48(s32 i) {
    if (i < 0 || i >= 4) return 0xFFFF;
    return boss6_plot_falz_player_order_table[i];
}

s32 TBoss6PlotFalz::sort_active_players() {
    s32 vals[4];
    s32 i;
    s32 j;
    s32 n;
    Player_802AAE78 *p;
    s32 t;
    s32 k;
    u16 s;
    for (i = 0; i < 4; i++) {
        boss6_plot_falz_player_order_table[i] = 0xFFFF;
        vals[i] = -1;
    }
    n = 0;
    for (i = 0; i < lbl_805D586C; i++) {
        p = get_player_data__10TObjPlayerFi(i);
        if (p != NULL && ((TBoss6PlotFalz *)p)->is_active() != 0 && p->f32c != 0) {
            boss6_plot_falz_player_order_table[n] = obj_getField1c(p);
            vals[n] = p->f32c;
            n++;
        }
    }
    for (i = 2; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
            k = j + 1;
            if (vals[j] < vals[k]) {
                t = vals[j];
                vals[j] = vals[k];
                vals[k] = t;
                s = boss6_plot_falz_player_order_table[j];
                boss6_plot_falz_player_order_table[j] = boss6_plot_falz_player_order_table[k];
                boss6_plot_falz_player_order_table[k] = s;
            }
        }
    }
    return n;
}

u16 TBoss6PlotFalz::pick_random_active_player() {
    u16 ids[4];
    s32 n;
    s32 i;
    Player_802AAE78 *p;

    n = 0;
    for (i = 0; i < lbl_805D586C; i++) {
        p = get_player_data__10TObjPlayerFi(i);
        if (p != NULL && ((TBoss6PlotFalz *)p)->is_active() != 0) {
            ids[n] = obj_getField1c(p);
            n++;
        }
    }
    if (n == 0) {
        return 0xFFFF;
    }
    return ids[(s32)(((f32)n - 0.1f) * (3.0517578125e-05f * (f32)rand()))];
}

s32 TBoss6PlotFalz::is_active() {
    if ((is_state_1f__14TBoss6PlotFalzFUi() != 0) && !(this->actorFlags & 0x02000800)) {
        return 1;
    }
    return 0;
}

}
#undef get_player_data__10TObjPlayerFi
#undef is_state_1f__14TBoss6PlotFalzFUi

#define update_random_shake__14TBoss6PlotFalzFPv ((s32 (*)(void *))update_random_shake__14TBoss6PlotFalzFPv)
#define get_field_3e0__12TBoss3VoloptFv ((s32 (*)())get_field_3e0__12TBoss3VoloptFv)

struct Stack_802AB1C8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

union MemberActionStorage_802AB1C8 { s32 words[3]; void (TBoss6PlotFalz::*action)(); };

struct RecoveredGlobal_802AB1C8_TBoss6PlotFalz__data_804DE66C {
    s32 value;
    u8 remaining[0x1D0];
};

struct Stack_802AB14C {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

union MemberActionStorage_802AB14C { s32 words[3]; void (TBoss6PlotFalz::*action)(); };

struct RecoveredGlobal_802AB14C_TBoss6PlotFalz__data_804DE66C {
    s32 value;
    u8 remaining[0x1D0];
};

union MemberActionStorage_802AB2B8 { s32 words[3]; void (TBoss6PlotFalz::*action)(); };

extern "C" {
extern RecoveredGlobal_802AB1C8_TBoss6PlotFalz__data_804DE66C TBoss6PlotFalz__data_804DE66C;
void TBoss6EmptyWarp__sub_802B1004(void *p);

s32 is_state_1f__14TBoss6PlotFalzFUi(u32 arg0) {
    if ((arg0 == 0U) || (get_field_3e0__12TBoss3VoloptFv() != 0x1F)) {
        return 0;
    }
    return 1;
}

typedef char MemberActionStorage_802AB1C8_size[sizeof(MemberActionStorage_802AB1C8) == 12 ? 1 : -1];
typedef char RecoveredGlobal_802AB1C8_TBoss6PlotFalz__data_804DE66C_size[sizeof(RecoveredGlobal_802AB1C8_TBoss6PlotFalz__data_804DE66C) == 0x1D4 ? 1 : -1];

typedef char MemberActionStorage_802AB14C_size[sizeof(MemberActionStorage_802AB14C) == 12 ? 1 : -1];
typedef char RecoveredGlobal_802AB14C_TBoss6PlotFalz__data_804DE66C_size[sizeof(RecoveredGlobal_802AB14C_TBoss6PlotFalz__data_804DE66C) == 0x1D4 ? 1 : -1];
void TBoss6PlotFalz::run_phase_action() {
  MemberActionStorage_802AB14C member_action;
  Stack_802AB14C stack;
  u8 *temp_r6;
  temp_r6 = (u8 *) (&(*(RecoveredGlobal_802AB14C_TBoss6PlotFalz__data_804DE66C *)&TBoss6PlotFalz__data_804DE66C).value);
  temp_r6 = temp_r6 + ((this->m_378) * 0x34);
  member_action.words[0] = *((s32 *) (((s8 *) temp_r6) + 0x28));
  member_action.words[1] = *((s32 *) (((s8 *) temp_r6) + 0x2C));
  member_action.words[2] = *((s32 *) (((s8 *) temp_r6) + 0x30));
  if (member_action.action != 0)
  {
    (this->*( member_action.action))();
  }
  update_random_shake__14TBoss6PlotFalzFPv((void *) this);
}

void TBoss6PlotFalz::call_state_action() {
  MemberActionStorage_802AB1C8 member_action;
  Stack_802AB1C8 stack;
  u8 *temp_r6;
  if (1)
  {
    temp_r6 = (u8 *)&TBoss6PlotFalz__data_804DE66C.value;
    temp_r6 = temp_r6 + ((this->m_378) * 0x34);
    member_action.words[0] = *((s32 *) (((s8 *) temp_r6) + 0x1C));
  }
  member_action.words[1] = *((s32 *) (((s8 *) temp_r6) + 0x20));
  member_action.words[2] = *((s32 *) (((s8 *) temp_r6) + 0x24));
  if (member_action.action != 0)
  {
    (this->*( member_action.action))();
  }
}

void TBoss6PlotFalz::set_state_2() { *(s32*)((char*)this + 0x3d4) = 0; *(s32*)((char*)this + 0x3d8) = 2; }
void TBoss6PlotFalz::reset_state() { *(s32*)((char*)this + 0x3d4) = 0; *(s32*)((char*)this + 0x3d8) = 0; }
void TBoss6PlotFalz::activate_warp() { void* m = *(void**)((char*)this + 0x384); if (m) ((TBoss6EmptyWarp *)m)->activate_warp(); }
void TBoss6PlotFalz::free_child() { void* m = *(void**)((char*)this + 0x384); if (m) TBoss6EmptyWarp__sub_802B1004(m); }
void TBoss6PlotFalz::set_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    MemberActionStorage_802AB2B8 leave;
    MemberActionStorage_802AB2B8 enter;
    u8 *e;
    if (arg1 < 0 || arg1 >= 9) {
        return;
    }
    {
        if (*(s32 *)(arg0 + 0x378) != -1) {
            e = (u8 *)&TBoss6PlotFalz__data_804DE66C.value;
            e = e + *(s32 *)(arg0 + 0x378) * 0x34;
            leave.words[0] = *(s32 *)(e + 0x10);
            leave.words[1] = *(s32 *)(e + 0x14);
            leave.words[2] = *(s32 *)(e + 0x18);
            if (leave.action != 0) {
                (((TBoss6PlotFalz *)arg0)->*(leave.action))();
            }
        }
        *(s32 *)(arg0 + 0x378) = arg1;
        e = (u8 *)&TBoss6PlotFalz__data_804DE66C.value;
            e = e + *(s32 *)(arg0 + 0x378) * 0x34;
        enter.words[0] = *(s32 *)(e + 0x4);
        enter.words[1] = *(s32 *)(e + 0x8);
        enter.words[2] = *(s32 *)(e + 0xC);
        if (enter.action != 0) {
            (((TBoss6PlotFalz *)arg0)->*(enter.action))();
        }
    }
}

}
#undef update_random_shake__14TBoss6PlotFalzFPv
#undef get_field_3e0__12TBoss3VoloptFv

#define get_player_data__10TObjPlayerFi ((Player_802AB3E0 *(*)(int))get_player_data__10TObjPlayerFi)
#define is_state_1f__14TBoss6PlotFalzFUi ((int (*)(Player_802AB3E0 *))is_state_1f__14TBoss6PlotFalzFUi)
#define get_player_by_client_id ((u8 *(*)(u16))get_player_by_client_id)
#define lbl_8047059C (*(RecoveredGlobal_802AB684_lbl_8047059C *)lbl_8047059C)

struct Stack_802AB684 {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

struct RecoveredGlobal_802AB684_lbl_8047059C { s32 value; u8 remaining[0x8]; };
typedef char RecoveredGlobal_802AB684_lbl_8047059C_size[sizeof(RecoveredGlobal_802AB684_lbl_8047059C) == 0xC ? 1 : -1];

struct Vec_802AB3E0 { f32 x, y, z; };

struct Player_802AB3E0 { u8 pad[0x38]; Vec_802AB3E0 pos; };

struct Vec_802AB6CC { f32 x, y, z; };

extern "C" {
void fn_803594B4(void *, s32, f32);
s32 vector_length(void *);
s32 subtract_vector(void *, void *);
void TBoss6PlotFalz__sub_802AB684(s32 arg0);
void *spawn_particle_effect(void *pos, s32 id);
int play_sound_effect(int, int, int, int);
int TBoss6Thanks__sub_8035D270();
f64 atan2_float(f32, f32);
s32 get_nth_view_player_id__11TCameraCtrlFl();
s32 angle_diff_s16(s32, s32);
s32 vec3_add_to(void *, void *);
f32 vec3_dot(void *, void *);
s32 normalize_vector(void *);
extern const f64 lbl_804705E0[];
extern u8 *camera_ctrl_instance;
s32 TBoss6PlotFalz__sub_802AB6CC(void *arg0, f32 r);
void set_visible_flag__14TBoss6PlotFalzFv(void *arg0);

s32 is_local_client_floor_leader();

void TBoss6PlotFalz::set_visible_flag() {
    if (is_local_client_floor_leader() != 0) {
        *(s32 *)((s8 *)this + 0x374) = 0;
        return;
    }
    *(s32 *)((s8 *)this + 0x374) = 1;
}

void TBoss6PlotFalz::spawn_player_hit_effects() {
    Vec_802AB3E0 v;
    Player_802AB3E0 *p;
    s32 i;
    f32 k;
    if (TBoss6Thanks__sub_8035D270() != 0) {
        play_sound_effect(0x40033231, 0, 0, 0);
        k = 12.5f;
        for (i = 0; i < lbl_805D586C; i++) {
            p = get_player_data__10TObjPlayerFi(i);
            if (is_state_1f__14TBoss6PlotFalzFUi(p) != 0) {
                VecCopy((Vec *)(&v), (const Vec *)(&p->pos));
                v.y += k;
                spawn_particle_effect(&v, 0x29);
            }
        }
    }
}

}
struct VBase_802AB490 { char pad[0x18]; };
struct VObj_802AB490 : VBase_802AB490 {
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
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77(void *);
};
struct V3_802AB490 { s32 x, y, z; };
struct Msg_802AB490 { s32 a, b, c; };
extern "C" {
s32 is_split_screen();
extern s32 local_client_id;

void TBoss6PlotFalz::award_exp_and_destroy() {
    u8 *arg0 = (u8 *)this;
    TBoss6PlotFalz::spawn_player_hit_effects();
    if (is_split_screen() != 0) {
        ((TObjEnemy *)arg0)->distribute_experience();
    } else {
        u8 *pl = ((u8 *(*)(s32))get_player_by_client_id)(local_client_id);
        if (pl != NULL) {
            V3_802AB490 saved = *(V3_802AB490 *)(arg0 + 0x2FC);
            VecCopy((Vec *)&this->m_2fc, (const Vec *)(pl + 0x2FC));
            ((TObjEnemy *)arg0)->distribute_experience();
            VecCopy((Vec *)&this->m_2fc, (const Vec *)&saved);
        }
    }
    Msg_802AB490 m;
    m.a = 0x800;
    ((TObjEnemy *)arg0)->send_6x0A_enemy_state(&m);
    ((TObjEnemy *)arg0)->exchange_object_state((s32)&m, (s16)0);
    ((VObj_802AB490 *)arg0)->m77(&m);
    ((TObjEnemy *)arg0)->send_entity_set_flags();
    queue_destruction__7TObjectFv(arg0);
}

void TBoss6PlotFalz::apply_fade_alpha(s32 arg1, f32 farg0) {
    f32 var_f1;
    u8 *temp_r3;
    var_f1 = farg0;
    temp_r3 = this->m_380;
    if ((temp_r3 != NULL) && !(var_f1 <= 0.0f)) {
        if (var_f1 > 1.0f) {
            var_f1 = 1.0f;
        }
        fn_803594B4(temp_r3, arg1, var_f1);
    }
}
f32 sin_table_lookup(s32);
#pragma push
#pragma fp_contract on
s32 TBoss6PlotFalz::rand_vary_count(s32 arg0, f32 farg0) {
    s32 v = (s32)((f32)arg0 * (farg0 * sin_table_lookup((s32)(65535.0f * (3.0517578125e-05f * (f32)rand())))) + (f32)arg0);
    if (v < 1) {
        v = 1;
    }
    return v;
}
#pragma pop
void TBoss6PlotFalz__sub_802AB684(s32 arg0) {
    typedef char sp8_offset[(offsetof(Stack_802AB684, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802AB684, spC) == 0x4) ? 1 : -1];
    Stack_802AB684 stack;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0));
    subtract_vector(&stack.sp8, &lbl_8047059C.value);
    stack.spC = 0.0f;
    vector_length(&stack.sp8);
}
extern "C" {
__declspec(section ".sdata2") const f32 lbl_805DE0A4[1] = { 1e-05f };
}
#define lbl_805DE0A4 (lbl_805DE0A4[0])
#define VLEN(v) (((f32 (*)(void *))vector_length)(v))
s32 TBoss6PlotFalz__sub_802AB6CC(void *arg0, f32 r) {
    Vec_802AB6CC c;
    Vec_802AB6CC pl;
    Vec_802AB6CC p = *(Vec_802AB6CC *)arg0;
    Vec_802AB6CC d1;
    Vec_802AB6CC d2;
    Vec_802AB6CC d3;
    Vec_802AB6CC a;
    Vec_802AB6CC b;
    Vec_802AB6CC dir;
    u8 *player;
    f32 l2;
    f32 l3;
    s32 ang1;
    s32 ang2;
    s32 ang3;
    s32 s1;
    s32 s2;
    p.y = 0.0f;
    TCameraCtrl::get_camera_no();
    player = get_player_by_client_id(get_nth_view_player_id__11TCameraCtrlFl());
    if (player == NULL) {
        return 0;
    }
    VecCopy((Vec *)&pl, (const Vec *)(player + 0x38));
    VecCopy((Vec *)&c, (const Vec *)(camera_ctrl_instance + 0x178));
    VecCopy((Vec *)&d1, (const Vec *)&p);
    subtract_vector(&d1, &pl);
    d1.y = 0.0f;
    if (VLEN(&d1) < r) {
        return 1;
    }
    VecCopy((Vec *)&d2, (const Vec *)&p);
    subtract_vector(&d2, &c);
    d2.y = 0.0f;
    l2 = VLEN(&d2);
    if (l2 < r) {
        return 1;
    }
    if (l2 > 250.0f) {
        return 0;
    }
    VecCopy((Vec *)&d3, (const Vec *)&pl);
    subtract_vector(&d3, &c);
    d3.y = 0.0f;
    l3 = VLEN(&d3);
    if (l3 <= lbl_805DE0A4 || l3 > 250.0f) {
        return 0;
    }
    if (l3 < l2 - r) {
        return 0;
    }
    if (vec3_dot(&d2, &d3) <= 0.0f) {
        return 0;
    }
    dir.x = -d2.z;
    dir.y = 0.0f;
    dir.z = d2.x;
    normalize_vector(&dir);
    dir.x *= r;
    dir.z *= r;
    VecCopy((Vec *)&a, (const Vec *)&p);
    vec3_add_to(&a, &dir);
    VecCopy((Vec *)&b, (const Vec *)&p);
    subtract_vector(&b, &dir);
    ang1 = (s32)(lbl_804705E0[0] * atan2_float(a.x - c.x, a.z - c.z));
    ang2 = (s32)(lbl_804705E0[0] * atan2_float(b.x - c.x, b.z - c.z));
    ang3 = (s32)(lbl_804705E0[0] * atan2_float(pl.x - c.x, pl.z - c.z));
    s1 = angle_diff_s16(ang1, ang3);
    s2 = angle_diff_s16(ang3, ang2);
    if ((s1 >= 0 && s2 >= 0) || (s1 <= 0 && s2 <= 0)) {
        if (l3 < l2 + r) {
            return 0;
        }
        return 1;
    }
    return 0;
}

#undef VLEN
#undef get_player_data__10TObjPlayerFi
#undef is_state_1f__14TBoss6PlotFalzFUi
#undef get_player_by_client_id
#undef lbl_8047059C
f32 cos_table_lookup(s32);

f32 TBoss6PlotFalz::cosine_ease(f32 t) {
    if (t < 0.0f) {
        return 0.0f;
    }
    if (t > 1.0f) {
        return 1.0f;
    }
    return 0.5f * (1.0f - cos_table_lookup((s32)(32768.0f * t)));
}
s32 TBoss6PlotFalz__sub_802ABADC(void);
f32 TBoss6PlotFalz::get_value() {
    if ((TBoss6PlotFalz__sub_802ABADC() == 0) || ((void *) (*(void **)&TBoss6PlotFalz__type1_instance) == NULL)) {
        return 0.0f;
    }
    return *(f32 *)((s8 *)(*(void **)&TBoss6PlotFalz__type1_instance) + 0x3C);
}
s32 TBoss6PlotFalz::is_boss_active() {
    if (((void *) (*(u8 **)&TBoss6PlotFalz__type2_instance) == NULL) || (((TBoss6Type2 *)(*(u8 **)&TBoss6PlotFalz__type2_instance))->get_state() == 0x23)) {
        return 0;
    }
    return 1;
}
s32 TBoss6PlotFalz__sub_802ABADC(void) {
    if (((void *) (*(u8 * *)&(*(void **)&TBoss6PlotFalz__type1_instance)) == NULL) || (((TBoss6GravBall *)(*(u8 * *)&(*(void **)&TBoss6PlotFalz__type1_instance)))->get_state() == 0x28)) {
        return 0;
    }
    return 1;
}

void destroy_static_instance__14TBoss6PlotFalzFv(void);
void queue_instance_destruction__14TBoss6PlotFalzFv(void);

void destroy_static_instance__14TBoss6PlotFalzFv(void) {
    if ((u32) TBoss6PlotFalz__type2_instance != 0U) {
        queue_destruction__7TObjectFv((void*)TBoss6PlotFalz__type2_instance);
        TBoss6PlotFalz__type2_instance = 0U;
    }
}

void queue_instance_destruction__14TBoss6PlotFalzFv(void) {
    if ((u32) TBoss6PlotFalz__type1_instance != 0U) {
        queue_destruction__7TObjectFv((void*)TBoss6PlotFalz__type1_instance);
        TBoss6PlotFalz__type1_instance = 0U;
    }
}

}

#define get_player_data__10TObjPlayerFi ((s32 (*)(s32))get_player_data__10TObjPlayerFi)
#define obj_getField1c ((s16 (*)(s32))obj_getField1c)

struct Stack_802ABCDC {
    s16 spC;
    u8 pad_E[0x4];
    s16 sp12;
    u8 pad_14[0x38];
    u8 sp4C;
};

struct Stack_802ABC64 {
    s16 spC;
    u8 pad_E[0x4];
    s16 sp12;
    s16 sp14;
    u8 pad_16[0x36];
    u8 sp4C;
};

struct RecoveredGlobal_802ABBC4_lbl_804705CC { s32 value; u8 remaining[0x8]; };
typedef char RecoveredGlobal_802ABBC4_lbl_804705CC_size[sizeof(RecoveredGlobal_802ABBC4_lbl_804705CC) == 0xC ? 1 : -1];

struct RecoveredGlobal_802ABC14_lbl_804705C0 { s32 value; u8 remaining[0x8]; };
typedef char RecoveredGlobal_802ABC14_lbl_804705C0_size[sizeof(RecoveredGlobal_802ABC14_lbl_804705C0) == 0xC ? 1 : -1];

extern "C" {
void TBoss4DarkFalz__sub_8004B4F0(void *arg0p, void *arg1p);
u32 create__11TBoss6Type1Fl(void *, int);
u32 create__11TBoss6Type2Fl(void *, int);
extern RecoveredGlobal_802ABBC4_lbl_804705CC lbl_804705CC;
extern RecoveredGlobal_802ABC14_lbl_804705C0 lbl_804705C0;
s32 TBoss6Type1__sub_802ABDEC(s32 seed);
s32 is_locally_controlled__10TObjPlayerFPv(s32);
f32 xyz_distance(void *, void *);
u32 create__10TBoss6TubeFPv();

void TBoss6PlotFalz::release_object() { if (*(unsigned int*)((char*)this + 0x384) != 0) { queue_destruction__7TObjectFv(*(void**)((char*)this + 0x384)); *(int*)((char*)this + 0x384) = 0; } }

s32 TBoss6PlotFalz::get_target_pos_a(s32 arg0, s32 arg1) {
    if ((u32) TBoss6PlotFalz__type2_instance == 0U) {
        VecCopy((Vec *)(arg1), (const Vec *)(&lbl_804705CC.value));
        return 0;
    }
    VecCopy((Vec *)(arg1), (const Vec *)(TBoss6PlotFalz__type2_instance + 0x38));
    return 1;
}

s32 TBoss6PlotFalz::get_target_pos_b(s32 arg0, s32 arg1) {
    if ((u32) TBoss6PlotFalz__type1_instance == 0U) {
        VecCopy((Vec *)(arg1), (const Vec *)(&lbl_804705C0.value));
        return 0;
    }
    VecCopy((Vec *)(arg1), (const Vec *)(TBoss6PlotFalz__type1_instance + 0x38));
    return 1;
}

void TBoss6PlotFalz::spawn_type2() {
    u8 *arg0 = (u8 *)this;
    Stack_802ABC64 stack;
    u8 *sp8;
    u16 temp_r4;
    if ((u32) TBoss6PlotFalz__type2_instance == 0U) {
        sp8 = arg0;
        stack.sp4C = this->m_37c;
        TBoss4DarkFalz__sub_8004B4F0((&stack.spC), (arg0 + 0x388));
        stack.sp14 = 1;
        stack.spC = *(s16 *)&this->m_2c + 0x1FF;
        temp_r4 = this->m_1c;
        stack.sp12 = temp_r4 + 0x1FF;
        TBoss6PlotFalz__type2_instance = create__11TBoss6Type2Fl(&sp8, temp_r4);
    }
}

void TBoss6PlotFalz::spawn_type1() {
    u8 *arg0 = (u8 *)this;
    Stack_802ABCDC stack;
    u8 *sp8;
    u16 temp_r4;
    if ((u32) TBoss6PlotFalz__type1_instance == 0U) {
        sp8 = arg0;
        stack.sp4C = this->m_37c;
        TBoss4DarkFalz__sub_8004B4F0((&stack.spC), (arg0 + 0x388));
        stack.spC = *(s16 *)&this->m_2c + 0x200;
        temp_r4 = this->m_1c;
        stack.sp12 = temp_r4 + 0x200;
        TBoss6PlotFalz__type1_instance = create__11TBoss6Type1Fl(&sp8, temp_r4);
    }
}

void TBoss6PlotFalz::ensure_field384() {
    if ((u32) *(u32 *)((s8 *)this + 0x384) == 0U) {
        *(u32 *)((s8 *)this + 0x384) = create__10TBoss6TubeFPv();
    }
}

f32 TBoss6Mine::next_random_float(s32 *arg0) {
    *arg0 = TBoss6Type1__sub_802ABDEC((s32)((void *) (*arg0)));
    return (f32) (*arg0 & 0x7FFF) / 32767.0f;
}

s32 TBoss6Type1__sub_802ABDEC(s32 seed) {
    seed = seed * 0x41C64E6D + 12345;
    seed = seed / 65536;
    seed = seed % 32768;
    return seed & 0x7FFF;
}

void TObjFish::reset_fish_globals() { chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask; chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask; model_render_flags = saved_model_render_flags; }
void TBoss6PlotFalz::apply_radial_effect_to_players(void *pos, s16 amount, s16 kind, f32 range) {
    s32 n;
    s32 i;
    s32 p;
    f32 d;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = get_player_data__10TObjPlayerFi(i);
        if (is_state_1f__14TBoss6PlotFalzFUi(p) != 0 && is_locally_controlled__10TObjPlayerFPv(p) != 0) {
            d = xyz_distance((void *)(p + 0x38), pos);
            if (!(d >= range)) {
                start_pad_rumble_client((s16)((f32)amount * (1.0f - d / range)), kind, (s16)((s32 (*)(s32))obj_getField1c)(p));
            }
        }
    }
}
extern "C" {
__declspec(section ".sdata2") const s32 lbl_805DE0B8[1] = { 0x8829 };
}
#define lbl_805DE0B8 (lbl_805DE0B8[0])
void TBoss6PlotFalz::set_fade_material_color(f32 f) {
    Color_802ABF44 c;
    s32 old = (*(s32 *)&model_render_flags);
    (*(s32 *)&model_render_flags) = old & ~0x10;
    (*(s32 *)&saved_model_render_flags) = old;
    (*(s32 *)&saved_chunk_polygon_flags_and_mask) = (*(s32 *)&chunk_polygon_flags_and_mask);
    (*(s32 *)&saved_chunk_polygon_flags_or_mask) = (*(s32 *)&chunk_polygon_flags_or_mask);
    (*(s32 *)&model_render_flags) |= lbl_805DE0B8;
    set_chunk_material_override_pair(0xFF00, 0x800, (*(s32 *)&chunk_polygon_flags_or_mask), (*(s32 *)&chunk_polygon_flags_and_mask));
    c.a = -1.0f + f;
    c.b = c.c = c.d = 0.0f;
    set_chunk_material_color__13TUnk_80494AE0Fv(&c);
}

}
#undef get_player_data__10TObjPlayerFi
#undef obj_getField1c

#define set_chunk_material_override_pair ((s32 (*)(int, int, int, void *, void *, int))set_chunk_material_override_pair)
#define set_chunk_material_color__13TUnk_80494AE0Fv ((s32 (*)(void *, f32, f32, f32, f32))set_chunk_material_color__13TUnk_80494AE0Fv)

struct Stack_802AC040 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
};

extern "C" {
void TBoss6PlotFalz__sub_802AC008(f32 farg0, f32 farg1);
}
void set_chunk_blend(u32 x);
extern f32 TBoss6PlotFalz__fade_amount;
extern s32 game_difficulty_selection;
extern "C" {
bool is_normal_difficulty(void);
void TBoss6PlotFalz::update_camera_target() {
    if (TBoss6PlotFalz__fade_amount > 0.0f) {
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
    }
    TBoss6PlotFalz__fade_amount = (-1.0f);
}
#pragma push
#pragma fp_contract on
void TBoss6PlotFalz__sub_802AC008(f32 farg0, f32 farg1) {
    f32 temp_f3;
    temp_f3 = 0.25f * farg1;
    TBoss6PlotFalz::apply_fade_material_color(farg0, ((-0.75f) * farg1) + 1.0f, temp_f3, temp_f3);
}
#pragma pop

extern "C" {
__declspec(section ".sdata2") const s32 lbl_805DE0C8[1] = { 0x8810 };
}
#define lbl_805DE0C8 (lbl_805DE0C8[0])
#pragma push
#pragma opt_common_subs off
#pragma opt_dead_assignments off
#pragma fp_contract on
void TBoss6PlotFalz::apply_fade_material_color(f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    typedef char sp8_offset[(offsetof(Stack_802AC040, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802AC040, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_802AC040, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_802AC040, sp14) == 0xC) ? 1 : -1];
    Stack_802AC040 stack;
    f32 temp_f1;
    f32 temp_f2;
    f32 var_f1;
    s32 temp_r5;
    s32 temp_r8;
    var_f1 = farg0;
    if (((-1.0f) != TBoss6PlotFalz__fade_amount) || (var_f1 < 0.0f) || (var_f1 > 1.0f) || (farg1 < 0.0f) || (farg1 > 1.0f) || (farg2 < 0.0f) || (farg2 > 1.0f) || (farg3 < 0.0f) || (farg3 > 1.0f)) {
        var_f1 = 0.0f;
    }
    TBoss6PlotFalz__fade_amount = var_f1;
    if (0.0f != var_f1) {
        temp_r8 = model_render_flags;
        temp_r5 = temp_r8 & 0xFFFFFFDF;
        model_render_flags = temp_r5;
        saved_model_render_flags = temp_r8;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags = temp_r5 | lbl_805DE0C8;
        set_chunk_material_override_pair(0, 0x800, (int)temp_r5, (void *)chunk_polygon_flags_or_mask, (void *)chunk_polygon_flags_and_mask, (int)temp_r8);
        set_chunk_blend(0x2500);
        stack.sp8 = 1.0f;
        temp_f2 = -((TBoss6PlotFalz__fade_amount * (1.0f - farg1)) - 1.0f);
        temp_f1 = -((TBoss6PlotFalz__fade_amount * (1.0f - farg2)) - 1.0f);
        stack.spC = temp_f2;
        stack.sp10 = temp_f1;
        stack.sp14 = -((TBoss6PlotFalz__fade_amount * (1.0f - farg3)) - 1.0f);
        set_chunk_material_color__13TUnk_80494AE0Fv(&stack.sp8, temp_f1, temp_f2, (f32) (1.0f), TBoss6PlotFalz__fade_amount);
    }
}
#pragma pop

bool is_normal_difficulty(void) {
    return game_difficulty_selection == 0;
}

#undef set_chunk_material_override_pair
#undef set_chunk_material_color__13TUnk_80494AE0Fv

int TBoss6PlotFalz::get_phase() {  return plot_falz_phase; }
}

struct Obj_8004AA04 { s32 count; u8 pad[0xC]; void **items; };

union MemberActionStorage_8004B084 { s32 words[3]; void (TBoss4DarkFalz::*action)(); };

struct RecoveredGlobal_8004B084_TBoss4DarkFalz__data_80485108 {
    s32 value;
    u8 remaining[0x33C];
};

union MemberActionStorage_8004B0F8 { s32 words[3]; void (TBoss4DarkFalz::*action)(); };

struct RecoveredGlobal_8004B0F8_TBoss4DarkFalz__data_80485108 {
    s32 value;
    u8 remaining[0x33C];
};

struct Obj_802AC1D8 { s32 count; s32 pad4; s32 x; s32 y; u32 *list; };

typedef struct Rec_8004AA80 {
    s32 a;
    s32 b;
    s32 c;
} Rec_8004AA80;

typedef struct Obj_8004AA80 {
    s32 count;
    u8 pad4[0x8 - 0x4];
    s32 f8;
    s32 fc;
    s32 *items;
} Obj_8004AA80;

struct Vec_802AC3E8 { f32 x, y, z; };

struct Sub_802AC3E8 { u8 pad[0x18]; s32 flags; };

struct Obj_802AC3E8 { u8 pad[0x38]; Vec_802AC3E8 pos; u8 pad2[0xA4 - 0x44]; Sub_802AC3E8 *sub; };

void *destroy_buffer_pair(void *arg0, s16 arg1);
extern "C" {
void mem_free(void *p);
void refresh_players_equipment__14TBoss6PlotFalzFPv(void *self);
void scroll_strip_uvs(u32, s16, s16);
s32 get_bml_model(s32, s32);
s32 alloc_tables__6TLobbyFll(s32, s32, s32);
void *mem_alloc(u32 size);
void build_tables__14TBoss6PlotFalzFPvPvi(Obj_8004AA80 *arg0, Rec_8004AA80 *arg1, s32 arg2);
extern u8 lbl_804705B4[];
extern s32 lbl_805D5868;
extern s32 lbl_805D5870;
void update_active_flag__14TBoss6PlotFalzFv(void);
s32 get_main_phase();

void update_active_flag__14TBoss6PlotFalzFv(void) {
    plot_falz_phase = 0;
    if ((get_main_phase() == 0xF) || (is_split_screen() != 0)) {
        plot_falz_phase = 1;
    }
}

void TBoss6PlotFalz::scroll_strips_uv(s32 dx, s32 dy) {
    Obj_802AC1D8 *o = (Obj_802AC1D8 *)this;
    s32 j;
    s32 i;
    i = 0;
    j = 0;
    o->x += dx;
    o->y += dy;
    for (; i < o->count; i++, j += 4) {
        u32 e = *(u32 *)((u8 *)o->list + j);
        if (e != 0) {
            scroll_strip_uvs(e, o->x, o->y);
        }
    }
}

void TBoss6PlotFalz::free_buffer_pairs() {
    Obj_8004AA04 *self = (Obj_8004AA04 *)this;
    s32 i;
    for (i = 0; i < self->count; i++) {
        if (self->items[i] != 0) {
            destroy_buffer_pair(self->items[i], 1);
            self->items[i] = 0;
        }
    }
    mem_free(self->items);
    self->items = 0;
}
typedef char MemberActionStorage_8004B084_size[sizeof(MemberActionStorage_8004B084) == 12 ? 1 : -1];
typedef char RecoveredGlobal_8004B084_TBoss4DarkFalz__data_80485108_size[sizeof(RecoveredGlobal_8004B084_TBoss4DarkFalz__data_80485108) == 0x340 ? 1 : -1];
typedef char MemberActionStorage_8004B0F8_size[sizeof(MemberActionStorage_8004B0F8) == 12 ? 1 : -1];
typedef char RecoveredGlobal_8004B0F8_TBoss4DarkFalz__data_80485108_size[sizeof(RecoveredGlobal_8004B0F8_TBoss4DarkFalz__data_80485108) == 0x340 ? 1 : -1];

void build_tables__14TBoss6PlotFalzFPvPvi(Obj_8004AA80 *arg0, Rec_8004AA80 *arg1, s32 arg2) {
    s32 h;
    s32 i;
    Rec_8004AA80 *r;
    s32 t;
    s32 p;
    s32 j;
    h = TObjFish::get_fish_count();
    if (h == 0 || arg1 == NULL || arg2 < 1) {
        return;
    }
    arg0->count = arg2;
    arg0->items = NULL;
    arg0->items = (s32 *)mem_alloc(arg0->count * 4);
    arg0->f8 = 0;
    arg0->fc = 0;
    for (j = 0; j < arg0->count; j++) {
        arg0->items[j] = 0;
    }
    for (i = 0; i < arg0->count; i++) {
        r = &arg1[i];
        t = (s32)find_model_node(get_bml_model(h, r->a), r->b);
        p = alloc__23TAdSinglePlyChrSelectGCFv(0x14);
        if (p != 0) {
            p = alloc_tables__6TLobbyFll(p, t, r->c);
        }
        arg0->items[i] = p;
    }
}

void TBoss6PlotFalz::warp_nearby_players() {
    Vec_802AC3E8 v;
    s32 i;
    Obj_802AC3E8 *p;
    for (i = lbl_805D586C + lbl_805D5870; i < lbl_805D5868; i++) {
        p = (Obj_802AC3E8 *)get_player_data__10TObjPlayerFi(i);
        if (p != NULL && p->sub != NULL && (p->sub->flags & 0x20000)
            && !(xyz_distance(lbl_804705B4, &p->pos) > 150.0f)
            && !(xyz_distance(lbl_8047059C, &p->pos) <= 300.0f)) {
            VecCopy((Vec *)&v, (const Vec *)&p->pos);
            subtract_vector(&v, lbl_804705B4);
            vec3_add_to(&v, lbl_8047059C);
            v.y = 7.5f;
            VecCopy((Vec *)&p->pos, (const Vec *)&v);
            ((TUnk_804AF8A0 *)p)->refresh_collision_body_centers();
        }
    }
}

void refresh_players_equipment__14TBoss6PlotFalzFPv(void *self) {
    s32 i;
    void *p;
    for (i = 0; i < lbl_805D586C; i++) {
        p = get_player_data__10TObjPlayerFi(i);
        if (p != 0) {
            if (get_field_3e0__12TBoss3VoloptFv(p) == 0x1f) {
                ((TObjPlayer *)p)->refresh_equipment_slot();
            }
        }
    }
}
}

struct V_802AC538 { f32 x, y, z; };
extern "C" {
u8 *get_hit_data__14TBoss4DarkFalzFv(void *);
void set_position_from__13TUnk_804B9870FPv();
}
void reset_cameras_to_actor(void *, s32);
extern const V_802AC538 lbl_804705A8;

#pragma push
#pragma fp_contract on
void place_players_in_warp_circle(void) {
    s32 step;
    s32 ang = 0;
    s32 i;
    if (lbl_805D586C <= 2) {
        step = 0x2000;
    } else {
        step = 0x2000 / (lbl_805D586C - 1);
    }
    for (i = 0; i < lbl_805D586C; i++) {
        void *p = get_player_data__10TObjPlayerFi(i);
        if (p != NULL && get_field_3e0__12TBoss3VoloptFv(p) == 0x1F) {
            V_802AC538 pos = lbl_804705A8;
            pos.x += 350.0f * sin_table_lookup(ang);
            pos.z += 350.0f * cos_table_lookup(ang);
            ((void (*)(void *, void *))set_position_from__13TUnk_804B9870FPv)(p, &pos);
            ((TBoss4DarkFalz *)p)->save_position();
            *(s32 *)(get_hit_data__14TBoss4DarkFalzFv(p) + 4) = ang + 0x8000;
            ((TObjPlayer *)p)->refresh_equipment_slot();
            if (is_locally_controlled__10TObjPlayerFPv((s32)p) != 0) {
                reset_cameras_to_actor(p, 0);
            }
            ang += step;
        }
    }
}
#pragma pop
void place_players_in_warp_circle(void);
extern "C" {

void TBoss6EmptyWarp::init_warp() { place_players_in_warp_circle(); TBoss6PlotFalz::warp_nearby_players(); }

void release_all_players_control_lock(void);
void end_cutscene_camera__14TBoss6PlotFalzFPv(void *self);
void start_freeze__10TObjPlayerFv();
void TBoss6PlotFalz__sub_802AC724(u8 *arg0, u32 arg1);
void end_cutscene_camera__14TBoss6PlotFalzFPv(void *self) {
    s32 i;
    void *p;
    TWindowCtrl::init_all_slots2();
    for (i = 0; i < lbl_805D586C; i++) {
        p = get_player_data__10TObjPlayerFi(i);
        if (p != 0) {
            ((TObjPlayer *)p)->end_camera_pan();
        }
    }
    release_all_players_control_lock();
}

void TBoss6PlotFalz::freeze_all_players() {
    s32 i;
    TWindowCtrl::init_all_slots();
    for (i = 0; i < lbl_805D586C; i++) {
        if (get_player_data__10TObjPlayerFi(i) != 0) {
            start_freeze__10TObjPlayerFv();
        }
    }
}
void TBoss6PlotFalz__sub_802AC724(u8 *boss4_dark_falz, u32 arg1) {
    if (boss4_dark_falz == NULL || arg1 == 0U) {
        return;
    }
    set_position_from__13TUnk_804B9870FPv();
    ((TBoss4DarkFalz *)boss4_dark_falz)->save_position();
    ((TUnk_804AF8A0 *)boss4_dark_falz)->set_indexed_flags(0, 0x900000);
    *(u32 *)(boss4_dark_falz + 0x30) &= 0xFFFFFFDF;
}
}

#define set_visible_flag__14TBoss6PlotFalzFv ((s32 (*)(void *))set_visible_flag__14TBoss6PlotFalzFv)
#define alloc__23TAdSinglePlyChrSelectGCFv ((int (*)(void *))alloc__23TAdSinglePlyChrSelectGCFv)
#define queue_destruction__7TObjectFv ((s32 (*)(int))queue_destruction__7TObjectFv)
#define destroy_static_instance__14TBoss6PlotFalzFv ((s32 (*)(void *))destroy_static_instance__14TBoss6PlotFalzFv)
#define queue_instance_destruction__14TBoss6PlotFalzFv ((s32 (*)(void *))queue_instance_destruction__14TBoss6PlotFalzFv)
#define refresh_players_equipment__14TBoss6PlotFalzFPv ((s32 (*)())refresh_players_equipment__14TBoss6PlotFalzFPv)
#define end_cutscene_camera__14TBoss6PlotFalzFPv ((s32 (*)())end_cutscene_camera__14TBoss6PlotFalzFPv)
#define update_active_flag__14TBoss6PlotFalzFv ((s32 (*)())update_active_flag__14TBoss6PlotFalzFv)

typedef struct Loc_802AC9EC {
    s32 a;
    s16 b;
    s16 c;
    s32 d;
    s32 e;
} Loc_802AC9EC;

struct RecoveredGlobal_802ACBE4_lbl_804DE200 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_802ACBE4_lbl_804DE200_size[sizeof(RecoveredGlobal_802ACBE4_lbl_804DE200) == 0x10 ? 1 : -1];

struct RecoveredGlobal_802AC904_lbl_804705E8
{
  s32 value;
  u8 remaining[0x5];
};

struct RecoveredGlobal_802AC904___vt__14TBoss6PlotFalz
{
  s32 value;
  u8 remaining[0x14C];
};

struct RecoveredFields_802AC904_arg0
{
  u8 unknown_0[0x18];
  s32 *field_18;
  u8 unknown_1C[0x35C];
  s32 field_378;
  u8 unknown_37C[0x4];
  u32 field_380;
};

struct Msg_802AC7E4 { u8 pad[2]; u16 id; s8 phase; s8 mode; };

struct Boss_802AC7E4 { u8 pad[0x37C]; u8 mode; };

extern "C" {
s32 query_teammate_state__9TObjEneDDFv();
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void fn_802E52AC(void);
void TItemEffOrgaFlowShot__sub_80357210(void);
void TLobby__sub_8036DDE8(void);
extern int obj_fish_count;
s32 restore_player_cameras();
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
void play_area_music(char *name);
volatile int __dl__7TObjectFPv(void *);
s32 is_ending_or_split_screen__14TBoss6PlotFalzFv(void *);
extern RecoveredGlobal_802AC904_lbl_804705E8 lbl_804705E8;
extern RecoveredGlobal_802AC904___vt__14TBoss6PlotFalz __vt__14TBoss6PlotFalz;
extern s32 TBoss6PlotFalz__instance;
u8 *__dt__14TBoss6PlotFalzFv(u8 *arg0, s16 arg1);
u8 *get_enemy_entity(u16 arg0);
void fn_802ACD40();
void handle_6xA3_olga_flow_boss_actions(Msg_802AC7E4 *m);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
s32 __ct__9TObjEnemyFP7TObject();
u16 register_entity_by_id(void *ov);
s32 TBoss6PlotFalz__ct(s32, s32, s32);
void TItemEffOrgaFlowShot__sub_80357204(void);
int TLobby__sub_8001FE7C(void*, void*);
s32 TObjControl__ct(s32, s32);
s32 __nw__7TObjectFUl(s32);

void TBoss6PlotFalz::render() {  }

void TBoss6PlotFalz::run_task() {
    u8 *arg0 = (u8 *)this;
    if (query_teammate_state__9TObjEneDDFv() == 0) {
        set_visible_flag__14TBoss6PlotFalzFv(arg0);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x374) == 0) {
            ((TBoss6PlotFalz *)arg0)->call_state_action();
        }
        ((TBoss6PlotFalz *)arg0)->run_phase_action();
    }
}

void TBoss6PlotFalz::vfunc_63() {  }

typedef struct RecoveredFields_802AC904_arg0 RecoveredFields_802AC904_arg0;
typedef struct RecoveredGlobal_802AC904___vt__14TBoss6PlotFalz RecoveredGlobal_802AC904___vt__14TBoss6PlotFalz;
typedef struct RecoveredGlobal_802AC904_lbl_804705E8 RecoveredGlobal_802AC904_lbl_804705E8;

void handle_6xA3_olga_flow_boss_actions(Msg_802AC7E4 *m) {
    Boss_802AC7E4 *b;
    s8 ph;
    s8 mode;
    fn_802ACD40();
    b = (Boss_802AC7E4 *)get_enemy_entity(m->id);
    if (b != NULL && b == (Boss_802AC7E4 *)TBoss6PlotFalz__instance) {
        ph = m->phase;
        if (ph >= 0 && ph < 9 && ph != ((TObjFish *)b)->get_phase()) {
            ((TBoss6PlotFalz *)b)->set_state(ph);
        }
        mode = m->mode;
        if (mode >= 0) {
            b->mode = mode;
        }
    }
}

struct Msg_802AC86C { u16 h; u16 a; s8 b; s8 c; u8 pad[0x12]; };
struct Boss_802AC86C { u8 pad[0x1C]; u16 f1C; u8 pad2[0x374 - 0x1E]; s32 f374; };
void fn_802ACD60(void *);
}
s32 create_boss4_fade();
extern s32 lbl_805D3E50;
void build_6xA3_olga_flow_boss_actions(void *);
extern "C" {

void TBoss6PlotFalz::send_6xA3_action(s8 v) {
    Boss_802AC86C *o = (Boss_802AC86C *)this;
    Msg_802AC86C m;
    if (o->f374 == 0) {
        build_6xA3_olga_flow_boss_actions(&m);
        m.a = o->f1C;
        m.b = v;
        m.c = (s8)(127.0f * (3.0517578125e-05f * (f32)rand()));
        fn_802ACD60(&m);
    }
}

u8 *__dt__14TBoss6PlotFalzFv(u8 *arg0, s16 arg1) {
  s32 *new_var;
  s32 temp_r0;
  if (arg0 != 0)
  {
    u32 temp_r3;
    ((RecoveredFields_802AC904_arg0 *) arg0)->field_18 = &__vt__14TBoss6PlotFalz.value;
    temp_r0 = ((RecoveredFields_802AC904_arg0 *) arg0)->field_378;
    new_var = &((RecoveredFields_802AC904_arg0 *) arg0)->field_378;
    if (temp_r0 < 9)
    {
      if (temp_r0 < 7)
      {
        if (1)
        {
          if (((!temp_r0) && (!temp_r0)) && (!temp_r0))
          {
          }
        }
      }
      else
      {
        ((TObjEnemy *)arg0)->send_entity_set_flags();
      }
    }
    if (is_ending_or_split_screen__14TBoss6PlotFalzFv((void *) arg0) == 0)
    {
      TLobby::stop_audio_streams();
      if (((s32) (*new_var)) == 7)
      {
        play_area_music((char *)(&lbl_804705E8.value));
      }
    }
    temp_r3 = ((RecoveredFields_802AC904_arg0 *) arg0)->field_380;
    if (temp_r3 != 0U)
    {
      queue_destruction__7TObjectFv((int) temp_r3);
      ((RecoveredFields_802AC904_arg0 *) arg0)->field_380 = 0U;
    }
    end_cutscene_camera__14TBoss6PlotFalzFPv();
    refresh_players_equipment__14TBoss6PlotFalzFPv();
    restore_player_cameras();
    queue_instance_destruction__14TBoss6PlotFalzFv((void *) arg0);
    destroy_static_instance__14TBoss6PlotFalzFv((void *) arg0);
    TBoss6PlotFalz__instance = 0;
    TBoss6PlotFalz__fade_amount = (-1.0f);
    __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
    if (arg1 > 0)
    {
      __dl__7TObjectFPv((void *) arg0);
    }
  }
  return arg0;
}

#define arg0 ((u8 *)self)
#pragma push
#pragma opt_common_subs off
s32 TBoss6PlotFalz__ct(s32 self, s32 arg1, s32 arg2) {
    Loc_802AC9EC sp8;
    s32 temp_r30;
    s32 temp_r29;
    s32 temp_r6;

    __ct__9TObjEnemyFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__14TBoss6PlotFalz.value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D3E50;
    ((TBoss6PlotFalz *)arg0)->sub_802AAC98();
    TBoss6PlotFalz__instance = self;
    ((TBoss6PlotFalz *)(arg0))->apply_set_data((void *)arg2);
    TBoss4DarkFalz__sub_8004B4F0((arg0 + 0x388), (void *)arg2);
    ((TBoss6PlotFalz *)arg0)->m_38a = 0;
    if (((TObjEnemy *)arg0)->exchange_object_state((s32)&sp8, (s16)(1)) != 0) {
        sp8.a = 0;
        sp8.c = 0;
        ((TObjEnemy *)arg0)->exchange_object_state((s32)&sp8, (s16)(0));
    }
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(VecCopy((Vec *)(arg0 + 0x50), (const Vec *)(VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38))))));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    ((TBoss6PlotFalz *)arg0)->m_310 = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0x30C) = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0x308) = (f32) 0.0f;
    *(s32 *)((s8 *)arg0 + 0x2A8) = 0;
    temp_r30 = register_boss__6TLobbyFl(0x2C);
    temp_r29 = dispatch_shared_handler_b__6TLobbyFl(0x2C);
    temp_r6 = register_object__6TLobbyFl(0x2C);
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)temp_r30, (u8 *)temp_r29, (u8 *)temp_r6);
    register_entity_by_id((arg0));
    ((TBoss6PlotFalz *)arg0)->actorFlags = (s32) (((TBoss6PlotFalz *)arg0)->actorFlags | 0x02000000);
    set_visible_flag__14TBoss6PlotFalzFv(arg0);
    update_active_flag__14TBoss6PlotFalzFv();
    *(s32 *)((s8 *)arg0 + 0x3CC) = 0;
    *(s32 *)((s8 *)arg0 + 0x3D0) = 0;
    *(s32 *)((s8 *)arg0 + 0x3D4) = 0;
    *(s32 *)((s8 *)arg0 + 0x3D8) = 0;
    *(s32 *)((s8 *)arg0 + 0x380) = create_boss4_fade();
    *(s32 *)((s8 *)arg0 + 0x384) = 0;
    ((TBoss6PlotFalz *)arg0)->ensure_field384();
    (*(s32 *)&TBoss6PlotFalz__type1_instance) = 0;
    (*(s32 *)&TBoss6PlotFalz__type2_instance) = 0;
    *(s32 *)((s8 *)arg0 + 0x3DC) = 0;
    TBoss6PlotFalz__fade_amount = (-1.0f);
    ((TBoss6PlotFalz *)arg0)->m_37c = 0;
    ((TBoss6PlotFalz *)arg0)->m_378 = -1;
    ((TBoss6PlotFalz *)arg0)->set_state(0);
    return self;
}
#pragma pop
#undef arg0

void TBoss6PlotFalz::free_all() { TBoss4DarkFalz::free_global_instance(); TBoss6Tube::free_resources(); TBoss6Rock::free_data(); TItemEffOrgaFlowShot__sub_80357204(); TLobby__sub_8001FE7C((void*)obj_fish_count, (void*)1); obj_fish_count = 0; }

extern s32 tl_04;

void TBoss6PlotFalz::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = alloc__23TAdSinglePlyChrSelectGCFv((void *)0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &boss6_plot_falz_resource_descriptor, 0, 0, 0));
    }
    (*(u8 * *)&obj_fish_count) = (unsigned char *) ((void *) var_r0);
    if ((u32) var_r0 != 0U) {
        TLobby__sub_8036DDE8();
        TItemEffOrgaFlowShot__sub_80357210();
        TBoss6Rock::load_resources();
        TBoss6Tube::load_resources();
        fn_802E52AC();
    }
}

s32 TBoss6PlotFalz::create(s32 arg0) {
    s32 var_r31;
    s32 var_r4;

    var_r31 = __nw__7TObjectFUl(0x3E0);
    if (var_r31 != 0) {
        var_r4 = __nw__7TObjectFUl(0x20);
        if (var_r4 != 0) {
            var_r4 = TObjControl__ct(var_r4, tl_04);
        }
        var_r31 = TBoss6PlotFalz__ct(var_r31, var_r4, arg0);
    }
    return var_r31;
}

s32 TObjFish::get_phase() { return *(s32*)((char*)this + 0x378); }

int TObjFish::get_fish_count() {  return obj_fish_count; }

__declspec(section ".data") const char *boss06_plotfalz_dat_model_names[15] = { lbl_8046FDB8, lbl_8046FDC8, lbl_8046FDDC, lbl_8046FDF4, lbl_8046FE08, lbl_8046FE1C, lbl_8046FE34, lbl_8046FE48, lbl_8046FE58, lbl_8046FE6C, lbl_8046FE7C, lbl_8046FE94, lbl_8046FEA8, lbl_8046FEB8, NULL };
__declspec(section ".data") const char *boss06_plotfalz_dat_motion_names[63] = { lbl_8046FED0, lbl_8046FEF0, lbl_8046FF0C, lbl_8046FF28, lbl_8046FF40, lbl_8046FF5C, lbl_8046FF78, lbl_8046FF94, lbl_8046FFB0, lbl_8046FFC4, lbl_8046FFDC, lbl_8046FFF4, lbl_8047000C, lbl_80470028, lbl_80470044, lbl_80470060, lbl_80470078, lbl_80470094, lbl_804700B0, lbl_804700CC, lbl_804700E8, lbl_80470104, lbl_80470120, lbl_8047013C, lbl_8047015C, lbl_80470178, lbl_80470194, lbl_804701B0, lbl_804701CC, lbl_804701E8, lbl_80470204, lbl_80470220, lbl_80470238, lbl_80470250, lbl_80470268, lbl_8047027C, lbl_80470294, lbl_804702AC, lbl_804702C8, lbl_804702E4, lbl_80470300, lbl_80470320, lbl_80470340, lbl_8047035C, lbl_80470378, lbl_80470394, lbl_804703B0, lbl_804703CC, lbl_804703E8, lbl_80470404, lbl_8047041C, lbl_80470438, lbl_80470454, lbl_80470470, lbl_80470490, lbl_804704A8, lbl_804704C4, lbl_804704E4, lbl_80470504, lbl_80470520, lbl_8047053C, lbl_8047055C, NULL };
}
BmlResourceDescriptor boss6_plot_falz_resource_descriptor = { lbl_80470574, boss06_plotfalz_dat_model_names, boss06_plotfalz_dat_motion_names, 14, 62 };
