#pragma readonly_strings on
#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/TEffStarLight2D.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
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
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/ending/TObjOnlineEnding.h"
#include <string.h>
#include "pso/technique/TTecCtrl.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

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

s32 play_weapon_hit_sound(void *);

void apply_camera_shake__10TObjPlayerFiii(s32 player, saddr target, s32 damage);

Hit_802E3D8C *csnVector(void *, void *, s32);


// The collider render() is drawing, and how many of its model's nodes have been drawn.
TItemAttackCol *attack_collider_render_owner;

int attack_collider_active_count;


void fn_802E3BA8(TItemAttackCol *col, void *node);


const char *TItemAttackCol__name = "TItemAttackCol";

// The particle's direction before the collider's heading is added.
static ParticleAngles particle_direction = {0x4000, 0, 0x4000};

void TObjPlayer__sub_801542F4(saddr a);

void TObjPlayer__sub_8015431C(u8 *set);

}
f32 vec_distance_squared(u8 *arg0, u8 *arg1);
TUnk_804E355C::TUnk_804E355C(TObject *parent, S_802E451C *params) : TObject(parent) {
    TObjPlayer *player;
    body.offset.x = 0.0f;
    body.offset.y = 0.0f;
    body.offset.z = 0.0f;
    body.radius = params->radius;
    body.half_width = 0.0f;
    body.shape = 0;
    body.flags = 0x41F07;
    body.center.x = 0.0f;
    body.center.y = 0.0f;
    body.center.z = 0.0f;
    body.unk_28 = 0.0f;
    bodies = &body;
    body_count = 1;
    VecCopy(&position, &params->position);
    memset(hits, 0, sizeof(hits));
    hit_count = 0;
    hits_left = params->hits;
    client_id = params->client_id;
    room = params->room;
    item_id = params->item_id;
    pad_B0 = params->pad_1C;
    pad_B4 = params->pad_20;
    pad_B8 = params->pad_24;
    pad_C0 = 1;
    player = get_player_by_client_id(params->client_id);
    if (player != NULL) {
        if (get_type__10TObjPlayerFPv(&player->m_828) != 0) {
            pad_BC = 1;
        } else {
            pad_BC = 0;
        }
    } else {
        pad_BC = 0;
    }
}

TUnk_804E355C::~TUnk_804E355C() {}

void TUnk_804E355C::check_hits() {
    s32 i;
    ActorBodyHit *hit;
    u8 *arg0 = (u8 *)this;
    reset_global_table();
    TObjPlayer__sub_801542F4((saddr)&this->bodies);
    if (pad_C0 != 0) {
        TObjPlayer__sub_8015431C((u8 *)&this->bodies);
    }
    if (pad_BC != 0) {
        TObjPlayer::apply_status_effect((saddr)(arg0 + 0x1C));
    }
    for (i = 0; i != TObjOnlineEnding::get_instance(); i++) {
        hit = static_cast<ActorBodyHit *>(TObjOnlineEnding::get_attack_entry(i));
        if (try_add_hit_target(hit) != 0) {
            vfunc_6(hit);
            hits_left -= 1;
            if (hits_left == 0) {
                queue_destruction();
                reset_global_table();
                return;
            }
        }
    }
    reset_global_table();
}

void copy_actor_body_hit(ActorBodyHit *destination, const ActorBodyHit *source) {
    volatile ActorBodyHit *output = destination;
    const volatile ActorBodyHit *input = source;
    output->target = input->target;
    output->body = input->body;
}

s32 TUnk_804E355C::try_add_hit_target(const ActorBodyHit *hit) {
    s32 ok;
    ActorBodyHit *previous;
    s32 i;
    s32 flags;
    if (hit_count >= 8) {
        return 0;
    }
    if (client_id == ((TObjBase *)hit->target)->get_entity_id()) {
        return 0;
    }
    ok = 1;
    if (TTecCtrl::is_technique_ready() == 0 && ((TObjCollidable *)hit->target)->test_actor_flags(0x60000000) == 0x20000000
        && this->room != ((TObjBase *)(hit->target))->get_room()) {
        ok = 0;
    }
    if (((TObjCollidable *)hit->target)->test_actor_flags(0x04000000) != 0
        || ((flags = hit->target->bodies[hit->body].flags) & 0x02000000)
        || (flags & 0x1000) || (flags & 0x80)) {
        ok = 0;
    }
    if (ok != 0) {
        previous = hits;
        for (i = 0; i != hit_count; i++) {
            if (previous->target == hit->target && previous->body == hit->body) {
                return 0;
            }
            previous++;
        }
        if (obj_is_hit_receivable(hit->target) != 0) {
            copy_actor_body_hit(previous, hit);
            hit_count += 1;
            return 1;
        }
    }
    return 0;
}

