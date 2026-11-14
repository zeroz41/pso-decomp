#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/TEffStarLight2D.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804E355C.h"

#include <stddef.h>
#include "pso/weapon/TItemAttackCol.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/unk/text_80087278.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/unk/text_80086B64.h"
#include "pso/system/task/TObject.h"
struct VBase_18_f2ea1e { char pad[0x18]; };

struct VObj_18_f2ea1e : VBase_18_f2ea1e {
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
    virtual s32 m19(void *, s32, s32, f32);
    virtual f32 m20(void *, f32);
    virtual void m21();
    virtual s32 m22(void *, s32);
    virtual s32 m23(void *, f32);
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

struct Stack_802E456C {
    u8 sp8;
    u8 sp9;
    u8 pad_A[0x2];
    u8 * spC;
    u8 pad_10[0x4];
    u8 * sp14;
    s32 sp18;
};


struct VBase_802E3C4C { char pad[0x18]; };
struct VObj_802E3C4C : VBase_802E3C4C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58();
    virtual void m59(u8 *, s32, s32, f32, s32);
};

struct Hit_802E3D8C { s32 pad; void *pos; };

extern "C" {
s32 disallow_rendering__7TObjectFv(void *);
s32 test_flags_any(void *, int);

}
f32 vec_distance_squared(u8 *arg0, u8 *arg1);
extern "C" {
s32 play_weapon_hit_sound(void *);
void apply_camera_shake__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2);
extern const f32 lbl_805DE914;
extern const f32 lbl_805DE928;
extern const float lbl_805DE918;
extern const f32 lbl_805DE924;
Hit_802E3D8C *csnVector(void *, void *, s32);
extern const f32 lbl_805DE910;
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 rotate_matrix_by_node_angles(void *, int);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern int attack_collider_render_owner;
extern int attack_collider_active_count;
void TItemAttackCol__vt5(s32 arg0);
void* TObjPlayer__sub_802E449C(void* a0);
s32 vec3_add_to(s32 *, s32);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
int fn_802E3BA8(void*, void*);

void TItemAttackCol::add_to_active_list(void* a0) { fn_802E3BA8((void*)attack_collider_render_owner, a0); attack_collider_active_count = (attack_collider_active_count + 0x1); }

void TItemAttackCol::shift_collision_bounds() {
    spin[2] += 0xCCC;
    pad_114[2] -= 0xCCC;
}

void TItemAttackCol::vfunc_6(s32 *a) {
    if (!(flags & 0x80)) {
        if (resolve_attack_col_hit((u8 *)a) != 0) {
            if (hit_object != NULL) {
                hit_object(item_id, a, &velocity);
            }
            if (flags & 0x100) {
                pad_B4 = pad_B4 * lbl_805DE910;
            }
        }
    } else {
        if (hit_object != NULL) {
            hit_object(item_id, a, &velocity);
        }
        if (flags & 0x200) {
            VObj_802E3C4C *p = (VObj_802E3C4C *)find_item_by_id(item_id);
            u8 *b = (u8 *)get_player_by_client_id(client_id);
            if (p != NULL) {
                p->m59(b, a[0], pad_B8, pad_B4, a[1]);
            }
        }
    }
}

void TItemAttackCol__vt5(s32 arg0) {
    s32 sp8;

    VecCopy((Vec *)&sp8, (const Vec *)(arg0 + 0xD0));
    vec3_add_to(&sp8, arg0 + 0x24);
    ((TItemAttackCol *)arg0)->move_with_collision(&sp8);
}

void TItemAttackCol::move_with_collision(void *arg1) {
    Hit_802E3D8C *hit;
    hit = csnVector((u8 *)&position, arg1, 0x8100);
    if (hit != NULL) {
        hit_wall_flags.set(1);
        VecCopy(&position, (const Vec *)(hit->pos));
        if (hit_wall != NULL) {
            hit_wall(item_id, &position, &velocity);
        }
    } else {
        VecCopy(&position, (const Vec *)(arg1));
    }
}

void TItemAttackCol::render() {
    if (all_parents_unqueued_for_destruction__7TObjectFv() == 0 || find_equipped_item(item_id) == 0U) {
        return;
    }
    {
        if (model != 0U) {
            if (texlist != 0U) {
                set_texlist(texlist);
            }
            TParticleCtrl::begin_effect_render();
            attack_collider_render_owner = (int)this;
            attack_collider_active_count = 0;
            push_matrix();
            post_translate_matrix((u8 *)&position);
            rotate_matrix_by_node_angles((u8 *)rotation, 1);
            rotate_matrix_by_node_angles((u8 *)spin, 1);
            scale_current_matrix((u8 *)&scale);
            draw_node_tree_with_callback((NJS_OBJECT *)model, (void (*)(NJS_OBJECT *))TItemAttackCol::add_to_active_list);
            pop_matrix();
            attack_collider_render_owner = 0;
            TParticleCtrl::end_effect_render();
        }
    }
}

