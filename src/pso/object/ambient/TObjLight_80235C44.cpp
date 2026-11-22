#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/NinjaTypes.h"
#include "pso/object/ambient/TObjLight_80235C44.h"
#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/TEffect.h"
#include "pso/object/TUnk_804CCAA8.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/unk/text_8023601C.h"
#include "pso/technique/TTecLuker.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/TUnk_804CCC68.h"
#include "pso/effect/TUnk_804CC148.h"
#include "pso/technique/TTecPlayerInfluence.h"
#include "pso/technique/TechniqueContact.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/render_util.h"


static const f32 lbl_805DC888[1] = {1.0f};
static const f32 lbl_805DC88C[1] = {0.0f};

struct Stack_80235E9C {
    s32 sp8;
    u8 trailing_storage[0xC];
};

struct Light_80235C44 {
    u8 task[0x1C];
    s32 duration;
    u32 phase;
    NJS_ARGB color;
    Vec desired;
    Vec direction;
    s32 age;
    f32 step;
    saddr source;
    f32 peak;
    f32 intensity;
    u16 actor;
    u16 pad62;
};

struct Base_80235C44 { u8 pad[0x1C]; f32 f1c; f32 f20; };

extern "C" {
u16 get_entity_id(void *);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__13TUnk_804CCAA8[];

void publish_actor_light_scalars(u32 arg0, f32 farg0, f32 farg1);
void publish_light_direction_color(u32 id, void *dir, void *color);
extern Base_80235C44 TObjLight__scene_light_state;

#pragma push
#pragma fp_contract on
void TUnk_804CCAA8::run_task() {
    Light_80235C44 *arg0 = (Light_80235C44 *)this;
    Vec baseDir;
    NJS_ARGB baseColor;
    NJS_ARGB unused;
    f32 mid;
    f32 frac;
    if (get_player_by_client_id(arg0->actor) == 0) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    TObjLight::find_light_params((f32 *)&baseDir, (f32 *)&baseColor, arg0->actor);
    mid = 0.5f * (f32) arg0->duration;
    if (arg0->age < (s32) mid) {
        f32 amb1;
        f32 inten1;
        frac = (f32) arg0->age / mid;
        amb1 = frac * (arg0->peak - TObjLight__scene_light_state.f20) + TObjLight__scene_light_state.f20;
        inten1 = frac * (arg0->intensity - TObjLight__scene_light_state.f1c) + TObjLight__scene_light_state.f1c;
        publish_actor_light_scalars((u16) get_entity_id((void *)arg0->source), inten1, amb1);
        copy_argb((NJS_ARGB *)&unused, (NJS_ARGB *)&baseColor);
        approach_vector_fixed_distance(&arg0->direction, &arg0->desired, &arg0->direction, arg0->step);
        approach_rgb_clamped(&unused, &arg0->color, 0.1f);
    } else {
        f32 amb2;
        f32 inten2;
        frac = ((f32) arg0->age - mid) / mid;
        amb2 = frac * (TObjLight__scene_light_state.f20 - arg0->peak) + arg0->peak;
        inten2 = frac * (TObjLight__scene_light_state.f1c - arg0->intensity) + arg0->intensity;
        publish_actor_light_scalars((u16) get_entity_id((void *)arg0->source), inten2, amb2);
        approach_vector_fixed_distance(&arg0->direction, &baseDir, &arg0->direction, arg0->step);
        approach_rgb_clamped(&arg0->color, &baseColor, 0.1f);
    }
    publish_light_direction_color((u16) get_entity_id((void *)arg0->source), &arg0->direction, &arg0->color);
    arg0->age++;
    if (arg0->duration < arg0->age) {
        ((TObject *)arg0)->queue_destruction();
    }
}
#pragma pop

}
TUnk_804CCAA8::~TUnk_804CCAA8() {

}

