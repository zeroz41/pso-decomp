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


struct RecoveredGlobal_8010355C_lbl_8043E038 { char value[0xA]; };

s32 item_buffer_temp_mode;
saddr item_buff_buffer;

void TItemAttacker::deliver_delayed_weapon_hit() {
    TObjChara *target;
    Vec *body;
    TObjPlayer *player;
    TItem *item;
    target = resolve_hittable_target(hit.target, hit.collider);
    if (target != NULL) {
        body = &target->bodies[hit.collider].center;
        if (horizontal_distance_squared(&target_pos, body) < 64.0f) {
            player = get_player_by_client_id(hit.source);
            item = find_item_by_id(hit.weapon);
            if ((player != NULL) && (item != NULL)) {
                ((TItemWeapon *)item)->deliver_hit(player, target, hit.kind, hit.damage, hit.collider);
            }
        } else {
            if (horizontal_distance_squared(body, &origin) < horizontal_distance_squared(&target_pos, &origin)) {
                ((TObjPlayer *)target)->show_miss_for_collider(hit.collider);
            }
        }
    }
    done = 1;
}

void spawn_item_attacker(TObject *parent, const Vec *origin, s32 frames, Unk_8010340C *hit) {
    if ((parent != NULL) && (hit != NULL) && (origin != NULL) && (hit->source != 0xFFFF) && (hit->target != 0xFFFF)) {
        TItemAttacker::spawn_item_timer(new TItemAttacker(parent, origin, frames, hit), TItemAttacker__sub_8010349C, frames);
    }
}

TItemAttacker::TItemAttacker(TObject *parent, const Vec *origin, s32 frames, Unk_8010340C *hit) : TObject(parent) {
    TObjCollidable *entity;
    m_name = TItemAttacker__name;
    this->hit.copy_from(hit);
    done = 0;
    VecCopy(&this->origin, origin);
    entity = find_entity_by_id(this->hit.target);
    if (entity != NULL) {
        VecCopy(&target_pos, &entity->bodies[this->hit.collider].center);
    } else {
        done = 1;
    }
}

void Unk_8010340C::copy_from(Unk_8010340C *src) {
    reserved = src->reserved;
    kind = src->kind;
    weapon = src->weapon;
    source = src->source;
    target = src->target;
    collider = src->collider;
    damage = src->damage;
}

void TItemAttacker::spawn_item_timer(TObject *object, ItemTimerCallback expire, s32 frames) {
    if (object != NULL) {
        new TItemTimer(object, (saddr)expire, frames);
    }
}

void TItemAttacker__sub_8010349C(TObject *object) {
    if (object != NULL) {
        ((TItemAttacker *)object)->deliver_delayed_weapon_hit();
    }
}

TItemAttacker::~TItemAttacker() {}
void TItemAttacker::run_task() { if (done != 0) { queue_destruction(); } }

__declspec(section ".data") saddr item_nj_chunk_buffer_table[2];
saddr get_item_chunk_buffer(int a0) {  return item_nj_chunk_buffer_table[a0]; }

void TItemBuff__ct(void) {
    if ((u32) (*(u32 *)&item_buff_buffer) != 0) {
        if ((s32) item_buffer_temp_mode != 0) {
            TLobby::tmp_buf_release((const char *)(saddr) &(*(RecoveredGlobal_8010355C_lbl_8043E038 *)(s32 *)"TItemBuff").value);
        } else {
            mem_free((void *)(*(uaddr *)&item_buff_buffer));
        }
        (*(u32 *)&item_buff_buffer) = 0;
    }
}
s32 create_item_buff(s32 size);
s32 create_item_buff(s32 size) {
    s32 temp_r3;

    if (size != 0) {
        TItemBuff__ct();
        temp_r3 = TLobby::tmp_buf_is_free();
        item_buffer_temp_mode = temp_r3;
        if ((temp_r3 != 0) && (size < 0x40000)) {
            item_buff_buffer = (saddr)TLobby::tmp_buf_use_req("TItemBuff");
        } else {
            item_buff_buffer = (saddr)mem_alloc(size);
        }
    }
    return item_buff_buffer;
}
