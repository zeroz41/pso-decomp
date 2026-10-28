#include "types.h"
#include "pso/unk/text_801AA3B4.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/player/TObjPlayer.h"

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

struct PhotonBlastChain_801AA424 {
    s32 kinds[4];
    u32 participants[4];
    s32 state;
};

extern "C" {
void TLobby__sub_8001FE7C(u32, int);
void call_funcs_reverse__6TLobbyFPvUi(void *, int);
extern u8 photon_blast_load_callback_table[];
extern u32 photon_blast_donation_flags[];
extern u32 photon_blast_shared_resource;
extern struct PhotonBlastChain_801AA424 photon_blast_sequence_table[];
u8 *load_resource_from_descriptor(u8 *, int, void *, int, int, int);
s32 run_load_callback_table(void *, int);
void TObjPlayer__sub_801AA3B4(void) {
    s32 i;
    call_funcs_reverse__6TLobbyFPvUi(photon_blast_load_callback_table, 0x50);
    if (photon_blast_shared_resource != 0U) {
        TLobby__sub_8001FE7C(photon_blast_shared_resource, 1);
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
