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

extern "C" {
u8 ret_801D795C(void *) { return 0; }
u8 ret_801D7954(void *) { return 0; }
u8 ret_801D794C(void *) { return 0; }
u8 ret_801D7944(void *) { return 0; }
u8 ret_801D793C(void *) { return 0; }
u8 ret_801D7934(void *) { return 0; }
u8 ret_801D792C(void *) { return 0; }
u8 ret_801D7924(void *) { return 0; }
u8 ret_801D791C(void *) { return 0; }
u8 ret_801D7914(void *) { return 0; }
u8 ret_801D790C(void *) { return 0; }
u8 ret_801D7904(void *) { return 0; }
u8 ret_801D78FC(void *) { return 0; }
u8 ret_801D78F4(void *) { return 0; }
u8 ret_801D78EC(void *) { return 0; }
u8 ret_801D78E4(void *) { return 0; }
}
