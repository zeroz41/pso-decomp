#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/TUnk_804C349C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/PhotonBlastResults.h"

extern "C" {
s32 queue_deferred_photon_blast_support(s32, s32, s32);
}

void TUnk_804C349C::update_and_destroy() {
    s32 kind;
    s32 j;
    s32 i;
    u32 recipient;

    elapsed += 1;
    if (delay < elapsed) {
        for (j = 0; j < 4; j++) {
            kind = kinds[j];
            if (kind == 4 || kind == 5) {
                for (i = 0; i < 4; i++) {
                    recipient = participants[i];
                    if (recipient < 4) {
                        queue_deferred_photon_blast_support(recipient, kinds[j], 1);
                    }
                }
            }
        }
        deliver_photon_blast_results_delayed(this);
        queue_destruction();
    }
}

void TUnk_804C349C::run_task() {
    owner = get_player_by_client_id(owner_client_id);
    if (animated != 0) {
        step_photon_blast_sequence(this);
        return;
    }
    update_and_destroy();
}
