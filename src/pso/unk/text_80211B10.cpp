#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
TObjPlayer *get_player_by_client_id(s32 id);
s32 check_flag_100__10TObjPlayerFPv(TObjPlayer *player);
f32 xz_distance_squared(const f32 *a, const f32 *b);

s32 TPlayerBattleCtrl4P__sub_80211B10(u16 id) {
    TObjPlayer *self = get_player_by_client_id(id);
    s32 result;
    s32 i;
    s32 j;
    s32 k;
    if (self == NULL) {
        return 1;
    }
    result = 0;
    for (i = 0; i < 4; i++) {
        if (id != i) {
            TObjPlayer *other = get_player_by_client_id(i);
            if (other != NULL && check_flag_100__10TObjPlayerFPv(other) != 0) {
                result = 3;
            }
        }
    }
    for (j = 0; j < 4; j++) {
        if (id != j) {
            TObjPlayer *other = get_player_by_client_id(j);
            if (other != NULL && xz_distance_squared(&self->position.x, &other->position.x) > 22500.0f) {
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
}
