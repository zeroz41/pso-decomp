#include "types.h"
#include "pso/misc/TPhotonMagicSquare.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TCameraCtrl.h"

extern "C" {

void *spawn_particle_effect(void *pos, s32 id);
s32 is_locally_controlled__10TObjPlayerFPv(s32);
s32 get_player_by_client_id(u16);
u32 __nw__7TObjectFUl(s32);
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);

extern s32 tl_07;

void TObjPlayer::start_photon_blast(s32 arg0, u16 arg1) {
    s32 temp_r3;
    void *photon_blast_entry;
    void *temp_nw;

    temp_r3 = get_player_by_client_id(arg1);
    if (temp_r3 != 0) {
        photon_blast_entry = TObjPlayer::get_photon_blast_entry(arg0);
        if (is_locally_controlled__10TObjPlayerFPv(temp_r3) != 0) {
            play_effect_default__10TObjPlayerFii(temp_r3, *(s16 *)((s8 *)photon_blast_entry + 0x20));
        }
        spawn_particle_effect((void *)(temp_r3 + 0x38), 0x13D);
        TCameraCtrl::set_shake_preset(0);
        switch (arg0) {
        case 2:
            temp_nw = (void *) __nw__7TObjectFUl(0xD0);
            if (temp_nw != NULL) {
                ((TPhotonMagicSquare *)temp_nw)->construct_at_owner(tl_07, 2, arg1);
                return;
            }
            break;
        case 3:
            temp_nw = (void *) __nw__7TObjectFUl(0xD0);
            if (temp_nw != NULL) {
                ((TPhotonMagicSquare *)temp_nw)->construct_at_owner(tl_07, 3, arg1);
                return;
            }
            break;
        case 4:
            temp_nw = (void *) __nw__7TObjectFUl(0xD0);
            if (temp_nw != NULL) {
                ((TPhotonMagicSquare *)temp_nw)->construct_at_owner(tl_07, 4, arg1);
                return;
            }
            break;
        case 0:
            temp_nw = (void *) __nw__7TObjectFUl(0xD0);
            if (temp_nw != NULL) {
                ((TPhotonMagicSquare *)temp_nw)->construct_at_owner(tl_07, 0, arg1);
                return;
            }
            break;
        case 1:
            temp_nw = (void *) __nw__7TObjectFUl(0xD0);
            if (temp_nw != NULL) {
                ((TPhotonMagicSquare *)temp_nw)->construct_at_owner(tl_07, 1, arg1);
                return;
            }
            break;
        case 5:
            temp_nw = (void *) __nw__7TObjectFUl(0xD0);
            if (temp_nw != NULL) {
                ((TPhotonMagicSquare *)temp_nw)->construct_at_owner(tl_07, 5, arg1);
            }
            break;
        }
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

PhotonBlastEntry photon_blast_entry_table[6] = {
    { 500.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x2AAA, 0x1555, 10, 10, 0, 0, 0 },
    { 350.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x2AAA, 0x1555, 10, 10, 0, 0, 0 },
    { 1200.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x2AAA, 0x1555, 10, 10, 0, 0, 0 },
    { 500.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x2AAA, 0x1555, 10, 10, 0, 0, 0 },
    { 150.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x1555, 0x1555, 10, 10, 0, 0, 0 },
    { 0.0f, 15.0f, 150.0f, 10.0f, 0, 10, 20, 4, 0x1555, 0x1555, 10, 10, 0, 0, 0 },
};

void*TObjPlayer::get_photon_blast_entry(int a0) {  return &photon_blast_entry_table[a0]; }

}
