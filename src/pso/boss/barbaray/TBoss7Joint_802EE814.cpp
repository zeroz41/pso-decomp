#include "types.h"
#include "pso/boss/barbaray/TBoss7Joint.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/system/SoundEffect.h"
#include "pso/enemy/dd/TObjEneDD.h"

extern "C" {
extern const f32 lbl_805DE9F0;
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
s32 reload_stats_keep_hp_tp__9TObjEneDDFv(void *, int, int, int);
u32 __nw__7TObjectFUl(int);
s32 TObjPlayer__sub_802E72DC(void *, void *, void *, int);

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
    if (*(s32 *)((s8 *)this->bodies + 0x18) & 6) {
        TObjEneDD::vfunc_93();
        return;
    }
    TObjEneDD::vfunc_94();
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
    if (temp_f2 < (lbl_805DE9F0 - 50.0f)) {
        temp_r4 = (u8 *)this->bodies;
        *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFF8);
    } else if (temp_f2 >= 30.0f) {
        temp_r4_2 = (u8 *)this->bodies;
        *(s32 *)((s8 *)temp_r4_2 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4_2 + 0x18) | 5);
        temp_r4_3 = (u8 *)this->bodies;
        *(s32 *)((s8 *)temp_r4_3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4_3 + 0x18) & 0xFFFFFFFD);
    } else {
        temp_r4_4 = (u8 *)this->bodies;
        *(s32 *)((s8 *)temp_r4_4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4_4 + 0x18) | 3);
        temp_r4_5 = (u8 *)this->bodies;
        *(s32 *)((s8 *)temp_r4_5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4_5 + 0x18) & 0xFFFFFFFB);
    }
    ((TObjEneDD *)arg0)->transform_part_positions();
}

}
