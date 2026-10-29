#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/effect/TEffect.h"
#include "pso/object/TUnk_804CCAA8.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/object/TObjLight.h"
#include "pso/unk/text_8023601C.h"
#include "pso/misc/TTecLuker.h"
#include "pso/object/TObjMotion.h"
#include "pso/effect/TUnk_804CCC68.h"
#include "pso/effect/TUnk_804CC148.h"
#include "pso/technique/TechniqueContact.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby.h"
#include "pso/map/FloorArea.h"

static const f32 lbl_805DC888[1] = {1.0f};
static const f32 lbl_805DC88C[1] = {0.0f};

struct Stack_80235E9C {
    s32 sp8;
    u8 trailing_storage[0xC];
};

struct RecoveredGlobal_80235E9C_lbl_804CCAA8 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_80235F60_lbl_804CCAA8 {
    s32 value;
    u8 remaining[0x14];
};

struct Vec_80235C44 { f32 x, y, z; };

struct Light_80235C44 {
    u8 task[0x1C];
    s32 duration;
    u32 phase;
    NJS_ARGB color;
    Vec_80235C44 desired;
    Vec_80235C44 direction;
    s32 age;
    f32 step;
    s32 source;
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

u8 *construct_actor_light_task(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u8 *arg4, u8 *arg5, f32 farg0);
void queue_destruction__7TObjectFv(void *arg0);
void publish_actor_light_scalars(u32 arg0, f32 farg0, f32 farg1);
void publish_light_direction_color(u32 id, void *dir, void *color);
s32 approach_vector_fixed_distance(void *, void *, void *, f32);
void *get_player_by_client_id(s32 i);
extern Base_80235C44 TObjLight__scene_light_state;

#pragma push
#pragma fp_contract on
void TUnk_804CCAA8::run_task() {
    Light_80235C44 *arg0 = (Light_80235C44 *)this;
    Vec_80235C44 baseDir;
    NJS_ARGB baseColor;
    NJS_ARGB unused;
    f32 mid;
    f32 frac;
    if (get_player_by_client_id(arg0->actor) == 0) {
        queue_destruction__7TObjectFv(arg0);
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
        queue_destruction__7TObjectFv(arg0);
    }
}
#pragma pop

}
TUnk_804CCAA8::~TUnk_804CCAA8() {

}

typedef char RecoveredGlobal_80235E9C_lbl_804CCAA8_size[sizeof(RecoveredGlobal_80235E9C_lbl_804CCAA8) == 0x18 ? 1 : -1];
u8 *TObjLight::construct_actor_light(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0, f32 farg1, f32 farg2, s32 arg_sp0) {
    Stack_80235E9C stack;
    __ct__7TObjectFP7TObject(this, (void *)arg5);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_80235E9C_lbl_804CCAA8 *)&__vt__13TUnk_804CCAA8).value;
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
typedef char RecoveredGlobal_80235F60_lbl_804CCAA8_size[sizeof(RecoveredGlobal_80235F60_lbl_804CCAA8) == 0x18 ? 1 : -1];
u8 *construct_actor_light_task(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u8 *arg4, u8 *arg5, f32 farg0) {
    s32 sp8;
    __ct__7TObjectFP7TObject(arg0, arg5);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80235F60_lbl_804CCAA8 *)&__vt__13TUnk_804CCAA8).value;
    copy_argb((NJS_ARGB *)(arg0 + 0x24), (NJS_ARGB *)arg1);
    VecCopy((Vec *)(arg0 + 0x34), (const Vec *)arg2);
    *(s32 *)((s8 *)arg0 + 0x1C) = arg3;
    ((TUnk_804CCAA8 *)arg0)->m_4c = 0;
    *(f32 *)((s8 *)arg0 + 0x50) = farg0;
    ((TUnk_804CCAA8 *)arg0)->m_54 = arg4;
    ((TUnk_804CCAA8 *)arg0)->m_20 = 0;
    *(f32 *)((s8 *)arg0 + 0x58) = (f32) lbl_805DC888[0];
    ((TUnk_804CCAA8 *)arg0)->m_5c = (f32) lbl_805DC888[0];
    *(u16 *)((s8 *)arg0 + 0x60) = ((u16)get_entity_id((void *)(int)(((TUnk_804CCAA8 *)arg0)->m_54)));
    TObjLight::find_light_params((f32 *)(arg0 + 0x40), (f32 *)((s32) &sp8), (u32)((int)((u32) *(u16 *)((s8 *)arg0 + 0x60))));
    return arg0;
}

