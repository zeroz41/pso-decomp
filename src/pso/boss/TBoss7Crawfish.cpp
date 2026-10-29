#include <dolphin/mtx.h>
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/object/TObjMotion.h"
#include "pso/unk/text_803D853C.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"
#include "types.h"

#include <stddef.h>
#include "pso/boss/TBoss7Crawfish.h"
#include "pso/object/TObjOnlineEnding.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"

struct Stack_80308B38 {
    s32 sp8;
    u8 pad_C[0x2];
    s16 spE;
};

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_80308840_lbl_8047559C {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80308840_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct Vec_803086A8 { f32 x; f32 y; f32 z; };

struct Msg_803086A8 { void *p; s32 one; Vec_803086A8 pos; s32 id; };

struct Slot_803086A8 { u32 a; s32 b; };

struct Obj_803086A8 { u8 pad[0x3A4]; s32 count; Slot_803086A8 slots[4]; };

struct VBase_18_405891 { char pad[0x18]; };
struct VObj_18_405891 : VBase_18_405891 {
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
    virtual s32 m18(s32, f32);
    virtual void m19();
    virtual s32 m20(s32, f32);
    virtual s32 m21(s32, s32 *, s32, s32, s32);
};

struct Pair_8030895C { s32 id; f32 v; };

extern "C" {
s32 obj_isState2_324__9TObjCharaFv(int);
int rand(void);
extern s32 game_difficulty_selection;
extern const f32 TBoss7Crawfish__data_805DF0DC;
extern const f32 lbl_805DF0E0;
extern const f32 lbl_805DF0E4;
extern const f32 lbl_805DF0E8;

extern const f32 TBoss7Crawfish__data_805DF0D8;
s32 exchange_object_state__9TObjEnemyFls(void *, void *, int);
s32 get_mode__11TCameraCtrlFPv(void *);
f32 horizontal_distance_squared(void *, void *);
extern RecoveredGlobal_80308840_lbl_8047559C lbl_8047559C;
extern const f32 lbl_805DF0CC;
extern const f32 lbl_805DF0D0;
extern const f32 lbl_805DF0D4;
s32 obj_is_hit_receivable(u32);
s32 reset_global_table();
Slot_803086A8 *get_attack_entry__16TObjOnlineEndingFi(s32);
s32 apply_hit_to_target__14TBoss7CrawfishFPvPv(void *, void *);
void TBoss7Crawfish__sub_803087D4(s32 arg0, s32 arg1);
int TBoss7Crawfish__sub_80308BEC(void* p);
s32 play_sound_effect(s32, s32, s32, s32);
int change_state__14TBoss7CrawfishFl(void*, int);
int scale_current_matrix(void*);
int post_translate_matrix(void*);
int push_matrix(void);
s32 pop_matrix(void);

extern f32 lbl_805DF0C8;

s32 TBoss7Crawfish::sub_80308688() {
    return (u32) __cntlzw((u32) (lbl_805DF0C8 < *(f32 *)((s8 *)this + 0x38))) >> 5;
}

void TBoss7Crawfish::register_attack_hits() {
    Msg_803086A8 msg;
    s32 i;
    Slot_803086A8 *e;
    s32 j;
    reset_global_table();
    msg.p = (u8 *)this + 0x374;
    msg.one = 1;
    VecCopy((Vec *)&msg.pos, (const Vec *)((u8 *)this + 0x38));
    msg.id = this->rotation_y;
    TObjPlayer::apply_status_effect((s32)&msg);
    for (i = 0; i != TObjOnlineEnding::get_instance(); i++) {
        if ((u32)((Obj_803086A8 *)this)->count < 4) {
            e = get_attack_entry__16TObjOnlineEndingFi(i);
            for (j = 0; j != ((Obj_803086A8 *)this)->count; j++) {
                if (((Obj_803086A8 *)this)->slots[j].a == e->a && ((Obj_803086A8 *)this)->slots[j].b == e->b) {
                    break;
                }
            }
            if (j == ((Obj_803086A8 *)this)->count && obj_is_hit_receivable(e->a) != 0) {
                ((Obj_803086A8 *)this)->slots[((Obj_803086A8 *)this)->count].a = e->a;
                ((Obj_803086A8 *)this)->slots[((Obj_803086A8 *)this)->count].b = e->b;
                ((Obj_803086A8 *)this)->count++;
                apply_hit_to_target__14TBoss7CrawfishFPvPv(((Obj_803086A8 *)this), e);
            }
        }
    }
    reset_global_table();
}

void TBoss7Crawfish__sub_803087D4(s32 arg0, s32 arg1) {
    play_persistent_sound(arg1, arg0, arg0 + 0x38, 0, 0);
}

void TBoss7Crawfish::spawn_effect(s32 arg1) {
    s32 arg0 = (s32)this;
    play_sound_effect(arg1, arg0 + 0x38, 0, 0);
}

typedef char RecoveredGlobal_80308840_lbl_8047559C_size[sizeof(RecoveredGlobal_80308840_lbl_8047559C) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80308840_main_task_size[sizeof(RecoveredGlobal_80308840_main_task) == 0x34 ? 1 : -1];
s32 TBoss7Crawfish::is_visible() {
    if (get_mode__11TCameraCtrlFPv(&(*(RecoveredGlobal_80308840_main_task *)&main_task).value) & 0x20) {
        if (lbl_805DF0CC < horizontal_distance_squared(&lbl_8047559C.value, ((u8 *)this) + 0x38)) {
            return 0;
        }
        goto block_5;
    }
    if (((VObj_18_26a62c *)(this))->m8(lbl_805DF0D0, lbl_805DF0D4) == 0) {
        return 0;
    }
block_5:
    return 1;
}

void TBoss7Crawfish::free_child() { if (*(unsigned int *)&this->m_3cc != 0) { queue_destruction__7TObjectFv((*(void* *)&this->m_3cc)); *(int *)&this->m_3cc = 0; } }

void TBoss7Crawfish::spawn_ground_effects() {
    u8 *arg0 = (u8 *)this;
    Vec position;
    position.x = *(f32 *)((s8 *)arg0 + 0x38);
    position.y = TBoss7Crawfish__data_805DF0D8;
    position.z = *(f32 *)((s8 *)arg0 + 0x40);
    spawn_particle_effect((&position.x), 0x20D);
    spawn_particle_effect((&position.x), 0x20E);
}

#define arg0 ((s32)arg0_)
#define arg1 ((u8 *)arg1_)
s32 apply_hit_to_target__14TBoss7CrawfishFPvPv(void *arg0_, void *arg1_) {
    Pair_8030895C p;

    u8 *temp_r31;

    if (arg1 != NULL) {
        temp_r31 = (u8 *)(*(u8 **)((s8 *)arg1 + 0));
        if (((TBoss7Crawfish *)arg0_)->sub_80308AA8() != 0) {
            if (((VObj_18_405891 *)(temp_r31))->m18(arg0, TBoss7Crawfish__data_805DF0DC) != 0) {
                ((VObj_18_405891 *)(temp_r31))->m20(arg0, TBoss7Crawfish__data_805DF0DC);
            }
        } else if (obj_isState2_324__9TObjCharaFv((int)temp_r31) == 0) {
            if ((s32) game_difficulty_selection == 3) {
                if ((lbl_805DF0E0 * (f32) rand()) <= lbl_805DF0E4) {
                    p.id = 0x10;
                } else {
                    p.id = 0x10;
                }
            } else {
                p.id = 0x12;
            }
            p.v = lbl_805DF0E8;
            {
                Pair_8030895C q = p;
                ((VObj_18_405891 *)(temp_r31))->m21(arg0, (s32 *)&q, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg1 + 0)) + 0xA4) + (*(s32 *)((s8 *)arg1 + 4) * 0x2C), -1, -1);
            }
        }
    }
}
#undef arg0
#undef arg1