u8 *TObjLight::construct_actor_light(saddr arg1, saddr arg2, s32 arg3, s32 arg4, saddr parent, f32 farg0, f32 farg1, f32 farg2, s32 arg_sp0) {
    Stack_80235E9C stack;
    __ct__7TObjectFP7TObject(this, (void *)parent);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = __vt__13TUnk_804CCAA8;
    copy_argb((NJS_ARGB *)(((u8 *)this) + 0x24), (NJS_ARGB *)arg1);
    VecCopy((Vec *)(((u8 *)this) + 0x34), (const Vec *)(arg2));
    *(s32 *)&this->entity_id = arg3;
    *(s32 *)&this->prev_position.z = 0;
    this->home_position.x = farg0;
    *(s32 *)&this->home_position.y = arg4;
    *(s32 *)((s8 *)((u8 *)this) + 0x20) = 1;
    this->home_position.z = farg1;
    *(f32 *)&this->rotation_x = farg2;
    *(u16 *)&this->rotation_y = get_entity_id((void *)(int) (*(s32 *)&this->home_position.y));
    TObjLight::find_light_params((f32 *)(((u8 *)this) + 0x40), (f32 *)&stack.sp8, (u32)((int) ((s32) *(u16 *)&this->rotation_y)));
    return ((u8 *)this);
}
u8 *construct_actor_light_task(u8 *arg0, NJS_ARGB *njs_argb, u8 *arg2, s32 arg3, u8 *arg4, u8 *parent, f32 farg0) {
    s32 sp8;
    __ct__7TObjectFP7TObject(arg0, parent);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804CCAA8;
    copy_argb((NJS_ARGB *)(arg0 + 0x24), njs_argb);
    VecCopy((Vec *)(arg0 + 0x34), (const Vec *)arg2);
    *(s32 *)((s8 *)arg0 + 0x1C) = arg3;
    ((TUnk_804CCAA8 *)arg0)->m_4c = 0;
    *(f32 *)((s8 *)arg0 + 0x50) = farg0;
    ((TUnk_804CCAA8 *)arg0)->m_54 = arg4;
    ((TUnk_804CCAA8 *)arg0)->m_20 = 0;
    *(f32 *)((s8 *)arg0 + 0x58) = (f32) lbl_805DC888[0];
    ((TUnk_804CCAA8 *)arg0)->m_5c = (f32) lbl_805DC888[0];
    *(u16 *)((s8 *)arg0 + 0x60) = ((u16)get_entity_id((void *)(saddr)(((TUnk_804CCAA8 *)arg0)->m_54)));
    TObjLight::find_light_params((f32 *)(arg0 + 0x40), (f32 *)((saddr) &sp8), (u32)((int)((u32) *(u16 *)((s8 *)arg0 + 0x60))));
    return arg0;
}

extern "C" {
f32 vec_squared_length(void *, f32);
}
extern TCameraCtrl *camera_ctrl_instance;

#pragma push
#pragma fp_contract on
void offset_point_toward_camera(u8 *center, u8 *arg1, f32 farg0) {
    Vec stack;
    f32 temp_f1;
    if ((void *) camera_ctrl_instance != NULL) {
        stack.x = camera_ctrl_instance->pos_x - *(f32 *)((s8 *)center + 0);
        stack.y = camera_ctrl_instance->pos_y - *(f32 *)((s8 *)center + 4);
        temp_f1 = camera_ctrl_instance->pos_z;
        stack.z = temp_f1 - *(f32 *)((s8 *)center + 8);
        if (lbl_805DC88C[0] != vec_squared_length(&stack.x, temp_f1)) {
            normalize_vector(&stack);
        }
        *(f32 *)((s8 *)arg1 + 0) = (f32) ((stack.x * farg0) + *(f32 *)((s8 *)center + 0));
        *(f32 *)((s8 *)arg1 + 4) = (f32) ((stack.y * farg0) + *(f32 *)((s8 *)center + 4));
        *(f32 *)((s8 *)arg1 + 8) = (f32) ((stack.z * farg0) + *(f32 *)((s8 *)center + 8));
    }
}
#pragma pop


s32 TTecLuker::is_parents_unqueued(uaddr arg0) {
    if (arg0 == 0U) {
        return 0;
    }
    if (((TObject *)arg0)->all_parents_unqueued_for_destruction()) {
        return 1;
    }
    return 0;
}


struct Stack_80236290 {
    s32 sp8;
    u8 trailing_storage[0x8];
};

struct Contact_80236154 { u8 pad[0x18]; u32 flags; };

struct PlayerData_80236154 { u8 pad[0x30]; u32 flags; };

struct List_80236154 {
    PlayerData_80236154 *actors[16];
    Contact_80236154 *bodies[16];
    s32 count;
    u32 reserved84;
};

struct PlayerData_80236154;

struct Contact_80236378 { u8 pad[0x18]; u32 flags; };

struct PD_80236378 { u8 pad[0x30]; u32 flags; };

struct List_80236378 {
    PD_80236378 *actors[16];
    Contact_80236378 *bodies[16];
    s32 count;
    u32 reserved84;
};

