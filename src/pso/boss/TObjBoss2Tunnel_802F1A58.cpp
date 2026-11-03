#include "types.h"
#include "pso/unk/text_803D853C.h"
#include "pso/boss/TBoss1DragonColli.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/TUnk_804E4B24.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TObjBoss7TunnelCol.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss8DragonDemo.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_802F1D1C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/unk/text_802F1F58.h"
#include "pso/boss/TObjBoss2Tunnel_802F1A58.h"
#include "pso/boss/TUnk_804E4AD4.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/boss/TUnk_804E4B3C.h"
#include "pso/boss/TunnelSceneController.h"
#include <stddef.h>
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/boss/TObjBoss2Tunnel_802F2070.h"
#include "pso/unk/text_802F1FB0.h"

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


struct RecoveredGlobal_802F1AE0_lbl_804E4AD4 { s32 value; u8 remaining[0x14]; };

extern "C" {
s32 get_bml_motion(void *, s32);
s32 get_bml_model(void *, s32);
u32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__13TUnk_804E4AD4[];
extern u8 *boss7_common_bml_resource;
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

void TUnk_804E4AD4::run_task() {
    f32 temp_f0;
    f32 temp_f1;
    *(f32 *)&this->unk_28 += 1.0f;
    temp_f1 = this->m_24;
    temp_f0 = *(f32 *)&this->unk_28;
    if (temp_f1 <= temp_f0) {
        *(f32 *)&this->unk_28 = (f32) (temp_f0 - temp_f1);
    }
}

void *__dt__13TUnk_804E4AD4Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804E4AD4;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TObjBoss2Tunnel__sub_802F1AE0(u8 *arg0, u8 *arg1, s32 arg2) {
    __ct__7TObjectFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_802F1AE0_lbl_804E4AD4 *)&__vt__13TUnk_804E4AD4).value;
    *(s32 *)((s8 *)arg0 + 0x1C) = get_bml_model(boss7_common_bml_resource, arg2 + 0x11);
    ((TUnk_804E4AD4 *)arg0)->m_20 = get_bml_motion(boss7_common_bml_resource, arg2);
    ((TUnk_804E4AD4 *)arg0)->m_24 = (f32) ((f32) *(u32 *)((s8 *)(((TUnk_804E4AD4 *)arg0)->m_20) + 4) - 1.0f);
    *(f32 *)((s8 *)arg0 + 0x28) = 0.0f;
    return arg0;
}

}

extern "C" void *__ct__14TObjCollidableFP7TObject(void *, TObject *);

extern "C" {

struct VOff_802F1BEC_arg0_802F1B7C { char pad_0[0xAC]; char f_AC[1]; };
struct VOff_802F1C68_arg0_802f1c68_802F1B7C { char pad_0[0x48]; char f_48[1]; };

void __dl__7TObjectFPv(void *);
s32 get_mode__11TCameraCtrlFPv(void *p);

void TObjBoss7TunnelCol::render() {  }
void TObjBoss7TunnelCol::run_task() {  }

extern s32 __vt__18TObjBoss7TunnelCol[];

void *__dt__18TObjBoss7TunnelColFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjBoss7TunnelCol;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        ((TObjCollidable *)arg0)->clear_collision_bodies();
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 TObjBoss7TunnelCol__col_desc[];
extern void *lbl_805D3FF0;

void *TObjBoss7TunnelCol__ct(void *arg0, TObject *parent) {
    struct VOff_802F1BEC_arg0_802F1B7C *self = (struct VOff_802F1BEC_arg0_802F1B7C *)arg0;
    __ct__14TObjCollidableFP7TObject(arg0, parent);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjBoss7TunnelCol;
    *(void * *)&((TObjBoss7TunnelCol *)arg0)->m_name = lbl_805D3FF0;
    copy_collision_body((CollisionBody *)self->f_AC, (const CollisionBody *)TObjBoss7TunnelCol__col_desc);
    *(f32 *)((s8 *)arg0 + 0x38) = 85.0f;
    *(f32 *)((s8 *)arg0 + 0x3C) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x40) = 0.0f;
    ((TObjCollidable *)arg0)->set_collision_body(self->f_AC);
    ((TObjPlayer *)arg0)->register_object_by_id();
    return arg0;
}

