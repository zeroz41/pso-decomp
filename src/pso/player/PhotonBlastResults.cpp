#include "pso/player/PhotonBlastRequests.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/PlayerSlots.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/BmlResource.h"
#include "pso/item/mag/TItemMag.h"
#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/effect/photon/PhotonBlastSummon.h"
#include "pso/system/vector.h"
#include "pso/effect/photon/TPhotonEstlla.h"
#include "pso/effect/photon/TPhotonPilla.h"
#include "pso/effect/photon/TPhotonFarlla.h"
#include "pso/effect/photon/TPhotonGolla.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/TUnk_804C349C.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/TFogCtrl.h"
#include "pso/player/TObjPlayer_803130BC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801C7430.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/player/TObjPlayer_801AC0D8.h"
#include "pso/effect/photon/TPhotonYoulla.h"
#include "pso/effect/photon/TPhotonMylla.h"
#include "pso/player/TObjPlayer_801AD47C.h"
#include "pso/effect/photon/TPhotonRainbow.h"
#include "pso/effect/photon/TPhotonLeilla.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/area/AreaScene.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/PlayerSlots.h"


#define TOBJECT_OUT_OF_LINE_HELPERS


PhotonBlastEntry photon_blast_entry_table[6] = {
    { 500.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x2AAA, 0x1555, 10, 10, 0, 0, 0 },
    { 350.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x2AAA, 0x1555, 10, 10, 0, 0, 0 },
    { 1200.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x2AAA, 0x1555, 10, 10, 0, 0, 0 },
    { 500.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x2AAA, 0x1555, 10, 10, 0, 0, 0 },
    { 150.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x1555, 0x1555, 10, 10, 0, 0, 0 },
    { 0.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x1555, 0x1555, 10, 10, 0, 0, 0 },
};

const char *pm_mdl_model_names[13] = {
    "farlla_body.nj",
    "leilla_body.nj",
    "mahoujin_base.nj",
    "pm1_s_body.nj",
    "pm2_s_body.nj",
    "pmback_s_niji.nj",
    "pmback_s_niji2.nj",
    "pmback_s_nijia.nj",
    "pmback_s_nijia2.nj",
    "pm_b_estlla_body.nj",
    "pm_b_mylla_body.nj",
    "pm_b_youlla_body.nj",
    NULL,
};
const char *pm_mdl_motion_names[16] = {
    "farlla_body.njm",
    "leilla_body.njm",
    "mahoujin_base.njm",
    "pm1cam_pm1_s_body.njm",
    "pm2cam_pm2_s_body.njm",
    "pm_b_estlla_body.njm",
    "pm_b_mylla_body.njm",
    "pm_b_youlla_body.njm",
    "wait_farlla_body.njm",
    "wait_leilla_body.njm",
    "wait_pm1_s_body.njm",
    "wait_pm2_s_body.njm",
    "wait_pm_b_estlla_body.njm",
    "wait_pm_b_mylla_body.njm",
    "wait_pm_b_youlla_body.njm",
    NULL,
};


BmlResourceDescriptor photon_blast_resource_descriptor = { "pm_mdl.bml", pm_mdl_model_names, pm_mdl_motion_names, 12, 15 };

const PhotonBlastChainCounts photon_blast_result_counts_init = { 0, 0, 0, 0 };

#pragma push
#pragma fp_contract on

f32 TUnk_804C349C::calc_photon_blast_power(s32 kind, f32 base_power) {
    f32 power;
    TItemMag *mag;
    power = 0.0f;
    if (owner != NULL) {
        mag = (TItemMag *)owner->activate_d04_slot();
        if (mag != 0) {
            switch (kind) {
            case 0:
                power = base_power + ((2.5f * (f32)mag->get_iq()) + 0.025f * (f32)(mag->get_synchro() * (owner->get_atp() + owner->get_actor_attack_params_atp_min())));
                break;
            case 1:
                power = base_power + ((15.0f * (f32)mag->get_iq()) + 0.15f * (f32)(owner->get_evp() * mag->get_synchro()));
                break;
            case 2:
                power = base_power + ((7.5f * (f32)mag->get_iq()) + 0.075f * (f32)(mag->get_synchro() * (owner->get_atp() + owner->get_actor_attack_params_atp_min())));
                break;
            case 3:
                power = base_power + ((7.5f * (f32)mag->get_iq()) + 0.075f * (f32)(owner->get_ata() * mag->get_synchro()));
                break;
            case 4:
                power = (0.5f * (f32)mag->get_iq()) + base_power;
                break;
            case 5:
                power = 0.1f * (f32)mag->get_iq();
                if (power >= 20.0f) {
                    power = 20.0f;
                }
                break;
            }
        }
    }
    return power;
}
#pragma pop

