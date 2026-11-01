#include "pso/TItemAttacker.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

#pragma readonly_strings on

extern "C" {
const char *TItemAttacker__name = "TItemAttacker";
}


struct RecoveredGlobal_8010355C_lbl_8043E038 { char value[0xA]; };
typedef char RecoveredGlobal_8010355C_lbl_8043E038_size[sizeof(RecoveredGlobal_8010355C_lbl_8043E038) == 0xA ? 1 : -1];

struct Rec_80103368 { u8 pad[0x1C]; f32 v[3]; u8 pad2[0x2C - 0x28]; };

struct M_80103368 { u8 pad[0xA4]; Rec_80103368 *recs; };

extern "C" {
void mem_free(void *p);
extern s32 item_buffer_temp_mode;
extern s32 item_buff_buffer;
void TItemBuff__ct(void);
void *find_entity_by_id(u16 id);
extern const char *TItemAttacker__name;
void TItemAttacker__sub_8010349C(u32 arg0);
int get_item_chunk_buffer(int a0);
u8 *TItemTimer__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void deliver_delayed_weapon_hit(u8 *arg0);
s32 __nw__7TObjectFUl(int);
void *mem_alloc(u32 size);
void queue_destruction__7TObjectFv(void *arg0);

}

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

struct Rec_801031CC { u8 d[0x2c]; };

struct Tbl_801031CC { u8 pad[0x1c]; Rec_801031CC r[1]; };

extern "C" {
u8 *__ct__13TItemAttackerFllll(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
f32 horizontal_distance_squared(void *, void *);
void *resolve_hittable_target(u16 actorId, s16 collider);
void *get_player_by_client_id(s32 i);
extern const f32 lbl_805DAAA8;
void deliver_delayed_weapon_hit(u8 *arg0) {
    u8 *temp_r3;
    u8 *temp_r30;
    u32 player;
    u8 *item;
    temp_r3 = (u8 *)(resolve_hittable_target(*(u16 *)((s8 *)arg0 + 0x2A), *(s16 *)((s8 *)arg0 + 0x2C)));
    if (temp_r3 != NULL) {
        temp_r30 = (u8 *)&((Tbl_801031CC *)(((TObjPlayer *)temp_r3)->bodies))->r[*(s16 *)((s8 *)arg0 + 0x2C)];
        if (horizontal_distance_squared(arg0 + 0x38, temp_r30) < lbl_805DAAA8) {
            player = (u32)get_player_by_client_id((*(u16 *)((s8 *)arg0 + 0x28)));
            item = (u8 *)(find_item_by_id(*(s32 *)((s8 *)arg0 + 0x24)));
            if ((player != 0U) && (item != NULL)) {
                ((AttackWeapon*)item)->m59(player,temp_r3,*(s32*)((s8 *)arg0 + 0x20),*(f32*)((s8 *)arg0 + 0x30),*(s16*)((s8 *)arg0 + 0x2C));
            }
        } else {
            if (horizontal_distance_squared(temp_r30, arg0 + 0x44) < horizontal_distance_squared(arg0 + 0x38, arg0 + 0x44)) {
                ((TObjPlayer *)temp_r3)->show_miss_for_collider(*(s16 *)((s8 *)arg0 + 0x2C));
            }
        }
    }
    *(s32 *)((s8 *)arg0 + 0x34) = 1;
}
}
void spawn_item_attacker(s32 arg0, u32 arg1, s32 arg2, u8 *arg3);
void spawn_item_attacker(s32 arg0, u32 arg1, s32 arg2, u8 *arg3) {
    s32 object;
    if ((arg0 != 0) && (arg3 != NULL) && (arg1 != 0U) && ((u16) *(u16 *)((s8 *)arg3 + 0xC) != 65535U) && ((u16) *(u16 *)((s8 *)arg3 + 0xE) != 65535U)) {
        object = __nw__7TObjectFUl(0x50);
        if (object != 0) {
            object = (s32)__ct__13TItemAttackerFllll((u8 *)object, (s32)arg0, (s32)arg1, (s32)arg2, (s32)arg3);
        }
        TItemAttacker::spawn_item_timer((TObject *)object, (ItemTimerCallback)TItemAttacker__sub_8010349C, arg2);
    }
}

TItemAttacker::TItemAttacker(s32 arg1, s32 arg2, s32 arg3, s32 arg4) : TObject((TObject *)arg1) {
    u8* temp_r5;
    u8 *entity;
    *(s32 *)((s8 *)this + 0) = (s32) ((s32)TItemAttacker__name);
    ((TItemAttacker *)(((u8 *)this) + 0x1C))->copy_from((void *)arg4);
    *(s32 *)((s8 *)this + 0x34) = 0;
    VecCopy((Vec *)(((u8 *)this) + 0x44), (const Vec *)(arg2));
    entity = (u8 *)(find_entity_by_id(*(u16 *)((s8 *)this + 0x2A)));
    if (entity != NULL) {
        VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(((M_80103368 *)entity)->recs[*(s16 *)((s8 *)this + 0x2C)].v));
    } else {
        *(s32 *)((s8 *)this + 0x34) = 1;
    }
}


