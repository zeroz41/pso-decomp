#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
int get_player_data__10TObjPlayerFi(int a0);
u16 get_entity_id(void *);
s32 get_current_floor();
f32 horizontal_distance_squared(void *, void *);
extern s32 lbl_805D586C;
s32 is_any_player_within_radius_xz(u8 *self, f32 radius);
s32 is_any_player_within_radius_xz(u8 *self, f32 radius) {
    u16 slot;
    u8 *player;
    for (slot = 0; (s32) slot < lbl_805D586C; slot++) {
        player = (u8 *)get_player_data__10TObjPlayerFi(slot);
        if (player != NULL && get_entity_id(player) < 0x1000) {
            if (((TObjPlayer *)player)->get_field_3e4() == get_current_floor() && horizontal_distance_squared(self + 0x38, player + 0x38) < radius) {
                return 1;
            }
        }
    }
    return 0;
}

}
