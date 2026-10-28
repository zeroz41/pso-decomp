#include "types.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/TObjLight_80133568.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct RecoveredGlobal_802D72E4_TObjNpcEnemy__data_80540FF0 {
    s32 value;
    u8 remaining[0x23C];
};

struct RecoveredGlobal_802D78A0_lbl_804A7CB8 {
    s32 value;
    u8 remaining[0x20];
};

struct RecoveredGlobal_802D78A0_lbl_804A7CDC {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_802D78A0_lbl_804E2680 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_802D78A0___vt__12TObjNpcEnemy {
    s32 value;
    u8 remaining[0x178];
};

struct Ent_802D732C { s16 id; u8 rest[0x22]; };

extern "C" {
extern RecoveredGlobal_802D72E4_TObjNpcEnemy__data_80540FF0 TObjNpcEnemy__entry_table;
s32 TObjNpcBase__ct(void *);
s32 init_collision_body_parts(void *, void *, int);
extern RecoveredGlobal_802D78A0_lbl_804A7CB8 npc_default_battle_stats;
extern RecoveredGlobal_802D78A0_lbl_804A7CDC npc_movement_parameters;
extern RecoveredGlobal_802D78A0_lbl_804E2680 TObjNpcEnemy__collision_body_parts;
extern s32 __vt__12TObjNpcEnemy[];
extern s32 TObjNpcEnemy_class_name;
u8 *TObjNpcEnemy__ct(u8 *arg0, s32 arg1, s32 arg2);
s32 advance_animation_playback(void *);
s32 draw_debug_info__11TObjNpcBaseFv();
void debug_printf_at(s32, const char *, ...);
extern char lbl_80472600[];
extern char lbl_80472610[];
extern char lbl_80472620[];
void *memmove(void *, const void *, u32);
struct NpcBase_802d7748_802D745C { char pad[0x18]; };
struct NpcV_802d7748_802D745C : NpcBase_802d7748_802D745C {
    virtual s32 m0(); virtual s32 m1(); virtual s32 m2();
    virtual s32 m3(); virtual s32 m4(); virtual s32 m5();
    virtual s32 m6(); virtual s32 m7();
    virtual s32 m8(f32 a, f32 b);
};

void * TObjNpcEnemy__create(void *arg0);
void *__dt__12TObjNpcEnemyFv(void *arg0, s16 arg1);
void *TObjControl__ct(void *, void *);
s32 rotate_matrix_y(int, int);
s32 translate_matrix(int, int, f32, f32, f32);
void __dl__7TObjectFPv(void *);
void *__dt__11TObjNpcBaseFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
s32 draw__10TObjMotionFv();
s32 draw_model__16TObjEneMe3StelthFv();
s32 init_npc_animation__10TObjPlayerFPvPvPv(void *, s32, s32, s16);
s32 set_global_flag__10TObjPlayerFv(void *);

typedef char RecoveredGlobal_802D72E4_TObjNpcEnemy__data_80540FF0_size[sizeof(RecoveredGlobal_802D72E4_TObjNpcEnemy__data_80540FF0) == 0x240 ? 1 : -1];
s16 *TObjNpcEnemy::get_entry_by_index(s16 arg0) {
    s16 *temp_r3;
    if (arg0 < 0) {
        return NULL;
    }
    if (arg0 >= 0x10) {
        return NULL;
    }
    temp_r3 = (s16 *)((u8 *)&TObjNpcEnemy__entry_table.value + (arg0 * 0x24));
    if (*(s16 *)((s8 *)temp_r3 + 0) == 0) {
        return NULL;
    }
    return temp_r3;
}

s16 *TObjNpcEnemy::insert_slot_by_id(s16 arg0) {
    s32 i;
    Ent_802D732C *e;
    for (i = 0; i < 0x10; i++) {
        e = &((Ent_802D732C *)&TObjNpcEnemy__entry_table)[i];
        if (e->id == 0) {
            return (s16 *)e;
        }
        if (e->id >= arg0) {
            if (e->id == arg0) {
                return NULL;
            }
            break;
        }
    }
    if (i >= 0x10) {
        return NULL;
    }
    if (((Ent_802D732C *)&TObjNpcEnemy__entry_table)[15].id != 0) {
        return NULL;
    }
    if (i < 0xF) {
        memmove(e + 1, e, (0xF - i) * 0x24);
    }
    ((TObjNpcEnemy *)e)->reset_anim_fields();
    return (s16 *)e;
}

void TObjNpcEnemy::reset_all_anim_fields() {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        ((TObjNpcEnemy *)(&((Ent_802D732C *)&TObjNpcEnemy__entry_table)[i]))->reset_anim_fields();
    }
}

s32 TObjNpcEnemy::sub_802D7444() {
    return (**(s16 * *)&this->m_3b8 != 0x3F) ? 1 : 0;
}

void TObjNpcEnemy::vfunc_88() {
    void *temp_r4;

    temp_r4 = *(void * *)&this->m_3b8;
    if ((s16) this->mode != 2) {
        this->m_b8 = (s16) *(s16 *)((s8 *)temp_r4 + 0x1C);
        return;
    }
    this->m_b8 = (s16) *(s16 *)((s8 *)temp_r4 + 0x1E);
}

extern const f32 lbl_805DE7D8;

void TObjNpcEnemy::set_npc_data(void *arg1) {
    void *temp_r5;

    *(void * *)&this->m_3b8 = arg1;
    temp_r5 = *(void * *)&this->m_3b8;
    if (temp_r5 == NULL) {
        this->model = 0;
        this->texture_id = 0;
        this->m_b8 = 0;
        *(f32 *)((s8 *)this->bodies + 0xC) = (f32) lbl_805DE7D8;
        return;
    }
    *(s32 *)&this->model = (s32) *(s32 *)((s8 *)temp_r5 + 8);
    this->texture_id = (s32) *(s32 *)(this->m_3b8 + 0xC);
    this->m_b8 = (s16) *(s16 *)((s8 *)temp_r5 + 0x1C);
    switch ((s32) (*(u16 *)(this->m_3b8 + 2))) {
    case 0:
    case 2:
    case 4:
        break;
    case 1:
    case 3:
        init_npc_animation__10TObjPlayerFPvPvPv(this, *(s32 *)((s8 *)temp_r5 + 0x18), *(s32 *)((s8 *)temp_r5 + 0x14), this->m_b8);
        break;
    }
    *(f32 *)((s8 *)this->bodies + 0xC) = (f32) *(f32 *)(this->m_3b8 + 0x10);
}

void TObjNpcEnemy::draw_debug_info() {
    u8 *arg0 = (u8 *)this;
    s16 *p;
    draw_debug_info__11TObjNpcBaseFv();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130018, lbl_80472600);
    debug_printf_at(0x13001A, lbl_80472610);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    p = TObjNpcEnemy::get_entry_by_index((s16) this->rotation_x);
    if (p != *(s16 * *)&this->m_3b8) {
        ((TObjNpcEnemy *)arg0)->set_npc_data(p);
    }
    p = *(s16 * *)&this->m_3b8;
    if (p == NULL) {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x240018, lbl_80472620);
        TObjNpcEnemy::set_global_count(0xF0F0F0FF);
        return;
    }
    switch (((u16 *) p)[1]) {
    case 0:
    case 2:
    case 4:
        break;
    case 1:
    case 3:
        if (p[0x10] <= this->rotation_z || this->rotation_z < 0) {
            TObjNpcEnemy::set_global_count(0xFF0000FF);
            debug_printf_at(0x24001A, lbl_80472620);
            TObjNpcEnemy::set_global_count(0xF0F0F0FF);
            this->m_b8 = 0;
        } else {
            this->m_b8 = this->rotation_z;
        }
        advance_animation_playback(arg0);
        break;
    }
}