s32 TObjPlayer::is_any_teammate_in_state() {
    PhotonBlastChainCopy chain;
    s32 floor;
    s32 client;

    floor = get_current_floor();
    for (client = 0; client < 4; client++) {
        TObjPlayer *player = get_player_by_client_id(client);
        if (player != NULL && floor == player->get_floor() && get_photon_blast_chain(&chain, client) == 2) {
            return 1;
        }
    }
    return 0;
}

s32 is_photon_blast_presentation_admitted(u32 owner_id, PhotonBlastRequest *requests) {
    TObjPlayer *local;
    TObjPlayer *owner;
    s32 room;
    if (is_split_screen() != 0) {
        return 1;
    }
    if (local_client_id == requests->get_client_id()) {
        return 1;
    }
    local = get_player_by_client_id(local_client_id);
    if (local == NULL) {
        return 0;
    }
    room = local->get_room();
    owner = get_player_by_client_id(owner_id);
    if (owner != NULL) {
        if (local->get_floor() == owner->get_floor() && room == owner->get_room()) {
            return 1;
        }
    }
    return 0;
}

void apply_photon_blast_action_hold(TUnk_804C349C *unused, s32 duration, s32 owner_client_id) {
    TObjPlayer *player;
    TObjCollidable *owner;
    s32 i;
    DirectAttackPayload hold1;
    DirectAttackPayload hold2;

    owner = find_entity_by_id(owner_client_id);
    for (i = TLobby::get_game_mode(); i < TLobby::get_game_mode() + TObjEneDD::get_enemy_count(); i++) {
        player = TObjPlayer::get_player_data(i);
        if (player != NULL && !(player->actorFlags & 0x40000000)) {
            if (is_split_screen() != 0) {
                hold1.power = (f32)duration;
                hold1.kind = 0x14;
                player->receive_direct_attack(owner, hold1, NULL, -1, -1);
            } else if (player->room == ((TObjBase *)owner)->get_room()) {
                hold2.power = (f32)duration;
                hold2.kind = 0x14;
                player->receive_direct_attack(owner, hold2, NULL, -1, -1);
            }
        }
    }
}

void clear_photon_blast_donations(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        photon_blast_donation_flags[i] = 0;
    }
}
void admit_photon_blast_sequence(PhotonBlastRequest *requests, TObjPlayer *self) {
    PhotonBlastRequest a[4];
    PhotonBlastRequest b[4];
    s32 n;
    s32 j;
    s32 k;
    s32 flag;
    s32 delay;
    TObjPlayer *p;
    s32 i;
    s32 idx;
    s32 m;
    TObjPlayer *q;
    PhotonBlastChainCounts counts = photon_blast_result_counts_init;
    for (n = 0; n < 4; n++) {
        b[n].set_client_id(0xFFFF);
        b[n].set_kind(-1);
    }
    n = 0;
    k = 0;
    for (j = 0; j < 4; j++, requests++) {
        p = get_player_by_client_id(requests->get_client_id());
        if (p != NULL && p->get_room() == self->get_room()
            && requests->get_kind() != -1) {
            a[n].set_client_id(requests->get_client_id());
            a[n].set_kind(requests->get_kind());
            n++;
        }
    }
    for (i = n; i < 4; i++) {
        a[i].set_client_id(0xFFFF);
        a[i].set_kind(-1);
    }
    for (m = 0; m < 4; m++) {
        if (m != 0) {
            if (a[m].get_kind() != -1) {
                if (b[k].get_kind() == a[m].get_kind()) {
                    counts.count[k]++;
                } else {
                    k++;
                }
            } else {
                k++;
            }
        }
        b[k] = a[m];
    }
    flag = 0;
    for (i = 0; i < 4; i++) {
        if (i != self->get_entity_id()) {
            q = get_player_by_client_id(i);
            if (q != NULL && q->get_room() == self->get_room()
                && photon_blast_sequence_table[q->get_entity_id()].state != 0) {
                flag = 1;
            }
        }
    }
    if (flag != 0) {
        return;
    }
    if (is_photon_blast_presentation_admitted(self->get_entity_id(), b) != 0) {
        new TUnk_804C349C(self->get_entity_id(), b, counts.count, 1, 0);
    } else {
        idx = 0;
        for (i = 0; i < 4; i++) {
            if (b[i].get_kind() == -1) {
                idx = i;
                break;
            }
        }
        delay = idx * 150 + 100;
        new TUnk_804C349C(self->get_entity_id(), b, counts.count, 0, delay);
    }
}

