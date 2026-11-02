#pragma readonly_strings on
#include "pso/npc/TObjNpcBase_80149128.h"
#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/TObject.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/quest/TQuestThread.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjChara.h"
#include "pso/map/FloorArea.h"
#include "pso/protocol/protocol_types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/npc/TObjNpcBringer.h"
#include "pso/npc/TObjNpcEnemy.h"


// ---- src/pso/npc/TObjNpcARW00.cpp (0x801480F4..0x80148274)

struct Npc_801480FC {
    u8 pad0[0x60];
    s32 f60;
    u8 pad64[0x358 - 0x64];
    f32 f358;
    f32 f35C;
    f32 f360;
    f32 f364;
    u8 pad368[0x384 - 0x368];
    s32 f384;
    u8 pad388[0x38C - 0x388];
    s32 f38C;
    u8 pad390[0x3A0 - 0x390];
    s32 f3A0;
    s32 f3A4;
    s32 f3A8;
    s32 f3AC;
};

extern "C" {
const char *TObjNpcBase__name = "TObjNpcBase";
s32 debug_printf_at(s32, const char *, ...);
}

#pragma pool_data off
void TObjNpcBase::vfunc_92() {  }
void TObjNpcBase::vfunc_91() {  }
void TObjNpcBase::draw_debug_info() {
    Npc_801480FC *o = (Npc_801480FC *)this;
    o->f384 = o->f60;
    o->f38C = 0;
    if (1000.0f <= o->f358) {
        o->f38C = 1;
        o->f3A0 = o->f358 - 1000.0f;
    } else {
        o->f3A0 = o->f358;
    }
    if (1000.0f <= o->f35C) {
        o->f38C = 1;
        o->f3A4 = o->f35C - 1000.0f;
    } else {
        o->f3A4 = o->f35C;
    }
    o->f3A8 = o->f364;
    o->f3AC = o->f360;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x1A001D, "<- DISP ON FLAG NO : %4.0f", o->f358);
    debug_printf_at(0x1A001E, "<- DISP OFF FLAG NO: %4.0f", o->f35C);
    debug_printf_at(0x1A001F, "<- OBJECT NUMBER : %4d", o->f3AC);
    debug_printf_at(0x1A0020, "<- MESSAGE LABEL : %4d", o->f3A8);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}
#pragma pool_data reset
// ---- src/pso/unk/text_80148274.cpp

struct Obj_80148274 { u8 pad0[0x350]; void *anim; };

