#ifndef PSO_PLAYER_PHOTONBLASTRESULTS_H
#define PSO_PLAYER_PHOTONBLASTRESULTS_H

#include "types.h"
#include "pso/system/data/FlagWord.h"

class TObjBase;
class TPhotonBlastSequence;
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
    void add_amount(s32 n);
    PhotonBlastRequestSlot &operator=(PhotonBlastRequestSlot &other);
};

// A player's pending photon blast: who fires it, which blast, and the
// players who donated to it. admit_photon_blast_sequence chains these
// into a TPhotonBlastSequence.
struct PhotonBlastRequest {
    u16 client_id;  // the player firing it, 0xFFFF while unused
    s16 kind;       // photon blast kind, -1 for none
    FlagWord flags; // bit 0: in use
    PhotonBlastRequestSlot slots[4];

    PhotonBlastRequest();
    ~PhotonBlastRequest();
    void reset();
    u16 get_client_id();
    s16 get_kind();
    void set_kind(s16 kind);
    void set_client_id(u16 client_id);
    PhotonBlastRequest &operator=(PhotonBlastRequest &other);
    // Frees every donor slot.
    void clear_slots();
    int get_slot_count();
    PhotonBlastRequestSlot *get_slot(s32 i);
    void mark_in_use();
    int is_free();
    // Adds 10 to client_id's slot, claiming a free slot on its first donation.
    void add_donor(u16 client_id);
};

// How many more donors share each chained kind; admit_photon_blast_sequence
// hands count to TPhotonBlastSequence.
struct PhotonBlastChainCounts { s32 count[4]; };

// One entry per photon blast; +0x00 is the hit power (queue_photon_blast_hit), +0x12 is read by
// TObjPlayerActions.cpp, +0x20 is the effect id start_photon_blast plays.
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

// Chains the requests whose players are in owner's room into one photon blast
// sequence (a TPhotonBlastSequence), unless another player's sequence is still running.
void admit_photon_blast_sequence(PhotonBlastRequest *requests, TObjPlayer *owner);
void apply_photon_blast_action_hold(TPhotonBlastSequence *unused, s32 duration, s32 owner_client_id);

// The photon blast entry of the scene load callback table.
void load_photon_blast_resources(void);
void release_photon_blast_resources(void);

// Copies player's chain into output while it is pending or running; returns its state.
s32 get_photon_blast_chain(PhotonBlastChainCopy *output, s32 player);

#endif
