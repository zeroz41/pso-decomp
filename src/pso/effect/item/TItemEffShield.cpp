#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/player/TUnk_8049F130.h"
#include "pso/item/TUnk_8049F148.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TBoss4Type2_80086C44.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/effect/item/TItemEffShield.h"
#include "pso/system/vector.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/PlayerSlots.h"

struct Obj_8010A1D0 {
    u8 pad0[0x18];
    void *vt;
    s32 f_1C;
    s32 f_20;
    s32 f_24;
    s16 f_28;
    u8 f_2A;
    u8 pad2B;
    u32 f_2C;
};

struct Recipe_8010A4C0 { u8 pad0[0x20]; s32 m_20; s32 m_24; s32 m_28; };

struct Shield_8010A4C0 {
    u8 pad0[0x1C];
    u8 m_1c[0xC];
    u8 m_28[0xC];
    Recipe_8010A4C0 *m_34;
    s32 m_38;
    s32 m_3c;
    s32 m_40;
    u16 m_44;
};


const char *TItemEffShield__class_name = "TItemEffShield";
int get_item_system_generation(void);
const s32 lbl_8043E280[8] = { 1, 1, 1, 0, 1, 0, 0, 0 };
const s32 lbl_8043E2A0[8] = { -1, 446, 447, 145, 32, 416, 417, 177 };
extern "C" {
s32 is_item_area_enabled(s32 area);

void run_task__14TItemEffShieldFv(Shield_8010A4C0 *self);
}

// Built with -inline off,deferred: the functions are written from the last one in the
// object (0x8010A050-0x8010A710) back to the first.

TItemEffShield::~TItemEffShield() {}

extern "C" {

s32 __ct__14TItemEffShieldFP7TObjectsl(u32, s32, u16, u32);

void TItemProShield::create_shield_effect(s32 arg0, u16 arg1, u32 effect_entry) {
    uaddr obj;
    if ((arg0 != 0) && ((u16) arg1 != 0xFFFF) && (effect_entry != 0U) && ((obj = (uaddr)TObject::operator new(0x48)) != 0U)) {
        __ct__14TItemEffShieldFP7TObjectsl(obj, arg0, arg1, effect_entry);
    }
}

}

TItemEffShield::TItemEffShield(TObject *parent, s16 arg2, s32 arg3) : TObject(parent) {
    *(saddr *)((s8 *)this + 0) = (saddr) TItemEffShield__class_name;
    *(s32 *)((s8 *)this + 0x34) = arg3;
    *(s16 *)((s8 *)this + 0x44) = arg2;
    *(s32 *)((s8 *)this + 0x38) = 0;
    *(s32 *)((s8 *)this + 0x3C) = 0;
    *(s32 *)((s8 *)this + 0x40) = 0x24;
    ((TObject *)this)->disallow_rendering();
}

void run_task__14TItemEffShieldFv(Shield_8010A4C0 *self) {
    TObjPlayer *p = (TObjPlayer *)get_player_by_client_id(self->m_44);
    Recipe_8010A4C0 *r;
    if (p != NULL) {
        p->get_anim_node_position(self->m_40, (Vec *)self->m_1c);
        copy_xyz(self->m_28, (u8 *)p + 0x5C);
    }
    if (p != NULL && self->m_3c != (r = self->m_34)->m_28) {
        switch (self->m_3c) {
        case 0:
            if (self->m_38 - 1 == r->m_20) {
                play_sound_effect(0x4001A81E, self->m_1c, 0, 0);
                ((TItemEffShield *)self)->spawn_recipe_particles();
                self->m_3c++;
                self->m_38 = 0;
            } else {
                self->m_38++;
            }
            break;
        default:
            if (self->m_38 == r->m_24) {
                ((TItemEffShield *)self)->spawn_recipe_particles();
                self->m_3c++;
                self->m_38 = 0;
            } else {
                self->m_38++;
            }
            break;
        }
    } else {
        ((TObject *)self)->queue_destruction();
    }
}

