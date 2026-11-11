#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/TUnk_804C349C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/render/TFogCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer_803130BC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801C7430.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_801AA3B4.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/player/TObjPlayer_801AC0D8.h"
#include "pso/player/TObjPlayer_801AE48C.h"
#include "pso/player/TObjPlayer_801ACA6C.h"
#include "pso/player/TObjPlayer_801AB608.h"
#include "pso/player/TObjPlayer_801AADE8.h"
#include "pso/effect/photon/TPhotonYoulla.h"
#include "pso/player/TObjPlayer_801ADC6C.h"
#include "pso/player/TObjPlayer_801AD47C.h"
#include "pso/effect/photon/TPhotonRainbow_801AE640.h"
#include "pso/effect/photon/TPhotonLeilla.h"

// One create/release pair per photon blast model: load_photon_blast_resources runs the
// table forwards, TObjPlayer__sub_801AA3B4 runs it backwards (field names inferred).
struct PhotonBlastLoadCallback {
    void (*load)(void);
    void (*release)(void);
};

void TUnk_804C349C::update_and_destroy() {
    s32 kind;
    s32 j;
    s32 i;
    u32 recipient;

    elapsed += 1;
    if (delay < elapsed) {
        for (j = 0; j < 4; j++) {
            kind = kinds[j];
            if (kind == 4 || kind == 5) {
                for (i = 0; i < 4; i++) {
                    recipient = participants[i];
                    if (recipient < 4) {
                        queue_deferred_photon_blast_support(recipient, kinds[j], 1);
                    }
                }
            }
        }
        deliver_photon_blast_results_delayed(this);
        queue_destruction();
    }
}

void TUnk_804C349C::run_task() {
    owner = get_player_by_client_id(owner_client_id);
    if (animated != 0) {
        step_photon_blast_sequence(this);
        return;
    }
    update_and_destroy();
}

extern "C" {
s32 get_photon_blast_chain(PhotonBlastChain *output, s32 player);
}
void reset_cameras_to_actor(void *actor, s32 arg1);

TUnk_804C349C::~TUnk_804C349C() {
    s32 i;
    s32 j;
    if (animated != 0) {
        TLobby::set_and_notify_default();
        release_photon_blast_player_holds(holds);
        if (get_player_by_client_id(local_client_id) != NULL) {
            TLobby__sub_8024AC20(local_client_id);
            TCameraCtrl::release_photon_blast_camera();
            restore_player_cameras();
            reset_cameras_to_actor(get_player_by_client_id(local_client_id), 0);
        }
    } else {
        TFogCtrl::restore_fog_for_player(owner_client_id, 0);
    }
    if (owner_client_id != 0xFFFF && owner_client_id < 4) {
        for (i = 0; i < 4; i++) {
            if (participants[i] < 4) {
                for (j = 0; j < 4; j++) {
                    photon_blast_sequence_table[participants[i]].kinds[j] = -1;
                    photon_blast_sequence_table[participants[i]].participants[j] = 0xFFFF;
                }
                photon_blast_sequence_table[participants[i]].state = 0;
            }
        }
    }
}

