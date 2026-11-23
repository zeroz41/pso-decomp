#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/technique/TTecPlayerInfluence.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecRaBarta.h"

#include <stddef.h>

#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/player/PlayerSlots.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/TObjPlayer_801542CC.h"
struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(u32);
};

struct List_802370D8 { u32 items[32]; s32 count; };

struct Obj_802370D8 : VObj_18_1a504b {
    void *source;
};

struct Arr_80236EE8 { TParticleCtrl *w[3]; };

struct Tec_80236EE8 {
    u8 pad0[0x8A];
    s16 type;
    u8 pad8C[0xA4 - 0x8C];
    s16 level;
    u8 padA6[2];
    u16 slot;
    u8 padAA[2];
    s32 active;
};

extern "C" {

List_802370D8 *gather_contacts_for_self__10TObjPlayerFl(void *, u32);
void deliver_technique_to_party_targets(Obj_802370D8 *arg0);
void spawn_support_tec_range_effect(Tec_80236EE8 *self);
}

const char *TTecPlayerInfluence::class_name = "TTecPlayerInfluence";

// Built with -inline off,deferred: the functions are written from the last one
// in the object back to the first.

void TTecPlayerInfluence::apply_to_player(TObjPlayer *) {  }

TTecPlayerInfluence::TTecPlayerInfluence(void *owner, void *pos, s32 level) : TEffect() {
  m_name = class_name;
  sourceId = 0xFFFF;
  VecCopy(&position, (const Vec *)pos);
  if (level < 0)
  {
    this->level = 0;
  }
  else
    if (level >= 30)
  {
    this->level = 30;
  }
  else
  {
    this->level = level;
  }
  band = TObjPlayer::get_level_tier(this->level);
  speed = 3.0f;
  lifetime = 90.0f;
  scale.x = 1.0f;
  scale.y = 1.0f;
  scale.z = 1.0f;
  source = (uaddr)owner;
  color.a = 0.2f;
  color.r = 1.0f;
  color.g = 1.0f;
  color.b = 1.0f;
  pad_A0 = 0;
  collisionBody.offset.x = 0.0f;
  collisionBody.offset.y = 0.0f;
  collisionBody.offset.z = 0.0f;
  collisionBody.radius = 10.0f;
  collisionBody.half_width = 1.0f;
  collisionBody.shape = 0;
  collisionBody.flags = 0x40107;
  target = new TObjCollidable(this);
  if (target != NULL)
  {
    init_collision_body_parts(target, &collisionBody, 1);
  }
  show_effects = 1;
  if (source != 0 && ((TObjBase *)source)->get_entity_id() < 4 && (((TObjBase *)source)->actorFlags & 0x02000000))
  {
    show_effects = 0;
  }
}

TTecPlayerInfluence::~TTecPlayerInfluence() {
    if (target != NULL) { free_collision_body_parts(target); }
}


void TTecPlayerInfluence::run_task() {
    sub_80237258();
    this->tick_lifetime();
}

void TTecPlayerInfluence::sub_80237258() { collisionBody.radius = scale.x; }

void TTecPlayerInfluence::tick_lifetime() {
    age++;
    if ((f32)age > lifetime) {
        queue_destruction();
    }
}

void TTecPlayerInfluence::render() {
    Vec target = {50.0f, 50.0f, 50.0f};
    approach_vector_in_place(&scale, &target, 2.7f);
    debug_draw_sphere(&position, &color, scale.x);
}

void deliver_technique_to_party_targets(Obj_802370D8 *arg0) {
    List_802370D8 *list;
    s32 i;
    if (*(u32 *)((s8 *)arg0 + 0xDC) == 0) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    if (((TObjBase *)(arg0->source))->get_entity_id() < 4) {
        list = gather_contacts_for_self__10TObjPlayerFl(arg0, *(u32 *)((s8 *)arg0 + 0x1C));
    } else {
        list = (List_802370D8 *)((TTecPlayerInfluence *)arg0)->find_support_technique_contact_for_target(*(u32 *)((s8 *)arg0 + 0x1C));
    }
    for (i = 0; i < list->count; i++) {
        if (TObjPlayer::is_valid_and_active(list->items[i]) != 0) {
            arg0->m5(list->items[i]);
        }
    }
}

const s32 support_tec_range_effect_id_table[4] = {493, 505, 506, 507};
const Arr_80236EE8 lbl_8044D908 = {{NULL, NULL, NULL}};
void spawn_support_tec_range_effect(Tec_80236EE8 *self) {
    s16 kind;
    Vec pos;
    s32 i;
    u32 band;
    u8 *pl;
    s32 j;
    s32 k;
    if (self->active == 0) {
        return;
    }
    if (self->slot >= 4) {
        return;
    }
    pl = (u8 *)get_player_by_client_id(self->slot);
    if (pl == NULL) {
        return;
    }
    {
        VecCopy((Vec *)&pos, (const Vec *)(pl + 0x38));
        switch (self->type) {
        case 8:
            break;
        case 6:
            kind = 0xF;
            break;
        case 7:
            kind = 0x10;
            break;
        case 9:
            kind = 0xD;
            break;
        case 10:
            kind = 0xA;
            break;
        }
        band = TTecCtrl::classify_distance_band(kind, self->level, self->slot);
        {
            Arr_80236EE8 fx = lbl_8044D908;
            fx.w[0] = spawn_particle_effect(&pos, support_tec_range_effect_id_table[band]);
            if (band == 3) {
                fx.w[1] = spawn_particle_effect(&pos, 0x1F2);
                fx.w[2] = spawn_particle_effect(&pos, 0x19D);
            }
            switch ((s16)kind) {
            case 14:
                break;
            case 16:
                for (i = 0; i < 3; i++) {
                    if (fx.w[i] != NULL) {
                        fx.w[i]->set_tint_color(0xFF4DFF99);
                    }
                }
                break;
            case 13:
                for (j = 0; j < 3; j++) {
                    if (fx.w[j] != NULL) {
                        fx.w[j]->set_tint_color(-0x6667);
                    }
                }
                break;
            case 10:
                for (k = 0; k < 3; k++) {
                    if (fx.w[k] != NULL) {
                        fx.w[k]->set_tint_color(0xFF337FFF);
                    }
                }
                break;
            }
        }
    }
}