void TUnk_804E355C::vfunc_6(ActorBodyHit *hit) { resolve_attack_col_hit(hit); }

s32 TUnk_804E355C::has_game_join_id() {
    return find_equipped_item(item_id) != 0;
}

s32 TUnk_804E355C::resolve_attack_col_hit(ActorBodyHit *hit) {
    u8 *arg1 = (u8 *)hit;
    u8 *arg0 = (u8 *)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_802E456C, sp8) == 0x0);
    LAYOUT_ASSERT(sp9_offset, offsetof(Stack_802E456C, sp9) == 0x1);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_802E456C, spC) == 0x4);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_802E456C, sp14) == 0xC);
    LAYOUT_ASSERT(sp18_offset, offsetof(Stack_802E456C, sp18) == 0x10);
    Stack_802E456C stack;
    s32 temp_r31;
    s32 damage;
    u8 *target;
    u8 *player;
    uaddr item;
    s32 temp_r0;
    f32 var_f31;
    target = (u8 *)(*(u8 **)((s8 *)arg1 + 0));
    player = (u8 *)(get_player_by_client_id(this->client_id));
    item = (uaddr)find_item_by_id((this->item_id));
    temp_r31 = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg1 + 0)) + 0xA4) + (*(s32 *)((s8 *)arg1 + 4) * 0x2C);
    if ((player != NULL) && (item != 0U) && (((VObj_18_f2ea1e *)(target))->m19(player, temp_r31, 0, *(f32 *)((s8 *)arg0 + 0xB0)) != 0)) {
        temp_r0 = *(s32 *)((s8 *)arg0 + 0xB8);
        var_f31 = 0.0f;
        switch (temp_r0) {
        case 0:
            var_f31 = ((VObj_18_f2ea1e *)(target))->m20(player, this->pad_B4);
            break;
        case 1:
            var_f31 = ((VObj_18_f2ea1e *)(target))->m20(player, this->pad_B4);
            ((VObj_18_f2ea1e *)(target))->m23(player, 0.1f * var_f31);
            break;
        case 2:
            ((VObj_18_f2ea1e *)(target))->m22(player, temp_r31);
            break;
        }
        damage = (s32) var_f31;
        TObjPlayer::calc_photon_blast_charge((void *)player, damage);
        ((VObj_18_f2ea1e *)(player))->m73();
        apply_camera_shake__10TObjPlayerFiii((saddr)player, (saddr)target, (s32)damage);
        ((TObjPlayer *)(&stack.sp8))->reset_status_block();
        stack.sp8 = ((TItem *)item)->get_item_group();
        stack.sp9 = ((TItem *)item)->get_item_index();
        stack.spC = player;
        stack.sp14 = target;
        stack.sp18 = *(s32 *)((s8 *)arg1 + 4);
        play_weapon_hit_sound(&stack.sp8);
        return 1;
    }
    return 0;
}

void reset_attack_params(S_802E451C *s_802_e451_c) {
    s_802_e451_c->position.x = 0.0f;
    s_802_e451_c->position.y = 0.0f;
    s_802_e451_c->position.z = 0.0f;
    s_802_e451_c->radius = 5.0f;
    s_802_e451_c->hits = 1;
    s_802_e451_c->client_id = 0xFFFF;
    s_802_e451_c->room = -1;
    s_802_e451_c->item_id = -1;
    s_802_e451_c->pad_1C = 0.0f;
    s_802_e451_c->pad_20 = 1.0f;
    s_802_e451_c->pad_24 = 0;
}

Desc_8011E5C4 *TObjPlayer__sub_802E449C(Desc_8011E5C4 *params) {
    reset_attack_params(params);
    params->flags = 0;
    params->model = NULL;
    params->texlist = 0;
    params->scale = 1.0f;
    params->spin[0] = 0;
    params->spin[1] = 0;
    params->spin[2] = 0;
    params->star_width = 3.0f;
    params->color.a = 1.0f;
    params->color.r = 1.0f;
    params->color.g = 1.0f;
    params->color.b = 1.0f;
    params->wall_effect = NULL;
    params->hit_effect = NULL;
    params->particle = -1;
    params->trail_particle = -1;
    return params;
}

void TItemAttackCol::create(TObject *parent, Desc_8011E5C4 *params) {
    new TItemAttackCol(parent, params);
}

