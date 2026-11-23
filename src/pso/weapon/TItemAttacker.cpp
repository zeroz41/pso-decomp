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

#pragma readonly_strings on


const char *TItemAttacker__name = "TItemAttacker";


struct ItemBuffTempLabel {
    char value[0xA];
};

struct EntityPositionRecord {
    u8 pad[0x1C];
    f32 position[3];
    u8 pad2[0x2C - 0x28];
};

struct EntityRecordTable {
    u8 pad[0xA4];
    EntityPositionRecord *recs;
};


s32 item_buffer_temp_mode;
saddr item_buff_buffer;
void TItemBuff__ct(void);
void TItemAttacker__sub_8010349C(uaddr attacker);
saddr get_item_chunk_buffer(int a0);
void deliver_delayed_weapon_hit(u8 *attacker);
struct AttackWeaponBase { char pad[0x18]; };

struct AttackWeapon : AttackWeaponBase {
virtual void m0();
virtual void m1();
virtual void m2();
virtual void m3();
virtual void m4();
virtual void m5();
virtual void m6();
virtual void m7();
virtual void m8();
virtual void m9();
virtual void m10();
virtual void m11();
virtual void m12();
virtual void m13();
virtual void m14();
virtual void m15();
virtual void m16();
virtual void m17();
virtual void m18();
virtual void m19();
virtual void m20();
virtual void m21();
virtual void m22();
virtual void m23();
virtual void m24();
virtual void m25();
virtual void m26();
virtual void m27();
virtual void m28();
virtual void m29();
virtual void m30();
virtual void m31();
virtual void m32();
virtual void m33();
virtual void m34();
virtual void m35();
virtual void m36();
virtual void m37();
virtual void m38();
virtual void m39();
virtual void m40();
virtual void m41();
virtual void m42();
virtual void m43();
virtual void m44();
virtual void m45();
virtual void m46();
virtual void m47();
virtual void m48();
virtual void m49();
virtual void m50();
virtual void m51();
virtual void m52();
virtual void m53();
virtual void m54();
virtual void m55();
virtual void m56();
virtual void m57();
virtual void m58();
virtual void m59(u32,void*,s32,f32,s16);
};

struct BodyPositionRecord {
    u8 d[0x2c];
};

struct PlayerBodyTable {
    u8 pad[0x1c];
    BodyPositionRecord entries[1];
};

extern "C" {
f32 horizontal_distance_squared(void *, void *);
}
void deliver_delayed_weapon_hit(u8 *attacker) {
    u8 *target;
    u8 *target_body;
    uaddr player;
    u8 *item;
    target = (u8 *)(resolve_hittable_target(*(u16 *)((s8 *)attacker + 0x2A), *(s16 *)((s8 *)attacker + 0x2C)));
    if (target != NULL) {
        target_body = (u8 *)&((PlayerBodyTable *)(((TObjPlayer *)target)->bodies))->entries[*(s16 *)((s8 *)attacker + 0x2C)];
        if (horizontal_distance_squared(attacker + 0x38, target_body) < 64.0f) {
            player = (uaddr)get_player_by_client_id((*(u16 *)((s8 *)attacker + 0x28)));
            item = (u8 *)(find_item_by_id(*(s32 *)((s8 *)attacker + 0x24)));
            if ((player != 0U) && (item != NULL)) {
                ((AttackWeapon*)item)->m59(player,target,*(s32*)((s8 *)attacker + 0x20),*(f32*)((s8 *)attacker + 0x30),*(s16*)((s8 *)attacker + 0x2C));
            }
        } else {
            if (horizontal_distance_squared(target_body, attacker + 0x44) < horizontal_distance_squared(attacker + 0x38, attacker + 0x44)) {
                ((TObjPlayer *)target)->show_miss_for_collider(*(s16 *)((s8 *)attacker + 0x2C));
            }
        }
    }
    *(s32 *)((s8 *)attacker + 0x34) = 1;
}
void spawn_item_attacker(s32 parent, u32 position, s32 frames, u8 *attack_record);
void spawn_item_attacker(s32 parent, u32 position, s32 frames, u8 *attack_record) {
    saddr object;
    if ((parent != 0) && (attack_record != NULL) && (position != 0U) && ((u16) *(u16 *)((s8 *)attack_record + 0xC) != 65535U) && ((u16) *(u16 *)((s8 *)attack_record + 0xE) != 65535U)) {
        object = (saddr)TObject::operator new(0x50);
        if (object != 0) {
            object = (saddr)__ct__13TItemAttackerFllll((u8 *)object, (s32)parent, (s32)position, (s32)frames, (saddr)attack_record);
        }
        TItemAttacker::spawn_item_timer((TObject *)object, (ItemTimerCallback)TItemAttacker__sub_8010349C, frames);
    }
}

TItemAttacker::TItemAttacker(saddr parent, saddr position, s32 frames, saddr attack_record) : TObject((TObject *)parent) {
    u8 *entity;
    *(s32 *)((s8 *)this + 0) = (s32) ((saddr)TItemAttacker__name);
    ((TItemAttacker *)(((u8 *)this) + 0x1C))->copy_from((void *)attack_record);
    *(s32 *)((s8 *)this + 0x34) = 0;
    VecCopy((Vec *)(((u8 *)this) + 0x44), (const Vec *)(position));
    entity = (u8 *)(find_entity_by_id(*(u16 *)((s8 *)this + 0x2A)));
    if (entity != NULL) {
        VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(((EntityRecordTable *)entity)->recs[*(s16 *)((s8 *)this + 0x2C)].position));
    } else {
        *(s32 *)((s8 *)this + 0x34) = 1;
    }
}


void TItemAttacker::copy_from(void *source_record) {
    *(s32 *)&this->m_name = (s32) *(s32 *)((s8 *)source_record + 0);
    *(s32 *)&this->m_flags = (s32) *(s32 *)((s8 *)source_record + 4);
    *(s32 *)&this->m_prev = (s32) *(s32 *)((s8 *)source_record + 8);
    *(u16 *)&this->m_next = (u16) *(u16 *)((s8 *)source_record + 0xC);
    *(u16 *)((s8 *)this + 0xE) = (u16) *(u16 *)((s8 *)source_record + 0xE);
    *(s16 *)&this->m_up = (s16) *(s16 *)((s8 *)source_record + 0x10);
    *(f32 *)&this->m_down = (f32) *(f32 *)((s8 *)source_record + 0x14);
}

void TItemAttacker::spawn_item_timer(TObject *object, ItemTimerCallback expire, s32 frames) {
    if (object != NULL) {
        new TItemTimer(object, (saddr)expire, frames);
    }
}

void TItemAttacker__sub_8010349C(uaddr attacker) {
    if (attacker != 0U) {
        deliver_delayed_weapon_hit((u8 *)attacker);
    }
}

TItemAttacker::~TItemAttacker() {}
void TItemAttacker::run_task() { if (*(int*)((char*)this + 0x34) != 0) { queue_destruction(); } }

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
