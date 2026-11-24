#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/TEffect.h"
#include "pso/object/TActorLight.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/unk/text_8023601C.h"
#include "pso/technique/TTecLuker.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/technique/TTecShot.h"
#include "pso/technique/TTecCircle.h"
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
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TObjPlayer_80011014.h"


static const f32 lbl_805DC888[1] = {1.0f};
static const f32 lbl_805DC88C[1] = {0.0f};


#pragma push
#pragma fp_contract on
void TActorLight::run_task() {
    Vec baseDir;
    NJS_ARGB baseColor;
    NJS_ARGB unused;
    f32 mid;
    f32 frac;
    if (get_player_by_client_id(actor) == 0) {
        queue_destruction();
        return;
    }
    TObjLight::find_light_params((f32 *)&baseDir, (f32 *)&baseColor, actor);
    mid = 0.5f * (f32) duration;
    if (age < (s32) mid) {
        f32 amb1;
        f32 inten1;
        frac = (f32) age / mid;
        amb1 = frac * (peak - scene_light_state.ambient) + scene_light_state.ambient;
        inten1 = frac * (intensity - scene_light_state.intensity) + scene_light_state.intensity;
        publish_actor_light_scalars((u16) source->get_entity_id(), inten1, amb1);
        copy_argb(&unused, &baseColor);
        approach_vector_fixed_distance(&direction, &desired, &direction, step);
        approach_rgb_clamped(&unused, &color, 0.1f);
    } else {
        f32 amb2;
        f32 inten2;
        frac = ((f32) age - mid) / mid;
        amb2 = frac * (scene_light_state.ambient - peak) + peak;
        inten2 = frac * (scene_light_state.intensity - intensity) + intensity;
        publish_actor_light_scalars((u16) source->get_entity_id(), inten2, amb2);
        approach_vector_fixed_distance(&direction, &baseDir, &direction, step);
        approach_rgb_clamped(&color, &baseColor, 0.1f);
    }
    publish_light_direction_color((u16) source->get_entity_id(), &direction, &color);
    age++;
    if (duration < age) {
        queue_destruction();
    }
}
#pragma pop

TActorLight::~TActorLight() {

}

TActorLight::TActorLight(f32 step, f32 peak, f32 intensity, NJS_ARGB *color, Vec *desired, s32 duration,
                             TObjBase *source, TObject *parent)
    : TObject(parent) {
    NJS_ARGB scene_color;
    copy_argb(&this->color, color);
    VecCopy(&this->desired, desired);
    this->duration = duration;
    age = 0;
    this->step = step;
    this->source = source;
    phase = 1;
    this->peak = peak;
    this->intensity = intensity;
    actor = this->source->get_entity_id();
    TObjLight::find_light_params((f32 *)&direction, (f32 *)&scene_color, actor);
}
TActorLight::TActorLight(f32 step, NJS_ARGB *color, Vec *desired, s32 duration, TObjBase *source, TObject *parent)
    : TObject(parent) {
    NJS_ARGB scene_color;
    copy_argb(&this->color, color);
    VecCopy(&this->desired, desired);
    this->duration = duration;
    age = 0;
    this->step = step;
    this->source = source;
    phase = 0;
    peak = lbl_805DC888[0];
    intensity = lbl_805DC888[0];
    actor = this->source->get_entity_id();
    TObjLight::find_light_params((f32 *)&direction, (f32 *)&scene_color, actor);
}

#pragma push
#pragma fp_contract on
void offset_point_toward_camera(Vec *center, Vec *out, f32 distance) {
    Vec dir;
    if (camera_ctrl_instance != NULL) {
        dir.x = camera_ctrl_instance->pos.x - center->x;
        dir.y = camera_ctrl_instance->pos.y - center->y;
        dir.z = camera_ctrl_instance->pos.z - center->z;
        if (lbl_805DC88C[0] != vec_squared_length(&dir)) {
            normalize_vector(&dir);
        }
        out->x = dir.x * distance + center->x;
        out->y = dir.y * distance + center->y;
        out->z = dir.z * distance + center->z;
    }
}
#pragma pop


s32 TTecLuker::is_parents_unqueued(uaddr object) {
    if (object == 0U) {
        return 0;
    }
    if (((TObject *)object)->all_parents_unqueued_for_destruction()) {
        return 1;
    }
    return 0;
}


