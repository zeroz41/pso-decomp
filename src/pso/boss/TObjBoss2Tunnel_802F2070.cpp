#include "types.h"
#include "pso/boss/TUnk_804E4B3C.h"
#include "pso/boss/TunnelSceneController.h"

#include <stddef.h>
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/item/TItemEffOrgaFlowShot.h"

struct Stack_802F2664 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct Nd_802F2348 { u8 pad[0xC]; Nd_802F2348 *next; };

struct Li_802F2348 { u8 pad[0x14]; Nd_802F2348 *head; };

struct Vec_802F25AC { f32 x, y, z; };

// count + index list; fn_802F1FB0 copies both into the effect object it builds
struct Boss2TunnelEffectEntry {
    s32 count;
    const s32 *indices;
};

extern const s32 lbl_804743B0[];
extern const s32 lbl_804743BC[];
extern const s32 lbl_804743CC[];
extern const s32 lbl_804743D8[];
extern const s32 lbl_804743E4[];

Boss2TunnelEffectEntry boss2_tunnel_effect_name_table[5] = {
    {3, lbl_804743B0},
    {4, lbl_804743BC},
    {3, lbl_804743CC},
    {3, lbl_804743D8},
    {4, lbl_804743E4},
};
s32 boss2_tunnel_spawn_timer_table[0x1F] = {
    2, 1, 2, 1, 1, 2, 2, 1, 2, 1, 2, 2, 1, 1, 1, 2,
    1, 2, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1,
};
s32 boss2_tunnel_spawn_timer_table_b[10] = {1, 1, 3, 4, 3, 3, 3, 3, 3, 3};
// y is filled in by the static initializer at 0x802F2CC4
Vec_802F25AC lbl_804E4A44[2] = {
    {78.0f, 0.0f, 83.0f},
    {-78.0f, 0.0f, 83.0f},
};

u32 boss2_tunnel_state_flags;
s32 lbl_805D696C;
s8 lbl_805D6970;

