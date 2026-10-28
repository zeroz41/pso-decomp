#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/boss/TBoss8Dragon_80065C90.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss5Gryphon.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80065EA0_lbl_80487CCC_80065C90 {
    s32 value;
    u8 remaining[0x8];
};
struct RecoveredGlobal_80065EA0_lbl_80487CD8_80065C90 {
    s32 value;
    u8 remaining[0x350];
};
struct RecoveredGlobal_80065DB4_lbl_804FF5B4_80065C90 {
    s32 value;
    u8 remaining[0x8];
};
struct RecoveredGlobal_80065F08_lbl_80437938_80065C90 {
    s32 value;
    u8 remaining[0x8];
};

struct O_80065FD4 { u16 a; u16 b; u32 c[4]; };

extern "C" {

extern RecoveredGlobal_80065EA0_lbl_80487CCC_80065C90 boss8_dragon_follow_camera_offsets;
extern RecoveredGlobal_80065EA0_lbl_80487CD8_80065C90 lbl_80487CD8;
extern int boss5_gryphon_instance;
extern RecoveredGlobal_80065DB4_lbl_804FF5B4_80065C90 boss5_gryphon_behavior_params;
extern const f32 lbl_805D8D5C;
extern RecoveredGlobal_80065F08_lbl_80437938_80065C90 lbl_80437938;

typedef char RecoveredGlobal_80065EA0_lbl_80487CCC_size[sizeof(RecoveredGlobal_80065EA0_lbl_80487CCC_80065C90) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80065EA0_lbl_80487CD8_size[sizeof(RecoveredGlobal_80065EA0_lbl_80487CD8_80065C90) == 0x354 ? 1 : -1];

typedef char RecoveredGlobal_80065DB4_lbl_804FF5B4_size[sizeof(RecoveredGlobal_80065DB4_lbl_804FF5B4_80065C90) == 0xC ? 1 : -1];
void TBoss8Dragon::fill_follow_camera_params(u8 *arg1, u8 *arg2) {
    *(f32 *)((s8 *)arg1 + 0) = (f32) lbl_805D8D5C;
    *(f32 *)((s8 *)arg2 + 0) = (f32) lbl_805D8D5C;
    switch (this->m_4e4) {
    default:
    case 2:
    case 0:
        *(f32 *)((s8 *)arg1 + 4) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)&boss5_gryphon_behavior_params.value + 0)) + 0);
        *(f32 *)((s8 *)arg1 + 8) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)&boss5_gryphon_behavior_params.value + 0)) + 4);
        *(f32 *)((s8 *)arg2 + 4) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)&boss5_gryphon_behavior_params.value + 0)) + 8);
        *(f32 *)((s8 *)arg2 + 8) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)&boss5_gryphon_behavior_params.value + 0)) + 0xC);
        return;
    case 1:
        *(f32 *)((s8 *)arg1 + 4) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)&boss5_gryphon_behavior_params.value + 0)) + 0x10);
        *(f32 *)((s8 *)arg1 + 8) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)&boss5_gryphon_behavior_params.value + 0)) + 0x14);
        *(f32 *)((s8 *)arg2 + 4) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)&boss5_gryphon_behavior_params.value + 4)) + 0);
        *(f32 *)((s8 *)arg2 + 8) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)&boss5_gryphon_behavior_params.value + 4)) + 4);
        return;
    case 3:
        *(f32 *)((s8 *)arg1 + 4) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)&boss5_gryphon_behavior_params.value + 4)) + 8);
        *(f32 *)((s8 *)arg1 + 8) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)&boss5_gryphon_behavior_params.value + 4)) + 0xC);
        *(f32 *)((s8 *)arg2 + 4) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)&boss5_gryphon_behavior_params.value + 4)) + 0x10);
        *(f32 *)((s8 *)arg2 + 8) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)&boss5_gryphon_behavior_params.value + 4)) + 0x14);
        return;
    }
}

void TBoss8Dragon::get_follow_camera_offsets(u8 *arg1) {
    if ((void *) (*(u8 * *)&boss5_gryphon_instance) == NULL) {
        VecCopy((Vec *)this, (const Vec *)&boss8_dragon_follow_camera_offsets.value);
        VecCopy((Vec *)arg1, (const Vec *)&lbl_80487CD8.value);
        return;
    }
    ((TBoss8Dragon *)(*(u8 * *)&boss5_gryphon_instance))->fill_follow_camera_params((u8 *)this, arg1);
}

