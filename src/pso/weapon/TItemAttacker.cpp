#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/weapon/TItemAttacker.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/item/TItemTimer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/render/render_util.h"
#include "pso/player/PlayerSlots.h"
#include "pso/object/base/CollisionActorLookup.h"

#pragma readonly_strings on


const char *TItemAttacker__name = "TItemAttacker";


struct ItemBuffTempLabel {
    char value[0xA];
};

s32 item_buffer_temp_mode;
saddr item_buff_buffer;

void TItemAttacker::deliver_delayed_weapon_hit() {
    TObjChara *target;
    Vec *target_body;
    TObjPlayer *player;
    TItem *item;
    target = resolve_hittable_target(hit.target, hit.collider);
    if (target != NULL) {
        target_body = &target->bodies[hit.collider].center;
        if (horizontal_distance_squared(&target_pos, target_body) < 64.0f) {
            player = get_player_by_client_id(hit.source);
            item = find_item_by_id(hit.weapon);
            if ((player != NULL) && (item != NULL)) {
                ((TItemWeapon *)item)->deliver_hit(player, target, hit.kind, hit.damage, hit.collider);
            }
        } else {
            if (horizontal_distance_squared(target_body, &origin) < horizontal_distance_squared(&target_pos, &origin)) {
                ((TObjPlayer *)target)->show_miss_for_collider(hit.collider);
            }
        }
    }
    done = 1;
}

void spawn_item_attacker(TObject *parent, const Vec *position, s32 frames, DelayedWeaponHit *attack_record) {
    if ((parent != NULL) && (attack_record != NULL) && (position != NULL) && (attack_record->source != 0xFFFF) && (attack_record->target != 0xFFFF)) {
        TItemAttacker::spawn_item_timer(new TItemAttacker(parent, position, frames, attack_record), TItemAttacker__sub_8010349C, frames);
    }
}

TItemAttacker::TItemAttacker(TObject *parent, const Vec *position, s32 frames, DelayedWeaponHit *attack_record) : TObject(parent) {
    TObjCollidable *entity;
    m_name = TItemAttacker__name;
    this->hit.copy_from(attack_record);
    done = 0;
    VecCopy(&this->origin, position);
    entity = find_entity_by_id(this->hit.target);
    if (entity != NULL) {
        VecCopy(&target_pos, &entity->bodies[this->hit.collider].center);
    } else {
        done = 1;
    }
}

void DelayedWeaponHit::copy_from(DelayedWeaponHit *source_record) {
    reserved = source_record->reserved;
    kind = source_record->kind;
    weapon = source_record->weapon;
    source = source_record->source;
    target = source_record->target;
    collider = source_record->collider;
    damage = source_record->damage;
}

void TItemAttacker::spawn_item_timer(TObject *object, ItemTimerCallback expire, s32 frames) {
    if (object != NULL) {
        new TItemTimer(object, (saddr)expire, frames);
    }
}

void TItemAttacker__sub_8010349C(TObject *attacker) {
    if (attacker != NULL) {
        ((TItemAttacker *)attacker)->deliver_delayed_weapon_hit();
    }
}

TItemAttacker::~TItemAttacker() {}
void TItemAttacker::run_task() { if (done != 0) { queue_destruction(); } }

__declspec(section ".data") saddr item_nj_chunk_buffer_table[2];
saddr get_item_chunk_buffer(int a0) {  return item_nj_chunk_buffer_table[a0]; }

void TItemBuff__ct(void) {
    if ((u32) (*(u32 *)&item_buff_buffer) != 0) {
        if ((s32) item_buffer_temp_mode != 0) {
            TLobby::tmp_buf_release((const char *)(saddr) &(*(ItemBuffTempLabel *)(s32 *)"TItemBuff").value);
        } else {
            mem_free((void *)(*(uaddr *)&item_buff_buffer));
        }
        (*(u32 *)&item_buff_buffer) = 0;
    }
}
s32 create_item_buff(s32 size);
s32 create_item_buff(s32 size) {
    s32 temp_available;

    if (size != 0) {
        TItemBuff__ct();
        temp_available = TLobby::tmp_buf_is_free();
        item_buffer_temp_mode = temp_available;
        if ((temp_available != 0) && (size < 0x40000)) {
            item_buff_buffer = (saddr)TLobby::tmp_buf_use_req("TItemBuff");
        } else {
            item_buff_buffer = (saddr)mem_alloc(size);
        }
    }
    return item_buff_buffer;
}
