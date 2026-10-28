#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TPlayerBattleCtrl4P.h"

extern "C" {
TObjPlayer *get_player_by_client_id(s32 id);
s32 check_flag_100__10TObjPlayerFPv(TObjPlayer *player);
f32 xz_distance_squared(const f32 *a, const f32 *b);
extern const f32 lbl_805DC644;

#pragma push
#pragma optimization_level 3
s32 TPlayerBattleCtrl4P::fn_80211B10(s32 id) {
    TObjPlayer *self;
    u16 client_id;
    s32 result;
    s32 i;
    s32 j;
    s32 k;
    self = get_player_by_client_id((u16)id);
    if (self == NULL) {
        return 1;
    }
    client_id = id;
    result = 0;
    for (i = 0; i < 4; i++) {
        if (client_id != i) {
            TObjPlayer *other = get_player_by_client_id(i);
            if (other != NULL && check_flag_100__10TObjPlayerFPv(other) != 0) {
                result = 3;
            }
        }
    }
    for (j = 0; j < 4; j++) {
        if (client_id != j) {
            TObjPlayer *other = get_player_by_client_id(j);
            if (other != NULL && xz_distance_squared(&self->position.x, &other->position.x) > lbl_805DC644) {
                result = 2;
            }
        }
    }
    for (k = 0; k < 4; k++) {
        TObjPlayer *other = get_player_by_client_id(k);
        if (other != NULL && other->is_inactive() == 0) {
            result = 2;
            break;
        }
    }
    return result;
}
#pragma pop
}