void TObjNpcEnemy::update_state() {
    void *sp4;

    sp4 = *(void * *)&this->m_3b8;
    switch ((s32) (*(u16 *)((s8 *)sp4 + 2))) {
    case 0:
        set_global_flag__10TObjPlayerFv(this);
        draw_chunk_object(this->model);
        set_default_alpha_blend();
        TObjPlayer::clear_global_state();
        return;
    case 1:
        draw__10TObjMotionFv();
        return;
    case 2:
        set_global_flag__10TObjPlayerFv(this);
        draw_ginja_object(this->model);
        set_default_alpha_blend();
        TObjPlayer::clear_global_state();
        return;
    case 3:
        draw_model__16TObjEneMe3StelthFv();
    case 4:
        return;
    }
}

extern s32 model_render_flags;

void TObjNpcEnemy::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r4;

    if (((void *) *(void * *)&this->m_3b8 != NULL) && (((NpcV_802d7748_802D745C *)arg0)->m8(*(f32 *)&this->unk_398, this->m_39c) != 0) && ((s32) *(s32 *)&this->m_390 == 1)) {
        select_actor_lighting((s32)arg0);
        if (((TObjNpcEnemy *)arg0)->sub_802D7444() != 0) {
            model_render_flags |= 1;
        }
        TObjFish::set_global_param(this->texture_id);
        push_matrix_from(0);
        translate_matrix_vec3(0, ((u8 *)&this->position));
        temp_r4 = (unsigned char *) (this->m_3b8);
        translate_matrix(0, (int)temp_r4, (f32)lbl_805DE7D8, (f32) (*(f32 *)((s8 *)temp_r4 + 4)), (f32)lbl_805DE7D8);
        rotate_matrix_y(0, this->rotation_y);
        update_state();
        pop_matrix();
        if (((TObjNpcEnemy *)arg0)->sub_802D7444() != 0) {
            model_render_flags &= 0xFFFFFFFE;
        }
        restore_scene_lighting();
        ((TObjEnemy *)arg0)->render_with_position_override(0, 0);
    }
}

