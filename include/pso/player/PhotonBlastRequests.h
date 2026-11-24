#ifndef PSO_PLAYER_PHOTONBLASTREQUESTS_H
#define PSO_PLAYER_PHOTONBLASTREQUESTS_H

#include "pso/player/PhotonBlastResults.h"
#include <stddef.h>

struct PhotonBlastRegistry {
    PhotonBlastRegistry();
    ~PhotonBlastRegistry();

    PhotonBlastRequest *get_element(s32 index);
    PhotonBlastRequestSlot *find_by_section_id(u16 section);
    void create_party_effects(u16 id);
    u16 find_first_valid_target_id();
    void process_all_elements();
    void process_indexed_element(s32 index);

    PhotonBlastRequest slots[4];
};

LAYOUT_ASSERT(PhotonBlastRequestSlotSize, sizeof(PhotonBlastRequestSlot) == 0x4);
LAYOUT_ASSERT(PhotonBlastRequestSize, sizeof(PhotonBlastRequest) == 0x18);
LAYOUT_ASSERT(PhotonBlastRequestFlagOffset, offsetof(PhotonBlastRequest, flags) == 4);
LAYOUT_ASSERT(PhotonBlastRequestSlotsOffset, offsetof(PhotonBlastRequest, slots) == 8);
LAYOUT_ASSERT(PhotonBlastRegistrySize, sizeof(PhotonBlastRegistry) == 0x60);

extern PhotonBlastRegistry *TObjPlayer__shared_photon_blast_state;
void release_photon_blast_requests(PhotonBlastRegistry *registry);

extern "C" {
void append_photon_blast_request(PhotonBlastRegistry *registry, u32 type, s16 kind);
void TObjPlayer__sub_80312E98(PhotonBlastRegistry *registry, s32 id);
}

#endif