extern "C" {
u32 __nw__7TObjectFUl(s32);
s32 fn_802F1FB0(void *, s32, s32, f32, s32);
void spawn__13TUnk_804E4B3CFll(void *arg0, s32 arg1, s32 arg2);
void TObjBoss2Tunnel__sub_802F2278(void);
s32 TObjBoss2Tunnel__sub_802F22F4(void);
void queue_destruction__7TObjectFv(void *arg0);
extern const f32 lbl_805DEC68;
extern const f32 lbl_805DEC98;
extern const f32 lbl_805DEC9C;
extern const f32 lbl_805DECA8;
extern const f32 lbl_805DECB8;
extern const f32 lbl_805DECBC;
extern const f32 lbl_805DECC0;
extern const f32 lbl_805DECC4;
extern const f32 lbl_805DECC8;
extern const f32 lbl_805DECCC;
extern const f32 lbl_805DECD0;
extern const f32 lbl_805DECD4;
extern const f32 lbl_805DECD8;
extern const f32 lbl_805DECDC;
extern const f32 lbl_805DECE0;
extern const f32 lbl_805DECE4;
extern const f32 lbl_805DECB4;
extern const f32 lbl_805DECFC;
s32 TObjBoss2Tunnel__sub_8007DEE4(void *, f32, f32, f32, f32, f32);
s32 advance_phase__15TObjBoss2TunnelFv(void *, void *);
f32 fabs_float(f32);
f32 update_position__15TObjBoss2TunnelFv(void *);
extern const f32 lbl_805DECF8;
extern const f32 lbl_805DED00;
extern const f32 lbl_805DED04;
extern const f32 lbl_805DED08;
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
extern s32 lbl_804E4B3C[];
void TObjBoss2Tunnel__sub_802F2C4C(void);
extern s32 tl_04;
void TObjBoss2Tunnel__sub_802F2C50(void);
void TObjBoss2Tunnel__sub_802F2C84(void);
void TObjBoss2Tunnel__sub_802F22DC(void);
void TObjBoss2Tunnel__sub_802F22C4(void);
s32 query_teammate_state__9TObjEneDDFv();
void draw_particle_effect(void *a0);
void draw_tunnel_segment(u8 *arg0);
void fn_802F1DAC(u8 *arg0);
void fn_802F1E54(u8 *arg0);
s32 is_split_screen();
s32 get_current_floor();
s32 reset_floats__15TObjBoss2TunnelFv(void *);
s32 reset_floats__15TObjBoss2TunnelFl(void *);
s32 is_room_enemy_set_cleared(s32, int);
u32 __ct__7TObjectFP7TObject(void *, void *);
s32 TObjBoss7RaftSplash__ct(void *, void *, void *, void *, void *);
s32 TObjBoss2Tunnel__sub_802F1AE0(void *, u32, int);
u32 TObjBoss7TunnelCol__ct(void *, void *);

extern u8 TObjBoss2Tunnel__raft_splash_offset_table[];
extern const f32 lbl_805DED0C;
extern const f32 lbl_805DED10;
void *TObjBoss2Tunnel__sub_802F2A2C(void *arg0p, s32 parent);
f32 rand_signed_unit();
u8 *__ct__13TObjBoss7DustFv(u8 *arg0, s32 arg1, s32 arg2);
s32 rand();
extern s32 tl_05;
s32 TObjBoss2Tunnel__sub_802F2070(void);

s32 TObjBoss2Tunnel__sub_802F2070(void) {
    return ((u32) boss2_tunnel_state_flags >> 0xFU) & 1;
}
}
struct TunnelVector3 { f32 x,y,z; };
 extern const f32 lbl_805DEC9C,lbl_805DECAC,lbl_805DECB0,lbl_805DECB4; void TunnelSceneController::spawn_segment_row_a() {
    TunnelVector3 position;
    position.x=segment_x;
    position.y=lbl_805DEC9C;
    for (position.z=half_length;position.z > -half_length;position.z-=lbl_805DECB4) {
        if (lbl_805DECAC > position.z && position.z > lbl_805DECB0) {
            ((void (*)(void*,s32,TunnelVector3*))spawn__13TUnk_804E4B3CFll)(this,4,&position);
        } else {
            ((void (*)(void*,s32,TunnelVector3*))spawn__13TUnk_804E4B3CFll)(this,3,&position);
        }
    }
}

void TunnelSceneController::spawn_segment_row_b() {
    TunnelVector3 position;
    position.x=segment_x;
    position.y=lbl_805DEC9C;
    for (position.z=half_length;position.z > -half_length;position.z-=lbl_805DECB4) {
        if (lbl_805DECAC > position.z && position.z > lbl_805DECB0) {
            ((void (*)(void*,s32,TunnelVector3*))spawn__13TUnk_804E4B3CFll)(this,0,&position);
        } else {
            ((void (*)(void*,s32,TunnelVector3*))spawn__13TUnk_804E4B3CFll)(this,2,&position);
        }
    }
}

void TUnk_804E4B3C::spawn(s32 arg1, s32 arg2) {
    void *new_obj = (void *) __nw__7TObjectFUl(0x78);
    if ((u32) new_obj != 0U) {
        fn_802F1FB0(new_obj, *(s32 *)((s8 *)this + 0x8C), arg1, this->m_84, arg2);
    }
}
void TObjBoss2Tunnel__sub_802F2278(void) { (*(int *)&boss2_tunnel_state_flags) = ((*(int *)&boss2_tunnel_state_flags) | 0x8); }
void TObjBoss2Tunnel::set_flag_0x200() { (*(int *)&boss2_tunnel_state_flags) = ((*(int *)&boss2_tunnel_state_flags) | 0x200); TObjBoss2Tunnel::clear_flags_0x3000(); }
void TObjBoss2Tunnel::clear_flags_0x3000() { (*(int *)&boss2_tunnel_state_flags) = ((*(int *)&boss2_tunnel_state_flags) & 0xffffcfff); }

void TObjBoss2Tunnel__sub_802F22C4(void) {
    boss2_tunnel_state_flags |= 0x2000;
    boss2_tunnel_state_flags &= ~0x1000;
}