typedef char RecoveredGlobal_80065F08_lbl_80437938_size[sizeof(RecoveredGlobal_80065F08_lbl_80437938_80065C90) == 0xC ? 1 : -1];
s32 *TBoss8Dragon__sub_80065F08(void) {
    return &lbl_80437938.value;
}

int TBoss8Dragon::get_instance_count() {  return boss5_gryphon_instance; }

void TBoss5Gryphon::apply_poison_status() {  }
void TBoss5Gryphon::apply_paralysis() {  }
void TBoss5Gryphon::apply_slow_status() {  }
void TBoss5Gryphon::apply_confusion_status() {  }
void TBoss5Gryphon::apply_movement_ailment(s32) {  }
void TBoss5Gryphon::apply_shock_status() {  }
void TBoss5Gryphon::clear_harmful_statuses() {  }
void TBoss8Dragon::init_color() { *(u8 *)&this->m_0 = 160; *(u8*)((char*)this + 0x1) = 10; }

void TBoss8Dragon::send_spawn_params_packet() { byteswap_action_packet(); send_subcommand((u8 *)this); }

void TBoss8Dragon::byteswap_action_packet() {
    ((G_ClientIDHeader *)this)->bswap();
    ((TBoss8Dragon *)((char *)this + 20))->byteswap_record();
    bswap_32((u32 *)((void *)((char *)this + 4)));
    bswap_32((u32 *)((void *)((char *)this + 8)));
    bswap_32((u32 *)((void *)((char *)this + 12)));
    bswap_32((u32 *)((void *)((char *)this + 16)));
}

void TBoss8Dragon::byteswap_record() {
    O_80065FD4 *p = (O_80065FD4 *)this;
    s32 i;
    bswap_16(&p->a);
    bswap_16(&p->b);
    for (i = 0; i < 4; i++) {
        bswap_32(&p->c[i]);
    }
}

void TBoss8Dragon::send_boss_actions() { bswap_boss_actions(); send_subcommand((u8 *)this); }

void TBoss8Dragon::bswap_boss_actions() {
    s32 arg0 = (s32)this;
    ((G_ClientIDHeader *)arg0)->bswap();
    bswap_32((u32 *)(arg0 + 4));
    bswap_32((u32 *)(arg0 + 8));
    bswap_32((u32 *)(arg0 + 0xC));
}
void TBoss8Dragon__sub_800660A4(void* p) { *(u8*)((char*)p + 0x0) = 159; *(u8*)((char*)p + 0x1) = 4; }

void fn_800660B8(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0xB0) = (s32) (*(s32 *)((s8 *)arg0 + 0xB0) & 0xFFFFFFFB);
    *(s32 *)((s8 *)arg0 + 0xB0) = (s32) (*(s32 *)((s8 *)arg0 + 0xB0) | 1);
}

void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0) {
    *(s32 *)((s8 *)arg0 + 0x4C) = arg1;
    *(s32 *)((s8 *)arg0 + 0x50) = arg2;
    *(s32 *)((s8 *)arg0 + 0x54) = arg3;
    *(u16 *)((s8 *)arg0 + 0x2C) = (u16) (*(u16 *)((s8 *)arg0 + 0x2C) | 0x200);
    *(f32 *)((s8 *)arg0 + 0x5C) = farg0;
    if (arg4 != 0) {
        *(u16 *)((s8 *)arg0 + 0x2C) = (u16) (*(u16 *)((s8 *)arg0 + 0x2C) | 0x400);
    }
}

extern f32 lbl_805D4D90;
extern f32 lbl_805D4D94;
extern f32 lbl_805D8D58;
extern f32 lbl_805D8D90;
extern f32 lbl_805D9E80;

void TBoss8Dragon__sub_80066108(void) {
    lbl_805D4D90 = lbl_805D8D90 * lbl_805D9E80;
    lbl_805D4D94 = lbl_805D8D58 * lbl_805D9E80;
}

}