void TUnk_804C349C::deliver_photon_blast_results_animated() {
    s32 i;
    for (i = 0; i < photon_blast_hit_count; i++) {
        TObjChara *target = (TObjChara *)find_entity_by_id(photon_blast_hit_queue[i].identity);
        if (target != NULL) {
            DirectAttackPayload payload;
            f32 power = calc_photon_blast_power(photon_blast_hit_queue[i].kind, photon_blast_hit_queue[i].value);
            payload.power = power * (0.01 * (power_level * summon_count));
            if (photon_blast_hit_queue[i].kind == 4) {
                payload.kind = 6;
                for (s32 j = 0; j < 4; j++) {
                    TObjPlayer *player = get_player_by_client_id(recipients[j]);
                    if (player != NULL) {
                        player->receive_direct_attack(owner, payload, NULL, -1, -1);
                        TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&player->body_center, 0x1F8, 0x10);
                        if (aura != NULL) {
                            aura->set_owner_id(player->get_entity_id());
                        }
                    }
                }
                if (local_client_id == target->get_entity_id()) {
                    play_sound_effect(0x4002AB0E, NULL, 0, 0);
                }
                target->receive_direct_attack(owner, payload, NULL, -1, -1);
                TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->body_center, 0x1F8, 0x10);
                if (aura != NULL) {
                    aura->set_owner_id(target->get_entity_id());
                }
                TParticleCtrl *effect = spawn_particle_effect_with_flags(&target->position, 0x16C, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(target->get_entity_id());
                }
                effect = spawn_particle_effect_with_flags(&target->position, 0x16D, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(target->get_entity_id());
                }
            } else if (photon_blast_hit_queue[i].kind == 5) {
                for (s32 j = 0; j < 4; j++) {
                    payload.kind = 7;
                    TObjPlayer *player = get_player_by_client_id(recipients[j]);
                    if (player != NULL) {
                        if (player->actorFlags & 0x800) {
                            payload.kind = 8;
                        }
                        player->receive_direct_attack(owner, payload, NULL, -1, -1);
                        TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&player->body_center, 0x1F8, 0x10);
                        if (aura != NULL) {
                            aura->set_owner_id(player->get_entity_id());
                        }
                    }
                }
                payload.kind = 7;
                if (target->actorFlags & 0x800) {
                    payload.kind = 8;
                }
                target->receive_direct_attack(owner, payload, NULL, -1, -1);
                TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->body_center, 0x1F8, 0x10);
                if (aura != NULL) {
                    aura->set_owner_id(target->get_entity_id());
                }
                payload.kind = 10;
                for (s32 j = 0; j < 4; j++) {
                    TObjPlayer *player = get_player_by_client_id(recipients[j]);
                    if (player != NULL) {
                        player->receive_direct_attack(owner, payload, NULL, -1, -1);
                    }
                }
                target->receive_direct_attack(owner, payload, NULL, -1, -1);
                payload.kind = 9;
                for (s32 j = 0; j < 4; j++) {
                    TObjPlayer *player = get_player_by_client_id(recipients[j]);
                    if (player != NULL) {
                        player->receive_direct_attack(owner, payload, NULL, -1, -1);
                    }
                }
                target->receive_direct_attack(owner, payload, NULL, -1, -1);
                if (local_client_id == target->get_entity_id()) {
                    play_sound_effect(0x4002AB10, NULL, 0, 0);
                    play_sound_effect(0x4002AD14, NULL, 0, 0);
                    play_sound_effect(0x4002AA16, NULL, 0, 0);
                }
                TParticleCtrl *effect = create_timed_particle_emitter_with_flags(&target->position, 0x16E, 0, 0xF, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(target->get_entity_id());
                }
                effect = spawn_particle_effect_with_flags(&target->position, 0x16F, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(target->get_entity_id());
                }
            } else {
                payload.kind = 4;
                target->receive_direct_attack(owner, payload, NULL, -1, -1);
            }
        }
    }
    clear_photon_blast_donations();
}