struct Stack_8023601C {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

extern "C" {
f32 vec_squared_length(void *, f32);
s32 normalize_vector(void *);
}
extern u8 *camera_ctrl_instance;

#pragma push
#pragma fp_contract on
void offset_point_toward_camera(u8 *arg0, u8 *arg1, f32 farg0) {
    Stack_8023601C stack;
    f32 temp_f1;
    if ((void *) camera_ctrl_instance != NULL) {
        stack.sp8 = *(f32 *)((s8 *)camera_ctrl_instance + 0x178) - *(f32 *)((s8 *)arg0 + 0);
        stack.spC = *(f32 *)((s8 *)camera_ctrl_instance + 0x17C) - *(f32 *)((s8 *)arg0 + 4);
        temp_f1 = *(f32 *)((s8 *)camera_ctrl_instance + 0x180);
        stack.sp10 = temp_f1 - *(f32 *)((s8 *)arg0 + 8);
        if (lbl_805DC88C[0] != vec_squared_length(&stack.sp8, temp_f1)) {
            normalize_vector(&stack.sp8);
        }
        *(f32 *)((s8 *)arg1 + 0) = (f32) ((stack.sp8 * farg0) + *(f32 *)((s8 *)arg0 + 0));
        *(f32 *)((s8 *)arg1 + 4) = (f32) ((stack.spC * farg0) + *(f32 *)((s8 *)arg0 + 4));
        *(f32 *)((s8 *)arg1 + 8) = (f32) ((stack.sp10 * farg0) + *(f32 *)((s8 *)arg0 + 8));
    }
}
#pragma pop

extern "C" {

s32 all_parents_unqueued_for_destruction__7TObjectFv();

s32 TTecLuker::is_parents_unqueued(u32 arg0) {
    if (arg0 == 0U) {
        return 0;
    }
    if (all_parents_unqueued_for_destruction__7TObjectFv()) {
        return 1;
    }
    return 0;
}

}

struct Stack_80236290 {
    s32 sp8;
    u8 trailing_storage[0x8];
};

struct RecoveredGlobal_80236290_lbl_80516150 {
    s32 value;
    u8 remaining[0x84];
};

struct Vec_80236154 { f32 x, y, z; };

struct Contact_80236154 { u8 pad[0x18]; u32 flags; };

struct PlayerData_80236154 { u8 pad[0x30]; u32 flags; };

struct List_80236154 {
    PlayerData_80236154 *actors[16];
    Contact_80236154 *bodies[16];
    s32 count;
    u32 reserved84;
};

struct RecoveredGlobal_80236290_lbl_80516150;
struct PlayerData_80236154;
struct Vec_80236378 { f32 x, y, z; };

struct Contact_80236378 { u8 pad[0x18]; u32 flags; };

struct PD_80236378 { u8 pad[0x30]; u32 flags; };

struct List_80236378 {
    PD_80236378 *actors[16];
    Contact_80236378 *bodies[16];
    s32 count;
    u32 reserved84;
};

struct Vec_802364D8 { f32 x, y, z; };

struct Contact_802364D8 { u8 pad[0x18]; u32 flags; };

struct PD_802364D8 { u8 pad[0x30]; u32 flags; };

struct List_802364D8 {
    PD_802364D8 *actors[16];
    Contact_802364D8 *bodies[16];
    s32 count;
    u32 reserved84;
};

struct Vec_802367D8 { f32 x, y, z; };

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

struct Vec_80236A20 { f32 x, y, z; };

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
void *get_player_by_client_id(s32 i);
int get_player_data__10TObjPlayerFi(int a0);

void *find_entity_by_id(u16 id);

f32 vector_length(void *);
extern const f64 lbl_8044D8D0[];
s32 obj_is_hit_receivable();

s32 TObjPlayer::is_valid_and_active(u32 arg0) {
    if (arg0 == 0U) {
        return 0;
    }
    if (obj_is_hit_receivable()) {
        return 1;
    }
    return 0;
}
}
extern RecoveredGlobal_80236290_lbl_80516150 technique_contact_query_results;

