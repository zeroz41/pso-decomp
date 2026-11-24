#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"

// TObjPlayer seen through vtable slot 75 (gain_photon_blast_chain_charge),
// which takes the charge in f1 but TObjChara declares without parameters.
struct B_80312D4C { char pad[0x18]; };

struct Ply_80312D4C : B_80312D4C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39(); virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59(); virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(f32);
};

extern "C" {
void append_photon_blast_request(void *requests, u16 client_id, s16 kind);
void TObjPlayer__sub_80312E98(void *requests, u16 client_id);
}

void release_photon_blast_requests(void *requests) {
    s32 count;
    saddr i;
    TObjPlayer *owner;
    count = get_photon_blast_request_count();
    for (i = 0; i < count; i++) {
        u16 client_id = TObjPlayer::get_element(requests, i)->get_client_id();
        if (client_id != 0xFFFF) {
            owner = get_player_by_client_id(client_id);
            if (owner != NULL) {
                owner->photon_blast_gauge.check_photon_blast_flag();
                owner->photon_blast_gauge.trigger_photon_blast();
            }
        }
    }
}

void *TObjPlayer::find_by_section_id(u16 section) {
    s32 n;
    saddr i;
    PhotonBlastRequest *request;
    n = get_photon_blast_request_count();
    for (i = 0; i < n; i++) {
        request = TObjPlayer::get_element(this, i);
        if (section == request->get_client_id()) {
            return request->get_slot(0);
        }
    }
    return 0;
}

void TObjPlayer::create_party_effects(u16 id) {
    s32 n;
    saddr i;
    u16 client_id;
    Ply_80312D4C *player;
    PhotonBlastRequest *request;
    n = get_photon_blast_request_count();
    for (i = 0; i < n; i++) {
        request = TObjPlayer::get_element(this, i);
        client_id = request->get_client_id();
        player = (Ply_80312D4C *)get_player_by_client_id(client_id);
        if (player != NULL && id != client_id && ((TObjPlayer *)player)->photon_blast_gauge.is_blast_requested() != 0) {
            TWindowCtrl::create_party_effect(id, client_id);
            request->add_donor(id);
            player->m75(10.0f);
        }
    }
}

u16 TObjPlayer::find_first_valid_target_id() {
    s32 n;
    saddr i;
    PhotonBlastRequest *request;
    TObjPlayer *player;
    n = get_photon_blast_request_count();
    for (i = 0; i < n; i++) {
        request = TObjPlayer::get_element(this, i);
        player = get_player_by_client_id(request->get_client_id());
        if (player != NULL && player->photon_blast_gauge.is_blast_requested() != 0) {
            return request->get_client_id();
        }
    }
    return 0xFFFF;
}

void TObjPlayer__sub_80312E98(void *requests, u16 client_id) {
    s32 n = get_photon_blast_request_count();
    saddr i;
    for (i = 0; i < n; i++) {
        if (client_id == TObjPlayer::get_element(requests, i)->get_client_id()) {
            reset_photon_blast_request(requests, i);
        }
    }
}

void TObjPlayer::process_all_elements() {
    int n = get_photon_blast_request_count();
    int i;
    for (i = 0; i < n; i++) {
        reset_photon_blast_request(this, i);
    }
}

void append_photon_blast_request(void *requests, u16 client_id, s16 kind) {
    PhotonBlastRequest *request = find_free_photon_blast_request(requests);
    if (request != NULL) {
        request->mark_in_use();
        request->set_client_id(client_id);
        request->set_kind(kind);
    }
}

PhotonBlastRequest *find_free_photon_blast_request(void *requests) {
    s32 i;
    PhotonBlastRequest *request;
    i = 0;
loop:
    request = TObjPlayer::get_element(requests, i);
    if (request->is_free() != 0) {
        return request;
    }
    i += 1;
    if (i >= 4) {
        return NULL;
    }
    goto loop;
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

void reset_photon_blast_request(void *requests, s32 index) {
    static_cast<PhotonBlastRequest *>(requests)[index].reset();
}

void PhotonBlastRequest::mark_in_use() { flags.set(1); }

int PhotonBlastRequest::is_free() { return test_flags_any(&flags.bits, 1) == 0; }

void PhotonBlastRequestSlot::set_client_id(u16 id) { client_id = id; }

void PhotonBlastRequestSlot::add_amount(s32 n) { amount = amount + n; }

int PhotonBlastRequest::get_slot_count() { return 4; }