struct Contact_802364D8 { u8 pad[0x18]; u32 flags; };

struct PD_802364D8 { u8 pad[0x30]; u32 flags; };

struct List_802364D8 {
    PD_802364D8 *actors[16];
    Contact_802364D8 *bodies[16];
    s32 count;
    u32 reserved84;
};

struct Contact_802367D8 { u8 pad[0x18]; u32 flags; };

struct PD_802367D8 { u8 pad[0x30]; u32 flags; };

struct List_802367D8 {
    PD_802367D8 *actors[16];
    Contact_802367D8 *bodies[16];
    s32 count;
    u32 reserved84;
};

struct Sub_802367D8 { u8 pad[0xC]; f32 fC; f32 f10; };

struct Proxy_802367D8 { u8 pad[0xA4]; Sub_802367D8 *a4; };

struct Self_802367D8 { u8 pad[0x128]; Proxy_802367D8 *proxy; f32 f12c; };

struct Contact_80236A20 { u8 pad[0x18]; u32 flags; };

struct PD_80236A20 { u8 pad[0x30]; u32 flags; };

struct List_80236A20 {
    PD_80236A20 *actors[16];
    Contact_80236A20 *bodies[16];
    s32 count;
    u32 reserved84;
};

struct Sub_80236A20 { u8 pad[0xC]; f32 fC; f32 f10; };

struct Proxy_80236A20 { u8 pad[0xA4]; Sub_80236A20 *a4; };

struct Self_80236A20 { u8 pad[0x128]; Proxy_80236A20 *proxy; f32 f12c; };

extern "C" {

f32 vector_length(void *);
const f64 lbl_8044D8D0[1] = {0.5};
s32 obj_is_hit_receivable();

s32 TObjPlayer::is_valid_and_active(uaddr arg0) {
    if (arg0 == 0U) {
        return 0;
    }
    if (obj_is_hit_receivable()) {
        return 1;
    }
    return 0;
}
}
TechniqueContactQueryResults technique_contact_query_results;

void resetTechniqueContactQuery();

saddr find_support_technique_contact(void *self, TObjCollidable *target, void *_w2, void *_w3);
saddr find_area_technique_contact(TUnk_804CC148 *self, TObjCollidable *target, CollisionBody *body, void *arg3);

saddr find_support_technique_contact(void *self, TObjCollidable *target, void *_w2, void *_w3) {
    Vec pos;
    f32 range;
    s32 i;
    PlayerData_80236154 *pd;
    Contact_80236154 *c;
    if (get_current_floor_area() == AREA_DARK_FALZ) {
        range = 6.25e+04f;
    } else {
        range = 1e+04f;
    }
    VecCopy((Vec *)&pos, (const Vec *)((u8 *)self + 0x20));
    resetTechniqueContactQuery();
    if (target == NULL) {
        return (saddr)&technique_contact_query_results;
    }
    VecCopy(&target->position, &pos);
    for (i = TLobby::get_game_mode(); i < TLobby::get_lobby_flag(); i++) {
        pd = (PlayerData_80236154 *)TObjPlayer::get_player_data(i);
        if (pd != 0 && (pd->flags & 0x20000000)) {
            c = (Contact_80236154 *)target->find_actor_body_contact((u8 *)pd, range);
            if (c != 0 && ((c->flags & 1) || !(c->flags & 0x02000000))) {
                ((List_80236154 *)&technique_contact_query_results)->bodies[((List_80236154 *)&technique_contact_query_results)->count] = c;
                ((List_80236154 *)&technique_contact_query_results)->actors[((List_80236154 *)&technique_contact_query_results)->count] = pd;
                if (++((List_80236154 *)&technique_contact_query_results)->count >= 16) {
                    ((List_80236154 *)&technique_contact_query_results)->count = 15;
                    break;
                }
            }
        }
    }
    return (saddr)&technique_contact_query_results;
}

s32 *TObjPlayer::gather_player_contacts(uaddr actor, saddr _w2, s32 _w3) {
    saddr arg0 = (saddr)this;
    Stack_80236290 stack;
    s32 temp_r0;
    saddr player;
    s32 var_r29;
    uaddr temp_r3_2;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x20));
    resetTechniqueContactQuery();
    if (actor == 0U) {
        return &technique_contact_query_results.value;
    }
    VecCopy((Vec *)(actor + 0x38), (const Vec *)(&stack.sp8));
    var_r29 = 0;