void resetTechniqueContactQuery();

s32 find_support_technique_contact(void *self, int target, void *_w2, void *_w3);
s32 find_area_technique_contact(void *self, int target, void *_w2, void *arg3);
typedef char RecoveredGlobal_80236290_lbl_80516150_size[sizeof(RecoveredGlobal_80236290_lbl_80516150) == 0x88 ? 1 : -1];

struct RecoveredGlobal_80236290_lbl_80516150;
s32 find_support_technique_contact(void *self, int target, void *_w2, void *_w3) {
    Vec_80236154 pos;
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
    if ((u32)target == 0) {
        return (s32)&technique_contact_query_results;
    }
    VecCopy((Vec *)((u8 *)target + 0x38), (const Vec *)&pos);
    for (i = TLobby::get_game_mode(); i < TLobby::get_lobby_flag(); i++) {
        pd = (PlayerData_80236154 *)get_player_data__10TObjPlayerFi(i);
        if (pd != 0 && (pd->flags & 0x20000000)) {
            c = (Contact_80236154 *)((TObjCollidable *)target)->find_actor_body_contact((u8 *)pd, range);
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
    return (s32)&technique_contact_query_results;
}

s32 *TObjPlayer::gather_player_contacts(u32 actor, s32 _w2, s32 _w3) {
    s32 arg0 = (s32)this;
    Stack_80236290 stack;
    s32 temp_r0;
    s32 player;
    s32 var_r29;
    u32 temp_r3_2;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x20));
    resetTechniqueContactQuery();
    if (actor == 0U) {
        return &technique_contact_query_results.value;
    }
    VecCopy((Vec *)(actor + 0x38), (const Vec *)(&stack.sp8));
    var_r29 = 0;
loop_3:
    player = (s32)get_player_by_client_id((var_r29));
    if ((player != 0) && (temp_r3_2 = (u32)((TObjCollidable *)actor)->find_actor_body_contact((u8 *)player, (f32)1e+04f), ((temp_r3_2 == 0U) == 0)) && (*(u32 *)((s8 *)((u8 *)&technique_contact_query_results.value + (*(s32 *)((s8 *)&technique_contact_query_results.value + 0x80) * 4)) + 0x40) = temp_r3_2, *(s32 *)((s8 *)&technique_contact_query_results.value + (*(s32 *)((s8 *)&technique_contact_query_results.value + 0x80) * 4)) = player, temp_r0 = *(s32 *)((s8 *)&technique_contact_query_results.value + 0x80) + 1, *(s32 *)((s8 *)&technique_contact_query_results.value + 0x80) = temp_r0, ((temp_r0 < 0x10) == 0))) {
        *(s32 *)((s8 *)&technique_contact_query_results.value + 0x80) = 0xF;
    } else {
        var_r29 += 1;
        if (var_r29 < 4) {
            goto loop_3;
        }
    }
    return &technique_contact_query_results.value;
}

