#include "types.h"
#include "pso/system/data/pso_const_ids4.h"
#include "pso/player/TPlyDispConfig.h"


void assign_photon_blast_palette_slot(TPlyDispConfig *palettes, s32 arg1) {
    s32 ids[3] = {1, 2, 3};
    s32 id;
    s32 i;
    for (i = 0; i < 3; i++) {
        id = ids[i];
        if (palettes->m_smth1.get_tag_mode(1, id) == 0) {
            palettes->m_smth1.set_tag(1, id, 5, arg1);
            return;
        }
    }
}

void assign_default_photon_blast_palette_slots(TPlyDispConfig *palettes) {
    s32 tbl[3] = {1, 3, 2};
    s32 i;
    i = 0;
    do {
        palettes->m_smth1.set_tag_mode(1, tbl[i], 0);
        i++;
    } while (i < 3);
}

u8 default_setting_01(void *) { return 0; }
u8 default_setting_02(void *) { return 0; }
u8 default_setting_03(void *) { return 0; }
u8 default_setting_04(void *) { return 0; }
u8 default_setting_05(void *) { return 0; }
u8 default_setting_06(void *) { return 0; }
u8 default_setting_07(void *) { return 0; }
u8 default_setting_08(void *) { return 0; }
u8 default_setting_09(void *) { return 0; }
u8 default_setting_0A(void *) { return 0; }
u8 default_setting_0B(void *) { return 0; }
u8 default_setting_0C(void *) { return 0; }
u8 default_setting_0D(void *) { return 0; }
u8 default_setting_0E(void *) { return 0; }
u8 default_setting_16(void *) { return 0; }
u8 default_setting_18(void *) { return 0; }
