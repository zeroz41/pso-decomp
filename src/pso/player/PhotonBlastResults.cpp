#define TOBJECT_OUT_OF_LINE_HELPERS
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
#include "pso/unk/text_801AAB74.h"
#include "pso/unk/text_801AB370.h"
#include "pso/unk/text_801ABE14.h"
#include "pso/unk/text_801AE1F8.h"
#include "pso/unk/text_80087278.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/TUnk_804C349C.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/render/TFogCtrl.h"
#include "pso/player/TObjPlayer_803130BC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801C7430.h"
#include "pso/unk/text_8024AB98.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
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
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

#define TOBJECT_OUT_OF_LINE_HELPERS

struct Slot_801A8868 { u8 pad[0x18]; };
struct Counts_801A8868 { s32 v[4]; };

struct Hit_801A86E0 { s32 kind; f32 value; };


struct PhotonSummonParams_801A9870 {
    Vec position;
    u16 owner_id;
    s32 is_first;
    s32 has_more;
    u8 pad18[4];
    u8 count;
    f32 level;
};
typedef char PhotonSummonParams_801A9870_size[sizeof(PhotonSummonParams_801A9870) == 0x24 ? 1 : -1];
struct VBase_18_b27ba1 { char pad[0x18]; };
struct VObj_18_b27ba1 : VBase_18_b27ba1 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21(void *, struct Hit_801A86E0 *, s32, s32, s32);
};

extern "C" {


TObjChara *find_entity_by_id(u16 identity);

s32 get_current_floor();
s32 get_floor__10TObjPlayerFv(void *);
s32 get_room__8TObjBaseFv(void *);
void set_type__10TObjPlayerFs(void *, s16);
s32 TObjPlayer__sub_801AA528(s32 arg0, s16 arg1);
void *TObjPlayer__sub_801AA66C(void *, void *);
void *__nw__7TObjectFUl(int);
s16 TObjPlayer__sub_80313114(u8 *arg0);
u8 *TPhotonLeilla__ct(u8 *self, u8 *params);
u8 *TPhotonMylla__ct(u8 *self, u8 *params);
extern u32 lbl_805D5D18;
}
extern s32 photon_blast_donation_flags[];
void clear_photon_blast_donations(void);
extern s32 local_client_id;
s32 is_photon_blast_presentation_admitted(u32 owner_id, void *records);

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

extern "C" {

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

}

BmlResourceDescriptor photon_blast_resource_descriptor = { "pm_mdl.bml", pm_mdl_model_names, pm_mdl_motion_names, 12, 15 };

const Counts_801A8868 photon_blast_result_counts_init = { 0, 0, 0, 0 };
void admit_photon_blast_sequence(u8 *players, void *self);

#pragma push
#pragma fp_contract on

f32 TObjPlayer::calc_photon_blast_power(s32 arg1, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    f32 var_f30;
    void *mag;
    var_f30 = 0.0f;
    if (*(u8 **)(arg0 + 0x38) != NULL) {
        mag = (void *)((TObjPlayer *)(*(u8 **)(arg0 + 0x38)))->activate_d04_slot();
        if (mag != 0) {
            switch (arg1) {
            case 0:
                var_f30 = farg0 + ((2.5f * (f32)((TItemMag *)mag)->get_iq()) + 0.025f * (f32)(((TItemMag *)mag)->get_synchro() * (((TObjPlayer *)(*(u8 **)(arg0 + 0x38)))->get_field_2c8() + ((TObjChara *)(*(u8 **)(arg0 + 0x38)))->get_actor_attack_params_atp_min())));
                break;
            case 1:
                var_f30 = farg0 + ((15.0f * (f32)((TItemMag *)mag)->get_iq()) + 0.15f * (f32)(((TObjPlayer *)(*(u8 **)(arg0 + 0x38)))->get_hp() * ((TItemMag *)mag)->get_synchro()));
                break;
            case 2:
                var_f30 = farg0 + ((7.5f * (f32)((TItemMag *)mag)->get_iq()) + 0.075f * (f32)(((TItemMag *)mag)->get_synchro() * (((TObjPlayer *)(*(u8 **)(arg0 + 0x38)))->get_field_2c8() + ((TObjChara *)(*(u8 **)(arg0 + 0x38)))->get_actor_attack_params_atp_min())));
                break;
            case 3:
                var_f30 = farg0 + ((7.5f * (f32)((TItemMag *)mag)->get_iq()) + 0.075f * (f32)(((TObjPlayer *)(*(u8 **)(arg0 + 0x38)))->get_ata() * ((TItemMag *)mag)->get_synchro()));
                break;
            case 4:
                var_f30 = (0.5f * (f32)((TItemMag *)mag)->get_iq()) + farg0;
                break;
            case 5:
                var_f30 = 0.1f * (f32)((TItemMag *)mag)->get_iq();
                if (var_f30 >= 20.0f) {
                    var_f30 = 20.0f;
                }
                break;
            }
        }
    }
    return var_f30;
}
#pragma pop