void TObjBoss2Tunnel__sub_802F22DC(void) {
    boss2_tunnel_state_flags |= 0x1000;
    boss2_tunnel_state_flags &= ~0x2000;
}

s32 TObjBoss2Tunnel__sub_802F22F4(void) {
    return ((u32) boss2_tunnel_state_flags >> 0xDU) & 1;
}
s32 TObjBoss2Tunnel::is_phase_active(s32 _w0) {
    return ((u32) boss2_tunnel_state_flags >> 0xCU) & 1;
}
s32 TObjBoss2Tunnel::check_both(s32 arg0) {
    s32 temp_r31;
    s32 temp_r3;
    temp_r31 = TObjBoss2Tunnel__sub_802F22F4();
    temp_r3 = TObjBoss2Tunnel::is_phase_active(arg0);
    return temp_r3 | temp_r31;
}

void TUnk_804E4B3C::render() {
    u8 *arg0 = (u8 *)this;
    Nd_802F2348 *n;
    if (query_teammate_state__9TObjEneDDFv() == 0) {
        for (n = (*(Li_802F2348 **)((s8 *)arg0 + 0x90))->head; n != 0; n = n->next) {
            draw_particle_effect(n);
        }
        for (n = (*(Li_802F2348 * *)&this->m_8c)->head; n != 0; n = n->next) {
            fn_802F1E54((u8 *)n);
        }
        for (n = (*(Li_802F2348 * *)&this->m_8c)->head; n != 0; n = n->next) {
            fn_802F1DAC((u8 *)n);
        }
        for (n = (*(Li_802F2348 * *)&this->m_8c)->head; n != 0; n = n->next) {
            draw_tunnel_segment((u8 *)n);
        }
    }
}

void TUnk_804E4B3C::sub_802F23FC() {  }
void TUnk_804E4B3C::sub_802F2400() {
    f32 temp_f1;
    TObject *temp_r3;
    update_spawn_timer((s32)boss2_tunnel_spawn_timer_table_b, 0xA, 1);
    if ((*(s32 *)&boss2_tunnel_state_flags) & 8) {
        temp_f1 = unk_80;
        if (temp_f1 < lbl_805DEC98) {
            unk_1C = 2;
            *(f32 *)((s8 *)this + 0x5C) = (f32) lbl_805DEC9C;
            unk_54 = (f32) lbl_805DECB8;
            temp_r3 = unk_88;
            if (temp_r3 != NULL) {
                queue_destruction__7TObjectFv(temp_r3);
                unk_88 = NULL;
            }
            (*(s32 *)&boss2_tunnel_state_flags) |= 0x8000;
            return;
        }
        if (temp_f1 < lbl_805DECBC) {
            TItemEffOrgaFlowShot::approach_value((f32 *)((s8 *)this + 0x5C), (f32)lbl_805DECC0, (f32)((f32) (lbl_805DECC4 * lbl_805DEC68)));
            TItemEffOrgaFlowShot::approach_value(&unk_54, (f32)lbl_805DECC8, (f32)lbl_805DECB8);
            return;
        }
        if (temp_f1 < lbl_805DECCC) {
            TItemEffOrgaFlowShot::approach_value((f32 *)((s8 *)this + 0x5C), (f32)lbl_805DECD0, (f32)((f32) (lbl_805DECD4 * lbl_805DEC68)));
            TItemEffOrgaFlowShot::approach_value(&unk_54, (f32)lbl_805DECC8, (f32)lbl_805DECD8);
            return;
        }
        if (temp_f1 < lbl_805DECA8) {
            TItemEffOrgaFlowShot::approach_value((f32 *)((s8 *)this + 0x5C), (f32)lbl_805DECDC, (f32)((f32) (lbl_805DECE0 * lbl_805DEC68)));
            TItemEffOrgaFlowShot::approach_value(&unk_54, (f32)lbl_805DECC8, (f32)lbl_805DECE4);
        }
    }
}
void TUnk_804E4B3C::init_effect() {
    advance_effect_timer();
    update_spawn_timer((s32)boss2_tunnel_spawn_timer_table, 0x1F, 0);
    if ((*(s32 *)&boss2_tunnel_state_flags) & 0x200) {
        (*(s32 *)&boss2_tunnel_state_flags) &= 0xFFFFFDFF;
        unk_1C = 1;
        unk_70 = 0;
    }
    update_dust_spawn();
}

