#ifndef PSO_SYSTEM_DATA_PSO_CONST_IDS4_H
#define PSO_SYSTEM_DATA_PSO_CONST_IDS4_H

#include "types.h"

class TPlyDispConfig;

extern "C" {
u8 ret_801D78E4(void *rules);
u8 ret_801D78EC(void *rules);
u8 ret_801D78F4(void *rules);
u8 ret_801D78FC(void *rules);
u8 ret_801D7904(void *rules);
u8 ret_801D790C(void *rules);
u8 ret_801D7914(void *rules);
u8 ret_801D791C(void *rules);
u8 ret_801D7924(void *rules);
u8 ret_801D792C(void *rules);
u8 ret_801D7934(void *rules);
u8 ret_801D793C(void *rules);
u8 ret_801D7944(void *rules);
u8 ret_801D794C(void *rules);
u8 ret_801D7954(void *rules);
u8 ret_801D795C(void *rules);
}

// Resets a player's action palettes to the default photon blast slots.
void assign_default_photon_blast_palette_slots(TPlyDispConfig *palettes);
// Puts a photon blast into the first free one of slots 1-3 of the palettes.
void assign_photon_blast_palette_slot(TPlyDispConfig *palettes, s32 arg1);


#endif