loop_3:
    player = (saddr)get_player_by_client_id((var_r29));
    if ((player != 0) && (temp_r3_2 = (uaddr)((TObjCollidable *)actor)->find_actor_body_contact((u8 *)player, (f32)1e+04f), ((temp_r3_2 == 0U) == 0)) && (*(u32 *)((s8 *)((u8 *)&technique_contact_query_results.value + (*(s32 *)((s8 *)&technique_contact_query_results.value + 0x80) * 4)) + 0x40) = temp_r3_2, *(s32 *)((s8 *)&technique_contact_query_results.value + (*(s32 *)((s8 *)&technique_contact_query_results.value + 0x80) * 4)) = player, temp_r0 = *(s32 *)((s8 *)&technique_contact_query_results.value + 0x80) + 1, *(s32 *)((s8 *)&technique_contact_query_results.value + 0x80) = temp_r0, ((temp_r0 < 0x10) == 0))) {
        *(s32 *)((s8 *)&technique_contact_query_results.value + 0x80) = 0xF;
    } else {
        var_r29 += 1;
        if (var_r29 < 4) {
            goto loop_3;
        }
    }
    return &technique_contact_query_results.value;
}

saddr find_area_technique_contact(TUnk_804CC148 *self, TObjCollidable *target, CollisionBody *body, void *arg3) {
    Vec pos;
    f32 range;
    PD_80236378 *pd;
    s32 i;
    Contact_80236378 *c;
    if (get_current_floor_area() == AREA_DARK_FALZ) {
        range = 6.25e+04f;
    } else {
        range = 6.25e+04f;
    }
    VecCopy(&pos, &self->position);
    resetTechniqueContactQuery();
    if (target == NULL) {
        return (saddr)&technique_contact_query_results;
    }
    VecCopy(&target->position, &pos);
    for (i = TLobby::get_game_mode(); i < TLobby::get_lobby_flag(); i++) {
        pd = (PD_80236378 *)TObjPlayer::get_player_data(i);
        if (pd != 0 && (pd->flags & 0x20000000) && get_entity_id(pd) != get_entity_id(arg3)) {
            c = (Contact_80236378 *)target->find_actor_body_contact((u8 *)pd, range);
            if (c != 0 && ((c->flags & 1) || !(c->flags & 0x02000000))) {
                ((List_80236378 *)&technique_contact_query_results)->bodies[((List_80236378 *)&technique_contact_query_results)->count] = c;
                ((List_80236378 *)&technique_contact_query_results)->actors[((List_80236378 *)&technique_contact_query_results)->count] = pd;
                if (++((List_80236378 *)&technique_contact_query_results)->count >= 16) {
                    ((List_80236378 *)&technique_contact_query_results)->count = 15;
                    break;
                }
            }
        }
    }
    return (saddr)&technique_contact_query_results;
}

saddr TUnk_804CC148::collect_body_contacts(TObjCollidable *target, CollisionBody *body, void *player) {
    Vec pos;
    PD_802364D8 *e;
    PD_802364D8 *pd;
    s32 i;
    s32 n;
    s32 ok;
    Contact_802364D8 *c;
    s32 j;
    VecCopy(&pos, &position);
    resetTechniqueContactQuery();
    if (target == NULL) {
        return (saddr)&technique_contact_query_results;
    }
    VecCopy(&target->position, &pos);
    if (get_entity_id(player) < 4) {
        n = TLobby::get_lobby_flag();
        for (i = 0; i < n; i++) {
            pd = (PD_802364D8 *)TObjPlayer::get_player_data(i);
            if (pd != 0 && get_entity_id(pd) != get_entity_id(player)) {
                ok = 1;
                if (get_entity_id(pd) < 4) {
                    if (((TObjPlayer *)player)->get_floor() == ((TObjPlayer *)pd)->get_floor()) {
                        ok = 1;
                    } else {
                        ok = 0;
                    }
                }
                if (ok != 0 && ((pd->flags & 0x20000000) || (pd->flags & 0x10000000))) {
                    c = (Contact_802364D8 *)target->find_actor_body_contact((u8 *)pd, 1e+04f);
                    if (c != 0 && ((c->flags & 1) || !(c->flags & 0x02000000))) {
                        ((List_802364D8 *)&technique_contact_query_results)->bodies[((List_802364D8 *)&technique_contact_query_results)->count] = c;
                        ((List_802364D8 *)&technique_contact_query_results)->actors[((List_802364D8 *)&technique_contact_query_results)->count] = pd;
                        if (++((List_802364D8 *)&technique_contact_query_results)->count >= 16) {
                            ((List_802364D8 *)&technique_contact_query_results)->count = 15;
                            break;
                        }
                    }
                }
            }
        }
    } else {
        for (j = 0; j < 4; j++) {
            e = (PD_802364D8 *)find_entity_by_id(j);
            if (e != 0 && get_entity_id(e) != get_entity_id(player) && (e->flags & 0x10000000)) {
                c = (Contact_802364D8 *)target->find_actor_body_contact((u8 *)e, 1e+04f);
                if (c != 0) {
                    ((List_802364D8 *)&technique_contact_query_results)->bodies[((List_802364D8 *)&technique_contact_query_results)->count] = c;
                    ((List_802364D8 *)&technique_contact_query_results)->actors[((List_802364D8 *)&technique_contact_query_results)->count] = e;
                    if (++((List_802364D8 *)&technique_contact_query_results)->count >= 16) {
                        ((List_802364D8 *)&technique_contact_query_results)->count = 15;
                        break;
                    }
                }
            }
        }
    }
    return (saddr)&technique_contact_query_results;
}