void TItemAttacker::copy_from(void *arg1) {
    *(s32 *)&this->m_name = (s32) *(s32 *)((s8 *)arg1 + 0);
    *(s32 *)&this->m_flags = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(s32 *)&this->m_prev = (s32) *(s32 *)((s8 *)arg1 + 8);
    *(u16 *)&this->m_next = (u16) *(u16 *)((s8 *)arg1 + 0xC);
    *(u16 *)((s8 *)this + 0xE) = (u16) *(u16 *)((s8 *)arg1 + 0xE);
    *(s16 *)&this->m_up = (s16) *(s16 *)((s8 *)arg1 + 0x10);
    *(f32 *)&this->m_down = (f32) *(f32 *)((s8 *)arg1 + 0x14);
}

void TItemAttacker::spawn_item_timer(TObject *object, ItemTimerCallback expire, s32 frames) {
    void *item_timer;
    if (object != NULL) {
        item_timer = (void *)__nw__7TObjectFUl(0x28);
        if (item_timer != NULL) {
            TItemTimer__ct((u8 *)item_timer, (s32)object, (s32)expire, frames);
        }
    }
}

void TItemAttacker__sub_8010349C(u32 arg0) {
    if (arg0 != 0U) {
        deliver_delayed_weapon_hit((u8 *)arg0);
    }
}

TItemAttacker::~TItemAttacker() {}
void TItemAttacker::run_task() { if (*(int*)((char*)this + 0x34) != 0) { queue_destruction__7TObjectFv(this); } }

    extern int item_nj_chunk_buffer_table[];
int get_item_chunk_buffer(int a0) {  return item_nj_chunk_buffer_table[a0]; }

void TItemBuff__ct(void) {
    if ((u32) (*(u32 *)&item_buff_buffer) != 0) {
        if ((s32) item_buffer_temp_mode != 0) {
            TLobby::tmp_buf_release((const char *)(s32) &(*(RecoveredGlobal_8010355C_lbl_8043E038 *)(s32 *)"TItemBuff").value);
        } else {
            mem_free((void *)(*(u32 *)&item_buff_buffer));
        }
        (*(u32 *)&item_buff_buffer) = 0;
    }
}
s32 create_item_buff(s32 arg0);
s32 create_item_buff(s32 arg0) {
    s32 temp_r3;

    if (arg0 != 0) {
        TItemBuff__ct();
        temp_r3 = TLobby::tmp_buf_is_free();
        item_buffer_temp_mode = temp_r3;
        if ((temp_r3 != 0) && (arg0 < 0x40000)) {
            item_buff_buffer = TLobby::tmp_buf_use_req((const char *)(s32 *)"TItemBuff");
        } else {
            item_buff_buffer = (s32)mem_alloc(arg0);
        }
    }
    return item_buff_buffer;
}