void TUnk_804C349C::deliver_photon_blast_results_delayed() {
    s32 i;
    for (i = 0; i < deferred_photon_blast_hit_count; i++) {
        TObjChara *target = (TObjChara *)find_entity_by_id(deferred_photon_blast_hit_queue[i].identity);
        if (target != NULL) {
            DirectAttackPayload payload;
            f32 power = calc_photon_blast_power(deferred_photon_blast_hit_queue[i].kind, deferred_photon_blast_hit_queue[i].value);
            payload.power = power * (0.01 * (power_level * summon_count));
            if (deferred_photon_blast_hit_queue[i].kind == 4) {
                payload.kind = 6;
                for (s32 j = 0; j < 4; j++) {
                    TObjPlayer *player = get_player_by_client_id(recipients[j]);
                    if (player != NULL) {
                        player->receive_direct_attack(owner, payload, NULL, -1, -1);
                        TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&player->body_center, 0x1F8, 0x10);
                        if (aura != NULL) {
                            aura->set_owner_id(player->get_entity_id());
                        }
                    }
                }
                if (local_client_id == target->get_entity_id()) {
                    play_sound_effect(0x4002AB0E, NULL, 0, 0);
                }
                target->receive_direct_attack(owner, payload, NULL, -1, -1);
                TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->body_center, 0x1F8, 0x10);
                if (aura != NULL) {
                    aura->set_owner_id(target->get_entity_id());
                }
                TParticleCtrl *effect = spawn_particle_effect_with_flags(&target->position, 0x16C, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(target->get_entity_id());
                }
                effect = spawn_particle_effect_with_flags(&target->position, 0x16D, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(target->get_entity_id());
                }
            } else if (deferred_photon_blast_hit_queue[i].kind == 5) {
                for (s32 j = 0; j < 4; j++) {
                    payload.kind = 7;
                    TObjPlayer *player = get_player_by_client_id(recipients[j]);
                    if (player != NULL) {
                        if (player->actorFlags & 0x800) {
                            payload.kind = 8;
                        }
                        player->receive_direct_attack(owner, payload, NULL, -1, -1);
                        TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&player->body_center, 0x1F8, 0x10);
                        if (aura != NULL) {
                            aura->set_owner_id(player->get_entity_id());
                        }
                    }
                }
                payload.kind = 7;
                if (target->actorFlags & 0x800) {
                    payload.kind = 8;
                }
                target->receive_direct_attack(owner, payload, NULL, -1, -1);
                TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->body_center, 0x1F8, 0x10);
                if (aura != NULL) {
                    aura->set_owner_id(target->get_entity_id());
                }
                payload.kind = 10;
                for (s32 j = 0; j < 4; j++) {
                    TObjPlayer *player = get_player_by_client_id(recipients[j]);
                    if (player != NULL) {
                        player->receive_direct_attack(owner, payload, NULL, -1, -1);
                    }
                }
                target->receive_direct_attack(owner, payload, NULL, -1, -1);
                payload.kind = 9;
                for (s32 j = 0; j < 4; j++) {
                    TObjPlayer *player = get_player_by_client_id(recipients[j]);
                    if (player != NULL) {
                        player->receive_direct_attack(owner, payload, NULL, -1, -1);
                    }
                }
                target->receive_direct_attack(owner, payload, NULL, -1, -1);
                if (local_client_id == target->get_entity_id()) {
                    play_sound_effect(0x4002AB10, NULL, 0, 0);
                    play_sound_effect(0x4002AD14, NULL, 0, 0);
                    play_sound_effect(0x4002AA16, NULL, 0, 0);
                }
                TParticleCtrl *effect = create_timed_particle_emitter_with_flags(&target->position, 0x16E, 0, 0xF, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(target->get_entity_id());
                }
                effect = spawn_particle_effect_with_flags(&target->position, 0x16F, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(target->get_entity_id());
                }
            } else {
                payload.kind = 4;
                target->receive_direct_attack(owner, payload, NULL, -1, -1);
            }
        }
    }
    clear_photon_blast_donations();
}