extern "C" {
u32 init_collision_body_parts(void *, void *, s32);
void *npc_default_battle_stats[9] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41a00000, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *npc_movement_parameters[7] = {
    (void *)0x42c80000, (void *)0x3f000000, (void *)0x400, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *npc_base_collision_body_desc[11] = {
    (void *)0x0, (void *)0x41200000, (void *)0x0, (void *)0x40a00000,
    (void *)0x0, (void *)0x0, (void *)0x30203, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void TObjNpcBase::setup_common() {
    Obj_80148274 *self = (Obj_80148274 *)this;
    ((TObjChara *)self)->set_motion_params(npc_default_battle_stats);
    this->movementParameters = npc_movement_parameters;
    init_collision_body_parts(self, npc_base_collision_body_desc, 1);
    ((TObjPlayer *)self)->register_object_by_id();
    ((TObjEnemy *)self)->update_prev_position();
    ((TBoss3VoloptHiraisin *)self)->copy_position();
    this->apply_set_params(0, 1);
}

}

// ---- src/pso/unk/text_801482F8.cpp

struct VBase18_801482f8 { char pad[0x18]; };
struct VObj18_801482f8 : VBase18_801482f8 {
    virtual void vpad0();
    virtual void vpad1();
    virtual void vpad2();
    virtual void vpad3();
    virtual void vpad4();
    virtual void vpad5();
    virtual void vpad6();
    virtual void vpad7();
    virtual void vpad8();
    virtual void vpad9();
    virtual void vpad10();
    virtual void vpad11();
    virtual void vpad12();
    virtual void vpad13();
    virtual void vpad14();
    virtual void vpad15();
    virtual void vpad16();
    virtual void vpad17();
    virtual void vpad18();
    virtual void vpad19();
    virtual void vpad20();
    virtual void vpad21();
    virtual void vpad22();
    virtual void vpad23();
    virtual void vpad24();
    virtual void vpad25();
    virtual void vpad26();
    virtual void vpad27();
    virtual void vpad28();
    virtual void vpad29();
    virtual void vpad30();
    virtual void vpad31();
    virtual void vpad32();
    virtual void vpad33();
    virtual void vpad34();
    virtual void vpad35();
    virtual void vpad36();
    virtual void vpad37();
    virtual void vpad38();
    virtual void vpad39();
    virtual void vpad40();
    virtual void vpad41();
    virtual void vpad42();
    virtual void vpad43();
    virtual void vpad44();
    virtual void vpad45();
    virtual void vpad46();
    virtual void vpad47();
    virtual void vpad48();
    virtual void vpad49();
    virtual void vpad50();
    virtual void vpad51();
    virtual void vpad52();
    virtual void vpad53();
    virtual void vpad54();
    virtual void vpad55();
    virtual void vpad56();
    virtual void vpad57();
    virtual void vpad58();
    virtual void vpad59();
    virtual void vpad60();
    virtual void vpad61();
    virtual void vpad62();
    virtual void vpad63();
    virtual void vpad64();
    virtual void vpad65();
    virtual void vpad66();
    virtual void vpad67();
    virtual void vpad68();
    virtual void vpad69();
    virtual void vpad70();
    virtual void vpad71();
    virtual void vpad72();
    virtual void vpad73();
    virtual void vpad74();
    virtual void vpad75();
    virtual void vpad76();
    virtual void vpad77();
    virtual void vpad78();
    virtual void vpad79();
    virtual void vpad80();
    virtual void vpad81();
    virtual void vpad82();
    virtual void vpad83();
    virtual void vpad84();
    virtual void vpad85();
    virtual void vf160(int);
};

struct VBase18_801489B8 { char pad[0x18]; };

struct VObj18_801489B8 : VBase18_801489B8 {
    virtual void vpad0();
    virtual void vpad1();
    virtual void vpad2();
    virtual void vpad3();
    virtual void vpad4();
    virtual void vpad5();
    virtual void vpad6();
    virtual void vpad7();
    virtual void vpad8();
    virtual void vpad9();
    virtual void vpad10();
    virtual void vpad11();
    virtual void vpad12();
    virtual void vpad13();
    virtual void vpad14();
    virtual void vpad15();
    virtual void vpad16();
    virtual void vpad17();
    virtual void vpad18();
    virtual void vpad19();
    virtual void vpad20();
    virtual void vpad21();
    virtual void vpad22();
    virtual void vpad23();
    virtual void vpad24();
    virtual void vpad25();
    virtual void vpad26();
    virtual void vpad27();
    virtual void vpad28();
    virtual void vpad29();
    virtual void vpad30();
    virtual void vpad31();
    virtual void vpad32();
    virtual void vpad33();
    virtual void vpad34();
    virtual void vpad35();
    virtual void vpad36();
    virtual void vpad37();
    virtual void vpad38();
    virtual void vpad39();
    virtual void vpad40();
    virtual void vpad41();
    virtual void vpad42();
    virtual void vpad43();
    virtual void vpad44();
    virtual void vpad45();
    virtual void vpad46();
    virtual void vpad47();
    virtual void vpad48();
    virtual void vpad49();
    virtual void vpad50();
    virtual void vpad51();
    virtual void vpad52();
    virtual void vpad53();
    virtual void vpad54();
    virtual void vpad55();
    virtual void vpad56();
    virtual void vpad57();
    virtual void vpad58();
    virtual void vpad59();
    virtual void vpad60();
    virtual void vpad61();
    virtual void vpad62();
    virtual void vpad63();
    virtual void vpad64();
    virtual void vpad65();
    virtual void vpad66();
    virtual void vpad67();
    virtual void vpad68();
    virtual void vpad69();
    virtual void vpad70();
    virtual void vpad71();
    virtual void vpad72();
    virtual void vpad73();
    virtual void vpad74();
    virtual void vpad75();
    virtual void vpad76();
    virtual void vpad77();
    virtual void vpad78();
    virtual void vpad79();
    virtual void vpad80();
    virtual void vpad81();
    virtual void vpad82();
    virtual void vpad83();
    virtual void vpad84();
    virtual void vpad85();
    virtual void vf160(int);
    virtual void vpad87();
    virtual void vf168();
};

typedef struct Vec_801489B8 { f32 x, y, z; } Vec_801489B8;

struct VBase_18_f3aa6a { char pad[0x18]; };

struct VObj_18_f3aa6a : VBase_18_f3aa6a {
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual s32 m86(s32);
};

struct Vec_8014854C { f32 x, y, z; };

struct Pkt_8014854C { u16 h0; u16 id; u16 h4; s16 ang; u8 pad8[4]; Vec_8014854C pos; };

struct Lim_8014854C { u8 pad0[8]; s32 lim; };

extern "C" {
s32 approach_angle_limited(s32, s32, s32);
f32 random_ratio__9TObjCharaFv();
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
void select_enemy_destination(void *, void *, s32);
void enemy_turn_toward_dest(void *, s32);
f32 horizontal_distance_squared(void *, void *);
void vec3_add_to(void *, void *);
void rotate_vector_by_matrix(int, void *, void *);
void rotate_matrix_y(int, int);
s32 push_matrix_from(void *src);
s32 pop_matrix(void);
extern u8 identity_matrix[];
u16 get_entity_id(void *);
f64 atan2_float(f32, f32);
s32 queue_destruction__7TObjectFv(void *);
}
void move_with_wall_slide(u8 *arg0);
u8 *create_conversation_camera(s32 arg0);
extern "C" {
s32 end_conversation_camera(void);
s32 begin_conversation_camera(void);
s32 angle_difference_abs(s32, s32);
void *__nw__7TObjectFUl(u32);
s32 subtract_vector(void *, void *);
extern s32 local_client_id;
extern u8 *quest_mission_manager;
extern u8 *quest_area_manager;
s32 has_interactor__14TObjCollidableFv();
s32 debug_printf_at(s32, const char *, ...);

void TObjNpcBase::interact(s32 client) {
    TObjPlayer *player;

    if ((s32) this->m_3a8 > 0) {
        if ((u16) client == local_client_id) {
            player = get_player_by_client_id((u16) client);
            if ((player != NULL) && ((s16) this->mode != 3)) {
                this->mode = 3;
                this->phase = 0;
                this->interactor = client;
                this->targetId = client;
                this->target = (u8 *) player;
                if ((s32) this->targetId == local_client_id) {
                    TObjPlayer::play_effect_default((int) player, -1);
                }
                this->request_action(1);
                this->m_2ac = 0;
            }
        } else {
            this->interactor = 0xFFFFU;
            this->targetId = 0xFFFFU;
        }
    }
}

#define F(T, o) (*(T *)(arg0 + (o)))

void TObjNpcBase::debug_draw_talk() {
    if ((has_interactor__14TObjCollidableFv() != 0) && (get_player_by_client_id(this->interactor) != NULL)) {
        debug_printf_at(0x1A0020, "TALK");
    }
}

void TObjNpcBase::apply_set_params(s32 arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    temp_r0 = this->variant;
    if (temp_r0 <= arg1) {
        this->variant = arg1;
    } else if (arg2 <= temp_r0) {
        this->variant = arg2;
    }
    if (1000.0f <= *(f32 *)((s8 *)arg0 + 0x358)) {
        this->m_38c = 1;
        this->m_3a0 = (s32) (*(f32 *)((s8 *)arg0 + 0x358) - 1000.0f);
    } else {
        this->m_3a0 = (s32) *(f32 *)((s8 *)arg0 + 0x358);
    }
    if (1000.0f <= *(f32 *)((s8 *)arg0 + 0x35C)) {
        this->m_38c = 1;
        this->m_3a4 = (s32) (*(f32 *)((s8 *)arg0 + 0x35C) - 1000.0f);
    } else {
        this->m_3a4 = (s32) *(f32 *)((s8 *)arg0 + 0x35C);
    }
    ((TObjNpcBase *)arg0)->sub_80149360((s32) *(f32 *)((s8 *)arg0 + 0x364));
    ((TObjNpcBase *)arg0)->sub_80149358((s32) *(f32 *)((s8 *)arg0 + 0x360));
    this->m_384 = (s32) this->rotation_y;
    if ((s32) this->m_3ac > 0) {
        this->m_398 = 400.0f;
        return;
    }
    this->m_398 = 250.0f;
}

void TObjNpcBase::update_conversation() {
    u8 *arg0 = (u8 *)this;
    Pkt_8014854C pkt1;
    Pkt_8014854C pkt2;
    Vec_8014854C d;
    s32 ang;
    void *m;
    u32 p;
    if (F(u16, 0x94) != local_client_id || F(void *, 0x2A8) == 0 || F(s32, 0x3A8) <= 0) {
        F(s16, 0x328) = 3;
    }
    switch (F(s16, 0x328)) {
    case 0:
        VecCopy((Vec *)&d, (const Vec *)(F(u8 *, 0x2A8) + 0x38));
        subtract_vector(&d, arg0 + 0x38);
        ang = 10430.38043493439 * atan2_float(d.x, d.z);
        switch (F(s32, 0x3AC)) {
        case 0x3E9:
        case 0x3EA:
        case 0x3EB:
        case 0x41A:
        case 0x41B:
        case 0x41F:
            F(s16, 0x328) = 1;
            ((VObj_18_f3aa6a *)arg0)->m86(0);
            ((TNpcPlayer *)(&pkt1))->init_6x3E_packet();
            pkt1.id = get_entity_id(F(void *, 0x2A8));
            VecCopy((Vec *)&pkt1.pos, (const Vec *)(F(u8 *, 0x2A8) + 0x38));
            pkt1.ang = ang + 0x8000;
            ((TNpcPlayer *)(&pkt1))->send_6x3E();
            break;
        default:
            if (angle_difference_abs(F(s32, 0x60), ang) < F(Lim_8014854C *, 0x350)->lim) {
                F(s16, 0x328) = 1;
                F(s32, 0x60) = ang;
                ((VObj_18_f3aa6a *)arg0)->m86(0);
                ((TNpcPlayer *)(&pkt2))->init_6x3E_packet();
                pkt2.id = get_entity_id(F(void *, 0x2A8));
                VecCopy((Vec *)&pkt2.pos, (const Vec *)(F(u8 *, 0x2A8) + 0x38));
                pkt2.ang = F(s32, 0x60) + 0x8000;
                ((TNpcPlayer *)(&pkt2))->send_6x3E();
            } else {
                F(s32, 0x60) = approach_angle_limited(F(s32, 0x60), ang, F(Lim_8014854C *, 0x350)->lim);
            }
            break;
        }
        break;
    case 1:
        F(s16, 0x328) = 2;
        if (TRaderMapCore::is_not_split_screen() == 0) {
            switch (F(s32, 0x3AC)) {
            case 0x3E9:
                F(u32, 0x3B4) = (u32)create_conversation_camera(7);
                TCameraCtrl::update_battle_camera();
                break;
            case 0x3EA:
                F(u32, 0x3B4) = (u32)create_conversation_camera(9);
                TCameraCtrl::update_battle_camera();
                break;
            case 0x3EB:
                F(u32, 0x3B4) = (u32)create_conversation_camera(8);
                TCameraCtrl::update_battle_camera();
                break;
            case 0x41A:
                F(u32, 0x3B4) = (u32)create_conversation_camera(0x11);
                TCameraCtrl::update_battle_camera();
                break;
            case 0x41B:
                F(u32, 0x3B4) = (u32)create_conversation_camera(0x12);
                TCameraCtrl::update_battle_camera();
                break;
            case 0x41F:
                F(u32, 0x3B4) = (u32)create_conversation_camera(0x13);
                TCameraCtrl::update_battle_camera();
                break;
            default:
                begin_conversation_camera();
                break;
            }
        }
        if (F(s32, 0x3AC) >= 100 && F(s32, 0x3AC) < 1000 && quest_mission_manager != 0 && ((TObject *)quest_mission_manager)->all_parents_unqueued_for_destruction() != 0) {
            m = new TQuestThread((TObject *)quest_mission_manager, F(s32, 0x3A8));
            F(void *, 0x3B0) = m;
        } else if (F(s32, 0x3AC) >= 1000 && quest_area_manager != 0 && ((TObject *)quest_area_manager)->all_parents_unqueued_for_destruction() != 0) {
            m = new TQuestThread((TObject *)quest_area_manager, F(s32, 0x3A8));
            F(void *, 0x3B0) = m;
        }
        break;
    case 2:
        if ((F(u32, 0x3B0) != 0 && ((TObject *)(F(u32, 0x3B0)))->all_parents_unqueued_for_destruction() == 0) || F(u32, 0x3B0) == 0) {
            F(s16, 0x328) = 3;
            F(s32, 0x2AC) = 0;
            switch (F(s32, 0x3AC)) {
            case 0x3E9:
            case 0x3EA:
            case 0x3EB:
            case 0x41A:
            case 0x41B:
            case 0x41F:
                TCameraCtrl::update_active_player();
                if (F(void *, 0x3B4) != 0) {
                    queue_destruction__7TObjectFv(F(void *, 0x3B4));
                    F(void *, 0x3B4) = 0;
                }
                break;
            default:
                end_conversation_camera();
                break;
            }
            if (F(void *, 0x2A8) != 0 && local_client_id == get_entity_id(F(void *, 0x2A8))) {
                p = (u32) get_player_by_client_id(local_client_id);
                if (p != 0 && ((TLobby *)p)->check_player_flag1() != 0) {
                    TObjPlayer::send_code_45_1((s32)((void *)p));
                }
            }
        }
        break;
    case 3:
        F(s16, 0x326) = 0;
        F(s16, 0x328) = 0;
        F(u16, 0x338) = 0xFFFF;
        F(u16, 0x94) = 0xFFFF;
        F(void *, 0x2A8) = 0;
        F(void *, 0x3B0) = 0;
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
}

void TObjNpcBase::update_wandering() {
    u8 *arg0 = (u8 *)this;
    switch (this->phase) {
    case 0: {
        Vec_801489B8 v;
        s32 angle;
        f32 s;
        v.y = 0.0f;
        v.x = 0.0f;
        v.z = 1.0f;
        angle = (s32)(182.04445f * (360.0f * random_ratio__9TObjCharaFv()));
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle);
        rotate_vector_by_matrix(0, &v, &v);
        pop_matrix();
        v.x = v.x * *(f32 *)((s8 *)arg0 + 0x354);
        v.z = v.z * *(f32 *)((s8 *)arg0 + 0x354);
        vec3_add_to(&v, (u8 *)&this->home_position);
        if (100.0f < horizontal_distance_squared(&v, (u8 *)&this->position)) {
            Vec_801489B8 d = v;
            select_enemy_destination(arg0, &d, 0);
            *(f32 *)((s8 *)arg0 + 0x308) = this->m_310 = 0.0f;
            this->phase = 1;
            this->request_action(1);
        }
        break;
    }
    case 1: {
        u8 *o;
        f32 r;
        enemy_turn_toward_dest(arg0, *(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8));
        enemy_set_heading_velocity(*(f32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 4), (TObjEnemy *)arg0, this->rotation_y);
        move_with_wall_slide(arg0);
        if (((TObjMotion *)arg0)->is_passing_frame(1.0f) != 0 || ((TObjMotion *)arg0)->is_passing_frame(15.0f) != 0) {
            this->play_voice();
        }
        {
            f32 dist = horizontal_distance_squared((u8 *)&this->m_29c, (u8 *)&this->m_2fc);
            r = *(f32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 4) + *(f32 *)((s8 *)(*(u8 * *)&this->bodies) + 0xC);
            if (dist < r * r || (*(u32 *)((s8 *)(*(u8 * *)&this->bodies) + 0x18) & 0x380000)) {
                this->phase = 3;
                this->request_action(0);
            }
        }
        break;
    }
    case 2:
        break;
    case 3:
        (*(s32 *)&this->m_2ac)++;
        if (120.0f < (f32) *(s32 *)&this->m_2ac) {
            this->phase = 0;
            *(s32 *)&this->m_2ac = 0;
        }
        break;
    }
    ((TObjPlayer *)arg0)->update_collisions();
}

void TObjNpcBase::update_standing() {
    u8 *arg0 = (u8 *)this;
    switch (this->phase) {
    case 0:
        if (this->rotation_y != this->m_384) {
            this->phase = 2;
            this->request_action(1);
        } else {
            this->phase = 1;
            this->request_action(0);
        }
        break;
    case 1:
        break;
    case 2:
        if (this->rotation_y != this->m_384) {
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_384, *(s32 *)((s8 *)this->movementParameters + 8));
        } else {
            this->phase = 1;
            this->request_action(0);
        }
        break;
    }
}

void TObjNpcBase::vfunc_59() {
    s16 temp_r0;
    temp_r0 = this->mode;
    if ((temp_r0 >= 4) || (temp_r0 < 1)) {
        if ((s32) this->variant != 1) {
            this->mode = 1;
            this->phase = 0;
            this->request_action(0);
            return;
        }
        this->mode = 2;
        this->phase = 0;
        this->request_action(0);
    }
}

void TObjNpcBase::vfunc_83() {  }
}

void TObjNpcBase::vfunc_58() {
    if (mode != 0) {
        mode = 0;
        phase = 0;
        this->request_action(0);
    }
}

// ---- src/pso/player/TObjPlayer_80148DCC.cpp

struct VBase_18_3eea3b
{
  char pad[0x18];
};

struct VObj_18_3eea3b : VBase_18_3eea3b {
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
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual s32 m81();
    virtual s32 m82();
    virtual s32 m83();
    virtual s32 m84();
};

extern "C" {
void draw_chunk_object(void *child);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
u16 find_nearest_visible_player(void *, s32, f32 *, f32);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
s32 push_matrix_from(void *src);
s32 pop_matrix();

void TObjNpcBase::vfunc_28() {
    f32 *temp_r5;

    if ((s16) this->mode != 3) {
        if (this->is_actor_cadence_frame(30) != 0) {
            temp_r5 = *(f32 * *)&this->movementParameters;
            this->targetId = find_nearest_visible_player(this, 0, temp_r5, *temp_r5);
            {
                u32 tmp338 = (u32) this->targetId;
                if (tmp338 != 0xFFFF) {
                    *(s32 *)&this->target = (s32)get_player_by_client_id(tmp338);
                } else {
                    this->target = 0;
                }
            }
        }
    }
}

extern s32 model_render_flags;

void TObjNpcBase::render() {
    if ((this->update_object_view_visibility(this->m_398, this->m_39c) != 0) && ((s32) this->m_390 == 1)) {
        select_actor_lighting((s32) this);
        model_render_flags |= 1;
        TObjFish::set_global_param(this->texlist);
        push_matrix_from(0);
        translate_matrix_vec3(0, (u8 *) &this->position);
        rotate_matrix_y(0, this->rotation_y);
        set_motion_packed_rotation();
        if ((s32) this->m_394 != 0) {
            draw_chunk_object(this->model);
        } else {
            this->draw();
        }
        clear_motion_packed_rotation();
        pop_matrix();
        model_render_flags &= ~1;
        restore_scene_lighting();
        this->draw_ground_shadow(0, 0);
    }
}
typedef struct VBase_18_3eea3b VBase_18_3eea3b;
typedef struct VObj_18_3eea3b VObj_18_3eea3b;
void TObjNpcBase::run_task() {
  s32 temp_r4;
  s32 temp_r4_2;
  u8 *new_var;
  u8 *var_r31;
  if ((((s32) (*((s32 *) (((s8 *) ((u8 *)this)) + ((((((((((0x3A0 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu))))) <= 0) && (((s32)this->m_3a4) <= 0))
  {
    this->m_390 = 1;
    set_indexed_flags(0, 1);
  }
  else
  {
    if (((s32)this->m_38c) == 0)
    {
      var_r31 = (u8 *) quest_mission_manager;
    }
    else
    {
      var_r31 = (u8 *) quest_area_manager;
    }
    temp_r4 = this->m_3a0;
    if (temp_r4 > 0)
    {
      if (TQuestThread::get_register(var_r31, temp_r4) != 0)
      {
        this->m_390 = 1;
        set_indexed_flags(0, 1);
      }
      else
      {
        this->m_390 = 0;
        this->clear_player_status_flag(0, 1U);
      }
    }
    temp_r4_2 = this->m_3a4;
    if ((temp_r4_2 > 0) && (TQuestThread::get_register(var_r31, temp_r4_2) != 0))
    {
      this->m_390 = 0;
      this->clear_player_status_flag(0, 1U);
    }
  }
  switch (this->mode)
  {
    case 0:
      (this->vfunc_83());
      break;
    case 1:
      (this->update_standing());
      break;
    case 2:
      (this->update_wandering());
      break;
    case 3:
      (this->update_conversation());
      break;
  }
  advance_animation();
  this->update_prev_position();
  new_var = ((u8 *)this);
  ((TBoss3VoloptHiraisin *)new_var)->copy_position();
  if ((((s32)this->m_3a8) > 0) && (TRaderMapCore::is_not_split_screen() == 0))
  {
    submit_cursor_candidate((void *) this, -1);
  }
  this->obj_clearFlags30(0x1B3FU);
}

}

// ---- src/pso/npc/TObjNpcBase_801490F4.cpp

extern u32 npc_town_motion_data;

void TObjNpcBase::free_static() {
    if ((u32) npc_town_motion_data != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)npc_town_motion_data));
        npc_town_motion_data = 0U;
    }
}

// ---- src/pso/npc/TObjNpcBase_80149128.cpp

extern "C" {
    int load_encrypted_archive_data(const char *);
void load_ply_motion_npc_town(void) { npc_town_motion_data = load_encrypted_archive_data("PlyMotionNpcTown.cpt"); }
}

// ---- src/pso/npc/TObjNpcBase.cpp

struct Npc_801491B4 {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    u8 pad1C[0x30 - 0x1C];
    s32 f30;
    u8 pad34[0x98 - 0x34];
    u8 sub98[0x326 - 0x98];
    s16 f326;
    u8 pad328[0x358 - 0x328];
    f32 f358;
    f32 f35C;
    f32 f360;
    f32 f364;
    u8 pad368[0x388 - 0x368];
    s32 f388;
    s32 f38C;
    s32 f390;
    s32 f394;
    f32 f398;
    f32 f39C;
    s32 f3A0;
    s32 f3A4;
    s32 f3A8;
    s32 f3AC;
    s32 f3B0;
    s32 f3B4;
};

extern "C" {
void __ct__9TObjEnemyFP7TObject(void *, void *, void *);
void TObjNpcBase__sub_80149368(void* p);
extern s32 __vt__11TObjNpcBase[];
void *TObjNpcBase__ct(void *arg0, void *arg1, void *arg2);
s32 play_sound_effect(s32, s32, s32, s32);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);

}

TObjNpcBase::~TObjNpcBase() {
    free_collision_body_parts(this);
}

extern "C" {

#define self ((Npc_801491B4 *)arg0)
void *TObjNpcBase__ct(void *arg0, void *arg1, void *arg2) {
    __ct__9TObjEnemyFP7TObject(arg0, arg1, arg2);
    self->vt = __vt__11TObjNpcBase;
    self->f0 = (s32)TObjNpcBase__name;
    self->f388 = 0;
    self->f390 = 1;
    switch (get_current_floor_area()) {
    case AREA_LOBBY:
        self->f394 = 1;
        break;
    default:
        self->f394 = 0;
        break;
    }
    self->f326 = 0;
    self->f30 = 0x44000000;
    self->f38C = 0;
    if (1000.0f <= self->f358) {
        self->f38C = 1;
        self->f3A0 = self->f358 - 1000.0f;
    } else {
        self->f3A0 = self->f358;
    }
    if (1000.0f <= self->f35C) {
        self->f38C = 1;
        self->f3A4 = self->f35C - 1000.0f;
    } else {
        self->f3A4 = self->f35C;
    }
    self->f3A8 = self->f364;
    self->f3AC = self->f360;
    self->f398 = 400.0f;
    self->f39C = 20.0f;
    TObjNpcBase__sub_80149368(self->sub98);
    self->f3B0 = 0;
    self->f3B4 = 0;
    return arg0;
}
#undef self

void TObjNpcBase::request_action(s32) {  }
void TObjNpcBase::play_voice() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x40003804, arg0 + 0x38, 0, 0);
}
void TObjNpcBase::sub_80149358(s32 v) { this->m_3ac = v; }
void TObjNpcBase::sub_80149360(s32 v) { this->m_3a8 = v; }
void TObjNpcBase__sub_80149368(void* p) { *(s32*)((char*)p + 0x0) = 2; }

}

// ---- src/pso/misc/TNpcPlayer_80149374.cpp

extern "C" {

void TNpcPlayer::send_6x3E() {
    s32 arg0 = (s32)this;
    bswap_6x3E();
    send_subcommand((u8 *)arg0);
}
void TNpcPlayer::bswap_6x3E() {
    s32 arg0 = (s32)this;
    ((G_ClientIDHeader *)this)->bswap();
    bswap_16((u16 *)(arg0 + 4));
    bswap_16((u16 *)(arg0 + 6));
    bswap_16((u16 *)(arg0 + 8));
    bswap_16((u16 *)(arg0 + 0xA));
    bswap_32((u32 *)(arg0 + 0xC));
    bswap_32((u32 *)(arg0 + 0x10));
    bswap_32((u32 *)(arg0 + 0x14));
}
void TNpcPlayer::init_6x3E_packet() { *(short *)&this->m_flags = 0; *(short *)&this->m_id = 0; *(short *)&this->m_prev = -1; *(short*)((char*)this + 0xa) = -1; *(float *)&this->m_down = 0.0f; *(float *)&this->m_up = 0.0f; *(float *)&this->m_next = 0.0f; *(unsigned char *)&this->m_name = 62; *(unsigned char*)((char*)this + 0x1) = 6; }
void TObjNpcBringer::request_action(s32) {
    if ((s16) this->mode != 2) {
        this->requested_action = 0;
        return;
    }
    this->requested_action = 1;
}

}
