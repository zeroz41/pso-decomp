#include "types.h"
#include "pso/unk/TUnk_804C349C.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/render/TFogCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_803130BC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801C7430.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"

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