#pragma push
#pragma fp_contract on
void TUnk_804E4B3C::update_dust_spawn() {
    u8 *arg0 = (u8 *)this;
    Vec_802F25AC v;
    u32 p;
    *(s32 *)((s8 *)arg0 + 0x74) = *(s32 *)((s8 *)arg0 + 0x74) - 1;
    if (*(s32 *)((s8 *)arg0 + 0x74) <= 0) {
        v.x = 200.0f * rand_signed_unit();
        v.y = 90.0f * (3.0517578125e-05f * (f32)rand()) + 10.0f;
        v.z = 600.0f;
        p = __nw__7TObjectFUl(0x30);
        if (p != 0U) {
            __ct__13TObjBoss7DustFv((u8 *)p, (s32)tl_05, (s32)&v);
        }
        *(s32 *)((s8 *)arg0 + 0x74) = 0x1E;
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TUnk_804E4B3C::update_spawn_timer(s32 arg1, s32 arg2, s32 arg3) {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_802F2664, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802F2664, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_802F2664, sp10) == 0x8) ? 1 : -1];
    Stack_802F2664 stack;
    f32 temp_f1;
    *(f32 *)((s8 *)arg0 + 0x58) = (f32) (*(f32 *)((s8 *)arg0 + 0x58) + *(f32 *)((s8 *)arg0 + 0x5C));
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x58);
    if (temp_f1 >= lbl_805DECB4) {
        *(f32 *)((s8 *)arg0 + 0x58) = (f32) (temp_f1 - lbl_805DECB4);
        *(s32 *)((s8 *)arg0 + 0x70) = (s32) (*(s32 *)((s8 *)arg0 + 0x70) + 1);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x70) == arg2) {
            if (arg3 != 0) {
                *(s32 *)((s8 *)arg0 + 0x70) = (arg2 - 1);
            } else {
                *(s32 *)((s8 *)arg0 + 0x70) = 0;
            }
        }
        stack.sp8 = *(f32 *)((s8 *)arg0 + 0x54);
        stack.spC = lbl_805DEC9C;
        stack.sp10 = *(f32 *)((s8 *)arg0 + 0x84) - *(f32 *)((s8 *)arg0 + 0x58);
        spawn__13TUnk_804E4B3CFll(arg0, *(s32 *)((s8 *)(arg1 + (*(s32 *)((s8 *)arg0 + 0x70) * 4)) + 0), (s32) &stack.sp8);
    }
}
#pragma pop

