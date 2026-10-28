#include "pso/boss/TBoss4Zako.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/misc/TLobby.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/boss/TBoss4Type3.h"
#include "pso/player/TObjChara.h"
#pragma defer_codegen on
#pragma push
#pragma dont_inline off
#pragma auto_inline off
#pragma inline_depth(2)
struct DamageRecipientTaskHeaderABI { u8 pad[0x18]; };

struct DamageRecipientABI : DamageRecipientTaskHeaderABI {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual f32 receive_direct_attack(void *source, DirectAttackPayload payload,
        void *collider, s32 technique, s32 flags);
};

#pragma pop
extern "C" const f32 lbl_805D8D10;
extern "C" {

#include "types.h"

struct V_8005BB5C { f32 x, y, z; };

struct Obj_8005BB5C { u8 pad[0x38]; V_8005BB5C pos; V_8005BB5C prev; u8 pad50[0x37C - 0x50]; s32 f37c; };

struct V_8005BF68 { f32 x, y, z; };

struct V2_8005BF68 { f32 x, z; };

struct Ctl_8005BF68 { u8 pad[0x18]; u32 flags; };

struct Obj_8005BF68 {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    u16 pad1c;
    u16 f1c_unused;
    u8 pad20[0x18];
    V_8005BF68 pos;
    u8 pad44[0x374 - 0x44];
    s32 f374;
    u8 pad378[4];
    s32 f37c;
    u8 pad380[4];
    Ctl_8005BF68 *ctl;
    u8 pad388[4];
    V_8005BF68 vel;
    f32 f398;
    u8 pad39c[4];
    f32 f3a0;
};

struct V_8005C218 { f32 x, y, z; };

struct Obj_8005C218 {
    u8 pad0[0x1C];
    u16 f1c;
    u8 pad1e[0x1A];
    V_8005C218 pos;
    u8 pad44[0x388 - 0x44];
    s32 f388;
    V_8005C218 vel;
    f32 f398;
    u8 pad39c[4];
    f32 f3a0;
    u8 pad3a4[0x3C4 - 0x3A4];
    V_8005C218 home;
};

struct Vec_8005BC4C { f32 x, y, z; };

struct TBoss4Bishi {
    u8 pad0[0x38];
    Vec_8005BC4C pos;
    u8 pad44[0x5C - 0x44];
    s32 f5C;
    s32 f60;
    u8 pad64[0x2FC - 0x64];
    u8 f2FC[0x374 - 0x2FC];
    s32 f374;
    void *f378;
    u8 pad37C[0x3B4 - 0x37C];
    void *f3B4;
    s32 f3B8;
    s32 f3BC;
    s32 f3C0;

    void vt0();
    void vt1();
    void vt2();
};

typedef void (TBoss4Bishi::*Act_8005BC4C)();

void vec3_add_to(void *, void *);
extern const f32 lbl_805D8CBC;
extern const f32 lbl_805D8CC8;
extern const f32 lbl_805D8CE4;
void vt6__9TBoss4UroFv(u8 *arg0);
void queue_destruction__7TObjectFv(void *arg0);
void *spawn_particle_effect(void *pos, s32 id);
extern const f32 lbl_805D8CB8;
extern const f32 lbl_805D8CC0;
void vt2__11TBoss4BishiFv(u8 *arg0);
void vt5__9TBoss4UroFv(u8 *arg0);
f32 calc_boss4_scale__10TObjPlayerFi(s32 arg0);

s32 get_instance__14TBoss4DarkFalzFv();
s32 get_position_ptr__10TObjPlayerFv(s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern const f32 lbl_805D8CF4;
extern const f32 lbl_805D8CF8;
extern const f32 lbl_805D8CFC;

void enter_state_3__11TBoss4BishiFPv(void* p);
f32 vector_length(void *);
extern const f32 lbl_805D8CC4;
void vt1__11TBoss4BishiFv(Obj_8005BB5C *self);

s32 TBoss4Zako__ct(s32, s32, s32);

void normalize_vector(void *);
extern V2_8005BF68 TBoss4Bishi_spawn_offsets[];
extern s32 __vt__11TBoss4Bishi[];
extern s32 lbl_805D27F0;
extern const f32 lbl_805D8CDC;
extern const f32 lbl_805D8CE0;
s32 TBoss4Bishi__ct(s32 arg0, s32 arg1, s32 arg2);

struct Obj_8005C6E4;
void clamp_min_player_distance__9TBoss4UroFPv(Obj_8005C6E4 *arg0);

extern const f32 lbl_805D8CE8;
extern const f32 lbl_805D8CEC;
extern const f32 lbl_805D8CF0;
s32 get_phase__9TBoss4UroFv(void *);

void submit_cursor_candidate(void *, s32);
void minimap_render_dot(void *, s32, s32, s32);
extern const f32 lbl_805D8CD0;
extern const f32 TBoss4Zako__data_805D8CD4;
extern const f32 lbl_805D8CD8;
struct VOff_8005C450_arg0_8005BABC { char pad_0[0x38]; char f_38[1]; };
void vt0__11TBoss4BishiFv(u8 *arg0);
void vt4__9TBoss4UroFv(void *arg0);
void *__dt_deleting__11TBoss4BishiFPvs(void *arg0, s16 arg1);
s32 create__11TBoss4BishiFi(s32 arg0);
void try_enter_state_3__11TBoss4BishiFPv(void* p);

s32 TObjControl__ct(s32, s32);

s32 __nw__7TObjectFUl(s32);

extern const f32 lbl_805D8CCC;
u32 TBoss4Zako_collision_body_parts[11] = {
 0, 0x40f00000, 0, 0x40a00000, 0, 0, 0x807a, 0, 0, 0, 0,
};

extern s32 tl_04;

struct Vec_8005C6E4 { f32 x, y, z; };

struct Obj_8005C6E4 {
    u8 pad0[0x38];
    Vec_8005C6E4 pos;
    u8 pad44[0x378 - 0x44];
    void *f378;
};

struct Vec_8005C858 { f32 x, y, z; };

struct Ctl_8005C858 {
    u8 pad0[0x18];
    s32 flags;
};

struct Obj_8005C858 {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    u8 pad1c[0x38 - 0x1c];
    Vec_8005C858 pos;
    u8 pad44[0x374 - 0x44];
    s32 f374;
    u8 pad378[0x384 - 0x378];
    Ctl_8005C858 *f384;
    s32 f388;
    Vec_8005C858 dir;
    f32 f398;
    u8 pad39c[0x3c4 - 0x39c];
    f32 f3c4;
    f32 f3c8;
    f32 f3cc;
};

extern const f32 lbl_805D8D00;
extern s32 __vt__9TBoss4Uro[];
extern s32 lbl_805D27EC;
extern const f32 lbl_805D8D04;
extern const f32 lbl_805D8D08;
s32 TBoss4Uro__ct(s32 a0, s32 a1, s32 a2);
void TBoss4Uro__vt61(void* p);
void *__dt__9TBoss4UroFv(void *arg0, s16 arg1);
s32 create__9TBoss4UroFi(s32 arg0);

struct Vec_8005C49C { f32 x, y, z; };

struct TBoss4Uro {
    u8 pad0[0x38];
    Vec_8005C49C pos;
    u8 pad44[0x5C - 0x44];
    s32 f5C;
    s32 f60;
    u8 pad64[0x2FC - 0x64];
    u8 f2FC[0x374 - 0x2FC];
    s32 f374;
    void *f378;
    u8 pad37C[0x3B4 - 0x37C];
    void *f3B4;
    s32 f3B8;
    s32 f3BC;
    s32 f3C0;

    void vt4();
    void vt5();
    void vt6();
};

typedef void (TBoss4Uro::*Act_8005C49C)();

void run_task__9TBoss4UroFv(TBoss4Uro *self);
void TBoss4Zako__sub_8005BC4C(TBoss4Bishi *self);

struct V_8005CBA4 { f32 x, y, z; };

struct Pl_8005CBA4 { u8 pad0[0x38]; V_8005CBA4 pos; };

extern const f32 lbl_805D8D0C;
extern const f32 lbl_805D8D14;

extern const f32 lbl_805D8D18;
extern const f32 lbl_805D8D1C;
extern const f32 TBoss4Zako_movement_speed_step;

extern const f32 TBoss4Zako_one_third;
void render__9TBoss4UroFv(void);

#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
extern "C" TObjEnemy *__ct__9TObjEnemyFP7TObject(void *, void *);

struct O_8005D6B0 { u8 pad[0x374]; s32 f374; };

f32 *dispatch_shared_handler_a__6TLobbyFl(s32);
s32 get_instance_count__9TBoss4UroFv();

void *create_particle_emitter(void *pos, s32 id);
s32 init_collision_body_parts(void *, void *, int);
extern u32 TBoss4Zako_collision_body_parts[];
extern s32 __vt__10TBoss4Zako[];
extern s32 lbl_805D27E8;
extern const f32 lbl_805D8D30;
extern const f32 lbl_805D8D34;
extern const f32 lbl_805D8D38;
extern const f32 lbl_805D8D3C;
extern const f32 lbl_805D8D40;
extern const f32 lbl_805D8D44;
s32 TBoss4Zako__ct(s32 arg0, s32 arg1, s32 arg2);

void update_state3__10TBoss4ZakoFPv(void* p);
s32 free_collision_body_parts(void *);

void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);

#define THIS self

void add_radar_scaled_marker(void *, s32, s32, s32, f32);
extern const f32 lbl_805D8CD0, lbl_805D8CD8, lbl_805D8CE0, lbl_805D8D28, lbl_805D8D2C;

u8 *VecCopy__FP3VecPC3Vec(void *, void *);
void *get_player_by_client_id(s32);
void TBoss4Uro__sub_8005D6D4(void *arg0);
void fn_8005D6E4(void *arg0);
void *__dt__10TBoss4ZakoFv(void *, s16);
void subtract_vector(void *, void *);
u16 find_nearest_visible_player(void *, s32, f32);
void __dl__7TObjectFPv(void *);
#pragma push
void fn_8005D6E4(void *arg0) {
    *(s32 *)((s8 *)arg0 + 0x388) = (s32) (*(s32 *)((s8 *)arg0 + 0x388) + 1);
}
#pragma pop
#pragma push
void TBoss4Uro__sub_8005D6D4(void *arg0) {
    *(s32 *)((s8 *)arg0 + 0x38C) = (s32) (*(s32 *)((s8 *)arg0 + 0x38C) + 1);
}
#pragma pop
#pragma push
s32 TBoss4Zako::sub_8005D6B0() {
    O_8005D6B0 *self = (O_8005D6B0 *)this;
    return self->f374 == 1 || self->f374 == 2;
}
#pragma pop
#pragma push
s32 TBoss4Zako::sub_8005D698() {
    return (u8) (*(s32 *)((s8 *)this + 0x374) != 3);
}
#pragma pop
#pragma push
s32 TBoss4Zako::create(s32 arg0) {
    s32 var_r31;
    s32 parent;

    var_r31 = __nw__7TObjectFUl(0x3C4);
    if (var_r31 != 0) {
        parent = __nw__7TObjectFUl(0x20);
        if (parent != 0) {
            parent = TObjControl__ct(parent, tl_04);
        }
        var_r31 = TBoss4Zako__ct(var_r31, parent, arg0);
    }
    return var_r31;
}
#pragma pop
#pragma push
#pragma fp_contract on
s32 TBoss4Zako__ct(s32 arg0, s32 parent, s32 arg2) {
    u8 *self;
    self = (u8 *)arg0;
    __ct__9TObjEnemyFP7TObject((TObjEnemy *)arg0, (void*)parent);
    *(s32 **)((s8 *)THIS + 0x18) = __vt__10TBoss4Zako;
    *(s32 *)((s8 *)THIS + 0) = lbl_805D27E8;
    ((TObjChara *)THIS)->add_flags_2e4(8);
    *(s32 *)((s8 *)THIS + 0x378) = ((s32 *)arg2)[0];
    fn_8005D6E4((u8 *)*(s32 *)((s8 *)THIS + 0x378));
    ((TBoss3Volopt *)THIS)->apply_set_data((s32 *)arg2 + 1);
    ((TBoss3Volopt *)THIS)->clear_lobby_object_state();
    *(s32 *)((s8 *)THIS + 0x380) = get_instance_count__9TBoss4UroFv();
    *(s32 *)((s8 *)THIS + 0x24) = 0;
    *(s32 *)((s8 *)THIS + 0x34) = 0;
    VecCopy__FP3VecPC3Vec(THIS + 0x44, VecCopy__FP3VecPC3Vec(THIS + 0x50, VecCopy__FP3VecPC3Vec(THIS + 0x74, THIS + 0x38)));
    *(s32 *)((s8 *)THIS + 0x384) = init_collision_body_parts(THIS, TBoss4Zako_collision_body_parts, 1);
    VecCopy__FP3VecPC3Vec(THIS + 0x2FC, THIS + 0x38);
    *(f32 *)((s8 *)THIS + 0x310) = lbl_805D8CBC;
    *(f32 *)((s8 *)THIS + 0x30C) = lbl_805D8CBC;
    *(f32 *)((s8 *)THIS + 0x308) = lbl_805D8CBC;
    *(s32 *)((s8 *)THIS + 0x2A8) = 0;
    ((TObjEnemy *)THIS)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(0x35)), (u8 *)(TLobby::dispatch_shared_handler_b(0x35)), (u8 *)(TLobby::register_object(0x35)));
    *(s16 *)((s8 *)THIS + 0x33E) = *(s16 *)((s8 *)THIS + 0x32C);
    ((TBoss3Volopt *)THIS)->reset_photon_effect();
    ((TObjEnemy *)THIS)->set_param(0);
    *(s32 *)((s8 *)THIS + 0x388) = 0;
    if ((*(u32 *)((s8 *)THIS + 0x3B4) = (u32)create_particle_emitter(THIS + 0x38, 0x103)) != 0) {
        ((TBoss4Type2 *)(*(u32 *)((s8 *)THIS + 0x3B4)))->set_flags(0x40);
    }
    *(f32 *)((s8 *)THIS + 0x398) = lbl_805D8CBC;
    *(f32 *)((s8 *)THIS + 0x394) = lbl_805D8CBC;
    *(f32 *)((s8 *)THIS + 0x390) = lbl_805D8CBC;
    *(f32 *)((s8 *)THIS + 0x38C) = lbl_805D8CBC;
    *(s32 *)((s8 *)THIS + 0x3A4) = TBoss4Zako__data_805D8CD4 * (*(u16 *)((s8 *)THIS + 0x1C) & 3);
    *(s32 *)((s8 *)THIS + 0x5C) = 0;
    *(s32 *)((s8 *)THIS + 0x60) = *(u16 *)((s8 *)THIS + 0x1C) << 14;
    *(s32 *)((s8 *)THIS + 0x3B8) = 0;
    *(s32 *)((s8 *)THIS + 0x3A8) = 0;
    *(s32 *)((s8 *)THIS + 0x3AC) = (*(u16 *)((s8 *)THIS + 0x1C) % 6 + 1) * 450;
    *(f32 *)((s8 *)THIS + 0x3B0) = lbl_805D8CBC;
    *(s32 *)((s8 *)THIS + 0x3BC) = lbl_805D8CF8 * calc_boss4_scale__10TObjPlayerFi((s32)THIS);
    *(s32 *)((s8 *)THIS + 0x3C0) = lbl_805D8D34 * calc_boss4_scale__10TObjPlayerFi((s32)THIS) + lbl_805D8D30;
    *(f32 *)((s8 *)THIS + 0x39C) = *dispatch_shared_handler_a__6TLobbyFl(0x35);
    if (*(f32 *)((s8 *)THIS + 0x39C) <= TBoss4Zako_one_third || *(f32 *)((s8 *)THIS + 0x39C) > lbl_805D8D38) {
        *(f32 *)((s8 *)THIS + 0x39C) = lbl_805D8D3C;
    }
    *(f32 *)((s8 *)THIS + 0x3A0) = *dispatch_shared_handler_a__6TLobbyFl(0x39);
    if (*(f32 *)((s8 *)THIS + 0x3A0) <= TBoss4Zako_one_third || *(f32 *)((s8 *)THIS + 0x3A0) > lbl_805D8D40) {
        *(f32 *)((s8 *)THIS + 0x3A0) = lbl_805D8D44;
    }
    *(s32 *)((s8 *)THIS + 0x374) = 0;
    return arg0;
}
#pragma pop
#pragma push
void *__dt__10TBoss4ZakoFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__10TBoss4Zako;
        free_collision_body_parts(arg0);
        *(s32 *)((s8 *)arg0 + 0x384) = 0;
        if ((u32) *(u32 *)((s8 *)arg0 + 0x3B4) != 0U) {
            TBoss4Type2::request_destroy((u32)(*(void **)((s8 *)arg0 + 0x3B4)));
            *(u32 *)((s8 *)arg0 + 0x3B4) = 0U;
        }
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma pop
#pragma push
void update_state3__10TBoss4ZakoFPv(void* p) { if (*(int*)((char*)p + 0x374) != 3) { ((TBoss4Zako *)p)->set_state3(); } }
#pragma pop
}