void TItemEffShield::spawn_recipe_particles() {
    u8 *arg0 = (u8 *)this;
  s32 id;
  s32 var_r31;
  s32 var_r30;
  var_r30 = 0;
  var_r31 = 0;
  if (id)
  {
  }
  do
  {
    id = *((s32 *) (((s8 *) (*((Recipe_8010A4C0 **) (((s8 *) arg0) + 0x34)))) + var_r31));
    if (id != (-1))
    {
      create_oneshot_particle_emitter((arg0 + 0x1C), (arg0 + 0x28), id, 4);
    }
    var_r30 += 1;
    var_r31 += 4;
  }
  while (var_r30 != 8);
}

TUnk_8049F148::TUnk_8049F148(TObject *parent, s16 arg2) : TObject(parent) {
    client_id = arg2;
    m_20 = -1;
    particle = NULL;
    m_28 = get_item_system_generation();
}

TUnk_8049F148::~TUnk_8049F148() {
    if (particle != NULL) {
        particle->queue_destruction();
        particle = NULL;
    }
}

void TUnk_8049F148::run_task() {
    s32 sp8[6];
    s32 temp_r3_2;
    TItem *item;
    TObjPlayer *player;

    if ((u32) this->m_28 != get_item_system_generation()) {
        queue_destruction();
        return;
    }
    player = (TObjPlayer *)get_player_by_client_id(this->client_id);
    if (player != NULL) {
        player->get_anim_node_position(0x24, (Vec *)sp8);
        temp_r3_2 = get_current_floor();
        if (temp_r3_2 != (s32) this->m_20) {
            this->m_20 = temp_r3_2;
            if ((is_current_area_item_enabled() != 0) && (temp_r3_2 == player->get_floor())) {
                this->particle = create_particle_emitter(sp8, 0x101);
            } else {
                this->particle = NULL;
            }
        }
        item = TObjPlayer::get_item_field_6(player);
        if (this->particle != NULL) {
            s32 var_r30 = 0;
            if ((item != NULL) && (item->get_item_group() == 0x1A)) {
                var_r30 = 1;
            }
            if (var_r30 != 0) {
                this->particle->clear_active_flag();
            } else {
                this->particle->enable();
            }
            this->particle->set_position(sp8);
        }
    } else {
        queue_destruction();
    }
}

TUnk_8049F130::TUnk_8049F130(TObject *parent, s16 a, u8 b) : TObject(parent) {
    ((Obj_8010A1D0 *)this)->f_1C = 0;
    ((Obj_8010A1D0 *)this)->f_20 = lbl_8043E2A0[(b - 0x53) % 8];
    ((Obj_8010A1D0 *)this)->f_24 = lbl_8043E280[(b - 0x53) % 8];
    ((Obj_8010A1D0 *)this)->f_28 = a;
    ((Obj_8010A1D0 *)this)->f_2A = b;
    ((Obj_8010A1D0 *)this)->f_2C = get_item_system_generation();
}

TUnk_8049F130::~TUnk_8049F130() {

}

struct TItemData8_8010a060 { s8 a; s8 b; u8 c; s8 pad[21]; };


void TUnk_8049F130::run_task() {
    struct TItemData8_8010a060 sp8;
    saddr player;

    if ((u32) this->m_2c != get_item_system_generation()) {
        queue_destruction();
        return;
    }
    if (120.0f == (f32) *(s32 *)&this->unk_1C) {
        ((TItemData *)(&sp8.a))->init();
        sp8.a = 1;
        sp8.b = 2;
        sp8.c = *(u8 *)((s8 *)this + 0x2A);
        if ((((s16)TObjPlayer::count_nearby_players_with_shield(this->m_28, (u8 *)&sp8.a)) > 0) && ((s32) this->m_20 != -1)) {
            player = (saddr)get_player_by_client_id(this->m_28);
            if (player != 0) {
                if (is_item_area_enabled(((TObjPlayer *)player)->get_area()) == 1) {
                    if ((s32) *(s32 *)&this->unk_24 == 0) {
                        create_timed_particle_emitter((void *)(player + 0x2FC), this->m_20, 0, 0xA);
                    } else {
                        spawn_particle_effect((const Vec *)(player + 0x2FC), this->m_20);
                    }
                }
            }
        }
        *(s32 *)&this->unk_1C = 0;
    }
    *(s32 *)&this->unk_1C = (s32) (*(s32 *)&this->unk_1C + 1);
}

NJS_OBJECT *TItem::get_item_model() { return item_model; }
saddr TObjBase::get_texlist() { return texlist; }
