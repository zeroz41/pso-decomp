#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/item/TItemEffShield.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemData.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/map/FloorArea.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/scene/TScene.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "types.h"

const char *TItemEffShield::class_name = "TItemEffShield";
// Per shield item index (0x53 on, every 8 indices): whether its particle is a
// one-shot effect, and the particle.
const s32 shield_particle_oneshot[8] = { 1, 1, 1, 0, 1, 0, 0, 0 };
const s32 shield_particle_ids[8] = { -1, 446, 447, 145, 32, 416, 417, 177 };

// Built with -inline off,deferred: the functions are written from the last one in the
// object back to the first.

TItemEffShield::~TItemEffShield() {}

void TItemProShield::create_shield_effect(TObject *parent, u16 client, ShieldEffectEntry *entry) {
    if (parent != NULL && client != 0xFFFF && entry != NULL) {
        new TItemEffShield(parent, client, entry);
    }
}

TItemEffShield::TItemEffShield(TObject *parent, u16 client_id, ShieldEffectEntry *entry) : TObject(parent) {
    m_name = class_name;
    this->entry = entry;
    this->client_id = client_id;
    timer = 0;
    burst = 0;
    node = 0x24;
    disallow_rendering();
}

void TItemEffShield::run_task() {
    TObjPlayer *player = get_player_by_client_id(client_id);
    ShieldEffectEntry *entry;
    if (player != NULL) {
        player->get_anim_node_position(node, &position);
        copy_xyz(&rotation_x, &player->rotation_x);
    }
    if (player != NULL && burst != (entry = this->entry)->burst_count) {
        switch (burst) {
        case 0:
            if (timer - 1 == entry->first_delay) {
                play_sound_effect(0x4001A81E, &position, 0, 0);
                spawn_recipe_particles();
                burst++;
                timer = 0;
            } else {
                timer++;
            }
            break;
        default:
            if (timer == entry->interval) {
                spawn_recipe_particles();
                burst++;
                timer = 0;
            } else {
                timer++;
            }
            break;
        }
    } else {
        queue_destruction();
    }
}

void TItemEffShield::spawn_recipe_particles() {
    s32 i;
    for (i = 0; i != 8; i++) {
        s32 id = entry->particle_ids[i];
        if (id != -1) {
            create_oneshot_particle_emitter(&position, &rotation_x, id, 4);
        }
    }
}

TItemEffShieldAura::TItemEffShieldAura(TObject *parent, u16 client_id) : TObject(parent) {
    this->client_id = client_id;
    floor = -1;
    particle = NULL;
    item_generation = get_item_system_generation();
}

TItemEffShieldAura::~TItemEffShieldAura() {
    if (particle != NULL) {
        particle->queue_destruction();
        particle = NULL;
    }
}

void TItemEffShieldAura::run_task() {
    Vec position;
    s32 current_floor;
    TItem *item;
    TObjPlayer *player;

    if (item_generation != get_item_system_generation()) {
        queue_destruction();
        return;
    }
    player = get_player_by_client_id(client_id);
    if (player != NULL) {
        player->get_anim_node_position(0x24, &position);
        current_floor = get_current_floor();
        if (current_floor != floor) {
            floor = current_floor;
            if (is_current_area_item_enabled() != 0 && current_floor == player->get_floor()) {
                particle = create_particle_emitter(&position, 0x101);
            } else {
                particle = NULL;
            }
        }
        item = TObjPlayer::get_equipped_weapon(player);
        if (particle != NULL) {
            s32 hidden = 0;
            if (item != NULL && item->get_item_group() == 0x1A) {
                hidden = 1;
            }
            if (hidden != 0) {
                particle->clear_active_flag();
            } else {
                particle->enable();
            }
            particle->set_position(&position);
        }
    } else {
        queue_destruction();
    }
}

TItemEffShieldPulse::TItemEffShieldPulse(TObject *parent, u16 client_id, u8 item_index) : TObject(parent) {
    timer = 0;
    particle_id = shield_particle_ids[(item_index - 0x53) % 8];
    oneshot = shield_particle_oneshot[(item_index - 0x53) % 8];
    this->client_id = client_id;
    this->item_index = item_index;
    item_generation = get_item_system_generation();
}

TItemEffShieldPulse::~TItemEffShieldPulse() {}

void TItemEffShieldPulse::run_task() {
    TItemData item;
    TObjPlayer *player;

    if (item_generation != get_item_system_generation()) {
        queue_destruction();
        return;
    }
    if (120.0f == (f32)timer) {
        item.init();
        item.data1.data_u8[0] = 1;
        item.data1.data_u8[1] = 2;
        item.data1.data_u8[2] = item_index;
        if ((s16)TObjPlayer::count_nearby_players_with_shield(client_id, (u8 *)&item) > 0 && particle_id != -1) {
            player = get_player_by_client_id(client_id);
            if (player != NULL) {
                if (is_item_area_enabled(player->get_area()) == 1) {
                    if (oneshot == 0) {
                        create_timed_particle_emitter(&player->body_center, particle_id, 0, 0xA);
                    } else {
                        spawn_particle_effect(&player->body_center, particle_id);
                    }
                }
            }
        }
        timer = 0;
    }
    timer++;
}

NJS_OBJECT *TItem::get_item_model() { return item_model; }
NJS_TEXLIST *TObjBase::get_texlist() { return texlist; }
