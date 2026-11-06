#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2_80356E50.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"

extern "C" {
void world_to_grid_pos__11TBoss6Type2FPvPvPv(f32 *arg0, s8 *arg1, s8 *arg2);
}
void send_6xAD_olga_flow_subordinate_boss_actions(u8 *arg0);
extern "C" {
void TBoss6Type2__sub_803570C8(s8 *arg0);

void TBoss6Type2__sub_80356E50(s32 arg0, s32 arg1, s32 force) {
    TBoss6Type2::send_subordinate_actions(0, arg0, arg1, force, arg0);
}

struct Pkt_80356F28 { u8 b[0x40]; };

s32 rand(void);
extern const u8 lbl_805E0018;
extern const u8 lbl_805E0019;
extern const f32 lbl_805E001C;
extern const f32 lbl_805E0020;
extern const f32 lbl_805E0024;

void TBoss6Type2::send_6xAD_grid_positions(u8 arg0, s32 arg1, s32 arg2) {
    u8 a;
    u8 b;
    u8 buf[0x44];
    s32 p;
    s32 j;
    s32 i;
    if (arg2 < 0 || arg2 > 3) {
        return;
    }
    TBoss6Type2__sub_803570C8((s8 *)buf);
    buf[0] = arg0;
    p = arg1;
    j = 1;
    for (i = 0; i < arg2; i++, p += 0xC, j += 2) {
        world_to_grid_pos__11TBoss6Type2FPvPvPv((f32 *)p, (s8 *)&a, (s8 *)&b);
        buf[j] = a;
        buf[j + 1] = b;
    }
    send_6xAD_olga_flow_subordinate_boss_actions((buf));
}

s32 TBoss6Type2::send_subordinate_actions(s32 kind, s32 ids, s32 n, s32 force, s32 unused) {
    Pkt_80356F28 pkt;
    s32 i;

    TBoss6Type2__sub_803570C8((s8 *)&pkt);
    for (i = 0; i < n; i++) {
        s32 off = ((s32 *)ids)[i] + 7;
        u8 flags = 0;
        if (lbl_805E001C * (f32)rand() > lbl_805E0020) {
            flags = lbl_805E0018;
        }
        if (force != 0 || lbl_805E001C * (f32)rand() < lbl_805E0024) {
            flags |= lbl_805E0019;
        }
        pkt.b[off] = flags | (s8)kind;
    }
    send_6xAD_olga_flow_subordinate_boss_actions((u8 *)&pkt);
}
}