s32 find_area_technique_contact(void *self, int target, void *_w2, void *arg3) {
    Vec_80236378 pos;
    f32 range;
    PD_80236378 *pd;
    s32 i;
    Contact_80236378 *c;
    if (get_current_floor_area() == AREA_DARK_FALZ) {
        range = 6.25e+04f;
    } else {
        range = 6.25e+04f;
    }
    VecCopy((Vec *)&pos, (const Vec *)((u8 *)self + 0x20));
    resetTechniqueContactQuery();
    if ((u32)target == 0) {
        return (s32)&technique_contact_query_results;
    }
    VecCopy((Vec *)((u8 *)target + 0x38), (const Vec *)&pos);
    for (i = TLobby::get_game_mode(); i < TLobby::get_lobby_flag(); i++) {
        pd = (PD_80236378 *)get_player_data__10TObjPlayerFi(i);
        if (pd != 0 && (pd->flags & 0x20000000) && get_entity_id(pd) != get_entity_id(arg3)) {
            c = (Contact_80236378 *)((TObjCollidable *)target)->find_actor_body_contact((u8 *)pd, range);
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
    return (s32)&technique_contact_query_results;
}

s32 TObjPlayer::collect_body_contacts(int target, void *_w2, void *player) {
    Vec_802364D8 pos;
    PD_802364D8 *e;
    PD_802364D8 *pd;
    s32 i;
    s32 n;
    s32 ok;
    Contact_802364D8 *c;
    s32 j;
    VecCopy((Vec *)&pos, (const Vec *)((u8 *)this + 0x20));
    resetTechniqueContactQuery();
    if ((u32)target == 0) {
        return (s32)&technique_contact_query_results;
    }
    VecCopy((Vec *)((u8 *)target + 0x38), (const Vec *)&pos);
    if (get_entity_id(player) < 4) {
        n = TLobby::get_lobby_flag();
        for (i = 0; i < n; i++) {
            pd = (PD_802364D8 *)get_player_data__10TObjPlayerFi(i);
            if (pd != 0 && get_entity_id(pd) != get_entity_id(player)) {
                ok = 1;
                if (get_entity_id(pd) < 4) {
                    if (((TObjPlayer *)player)->get_field_3e4() == ((TObjPlayer *)pd)->get_field_3e4()) {
                        ok = 1;
                    } else {
                        ok = 0;
                    }
                }
                if (ok != 0 && ((pd->flags & 0x20000000) || (pd->flags & 0x10000000))) {
                    c = (Contact_802364D8 *)((TObjCollidable *)target)->find_actor_body_contact((u8 *)pd, 1e+04f);
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
                c = (Contact_802364D8 *)((TObjCollidable *)target)->find_actor_body_contact((u8 *)e, 1e+04f);
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
    return (s32)&technique_contact_query_results;
}

void TUnk_804CC148::find_area_contact(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    find_area_technique_contact((void *)arg0, this->m_e8, (u8 *)&this->unk_BC, (void *)arg1);
}

void TObjPlayer::collect_body_contacts_for_target(s32 player) {
    collect_body_contacts((int)((int) (*(s32 *)&this->blend.motion[1])), (u8 *)&this->previous_action, (void *)player);
}

void TObjPlayer::find_support_technique_contact_for_target(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    find_support_technique_contact((void *)arg0, (int)this->motion_list, (u8 *)&this->motion_flags, (void *)arg1);
}

void TObjPlayer::gather_contacts_for_self(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    gather_player_contacts((u32)((int)this->motion_list), (s32)(arg0 + 0xb0), arg1);
}

u8 *TUnk_804CCC68::query_technique_enemy_contacts(s32 arg) {
    Vec_802367D8 pos;
    Vec_802367D8 d;
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
        pd = (PD_802367D8 *)get_player_data__10TObjPlayerFi(i);
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

u8 *TUnk_804CCC68::query_technique_player_contacts(s32 arg) {
    Vec_80236A20 pos;
    Vec_80236A20 d;
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
            pd = (PD_80236A20 *)get_player_data__10TObjPlayerFi(i);
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
