#include "pso/player/TObjPlayer_803130BC.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/player/PhotonBlastRequests.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowCtrl.h"


extern "C" {
// These two register-level calls leave the client ID in the return register or truncate on store.
u32 get_client_id__18PhotonBlastRequestFv(PhotonBlastRequest *request);
void set_client_id__18PhotonBlastRequestFUs(PhotonBlastRequest *request, u32 client_id);
PhotonBlastRequest *TObjPlayer__sub_80312FB0(PhotonBlastRegistry *registry);
void TObjPlayer__sub_80313010(PhotonBlastRequest *slot, u16 id);
}

void release_photon_blast_requests(PhotonBlastRegistry *registry) {
    s32 count;
    saddr i;
    TObjPlayer *owner;
    count = TObjPlayer__sub_803131AC(registry);
    for (i = 0; i < count; i++) {
        u16 player = registry->get_element(i)->get_client_id();
        if (player != 0xFFFF) {
            owner = get_player_by_client_id(player);
            if (owner != NULL) {
                owner->photon_blast_gauge.check_photon_blast_flag();
                owner->photon_blast_gauge.trigger_photon_blast();
            }
        }
    }
}

PhotonBlastRequestSlot *PhotonBlastRegistry::find_by_section_id(u16 section) {
    s32 n;
    saddr i;
    PhotonBlastRequest *slot;
    n = TObjPlayer__sub_803131AC(this);
    for (i = 0; i < n; i++) {
        slot = get_element(i);
        if (section == (u16)slot->get_client_id()) {
            return TObjPlayer__sub_803131B4(slot, 0);
        }
    }
    return 0;
}

void PhotonBlastRegistry::create_party_effects(u16 id) {
    s32 n;
    saddr i;
    u16 sec;
    TObjPlayer *ent;
    PhotonBlastRequest *slot;
    n = TObjPlayer__sub_803131AC(this);
    for (i = 0; i < n; i++) {
        slot = get_element(i);
        sec = slot->get_client_id();
        ent = get_player_by_client_id(sec);
        if (ent != NULL && id != sec && ent->photon_blast_gauge.query_field40() != 0) {
            TWindowCtrl::create_party_effect(id, sec);
            TObjPlayer__sub_80313010(slot, id);
            ent->gain_photon_blast_chain_charge(10.0f);
        }
    }
}

u16 PhotonBlastRegistry::find_first_valid_target_id() {
    s32 n;
    saddr i;
    PhotonBlastRequest *slot;
    TObjPlayer *ent;
    n = TObjPlayer__sub_803131AC(this);
    for (i = 0; i < n; i++) {
        slot = get_element(i);
        ent = get_player_by_client_id((u16)slot->get_client_id());
        if (ent != NULL && ent->photon_blast_gauge.query_field40() != 0) {
            return slot->get_client_id();
        }
    }
    return 0xFFFF;
}

void TObjPlayer__sub_80312E98(PhotonBlastRegistry *registry, s32 id) {
    s32 n = TObjPlayer__sub_803131AC(registry);
    saddr i;
    for (i = 0; i < n; i++) {
        if ((u16)id == (u16)registry->get_element(i)->get_client_id()) {
            registry->process_indexed_element(i);
        }
    }
}

void PhotonBlastRegistry::process_all_elements() {
    int n = TObjPlayer__sub_803131AC(this);
    int i;
    for (i = 0; i < n; i++) {
        process_indexed_element(i);
    }
}

void append_photon_blast_request(PhotonBlastRegistry *registry, u32 type, s16 kind) {
    PhotonBlastRequest *slot = TObjPlayer__sub_80312FB0(registry);
    if (slot != NULL) {
        slot->check_flag_at_4();
        set_client_id__18PhotonBlastRequestFUs(slot, type);
        slot->set_kind(kind);
    }
}

PhotonBlastRequest *TObjPlayer__sub_80312FB0(PhotonBlastRegistry *registry) {
    for (s32 index = 0; index < 4; index++) {
        PhotonBlastRequest *slot = registry->get_element(index);
        if (TObjPlayer__sub_80313218(slot) != 0) {
            return slot;
        }
    }
    return NULL;
}

void TObjPlayer__sub_80313010(PhotonBlastRequest *slot, u16 id) {
    s32 n;
    saddr i;
    PhotonBlastRequestSlot *e;
    n = PhotonBlastRequest::get_max_children(slot);
    for (i = 0; i < n; i++) {
        e = TObjPlayer__sub_803131B4(slot, i);
        if (id == e->get_client_id()) {
            TObjPlayer__sub_80313250(e, 10);
            return;
        }
        if (e->get_client_id() == 0xFFFF) {
            e->set_client_id(id);
            TObjPlayer__sub_80313250(e, 10);
            return;
        }
    }
}