void TUnk_804E4B3C::advance_effect_timer() {
    *(f32 *)((s8 *)this + 0x5C) = (f32) (*(f32 *)((s8 *)this + 0x5C) + lbl_805DECFC);
    if (*(f32 *)((s8 *)this + 0x5C) > lbl_805DEC68) {
        *(f32 *)((s8 *)this + 0x5C) = (f32) lbl_805DEC68;
    }
}
void TUnk_804E4B3C::sub_802F273C() {  }
void TUnk_804E4B3C::update_phase_motion() {
    u8 *arg0 = (u8 *)this;
    f32 sp8;
    switch (*(s32 *)((s8 *)arg0 + 0x4C)) {
    case 0:
        if (TObjBoss2Tunnel::check_both((s32)arg0) != 0) {
            if (TObjBoss2Tunnel::is_phase_active((s32)arg0) != 0) {
                *(f32 *)((s8 *)arg0 + 0x50) = (f32) lbl_805DECC8;
            } else {
                *(f32 *)((s8 *)arg0 + 0x50) = (f32) lbl_805DEC98;
            }
            *(s32 *)((s8 *)arg0 + 0x4C) = 1;
            TObjBoss2Tunnel__sub_8007DEE4(arg0 + 0x20, lbl_805DECC4, lbl_805DED00, lbl_805DED04, lbl_805DED08, lbl_805DECF8);
            *(f32 *)((s8 *)arg0 + 0x54) = (f32) lbl_805DEC9C;
        }
        break;
    case 1:
        if (TObjBoss2Tunnel::check_both((s32)arg0) == 0) {
            *(s32 *)((s8 *)arg0 + 0x4C) = 3;
            sp8 = fabs_float((f32) (*(f32 *)((s8 *)arg0 + 0x54)));
            TObjBoss2Tunnel__sub_8007DEE4(arg0 + 0x20, lbl_805DECC4, lbl_805DED00, (f32) (*(f32 *)((s8 *)arg0 + 0x54)), (f32) (-update_position__15TObjBoss2TunnelFv(arg0 + 0x20)), lbl_805DECF8);
            return;
        }
        if (advance_phase__15TObjBoss2TunnelFv(arg0 + 0x20, &sp8) != 0) {
            *(s32 *)((s8 *)arg0 + 0x4C) = 2;
        }
        *(f32 *)((s8 *)arg0 + 0x54) = (f32) (sp8 * *(f32 *)((s8 *)arg0 + 0x50));
        return;
    case 2:
        if (TObjBoss2Tunnel::check_both((s32)arg0) == 0) {
            *(s32 *)((s8 *)arg0 + 0x4C) = 3;
            TObjBoss2Tunnel__sub_8007DEE4(arg0 + 0x20, lbl_805DECC4, lbl_805DED00, lbl_805DED04, lbl_805DEC9C, lbl_805DECF8);
            return;
        }
        break;
    case 3:
        if (advance_phase__15TObjBoss2TunnelFv(arg0 + 0x20, &sp8) != 0) {
            *(f32 *)((s8 *)arg0 + 0x54) = (f32) lbl_805DEC9C;
            *(s32 *)((s8 *)arg0 + 0x4C) = 0;
            return;
        }
        *(f32 *)((s8 *)arg0 + 0x54) = (f32) (*(f32 *)((s8 *)arg0 + 0x50) * (lbl_805DED04 - sp8));
        break;
    }
}
void TUnk_804E4B3C::run_task() {
    update_phase_motion();
    static void (TUnk_804E4B3C::*phase_handlers[])() = {
        &TUnk_804E4B3C::init_effect,
        &TUnk_804E4B3C::sub_802F2400,
        &TUnk_804E4B3C::sub_802F23FC,
    };
    void (TUnk_804E4B3C::*handler)() = phase_handlers[unk_1C];
    (this->*handler)();
    sub_802F273C();
}