void TUnk_804CC148::find_area_contact(saddr arg1) {
    find_area_technique_contact(this, this->m_e8, &this->collisionBody, (void *)arg1);
}

saddr TUnk_804CC148::collect_body_contacts_for_target(saddr player) {
    return collect_body_contacts(m_e8, &collisionBody, (void *)player);
}

saddr TTecPlayerInfluence::find_support_technique_contact_for_target(saddr player) {
    return find_support_technique_contact(this, target, &m_b0, (void *)player);
}

void TObjPlayer::gather_contacts_for_self(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    gather_player_contacts((uaddr)this->motion_list, (saddr)(arg0 + 0xb0), arg1);
}

u8 *TUnk_804CCC68::query_technique_enemy_contacts(saddr arg) {
    Vec pos;
    Vec d;
    f32 range;
    f32 *pp;
    PD_802367D8 *pd;
    s32 i;
    Contact_802367D8 *c;
    Self_802367D8 *s = (Self_802367D8 *)this;
    if (get_current_floor_area() == AREA_DARK_FALZ) {
        range = 6.25e+04f;
    } else {
        range = 1e+04f;
    }
    VecCopy((Vec *)&pos, (const Vec *)((u8 *)this + 0x20));
    resetTechniqueContactQuery();
    if (s->proxy == 0) {
        return (u8 *)&technique_contact_query_results;
    }
    pp = (f32 *)((void *)((TObjPlayer *)this)->get_pos_ptr());
    d.x = pos.x - pp[0];
    d.y = pos.y - pp[1];
    d.z = pos.z - pp[2];
    {
        f32 len = vector_length(&d);
        s->proxy->a4->f10 = s->f12c;
        s->proxy->a4->fC = 0.5f * len;
    }
    pos.x = 0.5f * (pos.x + pp[0]);
    pos.y = 0.5f * (pos.y + pp[1]);
    pos.z = 0.5f * (pos.z + pp[2]);
    VecCopy((Vec *)((u8 *)s->proxy + 0x38), (const Vec *)&pos);
    copy_xyz((u8 *)s->proxy + 0x5C, (u8 *)this + 0x54);
    for (i = TLobby::get_game_mode(); i < TLobby::get_lobby_flag(); i++) {
        pd = (PD_802367D8 *)TObjPlayer::get_player_data(i);
        if (pd == 0) continue;
        if (pd->flags & 0x20000000) {
            if (get_entity_id(pd) == get_entity_id((void *)arg)) continue;
            c = (Contact_802367D8 *)((TObjCollidable *)((u8 *)s->proxy))->find_actor_body_contact((u8 *)pd, (f32)range);
            if (c != 0 && ((c->flags & 1) || !(c->flags & 0x02000000))) {
                ((List_802367D8 *)&technique_contact_query_results)->bodies[((List_802367D8 *)&technique_contact_query_results)->count] = c;
                ((List_802367D8 *)&technique_contact_query_results)->actors[((List_802367D8 *)&technique_contact_query_results)->count] = pd;
                if (++((List_802367D8 *)&technique_contact_query_results)->count >= 16) {
                    ((List_802367D8 *)&technique_contact_query_results)->count = 15;
                    break;
                }
            }
        } else if ((pd->flags & 0x40000000) && !(pd->flags & 0x80000000)) {
            if (((TObjCollidable *)((u8 *)s->proxy))->find_actor_body_contact((u8 *)pd, (f32)1e+04f) != 0) {
                return 0;
            }
        }
    }
    return (u8 *)&technique_contact_query_results;
}