void TUnk_804C349C::step_photon_blast_sequence() {
    PhotonSummonParams params;
    s32 first_summon;
    s32 j;

    VecCopy(&params.position, &this->position);
    if (this->owner != NULL) {
        params.owner_id = this->owner->get_entity_id();
    } else {
        params.owner_id = 0xFFFF;
    }
    switch (this->state) {
    case 0:
        if (this->summon_index != 0 && this->summon->all_parents_unqueued_for_destruction() != 0) {
            break;
        }
        if (this->summon_index == this->summon_count) {
            this->state = 2;
            break;
        }
        if (this->summon_index != 0) {
            switch (this->kinds[this->summon_index]) {
            case 2:
            case 3: {
                TObjChara *anchor = (TObjChara *)find_entity_by_id(last_photon_blast_hit_identity);
                if (anchor != NULL) {
                    VecCopy(&this->position, &anchor->position);
                }
                break;
            }
            }
        }
        first_summon = this->summon_index == 0 ? 1 : 0;
        params.has_more = this->summon_index != this->summon_count - 1 ? 1 : 0;
        params.is_first = first_summon;
        params.count = this->summon_count;
        params.level = this->levels[this->summon_index];
        switch (this->kinds[this->summon_index]) {
        case 2:
            this->summon = new TPhotonGolla(&params);
            break;
        case 3:
            this->summon = new TPhotonPilla(&params);
            break;
        case 4:
            this->summon = new TPhotonLeilla(&params);
            for (j = 0; j < 4; j++) {
                if (this->participants[j] < 4) {
                    queue_photon_blast_support(this->participants[j], 4, 1);
                }
            }
            break;
        case 0:
            this->summon = new TPhotonFarlla(&params);
            break;
        case 1:
            this->summon = new TPhotonEstlla(&params);
            break;
        case 5:
            this->summon = new TPhotonMylla(&params);
            for (j = 0; j < 4; j++) {
                if (this->participants[j] < 4) {
                    queue_photon_blast_support(this->participants[j], 5, 1);
                }
            }
            break;
        }
        this->summon->suspend_update();
        this->summon->disallow_rendering();
        this->summon_index++;
        this->state = 1;
        break;
    case 1:
        this->summon->clear_update_suspension();
        this->summon->allow_rendering();
        this->state = 0;
        break;
    case 2:
        play_sound_effect(0x40021927, &this->position, 0, 0);
        deliver_photon_blast_results_animated();
        this->queue_destruction();
        break;
    }
}

s32 photon_blast_donation_flags[4];
PhotonBlastChain photon_blast_sequence_table[4];

#define TOBJECT_OUT_OF_LINE_HELPERS


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
        deliver_photon_blast_results_delayed();
        queue_destruction();
    }
}

void TUnk_804C349C::run_task() {
    owner = get_player_by_client_id(owner_client_id);
    if (animated != 0) {
        step_photon_blast_sequence();
        return;
    }
    update_and_destroy();
}