TItemAttackCol::TItemAttackCol(TObject *parent, Desc_8011E5C4 *params) : TUnk_804E355C(parent, params) {
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
    model = (uaddr)params->model;
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
            {{0, 255.0f * params->color.r, 255.0f * params->color.g, 255.0f * params->color.b}},
            0,
            20.0f,
        };
        star_light = spawn_star_light_2d(&position, &star, this);
    } else {
        star_light = NULL;
    }
    hit_wall = reinterpret_cast<TItemAttackColHitWall>(params->wall_effect);
    hit_object = reinterpret_cast<TItemAttackColHitObject>(params->hit_effect);
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
                s32 yaw = params->rotation_y;
                ParticleAngles direction = particle_direction;
                direction.x += yaw;
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
    if ((range_sq <= vec_distance_squared((u8 *)&position, (u8 *)&start_position)) || (test_flags_any((s32 *)&hit_wall_flags, 1) != 0)) {
        queue_destruction();
    }
}

void TItemAttackCol::render() {
    if ((s32)this->all_parents_unqueued_for_destruction() == 0 || find_equipped_item(item_id) == 0U) {
        return;
    }
    {
        if (model != 0U) {
            if (texlist != 0U) {
                set_texlist(texlist);
            }
            TParticleCtrl::begin_effect_render();
            attack_collider_render_owner = this;
            attack_collider_active_count = 0;
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_by_node_angles(rotation, 1);
            rotate_matrix_by_node_angles(spin, 1);
            scale_current_matrix(&scale.x);
            draw_node_tree_with_callback((NJS_OBJECT *)model, (void (*)(NJS_OBJECT *))TItemAttackCol::add_to_active_list);
            pop_matrix();
            attack_collider_render_owner = 0;
            TParticleCtrl::end_effect_render();
        }
    }
}

void TItemAttackCol::move_with_collision(void *to) {
    Hit_802E3D8C *hit;
    hit = csnVector((u8 *)&position, to, 0x8100);
    if (hit != NULL) {
        hit_wall_flags.set(1);
        VecCopy(&position, (const Vec *)(hit->pos));
        if (hit_wall != NULL) {
            hit_wall(item_id, &position, &velocity);
        }
    } else {
        VecCopy(&position, (const Vec *)(to));
    }
}

void TItemAttackCol::vfunc_7() {
    Vec next;

    VecCopy(&next, &velocity);
    vec3_add_to(&next, &position);
    move_with_collision(&next);
}

void TItemAttackCol::vfunc_6(ActorBodyHit *hit) {
    if (!(flags & 0x80)) {
        if (resolve_attack_col_hit(hit) != 0) {
            if (hit_object != NULL) {
                hit_object(item_id, (s32 *)hit, &velocity);
            }
            if (flags & 0x100) {
                pad_B4 *= 0.75f;
            }
        }
    } else {
        if (hit_object != NULL) {
            hit_object(item_id, (s32 *)hit, &velocity);
        }
        if (flags & 0x200) {
            VObj_802E3C4C *p = (VObj_802E3C4C *)find_item_by_id(item_id);
            u8 *b = (u8 *)get_player_by_client_id(client_id);
            if (p != NULL) {
                p->m59(b, (saddr)hit->target, pad_B8, pad_B4, hit->body);
            }
        }
    }
}

void TItemAttackCol::shift_collision_bounds() {
    spin[2] += 0xCCC;
    pad_114[2] -= 0xCCC;
}

void TItemAttackCol::add_to_active_list(void* node) { fn_802E3BA8(attack_collider_render_owner, node); attack_collider_active_count = (attack_collider_active_count + 0x1); }

// Called for each node of the model before add_to_active_list counts it:
// with flag 8 the second node drawn gets the collider's extra rotation and scale.
void fn_802E3BA8(TItemAttackCol *col, void *node) {
    if ((col->flags & 8) && attack_collider_active_count == 1) {
        rotate_matrix_by_node_angles(col->pad_114, 1);
        scale_current_matrix(col->pad_120);
    }
}

void TItemAttackCol::check_object_hits() {
    s32 i;
    ActorBodyHit *hit;
    reset_global_table();
    TObjPlayer__sub_8015431C((u8 *)&this->bodies);
    for (i = 0; i != TObjOnlineEnding::get_instance(); i++) {
        hit = static_cast<ActorBodyHit *>(TObjOnlineEnding::get_attack_entry(i));
        if (try_add_hit_target(hit) != 0) {
            this->vfunc_6(hit);
            this->hits_left -= 1;
            if (this->hits_left == 0) {
                queue_destruction();
                reset_global_table();
                return;
            }
        }
    }
    reset_global_table();
}