s32 TObjPlayer::is_any_teammate_in_state() {
    PhotonBlastChainCopy sp8;
    s32 current_floor;
    s32 var_r30;

    current_floor = get_current_floor();
    var_r30 = 0;
loop_1:
    if ((((u32 (*)(s32))get_player_by_client_id)(var_r30) != 0U) && (current_floor == ((s32 (*)(void))get_floor__10TObjPlayerFv)()) && (get_photon_blast_chain(&sp8, var_r30) == 2)) {
        return 1;
    }
    var_r30 += 1;
    if (var_r30 >= 4) {
        return 0;
    }
    goto loop_1;
}

s32 is_photon_blast_presentation_admitted(u32 owner_id, void *records) {
    void *local;
    void *owner;
    s16 group;
    if (is_split_screen() != 0) {
        return 1;
    }
    if (local_client_id == ((TObjPlayer *)records)->get_section_id()) {
        return 1;
    }
    local = get_player_by_client_id(local_client_id);
    if (local == NULL) {
        return 0;
    }
    group = get_room__8TObjBaseFv(local);
    owner = get_player_by_client_id(owner_id);
    if (owner != NULL) {
        if (get_floor__10TObjPlayerFv(local) == get_floor__10TObjPlayerFv(owner) && group == (s16) get_room__8TObjBaseFv(owner)) {
            return 1;
        }
    }
    return 0;
}

