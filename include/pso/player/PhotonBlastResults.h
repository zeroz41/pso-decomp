#ifndef PSO_PLAYER_PHOTONBLASTRESULTS_H
#define PSO_PLAYER_PHOTONBLASTRESULTS_H

#include "types.h"
#include "pso/system/data/FlagWord.h"

class TUnk_804C349C;
struct BmlResource;

// The models, textures and motions every photon blast summon draws from.
extern BmlResource *photon_blast_shared_resource;

// One player's photon blast chain (photon_blast_sequence_table, one per
// client): the chained kinds and participants and its state (0 none,
// 1 pending, 2 running; see get_photon_blast_chain).
struct PhotonBlastChain {
    s32 kinds[4];
    u32 participants[4];
    s32 state;
};

extern PhotonBlastChain photon_blast_sequence_table[4];

// What get_photon_blast_chain copies out of a chain: its kinds and
// participants, without the state (callers pass a 0x20-byte buffer).
struct PhotonBlastChainCopy {
    s32 kinds[4];
    u32 participants[4];
};

// One player who chipped in to a photon blast request: append_photon_blast_request
// claims a free slot for them and adds 10 to amount on each donation.
struct PhotonBlastRequestSlot {
    u16 client_id;  // 0xFFFF while free
    s16 amount;

    PhotonBlastRequestSlot();
    ~PhotonBlastRequestSlot();
    void clear();
    u16 get_client_id();
    PhotonBlastRequestSlot &operator=(PhotonBlastRequestSlot &other);
};

// A player's pending photon blast: who fires it, which blast, and the
// players who donated to it. admit_photon_blast_sequence chains these
// into a TUnk_804C349C.
struct PhotonBlastRequest {
    u16 client_id;  // the player firing it, 0xFFFF while unused
    s16 kind;       // photon blast kind, -1 for none
    FlagWord flags; // bit 0: in use
    PhotonBlastRequestSlot slots[4];

    PhotonBlastRequest();
    ~PhotonBlastRequest();
    void reset();
    u16 get_client_id();
    void set_kind(s16 kind);
    void set_client_id(u16 client_id);
    PhotonBlastRequest &operator=(PhotonBlastRequest &other);
};

// Chains the requests whose players are in self's room into one photon blast
// sequence (a TUnk_804C349C), unless another player's sequence is still running.
void admit_photon_blast_sequence(PhotonBlastRequest *requests, void *self);
void apply_photon_blast_action_hold(s32 arg0, s32 arg1, s32 owner_client_id);

extern "C" {
// Copies player's chain into output while it is pending or running; returns its state.
s32 get_photon_blast_chain(PhotonBlastChainCopy *output, s32 player);
void deliver_photon_blast_results_animated(TUnk_804C349C *seq);
void deliver_photon_blast_results_delayed(TUnk_804C349C *seq);
void step_photon_blast_sequence__13TUnk_804C349CFv(TUnk_804C349C *seq);
}

#endif