extern "C" {

const f64 lbl_8044D8D0[1] = {0.5};

s32 TObjPlayer::is_valid_and_active(uaddr actor) {
    if (actor == 0U) {
        return 0;
    }
    if (obj_is_hit_receivable(reinterpret_cast<const TObjCollidable *>(actor))) {
        return 1;
    }
    return 0;
}
}
TechniqueContactList technique_contact_query_results;

void resetTechniqueContactQuery();

TechniqueContactList *find_support_technique_contact(TTecPlayerInfluence *self, TObjCollidable *target, CollisionBody *body, void *player);
saddr find_area_technique_contact(TTecCircle *self, TObjCollidable *target, CollisionBody *body, void *player);

TechniqueContactList *find_support_technique_contact(TTecPlayerInfluence *self, TObjCollidable *target, CollisionBody *body, void *player) {
    Vec pos;
    f32 range;
    s32 i;
    TObjPlayer *pd;
    CollisionBody *c;
    if (get_current_floor_area() == AREA_DARK_FALZ) {
        range = 6.25e+04f;
    } else {
        range = 1e+04f;
    }
    VecCopy(&pos, &self->position);
    resetTechniqueContactQuery();
    if (target == NULL) {
        return &technique_contact_query_results;
    }
    VecCopy(&target->position, &pos);
    for (i = TLobby::get_game_mode(); i < TLobby::get_lobby_flag(); i++) {
        pd = TObjPlayer::get_player_data(i);
        if (pd != 0 && (pd->actorFlags & 0x20000000)) {
            c = (CollisionBody *)target->find_actor_body_contact(pd, range);
            if (c != 0 && ((c->flags & 1) || !(c->flags & 0x02000000))) {
                technique_contact_query_results.bodies[technique_contact_query_results.count] = c;
                technique_contact_query_results.actors[technique_contact_query_results.count] = pd;
                if (++technique_contact_query_results.count >= 16) {
                    technique_contact_query_results.count = 15;
                    break;
                }
            }
        }
    }
    return &technique_contact_query_results;
}

TechniqueContactList *TTecPlayerInfluence::gather_player_contacts(TObjCollidable *target, CollisionBody *body, void *player) {
    Vec pos;
    TObjPlayer *pl;
    s32 i;
    CollisionBody *c;
    VecCopy(&pos, &position);
    resetTechniqueContactQuery();
    if (target == NULL) {
        return &technique_contact_query_results;
    }
    VecCopy(&target->position, &pos);
    for (i = 0; i < 4; i++) {
        pl = get_player_by_client_id(i);
        if (pl != NULL) {
            c = (CollisionBody *)target->find_actor_body_contact(pl, 1e+04f);
            if (c != NULL) {
                technique_contact_query_results.bodies[technique_contact_query_results.count] = c;
                technique_contact_query_results.actors[technique_contact_query_results.count] = pl;
                if (++technique_contact_query_results.count >= 16) {
                    technique_contact_query_results.count = 15;
                    break;
                }
            }
        }
    }
    return &technique_contact_query_results;
}

saddr find_area_technique_contact(TTecCircle *self, TObjCollidable *target, CollisionBody *body, void *player) {
    Vec pos;
    f32 range;
    TObjPlayer *pd;
    s32 i;
    CollisionBody *c;
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
        pd = TObjPlayer::get_player_data(i);
        if (pd != 0 && (pd->actorFlags & 0x20000000) && pd->get_entity_id() != ((TObjBase *)player)->get_entity_id()) {
            c = (CollisionBody *)target->find_actor_body_contact(pd, range);
            if (c != 0 && ((c->flags & 1) || !(c->flags & 0x02000000))) {
                technique_contact_query_results.bodies[technique_contact_query_results.count] = c;
                technique_contact_query_results.actors[technique_contact_query_results.count] = pd;
                if (++technique_contact_query_results.count >= 16) {
                    technique_contact_query_results.count = 15;
                    break;
                }
            }
        }
    }
    return (saddr)&technique_contact_query_results;
}

