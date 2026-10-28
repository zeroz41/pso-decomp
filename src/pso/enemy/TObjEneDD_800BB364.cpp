#include "types.h"
#include "pso/boss/TBoss8Dragon_800BB650.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TLobby.h"

struct RecoveredGlobal_800BB45C_lbl_80500B98 {
    s32 value;
    u8 remaining[0x1C];
};

struct Ent_800BB484 { s16 id; f32 dist; };

extern "C" {
extern RecoveredGlobal_800BB45C_lbl_80500B98 enemy_target_candidate_table;
typedef struct Ent_800BB388 {
    u8 pad0[0x30];
    s32 flags30;
    u8 pad34[0x38 - 0x34];
    u8 pos[0x2FC - 0x38];
    u8 f2FC[0xC];
} Ent_800BB388;

Ent_800BB388 *get_player_data__10TObjPlayerFi(s32);
u16 get_entity_id(void *);
u32 csnLookAt(void *, void *);
s32 is_alive__9TObjEneDDFv(void *);
f32 horizontal_distance_squared(void *, void *);

u16 enemy_nearest_visible_enemy_sq(Ent_800BB388 *self, f32 range);
extern const f32 TObjEneDD__data_805D9E8C;
s32 collect_enemy_target_candidates(s32 arg0, Ent_800BB484 *out, f32 farg0);

void TObjEneDD::set_squared_value(f32 farg0) {
    ((s32 (*)(f32))enemy_nearest_visible_enemy_sq)(farg0 * farg0);
}
u16 enemy_nearest_visible_enemy_sq(Ent_800BB388 *self, f32 range) {
    s32 count;
    s32 base;
    Ent_800BB388 *p;
    u16 best;
    s32 i;
    f32 d;

    best = 0xFFFF;
    base = TLobby::get_game_mode();
    count = TObjEneDD::get_enemy_count();
    for (i = 0; i < count; i++) {
        p = get_player_data__10TObjPlayerFi(base + i);
        if (p != self && !(p->flags30 & 0x01000000) && is_alive__9TObjEneDDFv(p) != 0) {
            d = horizontal_distance_squared(self->f2FC, p->pos);
            if (d < range && csnLookAt(self->f2FC, p->f2FC) == 0) {
                best = get_entity_id(p);
                range = d;
            }
        }
    }
    return best;
}
typedef char RecoveredGlobal_800BB45C_lbl_80500B98_size[sizeof(RecoveredGlobal_800BB45C_lbl_80500B98) == 0x20 ? 1 : -1];
void TObjEneDD::collect_target_candidates(s32 arg0, f32 farg0) {
    collect_enemy_target_candidates(arg0, (Ent_800BB484 *)(&enemy_target_candidate_table.value), farg0);
}
s32 collect_enemy_target_candidates(s32 arg0, Ent_800BB484 *out, f32 farg0) {
    s32 n;
    s32 cnt;
    Ent_800BB484 tmp;
    u8 *p;
    s32 mi;
    s32 j;
    f32 mx;
    f32 d;
    s32 k;
    n = 0;
    cnt = TLobby::get_game_mode();
    if (farg0 > TObjEneDD__data_805D9E8C) {
        for (s32 i = 0; i < cnt; i++) {
            p = ((u8 *)get_player_data__10TObjPlayerFi(i));
            if (is_alive__9TObjEneDDFv(p) != 0) {
                d = horizontal_distance_squared((void *)(arg0 + 0x38), p + 0x38);
                if (d < farg0) {
                    out[n].id = get_entity_id(p);
                    out[n].dist = d;
                    n++;
                }
            }
        }
    } else {
        for (s32 i = 0; i < cnt; i++) {
            p = ((u8 *)get_player_data__10TObjPlayerFi(i));
            if (is_alive__9TObjEneDDFv(p) != 0) {
                d = horizontal_distance_squared((void *)(arg0 + 0x38), p + 0x38);
                out[n].id = get_entity_id(p);
                out[n].dist = d;
                n++;
            }
        }
    }
    if (n > 1) {
        for (k = n - 1; k >= 1; k--) {
            mx = out[0].dist;
            mi = 0;
            for (j = 1; j <= k; j++) {
                f32 v = out[j].dist;
                if (v > mx) {
                    mx = v;
                    mi = j;
                }
            }
            if (mi != k) {
                TBoss8Dragon__sub_800BB650(&tmp, &out[mi]);
                TBoss8Dragon__sub_800BB650(&out[mi], &out[k]);
                TBoss8Dragon__sub_800BB650(&out[k], &tmp);
            }
        }
    }
    return n;
}

}
