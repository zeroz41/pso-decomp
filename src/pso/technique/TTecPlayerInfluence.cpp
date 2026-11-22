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
struct Owner_80237310
{
  u8 pad[0x30];
  u32 flags;
};

struct Obj_80237310
{
  s32 f0;
  u8 pad4[0x14];
  void *vt;
  Owner_80237310 *owner;
  f32 pos[3];
  f32 f2c;
  f32 f30;
  f32 f34;
  f32 f38;
  f32 f3c;
  f32 f40;
  f32 f44;
  u8 pad48[0x64 - 0x48];
  f32 f64;
  u8 pad68[0x70 - 0x68];
  f32 f70;
  u8 pad74[0xA0 - 0x74];
  s32 fa0;
  s16 level;
  s16 tier;
  u16 fa8;
  u8 padaa[2];
  s32 fac;
  f32 fb0[3];
  f32 fbc;
  f32 fc0;
  s32 fc4;
  s32 fc8;
  u8 padcc[0xDC - 0xCC];
  void *fdc;
};

typedef struct Emitter_80237494
{
  u32 entry;
  u32 flags;
  f32 scale;
} Emitter_80237494;

typedef struct Profile_80237494
{
  Emitter_80237494 *emitters;
  u32 count;
} Profile_80237494;

typedef struct Rabarta_80237494
{
  u8 pad0[0x1C];
  u8 *source;
  u8 pad20[0x7A - 0x20];
  s16 band;
  u8 pad7c[0xF4 - 0x7C];
  void **emitters;
} Rabarta_80237494;

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
u16 get_entity_id(void *);
void init_collision_body_parts(void *, f32 *, s32);
void *__ct__14TObjCollidableFP7TObject(void *, void *);
const char *lbl_805D37F0 = "TTecPlayerInfluence";
void free_collision_body_parts(void *);

List_802370D8 *find_support_technique_contact_for_target__10TObjPlayerFl(void *, u32);
List_802370D8 *gather_contacts_for_self__10TObjPlayerFl(void *, u32);
void *get_player_by_client_id(s32 i);
void deliver_technique_to_party_targets(Obj_802370D8 *arg0);
void spawn_support_tec_range_effect(Tec_80236EE8 *self);
}

// Built with -inline off,deferred: the functions are written from the last one
// in the object back to the first.

void TTecPlayerInfluence::vfunc_7(void *) {  }

#define self ((Obj_80237310 *)this)
TTecPlayerInfluence::TTecPlayerInfluence(void *owner_arg, void *pos, s32 level) : TEffect() {
  Owner_80237310 *owner = (Owner_80237310 *)owner_arg;
  void *p;
  self->f0 = (saddr)lbl_805D37F0;
  self->fa8 = 0xFFFF;
  VecCopy((Vec *)self->pos, (const Vec *)pos);
  if (level < 0)
  {
    self->level = 0;
  }
  else
    if (level >= 30)
  {
    self->level = 30;
  }
  else
  {
    self->level = level;
  }
  self->tier = TObjPlayer::get_level_tier(self->level);
  self->f64 = (3.0f);
  self->f70 = (9e+01f);
  self->f3c = (1.0f);
  self->f40 = (1.0f);
  self->f44 = (1.0f);
  self->owner = owner;
  self->f2c = (0.2f);
  self->f30 = (1.0f);
  self->f34 = (1.0f);
  self->f38 = (1.0f);
  self->fa0 = 0;
  self->fb0[0] = (0.0f);
  self->fb0[1] = (0.0f);
  self->fb0[2] = (0.0f);
  self->fbc = 10.0f;
  self->fc0 = (1.0f);
  self->fc4 = 0;
  self->fc8 = 0x40107;
  p = TObject::operator new(0xAC);
  if (p != 0)
  {
    p = __ct__14TObjCollidableFP7TObject(p, self);
  }
  self->fdc = p;
  if (self->fdc != 0)
  {
    init_collision_body_parts(self->fdc, self->fb0, 1);
  }
  self->fac = 1;
  if (((self->owner != 0) && (get_entity_id(self->owner) < 4)) && (self->owner->flags & 0x02000000))
  {
    self->fac = 0;
  }
}
#undef self

TTecPlayerInfluence::~TTecPlayerInfluence() {
    if (*(void **)((s8 *)this + 0xDC) != NULL) { free_collision_body_parts(*(void **)((s8 *)this + 0xDC)); }
}


void TTecPlayerInfluence::run_task() {
    sub_80237258();
    this->tick_lifetime();
}

void TTecPlayerInfluence::sub_80237258() { this->m_bc = *(f32*)((char*)this + 0x3c); }

void TTecPlayerInfluence::tick_lifetime() {
    u8 *arg0 = (u8 *)this;
    this->age = (this->age + 1);
    if ((f32) this->age > *(f32 *)&this->unk_70) {
        ((TObject *)arg0)->queue_destruction();
    }
}

void TTecPlayerInfluence::render() {
    u8 *arg0 = (u8 *)this;
    Vec target = {50.0f, 50.0f, 50.0f};
    approach_vector_in_place(&scale, &target, 2.7f);
    debug_draw_sphere((const Vec *)(arg0 + 0x20), (const NJS_ARGB *)&this->color, *(f32 *)(arg0 + 0x3C));
}

void deliver_technique_to_party_targets(Obj_802370D8 *arg0) {
    List_802370D8 *list;
    s32 i;
    if (*(u32 *)((s8 *)arg0 + 0xDC) == 0) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    if (get_entity_id(*(void **)((s8 *)arg0 + 0x1C)) < 4) {
        list = gather_contacts_for_self__10TObjPlayerFl(arg0, *(u32 *)((s8 *)arg0 + 0x1C));
    } else {
        list = find_support_technique_contact_for_target__10TObjPlayerFl(arg0, *(u32 *)((s8 *)arg0 + 0x1C));
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

