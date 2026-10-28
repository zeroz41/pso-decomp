#include "types.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);

extern s32 collision_body_vtable[];

void *TUnk_804928CC::destroy_enemy_object(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = collision_body_vtable;
        free_collision_body_parts(this);
        __dt__14TObjCollidableFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}
