#ifndef PSO_PLAYER_PHOTONBLASTRESULTS_H
#define PSO_PLAYER_PHOTONBLASTRESULTS_H

#include "types.h"
#include "pso/system/data/FlagWord.h"

class TObjBase;
class TUnk_804C349C;
class TObjPlayer;
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
// One flag per client, cleared when results are delivered and on load and release.
extern s32 photon_blast_donation_flags[4];

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
    void set_client_id(u16 id);
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
    void update_children();
    void check_flag_at_4();
    static int get_max_children(const PhotonBlastRequest *request);
    u16 get_client_id();
    s16 get_kind();
    void set_kind(s16 kind);
    void set_client_id(u16 client_id);
    PhotonBlastRequest &operator=(PhotonBlastRequest &other);
};

// How many more donors share each chained kind; admit_photon_blast_sequence
// hands count to TUnk_804C349C.
struct PhotonBlastChainCounts { s32 count[4]; };

// One entry per photon blast; +0x00 is the hit power (queue_photon_blast_hit), +0x12 is read by
// TObjPlayer_801C7430, +0x20 is the effect id start_photon_blast plays.
struct PhotonBlastEntry {
    f32 power;
    f32 pad_04;
    f32 pad_08;
    f32 pad_0c;
    s16 pad_10;
    s16 pad_12;
    s16 pad_14;
    s16 pad_16;
    s32 pad_18;
    s32 pad_1c;
    s16 effect_id;
    s8 pad_22;
    u8 pad_23;
    s32 pad_24;
    s32 pad_28;
};

PhotonBlastEntry *get_photon_blast_entry(int kind);

// One create/release pair per photon blast model: load_photon_blast_resources runs the
// table forwards, release_photon_blast_resources runs it backwards.
struct PhotonBlastLoadCallback {
    void (*load)(void);
    void (*release)(void);
};

// Chains the requests whose players are in self's room into one photon blast
// sequence (a TUnk_804C349C), unless another player's sequence is still running.
void admit_photon_blast_sequence(PhotonBlastRequest *requests, TObjPlayer *self);
void apply_photon_blast_action_hold(TUnk_804C349C *unused, s32 duration, s32 owner_client_id);

// The photon blast entry of the scene load callback table.
void load_photon_blast_resources(void);
void release_photon_blast_resources(void);

extern "C" {
// Copies player's chain into output while it is pending or running; returns its state.
s32 get_photon_blast_chain(PhotonBlastChainCopy *output, s32 player);
}

#endif