void TUnk_804E4B24::update_collision() {
    struct VOff_802F1C68_arg0_802f1c68_802F1B7C *self = (struct VOff_802F1C68_arg0_802f1c68_802F1B7C *)this;
    set_matrix_identity((u8 *)self->f_48);
    translate_matrix_vec3((u8 *)self->f_48, (u8 *)((char *)this + 28));
    rotate_matrix_yxz((s32)self->f_48, (s32)(*(void * *)&(*(void * *)((u8 *)this + 0x28))), (s32)this->m_2c, (s32)(*(void * *)&(this->unk_30)));
}


s32 TObjBoss7TunnelCol::is_in_camera_range() {
    f32 temp_f1;

    if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x20) {
        temp_f1 = *(f32 *)&this->texlist;
        if ((temp_f1 < -300.0f) && (300.0f < temp_f1)) {
            return 0;
        }
    }
    return 1;
}

}



struct GE_802F1DAC { s32 a, b, obj, d; };

struct GE_802F1E54 { s32 a, b, obj, d; };

extern "C" {
s32 copy_position__16TBoss8DragonDemoFv(int, void *);
s32 draw_ginja_object(int);
s32 is_in_camera_range__18TObjBoss7TunnelColFv(void *);
s32 push_matrix();
extern u8 *boss7_common_bml_resource;
extern u8 *boss7_common_texture_list;

void draw_tunnel_segment(u8 *boss7_tunnel_col) {
    s32 var_r31;
    u8 *var_r30;
    u8 *var_r3;
    u8 *var_r4;
    var_r30 = boss7_tunnel_col;
    if (is_in_camera_range__18TObjBoss7TunnelColFv(boss7_tunnel_col) != 0) {
        var_r3 = (u8 *)((void *)2);
        var_r4 = (u8 *)(*(u8 **)((s8 *)var_r30 + 0x3C));
        var_r4 += *(s32 *)((s8 *)var_r30 + 0x38) * 4;
        var_r31 = *(s32 *)((s8 *)var_r4 + (-4));
        set_draw_list_mask(2);
        var_r3 = boss7_common_texture_list;
        TObjFish::set_global_param((int)var_r3);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        var_r4 = (var_r30 + 0x48);
        var_r3 = NULL;
        TObjPlayer::concat_matrix(0, (int)var_r4);
        var_r3 = boss7_common_bml_resource;
        var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x42C));
        var_r3 += var_r31 * 0x10;
        var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 8));
        draw_ginja_object((int)var_r3);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        restore_draw_list_mask();
    }
}

void fn_802F1DAC(u8 *arg0) {
    if (((s32 (*)(void))is_in_camera_range__18TObjBoss7TunnelColFv)() != 0) {
        set_draw_list_mask(2);
        TObjFish::set_global_param((int)boss7_common_texture_list);
        push_matrix();
        TObjPlayer::concat_matrix(0, (int)(arg0 + 0x48));
        ((s32 (*)(int, void *))draw_ginja_object)((*(GE_802F1DAC **)((s8 *)boss7_common_bml_resource + 0x42C))[(*(s32 **)((s8 *)arg0 + 0x3C))[1]].obj, boss7_common_bml_resource);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x38) == 4) {
            ((s32 (*)(int, void *))draw_ginja_object)((*(GE_802F1DAC **)((s8 *)boss7_common_bml_resource + 0x42C))[(*(s32 **)((s8 *)arg0 + 0x3C))[2]].obj, boss7_common_bml_resource);
        }
        pop_matrix();
        restore_draw_list_mask();
    }
}

void fn_802F1E54(u8 *arg0) {
    if (((s32 (*)(void))is_in_camera_range__18TObjBoss7TunnelColFv)() != 0) {
        set_draw_list_mask(1);
        TObjFish::set_global_param((int)boss7_common_texture_list);
        push_matrix();
        TObjPlayer::concat_matrix(0, (int)(arg0 + 0x48));
        ((s32 (*)(int, void *))draw_ginja_object)((*(GE_802F1E54 **)((s8 *)boss7_common_bml_resource + 0x42C))[(*(s32 **)((s8 *)arg0 + 0x3C))[0]].obj, boss7_common_bml_resource);
        pop_matrix();
        restore_draw_list_mask();
    }
}