#pragma push
#pragma fp_contract on
void TBoss4Zako::run_task() {
    TBoss4Zako *self = this;
    void (TBoss4Zako::*fn)();

    if (((TBoss4Zako *)self)->sub_8005D698() != 0 && get_phase__9TBoss4UroFv(self->m_378) != 4) {
        ((TBoss4Zako *)self)->set_state3();
    }
    if (((TBoss4Zako *)self)->sub_8005D6B0() != 0) {
        self->m_3ac--;
        if (self->m_3ac < 0) {
            self->m_3a8 = 0;
            self->m_3ac = 2700;
        } else if (self->m_3ac < 450) {
            self->m_3a8 = 1;
        }
    }
    {
        static void (TBoss4Zako::*tbl[5])() = {
            &TBoss4Zako::update_rise_state, &TBoss4Zako::update_move_to_target_state, &TBoss4Zako::update_surround_player_state, &TBoss4Zako::update_sink_state,
        };
        fn = tbl[self->m_374];
    }
    if (fn) {
        (self->*fn)();
        if (self->m_374 == 1 || self->m_374 == 2) {
            self->m_38.y = lbl_805D8CD0 * sin_table_lookup(self->m_3bc) + self->m_38.y;
            self->m_3bc += self->m_3c0;
        }
        if (self->m_3b4 != NULL) {
            TBoss4ZakoVec3 p = self->m_38;
            if (self->m_3a8 != 0) {
                p.y += TBoss4Zako__data_805D8CD4;
            } else {
                p.y += lbl_805D8CD8;
            }
            ((TNowLoading *)(self->m_3b4))->copy_pos(&p);
        }
        self->m_3b0 = lbl_805D8CBC;
        if (self->m_3a8 != 0) {
            if (self->m_3ac < 30) {
                self->m_3b0 = (f32)self->m_3ac / lbl_805D8D28;
            } else {
                self->m_3b0 = lbl_805D8CE0;
            }
        } else if (self->m_3ac < 480) {
            self->m_3b0 = (f32)(480 - self->m_3ac) / lbl_805D8D28;
        }
        if (((TBoss4Zako *)self)->sub_8005D6B0() != 0 && self->m_3b0 > lbl_805D8CBC) {
            self->m_60 = lbl_805D8D2C * self->m_3b0 + self->m_60;
        }
        ((TBoss4Zako *)self)->apply_contact_damage();
        ((TObjEnemy *)self)->update_prev_position();
        TBoss4Zako::queue_entry(&self->m_38, self->m_5c, self->m_60);
        if (((TBoss4Zako *)self)->sub_8005D698() != 0) {
            if (self->m_3a8 != 0) {
                self->m_384->flags |= 1;
                ((TObjPlayer *)self)->update_collisions();
                submit_cursor_candidate(self, -1);
                minimap_render_dot(self->m_2fc, -0x5DB4, 1, 0);
            } else {
                self->m_384->flags &= ~1;
                add_radar_scaled_marker(self->m_2fc, 0xFF7F5126, 1, 1, lbl_805D8CE0);
            }
        }
        self->m_3b8++;
    }
}
#pragma pop

