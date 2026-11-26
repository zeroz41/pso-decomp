#ifndef PSO_PLAYER_PHOTONBLASTREQUESTS_H
#define PSO_PLAYER_PHOTONBLASTREQUESTS_H

#include "pso/player/PhotonBlastResults.h"
#include <stddef.h>

// Every player's pending photon blast, one request per client; TObjPlayer::alloc_shared_buffers
// creates it and TObjPlayer::free_shared_data deletes it.
struct PhotonBlastRegistry {
    PhotonBlastRegistry();
    ~PhotonBlastRegistry();

    PhotonBlastRequest *get_element(s32 index);
    // The first donor slot of section's request, NULL when no request is from section.
    PhotonBlastRequestSlot *find_by_section_id(u16 section);
    // Donates id's charge to every other player whose blast is requested.
    void create_party_effects(u16 id);
    u16 find_first_valid_target_id();
    void process_all_elements();
    void reset_request(s32 index);
    // Inferred: resets every request from client_id.
    void sub_80312E98(s32 client_id);

    PhotonBlastRequest slots[4];
};

LAYOUT_ASSERT(PhotonBlastRequestSlotSize, sizeof(PhotonBlastRequestSlot) == 0x4);
LAYOUT_ASSERT(PhotonBlastRequestSize, sizeof(PhotonBlastRequest) == 0x18);
LAYOUT_ASSERT(PhotonBlastRequestFlagOffset, offsetof(PhotonBlastRequest, flags) == 4);
LAYOUT_ASSERT(PhotonBlastRequestSlotsOffset, offsetof(PhotonBlastRequest, slots) == 8);
LAYOUT_ASSERT(PhotonBlastRegistrySize, sizeof(PhotonBlastRegistry) == 0x60);

// The four requests (TObjPlayer::shared_photon_blast_state).
int get_photon_blast_request_count();
// The first request not in use, NULL when all four are.
PhotonBlastRequest *find_free_photon_blast_request(PhotonBlastRegistry *registry);
// Clears flag 4 and sets flag 8 on the photon blast gauge of each requesting player.
void release_photon_blast_requests(PhotonBlastRegistry *registry);

void append_photon_blast_request(PhotonBlastRegistry *registry, u16 client_id, s16 kind);

#endif