void TItemAttackCol::run_task() {
    if (has_game_join_id() == 0) {
        queue_destruction();
        disallow_rendering();
        return;
    }
    if (flags & 4) {
        shift_collision_bounds();
    }
    if (flags & 0x20) {
        spin[1] += 0x888;
    }
    this->vfunc_7();
    if (star_light != NULL) {
        star_light->copy_position(&position);
    }
    if (particle != NULL) {
        particle->set_position(&position);
    }
    if (trail_particle != NULL) {
        trail_particle->set_position(&position);
    }
    if (continuous_particle != NULL) {
        continuous_particle->set_position(&position);
    }
    check_hits();
    if ((range_sq <= vec_distance_squared((u8 *)&position, (u8 *)&start_position)) || (test_flags_any(&hit_wall_flags, 1) != 0)) {
        queue_destruction();
    }
}

TItemAttackCol::~TItemAttackCol() {
    if (star_light != NULL) {
        star_light->queue_destruction();
        star_light = NULL;
    }
    if (particle != NULL) {
        particle->queue_destruction();
        particle = NULL;
    }
    if (trail_particle != NULL) {
        trail_particle->queue_destruction();
        trail_particle = NULL;
    }
    if (continuous_particle != NULL) {
        continuous_particle->queue_destruction();
        continuous_particle = NULL;
    }
}

extern "C" f32 normalize_vector(Vec *v);

const char *TItemAttackCol__name = "TItemAttackCol";

// The particle's direction before the collider's heading is added.
static ParticleAngles particle_direction = {0x4000, 0, 0x4000};

TItemAttackCol::TItemAttackCol(TObject *parent, S_802E449C *params) : TUnk_804E355C(parent, params) {
    m_name = TItemAttackCol__name;
    VecCopy(&start_position, &params->position);
    if (params->flags & 1) {
        VecCopy(&velocity, &params->direction);
        normalize_vector(&velocity);
        rotation[0] = -(s32)(10430.38043493439 * atan2_float(velocity.y, newton_sqrtf(velocity.x * velocity.x + velocity.z * velocity.z)));
        rotation[1] = (s32)(10430.38043493439 * atan2_float(velocity.x, velocity.z));
        rotation[2] = 0;
    } else {
        velocity.x = sin_table_lookup(params->rotation_y);
        velocity.y = 0.0f;
        velocity.z = cos_table_lookup(params->rotation_y);
        rotation[0] = 0;
        rotation[1] = params->rotation_y;
        rotation[2] = 0;
    }
    velocity.x *= params->speed;
    velocity.y *= params->speed;
    velocity.z *= params->speed;
    rotation_y = rotation[1];
    range_sq = params->range * params->range;
    model = params->model;
    texlist = params->texlist;
    scale.x = params->scale;
    scale.y = params->scale;
    scale.z = params->scale;
    copy_xyz(spin, params->spin);
    pad_114[0] = 0;
    pad_114[1] = 0;
    pad_114[2] = 0;
    pad_120[0] = 1.0f;
    pad_120[1] = 1.0f;
    pad_120[2] = 1.0f;
    hit_wall_flags.reset();
    if (params->flags & 2) {
        const StarLightParameters star = {
            params->star_width,
            7.0f,
            {{0, 255.0f * params->star_color[0], 255.0f * params->star_color[1], 255.0f * params->star_color[2]}},
            0,
            20.0f,
        };
        star_light = (TEffStarLight2D *)spawn_star_light_2d((s32)&position, (s32)&star, (s32)this);
    } else {
        star_light = NULL;
    }
    hit_wall = params->hit_wall;
    hit_object = params->hit_object;
    flags = params->flags;
    if (params->flags & 0x800) {
        check_object_hits();
        if (hit_wall != NULL) {
            hit_wall(item_id, &position, &velocity);
        }
        particle = NULL;
        trail_particle = NULL;
        continuous_particle = NULL;
        queue_destruction();
        disallow_rendering();
    } else {
        check_hits();
        if (params->particle != -1) {
            particle = create_particle_emitter(&position, params->particle);
            if (particle != NULL) {
                ParticleAngles direction = particle_direction;
                direction.x += params->rotation_y;
                particle->set_direction(&direction);
            }
        } else {
            particle = NULL;
        }
        if (params->trail_particle != -1) {
            trail_particle = create_particle_emitter(&position, params->trail_particle);
        } else {
            trail_particle = NULL;
        }
        if (params->flags & 0x10) {
            continuous_particle = spawn_continuous_particle_effect_with_flags(&position, 0x19E, 0x2000);
        } else {
            continuous_particle = NULL;
        }
    }
}

