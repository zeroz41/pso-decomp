#include "types.h"
#include "pso/player/TObjPlayer_80126460.h"
#include "pso/item/TItemShootParticle.h"
#include "pso/TObject.h"
#include "pso/item/TUnk_804A2A58.h"

extern "C" {

u32 spawn_shoot_particle__10TObjPlayerFUlllf(void *, s32, s32, f32);
u32 create_shoot_model__10TObjPlayerFUiiif();
int get_player_list__10TObjPlayerFv(void*);
int rotate_matrix_y(void*, void*);

u32 baranz_launcher_create_shot(void *player, s32 arg1, s32 arg2, f32 farg0) {
    u32 temp_r31;
    u32 temp_r30;
    void *temp_r4;

    temp_r31 = create_shoot_model__10TObjPlayerFUiiif();
    temp_r30 = spawn_shoot_particle__10TObjPlayerFUlllf(player, arg1, arg2, farg0);
    if ((temp_r31 != 0U) && (temp_r30 != 0U)) {
        temp_r4 = *(void **)((s8 *)player + 0x188);
        if (temp_r4 != NULL) {
            *(s32 *)((s8 *)temp_r4 + 0) = (s32) (*(s32 *)((s8 *)temp_r4 + 0) & 0xFFFFFFFD);
            *(s32 *)((s8 *)temp_r4 + 0x14) = 0x4000;
        }
        ((TItemShootParticle *)temp_r30)->spawn_slot_emitter(0x1BB, 0);
        ((TObject *)temp_r30)->set_parent((TObject *)temp_r31);
    }
    return temp_r31;
}
}

// Baranz Launcher (inferred)
void TUnk_804A2A58::vfunc_60() { if (get_player_list__10TObjPlayerFv(this) == 1) { rotate_matrix_y((void*)0, *(void* *)&this->unk_1F8); } }