saddr TTecCircle::collect_body_contacts(TObjCollidable *target, CollisionBody *body, void *player) {
    Vec pos;
    TObjCollidable *e;
    TObjPlayer *pd;
    s32 i;
    s32 n;
    s32 ok;
    CollisionBody *c;
    s32 j;
    VecCopy(&pos, &position);
    resetTechniqueContactQuery();
    if (target == NULL) {
        return (saddr)&technique_contact_query_results;
    }
    VecCopy(&target->position, &pos);
    if (((TObjBase *)player)->get_entity_id() < 4) {
        n = TLobby::get_lobby_flag();
        for (i = 0; i < n; i++) {
            pd = TObjPlayer::get_player_data(i);
            if (pd != 0 && pd->get_entity_id() != ((TObjBase *)player)->get_entity_id()) {
                ok = 1;
                if (pd->get_entity_id() < 4) {
                    if (((TObjPlayer *)player)->get_floor() == pd->get_floor()) {
                        ok = 1;
                    } else {
                        ok = 0;
                    }
                }
                if (ok != 0 && ((pd->actorFlags & 0x20000000) || (pd->actorFlags & 0x10000000))) {
                    c = (CollisionBody *)target->find_actor_body_contact(pd, 1e+04f);
                    if (c != 0 && ((c->flags & 1) || !(c->flags & 0x02000000))) {
                        technique_contact_query_results.bodies[technique_contact_query_results.count] = c;
                        technique_contact_query_results.actors[technique_contact_query_results.count] = pd;
                        if (++technique_contact_query_results.count >= 16) {
                            technique_contact_query_results.count = 15;
                            break;
                        }
                    }
                }
            }
        }
    } else {
        for (j = 0; j < 4; j++) {
            e = find_entity_by_id(j);
            if (e != 0 && e->get_entity_id() != ((TObjBase *)player)->get_entity_id() && (e->actorFlags & 0x10000000)) {
                c = (CollisionBody *)target->find_actor_body_contact((TObjCollidable *)e, 1e+04f);
                if (c != 0) {
                    technique_contact_query_results.bodies[technique_contact_query_results.count] = c;
                    technique_contact_query_results.actors[technique_contact_query_results.count] = e;
                    if (++technique_contact_query_results.count >= 16) {
                        technique_contact_query_results.count = 15;
                        break;
                    }
                }
            }
        }
    }
    return (saddr)&technique_contact_query_results;
}

void TTecCircle::find_area_contact(saddr player) {
    find_area_technique_contact(this, collidable, &collisionBody, (void *)player);
}

saddr TTecCircle::collect_body_contacts_for_target(saddr player) {
    return collect_body_contacts(collidable, &collisionBody, (void *)player);
}

TechniqueContactList *TTecPlayerInfluence::find_support_technique_contact_for_target(saddr player) {
    return find_support_technique_contact(this, target, &collisionBody, (void *)player);
}

TechniqueContactList *TTecPlayerInfluence::gather_contacts_for_self(saddr player) {
    return gather_player_contacts(target, &collisionBody, (void *)player);
}

u8 *TTecShot::query_technique_enemy_contacts(saddr source) {
    Vec pos;
    Vec d;
    f32 range;
    Vec *prev;
    TObjPlayer *pd;
    s32 i;
    CollisionBody *c;
    if (get_current_floor_area() == AREA_DARK_FALZ) {
        range = 6.25e+04f;
    } else {
        range = 1e+04f;
    }
    VecCopy(&pos, &position);
    resetTechniqueContactQuery();
    if (collidable == 0) {
        return (u8 *)&technique_contact_query_results;
    }
    prev = get_pos_ptr();
    d.x = pos.x - prev->x;
    d.y = pos.y - prev->y;
    d.z = pos.z - prev->z;
    {
        f32 len = vector_length(&d);
        collidable->bodies->half_width = halfWidth;
        collidable->bodies->radius = 0.5f * len;
    }
    pos.x = 0.5f * (pos.x + prev->x);
    pos.y = 0.5f * (pos.y + prev->y);
    pos.z = 0.5f * (pos.z + prev->z);
    VecCopy(&collidable->position, &pos);
    copy_xyz(&collidable->rotation_x, angles);
    for (i = TLobby::get_game_mode(); i < TLobby::get_lobby_flag(); i++) {
        pd = TObjPlayer::get_player_data(i);
        if (pd == 0) continue;
        if (pd->actorFlags & 0x20000000) {
            if (pd->get_entity_id() == ((TObjBase *)source)->get_entity_id()) continue;
            c = (CollisionBody *)collidable->find_actor_body_contact(pd, (f32)range);
            if (c != 0 && ((c->flags & 1) || !(c->flags & 0x02000000))) {
                technique_contact_query_results.bodies[technique_contact_query_results.count] = c;
                technique_contact_query_results.actors[technique_contact_query_results.count] = pd;
                if (++technique_contact_query_results.count >= 16) {
                    technique_contact_query_results.count = 15;
                    break;
                }
            }
        } else if ((pd->actorFlags & 0x40000000) && !(pd->actorFlags & 0x80000000)) {
            if (collidable->find_actor_body_contact(pd, (f32)1e+04f) != 0) {
                return 0;
            }
        }
    }
    return (u8 *)&technique_contact_query_results;
}

