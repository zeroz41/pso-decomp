#ifndef PSO_PLAYER_TPHOTONBLASTSEQUENCE_H
#define PSO_PLAYER_TPHOTONBLASTSEQUENCE_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

class TObjPlayer;
struct PhotonBlastRequest;

// The photon blast sequence task: new'd by
// admit_photon_blast_sequence with the owner's client id, the chained
// players and their counts; run by step_photon_blast_sequence while
// `animated`, else delivered after `delay` frames (update_and_destroy).
class TPhotonBlastSequence : public TObject {
public:
    TPhotonBlastSequence(s32 owner_client_id, PhotonBlastRequest *requests, s32 *counts, s32 animated, s32 delay);
    virtual ~TPhotonBlastSequence();
    void step_photon_blast_sequence();
    void update_and_destroy();
    f32 calc_photon_blast_power(s32 kind, f32 base_power);
    void deliver_photon_blast_results_animated();
    void deliver_photon_blast_results_delayed();
    virtual void run_task();

    TObject *summon;
    s32 summon_index;
    s32 state;
    s32 summon_count;
    Vec position;
    TObjPlayer *owner;
    u16 owner_client_id;
    s32 power_level;
    s32 elapsed;
    s32 delay;
    s32 animated;
    s32 kinds[4];
    u32 participants[4];
    s32 levels[4];
    u32 recipients[4];
    u16 holds[4];
};
LAYOUT_ASSERT(PhotonBlastSequenceSize, sizeof(TPhotonBlastSequence) == 0x98);

#endif
