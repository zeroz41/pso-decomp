#ifndef PSO_PLAYER_PHOTONBLASTRESULTS_H
#define PSO_PLAYER_PHOTONBLASTRESULTS_H

#include "types.h"

class TUnk_804C349C;

// One player's photon blast chain (photon_blast_sequence_table, one per
// client): the chained kinds and participants and its state (0 none,
// 1 pending, 2 running; see get_photon_blast_chain).
struct PhotonBlastChain {
    s32 kinds[4];
    u32 participants[4];
    s32 state;
};

extern PhotonBlastChain photon_blast_sequence_table[4];

void apply_photon_blast_action_hold(s32 arg0, s32 arg1, s32 arg2);

extern "C" {
void deliver_photon_blast_results_animated(TUnk_804C349C *seq);
void deliver_photon_blast_results_delayed(TUnk_804C349C *seq);
void step_photon_blast_sequence(TUnk_804C349C *seq);
}

#endif
