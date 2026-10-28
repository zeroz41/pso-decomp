#include "types.h"
#include "pso/boss/TBoss7Joint_802EE6E0.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/boss/TBoss7DeRolLeC.h"
#include "pso/boss/TBoss7Joint.h"
#include "pso/enemy/TObjEneDD.h"

extern "C" {
extern const f32 lbl_805DE9F0;
extern const f32 lbl_805DEBA8;
extern const f32 lbl_805DEBAC;
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
s32 reload_stats_keep_hp_tp__9TObjEneDDFv(void *, int, int, int);
s32 play_sound_effect(int, void *, int, int);
u32 __nw__7TObjectFUl(int);
s32 TObjPlayer__sub_802E72DC(void *, void *, void *, int);
s32 vfunc_93__9TObjEneDDFv(void *);
s32 vfunc_94__9TObjEneDDFv(void *);
int read_be16_field2__10TObjPlayerFv(void*);

    extern int boss7_joint_state;
int TBoss7Joint::get_state() {  return boss7_joint_state; }

void TBoss7DeRolLeC::apply_poison_status() {  }
void TBoss7DeRolLeC::apply_paralysis() {  }
void TBoss7DeRolLeC::apply_slow_status() {  }
void TBoss7DeRolLeC::apply_confusion_status() {  }
void TBoss7DeRolLeC::apply_movement_ailment(s32) {  }
void TBoss7DeRolLeC::apply_shock_status() {  }
void TBoss7DeRolLeC::clear_harmful_statuses() {  }
void TBoss7Joint::read_state() { read_be16_field2__10TObjPlayerFv(this); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }
void TBoss7Joint::byteswap_action_packet() { read_be16_field2__10TObjPlayerFv(this); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }
void TBoss7Joint::update_and_send_60() { byteswap_action_packet(); send_subcommand((u8 *)this); }
void TBoss7Joint__sub_802EE7B8(void* p) { *(u8*)((char*)p + 0x0) = 169; *(u8*)((char*)p + 0x1) = 2; }
void TBoss7Joint::broadcast_state() { read_state(); send_subcommand((u8 *)this); }
void TBoss7Joint__sub_802EE800(void* p) { *(u8*)((char*)p + 0x0) = 170; *(u8*)((char*)p + 0x1) = 3; }

int TBoss7Joint::is_part_active() { return *(u32*)((char*)this + 0x3bc) & 0x1; }

void TBoss7Joint::init_boss_stats() {
    *(s32 *)((s8 *)((u8 *)this) + 0x3BC) = *(s32 *)((s8 *)((u8 *)this) + 0x3BC) | 1;
    reload_stats_keep_hp_tp__9TObjEneDDFv(this, register_boss__6TLobbyFl(0x10), dispatch_shared_handler_b__6TLobbyFl(0xF), register_object__6TLobbyFl(0x10));
    *(s16 *)((s8 *)((u8 *)this) + 0x32C) = 0x4E20;
    *(s16 *)((s8 *)((u8 *)this) + 0x2B8) = 0x4E20;
    u32 p = __nw__7TObjectFUl(0x2C);
    if (p != 0U) {
        TObjPlayer__sub_802E72DC((void *)p, this, ((u8 *)this) + 0x38, *(s32 *)((s8 *)((u8 *)this) + 0x3B8));
    }
    play_sound_effect(0x3A312, ((u8 *)this) + 0x38, 0, 0);
}

void TBoss7Joint::vfunc_93() {
    if (*(s32 *)((s8 *)this->m_a4 + 0x18) & 6) {
        vfunc_93__9TObjEneDDFv(this);
        return;
    }
    vfunc_94__9TObjEneDDFv(this);
}
void TBoss7Joint::vfunc_88() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f2;
    u8 *temp_r4;
    u8 *temp_r4_2;
    u8 *temp_r4_3;
    u8 *temp_r4_4;
    u8 *temp_r4_5;
    temp_f2 = *(f32 *)((s8 *)arg0 + 0x3C);
    if (temp_f2 < (lbl_805DE9F0 - lbl_805DEBA8)) {
        temp_r4 = (u8 *)this->m_a4;
        *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFF8);
    } else if (temp_f2 >= lbl_805DEBAC) {
        temp_r4_2 = (u8 *)this->m_a4;
        *(s32 *)((s8 *)temp_r4_2 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4_2 + 0x18) | 5);
        temp_r4_3 = (u8 *)this->m_a4;
        *(s32 *)((s8 *)temp_r4_3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4_3 + 0x18) & 0xFFFFFFFD);
    } else {
        temp_r4_4 = (u8 *)this->m_a4;
        *(s32 *)((s8 *)temp_r4_4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4_4 + 0x18) | 3);
        temp_r4_5 = (u8 *)this->m_a4;
        *(s32 *)((s8 *)temp_r4_5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4_5 + 0x18) & 0xFFFFFFFB);
    }
    ((TObjEneDD *)arg0)->transform_part_positions();
}

}