extern "C" {
#pragma push
void render__9TBoss4UroFv(void) {  }
#pragma pop
}

#pragma push
void TBoss4Zako::update_rise_state() {
    f32 temp_f0;
    f32 temp_f2;

    VecCopy__FP3VecPC3Vec(&m_44, &m_38);
    temp_f2 = m_38.y;
    if (temp_f2 < lbl_805D8CC8) {
        temp_f0 = temp_f2 + TBoss4Zako_one_third;
        m_38.y = temp_f0;
        if (temp_f0 > lbl_805D8CC8) {
            m_38.y = (f32) lbl_805D8CC8;
            m_374 = 1;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TBoss4Zako::update_move_to_target_state() {
    TBoss4Zako *o = this;
    TBoss4ZakoVec3 d;
    f32 max_speed;
    f32 dist;
    s32 id;
    f32 t;
    VecCopy__FP3VecPC3Vec(&d, &o->m_50);
    subtract_vector(&d, &o->m_38);
    d.y = lbl_805D8CBC;
    dist = vector_length(&d);
    if (dist < lbl_805D8CE0 && o->m_398 < lbl_805D8CE0) {
        o->m_38.x = o->m_50.x;
        o->m_38.z = o->m_50.z;
        o->m_398 = lbl_805D8CBC;
        o->m_38c.z = lbl_805D8CBC;
        o->m_38c.x = lbl_805D8CBC;
        if (--o->m_3a4 < 0) {
            id = find_nearest_visible_player(o, 0, lbl_805D8D18);
            o->m_388 = id;
            if (id == 0xFFFF) {
                o->m_3a4 = 0x3C;
                return;
            }
            o->m_3a4 = 0xB4;
            o->m_374 = 2;
        }
        return;
    }
    if (dist < lbl_805D8D1C) {
        if ((o->m_398 -= TBoss4Zako_movement_speed_step) < TBoss4Zako_one_third) {
            o->m_398 = TBoss4Zako_one_third;
        }
    } else {
        if ((o->m_398 = o->m_398 + TBoss4Zako_movement_speed_step) > (max_speed = o->m_39c)) {
            o->m_398 = max_speed;
        }
    }
    VecCopy__FP3VecPC3Vec(&o->m_38c, &d);
    if (lbl_805D8CBC != dist) {
        normalize_vector(&o->m_38c);
    }
    o->m_38c.x *= o->m_398;
    o->m_38c.z *= o->m_398;
    vec3_add_to(&o->m_38, &o->m_38c);
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss4Zako::update_surround_player_state() {
#define o this
    Pl_8005CBA4 *pl;
    s32 ang;
    pl = (Pl_8005CBA4 *)get_player_by_client_id(o->m_388);
    if (pl == NULL) {
        o->m_3a4 = 0x3C;
        o->m_374 = 1;
        return;
    }
    TBoss4ZakoVec3 t = *(TBoss4ZakoVec3 *)&pl->pos;
    ang = o->m_1c << 0xD;
    t.x = lbl_805D8D0C * sin_table_lookup(ang) + t.x;
    t.z = lbl_805D8D0C * cos_table_lookup(ang) + t.z;
    if (o->m_38.x < t.x) {
        o->m_38c.x += lbl_805D8D14;
    } else {
        o->m_38c.x -= lbl_805D8D14;
    }
    if (o->m_38.z < t.z) {
        o->m_38c.z += lbl_805D8D14;
    } else {
        o->m_38c.z -= lbl_805D8D14;
    }
    o->m_398 = vector_length(&o->m_38c);
    if (o->m_398 > o->m_39c) {
        normalize_vector(&o->m_38c);
        o->m_38c.x *= o->m_39c;
        o->m_38c.z *= o->m_39c;
        o->m_398 = o->m_39c;
    }
    vec3_add_to(&o->m_38, &o->m_38c);
    if (--o->m_3a4 < 0) {
        o->m_3a4 = 0x3C;
        o->m_374 = 1;
    }
#undef o
}
#pragma pop

#pragma push
void TBoss4Zako::update_sink_state() {
    f32 temp_f1;
    m_38.y = (f32) (m_38.y + lbl_805D8CB8);
    temp_f1 = m_38.y;
    if ((temp_f1 < lbl_805D8CBC) && (temp_f1 >= lbl_805D8CB8)) {
        spawn_particle_effect((&m_38), 0xF3);
    }
    m_5c = (m_5c + 0x111);
    if (m_38.y < lbl_805D8CC0) {
        queue_destruction__7TObjectFv(this);
    }
}
#pragma pop

extern "C" {
#pragma push
void TBoss4Zako::set_state3() {
    TBoss4Uro__sub_8005D6D4(this->m_378);
    *(s32 *)((s8 *)this + 0x3A8) = 0;
    this->m_374 = 3;
}
#pragma pop
}

#pragma push
#pragma dont_inline off
#pragma auto_inline off
#pragma inline_depth(2)
void TBoss4Zako::apply_contact_damage() {
    TBoss4Zako *arg0 = this;
    DirectAttackPayload hit;
    s32 lim;
    s32 n;
    s32 id;
    DamageRecipientABI *p;

    if (arg0->m_398 <= lbl_805D8D10) {
        lim = 16;
    } else {
        lim = (s32)(lbl_805D8D0C / arg0->m_398);
    }
    for (n = 1; n < lim; n *= 2) {
    }
    if (((n - 1) & arg0->m_3b8) != 0 || ((TBoss4Zako *)arg0)->sub_8005D6B0() == 0) {
        return;
    }
    id = find_nearest_visible_player(arg0, 0, lbl_805D8D0C);
    if (id == 0xFFFF || (p = (DamageRecipientABI *)get_player_by_client_id(id)) == 0) {
        return;
    }
    hit.kind = 0;
    hit.power = arg0->m_2c8;
    p->receive_direct_attack(arg0, hit, 0, -1, -1);
}
#pragma pop

extern "C" {
#pragma push
s32 create__9TBoss4UroFi(s32 arg0) {
    s32 var_r31;
    s32 var_r4;

    var_r31 = __nw__7TObjectFUl(0x3D0);
    if (var_r31 != 0) {
        var_r4 = __nw__7TObjectFUl(0x20);
        if (var_r4 != 0) {
            var_r4 = TObjControl__ct(var_r4, tl_04);
        }
        var_r31 = TBoss4Uro__ct(var_r31, var_r4, arg0);
    }
    return var_r31;
}
#pragma pop
#pragma push
#pragma fp_contract on
s32 TBoss4Uro__ct(s32 a0, s32 a1, s32 a2) {
    Obj_8005C858 *o = (Obj_8005C858 *)a0;
    TBoss4Zako__ct(a0, a1, a2);
    o->vt = __vt__9TBoss4Uro;
    o->f0 = lbl_805D27EC;
    o->dir.x = -o->pos.x;
    o->dir.y = lbl_805D8CBC;
    o->dir.z = -o->pos.z;
    if (vector_length(&o->dir) < lbl_805D8D00) {
        o->dir.x = lbl_805D8CE0;
        o->dir.z = lbl_805D8CBC;
    }
    normalize_vector(&o->dir);
    o->f398 = lbl_805D8D08 * calc_boss4_scale__10TObjPlayerFi((s32)o) + lbl_805D8D04;
    o->dir.x = o->dir.x * o->f398;
    o->dir.z = o->dir.z * o->f398;
    o->f388 = 0xFFFF;
    o->f3c4 = lbl_805D8CBC;
    o->f3c8 = lbl_805D8CBC;
    o->f3cc = lbl_805D8CBC;
    o->f374 = 4;
    o->f384->flags |= 1;
    return a0;
}
#pragma pop
#pragma push
void *__dt__9TBoss4UroFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__9TBoss4Uro;
        __dt__10TBoss4ZakoFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma pop
#pragma push
void TBoss4Uro__vt61(void* p) { if (*(int*)((char*)p + 0x374) != 3) { ((TObjEnemy *)p)->distribute_experience(); TBoss4Uro__sub_8005D6D4(*(void**)((char*)p + 0x378)); *(int*)((char*)p + 0x374) = 3; } }
#pragma pop
#pragma push
#pragma fp_contract on
void clamp_min_player_distance__9TBoss4UroFPv(Obj_8005C6E4 *arg0) {
    Vec_8005C6E4 target;
    Vec_8005C6E4 d;
    f32 len;
    if (arg0->f378 == 0) {
        return;
    }
    if (((u32 (*)())get_instance__14TBoss4DarkFalzFv)() == 0) {
        return;
    }
    VecCopy__FP3VecPC3Vec(&target, (void *)((s32 (*)())get_position_ptr__10TObjPlayerFv)());
    VecCopy__FP3VecPC3Vec(&d, &arg0->pos);
    subtract_vector(&d, &target);
    d.y = lbl_805D8CBC;
    len = vector_length(&d);
    if (len >= lbl_805D8CDC) {
        return;
    }
    if (len > lbl_805D8D00) {
        normalize_vector(&d);
    } else {
        d.x = lbl_805D8CE0;
        d.z = lbl_805D8CBC;
    }
    arg0->pos.x = lbl_805D8CDC * d.x + target.x;
    arg0->pos.z = lbl_805D8CDC * d.z + target.z;
}
#pragma pop
#pragma push
#pragma fp_contract on
void run_task__9TBoss4UroFv(TBoss4Uro *self) {
    if (self->f374 != 3 && get_phase__9TBoss4UroFv(self->f378) != 6) {
        TBoss4Uro__sub_8005D6D4(self->f378);
        self->f374 = 3;
        return;
    }
    static Act_8005C49C tbl[5] = {
        0, 0, &TBoss4Uro::vt4, &TBoss4Uro::vt5, &TBoss4Uro::vt6,
    };
    Act_8005C49C a = tbl[self->f374];
    if (a) {
        (self->*a)();
        if (self->f374 == 2) {
            self->pos.y = lbl_805D8CD0 * sin_table_lookup(self->f3BC) + self->pos.y;
            self->f3BC += self->f3C0;
        }
        Vec_8005C49C v = self->pos;
        if (((TBoss4Zako *)self)->sub_8005D698() != 0) {
            v.y += TBoss4Zako__data_805D8CD4;
        } else {
            v.y += lbl_805D8CD8;
        }
        ((TNowLoading *)(self->f3B4))->copy_pos(&v);
        if (((TBoss4Zako *)self)->sub_8005D698() != 0) {
            self->f60 += 0x1111;
        }
        TBoss4Zako::queue_entry(&self->pos, self->f5C, self->f60);
        ((TBoss4Zako *)self)->apply_contact_damage();
        ((TObjEnemy *)self)->update_prev_position();
        if (((TBoss4Zako *)self)->sub_8005D698() != 0) {
            ((TObjPlayer *)self)->update_collisions();
            submit_cursor_candidate(self, -1);
            minimap_render_dot(self->f2FC, -0x5DB4, 1, 0);
        }
        self->f3B8++;
    }
}
#pragma pop
V2_8005BF68 TBoss4Bishi_spawn_offsets[4] = {
    { -4.0f, -4.0f }, { 4.0f, -4.0f }, { -4.0f, 4.0f }, { 4.0f, 4.0f },
};
#pragma push
void vt4__9TBoss4UroFv(void *actor) {
    struct VOff_8005C450_arg0_8005BABC *self = (struct VOff_8005C450_arg0_8005BABC *)actor;
    ((TBoss4Zako *)actor)->update_target_position();
    ((TBoss4Zako *)actor)->update_orbit_velocity();
    VecCopy__FP3VecPC3Vec((void *)((void *)((char *)actor + 68)), self->f_38);
    vec3_add_to(self->f_38, (void *)((char *)actor + 908));
}
#pragma pop
#pragma push
#pragma fp_contract on
void TBoss4Zako::update_target_position() {
    s32 temp_r31;
    s32 temp_r3;
    u8 *actor = (u8 *)this;
    if (!(*(s32 *)((s8 *)actor + 0x3B8) & 0x7F)) {
        if (*(s32 *)((s8 *)actor + 0x388) == 0xFFFF) {
            *(u32 *)((s8 *)actor + 0x388) = (u32) find_nearest_visible_player(actor, 0, lbl_805D8CF4);
            return;
        }
        *(u32 *)((s8 *)actor + 0x388) = 0xFFFFU;
        if ((u32) *(u32 *)((s8 *)actor + 0x378) != 0U) {
            temp_r3 = get_instance__14TBoss4DarkFalzFv();
            if (temp_r3 != 0) {
                temp_r31 = (s32) (lbl_805D8CF8 * calc_boss4_scale__10TObjPlayerFi((s32)actor));
                VecCopy__FP3VecPC3Vec(actor + 0x3C4, (void *)(get_position_ptr__10TObjPlayerFv(temp_r3)));
                *(f32 *)((s8 *)actor + 0x3C8) = (f32) lbl_805D8CBC;
                *(f32 *)((s8 *)actor + 0x3C4) = (f32) ((lbl_805D8CFC * sin_table_lookup(temp_r31)) + *(f32 *)((s8 *)actor + 0x3C4));
                *(f32 *)((s8 *)actor + 0x3CC) = (f32) ((lbl_805D8CFC * cos_table_lookup(temp_r31)) + *(f32 *)((s8 *)actor + 0x3CC));
            }
        }
    }
}
#pragma pop
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss4Zako::update_orbit_velocity() {
#define o ((Obj_8005C218 *)this)
    f32 tx;
    f32 tz;
    s32 ang;
    s32 pl;
    if (o->f388 != 0xFFFF) {
        pl = (s32)get_player_by_client_id(o->f388);
        if (pl != 0) {
            VecCopy__FP3VecPC3Vec(&o->home, (void *)(pl + 0x38));
        }
    }
    ang = o->f1c << 0xD;
    tx = lbl_805D8CE8 * sin_table_lookup(ang) + o->home.x;
    tz = lbl_805D8CE8 * cos_table_lookup(ang) + o->home.z;
    o->vel.y = lbl_805D8CBC;
    if (o->pos.x < tx) {
        o->vel.x += lbl_805D8CEC;
    } else {
        o->vel.x -= lbl_805D8CEC;
    }
    if (o->pos.z < tz) {
        o->vel.z += lbl_805D8CEC;
    } else {
        o->vel.z -= lbl_805D8CEC;
    }
    clamp_min_player_distance__9TBoss4UroFPv((Obj_8005C6E4 *)o);
    o->f398 = vector_length(&o->vel);
    if (o->f398 > o->f3a0) {
        o->f398 += lbl_805D8CF0;
        normalize_vector(&o->vel);
        o->vel.x *= o->f398;
        o->vel.z *= o->f398;
    }
#undef o
}
#pragma pop
#pragma push
void vt5__9TBoss4UroFv(u8 *arg0) {
    f32 temp_f1;
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C) + lbl_805D8CB8);
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x3C);
    if ((temp_f1 < lbl_805D8CBC) && (temp_f1 >= lbl_805D8CB8)) {
        spawn_particle_effect((arg0 + 0x38), 0xF3);
    }
    *(s32 *)((s8 *)arg0 + 0x5C) = (s32) (*(s32 *)((s8 *)arg0 + 0x5C) + 0x111);
    if (*(f32 *)((s8 *)arg0 + 0x3C) < lbl_805D8CC0) {
        queue_destruction__7TObjectFv((arg0));
    }
}
#pragma pop
#pragma push
void vt6__9TBoss4UroFv(u8 *arg0) {
    *(f32 *)((s8 *)arg0 + 0x390) = (f32) ((*(f32 *)((s8 *)arg0 + 0x390)) + lbl_805D8CE4);
    VecCopy__FP3VecPC3Vec(arg0 + 0x44, arg0 + 0x38);
    vec3_add_to(arg0 + 0x38, arg0 + 0x38C);
    if (*(f32 *)((s8 *)arg0 + 0x3C) < lbl_805D8CC8) {
        *(f32 *)((s8 *)arg0 + 0x390) = (f32) lbl_805D8CBC;
        *(f32 *)((s8 *)arg0 + 0x3C) = (f32) lbl_805D8CC8;
        *(s32 *)((s8 *)arg0 + 0x374) = 2;
    }
}
#pragma pop
#pragma push
s32 create__11TBoss4BishiFi(s32 arg0) {
    s32 var_r31;
    s32 parent;

    var_r31 = __nw__7TObjectFUl(0x3C4);
    if (var_r31 != 0) {
        parent = __nw__7TObjectFUl(0x20);
        if (parent != 0) {
            parent = TObjControl__ct(parent, tl_04);
        }
        var_r31 = TBoss4Bishi__ct(var_r31, parent, arg0);
    }
    return var_r31;
}
#pragma pop
#pragma push
#pragma opt_common_subs off
s32 TBoss4Bishi__ct(s32 arg0, s32 parent, s32 arg2) {
#define o ((Obj_8005BF68 *)arg0)
    s32 id;
    s32 pl;
    TBoss4Zako__ct(arg0, parent, arg2);
    o->vt = __vt__11TBoss4Bishi;
    o->f0 = lbl_805D27F0;
    if ((id = find_nearest_visible_player(o, 0, lbl_805D8CDC)) == 0xFFFF ||
        (pl = (s32)get_player_by_client_id(id)) == 0) {
        o->vel.x = o->vel.z = lbl_805D8CBC;
    } else {
        VecCopy__FP3VecPC3Vec(&o->vel, (void *)(pl + 0x38));
        id = o->pad1c & 3;
        o->vel.x += TBoss4Bishi_spawn_offsets[id].x;
        o->vel.z += TBoss4Bishi_spawn_offsets[id].z;
    }
    subtract_vector(&o->vel, &o->pos);
    o->vel.y = lbl_805D8CBC;
    if (lbl_805D8CBC == vector_length(&o->vel)) {
        o->vel.x = lbl_805D8CE0;
        o->vel.z = lbl_805D8CBC;
    } else {
        normalize_vector(&o->vel);
    }
    o->f398 = o->f3a0;
    o->vel.x *= o->f398;
    o->vel.z *= o->f398;
    o->pos.y = lbl_805D8CC0;
    o->f37c = 0x96;
    o->f374 = 0;
    o->ctl->flags |= 1;
    return arg0;
#undef o
}
#pragma pop
#pragma push
void *__dt_deleting__11TBoss4BishiFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TBoss4Bishi;
        __dt__10TBoss4ZakoFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma pop
#pragma push
void try_enter_state_3__11TBoss4BishiFPv(void* p) { if (*(int*)((char*)p + 0x374) != 3) { ((TObjEnemy *)p)->distribute_experience(); enter_state_3__11TBoss4BishiFPv(p); } }
#pragma pop
#pragma push
void enter_state_3__11TBoss4BishiFPv(void* p) { if (*(int*)((char*)p + 0x374) != 3) { TBoss4Uro__sub_8005D6D4(*(void**)((char*)p + 0x378)); *(int*)((char*)p + 0x374) = 3; } }
#pragma pop
#pragma push
#pragma fp_contract on
void TBoss4Zako__sub_8005BC4C(TBoss4Bishi *self) {
    if (self->f374 != 3 && get_phase__9TBoss4UroFv(self->f378) != 8) {
        enter_state_3__11TBoss4BishiFPv(self);
        return;
    }
    static Act_8005BC4C tbl[5] = {
        &TBoss4Bishi::vt0, 0, &TBoss4Bishi::vt1, &TBoss4Bishi::vt2, 0,
    };
    Act_8005BC4C a = tbl[self->f374];
    if (a) {
        (self->*a)();
        if (self->f374 == 2) {
            self->pos.y = lbl_805D8CD0 * sin_table_lookup(self->f3BC) + self->pos.y;
            self->f3BC += self->f3C0;
        }
        Vec_8005BC4C v = self->pos;
        if (((TBoss4Zako *)self)->sub_8005D698() != 0) {
            v.y += TBoss4Zako__data_805D8CD4;
        } else {
            v.y += lbl_805D8CD8;
        }
        ((TNowLoading *)(self->f3B4))->copy_pos(&v);
        if (((TBoss4Zako *)self)->sub_8005D698() != 0) {
            self->f60 += 0x1111;
        }
        TBoss4Zako::queue_entry(&self->pos, self->f5C, self->f60);
        ((TBoss4Zako *)self)->apply_contact_damage();
        ((TObjEnemy *)self)->update_prev_position();
        if (((TBoss4Zako *)self)->sub_8005D698() != 0) {
            ((TObjPlayer *)self)->update_collisions();
            submit_cursor_candidate(self, -1);
            minimap_render_dot(self->f2FC, -0x5DB4, 1, 0);
        }
        self->f3B8++;
    }
}
#pragma pop
#pragma push
void vt0__11TBoss4BishiFv(u8 *arg0) {
    f32 temp_f0;
    f32 temp_f2;

    VecCopy__FP3VecPC3Vec(arg0 + 0x44, arg0 + 0x38);
    temp_f2 = *(f32 *)((s8 *)arg0 + 0x3C);
    if (temp_f2 < lbl_805D8CC8) {
        temp_f0 = temp_f2 + lbl_805D8CCC;
        *(f32 *)((s8 *)arg0 + 0x3C) = temp_f0;
        if (temp_f0 > lbl_805D8CC8) {
            *(f32 *)((s8 *)arg0 + 0x3C) = (f32) lbl_805D8CC8;
            *(s32 *)((s8 *)arg0 + 0x374) = 2;
        }
    }
}
#pragma pop
#pragma push
void vt1__11TBoss4BishiFv(Obj_8005BB5C *self) {
    VecCopy__FP3VecPC3Vec(&self->prev, &self->pos);
    vec3_add_to(&self->pos, (u8 *)self + 0x38C);
    V_8005BB5C v = self->pos;
    v.y = lbl_805D8CBC;
    if (--self->f37c < 0 || vector_length(&v) > lbl_805D8CC4) {
        enter_state_3__11TBoss4BishiFPv(self);
    }
}
#pragma pop
#pragma push
void vt2__11TBoss4BishiFv(u8 *arg0) {
    f32 temp_f1;
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C) + lbl_805D8CB8);
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x3C);
    if ((temp_f1 < lbl_805D8CBC) && (temp_f1 >= lbl_805D8CB8)) {
        spawn_particle_effect((arg0 + 0x38), 0xF3);
    }
    *(s32 *)((s8 *)arg0 + 0x5C) = (s32) (*(s32 *)((s8 *)arg0 + 0x5C) + 0x111);
    if (*(f32 *)((s8 *)arg0 + 0x3C) < lbl_805D8CC0) {
        queue_destruction__7TObjectFv((arg0));
    }
}
#pragma pop
#pragma push
void TBoss4Type3::clear_harmful_statuses() {  }
#pragma pop
#pragma push
void TBoss4Type3::apply_shock_status() {  }
#pragma pop
#pragma push
void TBoss4Type3::apply_movement_ailment(s32) {  }
#pragma pop
#pragma push
void TBoss4Type3::apply_confusion_status() {  }
#pragma pop
#pragma push
void TBoss4Type3::apply_slow_status() {  }
#pragma pop
#pragma push
void TBoss4Type3::apply_paralysis() {  }
#pragma pop
#pragma push
void TBoss4Type3::apply_poison_status() {  }
#pragma pop
}

