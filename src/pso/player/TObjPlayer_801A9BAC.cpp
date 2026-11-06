#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/TUnk_804C349C.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

typedef struct SA9_801a9bac {
    char pad0[0x44];
    s32 f44;
    s32 f48;
    s32 pad4C;
    s32 arr50[4];
    s32 arr60[4];
} SA9_801a9bac;

s32 deliver_photon_blast_results_delayed(void *);
s32 step_photon_blast_sequence(void *);
void *get_player_by_client_id(s32 i);
s32 queue_deferred_photon_blast_support(s32, s32, s32);

void TUnk_804C349C::update_and_destroy() {
    SA9_801a9bac *self = (SA9_801a9bac *)this;
    s32 temp_r0;
    s32 var_r31;
    s32 var_r30;
    s32 j;
    s32 i;
    s32 inner;

    self->f44 += 1;
    if (self->f48 < self->f44) {
        for (j = 0; j < 4; j++) {
            temp_r0 = self->arr50[j];
            if ((temp_r0 == 4) || (temp_r0 == 5)) {
                for (i = 0; i < 4; i++) {
                    inner = self->arr60[i];
                    if ((u32) inner < 4U) {
                        queue_deferred_photon_blast_support(inner, self->arr50[j], 1);
                    }
                }
            }
        }
        deliver_photon_blast_results_delayed(this);
        queue_destruction__7TObjectFv(this);
    }
}

void TUnk_804C349C::run_task() {
    this->m_38 = (s32)get_player_by_client_id(*(u16 *)((s8 *)this + 0x3C));
    if ((s32) this->m_4c != 0) {
        step_photon_blast_sequence(this);
        return;
    }
    update_and_destroy();
}

}
