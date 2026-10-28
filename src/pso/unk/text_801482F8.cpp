#include "types.h"
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/TObject.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestThread.h"

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
f32 calc_boss4_scale__10TObjPlayerFi();
void enemy_set_heading_velocity(TObjEnemy *arg0, s32 arg1, f32 farg0);
void select_enemy_destination(void *, void *, s32);
void enemy_turn_toward_dest(void *, s32);
f32 horizontal_distance_squared(void *, void *);
void vec3_add_to(void *, void *);
void rotate_vector_by_matrix(int, void *, void *);
void rotate_matrix_y(int, int);
s32 push_matrix_from(void *src);
s32 pop_matrix(void);
extern u8 identity_matrix[];
extern const f32 lbl_805DB1C4;
extern const f32 lbl_805DB1C8;
extern const f32 lbl_805DB1CC;
extern const f32 lbl_805DB1D0;
extern const f32 lbl_805DB1D4;
extern const f32 lbl_805DB1D8;
extern const f32 lbl_805DB1DC;
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
u32 get_player_by_client_id();
void *__nw__7TObjectFUl(u32);
s32 subtract_vector(void *, void *);
extern const f64 lbl_8043F550[];
extern s32 local_client_id;
extern u32 quest_mission_manager;
extern u32 quest_area_manager;
extern const f32 lbl_805DB1B8;
extern const f32 lbl_805DB1BC;
extern const f32 lbl_805DB1C0;
s32 has_interactor__14TObjCollidableFv();
s32 debug_printf_at(s32, const char *, ...);
extern char lbl_8043F544[];
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);

void TObjNpcFemaleBase::handle_message_event(u16 arg1) {
    u32 temp_r3;

    if ((s32) this->m_3a8 > 0) {
        if ((s32) arg1 == (s32) local_client_id) {
            temp_r3 = get_player_by_client_id();
            if ((temp_r3 != 0U) && ((s16) this->mode != 3)) {
                this->mode = 3;
                this->phase = 0;
                this->interactor = arg1;
                this->targetId = arg1;
                *(u32 *)&this->target = temp_r3;
                if ((s32) this->targetId == (s32) local_client_id) {
                    play_effect_default__10TObjPlayerFii(temp_r3, -1);
                }
                ((VObj18_801482f8 *) this)->vf160(1);
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
    if ((has_interactor__14TObjCollidableFv() != 0) && (((u32 (*)(u16))get_player_by_client_id)(this->interactor) != 0)) {
        debug_printf_at(0x1A0020, lbl_8043F544);
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
    if (lbl_805DB1B8 <= *(f32 *)((s8 *)arg0 + 0x358)) {
        this->m_38c = 1;
        this->m_3a0 = (s32) (*(f32 *)((s8 *)arg0 + 0x358) - lbl_805DB1B8);
    } else {
        this->m_3a0 = (s32) *(f32 *)((s8 *)arg0 + 0x358);
    }
    if (lbl_805DB1B8 <= *(f32 *)((s8 *)arg0 + 0x35C)) {
        this->m_38c = 1;
        this->m_3a4 = (s32) (*(f32 *)((s8 *)arg0 + 0x35C) - lbl_805DB1B8);
    } else {
        this->m_3a4 = (s32) *(f32 *)((s8 *)arg0 + 0x35C);
    }
    ((TObjNpcBase *)arg0)->sub_80149360((s32) *(f32 *)((s8 *)arg0 + 0x364));
    ((TObjNpcBase *)arg0)->sub_80149358((s32) *(f32 *)((s8 *)arg0 + 0x360));
    this->m_384 = (s32) this->rotation_y;
    if ((s32) this->m_3ac > 0) {
        *(f32 *)&this->unk_398 = (f32) lbl_805DB1BC;
        return;
    }
    *(f32 *)&this->unk_398 = (f32) lbl_805DB1C0;
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
        ang = lbl_8043F550[0] * atan2_float(d.x, d.z);
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
                p = ((u32 (*)(s32))get_player_by_client_id)(local_client_id);
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
        v.y = lbl_805DB1C4;
        v.x = lbl_805DB1C4;
        v.z = lbl_805DB1C8;
        angle = (s32)(lbl_805DB1CC * (lbl_805DB1D0 * calc_boss4_scale__10TObjPlayerFi()));
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle);
        rotate_vector_by_matrix(0, &v, &v);
        pop_matrix();
        v.x = v.x * *(f32 *)((s8 *)arg0 + 0x354);
        v.z = v.z * *(f32 *)((s8 *)arg0 + 0x354);
        vec3_add_to(&v, (u8 *)&this->home_position);
        if (lbl_805DB1D4 < horizontal_distance_squared(&v, (u8 *)&this->position)) {
            Vec_801489B8 d = v;
            select_enemy_destination(arg0, &d, 0);
            *(f32 *)((s8 *)arg0 + 0x308) = this->m_310 = lbl_805DB1C4;
            this->phase = 1;
            ((VObj18_801489B8 *) arg0)->vf160(1);
        }
        break;
    }
    case 1: {
        u8 *o;
        f32 r;
        enemy_turn_toward_dest(arg0, *(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8));
        enemy_set_heading_velocity((TObjEnemy *)arg0, this->rotation_y, *(f32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 4));
        move_with_wall_slide(arg0);
        if (objInBand((GameObj *)arg0, (f32)lbl_805DB1C8) != 0 || objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805DB1D8)) != 0) {
            this->play_voice();
        }
        {
            f32 dist = horizontal_distance_squared((u8 *)&this->m_29c, (u8 *)&this->m_2fc);
            r = *(f32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 4) + *(f32 *)((s8 *)(*(u8 * *)&this->bodies) + 0xC);
            if (dist < r * r || (*(u32 *)((s8 *)(*(u8 * *)&this->bodies) + 0x18) & 0x380000)) {
                this->phase = 3;
                ((VObj18_801489B8 *) arg0)->vf160(0);
            }
        }
        break;
    }
    case 2:
        break;
    case 3:
        (*(s32 *)&this->m_2ac)++;
        if (lbl_805DB1DC < (f32) *(s32 *)&this->m_2ac) {
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
            ((VObj18_801482f8 *) arg0)->vf160(1);
        } else {
            this->phase = 1;
            ((VObj18_801482f8 *) arg0)->vf160(0);
        }
        break;
    case 1:
        break;
    case 2:
        if (this->rotation_y != this->m_384) {
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_384, *(s32 *)((s8 *)this->movementParameters + 8));
        } else {
            this->phase = 1;
            ((VObj18_801482f8 *) arg0)->vf160(0);
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
            ((VObj18_801482f8 *) this)->vf160(0);
            return;
        }
        this->mode = 2;
        this->phase = 0;
        ((VObj18_801482f8 *) this)->vf160(0);
    }
}

void TObjNpcBase::vfunc_83() {  }
}

void TObjNpcBase::vfunc_58() {
    if (mode != 0) {
        mode = 0;
        phase = 0;
        ((VObj18_801482f8 *)this)->vf160(0);
    }
}