void TUnk_804E4B24::run_task() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x1C) = TBoss8DragonDemo__sub_802F2CBC((void *)this->m_34);
    this->m_24 = (f32) (this->m_24 - TBoss8DragonDemo__sub_802F2CB4((void *)this->m_34));
    if ((s32) this->m_40 == 4) {
        copy_position__16TBoss8DragonDemoFv(this->m_34, (u8 *)&this->unk_1C);
    }
    if (this->m_24 <= -*(f32 *)((s8 *)arg0 + 0x44)) {
        queue_destruction__7TObjectFv((arg0));
    }
    ((TUnk_804E4B24 *)arg0)->update_collision();
}

}


extern "C" {

void __dt__7TObjectFv(void *, int);
void __dl__7TObjectFPv(void *);
extern s32 __vt__13TUnk_804E4B24[];

void *__dt__13TUnk_804E4B24Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804E4B24;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}



extern "C" {
s32 VecCopy__FP3VecPC3Vec(void *, void *, int, int);
s32 copy_position__16TBoss8DragonDemoFv(int, void *);
u8 *fn_802F1FB0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 farg0) {
    s32 temp_r5;
    s32 temp_r6;
    u8 *temp_r31;
    __ct__7TObjectFP7TObject(arg0, arg1);
    temp_r5 = arg2 * 8;
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804E4B24;
    temp_r6 = *(s32 *)((s8 *)arg1 + 0x10);
    temp_r31 = (u8 *)boss2_tunnel_effect_name_table + temp_r5;
    ((TUnk_804E4B24 *)arg0)->m_34 = temp_r6;
    VecCopy__FP3VecPC3Vec(arg0 + 0x1C, (void *)arg3, (int)temp_r5, (int)temp_r6);
    *(s32 *)((s8 *)arg0 + 0x28) = 0;
    *(s32 *)((s8 *)arg0 + 0x2C) = 0;
    *(s32 *)((s8 *)arg0 + 0x30) = 0;
    ((TUnk_804E4B24 *)arg0)->m_3c = (s32) *(s32 *)((s8 *)temp_r31 + 4);
    *(s32 *)((s8 *)arg0 + 0x38) = (s32) *(s32 *)((s8 *)temp_r31 + 0);
    ((TUnk_804E4B24 *)arg0)->m_40 = arg2;
    *(f32 *)((s8 *)arg0 + 0x44) = farg0;
    if (arg2 == 4) {
        copy_position__16TBoss8DragonDemoFv((int) (((TUnk_804E4B24 *)arg0)->m_34), arg0 + 0x1C);
        TObjBoss2Tunnel__sub_802F2278();
    }
    ((TUnk_804E4B24 *)arg0)->update_collision();
    return arg0;
}

}