TUnk_804C349C::TUnk_804C349C(s32 owner_client_id, u8 *players, s32 *counts, s32 animated, s32 delay)
    : TObject(tl_07) {
    TObjPlayer *player;
    s32 i;
    s32 j;
    u8 *entry;

    this->owner_client_id = owner_client_id;
    this->delay = delay;
    elapsed = 0;
    this->animated = animated;
    for (i = 0; i < 4; i++) {
        levels[i] = counts[i] + 1;
        kinds[i] = -1;
        holds[i] = 0xFFFF;
    }
    power_level = 0;
    player = get_player_by_client_id(owner_client_id);
    if (player != NULL) {
        power_level = player->get_photon_blast_charge();
    }
    for (i = 0; i < 4; i++) {
        participants[i] = 0xFFFF;
    }
    summon_count = 4;
    for (i = 0; i < 4; i++) {
        if (TObjPlayer__sub_80313114(players) == -1) {
            summon_count = i;
            break;
        }
        kinds[i] = TObjPlayer__sub_80313114(players);
        participants[i] = ((TObjPlayer *)players)->get_section_id();
        players += 0x18;
    }
    owner = get_player_by_client_id(owner_client_id);
    apply_photon_blast_action_hold((s32)this, summon_count * 150 + 100, owner_client_id);
    if (this->animated != 0) {
        TLobby::send_neg30();
        TObjPlayer__sub_8024ABDC(local_client_id);
        if (owner != NULL) {
            VecCopy(&position, &owner->position);
            play_sound_effect(0x40021927, &position, 0, 0);
        }
        clear_photon_blast_hits();
    } else {
        clear_deferred_photon_blast_hits();
        TFogCtrl::select_fog_for_viewport(this->owner_client_id, 0x3E, 0);
    }
    for (i = 0; i < 4; i++) {
        if (participants[i] < 4) {
            if (photon_blast_sequence_table[participants[i]].state != 2) {
                for (j = 0; j < 4; j++) {
                    photon_blast_sequence_table[participants[i]].kinds[j] = kinds[j];
                    photon_blast_sequence_table[participants[i]].participants[j] = participants[j];
                }
            }
            photon_blast_sequence_table[participants[i]].state = 2;
        }
    }
    state = 0;
    summon = NULL;
    summon_index = 0;
    for (s32 k = 0; k < 4; k++) {
        recipients[k] = 0xFFFF;
    }
    if (owner != NULL && get_player_by_client_id(local_client_id) != NULL) {
        entry = TObjPlayer::find_photon_blast_by_section_id(get_entity_id(owner));
        if (entry != NULL) {
            for (i = 0; i < 4; i++) {
                if (((TObjPlayer *)entry)->get_entity_type() != 0xFFFF
                    && this->owner_client_id != ((TObjPlayer *)entry)->get_entity_type()) {
                    recipients[i] = ((TObjPlayer *)entry)->get_entity_type();
                }
                entry += 4;
            }
        }
    }
    if (this->animated != 0) {
        player = get_player_by_client_id(this->owner_client_id);
        if (player != NULL) {
            freeze_players_for_photon_blast(player->get_room(), holds);
        }
    }
}
extern "C" {

s32 get_photon_blast_chain(PhotonBlastChain *output, s32 player) {
    s32 i;
    if (photon_blast_sequence_table[player].state == 0) {
        return 0;
    }
    if (photon_blast_sequence_table[player].state == 2) {
        for (i = 0; i < 4; i++) {
            output->kinds[i] = photon_blast_sequence_table[player].kinds[i];
            output->participants[i] = photon_blast_sequence_table[player].participants[i];
        }
        return 2;
    }
    if (photon_blast_sequence_table[player].state == 1) {
        for (i = 0; i < 4; i++) {
            output->kinds[i] = photon_blast_sequence_table[player].kinds[i];
            output->participants[i] = photon_blast_sequence_table[player].participants[i];
        }
        return 1;
    }
    return 0;
}
}

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

void TObjPlayer::start_photon_blast(s32 kind, s32 client_id) {
    TObjPlayer *player;
    PhotonBlastEntry *entry;

    player = get_player_by_client_id(client_id);
    if (player != NULL) {
        entry = (PhotonBlastEntry *)TObjPlayer::get_photon_blast_entry(kind);
        if (TObjPlayer::is_locally_controlled(player) != 0) {
            TObjPlayer::play_effect_default((int)player, entry->effect_id);
        }
        spawn_particle_effect(&player->position, 0x13D);
        TCameraCtrl::set_shake_preset(0);
        switch (kind) {
        case 2:
            new TPhotonMagicSquare(tl_07, 2, client_id);
            break;
        case 3:
            new TPhotonMagicSquare(tl_07, 3, client_id);
            break;
        case 4:
            new TPhotonMagicSquare(tl_07, 4, client_id);
            break;
        case 0:
            new TPhotonMagicSquare(tl_07, 0, client_id);
            break;
        case 1:
            new TPhotonMagicSquare(tl_07, 1, client_id);
            break;
        case 5:
            new TPhotonMagicSquare(tl_07, 5, client_id);
            break;
        }
    }
}

extern "C" {

PhotonBlastEntry photon_blast_entry_table[6] = {
    { 500.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x2AAA, 0x1555, 10, 10, 0, 0, 0 },
    { 350.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x2AAA, 0x1555, 10, 10, 0, 0, 0 },
    { 1200.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x2AAA, 0x1555, 10, 10, 0, 0, 0 },
    { 500.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x2AAA, 0x1555, 10, 10, 0, 0, 0 },
    { 150.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x1555, 0x1555, 10, 10, 0, 0, 0 },
    { 0.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x1555, 0x1555, 10, 10, 0, 0, 0 },
};

}

void *TObjPlayer::get_photon_blast_entry(int kind) {
    return &photon_blast_entry_table[kind];
}