void apply_photon_blast_action_hold(s32 arg0, s32 arg1, s32 arg2) {
    u8 *plr;
    u8 *ent;
    s32 i;
    Hit_801A86E0 tmp1;
    Hit_801A86E0 tmp2;

    ent = ((u8 *(*)(u16))find_entity_by_id)(arg2);
    for (i = TLobby::get_game_mode(); i < TLobby::get_game_mode() + TObjEneDD::get_enemy_count(); i++) {
        plr = (u8 *)TObjPlayer::get_player_data(i);
        if (plr != NULL && !(*(s32 *)((s8 *)plr + 0x30) & 0x40000000)) {
            if (is_split_screen() != 0) {
                tmp1.value = (f32)arg1;
                tmp1.kind = 0x14;
                Hit_801A86E0 hit1 = tmp1;
                ((VObj_18_b27ba1 *)plr)->m21(ent, &hit1, 0, -1, -1);
            } else if (*(s16 *)((s8 *)plr + 0x28) == (s16)((TObjBase *)ent)->get_room()) {
                tmp2.value = (f32)arg1;
                tmp2.kind = 0x14;
                Hit_801A86E0 hit2 = tmp2;
                ((VObj_18_b27ba1 *)plr)->m21(ent, &hit2, 0, -1, -1);
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
#define GET_STAT ((s16 (*)(void *))get_room__8TObjBaseFv)
#define SET_TYPE ((void (*)(void *, u16))set_type__10TObjPlayerFs)
void admit_photon_blast_sequence(u8 *players, void *self) {
    Slot_801A8868 a[4];
    Slot_801A8868 b[4];
    s32 n;
    s32 j;
    s32 k;
    s32 flag;
    s32 delay;
    void *p;
    s32 i;
    s32 idx;
    s32 m;
    TObjPlayer *q;
    ((TObjPlayer *)(&a[0]))->init_arrays();
    ((TObjPlayer *)(&a[1]))->init_arrays();
    ((TObjPlayer *)(&a[2]))->init_arrays();
    ((TObjPlayer *)(&a[3]))->init_arrays();
    ((TObjPlayer *)(&b[0]))->init_arrays();
    ((TObjPlayer *)(&b[1]))->init_arrays();
    ((TObjPlayer *)(&b[2]))->init_arrays();
    ((TObjPlayer *)(&b[3]))->init_arrays();
    Counts_801A8868 counts = photon_blast_result_counts_init;
    for (n = 0; n < 4; n++) {
        SET_TYPE(&b[n], 0xFFFF);
        ((TObjPlayer *)(&b[n]))->set_field_2(-1);
    }
    n = 0;
    k = 0;
    for (j = 0; j < 4; j++, players += 0x18) {
        p = get_player_by_client_id(((TObjPlayer *)players)->get_section_id());
        if (p != NULL && GET_STAT(p) == GET_STAT(self)
            && TObjPlayer__sub_80313114(players) != -1) {
            SET_TYPE(&a[n], ((TObjPlayer *)players)->get_section_id());
            ((TObjPlayer *)(&a[n]))->set_field_2(TObjPlayer__sub_80313114(players));
            n++;
        }
    }
    for (i = n; i < 4; i++) {
        SET_TYPE(&a[i], 0xFFFF);
        ((TObjPlayer *)(&a[i]))->set_field_2(-1);
    }
    for (m = 0; m < 4; m++) {
        if (m != 0) {
            if (TObjPlayer__sub_80313114((u8 *)&a[m]) != -1) {
                if (TObjPlayer__sub_80313114((u8 *)&b[k]) == TObjPlayer__sub_80313114((u8 *)((u8 *)&a[m]))) {
                    counts.v[k]++;
                } else {
                    k++;
                }
            } else {
                k++;
            }
        }
        TObjPlayer__sub_801AA66C(&b[k], &a[m]);
    }
    flag = 0;
    for (i = 0; i < 4; i++) {
        if (i != get_entity_id((TObjBase *)self)) {
            q = get_player_by_client_id(i);
            if (q != NULL && GET_STAT(q) == GET_STAT(self)
                && photon_blast_sequence_table[get_entity_id(q)].state != 0) {
                flag = 1;
            }
        }
    }
    if (flag != 0) {
        TObjPlayer__sub_801AA528((s32)&b[3], -1);
        TObjPlayer__sub_801AA528((s32)&b[2], -1);
        TObjPlayer__sub_801AA528((s32)&b[1], -1);
        TObjPlayer__sub_801AA528((s32)&b[0], -1);
        TObjPlayer__sub_801AA528((s32)&a[3], -1);
        TObjPlayer__sub_801AA528((s32)&a[2], -1);
        TObjPlayer__sub_801AA528((s32)&a[1], -1);
        TObjPlayer__sub_801AA528((s32)&a[0], -1);
        return;
    }
    if (is_photon_blast_presentation_admitted(get_entity_id((TObjBase *)self), b) != 0) {
        new TUnk_804C349C(get_entity_id((TObjBase *)self), (u8 *)b, counts.v, 1, 0);
    } else {
        idx = 0;
        for (i = 0; i < 4; i++) {
            if (TObjPlayer__sub_80313114((u8 *)&b[i]) == -1) {
                idx = i;
                break;
            }
        }
        delay = idx * 150 + 100;
        new TUnk_804C349C(get_entity_id((TObjBase *)self), (u8 *)b, counts.v, 0, delay);
    }
    TObjPlayer__sub_801AA528((s32)&b[3], -1);
    TObjPlayer__sub_801AA528((s32)&b[2], -1);
    TObjPlayer__sub_801AA528((s32)&b[1], -1);
    TObjPlayer__sub_801AA528((s32)&b[0], -1);
    TObjPlayer__sub_801AA528((s32)&a[3], -1);
    TObjPlayer__sub_801AA528((s32)&a[2], -1);
    TObjPlayer__sub_801AA528((s32)&a[1], -1);
    TObjPlayer__sub_801AA528((s32)&a[0], -1);
}
#undef GET_STAT
#undef SET_TYPE

void deliver_photon_blast_results_animated(TUnk_804C349C *seq) {
    s32 i;
    for (i = 0; i < photon_blast_hit_count; i++) {
        TObjChara *target = find_entity_by_id(photon_blast_hit_queue[i].identity);
        if (target != NULL) {
            DirectAttackPayload payload;
            f32 power = ((TObjPlayer *)seq)->calc_photon_blast_power(photon_blast_hit_queue[i].kind, photon_blast_hit_queue[i].value);
            payload.power = power * (0.01 * (seq->power_level * seq->summon_count));
            if (photon_blast_hit_queue[i].kind == 4) {
                payload.kind = 6;
                for (s32 j = 0; j < 4; j++) {
                    TObjPlayer *player = get_player_by_client_id(seq->recipients[j]);
                    if (player != NULL) {
                        player->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                        TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&player->m_2fc, 0x1F8, 0x10);
                        if (aura != NULL) {
                            aura->set_owner_id(get_entity_id(player));
                        }
                    }
                }
                if (local_client_id == get_entity_id(target)) {
                    play_sound_effect(0x4002AB0E, NULL, 0, 0);
                }
                target->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->m_2fc, 0x1F8, 0x10);
                if (aura != NULL) {
                    aura->set_owner_id(get_entity_id(target));
                }
                TParticleCtrl *effect = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->position, 0x16C, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(get_entity_id(target));
                }
                effect = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->position, 0x16D, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(get_entity_id(target));
                }
            } else if (photon_blast_hit_queue[i].kind == 5) {
                for (s32 j = 0; j < 4; j++) {
                    payload.kind = 7;
                    TObjPlayer *player = get_player_by_client_id(seq->recipients[j]);
                    if (player != NULL) {
                        if (player->actorFlags & 0x800) {
                            payload.kind = 8;
                        }
                        player->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                        TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&player->m_2fc, 0x1F8, 0x10);
                        if (aura != NULL) {
                            aura->set_owner_id(get_entity_id(player));
                        }
                    }
                }
                payload.kind = 7;
                if (target->actorFlags & 0x800) {
                    payload.kind = 8;
                }
                target->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->m_2fc, 0x1F8, 0x10);
                if (aura != NULL) {
                    aura->set_owner_id(get_entity_id(target));
                }
                payload.kind = 10;
                for (s32 j = 0; j < 4; j++) {
                    TObjPlayer *player = get_player_by_client_id(seq->recipients[j]);
                    if (player != NULL) {
                        player->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                    }
                }
                target->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                payload.kind = 9;
                for (s32 j = 0; j < 4; j++) {
                    TObjPlayer *player = get_player_by_client_id(seq->recipients[j]);
                    if (player != NULL) {
                        player->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                    }
                }
                target->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                if (local_client_id == get_entity_id(target)) {
                    play_sound_effect(0x4002AB10, NULL, 0, 0);
                    play_sound_effect(0x4002AD14, NULL, 0, 0);
                    play_sound_effect(0x4002AA16, NULL, 0, 0);
                }
                TParticleCtrl *effect = (TParticleCtrl *)create_timed_particle_emitter_with_flags(&target->position, 0x16E, 0, 0xF, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(get_entity_id(target));
                }
                effect = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->position, 0x16F, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(get_entity_id(target));
                }
            } else {
                payload.kind = 4;
                target->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
            }
        }
    }
    clear_photon_blast_donations();
}

