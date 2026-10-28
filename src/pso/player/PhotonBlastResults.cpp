#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/PhotonBlastSummon.h"
#include "pso/system/vector.h"
#include "pso/unk/text_801AAB74.h"
#include "pso/unk/text_801AB370.h"
#include "pso/unk/text_801ABE14.h"
#include "pso/unk/text_801AE1F8.h"

struct Slot_801A8868 { u8 pad[0x18]; };
struct Counts_801A8868 { s32 v[4]; };
struct Rec_801A8868 { u8 pad[0x20]; s32 f20; };

struct Hit_801A86E0 { s32 kind; f32 value; };

struct PhotonBlastSequence_801A9870 : public TObject {
    TObject *summon;
    s32 summon_index;
    s32 state;
    s32 summon_count;
    Vec position;
    TObjPlayer *owner;
    u16 owner_client_id;
    s32 power_level;
    s32 elapsed;
    s32 delay;
    s32 animated;
    s32 kinds[4];
    u32 participants[4];
    s32 levels[4];
    u32 recipients[4];
    u16 holds[4];
};
typedef char PhotonBlastSequence_801A9870_size[sizeof(PhotonBlastSequence_801A9870) == 0x98 ? 1 : -1];

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

s16 TObjPlayer__sub_80113D90(void *);
extern const f32 lbl_805DC110;
extern const f32 lbl_805DC114;
extern const f32 lbl_805DC118;
extern const f32 lbl_805DC11C;
extern const f32 lbl_805DC120;
extern const f32 lbl_805DC124;
extern const f32 lbl_805DC128;
extern const f32 lbl_805DC12C;

TUnk_804806E8 *find_entity_by_id(u16 identity);

s32 get_current_floor();
s32 get_field_3e4__10TObjPlayerFv(void *);
s32 get_photon_blast_chain(void *, s32);
void *get_player_by_client_id(u32);
s32 is_split_screen();
s32 get_room__13TUnk_804B9870Fv(void *);
u16 get_entity_id(void *);
s32 TObjPlayer__sub_801A9E10(void *, int, void *, void *, int, int);
void set_type__10TObjPlayerFs(void *, s16);
s32 TObjPlayer__sub_801AA528(s32 arg0, s16 arg1);
void *TObjPlayer__sub_801AA66C(void *, void *);
void *__nw__7TObjectFUl(int);
s16 TObjPlayer__sub_80313114(u8 *arg0);
int get_player_data__10TObjPlayerFi(int);
void play_sound_effect(u32 id, void *position, s32, s32);
u8 *TPhotonLeilla__ct(u8 *self, u8 *params);
u8 *TPhotonMylla__ct(u8 *self, u8 *params);
extern u32 lbl_805D5D18;
void deliver_photon_blast_results_animated(PhotonBlastSequence_801A9870 *seq);
void step_photon_blast_sequence(PhotonBlastSequence_801A9870 *seq);
}
extern s32 photon_blast_donation_flags[];
void clear_photon_blast_donations(void);
extern s32 local_client_id;
s32 is_photon_blast_presentation_admitted(u32 owner_id, void *records);
extern Counts_801A8868 photon_blast_result_counts_init;
extern Rec_801A8868 photon_blast_sequence_table[];
void admit_photon_blast_sequence(u8 *players, void *self);
void apply_photon_blast_action_hold(s32 arg0, s32 arg1, s32 arg2);

#pragma push
#pragma fp_contract on