TUnk_804C349C::~TUnk_804C349C() {
    s32 i;
    s32 j;
    if (animated != 0) {
        TLobby::set_and_notify_default();
        release_photon_blast_player_holds(holds);
        if (get_player_by_client_id(local_client_id) != NULL) {
            TWindowCtrl::enable_client_main_menu(local_client_id);
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

TUnk_804C349C::TUnk_804C349C(s32 owner_client_id, PhotonBlastRequest *requests, s32 *counts, s32 animated, s32 delay)
    : TObject(tl_07) {
    TObjPlayer *player;
    s32 i;
    s32 j;
    PhotonBlastRequestSlot *donor;

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
        if (requests->get_kind() == -1) {
            summon_count = i;
            break;
        }
        kinds[i] = requests->get_kind();
        participants[i] = requests->get_client_id();
        requests++;
    }
    owner = get_player_by_client_id(owner_client_id);
    apply_photon_blast_action_hold(this, summon_count * 150 + 100, owner_client_id);
    if (this->animated != 0) {
        TLobby::send_neg30();
        TWindowCtrl::disable_client_main_menu(local_client_id);
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
        donor = TObjPlayer::find_photon_blast_by_section_id(owner->get_entity_id());
        if (donor != NULL) {
            for (i = 0; i < 4; i++) {
                if (donor->get_client_id() != 0xFFFF
                    && this->owner_client_id != donor->get_client_id()) {
                    recipients[i] = donor->get_client_id();
                }
                donor++;
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


s32 get_photon_blast_chain(PhotonBlastChainCopy *output, s32 player) {
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

void TObjPlayer::start_photon_blast(s32 kind, s32 client_id) {
    TObjPlayer *player;
    PhotonBlastEntry *entry;

    player = get_player_by_client_id(client_id);
    if (player != NULL) {
        entry = get_photon_blast_entry(kind);
        if (TObjPlayer::is_locally_controlled(player) != 0) {
            send_impose_hold(player, entry->effect_id);
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

PhotonBlastEntry *get_photon_blast_entry(int kind) {
    return &photon_blast_entry_table[kind];
}


BmlResource *photon_blast_shared_resource;
PhotonBlastLoadCallback photon_blast_load_callback_table[10] = {
    { create_golla_photon_blast_model, destroy_golla_photon_blast_model },
    { create_pilla_photon_blast_model, destroy_pilla_photon_blast_model },
    { create_leilla_photon_blast_model, destroy_leilla_photon_blast_model },
    { create_farlla_photon_blast_model, destroy_farlla_photon_blast_model },
    { create_estlla_photon_blast_model, destroy_estlla_photon_blast_model },
    { create_youlla_photon_blast_model, destroy_youlla_photon_blast_model },
    { create_mylla_photon_blast_model, destroy_mylla_photon_blast_model },
    { TObjPlayer__sub_801AD480, TObjPlayer__sub_801AD47C },
    { load_photon_rainbow_resources, release_photon_rainbow_resources },
    { load_photon_laser_resources, release_photon_laser_resources },
};

void release_photon_blast_resources(void) {
    s32 i;
    TLobby::call_funcs_reverse(photon_blast_load_callback_table, 0x50);
    if (photon_blast_shared_resource != NULL) {
        delete photon_blast_shared_resource;
        photon_blast_shared_resource = NULL;
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
void load_photon_blast_resources(void) {
    s32 i;
    photon_blast_shared_resource = new BmlResource(1, &photon_blast_resource_descriptor, 0, 0, NULL);
    run_load_callback_table(photon_blast_load_callback_table, 0x50);
    for (i = 0; i < 4; i++) {
        photon_blast_donation_flags[i] = 0;
    }
    TObjPlayer::clear_photon_blast_slots();
}


s16 TObjPlayer::get_evp() { return evp; }

u16 PhotonBlastRequest::get_client_id() { return client_id; }

void PhotonBlastRequest::set_kind(s16 kind) { this->kind = kind; }

void PhotonBlastRequest::set_client_id(u16 client_id) { this->client_id = client_id; }

PhotonBlastRequest::~PhotonBlastRequest() {}

PhotonBlastRequestSlot::~PhotonBlastRequestSlot() {}

PhotonBlastRequest::PhotonBlastRequest() { reset(); }

PhotonBlastRequestSlot::PhotonBlastRequestSlot() { clear(); }

void PhotonBlastRequestSlot::clear() {
    client_id = 0xFFFF;
    amount = 0;
}

u16 PhotonBlastRequestSlot::get_client_id() { return client_id; }

PhotonBlastRequest &PhotonBlastRequest::operator=(PhotonBlastRequest &other) {
    client_id = other.client_id;
    kind = other.kind;
    flags.bits = other.flags.bits;
    slots[0] = other.slots[0];
    slots[1] = other.slots[1];
    slots[2] = other.slots[2];
    slots[3] = other.slots[3];
    return *this;
}

PhotonBlastRequestSlot &PhotonBlastRequestSlot::operator=(PhotonBlastRequestSlot &other) {
    client_id = other.client_id;
    amount = other.amount;
    return *this;
}