void deliver_photon_blast_results_delayed(TUnk_804C349C *seq) {
    s32 i;
    for (i = 0; i < deferred_photon_blast_hit_count; i++) {
        TObjChara *target = find_entity_by_id(deferred_photon_blast_hit_queue[i].identity);
        if (target != NULL) {
            DirectAttackPayload payload;
            f32 power = ((TObjPlayer *)seq)->calc_photon_blast_power(deferred_photon_blast_hit_queue[i].kind, deferred_photon_blast_hit_queue[i].value);
            payload.power = power * (0.01 * (seq->power_level * seq->summon_count));
            if (deferred_photon_blast_hit_queue[i].kind == 4) {
                payload.kind = 6;
                for (s32 j = 0; j < 4; j++) {
                    TObjPlayer *player = get_player_by_client_id(seq->recipients[j]);
                    if (player != NULL) {
                        player->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                        TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&player->m_2fc, 0x1F8, 0x10);
                        if (aura != NULL) {
                            aura->set_owner_id(get_entity_id(player));
                        }
                    }
                }
                if (local_client_id == get_entity_id(target)) {
                    play_sound_effect(0x4002AB0E, NULL, 0, 0);
                }
                target->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->m_2fc, 0x1F8, 0x10);
                if (aura != NULL) {
                    aura->set_owner_id(get_entity_id(target));
                }
                TParticleCtrl *effect = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->position, 0x16C, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(get_entity_id(target));
                }
                effect = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->position, 0x16D, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(get_entity_id(target));
                }
            } else if (deferred_photon_blast_hit_queue[i].kind == 5) {
                for (s32 j = 0; j < 4; j++) {
                    payload.kind = 7;
                    TObjPlayer *player = get_player_by_client_id(seq->recipients[j]);
                    if (player != NULL) {
                        if (player->actorFlags & 0x800) {
                            payload.kind = 8;
                        }
                        player->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                        TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&player->m_2fc, 0x1F8, 0x10);
                        if (aura != NULL) {
                            aura->set_owner_id(get_entity_id(player));
                        }
                    }
                }
                payload.kind = 7;
                if (target->actorFlags & 0x800) {
                    payload.kind = 8;
                }
                target->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                TParticleCtrl *aura = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->m_2fc, 0x1F8, 0x10);
                if (aura != NULL) {
                    aura->set_owner_id(get_entity_id(target));
                }
                payload.kind = 10;
                for (s32 j = 0; j < 4; j++) {
                    TObjPlayer *player = get_player_by_client_id(seq->recipients[j]);
                    if (player != NULL) {
                        player->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                    }
                }
                target->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                payload.kind = 9;
                for (s32 j = 0; j < 4; j++) {
                    TObjPlayer *player = get_player_by_client_id(seq->recipients[j]);
                    if (player != NULL) {
                        player->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                    }
                }
                target->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
                if (local_client_id == get_entity_id(target)) {
                    play_sound_effect(0x4002AB10, NULL, 0, 0);
                    play_sound_effect(0x4002AD14, NULL, 0, 0);
                    play_sound_effect(0x4002AA16, NULL, 0, 0);
                }
                TParticleCtrl *effect = (TParticleCtrl *)create_timed_particle_emitter_with_flags(&target->position, 0x16E, 0, 0xF, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(get_entity_id(target));
                }
                effect = (TParticleCtrl *)spawn_particle_effect_with_flags(&target->position, 0x16F, 0x10);
                if (effect != NULL) {
                    effect->set_owner_id(get_entity_id(target));
                }
            } else {
                payload.kind = 4;
                target->receive_direct_attack(seq->owner, payload, NULL, -1, -1);
            }
        }
    }
    clear_photon_blast_donations();
}