f32 TObjPlayer::calc_photon_blast_power(s32 arg1, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    f32 var_f30;
    void *mag;
    var_f30 = lbl_805DC110;
    if (*(u8 **)(arg0 + 0x38) != NULL) {
        mag = (void *)((TObjPlayer *)(*(u8 **)(arg0 + 0x38)))->activate_d04_slot();
        if (mag != 0) {
            switch (arg1) {
            case 0:
                var_f30 = farg0 + ((lbl_805DC114 * (f32)((TObjPlayer *)mag)->get_mag_data()) + lbl_805DC118 * (f32)(TObjPlayer__sub_80113D90(mag) * (((TObjPlayer *)(*(u8 **)(arg0 + 0x38)))->get_field_2c8() + ((TUnk_804806E8 *)(*(u8 **)(arg0 + 0x38)))->get_actor_attack_params_atp_min())));
                break;
            case 1:
                var_f30 = farg0 + ((lbl_805DC11C * (f32)((TObjPlayer *)mag)->get_mag_data()) + lbl_805DC120 * (f32)(((TObjPlayer *)(*(u8 **)(arg0 + 0x38)))->get_hp() * TObjPlayer__sub_80113D90(mag)));
                break;
            case 2:
                var_f30 = farg0 + ((lbl_805DC124 * (f32)((TObjPlayer *)mag)->get_mag_data()) + lbl_805DC128 * (f32)(TObjPlayer__sub_80113D90(mag) * (((TObjPlayer *)(*(u8 **)(arg0 + 0x38)))->get_field_2c8() + ((TUnk_804806E8 *)(*(u8 **)(arg0 + 0x38)))->get_actor_attack_params_atp_min())));
                break;
            case 3:
                var_f30 = farg0 + ((lbl_805DC124 * (f32)((TObjPlayer *)mag)->get_mag_data()) + lbl_805DC128 * (f32)(((TObjPlayer *)(*(u8 **)(arg0 + 0x38)))->get_ata() * TObjPlayer__sub_80113D90(mag)));
                break;
            case 4:
                var_f30 = (lbl_805DC12C * (f32)((TObjPlayer *)mag)->get_mag_data()) + farg0;
                break;
            case 5:
                var_f30 = 0.1f * (f32)((TObjPlayer *)mag)->get_mag_data();
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
    struct { u8 _pad[0x20]; } sp8;
    s32 current_floor;
    s32 var_r30;

    current_floor = get_current_floor();
    var_r30 = 0;
loop_1:
    if ((((u32 (*)(s32))get_player_by_client_id)(var_r30) != 0U) && (current_floor == ((s32 (*)(void))get_field_3e4__10TObjPlayerFv)()) && (get_photon_blast_chain(&sp8, var_r30) == 2)) {
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
    group = get_room__13TUnk_804B9870Fv(local);
    owner = get_player_by_client_id(owner_id);
    if (owner != NULL) {
        if (get_field_3e4__10TObjPlayerFv(local) == get_field_3e4__10TObjPlayerFv(owner) && group == (s16) get_room__13TUnk_804B9870Fv(owner)) {
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
        plr = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (plr != NULL && !(*(s32 *)((s8 *)plr + 0x30) & 0x40000000)) {
            if (is_split_screen() != 0) {
                tmp1.value = (f32)arg1;
                tmp1.kind = 0x14;
                Hit_801A86E0 hit1 = tmp1;
                ((VObj_18_b27ba1 *)plr)->m21(ent, &hit1, 0, -1, -1);
            } else if (*(s16 *)((s8 *)plr + 0x28) == (s16)get_room__13TUnk_804B9870Fv(ent)) {
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
#define GET_STAT ((s16 (*)(void *))get_room__13TUnk_804B9870Fv)
#define SET_TYPE ((void (*)(void *, u16))set_type__10TObjPlayerFs)
void admit_photon_blast_sequence(u8 *players, void *self) {
    Slot_801A8868 a[4];
    Slot_801A8868 b[4];
    s32 n;
    s32 j;
    s32 k;
    s32 flag;
    s32 delay;
    void *o;
    void *p;
    s32 i;
    s32 idx;
    s32 m;
    void *q;
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
        if (i != get_entity_id(self)) {
            q = get_player_by_client_id(i);
            if (q != NULL && GET_STAT(q) == GET_STAT(self)
                && photon_blast_sequence_table[get_entity_id(q)].f20 != 0) {
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
    if (is_photon_blast_presentation_admitted(get_entity_id(self), b) != 0) {
        o = __nw__7TObjectFUl(0x98);
        if (o != NULL) {
            TObjPlayer__sub_801A9E10(o, get_entity_id(self), b, &counts, 1, 0);
        }
    } else {
        idx = 0;
        for (i = 0; i < 4; i++) {
            if (TObjPlayer__sub_80313114((u8 *)&b[i]) == -1) {
                idx = i;
                break;
            }
        }
        delay = idx * 150 + 100;
        o = __nw__7TObjectFUl(0x98);
        if (o != NULL) {
            TObjPlayer__sub_801A9E10(o, get_entity_id(self), b, &counts, 0, delay);
        }
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


void step_photon_blast_sequence(PhotonBlastSequence_801A9870 *seq) {
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
                TUnk_804806E8 *anchor = find_entity_by_id(lbl_805D5D18);
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
                summon = TPhotonEstlla__ct(summon, (u8 *)&params);
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