extern char lbl_80446A78[];
extern char lbl_80446A88[];
extern char lbl_80446A98[];
extern char lbl_80446AAC[];
extern char lbl_80446ABC[];
extern char lbl_80446ACC[];
extern char lbl_80446AE0[];
extern char lbl_80446AF4[];
extern char lbl_80446B08[];
extern char lbl_80446B1C[];
extern char lbl_80446B30[];
extern char lbl_80446B44[];
extern char lbl_80446B58[];
extern char lbl_80446B68[];
extern char lbl_80446B78[];
extern char lbl_80446B8C[];
extern char lbl_80446BA4[];
extern char lbl_80446BBC[];
extern char lbl_80446BD4[];
extern char lbl_80446BE8[];
extern char lbl_80446C00[];
extern char lbl_80446C18[];
extern char lbl_80446C30[];
extern char lbl_80446C44[];
extern char lbl_80446C58[];
extern char lbl_80446C74[];
extern char lbl_80446C90[];
extern char lbl_80446CAC[];
extern const char *pm_mdl_model_names[13];
extern const char *pm_mdl_motion_names[16];
extern BmlResourceDescriptor photon_blast_resource_descriptor;

extern "C" {
void free_bin_model_request(u32, int);
void call_funcs_reverse__6TLobbyFPvUi(void *, int);
extern PhotonBlastLoadCallback photon_blast_load_callback_table[10];
extern u32 photon_blast_donation_flags[];
extern u32 photon_blast_shared_resource;
u8 *load_resource_from_descriptor(u8 *, int, void *, int, int, int);
s32 run_load_callback_table(void *, int);
void TObjPlayer__sub_801AA3B4(void) {
    s32 i;
    call_funcs_reverse__6TLobbyFPvUi(photon_blast_load_callback_table, 0x50);
    if (photon_blast_shared_resource != 0U) {
        free_bin_model_request(photon_blast_shared_resource, 1);
        photon_blast_shared_resource = 0U;
    }
    for (i = 0; i < 4; i++) {
        photon_blast_donation_flags[i] = 0;
    }
    TObjPlayer::clear_photon_blast_slots();
}
void TObjPlayer::clear_photon_blast_slots() {
    s32 i;
    s32 j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            photon_blast_sequence_table[i].kinds[j] = -1;
            photon_blast_sequence_table[i].participants[j] = 0xFFFF;
        }
        photon_blast_sequence_table[i].state = 0;
    }
}
}
void load_photon_blast_resources(void) {
    u8 *p;
    s32 i;
    p = (u8 *)::operator new(0x440);
    if (p != NULL) {
        p = load_resource_from_descriptor(p, 1, &photon_blast_resource_descriptor, 0, 0, 0);
    }
    photon_blast_shared_resource = (u32) p;
    run_load_callback_table(photon_blast_load_callback_table, 0x50);
    for (i = 0; i < 4; i++) {
        photon_blast_donation_flags[i] = 0;
    }
    TObjPlayer::clear_photon_blast_slots();
}
extern "C" {

__declspec(section ".data") const char *pm_mdl_model_names[13] = { lbl_80446A78, lbl_80446A88, lbl_80446A98, lbl_80446AAC, lbl_80446ABC, lbl_80446ACC, lbl_80446AE0, lbl_80446AF4, lbl_80446B08, lbl_80446B1C, lbl_80446B30, lbl_80446B44, NULL };
__declspec(section ".data") const char *pm_mdl_motion_names[16] = { lbl_80446B58, lbl_80446B68, lbl_80446B78, lbl_80446B8C, lbl_80446BA4, lbl_80446BBC, lbl_80446BD4, lbl_80446BE8, lbl_80446C00, lbl_80446C18, lbl_80446C30, lbl_80446C44, lbl_80446C58, lbl_80446C74, lbl_80446C90, NULL };
}
BmlResourceDescriptor photon_blast_resource_descriptor = { lbl_80446CAC, pm_mdl_model_names, pm_mdl_motion_names, 12, 15 };

PhotonBlastLoadCallback photon_blast_load_callback_table[10] = {
    { create_golla_photon_blast_model, TObjPlayer::destroy_static_buffer_pair },
    { create_pilla_photon_blast_model, TObjPlayer::free_buffer_pair },
    { create_leilla_photon_blast_model, TObjPlayer::destroy_buffer_pair_instance },
    { create_farlla_photon_blast_model, TObjPlayer::destroy_buffers },
    { create_estlla_photon_blast_model, TObjPlayer::destroy_global_buffer },
    { TObjPlayer__sub_801AEB80, TObjPlayer__sub_801AEB74 },
    { TObjPlayer__sub_801ADC78, TObjPlayer__sub_801ADC6C },
    { TObjPlayer__sub_801AD480, TObjPlayer__sub_801AD47C },
    { TObjPlayer__sub_801AE728, TObjPlayer__sub_801AE724 },
    { TObjPlayer__sub_801AC440, TObjPlayer__sub_801AC43C },
};
