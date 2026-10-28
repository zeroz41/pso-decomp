#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8010A050.h"
#include "pso/item/TItem.h"

struct Vec_80109A30 { f32 x, y, z; };

extern "C" {
void *__ct__17TItemEffNeedlePosFv(void *, s32, void *, Vec_80109A30 *, Vec_80109A30 *);
void *__nw__7TObjectFUl(u32);
void subtract_vector(Vec_80109A30 *, Vec_80109A30 *);
void spawn_needle_wall_impact(s32 arg0, void *arg1, Vec_80109A30 *arg2, Vec_80109A30 *arg3);
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
extern TObject *tl_05;

void fn_80109974(s32 id, const Vec_80109A30 &pos, Vec_80109A30 *dir) {
    void *eff;
    TObjPlayer *player;

    player = (TObjPlayer *)find_item_by_id(id);
    eff = __nw__7TObjectFUl(0x50);
    if (eff != NULL) {
        eff = __ct__17TItemEffNeedlePosFv(eff, (s32)tl_05, player, (Vec_80109A30 *)&pos, dir);
    }
    if (eff != NULL) {
        *(s32 *)((s8 *)eff + 0x3C) = TObjPlayer__sub_8010A058(player);
        *(s32 *)((s8 *)eff + 0x40) = player->get_entity_id();
        *(s32 *)((s8 *)eff + 0x44) += 0x8000;
    }
    Vec_80109A30 v = pos;
    create_timed_particle_emitter(&v, 0x180, 0, 0x3C);
}

void spawn_needle_wall_impact(s32 arg0, void *arg1, Vec_80109A30 *arg2, Vec_80109A30 *pos) {
    void *var_r31;
    if ((arg0 != 0) && (arg2 != NULL) && (arg1 != NULL) && (pos != NULL)) {
        Vec_80109A30 v = *pos;
        subtract_vector(&v, arg2);
        var_r31 = __nw__7TObjectFUl(0x50);
        if (var_r31 != NULL) {
            var_r31 = __ct__17TItemEffNeedlePosFv(var_r31, arg0, arg1, pos, &v);
        }
        if (var_r31 != NULL) {
            *(s32 *)((s8 *)var_r31 + 0x3C) = *(s32 *)((s8 *)arg1 + 0x188);
            *(s32 *)((s8 *)var_r31 + 0x40) = ((TObjPlayer *)arg1)->get_entity_id();
        }
    }
}

}
