#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/player/PhotonBlastRequests.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"

void release_photon_blast_requests(PhotonBlastRegistry *registry) {
    s32 count;
    saddr i;
    TObjPlayer *owner;
    count = get_photon_blast_request_count();
    for (i = 0; i < count; i++) {
        u16 client_id = registry->get_element(i)->get_client_id();
        if (client_id != 0xFFFF) {
            owner = get_player_by_client_id(client_id);
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
    PhotonBlastRequest *request;
    n = get_photon_blast_request_count();
    for (i = 0; i < n; i++) {
        request = get_element(i);
        if (section == request->get_client_id()) {
            return request->get_slot(0);
        }
    }
    return 0;
}

void PhotonBlastRegistry::create_party_effects(u16 id) {
    s32 n;
    saddr i;
    u16 client_id;
    TObjPlayer *player;
    PhotonBlastRequest *request;
    n = get_photon_blast_request_count();
    for (i = 0; i < n; i++) {
        request = get_element(i);
        client_id = request->get_client_id();
        player = get_player_by_client_id(client_id);
        if (player != NULL && id != client_id && player->photon_blast_gauge.is_blast_requested() != 0) {
            TWindowCtrl::create_party_effect(id, client_id);
            request->add_donor(id);
            player->gain_photon_blast_chain_charge(10.0f);
        }
    }
}

u16 PhotonBlastRegistry::find_first_valid_target_id() {
    s32 n;
    saddr i;
    PhotonBlastRequest *request;
    TObjPlayer *player;
    n = get_photon_blast_request_count();
    for (i = 0; i < n; i++) {
        request = get_element(i);
        player = get_player_by_client_id(request->get_client_id());
        if (player != NULL && player->photon_blast_gauge.is_blast_requested() != 0) {
            return request->get_client_id();
        }
    }
    return 0xFFFF;
}

void TObjPlayer__sub_80312E98(PhotonBlastRegistry *registry, s32 client_id) {
    s32 n = get_photon_blast_request_count();
    saddr i;
    for (i = 0; i < n; i++) {
        if ((u16)client_id == registry->get_element(i)->get_client_id()) {
            registry->reset_request(i);
        }
    }
}

void PhotonBlastRegistry::process_all_elements() {
    int n = get_photon_blast_request_count();
    int i;
    for (i = 0; i < n; i++) {
        reset_request(i);
    }
}

void append_photon_blast_request(PhotonBlastRegistry *registry, u16 client_id, s16 kind) {
    PhotonBlastRequest *request = find_free_photon_blast_request(registry);
    if (request != NULL) {
        request->mark_in_use();
        request->set_client_id(client_id);
        request->set_kind(kind);
    }
}

PhotonBlastRequest *find_free_photon_blast_request(PhotonBlastRegistry *registry) {
    for (s32 index = 0; index < 4; index++) {
        PhotonBlastRequest *request = registry->get_element(index);
        if (request->is_free() != 0) {
            return request;
        }
    }
    return NULL;
}

void PhotonBlastRequest::add_donor(u16 client_id) {
    s32 n;
    saddr i;
    PhotonBlastRequestSlot *slot;
    n = get_slot_count();
    for (i = 0; i < n; i++) {
        slot = get_slot(i);
        if (client_id == slot->get_client_id()) {
            slot->add_amount(10);
            return;
        }
        if (slot->get_client_id() == 0xFFFF) {
            slot->set_client_id(client_id);
            slot->add_amount(10);
            return;
        }
    }
}

void PhotonBlastRequest::clear_slots() {
    int n = get_slot_count();
    int i;
    for (i = 0; i < n; i++) {
        slots[i].clear();
    }
}

s16 PhotonBlastRequest::get_kind() {
    if ((kind < 0 || kind >= 6) && kind != -1) {
        return 0;
    }
    return kind;
}

void PhotonBlastRequest::reset() {
    client_id = 0xFFFF;
    kind = -1;
    flags.reset();
    clear_slots();
}

int PhotonBlastGauge::is_blast_requested() { return test_flags_any(&flags.bits, 4); }

int get_photon_blast_request_count() { return 4; }

PhotonBlastRequestSlot *PhotonBlastRequest::get_slot(s32 i) { return &slots[i]; }

void PhotonBlastRegistry::reset_request(s32 index) { slots[index].reset(); }

void PhotonBlastRequest::mark_in_use() { flags.set(1); }

int PhotonBlastRequest::is_free() { return test_flags_any(&flags.bits, 1) == 0; }

void PhotonBlastRequestSlot::set_client_id(u16 id) { client_id = id; }

void PhotonBlastRequestSlot::add_amount(s32 n) { amount = amount + n; }

int PhotonBlastRequest::get_slot_count() { return 4; }
