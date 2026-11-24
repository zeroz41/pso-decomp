#ifndef PSO_UNK_TUNK_804C349C_H
#define PSO_UNK_TUNK_804C349C_H
#include "types.h"
#include "pso/player/PhotonBlastRequests.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include <stddef.h>

class TObjPlayer;
struct PhotonBlastRequest;

// The photon blast sequence task: new'd by
// admit_photon_blast_sequence with the owner's client id, the chained
// players and their counts; run by step_photon_blast_sequence while
// `animated`, else delivered after `delay` frames (update_and_destroy).
class TUnk_804C349C : public TObject {
public:
    TUnk_804C349C(s32 owner_client_id, PhotonBlastRequest *requests, s32 *counts, s32 animated, s32 delay);
    virtual ~TUnk_804C349C();
    f32 calc_photon_blast_power(s32 kind, f32 value);
    void step_photon_blast_sequence();
    void update_and_destroy();
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
LAYOUT_ASSERT(TUnk_804C349C_size, sizeof(TUnk_804C349C) == 0x98);
LAYOUT_ASSERT(PhotonBlastSequenceOwnerOffset, offsetof(TUnk_804C349C, owner) == 0x38);
LAYOUT_ASSERT(PhotonBlastSequenceOwnerClientOffset, offsetof(TUnk_804C349C, owner_client_id) == 0x3C);
LAYOUT_ASSERT(PhotonBlastSequencePowerOffset, offsetof(TUnk_804C349C, power_level) == 0x40);
LAYOUT_ASSERT(PhotonBlastSequenceElapsedOffset, offsetof(TUnk_804C349C, elapsed) == 0x44);
LAYOUT_ASSERT(PhotonBlastSequenceDelayOffset, offsetof(TUnk_804C349C, delay) == 0x48);
LAYOUT_ASSERT(PhotonBlastSequenceAnimatedOffset, offsetof(TUnk_804C349C, animated) == 0x4C);
LAYOUT_ASSERT(PhotonBlastSequenceKindsOffset, offsetof(TUnk_804C349C, kinds) == 0x50);
LAYOUT_ASSERT(PhotonBlastSequenceParticipantsOffset, offsetof(TUnk_804C349C, participants) == 0x60);
LAYOUT_ASSERT(PhotonBlastSequenceLevelsOffset, offsetof(TUnk_804C349C, levels) == 0x70);
LAYOUT_ASSERT(PhotonBlastSequenceRecipientsOffset, offsetof(TUnk_804C349C, recipients) == 0x80);
LAYOUT_ASSERT(PhotonBlastSequenceHoldsOffset, offsetof(TUnk_804C349C, holds) == 0x90);

#endif