u8 *TUnk_804CCC68::query_technique_player_contacts(saddr arg) {
    Vec pos;
    Vec d;
    f32 range;
    f32 *pp;
    PD_80236A20 *e;
    PD_80236A20 *pd;
    s32 i;
    s32 n;
    Contact_80236A20 *c;
    s32 j;
    Self_80236A20 *s = (Self_80236A20 *)this;
    if (get_current_floor_area() == AREA_DARK_FALZ) {
        range = 6.25e+04f;
    } else {
        range = 1e+04f;
    }
    VecCopy((Vec *)&pos, (const Vec *)((u8 *)this + 0x20));
    resetTechniqueContactQuery();
    if (s->proxy == 0) {
        return (u8 *)&technique_contact_query_results;
    }
    pp = (f32 *)((void *)((TObjPlayer *)this)->get_pos_ptr());
    d.x = pos.x - pp[0];
    d.y = pos.y - pp[1];
    d.z = pos.z - pp[2];
    {
        f32 len = vector_length(&d);
        s->proxy->a4->f10 = s->f12c;
        s->proxy->a4->fC = lbl_8044D8D0[0] * len;
    }
    pos.x = 0.5f * (pos.x + pp[0]);
    pos.y = 0.5f * (pos.y + pp[1]);
    pos.z = 0.5f * (pos.z + pp[2]);
    VecCopy((Vec *)((u8 *)s->proxy + 0x38), (const Vec *)&pos);
    copy_xyz((u8 *)s->proxy + 0x5C, (u8 *)this + 0x54);
    if (get_entity_id((void *)arg) < 4) {
        n = TLobby::get_lobby_flag();
        for (i = 0; i < n; i++) {
            pd = (PD_80236A20 *)TObjPlayer::get_player_data(i);
            if (pd == 0) continue;
            if (get_entity_id(pd) == get_entity_id((void *)arg)) continue;
            c = (Contact_80236A20 *)((TObjCollidable *)((u8 *)s->proxy))->find_actor_body_contact((u8 *)pd, (f32)range);
            if (c != 0 && ((pd->flags & 0x20000000) || (pd->flags & 0x10000000)) && ((c->flags & 1) || !(c->flags & 0x02000000))) {
                ((List_80236A20 *)&technique_contact_query_results)->bodies[((List_80236A20 *)&technique_contact_query_results)->count] = c;
                ((List_80236A20 *)&technique_contact_query_results)->actors[((List_80236A20 *)&technique_contact_query_results)->count] = pd;
                if (++((List_80236A20 *)&technique_contact_query_results)->count >= 16) {
                    ((List_80236A20 *)&technique_contact_query_results)->count = 15;
                    break;
                }
            }
        }
    } else {
        for (j = 0; j < 4; j++) {
            e = (PD_80236A20 *)find_entity_by_id(j);
            if (e == 0) continue;
            if (get_entity_id(e) == get_entity_id((void *)arg)) continue;
            c = (Contact_80236A20 *)((TObjCollidable *)((u8 *)s->proxy))->find_actor_body_contact((u8 *)e, (f32)1e+04f);
            if (c != 0 && (e->flags & 0x10000000)) {
                ((List_80236A20 *)&technique_contact_query_results)->bodies[((List_80236A20 *)&technique_contact_query_results)->count] = c;
                ((List_80236A20 *)&technique_contact_query_results)->actors[((List_80236A20 *)&technique_contact_query_results)->count] = e;
                if (++((List_80236A20 *)&technique_contact_query_results)->count >= 16) {
                    ((List_80236A20 *)&technique_contact_query_results)->count = 15;
                    break;
                }
            }
        }
    }
    return (u8 *)&technique_contact_query_results;
}

void resetTechniqueContactQuery() {
    for (s32 i=0;i<16;++i) {
        (*(TechniqueContactList *)&technique_contact_query_results).actors[i]=0;
        (*(TechniqueContactList *)&technique_contact_query_results).bodies[i]=0;
    }
    (*(TechniqueContactList *)&technique_contact_query_results).count=0;
}

void*TObjPlayer::get_pos_ptr() { return (char*)this + 0x78; }