extern "C" {
u32 __nw__7TObjectFUl(s32);
void spawn__13TUnk_804E4B3CFll(void *arg0, s32 arg1, s32 arg2);
void TObjBoss2Tunnel__sub_802F2278(void);
s32 TObjBoss2Tunnel__sub_802F22F4(void);
void queue_destruction__7TObjectFv(void *arg0);
extern const f32 lbl_805DEC68;
s32 TObjBoss2Tunnel__sub_8007DEE4(void *, f32, f32, f32, f32, f32);
s32 advance_phase__15TObjBoss2TunnelFv(void *, void *);
f32 fabs_float(f32);
f32 update_position__15TObjBoss2TunnelFv(void *);
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
s32 TObjBoss7RaftSplash__ct(void *, void *, void *, void *, void *);

extern u8 TObjBoss2Tunnel__raft_splash_offset_table[];
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

void TunnelSceneController::spawn_segment_row_a() {
    TunnelVector3 position;
    position.x=segment_x;
    position.y=0.0f;
    for (position.z=half_length;position.z > -half_length;position.z-=800.0f) {
        if (799.0f > position.z && position.z > (-799.0f)) {
            ((void (*)(void*,s32,TunnelVector3*))spawn__13TUnk_804E4B3CFll)(this,4,&position);
        } else {
            ((void (*)(void*,s32,TunnelVector3*))spawn__13TUnk_804E4B3CFll)(this,3,&position);
        }
    }
}

void TunnelSceneController::spawn_segment_row_b() {
    TunnelVector3 position;
    position.x=segment_x;
    position.y=0.0f;
    for (position.z=half_length;position.z > -half_length;position.z-=800.0f) {
        if (799.0f > position.z && position.z > (-799.0f)) {
            ((void (*)(void*,s32,TunnelVector3*))spawn__13TUnk_804E4B3CFll)(this,0,&position);
        } else {
            ((void (*)(void*,s32,TunnelVector3*))spawn__13TUnk_804E4B3CFll)(this,2,&position);
        }
    }
}

void TUnk_804E4B3C::spawn(s32 arg1, s32 arg2) {
    void *new_obj = (void *) __nw__7TObjectFUl(0x78);
    if ((u32) new_obj != 0U) {
        fn_802F1FB0((u8 *)new_obj, *(u8 **)((s8 *)this + 0x8C), arg1, arg2, this->m_84);
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
        if (temp_f1 < 1.0f) {
            unk_1C = 2;
            *(f32 *)((s8 *)this + 0x5C) = 0.0f;
            unk_54 = (-50.0f);
            temp_r3 = unk_88;
            if (temp_r3 != NULL) {
                queue_destruction__7TObjectFv(temp_r3);
                unk_88 = NULL;
            }
            (*(s32 *)&boss2_tunnel_state_flags) |= 0x8000;
            return;
        }
        if (temp_f1 < 100.0f) {
            TItemEffOrgaFlowShot::approach_value((f32 *)((s8 *)this + 0x5C), 0.02f, (f32)((f32) (0.1f * lbl_805DEC68)));
            TItemEffOrgaFlowShot::approach_value(&unk_54, (-1.0f), (-50.0f));
            return;
        }
        if (temp_f1 < 200.0f) {
            TItemEffOrgaFlowShot::approach_value((f32 *)((s8 *)this + 0x5C), 0.04f, (f32)((f32) (0.2f * lbl_805DEC68)));
            TItemEffOrgaFlowShot::approach_value(&unk_54, (-1.0f), (-30.000002f));
            return;
        }
        if (temp_f1 < 300.0f) {
            TItemEffOrgaFlowShot::approach_value((f32 *)((s8 *)this + 0x5C), 0.06f, (f32)((f32) (0.3f * lbl_805DEC68)));
            TItemEffOrgaFlowShot::approach_value(&unk_54, (-1.0f), (-15.000001f));
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
    if (temp_f1 >= 800.0f) {
        *(f32 *)((s8 *)arg0 + 0x58) = (f32) (temp_f1 - 800.0f);
        *(s32 *)((s8 *)arg0 + 0x70) = (s32) (*(s32 *)((s8 *)arg0 + 0x70) + 1);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x70) == arg2) {
            if (arg3 != 0) {
                *(s32 *)((s8 *)arg0 + 0x70) = (arg2 - 1);
            } else {
                *(s32 *)((s8 *)arg0 + 0x70) = 0;
            }
        }
        stack.sp8 = *(f32 *)((s8 *)arg0 + 0x54);
        stack.spC = 0.0f;
        stack.sp10 = *(f32 *)((s8 *)arg0 + 0x84) - *(f32 *)((s8 *)arg0 + 0x58);
        spawn__13TUnk_804E4B3CFll(arg0, *(s32 *)((s8 *)(arg1 + (*(s32 *)((s8 *)arg0 + 0x70) * 4)) + 0), (s32) &stack.sp8);
    }
}
#pragma pop

// Dead-stripped from the DOL: no code of it survives, only its literal 2.0f
// (.sdata2 0x805DECF8, pooled between update_dust_spawn's 600.0f and
// advance_effect_timer's 0.05f). It sits between the two scroll-speed helpers
// (update_spawn_timer, advance_effect_timer); body and name inferred from that role.
void TUnk_804E4B3C::double_scroll_speed() {
    unk_5C *= 2.0f;
}

void TUnk_804E4B3C::advance_effect_timer() {
    *(f32 *)((s8 *)this + 0x5C) += 0.05f;
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
                *(f32 *)((s8 *)arg0 + 0x50) = (-1.0f);
            } else {
                *(f32 *)((s8 *)arg0 + 0x50) = 1.0f;
            }
            *(s32 *)((s8 *)arg0 + 0x4C) = 1;
            TObjBoss2Tunnel__sub_8007DEE4(arg0 + 0x20, 0.1f, (-0.1f), 150.0f, 5.0f, 2.0f);
            *(f32 *)((s8 *)arg0 + 0x54) = 0.0f;
        }
        break;
    case 1:
        if (TObjBoss2Tunnel::check_both((s32)arg0) == 0) {
            *(s32 *)((s8 *)arg0 + 0x4C) = 3;
            sp8 = fabs_float((f32) (*(f32 *)((s8 *)arg0 + 0x54)));
            TObjBoss2Tunnel__sub_8007DEE4(arg0 + 0x20, 0.1f, (-0.1f), (f32) (*(f32 *)((s8 *)arg0 + 0x54)), (f32) (-update_position__15TObjBoss2TunnelFv(arg0 + 0x20)), 2.0f);
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
            TObjBoss2Tunnel__sub_8007DEE4(arg0 + 0x20, 0.1f, (-0.1f), 150.0f, 0.0f, 2.0f);
            return;
        }
        break;
    case 3:
        if (advance_phase__15TObjBoss2TunnelFv(arg0 + 0x20, &sp8) != 0) {
            *(f32 *)((s8 *)arg0 + 0x54) = 0.0f;
            *(s32 *)((s8 *)arg0 + 0x4C) = 0;
            return;
        }
        *(f32 *)((s8 *)arg0 + 0x54) = (f32) (*(f32 *)((s8 *)arg0 + 0x50) * (150.0f - sp8));
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
        *(f32 *)((s8 *)arg0 + 0x84) = 8000.0f;
    } else {
        *(f32 *)((s8 *)arg0 + 0x84) = 2666.6667f;
    }
    reset_floats__15TObjBoss2TunnelFv(arg0 + 0x20);
    *(s32 *)((s8 *)arg0 + 0x4C) = 0;
    *(f32 *)((s8 *)arg0 + 0x50) = 1.0f;
    *(f32 *)((s8 *)arg0 + 0x54) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x5C) = 0.0f;
    boss2_tunnel_state_flags = 0;
    *(f32 *)((s8 *)arg0 + 0x58) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x70) = 0;
    *(f32 *)((s8 *)arg0 + 0x78) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x7C) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x80) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x74) = 0x1E;
    for (i = 0; i < 2; i++) {
        p = __nw__7TObjectFUl(0x40);
        if (p != 0) {
            TObjBoss7RaftSplash__ct((void *) p, arg0, &lbl_804E4A44[i], TObjBoss2Tunnel__raft_splash_offset_table + i * 0xC, arg0 + 0x5C);
        }
    }
    p = __nw__7TObjectFUl(0x2C);
    if (p != 0) {
        TObjBoss2Tunnel__sub_802F1AE0((u8 *) p, *(u8 **)((s8 *)arg0 + 0x90), 0);
    }
    p = __nw__7TObjectFUl(0x2C);
    if (p != 0) {
        TObjBoss2Tunnel__sub_802F1AE0((u8 *) p, *(u8 **)((s8 *)arg0 + 0x90), 1);
    }
    p = __nw__7TObjectFUl(0x2C);
    if (p != 0) {
        TObjBoss2Tunnel__sub_802F1AE0((u8 *) p, *(u8 **)((s8 *)arg0 + 0x90), 2);
    }
    if (lbl_805D6970 == 0) {
        lbl_805D696C = 1;
        lbl_805D6970 = 1;
    }
    if (is_room_enemy_set_cleared(get_current_floor(), 1) == 0) {
        ((TunnelSceneController*)arg0)->spawn_segment_row_b();
        p = __nw__7TObjectFUl(0xD8);
        if (p != 0) {
            p = (u32)TObjBoss7TunnelCol__ct((void *) p, (TObject *)arg0);
        }
        *(u32 *)((s8 *)arg0 + 0x88) = p;
    } else {
        *(f32 *)((s8 *)arg0 + 0x84) = 8000.0f;
        ((TunnelSceneController*)arg0)->spawn_segment_row_a();
        *(s32 *)((s8 *)arg0 + 0x1C) = 2;
        *(f32 *)((s8 *)arg0 + 0x5C) = 0.0f;
        *(f32 *)((s8 *)arg0 + 0x54) = (-50.0f);
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
