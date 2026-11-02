#include "types.h"
#include "pso/player/TUnk_804A1858.h"
#include "pso/items/TItemWeapon.h"
#include "pso/unk/text_80087278.h"
#include "pso/player/TObjPlayer.h"

struct Vec_8012327C { f32 x, y, z; };

extern "C" {
u8 * construct_twin_chakram(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_twin_chakram(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(construct_twin_chakram(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}
void TUnk_804A1858::emit_marker_effects() {
    Vec_8012327C v;
    ((TItemWeapon *)this)->get_joint_position(2, &v);
    v.y -= 15.0f;
    spawn_particle_effect(&v, 0x1d2);
}

}
