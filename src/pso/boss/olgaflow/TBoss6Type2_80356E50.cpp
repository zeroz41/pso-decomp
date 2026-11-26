#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2_80356E50.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include <stdlib.h>
#include "pso/effect/item/TItemEffOrgaFlowShot.h"


void TBoss6Type2__sub_80356E50(s32 ids, s32 cnt, s32 force) {
    TBoss6Type2::send_subordinate_actions(0, ids, cnt, force, ids);
}

struct Pkt_80356F28 { u8 b[0x40]; };

// The two packet flag bits are loaded from .sdata2 ahead of the function's float literals: file constants
// read through inlined references, emitted at their first user (the TBoss6Type2.cpp form).
static const u8 random_action_flag = 0x40;
static const u8 forced_action_flag = 0x20;

inline const u8 &get_random_action_flag() { return random_action_flag; }
inline const u8 &get_forced_action_flag() { return forced_action_flag; }

void TBoss6Type2::send_6xAD_grid_positions(s32 index, saddr points, s32 count) {
    u8 a;
    u8 b;
    u8 buf[0x44];
    saddr p;
    s32 j;
    s32 i;
    if (count < 0 || count > 3) {
        return;
    }
    clear_6xAD_action_buffer((s8 *)buf);
    buf[0] = index;
    p = points;
    j = 1;
    for (i = 0; i < count; i++, p += 0xC, j += 2) {
        world_to_grid_pos((Vec *)p, (s8 *)&a, (s8 *)&b);
        buf[j] = a;
        buf[j + 1] = b;
    }
    send_6xAD_olga_flow_subordinate_boss_actions((buf));
}

void TBoss6Type2::send_subordinate_actions(s32 kind, saddr ids, s32 n, s32 force, s32 unused) {
    Pkt_80356F28 pkt;
    s32 i;

    clear_6xAD_action_buffer((s8 *)&pkt);
    for (i = 0; i < n; i++) {
        s32 off = ((s32 *)ids)[i] + 7;
        u8 flags = 0;
        if (3.0517578125e-05f * (f32)rand() > 0.5f) {
            flags = get_random_action_flag();
        }
        if (force != 0 || 3.0517578125e-05f * (f32)rand() < 0.25f) {
            flags |= get_forced_action_flag();
        }
        pkt.b[off] = flags | (s8)kind;
    }
    send_6xAD_olga_flow_subordinate_boss_actions((u8 *)&pkt);
}