void step_photon_blast_sequence(TUnk_804C349C *seq) {
    PhotonSummonParams_801A9870 params;
    u8 *summon;
    s32 first_summon;
    s32 j;

    VecCopy(&params.position, &seq->position);
    if (seq->owner != NULL) {
        params.owner_id = get_entity_id(seq->owner);
    } else {
        params.owner_id = 0xFFFF;
    }
    switch (seq->state) {
    case 0:
        if (seq->summon_index != 0 && seq->summon->all_parents_unqueued_for_destruction() != 0) {
            break;
        }
        if (seq->summon_index == seq->summon_count) {
            seq->state = 2;
            break;
        }
        if (seq->summon_index != 0) {
            switch (seq->kinds[seq->summon_index]) {
            case 2:
            case 3: {
                TObjChara *anchor = find_entity_by_id(lbl_805D5D18);
                if (anchor != NULL) {
                    VecCopy(&seq->position, &anchor->position);
                }
                break;
            }
            }
        }
        first_summon = seq->summon_index == 0 ? 1 : 0;
        params.has_more = seq->summon_index != seq->summon_count - 1 ? 1 : 0;
        params.is_first = first_summon;
        params.count = seq->summon_count;
        params.level = seq->levels[seq->summon_index];
        switch (seq->kinds[seq->summon_index]) {
        case 2:
            summon = (u8 *)TObject::operator new(0x1CC);
            if (summon != NULL) {
                summon = TPhotonGolla__ct(summon, (u8 *)&params);
            }
            seq->summon = (TObject *)summon;
            break;
        case 3:
            summon = (u8 *)TObject::operator new(0x1AC);
            if (summon != NULL) {
                summon = TPhotonPilla__ct(summon, (u8 *)&params);
            }
            seq->summon = (TObject *)summon;
            break;
        case 4:
            summon = (u8 *)TObject::operator new(0x1B0);
            if (summon != NULL) {
                summon = TPhotonLeilla__ct(summon, (u8 *)&params);
            }
            seq->summon = (TObject *)summon;
            for (j = 0; j < 4; j++) {
                if (seq->participants[j] < 4) {
                    ((void (*)(u32, s32, s32))queue_photon_blast_support)(seq->participants[j], 4, 1);
                }
            }
            break;
        case 0:
            summon = (u8 *)TObject::operator new(0x1A8);
            if (summon != NULL) {
                summon = TPhotonFarlla__ct(summon, (u8 *)&params);
            }
            seq->summon = (TObject *)summon;
            break;
        case 1:
            summon = (u8 *)TObject::operator new(0x1A4);
            if (summon != NULL) {
                summon = __ct__13TPhotonEstllaFPUc(summon, (u8 *)&params);
            }
            seq->summon = (TObject *)summon;
            break;
        case 5:
            summon = (u8 *)TObject::operator new(0x1A8);
            if (summon != NULL) {
                summon = TPhotonMylla__ct(summon, (u8 *)&params);
            }
            seq->summon = (TObject *)summon;
            for (j = 0; j < 4; j++) {
                if (seq->participants[j] < 4) {
                    ((void (*)(u32, s32, s32))queue_photon_blast_support)(seq->participants[j], 5, 1);
                }
            }
            break;
        }
        seq->summon->suspend_update();
        seq->summon->disallow_rendering();
        seq->summon_index++;
        seq->state = 1;
        break;
    case 1:
        ((TQuestVmDownLoadServer *)seq->summon)->clear_flag4_bit4();
        seq->summon->allow_rendering();
        seq->state = 0;
        break;
    case 2:
        play_sound_effect(0x40021927, &seq->position, 0, 0);
        deliver_photon_blast_results_animated(seq);
        seq->queue_destruction();
        break;
    }
}

s32 photon_blast_donation_flags[4];
PhotonBlastChain photon_blast_sequence_table[4];

#define TOBJECT_OUT_OF_LINE_HELPERS

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
}

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

void *TObjPlayer::get_photon_blast_entry(int kind) {
    return &photon_blast_entry_table[kind];
}


extern "C" {
void free_bin_model_request(u32, int);
void call_funcs_reverse__6TLobbyFPvUi(void *, int);
extern PhotonBlastLoadCallback photon_blast_load_callback_table[10];
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
