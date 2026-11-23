#ifndef PSO_UNK_TUNK_804C349C_H
#define PSO_UNK_TUNK_804C349C_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

class TObjPlayer;
struct PhotonBlastRequest;

// The photon blast sequence task (vtable 0x804C349C): new'd by
// admit_photon_blast_sequence with the owner's client id, the chained
// players and their counts; run by step_photon_blast_sequence__13TUnk_804C349CFv while
// `animated`, else delivered after `delay` frames (update_and_destroy).
// Field names are inferred from the functions that use them.
class TUnk_804C349C : public TObject {
public:
    TUnk_804C349C(s32 owner_client_id, PhotonBlastRequest *requests, s32 *counts, s32 animated, s32 delay);
    virtual ~TUnk_804C349C();
    void step_photon_blast_sequence();
    void update_and_destroy();
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

#endif