s32 TBoss7Crawfish::sub_80308AA8() {
    return TBoss7Crawfish__data_805DF0D8 == *(f32 *)((s8 *)((u8 *)this) + 0x354);
}

void TBoss7Crawfish::render() { if (is_visible() != 0) { set_texlist(this->texlist); set_motion_packed_rotation(); push_matrix(); post_translate_matrix((char*)this + 0x38); rotate_matrix_yxz((s32)((void*)0), (s32)this->rotation_x, this->rotation_y, this->rotation_z); scale_current_matrix((char*)this + 0x68); draw(); pop_matrix(); clear_motion_packed_rotation(); } }

extern const f32 lbl_805DF0EC;

void TBoss7Crawfish::clear_object_state_exchange() {
    s32 arg0 = (s32)this;
    typedef char sp8_offset[(offsetof(Stack_80308B38, sp8) == 0x0) ? 1 : -1];
    typedef char spE_offset[(offsetof(Stack_80308B38, spE) == 0x6) ? 1 : -1];
    Stack_80308B38 stack;
    if (exchange_object_state__9TObjEnemyFls((void *)arg0, &stack.sp8, 1) != 0) {
        stack.sp8 = 0;
        stack.spE = 0;
        exchange_object_state__9TObjEnemyFls((void *)arg0, &stack.sp8, 0);
    }
}

void TBoss7Crawfish::check_band_and_destroy() {
    s32 arg0 = (s32)this;
    if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DF0EC) != 0) {
        spawn_ground_effects();
    }
    if (TBoss7Crawfish__data_805DF0D8 == ((TBoss7Crawfish *)arg0)->get_health()) {
        queue_destruction__7TObjectFv((void *)arg0);
    }
}

int TBoss7Crawfish__sub_80308BEC(void* p) { return change_state__14TBoss7CrawfishFl(p, 5); }

}
