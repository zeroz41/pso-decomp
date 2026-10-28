#pragma readonly_strings on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/item/TItemProArmorParticle.h"
#include "pso/TItemEffArmorParticle.h"
#include "pso/TParticleCtrl.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/item/TUnk_804A05C8.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_80087278.h"
extern "C" s32 is_item_area_enabled(s32 area);
#include "pso/TMainTask.h"

extern "C" {
// TItemTimerEvent has no real constructor yet (TItemTimerEvent.cpp).
void TItemTimerEvent__ct(void *event);
extern s32 lbl_804A05C8[];
}

const char *item_pro_armor_particle_class_name = "TItemProArmorParticle";

// The particle of the armors with item index 0x29..0x34; the first five
// play it from a timer event, the rest once in each area.
static const s32 armor_particle_ids[12] = {
    224, 50, 283, 381, 446, 34, 107, 176, 225, 262, 402, 444,
};

// The functions below run from the last one in the object back to the first
// (deferred code generation, see configure.py).

TItemProArmorParticle::~TItemProArmorParticle() {}

void *TUnk_804A05C8::initialize(TItemHeapObject *parent, u16 client, s32 duration, s32 particle) {
    TItemTimerEvent__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A05C8;
    *(s32 *)&this->unk_2C = particle;
    return this;
}

TItemProArmorParticle::TItemProArmorParticle(TObject *parent, u8 *item) : TItemProArmor(parent, item) {
    u8 index;
    m_name = item_pro_armor_particle_class_name;
    last_area = -1;
    index = get_item_index() - 0x29;
    if (index < 12) {
        particle_id = armor_particle_ids[index];
        if (index < 5) {
            particle_mode = ARMOR_PARTICLE_TIMER;
        } else {
            particle_mode = ARMOR_PARTICLE_PER_AREA;
        }
    } else {
        particle_id = 0;
        particle_mode = ARMOR_PARTICLE_NONE;
    }
}

void TItemProArmorParticle::on_equip() {
    TUnk_804A05C8 *event;
    TItemProArmor::on_equip();
    if ((particle_mode == ARMOR_PARTICLE_TIMER) && (effect_objects != NULL)) {
        event = (TUnk_804A05C8 *)TItemHeapObject::operator new(0x30);
        if (event != NULL) {
            event->initialize(effect_objects, get_owner_client(), 120, particle_id);
        }
    }
}

void TItemProArmorParticle::on_unequip() {
    if (particle_mode == ARMOR_PARTICLE_PER_AREA) {
        last_area = -1;
    }
    TItemEquipBase::on_unequip();
}

void TItemProArmorParticle::update_equipped() {
    s32 area;
    if (particle_mode == ARMOR_PARTICLE_PER_AREA) {
        area = get_current_floor_area();
        if (area != last_area) {
            last_area = area;
            if (is_item_area_enabled(area) != 0) {
                create_effect(tl_05, get_item_id(), get_owner_client(), particle_id);
            }
        }
    }
}

void TItemProArmorParticle::create_effect(TObject *parent, s32 item_id, u16 client, s32 particle) {
    if (parent != NULL) {
        new TItemEffArmorParticle(parent, item_id, client, particle);
    }
}

const char *item_eff_armor_particle_class_name = "TItemEffArmorParticle";

TItemEffArmorParticle::TItemEffArmorParticle(TObject *parent, s32 item_id, u16 client, s32 particle) : TObject(parent) {
    TObjPlayer *player;
    m_name = item_eff_armor_particle_class_name;
    disallow_rendering();
    this->item_id = item_id;
    this->client = client;
    item_generation = get_item_system_generation();
    player = get_player_by_client_id(client);
    if (player != NULL) {
        this->particle = (TParticleCtrl *)spawn_continuous_particle_effect_with_flags(player->get_center(), particle, 0x10);
        if (this->particle != NULL) {
            this->particle->set_owner_id(this->client);
        }
    } else {
        this->particle = NULL;
    }
}

TItemEffArmorParticle::~TItemEffArmorParticle() {
    if (particle != NULL) {
        particle->queue_destruction();
    }
}

void TItemEffArmorParticle::run_task() {
    s32 active;
    TObjPlayer *player;
    TItem *item;

    if (item_generation != (u32)get_item_system_generation()) {
        queue_destruction();
        return;
    }
    active = 0;
    if (particle != NULL) {
        player = get_player_by_client_id(client);
        item = find_item_by_id(item_id);
        if (player != NULL) {
            if (item != NULL) {
                if (item->get_mode() == 2) {
                    if (player->obj_testFlags30(0x800) == 0) {
                        if (item->is_hidden() == 0) {
                            particle->clear_active_flag();
                        } else {
                            goto enable_particle;
                        }
                    } else {
                    enable_particle:
                        particle->enable();
                    }
                    active = 1;
                    ((TNowLoading *)particle)->copy_pos(&player->m_2fc);
                }
            }
        }
    }
    if (active == 0) {
        queue_destruction();
    }
}