void *__dt__12TObjNpcEnemyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjNpcEnemy;
        __dt__11TObjNpcBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

typedef char RecoveredGlobal_802D78A0_lbl_804A7CB8_size[sizeof(RecoveredGlobal_802D78A0_lbl_804A7CB8) == 0x24 ? 1 : -1];
typedef char RecoveredGlobal_802D78A0_lbl_804A7CDC_size[sizeof(RecoveredGlobal_802D78A0_lbl_804A7CDC) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_802D78A0_lbl_804E2680_size[sizeof(RecoveredGlobal_802D78A0_lbl_804E2680) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_802D78A0___vt__12TObjNpcEnemy_size[sizeof(RecoveredGlobal_802D78A0___vt__12TObjNpcEnemy) == 0x17C ? 1 : -1];
u8 *TObjNpcEnemy__ct(u8 *arg0, s32 arg1, s32 arg2) {
    TObjNpcBase__ct(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_802D78A0___vt__12TObjNpcEnemy *)&__vt__12TObjNpcEnemy).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjNpcEnemy_class_name;
    ((TObjNpcEnemy *)(arg0))->apply_set_data((void *)arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    ((TObjNpcEnemy *)(arg0))->apply_set_params(0, 1);
    ((TObjNpcEnemy *)arg0)->movementParameters = &npc_movement_parameters.value;
    ((TUnk_804806E8 *)arg0)->set_motion_params(&npc_default_battle_stats.value);
    init_collision_body_parts(arg0, &TObjNpcEnemy__collision_body_parts.value, 1);
    ((TObjPlayer *)arg0)->reset_photon_effect();
    ((TObjEnemy *)arg0)->update_prev_position();
    ((TBoss3VoloptHiraisin *)arg0)->copy_position();
    ((TObjNpcEnemy *)arg0)->set_npc_data((void *)((int) (((s32)TObjNpcEnemy::get_entry_by_index((s16)((int) ((s16) *(s32 *)((s8 *)arg0 + 0x5C))))))));
    return arg0;
}

void * TObjNpcEnemy__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3BC);
    if (o2 != NULL) {
        o2 = TObjNpcEnemy__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