void TItemAttackCol::create(void *arg0, void *arg1) {
    new TItemAttackCol((TObject *)arg0, (S_802E449C *)arg1);
}

    extern const float lbl_805DE920;
void* TObjPlayer__sub_802E449C(void* a0) { TObjPlayer__sub_802E451C((S_802E451C *)(a0)); *(int*)((char*)a0 + 0x40) = 0; *(int*)((char*)a0 + 0x44) = 0; *(int*)((char*)a0 + 0x48) = 0; *(float*)((char*)a0 + 0x4c) = lbl_805DE918; *(int*)((char*)a0 + 0x50) = 0; *(int*)((char*)a0 + 0x54) = 0; *(int*)((char*)a0 + 0x58) = 0; *(float*)((char*)a0 + 0x5c) = lbl_805DE920; *(float*)((char*)a0 + 0x60) = lbl_805DE918; *(float*)((char*)a0 + 0x64) = lbl_805DE918; *(float*)((char*)a0 + 0x68) = lbl_805DE918; *(float*)((char*)a0 + 0x6c) = lbl_805DE918; *(int*)((char*)a0 + 0x70) = 0; *(int*)((char*)a0 + 0x74) = 0; *(int*)((char*)a0 + 0x78) = -1; *(int*)((char*)a0 + 0x7c) = -1; return a0; }

void TObjPlayer__sub_802E451C(S_802E451C *arg0) {
    arg0->position.x = lbl_805DE914;
    arg0->position.y = lbl_805DE914;
    arg0->position.z = lbl_805DE914;
    arg0->radius = lbl_805DE924;
    arg0->hits = 1;
    arg0->client_id = 0xFFFF;
    arg0->room = -1;
    arg0->item_id = -1;
    arg0->pad_1C = lbl_805DE914;
    arg0->pad_20 = (*(const f32 *)&lbl_805DE918);
    arg0->pad_24 = 0;
}

s32 TUnk_804E355C::resolve_attack_col_hit(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_802E456C, sp8) == 0x0) ? 1 : -1];
    typedef char sp9_offset[(offsetof(Stack_802E456C, sp9) == 0x1) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802E456C, spC) == 0x4) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_802E456C, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_802E456C, sp18) == 0x10) ? 1 : -1];
    Stack_802E456C stack;
    s32 temp_r31;
    s32 temp_r31_2;
    u8 *temp_r30;
    u8 *player;
    u32 item;
    s32 temp_r0;
    f32 var_f31;
    temp_r30 = (u8 *)(*(u8 **)((s8 *)arg1 + 0));
    player = (u8 *)(get_player_by_client_id(this->client_id));
    item = (u32)find_item_by_id((this->item_id));
    temp_r31 = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg1 + 0)) + 0xA4) + (*(s32 *)((s8 *)arg1 + 4) * 0x2C);
    if ((player != NULL) && (item != 0U) && (((VObj_18_f2ea1e *)(temp_r30))->m19(player, temp_r31, 0, *(f32 *)((s8 *)arg0 + 0xB0)) != 0)) {
        temp_r0 = *(s32 *)((s8 *)arg0 + 0xB8);
        var_f31 = lbl_805DE914;
        switch (temp_r0) {
        case 0:
            var_f31 = ((VObj_18_f2ea1e *)(temp_r30))->m20(player, this->pad_B4);
            break;
        case 1:
            var_f31 = ((VObj_18_f2ea1e *)(temp_r30))->m20(player, this->pad_B4);
            ((VObj_18_f2ea1e *)(temp_r30))->m23(player, lbl_805DE928 * var_f31);
            break;
        case 2:
            ((VObj_18_f2ea1e *)(temp_r30))->m22(player, temp_r31);
            break;
        }
        temp_r31_2 = (s32) var_f31;
        TObjPlayer::calc_photon_blast_charge((void *)player, temp_r31_2);
        ((VObj_18_f2ea1e *)(player))->m73();
        apply_camera_shake__10TObjPlayerFiii((s32)player, (s32)temp_r30, (s32)temp_r31_2);
        ((TObjPlayer *)(&stack.sp8))->reset_status_block();
        stack.sp8 = ((TItem *)item)->get_item_group();
        stack.sp9 = ((TItem *)item)->get_item_index();
        stack.spC = player;
        stack.sp14 = temp_r30;
        stack.sp18 = *(s32 *)((s8 *)arg1 + 4);
        play_weapon_hit_sound(&stack.sp8);
        return 1;
    }
    return 0;
}
}
