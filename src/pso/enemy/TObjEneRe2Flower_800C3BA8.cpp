#include "types.h"
#include "pso/enemy/TObjEneRe2Flower_800C3BA8.h"
#include "pso/enemy/TObjEneRe2Flower.h"
#include "pso/misc/TLobby.h"

extern "C" {
s32 obj_isState2_324__9TObjCharaFv(void *);
int get_player_data__10TObjPlayerFi(int a0);
s32 is_valid_target__9TObjEneDDFv(void *);
f32 horizontal_distance_squared(void *, void *);
extern const f32 lbl_805D9FF4;

void TObjEneRe2Flower__sub_800C3BA8(void) {  }
u8 *TObjEneRe2Flower::find_target_in_range() {
    s32 n;
    u8 *result;
    u8 *p;
    s32 i;
    result = NULL;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (is_valid_target__9TObjEneDDFv(p) != 0 && obj_isState2_324__9TObjCharaFv(p) == 0) {
            result = p;
            break;
        }
    }
    if (is_valid_target__9TObjEneDDFv(result) != 0 && horizontal_distance_squared((u8 *)&this->position, result + 0x38) < lbl_805D9FF4) {
        return result;
    }
    return NULL;
}

}