#pragma dont_inline off
#pragma auto_inline off
#pragma inline_depth(2)

extern "C" const f32 TBoss4Zako_movement_speed_step = 0.033333335f;
extern "C" const f32 TBoss4Zako_one_third = 0.33333334f;

extern "C" {
void vfunc_29__9TObjCharaFv();
void apply_anti_technique__9TObjCharaFl();
void recalc_stats__9TObjCharaFv();
void enemy_spawn_zalure_effect__9TObjCharaFv();
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
void enemy_spawn_jellen_effect__9TObjCharaFv();
void apply_switch_attack__9TObjCharaFv();
void vfunc_78__9TObjCharaFl();
void vfunc_77__9TObjCharaFv();
void vfunc_76__9TObjCharaFv();
void vfunc_75__9TObjCharaFf();
void vfunc_28__9TObjCharaFv();
void get_actor_level_index__9TObjCharaFv();
void consume_timer_field__9TObjCharaFl();
void add_actor_exp__9TObjCharaFl();
void is_actor_cadence_frame__9TObjCharaFl();
void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
void apply_knockback_from_attacker__9TObjCharaFPUc();
void receive_physical_attack__9TObjCharaFPvf();
void vfunc_67__9TObjCharaFf();
void vfunc_66__9TObjCharaFv();
void get_anim_node_position__9TObjCharaFlP3Vec();
void reset_pose__9TObjCharaFv();
void vfunc_62__9TObjCharaFv();
void vfunc_61__9TObjCharaFv();
void vfunc_60__9TObjCharaFv();
void vfunc_59__9TObjCharaFv();
void vfunc_58__9TObjCharaFv();
void apply_action_hold_status__9TObjCharaFf();
void clear_all_status_effects__9TObjCharaFv();
void cure_paralysis__9TObjCharaFv();
void cure_poison_ailment__9TObjCharaFv();
void apply_attack_stat_status__9TObjCharaFPv();
void clear_harmful_statuses__9TObjCharaFv();
void apply_shock_status__9TObjCharaFv();
void apply_movement_ailment__9TObjCharaFl();
void apply_confusion_status__9TObjCharaFv();
void apply_slow_status__9TObjCharaFv();
void apply_paralysis__9TObjCharaFv();
void apply_poison_status__9TObjCharaFv();
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
void roll_physical_accuracy__9TObjCharaFPvlf();
void try_start_action__9TObjCharaFll();
void select_melee_contact_body__9TObjCharaFPvf();
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
void update_shock_clock__9TObjCharaFv();
void update_movement_status__9TObjCharaFv();
void update_flag30_timer__9TObjCharaFv();
s32 vfunc_37__9TObjCharaFv(u8 *arg0);
void update_action_hold_status__9TObjCharaFv();
void update_poison_status__9TObjCharaFv();
void vfunc_43__9TObjCharaFv();
void is_target_in_attack_range__9TObjCharaFv();
void vfunc_18__9TObjCharaFPUc();
void update_actor_ground_y__9TObjCharaFv();
void get_center__9TObjCharaFv();
void reset_motion_fields__9TObjCharaFv();
void get_pos__9TObjCharaFl();
void interact__14TObjCollidableFl();
void run_task__10TBoss4ZakoFv();
void clear_lobby_object_state__9TObjEnemyFv();
void render_shadows__9TObjEnemyFv(u8 *arg0);
void get_name__9TObjEnemyFv();
void vfunc_74__9TObjEnemyFl();
void apply_hit_message_flags__9TObjEnemyFPv();
void vfunc_79__9TObjEnemyFv();
void apply_set_data__9TObjEnemyFPv();
void apply_object_set_data__8TObjBaseFPv();
void vfunc_6__8TObjBaseFPsl();
void classify_actor_view_detail__8TObjBaseFfff();
void update_object_view_visibility__8TObjBaseFff();
s32 __vt__11TBoss4Bishi[83] = {
    0,
    0,
    (s32)__dt_deleting__11TBoss4BishiFPvs,
    (s32)TBoss4Zako__sub_8005BC4C,
    (s32)render__9TBoss4UroFv,
    (s32)render_shadows__9TObjEnemyFv,
    (s32)vfunc_6__8TObjBaseFPsl,
    (s32)apply_object_set_data__8TObjBaseFPv,
    (s32)reset_motion_fields__9TObjCharaFv,
    (s32)get_center__9TObjCharaFv,
    (s32)update_object_view_visibility__8TObjBaseFff,
    (s32)classify_actor_view_detail__8TObjBaseFfff,
    (s32)get_name__9TObjEnemyFv,
    (s32)interact__14TObjCollidableFl,
    (s32)add_actor_exp__9TObjCharaFl,
    (s32)consume_timer_field__9TObjCharaFl,
    (s32)get_actor_level_index__9TObjCharaFv,
    (s32)update_actor_ground_y__9TObjCharaFv,
    (s32)vfunc_18__9TObjCharaFPUc,
    (s32)is_actor_cadence_frame__9TObjCharaFl,
    (s32)select_melee_contact_body__9TObjCharaFPvf,
    (s32)calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf,
    (s32)receive_physical_attack__9TObjCharaFPvf,
    (s32)receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (s32)receive_weapon_special_attack__9TObjCharaFPvPv,
    (s32)apply_knockback_from_attacker__9TObjCharaFPUc,
    (s32)try_start_action__9TObjCharaFll,
    (s32)roll_physical_accuracy__9TObjCharaFPvlf,
    (s32)vfunc_28__9TObjCharaFv,
    (s32)vfunc_29__9TObjCharaFv,
    (s32)is_target_in_attack_range__9TObjCharaFv,
    (s32)&test_flag_256__9TObjCharaFv,
    (s32)&test_flag30_512__9TObjCharaFv,
    (s32)&has_flag_0x800__9TObjCharaFv,
    (s32)&test_flag_1000__9TObjCharaFv,
    (s32)update_poison_status__9TObjCharaFv,
    (s32)update_action_hold_status__9TObjCharaFv,
    (s32)vfunc_37__9TObjCharaFv,
    (s32)update_flag30_timer__9TObjCharaFv,
    (s32)update_movement_status__9TObjCharaFv,
    (s32)update_shock_clock__9TObjCharaFv,
    (s32)update_attack_stat_status__9TObjCharaFv,
    (s32)update_defense_stat_status__9TObjCharaFv,
    (s32)vfunc_43__9TObjCharaFv,
    (s32)apply_poison_status__9TObjCharaFv,
    (s32)apply_paralysis__9TObjCharaFv,
    (s32)apply_slow_status__9TObjCharaFv,
    (s32)apply_confusion_status__9TObjCharaFv,
    (s32)apply_movement_ailment__9TObjCharaFl,
    (s32)apply_shock_status__9TObjCharaFv,
    (s32)clear_harmful_statuses__9TObjCharaFv,
    (s32)apply_attack_stat_status__9TObjCharaFPv,
    (s32)apply_defense_stat_status__9TObjCharaFPv,
    (s32)cure_poison_ailment__9TObjCharaFv,
    (s32)cure_paralysis__9TObjCharaFv,
    (s32)clear_all_status_effects__9TObjCharaFv,
    (s32)apply_action_hold_status__9TObjCharaFf,
    (s32)apply_anti_technique__9TObjCharaFl,
    (s32)vfunc_58__9TObjCharaFv,
    (s32)vfunc_59__9TObjCharaFv,
    (s32)vfunc_60__9TObjCharaFv,
    (s32)vfunc_61__9TObjCharaFv,
    (s32)vfunc_62__9TObjCharaFv,
    (s32)try_enter_state_3__11TBoss4BishiFPv,
    (s32)reset_pose__9TObjCharaFv,
    (s32)get_anim_node_position__9TObjCharaFlP3Vec,
    (s32)vfunc_66__9TObjCharaFv,
    (s32)vfunc_67__9TObjCharaFf,
    (s32)get_pos__9TObjCharaFl,
    (s32)apply_switch_attack__9TObjCharaFv,
    (s32)enemy_spawn_jellen_effect__9TObjCharaFv,
    (s32)trigger_switch_attack__9TObjCharaFv,
    (s32)enemy_spawn_zalure_effect__9TObjCharaFv,
    (s32)recalc_stats__9TObjCharaFv,
    (s32)vfunc_74__9TObjEnemyFl,
    (s32)vfunc_75__9TObjCharaFf,
    (s32)vfunc_76__9TObjCharaFv,
    (s32)vfunc_77__9TObjCharaFv,
    (s32)vfunc_78__9TObjCharaFl,
    (s32)vfunc_79__9TObjEnemyFv,
    (s32)apply_hit_message_flags__9TObjEnemyFPv,
    (s32)apply_set_data__9TObjEnemyFPv,
    (s32)clear_lobby_object_state__9TObjEnemyFv,
};
s32 __vt__9TBoss4Uro[83] = {
    0,
    0,
    (s32)__dt__9TBoss4UroFv,
    (s32)run_task__9TBoss4UroFv,
    (s32)render__9TBoss4UroFv,
    (s32)render_shadows__9TObjEnemyFv,
    (s32)vfunc_6__8TObjBaseFPsl,
    (s32)apply_object_set_data__8TObjBaseFPv,
    (s32)reset_motion_fields__9TObjCharaFv,
    (s32)get_center__9TObjCharaFv,
    (s32)update_object_view_visibility__8TObjBaseFff,
    (s32)classify_actor_view_detail__8TObjBaseFfff,
    (s32)get_name__9TObjEnemyFv,
    (s32)interact__14TObjCollidableFl,
    (s32)add_actor_exp__9TObjCharaFl,
    (s32)consume_timer_field__9TObjCharaFl,
    (s32)get_actor_level_index__9TObjCharaFv,
    (s32)update_actor_ground_y__9TObjCharaFv,
    (s32)vfunc_18__9TObjCharaFPUc,
    (s32)is_actor_cadence_frame__9TObjCharaFl,
    (s32)select_melee_contact_body__9TObjCharaFPvf,
    (s32)calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf,
    (s32)receive_physical_attack__9TObjCharaFPvf,
    (s32)receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (s32)receive_weapon_special_attack__9TObjCharaFPvPv,
    (s32)apply_knockback_from_attacker__9TObjCharaFPUc,
    (s32)try_start_action__9TObjCharaFll,
    (s32)roll_physical_accuracy__9TObjCharaFPvlf,
    (s32)vfunc_28__9TObjCharaFv,
    (s32)vfunc_29__9TObjCharaFv,
    (s32)is_target_in_attack_range__9TObjCharaFv,
    (s32)&test_flag_256__9TObjCharaFv,
    (s32)&test_flag30_512__9TObjCharaFv,
    (s32)&has_flag_0x800__9TObjCharaFv,
    (s32)&test_flag_1000__9TObjCharaFv,
    (s32)update_poison_status__9TObjCharaFv,
    (s32)update_action_hold_status__9TObjCharaFv,
    (s32)vfunc_37__9TObjCharaFv,
    (s32)update_flag30_timer__9TObjCharaFv,
    (s32)update_movement_status__9TObjCharaFv,
    (s32)update_shock_clock__9TObjCharaFv,
    (s32)update_attack_stat_status__9TObjCharaFv,
    (s32)update_defense_stat_status__9TObjCharaFv,
    (s32)vfunc_43__9TObjCharaFv,
    (s32)apply_poison_status__9TObjCharaFv,
    (s32)apply_paralysis__9TObjCharaFv,
    (s32)apply_slow_status__9TObjCharaFv,
    (s32)apply_confusion_status__9TObjCharaFv,
    (s32)apply_movement_ailment__9TObjCharaFl,
    (s32)apply_shock_status__9TObjCharaFv,
    (s32)clear_harmful_statuses__9TObjCharaFv,
    (s32)apply_attack_stat_status__9TObjCharaFPv,
    (s32)apply_defense_stat_status__9TObjCharaFPv,
    (s32)cure_poison_ailment__9TObjCharaFv,
    (s32)cure_paralysis__9TObjCharaFv,
    (s32)clear_all_status_effects__9TObjCharaFv,
    (s32)apply_action_hold_status__9TObjCharaFf,
    (s32)apply_anti_technique__9TObjCharaFl,
    (s32)vfunc_58__9TObjCharaFv,
    (s32)vfunc_59__9TObjCharaFv,
    (s32)vfunc_60__9TObjCharaFv,
    (s32)vfunc_61__9TObjCharaFv,
    (s32)vfunc_62__9TObjCharaFv,
    (s32)TBoss4Uro__vt61,
    (s32)reset_pose__9TObjCharaFv,
    (s32)get_anim_node_position__9TObjCharaFlP3Vec,
    (s32)vfunc_66__9TObjCharaFv,
    (s32)vfunc_67__9TObjCharaFf,
    (s32)get_pos__9TObjCharaFl,
    (s32)apply_switch_attack__9TObjCharaFv,
    (s32)enemy_spawn_jellen_effect__9TObjCharaFv,
    (s32)trigger_switch_attack__9TObjCharaFv,
    (s32)enemy_spawn_zalure_effect__9TObjCharaFv,
    (s32)recalc_stats__9TObjCharaFv,
    (s32)vfunc_74__9TObjEnemyFl,
    (s32)vfunc_75__9TObjCharaFf,
    (s32)vfunc_76__9TObjCharaFv,
    (s32)vfunc_77__9TObjCharaFv,
    (s32)vfunc_78__9TObjCharaFl,
    (s32)vfunc_79__9TObjEnemyFv,
    (s32)apply_hit_message_flags__9TObjEnemyFPv,
    (s32)apply_set_data__9TObjEnemyFPv,
    (s32)clear_lobby_object_state__9TObjEnemyFv,
};
s32 __vt__10TBoss4Zako[83] = {
    0,
    0,
    (s32)__dt__10TBoss4ZakoFv,
    (s32)run_task__10TBoss4ZakoFv,
    (s32)render__9TBoss4UroFv,
    (s32)render_shadows__9TObjEnemyFv,
    (s32)vfunc_6__8TObjBaseFPsl,
    (s32)apply_object_set_data__8TObjBaseFPv,
    (s32)reset_motion_fields__9TObjCharaFv,
    (s32)get_center__9TObjCharaFv,
    (s32)update_object_view_visibility__8TObjBaseFff,
    (s32)classify_actor_view_detail__8TObjBaseFfff,
    (s32)get_name__9TObjEnemyFv,
    (s32)interact__14TObjCollidableFl,
    (s32)add_actor_exp__9TObjCharaFl,
    (s32)consume_timer_field__9TObjCharaFl,
    (s32)get_actor_level_index__9TObjCharaFv,
    (s32)update_actor_ground_y__9TObjCharaFv,
    (s32)vfunc_18__9TObjCharaFPUc,
    (s32)is_actor_cadence_frame__9TObjCharaFl,
    (s32)select_melee_contact_body__9TObjCharaFPvf,
    (s32)calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf,
    (s32)receive_physical_attack__9TObjCharaFPvf,
    (s32)receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (s32)receive_weapon_special_attack__9TObjCharaFPvPv,
    (s32)apply_knockback_from_attacker__9TObjCharaFPUc,
    (s32)try_start_action__9TObjCharaFll,
    (s32)roll_physical_accuracy__9TObjCharaFPvlf,
    (s32)vfunc_28__9TObjCharaFv,
    (s32)vfunc_29__9TObjCharaFv,
    (s32)is_target_in_attack_range__9TObjCharaFv,
    (s32)&test_flag_256__9TObjCharaFv,
    (s32)&test_flag30_512__9TObjCharaFv,
    (s32)&has_flag_0x800__9TObjCharaFv,
    (s32)&test_flag_1000__9TObjCharaFv,
    (s32)update_poison_status__9TObjCharaFv,
    (s32)update_action_hold_status__9TObjCharaFv,
    (s32)vfunc_37__9TObjCharaFv,
    (s32)update_flag30_timer__9TObjCharaFv,
    (s32)update_movement_status__9TObjCharaFv,
    (s32)update_shock_clock__9TObjCharaFv,
    (s32)update_attack_stat_status__9TObjCharaFv,
    (s32)update_defense_stat_status__9TObjCharaFv,
    (s32)vfunc_43__9TObjCharaFv,
    (s32)apply_poison_status__9TObjCharaFv,
    (s32)apply_paralysis__9TObjCharaFv,
    (s32)apply_slow_status__9TObjCharaFv,
    (s32)apply_confusion_status__9TObjCharaFv,
    (s32)apply_movement_ailment__9TObjCharaFl,
    (s32)apply_shock_status__9TObjCharaFv,
    (s32)clear_harmful_statuses__9TObjCharaFv,
    (s32)apply_attack_stat_status__9TObjCharaFPv,
    (s32)apply_defense_stat_status__9TObjCharaFPv,
    (s32)cure_poison_ailment__9TObjCharaFv,
    (s32)cure_paralysis__9TObjCharaFv,
    (s32)clear_all_status_effects__9TObjCharaFv,
    (s32)apply_action_hold_status__9TObjCharaFf,
    (s32)apply_anti_technique__9TObjCharaFl,
    (s32)vfunc_58__9TObjCharaFv,
    (s32)vfunc_59__9TObjCharaFv,
    (s32)vfunc_60__9TObjCharaFv,
    (s32)vfunc_61__9TObjCharaFv,
    (s32)vfunc_62__9TObjCharaFv,
    (s32)update_state3__10TBoss4ZakoFPv,
    (s32)reset_pose__9TObjCharaFv,
    (s32)get_anim_node_position__9TObjCharaFlP3Vec,
    (s32)vfunc_66__9TObjCharaFv,
    (s32)vfunc_67__9TObjCharaFf,
    (s32)get_pos__9TObjCharaFl,
    (s32)apply_switch_attack__9TObjCharaFv,
    (s32)enemy_spawn_jellen_effect__9TObjCharaFv,
    (s32)trigger_switch_attack__9TObjCharaFv,
    (s32)enemy_spawn_zalure_effect__9TObjCharaFv,
    (s32)recalc_stats__9TObjCharaFv,
    (s32)vfunc_74__9TObjEnemyFl,
    (s32)vfunc_75__9TObjCharaFf,
    (s32)vfunc_76__9TObjCharaFv,
    (s32)vfunc_77__9TObjCharaFv,
    (s32)vfunc_78__9TObjCharaFl,
    (s32)vfunc_79__9TObjEnemyFv,
    (s32)apply_hit_message_flags__9TObjEnemyFPv,
    (s32)apply_set_data__9TObjEnemyFPv,
    (s32)clear_lobby_object_state__9TObjEnemyFv,
};
}
