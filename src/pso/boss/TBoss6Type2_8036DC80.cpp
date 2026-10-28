#include "types.h"
#include "pso/boss/TBoss6Type2_8036DC80.h"
#include "pso/boss/TBoss6Type2.h"

struct E_8036DDE8 { s32 f0; u8 pad[0x28]; };

struct Ent_8036DD30 { s32 active; u8 v0[8]; u8 v1[8]; u8 v2[8]; s32 a; s32 b; s32 c; s32 d; };

extern "C" {
extern s8 boss6_type2_player_snapshot_table[];
void *get_player_by_client_id(s32 i);
s32 is_state_1f__14TBoss6PlotFalzFUi(u32 arg0);
u16 get_entity_id();

void TBoss6Type2::apply_pending_effect() {
    u16 temp_r3;
    u8 *temp_r31;

    temp_r3 = get_entity_id();
    if (temp_r3 < 4U) {
        temp_r31 = (unsigned char *) (boss6_type2_player_snapshot_table + (temp_r3 * 0x2C));
        if ((s32) *(s32 *)((s8 *)temp_r31 + 0) != 0) {
            *(s32 *)((s8 *)temp_r31 + 0) = 0;
            if (is_state_1f__14TBoss6PlotFalzFUi((u32)this) != 0) {
                ((TBoss6Type2 *)(((u8 *)this) + 0xCF4))->copy_vec2(temp_r31 + 4);
                ((TBoss6Type2 *)(((u8 *)this) + 0xA1C))->copy_vec2(temp_r31 + 0xC);
                ((TBoss6Type2 *)(((u8 *)this) + 0xB88))->copy_vec2(temp_r31 + 0x14);
                this->m_34 = (s32) *(s32 *)((s8 *)temp_r31 + 0x1C);
                *(s32 *)((s8 *)((u8 *)this) + 0x8B0) = (s32) *(s32 *)((s8 *)temp_r31 + 0x20);
                *(s32 *)((s8 *)((u8 *)this) + 0x8AC) = (s32) *(s32 *)((s8 *)temp_r31 + 0x24);
                *(s32 *)((s8 *)((u8 *)this) + 0x8B4) = (s32) *(s32 *)((s8 *)temp_r31 + 0x28);
            }
        }
    }
}

void TBoss6Type2::capture_player_snapshots() {
    s32 i;
    u8 *p;
    Ent_8036DD30 *e;
    for (i = 0; i < 4; i++) {
        e = &((Ent_8036DD30 *)boss6_type2_player_snapshot_table)[i];
        e->active = 0;
        p = (u8 *)get_player_by_client_id(i);
        if (p != NULL && is_state_1f__14TBoss6PlotFalzFUi((u32)p) != 0) {
            ((TBoss6Type2 *)(e->v0))->copy_vec2(p + 0xCF4);
            ((TBoss6Type2 *)(e->v1))->copy_vec2(p + 0xA1C);
            ((TBoss6Type2 *)(e->v2))->copy_vec2(p + 0xB88);
            e->a = *(s32 *)((s8 *)p + 0x34);
            e->b = *(s32 *)((s8 *)p + 0x8B0);
            e->c = *(s32 *)((s8 *)p + 0x8AC);
            e->d = *(s32 *)((s8 *)p + 0x8B4);
            e->active = 1;
        }
    }
}

void TLobby__sub_8036DDE8(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((E_8036DDE8 *)boss6_type2_player_snapshot_table)[i].f0 = 0;
    }
}

}
