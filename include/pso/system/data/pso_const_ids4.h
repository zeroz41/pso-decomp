#ifndef PSO_SYSTEM_DATA_PSO_CONST_IDS4_H
#define PSO_SYSTEM_DATA_PSO_CONST_IDS4_H

#include "types.h"

class TPlyDispConfig;

extern "C" {
int default_setting_18(void);
int default_setting_16(void);
int default_setting_0E(void);
int default_setting_0D(void);
int default_setting_0C(void);
int default_setting_0B(void);
int default_setting_0A(void);
int default_setting_09(void);
int default_setting_08(void);
int default_setting_07(void);
int default_setting_06(void);
int default_setting_05(void);
int default_setting_04(void);
int default_setting_03(void);
int default_setting_02(void);
int default_setting_01(void);
}

// Resets a player's action palettes to the default photon blast slots.
void assign_default_photon_blast_palette_slots(TPlyDispConfig *palettes);
// Puts a photon blast into the first free one of slots 1-3 of the palettes.
void assign_photon_blast_palette_slot(TPlyDispConfig *palettes, s32 arg1);


#endif