u8 *TTecShot::query_technique_player_contacts(saddr source) {
    Vec pos;
    Vec d;
    f32 range;
    Vec *prev;
    TObjCollidable *e;
    TObjPlayer *pd;
    s32 i;
    s32 n;
    CollisionBody *c;
    s32 j;
    if (get_current_floor_area() == AREA_DARK_FALZ) {
        range = 6.25e+04f;
    } else {
        range = 1e+04f;
    }
    VecCopy(&pos, &position);
    resetTechniqueContactQuery();
    if (collidable == 0) {
        return (u8 *)&technique_contact_query_results;
    }
    prev = get_pos_ptr();
    d.x = pos.x - prev->x;
    d.y = pos.y - prev->y;
    d.z = pos.z - prev->z;
    {
        f32 len = vector_length(&d);
        collidable->bodies->half_width = halfWidth;
        collidable->bodies->radius = lbl_8044D8D0[0] * len;
    }
    pos.x = 0.5f * (pos.x + prev->x);
    pos.y = 0.5f * (pos.y + prev->y);
    pos.z = 0.5f * (pos.z + prev->z);
    VecCopy(&collidable->position, &pos);
    copy_xyz(&collidable->rotation_x, angles);
    if (((TObjBase *)source)->get_entity_id() < 4) {
        n = TLobby::get_lobby_flag();
        for (i = 0; i < n; i++) {
            pd = TObjPlayer::get_player_data(i);
            if (pd == 0) continue;
            if (pd->get_entity_id() == ((TObjBase *)source)->get_entity_id()) continue;
            c = (CollisionBody *)collidable->find_actor_body_contact(pd, (f32)range);
            if (c != 0 && ((pd->actorFlags & 0x20000000) || (pd->actorFlags & 0x10000000)) && ((c->flags & 1) || !(c->flags & 0x02000000))) {
                technique_contact_query_results.bodies[technique_contact_query_results.count] = c;
                technique_contact_query_results.actors[technique_contact_query_results.count] = pd;
                if (++technique_contact_query_results.count >= 16) {
                    technique_contact_query_results.count = 15;
                    break;
                }
            }
        }
    } else {
        for (j = 0; j < 4; j++) {
            e = find_entity_by_id(j);
            if (e == 0) continue;
            if (e->get_entity_id() == ((TObjBase *)source)->get_entity_id()) continue;
            c = (CollisionBody *)collidable->find_actor_body_contact((TObjCollidable *)e, (f32)1e+04f);
            if (c != 0 && (e->actorFlags & 0x10000000)) {
                technique_contact_query_results.bodies[technique_contact_query_results.count] = c;
                technique_contact_query_results.actors[technique_contact_query_results.count] = e;
                if (++technique_contact_query_results.count >= 16) {
                    technique_contact_query_results.count = 15;
                    break;
                }
            }
        }
    }
    return (u8 *)&technique_contact_query_results;
}

void resetTechniqueContactQuery() {
    for (s32 i = 0; i < 16; ++i) {
        technique_contact_query_results.actors[i] = 0;
        technique_contact_query_results.bodies[i] = 0;
    }
    technique_contact_query_results.count = 0;
}

Vec *TTecShot::get_pos_ptr() { return &previous; }