f32 lbl_804E4AA4[12] = {
    26.0f, -19.0f, 62.0f,
    -26.0f, -19.0f, 62.0f,
    26.0f, -19.0f, 0.0f,
    -26.0f, -19.0f, 0.0f,
};
void *TUnk_804E4B3C::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804E4B3C;
        if (*(void **)((s8 *)this + 0x88) != NULL) { queue_destruction__7TObjectFv((*(void **)((s8 *)this + 0x88))); }
        TObjBoss2Tunnel::dt((s32)((s8 *)this + 0x20), (s16)(-1));
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#define arg0 ((u8 *)arg0p)
void *TObjBoss2Tunnel__sub_802F2A2C(void *arg0p, s32 parent) {
    s32 i;
    u32 p;
    __ct__7TObjectFP7TObject(arg0, (void *) parent);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E4B3C;
    reset_floats__15TObjBoss2TunnelFl(arg0 + 0x20);
    p = __nw__7TObjectFUl(0x1C);
    if (p != 0) {
        p = __ct__7TObjectFP7TObject((void *) p, arg0);
    }
    *(u32 *)((s8 *)arg0 + 0x90) = p;
    p = __nw__7TObjectFUl(0x1C);
    if (p != 0) {
        p = __ct__7TObjectFP7TObject((void *) p, arg0);
    }
    *(u32 *)((s8 *)arg0 + 0x8C) = p;
    *(s32 *)((s8 *)arg0 + 0x1C) = 0;
    if (is_split_screen() == 0) {
        *(f32 *)((s8 *)arg0 + 0x84) = lbl_805DED0C;
    } else {
        *(f32 *)((s8 *)arg0 + 0x84) = lbl_805DED10;
    }
    reset_floats__15TObjBoss2TunnelFv(arg0 + 0x20);
    *(s32 *)((s8 *)arg0 + 0x4C) = 0;
    *(f32 *)((s8 *)arg0 + 0x50) = lbl_805DEC98;
    *(f32 *)((s8 *)arg0 + 0x54) = lbl_805DEC9C;
    *(f32 *)((s8 *)arg0 + 0x5C) = lbl_805DEC9C;
    boss2_tunnel_state_flags = 0;
    *(f32 *)((s8 *)arg0 + 0x58) = lbl_805DEC9C;
    *(s32 *)((s8 *)arg0 + 0x70) = 0;
    *(f32 *)((s8 *)arg0 + 0x78) = lbl_805DEC9C;
    *(f32 *)((s8 *)arg0 + 0x7C) = lbl_805DEC9C;
    *(f32 *)((s8 *)arg0 + 0x80) = lbl_805DEC9C;
    *(s32 *)((s8 *)arg0 + 0x74) = 0x1E;
    for (i = 0; i < 2; i++) {
        p = __nw__7TObjectFUl(0x40);
        if (p != 0) {
            TObjBoss7RaftSplash__ct((void *) p, arg0, &lbl_804E4A44[i], TObjBoss2Tunnel__raft_splash_offset_table + i * 0xC, arg0 + 0x5C);
        }
    }
    p = __nw__7TObjectFUl(0x2C);
    if (p != 0) {
        TObjBoss2Tunnel__sub_802F1AE0((void *) p, *(u32 *)((s8 *)arg0 + 0x90), 0);
    }
    p = __nw__7TObjectFUl(0x2C);
    if (p != 0) {
        TObjBoss2Tunnel__sub_802F1AE0((void *) p, *(u32 *)((s8 *)arg0 + 0x90), 1);
    }
    p = __nw__7TObjectFUl(0x2C);
    if (p != 0) {
        TObjBoss2Tunnel__sub_802F1AE0((void *) p, *(u32 *)((s8 *)arg0 + 0x90), 2);
    }
    if (lbl_805D6970 == 0) {
        lbl_805D696C = 1;
        lbl_805D6970 = 1;
    }
    if (is_room_enemy_set_cleared(get_current_floor(), 1) == 0) {
        ((TunnelSceneController*)arg0)->spawn_segment_row_b();
        p = __nw__7TObjectFUl(0xD8);
        if (p != 0) {
            p = TObjBoss7TunnelCol__ct((void *) p, arg0);
        }
        *(u32 *)((s8 *)arg0 + 0x88) = p;
    } else {
        *(f32 *)((s8 *)arg0 + 0x84) = lbl_805DED0C;
        ((TunnelSceneController*)arg0)->spawn_segment_row_a();
        *(s32 *)((s8 *)arg0 + 0x1C) = 2;
        *(f32 *)((s8 *)arg0 + 0x5C) = lbl_805DEC9C;
        *(f32 *)((s8 *)arg0 + 0x54) = lbl_805DECB8;
        *(u32 *)((s8 *)arg0 + 0x88) = 0;
        boss2_tunnel_state_flags |= 0x8000;
    }
    return arg0;
}
#undef arg0
#pragma pop

void TObjBoss2Tunnel__sub_802F2C4C(void) {  }
void TObjBoss2Tunnel__sub_802F2C50(void) {
    void* obj = ((void*)__nw__7TObjectFUl(0x94));
    if (obj != 0) {
        TObjBoss2Tunnel__sub_802F2A2C(obj, tl_04);
    }
}
void TObjBoss2Tunnel__sub_802F2C84(void) { (*(int *)&boss2_tunnel_state_flags) = 0; }

#pragma push
#pragma opt_common_subs off
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma pop
